const abi = @import("r4os_contract").abi;
const std = @import("std");

const Alignment = std.mem.Alignment;

const page_size: usize = 4096;
const small_region_reserve: usize = 64 * 1024 * 1024;
const small_region_grow: usize = 64 * 1024;
const large_threshold: usize = 1024 * 1024;
const max_small_regions: usize = 32;
const block_magic: u32 = 0x32414D52; // "RMA2"
const block_flag_used: u32 = 1 << 0;
const block_flag_direct: u32 = 1 << 1;
const min_free_block: usize = @sizeOf(BlockHeader) + @sizeOf(usize) + 32;

const BlockHeader = extern struct {
    magic: u32 = block_magic,
    flags: u32 = 0,
    region_id: u32 = 0,
    reserved: u32 = 0,
    block_size: usize = 0,
    requested_size: usize = 0,
    user_addr: usize = 0,
};

const SmallRegion = struct {
    used: bool = false,
    region_id: u32 = 0,
    base: usize = 0,
    reserve_size: usize = 0,
    committed_size: usize = 0,
    active_allocations: u32 = 0,
    allocations: u64 = 0,
    frees: u64 = 0,
    active_bytes: u64 = 0,
    peak_active_bytes: u64 = 0,
    decommits: u64 = 0,
};

const State = struct {
    small_regions: [max_small_regions]SmallRegion = .{SmallRegion{}} ** max_small_regions,
    direct_active: u32 = 0,
    direct_allocations: u64 = 0,
    direct_frees: u64 = 0,
    direct_active_bytes: u64 = 0,
    direct_peak_active_bytes: u64 = 0,
    direct_reserved_bytes: u64 = 0,
    allocation_errors: u64 = 0,
};

pub const Stats = struct {
    small_regions: u32 = 0,
    direct_active: u32 = 0,
    active_allocations: u64 = 0,
    allocations: u64 = 0,
    frees: u64 = 0,
    active_bytes: u64 = 0,
    peak_active_bytes: u64 = 0,
    reserved_bytes: u64 = 0,
    committed_bytes: u64 = 0,
    decommits: u64 = 0,
    allocation_errors: u64 = 0,
};

const AllocationLayout = struct {
    user_addr: usize,
    backref_addr: usize,
    allocated_size: usize,
    remaining_size: usize,
};

var state: State = .{};

const vtable = std.mem.Allocator.VTable{
    .alloc = allocatorAlloc,
    .resize = allocatorResize,
    .remap = allocatorRemap,
    .free = allocatorFree,
};

// 0.56.41 (B2): der Allokator laeuft ueber die R4SYS-Gruppentabelle
// (vm_reserve/commit/decommit/release seit v5 enthalten); der
// Parameter heisst weiter api, traegt aber den Tabellenzeiger.
pub fn allocator(api: *const abi.R4XStartR4Sys) std.mem.Allocator {
    return .{ .ptr = @constCast(api), .vtable = &vtable };
}

pub fn stats() Stats {
    var out: Stats = .{
        .direct_active = state.direct_active,
        .active_allocations = state.direct_active,
        .allocations = state.direct_allocations,
        .frees = state.direct_frees,
        .active_bytes = state.direct_active_bytes,
        .peak_active_bytes = state.direct_peak_active_bytes,
        .reserved_bytes = state.direct_reserved_bytes,
        .committed_bytes = state.direct_reserved_bytes,
        .allocation_errors = state.allocation_errors,
    };
    for (state.small_regions) |region| {
        if (!region.used) continue;
        out.small_regions += 1;
        out.active_allocations += region.active_allocations;
        out.allocations += region.allocations;
        out.frees += region.frees;
        out.active_bytes +%= region.active_bytes;
        if (region.peak_active_bytes > out.peak_active_bytes) out.peak_active_bytes = region.peak_active_bytes;
        out.reserved_bytes +%= region.reserve_size;
        out.committed_bytes +%= region.committed_size;
        out.decommits +%= region.decommits;
    }
    return out;
}

fn allocatorAlloc(ptr: *anyopaque, len: usize, alignment: Alignment, ret_addr: usize) ?[*]u8 {
    _ = ret_addr;
    const api = apiFromPtr(ptr);
    if (len == 0 or !supportsVmApi(api)) return failAlloc();
    const byte_alignment = normalizeAlignment(alignment.toByteUnits()) orelse return failAlloc();
    if (len >= large_threshold or byte_alignment > page_size) return allocDirect(api, len, byte_alignment) orelse failAlloc();
    return allocSmall(api, len, byte_alignment) orelse failAlloc();
}

fn allocatorResize(ptr: *anyopaque, memory: []u8, alignment: Alignment, new_len: usize, ret_addr: usize) bool {
    _ = ret_addr;
    if (new_len == memory.len) return true;
    if (memory.len == 0) return new_len == 0;
    const api = apiFromPtr(ptr);
    if (!supportsVmApi(api)) return false;
    const byte_alignment = normalizeAlignment(alignment.toByteUnits()) orelse return false;
    const header = headerFromUser(memory.ptr) orelse return false;
    if (!isUsed(header)) return false;
    if (new_len <= memory.len) {
        shrinkBlock(header, memory.len, new_len);
        return true;
    }
    if (isDirect(header)) return false;
    return growSmallBlock(api, header, byte_alignment, memory.len, new_len);
}

fn allocatorRemap(ptr: *anyopaque, memory: []u8, alignment: Alignment, new_len: usize, ret_addr: usize) ?[*]u8 {
    if (new_len == 0) return null;
    if (allocatorResize(ptr, memory, alignment, new_len, ret_addr)) return memory.ptr;
    const next = allocatorAlloc(ptr, new_len, alignment, ret_addr) orelse return null;
    @memcpy(next[0..@min(memory.len, new_len)], memory[0..@min(memory.len, new_len)]);
    allocatorFree(ptr, memory, alignment, ret_addr);
    return next;
}

fn allocatorFree(ptr: *anyopaque, memory: []u8, alignment: Alignment, ret_addr: usize) void {
    _ = alignment;
    _ = ret_addr;
    if (memory.len == 0) return;
    const api = apiFromPtr(ptr);
    const header = headerFromUser(memory.ptr) orelse return;
    if (!isUsed(header)) return;
    if (isDirect(header)) {
        const region_id = header.region_id;
        const block_size = header.block_size;
        const requested_size = header.requested_size;
        header.flags = 0;
        if (state.direct_active > 0) state.direct_active -= 1;
        state.direct_frees +%= 1;
        if (state.direct_active_bytes >= requested_size) {
            state.direct_active_bytes -= requested_size;
        } else {
            state.direct_active_bytes = 0;
        }
        if (state.direct_reserved_bytes >= block_size) {
            state.direct_reserved_bytes -= block_size;
        } else {
            state.direct_reserved_bytes = 0;
        }
        _ = vmFn(api, "vm_release")(region_id);
        return;
    }
    const region_index = findSmallRegion(header.region_id) orelse return;
    freeSmallBlock(api, region_index, header, memory.len);
}

fn allocSmall(api: *const abi.R4XStartR4Sys, len: usize, alignment: usize) ?[*]u8 {
    if (tryAllocExistingSmall(len, alignment)) |ptr| return ptr;

    const needed = conservativeBlockNeed(len, alignment) orelse return null;
    var i: usize = 0;
    while (i < state.small_regions.len) : (i += 1) {
        if (!state.small_regions[i].used) continue;
        if (growSmallRegion(api, i, needed)) {
            if (tryAllocFromRegion(i, len, alignment)) |ptr| return ptr;
        }
    }

    const region_index = createSmallRegion(api) orelse return null;
    if (tryAllocFromRegion(region_index, len, alignment)) |ptr| return ptr;
    // 0.56.34f: Eine frische Region committet nur EINE Seite; ohne dieses
    // Nachwachsen scheiterte JEDE Erstallokation groesser ~4KB dauerhaft
    // (Befund: REG "scratch-memory" - hive_buffer 32KB ist REGs erste
    // Allokation; alle spaeteren Groessen gingen nur, wenn vorher eine
    // kleine Allokation die Region angelegt hatte).
    if (growSmallRegion(api, region_index, needed)) {
        if (tryAllocFromRegion(region_index, len, alignment)) |ptr| return ptr;
    }
    return null;
}

fn tryAllocExistingSmall(len: usize, alignment: usize) ?[*]u8 {
    var i: usize = 0;
    while (i < state.small_regions.len) : (i += 1) {
        if (!state.small_regions[i].used) continue;
        if (tryAllocFromRegion(i, len, alignment)) |ptr| return ptr;
    }
    return null;
}

fn tryAllocFromRegion(region_index: usize, len: usize, alignment: usize) ?[*]u8 {
    const region = &state.small_regions[region_index];
    const end = checkedAdd(region.base, region.committed_size) orelse return null;
    var addr = region.base;
    while (addr + @sizeOf(BlockHeader) <= end) {
        const header = headerAt(addr);
        if (!validHeader(header) or header.block_size == 0) return null;
        const next = checkedAdd(addr, header.block_size) orelse return null;
        if (next > end) return null;
        if (!isUsed(header)) {
            if (layoutInBlock(addr, header.block_size, len, alignment)) |layout| {
                allocateFromFreeBlock(region, header, addr, layout, len);
                return @ptrFromInt(layout.user_addr);
            }
        }
        addr = next;
    }
    return null;
}

fn allocateFromFreeBlock(region: *SmallRegion, header: *BlockHeader, header_addr: usize, layout: AllocationLayout, len: usize) void {
    const region_id = header.region_id;
    if (layout.remaining_size >= min_free_block) {
        const next_addr = header_addr + layout.allocated_size;
        const next = headerAt(next_addr);
        next.* = .{
            .flags = 0,
            .region_id = region_id,
            .block_size = layout.remaining_size,
        };
        header.block_size = layout.allocated_size;
    }
    header.magic = block_magic;
    header.flags = block_flag_used;
    header.region_id = region_id;
    header.requested_size = len;
    header.user_addr = layout.user_addr;
    writeBackref(layout.backref_addr, header_addr);
    region.active_allocations += 1;
    region.allocations +%= 1;
    region.active_bytes +%= len;
    if (region.active_bytes > region.peak_active_bytes) region.peak_active_bytes = region.active_bytes;
}

fn allocDirect(api: *const abi.R4XStartR4Sys, len: usize, alignment: usize) ?[*]u8 {
    const effective_alignment = @max(alignment, page_size);
    const need = conservativeBlockNeed(len, effective_alignment) orelse return null;
    const reserve_size = alignForward(need, page_size) orelse return null;
    const reserve_alignment: u64 = @intCast(effective_alignment);
    var info: abi.ProgramVmRegionInfo = .{};
    if (vmFn(api, "vm_reserve")(reserve_size, reserve_alignment, abi.vm_region_flags_default, &info) != abi.vm_ok) return null;
    if (vmFn(api, "vm_commit")(info.id, 0, reserve_size, 0) != abi.vm_ok) {
        _ = vmFn(api, "vm_release")(info.id);
        return null;
    }
    const base: usize = @intCast(info.base);
    const layout = layoutInBlock(base, reserve_size, len, effective_alignment) orelse {
        _ = vmFn(api, "vm_release")(info.id);
        return null;
    };
    const header = headerAt(base);
    header.* = .{
        .flags = block_flag_used | block_flag_direct,
        .region_id = info.id,
        .block_size = reserve_size,
        .requested_size = len,
        .user_addr = layout.user_addr,
    };
    writeBackref(layout.backref_addr, base);
    state.direct_active += 1;
    state.direct_allocations +%= 1;
    state.direct_active_bytes +%= len;
    state.direct_reserved_bytes +%= reserve_size;
    if (state.direct_active_bytes > state.direct_peak_active_bytes) state.direct_peak_active_bytes = state.direct_active_bytes;
    return @ptrFromInt(layout.user_addr);
}

fn createSmallRegion(api: *const abi.R4XStartR4Sys) ?usize {
    const slot = freeSmallRegionSlot() orelse return null;
    var info: abi.ProgramVmRegionInfo = .{};
    if (vmFn(api, "vm_reserve")(small_region_reserve, page_size, abi.vm_region_flags_default, &info) != abi.vm_ok) return null;
    if (vmFn(api, "vm_commit")(info.id, 0, page_size, 0) != abi.vm_ok) {
        _ = vmFn(api, "vm_release")(info.id);
        return null;
    }
    const base: usize = @intCast(info.base);
    state.small_regions[slot] = .{
        .used = true,
        .region_id = info.id,
        .base = base,
        .reserve_size = @intCast(info.len),
        .committed_size = page_size,
    };
    const header = headerAt(base);
    header.* = .{
        .flags = 0,
        .region_id = info.id,
        .block_size = page_size,
    };
    return slot;
}

fn growSmallRegion(api: *const abi.R4XStartR4Sys, region_index: usize, needed: usize) bool {
    var region = &state.small_regions[region_index];
    if (!region.used or region.committed_size >= region.reserve_size) return false;
    const wanted = @max(needed, small_region_grow);
    var add = alignForward(wanted, page_size) orelse return false;
    const available = region.reserve_size - region.committed_size;
    if (add > available) add = alignDown(available, page_size);
    if (add == 0) return false;
    const old_committed = region.committed_size;
    if (vmFn(api, "vm_commit")(region.region_id, old_committed, add, 0) != abi.vm_ok) return false;
    const new_block_addr = region.base + old_committed;
    region.committed_size = old_committed + add;
    if (lastBlock(region.*)) |last| {
        if (!isUsed(last.header) and last.addr + last.header.block_size == new_block_addr) {
            last.header.block_size += add;
            return true;
        }
    }
    const header = headerAt(new_block_addr);
    header.* = .{
        .flags = 0,
        .region_id = region.region_id,
        .block_size = add,
    };
    return true;
}

fn freeSmallBlock(api: *const abi.R4XStartR4Sys, region_index: usize, header: *BlockHeader, old_len: usize) void {
    var region = &state.small_regions[region_index];
    header.flags = 0;
    header.requested_size = 0;
    header.user_addr = 0;
    if (region.active_allocations > 0) region.active_allocations -= 1;
    region.frees +%= 1;
    if (region.active_bytes >= old_len) {
        region.active_bytes -= old_len;
    } else {
        region.active_bytes = 0;
    }
    coalesceAround(region.*, header);
    decommitTopFree(api, region_index);
}

fn growSmallBlock(api: *const abi.R4XStartR4Sys, header: *BlockHeader, alignment: usize, old_len: usize, new_len: usize) bool {
    _ = alignment;
    const region_index = findSmallRegion(header.region_id) orelse return false;
    const region = &state.small_regions[region_index];
    const header_addr = @intFromPtr(header);
    const user_addr = header.user_addr;
    if (canHoldUser(header_addr, header.block_size, user_addr, new_len)) {
        accountResize(region, old_len, new_len);
        header.requested_size = new_len;
        return true;
    }

    while (!canHoldUser(header_addr, header.block_size, user_addr, new_len)) {
        const next_addr = header_addr + header.block_size;
        const committed_end = region.base + region.committed_size;
        if (next_addr == committed_end) {
            const need = checkedSub((user_addr + new_len), committed_end) orelse return false;
            if (!growSmallRegion(api, region_index, need)) return false;
        }
        const next = headerAt(next_addr);
        if (!validHeader(next) or isUsed(next)) return false;
        header.block_size += next.block_size;
    }

    splitAfterResize(header, user_addr, new_len);
    accountResize(region, old_len, new_len);
    header.requested_size = new_len;
    return true;
}

fn shrinkBlock(header: *BlockHeader, old_len: usize, new_len: usize) void {
    const region_index = findSmallRegion(header.region_id) orelse {
        header.requested_size = new_len;
        return;
    };
    var region = &state.small_regions[region_index];
    if (old_len > new_len and region.active_bytes >= old_len - new_len) region.active_bytes -= old_len - new_len;
    header.requested_size = new_len;
}

fn splitAfterResize(header: *BlockHeader, user_addr: usize, new_len: usize) void {
    const header_addr = @intFromPtr(header);
    const block_end = header_addr + header.block_size;
    const user_end = user_addr + new_len;
    var split_addr = alignForward(user_end, @alignOf(BlockHeader)) orelse block_end;
    if (split_addr > block_end or block_end - split_addr < min_free_block) {
        split_addr = block_end;
    }
    if (split_addr < block_end) {
        const old_size = header.block_size;
        header.block_size = split_addr - header_addr;
        const free = headerAt(split_addr);
        free.* = .{
            .flags = 0,
            .region_id = header.region_id,
            .block_size = old_size - header.block_size,
        };
    }
}

fn accountResize(region: *SmallRegion, old_len: usize, new_len: usize) void {
    if (new_len >= old_len) {
        region.active_bytes +%= new_len - old_len;
    } else if (region.active_bytes >= old_len - new_len) {
        region.active_bytes -= old_len - new_len;
    } else {
        region.active_bytes = 0;
    }
    if (region.active_bytes > region.peak_active_bytes) region.peak_active_bytes = region.active_bytes;
}

fn coalesceAround(region: SmallRegion, header: *BlockHeader) void {
    coalesceNext(region, header);
    if (previousBlock(region, @intFromPtr(header))) |prev| {
        if (!isUsed(prev)) {
            prev.block_size += header.block_size;
            coalesceNext(region, prev);
        }
    }
}

fn coalesceNext(region: SmallRegion, header: *BlockHeader) void {
    const end = region.base + region.committed_size;
    while (true) {
        const next_addr = @intFromPtr(header) + header.block_size;
        if (next_addr + @sizeOf(BlockHeader) > end) return;
        const next = headerAt(next_addr);
        if (!validHeader(next) or isUsed(next)) return;
        header.block_size += next.block_size;
    }
}

fn decommitTopFree(api: *const abi.R4XStartR4Sys, region_index: usize) void {
    var region = &state.small_regions[region_index];
    if (region.committed_size <= page_size) return;
    const last = lastBlock(region.*) orelse return;
    if (isUsed(last.header)) return;
    const keep_until = alignForward(last.addr + @sizeOf(BlockHeader), page_size) orelse return;
    const committed_end = region.base + region.committed_size;
    if (keep_until >= committed_end or keep_until < region.base + page_size) return;
    const len = committed_end - keep_until;
    if (vmFn(api, "vm_decommit")(region.region_id, keep_until - region.base, len) != abi.vm_ok) return;
    region.committed_size = keep_until - region.base;
    last.header.block_size = keep_until - last.addr;
    region.decommits +%= 1;
}

fn layoutInBlock(block_addr: usize, block_size: usize, len: usize, alignment: usize) ?AllocationLayout {
    const block_end = checkedAdd(block_addr, block_size) orelse return null;
    const min_user = checkedAdd(block_addr, @sizeOf(BlockHeader) + @sizeOf(usize)) orelse return null;
    const user_addr = alignForward(min_user, alignment) orelse return null;
    const backref_addr = checkedSub(user_addr, @sizeOf(usize)) orelse return null;
    const user_end = checkedAdd(user_addr, len) orelse return null;
    if (user_end > block_end) return null;
    var split_addr = alignForward(user_end, @alignOf(BlockHeader)) orelse return null;
    if (split_addr > block_end or block_end - split_addr < min_free_block) {
        split_addr = block_end;
    }
    return .{
        .user_addr = user_addr,
        .backref_addr = backref_addr,
        .allocated_size = split_addr - block_addr,
        .remaining_size = block_end - split_addr,
    };
}

fn conservativeBlockNeed(len: usize, alignment: usize) ?usize {
    const with_header = checkedAdd(@sizeOf(BlockHeader) + @sizeOf(usize), len) orelse return null;
    return checkedAdd(with_header, alignment - 1);
}

fn headerFromUser(ptr: [*]u8) ?*BlockHeader {
    const user_addr = @intFromPtr(ptr);
    const backref_addr = checkedSub(user_addr, @sizeOf(usize)) orelse return null;
    const header_addr = (@as(*const usize, @ptrFromInt(backref_addr))).*;
    const header = headerAt(header_addr);
    if (!validHeader(header) or header.user_addr != user_addr) return null;
    return header;
}

fn headerAt(addr: usize) *BlockHeader {
    return @ptrFromInt(addr);
}

fn writeBackref(addr: usize, header_addr: usize) void {
    const backref: *usize = @ptrFromInt(addr);
    backref.* = header_addr;
}

fn validHeader(header: *const BlockHeader) bool {
    return header.magic == block_magic and header.block_size >= @sizeOf(BlockHeader);
}

fn isUsed(header: *const BlockHeader) bool {
    return (header.flags & block_flag_used) != 0;
}

fn isDirect(header: *const BlockHeader) bool {
    return (header.flags & block_flag_direct) != 0;
}

fn previousBlock(region: SmallRegion, header_addr: usize) ?*BlockHeader {
    var addr = region.base;
    while (addr < header_addr) {
        const header = headerAt(addr);
        if (!validHeader(header) or header.block_size == 0) return null;
        const next = addr + header.block_size;
        if (next == header_addr) return header;
        if (next > header_addr) return null;
        addr = next;
    }
    return null;
}

const LastBlock = struct {
    addr: usize,
    header: *BlockHeader,
};

fn lastBlock(region: SmallRegion) ?LastBlock {
    const end = region.base + region.committed_size;
    var addr = region.base;
    var last: ?LastBlock = null;
    while (addr + @sizeOf(BlockHeader) <= end) {
        const header = headerAt(addr);
        if (!validHeader(header) or header.block_size == 0) return null;
        const next = addr + header.block_size;
        if (next > end) return null;
        last = .{ .addr = addr, .header = header };
        if (next == end) break;
        addr = next;
    }
    return last;
}

fn canHoldUser(header_addr: usize, block_size: usize, user_addr: usize, len: usize) bool {
    const user_end = checkedAdd(user_addr, len) orelse return false;
    const block_end = checkedAdd(header_addr, block_size) orelse return false;
    return user_end <= block_end;
}

fn freeSmallRegionSlot() ?usize {
    var i: usize = 0;
    while (i < state.small_regions.len) : (i += 1) {
        if (!state.small_regions[i].used) return i;
    }
    return null;
}

fn findSmallRegion(region_id: u32) ?usize {
    var i: usize = 0;
    while (i < state.small_regions.len) : (i += 1) {
        if (state.small_regions[i].used and state.small_regions[i].region_id == region_id) return i;
    }
    return null;
}

fn apiFromPtr(ptr: *anyopaque) *const abi.R4XStartR4Sys {
    return @ptrCast(@alignCast(ptr));
}

fn supportsVmApi(api: *const abi.R4XStartR4Sys) bool {
    return api.magic == abi.r4xstart_r4sys_magic and
        api.size >= abi.r4xstart_r4sys_size and
        api.vm_reserve != 0 and api.vm_commit != 0 and
        api.vm_decommit != 0 and api.vm_release != 0;
}

fn vmFn(api: *const abi.R4XStartR4Sys, comptime field: []const u8) @field(abi.R4SysFns, field) {
    return @ptrFromInt(@field(api.*, field));
}

fn normalizeAlignment(raw: usize) ?usize {
    var alignment = if (raw == 0) @as(usize, 1) else raw;
    if ((alignment & (alignment - 1)) != 0) return null;
    if (alignment < @alignOf(usize)) alignment = @alignOf(usize);
    return alignment;
}

fn alignForward(value: usize, alignment: usize) ?usize {
    const mask = alignment - 1;
    if (value > std.math.maxInt(usize) - mask) return null;
    return (value + mask) & ~mask;
}

fn alignDown(value: usize, alignment: usize) usize {
    return value & ~(alignment - 1);
}

fn checkedAdd(a: usize, b: usize) ?usize {
    if (a > std.math.maxInt(usize) - b) return null;
    return a + b;
}

fn checkedSub(a: usize, b: usize) ?usize {
    if (a < b) return null;
    return a - b;
}

fn failAlloc() ?[*]u8 {
    state.allocation_errors +%= 1;
    return null;
}

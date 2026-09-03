const abi = @import("r4os_contract").abi;
const std = @import("std");

const Alignment = std.mem.Alignment;

const page_size: usize = 4096;
const small_region_reserve: usize = 64 * 1024 * 1024;
const small_region_grow: usize = 64 * 1024;
const large_threshold: usize = 1024 * 1024;
const max_small_regions: usize = 32;
const block_magic: u32 = 0x33414D52; // "RMA3"
const retired_block_magic: u32 = 0x58414D52; // "RMAX"
const footer_magic: u32 = 0x33464D52; // "RMF3"
const block_flag_used: u32 = 1 << 0;
const block_flag_direct: u32 = 1 << 1;
const block_flag_listed: u32 = 1 << 2;
const valid_block_flags: u32 = block_flag_used | block_flag_direct | block_flag_listed;

const BlockHeader = extern struct {
    magic: u32 = block_magic,
    flags: u32 = 0,
    region_id: u32 = 0,
    reserved: u32 = 0,
    block_size: usize = 0,
    requested_size: usize = 0,
    user_addr: usize = 0,
    free_previous: usize = 0,
    free_next: usize = 0,
};

const BlockFooter = extern struct {
    magic: u32 = footer_magic,
    reserved: u32 = 0,
    block_size: usize = 0,
};

const FreeLinks = extern struct {
    previous: usize = 0,
    next: usize = 0,
};

const min_free_block_unaligned = @sizeOf(BlockHeader) + @sizeOf(usize) + 1 + @sizeOf(BlockFooter);
const min_free_block: usize = (min_free_block_unaligned + @alignOf(BlockHeader) - 1) & ~@as(usize, @alignOf(BlockHeader) - 1);
const first_size_class_limit: usize = 128;
const size_class_count: usize = 20;

comptime {
    if (min_free_block > first_size_class_limit) @compileError("first VM allocator size class is smaller than a free block");
    if ((first_size_class_limit << (size_class_count - 1)) < small_region_reserve) @compileError("VM allocator size classes do not cover a small region");
}

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
    free_heads: [size_class_count]usize = .{0} ** size_class_count,
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
    allocation_search_steps: u64 = 0,
    class_search_steps: u64 = 0,
    backward_search_steps: u64 = 0,
    end_search_steps: u64 = 0,
    splits: u64 = 0,
    coalesces: u64 = 0,
    corruptions: u64 = 0,
    vm_reserve_calls: u64 = 0,
    vm_commit_calls: u64 = 0,
    vm_decommit_calls: u64 = 0,
    vm_release_calls: u64 = 0,
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
    allocation_search_steps: u64 = 0,
    class_search_steps: u64 = 0,
    backward_search_steps: u64 = 0,
    end_search_steps: u64 = 0,
    splits: u64 = 0,
    coalesces: u64 = 0,
    corruptions: u64 = 0,
    vm_reserve_calls: u64 = 0,
    vm_commit_calls: u64 = 0,
    vm_decommit_calls: u64 = 0,
    vm_release_calls: u64 = 0,
};

const AllocationLayout = struct {
    user_addr: usize,
    backref_addr: usize,
    allocated_size: usize,
    remaining_size: usize,
};

var state: State = .{};
var allocator_lock: u32 = 0;

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
    acquireAllocatorLock(null);
    defer releaseAllocatorLock();
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
        .allocation_search_steps = state.allocation_search_steps,
        .class_search_steps = state.class_search_steps,
        .backward_search_steps = state.backward_search_steps,
        .end_search_steps = state.end_search_steps,
        .splits = state.splits,
        .coalesces = state.coalesces,
        .corruptions = state.corruptions,
        .vm_reserve_calls = state.vm_reserve_calls,
        .vm_commit_calls = state.vm_commit_calls,
        .vm_decommit_calls = state.vm_decommit_calls,
        .vm_release_calls = state.vm_release_calls,
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
    acquireAllocatorLock(api);
    defer releaseAllocatorLock();
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
    acquireAllocatorLock(api);
    defer releaseAllocatorLock();
    if (!supportsVmApi(api)) return false;
    const byte_alignment = normalizeAlignment(alignment.toByteUnits()) orelse return false;
    const header = headerFromUser(memory.ptr, byte_alignment) orelse return false;
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
    _ = ret_addr;
    if (memory.len == 0) return;
    const api = apiFromPtr(ptr);
    acquireAllocatorLock(api);
    defer releaseAllocatorLock();
    const byte_alignment = normalizeAlignment(alignment.toByteUnits()) orelse return;
    const header = headerFromUser(memory.ptr, byte_alignment) orelse return;
    if (!isUsed(header)) return;
    if (isDirect(header)) {
        const region_id = header.region_id;
        const block_size = header.block_size;
        const requested_size = header.requested_size;
        if (vmRelease(api, region_id) != abi.vm_ok) return;
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
        return;
    }
    const region_index = findSmallRegion(header.region_id) orelse return;
    freeSmallBlock(api, region_index, header, header.requested_size);
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
    const needed = conservativeBlockNeed(len, alignment) orelse return null;
    var class_index = sizeClass(needed);
    while (class_index < size_class_count) : (class_index += 1) {
        state.class_search_steps +%= 1;
        var addr = region.free_heads[class_index];
        var previous: usize = 0;
        var visits: usize = 0;
        const visit_limit = region.committed_size / min_free_block + 1;
        while (addr != 0 and visits < visit_limit) : (visits += 1) {
            state.allocation_search_steps +%= 1;
            const header = validatedFreeNode(region.*, addr, class_index, previous) orelse return null;
            const next = freeLinks(header).next;
            if (layoutInBlock(addr, header.block_size, len, alignment)) |layout| {
                if (!removeFree(region, header)) return null;
                allocateFromFreeBlock(region, header, addr, layout, len);
                return @ptrFromInt(layout.user_addr);
            }
            previous = addr;
            addr = next;
        }
        if (addr != 0) {
            recordCorruption();
            return null;
        }
    }
    return null;
}

fn allocateFromFreeBlock(region: *SmallRegion, header: *BlockHeader, header_addr: usize, layout: AllocationLayout, len: usize) void {
    const region_id = header.region_id;
    if (layout.remaining_size >= min_free_block) {
        state.splits +%= 1;
        const next_addr = header_addr + layout.allocated_size;
        header.block_size = layout.allocated_size;
        writeFooter(header);
        const next = initFreeBlock(region_id, next_addr, layout.remaining_size);
        _ = insertFree(region, next);
    }
    header.magic = block_magic;
    header.flags = block_flag_used;
    header.region_id = region_id;
    header.requested_size = len;
    header.user_addr = layout.user_addr;
    writeFooter(header);
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
    if (vmReserve(api, reserve_size, reserve_alignment, abi.vm_region_flags_default, &info) != abi.vm_ok) return null;
    if (!validReservedRegion(info, reserve_size, effective_alignment)) {
        _ = vmRelease(api, info.id);
        return null;
    }
    if (vmCommit(api, info.id, 0, reserve_size, 0) != abi.vm_ok) {
        _ = vmRelease(api, info.id);
        return null;
    }
    const base: usize = @intCast(info.base);
    const layout = layoutInBlock(base, reserve_size, len, effective_alignment) orelse {
        _ = vmRelease(api, info.id);
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
    writeFooter(header);
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
    if (vmReserve(api, small_region_reserve, page_size, abi.vm_region_flags_default, &info) != abi.vm_ok) return null;
    if (!validReservedRegion(info, small_region_reserve, page_size)) {
        _ = vmRelease(api, info.id);
        return null;
    }
    if (vmCommit(api, info.id, 0, page_size, 0) != abi.vm_ok) {
        _ = vmRelease(api, info.id);
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
    const header = initFreeBlock(info.id, base, page_size);
    if (!insertFree(&state.small_regions[slot], header)) {
        _ = vmRelease(api, info.id);
        state.small_regions[slot] = .{};
        return null;
    }
    return slot;
}

fn growSmallRegion(api: *const abi.R4XStartR4Sys, region_index: usize, needed: usize) bool {
    const region = &state.small_regions[region_index];
    if (!region.used or region.committed_size >= region.reserve_size) return false;
    const wanted = @max(needed, small_region_grow);
    var add = alignForward(wanted, page_size) orelse return false;
    const available = region.reserve_size - region.committed_size;
    if (add > available) add = alignDown(available, page_size);
    if (add == 0) return false;
    const old_committed = region.committed_size;
    const last = lastBlock(region.*) orelse return false;
    const extend_last = !isUsed(last.header);
    if (extend_last and !canRemoveFree(region.*, last.header)) return false;
    if (vmCommit(api, region.region_id, old_committed, add, 0) != abi.vm_ok) return false;
    const new_block_addr = region.base + old_committed;
    if (extend_last) {
        if (!removeFree(region, last.header)) {
            _ = vmDecommit(api, region.region_id, old_committed, add);
            return false;
        }
        footerFromHeader(last.header).magic = 0;
        region.committed_size = old_committed + add;
        last.header.block_size += add;
        writeFooter(last.header);
        return insertFree(region, last.header);
    }
    region.committed_size = old_committed + add;
    const header = initFreeBlock(region.region_id, new_block_addr, add);
    return insertFree(region, header);
}

fn freeSmallBlock(api: *const abi.R4XStartR4Sys, region_index: usize, header: *BlockHeader, old_len: usize) void {
    const region = &state.small_regions[region_index];
    const header_addr = @intFromPtr(header);
    const previous = previousBlock(region.*, header_addr) catch return;
    const next = nextBlock(region.*, header) catch return;
    if (previous) |candidate| {
        if (!isUsed(candidate) and !canRemoveFree(region.*, candidate)) return;
    }
    if (next) |candidate| {
        if (!isUsed(candidate) and !canRemoveFree(region.*, candidate)) return;
    }

    var merged = header;
    var merged_size = header.block_size;
    header.flags = 0;
    header.requested_size = 0;
    header.user_addr = 0;
    if (previous) |candidate| {
        if (!isUsed(candidate)) {
            if (!removeFree(region, candidate)) return;
            footerFromHeader(candidate).magic = 0;
            header.magic = retired_block_magic;
            merged = candidate;
            merged_size += candidate.block_size;
            state.coalesces +%= 1;
        }
    }
    if (next) |candidate| {
        if (!isUsed(candidate)) {
            if (!removeFree(region, candidate)) return;
            footerFromHeader(merged).magic = 0;
            candidate.magic = retired_block_magic;
            merged_size += candidate.block_size;
            state.coalesces +%= 1;
        }
    }
    merged.magic = block_magic;
    merged.flags = 0;
    merged.region_id = region.region_id;
    merged.block_size = merged_size;
    merged.requested_size = 0;
    merged.user_addr = 0;
    writeFooter(merged);
    if (!insertFree(region, merged)) return;

    if (region.active_allocations > 0) region.active_allocations -= 1;
    region.frees +%= 1;
    if (region.active_bytes >= old_len) {
        region.active_bytes -= old_len;
    } else {
        region.active_bytes = 0;
    }
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

    var next = (nextBlock(region.*, header) catch return false) orelse blk: {
        const required_end = requiredBlockEnd(user_addr, new_len) orelse return false;
        const committed_end = region.base + region.committed_size;
        const need = checkedSub(required_end, committed_end) orelse min_free_block;
        if (!growSmallRegion(api, region_index, @max(need, min_free_block))) return false;
        break :blk (nextBlock(region.*, header) catch return false) orelse return false;
    };
    if (isUsed(next)) return false;

    if (!canHoldUser(header_addr, header.block_size + next.block_size, user_addr, new_len)) {
        const next_end = @intFromPtr(next) + next.block_size;
        if (next_end != region.base + region.committed_size) return false;
        const required_end = requiredBlockEnd(user_addr, new_len) orelse return false;
        const need = checkedSub(required_end, next_end) orelse return false;
        if (!growSmallRegion(api, region_index, need)) return false;
        next = (nextBlock(region.*, header) catch return false) orelse return false;
        if (isUsed(next) or !canHoldUser(header_addr, header.block_size + next.block_size, user_addr, new_len)) return false;
    }

    if (!removeFree(region, next)) return false;
    footerFromHeader(header).magic = 0;
    next.magic = retired_block_magic;
    header.block_size += next.block_size;
    writeFooter(header);
    state.coalesces +%= 1;
    splitAfterResize(region, header, user_addr, new_len);
    accountResize(region, old_len, new_len);
    header.requested_size = new_len;
    return true;
}

fn shrinkBlock(header: *BlockHeader, old_len: usize, new_len: usize) void {
    if (isDirect(header)) {
        if (old_len > new_len and state.direct_active_bytes >= old_len - new_len) state.direct_active_bytes -= old_len - new_len;
        header.requested_size = new_len;
        return;
    }
    const region_index = findSmallRegion(header.region_id) orelse {
        header.requested_size = new_len;
        return;
    };
    var region = &state.small_regions[region_index];
    if (old_len > new_len and region.active_bytes >= old_len - new_len) region.active_bytes -= old_len - new_len;
    header.requested_size = new_len;
}

fn splitAfterResize(region: *SmallRegion, header: *BlockHeader, user_addr: usize, new_len: usize) void {
    const header_addr = @intFromPtr(header);
    const block_end = header_addr + header.block_size;
    var split_addr = requiredBlockEnd(user_addr, new_len) orelse block_end;
    if (split_addr > block_end or block_end - split_addr < min_free_block) {
        split_addr = block_end;
    }
    if (split_addr < block_end) {
        state.splits +%= 1;
        const old_size = header.block_size;
        footerFromHeader(header).magic = 0;
        header.block_size = split_addr - header_addr;
        writeFooter(header);
        const free = initFreeBlock(header.region_id, split_addr, old_size - header.block_size);
        _ = insertFree(region, free);
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

fn decommitTopFree(api: *const abi.R4XStartR4Sys, region_index: usize) void {
    const region = &state.small_regions[region_index];
    if (region.committed_size <= page_size) return;
    const last = lastBlock(region.*) orelse return;
    if (isUsed(last.header)) return;
    if (!canRemoveFree(region.*, last.header)) return;
    const keep_until = alignForward(last.addr + min_free_block, page_size) orelse return;
    const committed_end = region.base + region.committed_size;
    if (keep_until >= committed_end or keep_until < region.base + page_size) return;
    const len = committed_end - keep_until;
    if (!removeFree(region, last.header)) return;
    if (vmDecommit(api, region.region_id, keep_until - region.base, len) != abi.vm_ok) {
        _ = insertFree(region, last.header);
        return;
    }
    region.committed_size = keep_until - region.base;
    last.header.block_size = keep_until - last.addr;
    writeFooter(last.header);
    _ = insertFree(region, last.header);
    region.decommits +%= 1;
}

fn layoutInBlock(block_addr: usize, block_size: usize, len: usize, alignment: usize) ?AllocationLayout {
    const block_end = checkedAdd(block_addr, block_size) orelse return null;
    const payload_end = checkedSub(block_end, @sizeOf(BlockFooter)) orelse return null;
    const min_user = checkedAdd(block_addr, @sizeOf(BlockHeader) + @sizeOf(usize)) orelse return null;
    const user_addr = alignForward(min_user, alignment) orelse return null;
    const backref_addr = checkedSub(user_addr, @sizeOf(usize)) orelse return null;
    const user_end = checkedAdd(user_addr, len) orelse return null;
    if (user_end > payload_end) return null;
    var split_addr = requiredBlockEnd(user_addr, len) orelse return null;
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
    const with_alignment = checkedAdd(with_header, alignment - 1) orelse return null;
    const with_footer = checkedAdd(with_alignment, @sizeOf(BlockFooter)) orelse return null;
    return alignForward(with_footer, @alignOf(BlockHeader));
}

fn requiredBlockEnd(user_addr: usize, len: usize) ?usize {
    const user_end = checkedAdd(user_addr, len) orelse return null;
    const footer_end = checkedAdd(user_end, @sizeOf(BlockFooter)) orelse return null;
    return alignForward(footer_end, @alignOf(BlockHeader));
}

fn headerFromUser(ptr: [*]u8, alignment: usize) ?*BlockHeader {
    const user_addr = @intFromPtr(ptr);
    if (findSmallRegionContaining(user_addr)) |region_index| {
        const region = state.small_regions[region_index];
        const committed_end = checkedAdd(region.base, region.committed_size) orelse return corruptNull();
        const backref_addr = checkedSub(user_addr, @sizeOf(usize)) orelse return corruptNull();
        if (backref_addr < region.base + @sizeOf(BlockHeader) or backref_addr + @sizeOf(usize) > committed_end) return corruptNull();
        const header_addr = (@as(*const usize, @ptrFromInt(backref_addr))).*;
        if (header_addr < region.base or header_addr + @sizeOf(BlockHeader) > committed_end) return corruptNull();
        const header = headerAt(header_addr);
        if (header.magic == retired_block_magic) return null;
        if (!validSmallBlock(region, header_addr, header)) return corruptNull();
        if (isUsed(header) and header.user_addr != user_addr) return corruptNull();
        return header;
    }

    const effective_alignment = @max(alignment, page_size);
    const header_addr = checkedSub(user_addr, effective_alignment) orelse return null;
    const header = headerAt(header_addr);
    if (header.magic == retired_block_magic) return null;
    if (!validDirectBlock(header_addr, header, user_addr, effective_alignment)) return corruptNull();
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
    return header.magic == block_magic and
        (header.flags & ~valid_block_flags) == 0 and
        header.block_size >= min_free_block and
        (header.block_size & (@alignOf(BlockHeader) - 1)) == 0;
}

fn isUsed(header: *const BlockHeader) bool {
    return (header.flags & block_flag_used) != 0;
}

fn isDirect(header: *const BlockHeader) bool {
    return (header.flags & block_flag_direct) != 0;
}

fn footerFromHeader(header: *const BlockHeader) *BlockFooter {
    return @ptrFromInt(@intFromPtr(header) + header.block_size - @sizeOf(BlockFooter));
}

fn writeFooter(header: *const BlockHeader) void {
    footerFromHeader(header).* = .{ .block_size = header.block_size };
}

fn freeLinks(header: *const BlockHeader) *FreeLinks {
    return @ptrCast(@constCast(&header.free_previous));
}

fn initFreeBlock(region_id: u32, addr: usize, block_size: usize) *BlockHeader {
    const header = headerAt(addr);
    header.* = .{
        .region_id = region_id,
        .block_size = block_size,
    };
    freeLinks(header).* = .{};
    writeFooter(header);
    return header;
}

fn sizeClass(block_size: usize) usize {
    var class_index: usize = 0;
    var limit = first_size_class_limit;
    while (class_index + 1 < size_class_count and block_size > limit) : (class_index += 1) {
        limit <<= 1;
    }
    return class_index;
}

fn validSmallBlock(region: SmallRegion, addr: usize, header: *const BlockHeader) bool {
    const committed_end = checkedAdd(region.base, region.committed_size) orelse return false;
    if (addr < region.base or (addr & (@alignOf(BlockHeader) - 1)) != 0) return false;
    if (!validHeader(header) or isDirect(header) or header.region_id != region.region_id) return false;
    if (isUsed(header) and (header.flags & block_flag_listed) != 0) return false;
    const end = checkedAdd(addr, header.block_size) orelse return false;
    if (end > committed_end) return false;
    const footer = footerFromHeader(header);
    return footer.magic == footer_magic and footer.block_size == header.block_size;
}

fn validDirectBlock(header_addr: usize, header: *const BlockHeader, user_addr: usize, alignment: usize) bool {
    if (!validHeader(header) or !isUsed(header) or !isDirect(header) or (header.flags & block_flag_listed) != 0) return false;
    if (header.user_addr != user_addr or header_addr + alignment != user_addr) return false;
    const need = conservativeBlockNeed(header.requested_size, alignment) orelse return false;
    const minimum_size = alignForward(need, page_size) orelse return false;
    if (header.block_size < minimum_size or (header.block_size & (page_size - 1)) != 0) return false;
    const footer = footerFromHeader(header);
    return footer.magic == footer_magic and footer.block_size == header.block_size;
}

fn validatedFreeNode(region: SmallRegion, addr: usize, class_index: usize, expected_previous: usize) ?*BlockHeader {
    const header = headerAt(addr);
    if (!validSmallBlock(region, addr, header) or isUsed(header) or
        (header.flags & block_flag_listed) == 0 or sizeClass(header.block_size) != class_index)
    {
        return corruptNull();
    }
    const links = freeLinks(header);
    if (links.previous != expected_previous or links.next == addr) return corruptNull();
    if (links.next != 0) {
        const next = headerAt(links.next);
        if (!validSmallBlock(region, links.next, next) or isUsed(next) or
            (next.flags & block_flag_listed) == 0 or sizeClass(next.block_size) != class_index or
            freeLinks(next).previous != addr)
        {
            return corruptNull();
        }
    }
    return header;
}

fn insertFree(region: *SmallRegion, header: *BlockHeader) bool {
    const addr = @intFromPtr(header);
    if (!validSmallBlock(region.*, addr, header) or isUsed(header) or (header.flags & block_flag_listed) != 0) return corruptFalse();
    const class_index = sizeClass(header.block_size);
    const old_head = region.free_heads[class_index];
    if (old_head != 0) {
        const old = headerAt(old_head);
        if (!validSmallBlock(region.*, old_head, old) or isUsed(old) or
            (old.flags & block_flag_listed) == 0 or sizeClass(old.block_size) != class_index or
            freeLinks(old).previous != 0)
        {
            return corruptFalse();
        }
    }
    freeLinks(header).* = .{ .next = old_head };
    header.flags |= block_flag_listed;
    if (old_head != 0) freeLinks(headerAt(old_head)).previous = addr;
    region.free_heads[class_index] = addr;
    return true;
}

fn freeNodeRemovable(region: SmallRegion, header: *const BlockHeader) bool {
    const addr = @intFromPtr(header);
    if (!validSmallBlock(region, addr, header) or isUsed(header) or (header.flags & block_flag_listed) == 0) return false;
    const class_index = sizeClass(header.block_size);
    const links = freeLinks(header);
    if (links.previous == addr or links.next == addr) return false;
    if (links.previous == 0) {
        if (region.free_heads[class_index] != addr) return false;
    } else {
        const previous = headerAt(links.previous);
        if (!validSmallBlock(region, links.previous, previous) or isUsed(previous) or
            (previous.flags & block_flag_listed) == 0 or sizeClass(previous.block_size) != class_index or
            freeLinks(previous).next != addr)
        {
            return false;
        }
    }
    if (links.next != 0) {
        const next = headerAt(links.next);
        if (!validSmallBlock(region, links.next, next) or isUsed(next) or
            (next.flags & block_flag_listed) == 0 or sizeClass(next.block_size) != class_index or
            freeLinks(next).previous != addr)
        {
            return false;
        }
    }
    return true;
}

fn canRemoveFree(region: SmallRegion, header: *const BlockHeader) bool {
    if (freeNodeRemovable(region, header)) return true;
    return corruptFalse();
}

fn removeFree(region: *SmallRegion, header: *BlockHeader) bool {
    if (!canRemoveFree(region.*, header)) return false;
    const class_index = sizeClass(header.block_size);
    const links = freeLinks(header).*;
    if (links.previous == 0) {
        region.free_heads[class_index] = links.next;
    } else {
        freeLinks(headerAt(links.previous)).next = links.next;
    }
    if (links.next != 0) freeLinks(headerAt(links.next)).previous = links.previous;
    freeLinks(header).* = .{};
    header.flags &= ~block_flag_listed;
    return true;
}

const NeighborError = error{Corrupt};

fn previousBlock(region: SmallRegion, header_addr: usize) NeighborError!?*BlockHeader {
    if (header_addr == region.base) return null;
    state.backward_search_steps +%= 1;
    if (header_addr < region.base + @sizeOf(BlockFooter)) return corruptNeighbor();
    const footer: *const BlockFooter = @ptrFromInt(header_addr - @sizeOf(BlockFooter));
    if (footer.magic != footer_magic or footer.block_size < min_free_block or footer.block_size > header_addr - region.base) return corruptNeighbor();
    const previous_addr = header_addr - footer.block_size;
    const previous = headerAt(previous_addr);
    if (!validSmallBlock(region, previous_addr, previous) or previous_addr + previous.block_size != header_addr) return corruptNeighbor();
    return previous;
}

fn nextBlock(region: SmallRegion, header: *const BlockHeader) NeighborError!?*BlockHeader {
    const next_addr = checkedAdd(@intFromPtr(header), header.block_size) orelse return corruptNeighbor();
    const committed_end = checkedAdd(region.base, region.committed_size) orelse return corruptNeighbor();
    if (next_addr == committed_end) return null;
    if (next_addr > committed_end or next_addr + @sizeOf(BlockHeader) > committed_end) return corruptNeighbor();
    const next = headerAt(next_addr);
    if (!validSmallBlock(region, next_addr, next)) return corruptNeighbor();
    return next;
}

const LastBlock = struct {
    addr: usize,
    header: *BlockHeader,
};

fn lastBlock(region: SmallRegion) ?LastBlock {
    state.end_search_steps +%= 1;
    const end = checkedAdd(region.base, region.committed_size) orelse {
        recordCorruption();
        return null;
    };
    if (region.committed_size < min_free_block) {
        recordCorruption();
        return null;
    }
    const footer: *const BlockFooter = @ptrFromInt(end - @sizeOf(BlockFooter));
    if (footer.magic != footer_magic or footer.block_size < min_free_block or footer.block_size > region.committed_size) {
        recordCorruption();
        return null;
    }
    const addr = end - footer.block_size;
    const header = headerAt(addr);
    if (!validSmallBlock(region, addr, header) or addr + header.block_size != end) {
        recordCorruption();
        return null;
    }
    return .{ .addr = addr, .header = header };
}

fn canHoldUser(header_addr: usize, block_size: usize, user_addr: usize, len: usize) bool {
    const user_end = checkedAdd(user_addr, len) orelse return false;
    const block_end = checkedAdd(header_addr, block_size) orelse return false;
    const payload_end = checkedSub(block_end, @sizeOf(BlockFooter)) orelse return false;
    return user_end <= payload_end;
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

fn findSmallRegionContaining(addr: usize) ?usize {
    var i: usize = 0;
    while (i < state.small_regions.len) : (i += 1) {
        const region = state.small_regions[i];
        if (!region.used) continue;
        const end = checkedAdd(region.base, region.committed_size) orelse continue;
        if (addr >= region.base and addr < end) return i;
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

fn acquireAllocatorLock(api: ?*const abi.R4XStartR4Sys) void {
    while (@cmpxchgWeak(u32, &allocator_lock, 0, 1, .acquire, .monotonic) != null) {
        const table = api orelse continue;
        if (table.size < abi.r4xstart_r4sys_size or table.task_yield == 0) continue;
        vmFn(table, "task_yield")();
    }
}

fn releaseAllocatorLock() void {
    @atomicStore(u32, &allocator_lock, 0, .release);
}

fn vmReserve(api: *const abi.R4XStartR4Sys, size: usize, alignment: u64, flags: u64, out: *abi.ProgramVmRegionInfo) i32 {
    state.vm_reserve_calls +%= 1;
    return vmFn(api, "vm_reserve")(@intCast(size), alignment, flags, out);
}

fn vmCommit(api: *const abi.R4XStartR4Sys, region_id: u32, offset: usize, len: usize, flags: u64) i32 {
    state.vm_commit_calls +%= 1;
    return vmFn(api, "vm_commit")(region_id, @intCast(offset), @intCast(len), flags);
}

fn vmDecommit(api: *const abi.R4XStartR4Sys, region_id: u32, offset: usize, len: usize) i32 {
    state.vm_decommit_calls +%= 1;
    return vmFn(api, "vm_decommit")(region_id, @intCast(offset), @intCast(len));
}

fn vmRelease(api: *const abi.R4XStartR4Sys, region_id: u32) i32 {
    state.vm_release_calls +%= 1;
    return vmFn(api, "vm_release")(region_id);
}

fn validReservedRegion(info: abi.ProgramVmRegionInfo, required_size: usize, alignment: usize) bool {
    if (info.base > std.math.maxInt(usize) or info.len > std.math.maxInt(usize)) return false;
    const base: usize = @intCast(info.base);
    const len: usize = @intCast(info.len);
    return len >= required_size and (base & (alignment - 1)) == 0;
}

fn recordCorruption() void {
    state.corruptions +%= 1;
}

fn corruptNull() ?*BlockHeader {
    recordCorruption();
    return null;
}

fn corruptFalse() bool {
    recordCorruption();
    return false;
}

fn corruptNeighbor() NeighborError {
    recordCorruption();
    return error.Corrupt;
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

const test_vm_capacity: usize = small_region_reserve;
var test_vm_storage: [test_vm_capacity]u8 align(page_size) = undefined;
var test_vm_table: abi.R4XStartR4Sys = .{};
var test_vm_active: bool = false;
var test_vm_reserved_size: usize = 0;
var test_vm_committed: usize = 0;
var test_vm_fail_commit: bool = false;
var test_vm_fail_decommit: bool = false;
var test_vm_fail_release: bool = false;
var test_vm_reserve_calls: u64 = 0;
var test_vm_commit_calls: u64 = 0;
var test_vm_decommit_calls: u64 = 0;
var test_vm_release_calls: u64 = 0;

fn testVmReserve(size: u64, alignment: u64, _: u64, out: *abi.ProgramVmRegionInfo) callconv(.c) i32 {
    test_vm_reserve_calls +%= 1;
    if (test_vm_active or size > test_vm_capacity or alignment > page_size) return abi.vm_error_no_space;
    test_vm_active = true;
    test_vm_reserved_size = @intCast(size);
    test_vm_committed = 0;
    out.* = .{
        .id = 1,
        .base = @intFromPtr(&test_vm_storage),
        .len = size,
    };
    return abi.vm_ok;
}

fn testVmCommit(id: u32, offset: u64, len: u64, _: u64) callconv(.c) i32 {
    test_vm_commit_calls +%= 1;
    if (test_vm_fail_commit) return abi.vm_error_out_of_memory;
    const end = checkedAdd(@intCast(offset), @intCast(len)) orelse return abi.vm_error_invalid_range;
    if (!test_vm_active or id != 1 or len == 0 or end > test_vm_reserved_size) return abi.vm_error_invalid_range;
    if (end > test_vm_committed) test_vm_committed = end;
    return abi.vm_ok;
}

fn testVmDecommit(id: u32, offset: u64, len: u64) callconv(.c) i32 {
    test_vm_decommit_calls +%= 1;
    if (test_vm_fail_decommit) return abi.vm_error_out_of_memory;
    const end = checkedAdd(@intCast(offset), @intCast(len)) orelse return abi.vm_error_invalid_range;
    if (!test_vm_active or id != 1 or len == 0 or end > test_vm_committed) return abi.vm_error_invalid_range;
    test_vm_committed = @intCast(offset);
    return abi.vm_ok;
}

fn testVmRelease(id: u32) callconv(.c) i32 {
    test_vm_release_calls +%= 1;
    if (test_vm_fail_release) return abi.vm_error_owner_mismatch;
    if (!test_vm_active or id != 1) return abi.vm_error_invalid_range;
    test_vm_active = false;
    test_vm_reserved_size = 0;
    test_vm_committed = 0;
    return abi.vm_ok;
}

fn resetTestVm() void {
    @atomicStore(u32, &allocator_lock, 0, .release);
    state = .{};
    test_vm_table = .{};
    test_vm_table.vm_reserve = @intFromPtr(&testVmReserve);
    test_vm_table.vm_commit = @intFromPtr(&testVmCommit);
    test_vm_table.vm_decommit = @intFromPtr(&testVmDecommit);
    test_vm_table.vm_release = @intFromPtr(&testVmRelease);
    test_vm_active = false;
    test_vm_reserved_size = 0;
    test_vm_committed = 0;
    test_vm_fail_commit = false;
    test_vm_fail_decommit = false;
    test_vm_fail_release = false;
    test_vm_reserve_calls = 0;
    test_vm_commit_calls = 0;
    test_vm_decommit_calls = 0;
    test_vm_release_calls = 0;
    @memset(test_vm_storage[0 .. 2 * 1024 * 1024], 0);
}

fn expectTestRegionIntegrity(region_index: usize) !void {
    const region = state.small_regions[region_index];
    try std.testing.expect(region.used);
    const end = region.base + region.committed_size;
    var addr = region.base;
    var physical_free: usize = 0;
    var previous_was_free = false;
    while (addr < end) {
        const header = headerAt(addr);
        try std.testing.expect(validSmallBlock(region, addr, header));
        const free = !isUsed(header);
        if (free) {
            try std.testing.expect((header.flags & block_flag_listed) != 0);
            try std.testing.expect(!previous_was_free);
            physical_free += 1;
        } else {
            try std.testing.expectEqual(@as(u32, 0), header.flags & block_flag_listed);
        }
        previous_was_free = free;
        addr += header.block_size;
    }
    try std.testing.expectEqual(end, addr);

    var listed_free: usize = 0;
    for (0..size_class_count) |class_index| {
        var current = region.free_heads[class_index];
        var previous: usize = 0;
        var visits: usize = 0;
        const visit_limit = region.committed_size / min_free_block + 1;
        while (current != 0 and visits < visit_limit) : (visits += 1) {
            const header = validatedFreeNode(region, current, class_index, previous) orelse return error.CorruptMetadata;
            listed_free += 1;
            previous = current;
            current = freeLinks(header).next;
        }
        try std.testing.expectEqual(@as(usize, 0), current);
    }
    try std.testing.expectEqual(physical_free, listed_free);
}

test "VM allocator mixed fragmentation workload exposes bounded search metrics" {
    resetTestVm();

    const allocation_count = 512;
    const lengths = [_]usize{ 24, 80, 192, 512, 1536, 4096, 73, 777 };
    const alignments = [_]usize{ 8, 16, 64, 256 };
    var pointers: [allocation_count]?[*]u8 = .{null} ** allocation_count;
    var sizes: [allocation_count]usize = .{0} ** allocation_count;
    var aligns: [allocation_count]usize = .{0} ** allocation_count;

    for (0..allocation_count) |i| {
        const len = lengths[i % lengths.len];
        const alignment = alignments[i % alignments.len];
        const memory = allocatorAlloc(@ptrCast(&test_vm_table), len, .fromByteUnits(alignment), 0) orelse return error.OutOfMemory;
        try std.testing.expectEqual(@as(usize, 0), @intFromPtr(memory) & (alignment - 1));
        @memset(memory[0..len], @intCast(i % 251));
        pointers[i] = memory;
        sizes[i] = len;
        aligns[i] = alignment;
    }

    for (0..allocation_count) |i| {
        if ((i & 1) != 0) continue;
        const memory = pointers[i].?;
        allocatorFree(@ptrCast(&test_vm_table), memory[0..sizes[i]], .fromByteUnits(aligns[i]), 0);
        pointers[i] = null;
    }

    const frees_before_repeat = stats().frees;
    const first_backref_addr = state.small_regions[0].base + @sizeOf(BlockHeader);
    const first_user_addr = alignForward(first_backref_addr + @sizeOf(usize), aligns[0]).?;
    const first_freed: [*]u8 = @ptrFromInt(first_user_addr);
    allocatorFree(@ptrCast(&test_vm_table), first_freed[0..sizes[0]], .fromByteUnits(aligns[0]), 0);
    try std.testing.expectEqual(frees_before_repeat, stats().frees);

    for (0..allocation_count) |i| {
        if ((i & 1) != 0) continue;
        const memory = allocatorAlloc(@ptrCast(&test_vm_table), sizes[i], .fromByteUnits(aligns[i]), 0) orelse return error.OutOfMemory;
        try std.testing.expectEqual(@as(usize, 0), @intFromPtr(memory) & (aligns[i] - 1));
        pointers[i] = memory;
    }

    for (0..allocation_count) |i| {
        if ((i & 1) == 0) continue;
        for (pointers[i].?[0..sizes[i]]) |byte| try std.testing.expectEqual(@as(u8, @intCast(i % 251)), byte);
    }

    const measured = stats();
    // The instrumented legacy First-Fit implementation needed 197746 block,
    // 63213 backward and 131152 region-end visits for this exact workload.
    try std.testing.expectEqual(@as(u64, allocation_count + allocation_count / 2), measured.allocations);
    try std.testing.expectEqual(@as(u64, allocation_count / 2), measured.frees);
    try std.testing.expectEqual(@as(u64, allocation_count), measured.active_allocations);
    try std.testing.expect(measured.allocation_search_steps <= allocation_count * 2);
    try std.testing.expect(measured.class_search_steps <= measured.allocations * size_class_count);
    try std.testing.expect(measured.backward_search_steps <= measured.frees);
    try std.testing.expect(measured.end_search_steps <= measured.frees + measured.vm_commit_calls);
    try std.testing.expectEqual(@as(u64, 0), measured.corruptions);
    try std.testing.expectEqual(@as(u64, 1), test_vm_reserve_calls);
    try std.testing.expectEqual(test_vm_reserve_calls, measured.vm_reserve_calls);
    try std.testing.expectEqual(test_vm_commit_calls, measured.vm_commit_calls);
    try std.testing.expectEqual(test_vm_decommit_calls, measured.vm_decommit_calls);
    try std.testing.expectEqual(test_vm_release_calls, measured.vm_release_calls);
    try expectTestRegionIntegrity(0);

    for (0..allocation_count) |i| {
        const memory = pointers[i].?;
        allocatorFree(@ptrCast(&test_vm_table), memory[0..sizes[i]], .fromByteUnits(aligns[i]), 0);
    }
    const complete = stats();
    try std.testing.expectEqual(@as(u64, allocation_count + allocation_count / 2), complete.frees);
    try std.testing.expectEqual(@as(u64, 0), complete.active_allocations);
    try std.testing.expect(complete.coalesces > 0);
    try std.testing.expectEqual(@as(u64, 0), complete.corruptions);
    try expectTestRegionIntegrity(0);
}

test "VM allocator rolls back VM failures and preserves direct ownership" {
    resetTestVm();
    test_vm_fail_commit = true;
    try std.testing.expectEqual(@as(?[*]u8, null), allocatorAlloc(@ptrCast(&test_vm_table), 128, .fromByteUnits(16), 0));
    try std.testing.expect(!test_vm_active);
    try std.testing.expectEqual(@as(u64, 1), test_vm_reserve_calls);
    try std.testing.expectEqual(@as(u64, 1), test_vm_commit_calls);
    try std.testing.expectEqual(@as(u64, 1), test_vm_release_calls);
    try std.testing.expectEqual(@as(u32, 0), stats().small_regions);

    resetTestVm();
    const small = allocatorAlloc(@ptrCast(&test_vm_table), 128, .fromByteUnits(16), 0) orelse return error.OutOfMemory;
    const committed_before_failure = state.small_regions[0].committed_size;
    test_vm_fail_commit = true;
    try std.testing.expectEqual(@as(?[*]u8, null), allocatorAlloc(@ptrCast(&test_vm_table), 32 * 1024, .fromByteUnits(64), 0));
    try std.testing.expectEqual(committed_before_failure, state.small_regions[0].committed_size);
    try std.testing.expectEqual(@as(u64, 1), stats().active_allocations);
    try expectTestRegionIntegrity(0);

    test_vm_fail_commit = false;
    const large_small = allocatorAlloc(@ptrCast(&test_vm_table), 32 * 1024, .fromByteUnits(64), 0) orelse return error.OutOfMemory;
    const committed_before_decommit = state.small_regions[0].committed_size;
    test_vm_fail_decommit = true;
    allocatorFree(@ptrCast(&test_vm_table), large_small[0 .. 32 * 1024], .fromByteUnits(64), 0);
    try std.testing.expectEqual(committed_before_decommit, state.small_regions[0].committed_size);
    try std.testing.expectEqual(@as(u64, 1), stats().active_allocations);
    try expectTestRegionIntegrity(0);
    test_vm_fail_decommit = false;
    allocatorFree(@ptrCast(&test_vm_table), small[0..128], .fromByteUnits(16), 0);
    try std.testing.expectEqual(@as(u64, 0), stats().active_allocations);
    try expectTestRegionIntegrity(0);

    resetTestVm();
    const resized = allocatorAlloc(@ptrCast(&test_vm_table), 256, .fromByteUnits(64), 0) orelse return error.OutOfMemory;
    @memset(resized[0..256], 0x5A);
    try std.testing.expect(allocatorResize(@ptrCast(&test_vm_table), resized[0..256], .fromByteUnits(64), 48 * 1024, 0));
    for (resized[0..256]) |byte| try std.testing.expectEqual(@as(u8, 0x5A), byte);
    try std.testing.expect(allocatorResize(@ptrCast(&test_vm_table), resized[0 .. 48 * 1024], .fromByteUnits(64), 64, 0));
    try std.testing.expectEqual(@as(u64, 64), stats().active_bytes);
    allocatorFree(@ptrCast(&test_vm_table), resized[0..64], .fromByteUnits(64), 0);
    try std.testing.expectEqual(@as(u64, 0), stats().active_allocations);
    try expectTestRegionIntegrity(0);

    resetTestVm();
    const direct_len = large_threshold;
    const direct = allocatorAlloc(@ptrCast(&test_vm_table), direct_len, .fromByteUnits(64), 0) orelse return error.OutOfMemory;
    @memset(direct[0..256], 0xA5);
    try std.testing.expectEqual(@as(u32, 1), stats().direct_active);
    try std.testing.expect(allocatorResize(@ptrCast(&test_vm_table), direct[0..direct_len], .fromByteUnits(64), direct_len / 2, 0));
    try std.testing.expectEqual(@as(u64, direct_len / 2), stats().active_bytes);
    for (direct[0..256]) |byte| try std.testing.expectEqual(@as(u8, 0xA5), byte);

    test_vm_fail_release = true;
    allocatorFree(@ptrCast(&test_vm_table), direct[0 .. direct_len / 2], .fromByteUnits(64), 0);
    try std.testing.expectEqual(@as(u32, 1), stats().direct_active);
    try std.testing.expect(test_vm_active);
    test_vm_fail_release = false;
    allocatorFree(@ptrCast(&test_vm_table), direct[0 .. direct_len / 2], .fromByteUnits(64), 0);
    try std.testing.expectEqual(@as(u32, 0), stats().direct_active);
    try std.testing.expect(!test_vm_active);
    try std.testing.expectEqual(test_vm_reserve_calls, stats().vm_reserve_calls);
    try std.testing.expectEqual(test_vm_commit_calls, stats().vm_commit_calls);
    try std.testing.expectEqual(test_vm_release_calls, stats().vm_release_calls);
}

test "VM allocator rejects damaged boundary tags and repeated frees fail closed" {
    resetTestVm();
    const first = allocatorAlloc(@ptrCast(&test_vm_table), 192, .fromByteUnits(64), 0) orelse return error.OutOfMemory;
    const second = allocatorAlloc(@ptrCast(&test_vm_table), 96, .fromByteUnits(16), 0) orelse return error.OutOfMemory;
    const header = headerFromUser(first, 64) orelse return error.MissingHeader;
    const footer = footerFromHeader(header);

    footer.magic = 0;
    allocatorFree(@ptrCast(&test_vm_table), first[0..192], .fromByteUnits(64), 0);
    try std.testing.expectEqual(@as(u64, 1), stats().corruptions);
    try std.testing.expectEqual(@as(u64, 2), stats().active_allocations);
    footer.magic = footer_magic;

    header.magic = 0;
    allocatorFree(@ptrCast(&test_vm_table), first[0..192], .fromByteUnits(64), 0);
    try std.testing.expectEqual(@as(u64, 2), stats().corruptions);
    try std.testing.expectEqual(@as(u64, 2), stats().active_allocations);
    header.magic = block_magic;

    allocatorFree(@ptrCast(&test_vm_table), first[0..192], .fromByteUnits(64), 0);
    const after_first_free = stats();
    try std.testing.expectEqual(@as(u64, 1), after_first_free.frees);
    allocatorFree(@ptrCast(&test_vm_table), first[0..192], .fromByteUnits(64), 0);
    try std.testing.expectEqual(after_first_free.frees, stats().frees);
    try std.testing.expectEqual(after_first_free.corruptions, stats().corruptions);

    allocatorFree(@ptrCast(&test_vm_table), second[0..96], .fromByteUnits(16), 0);
    try std.testing.expectEqual(@as(u64, 0), stats().active_allocations);
    try std.testing.expectEqual(@as(u64, 2), stats().corruptions);
    try expectTestRegionIntegrity(0);
}

fn concurrentAllocatorWorker(worker_index: usize, failed: *u32) void {
    const slot_count = 32;
    var pointers: [slot_count]?[*]u8 = .{null} ** slot_count;
    var sizes: [slot_count]usize = .{0} ** slot_count;
    var alignments: [slot_count]usize = .{0} ** slot_count;
    var patterns: [slot_count]u8 = .{0} ** slot_count;
    var value: u64 = 0x9E3779B97F4A7C15 ^ @as(u64, worker_index + 1);

    var operation: usize = 0;
    while (operation < 4096 and @atomicLoad(u32, failed, .acquire) == 0) : (operation += 1) {
        value = value *% 6364136223846793005 +% 1442695040888963407;
        const slot: usize = @intCast((value >> 32) % slot_count);
        if (pointers[slot]) |memory| {
            const last = sizes[slot] - 1;
            if (memory[0] != patterns[slot] or memory[last] != patterns[slot]) {
                @atomicStore(u32, failed, 1, .release);
                break;
            }
            allocatorFree(@ptrCast(&test_vm_table), memory[0..sizes[slot]], .fromByteUnits(alignments[slot]), 0);
            pointers[slot] = null;
        } else {
            const len = 1 + @as(usize, @intCast((value >> 16) % 8192));
            const worker_alignments = [_]usize{ 8, 16, 64, 256 };
            const alignment = worker_alignments[@as(usize, @intCast(value & 3))];
            const memory = allocatorAlloc(@ptrCast(&test_vm_table), len, .fromByteUnits(alignment), 0) orelse {
                @atomicStore(u32, failed, 1, .release);
                break;
            };
            const pattern: u8 = @intCast((worker_index * 37 + operation) % 251);
            @memset(memory[0..len], pattern);
            pointers[slot] = memory;
            sizes[slot] = len;
            alignments[slot] = alignment;
            patterns[slot] = pattern;
        }
    }

    for (0..slot_count) |slot| {
        if (pointers[slot]) |memory| {
            allocatorFree(@ptrCast(&test_vm_table), memory[0..sizes[slot]], .fromByteUnits(alignments[slot]), 0);
        }
    }
}

test "VM allocator serializes concurrent R4X thread traffic" {
    resetTestVm();
    var failed: u32 = 0;
    var threads: [4]std.Thread = undefined;
    for (&threads, 0..) |*thread, worker_index| {
        thread.* = try std.Thread.spawn(.{}, concurrentAllocatorWorker, .{ worker_index, &failed });
    }
    for (&threads) |*thread| thread.join();

    try std.testing.expectEqual(@as(u32, 0), @atomicLoad(u32, &failed, .acquire));
    try std.testing.expectEqual(@as(u64, 0), stats().active_allocations);
    try std.testing.expectEqual(@as(u64, 0), stats().corruptions);
    try expectTestRegionIntegrity(0);
}

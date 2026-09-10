const abi = @import("r4os_contract").abi;
const program = @import("program.zig");
pub const Context = struct {
    base: program.Context,
    pub fn revision(self: *const Context, output: *abi.GfxDisplayRevision) i32 { return self.base.gfxOutputRevision(output); }
    pub fn info(self: *const Context, index: u32, output: *abi.GfxOutputInfo) i32 { return self.base.gfxOutputInfo(index, output); }
    pub fn mode(self: *const Context, identity: *const abi.GfxOutputId, index: u32, output: *abi.GfxOutputMode) i32 { return self.base.gfxOutputMode(identity, index, output); }
    pub fn edid(self: *const Context, identity: *const abi.GfxOutputId, index: u32, output: *abi.GfxEdidBlock) i32 { return self.base.gfxOutputEdid(identity, index, output); }
    pub fn testState(self: *const Context, state: *const abi.GfxAtomicState, output: *abi.GfxAtomicResult) i32 { return self.base.gfxAtomicTest(state, output); }
    pub fn commit(self: *const Context, state: *const abi.GfxAtomicState, output: *abi.GfxAtomicResult) i32 { return self.base.gfxAtomicCommit(state, output); }
};

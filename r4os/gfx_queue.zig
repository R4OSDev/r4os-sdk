const abi = @import("r4os_contract").abi;
const program = @import("program.zig");

pub const Context = struct {
    base: program.Context,
    pub fn backend(self: *const Context, index: u32, output: *abi.GfxBackendBinding) i32 {
        return self.base.gfxQueueBackend(index, output);
    }
    pub fn backendInfo(self: *const Context, index: u32, output: *abi.GfxBackendInfo) i32 {
        return self.base.gfxQueueBackendInfo(index, output);
    }

    pub fn open(self: *const Context, config: *const abi.GfxQueueConfig, output: *abi.GfxQueueHandle) i32 {
        return self.base.gfxQueueOpen(config, output);
    }

    pub fn close(self: *const Context, queue: *const abi.GfxQueueHandle) i32 {
        return self.base.gfxQueueClose(queue);
    }

    pub fn submit(self: *const Context, queue: *const abi.GfxQueueHandle, submission: *const abi.GfxSubmission, output: *abi.GfxFenceStatus) i32 {
        return self.base.gfxQueueSubmit(queue, submission, output);
    }
    pub fn submitRenderList(self: *const Context, queue: *const abi.GfxQueueHandle, submission: *const abi.GfxSubmission, list: *const abi.GfxRenderList, output: *abi.GfxFenceStatus) i32 {
        return self.base.gfxQueueSubmitRenderList(queue, submission, list, output);
    }
    pub fn submitRenderGridList(self: *const Context, queue: *const abi.GfxQueueHandle, submission: *const abi.GfxSubmission, list: *const abi.GfxRenderGridList, output: *abi.GfxFenceStatus) i32 {
        return self.base.gfxQueueSubmitRenderGridList(queue, submission, list, output);
    }

    pub fn submitOutput(self: *const Context, queue: *const abi.GfxQueueHandle, submission: *const abi.GfxSubmission, target: *const abi.GfxOutputTarget, output: *abi.GfxFenceStatus) i32 {
        return self.base.gfxQueueSubmitOutput(queue, submission, target, output);
    }
    pub fn query(self: *const Context, fence: *const abi.GfxFence, output: *abi.GfxFenceStatus) i32 {
        return self.base.gfxFenceQuery(fence, output);
    }

    pub fn wait(self: *const Context, fence: *const abi.GfxFence, timeout_ticks: u64, wait_for: u32, output: *abi.GfxFenceStatus) i32 {
        return self.base.gfxFenceWait(fence, timeout_ticks, wait_for, output);
    }

    pub fn cancel(self: *const Context, fence: *const abi.GfxFence) i32 {
        return self.base.gfxFenceCancel(fence);
    }

    pub fn release(self: *const Context, fence: *const abi.GfxFence) i32 {
        return self.base.gfxFenceRelease(fence);
    }
};

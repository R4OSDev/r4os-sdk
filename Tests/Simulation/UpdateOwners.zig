//! Current transaction/metadata owner cases in the SDK package root.
const std = @import("std");
const sdk = @import("../../r4os.zig");
test {
    inline for (.{ sdk.version_info, sdk.r4u_manifest, sdk.r4u_artifact, sdk.system_update_inventory, sdk.system_update_recovery, sdk.system_update_batch, sdk.system_update_backup, sdk.update_catalog }) |M| std.testing.refAllDecls(M);
}

# R4OS SDK

The host-neutral R4OS SDK provides Zig and C startup code, platform facades,
module build support, templates, build profiles, and generic Runtime-R4L
helpers. The platform API and ABI remain canonical in the separate Contract
repository.

Subsystem R4X hosts can compose the allocation-free `subsystem_host` video
and input layer with `subsystem_runtime` for bounded guest slices, monotonic
guest time, lifecycle control, paced frames, and buffered S16LE audio through
the regular app audio facade.

## Dependency mapping

`Settings.R4S` maps the local Contract and workspace paths. Relative and
absolute mappings are supported. Use the repository build starters so those
mappings are applied before Zig resolves packages.

## Build and validation

On Windows:

    Build.bat test

On Linux or macOS:

    ./Build.sh test

Detailed German migration notes are preserved in
`DOCUMENTATION.de.txt`.

## License

Original R4OS material is licensed under Apache License 2.0. See `LICENSE`,
`NOTICE`, and `THIRD_PARTY_NOTICES.md`.

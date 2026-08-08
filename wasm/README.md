# PHPX WASI SDK

PHPX is the canonical installation root for the TypePHP `wasm32-wasip2` SDK:

```text
phpx/wasm/wasm32-wasip2/
├── include/
├── lib/
└── .typephp-wasi-sdk-abi
```

Release packages populate this directory with the PHP, PHPX, GMP, MPFR, and
mpdecimal headers and static archives. Locally built SDK artifacts are ignored
by Git. TypePHP locates this directory through the existing PHPX resolution
rules (`PHPX_HOME`, Composer package metadata, then `vendor/swoole/phpx`) and
does not define a separate WASI SDK environment variable.

Language-level WIT exports additionally use a host-side generator shipped by
the PHPX package:

```text
phpx/wasm/bin/
├── linux-x86_64/wit-bindgen
├── linux-aarch64/wit-bindgen
├── macos-x86_64/wit-bindgen
├── macos-arm64/wit-bindgen
└── windows-x86_64/wit-bindgen.exe
```

This is a build tool, not a PHPX runtime facility. It is intentionally not
linked into `libphpx.so`, `phpx.dll`, or `wasm32-wasip2/lib/libphpx.a`.
`tpc` locates the matching binary relative to `PHPX_HOME` (which takes
precedence) or the Composer PHPX directory. Users do not install Rust,
`wit-bindgen`, or `wasm-tools`.

TypePHP invokes the pinned upstream C generator internally:

```text
wit-bindgen c --world <world> --rename-world <c-name> \
  --out-dir <dir> <world.wit>
```

The generator version is pinned by the PHPX release. Its manifest schema is an
internal PHPX/TypePHP ABI and may only change together with their bound
versions. Generated source is cached by the WIT contents, manifest schema, and
generator version.

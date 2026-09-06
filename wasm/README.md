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

Language-level WIT exports additionally use the host-side
`wit-bindgen-cli 0.60.0` executable from `PATH`. This is an application build
tool, not a PHPX runtime facility: PHPX does not package it and it is not
linked into `libphpx.so`, `phpx.dll`, or `wasm32-wasip2/lib/libphpx.a`.
Command components do not require `wit-bindgen`.

TypePHP invokes the pinned upstream C generator internally:

```text
wit-bindgen c --world <world> --rename-world <c-name> \
  --out-dir <dir> <world.wit>
```

TypePHP validates the generator version before a library build. Its manifest
schema is an internal PHPX/TypePHP ABI and may only change together with their
bound versions.

## Building PHPX/WASI

PHPX owns the GMP, MPFR, and mpdecimal dependencies used by TypePHP's BigInt,
BigFloat, and Decimal types. Build and install the PHPX portion of an SDK with:

```shell
./wasm/build.sh \
    --prefix /path/to/phpx/wasm/wasm32-wasip2 \
    --jobs 16
```

The prefix must already contain the PHP/WASI headers installed by the matching
php-src build. `build-deps.sh` downloads pinned GMP and MPFR releases and
verifies their checksums. mpdecimal is never downloaded: CMake builds the
version in `thirdparty/mpdecimal` from a build-tree copy.

### CMake only

PHPX uses a separate CMake project for the WASI Preview 2 static library. The
host `CMakeLists.txt` is intentionally independent because its PHP discovery,
shared-library targets, and tests do not apply to WASI.

Configure with the `wasi-sdk-p2.cmake` toolchain supplied by WASI SDK. The PHP,
GMP, and MPFR dependency headers must already be installed in
`wasm/wasm32-wasip2`, or in the prefix passed as `PHPX_WASI_SDK_DIR`:

```shell
cmake -S wasm -B build/wasm32-wasip2 -G Ninja \
    -DCMAKE_TOOLCHAIN_FILE=/path/to/wasi-sdk/share/cmake/wasi-sdk-p2.cmake \
    -DCMAKE_BUILD_TYPE=Release \
    -DCMAKE_INSTALL_PREFIX="$PWD/wasm/wasm32-wasip2"
cmake --build build/wasm32-wasip2 --parallel
cmake --install build/wasm32-wasip2
```

The build compiles PHPX's vendored mpdecimal into `libmpdec.a` and
`libmpdec++.a`, then compiles PHPX core and `src/std` with C++17 and
WebAssembly exception support. Test-only helpers and shared-library glue are
not part of the WASI archive.

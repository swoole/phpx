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
Facade API, shared-library targets, and tests do not apply to WASI.

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
WebAssembly exception support. The class/function/constant Facade API and its
generated literal table are not part of the WASI archive.

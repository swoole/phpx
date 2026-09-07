# PHPX iPhoneOS SDK

PHPX is the canonical installation root for the physical-device iOS SDK:

```text
phpx/ios/iphoneos-arm64/
├── include/
│   ├── php/
│   └── phpx/
├── lib/
│   ├── libphp.a
│   ├── libphpx.a
│   ├── libgmp.a
│   ├── libgmpxx.a
│   └── libmpfr.a
└── .typephp-ios-sdk-abi
```

This follows the same integrated-prefix rule as `full-static/sdk` and
`wasm/wasm32-wasip2`: target headers and archives are selected together from
the PHPX checkout. TypePHP does not use `PHP_HOME` for an iPhoneOS target and
must never mix these files with macOS/Homebrew libraries.

The PHP, GMP, and MPFR target files are built by the SDK producer. The staging
step also writes `.typephp-ios-php-abi`; PHPX requires this marker and a ZTS
`php_config.h` before it accepts the prefix. Once those files have been
installed, build the PHPX portion on macOS with full Xcode:

```sh
./ios/build.sh --jobs 8
```

The script reuses `full-static/CMakeLists.txt` with CMake's iOS toolchain
settings, installs `libphpx.a` and PHPX headers into the prefix, validates its
architecture, and writes the SDK ABI marker. Apple libc, libc++, Foundation,
and UIKit are not copied into static archives; the final application links
them from the selected iPhoneOS SDK.

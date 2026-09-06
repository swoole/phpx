# CLAUDE.md

This file provides guidance to Claude Code (claude.ai/code) when working with code in this repository.

## Project

PHPX is a C++17 wrapper library for the Zend Engine API, enabling development of PHP extensions in modern C++ with RAII, type-safe wrappers, and an object-oriented API. Requires PHP 8.2+.

## Build

```bash
# Standard build
cmake . && make -j$(nproc)
sudo make install && sudo ldconfig

# Debug build (symbols, no optimization, runtime checks)
cmake -DCMAKE_BUILD_TYPE=Debug . && make -j$(nproc)

# Coverage build
cmake -DCODE_COVERAGE=ON . && make -j$(nproc)

# ASAN build
cmake -Denable_asan=ON . && make -j$(nproc)
```

Build outputs go to `lib/` (libphpx.so, ext.so) and `bin/` (phpx-tests).

## Testing

```bash
# C++ tests (Google Test via PHP embed)
./bin/phpx-tests                           # all tests
./bin/phpx-tests --gtest_filter="variant.*" # filter
./bin/phpx-tests --gtest_list_tests        # list

# PHP tests (PHPUnit — requires ext.so loaded)
composer test

# In CI, ext.so is copied to PHP extension dir first:
sudo cp lib/ext.so $(php-config --extension-dir)/phpx_test.so
```

Test infrastructure uses PHP Embed SAPI — `tests/src/main.cpp` bootstraps `php_embed_init`, runs GTest inside a PHP eval, then shuts down. The `try_call` helper asserts exception messages match expected strings.

## Code formatting

```bash
./format.sh   # clang-format -i on src/core/*.cc include/*.h tests/src/*.cpp
```

Based on Google style, 120 cols, 4-space indent (see `.clang-format`).

## Architecture

### Layers

```
PHP Extension ── PHPX core type wrappers ── Zend Engine API
```

### Core types (`include/phpx.h`, `src/core/`)

All live in `namespace php`. The primary wrapper types:

- **`Variant`** — universal zval wrapper, the central type. Supports construction from all PHP scalar types, type checking (`isString()`, `isInt()`, …), conversion (`toString()`, `toInt()`, …), and operator overloading. Uses RAII with `zval_ptr_dtor` on destruction.
- **`Array`** — `zend_array` wrapper. `set(key, val)`, `get(key)`, `exists()`, `append()`, `count()`, `foreach(lambda)`, `operator[]`. Initializer-list construction: `Array{1, 2, 3}` or `Array{{"k1", v1}, {"k2", v2}}`.
- **`Object`** — wraps `zend_object`. `newObject("ClassName", args)`, `call("method", args)`, `getProperty()`/`setProperty()`, `callStatic()`.
- **`String`** — `zend_string` wrapper. `length()`, `toStdString()`, `toCString()`.
- **`Reference`** — needed when passing arrays to PHP functions that modify them (e.g., `php::sort(arr.toReference())`).
- **`Box`** — Stores a C++ pointer as a PHP resource, enabling with-construct/destruct lifecycle.
- **`Closure`** — wraps a C++ lambda into a PHP callable.

**Critical rule**: PHP headers must always be wrapped in `extern "C" {}`. See `include/phpx.h:23`.

### Extension API (`include/phpx_ext.h`, `src/core/extension.cc`)

```cpp
PHPX_EXTENSION() {
    Extension *ext = new Extension("name", "1.0.0");
    ext->onStart = [ext]() noexcept {
        // Register classes, functions, constants
    };
    return ext;
}
```

Macros: `PHPX_FUNCTION(name)` for functions, `PHPX_METHOD(Class, method)` for methods. `PHPX_FN(fn)` / `PHPX_ME(Class, method)` for registration.

### PHP calls

Use `php::call()`, `Object::call()`, and `callStaticMethod()` for dynamic PHP
calls. The small facade under `tests/include/` is test-only and must not be
used by production code.

### gen_stub.php

Arginfo headers are generated with the `gen_stub.php` supplied by the matching
PHP development package. PHPX does not maintain a separate copy.

## CI

GitHub Actions (`.github/workflows/test.yml`): tests against PHP 8.4–8.5. Builds with coverage, runs `phpx-tests` (GTest) then `composer test` (PHPUnit), uploads coverage to Codecov.

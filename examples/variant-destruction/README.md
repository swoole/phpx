# Scalar Variant destruction benchmark

Each iteration constructs and destroys an integer Variant and accumulates a
checksum. This isolates scalar temporary lifetime overhead. Scalars require no
PHP request initialization in this benchmark; it performs no PHP allocation or
user-code invocation.

From this directory, with PHPX and a matching PHP embed library built:

```sh
c++ -O2 -std=c++17 benchmark.cc -I../../include $(php-config --includes) \
  -L../../lib -L"$(php-config --prefix)/lib" -lphpx -lphp -o benchmark
LD_LIBRARY_PATH="../../lib:$(php-config --prefix)/lib" ./benchmark 100000000
```

Expected checksum: `4950000000`. For comparison, build baseline and candidate
PHPX with identical flags, preserve each library in a separate directory, and
run the same benchmark binary with `LD_LIBRARY_PATH` selecting each library.
No `LD_PRELOAD` override is used. Alternate execution order, discard warm-up
runs, and compare medians. Exclude compilation time.

## Sample result

Linux ARM64 in Docker, PHP 8.5.10 ZTS, PHPX Release build (`-O3 -DNDEBUG`),
benchmark `-O2`; baseline PHPX `b5231cd` versus the refcounted-value guard.
Nine measured runs per library, 100 million iterations:

| Library | Median |
| --- | ---: |
| Baseline | 213.95 ms |
| Refcounted guard | 101.77 ms |

Elapsed time decreased 52.43% in this scalar-heavy microbenchmark, with all nine
pairs faster and matching checksums. It is not an application-wide speedup.
Measurements include process startup on a shared development machine. Raw
samples in seconds are in `results-arm64.json`.

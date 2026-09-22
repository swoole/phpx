# Variadic array_merge benchmark

Measures merging 2, 8, or 32 copies of a 1,024-element array, 1,000 times.
The mixed case adds a string key, forcing mixed hash-table storage while also
exercising replacement of the same string key. Input construction and PHP
startup are outside the timed region; result destruction is included.

From this directory, with PHPX and a matching PHP embed library built:

```sh
mkdir -p build
c++ -O3 -DNDEBUG -std=c++17 benchmark.cc -I../../include $(php-config --includes) \
  -L../../lib -L"$(php-config --prefix)/lib" -lphpx -lphp -o build/benchmark
LD_LIBRARY_PATH="../../lib:$(php-config --prefix)/lib" ./build/benchmark
```

The variadic overload is a header template: recompile the benchmark for each
revision. This change leaves the shared library unchanged, so the same library
can be used with both benchmark executables. The baseline does not contain this
new benchmark source. To compare from the candidate repository root, keep the
source fixed and extract the baseline headers separately:

```sh
bench_dir=$(mktemp -d)
git archive 864aed3 include | tar -x -C "$bench_dir"
cp examples/array-merge/benchmark.cc "$bench_dir/benchmark.cc"
c++ -O3 -DNDEBUG -std=c++17 "$bench_dir/benchmark.cc" \
  -I"$bench_dir/include" $(php-config --includes) \
  -Llib -L"$(php-config --prefix)/lib" -lphpx -lphp -o "$bench_dir/before"
c++ -O3 -DNDEBUG -std=c++17 "$bench_dir/benchmark.cc" \
  -Iinclude $(php-config --includes) \
  -Llib -L"$(php-config --prefix)/lib" -lphpx -lphp -o "$bench_dir/after"
LD_LIBRARY_PATH="$(pwd)/lib:$(php-config --prefix)/lib" "$bench_dir/before"
LD_LIBRARY_PATH="$(pwd)/lib:$(php-config --prefix)/lib" "$bench_dir/after"
```

Warm up both executables, then interleave runs and compare medians. The
two-input cases provide a control; they do not use the variadic overload.

Each packed checksum is `1000 * 1024 * array_count`. Each mixed checksum adds
1,000 because only one copy of the string key survives. Checksums must match
between revisions. This is a microbenchmark, not an application-wide speedup.

## Sample result

Linux ARM64 Docker, PHP 8.5.10 ZTS, GCC 14.2, Release PHPX; benchmark flags as
above. Baseline: `864aed3`; candidate: direct append to the separated result.
Five measured runs per executable after warm-up:

| Input | Arrays | Baseline median (ms) | Candidate median (ms) | Speedup |
| --- | ---: | ---: | ---: | ---: |
| Packed | 2 | 1.251 | 1.229 | 1.02x |
| Packed | 8 | 23.207 | 5.973 | 3.89x |
| Packed | 32 | 336.895 | 24.257 | 13.89x |
| Mixed | 2 | 8.391 | 8.250 | 1.02x |
| Mixed | 8 | 106.612 | 44.177 | 2.41x |
| Mixed | 32 | 1426.960 | 264.131 | 5.40x |

Raw timings and checksums are in `results-arm64.txt`.

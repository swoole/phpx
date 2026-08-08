#!/usr/bin/env bash

set -euo pipefail

script_dir=$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)

usage()
{
    cat <<'EOF'
Usage: ./build.sh --prefix <wasm32-wasip2-sdk-dir> [options]

Options:
  --prefix <dir>     Required SDK installation prefix
  --build-dir <dir>  Build root (default: /tmp/phpx-wasip2-build)
  --jobs <number>    Parallel build jobs (default: 8)
  -h, --help         Show this help
EOF
}

prefix=
build_root=${PHPX_WASM_BUILD_DIR:-/tmp/phpx-wasip2-build}
jobs=${PHPX_WASM_JOBS:-8}

while [[ $# -gt 0 ]]; do
    case "$1" in
        --prefix)
            [[ $# -ge 2 ]] || { echo "--prefix requires a directory" >&2; exit 2; }
            prefix=$2
            shift 2
            ;;
        --prefix=*) prefix=${1#*=}; shift ;;
        --build-dir)
            [[ $# -ge 2 ]] || { echo "--build-dir requires a directory" >&2; exit 2; }
            build_root=$2
            shift 2
            ;;
        --build-dir=*) build_root=${1#*=}; shift ;;
        --jobs|-j)
            [[ $# -ge 2 ]] || { echo "$1 requires a number" >&2; exit 2; }
            jobs=$2
            shift 2
            ;;
        --jobs=*|-j*) jobs=${1#*=}; jobs=${jobs#-j}; shift ;;
        -h|--help) usage; exit 0 ;;
        *) echo "Unknown option: $1" >&2; usage >&2; exit 2 ;;
    esac
done

if [[ -z "${prefix}" ]]; then
    echo "--prefix is required" >&2
    usage >&2
    exit 2
fi
if [[ ! "${jobs}" =~ ^[1-9][0-9]*$ ]]; then
    echo "Invalid --jobs value: ${jobs}" >&2
    exit 2
fi

mkdir -p "${prefix}" "${build_root}"
prefix=$(cd "${prefix}" && pwd)
build_root=$(cd "${build_root}" && pwd)

PHPX_WASM_DEPS_WORK_DIR="${build_root}/deps" \
PHPX_WASM_DEPS_PREFIX="${prefix}" \
PHPX_WASM_JOBS="${jobs}" \
    "${script_dir}/build-deps.sh"

source "${script_dir}/toolchain.sh"
wasi_resource_dir=$("${wasi_cxx}" --print-resource-dir)
wasi_sdk_root=$(cd "${wasi_resource_dir}/../../.." && pwd)
wasi_cmake_toolchain=${wasi_sdk_root}/share/cmake/wasi-sdk-p2.cmake
if [[ ! -f "${wasi_cmake_toolchain}" ]]; then
    echo "WASI SDK Preview 2 CMake toolchain was not found: ${wasi_cmake_toolchain}" >&2
    exit 1
fi

cmake_generator=()
if command -v ninja >/dev/null 2>&1; then
    cmake_generator=(-G Ninja)
fi

cmake -S "${script_dir}" -B "${build_root}/cmake" \
    "${cmake_generator[@]}" \
    -DCMAKE_TOOLCHAIN_FILE="${wasi_cmake_toolchain}" \
    -DCMAKE_BUILD_TYPE=Release \
    -DPHPX_WASI_SDK_DIR="${prefix}" \
    -DCMAKE_INSTALL_PREFIX="${prefix}"
cmake --build "${build_root}/cmake" --parallel "${jobs}"
cmake --install "${build_root}/cmake"

required_files=(
    include/phpx/phpx.h
    include/phpx/typephp_helper.h
    include/gmp.h
    include/mpfr.h
    include/mpdecimal.h
    include/decimal.hh
    lib/libphpx.a
    lib/libgmp.a
    lib/libgmpxx.a
    lib/libmpfr.a
    lib/libmpdec.a
    lib/libmpdec++.a
)
for file in "${required_files[@]}"; do
    if [[ ! -f "${prefix}/${file}" ]]; then
        echo "PHPX WASI installation is incomplete: ${prefix}/${file}" >&2
        exit 1
    fi
done

echo "Installed PHPX WASI libraries: ${prefix}"

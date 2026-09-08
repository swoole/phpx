#!/usr/bin/env bash

set -euo pipefail

script_dir=$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)
phpx_root=$(cd "${script_dir}/.." && pwd)

usage()
{
    cat >&2 <<'EOF'
Usage: sdk/build-native.sh --prefix <runtime-layer-dir> --target <target> [options]

Targets: linux-x64, linux-arm64, iphoneos-arm64, android-arm64-v8a
Options:
  --build-dir <dir>  CMake build directory
  --jobs <number>    Parallel build jobs (default: 4)
EOF
}

prefix=
target=
build_dir=
jobs=${PHPX_SDK_JOBS:-4}

while [[ $# -gt 0 ]]; do
    case "$1" in
        --prefix) prefix=${2:?}; shift 2 ;;
        --prefix=*) prefix=${1#*=}; shift ;;
        --target) target=${2:?}; shift 2 ;;
        --target=*) target=${1#*=}; shift ;;
        --build-dir) build_dir=${2:?}; shift 2 ;;
        --build-dir=*) build_dir=${1#*=}; shift ;;
        --jobs|-j) jobs=${2:?}; shift 2 ;;
        --jobs=*|-j*) jobs=${1#*=}; jobs=${jobs#-j}; shift ;;
        -h|--help) usage; exit 0 ;;
        *) echo "Unknown option: $1" >&2; usage; exit 2 ;;
    esac
done

if [[ -z "${prefix}" || -z "${target}" ]]; then
    usage
    exit 2
fi
case "${target}" in
    linux-x64|linux-arm64|iphoneos-arm64|android-arm64-v8a) ;;
    *) echo "Unsupported target: ${target}" >&2; exit 2 ;;
esac
if [[ ! "${jobs}" =~ ^[1-9][0-9]*$ ]]; then
    echo "Invalid --jobs value: ${jobs}" >&2
    exit 2
fi

mkdir -p "${prefix}"
prefix=$(cd "${prefix}" && pwd)
build_dir=${build_dir:-${phpx_root}/build/sdk-${target}}

required_files=(
    manifest.json
    .typephp-php-runtime-abi
    include/php/main/php.h
    include/php/main/php_config.h
    include/php/Zend/zend.h
    include/gmp.h
    include/gmpxx.h
    include/mpfr.h
    lib/libphp.a
)
for file in "${required_files[@]}"; do
    if [[ ! -s "${prefix}/${file}" ]]; then
        echo "Runtime layer is incomplete: ${prefix}/${file}" >&2
        exit 1
    fi
done

manifest_target=$(sed -n 's/.*"target": "\([^"]*\)".*/\1/p' \
    "${prefix}/manifest.json")
if [[ "${manifest_target}" != "${target}" ]]; then
    echo "Runtime target mismatch: expected ${target}, got ${manifest_target:-unknown}" >&2
    exit 1
fi

if [[ "${target}" == iphoneos-arm64 ]]; then
    "${phpx_root}/ios/build.sh" \
        --prefix "${prefix}" \
        --build-dir "${build_dir}" \
        --jobs "${jobs}"
    printf '%s\n' 'typephp-iphoneos-arm64-phpx-sdk-abi-v1' \
        > "${prefix}/.typephp-sdk-abi"
elif [[ "${target}" == android-arm64-v8a ]]; then
    "${phpx_root}/android/build.sh" \
        --prefix "${prefix}" \
        --build-dir "${build_dir}" \
        --jobs "${jobs}"
    printf '%s\n' 'typephp-android-arm64-v8a-api24-phpx-sdk-abi-v1' \
        > "${prefix}/.typephp-sdk-abi"
else
    machine=$(uname -m)
    case "${target}:${machine}" in
        linux-x64:x86_64|linux-arm64:aarch64|linux-arm64:arm64) ;;
        *) echo "Build host architecture ${machine} does not match ${target}." >&2; exit 1 ;;
    esac

    cmake_generator=()
    if command -v ninja >/dev/null 2>&1; then
        cmake_generator=(-G Ninja)
    fi
    cmake -S "${phpx_root}/full-static" -B "${build_dir}" \
        "${cmake_generator[@]}" \
        -DCMAKE_BUILD_TYPE=Release \
        -DCMAKE_INSTALL_PREFIX="${prefix}" \
        -DPHPX_PHP_INCLUDE_DIR="${prefix}/include/php" \
        -DPHPX_GMP_INCLUDE_DIR="${prefix}/include" \
        -DPHPX_GMP_LIB_DIR="${prefix}/lib" \
        -DPHPX_MPFR_INCLUDE_DIR="${prefix}/include" \
        -DPHPX_MPFR_LIB_DIR="${prefix}/lib"
    cmake --build "${build_dir}" --parallel "${jobs}"
    cmake --install "${build_dir}"

    mkdir -p "${prefix}/include/phpx"
    cp -Rp "${phpx_root}/include/." "${prefix}/include/phpx/"
    cp -p "${phpx_root}/thirdparty/mpdecimal/libmpdec/mpdecimal.h" \
        "${prefix}/include/phpx/"
    cp -p "${phpx_root}/thirdparty/mpdecimal/libmpdec++/decimal.hh" \
        "${prefix}/include/phpx/"
    printf '%s\n' "typephp-${target}-phpx-full-static-sdk-abi-v1" \
        > "${prefix}/.typephp-sdk-abi"
fi

if [[ ! -s "${prefix}/lib/libphpx.a" ]]; then
    echo "PHPX build did not produce ${prefix}/lib/libphpx.a" >&2
    exit 1
fi
if [[ "${target}" == iphoneos-arm64 ]]; then
    archive_member=$(xcrun --sdk iphoneos ar -t "${prefix}/lib/libphpx.a" \
        | sed -n '1p')
elif [[ "${target}" == android-arm64-v8a ]]; then
    ndk_root=${ANDROID_NDK_HOME:-${ANDROID_NDK_ROOT:-}}
    ndk_host_tag=linux-x86_64
    case "$(uname -s):$(uname -m)" in
        Darwin:arm64) ndk_host_tag=darwin-x86_64 ;;
        Darwin:x86_64) ndk_host_tag=darwin-x86_64 ;;
        Linux:aarch64|Linux:arm64) ndk_host_tag=linux-x86_64 ;;
    esac
    archive_member=$("${ndk_root}/toolchains/llvm/prebuilt/${ndk_host_tag}/bin/llvm-ar" \
        t "${prefix}/lib/libphpx.a" | sed -n '1p')
else
    archive_member=$(ar t "${prefix}/lib/libphpx.a" | sed -n '1p')
fi
if [[ -z "${archive_member}" ]]; then
    echo "libphpx.a is empty." >&2
    exit 1
fi

echo "Installed PHPX native SDK layer: ${prefix}"

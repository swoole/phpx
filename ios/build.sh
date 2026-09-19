#!/usr/bin/env bash

set -euo pipefail

script_dir=$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)
phpx_root=$(cd "${script_dir}/.." && pwd)

usage()
{
    cat <<'EOF'
Usage: ./ios/build.sh [options]

Build and install libphpx.a for an arm64 iPhone or iOS simulator. The prefix
must contain a libphp.a and headers built for the selected platform.

Options:
  --platform <device|simulator>  Target platform (default: device)
  --prefix <dir>             SDK prefix (default: ios/iphoneos-arm64)
  --build-dir <dir>          CMake build directory
  --deployment-target <ver>  Minimum iOS version (default: 15.0)
  --jobs <number>            Parallel build jobs (default: 8)
  -h, --help                 Show this help
EOF
}

platform=${PHPX_IOS_PLATFORM:-device}
prefix=${PHPX_IOS_SDK_DIR:-}
build_dir=${PHPX_IOS_BUILD_DIR:-}
deployment_target=${PHPX_IOS_DEPLOYMENT_TARGET:-15.0}
jobs=${PHPX_IOS_JOBS:-8}

while [[ $# -gt 0 ]]; do
    case "$1" in
        --platform)
            [[ $# -ge 2 ]] || { echo "--platform requires a value" >&2; exit 2; }
            platform=$2
            shift 2
            ;;
        --platform=*) platform=${1#*=}; shift ;;
        --prefix)
            [[ $# -ge 2 ]] || { echo "--prefix requires a directory" >&2; exit 2; }
            prefix=$2
            shift 2
            ;;
        --prefix=*) prefix=${1#*=}; shift ;;
        --build-dir)
            [[ $# -ge 2 ]] || { echo "--build-dir requires a directory" >&2; exit 2; }
            build_dir=$2
            shift 2
            ;;
        --build-dir=*) build_dir=${1#*=}; shift ;;
        --deployment-target)
            [[ $# -ge 2 ]] || { echo "--deployment-target requires a version" >&2; exit 2; }
            deployment_target=$2
            shift 2
            ;;
        --deployment-target=*) deployment_target=${1#*=}; shift ;;
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

case "${platform}" in
    device) sdk=iphoneos ;;
    simulator) sdk=iphonesimulator ;;
    *) echo "Unsupported --platform: ${platform}" >&2; exit 2 ;;
esac
target=${sdk}-arm64
prefix=${prefix:-${phpx_root}/ios/${target}}
build_dir=${build_dir:-${phpx_root}/build/${target}}

if [[ $(uname -s) != Darwin ]]; then
    echo "PHPX/iPhoneOS must be cross-compiled on macOS with full Xcode." >&2
    exit 1
fi
if [[ ! "${jobs}" =~ ^[1-9][0-9]*$ ]]; then
    echo "Invalid --jobs value: ${jobs}" >&2
    exit 2
fi
if [[ ! "${deployment_target}" =~ ^[0-9]+([.][0-9]+){0,2}$ ]]; then
    echo "Invalid --deployment-target value: ${deployment_target}" >&2
    exit 2
fi

xcrun --sdk "${sdk}" --show-sdk-path >/dev/null
mkdir -p "${prefix}" "${build_dir}"
prefix=$(cd "${prefix}" && pwd)
build_dir=$(cd "${build_dir}" && pwd)

required_files=(
    include/php/main/php.h
    include/php/main/php_config.h
    include/php/Zend/zend.h
    include/gmp.h
    include/gmpxx.h
    include/mpfr.h
    lib/libphp.a
)
for file in "${required_files[@]}"; do
    if [[ ! -f "${prefix}/${file}" ]]; then
        echo "The iPhoneOS SDK prerequisite is missing: ${prefix}/${file}" >&2
        exit 1
    fi
done

runtime_abi_file=${prefix}/.typephp-php-runtime-abi
if [[ ! -f "${runtime_abi_file}" && -f "${prefix}/.typephp-ios-php-abi" ]]; then
    runtime_abi_file=${prefix}/.typephp-ios-php-abi
fi
if [[ ! -f "${runtime_abi_file}"
    || $(<"${runtime_abi_file}") != "typephp-${target}-php-zts-abi-v1" ]]; then
    echo "The iPhoneOS PHP Runtime Layer ABI marker is incompatible: ${runtime_abi_file}" >&2
    exit 1
fi
if ! grep -Eq '^#define[[:space:]]+ZTS([[:space:]]+1)?([[:space:]]|$)' "${prefix}/include/php/main/php_config.h"; then
    echo "PHPX/iPhoneOS requires a ZTS PHP SDK." >&2
    exit 1
fi

cmake_arguments=(
    -S "${phpx_root}/full-static"
    -B "${build_dir}"
    -DCMAKE_SYSTEM_NAME=iOS
    -DCMAKE_OSX_SYSROOT="${sdk}"
    -DCMAKE_OSX_ARCHITECTURES=arm64
    -DCMAKE_OSX_DEPLOYMENT_TARGET="${deployment_target}"
    -DCMAKE_BUILD_TYPE=Release
    -DCMAKE_INSTALL_PREFIX="${prefix}"
    -DPHPX_PHP_INCLUDE_DIR="${prefix}/include/php"
    -DPHPX_GMP_INCLUDE_DIR="${prefix}/include"
    -DPHPX_GMP_LIB_DIR="${prefix}/lib"
    -DPHPX_MPFR_INCLUDE_DIR="${prefix}/include"
    -DPHPX_MPFR_LIB_DIR="${prefix}/lib"
)
if command -v ninja >/dev/null 2>&1; then
    cmake_arguments+=(-G Ninja)
fi
cmake "${cmake_arguments[@]}"
cmake --build "${build_dir}" --parallel "${jobs}"
cmake --install "${build_dir}"

mkdir -p "${prefix}/include/phpx"
cp -Rp "${phpx_root}/include/." "${prefix}/include/phpx/"
cp -p "${phpx_root}/thirdparty/mpdecimal/libmpdec/mpdecimal.h" "${prefix}/include/"
cp -p "${phpx_root}/thirdparty/mpdecimal/libmpdec++/decimal.hh" "${prefix}/include/"

if [[ ! -f "${prefix}/lib/libphpx.a" ]]; then
    echo "PHPX iPhoneOS build did not produce ${prefix}/lib/libphpx.a" >&2
    exit 1
fi

archive_arch=$(xcrun --sdk "${sdk}" lipo -archs "${prefix}/lib/libphpx.a")
if [[ " ${archive_arch} " != *" arm64 "* ]]; then
    echo "libphpx.a does not contain arm64: ${archive_arch}" >&2
    exit 1
fi

printf 'typephp-%s-sdk-abi-v1\n' "${target}" > "${prefix}/.typephp-ios-sdk-abi"
echo "Installed PHPX ${sdk} archive and headers: ${prefix}"

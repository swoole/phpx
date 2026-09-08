#!/usr/bin/env bash

set -euo pipefail

script_dir=$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)
phpx_root=$(cd "${script_dir}/.." && pwd)

usage()
{
    cat <<'EOF'
Usage: ./android/build.sh [options]

Cross-compile and install libphpx.a for Android arm64-v8a. The prefix must
already contain the matching self-contained Android libphp.a and headers.

Options:
  --prefix <dir>     SDK prefix (default: android/arm64-v8a)
  --build-dir <dir>  CMake build directory
  --api <level>      Minimum Android API level (default: 24)
  --jobs <number>    Parallel build jobs (default: 8)
  -h, --help         Show this help
EOF
}

prefix=${PHPX_ANDROID_SDK_DIR:-${phpx_root}/android/arm64-v8a}
build_dir=${PHPX_ANDROID_BUILD_DIR:-${phpx_root}/build/android-arm64-v8a}
android_api=${TYPEPHP_ANDROID_API:-24}
jobs=${PHPX_ANDROID_JOBS:-8}

while [[ $# -gt 0 ]]; do
    case "$1" in
        --prefix) prefix=${2:?}; shift 2 ;;
        --prefix=*) prefix=${1#*=}; shift ;;
        --build-dir) build_dir=${2:?}; shift 2 ;;
        --build-dir=*) build_dir=${1#*=}; shift ;;
        --api) android_api=${2:?}; shift 2 ;;
        --api=*) android_api=${1#*=}; shift ;;
        --jobs|-j) jobs=${2:?}; shift 2 ;;
        --jobs=*|-j*) jobs=${1#*=}; jobs=${jobs#-j}; shift ;;
        -h|--help) usage; exit 0 ;;
        *) echo "Unknown option: $1" >&2; usage >&2; exit 2 ;;
    esac
done

if [[ ! "${jobs}" =~ ^[1-9][0-9]*$ || ! "${android_api}" =~ ^[0-9]+$ ]]; then
    echo "Invalid Android API level or job count." >&2
    exit 2
fi

ndk_root=${ANDROID_NDK_HOME:-${ANDROID_NDK_ROOT:-}}
if [[ -z "${ndk_root}" || ! -f "${ndk_root}/build/cmake/android.toolchain.cmake" ]]; then
    echo "Set ANDROID_NDK_HOME to an Android NDK installation." >&2
    exit 1
fi
ndk_root=$(cd "${ndk_root}" && pwd)

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
    .typephp-php-runtime-abi
)
for file in "${required_files[@]}"; do
    if [[ ! -s "${prefix}/${file}" ]]; then
        echo "The Android SDK prerequisite is missing: ${prefix}/${file}" >&2
        exit 1
    fi
done

expected_runtime_abi="typephp-android-arm64-v8a-api${android_api}-php-zts-pic-abi-v1"
if [[ $(<"${prefix}/.typephp-php-runtime-abi") != "${expected_runtime_abi}" ]]; then
    echo "The Android PHP Runtime Layer ABI marker is incompatible." >&2
    exit 1
fi
if ! grep -Eq '^#define[[:space:]]+ZTS([[:space:]]+1)?([[:space:]]|$)' \
    "${prefix}/include/php/main/php_config.h"; then
    echo "PHPX/Android requires a ZTS PHP SDK." >&2
    exit 1
fi

cmake_arguments=(
    -S "${phpx_root}/full-static"
    -B "${build_dir}"
    -DCMAKE_TOOLCHAIN_FILE="${ndk_root}/build/cmake/android.toolchain.cmake"
    -DANDROID_ABI=arm64-v8a
    -DANDROID_PLATFORM="android-${android_api}"
    -DANDROID_STL=c++_static
    -DANDROID_SUPPORT_FLEXIBLE_PAGE_SIZES=ON
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
cp -p "${phpx_root}/thirdparty/mpdecimal/libmpdec/mpdecimal.h" \
    "${prefix}/include/"
cp -p "${phpx_root}/thirdparty/mpdecimal/libmpdec++/decimal.hh" \
    "${prefix}/include/"

if [[ ! -s "${prefix}/lib/libphpx.a" ]]; then
    echo "PHPX Android build did not produce ${prefix}/lib/libphpx.a" >&2
    exit 1
fi

printf '%s\n' "typephp-android-arm64-v8a-api${android_api}-phpx-sdk-abi-v1" \
    > "${prefix}/.typephp-android-sdk-abi"
echo "Installed PHPX Android archive and headers: ${prefix}"

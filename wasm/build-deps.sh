#!/usr/bin/env bash

set -euo pipefail

script_dir=$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)
work_dir=${PHPX_WASM_DEPS_WORK_DIR:-/tmp/phpx-wasip2-deps}
prefix=${PHPX_WASM_DEPS_PREFIX:-${work_dir}/prefix}
jobs=${PHPX_WASM_JOBS:-8}

gmp_version=6.3.0
mpfr_version=4.2.2

gmp_sha256=ac28211a7cfb609bae2e2c8d6058d66c8fe96434f740cf6fe2e47b000d1c20cb
mpfr_sha256=826cbb24610bd193f36fde172233fb8c009f3f5c2ad99f644d0dea2e16a20e42

source "${script_dir}/toolchain.sh"

archive_dir=${work_dir}/archives
source_root=${work_dir}/src
build_root=${work_dir}/build
mkdir -p "${archive_dir}" "${source_root}" "${build_root}" "${prefix}"

download()
{
    local url=$1
    local file=$2
    local sha256=$3

    if [[ ! -f "${file}" ]]; then
        curl -L --fail --retry 3 "${url}" -o "${file}"
    fi
    printf '%s  %s\n' "${sha256}" "${file}" | sha256sum --check --status
}

extract()
{
    local archive=$1
    local destination=$2

    if [[ ! -f "${destination}/.typephp-extracted" ]]; then
        mkdir -p "${destination}"
        tar -xf "${archive}" -C "${destination}" --strip-components=1
        touch "${destination}/.typephp-extracted"
    fi
}

gmp_archive=${archive_dir}/gmp-${gmp_version}.tar.bz2
mpfr_archive=${archive_dir}/mpfr-${mpfr_version}.tar.gz

download "https://ftp.gnu.org/gnu/gmp/gmp-${gmp_version}.tar.bz2" "${gmp_archive}" "${gmp_sha256}"
download "https://ftp.gnu.org/gnu/mpfr/mpfr-${mpfr_version}.tar.gz" "${mpfr_archive}" "${mpfr_sha256}"

gmp_source=${source_root}/gmp-${gmp_version}
mpfr_source=${source_root}/mpfr-${mpfr_version}
extract "${gmp_archive}" "${gmp_source}"
extract "${mpfr_archive}" "${mpfr_source}"

gmp_build=${build_root}/gmp-${gmp_version}
mkdir -p "${gmp_build}"
(
    cd "${gmp_build}"
    env \
        CC="${wasi_cc}" \
        CXX="${wasi_cxx}" \
        AR="${wasi_ar}" \
        RANLIB="${wasi_ranlib}" \
        NM="${wasi_nm}" \
        CC_FOR_BUILD=cc \
        CPP_FOR_BUILD='cc -E' \
        CFLAGS='-O2 -DNO_ASM -D_WASI_EMULATED_SIGNAL -DHAVE_RAISE=1' \
        CXXFLAGS='-O2 -std=c++17 -fwasm-exceptions -mllvm -wasm-use-legacy-eh=false' \
        "${gmp_source}/configure" \
            --build=x86_64-pc-linux-gnu \
            --host=wasm32-wasip2 \
            --prefix="${prefix}" \
            --disable-shared \
            --enable-static \
            --disable-assembly \
            --enable-cxx \
            --enable-alloca=malloc-reentrant \
            --with-readline=no
    make -j"${jobs}"
    make install
)

mpfr_build=${build_root}/mpfr-${mpfr_version}
mkdir -p "${mpfr_build}"
(
    cd "${mpfr_build}"
    env \
        CC="${wasi_cc}" \
        AR="${wasi_ar}" \
        RANLIB="${wasi_ranlib}" \
        NM="${wasi_nm}" \
        CPPFLAGS="-I${prefix}/include" \
        CFLAGS='-O2' \
        LDFLAGS="-L${prefix}/lib" \
        mpfr_cv_gcc_floatconv_bug=no \
        mpfr_cv_have_subnorm_dbl=yes \
        mpfr_cv_have_subnorm_flt=yes \
        mpfr_cv_have_signedz=yes \
        mpfr_cv_errdivzero=no \
        mpfr_cv_nanisnan=no \
        "${mpfr_source}/configure" \
            --build=x86_64-pc-linux-gnu \
            --host=wasm32-wasip2 \
            --prefix="${prefix}" \
            --with-gmp="${prefix}" \
            --disable-shared \
            --enable-static \
            --disable-thread-safe \
            --disable-float128 \
            --disable-decimal-float
    make -j"${jobs}"
    make install
)

printf '%s\n' 'typephp-wasip2-numeric-abi-v1' > "${prefix}/.typephp-wasi-numeric-abi"
echo "Built PHPX GMP and MPFR dependencies for WASI 0.2: ${prefix}"

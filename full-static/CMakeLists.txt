# PHPX 全静态构建（libphpx.a）
#
# 独立于主 CMakeLists.txt，参照 wasm/ 的模式。
# 只编译 src/core + src/std + src/typephp（不含 facade：src/func、src/class、
# src/const），因此不会引入 include/class/swoole.h 等 facade 头，
# 也就不会与 <sys/socket.h> 的 MSG_* / SHUT_* 宏冲突。
#
# 依赖（gmp/gmpxx/mpfr）作为 PRIVATE 链接，其符号由最终链接的自包含
# libphp.a 提供，不作为 PUBLIC 传播，避免解析到系统的 glibc 版本。
#
# 用法（由 swoole-cli 或外部构建脚本调用）：
#   cmake -S full-static -B build/full-static \
#       -DPHPX_PHP_INCLUDE_DIR=/path/to/php-src \
#       -DPHPX_GMP_INCLUDE_DIR=... -DPHPX_GMP_LIB_DIR=... \
#       -DPHPX_MPFR_INCLUDE_DIR=... -DPHPX_MPFR_LIB_DIR=...

cmake_minimum_required(VERSION 3.20)
project(phpx_full_static LANGUAGES C CXX)

set(PHPX_ROOT "${CMAKE_CURRENT_LIST_DIR}/..")

# ---- 外部依赖路径（由调用方传入）----
set(PHPX_PHP_INCLUDE_DIR "" CACHE PATH "PHP source include root (e.g. /work)")
set(PHPX_GMP_INCLUDE_DIR "" CACHE PATH "GMP include dir")
set(PHPX_GMP_LIB_DIR "" CACHE PATH "GMP lib dir")
set(PHPX_MPFR_INCLUDE_DIR "" CACHE PATH "MPFR include dir")
set(PHPX_MPFR_LIB_DIR "" CACHE PATH "MPFR lib dir")

foreach(required_file
    "${PHPX_PHP_INCLUDE_DIR}/main/php.h"
    "${PHPX_PHP_INCLUDE_DIR}/Zend/zend.h"
    "${PHPX_GMP_INCLUDE_DIR}/gmp.h"
    "${PHPX_GMP_INCLUDE_DIR}/gmpxx.h"
    "${PHPX_MPFR_INCLUDE_DIR}/mpfr.h"
)
    if(NOT EXISTS "${required_file}")
        message(FATAL_ERROR "required header is missing: ${required_file}")
    endif()
endforeach()

# ---- wren_gc ----
add_library(wren_gc STATIC "${PHPX_ROOT}/thirdparty/wren-gc/src/wren_gc.c")
target_include_directories(wren_gc PUBLIC "${PHPX_ROOT}/thirdparty/wren-gc/include")
set_target_properties(wren_gc PROPERTIES
    C_STANDARD 11
    C_STANDARD_REQUIRED ON
    POSITION_INDEPENDENT_CODE ON
)

# ---- mpdecimal（bundled，mpdecimal.h 已随仓库提供）----
set(MPDECIMAL_DIR "${PHPX_ROOT}/thirdparty/mpdecimal")
file(GLOB MPDEC_C_SOURCES "${MPDECIMAL_DIR}/libmpdec/*.c")
list(FILTER MPDEC_C_SOURCES EXCLUDE REGEX "bench")

add_library(mpdecimal STATIC
    ${MPDEC_C_SOURCES}
    "${MPDECIMAL_DIR}/libmpdec++/decimal.cc"
)
target_include_directories(mpdecimal PUBLIC
    "${MPDECIMAL_DIR}/libmpdec"
    "${MPDECIMAL_DIR}/libmpdec++"
)
target_compile_definitions(mpdecimal PRIVATE CONFIG_64 ANSI HAVE_UINT128_T)
set_target_properties(mpdecimal PROPERTIES
    C_STANDARD 99
    C_STANDARD_REQUIRED ON
    POSITION_INDEPENDENT_CODE ON
)
target_compile_options(mpdecimal PRIVATE -fPIC)

# ---- phpx：core + std + typephp ----
file(GLOB PHPX_CORE_SOURCES "${PHPX_ROOT}/src/core/*.cc")
file(GLOB PHPX_STD_SOURCES "${PHPX_ROOT}/src/std/*.cc")
file(GLOB PHPX_TYPEPHP_SOURCES "${PHPX_ROOT}/src/typephp/*.cc")

add_library(phpx STATIC
    ${PHPX_CORE_SOURCES}
    ${PHPX_STD_SOURCES}
    ${PHPX_TYPEPHP_SOURCES}
)
set_target_properties(phpx PROPERTIES
    OUTPUT_NAME phpx
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED ON
    POSITION_INDEPENDENT_CODE ON
)

target_include_directories(phpx PRIVATE
    "${PHPX_ROOT}/include"
    "${PHPX_ROOT}/src/misc"
    "${PHPX_PHP_INCLUDE_DIR}"
    "${PHPX_PHP_INCLUDE_DIR}/main"
    "${PHPX_PHP_INCLUDE_DIR}/Zend"
    "${PHPX_PHP_INCLUDE_DIR}/TSRM"
    "${PHPX_PHP_INCLUDE_DIR}/ext"
    "${PHPX_PHP_INCLUDE_DIR}/ext/date/lib"
    "${PHPX_GMP_INCLUDE_DIR}"
    "${PHPX_MPFR_INCLUDE_DIR}"
)
target_compile_options(phpx PRIVATE -fPIC)

# gmp/gmpxx/mpfr 符号由最终链接的自包含 libphp.a 提供，用 PRIVATE 不传播
target_link_directories(phpx PRIVATE "${PHPX_GMP_LIB_DIR}" "${PHPX_MPFR_LIB_DIR}")
target_link_libraries(phpx PRIVATE gmp gmpxx mpfr)
target_link_libraries(phpx PUBLIC mpdecimal wren_gc)

install(TARGETS phpx mpdecimal wren_gc ARCHIVE DESTINATION lib)

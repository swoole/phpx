cmake_minimum_required(VERSION 3.20)
project(phpx_sapi_static LANGUAGES C CXX)

set(PHPX_ROOT "" CACHE PATH "PHPX source directory")
set(PHPX_PHP_PREFIX "" CACHE PATH "Private PHP installation prefix")
if(NOT EXISTS "${PHPX_ROOT}/include/phpx.h")
    message(FATAL_ERROR "Invalid PHPX source directory: ${PHPX_ROOT}")
endif()
if(NOT EXISTS "${PHPX_PHP_PREFIX}/include/php/main/php.h")
    message(FATAL_ERROR "Invalid private PHP prefix: ${PHPX_PHP_PREFIX}")
endif()

file(GLOB PHPX_CORE_SOURCES "${PHPX_ROOT}/src/core/*.cc")
file(GLOB PHPX_STD_SOURCES "${PHPX_ROOT}/src/std/*.cc")
file(GLOB PHPX_TYPEPHP_SOURCES "${PHPX_ROOT}/src/typephp/*.cc")
list(FILTER PHPX_CORE_SOURCES EXCLUDE REGEX "/[^/]+_nano\\.cc$")
list(FILTER PHPX_TYPEPHP_SOURCES EXCLUDE REGEX "/[^/]+_nano\\.cc$")

file(GLOB MPDEC_C_SOURCES "${PHPX_ROOT}/thirdparty/mpdecimal/libmpdec/*.c")
list(FILTER MPDEC_C_SOURCES EXCLUDE REGEX "bench")
add_library(mpdecimal_obj OBJECT
    ${MPDEC_C_SOURCES}
    "${PHPX_ROOT}/thirdparty/mpdecimal/libmpdec++/decimal.cc"
)
target_include_directories(mpdecimal_obj PUBLIC
    "${PHPX_ROOT}/thirdparty/mpdecimal/libmpdec"
    "${PHPX_ROOT}/thirdparty/mpdecimal/libmpdec++"
)
target_compile_definitions(mpdecimal_obj PRIVATE CONFIG_64 ANSI HAVE_UINT128_T)
set_target_properties(mpdecimal_obj PROPERTIES C_STANDARD 99 POSITION_INDEPENDENT_CODE ON)

add_library(wren_gc_obj OBJECT "${PHPX_ROOT}/thirdparty/wren-gc/src/wren_gc.c")
target_include_directories(wren_gc_obj PUBLIC "${PHPX_ROOT}/thirdparty/wren-gc/include")
set_target_properties(wren_gc_obj PROPERTIES C_STANDARD 11 POSITION_INDEPENDENT_CODE ON)

add_library(phpx STATIC
    ${PHPX_CORE_SOURCES}
    ${PHPX_STD_SOURCES}
    ${PHPX_TYPEPHP_SOURCES}
    $<TARGET_OBJECTS:mpdecimal_obj>
    $<TARGET_OBJECTS:wren_gc_obj>
)
set_target_properties(phpx PROPERTIES
    OUTPUT_NAME phpx
    ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib"
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED ON
    POSITION_INDEPENDENT_CODE ON
)
target_include_directories(phpx PRIVATE
    "${PHPX_ROOT}/include"
    "${PHPX_ROOT}/src/misc"
    "${PHPX_PHP_PREFIX}/include/php"
    "${PHPX_PHP_PREFIX}/include/php/main"
    "${PHPX_PHP_PREFIX}/include/php/Zend"
    "${PHPX_PHP_PREFIX}/include/php/TSRM"
    "${PHPX_PHP_PREFIX}/include/php/ext"
    "${PHPX_PHP_PREFIX}/include/php/ext/date/lib"
    "${PHPX_ROOT}/thirdparty/mpdecimal/libmpdec"
    "${PHPX_ROOT}/thirdparty/mpdecimal/libmpdec++"
    "${PHPX_ROOT}/thirdparty/wren-gc/include"
)

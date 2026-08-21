cmake_minimum_required(VERSION 3.20)

project(phpx_wasi LANGUAGES C CXX)

if(NOT CMAKE_SYSTEM_NAME STREQUAL "WASI")
    message(FATAL_ERROR
        "PHPX/WASI must be cross-compiled with the WASI SDK Preview 2 "
        "toolchain (wasi-sdk-p2.cmake)"
    )
endif()

if(NOT CMAKE_SYSTEM_PROCESSOR STREQUAL "wasm32")
    message(FATAL_ERROR
        "PHPX/WASI only supports the wasm32-wasip2 target"
    )
endif()

if(NOT CMAKE_CXX_COMPILER_TARGET STREQUAL "wasm32-wasip2")
    message(FATAL_ERROR
        "PHPX/WASI requires the wasm32-wasip2 target; configured target is "
        "'${CMAKE_CXX_COMPILER_TARGET}'"
    )
endif()

set(PHPX_ROOT "${CMAKE_CURRENT_LIST_DIR}/..")
set(PHPX_WASI_SDK_DIR "${CMAKE_CURRENT_LIST_DIR}/wasm32-wasip2"
    CACHE PATH "PHPX wasm32-wasip2 SDK containing PHP and numeric headers"
)

set(PHPX_WASI_PHP_INCLUDE_DIR "${PHPX_WASI_SDK_DIR}/include/php")

foreach(required_file
    "${PHPX_WASI_PHP_INCLUDE_DIR}/main/php.h"
    "${PHPX_WASI_PHP_INCLUDE_DIR}/main/php_config.h"
    "${PHPX_WASI_PHP_INCLUDE_DIR}/main/build-defs.h"
    "${PHPX_WASI_PHP_INCLUDE_DIR}/Zend/zend_config.h"
    "${PHPX_WASI_PHP_INCLUDE_DIR}/ext/date/lib/timelib_config.h"
    "${PHPX_WASI_SDK_DIR}/include/gmp.h"
    "${PHPX_WASI_SDK_DIR}/include/gmpxx.h"
    "${PHPX_WASI_SDK_DIR}/include/mpfr.h"
)
    if(NOT EXISTS "${required_file}")
        message(FATAL_ERROR
            "PHPX WASI SDK header is missing: ${required_file}\n"
            "Build and install the PHP and numeric WASI dependencies first, "
            "or set PHPX_WASI_SDK_DIR to their installation prefix."
        )
    endif()
endforeach()

# mpdecimal is a PHPX implementation dependency, not a PHP dependency. Build
# the PHPX-vendored source here so Host and WASI packages use the same pinned
# version. Work on a build-tree copy because wasm32 needs an ANSI32 header and
# an NTS process-global C++ context; the pristine third-party source must not
# be modified by configuration or compatibility changes.
set(MPDECIMAL_SOURCE_DIR "${PHPX_ROOT}/thirdparty/mpdecimal")
set(MPDECIMAL_WASI_SOURCE_DIR "${CMAKE_CURRENT_BINARY_DIR}/mpdecimal-src")
set(MPDECIMAL_PRISTINE_DIR "${CMAKE_CURRENT_BINARY_DIR}/mpdecimal-pristine")
file(MAKE_DIRECTORY
    "${MPDECIMAL_WASI_SOURCE_DIR}/libmpdec"
    "${MPDECIMAL_WASI_SOURCE_DIR}/libmpdec++"
    "${MPDECIMAL_PRISTINE_DIR}/libmpdec++"
)

file(GLOB MPDECIMAL_ORIGINAL_C_SOURCES CONFIGURE_DEPENDS
    "${MPDECIMAL_SOURCE_DIR}/libmpdec/*.c"
)
list(FILTER MPDECIMAL_ORIGINAL_C_SOURCES EXCLUDE REGEX "/bench(_full)?\\.c$")
set(MPDECIMAL_C_SOURCES)
foreach(source IN LISTS MPDECIMAL_ORIGINAL_C_SOURCES)
    get_filename_component(filename "${source}" NAME)
    set(staged_source "${MPDECIMAL_WASI_SOURCE_DIR}/libmpdec/${filename}")
    configure_file("${source}" "${staged_source}" COPYONLY)
    list(APPEND MPDECIMAL_C_SOURCES "${staged_source}")
endforeach()

file(GLOB MPDECIMAL_ORIGINAL_HEADERS CONFIGURE_DEPENDS
    "${MPDECIMAL_SOURCE_DIR}/libmpdec/*.h"
)
foreach(header IN LISTS MPDECIMAL_ORIGINAL_HEADERS)
    get_filename_component(filename "${header}" NAME)
    if(NOT filename STREQUAL "mpdecimal.h")
        configure_file(
            "${header}"
            "${MPDECIMAL_WASI_SOURCE_DIR}/libmpdec/${filename}"
            COPYONLY
        )
    endif()
endforeach()

configure_file(
    "${MPDECIMAL_SOURCE_DIR}/libmpdec++/decimal.cc"
    "${MPDECIMAL_PRISTINE_DIR}/libmpdec++/decimal.cc"
    COPYONLY
)
configure_file(
    "${MPDECIMAL_SOURCE_DIR}/libmpdec++/decimal.hh"
    "${MPDECIMAL_PRISTINE_DIR}/libmpdec++/decimal.hh"
    COPYONLY
)

set(MPD_HEADER_CONFIG [=[
/* ABI: 32-bit */
#define MPD_CONFIG_32 1

#ifdef MPD_CONFIG_64
  #error "cannot use MPD_CONFIG_64 with 32-bit header."
#endif

#ifdef CONFIG_64
  #error "cannot use CONFIG_64 with 32-bit header."
#endif
]=])
configure_file(
    "${MPDECIMAL_SOURCE_DIR}/libmpdec/mpdecimal.h.in"
    "${MPDECIMAL_WASI_SOURCE_DIR}/libmpdec/mpdecimal.h"
    @ONLY
)

function(phpx_transform_once source destination search replacement)
    file(READ "${source}" contents)
    string(FIND "${contents}" "${search}" offset)
    if(offset EQUAL -1)
        message(FATAL_ERROR
            "The expected mpdecimal source fragment was not found in ${source}; "
            "review the PHPX WASI NTS compatibility transformation."
        )
    endif()
    string(REPLACE "${search}" "${replacement}" contents "${contents}")
    set(current_contents)
    if(EXISTS "${destination}")
        file(READ "${destination}" current_contents)
    endif()
    if(NOT "${current_contents}" STREQUAL "${contents}")
        file(WRITE "${destination}" "${contents}")
    endif()
endfunction()

phpx_transform_once(
    "${MPDECIMAL_PRISTINE_DIR}/libmpdec++/decimal.hh"
    "${MPDECIMAL_WASI_SOURCE_DIR}/libmpdec++/decimal.hh"
    [=[IMPORTEXPORT extern Context context_template;
#if defined(__OpenBSD__) || defined(__sun) || defined(_MSC_VER) && defined(_DLL)]=]
    [=[IMPORTEXPORT extern Context context_template;
#if defined(__wasi__)
IMPORTEXPORT extern Context context;
#elif defined(__OpenBSD__) || defined(__sun) || defined(_MSC_VER) && defined(_DLL)]=]
)
phpx_transform_once(
    "${MPDECIMAL_PRISTINE_DIR}/libmpdec++/decimal.cc"
    "${MPDECIMAL_WASI_SOURCE_DIR}/libmpdec++/decimal.cc"
    [=[#if defined(__OpenBSD__) || defined(__sun) || defined(_MSC_VER) && defined(_DLL)
Context& getcontext() {]=]
    [=[#if defined(__wasi__)
Context context{context_template};
#elif defined(__OpenBSD__) || defined(__sun) || defined(_MSC_VER) && defined(_DLL)
Context& getcontext() {]=]
)

add_library(mpdec STATIC ${MPDECIMAL_C_SOURCES})
set_target_properties(mpdec PROPERTIES
    OUTPUT_NAME mpdec
    C_STANDARD 99
    C_STANDARD_REQUIRED YES
    C_EXTENSIONS NO
)
target_compile_definitions(mpdec PRIVATE
    CONFIG_32
    ANSI
    _WASI_EMULATED_SIGNAL
)
target_compile_options(mpdec PRIVATE -O2)
target_include_directories(mpdec PUBLIC
    "${MPDECIMAL_WASI_SOURCE_DIR}/libmpdec"
)

add_library(mpdec_cxx STATIC
    "${MPDECIMAL_WASI_SOURCE_DIR}/libmpdec++/decimal.cc"
)
set_target_properties(mpdec_cxx PROPERTIES
    OUTPUT_NAME "mpdec++"
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED YES
    CXX_EXTENSIONS NO
)
target_compile_definitions(mpdec_cxx PRIVATE _WASI_EMULATED_SIGNAL)
target_compile_options(mpdec_cxx PRIVATE
    -O2
    -fwasm-exceptions
    "SHELL:-mllvm -wasm-enable-sjlj"
    "SHELL:-mllvm -wasm-use-legacy-eh=false"
)
target_include_directories(mpdec_cxx PUBLIC
    "${MPDECIMAL_WASI_SOURCE_DIR}/libmpdec"
    "${MPDECIMAL_WASI_SOURCE_DIR}/libmpdec++"
)
target_link_libraries(mpdec_cxx PUBLIC mpdec)

file(GLOB PHPX_WASI_CORE_SOURCES CONFIGURE_DEPENDS
    "${PHPX_ROOT}/src/core/*.cc"
)
list(REMOVE_ITEM PHPX_WASI_CORE_SOURCES
    "${PHPX_ROOT}/src/core/literal_string.cc"
)

file(GLOB PHPX_WASI_STD_SOURCES CONFIGURE_DEPENDS
    "${PHPX_ROOT}/src/std/*.cc"
)

add_library(phpx STATIC
    ${PHPX_WASI_CORE_SOURCES}
    ${PHPX_WASI_STD_SOURCES}
    "${PHPX_ROOT}/thirdparty/wren-gc/src/wren_gc.c"
    "${PHPX_ROOT}/src/misc/typephp_helper.cc"
)

set_target_properties(phpx PROPERTIES
    OUTPUT_NAME phpx
    C_STANDARD 11
    C_STANDARD_REQUIRED YES
    C_EXTENSIONS NO
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED YES
    CXX_EXTENSIONS NO
)

target_compile_options(phpx PRIVATE
    -O2
    -fwasm-exceptions
    "SHELL:-mllvm -wasm-enable-sjlj"
    "SHELL:-mllvm -wasm-use-legacy-eh=false"
    -Wno-deprecated-literal-operator
)

target_include_directories(phpx PRIVATE
    "${PHPX_ROOT}/thirdparty/wren-gc/include"
    "${MPDECIMAL_WASI_SOURCE_DIR}/libmpdec++"
    "${MPDECIMAL_WASI_SOURCE_DIR}/libmpdec"
    "${PHPX_WASI_PHP_INCLUDE_DIR}"
    "${PHPX_WASI_PHP_INCLUDE_DIR}/main"
    "${PHPX_WASI_PHP_INCLUDE_DIR}/Zend"
    "${PHPX_WASI_PHP_INCLUDE_DIR}/TSRM"
    "${PHPX_WASI_PHP_INCLUDE_DIR}/ext/date/lib"
    "${PHPX_WASI_SDK_DIR}/include"
    "${PHPX_ROOT}/include"
    "${PHPX_ROOT}/src/misc"
)

install(TARGETS phpx mpdec mpdec_cxx
    ARCHIVE DESTINATION lib
)

install(FILES
    "${MPDECIMAL_WASI_SOURCE_DIR}/libmpdec/mpdecimal.h"
    "${MPDECIMAL_WASI_SOURCE_DIR}/libmpdec++/decimal.hh"
    DESTINATION include
)

install(FILES
    "${PHPX_ROOT}/include/phpx.h"
    "${PHPX_ROOT}/include/phpx_types.h"
    "${PHPX_ROOT}/include/phpx_compat.h"
    "${PHPX_ROOT}/include/phpx_scope_guard.h"
    "${PHPX_ROOT}/include/phpx_fake_scope_guard.h"
    "${PHPX_ROOT}/include/phpx_operator.h"
    "${PHPX_ROOT}/include/phpx_helper.h"
    "${PHPX_ROOT}/include/phpx_big_int.h"
    "${PHPX_ROOT}/include/phpx_big_float.h"
    "${PHPX_ROOT}/include/phpx_decimal.h"
    "${PHPX_ROOT}/include/phpx_native_gc.h"
    "${PHPX_ROOT}/include/phpx_std.h"
    DESTINATION include/phpx
)
install(DIRECTORY "${PHPX_ROOT}/include/std/"
    DESTINATION include/phpx/std
    FILES_MATCHING PATTERN "*.h"
)
install(FILES
    "${PHPX_ROOT}/src/misc/typephp_helper.h"
    "${PHPX_ROOT}/src/misc/typephp_fiber_generator.h"
    DESTINATION include/phpx
)

install(CODE [[
    file(WRITE
        "${CMAKE_INSTALL_PREFIX}/.typephp-wasi-runtime-abi"
        "typephp-wasip2-phpx-abi-v1\n"
    )
]])

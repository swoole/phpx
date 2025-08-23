cmake_minimum_required(VERSION 3.10)
project(phpx_embed)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

if (NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Debug CACHE STRING "Build type" FORCE)
endif ()

set(php_dir "" CACHE STRING "Set the root directory of PHP")
if (php_dir)
    set(PHP_CONFIG "${php_dir}/bin/php-config")
else ()
    set(PHP_CONFIG "php-config")
endif()

execute_process(COMMAND ${PHP_CONFIG} --includes OUTPUT_VARIABLE PHP_INCLUDES OUTPUT_STRIP_TRAILING_WHITESPACE  RESULT_VARIABLE PHP_CONFIG_RESULT)
if (NOT PHP_CONFIG_RESULT EQUAL 0)
    message(FATAL_ERROR "Failed to execute ${PHP_CONFIG}: ${PHP_CONFIG_RESULT}")
endif()

execute_process(COMMAND ${PHP_CONFIG} --extension-dir OUTPUT_VARIABLE PHP_EXTENSION_DIR OUTPUT_STRIP_TRAILING_WHITESPACE RESULT_VARIABLE PHP_CONFIG_RESULT)
if (NOT PHP_CONFIG_RESULT EQUAL 0)
    message(FATAL_ERROR "Failed to execute php-config: ${PHP_CONFIG_RESULT}")
endif()

execute_process(COMMAND ${PHP_CONFIG} --libs OUTPUT_VARIABLE PHP_LIBS OUTPUT_STRIP_TRAILING_WHITESPACE RESULT_VARIABLE PHP_CONFIG_RESULT)
if (NOT PHP_CONFIG_RESULT EQUAL 0)
    message(FATAL_ERROR "Failed to execute php-config: ${PHP_CONFIG_RESULT}")
endif()

execute_process(COMMAND ${PHP_CONFIG} --ldflags OUTPUT_VARIABLE PHP_LDFLAGS OUTPUT_STRIP_TRAILING_WHITESPACE RESULT_VARIABLE PHP_CONFIG_RESULT)
if (NOT PHP_CONFIG_RESULT EQUAL 0)
    message(FATAL_ERROR "Failed to execute php-config: ${PHP_CONFIG_RESULT}")
endif()

execute_process(COMMAND ${PHP_CONFIG} --prefix OUTPUT_VARIABLE PHP_PREFIX OUTPUT_STRIP_TRAILING_WHITESPACE RESULT_VARIABLE PHP_CONFIG_RESULT)
if (NOT PHP_CONFIG_RESULT EQUAL 0)
    message(FATAL_ERROR "Failed to execute php-config: ${PHP_CONFIG_RESULT}")
endif()

include_directories(include ../../include ${PHP_PREFIX}/include/php/ext/swoole)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${PHP_INCLUDES}")

set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/lib)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/lib)

add_definitions(-DHAVE_CONFIG_H)

if (APPLE)
    SET(CMAKE_SHARED_LINKER_FLAGS  "${CMAKE_SHARED_LINKER_FLAGS} -undefined dynamic_lookup")
    message(${CMAKE_SHARED_LINKER_FLAGS})
endif ()

file(GLOB_RECURSE EXT_FILES src/*.cc src/*.cpp)
add_executable(embed ${EXT_FILES})
target_link_options(embed PRIVATE "-L${PHP_PREFIX}/lib" "-Wl,-rpath,${PHP_PREFIX}/lib")
target_link_libraries(embed phpx php)


cmake_minimum_required(VERSION 3.10)
project(phpx)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

aux_source_directory(src DIR_SRCS)
file(GLOB_RECURSE HEADER_FILES include/*.h)

if (NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Debug CACHE STRING "Build type" FORCE)
endif ()

# Code Coverage Configuration
add_library(coverage_config INTERFACE)

option(CODE_COVERAGE "Enable coverage reporting" OFF)
if(CODE_COVERAGE)
    message(STATUS "Open coverage")
    # --coverage => -fprofile-arcs -ftest-coverage
    target_compile_options(coverage_config INTERFACE
            -O0
            -g
            -fprofile-update=atomic
            --coverage
    )
    if(CMAKE_VERSION VERSION_GREATER_EQUAL 3.13)
        target_link_options(coverage_config INTERFACE --coverage)
    else()
        target_link_libraries(coverage_config INTERFACE --coverage)
    endif()
endif(CODE_COVERAGE)

if (DEFINED enable_asan)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fsanitize=address -fno-omit-frame-pointer")
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -fsanitize=address -fno-omit-frame-pointer")
endif ()

if (DEFINED php_dir)
    set(PHP_CONFIG "${php_dir}/bin/php-config")
else ()
    set(PHP_CONFIG "php-config")
endif()

execute_process(COMMAND ${PHP_CONFIG} --includes OUTPUT_VARIABLE PHP_INCLUDES OUTPUT_STRIP_TRAILING_WHITESPACE  RESULT_VARIABLE PHP_CONFIG_RESULT)
if (NOT PHP_CONFIG_RESULT EQUAL 0)
    message(FATAL_ERROR "Failed to execute php-config: ${PHP_CONFIG_RESULT}")
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

message("PHP_PREFIX: ${PHP_PREFIX}")
message("PHP_INCLUDES: ${PHP_INCLUDES}")
message("PHP_LIBS: ${PHP_LIBS}")
message("PHP_LDFLAGS: ${PHP_LDFLAGS}")

include_directories(include tests/include)
link_directories(${PHP_PREFIX}/lib)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${PHP_INCLUDES}")

set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/lib)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/lib)
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)

if (APPLE)
    SET(CMAKE_SHARED_LINKER_FLAGS  "${CMAKE_SHARED_LINKER_FLAGS} -undefined dynamic_lookup")
    message(${CMAKE_SHARED_LINKER_FLAGS})
endif ()

# library
add_library(phpx SHARED ${DIR_SRCS})
set_target_properties(phpx PROPERTIES CLEAN_DIRECT_OUTPUT 1)
target_link_libraries(phpx ${PHP_LIBS} ${PHP_LDFLAGS} php)

if (CODE_COVERAGE)
    target_link_libraries(phpx coverage_config gcov)
endif(CODE_COVERAGE)

# find GTest
find_package(GTest)
if (!${GTEST_FOUND})
    message(FATAL_ERROR "Not found GTest")
endif()
message(STATUS "Found GTest")

# tests
file(GLOB_RECURSE TEST_FILES tests/src/*.cpp)
add_executable(phpx-tests ${TEST_FILES})
add_dependencies(phpx-tests phpx)
target_link_libraries(phpx-tests php phpx ${GTEST_BOTH_LIBRARIES})

# install
install(CODE "MESSAGE(\"Are you run command using root user?\")")
install(TARGETS phpx LIBRARY DESTINATION lib ARCHIVE DESTINATION lib)
install(FILES ${HEADER_FILES} DESTINATION include)

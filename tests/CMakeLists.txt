cmake_minimum_required(VERSION 2.8.1)

project(phpx_tests)

#set(CMAKE_BUILD_TYPE Released)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -Wall -g")

file(GLOB_RECURSE SOURCE_FILES FOLLOW_SYMLINKS src/*.cpp)

execute_process(COMMAND ${PHP_CONFIG_DIR}php-config --include-dir
        OUTPUT_VARIABLE PHP_INCLUDE_DIR
        OUTPUT_STRIP_TRAILING_WHITESPACE
        )
        
execute_process(COMMAND ${PHP_CONFIG_DIR}php-config --prefix
        OUTPUT_VARIABLE PHP_PREFIX_DIR
        OUTPUT_STRIP_TRAILING_WHITESPACE
        )

execute_process(COMMAND ${PHP_CONFIG_DIR}php-config --libs
        OUTPUT_VARIABLE PHP_LIBS
        OUTPUT_STRIP_TRAILING_WHITESPACE
        )
execute_process(COMMAND ${PHP_CONFIG_DIR}php-config --ldflags
        OUTPUT_VARIABLE PHP_LDFLAGS
        OUTPUT_STRIP_TRAILING_WHITESPACE
        )

message("PHP_INCLUDE_DIR: ${PHP_INCLUDE_DIR}")

set(phpx_tests_includes ./include/ ../include)
set(phpx_tests_libraries)
set(phpx_tests_link_directories /usr/local/lib ${PHP_PREFIX_DIR}/lib ../lib)

include_directories(${PHP_INCLUDE_DIR} ${PHP_INCLUDE_DIR}/Zend ${PHP_INCLUDE_DIR}/main ${PHP_INCLUDE_DIR}/TSRM BEFORE)

list(APPEND phpx_tests_libraries php7 phpx pthread)

# find GTest
find_package(GTest)
if (!${GTEST_FOUND})
    message(FATAL_ERROR "Not found GTest")
endif()
message(STATUS "Found GTest")

list(APPEND phpx_tests_libraries ${GTEST_BOTH_LIBRARIES})
list(APPEND phpx_tests_includes ${GTEST_INCLUDE_DIRS})

if (DEFINED enable_asan)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fsanitize=address -fno-omit-frame-pointer")
endif()

# should execute before the add_executable command
link_directories(${phpx_tests_link_directories})

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)
add_executable(phpx_tests ${SOURCE_FILES})
target_include_directories(phpx_tests PRIVATE ${phpx_tests_includes})
target_link_libraries(phpx_tests ${phpx_tests_libraries})

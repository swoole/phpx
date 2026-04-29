cmake_minimum_required(VERSION 3.10)
project(phpx)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

if (NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Debug CACHE STRING "Build type" FORCE)
endif ()

# ============ 平台检测 ============
if(WIN32)
    message(STATUS "Configuring for Windows platform")
    set(IS_WINDOWS TRUE)
else()
    set(IS_WINDOWS FALSE)
endif()

# ============ Code Coverage Configuration (仅非 Windows) ============
add_library(coverage_config INTERFACE)

option(CODE_COVERAGE "Enable coverage reporting" OFF)
if(CODE_COVERAGE AND NOT IS_WINDOWS)
    message(STATUS "Open coverage")
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
endif()

# ============ Address Sanitizer (仅非 Windows) ============
option(enable_asan "Enable address sanitize" OFF)
if (enable_asan AND NOT IS_WINDOWS)
    message(STATUS "Enabled ASAN")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fsanitize=address -fno-omit-frame-pointer")
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -fsanitize=address -fno-omit-frame-pointer")
endif ()

# ============ PHP 配置 ============
if(IS_WINDOWS)
    # Windows 平台：使用指定的目录
    set(PHP_SOURCE_DIR "D:/workspace/php-8.4.20-src" CACHE PATH "PHP source directory")
    set(PHP_INSTALL_DIR "D:/workspace/php-8.4.20" CACHE PATH "PHP installation directory")
    
    # 验证目录是否存在
    if(NOT EXISTS ${PHP_SOURCE_DIR})
        message(FATAL_ERROR "PHP source directory not found: ${PHP_SOURCE_DIR}")
    endif()
    
    if(NOT EXISTS ${PHP_INSTALL_DIR})
        message(FATAL_ERROR "PHP installation directory not found: ${PHP_INSTALL_DIR}")
    endif()
    
    # 设置 PHP 头文件路径
    set(PHP_INCLUDE_DIRS
        ${PHP_SOURCE_DIR}
        ${PHP_SOURCE_DIR}/main
        ${PHP_SOURCE_DIR}/Zend
        ${PHP_SOURCE_DIR}/TSRM
        ${PHP_SOURCE_DIR}/ext
    )
    
    # 检查是否存在 x64/Release 或其他构建目录
    if(EXISTS ${PHP_SOURCE_DIR}/x64/Release_TS)
        list(APPEND PHP_INCLUDE_DIRS ${PHP_SOURCE_DIR}/x64/Release_TS)
    elseif(EXISTS ${PHP_SOURCE_DIR}/x64/Release)
        list(APPEND PHP_INCLUDE_DIRS ${PHP_SOURCE_DIR}/x64/Release)
    elseif(EXISTS ${PHP_SOURCE_DIR}/Release_TS)
        list(APPEND PHP_INCLUDE_DIRS ${PHP_SOURCE_DIR}/Release_TS)
    endif()
    
    # 设置 PHP 库文件
    set(PHP_LIBRARY_DIR ${PHP_INSTALL_DIR})
    
    # 查找 php8.lib 或 php8ts.lib
    find_library(PHP_LIBRARY
        NAMES php8ts php8 php
        PATHS ${PHP_LIBRARY_DIR} ${PHP_LIBRARY_DIR}/dev
        NO_DEFAULT_PATH
    )
    
    if(NOT PHP_LIBRARY)
        message(FATAL_ERROR "PHP library not found in ${PHP_LIBRARY_DIR}")
    endif()
    
    # 设置 PHP DLL 路径
    find_file(PHP_DLL
        NAMES php8ts.dll php8.dll
        PATHS ${PHP_INSTALL_DIR}
        NO_DEFAULT_PATH
    )
    
    if(NOT PHP_DLL)
        message(WARNING "PHP DLL not found in ${PHP_INSTALL_DIR}")
    endif()
    
    set(PHP_EXTENSION_DIR ${PHP_INSTALL_DIR}/ext)
    set(PHP_PREFIX ${PHP_INSTALL_DIR})
    
    message(STATUS "PHP_SOURCE_DIR: ${PHP_SOURCE_DIR}")
    message(STATUS "PHP_INSTALL_DIR: ${PHP_INSTALL_DIR}")
    message(STATUS "PHP_LIBRARY: ${PHP_LIBRARY}")
    message(STATUS "PHP_DLL: ${PHP_DLL}")
    message(STATUS "PHP_INCLUDE_DIRS: ${PHP_INCLUDE_DIRS}")
    
else()
    # Unix/Linux/Mac 平台：使用 php-config
    if (DEFINED php_dir)
        set(PHP_CONFIG "${php_dir}/bin/php-config")
    else ()
        set(PHP_CONFIG "php-config")
    endif()

    execute_process(COMMAND ${PHP_CONFIG} --includes 
        OUTPUT_VARIABLE PHP_INCLUDES 
        OUTPUT_STRIP_TRAILING_WHITESPACE  
        RESULT_VARIABLE PHP_CONFIG_RESULT)
    if (NOT PHP_CONFIG_RESULT EQUAL 0)
        message(FATAL_ERROR "Failed to execute php-config: ${PHP_CONFIG_RESULT}")
    endif()

    execute_process(COMMAND ${PHP_CONFIG} --extension-dir 
        OUTPUT_VARIABLE PHP_EXTENSION_DIR 
        OUTPUT_STRIP_TRAILING_WHITESPACE 
        RESULT_VARIABLE PHP_CONFIG_RESULT)
    if (NOT PHP_CONFIG_RESULT EQUAL 0)
        message(FATAL_ERROR "Failed to execute php-config: ${PHP_CONFIG_RESULT}")
    endif()

    execute_process(COMMAND ${PHP_CONFIG} --libs 
        OUTPUT_VARIABLE PHP_LIBS 
        OUTPUT_STRIP_TRAILING_WHITESPACE 
        RESULT_VARIABLE PHP_CONFIG_RESULT)
    if (NOT PHP_CONFIG_RESULT EQUAL 0)
        message(FATAL_ERROR "Failed to execute php-config: ${PHP_CONFIG_RESULT}")
    endif()

    execute_process(COMMAND ${PHP_CONFIG} --ldflags 
        OUTPUT_VARIABLE PHP_LDFLAGS 
        OUTPUT_STRIP_TRAILING_WHITESPACE 
        RESULT_VARIABLE PHP_CONFIG_RESULT)
    if (NOT PHP_CONFIG_RESULT EQUAL 0)
        message(FATAL_ERROR "Failed to execute php-config: ${PHP_CONFIG_RESULT}")
    endif()

    execute_process(COMMAND ${PHP_CONFIG} --prefix 
        OUTPUT_VARIABLE PHP_PREFIX 
        OUTPUT_STRIP_TRAILING_WHITESPACE 
        RESULT_VARIABLE PHP_CONFIG_RESULT)
    if (NOT PHP_CONFIG_RESULT EQUAL 0)
        message(FATAL_ERROR "Failed to execute php-config: ${PHP_CONFIG_RESULT}")
    endif()

    message(STATUS "PHP_PREFIX: ${PHP_PREFIX}")
    message(STATUS "PHP_INCLUDES: ${PHP_INCLUDES}")
    message(STATUS "PHP_LIBS: ${PHP_LIBS}")
    message(STATUS "PHP_LDFLAGS: ${PHP_LDFLAGS}")
    
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${PHP_INCLUDES}")
endif()

# ============ 包含目录 ============
include_directories(include tests/include)

if(IS_WINDOWS)
    include_directories(${PHP_INCLUDE_DIRS})
endif()

# ============ 链接目录 ============
if(IS_WINDOWS)
    link_directories(${PHP_LIBRARY_DIR})
else()
    link_directories(${PHP_PREFIX}/lib)
endif()

# ============ 输出目录 ============
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/lib)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/lib)
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)

# ============ 平台特定链接标志 ============
if (APPLE)
    SET(CMAKE_SHARED_LINKER_FLAGS "${CMAKE_SHARED_LINKER_FLAGS} -undefined dynamic_lookup")
    message(STATUS "macOS linker flags: ${CMAKE_SHARED_LINKER_FLAGS}")
elseif(IS_WINDOWS)
    # Windows 下需要导出符号
    set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)
endif()

# ============ 主库 phpx ============
file(GLOB_RECURSE SRC_FILES src/core/*.cc src/func/*.cc src/class/*.cc src/const/*.cc)
file(GLOB_RECURSE HEADER_FILES include/*.h)

add_library(phpx SHARED ${SRC_FILES})
set_target_properties(phpx PROPERTIES 
    CLEAN_DIRECT_OUTPUT 1
    PREFIX ""  # 去掉 lib 前缀
)

if (IS_WINDOWS)
    # Windows 平台链接 PHP 库
    target_link_libraries(phpx PRIVATE ${PHP_LIBRARY})
    target_compile_definitions(phpx PRIVATE PHP_EXPORTS)
    
    # 设置输出名称
    set_target_properties(phpx PROPERTIES
        OUTPUT_NAME "phpx"
        SUFFIX ".dll"
    )
    
    # 添加 Windows 特定的编译定义
    target_compile_definitions(phpx PRIVATE
        ZEND_WIN32
        PHP_WIN32
        ZEND_DEBUG=0
    )
    
    # 复制 PHP DLL 到输出目录（如果需要）
    if(PHP_DLL)
        add_custom_command(TARGET phpx POST_BUILD
            COMMAND ${CMAKE_COMMAND} -E copy_if_different
                ${PHP_DLL}
                $<TARGET_FILE_DIR:phpx>
            COMMENT "Copying PHP DLL to output directory"
        )
    endif()
endif()

if (CODE_COVERAGE AND NOT IS_WINDOWS)
    target_link_libraries(phpx coverage_config gcov)
endif()

# ============ 测试 (需要 GTest) ============
option(BUILD_TESTS "Build tests" ON)
if(BUILD_TESTS)
    find_package(GTest)
    if(NOT GTEST_FOUND)
        message(WARNING "GTest not found, skipping tests")
        set(BUILD_TESTS OFF)
    else()
        message(STATUS "Found GTest: ${GTEST_LIBRARIES}")
        
        file(GLOB_RECURSE TEST_FILES tests/src/*.cpp)
        add_executable(phpx-tests ${TEST_FILES})
        add_dependencies(phpx-tests phpx)
        
        if(IS_WINDOWS)
            target_link_libraries(phpx-tests 
                PRIVATE
                    ${PHP_LIBRARY}
                    phpx
                    ${GTEST_BOTH_LIBRARIES}
            )
            
            # 复制 DLL 到测试可执行文件目录
            add_custom_command(TARGET phpx-tests POST_BUILD
                COMMAND ${CMAKE_COMMAND} -E copy_if_different
                    $<TARGET_FILE:phpx>
                    $<TARGET_FILE_DIR:phpx-tests>
                COMMENT "Copying phpx.dll to test directory"
            )
            
            if(PHP_DLL)
                add_custom_command(TARGET phpx-tests POST_BUILD
                    COMMAND ${CMAKE_COMMAND} -E copy_if_different
                        ${PHP_DLL}
                        $<TARGET_FILE_DIR:phpx-tests>
                    COMMENT "Copying PHP DLL to test directory"
                )
            endif()
        else()
            target_link_libraries(phpx-tests 
                PRIVATE
                    php 
                    phpx 
                    ${PHP_LIBS_NO_PHP} 
                    ${PHP_LDFLAGS} 
                    ${GTEST_BOTH_LIBRARIES}
            )
        endif()
    endif()
endif()

# ============ 扩展库 ext ============
option(BUILD_EXT "Build extension library" ON)
if(BUILD_EXT)
    file(GLOB_RECURSE EXT_FILES tests/ext/*.cpp)
    if(EXT_FILES)
        add_library(ext SHARED ${EXT_FILES})
        add_dependencies(ext phpx)
        target_link_libraries(ext PRIVATE phpx)
        
        set_target_properties(ext PROPERTIES 
            PREFIX ""
        )
        
        if(IS_WINDOWS)
            set_target_properties(ext PROPERTIES SUFFIX ".dll")
            
            # 复制依赖的 DLL
            add_custom_command(TARGET ext POST_BUILD
                COMMAND ${CMAKE_COMMAND} -E copy_if_different
                    $<TARGET_FILE:phpx>
                    $<TARGET_FILE_DIR:ext>
                COMMENT "Copying phpx.dll to ext directory"
            )
        endif()
    else()
        message(WARNING "No extension files found in tests/ext/")
    endif()
endif()

# ============ 安装 ============
if(IS_WINDOWS)
    # Windows 安装配置
    install(TARGETS phpx 
        RUNTIME DESTINATION ${PHP_PREFIX}
        LIBRARY DESTINATION ${PHP_PREFIX}
        ARCHIVE DESTINATION ${PHP_PREFIX}/dev
    )
    install(FILES ${HEADER_FILES} DESTINATION ${PHP_PREFIX}/dev/include/phpx)
    
    message(STATUS "Install destination: ${PHP_PREFIX}")
else()
    # Unix/Linux/Mac 安装配置
    install(CODE "MESSAGE(\"Are you run command using root user?\")")
    install(TARGETS phpx LIBRARY DESTINATION ${PHP_PREFIX}/lib)
    install(FILES ${HEADER_FILES} DESTINATION ${PHP_PREFIX}/include/phpx)
endif()

# ============ 打印配置摘要 ============
message(STATUS "=================================")
message(STATUS "Build Configuration Summary")
message(STATUS "=================================")
message(STATUS "Platform: ${CMAKE_SYSTEM_NAME}")
message(STATUS "Build Type: ${CMAKE_BUILD_TYPE}")
message(STATUS "C++ Standard: ${CMAKE_CXX_STANDARD}")
if(IS_WINDOWS)
    message(STATUS "PHP Source: ${PHP_SOURCE_DIR}")
    message(STATUS "PHP Install: ${PHP_INSTALL_DIR}")
else()
    message(STATUS "PHP Prefix: ${PHP_PREFIX}")
endif()
message(STATUS "Build Tests: ${BUILD_TESTS}")
message(STATUS "Build Extension: ${BUILD_EXT}")
message(STATUS "=================================")

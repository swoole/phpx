cmake_minimum_required(VERSION 3.10)
project(phpx)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

if (NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Release CACHE STRING "Build type" FORCE)
endif ()

# ============ 调试配置 ============
if(CMAKE_BUILD_TYPE STREQUAL "Debug")
    message(STATUS "Building in Debug mode with debug symbols")
    if(IS_WINDOWS)
        # Windows Debug 模式：添加调试信息和详细输出
        add_compile_options(
            /Zi          # 生成调试信息
            /Od          # 禁用优化，方便调试
            /RTC1        # 运行时错误检查
        )
        # 设置链接选项以生成完整的调试信息
        set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} /DEBUG")
        set(CMAKE_SHARED_LINKER_FLAGS "${CMAKE_SHARED_LINKER_FLAGS} /DEBUG")
    else()
        # Unix/Linux/Mac Debug 模式
        add_compile_options(-g -O0)
        add_definitions(-DDEBUG=1)
    endif()
else()
    message(STATUS "Building in ${CMAKE_BUILD_TYPE} mode")
endif()

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
    # Windows 平台：必须设置 PHP_HOME 环境变量

    # 检查 PHP_HOME 环境变量是否存在
    if(NOT DEFINED ENV{PHP_HOME})
        message(FATAL_ERROR "PHP_HOME environment variable is not set.\nPlease set PHP_HOME to your PHP installation directory.\nExample: setx PHP_HOME \"C:\\php\"")
    endif()

    set(PHP_INSTALL_DIR $ENV{PHP_HOME})
    message(STATUS "Using PHP installation directory from PHP_HOME: ${PHP_INSTALL_DIR}")

    # 验证 PHP 安装目录是否存在
    if(NOT EXISTS ${PHP_INSTALL_DIR})
        message(FATAL_ERROR "PHP installation directory not found: ${PHP_INSTALL_DIR}\nPlease verify PHP_HOME environment variable is set correctly.")
    endif()

    # 设置 SDK 目录（PHP 8.x 标准结构）
    set(PHP_SDK_DIR ${PHP_INSTALL_DIR}/SDK)
    set(PHP_DEV_DIR_NAME "SDK")

    # 验证 SDK 目录是否存在
    if(NOT EXISTS ${PHP_SDK_DIR})
        message(FATAL_ERROR "PHP SDK directory not found: ${PHP_SDK_DIR}\nExpected structure: \$PHP_HOME/SDK/include\nPlease verify PHP_HOME is set to the correct PHP installation directory.")
    endif()

    # 设置 PHP 头文件路径（从 SDK 目录）
    set(PHP_INCLUDE_DIRS
        ${PHP_SDK_DIR}/include
        ${PHP_SDK_DIR}/include/main
        ${PHP_SDK_DIR}/include/Zend
        ${PHP_SDK_DIR}/include/TSRM
        ${PHP_SDK_DIR}/include/ext
    )

    # 检查构建类型对应的配置目录（用于 zend_config.w32.h）
    if(EXISTS ${PHP_SDK_DIR}/include/Zend/zend_config.w32.h)
        message(STATUS "Found zend_config.w32.h in Zend directory")
    else()
        message(WARNING "zend_config.w32.h not found in ${PHP_SDK_DIR}/include/Zend")
    endif()

    # 验证关键头文件是否存在
    if(NOT EXISTS ${PHP_SDK_DIR}/include/main/php.h)
        message(FATAL_ERROR "PHP header file not found: ${PHP_SDK_DIR}/include/main/php.h\nPlease verify PHP SDK directory structure is correct.")
    endif()

    # 设置 PHP 库文件路径
    set(PHP_LIBRARY_DIR ${PHP_SDK_DIR}/lib)

    # 验证库目录是否存在
    if(NOT EXISTS ${PHP_LIBRARY_DIR})
        message(FATAL_ERROR "PHP library directory not found: ${PHP_LIBRARY_DIR}\nExpected structure: \$PHP_HOME/SDK/lib")
    endif()

    # 查找 php8.lib 或 php8ts.lib
    find_library(PHP_LIBRARY
        NAMES php8ts php8
        PATHS ${PHP_LIBRARY_DIR}
        NO_DEFAULT_PATH
    )

    if(NOT PHP_LIBRARY)
        message(FATAL_ERROR "PHP library not found in ${PHP_LIBRARY_DIR}")
    endif()

    # 根据找到的库文件确定是否启用 ZTS
    get_filename_component(PHP_LIB_NAME ${PHP_LIBRARY} NAME)
    if(${PHP_LIB_NAME} STREQUAL "php8ts.lib")
        set(ZTS_ENABLED TRUE)
        message(STATUS "Found Thread-Safe PHP library: ${PHP_LIBRARY}")
    else()
        set(ZTS_ENABLED FALSE)
        message(STATUS "Found Non-Thread-Safe PHP library: ${PHP_LIBRARY}")
    endif()

    # 查找 embed 库（固定使用 php8embed.lib）
    find_library(PHP_EMBED_LIBRARY
        NAMES php8embed
        PATHS ${PHP_LIBRARY_DIR}
        NO_DEFAULT_PATH
    )

    if(PHP_EMBED_LIBRARY)
        message(STATUS "Found PHP Embed library: ${PHP_EMBED_LIBRARY}")
        option(USE_PHP_EMBED "Use PHP Embed SAPI" OFF)
    else()
        message(STATUS "PHP Embed library not found (optional)")
        set(USE_PHP_EMBED OFF CACHE BOOL "Use PHP Embed SAPI" FORCE)
    endif()

    set(PHP_EXTENSION_DIR ${PHP_INSTALL_DIR}/ext)
    set(PHP_PREFIX ${PHP_INSTALL_DIR})

    message(STATUS "PHP_INSTALL_DIR: ${PHP_INSTALL_DIR}")
    message(STATUS "PHP_SDK_DIR: ${PHP_SDK_DIR}")
    message(STATUS "PHP_LIBRARY_DIR: ${PHP_LIBRARY_DIR}")
    message(STATUS "PHP_LIBRARY: ${PHP_LIBRARY}")

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

    # Windows 下添加额外的编译选项
    add_compile_options(
        /wd4996    # 禁用 deprecated 警告
        /wd4267    # 禁用 size_t 转换警告
        /wd4244    # 禁用类型转换警告
        /wd4146    # 禁用一元负运算符应用于无符号类型的警告
        /wd4018    # 禁用有符号/无符号不匹配警告
        /wd4305    # 禁用截断警告
        /wd4309    # 禁用截断常量值警告
        /wd4804    # 禁用不安全的使用布尔类型警告
    )

    # Debug 模式下显示更多编译信息
    if(CMAKE_BUILD_TYPE STREQUAL "Debug")
        message(STATUS "Windows Debug mode: Adding verbose compilation output")
        add_compile_options(/showIncludes)  # 显示包含的头文件
    endif()
endif()

# ============ 链接目录 ============
if(IS_WINDOWS)
    link_directories(${PHP_LIBRARY_DIR})
else()
    link_directories(${PHP_PREFIX}/lib)
endif()

set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/lib)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/lib)
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)

if (APPLE)
    SET(CMAKE_SHARED_LINKER_FLAGS "${CMAKE_SHARED_LINKER_FLAGS} -undefined dynamic_lookup")
    message(STATUS "macOS linker flags: ${CMAKE_SHARED_LINKER_FLAGS}")
elseif(IS_WINDOWS)
    # Windows 下需要导出符号
    set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)
endif()

file(GLOB_RECURSE SRC_FILES src/core/*.cc src/func/*.cc src/class/*.cc src/const/*.cc)
file(GLOB_RECURSE HEADER_FILES include/*.h)

add_library(phpx SHARED ${SRC_FILES})
set_target_properties(phpx PROPERTIES
    CLEAN_DIRECT_OUTPUT 1
)

if (IS_WINDOWS)
    target_link_libraries(phpx PRIVATE
        ${PHP_LIBRARY}
    )

    target_compile_definitions(phpx PUBLIC
        PHP_EXPORTS
        ZEND_WIN32
        PHP_WIN32
        ZEND_DEBUG=0
        $<$<BOOL:${ZTS_ENABLED}>:ZTS>
    )

    set_target_properties(phpx PROPERTIES
        OUTPUT_NAME "phpx"
        SUFFIX ".dll"
    )

    if(PHP_EMBED_LIBRARY AND USE_PHP_EMBED)
        add_custom_command(TARGET phpx POST_BUILD
            COMMAND ${CMAKE_COMMAND} -E copy_if_different
                ${PHP_EMBED_LIBRARY}
                $<TARGET_FILE_DIR:phpx>
            COMMENT "Copying PHP Embed library to output directory"
        )
    endif()
else()
    target_link_libraries(phpx PRIVATE php)
endif()

if (CODE_COVERAGE AND NOT IS_WINDOWS)
    target_link_libraries(phpx PRIVATE coverage_config gcov)
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

            if(PHP_EMBED_LIBRARY AND USE_PHP_EMBED)
                add_custom_command(TARGET phpx-tests POST_BUILD
                    COMMAND ${CMAKE_COMMAND} -E copy_if_different
                        ${PHP_EMBED_LIBRARY}
                        $<TARGET_FILE_DIR:phpx-tests>
                    COMMENT "Copying PHP Embed library to test directory"
                )
            endif()
        else()
            target_link_libraries(phpx-tests
                PRIVATE
                    phpx
                    ${PHP_LIBS}
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
        ARCHIVE DESTINATION ${PHP_PREFIX}/${PHP_DEV_DIR_NAME}
    )
    install(FILES ${HEADER_FILES} DESTINATION ${PHP_PREFIX}/${PHP_DEV_DIR_NAME}/include/phpx)

    message(STATUS "Install destination: ${PHP_PREFIX}")
    message(STATUS "Dev directory name: ${PHP_DEV_DIR_NAME}")
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
if(CMAKE_BUILD_TYPE STREQUAL "Debug")
    message(STATUS "Debug Mode: Enabled with debug symbols and runtime checks")
    if(IS_WINDOWS)
        message(STATUS "  - Debug symbols: /Zi (PDB files)")
        message(STATUS "  - Optimization: /Od (disabled)")
        message(STATUS "  - Runtime checks: /RTC1")
        message(STATUS "  - Verbose output: /showIncludes")
    else()
        message(STATUS "  - Debug symbols: -g")
        message(STATUS "  - Optimization: -O0 (disabled)")
        message(STATUS "  - Debug macro: -DDEBUG=1")
    endif()
endif()
message(STATUS "C++ Standard: ${CMAKE_CXX_STANDARD}")
if(IS_WINDOWS)
    message(STATUS "PHP Install: ${PHP_INSTALL_DIR}")
    message(STATUS "PHP SDK: ${PHP_SDK_DIR}")
    message(STATUS "PHP Library: ${PHP_LIBRARY}")
else()
    message(STATUS "PHP Prefix: ${PHP_PREFIX}")
endif()
message(STATUS "Build Tests: ${BUILD_TESTS}")
message(STATUS "Build Extension: ${BUILD_EXT}")
message(STATUS "=================================")

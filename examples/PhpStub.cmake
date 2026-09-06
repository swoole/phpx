function(phpx_generate_arginfo target stub_file)
    if(NOT TARGET ${target})
        message(FATAL_ERROR "Unknown target: ${target}")
    endif()

    execute_process(
        COMMAND "${PHP_CONFIG}" --php-binary
        OUTPUT_VARIABLE PHP_EXECUTABLE
        OUTPUT_STRIP_TRAILING_WHITESPACE
        RESULT_VARIABLE PHP_EXECUTABLE_RESULT
    )
    if(NOT PHP_EXECUTABLE_RESULT EQUAL 0 OR NOT EXISTS "${PHP_EXECUTABLE}")
        message(FATAL_ERROR "Unable to locate PHP CLI through ${PHP_CONFIG}")
    endif()

    set(GENERATED_TOOL "${CMAKE_CURRENT_SOURCE_DIR}/build/gen_stub.php")
    if(NOT EXISTS "${GENERATED_TOOL}" OR NOT EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/run-tests.php")
        message(FATAL_ERROR
            "PHP extension build tools are missing. Run `phpx init` in ${CMAKE_CURRENT_SOURCE_DIR} first."
        )
    endif()

    get_filename_component(STUB_SOURCE "${stub_file}" ABSOLUTE BASE_DIR "${CMAKE_CURRENT_SOURCE_DIR}")
    get_filename_component(STUB_NAME "${STUB_SOURCE}" NAME)
    get_filename_component(STUB_DIR "${STUB_SOURCE}" DIRECTORY)
    string(REGEX REPLACE "\\.stub\\.php$" "" STUB_BASE "${STUB_NAME}")

    set(GENERATED_ARGINFO "${STUB_DIR}/${STUB_BASE}_arginfo.h")

    add_custom_command(
        OUTPUT "${GENERATED_ARGINFO}"
        COMMAND "${PHP_EXECUTABLE}" -n "${GENERATED_TOOL}" --force-regeneration "${STUB_SOURCE}"
        DEPENDS "${STUB_SOURCE}" "${GENERATED_TOOL}"
        COMMENT "Generating ${STUB_BASE}_arginfo.h with PHP's gen_stub.php"
        VERBATIM
    )

    target_sources(${target} PRIVATE "${GENERATED_ARGINFO}")
    target_include_directories(${target} PRIVATE "${STUB_DIR}")
endfunction()

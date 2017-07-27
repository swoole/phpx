#project
project(phpx)
aux_source_directory(src DIR_SRCS)
file(GLOB_RECURSE HEADER_FILES include/*.h)

set(CMAKE_BUILD_TYPE Debug)

if (DEFINED PHP_CONFIG_DIR)
  set(PHP_CONFIG_DIR "${PHP_CONFIG_DIR}/")
else()
  set(PHP_CONFIG_DIR "")
endif()

#execute_process(COMMAND ${PHP_CONFIG_DIR}php-config --includes
#        RESULT_VARIABLE PHP_INCLUDE
#        )

execute_process(COMMAND ${PHP_CONFIG_DIR}php-config --include-dir
        OUTPUT_VARIABLE PHP_INCLUDE_DIR
        OUTPUT_STRIP_TRAILING_WHITESPACE
        )

execute_process(COMMAND ${PHP_CONFIG_DIR}php-config --libs
        OUTPUT_VARIABLE PHP_LIBS
        OUTPUT_STRIP_TRAILING_WHITESPACE
        )
execute_process(COMMAND ${PHP_CONFIG_DIR}php-config --ldflags
        OUTPUT_VARIABLE ${PHP_LDFLAGS}
        OUTPUT_STRIP_TRAILING_WHITESPACE
        )

message("PHP_INCLUDE_DIR: ${PHP_INCLUDE_DIR}")

link_directories(${PHP_LDFLAGS})

include_directories(include)
include_directories(BEFORE ${PHP_INCLUDE_DIR} ${PHP_INCLUDE_DIR}/Zend ${PHP_INCLUDE_DIR}/main ${PHP_INCLUDE_DIR}/TSRM)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

if (APPLE)
    SET(CMAKE_SHARED_LINKER_FLAGS  "${CMAKE_SHARED_LINKER_FLAGS} -undefined dynamic_lookup")
    message(${CMAKE_SHARED_LINKER_FLAGS})
endif ()

#libary
add_library(phpx SHARED ${DIR_SRCS})

#install
install(CODE "MESSAGE(\"Are you run command using root user?\")")
install(TARGETS phpx LIBRARY DESTINATION lib ARCHIVE DESTINATION lib)
install(FILES ${HEADER_FILES} DESTINATION include)

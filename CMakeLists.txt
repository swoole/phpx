#project
project(phpx)
cmake_minimum_required(VERSION 3.5)
aux_source_directory(src DIR_SRCS)
file(GLOB_RECURSE HEADER_FILES include/*.h)

set(CMAKE_BUILD_TYPE Release)

#execute_process(COMMAND php-config --includes
#        RESULT_VARIABLE PHP_INCLUDE
#        )

execute_process(COMMAND php-config --include-dir
        OUTPUT_VARIABLE PHP_INCLUDE_DIR
        OUTPUT_STRIP_TRAILING_WHITESPACE
        )

execute_process(COMMAND php-config --libs
        OUTPUT_VARIABLE PHP_LIBS
        OUTPUT_STRIP_TRAILING_WHITESPACE
        )
execute_process(COMMAND php-config --ldflags
        OUTPUT_VARIABLE ${PHP_LDFLAGS}
        OUTPUT_STRIP_TRAILING_WHITESPACE
        )

link_directories(${PHP_LDFLAGS})

include_directories(include)
include_directories(BEFORE ${PHP_INCLUDE_DIR} ${PHP_INCLUDE_DIR}/Zend ${PHP_INCLUDE_DIR}/main ${PHP_INCLUDE_DIR}/TSRM)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
#libary
add_library(phpx SHARED ${DIR_SRCS})

#install
INSTALL(CODE "MESSAGE(\"Are you run command using root user?\")")
INSTALL(TARGETS phpx LIBRARY DESTINATION lib ARCHIVE DESTINATION lib)
INSTALL(FILES ${HEADER_FILES} DESTINATION include)
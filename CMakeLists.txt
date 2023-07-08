cmake_minimum_required(VERSION 3.25)
project(jfmt C)
set(CMAKE_C_STANDARD 99)

list(APPEND JFMT_PUBLIC_HEADERS source/include/jfmt/jfmt.h source/include/jfmt/cformatted.h source/include/jfmt/sformatted.h source/include/jfmt/sstream.h)
list(APPEND JFMT_SOURCE_FILES source/internal_formatted.c source/cformatted.c source/sformatted.c source/sstream.c)
list(APPEND JFMT_HEADER_FILES source/internal_formatted.h ${JFMT_PUBLIC_HEADERS})

add_library(jfmt ${JFMT_SOURCE_FILES} source/include/jfmt/jfmt_common.h)
target_link_libraries(jfmt PRIVATE jmem m)
enable_testing()
add_executable(formatted_string_test source/tests/fmt_test.c ${JFMT_SOURCE_FILES} ${JFMT_HEADER_FILES})
target_link_libraries(formatted_string_test PRIVATE jmem m)
add_test(NAME formatted_test COMMAND formatted_string_test)

target_sources(jfmt PUBLIC FILE_SET jfmt_header_list TYPE HEADERS BASE_DIRS source/include/jfmt FILES ${JFMT_PUBLIC_HEADERS})
include(GNUInstallDirs)
install(TARGETS jfmt
            FILE_SET jfmt_header_list
                DESTINATION "/usr/include/jfmt"
            ARCHIVE
                DESTINATION "/usr/lib")

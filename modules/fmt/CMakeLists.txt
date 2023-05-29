cmake_minimum_required(VERSION 3.26)

set(TARGET_NAME fmt-modules)
add_library(${TARGET_NAME})
target_link_libraries(${TARGET_NAME} PUBLIC stdcxx)
target_link_libraries(${TARGET_NAME} PUBLIC CONAN_PKG::fmt)

FILE(GLOB_RECURSE SRCS RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} *.cppm)
target_sources(${TARGET_NAME} PUBLIC
    FILE_SET cxx_modules TYPE CXX_MODULES
    BASE_DIRS
    ${CMAKE_CURRENT_SOURCE_DIR}
    FILES
    ${SRCS}
)

# cppm is non-standard by gcc
set_source_files_properties(src/ut.cppm PROPERTIES LANGUAGE CXX)
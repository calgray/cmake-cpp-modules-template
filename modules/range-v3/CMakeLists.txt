cmake_minimum_required(VERSION 3.26)

set(TARGET_NAME range-v3-modules)
add_library(${TARGET_NAME})
target_link_libraries(${TARGET_NAME} PUBLIC stdcxx)
target_link_libraries(${TARGET_NAME} PUBLIC CONAN_PKG::range-v3)

#target_compile_definitions(${TARGET_NAME} PUBLIC __cpp_coroutines=202000L)

FILE(GLOB_RECURSE SRCS RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} *.cppm)
target_sources(${TARGET_NAME} PUBLIC
    FILE_SET cxx_modules TYPE CXX_MODULES
    BASE_DIRS
    ${CMAKE_CURRENT_SOURCE_DIR}
    FILES
    ${SRCS}
)

# cppm is non-standard by gcc
set_source_files_properties(${SRCS} PROPERTIES LANGUAGE CXX)
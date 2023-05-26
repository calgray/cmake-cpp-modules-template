cmake_minimum_required(VERSION 3.26)

set(TARGET_NAME cppcoro-modules)
add_library(${TARGET_NAME})
target_link_libraries(${TARGET_NAME} PRIVATE CONAN_PKG::andreasbuhr-cppcoro)
target_link_libraries(${TARGET_NAME} PUBLIC stdcxx)
target_compile_options(${TARGET_NAME} PRIVATE -fexperimental-new-constant-interpreter)

target_sources(${TARGET_NAME} PUBLIC
    FILE_SET cxx_modules TYPE CXX_MODULES
    BASE_DIRS
    ${CMAKE_CURRENT_SOURCE_DIR}
    FILES
    src/cppcoro.cppm
)

# cppm is non-standard by gcc
set_source_files_properties(src/cppcoro.cppm PROPERTIES LANGUAGE CXX)
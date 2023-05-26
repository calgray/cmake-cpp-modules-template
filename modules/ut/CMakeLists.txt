cmake_minimum_required(VERSION 3.26)

set(TARGET_NAME boost-ext-ut-modules)
add_library(${TARGET_NAME})
target_link_libraries(${TARGET_NAME} PUBLIC stdcxx)
target_link_libraries(${TARGET_NAME} PUBLIC CONAN_PKG::boost-ext-ut)
target_include_directories(${TARGET_NAME} PRIVATE src)

target_sources(${TARGET_NAME} PUBLIC
    FILE_SET cxx_modules TYPE CXX_MODULES
    BASE_DIRS
        ${CMAKE_CURRENT_SOURCE_DIR}
    FILES
        src/ut.cppm
)

# cppm is non-standard by gcc
set_source_files_properties(src/ut.cppm PROPERTIES LANGUAGE CXX)
cmake_minimum_required(VERSION 3.26)

add_library(eigen-modules)
target_compile_features(eigen-modules PUBLIC cxx_std_20)
target_compile_definitions(eigen-modules PRIVATE __cpp_modules=1)
target_link_libraries(eigen-modules PUBLIC CONAN_PKG::eigen)
target_link_libraries(eigen-modules PUBLIC stdcxx)

FILE(GLOB_RECURSE SRCS RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} *.cppm)
target_sources(eigen-modules PUBLIC
    FILE_SET cxx_modules TYPE CXX_MODULES
    BASE_DIRS
    ${CMAKE_CURRENT_SOURCE_DIR}
    FILES
    ${SRCS}
)

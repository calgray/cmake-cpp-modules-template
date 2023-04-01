cmake_minimum_required(VERSION 3.26)

add_library(fmt-modules)
target_compile_features(fmt-modules PUBLIC cxx_std_20)
target_compile_definitions(fmt-modules PRIVATE __cpp_modules=1)
target_link_libraries(fmt-modules PUBLIC stdcxx)
target_link_libraries(fmt-modules PUBLIC CONAN_PKG::fmt)

FILE(GLOB_RECURSE SRCS RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} *.cppm)
target_sources(fmt-modules PUBLIC
    FILE_SET cxx_modules TYPE CXX_MODULES
    BASE_DIRS
    ${CMAKE_CURRENT_SOURCE_DIR}
    FILES
    ${SRCS}
)

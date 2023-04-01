cmake_minimum_required(VERSION 3.26)

add_library(range-v3-modules)
target_compile_features(range-v3-modules PUBLIC cxx_std_20)
target_compile_definitions(range-v3-modules PRIVATE __cpp_modules=1)
target_link_libraries(range-v3-modules PUBLIC stdcxx)
target_link_libraries(range-v3-modules PUBLIC CONAN_PKG::range-v3)

FILE(GLOB_RECURSE SRCS RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} *.cppm)
target_sources(range-v3-modules PUBLIC
    FILE_SET cxx_modules TYPE CXX_MODULES
    BASE_DIRS
    ${CMAKE_CURRENT_SOURCE_DIR}
    FILES
    ${SRCS}
)

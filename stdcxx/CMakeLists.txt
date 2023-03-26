cmake_minimum_required(VERSION 3.25)

# Library from https://github.com/ChuanqiXu9/stdmodules
add_library(stdcxx)
target_compile_features(stdcxx PUBLIC cxx_std_20)

# TODO: use clang stdc++
# target_compile_options(std PUBLIC -stdlib=libc++)

FILE(GLOB_RECURSE SRCS RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} *.cppm)
target_sources(stdcxx PUBLIC
    FILE_SET cxx_modules TYPE CXX_MODULES
    BASE_DIRS
    ${CMAKE_CURRENT_SOURCE_DIR}
    FILES
    ${SRCS}
)

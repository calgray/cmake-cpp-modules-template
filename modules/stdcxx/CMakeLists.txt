cmake_minimum_required(VERSION 3.26)

# Library from https://github.com/ChuanqiXu9/stdmodules
add_library(stdcxx)
target_compile_features(stdcxx PUBLIC cxx_std_20)
if(CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
    target_compile_options(stdcxx PUBLIC $<$<COMPILE_LANGUAGE:CXX>:-stdlib=libc++>)
    target_link_options(stdcxx PUBLIC $<$<COMPILE_LANGUAGE:CXX>:-stdlib=libc++>)
    
    if(CMAKE_CXX_COMPILER_VERSION GREATER 16)
        # Misnomer warning on module partitions
        target_compile_options(stdcxx PUBLIC $<$<COMPILE_LANGUAGE:CXX>:-Wno-read-modules-implicitly>)
    endif()
endif()

FILE(GLOB_RECURSE SRCS RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} *.cppm)
target_sources(stdcxx PUBLIC
    FILE_SET cxx_modules TYPE CXX_MODULES
    BASE_DIRS
    ${CMAKE_CURRENT_SOURCE_DIR}
    FILES
    ${SRCS}
)

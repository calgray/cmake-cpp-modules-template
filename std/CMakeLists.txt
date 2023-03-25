cmake_minimum_required(VERSION 3.25)

set(STD_MODULES
    iostream
    string
    vector
)
add_custom_target(std_modules ALL
    COMMAND ${CMAKE_COMMAND} -E echo "Building standard library modules"
    COMMAND
        ${CMAKE_CXX_COMPILER}
        -stdlib=libc++
        -std=c++20
        #-isystem /opt/clang/16.0.0/include/c++/v1
        -c -x c++-system-header ${STD_MODULES}
    WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
)


add_library(std_modules_lib INTERFACE)
target_sources(std_modules_lib INTERFACE
    ${CMAKE_CURRENT_BINARY_DIR}/iostream.pcm
    ${CMAKE_CURRENT_BINARY_DIR}/string.pcm
)

# Library from https://github.com/ChuanqiXu9/stdmodules
add_library(std)
target_link_libraries(std PUBLIC std_modules_lib)
target_compile_options(std PUBLIC -fprebuilt-module-path=${CMAKE_CURRENT_BINARY_DIR})
target_compile_features(std PUBLIC cxx_std_23)
FILE(GLOB_RECURSE SRCS RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} *.cppm)
target_sources(std PUBLIC
    FILE_SET cxx_modules TYPE CXX_MODULES
    BASE_DIRS
    ${CMAKE_CURRENT_SOURCE_DIR}
    FILES
    ${SRCS}
)

cmake_minimum_required(VERSION 3.25)

set(STD_MODULES
    iostream
    cstdio
)
add_custom_target(std_modules ALL
    COMMAND ${CMAKE_COMMAND} -E echo "Building standard library modules"
    COMMAND
        ${CMAKE_CXX_COMPILER}
        -std=c++20
        -c -x c++-system-header ${STD_MODULES}
    WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
)

add_library(headers)
target_compile_features(headers PUBLIC cxx_std_20)
target_sources(headers PUBLIC
    FILE_SET cxx_modules TYPE CXX_MODULES
    BASE_DIRS
    "${CMAKE_CURRENT_SOURCE_DIR}"/src
    FILES
    src/foo.cxx
    src/bar.cxx
)

add_dependencies(headers std_modules)
target_sources(headers PUBLIC
    FILE_SET cxx_header_units TYPE CXX_MODULE_HEADER_UNITS
    BASE_DIRS
    /opt/clang/16.0.0/include/c++/v1
    #${CMAKE_BINARY_DIR}
)

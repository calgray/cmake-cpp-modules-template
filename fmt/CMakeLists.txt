cmake_minimum_required(VERSION 3.25)

set(FMT_HEADERS fmt/core.h)
add_custom_target(fmt_header_units)
foreach(header ${FMT_HEADERS})
get_target_property(FMT_INCLUDES CONAN_PKG::fmt INTERFACE_INCLUDE_DIRECTORIES)
    add_custom_command(
        OUTPUT ${CMAKE_BINARY_DIR}/fmt.core.pcm
        COMMAND
            ${CMAKE_CXX_COMPILER}
            -std=c++20
            -I${FMT_INCLUDES}
            -c -x c++-user-header
            --precompile
            ${header}
            -o fmt.core.pcm
        WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
    )
    target_sources(fmt_header_units PRIVATE ${CMAKE_BINARY_DIR}/fmt.core.pcm)
endforeach()

# Library from https://github.com/ChuanqiXu9/stdmodules
add_library(fmt-module OBJECT)
add_dependencies(fmt-module fmt_header_units)
target_compile_options(fmt-module PUBLIC -fmodule-file=fmt.core.pcm)
target_compile_features(fmt-module PUBLIC cxx_std_20)
target_compile_definitions(fmt-module PRIVATE __cpp_modules=1)
target_link_libraries(fmt-module PUBLIC stdhu)

#WARNING: this is compiled with gcc?
target_link_libraries(fmt-module PUBLIC CONAN_PKG::fmt)


target_sources(fmt-module PUBLIC
    FILE_SET cxx_modules TYPE CXX_MODULES
    BASE_DIRS
    ${CMAKE_CURRENT_SOURCE_DIR}
    FILES
    src/fmtm.cc
)

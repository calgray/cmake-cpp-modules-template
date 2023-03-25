cmake_minimum_required(VERSION 3.25)


add_library(headers)
target_compile_features(headers PUBLIC cxx_std_20)

# see https://discourse.cmake.org/t/api-design-c-modules-source-listings-and-interface-properties/5389/2
target_sources(headers PUBLIC
    # FILE_SET cxx_header_units TYPE CXX_MODULE_HEADER_UNITS
    #     BASE_DIRS
    #         #/opt/clang/16.0.0/include/c++/v1
    #         ${CMAKE_CURRENT_SOURCE_DIR}
    #     FILES
    #         help.h
    #         #/opt/clang/16.0.0/include/c++/v1/iostream
    #         #/opt/clang/16.0.0/include/c++/v1/cstdio

            
    FILE_SET public_modules TYPE CXX_MODULES
        BASE_DIRS
            ${CMAKE_CURRENT_SOURCE_DIR}/src
        FILES
            src/main.cxx
)

target_link_libraries(headers PUBLIC std)
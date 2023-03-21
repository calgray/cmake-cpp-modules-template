cmake_minimum_required(VERSION 3.25)

add_library(foobar)
# target_sources(foobar PUBLIC
#     FILE_SET cxx_header_units TYPE CXX_MODULE_HEADER_UNITS
#     BASE_DIRS
#     /opt/clang/16.0.0/include/c++/v1
#     FILES
#     /opt/clang/16.0.0/include/c++/v1/iostream
# )
# target_compile_options(foobar PUBLIC
#     -fimplicit-modules
#     #-fimplicit-module-maps
# )
target_sources(foobar PUBLIC
    FILE_SET cxx_modules TYPE CXX_MODULES FILES
    src/foo.cxx
    src/bar.cxx
)

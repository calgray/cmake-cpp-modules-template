cmake_minimum_required(VERSION 3.25)

add_library(foobar)
target_compile_features(foobar PUBLIC cxx_std_20)
target_sources(foobar PUBLIC
    FILE_SET cxx_modules TYPE CXX_MODULES FILES
    src/foo.cxx
    src/bar.cxx
)

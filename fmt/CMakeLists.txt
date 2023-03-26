cmake_minimum_required(VERSION 3.25)

# Library from https://github.com/ChuanqiXu9/stdmodules
add_library(fmt)
target_compile_features(std PUBLIC cxx_std_20)
target_compile_definitions(fmt PRIVATE __cpp_modules=1)
target_link_libraries(fmt PUBLIC stdcxx)

#WARNING: this is compiled with gcc?
target_link_libraries(fmt PUBLIC CONAN_PKG::fmt)

target_sources(fmt PUBLIC
    FILE_SET cxx_modules TYPE CXX_MODULES
    BASE_DIRS
    ${CMAKE_CURRENT_SOURCE_DIR}
    FILES
    src/fmt.cc
)

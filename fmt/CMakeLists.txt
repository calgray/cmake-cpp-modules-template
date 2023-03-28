cmake_minimum_required(VERSION 3.25)

add_library(fmt)
target_compile_features(fmt PUBLIC cxx_std_20)
target_compile_definitions(fmt PRIVATE __cpp_modules=1)
target_link_libraries(fmt PUBLIC CONAN_PKG::fmt)
target_link_libraries(fmt PUBLIC stdcxx)

target_sources(fmt PUBLIC
    FILE_SET cxx_modules TYPE CXX_MODULES
    BASE_DIRS
    ${CMAKE_CURRENT_SOURCE_DIR}
    FILES
    src/fmt.cc
)

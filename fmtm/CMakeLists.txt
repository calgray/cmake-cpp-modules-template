cmake_minimum_required(VERSION 3.25)

add_library(fmtm)
target_compile_features(fmtm PUBLIC cxx_std_20)
# target_compile_definitions(fmtm PRIVATE __cpp_modules=1)
target_link_libraries(fmtm PUBLIC stdcxx)
target_link_libraries(fmtm PUBLIC CONAN_PKG::fmt)

target_sources(fmtm PUBLIC
    FILE_SET cxx_modules TYPE CXX_MODULES
    BASE_DIRS
    ${CMAKE_CURRENT_SOURCE_DIR}
    FILES
    src/fmtm.cc
)

cmake_minimum_required(VERSION 3.26)

add_library(cppcoro-modules)
target_compile_features(cppcoro-modules PUBLIC cxx_std_20)
target_compile_definitions(cppcoro-modules PRIVATE __cpp_modules=1)
target_link_libraries(cppcoro-modules PUBLIC CONAN_PKG::andreasbuhr-cppcoro)
target_link_libraries(cppcoro-modules PUBLIC stdcxx)

target_sources(cppcoro-modules PUBLIC
    FILE_SET cxx_modules TYPE CXX_MODULES
    BASE_DIRS
    ${CMAKE_CURRENT_SOURCE_DIR}
    FILES
    src/cppcoro.cppm
)

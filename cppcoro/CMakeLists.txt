cmake_minimum_required(VERSION 3.25)

add_library(cppcorom)
target_compile_features(cppcorom PUBLIC cxx_std_20)
target_compile_definitions(cppcorom PRIVATE __cpp_modules=1)
target_link_libraries(cppcorom PUBLIC CONAN_PKG::andreasbuhr-cppcoro)
target_link_libraries(cppcorom PUBLIC stdcxx)

target_sources(cppcorom PUBLIC
    FILE_SET cxx_modules TYPE CXX_MODULES
    BASE_DIRS
    ${CMAKE_CURRENT_SOURCE_DIR}
    FILES
    src/cppcoro.cxx
)

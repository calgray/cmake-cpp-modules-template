cmake_minimum_required(VERSION 3.25)

add_library(rangev3)
target_compile_features(rangev3 PUBLIC cxx_std_20)
target_compile_definitions(rangev3 PRIVATE __cpp_modules=1)
target_link_libraries(rangev3 PUBLIC CONAN_PKG::range-v3)

target_sources(rangev3 PUBLIC
    FILE_SET cxx_modules TYPE CXX_MODULES
    BASE_DIRS
    ${CMAKE_CURRENT_SOURCE_DIR}
    FILES
    src/range_v3.cxx
    src/range_v3.range.cxx
    src/range_v3.algorithm.cxx
    src/range_v3.views.cxx
)

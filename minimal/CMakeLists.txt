cmake_minimum_required(VERSION 3.25)

add_executable(minimal)
target_sources(minimal PUBLIC
    src/main.cxx
)
target_sources(minimal PUBLIC
    FILE_SET cxx_modules TYPE CXX_MODULES
    BASE_DIRS
        ${CMAKE_CURRENT_SOURCE_DIR}/src
    FILES
        src/lib.cxx
)


target_compile_features(stdhu PUBLIC cxx_std_20)
target_compile_options(minimal PUBLIC -stdlib=libc++)
target_link_options(minimal PUBLIC -stdlib=libc++)
target_include_directories(minimal SYSTEM PUBLIC /opt/clang/16.0.0/include)
target_compile_definitions(minimal PUBLIC
    -D_GNU_SOURCE
    -D__STDC_CONSTANT_MACROS
    -D__STDC_FORMAT_MACROS
    -D__STDC_LIMIT_MACROS
)
target_link_directories(minimal PUBLIC /opt/clang/16.0.0/lib)
target_link_libraries(minimal PUBLIC LLVM-16)
# target_link_libraries(minimal PUBLIC rangev3)
target_link_libraries(minimal PUBLIC stdcxx)

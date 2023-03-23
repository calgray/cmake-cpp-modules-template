add_library(std)
target_compile_features(std PUBLIC cxx_std_20)
target_sources(std PUBLIC
    FILE_SET cxx_modules TYPE CXX_MODULES
    BASE_DIRS
    "${CMAKE_CURRENT_SOURCE_DIR}"
    FILES
    std.cxx
)

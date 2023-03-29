add_library(ut)
target_compile_features(ut PUBLIC cxx_std_20)
target_sources(ut PUBLIC
    FILE_SET cxx_modules TYPE CXX_MODULES
    BASE_DIRS
        ${CMAKE_CURRENT_SOURCE_DIR}
    FILES
        src/ut.cxx
)
target_link_libraries(ut PUBLIC stdcxx)
# target_link_libraries(ut PUBLIC stdhu)
target_link_libraries(ut PUBLIC CONAN_PKG::boost-ext-ut)

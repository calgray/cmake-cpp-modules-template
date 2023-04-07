add_library(boost-ext-ut-modules)
target_compile_features(boost-ext-ut-modules PUBLIC cxx_std_20)
target_sources(boost-ext-ut-modules PUBLIC
    FILE_SET cxx_modules TYPE CXX_MODULES
    BASE_DIRS
        ${CMAKE_CURRENT_SOURCE_DIR}
    FILES
        src/ut.cppm
)
target_link_libraries(boost-ext-ut-modules PUBLIC stdcxx)
target_link_libraries(boost-ext-ut-modules PUBLIC CONAN_PKG::boost-ext-ut)
target_include_directories(boost-ext-ut-modules PRIVATE src)

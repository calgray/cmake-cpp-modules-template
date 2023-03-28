cmake_minimum_required(VERSION 3.25)

add_library(cppcoro)
target_compile_features(cppcoro PUBLIC cxx_std_20)
target_compile_definitions(cppcoro PRIVATE __cpp_modules=1)
# target_include_directories(cppcoro PUBLIC /home/callan/.conan/data/andreasbuhr-cppcoro/cci.20210113/_/_/package/174df609440df17baf334e1f5953cca909f2ae18/include)
target_link_libraries(cppcoro PUBLIC CONAN_PKG::andreasbuhr-cppcoro)

target_sources(cppcoro PUBLIC
    FILE_SET cxx_modules TYPE CXX_MODULES
    BASE_DIRS
    ${CMAKE_CURRENT_SOURCE_DIR}
    FILES
    src/cppcoro.cxx
)

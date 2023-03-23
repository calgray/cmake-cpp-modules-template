cmake_minimum_required(VERSION 3.25)

add_executable(helloworld src/main.cxx)
# target_sources(helloworld PUBLIC src/main.cxx)
# target_sources(helloworld PUBLIC
#     FILE_SET cxx_modules TYPE CXX_MODULES
#     BASE_DIRS
#     "${CMAKE_CURRENT_SOURCE_DIR}"/src
#     FILES
#     src/main.cxx
# )
target_link_libraries(helloworld foobar)

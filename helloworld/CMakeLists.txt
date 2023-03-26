cmake_minimum_required(VERSION 3.25)

add_executable(helloworld)
target_sources(helloworld PUBLIC
    src/main.cxx
)
# target_sources(helloworld PUBLIC
#     FILE_SET cxx_modules
#     TYPE CXX_MODULES
#     BASE_DIRS
#         ${CMAKE_CURRENT_SOURCE_DIR}
#     FILES
#         src/mainmod.cxx
# )

target_link_libraries(helloworld foobar)
target_link_libraries(helloworld ut)

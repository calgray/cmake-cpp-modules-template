cmake_minimum_required(VERSION 3.25)

add_executable(helloworld src/main.cxx)
target_link_libraries(helloworld foobar)

# target_compile_options(helloworld PUBLIC
#     -fmodule-file=iostream.pcm
# )

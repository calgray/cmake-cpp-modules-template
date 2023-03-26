cmake_minimum_required(VERSION 3.25)

add_executable(helloworld)
target_sources(helloworld PUBLIC
    src/main.cxx
)
target_link_libraries(helloworld foobar)

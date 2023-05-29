cmake_minimum_required(VERSION 3.26)

set(TARGET_NAME helloworld)
add_executable(${TARGET_NAME})
target_link_libraries(${TARGET_NAME} foobar)
target_sources(${TARGET_NAME} PUBLIC
    src/main.cxx
)

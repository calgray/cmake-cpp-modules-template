cmake_minimum_required(VERSION 3.26)

set_target_properties(${TARGET_NAME}
    PROPERTIES
        CXX_SCAN_FOR_MODULES ON
)

set(TARGET_NAME helloworld)
add_executable(${TARGET_NAME})

target_link_libraries(${TARGET_NAME} PUBLIC libcxx)
target_link_libraries(${TARGET_NAME} PUBLIC foobar)
target_link_libraries(${TARGET_NAME} PUBLIC fmt-modules)
if(ENABLE_EIGEN)
    target_link_libraries(${TARGET_NAME} PUBLIC eigen-modules)
endif()

target_sources(${TARGET_NAME}
    PUBLIC
        src/main.cxx
)
set_source_files_properties(
    src/main.cxx
    PROPERTIES
        CXX_SCAN_FOR_MODULES ON
)

cmake_minimum_required(VERSION 3.26)

add_library(foobar)
target_compile_features(foobar PUBLIC cxx_std_20)
target_link_libraries(foobar PUBLIC stdcxx)
target_link_libraries(foobar PUBLIC fmt-modules)
target_link_libraries(foobar PUBLIC range-v3-modules)

if(ENABLE_CUDA)
target_link_libraries(foobar PUBLIC cuda-modules)
endif()
if(ENABLE_CPPCORO)
target_link_libraries(foobar PUBLIC cppcoro-modules)
endif()

target_sources(foobar PUBLIC
    FILE_SET cxx_modules TYPE CXX_MODULES
    BASE_DIRS
        ${CMAKE_CURRENT_SOURCE_DIR}/src
    FILES
        src/foo.cxx
        src/bar.cxx
        src/cycle.cxx
        src/cycleA.cxx
        src/cycleB.cxx
)

if(ENABLE_CUDA)
    target_sources(foobar PUBLIC
    src/cuda_hello.cu
    )
    target_sources(foobar PUBLIC
        FILE_SET cuda_modules TYPE CXX_MODULES
        BASE_DIRS
            ${CMAKE_CURRENT_SOURCE_DIR}/src
        FILES
            src/cuda_hello.cxx
    )
endif()

enable_testing()
add_subdirectory(tests)

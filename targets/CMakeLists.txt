# Dependency Targets
add_subdirectory(cpp-deps-modules/libcxx)
add_subdirectory(cpp-deps-modules/range-v3)
add_subdirectory(cpp-deps-modules/fmt)
add_subdirectory(cpp-deps-modules/cli11)
if(ENABLE_EIGEN)
add_subdirectory(cpp-deps-modules/eigen)
endif()
add_subdirectory(cpp-deps-modules/unifex)
if(ENABLE_CUDA)
add_subdirectory(cpp-deps-modules/cuda)
endif()

add_subdirectory(cpp-deps-modules/ut)
add_subdirectory(cpp-deps-modules/nanobench)

# Project Targets
add_subdirectory(foobar)
add_subdirectory(examples/helloworld)

cmake_minimum_required(VERSION 3.26)

set(TARGET_NAME foobar_tests)
add_executable(${TARGET_NAME})
target_link_libraries(${TARGET_NAME} PRIVATE foobar)
target_link_libraries(${TARGET_NAME} PRIVATE boost-ext-ut-modules)
target_link_libraries(${TARGET_NAME} PUBLIC eigen-modules)

target_sources(${TARGET_NAME} PUBLIC
    main.cxx
    test_foo.cxx
    test_bar.cxx
    test_cycle.cxx
    test_bdd.cxx
    test_eigen.cxx
)
if(ENABLE_CUDA)
    target_link_libraries(${TARGET_NAME} PUBLIC cuda-modules)
    target_sources(${TARGET_NAME} PUBLIC
        test_cuda.cxx
    )
endif()
if(ENABLE_CPPCORO)
    target_link_libraries(${TARGET_NAME} PUBLIC cppcoro-modules)
    target_sources(${TARGET_NAME} PUBLIC
        test_coro.cxx
    )
endif()

enable_testing()
add_test(NAME ${TARGET_NAME} COMMAND foobar_tests)
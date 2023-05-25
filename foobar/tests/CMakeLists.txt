cmake_minimum_required(VERSION 3.26)


add_executable(foobar_tests)
target_compile_features(foobar PUBLIC cxx_std_20)
target_sources(foobar_tests PUBLIC
    main.cxx
    test_foo.cxx
    test_bar.cxx
    test_cycle.cxx
    # test_coro.cxx
    test_eigen.cxx
    # test_cuda.cxx
)
target_link_libraries(foobar_tests PRIVATE foobar)
target_link_libraries(foobar_tests PRIVATE boost-ext-ut-modules)
# target_link_libraries(foobar_tests PUBLIC cppcoro-modules)
target_link_libraries(foobar_tests PUBLIC eigen-modules)
cmake_minimum_required(VERSION 3.25)


add_executable(foobar_tests)
target_compile_features(foobar PUBLIC cxx_std_20)
target_sources(foobar_tests PUBLIC
    main.cxx
    test_foo.cxx
    test_bar.cxx
    test_cycle.cxx
)
target_link_libraries(foobar_tests PRIVATE foobar)
target_link_libraries(foobar_tests PRIVATE ut)
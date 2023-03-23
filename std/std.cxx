module;
#include <array>
#include <iostream>
#include <sstream>
#include <string_view>
#include <utility>
#include <vector>
#if __has_include(<unistd.h>) and __has_include(<sys/wait.h>)
#include <sys/wait.h>
#include <unistd.h>
#endif
#if defined(__cpp_exceptions)
#include <exception>
#endif

export module nstd;

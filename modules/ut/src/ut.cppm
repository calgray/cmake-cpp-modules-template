module;
#define __cpp_modules 1
#define BOOST_UT_IMPLEMENTATION 1

// Explicit includes due to missing std module exports
#include <algorithm>
#include <array>
#include <chrono>
#include <cstdint>
#include <functional>
#include <iostream>
#include <memory>
#include <optional>
#include <regex>
#include <sstream>
#include <stack>
#include <string_view>
#include <unordered_map>
#include <utility>
#include <variant>
#include <vector>
#include <regex>
#if __has_include(<unistd.h>) and __has_include(<sys/wait.h>)
#include <sys/wait.h>
#include <unistd.h>
#endif // __has_include(<unistd.h>) and __has_include(<sys/wait.h>)
#if defined(__cpp_exceptions)
#include <exception>
#endif // defined(__cpp_exceptions)

#if __has_include(<source_location>)
#include <source_location>
#endif // __has_include(<source_location>)

#include "boost/ut.hpp"

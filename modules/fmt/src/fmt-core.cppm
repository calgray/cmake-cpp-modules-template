module;
#include <fmt/core.h>

export module fmt.core;

export namespace fmt
{
    using fmt::format;
    using fmt::vformat;
    using fmt::format_to;
    using fmt::format_to_n;
    using fmt::formatted_size;
    using fmt::format_to_n_result;
    using fmt::print;
    using fmt::vprint;
    using fmt::basic_format_string;
    using fmt::format_string;
    using fmt::runtime;
    using fmt::arg;
    using fmt::make_format_args;
    using fmt::format_arg_store;
    using fmt::dynamic_format_arg_store;
    using fmt::basic_format_args;
    using fmt::format_args;
    using fmt::basic_format_arg;
    using fmt::basic_format_parse_context;
    using fmt::basic_format_context;
};

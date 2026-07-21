module;
#include <range/v3/algorithm.hpp>

export module range_v3:algorithm;

export namespace ranges
{
    using ranges::adjacent_find;
    using ranges::adjacent_remove_if;
    using ranges::count;
    using ranges::all_of;
    using ranges::any_of;
    using ranges::for_each;
    using ranges::none_of;

    using ranges::is_sorted;
}


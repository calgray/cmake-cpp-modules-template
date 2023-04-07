module;
#include <range/v3/range.hpp>

export module range_v3:range;

export namespace ranges
{
    using ranges::range;
    using ranges::borrowed_range;
    using ranges::output_range;
    using ranges::input_range;
    using ranges::forward_range;
    using ranges::bidirectional_range;
    using ranges::random_access_range;
    using ranges::contiguous_range;
    using ranges::common_range;
    using ranges::sized_range;
    using ranges::viewable_range;
    // using ranges::erasable_range;

    using ranges::semi_container;
    using ranges::container;
    using ranges::reservable;
    using ranges::reservable_with_assign;
    using ranges::random_access_reservable;
    using ranges::lvalue_container_like;

    using ranges::at_fn;
    using ranges::back_fn;
    using ranges::dangling;
    using ranges::front_fn;
    using ranges::index_fn;
    using ranges::range_cardinality;

    using ranges::begin;
    using ranges::end;
};

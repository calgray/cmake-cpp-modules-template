module;
#include <range/v3/view.hpp>

export module range_v3:views;

export namespace ranges
{
    using ranges::iota_view;
    using ranges::join_view;
    using ranges::drop_view;
    using ranges::view_facade;
    using ranges::operator==;
    using ranges::operator!=;
};

export namespace ranges::views
{
    using ranges::views::addressof;
    using ranges::views::all;
    using ranges::views::iota;
    using ranges::views::take;
};

module;

#include <concepts/concepts.hpp>

export module range_v3:concepts;

export namespace concepts
{
    inline namespace defs
    {
        using concepts::defs::is_true;
        using concepts::defs::type;
        using concepts::defs::satisfies;
        using concepts::defs::same_as;
        using concepts::defs::implicitly_convertible_to;
        using concepts::defs::explicitly_convertible_to;
        using concepts::defs::convertible_to;
        using concepts::defs::derived_from;
        using concepts::defs::common_reference_with;
        using concepts::defs::common_with;
        using concepts::defs::integral;
        using concepts::defs::signed_integral;
        using concepts::defs::unsigned_integral;
        using concepts::defs::assignable_from;
        using concepts::defs::swappable;
        using concepts::defs::swappable_with;

        using concepts::defs::equality_comparable;
        using concepts::defs::equality_comparable_with;
        using concepts::defs::totally_ordered;
        using concepts::defs::totally_ordered_with;

        using concepts::defs::destructible;
        using concepts::defs::constructible_from;
        using concepts::defs::default_constructible;
        using concepts::defs::move_constructible;
        using concepts::defs::copy_constructible;
        using concepts::defs::movable;
        using concepts::defs::copyable;
        using concepts::defs::semiregular;
        using concepts::defs::regular;
    }
}

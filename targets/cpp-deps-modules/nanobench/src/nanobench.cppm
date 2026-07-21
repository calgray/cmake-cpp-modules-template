module;

#define ANKERL_NANOBENCH_IMPLEMENT
#include <nanobench.h>

export module nanobench;

export namespace ankerl::nanobench
{
    using ::ankerl::nanobench::Bench;
    using ::ankerl::nanobench::Rng;
    using ::ankerl::nanobench::Result;
    using ::ankerl::nanobench::doNotOptimizeAway;
    using ::ankerl::nanobench::render;

    namespace templates
    {
        using ::ankerl::nanobench::templates::csv;
        using ::ankerl::nanobench::templates::htmlBoxplot;
        using ::ankerl::nanobench::templates::json;
        using ::ankerl::nanobench::templates::pyperf;
    }
}

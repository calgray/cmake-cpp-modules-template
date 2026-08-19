#if !defined(_MSC_VER)

import boost.ut;
import std;
import std.compat;
import nanobench;

namespace nanobench = ankerl::nanobench;
namespace ut = boost::ut;
using namespace boost::ut::literals;
using namespace std::chrono_literals;

template <typename Rng>
void bench_rng(ankerl::nanobench::Bench& bench, char const* name) {
    std::random_device dev;
    Rng rng(dev());

    bench.run(name, [&]() {
        auto r = std::uniform_int_distribution<uint64_t>{}(rng);
        nanobench::doNotOptimizeAway(r);
    });
}

ut::suite<"rng"> rng_suite = [] {
    "Random Number Generators Naive"_test = [] {
        nanobench::Bench b;
        b.title("Random Number Generators Naive")
            .unit("uint64_t")
            .warmup(0)
            .relative(true);
        b.performanceCounters(true);

        // first entry is the baseline
        bench_rng<std::default_random_engine>(b, "std::default_random_engine");
        bench_rng<std::mt19937>(b, "std::mt19937");
        bench_rng<std::mt19937_64>(b, "std::mt19937_64");
        bench_rng<std::ranlux24_base>(b, "std::ranlux24_base");
        bench_rng<std::ranlux48_base>(b, "std::ranlux48_base");
        bench_rng<std::ranlux24>(b, "std::ranlux24_base");
        bench_rng<std::ranlux48>(b, "std::ranlux48");
        bench_rng<std::knuth_b>(b, "std::knuth_b");
        // bench_rng<WyRng>(b, "WyRng");
        // bench_rng<NasamRng>(b, "NasamRng");
        // bench_rng<Sfc4>(b, "Sfc4");
        // bench_rng<RomuTrio>(b, "RomuTrio");
        // bench_rng<RomuDuo>(b, "RomuDuo");
        // bench_rng<RomuDuoJr>(b, "RomuDuoJr");
        // bench_rng<Orbit>(b, "Orbit");
        bench_rng<ankerl::nanobench::Rng>(b, "ankerl::nanobench::Rng");
    };

    "Random Number Generators"_test = [] {
        nanobench::Bench b;
        b.title("Random Number Generators")
            .unit("uint64_t")
            .warmup(100)
            .relative(true);
        b.performanceCounters(true);

        // first entry is the baseline
        bench_rng<std::default_random_engine>(b, "std::default_random_engine");
        bench_rng<std::mt19937>(b, "std::mt19937");
        bench_rng<std::mt19937_64>(b, "std::mt19937_64");
        bench_rng<std::ranlux24_base>(b, "std::ranlux24_base");
        bench_rng<std::ranlux48_base>(b, "std::ranlux48_base");
        bench_rng<std::ranlux24>(b, "std::ranlux24_base");
        bench_rng<std::ranlux48>(b, "std::ranlux48");
        bench_rng<std::knuth_b>(b, "std::knuth_b");
        // bench_rng<WyRng>(b, "WyRng");
        // bench_rng<NasamRng>(b, "NasamRng");
        // bench_rng<Sfc4>(b, "Sfc4");
        // bench_rng<RomuTrio>(b, "RomuTrio");
        // bench_rng<RomuDuo>(b, "RomuDuo");
        // bench_rng<RomuDuoJr>(b, "RomuDuoJr");
        // bench_rng<Orbit>(b, "Orbit");
        bench_rng<ankerl::nanobench::Rng>(b, "ankerl::nanobench::Rng");
    };
};

#endif // !defined(_MSC_VER)

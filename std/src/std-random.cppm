module;
#include <random>
export module clangstd:random;
export namespace std {
    using std::uniform_int_distribution;
    using std::random_device;
    using std::mt19937;
    using std::default_random_engine;
}

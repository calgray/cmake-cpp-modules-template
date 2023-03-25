module;
#include <tuple>
export module clangstd:tuple;
export namespace std {
    using std::tuple;
    using std::get;
    using std::tie;
    using std::make_tuple;
}

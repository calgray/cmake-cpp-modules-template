module;
#include <tuple>
export module stdcxx:tuple;
export namespace std {
    using std::tuple;
    using std::tuple_size;
    using std::get;
    using std::tie;
    using std::make_tuple;
    using std::apply;
    using std::make_from_tuple;
    using std::tuple_element;
    using std::tuple_size_v;
    using std::remove_reference_t;
}

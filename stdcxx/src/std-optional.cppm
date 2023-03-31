module;
#include <optional>
export module stdcxx:optional;
export namespace std {
    using std::optional;
    using std::make_optional;
    using std::nullopt;
};
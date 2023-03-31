module;
#include <variant>
export module stdcxx:variant;
export namespace std {
    using std::variant;
    using std::monostate;
    using std::holds_alternative;
};
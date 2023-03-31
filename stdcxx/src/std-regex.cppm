module;
#include <regex>
export module stdcxx:regex;
export namespace std {
    using std::regex;
    using std::regex_match;
    using std::basic_regex;
    using std::match_results;
};

export namespace std::regex_constants {
    using std::regex_constants::match_flag_type;
};

#include <vector>
#include <regex>

import boost.ut;
import std;

using namespace boost::ut;

suite<"headers"> headers_suite = [] {
    "vector"_test = [] {
        expect(std::vector<int>{0,1}.size() == 2l);
    };

    // "regex"_test = [] {
    //     // historically a problematic header
    //     const std::regex pattern = std::regex("");
    // };
};
export module cmake_cpp_modules_template.foobar.cycle:A;

import std;
import :fwd;

export class cycleA {
public:
    std::string name() const { return "cycleA"; }
    std::string concat_names(cycleB& b);
};

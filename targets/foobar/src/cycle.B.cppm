export module cmake_cpp_modules_template.foobar.cycle:B;

import std;
import :fwd;

export class cycleB {
public:
    std::string name() const { return "cycleB"; }
    std::string concat_names(cycleA& a);
};

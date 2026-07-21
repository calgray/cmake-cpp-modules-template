export module cmake_cpp_modules_template.foobar.cycle;

import std;

export import :fwd;
export import :A;
export import :B;

std::string cycleA::concat_names(cycleB& b)
{
    return name() + b.name();
}

std::string cycleB::concat_names(cycleA& a)
{
    return name() + a.name();
}

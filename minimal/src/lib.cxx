module;
#include <range/v3/all.hpp>

export module lib;
import stdcxx;

export void function()
{
    std::string s = "sdad";
    std::cout << ranges::views::iota(0,10) << "\n";
    std::cout << "hello world" << std::endl;
}

export module lib;
import stdcxx;
import range_v3;
import fmt.core;
import boost.ut;

export void function()
{
    std::stringstream ss;
    ss << "hello world";
    std::string s = ss.str();
    std::cout << s << std::endl;

    fmt::print("hello fmt");
}

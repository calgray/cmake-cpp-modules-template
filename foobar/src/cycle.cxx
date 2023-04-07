export module foobar.cycle;

// import stdcxx;
#ifndef STD_HEADER_UNITS
import stdcxx;
#else
import <iostream>;
#endif

export import :A;
export import :B;

void cycleA::f(cycleB& b)
{
    std::cout << b.name() << "\n";
}

void cycleB::f(cycleA& a)
{
    std::cout << a.name() << "\n";
}

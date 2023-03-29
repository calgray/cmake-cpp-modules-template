export module foobar.cycle:B;

#ifndef STD_HEADER_UNITS
import stdcxx;
#else
import <string>;
#endif

class cycleA;
export class cycleB {
public:
    std::string name() const { return "cycleB"; }
    void f(cycleA& a);
};

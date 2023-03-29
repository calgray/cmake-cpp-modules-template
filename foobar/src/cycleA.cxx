export module foobar.cycle:A;

#ifndef STD_HEADER_UNITS
import stdcxx;
#else
import <string>;
#endif

class cycleB;
export class cycleA {
public:
    std::string name() const { return "cycleA"; }
    void f(cycleB& b);
};
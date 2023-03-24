module;
#include <string>

export module foobar.cycle:B;

class cycleA;
export class cycleB {
public:
    std::string name() const { return "cycleB"; }
    void f(cycleA& a);
};

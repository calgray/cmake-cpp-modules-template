module;
#include <string>

export module foobar.cycle:A;

class cycleB;
export class cycleA {
public:
    std::string name() const { return "cycleA"; }
    void f(cycleB& b);
};
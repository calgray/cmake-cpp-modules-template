export module foobar.cycle:B;

import stdcxx;

class cycleA;
export class cycleB {
public:
    std::string name() const { return "cycleB"; }
    void f(cycleA& a);
};

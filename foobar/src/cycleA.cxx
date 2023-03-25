export module foobar.cycle:A;

import clangstd;

class cycleB;
export class cycleA {
public:
    std::string name() const { return "cycleA"; }
    void f(cycleB& b);
};
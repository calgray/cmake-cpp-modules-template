export module foobar.cycle:A;

// import stdcxx;
import <string>;


class cycleB;
export class cycleA {
public:
    std::string name() const { return "cycleA"; }
    void f(cycleB& b);
};
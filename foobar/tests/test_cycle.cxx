import boost.ut;
import foobar.cycle;

#ifndef STD_HEADER_UNITS
import stdcxx;
#else
import <array>;
import <iostream>;
import <vector>;
#endif

using namespace boost::ut;

suite cycleA_suite = [] {
    "cycleA_name"_test = [] {
        cycleA a;
        expect(a.name() == "cycleA");
    };
    "cycleA_f"_test = [] {
        cycleA a;
        cycleB b;
        a.f(b);
    };
};

suite cycleB_suite = [] {
    "cycleB_name"_test = [] {
        cycleB b;
        expect(b.name() == "cycleB");
    };
    "cycleB_f"_test = [] {
        cycleA a;
        cycleB b;
        b.f(a);
    };
};
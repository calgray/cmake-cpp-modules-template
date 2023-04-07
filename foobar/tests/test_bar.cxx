
import boost.ut;
import bar;

#ifndef STD_HEADER_UNITS
import stdcxx;
#else
import <array>;
import <iostream>;
import <vector>;
#endif

using namespace boost::ut;

suite bar_suite = [] {
    "simple"_test = [] {
        expect(1 == 1);
    };
    "name"_test = [] {
        bar b;
        expect(b.name() == "bar");
    };
    "print"_test = [] {
        bar b;
        b.print();
    };
};
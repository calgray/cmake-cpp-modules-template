import boost.ut;
import cmake_cpp_modules_template.foobar.cycle;
import std;

using namespace boost::ut;

suite<"cycleA"> cycleA_suite = [] {
    "name"_test = [] {
        cycleA a;
        expect(a.name() == "cycleA");
    };
    "concat_names"_test = [] {
        cycleA a;
        cycleB b;
        expect(a.concat_names(b) == "cycleAcycleB");
    };
};

suite<"cycleB"> cycleB_suite = [] {
    "name"_test = [] {
        cycleB b;
        expect(b.name() == "cycleB");
    };
    "concat_names"_test = [] {
        cycleA a;
        cycleB b;
        expect(b.concat_names(a) == "cycleBcycleA");
    };
};

import boost.ut;
import cmake_cpp_modules_template.foobar.bar;
import std;

using namespace boost::ut;

suite<"bar"> bar_suite = [] {
    "name"_test = [] {
        bar b;
        expect(b.name() == "bar");
    };
    "get"_test = [] {
        bar b;
        expect(b.get() == 1_i);
    };
};
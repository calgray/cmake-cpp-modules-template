import boost.ut;
import foo;

using namespace boost::ut;

suite foo_suite = [] {
    "simple"_test = [] {
        expect(1 == 1_i);
    };
    "name"_test = [] {
        foo f;
        expect(f.name() == "foo");
    };
    "print"_test = [] {
        foo f;
        f.print();
    };
};
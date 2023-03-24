import boost.ut;
import foo;

using namespace boost::ut;

suite foo_suite = [] {
    "simple"_test = [] {
        expect(1 == 1);
    };
    "name"_test = [] {
        foo f;
        expect(f.name() == "foo");
    };
};
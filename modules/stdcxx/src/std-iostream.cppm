module;
#include <iosfwd>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
export module stdcxx:iostream;
export namespace std {
    using std::cout;
    using std::cerr;
    using std::endl;
    using std::printf;
    using std::boolalpha;
    using std::noboolalpha;
    using std::setw;
    using std::flush;
    using std::istream;
    using std::ostream;
    using std::basic_ostream;
    using std::iostream;
    using std::ifstream;
    using std::streambuf;

    // using std::basic_stringstream;
    // using std::ios_base;
    using std::stringstream;
    using std::ostringstream;
    // using std::stringbuf;
    // using std::wstringbuf;
    // using std::basic_streambuf;
    // using std::basic_iostream;
    // using std::basic_ios;

    using std::operator<<;
    using std::operator>>;
};

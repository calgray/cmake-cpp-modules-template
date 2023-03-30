
// TODO: For some reason iostream is still needed
// to be explicitly imported/included here to
// avoid segmentation faults.
#if STD_HEADER_UNITS
import <iostream>;
#endif

import foo;
import bar;

int main(int argc, char** argv)
{
    foo f;
    f.print();
    bar b;
    b.print();
    return 0;
}

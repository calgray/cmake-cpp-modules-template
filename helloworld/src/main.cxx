
// TODO: For some reason iostream is still needed
// to be explicitly imported/included here to
// avoid segmentation faults.

// Maybe use an intermediate main module?
import <iostream>;

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

import boost.ut;

int main(int argc, const char** argv) {
    namespace ut = boost::ut;
    
    return ut::cfg<ut::override>.run({
        .report_errors = true,
        .argc = argc,
        .argv = argv,
    });
}


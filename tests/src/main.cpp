#include "phpx_test.h"

using namespace std;


int main(int argc, char **argv) {
    php::VM vm(argc, argv);

    ::testing::InitGoogleTest(&argc, argv);
    int retval = RUN_ALL_TESTS();
    return retval;
}

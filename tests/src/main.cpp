#include "phpx_test.h"

using namespace std;

int main(int argc, char **argv) {
    php::VM vm(argc, argv);

    ::testing::InitGoogleTest(&argc, argv);
    int retval = RUN_ALL_TESTS();
    return retval;
}

php::Array create_map() {
    php::Array v1;
    v1.set("c++", 1);
    v1.set("java", 2);
    v1.set("php", 3);
    v1.set("golang", 4);
    v1.set("node.js", 5);
    return v1;
}
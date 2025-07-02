#include "phpx_test.h"

using namespace std;

static string root_path;

static void init_root_path(const char *_exec_file) {
    char buf[PATH_MAX];
    string file;
    if (_exec_file[0] == '/') {
        file = _exec_file;
    } else {
        char *dir = getcwd(buf, sizeof(buf));
        file = string(dir) + "/" + _exec_file;
    }
    string relative_root_path = file.substr(0, file.rfind('/')) + "/../";
    char *_realpath = realpath(relative_root_path.c_str(), buf);
    if (_realpath == nullptr) {
        root_path = relative_root_path;
    } else {
        root_path = string(_realpath);
    }
}

const string &get_root_path() {
    return root_path;
}

string get_tests_dir() {
    return get_root_path() + "/tests";
}

string get_include_dir() {
    return get_root_path() + "/tests/include";
}

int main(int argc, char **argv) {
    php::VM vm(argc, argv);
    init_root_path(argv[0]);
    zend_first_try {
        ::testing::InitGoogleTest(&argc, argv);
    } zend_end_try();
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

php::Array create_list() {
    return {"php", "java", "go", "python", "c++"};
}
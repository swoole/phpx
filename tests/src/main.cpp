#include "phpx_test.h"

#include <cerrno>
#include <cstring>
#include <string>
#include <system_error>
#include <functional>
#include <iostream>
#include <type_traits>

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

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_void, 0, 0, IS_VOID, 0)
ZEND_END_ARG_INFO()

static int gtest_exit_status = 0;

static void php_main() {
    gtest_exit_status = RUN_ALL_TESTS();
}

static ZEND_FUNCTION(main) {
    php_main();
}

static void throw_exception(zend_object *ex) {
    zend_bailout();
}

static const zend_function_entry ext_functions[] = {ZEND_FE(main, arginfo_void) ZEND_FE_END};

int main(int argc, char **argv) {
    php_embed_init(argc, argv);
    zend_register_functions(nullptr, ext_functions, nullptr, 0);
    zend_throw_exception_hook = throw_exception;

    php::request_init();
    init_root_path(argv[0]);
    ::testing::InitGoogleTest(&argc, argv);

    zend_first_try {
        php::eval("main();");
    }
    zend_catch {
        EG(exit_status);
        if (EG(exception)) {
            zend_exception_error(EG(exception), E_ERROR);
            zend_clear_exception();
        }
    }
    zend_end_try();

    php::request_shutdown();
    php_embed_shutdown();

    return gtest_exit_status;
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

ChildResult run_in_child_capture_stdout(const std::function<int(void)> &func) {
    std::fflush(nullptr);
    std::cout.flush();
    std::cerr.flush();

    int pipefd[2];
    if (pipe(pipefd) == -1) {
        throw std::system_error(errno, std::generic_category(), "pipe");
    }

    pid_t pid = fork();
    if (pid == -1) {
        close(pipefd[0]);
        close(pipefd[1]);
        throw std::system_error(errno, std::generic_category(), "fork");
    }

    if (pid == 0) {
        // child
        if (dup2(pipefd[1], STDOUT_FILENO) == -1) {
            _exit(127);
        }
        if (dup2(pipefd[1], STDERR_FILENO) == -1) {
            _exit(127);
        }
        ::close(pipefd[0]);
        ::close(pipefd[1]);

        try {
            int r = func();
            std::fflush(nullptr);
            long code_long = 0;
            code_long = static_cast<long>(r);
            int code = static_cast<int>(code_long & 0xFF);
            _exit(code);
        } catch (...) {
            std::fflush(nullptr);
            _exit(1);
        }
    } else {
        // parent
        ::close(pipefd[1]);

        std::string collected;
        constexpr size_t BUF_SIZE = 4096;
        char buf[BUF_SIZE];

        while (true) {
            ssize_t n = ::read(pipefd[0], buf, sizeof(buf));
            if (n > 0) {
                collected.append(buf, buf + n);
            } else if (n == 0) {
                break;
            } else {  // n == -1
                if (errno == EINTR) continue;
                int saved_errno = errno;
                ::close(pipefd[0]);
                int status_dummy = 0;
                pid_t wdummy;
                do {
                    wdummy = waitpid(pid, &status_dummy, 0);
                } while (wdummy == -1 && errno == EINTR);
                throw std::system_error(saved_errno, std::generic_category(), "read from pipe");
            }
        }

        ::close(pipefd[0]);

        int status = 0;
        pid_t w;
        do {
            w = waitpid(pid, &status, 0);
        } while (w == -1 && errno == EINTR);

        if (w == -1) {
            throw std::system_error(errno, std::generic_category(), "waitpid");
        }

        ChildResult res;
        res.output = std::move(collected);
        if (WIFEXITED(status)) {
            res.exited = true;
            res.exit_code = WEXITSTATUS(status);
            res.term_signal = 0;
        } else if (WIFSIGNALED(status)) {
            res.exited = false;
            res.exit_code = -1;
            res.term_signal = WTERMSIG(status);
        } else {
            res.exited = false;
            res.exit_code = -1;
            res.term_signal = 0;
        }
        return res;
    }
}

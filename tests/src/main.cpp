#include "phpx_test.h"
#include "phpx_func.h"
#include "typephp_fiber_generator.h"

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

void try_call(const std::function<void(void)> &fn, const php::String &msg, bool print) {
    try {
        fn();
    } catch (zend_object *ex) {
        auto e = php::catchException();
        auto s = e.call("getMessage");
        if (print) {
            s.print();
        }
        bool expected = php::str_contains(s, msg).toBool();
        if (!expected) {
            fprintf(stderr, "ERROR: %s\n", s.toCString());
        }
        EXPECT_TRUE(expected);
    }
}

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_void, 0, 0, IS_VOID, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_mixed, 0, 0, IS_MIXED, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_hook_get, 0, 0, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_hook_set, 0, 1, IS_VOID, 0)
    ZEND_ARG_TYPE_INFO(0, value, IS_STRING, 0)
ZEND_END_ARG_INFO()

static zend_class_entry *gtest_hooked_ce = nullptr;
static zend_class_entry *gtest_hook_interface_ce = nullptr;

static ZEND_METHOD(PhpxGtestHooked, readHook) {
    zval rv;
    zval *value = zend_read_property(
        gtest_hooked_ce, Z_OBJ_P(ZEND_THIS), ZEND_STRL("stored"), false, &rv);
    RETURN_STR(zval_get_string(value));
}

static ZEND_METHOD(PhpxGtestHooked, writeHook) {
    zend_string *value;
    ZEND_PARSE_PARAMETERS_START(1, 1)
        Z_PARAM_STR(value)
    ZEND_PARSE_PARAMETERS_END();

    zend_update_property_str(
        gtest_hooked_ce, Z_OBJ_P(ZEND_THIS), ZEND_STRL("stored"), value);
}

static const zend_function_entry hooked_object_methods[] = {
    ZEND_ME(PhpxGtestHooked, readHook, arginfo_hook_get, ZEND_ACC_PUBLIC)
    ZEND_ME(PhpxGtestHooked, writeHook, arginfo_hook_set, ZEND_ACC_PUBLIC)
    ZEND_FE_END
};

static php::Array generator_payload(const php::Var &value,
                                    const php::Var &key = php::null,
                                    bool has_key = false) {
    if (has_key) {
        return php::Array(php::StdStrKeyMap{{"key", key}, {"value", value}, {"has_key", true}});
    }
    return php::Array(php::StdStrKeyMap{{"value", value}, {"has_key", false}});
}

static int gtest_exit_status = 0;

static void php_main() {
    gtest_exit_status = RUN_ALL_TESTS();
}

static ZEND_FUNCTION(main) {
    php_main();
}

static ZEND_FUNCTION(phpx_test_generator_sequence) {
    try {
        bool closed = false;
        php::Var sent = typephp_fiber_suspend(generator_payload(10), &closed);
        if (closed) {
            RETURN_NULL();
        }
        typephp_fiber_suspend(generator_payload(sent, 7, true), &closed);
        RETURN_LONG(42);
    } catch (zend_object *exception) {
        ZEND_ASSERT(EG(exception) == exception);
    }
}

static ZEND_FUNCTION(phpx_test_generator_yield_from_array) {
    try {
        php::Array values;
        values.set("first", "A");
        values.set(3, "B");
        bool closed = false;
        typephp_fiber_yield_from(values, &closed);
        RETURN_LONG(21);
    } catch (zend_object *exception) {
        ZEND_ASSERT(EG(exception) == exception);
    }
}

static ZEND_FUNCTION(phpx_test_generator_yield_from_generator) {
    try {
        php::Var iterator = php::eval("return (function () { yield 'nested' => 5; return 77; })();");
        bool closed = false;
        php::Var result = typephp_fiber_yield_from(iterator, &closed);
        ZVAL_COPY(return_value, result.const_ptr());
    } catch (zend_object *exception) {
        ZEND_ASSERT(EG(exception) == exception);
    }
}

static ZEND_FUNCTION(phpx_test_generator_yield_from_iterator_aggregate) {
    try {
        php::Var iterator = php::eval(R"PHP(
            return new class implements IteratorAggregate {
                public function getIterator(): Traversable {
                    return new ArrayIterator(['aggregate' => 12]);
                }
            };
        )PHP");
        bool closed = false;
        typephp_fiber_yield_from(iterator, &closed);
        RETURN_LONG(33);
    } catch (zend_object *exception) {
        ZEND_ASSERT(EG(exception) == exception);
    }
}

static ZEND_FUNCTION(phpx_test_generator_yield_from_send) {
    try {
        php::Var iterator = php::eval(R"PHP(
            return (function () {
                $sent = yield 'initial';
                yield $sent;
                return 99;
            })();
        )PHP");
        bool closed = false;
        php::Var result = typephp_fiber_yield_from(iterator, &closed);
        ZVAL_COPY(return_value, result.const_ptr());
    } catch (zend_object *exception) {
        ZEND_ASSERT(EG(exception) == exception);
    }
}

static const zend_function_entry ext_functions[] = {
    ZEND_FE(main, arginfo_void)
    ZEND_FE(phpx_test_generator_sequence, arginfo_mixed)
    ZEND_FE(phpx_test_generator_yield_from_array, arginfo_mixed)
    ZEND_FE(phpx_test_generator_yield_from_generator, arginfo_mixed)
    ZEND_FE(phpx_test_generator_yield_from_iterator_aggregate, arginfo_mixed)
    ZEND_FE(phpx_test_generator_yield_from_send, arginfo_mixed)
    ZEND_FE_END
};

static PHP_MINIT_FUNCTION(phpx_gtest_runtime) {
    typephp_register_fiber_generator_class();

    zend_class_entry hooked_ce;
    INIT_CLASS_ENTRY(hooked_ce, "PhpxGtestHooked", hooked_object_methods);
    gtest_hooked_ce = zend_register_internal_class(&hooked_ce);
    zend_declare_property_string(
        gtest_hooked_ce, ZEND_STRL("stored"), "initial", ZEND_ACC_PRIVATE);

    zval hooked_default;
    ZVAL_EMPTY_STRING(&hooked_default);
    zend_string *hooked_name = zend_string_init(ZEND_STRL("value"), true);
    zend_property_info *hooked_info = zend_declare_typed_property(
        gtest_hooked_ce,
        hooked_name,
        &hooked_default,
        ZEND_ACC_PUBLIC,
        nullptr,
        ZEND_TYPE_INIT_CODE(IS_STRING, false, 0));
    zend_string_release(hooked_name);
    php::registerPropertyHooks(gtest_hooked_ce, hooked_info, "readhook", "writehook");

    zend_class_entry hook_interface_ce;
    INIT_CLASS_ENTRY(hook_interface_ce, "PhpxGtestHookInterface", nullptr);
    gtest_hook_interface_ce = zend_register_internal_interface(&hook_interface_ce);
    zval interface_default;
    ZVAL_UNDEF(&interface_default);
    zend_string *interface_name = zend_string_init(ZEND_STRL("contractValue"), true);
    zend_property_info *interface_info = zend_declare_typed_property(
        gtest_hook_interface_ce,
        interface_name,
        &interface_default,
        ZEND_ACC_PUBLIC | ZEND_ACC_ABSTRACT | ZEND_ACC_VIRTUAL,
        nullptr,
        ZEND_TYPE_INIT_CODE(IS_STRING, false, 0));
    zend_string_release(interface_name);
    php::registerAbstractPropertyHooks(gtest_hook_interface_ce, interface_info, true, true);
    return SUCCESS;
}

static PHP_MSHUTDOWN_FUNCTION(phpx_gtest_runtime) {
    typephp_unregister_fiber_generator_class();
    gtest_hooked_ce = nullptr;
    gtest_hook_interface_ce = nullptr;
    return SUCCESS;
}

static zend_module_entry phpx_gtest_module = {
    STANDARD_MODULE_HEADER,
    "phpx_gtest_runtime",
    ext_functions,
    PHP_MINIT(phpx_gtest_runtime),
    PHP_MSHUTDOWN(phpx_gtest_runtime),
    nullptr,
    nullptr,
    nullptr,
    "test",
    STANDARD_MODULE_PROPERTIES,
};

static zend_module_entry *startup_gtest_module() {
    auto *module = zend_register_module_ex(&phpx_gtest_module, MODULE_PERSISTENT);
    if (module == nullptr || zend_startup_module_ex(module) == FAILURE) {
        return nullptr;
    }
    return module;
}

static void shutdown_gtest_module(zend_module_entry *module) {
    if (module == nullptr) {
        return;
    }
    module->module_shutdown_func(module->type, module->module_number);
    zend_hash_str_del(&module_registry, module->name, strlen(module->name));
}

int main(int argc, char **argv) {
    php_embed_init(argc, argv);
    auto *gtest_module = startup_gtest_module();
    if (gtest_module == nullptr) {
        php_embed_shutdown();
        return 255;
    }

    php::request_init();
    init_root_path(argv[0]);
    ::testing::InitGoogleTest(&argc, argv);

    zend_first_try {
        try {
            php::eval("main();");
        } catch (zend_object *e) {
            gtest_exit_status = EG(exit_status);
            CG(unclean_shutdown) = 1;
            zend_exception_error(e, E_ERROR);
        }
    }
    zend_end_try();

    php::request_shutdown();
    shutdown_gtest_module(gtest_module);
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

#include "phpx.h"
#include "phpx_literal_string.h"
#include "phpx_class.h"

namespace php {
Variant pcntl_fork() {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[994]);
    }
    return call(fn, {});
}
Variant pcntl_waitpid(const Variant &process_id,
                      const Reference &status,
                      const Variant &flags,
                      const Reference &resource_usage) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[995]);
    }
    return call(fn, {process_id, &status, flags, &resource_usage});
}
Variant pcntl_waitid(const Variant &idtype, const Variant &id, const Reference &info, const Variant &flags) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[996]);
    }
    return call(fn, {idtype, id, &info, flags});
}
Variant pcntl_wait(const Reference &status, const Variant &flags, const Reference &resource_usage) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[997]);
    }
    return call(fn, {&status, flags, &resource_usage});
}
Variant pcntl_signal(const Variant &signal, const Variant &handler, const Variant &restart_syscalls) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[998]);
    }
    return call(fn, {signal, handler, restart_syscalls});
}
Variant pcntl_signal_get_handler(const Variant &signal) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[999]);
    }
    return call(fn, {signal});
}
Variant pcntl_signal_dispatch() {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[1000]);
    }
    return call(fn, {});
}
Variant pcntl_sigprocmask(const Variant &mode, const Variant &signals, const Reference &old_signals) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[1001]);
    }
    return call(fn, {mode, signals, &old_signals});
}
Variant pcntl_sigwaitinfo(const Variant &signals, const Reference &info) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[1002]);
    }
    return call(fn, {signals, &info});
}
Variant pcntl_sigtimedwait(const Variant &signals,
                           const Reference &info,
                           const Variant &seconds,
                           const Variant &nanoseconds) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[1003]);
    }
    return call(fn, {signals, &info, seconds, nanoseconds});
}
Variant pcntl_wifexited(const Variant &status) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[1004]);
    }
    return call(fn, {status});
}
Variant pcntl_wifstopped(const Variant &status) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[1005]);
    }
    return call(fn, {status});
}
Variant pcntl_wifcontinued(const Variant &status) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[1006]);
    }
    return call(fn, {status});
}
Variant pcntl_wifsignaled(const Variant &status) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[1007]);
    }
    return call(fn, {status});
}
Variant pcntl_wexitstatus(const Variant &status) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[1008]);
    }
    return call(fn, {status});
}
Variant pcntl_wtermsig(const Variant &status) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[1009]);
    }
    return call(fn, {status});
}
Variant pcntl_wstopsig(const Variant &status) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[1010]);
    }
    return call(fn, {status});
}
Variant pcntl_exec(const Variant &path, const Variant &args, const Variant &env_vars) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[1011]);
    }
    return call(fn, {path, args, env_vars});
}
Variant pcntl_alarm(const Variant &seconds) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[1012]);
    }
    return call(fn, {seconds});
}
Variant pcntl_get_last_error() {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[1013]);
    }
    return call(fn, {});
}
Variant pcntl_errno() {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[1014]);
    }
    return call(fn, {});
}
Variant pcntl_getpriority(const Variant &process_id, const Variant &mode) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[1015]);
    }
    return call(fn, {process_id, mode});
}
Variant pcntl_setpriority(const Variant &priority, const Variant &process_id, const Variant &mode) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[1016]);
    }
    return call(fn, {priority, process_id, mode});
}
Variant pcntl_strerror(const Variant &error_code) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[1017]);
    }
    return call(fn, {error_code});
}
Variant pcntl_async_signals(const Variant &enable) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[1018]);
    }
    return call(fn, {enable});
}
Variant pcntl_unshare(const Variant &flags) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[1019]);
    }
    return call(fn, {flags});
}
Variant pcntl_getcpuaffinity(const Variant &process_id) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[1020]);
    }
    return call(fn, {process_id});
}
Variant pcntl_setcpuaffinity(const Variant &process_id, const Variant &cpu_ids) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[1021]);
    }
    return call(fn, {process_id, cpu_ids});
}
Variant pcntl_getcpu() {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[1022]);
    }
    return call(fn, {});
}
}  // namespace php

#include "phpx.h"
#include "phpx_literal_string.h"
#include "phpx_class.h"

namespace php {
Variant pcntl_fork() {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[814]);
    }
    return call(fn, {});
}
Variant pcntl_waitpid(const Variant &process_id,
                      const Reference &status,
                      const Variant &flags,
                      const Reference &resource_usage) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[815]);
    }
    return call(fn, {process_id, &status, flags, &resource_usage});
}
Variant pcntl_waitid(const Variant &idtype, const Variant &id, const Reference &info, const Variant &flags) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[816]);
    }
    return call(fn, {idtype, id, &info, flags});
}
Variant pcntl_wait(const Reference &status, const Variant &flags, const Reference &resource_usage) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[817]);
    }
    return call(fn, {&status, flags, &resource_usage});
}
Variant pcntl_signal(const Variant &signal, const Variant &handler, const Variant &restart_syscalls) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[818]);
    }
    return call(fn, {signal, handler, restart_syscalls});
}
Variant pcntl_signal_get_handler(const Variant &signal) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[819]);
    }
    return call(fn, {signal});
}
Variant pcntl_signal_dispatch() {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[820]);
    }
    return call(fn, {});
}
Variant pcntl_sigprocmask(const Variant &mode, const Variant &signals, const Reference &old_signals) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[821]);
    }
    return call(fn, {mode, signals, &old_signals});
}
Variant pcntl_sigwaitinfo(const Variant &signals, const Reference &info) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[822]);
    }
    return call(fn, {signals, &info});
}
Variant pcntl_sigtimedwait(const Variant &signals,
                           const Reference &info,
                           const Variant &seconds,
                           const Variant &nanoseconds) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[823]);
    }
    return call(fn, {signals, &info, seconds, nanoseconds});
}
Variant pcntl_wifexited(const Variant &status) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[824]);
    }
    return call(fn, {status});
}
Variant pcntl_wifstopped(const Variant &status) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[825]);
    }
    return call(fn, {status});
}
Variant pcntl_wifcontinued(const Variant &status) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[826]);
    }
    return call(fn, {status});
}
Variant pcntl_wifsignaled(const Variant &status) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[827]);
    }
    return call(fn, {status});
}
Variant pcntl_wexitstatus(const Variant &status) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[828]);
    }
    return call(fn, {status});
}
Variant pcntl_wtermsig(const Variant &status) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[829]);
    }
    return call(fn, {status});
}
Variant pcntl_wstopsig(const Variant &status) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[830]);
    }
    return call(fn, {status});
}
Variant pcntl_exec(const Variant &path, const Variant &args, const Variant &env_vars) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[831]);
    }
    return call(fn, {path, args, env_vars});
}
Variant pcntl_alarm(const Variant &seconds) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[832]);
    }
    return call(fn, {seconds});
}
Variant pcntl_get_last_error() {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[833]);
    }
    return call(fn, {});
}
Variant pcntl_errno() {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[834]);
    }
    return call(fn, {});
}
Variant pcntl_getpriority(const Variant &process_id, const Variant &mode) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[835]);
    }
    return call(fn, {process_id, mode});
}
Variant pcntl_setpriority(const Variant &priority, const Variant &process_id, const Variant &mode) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[836]);
    }
    return call(fn, {priority, process_id, mode});
}
Variant pcntl_strerror(const Variant &error_code) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[837]);
    }
    return call(fn, {error_code});
}
Variant pcntl_async_signals(const Variant &enable) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[838]);
    }
    return call(fn, {enable});
}
Variant pcntl_unshare(const Variant &flags) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[839]);
    }
    return call(fn, {flags});
}
Variant pcntl_getcpuaffinity(const Variant &process_id) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[840]);
    }
    return call(fn, {process_id});
}
Variant pcntl_setcpuaffinity(const Variant &process_id, const Variant &cpu_ids) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[841]);
    }
    return call(fn, {process_id, cpu_ids});
}
Variant pcntl_getcpu() {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[842]);
    }
    return call(fn, {});
}
}  // namespace php

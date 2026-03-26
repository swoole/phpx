#include "phpx.h"
#include "phpx_literal_string.h"

namespace php {
Variant pcntl_fork() {
    return call(LITERAL_STRING[777], {});
}
Variant pcntl_waitpid(const Variant &process_id,
                      const Reference &status,
                      const Variant &flags,
                      const Reference &resource_usage) {
    return call(LITERAL_STRING[778], {process_id, &status, flags, &resource_usage});
}
Variant pcntl_waitid(const Variant &idtype, const Variant &id, const Reference &info, const Variant &flags) {
    return call(LITERAL_STRING[779], {idtype, id, &info, flags});
}
Variant pcntl_wait(const Reference &status, const Variant &flags, const Reference &resource_usage) {
    return call(LITERAL_STRING[780], {&status, flags, &resource_usage});
}
Variant pcntl_signal(const Variant &signal, const Variant &handler, const Variant &restart_syscalls) {
    return call(LITERAL_STRING[781], {signal, handler, restart_syscalls});
}
Variant pcntl_signal_get_handler(const Variant &signal) {
    return call(LITERAL_STRING[782], {signal});
}
Variant pcntl_signal_dispatch() {
    return call(LITERAL_STRING[783], {});
}
Variant pcntl_sigprocmask(const Variant &mode, const Variant &signals, const Reference &old_signals) {
    return call(LITERAL_STRING[784], {mode, signals, &old_signals});
}
Variant pcntl_sigwaitinfo(const Variant &signals, const Reference &info) {
    return call(LITERAL_STRING[785], {signals, &info});
}
Variant pcntl_sigtimedwait(const Variant &signals,
                           const Reference &info,
                           const Variant &seconds,
                           const Variant &nanoseconds) {
    return call(LITERAL_STRING[786], {signals, &info, seconds, nanoseconds});
}
Variant pcntl_wifexited(const Variant &status) {
    return call(LITERAL_STRING[787], {status});
}
Variant pcntl_wifstopped(const Variant &status) {
    return call(LITERAL_STRING[788], {status});
}
Variant pcntl_wifcontinued(const Variant &status) {
    return call(LITERAL_STRING[789], {status});
}
Variant pcntl_wifsignaled(const Variant &status) {
    return call(LITERAL_STRING[790], {status});
}
Variant pcntl_wexitstatus(const Variant &status) {
    return call(LITERAL_STRING[791], {status});
}
Variant pcntl_wtermsig(const Variant &status) {
    return call(LITERAL_STRING[792], {status});
}
Variant pcntl_wstopsig(const Variant &status) {
    return call(LITERAL_STRING[793], {status});
}
Variant pcntl_exec(const Variant &path, const Variant &args, const Variant &env_vars) {
    return call(LITERAL_STRING[794], {path, args, env_vars});
}
Variant pcntl_alarm(const Variant &seconds) {
    return call(LITERAL_STRING[795], {seconds});
}
Variant pcntl_get_last_error() {
    return call(LITERAL_STRING[796], {});
}
Variant pcntl_errno() {
    return call(LITERAL_STRING[797], {});
}
Variant pcntl_getpriority(const Variant &process_id, const Variant &mode) {
    return call(LITERAL_STRING[798], {process_id, mode});
}
Variant pcntl_setpriority(const Variant &priority, const Variant &process_id, const Variant &mode) {
    return call(LITERAL_STRING[799], {priority, process_id, mode});
}
Variant pcntl_strerror(const Variant &error_code) {
    return call(LITERAL_STRING[800], {error_code});
}
Variant pcntl_async_signals(const Variant &enable) {
    return call(LITERAL_STRING[801], {enable});
}
Variant pcntl_unshare(const Variant &flags) {
    return call(LITERAL_STRING[802], {flags});
}
Variant pcntl_getcpuaffinity(const Variant &process_id) {
    return call(LITERAL_STRING[803], {process_id});
}
Variant pcntl_setcpuaffinity(const Variant &process_id, const Variant &cpu_ids) {
    return call(LITERAL_STRING[804], {process_id, cpu_ids});
}
Variant pcntl_getcpu() {
    return call(LITERAL_STRING[805], {});
}
}  // namespace php

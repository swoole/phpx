#include "phpx.h"

namespace php {
Variant pcntl_fork() {
    return call("pcntl_fork", {});
}
Variant pcntl_waitpid(const Variant &process_id, const Reference &status, const Variant &flags, const Reference &resource_usage) {
    return call("pcntl_waitpid", {process_id, &status, flags, &resource_usage});
}
Variant pcntl_waitid(const Variant &idtype, const Variant &id, const Reference &info, const Variant &flags) {
    return call("pcntl_waitid", {idtype, id, &info, flags});
}
Variant pcntl_wait(const Reference &status, const Variant &flags, const Reference &resource_usage) {
    return call("pcntl_wait", {&status, flags, &resource_usage});
}
Variant pcntl_signal(const Variant &signal, const Variant &handler, const Variant &restart_syscalls) {
    return call("pcntl_signal", {signal, handler, restart_syscalls});
}
Variant pcntl_signal_get_handler(const Variant &signal) {
    return call("pcntl_signal_get_handler", {signal});
}
Variant pcntl_signal_dispatch() {
    return call("pcntl_signal_dispatch", {});
}
Variant pcntl_sigprocmask(const Variant &mode, const Variant &signals, const Reference &old_signals) {
    return call("pcntl_sigprocmask", {mode, signals, &old_signals});
}
Variant pcntl_sigwaitinfo(const Variant &signals, const Reference &info) {
    return call("pcntl_sigwaitinfo", {signals, &info});
}
Variant pcntl_sigtimedwait(const Variant &signals, const Reference &info, const Variant &seconds, const Variant &nanoseconds) {
    return call("pcntl_sigtimedwait", {signals, &info, seconds, nanoseconds});
}
Variant pcntl_wifexited(const Variant &status) {
    return call("pcntl_wifexited", {status});
}
Variant pcntl_wifstopped(const Variant &status) {
    return call("pcntl_wifstopped", {status});
}
Variant pcntl_wifcontinued(const Variant &status) {
    return call("pcntl_wifcontinued", {status});
}
Variant pcntl_wifsignaled(const Variant &status) {
    return call("pcntl_wifsignaled", {status});
}
Variant pcntl_wexitstatus(const Variant &status) {
    return call("pcntl_wexitstatus", {status});
}
Variant pcntl_wtermsig(const Variant &status) {
    return call("pcntl_wtermsig", {status});
}
Variant pcntl_wstopsig(const Variant &status) {
    return call("pcntl_wstopsig", {status});
}
Variant pcntl_exec(const Variant &path, const Variant &args, const Variant &env_vars) {
    return call("pcntl_exec", {path, args, env_vars});
}
Variant pcntl_alarm(const Variant &seconds) {
    return call("pcntl_alarm", {seconds});
}
Variant pcntl_get_last_error() {
    return call("pcntl_get_last_error", {});
}
Variant pcntl_errno() {
    return call("pcntl_errno", {});
}
Variant pcntl_getpriority(const Variant &process_id, const Variant &mode) {
    return call("pcntl_getpriority", {process_id, mode});
}
Variant pcntl_setpriority(const Variant &priority, const Variant &process_id, const Variant &mode) {
    return call("pcntl_setpriority", {priority, process_id, mode});
}
Variant pcntl_strerror(const Variant &error_code) {
    return call("pcntl_strerror", {error_code});
}
Variant pcntl_async_signals(const Variant &enable) {
    return call("pcntl_async_signals", {enable});
}
Variant pcntl_unshare(const Variant &flags) {
    return call("pcntl_unshare", {flags});
}
Variant pcntl_getcpuaffinity(const Variant &process_id) {
    return call("pcntl_getcpuaffinity", {process_id});
}
Variant pcntl_setcpuaffinity(const Variant &process_id, const Variant &cpu_ids) {
    return call("pcntl_setcpuaffinity", {process_id, cpu_ids});
}
Variant pcntl_getcpu() {
    return call("pcntl_getcpu", {});
}
}

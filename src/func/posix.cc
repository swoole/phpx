#include "phpx.h"

namespace php {
Variant posix_kill(const Variant &process_id, const Variant &signal) {
    return call("posix_kill", {process_id, signal});
}
Variant posix_getpid() {
    return call("posix_getpid", {});
}
Variant posix_getppid() {
    return call("posix_getppid", {});
}
Variant posix_getuid() {
    return call("posix_getuid", {});
}
Variant posix_setuid(const Variant &user_id) {
    return call("posix_setuid", {user_id});
}
Variant posix_geteuid() {
    return call("posix_geteuid", {});
}
Variant posix_seteuid(const Variant &user_id) {
    return call("posix_seteuid", {user_id});
}
Variant posix_getgid() {
    return call("posix_getgid", {});
}
Variant posix_setgid(const Variant &group_id) {
    return call("posix_setgid", {group_id});
}
Variant posix_getegid() {
    return call("posix_getegid", {});
}
Variant posix_setegid(const Variant &group_id) {
    return call("posix_setegid", {group_id});
}
Variant posix_getgroups() {
    return call("posix_getgroups", {});
}
Variant posix_getlogin() {
    return call("posix_getlogin", {});
}
Variant posix_getpgrp() {
    return call("posix_getpgrp", {});
}
Variant posix_setsid() {
    return call("posix_setsid", {});
}
Variant posix_setpgid(const Variant &process_id, const Variant &process_group_id) {
    return call("posix_setpgid", {process_id, process_group_id});
}
Variant posix_getpgid(const Variant &process_id) {
    return call("posix_getpgid", {process_id});
}
Variant posix_getsid(const Variant &process_id) {
    return call("posix_getsid", {process_id});
}
Variant posix_uname() {
    return call("posix_uname", {});
}
Variant posix_times() {
    return call("posix_times", {});
}
Variant posix_ctermid() {
    return call("posix_ctermid", {});
}
Variant posix_ttyname(const Variant &file_descriptor) {
    return call("posix_ttyname", {file_descriptor});
}
Variant posix_isatty(const Variant &file_descriptor) {
    return call("posix_isatty", {file_descriptor});
}
Variant posix_getcwd() {
    return call("posix_getcwd", {});
}
Variant posix_mkfifo(const Variant &filename, const Variant &permissions) {
    return call("posix_mkfifo", {filename, permissions});
}
Variant posix_mknod(const Variant &filename, const Variant &flags, const Variant &major, const Variant &minor) {
    return call("posix_mknod", {filename, flags, major, minor});
}
Variant posix_access(const Variant &filename, const Variant &flags) {
    return call("posix_access", {filename, flags});
}
Variant posix_eaccess(const Variant &filename, const Variant &flags) {
    return call("posix_eaccess", {filename, flags});
}
Variant posix_getgrnam(const Variant &name) {
    return call("posix_getgrnam", {name});
}
Variant posix_getgrgid(const Variant &group_id) {
    return call("posix_getgrgid", {group_id});
}
Variant posix_getpwnam(const Variant &username) {
    return call("posix_getpwnam", {username});
}
Variant posix_getpwuid(const Variant &user_id) {
    return call("posix_getpwuid", {user_id});
}
Variant posix_getrlimit(const Variant &resource) {
    return call("posix_getrlimit", {resource});
}
Variant posix_setrlimit(const Variant &resource, const Variant &soft_limit, const Variant &hard_limit) {
    return call("posix_setrlimit", {resource, soft_limit, hard_limit});
}
Variant posix_get_last_error() {
    return call("posix_get_last_error", {});
}
Variant posix_errno() {
    return call("posix_errno", {});
}
Variant posix_strerror(const Variant &error_code) {
    return call("posix_strerror", {error_code});
}
Variant posix_initgroups(const Variant &username, const Variant &group_id) {
    return call("posix_initgroups", {username, group_id});
}
Variant posix_sysconf(const Variant &conf_id) {
    return call("posix_sysconf", {conf_id});
}
Variant posix_pathconf(const Variant &path, const Variant &name) {
    return call("posix_pathconf", {path, name});
}
Variant posix_fpathconf(const Variant &file_descriptor, const Variant &name) {
    return call("posix_fpathconf", {file_descriptor, name});
}
}

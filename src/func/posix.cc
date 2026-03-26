#include "phpx.h"
#include "phpx_literal_string.h"

namespace php {
Variant posix_kill(const Variant &process_id, const Variant &signal) {
    return call(LITERAL_STRING[969], {process_id, signal});
}
Variant posix_getpid() {
    return call(LITERAL_STRING[970], {});
}
Variant posix_getppid() {
    return call(LITERAL_STRING[971], {});
}
Variant posix_getuid() {
    return call(LITERAL_STRING[972], {});
}
Variant posix_setuid(const Variant &user_id) {
    return call(LITERAL_STRING[973], {user_id});
}
Variant posix_geteuid() {
    return call(LITERAL_STRING[974], {});
}
Variant posix_seteuid(const Variant &user_id) {
    return call(LITERAL_STRING[975], {user_id});
}
Variant posix_getgid() {
    return call(LITERAL_STRING[976], {});
}
Variant posix_setgid(const Variant &group_id) {
    return call(LITERAL_STRING[977], {group_id});
}
Variant posix_getegid() {
    return call(LITERAL_STRING[978], {});
}
Variant posix_setegid(const Variant &group_id) {
    return call(LITERAL_STRING[979], {group_id});
}
Variant posix_getgroups() {
    return call(LITERAL_STRING[980], {});
}
Variant posix_getlogin() {
    return call(LITERAL_STRING[981], {});
}
Variant posix_getpgrp() {
    return call(LITERAL_STRING[982], {});
}
Variant posix_setsid() {
    return call(LITERAL_STRING[983], {});
}
Variant posix_setpgid(const Variant &process_id, const Variant &process_group_id) {
    return call(LITERAL_STRING[984], {process_id, process_group_id});
}
Variant posix_getpgid(const Variant &process_id) {
    return call(LITERAL_STRING[985], {process_id});
}
Variant posix_getsid(const Variant &process_id) {
    return call(LITERAL_STRING[986], {process_id});
}
Variant posix_uname() {
    return call(LITERAL_STRING[987], {});
}
Variant posix_times() {
    return call(LITERAL_STRING[988], {});
}
Variant posix_ctermid() {
    return call(LITERAL_STRING[989], {});
}
Variant posix_ttyname(const Variant &file_descriptor) {
    return call(LITERAL_STRING[990], {file_descriptor});
}
Variant posix_isatty(const Variant &file_descriptor) {
    return call(LITERAL_STRING[991], {file_descriptor});
}
Variant posix_getcwd() {
    return call(LITERAL_STRING[992], {});
}
Variant posix_mkfifo(const Variant &filename, const Variant &permissions) {
    return call(LITERAL_STRING[993], {filename, permissions});
}
Variant posix_mknod(const Variant &filename, const Variant &flags, const Variant &major, const Variant &minor) {
    return call(LITERAL_STRING[994], {filename, flags, major, minor});
}
Variant posix_access(const Variant &filename, const Variant &flags) {
    return call(LITERAL_STRING[995], {filename, flags});
}
Variant posix_eaccess(const Variant &filename, const Variant &flags) {
    return call(LITERAL_STRING[996], {filename, flags});
}
Variant posix_getgrnam(const Variant &name) {
    return call(LITERAL_STRING[997], {name});
}
Variant posix_getgrgid(const Variant &group_id) {
    return call(LITERAL_STRING[998], {group_id});
}
Variant posix_getpwnam(const Variant &username) {
    return call(LITERAL_STRING[999], {username});
}
Variant posix_getpwuid(const Variant &user_id) {
    return call(LITERAL_STRING[1000], {user_id});
}
Variant posix_getrlimit(const Variant &resource) {
    return call(LITERAL_STRING[1001], {resource});
}
Variant posix_setrlimit(const Variant &resource, const Variant &soft_limit, const Variant &hard_limit) {
    return call(LITERAL_STRING[1002], {resource, soft_limit, hard_limit});
}
Variant posix_get_last_error() {
    return call(LITERAL_STRING[1003], {});
}
Variant posix_errno() {
    return call(LITERAL_STRING[1004], {});
}
Variant posix_strerror(const Variant &error_code) {
    return call(LITERAL_STRING[1005], {error_code});
}
Variant posix_initgroups(const Variant &username, const Variant &group_id) {
    return call(LITERAL_STRING[1006], {username, group_id});
}
Variant posix_sysconf(const Variant &conf_id) {
    return call(LITERAL_STRING[1007], {conf_id});
}
Variant posix_pathconf(const Variant &path, const Variant &name) {
    return call(LITERAL_STRING[1008], {path, name});
}
Variant posix_fpathconf(const Variant &file_descriptor, const Variant &name) {
    return call(LITERAL_STRING[1009], {file_descriptor, name});
}
}  // namespace php

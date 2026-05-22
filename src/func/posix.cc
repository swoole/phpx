#include "phpx.h"
#include "phpx_literal_string.h"
#include "phpx_class.h"

namespace php {
Variant posix_kill(const Variant &process_id, const Variant &signal) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[1195]);
    }
    return call(fn, {process_id, signal});
}
Variant posix_getpid() {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[1196]);
    }
    return call(fn, {});
}
Variant posix_getppid() {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[1197]);
    }
    return call(fn, {});
}
Variant posix_getuid() {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[1198]);
    }
    return call(fn, {});
}
Variant posix_setuid(const Variant &user_id) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[1199]);
    }
    return call(fn, {user_id});
}
Variant posix_geteuid() {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[1200]);
    }
    return call(fn, {});
}
Variant posix_seteuid(const Variant &user_id) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[1201]);
    }
    return call(fn, {user_id});
}
Variant posix_getgid() {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[1202]);
    }
    return call(fn, {});
}
Variant posix_setgid(const Variant &group_id) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[1203]);
    }
    return call(fn, {group_id});
}
Variant posix_getegid() {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[1204]);
    }
    return call(fn, {});
}
Variant posix_setegid(const Variant &group_id) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[1205]);
    }
    return call(fn, {group_id});
}
Variant posix_getgroups() {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[1206]);
    }
    return call(fn, {});
}
Variant posix_getlogin() {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[1207]);
    }
    return call(fn, {});
}
Variant posix_getpgrp() {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[1208]);
    }
    return call(fn, {});
}
Variant posix_setsid() {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[1209]);
    }
    return call(fn, {});
}
Variant posix_setpgid(const Variant &process_id, const Variant &process_group_id) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[1210]);
    }
    return call(fn, {process_id, process_group_id});
}
Variant posix_getpgid(const Variant &process_id) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[1211]);
    }
    return call(fn, {process_id});
}
Variant posix_getsid(const Variant &process_id) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[1212]);
    }
    return call(fn, {process_id});
}
Variant posix_uname() {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[1213]);
    }
    return call(fn, {});
}
Variant posix_times() {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[1214]);
    }
    return call(fn, {});
}
Variant posix_ctermid() {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[1215]);
    }
    return call(fn, {});
}
Variant posix_ttyname(const Variant &file_descriptor) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[1216]);
    }
    return call(fn, {file_descriptor});
}
Variant posix_isatty(const Variant &file_descriptor) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[1217]);
    }
    return call(fn, {file_descriptor});
}
Variant posix_getcwd() {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[1218]);
    }
    return call(fn, {});
}
Variant posix_mkfifo(const Variant &filename, const Variant &permissions) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[1219]);
    }
    return call(fn, {filename, permissions});
}
Variant posix_mknod(const Variant &filename, const Variant &flags, const Variant &major, const Variant &minor) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[1220]);
    }
    return call(fn, {filename, flags, major, minor});
}
Variant posix_access(const Variant &filename, const Variant &flags) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[1221]);
    }
    return call(fn, {filename, flags});
}
Variant posix_eaccess(const Variant &filename, const Variant &flags) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[1222]);
    }
    return call(fn, {filename, flags});
}
Variant posix_getgrnam(const Variant &name) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[1223]);
    }
    return call(fn, {name});
}
Variant posix_getgrgid(const Variant &group_id) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[1224]);
    }
    return call(fn, {group_id});
}
Variant posix_getpwnam(const Variant &username) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[1225]);
    }
    return call(fn, {username});
}
Variant posix_getpwuid(const Variant &user_id) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[1226]);
    }
    return call(fn, {user_id});
}
Variant posix_getrlimit(const Variant &resource) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[1227]);
    }
    return call(fn, {resource});
}
Variant posix_setrlimit(const Variant &resource, const Variant &soft_limit, const Variant &hard_limit) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[1228]);
    }
    return call(fn, {resource, soft_limit, hard_limit});
}
Variant posix_get_last_error() {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[1229]);
    }
    return call(fn, {});
}
Variant posix_errno() {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[1230]);
    }
    return call(fn, {});
}
Variant posix_strerror(const Variant &error_code) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[1231]);
    }
    return call(fn, {error_code});
}
Variant posix_initgroups(const Variant &username, const Variant &group_id) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[1232]);
    }
    return call(fn, {username, group_id});
}
Variant posix_sysconf(const Variant &conf_id) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[1233]);
    }
    return call(fn, {conf_id});
}
Variant posix_pathconf(const Variant &path, const Variant &name) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[1234]);
    }
    return call(fn, {path, name});
}
Variant posix_fpathconf(const Variant &file_descriptor, const Variant &name) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[1235]);
    }
    return call(fn, {file_descriptor, name});
}
}  // namespace php

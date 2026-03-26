#include "phpx.h"
#include "phpx_literal_string.h"

namespace php {
Variant posix_kill(const Variant &process_id, const Variant &signal);
Variant posix_getpid();
Variant posix_getppid();
Variant posix_getuid();
Variant posix_setuid(const Variant &user_id);
Variant posix_geteuid();
Variant posix_seteuid(const Variant &user_id);
Variant posix_getgid();
Variant posix_setgid(const Variant &group_id);
Variant posix_getegid();
Variant posix_setegid(const Variant &group_id);
Variant posix_getgroups();
Variant posix_getlogin();
Variant posix_getpgrp();
Variant posix_setsid();
Variant posix_setpgid(const Variant &process_id, const Variant &process_group_id);
Variant posix_getpgid(const Variant &process_id);
Variant posix_getsid(const Variant &process_id);
Variant posix_uname();
Variant posix_times();
Variant posix_ctermid();
Variant posix_ttyname(const Variant &file_descriptor);
Variant posix_isatty(const Variant &file_descriptor);
Variant posix_getcwd();
Variant posix_mkfifo(const Variant &filename, const Variant &permissions);
Variant posix_mknod(const Variant &filename, const Variant &flags, const Variant &major = 0, const Variant &minor = 0);
Variant posix_access(const Variant &filename, const Variant &flags = 0);
Variant posix_eaccess(const Variant &filename, const Variant &flags = 0);
Variant posix_getgrnam(const Variant &name);
Variant posix_getgrgid(const Variant &group_id);
Variant posix_getpwnam(const Variant &username);
Variant posix_getpwuid(const Variant &user_id);
Variant posix_getrlimit(const Variant &resource = {});
Variant posix_setrlimit(const Variant &resource, const Variant &soft_limit, const Variant &hard_limit);
Variant posix_get_last_error();
Variant posix_errno();
Variant posix_strerror(const Variant &error_code);
Variant posix_initgroups(const Variant &username, const Variant &group_id);
Variant posix_sysconf(const Variant &conf_id);
Variant posix_pathconf(const Variant &path, const Variant &name);
Variant posix_fpathconf(const Variant &file_descriptor, const Variant &name);
}  // namespace php

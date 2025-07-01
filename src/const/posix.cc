#include "phpx.h"

namespace php {
Variant POSIX_F_OK { 0 };
Variant POSIX_X_OK { 1 };
Variant POSIX_W_OK { 2 };
Variant POSIX_R_OK { 4 };
Variant POSIX_S_IFREG { 32768 };
Variant POSIX_S_IFCHR { 8192 };
Variant POSIX_S_IFBLK { 24576 };
Variant POSIX_S_IFIFO { 4096 };
Variant POSIX_S_IFSOCK { 49152 };
Variant POSIX_RLIMIT_AS { 9 };
Variant POSIX_RLIMIT_CORE { 4 };
Variant POSIX_RLIMIT_CPU { 0 };
Variant POSIX_RLIMIT_DATA { 2 };
Variant POSIX_RLIMIT_FSIZE { 1 };
Variant POSIX_RLIMIT_LOCKS { 10 };
Variant POSIX_RLIMIT_MEMLOCK { 8 };
Variant POSIX_RLIMIT_MSGQUEUE { 12 };
Variant POSIX_RLIMIT_NICE { 13 };
Variant POSIX_RLIMIT_NOFILE { 7 };
Variant POSIX_RLIMIT_NPROC { 6 };
Variant POSIX_RLIMIT_RSS { 5 };
Variant POSIX_RLIMIT_RTPRIO { 14 };
Variant POSIX_RLIMIT_RTTIME { 15 };
Variant POSIX_RLIMIT_SIGPENDING { 11 };
Variant POSIX_RLIMIT_STACK { 3 };
Variant POSIX_RLIMIT_INFINITY { -1 };
}

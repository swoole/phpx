#include "phpx.h"

namespace php {
Variant pcntl_fork{ZEND_STRL("pcntl_fork"), true};
Variant pcntl_waitpid{ZEND_STRL("pcntl_waitpid"), true};
Variant pcntl_wait{ZEND_STRL("pcntl_wait"), true};
Variant pcntl_signal{ZEND_STRL("pcntl_signal"), true};
Variant pcntl_signal_get_handler{ZEND_STRL("pcntl_signal_get_handler"), true};
Variant pcntl_signal_dispatch{ZEND_STRL("pcntl_signal_dispatch"), true};
Variant pcntl_sigprocmask{ZEND_STRL("pcntl_sigprocmask"), true};
Variant pcntl_sigwaitinfo{ZEND_STRL("pcntl_sigwaitinfo"), true};
Variant pcntl_sigtimedwait{ZEND_STRL("pcntl_sigtimedwait"), true};
Variant pcntl_wifexited{ZEND_STRL("pcntl_wifexited"), true};
Variant pcntl_wifstopped{ZEND_STRL("pcntl_wifstopped"), true};
Variant pcntl_wifcontinued{ZEND_STRL("pcntl_wifcontinued"), true};
Variant pcntl_wifsignaled{ZEND_STRL("pcntl_wifsignaled"), true};
Variant pcntl_wexitstatus{ZEND_STRL("pcntl_wexitstatus"), true};
Variant pcntl_wtermsig{ZEND_STRL("pcntl_wtermsig"), true};
Variant pcntl_wstopsig{ZEND_STRL("pcntl_wstopsig"), true};
Variant pcntl_exec{ZEND_STRL("pcntl_exec"), true};
Variant pcntl_alarm{ZEND_STRL("pcntl_alarm"), true};
Variant pcntl_get_last_error{ZEND_STRL("pcntl_get_last_error"), true};
Variant pcntl_errno{ZEND_STRL("pcntl_errno"), true};
Variant pcntl_getpriority{ZEND_STRL("pcntl_getpriority"), true};
Variant pcntl_setpriority{ZEND_STRL("pcntl_setpriority"), true};
Variant pcntl_strerror{ZEND_STRL("pcntl_strerror"), true};
Variant pcntl_async_signals{ZEND_STRL("pcntl_async_signals"), true};
Variant pcntl_unshare{ZEND_STRL("pcntl_unshare"), true};
}

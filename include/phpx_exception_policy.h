#pragma once

/*
 * Replaceable exception policy used by PHPX internals. The default policy
 * retains native C++ exceptions. Alternative hosts can provide another
 * propagation model without changing call sites; the freestanding kernel
 * policy terminates through its panic hook and compiles with -fno-exceptions.
 */
#ifdef PHPX_KERNEL
extern "C" ZEND_NORETURN void php_nano_kernel_panic(const char *message);
#define PHPX_TRY if (true)
#define PHPX_CATCH_ALL else if (false)
#define PHPX_CATCH(type, name) else if (false) for (type name = nullptr; false;)
#define PHPX_THROW(value) ((void) (value), php_nano_kernel_panic("PHPX exception in kernel mode"))
#define PHPX_RETHROW() PHPX_THROW(EG(exception))
#else
#define PHPX_TRY try
#define PHPX_CATCH_ALL catch (...)
#define PHPX_CATCH(type, name) catch (type name)
#define PHPX_THROW(value) throw (value)
#define PHPX_RETHROW() throw
#endif

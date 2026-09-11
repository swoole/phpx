#pragma once

/*
 * Replaceable exception policy used by PHPX internals. The default policy
 * retains native C++ exceptions. Alternative hosts can provide another
 * propagation model without changing call sites. Hosts built with
 * -fno-exceptions define PHPX_NO_EXCEPTION and provide the abort hook below.
 */
#ifdef PHPX_NO_EXCEPTION
extern "C" ZEND_NORETURN void phpx_no_exception_abort(const char *message);
#define PHPX_TRY if (true)
#define PHPX_CATCH_ALL else if (false)
#define PHPX_CATCH(type, name) else if (false) for (type name = nullptr; false;)
#define PHPX_THROW(value) ((void) (value), phpx_no_exception_abort("PHPX exception propagation is unavailable"))
#define PHPX_RETHROW() PHPX_THROW(EG(exception))
#else
#define PHPX_TRY try
#define PHPX_CATCH_ALL catch (...)
#define PHPX_CATCH(type, name) catch (type name)
#define PHPX_THROW(value) throw (value)
#define PHPX_RETHROW() throw
#endif

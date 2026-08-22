#pragma once

#include <phpx.h>

extern PHPX_API zend_class_entry *typephp_fiber_generator_ce;

PHPX_API php::Object typephp_new_fiber_generator(const php::Var &callback);
PHPX_API php::Var typephp_fiber_suspend(const php::Var &value, bool *closed);
PHPX_API bool typephp_fiber_yield(const php::Var &value);
PHPX_API php::Var typephp_fiber_yield_from(const php::Var &iterable, bool *closed);
PHPX_API void typephp_fiber_rethrow(const php::Var &exception);
PHPX_API void typephp_register_fiber_generator_class();
PHPX_API void typephp_unregister_fiber_generator_class();

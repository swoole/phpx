#pragma once

#include <phpx.h>

extern zend_class_entry *typephp_fiber_generator_ce;

php::Object typephp_new_fiber_generator(const php::Var &callback);
php::Var typephp_fiber_suspend(const php::Var &value, bool *closed);
bool typephp_fiber_yield(const php::Var &value);
php::Var typephp_fiber_yield_from(const php::Var &iterable, bool *closed);
void typephp_fiber_rethrow(const php::Var &exception);
void typephp_register_fiber_generator_class();

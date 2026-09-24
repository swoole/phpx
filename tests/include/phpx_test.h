#pragma once

#include "phpx.h"
#include "sapi/embed/php_embed.h"

#include <gtest/gtest.h>

struct ChildResult {
	std::string output;
	bool exited;
	int exit_code;
	int term_signal;
};

php::Array create_map();
php::Array create_list();
const std::string &get_root_path();
std::string get_tests_dir();
std::string get_include_dir();
php::String get_machine_architecture();
php::String get_runtime_php_version();
php::Int get_runtime_php_version_id();
ChildResult run_in_child_capture_stdout(const std::function<int(void)> &func);
void try_call(const std::function<void(void)> &fn, const php::String &msg, bool print = false);

namespace php {
class Class;
class Interface;
}  // namespace php

php::Class *get_gtest_builder_base();
php::Class *get_gtest_builder_child();
php::Class *get_gtest_builder_direct_child();
php::Interface *get_gtest_builder_interface();
zend_class_entry *get_gtest_hooked_class();
zend_class_entry *get_gtest_hooked_child_class();
zend_class_entry *get_gtest_hooked_inherited_class();

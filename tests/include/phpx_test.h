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
ChildResult run_in_child_capture_stdout(const std::function<int(void)> &func);

#pragma once

#include "phpx.h"
#include "sapi/embed/php_embed.h"

#include <gtest/gtest.h>

php::Array create_map();
php::Array create_list();
const std::string &get_root_path();
std::string get_tests_dir();
std::string get_include_dir();

#pragma once

#include "phpx.h"
#include "phpx_embed.h"

#include <gtest/gtest.h>

php::Array create_map();
const std::string &get_root_path();
std::string get_tests_dir();
std::string get_include_dir();

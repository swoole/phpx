/*
 * base.cpp
 *
 *  Created on: 2017年5月23日
 *      Author: htf
 */



#include "phpx.h"

using namespace std;

namespace php
{
Variant ini_get(string varname)
{
    char* str = zend_ini_string((char *) varname.c_str(), (uint) varname.length(), 0);
    return Variant(str);
}
}

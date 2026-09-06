#pragma once

#include "phpx.h"

// Resolve extension constants at request time; no process-global zvals.
#define CURLOPT_URL php::constant("CURLOPT_URL")
#define CURLOPT_SSL_VERIFYPEER php::constant("CURLOPT_SSL_VERIFYPEER")
#define CURLOPT_SSL_VERIFYHOST php::constant("CURLOPT_SSL_VERIFYHOST")
#define CURLOPT_RETURNTRANSFER php::constant("CURLOPT_RETURNTRANSFER")
#define CURLOPT_HTTPHEADER php::constant("CURLOPT_HTTPHEADER")

/*
  +----------------------------------------------------------------------+
  | PHP-X                                                                |
  +----------------------------------------------------------------------+
  | This source file is subject to version 2.0 of the Apache license,    |
  | that is bundled with this package in the file LICENSE, and is        |
  | available through the world-wide-web at the following url:           |
  | http://www.apache.org/licenses/LICENSE-2.0.html                      |
  | If you did not receive a copy of the Apache2.0 license and are unable|
  | to obtain it through the world-wide-web, please send a note to       |
  | license@swoole.com so we can mail you a copy immediately.            |
  +----------------------------------------------------------------------+
  | Author: Tianfeng Han  <rango@swoole.com>                             |
  +----------------------------------------------------------------------+
*/

#pragma once

#include "phpx.h"
#include "phpx_scope_guard.h"
#include "phpx_math.h"
#include "phpx_builtin_func.h"
#include "phpx_operator.h"

namespace php {
static inline bool same(Int a, Int b) {
    return a == b;
}

static inline bool same(Float a, Float b) {
    return a == b;
}

static inline bool same(Bool a, Bool b) {
    return a == b;
}

static inline bool equals(Int a, Int b) {
    return a == b;
}

static inline bool equals(Float a, Float b) {
    return a == b;
}

static inline Int toInt(Int v) {
    return v;
}

static inline Int toInt(const Variant &v) {
    return v.toInt();
}

static inline Int toInt(zval *zv) {
    return zval_get_long(zv);
}

static inline Float toFloat(Float v) {
    return v;
}

static inline Float toFloat(const Variant &v) {
    return v.toFloat();
}

static inline Float toFloat(zval *zv) {
    return zval_get_double(zv);
}

static inline bool toBool(bool v) {
    return v;
}

static inline bool toBool(const Variant &v) {
    return v.toBool();
}

static inline bool toBool(zval *zv) {
    return zend_is_true(zv);
}

static inline String toString(const Variant &v) {
    return v.toString();
}

static inline void echo(int val) {
    echo((Int) val);
}

static inline Int len(const Variant &v) {
    return v.length();
}

static inline Bool empty(Int v) {
    return v == 0;
}

static inline Bool empty(Float v) {
    return v == 0;
}

static inline Bool empty(Bool v) {
    return !v;
}

static inline Bool empty(const Variant &v) {
    return !v.toBool();
}

static inline bool exists(Int v) {
    return true;
}

static inline bool exists(Float v) {
    return true;
}

static inline bool exists(Bool v) {
    return true;
}

static inline Bool exists(const Variant &v) {
    return !(v.isNull() || v.isUndef());
}

static inline void move(Int v, zval *retval) {
    ZVAL_LONG(retval, v);
}

static inline void move(Float v, zval *retval) {
    ZVAL_DOUBLE(retval, v);
}

static inline void move(Bool v, zval *retval) {
    ZVAL_BOOL(retval, v);
}

static inline void move(Variant &v, zval *retval) {
    v.moveTo(retval);
}

static inline bool instanceOf(const Object &v, const String &cls) {
    return v.instanceOf(cls);
}

static inline Variant silentCall(const Variant &func, const ArgList &args) {
    auto ori_error_reporting = EG(error_reporting);
    php::call("error_reporting", {E_FATAL_ERRORS});
    auto rs = call(func, args);
    php::call("error_reporting", {ori_error_reporting});
    return rs;
}

static inline Variant silentCall(const Variant &func) {
    return silentCall(func, {});
}

static inline Variant getCallArg(uint32_t i) {
    return {ZEND_CALL_ARG(EG(current_execute_data), i + 1), Ctor::CopyRef};
}

static inline Variant getCallArg(uint32_t i, const Variant &defaultValue) {
    if (i >= ZEND_CALL_NUM_ARGS(EG(current_execute_data))) {
        return defaultValue;
    } else {
        return getCallArg(i);
    }
}
}  // namespace php

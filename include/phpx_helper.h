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

static inline bool same(Float a, Int b) {
    return same(a, static_cast<Float>(b));
}

static inline bool same(Int a, Float b) {
    return same(static_cast<Float>(a), b);
}

static inline bool equals(Int a, Int b) {
    return a == b;
}

static inline bool equals(Float a, Float b) {
    return a == b;
}

static inline bool equals(Float a, Int b) {
    return equals(a, static_cast<Float>(b));
}

static inline bool equals(Int a, Float b) {
    return equals(static_cast<Float>(a), b);
}

static inline Int toInt(Int v) {
    return v;
}

static inline Int toInt(Float v) {
    return static_cast<Int>(v);
}

static inline Int toInt(Bool v) {
    return static_cast<Int>(v);
}

static inline Int toInt(const char *v) {
    return Variant(v).toInt();
}

static inline Int toInt(const std::string &v) {
    return Variant(v).toInt();
}

static inline Int toInt(const Variant &v) {
    return v.toInt();
}

static inline Int toInt(zval *zv) {
    return zval_get_long(zv);
}

static inline Float toFloat(Int v) {
    return static_cast<Float>(v);
}

static inline Float toFloat(Float v) {
    return v;
}

static inline Float toFloat(Bool v) {
    return static_cast<Float>(v);
}

static inline Float toFloat(const char *v) {
    return Variant(v).toFloat();
}

static inline Float toFloat(const std::string &v) {
    return Variant(v).toFloat();
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

template <typename T>
static inline bool notEmpty(T v) {
    return !empty(v);
}

static inline bool notEmpty(const Variant &v, const OperationChain &list) {
    return !empty(v, list);
}

static inline bool notEmpty(const Variant &v, const OperationChain &list, Variant &result) {
    return !empty(v, list, result);
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

static inline void deref(zval *v) {
    if (UNEXPECTED(zval_is_ref(v) && zval_ref_count(v) == 1)) {
        zend_reference *ref = Z_REF_P(v);
        ZVAL_COPY_VALUE(v, &ref->val);
        efree_size(ref, sizeof(zend_reference));
    }
}

static inline bool instanceOf(const Variant &v, const String &cls) {
    if (!v.isObject()) {
        return false;
    }
    Object tmp(v);
    return tmp.instanceOf(cls);
}

static inline bool instanceOf(const Variant &v, zend_class_entry *ce) {
    if (!v.isObject()) {
        return false;
    }
    Object tmp(v);
    return tmp.instanceOf(ce);
}

static inline Object clone(const Variant &v) {
    if (!v.isObject()) {
        throwError("Attempt to clone on %s", v.typeStr());
        return {};
    }
    Object tmp(v);
    return tmp.clone();
}

static inline bool instanceOf(const Object &v, const String &cls) {
    return v.instanceOf(cls);
}

static inline Variant getCallArg(uint32_t i) {
    return {ZEND_CALL_ARG(EG(current_execute_data), i + 1), Ctor::CopyRef};
}

static inline Reference getCallArgByRef(uint32_t i) {
    return {ZEND_CALL_ARG(EG(current_execute_data), i + 1), Ctor::CopyRef};
}

static inline uint32_t getCallArgNum() {
    return ZEND_CALL_NUM_ARGS(EG(current_execute_data));
}

static inline Variant getCallArg(uint32_t i, const Variant &defaultValue) {
    if (i >= getCallArgNum()) {
        return defaultValue;
    } else {
        return getCallArg(i);
    }
}

static inline Reference getCallArgByRef(uint32_t i, const Reference &defaultValue) {
    if (i >= getCallArgNum()) {
        return defaultValue;
    } else {
        return getCallArgByRef(i);
    }
}
}  // namespace php

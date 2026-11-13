#include "phpx.h"
#include "typephp_helper.h"

#include <zend_closures.h>

namespace php {

// Resolves a class-declared keyword method on an object. Returns false when the
// class does not declare it, so the caller uses the default conversion. The
// compiler enforces the keyword contract for compiled classes; a class it never
// saw (loaded at runtime, internal) is checked here from the already-resolved
// zend_function: a few flag/type-mask tests and no extra lookup. `lower` is the
// lowercase method name, `expected_mask` the exact return type bit mask.
bool callKeywordMethod(const Variant &object_value,
                       const String &lower,
                       uint32_t expected_mask,
                       const char *expected,
                       Variant &result) {
    zend_object *object = Z_OBJ_P(object_value.unwrap_ptr());
    auto *fn = static_cast<zend_function *>(zend_hash_find_ptr(&object->ce->function_table, lower.str()));
    if (fn == nullptr || object->ce == zend_ce_closure) {
        return false;
    }
    const uint32_t flags = fn->common.fn_flags;
    // arg_info is null without a declared return type.
    const bool conforming =
        (flags & (ZEND_ACC_PUBLIC | ZEND_ACC_STATIC | ZEND_ACC_RETURN_REFERENCE | ZEND_ACC_HAS_RETURN_TYPE)) ==
            (ZEND_ACC_PUBLIC | ZEND_ACC_HAS_RETURN_TYPE) &&
        fn->common.num_args == 0 && !ZEND_TYPE_HAS_NAME(fn->common.arg_info[-1].type) &&
        ZEND_TYPE_PURE_MASK(fn->common.arg_info[-1].type) == expected_mask;
    if (UNEXPECTED(!conforming)) {
        throwError("%s::%s() must be a public, non-static method without parameters returning exactly %s",
                   ZSTR_VAL(object->ce->name),
                   ZSTR_VAL(fn->common.function_name),
                   expected);
        return false;
    }
    zend_call_known_instance_method_with_0_params(fn, object, result.ptr());
    throwErrorIfOccurred();
    return true;
}

}  // namespace php

bool typephp_keyword_object_to_int(const php::Variant &v, php::Int *out) {
    static php::String lower{ZEND_STRL("toint"), true};
    php::Variant result;
    if (!php::callKeywordMethod(v, lower, MAY_BE_LONG, "int", result)) {
        return false;
    }
    *out = result.toInt();
    return true;
}

bool typephp_keyword_object_to_float(const php::Variant &v, php::Float *out) {
    static php::String lower{ZEND_STRL("tofloat"), true};
    php::Variant result;
    if (!php::callKeywordMethod(v, lower, MAY_BE_DOUBLE, "float", result)) {
        return false;
    }
    *out = result.toFloat();
    return true;
}

bool typephp_keyword_object_to_string(const php::Variant &v, php::String *out) {
    static php::String lower{ZEND_STRL("tostring"), true};
    php::Variant result;
    if (!php::callKeywordMethod(v, lower, MAY_BE_STRING, "string", result)) {
        return false;
    }
    *out = result.toString();
    return true;
}

bool typephp_keyword_object_to_bool(const php::Variant &v, bool *out) {
    static php::String lower{ZEND_STRL("tobool"), true};
    php::Variant result;
    if (!php::callKeywordMethod(v, lower, MAY_BE_BOOL, "bool", result)) {
        return false;
    }
    *out = result.toBool();
    return true;
}

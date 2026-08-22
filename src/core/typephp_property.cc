#include <typephp_helper.h>

#include <cstring>

void typephp_unset_typed_property(zend_object *object, zend_string *member, void **cache_slot) {
    zend_class_entry *ce = object->ce;
    zend_property_info *property_info = zend_get_property_info(ce, member, 1);

    if (property_info != nullptr && ZEND_TYPE_IS_SET(property_info->type)) {
        if (property_info->flags & ZEND_ACC_STATIC) {
            goto std_unset;
        }

        zend_uchar pure_mask = ZEND_TYPE_PURE_MASK(property_info->type);
        if (ZEND_TYPE_HAS_NAME(property_info->type)) {
            goto std_unset;
        }

        /* Preserve an existing reference container while resetting its inner
         * value, otherwise references to the property would become detached. */
        zval *member_p = OBJ_PROP(object, property_info->offset);
        zval *value_p = Z_ISREF_P(member_p) ? Z_REFVAL_P(member_p) : member_p;
        zend_uchar type_mask = pure_mask & static_cast<zend_uchar>(~MAY_BE_NULL);

        switch (type_mask) {
        case MAY_BE_LONG:
            zval_ptr_dtor(value_p);
            ZVAL_LONG(value_p, 0);
            return;
        case MAY_BE_DOUBLE:
            zval_ptr_dtor(value_p);
            ZVAL_DOUBLE(value_p, 0.0);
            return;
        case MAY_BE_BOOL:
            zval_ptr_dtor(value_p);
            ZVAL_FALSE(value_p);
            return;
        case MAY_BE_STRING:
            zval_ptr_dtor(value_p);
            ZVAL_EMPTY_STRING(value_p);
            return;
        case MAY_BE_ARRAY:
            zval_ptr_dtor(value_p);
            ZVAL_EMPTY_ARRAY(value_p);
            return;
        default:
            break;
        }
    }

std_unset:
    zend_std_unset_property(object, member, cache_slot);
}

namespace {

zend_function *find_property_helper(zend_object *object, zend_string *member, const char *prefix, size_t prefix_len) {
    static const char hex[] = "0123456789abcdef";
    const size_t member_len = ZSTR_LEN(member);
    // Property names are runtime input. Use Zend's checked allocator so the
    // hexadecimal expansion cannot wrap before the method-name allocation.
    zend_string *method = zend_string_safe_alloc(2, member_len, prefix_len, false);
    memcpy(ZSTR_VAL(method), prefix, prefix_len);
    for (size_t i = 0; i < member_len; i++) {
        const unsigned char ch = static_cast<unsigned char>(ZSTR_VAL(member)[i]);
        ZSTR_VAL(method)[prefix_len + i * 2] = hex[ch >> 4];
        ZSTR_VAL(method)[prefix_len + i * 2 + 1] = hex[ch & 0x0f];
    }
    ZSTR_VAL(method)[ZSTR_LEN(method)] = '\0';
    auto *function = static_cast<zend_function *>(zend_hash_find_ptr(&object->ce->function_table, method));
    zend_string_release(method);
    return function;
}

zval *read_hook_property(zend_object *object, zend_string *member, int type, void **cache_slot, zval *rv) {
    static const char prefix[] = "__typephp_property_get_";
    zend_function *function = find_property_helper(object, member, prefix, sizeof(prefix) - 1);
    if (function == nullptr) {
        return zend_std_read_property(object, member, type, cache_slot, rv);
    }
    ZVAL_UNDEF(rv);
    zend_call_known_instance_method_with_0_params(function, object, rv);
    return rv;
}

bool reject_asymmetric_property_write(zend_object *object, zend_string *member) {
    static const char private_prefix[] = "__typephp_property_private_set_";
    static const char protected_prefix[] = "__typephp_property_protected_set_";
    zend_function *visibility = find_property_helper(object, member, private_prefix, sizeof(private_prefix) - 1);
    auto *scope = php::FakeScopeGuard::current();
    if (visibility != nullptr && scope != visibility->common.scope) {
        zend_throw_error(nullptr,
                         "Cannot modify private(set) property %s::$%s",
                         ZSTR_VAL(visibility->common.scope->name),
                         ZSTR_VAL(member));
        return true;
    }
    if (visibility == nullptr) {
        visibility = find_property_helper(object, member, protected_prefix, sizeof(protected_prefix) - 1);
        if (visibility != nullptr && (scope == nullptr || (!instanceof_function(scope, visibility->common.scope) &&
                                                           !instanceof_function(visibility->common.scope, scope)))) {
            zend_throw_error(nullptr,
                             "Cannot modify protected(set) property %s::$%s",
                             ZSTR_VAL(visibility->common.scope->name),
                             ZSTR_VAL(member));
            return true;
        }
    }
    return false;
}

zval *write_hook_property(zend_object *object, zend_string *member, zval *value, void **cache_slot) {
    if (reject_asymmetric_property_write(object, member)) {
        return &EG(uninitialized_zval);
    }

    static const char setter_prefix[] = "__typephp_property_set_";
    zend_function *function = find_property_helper(object, member, setter_prefix, sizeof(setter_prefix) - 1);
    if (function == nullptr) {
        static const char getter_prefix[] = "__typephp_property_get_";
        if (find_property_helper(object, member, getter_prefix, sizeof(getter_prefix) - 1) != nullptr) {
            zend_throw_error(nullptr, "Property %s::$%s is read-only", ZSTR_VAL(object->ce->name), ZSTR_VAL(member));
            return &EG(uninitialized_zval);
        }
        return zend_std_write_property(object, member, value, cache_slot);
    }

    zval retval;
    ZVAL_UNDEF(&retval);
    zend_call_known_instance_method_with_1_params(function, object, &retval, value);
    if (!Z_ISUNDEF(retval)) {
        zval_ptr_dtor(&retval);
    }
    zend_property_info *property_info = zend_get_property_info(object->ce, member, true);
    if (property_info == nullptr || (property_info->flags & ZEND_ACC_STATIC)) {
        return &EG(uninitialized_zval);
    }
    return OBJ_PROP(object, property_info->offset);
}

void initialize_property_handlers(zend_object_handlers *handlers, const zend_object_handlers *base_handlers) {
    memcpy(handlers, base_handlers, sizeof(zend_object_handlers));
    handlers->read_property = read_hook_property;
    handlers->write_property = write_hook_property;
    handlers->unset_property = typephp_unset_typed_property;
}

}  // namespace

void typephp_install_property_handlers(zend_class_entry *class_entry, zend_object_handlers *handlers) {
    initialize_property_handlers(handlers, class_entry->default_object_handlers);
    class_entry->default_object_handlers = handlers;
}

php::Variant typephp_read_property_scoped(const php::Variant &object,
                                          const php::Variant &member,
                                          zend_class_entry *scope,
                                          php::AttrMode mode) {
    if (UNEXPECTED(!object.isObject())) {
        php::throwError("Attempt to read property `%s` on %s", member.toCString(), object.typeStr());
        return {};
    }

    php::String property_name = member.toString();
    zval rv;
    zval *member_p;
    {
        php::FakeScopeGuard fake_scope_guard{scope};
        member_p = object.object()->handlers->read_property(
            object.object(),
            property_name.str(),
            mode == php::AttrMode::Update ? BP_VAR_RW : (mode == php::AttrMode::Isset ? BP_VAR_IS : BP_VAR_R),
            nullptr,
            &rv);
        php::throwErrorIfOccurred();

        if (php::zval_is_null(member_p) && mode == php::AttrMode::Update) {
            member_p =
                object.object()->handlers->write_property(object.object(), property_name.str(), php::undef(), nullptr);
            php::throwErrorIfOccurred();
            if (member_p == php::undef()) {
                php::throwError("Dynamic property `%s` assignment is not supported", member.toCString());
            }
        }
    }

    if (member_p == &rv) {
        return php::Variant{member_p, php::Ctor::Move};
    }
    return php::Variant{member_p, php::zval_wrap(member_p)};
}

void typephp_write_property_scoped(const php::Variant &object,
                                   const php::Variant &member,
                                   const php::Variant &value,
                                   zend_class_entry *scope) {
    if (UNEXPECTED(!object.isObject())) {
        php::throwError("Attempt to write property `%s` on %s", member.toCString(), object.typeStr());
        return;
    }
    php::String property_name = member.toString();
    // Trait properties are inserted into the consuming class. Resolve the
    // source trait scope to the class that owns the actual property slot.
    if (scope && (scope->ce_flags & ZEND_ACC_TRAIT)) {
        auto *property_info = static_cast<zend_property_info *>(
            zend_hash_find_ptr(&object.object()->ce->properties_info, property_name.str()));
        if (property_info) {
            scope = property_info->ce;
        }
    }
    {
        php::FakeScopeGuard fake_scope_guard{scope};
        object.object()->handlers->write_property(
            object.object(), property_name.str(), const_cast<zval *>(value.const_ptr()), nullptr);
    }
    php::throwErrorIfOccurred();
}

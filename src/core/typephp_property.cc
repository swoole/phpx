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

zval *write_hook_property(zend_object *object, zend_string *member, zval *value, void **cache_slot);

#if PHP_VERSION_ID >= 80500
bool is_compatible_property_scope(const zend_class_entry *declaring_scope, const zend_class_entry *scope) {
    return scope != nullptr && (declaring_scope == scope || instanceof_function(scope, declaring_scope) ||
                                instanceof_function(declaring_scope, scope));
}

bool has_property_read_access(const zend_property_info *property_info, const zend_class_entry *scope) {
    if (property_info->flags & ZEND_ACC_PRIVATE) {
        return property_info->ce == scope;
    }
    if (property_info->flags & ZEND_ACC_PROTECTED) {
        return is_compatible_property_scope(property_info->prototype->ce, scope);
    }
    return true;
}

bool has_property_set_access(const zend_property_info *property_info, const zend_class_entry *scope) {
    if (property_info->flags & ZEND_ACC_PRIVATE_SET) {
        return property_info->ce == scope;
    }
    if (property_info->flags & ZEND_ACC_PROTECTED_SET) {
        return is_compatible_property_scope(property_info->prototype->ce, scope);
    }
    return true;
}

zend_property_info *find_clone_property(zend_object *object, zend_string *member, const zend_class_entry *scope) {
    // Parent-private properties are stored under a mangled key on the child
    // object. Resolve the source-level name against the lexical scope first,
    // matching the behavior of a property write compiled in that scope.
    if (scope != nullptr && scope != object->ce && instanceof_function(object->ce, scope)) {
        auto *property_info = static_cast<zend_property_info *>(zend_hash_find_ptr(&scope->properties_info, member));
        if (property_info != nullptr && property_info->ce == scope && (property_info->flags & ZEND_ACC_PRIVATE)) {
            return property_info;
        }
    }

    return static_cast<zend_property_info *>(zend_hash_find_ptr(&object->ce->properties_info, member));
}

bool property_uses_strict_types() {
    zend_execute_data *execute_data = EG(current_execute_data);
    return execute_data != nullptr && execute_data->func != nullptr && ZEND_CALL_USES_STRICT_TYPES(execute_data);
}

zval *write_parent_private_clone_property(zend_object *object, zend_property_info *property_info, zval *value) {
    zval *property = OBJ_PROP(object, property_info->offset);
    const bool strict = property_uses_strict_types();
    zval assigned;

    Z_TRY_ADDREF_P(value);
    ZVAL_COPY_VALUE(&assigned, value);
    if (ZEND_TYPE_IS_SET(property_info->type) &&
        UNEXPECTED(!zend_verify_property_type(property_info, &assigned, strict))) {
        zval_ptr_dtor(&assigned);
        return &EG(error_zval);
    }

    Z_PROP_FLAG_P(property) &= ~(IS_PROP_UNINIT | IS_PROP_REINITABLE);
    return zend_assign_to_variable(property, &assigned, IS_TMP_VAR, strict);
}

zval *write_clone_property(zend_object *object, zend_string *member, zval *value, const zend_class_entry *scope) {
    zend_property_info *property_info = find_clone_property(object, member, scope);
    if (property_info == nullptr || (property_info->flags & ZEND_ACC_STATIC) ||
        !has_property_read_access(property_info, scope) || !has_property_set_access(property_info, scope)) {
        php::FakeScopeGuard scope_guard{scope};
        return zend_std_write_property(object, member, value, nullptr);
    }

    php::FakeScopeGuard scope_guard{property_info->ce};
    static const char setter_prefix[] = "__typephp_property_set_";
    static const char getter_prefix[] = "__typephp_property_get_";
    if (find_property_helper(object, member, setter_prefix, sizeof(setter_prefix) - 1) != nullptr ||
        find_property_helper(object, member, getter_prefix, sizeof(getter_prefix) - 1) != nullptr) {
        return write_hook_property(object, member, value, nullptr);
    }

    if ((property_info->flags & ZEND_ACC_PRIVATE) && property_info->ce != object->ce) {
        return write_parent_private_clone_property(object, property_info, value);
    }
    return zend_std_write_property(object, member, value, nullptr);
}

zend_object *clone_object_with(zend_object *old_object, const zend_class_entry *scope, const HashTable *properties) {
    // Direct AOT method calls have no Zend method frame for
    // zend_get_executed_scope(). Scoped php::call() carries that lexical scope
    // separately, while ordinary Zend calls provide it in the clone_obj_with
    // argument.
    if (scope == nullptr) {
        scope = php::detail::getLexicalCallScope();
    }
    zend_object *new_object = old_object->handlers->clone_obj(old_object);
    if (new_object == nullptr) {
        return nullptr;
    }

    // A custom clone allocator may restore its base handlers. The clone has
    // the same runtime class as the source, so retain the exact TypePHP table
    // before dispatching property hooks on the new object.
    new_object->handlers = old_object->handlers;
    if (UNEXPECTED(EG(exception))) {
        return new_object;
    }

    if (ZEND_CLASS_HAS_READONLY_PROPS(new_object->ce)) {
        for (uint32_t i = 0; i < new_object->ce->default_properties_count; i++) {
            Z_PROP_FLAG_P(OBJ_PROP_NUM(new_object, i)) |= IS_PROP_REINITABLE;
        }
    }

    ZEND_HASH_FOREACH_KEY_VAL(properties, zend_ulong index, zend_string * member, zval * value) {
        if (UNEXPECTED(Z_ISREF_P(value))) {
            if (Z_REFCOUNT_P(value) == 1) {
                value = Z_REFVAL_P(value);
            } else {
                zend_throw_error(nullptr, "Cannot assign by reference when cloning with updated properties");
                break;
            }
        }

        if (UNEXPECTED(member == nullptr)) {
            member = zend_long_to_str(index);
            write_clone_property(new_object, member, value, scope);
            zend_string_release_ex(member, false);
        } else {
            write_clone_property(new_object, member, value, scope);
        }

        if (UNEXPECTED(EG(exception))) {
            break;
        }
    }
    ZEND_HASH_FOREACH_END();

    // Do not clear IS_PROP_REINITABLE globally here. Zend intentionally leaves
    // readonly properties that were not present in `properties` reinitializable
    // once on the clone; each successful write consumes the flag for the slot
    // it updates.
    return new_object;
}
#endif

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
#if PHP_VERSION_ID >= 80500
    handlers->clone_obj_with = clone_object_with;
#endif
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

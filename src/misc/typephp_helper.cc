#include "typephp_helper.h"

#include <zend_smart_str.h>

#include <cstdint>

namespace {

constexpr uint32_t typephp_attribute_has_lazy_arguments = 1u << 31;
constexpr uint16_t typephp_attribute_lazy_value_marker = 0x5450;

zif_handler original_get_arguments = nullptr;
zif_handler original_new_instance = nullptr;
zif_handler original_to_string = nullptr;

zend_internal_function *reflection_get_arguments = nullptr;
zend_internal_function *reflection_new_instance = nullptr;
zend_internal_function *reflection_to_string = nullptr;
zend_function *reflection_get_name = nullptr;
zend_function *reflection_get_target = nullptr;
zend_function *reflection_is_repeated = nullptr;

uint32_t reflection_hook_install_count = 0;
thread_local bool last_get_arguments_had_lazy_value = false;

static bool is_lazy_value_argument(const zval *value) {
    return Z_TYPE_P(value) == IS_LONG && Z_TYPE_EXTRA_P(value) == typephp_attribute_lazy_value_marker;
}

static typephp_attribute_value_factory get_lazy_factory(const zval *value) {
    return reinterpret_cast<typephp_attribute_value_factory>(static_cast<uintptr_t>(Z_LVAL_P(value)));
}

static bool materialize_lazy_arguments(zval *arguments) {
    bool changed = false;
    zval *value;

    ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(arguments), value) {
        if (!is_lazy_value_argument(value)) {
            continue;
        }

        typephp_attribute_value_factory factory = get_lazy_factory(value);
        ZEND_ASSERT(factory != nullptr);
        php::Var materialized = factory(false);
        if (UNEXPECTED(EG(exception))) {
            return changed;
        }
        ZVAL_COPY(value, materialized.ptr());
        changed = true;
    }
    ZEND_HASH_FOREACH_END();

    return changed;
}

static zend_internal_function *find_internal_method(zend_class_entry *class_entry, const char *name, size_t length) {
    auto *function = static_cast<zend_function *>(zend_hash_str_find_ptr(&class_entry->function_table, name, length));
    if (function == nullptr || function->type != ZEND_INTERNAL_FUNCTION) {
        return nullptr;
    }
    return reinterpret_cast<zend_internal_function *>(function);
}

static bool call_reflection_method(zend_object *object, zend_function *method, zval *return_value) {
    ZVAL_UNDEF(return_value);
    zend_call_known_function(method, object, object->ce, return_value, 0, nullptr, nullptr);
    return !EG(exception);
}

static bool get_materialized_arguments(zend_object *object, zval *arguments, bool *had_lazy_value) {
    last_get_arguments_had_lazy_value = false;
    ZVAL_UNDEF(arguments);
    zend_call_known_function(
        reinterpret_cast<zend_function *>(reflection_get_arguments), object, object->ce, arguments, 0, nullptr, nullptr);
    *had_lazy_value = last_get_arguments_had_lazy_value;
    return !EG(exception);
}

static uint32_t get_attribute_class_flags(zend_attribute *marker, zend_class_entry *attribute_class) {
    uint32_t flags = ZEND_ATTRIBUTE_TARGET_ALL;
    if (marker->argc == 0) {
        return flags;
    }

    zval value;
    if (zend_get_attribute_value(&value, marker, 0, attribute_class) == FAILURE) {
        return 0;
    }
    if (Z_TYPE(value) == IS_LONG) {
        flags = static_cast<uint32_t>(Z_LVAL(value));
    }
    zval_ptr_dtor(&value);
    return flags;
}

static bool validate_attribute_target_and_repeatability(zend_object *reflection,
                                                        zend_class_entry *attribute_class,
                                                        zend_attribute *marker,
                                                        zend_string *attribute_name) {
    if (attribute_class->type != ZEND_USER_CLASS) {
        return true;
    }

    uint32_t flags = get_attribute_class_flags(marker, attribute_class);
    if (EG(exception)) {
        return false;
    }

    zval target;
    if (!call_reflection_method(reflection, reflection_get_target, &target)) {
        return false;
    }
    uint32_t target_flags = static_cast<uint32_t>(zval_get_long(&target));
    zval_ptr_dtor(&target);

    if (!(target_flags & flags)) {
        zend_string *location = zend_get_attribute_target_names(target_flags);
        zend_string *allowed = zend_get_attribute_target_names(flags);
        zend_throw_error(nullptr,
                         "Attribute \"%s\" cannot target %s (allowed targets: %s)",
                         ZSTR_VAL(attribute_name),
                         ZSTR_VAL(location),
                         ZSTR_VAL(allowed));
        zend_string_release(location);
        zend_string_release(allowed);
        return false;
    }

    if (!(flags & ZEND_ATTRIBUTE_IS_REPEATABLE)) {
        zval repeated;
        if (!call_reflection_method(reflection, reflection_is_repeated, &repeated)) {
            return false;
        }
        bool is_repeated = zend_is_true(&repeated);
        zval_ptr_dtor(&repeated);
        if (is_repeated) {
            zend_throw_error(nullptr, "Attribute \"%s\" must not be repeated", ZSTR_VAL(attribute_name));
            return false;
        }
    }

    return true;
}

struct constructor_arguments {
    zval *positional = nullptr;
    uint32_t positional_count = 0;
    HashTable *named = nullptr;
};

static constructor_arguments prepare_constructor_arguments(zend_array *arguments) {
    constructor_arguments result;
    if (zend_hash_num_elements(arguments) != 0) {
        result.positional = static_cast<zval *>(safe_emalloc(zend_hash_num_elements(arguments), sizeof(zval), 0));
    }

    zend_string *name;
    zval *value;
    ZEND_HASH_FOREACH_STR_KEY_VAL(arguments, name, value) {
        if (name == nullptr) {
            ZVAL_COPY(&result.positional[result.positional_count++], value);
        } else {
            if (result.named == nullptr) {
                result.named = zend_new_array(0);
            }
            zval copy;
            ZVAL_COPY(&copy, value);
            zend_hash_add_new(result.named, name, &copy);
        }
    }
    ZEND_HASH_FOREACH_END();

    return result;
}

static void destroy_constructor_arguments(constructor_arguments *arguments) {
    for (uint32_t i = 0; i < arguments->positional_count; i++) {
        zval_ptr_dtor(&arguments->positional[i]);
    }
    if (arguments->positional != nullptr) {
        efree(arguments->positional);
    }
    if (arguments->named != nullptr) {
        zend_array_destroy(arguments->named);
    }
}

static zend_result instantiate_attribute(zend_class_entry *class_entry,
                                         constructor_arguments *arguments,
                                         zval *result) {
    if (object_init_ex(result, class_entry) == FAILURE) {
        return FAILURE;
    }

    if (class_entry->constructor == nullptr) {
        if (arguments->positional_count != 0 || arguments->named != nullptr) {
            zval_ptr_dtor(result);
            ZVAL_UNDEF(result);
            zend_throw_error(nullptr,
                             "Attribute class %s does not have a constructor, cannot pass arguments",
                             ZSTR_VAL(class_entry->name));
            return FAILURE;
        }
        return SUCCESS;
    }

    zend_function *constructor = class_entry->constructor;
    if (!(constructor->common.fn_flags & ZEND_ACC_PUBLIC)) {
        zval_ptr_dtor(result);
        ZVAL_UNDEF(result);
        zend_throw_error(nullptr, "Attribute constructor of class %s must be public", ZSTR_VAL(class_entry->name));
        return FAILURE;
    }

    zend_call_known_function(constructor,
                             Z_OBJ_P(result),
                             Z_OBJCE_P(result),
                             nullptr,
                             arguments->positional_count,
                             arguments->positional,
                             arguments->named);
    if (EG(exception)) {
        zend_object_store_ctor_failed(Z_OBJ_P(result));
        zval_ptr_dtor(result);
        ZVAL_UNDEF(result);
        return FAILURE;
    }

    return SUCCESS;
}

static zend_result format_attribute_value(smart_str *buffer, zval *value) {
    if (is_lazy_value_argument(value)) {
        typephp_attribute_value_factory factory = get_lazy_factory(value);
        php::Var description = factory(true);
        if (UNEXPECTED(EG(exception)) || !description.isString()) {
            return FAILURE;
        }
        smart_str_append(buffer, Z_STR_P(description.ptr()));
        return SUCCESS;
    }
    if (smart_str_append_zval(buffer, value, SIZE_MAX) == SUCCESS) {
        return SUCCESS;
    }
    if (Z_TYPE_P(value) != IS_ARRAY) {
        return FAILURE;
    }

    bool is_list = zend_array_is_list(Z_ARRVAL_P(value));
    bool first = true;
    smart_str_appendc(buffer, '[');

    zend_ulong index;
    zend_string *key;
    zval *item;
    ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(value), index, key, item) {
        if (!first) {
            smart_str_appends(buffer, ", ");
        }
        first = false;
        if (!is_list) {
            if (key != nullptr) {
                smart_str_appendc(buffer, '\'');
                smart_str_append_escaped(buffer, ZSTR_VAL(key), ZSTR_LEN(key));
                smart_str_appendc(buffer, '\'');
            } else {
                smart_str_append_long(buffer, index);
            }
            smart_str_appends(buffer, " => ");
        }
        if (format_attribute_value(buffer, item) == FAILURE) {
            return FAILURE;
        }
    }
    ZEND_HASH_FOREACH_END();

    smart_str_appendc(buffer, ']');
    return SUCCESS;
}

static void typephp_reflection_get_arguments(INTERNAL_FUNCTION_PARAMETERS) {
    original_get_arguments(INTERNAL_FUNCTION_PARAM_PASSTHRU);
    if (EG(exception) || Z_TYPE_P(return_value) != IS_ARRAY) {
        last_get_arguments_had_lazy_value = false;
        return;
    }

    last_get_arguments_had_lazy_value = materialize_lazy_arguments(return_value);
}

static void typephp_reflection_new_instance(INTERNAL_FUNCTION_PARAMETERS) {
    if (zend_parse_parameters_none() == FAILURE) {
        RETURN_THROWS();
    }

    zval arguments;
    bool had_lazy_value = false;
    if (!get_materialized_arguments(Z_OBJ_P(ZEND_THIS), &arguments, &had_lazy_value)) {
        RETURN_THROWS();
    }
    if (!had_lazy_value) {
        zval_ptr_dtor(&arguments);
        original_new_instance(INTERNAL_FUNCTION_PARAM_PASSTHRU);
        return;
    }

    zval name;
    if (!call_reflection_method(Z_OBJ_P(ZEND_THIS), reflection_get_name, &name)) {
        zval_ptr_dtor(&arguments);
        RETURN_THROWS();
    }
    if (Z_TYPE(name) != IS_STRING) {
        zval_ptr_dtor(&name);
        zval_ptr_dtor(&arguments);
        zend_throw_error(nullptr, "ReflectionAttribute::getName() did not return a string");
        RETURN_THROWS();
    }

    zend_class_entry *attribute_class = zend_lookup_class(Z_STR(name));
    if (attribute_class == nullptr) {
        zend_throw_error(nullptr, "Attribute class \"%s\" not found", Z_STRVAL(name));
        zval_ptr_dtor(&name);
        zval_ptr_dtor(&arguments);
        RETURN_THROWS();
    }

    zend_attribute *marker = zend_get_attribute_str(attribute_class->attributes, ZEND_STRL("attribute"));
    if (marker == nullptr) {
        zend_throw_error(nullptr, "Attempting to use non-attribute class \"%s\" as attribute", Z_STRVAL(name));
        zval_ptr_dtor(&name);
        zval_ptr_dtor(&arguments);
        RETURN_THROWS();
    }

    if (!validate_attribute_target_and_repeatability(Z_OBJ_P(ZEND_THIS), attribute_class, marker, Z_STR(name))) {
        zval_ptr_dtor(&name);
        zval_ptr_dtor(&arguments);
        RETURN_THROWS();
    }

    constructor_arguments constructor_args = prepare_constructor_arguments(Z_ARRVAL(arguments));
    zval object;
    zend_result status = instantiate_attribute(attribute_class, &constructor_args, &object);
    destroy_constructor_arguments(&constructor_args);
    zval_ptr_dtor(&name);
    zval_ptr_dtor(&arguments);

    if (status == FAILURE) {
        RETURN_THROWS();
    }
    RETURN_COPY_VALUE(&object);
}

static void typephp_reflection_to_string(INTERNAL_FUNCTION_PARAMETERS) {
    if (zend_parse_parameters_none() == FAILURE) {
        RETURN_THROWS();
    }

    zval arguments;
    ZVAL_UNDEF(&arguments);
    original_get_arguments(execute_data, &arguments);
    if (EG(exception) || Z_TYPE(arguments) != IS_ARRAY) {
        RETURN_THROWS();
    }
    bool had_lazy_value = false;
    zval *argument_value;
    ZEND_HASH_FOREACH_VAL(Z_ARRVAL(arguments), argument_value) {
        if (is_lazy_value_argument(argument_value)) {
            had_lazy_value = true;
            break;
        }
    }
    ZEND_HASH_FOREACH_END();
    if (!had_lazy_value) {
        zval_ptr_dtor(&arguments);
        original_to_string(INTERNAL_FUNCTION_PARAM_PASSTHRU);
        return;
    }

    zval name;
    if (!call_reflection_method(Z_OBJ_P(ZEND_THIS), reflection_get_name, &name)) {
        zval_ptr_dtor(&arguments);
        RETURN_THROWS();
    }

    smart_str buffer = {nullptr};
    smart_str_appends(&buffer, "Attribute [ ");
    smart_str_append(&buffer, Z_STR(name));
    smart_str_appends(&buffer, " ]");

    uint32_t argument_count = zend_hash_num_elements(Z_ARRVAL(arguments));
    if (argument_count == 0) {
        smart_str_appendc(&buffer, '\n');
    } else {
        smart_str_appends(&buffer, " {\n");
        smart_str_append_printf(&buffer, "  - Arguments [%u] {\n", argument_count);

        uint32_t argument_index = 0;
        zend_string *argument_name;
        zval *argument;
        ZEND_HASH_FOREACH_STR_KEY_VAL(Z_ARRVAL(arguments), argument_name, argument) {
            smart_str_append_printf(&buffer, "    Argument #%u [ ", argument_index++);
            if (argument_name != nullptr) {
                smart_str_append(&buffer, argument_name);
                smart_str_appends(&buffer, " = ");
            }
            if (format_attribute_value(&buffer, argument) == FAILURE) {
                smart_str_free(&buffer);
                zval_ptr_dtor(&name);
                zval_ptr_dtor(&arguments);
                zend_throw_error(nullptr, "Unable to format attribute argument");
                RETURN_THROWS();
            }
            smart_str_appends(&buffer, " ]\n");
        }
        ZEND_HASH_FOREACH_END();

        smart_str_appends(&buffer, "  }\n}\n");
    }

    zval_ptr_dtor(&name);
    zval_ptr_dtor(&arguments);
    RETURN_STR(smart_str_extract(&buffer));
}

}  // namespace

void typephp_attribute_set_lazy_value_argument(zend_attribute *attribute,
                                               uint32_t argument_index,
                                               typephp_attribute_value_factory factory) {
    static_assert(sizeof(zend_long) >= sizeof(typephp_attribute_value_factory));
    ZEND_ASSERT(attribute != nullptr);
    ZEND_ASSERT(argument_index < attribute->argc);
    ZEND_ASSERT(factory != nullptr);

    attribute->flags |= typephp_attribute_has_lazy_arguments;
    ZVAL_LONG(&attribute->args[argument_index].value, static_cast<zend_long>(reinterpret_cast<uintptr_t>(factory)));
    Z_TYPE_EXTRA(attribute->args[argument_index].value) = typephp_attribute_lazy_value_marker;
}

zend_result typephp_install_reflection_attribute_handlers() {
    if (reflection_hook_install_count++ != 0) {
        return SUCCESS;
    }

    auto *reflection_attribute =
        static_cast<zend_class_entry *>(zend_hash_str_find_ptr(CG(class_table), ZEND_STRL("reflectionattribute")));
    if (reflection_attribute == nullptr) {
        reflection_hook_install_count = 0;
        return FAILURE;
    }

    reflection_get_arguments = find_internal_method(reflection_attribute, ZEND_STRL("getarguments"));
    reflection_new_instance = find_internal_method(reflection_attribute, ZEND_STRL("newinstance"));
    reflection_to_string = find_internal_method(reflection_attribute, ZEND_STRL("__tostring"));
    reflection_get_name = reinterpret_cast<zend_function *>(
        find_internal_method(reflection_attribute, ZEND_STRL("getname")));
    reflection_get_target = reinterpret_cast<zend_function *>(
        find_internal_method(reflection_attribute, ZEND_STRL("gettarget")));
    reflection_is_repeated = reinterpret_cast<zend_function *>(
        find_internal_method(reflection_attribute, ZEND_STRL("isrepeated")));
    if (reflection_get_arguments == nullptr || reflection_new_instance == nullptr || reflection_to_string == nullptr ||
        reflection_get_name == nullptr || reflection_get_target == nullptr || reflection_is_repeated == nullptr) {
        reflection_hook_install_count = 0;
        return FAILURE;
    }

    original_get_arguments = reflection_get_arguments->handler;
    original_new_instance = reflection_new_instance->handler;
    original_to_string = reflection_to_string->handler;

    reflection_get_arguments->handler = reinterpret_cast<zif_handler>(typephp_reflection_get_arguments);
    reflection_new_instance->handler = reinterpret_cast<zif_handler>(typephp_reflection_new_instance);
    reflection_to_string->handler = reinterpret_cast<zif_handler>(typephp_reflection_to_string);
    return SUCCESS;
}

void typephp_uninstall_reflection_attribute_handlers() {
    if (reflection_hook_install_count == 0 || --reflection_hook_install_count != 0) {
        return;
    }

    if (reflection_get_arguments != nullptr &&
        reflection_get_arguments->handler == reinterpret_cast<zif_handler>(typephp_reflection_get_arguments)) {
        reflection_get_arguments->handler = original_get_arguments;
    }
    if (reflection_new_instance != nullptr &&
        reflection_new_instance->handler == reinterpret_cast<zif_handler>(typephp_reflection_new_instance)) {
        reflection_new_instance->handler = original_new_instance;
    }
    if (reflection_to_string != nullptr &&
        reflection_to_string->handler == reinterpret_cast<zif_handler>(typephp_reflection_to_string)) {
        reflection_to_string->handler = original_to_string;
    }

    reflection_get_arguments = nullptr;
    reflection_new_instance = nullptr;
    reflection_to_string = nullptr;
    reflection_get_name = nullptr;
    reflection_get_target = nullptr;
    reflection_is_repeated = nullptr;
    original_get_arguments = nullptr;
    original_new_instance = nullptr;
    original_to_string = nullptr;
}

#ifdef PPROF_ON
#include <gperftools/profiler.h>
#endif

#include <phpx.h>
#include <typephp_helper.h>
#include <mutex>
BEGIN_EXTERN_C()
#include "sapi/embed/php_embed.h"
#include "ps_title.h"
END_EXTERN_C()

extern zend_module_entry *php_embed_get_module();

void module_init(zend_module_entry *module) {
#if PHP_VERSION_ID >= 80400
    if (zend_register_module_ex(module, MODULE_PERSISTENT) == NULL) {
#else
    if (zend_register_module_ex(module) == NULL) {
#endif
        zend_error(E_ERROR, "Failed to register module [%s]", module->name);
        exit(255);
    }
    if (zend_startup_module_ex(module) == FAILURE) {
        zend_error(E_ERROR, "Failed to startup module [%s]", module->name);
        exit(255);
    }
}

const char *php_get_called_class(php::Object &this_) {
    auto ce = php_get_called_ce(this_);
    if (ce) {
        return ce->name->val;
    } else {
        return "";
    }
}

zend_class_entry *php_get_called_ce(php::Object &this_) {
    if (this_.isObject()) {
        return this_.ce();
    } else {
        return (zend_class_entry *) Z_PTR_P(this_.ptr());
    }
}

static zend_execute_data *get_frame() {
    zend_execute_data *frame = EG(current_execute_data);
    while (frame && (!frame->func || !ZEND_USER_CODE(frame->func->type))) {
        frame = frame->prev_execute_data;
    }
    return frame;
}

php::Scope php_switch_scope(php::Object &this_) {
    php::Scope scope;
    scope.frame = get_frame();
    scope.ce = scope.frame->func->common.scope;
    scope.frame->func->common.scope = php_get_called_ce(this_);
    return scope;
}

void php_restore_scope(php::Scope &ori_scope) {
    ori_scope.frame->func->common.scope = ori_scope.ce;
}

static php_stream *s_in_process = NULL;
static void cli_register_file_handles(void) {
    php_stream *s_in, *s_out, *s_err;
    php_stream_context *sc_in = NULL, *sc_out = NULL, *sc_err = NULL;
    zend_constant ic, oc, ec;

    s_in = php_stream_open_wrapper_ex("php://stdin", "rb", 0, NULL, sc_in);
    s_out = php_stream_open_wrapper_ex("php://stdout", "wb", 0, NULL, sc_out);
    s_err = php_stream_open_wrapper_ex("php://stderr", "wb", 0, NULL, sc_err);

    /* Release stream resources, but don't free the underlying handles. Otherwise,
     * extensions which write to stderr or company during mshutdown/gshutdown
     * won't have the expected functionality.
     */
    if (s_in) s_in->flags |= PHP_STREAM_FLAG_NO_RSCR_DTOR_CLOSE;
    if (s_out) s_out->flags |= PHP_STREAM_FLAG_NO_RSCR_DTOR_CLOSE;
    if (s_err) s_err->flags |= PHP_STREAM_FLAG_NO_RSCR_DTOR_CLOSE;

    if (s_in == NULL || s_out == NULL || s_err == NULL) {
        if (s_in) php_stream_close(s_in);
        if (s_out) php_stream_close(s_out);
        if (s_err) php_stream_close(s_err);
        return;
    }

    s_in_process = s_in;

    php_stream_to_zval(s_in, &ic.value);
    php_stream_to_zval(s_out, &oc.value);
    php_stream_to_zval(s_err, &ec.value);

    Z_CONSTANT_FLAGS(ic.value) = 0;
    ic.name = zend_string_init_interned("STDIN", sizeof("STDIN") - 1, 0);
    zend_register_constant(&ic);

    Z_CONSTANT_FLAGS(oc.value) = 0;
    oc.name = zend_string_init_interned("STDOUT", sizeof("STDOUT") - 1, 0);
    zend_register_constant(&oc);

    Z_CONSTANT_FLAGS(ec.value) = 0;
    ec.name = zend_string_init_interned("STDERR", sizeof("STDERR") - 1, 0);
    zend_register_constant(&ec);
}

void module_shutdown(zend_module_entry *module) {
    /**
     * There is a bug in PHP's handling of internal strings. All interned strings are released in the request shutdown
     * function, but then released again in the php_embed_shutdown function, resulting in a use-after-free issue. These
     * must be manually removed from the module table to prevent double release.
     */
    auto name_len = strlen(module->name);
    auto lcname = zend_string_alloc(name_len, module->type == MODULE_PERSISTENT);
    zend_str_tolower_copy(ZSTR_VAL(lcname), module->name, name_len);
    zend_hash_del(&module_registry, lcname);
}

void typephp_unset_typed_property(zend_object *object, zend_string *member, void **cache_slot) {
    zend_class_entry *ce = object->ce;
    zend_property_info *property_info = zend_get_property_info(ce, member, 1);

    if (property_info != NULL && ZEND_TYPE_IS_SET(property_info->type)) {
        if (property_info->flags & ZEND_ACC_STATIC) {
            goto _std_unset;
        }

        zend_uchar pure_mask = ZEND_TYPE_PURE_MASK(property_info->type);

        /* Object/class type properties default to null */
        if (ZEND_TYPE_HAS_NAME(property_info->type)) {
            goto _std_unset;
        }

        /* Simple typed properties: reset to type default.
         *
         * The property slot may already be IS_REFERENCE if user code has taken
         * &$object->prop. In that case preserve the reference container and
         * reset its inner value, otherwise existing references would detach from
         * the object property.
         */
        zval *member_p = OBJ_PROP(object, property_info->offset);
        zval *value_p = Z_ISREF_P(member_p) ? Z_REFVAL_P(member_p) : member_p;
        zend_uchar type_mask = pure_mask & (zend_uchar) ~MAY_BE_NULL;

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
        case MAY_BE_ARRAY: {
            zval_ptr_dtor(value_p);
            ZVAL_EMPTY_ARRAY(value_p);
            return;
        }
        default:
            break;
        }
    }

_std_unset:
    zend_std_unset_property(object, member, cache_slot);
}

namespace {
static zend_function *find_property_helper(zend_object *object,
                                           zend_string *member,
                                           const char *prefix,
                                           size_t prefix_len) {
    static const char hex[] = "0123456789abcdef";
    const size_t member_len = ZSTR_LEN(member);
    zend_string *method = zend_string_alloc(prefix_len + member_len * 2, false);
    memcpy(ZSTR_VAL(method), prefix, prefix_len);
    for (size_t i = 0; i < member_len; i++) {
        const unsigned char ch = (unsigned char) ZSTR_VAL(member)[i];
        ZSTR_VAL(method)[prefix_len + i * 2] = hex[ch >> 4];
        ZSTR_VAL(method)[prefix_len + i * 2 + 1] = hex[ch & 0x0f];
    }
    ZSTR_VAL(method)[ZSTR_LEN(method)] = '\0';
    zend_function *function = (zend_function *) zend_hash_find_ptr(&object->ce->function_table, method);
    zend_string_release(method);
    return function;
}

static zval *read_hook_property(zend_object *object, zend_string *member, int type, void **cache_slot, zval *rv) {
    static const char prefix[] = "__typephp_property_get_";
    zend_function *function = find_property_helper(object, member, prefix, sizeof(prefix) - 1);
    if (function == nullptr) {
        return zend_std_read_property(object, member, type, cache_slot, rv);
    }
    ZVAL_UNDEF(rv);
    zend_call_known_instance_method_with_0_params(function, object, rv);
    return rv;
}

static bool reject_asymmetric_property_write(zend_object *object, zend_string *member) {
    static const char private_prefix[] = "__typephp_property_private_set_";
    static const char protected_prefix[] = "__typephp_property_protected_set_";
    zend_function *visibility = find_property_helper(object, member, private_prefix, sizeof(private_prefix) - 1);
    zend_class_entry *scope = EG(fake_scope);
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

static zval *write_hook_property(zend_object *object, zend_string *member, zval *value, void **cache_slot) {
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

static std::mutex property_handlers_init_mutex;
}  // namespace

static void initialize_property_handlers(zend_object_handlers *handlers, const zend_object_handlers *base_handlers) {
    memcpy(handlers, base_handlers, sizeof(zend_object_handlers));
    handlers->read_property = read_hook_property;
    handlers->write_property = write_hook_property;
    handlers->unset_property = typephp_unset_typed_property;
}

void typephp_install_property_handlers(zend_class_entry *class_entry, zend_object_handlers *handlers) {
#if PHP_VERSION_ID >= 80400
    initialize_property_handlers(handlers, class_entry->default_object_handlers);
    class_entry->default_object_handlers = handlers;
#else
    (void) class_entry;
    memset(handlers, 0, sizeof(zend_object_handlers));
#endif
}

zend_object *typephp_attach_property_handlers(zend_object *object, zend_object_handlers *handlers) {
#if PHP_VERSION_ID < 80400
    if (UNEXPECTED(handlers->read_property != read_hook_property)) {
        std::lock_guard<std::mutex> lock(property_handlers_init_mutex);
        if (handlers->read_property != read_hook_property) {
            initialize_property_handlers(handlers, object->handlers);
        }
    }
    object->handlers = handlers;
#else
    (void) handlers;
#endif
    return object;
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
    // Trait properties are inserted into the consuming class. A shared AOT
    // trait body still carries the trait CE as its source scope, which Zend
    // cannot use for protected/private visibility checks. Resolve that scope
    // to the class that actually declares the property.
    if (scope && (scope->ce_flags & ZEND_ACC_TRAIT)) {
        auto *property_info = static_cast<zend_property_info *>(
            zend_hash_find_ptr(&object.object()->ce->properties_info, property_name.str()));
        if (property_info) {
            scope = property_info->ce;
        }
    }
    zend_class_entry *old_scope = EG(fake_scope);
    EG(fake_scope) = scope;
    try {
        object.object()->handlers->write_property(
            object.object(), property_name.str(), const_cast<zval *>(value.const_ptr()), nullptr);
    } catch (...) {
        EG(fake_scope) = old_scope;
        throw;
    }
    EG(fake_scope) = old_scope;
    php::throwErrorIfOccurred();
}

#ifdef _WIN32
#define TYPEPHP_RUNTIME_API extern "C" __declspec(dllexport)
#else
#define TYPEPHP_RUNTIME_API extern "C" __attribute__((visibility("default")))
#endif

static zend_module_entry *typephp_runtime_module = nullptr;
static bool typephp_runtime_started = false;

TYPEPHP_RUNTIME_API int typephp_runtime_init(int argc, char **argv) {
    if (typephp_runtime_started) {
        return 0;
    }

    php_embed_init(argc, argv);
    php::throw_impl = [](zend_object *ex) { throw ex; };

    typephp_runtime_module = php_embed_get_module();
    module_init(typephp_runtime_module);

#ifndef PHP_WIN32
    save_ps_args(argc, argv);
#endif

    int rc = 0;
    zend_first_try {
        try {
            char path_translated[] = "embed";
            cli_register_file_handles();
            SG(request_info).path_translated = path_translated;
            typephp_runtime_module->request_startup_func(
                typephp_runtime_module->type,
                typephp_runtime_module->module_number
            );
        } catch (zend_object *e) {
            rc = EG(exit_status);
            if (!zend_is_graceful_exit(e)) {
                CG(unclean_shutdown) = 1;
                zend_exception_error(e, E_ERROR);
            }
        }
    }
    zend_end_try();

    if (rc != 0) {
        return rc;
    }

    typephp_runtime_started = true;
    return 0;
}

TYPEPHP_RUNTIME_API void typephp_runtime_shutdown() {
    if (!typephp_runtime_started) {
        return;
    }

    typephp_runtime_module->request_shutdown_func(
        typephp_runtime_module->type,
        typephp_runtime_module->module_number
    );
    module_shutdown(typephp_runtime_module);
    php_embed_shutdown();

    typephp_runtime_module = nullptr;
    typephp_runtime_started = false;
}

#ifndef TYPEPHP_NO_MAIN
int main(int cpp_argc, char **cpp_argv) {
    int rc = 0;
#ifdef PPROF_ON
    ProfilerStart(PROF_OUTPUT_FILE);
#endif
    rc = typephp_runtime_init(cpp_argc, cpp_argv);
#ifdef PPROF_ON
    ProfilerStop();
#endif
    typephp_runtime_shutdown();
    return rc;
}
#endif

#include <phpx.h>
#include <typephp_runtime.h>

BEGIN_EXTERN_C()
#include "ext/standard/basic_functions.h"
#include "sapi/embed/php_embed.h"
#if !defined(PHP_WIN32) && !defined(__wasi__)
#include "ps_title.h"
#endif
END_EXTERN_C()

static void module_init(zend_module_entry *module) {
    if (zend_register_module_ex(module, MODULE_PERSISTENT) == nullptr) {
        zend_error(E_ERROR, "Failed to register module [%s]", module->name);
        exit(255);
    }
    if (zend_startup_module_ex(module) == FAILURE) {
        zend_error(E_ERROR, "Failed to startup module [%s]", module->name);
        exit(255);
    }
}

static php_stream *s_in_process = nullptr;

static void cli_register_file_handles() {
    php_stream *s_in = php_stream_open_wrapper_ex("php://stdin", "rb", 0, nullptr, nullptr);
    php_stream *s_out = php_stream_open_wrapper_ex("php://stdout", "wb", 0, nullptr, nullptr);
    php_stream *s_err = php_stream_open_wrapper_ex("php://stderr", "wb", 0, nullptr, nullptr);

    /* Release stream resources, but don't free the underlying handles. Otherwise,
     * extensions which write during mshutdown/gshutdown lose the standard streams. */
    if (s_in) s_in->flags |= PHP_STREAM_FLAG_NO_RSCR_DTOR_CLOSE;
    if (s_out) s_out->flags |= PHP_STREAM_FLAG_NO_RSCR_DTOR_CLOSE;
    if (s_err) s_err->flags |= PHP_STREAM_FLAG_NO_RSCR_DTOR_CLOSE;

    if (s_in == nullptr || s_out == nullptr || s_err == nullptr) {
        if (s_in) php_stream_close(s_in);
        if (s_out) php_stream_close(s_out);
        if (s_err) php_stream_close(s_err);
        return;
    }

    s_in_process = s_in;
    zend_constant ic, oc, ec;
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

static void module_shutdown(zend_module_entry *module) {
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

static zend_module_entry *typephp_runtime_module = nullptr;
static bool typephp_runtime_started = false;

extern "C" int typephp_runtime_start(typephp_module_getter get_module, int argc, char **argv) {
    if (typephp_runtime_started) {
        return 0;
    }

    php_embed_init(argc, argv);

    typephp_runtime_module = get_module();
    module_init(typephp_runtime_module);

#if !defined(PHP_WIN32) && !defined(__wasi__)
    save_ps_args(argc, argv);
#endif

    int rc = 0;
    zend_first_try {
        try {
            char path_translated[] = "embed";
            cli_register_file_handles();
            SG(request_info).path_translated = path_translated;
            typephp_runtime_module->request_startup_func(typephp_runtime_module->type,
                                                         typephp_runtime_module->module_number);
        } catch (zend_object *e) {
            if (!zend_is_graceful_exit(e)) {
                CG(unclean_shutdown) = 1;
                zend_exception_error(e, E_ERROR);
            }
            rc = EG(exit_status);
        }
    }
    zend_end_try();

    if (rc == 0) {
        // A fatal error bails out (longjmp) and bypasses the C++ catch above,
        // so the exit status recorded by the error handler is the fallback.
        rc = EG(exit_status);
    }

    if (rc != 0) {
        return rc;
    }

    typephp_runtime_started = true;
    return 0;
}

extern "C" void typephp_runtime_stop(void) {
    if (!typephp_runtime_started) {
        return;
    }

    // The TypePHP module is registered after php_embed_init(), so it is not in
    // PHP's precomputed RSHUTDOWN handler list. Run the user-visible shutdown
    // phases first, while the TypePHP request state is still alive.
    EG(flags) |= EG_FLAGS_IN_SHUTDOWN;
    EG(current_execute_data) = nullptr;
    if (PG(modules_activated)) {
        php_call_shutdown_functions();
        php_free_shutdown_functions();
    }
    zend_try {
        zend_call_destructors();
    }
    zend_end_try();

    // Keep this manual cleanup and registry removal. Registering an internal
    // module after request startup exposes a PHP Embed double-release bug for
    // its persistent strings if the module remains registered through
    // php_module_shutdown().
    typephp_runtime_module->request_shutdown_func(typephp_runtime_module->type, typephp_runtime_module->module_number);
    module_shutdown(typephp_runtime_module);
    php_embed_shutdown();

    typephp_runtime_module = nullptr;
    typephp_runtime_started = false;
}

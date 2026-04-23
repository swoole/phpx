#if PPROF_ON
#include <gperftools/profiler.h>
#endif

#include <phpx.h>
#include <php_aot_helper.h>
#include "sapi/embed/php_embed.h"
#include "ps_title.h"

extern zend_module_entry *php_embed_get_module();

void module_init(zend_module_entry *module) {
    if (zend_register_module_ex(module, MODULE_PERSISTENT) == NULL) {
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

int main(int cpp_argc, char **cpp_argv) {
    php_embed_init(cpp_argc, cpp_argv);
    php::throw_impl = [](zend_object *ex) { throw ex; };

    zend_module_entry *module = php_embed_get_module();
    module_init(module);

    save_ps_args(cpp_argc, cpp_argv);

    int rc = 0;
#if PPROF_ON
    ProfilerStart("profile.out");
#endif
    zend_first_try {
        try {
            char path_translated[] = "embed";
            cli_register_file_handles();
            SG(request_info).path_translated = path_translated;
            module->request_startup_func(module->type, module->module_number);
        } catch (zend_object *e) {
            rc = EG(exit_status);
            CG(unclean_shutdown) = 1;
            zend_exception_error(e, E_ERROR);
        }
    }
    zend_end_try();
#if PPROF_ON
    ProfilerStop();
#endif

    module->request_shutdown_func(module->type, module->module_number);
    module_shutdown(module);
    php_embed_shutdown();

    return rc;
}

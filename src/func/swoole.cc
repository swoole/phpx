#include "phpx.h"
#include "phpx_literal_string.h"
#include "phpx_class.h"

namespace php {
Variant swoole_version() {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2728]);
    }
    return call(fn, {});
}
Variant swoole_cpu_num() {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2729]);
    }
    return call(fn, {});
}
Variant swoole_last_error() {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2730]);
    }
    return call(fn, {});
}
Variant swoole_async_dns_lookup_coro(const Variant &domain_name, const Variant &timeout, const Variant &type) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2731]);
    }
    return call(fn, {domain_name, timeout, type});
}
Variant swoole_async_set(const Variant &settings) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2732]);
    }
    return call(fn, {settings});
}
Variant swoole_coroutine_defer(const Variant &callback) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2734]);
    }
    return call(fn, {callback});
}
Variant swoole_coroutine_socketpair(const Variant &domain, const Variant &type, const Variant &protocol) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2735]);
    }
    return call(fn, {domain, type, protocol});
}
Variant swoole_test_kernel_coroutine(const Variant &count, const Variant &sleep_time) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2736]);
    }
    return call(fn, {count, sleep_time});
}
Variant swoole_client_select(const Reference &read,
                             const Reference &write,
                             const Reference &except,
                             const Variant &timeout) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2737]);
    }
    return call(fn, {&read, &write, &except, timeout});
}
Variant swoole_select(const Reference &read, const Reference &write, const Reference &except, const Variant &timeout) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2738]);
    }
    return call(fn, {&read, &write, &except, timeout});
}
Variant swoole_set_process_name(const Variant &process_name) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2739]);
    }
    return call(fn, {process_name});
}
Variant swoole_get_local_ip(const Variant &family) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2740]);
    }
    return call(fn, {family});
}
Variant swoole_get_local_mac() {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2741]);
    }
    return call(fn, {});
}
Variant swoole_strerror(const Variant &errno, const Variant &error_type) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2742]);
    }
    return call(fn, {errno, error_type});
}
Variant swoole_errno() {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2743]);
    }
    return call(fn, {});
}
Variant swoole_clear_error() {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2744]);
    }
    return call(fn, {});
}
Variant swoole_error_log(const Variant &level, const Variant &msg) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2745]);
    }
    return call(fn, {level, msg});
}
Variant swoole_error_log_ex(const Variant &level, const Variant &error, const Variant &msg) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2746]);
    }
    return call(fn, {level, error, msg});
}
Variant swoole_ignore_error(const Variant &error) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2747]);
    }
    return call(fn, {error});
}
Variant swoole_hashcode(const Variant &data, const Variant &type) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2748]);
    }
    return call(fn, {data, type});
}
Variant swoole_mime_type_add(const Variant &suffix, const Variant &mime_type) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2749]);
    }
    return call(fn, {suffix, mime_type});
}
Variant swoole_mime_type_set(const Variant &suffix, const Variant &mime_type) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2750]);
    }
    return call(fn, {suffix, mime_type});
}
Variant swoole_mime_type_delete(const Variant &suffix) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2751]);
    }
    return call(fn, {suffix});
}
Variant swoole_mime_type_get(const Variant &filename) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2752]);
    }
    return call(fn, {filename});
}
Variant swoole_get_mime_type(const Variant &filename) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2753]);
    }
    return call(fn, {filename});
}
Variant swoole_mime_type_exists(const Variant &filename) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2754]);
    }
    return call(fn, {filename});
}
Variant swoole_mime_type_list() {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2755]);
    }
    return call(fn, {});
}
Variant swoole_clear_dns_cache() {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2756]);
    }
    return call(fn, {});
}
Variant swoole_substr_unserialize(const Variant &str,
                                  const Variant &offset,
                                  const Variant &length,
                                  const Variant &options) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2757]);
    }
    return call(fn, {str, offset, length, options});
}
Variant swoole_substr_json_decode(const Variant &str,
                                  const Variant &offset,
                                  const Variant &length,
                                  const Variant &associative,
                                  const Variant &depth,
                                  const Variant &flags) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2758]);
    }
    return call(fn, {str, offset, length, associative, depth, flags});
}
Variant swoole_internal_call_user_shutdown_begin() {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2759]);
    }
    return call(fn, {});
}
Variant swoole_implicit_fn(const Variant &fn, const Variant &args) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2760]);
    }
    return call(fn, {fn, args});
}
Variant swoole_get_objects() {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2761]);
    }
    return call(fn, {});
}
Variant swoole_get_vm_status() {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2762]);
    }
    return call(fn, {});
}
Variant swoole_get_object_by_handle(const Variant &handle) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2763]);
    }
    return call(fn, {handle});
}
Variant swoole_name_resolver_lookup(const Variant &name, const Swoole_NameResolver_Context &ctx) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2764]);
    }
    return call(fn, {name, ctx.getObject()});
}
Variant swoole_name_resolver_lookup(const Variant &name, const Variant &ctx) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2764]);
    }
    return call(fn, {name, ctx});
}
Variant swoole_name_resolver_add(const Variant &ns) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2765]);
    }
    return call(fn, {ns});
}
Variant swoole_name_resolver_remove(const Variant &ns) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2766]);
    }
    return call(fn, {ns});
}
Variant swoole_array_search(const Variant &array, const Variant &value, const Variant &strict) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2770]);
    }
    return call(fn, {array, value, strict});
}
Variant swoole_array_contains(const Variant &array, const Variant &needle, const Variant &strict) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2771]);
    }
    return call(fn, {array, needle, strict});
}
Variant swoole_array_join(const Variant &array, const Variant &separator) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2772]);
    }
    return call(fn, {array, separator});
}
Variant swoole_array_key_exists(const Variant &array, const Variant &key) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2773]);
    }
    return call(fn, {array, key});
}
Variant swoole_str_split(const Variant &string, const Variant &delimiter, const Variant &limit) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2775]);
    }
    return call(fn, {string, delimiter, limit});
}
Variant swoole_parse_str(const Variant &string) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2776]);
    }
    return call(fn, {string});
}
Variant swoole_hash(const Variant &data, const Variant &algo, const Variant &binary, const Variant &options) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2777]);
    }
    return call(fn, {data, algo, binary, options});
}
Variant swoole_typed_array(const Variant &type_def, const Variant &init_array) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2778]);
    }
    return call(fn, {type_def, init_array});
}
Variant swoole_array_is_typed(const Variant &array, const Variant &type_def) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2779]);
    }
    return call(fn, {array, type_def});
}
Variant swoole_str_is_empty(const Variant &string) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2780]);
    }
    return call(fn, {string});
}
Variant swoole_array_is_empty(const Variant &array) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2781]);
    }
    return call(fn, {array});
}
Variant swoole_str_match(const Variant &string, const Variant &pattern, const Variant &flags, const Variant &offset) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2782]);
    }
    return call(fn, {string, pattern, flags, offset});
}
Variant swoole_str_match_all(const Variant &string,
                             const Variant &pattern,
                             const Variant &flags,
                             const Variant &offset) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2783]);
    }
    return call(fn, {string, pattern, flags, offset});
}
Variant swoole_str_json_decode(const Variant &string, const Variant &depth, const Variant &flags) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2784]);
    }
    return call(fn, {string, depth, flags});
}
Variant swoole_str_json_decode_to_object(const Variant &string, const Variant &depth, const Variant &flags) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2785]);
    }
    return call(fn, {string, depth, flags});
}
Variant swoole_str_replace(const Variant &subject, const Variant &search, const Variant &replace) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2786]);
    }
    return call(fn, {subject, search, replace});
}
Variant swoole_str_ireplace(const Variant &subject, const Variant &search, const Variant &replace) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2787]);
    }
    return call(fn, {subject, search, replace});
}
Variant swoole_array_replace_str(const Variant &subjects, const Variant &search, const Variant &replace) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2788]);
    }
    return call(fn, {subjects, search, replace});
}
Variant swoole_array_ireplace_str(const Variant &subjects, const Variant &search, const Variant &replace) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2789]);
    }
    return call(fn, {subjects, search, replace});
}
Variant ssh2_connect(const Variant &host, const Variant &port, const Variant &methods, const Variant &callbacks) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2790]);
    }
    return call(fn, {host, port, methods, callbacks});
}
Variant ssh2_disconnect(const Variant &session) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2791]);
    }
    return call(fn, {session});
}
Variant ssh2_methods_negotiated(const Variant &session) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2792]);
    }
    return call(fn, {session});
}
Variant ssh2_fingerprint(const Variant &session, const Variant &flags) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2793]);
    }
    return call(fn, {session, flags});
}
Variant ssh2_auth_none(const Variant &session, const Variant &username) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2794]);
    }
    return call(fn, {session, username});
}
Variant ssh2_auth_password(const Variant &session, const Variant &username, const Variant &password) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2795]);
    }
    return call(fn, {session, username, password});
}
Variant ssh2_auth_pubkey_file(const Variant &session,
                              const Variant &username,
                              const Variant &pubkeyfile,
                              const Variant &privkeyfile,
                              const Variant &passphrase) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2796]);
    }
    return call(fn, {session, username, pubkeyfile, privkeyfile, passphrase});
}
Variant ssh2_auth_pubkey(const Variant &session,
                         const Variant &username,
                         const Variant &pubkey,
                         const Variant &privkey,
                         const Variant &passphrase) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2797]);
    }
    return call(fn, {session, username, pubkey, privkey, passphrase});
}
Variant ssh2_auth_hostbased_file(const Variant &session,
                                 const Variant &username,
                                 const Variant &hostname,
                                 const Variant &pubkeyfile,
                                 const Variant &privkeyfile,
                                 const Variant &passphrase,
                                 const Variant &local_username) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2798]);
    }
    return call(fn, {session, username, hostname, pubkeyfile, privkeyfile, passphrase, local_username});
}
Variant ssh2_forward_listen(const Variant &session,
                            const Variant &port,
                            const Variant &host,
                            const Variant &max_connections) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2799]);
    }
    return call(fn, {session, port, host, max_connections});
}
Variant ssh2_forward_accept(const Variant &listener, const Reference &host, const Reference &port) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2800]);
    }
    return call(fn, {listener, &host, &port});
}
Variant ssh2_shell(const Variant &session,
                   const Variant &termtype,
                   const Variant &env,
                   const Variant &width,
                   const Variant &height,
                   const Variant &width_height_type) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2801]);
    }
    return call(fn, {session, termtype, env, width, height, width_height_type});
}
Variant ssh2_shell_resize(const Variant &session, const Variant &width, const Variant &height) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2802]);
    }
    return call(fn, {session, width, height});
}
Variant ssh2_exec(const Variant &session,
                  const Variant &command,
                  const Variant &pty,
                  const Variant &env,
                  const Variant &width,
                  const Variant &height,
                  const Variant &width_height_type) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2803]);
    }
    return call(fn, {session, command, pty, env, width, height, width_height_type});
}
Variant ssh2_tunnel(const Variant &session, const Variant &host, const Variant &port) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2804]);
    }
    return call(fn, {session, host, port});
}
Variant ssh2_scp_recv(const Variant &session, const Variant &remote_file, const Variant &local_file) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2805]);
    }
    return call(fn, {session, remote_file, local_file});
}
Variant ssh2_scp_send(const Variant &session,
                      const Variant &local_file,
                      const Variant &remote_file,
                      const Variant &create_mode) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2806]);
    }
    return call(fn, {session, local_file, remote_file, create_mode});
}
Variant ssh2_fetch_stream(const Variant &channel, const Variant &streamid) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2807]);
    }
    return call(fn, {channel, streamid});
}
Variant ssh2_send_eof(const Variant &channel) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2808]);
    }
    return call(fn, {channel});
}
Variant ssh2_sftp(const Variant &session) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2809]);
    }
    return call(fn, {session});
}
Variant ssh2_sftp_rename(const Variant &sftp, const Variant &from, const Variant &to) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2810]);
    }
    return call(fn, {sftp, from, to});
}
Variant ssh2_sftp_unlink(const Variant &sftp, const Variant &filename) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2811]);
    }
    return call(fn, {sftp, filename});
}
Variant ssh2_sftp_mkdir(const Variant &sftp, const Variant &dirname, const Variant &mode, const Variant &recursive) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2812]);
    }
    return call(fn, {sftp, dirname, mode, recursive});
}
Variant ssh2_sftp_rmdir(const Variant &sftp, const Variant &dirname) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2813]);
    }
    return call(fn, {sftp, dirname});
}
Variant ssh2_sftp_chmod(const Variant &sftp, const Variant &filename, const Variant &mode) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2814]);
    }
    return call(fn, {sftp, filename, mode});
}
Variant ssh2_sftp_stat(const Variant &sftp, const Variant &path) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2815]);
    }
    return call(fn, {sftp, path});
}
Variant ssh2_sftp_lstat(const Variant &sftp, const Variant &path) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2816]);
    }
    return call(fn, {sftp, path});
}
Variant ssh2_sftp_symlink(const Variant &sftp, const Variant &target, const Variant &link) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2817]);
    }
    return call(fn, {sftp, target, link});
}
Variant ssh2_sftp_readlink(const Variant &sftp, const Variant &link) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2818]);
    }
    return call(fn, {sftp, link});
}
Variant ssh2_sftp_realpath(const Variant &sftp, const Variant &filename) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2819]);
    }
    return call(fn, {sftp, filename});
}
Variant ssh2_publickey_init(const Variant &session) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2820]);
    }
    return call(fn, {session});
}
Variant ssh2_publickey_add(const Variant &pkey,
                           const Variant &algoname,
                           const Variant &blob,
                           const Variant &overwrite,
                           const Variant &attributes) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2821]);
    }
    return call(fn, {pkey, algoname, blob, overwrite, attributes});
}
Variant ssh2_publickey_remove(const Variant &pkey, const Variant &algoname, const Variant &blob) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2822]);
    }
    return call(fn, {pkey, algoname, blob});
}
Variant ssh2_publickey_list(const Variant &pkey) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2823]);
    }
    return call(fn, {pkey});
}
Variant ssh2_auth_agent(const Variant &session, const Variant &username) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2824]);
    }
    return call(fn, {session, username});
}
FTP_Connection ftp_connect(const Variant &hostname, const Variant &port, const Variant &timeout) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2825]);
    }
    auto _rv = call(fn, {hostname, port, timeout});
    if (!_rv.toBool()) {
        throwException(String("RuntimeException"), "ftp_connect() returned false");
    }
    return FTP_Connection(Object(std::move(_rv)));
}
FTP_Connection ftp_ssl_connect(const Variant &hostname, const Variant &port, const Variant &timeout) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2826]);
    }
    auto _rv = call(fn, {hostname, port, timeout});
    if (!_rv.toBool()) {
        throwException(String("RuntimeException"), "ftp_ssl_connect() returned false");
    }
    return FTP_Connection(Object(std::move(_rv)));
}
Variant ftp_login(const FTP_Connection &ftp, const Variant &username, const Variant &password) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2827]);
    }
    return call(fn, {ftp.getObject(), username, password});
}
Variant ftp_login(const Variant &ftp, const Variant &username, const Variant &password) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2827]);
    }
    return call(fn, {ftp, username, password});
}
Variant ftp_pwd(const FTP_Connection &ftp) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2828]);
    }
    return call(fn, {ftp.getObject()});
}
Variant ftp_pwd(const Variant &ftp) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2828]);
    }
    return call(fn, {ftp});
}
Variant ftp_cdup(const FTP_Connection &ftp) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2829]);
    }
    return call(fn, {ftp.getObject()});
}
Variant ftp_cdup(const Variant &ftp) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2829]);
    }
    return call(fn, {ftp});
}
Variant ftp_chdir(const FTP_Connection &ftp, const Variant &directory) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2830]);
    }
    return call(fn, {ftp.getObject(), directory});
}
Variant ftp_chdir(const Variant &ftp, const Variant &directory) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2830]);
    }
    return call(fn, {ftp, directory});
}
Variant ftp_exec(const FTP_Connection &ftp, const Variant &command) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2831]);
    }
    return call(fn, {ftp.getObject(), command});
}
Variant ftp_exec(const Variant &ftp, const Variant &command) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2831]);
    }
    return call(fn, {ftp, command});
}
Variant ftp_raw(const FTP_Connection &ftp, const Variant &command) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2832]);
    }
    return call(fn, {ftp.getObject(), command});
}
Variant ftp_raw(const Variant &ftp, const Variant &command) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2832]);
    }
    return call(fn, {ftp, command});
}
Variant ftp_mkdir(const FTP_Connection &ftp, const Variant &directory) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2833]);
    }
    return call(fn, {ftp.getObject(), directory});
}
Variant ftp_mkdir(const Variant &ftp, const Variant &directory) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2833]);
    }
    return call(fn, {ftp, directory});
}
Variant ftp_rmdir(const FTP_Connection &ftp, const Variant &directory) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2834]);
    }
    return call(fn, {ftp.getObject(), directory});
}
Variant ftp_rmdir(const Variant &ftp, const Variant &directory) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2834]);
    }
    return call(fn, {ftp, directory});
}
Variant ftp_chmod(const FTP_Connection &ftp, const Variant &permissions, const Variant &filename) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2835]);
    }
    return call(fn, {ftp.getObject(), permissions, filename});
}
Variant ftp_chmod(const Variant &ftp, const Variant &permissions, const Variant &filename) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2835]);
    }
    return call(fn, {ftp, permissions, filename});
}
Variant ftp_alloc(const FTP_Connection &ftp, const Variant &size, const Reference &response) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2836]);
    }
    return call(fn, {ftp.getObject(), size, &response});
}
Variant ftp_alloc(const Variant &ftp, const Variant &size, const Reference &response) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2836]);
    }
    return call(fn, {ftp, size, &response});
}
Variant ftp_nlist(const FTP_Connection &ftp, const Variant &directory) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2837]);
    }
    return call(fn, {ftp.getObject(), directory});
}
Variant ftp_nlist(const Variant &ftp, const Variant &directory) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2837]);
    }
    return call(fn, {ftp, directory});
}
Variant ftp_rawlist(const FTP_Connection &ftp, const Variant &directory, const Variant &recursive) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2838]);
    }
    return call(fn, {ftp.getObject(), directory, recursive});
}
Variant ftp_rawlist(const Variant &ftp, const Variant &directory, const Variant &recursive) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2838]);
    }
    return call(fn, {ftp, directory, recursive});
}
Variant ftp_mlsd(const FTP_Connection &ftp, const Variant &directory) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2839]);
    }
    return call(fn, {ftp.getObject(), directory});
}
Variant ftp_mlsd(const Variant &ftp, const Variant &directory) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2839]);
    }
    return call(fn, {ftp, directory});
}
Variant ftp_systype(const FTP_Connection &ftp) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2840]);
    }
    return call(fn, {ftp.getObject()});
}
Variant ftp_systype(const Variant &ftp) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2840]);
    }
    return call(fn, {ftp});
}
Variant ftp_fget(const FTP_Connection &ftp,
                 const Variant &stream,
                 const Variant &remote_filename,
                 const Variant &mode,
                 const Variant &offset) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2841]);
    }
    return call(fn, {ftp.getObject(), stream, remote_filename, mode, offset});
}
Variant ftp_fget(const Variant &ftp,
                 const Variant &stream,
                 const Variant &remote_filename,
                 const Variant &mode,
                 const Variant &offset) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2841]);
    }
    return call(fn, {ftp, stream, remote_filename, mode, offset});
}
Variant ftp_nb_fget(const FTP_Connection &ftp,
                    const Variant &stream,
                    const Variant &remote_filename,
                    const Variant &mode,
                    const Variant &offset) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2842]);
    }
    return call(fn, {ftp.getObject(), stream, remote_filename, mode, offset});
}
Variant ftp_nb_fget(const Variant &ftp,
                    const Variant &stream,
                    const Variant &remote_filename,
                    const Variant &mode,
                    const Variant &offset) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2842]);
    }
    return call(fn, {ftp, stream, remote_filename, mode, offset});
}
Variant ftp_pasv(const FTP_Connection &ftp, const Variant &enable) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2843]);
    }
    return call(fn, {ftp.getObject(), enable});
}
Variant ftp_pasv(const Variant &ftp, const Variant &enable) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2843]);
    }
    return call(fn, {ftp, enable});
}
Variant ftp_get(const FTP_Connection &ftp,
                const Variant &local_filename,
                const Variant &remote_filename,
                const Variant &mode,
                const Variant &offset) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2844]);
    }
    return call(fn, {ftp.getObject(), local_filename, remote_filename, mode, offset});
}
Variant ftp_get(const Variant &ftp,
                const Variant &local_filename,
                const Variant &remote_filename,
                const Variant &mode,
                const Variant &offset) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2844]);
    }
    return call(fn, {ftp, local_filename, remote_filename, mode, offset});
}
Variant ftp_nb_get(const FTP_Connection &ftp,
                   const Variant &local_filename,
                   const Variant &remote_filename,
                   const Variant &mode,
                   const Variant &offset) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2845]);
    }
    return call(fn, {ftp.getObject(), local_filename, remote_filename, mode, offset});
}
Variant ftp_nb_get(const Variant &ftp,
                   const Variant &local_filename,
                   const Variant &remote_filename,
                   const Variant &mode,
                   const Variant &offset) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2845]);
    }
    return call(fn, {ftp, local_filename, remote_filename, mode, offset});
}
Variant ftp_nb_continue(const FTP_Connection &ftp) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2846]);
    }
    return call(fn, {ftp.getObject()});
}
Variant ftp_nb_continue(const Variant &ftp) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2846]);
    }
    return call(fn, {ftp});
}
Variant ftp_fput(const FTP_Connection &ftp,
                 const Variant &remote_filename,
                 const Variant &stream,
                 const Variant &mode,
                 const Variant &offset) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2847]);
    }
    return call(fn, {ftp.getObject(), remote_filename, stream, mode, offset});
}
Variant ftp_fput(const Variant &ftp,
                 const Variant &remote_filename,
                 const Variant &stream,
                 const Variant &mode,
                 const Variant &offset) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2847]);
    }
    return call(fn, {ftp, remote_filename, stream, mode, offset});
}
Variant ftp_nb_fput(const FTP_Connection &ftp,
                    const Variant &remote_filename,
                    const Variant &stream,
                    const Variant &mode,
                    const Variant &offset) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2848]);
    }
    return call(fn, {ftp.getObject(), remote_filename, stream, mode, offset});
}
Variant ftp_nb_fput(const Variant &ftp,
                    const Variant &remote_filename,
                    const Variant &stream,
                    const Variant &mode,
                    const Variant &offset) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2848]);
    }
    return call(fn, {ftp, remote_filename, stream, mode, offset});
}
Variant ftp_put(const FTP_Connection &ftp,
                const Variant &remote_filename,
                const Variant &local_filename,
                const Variant &mode,
                const Variant &offset) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2849]);
    }
    return call(fn, {ftp.getObject(), remote_filename, local_filename, mode, offset});
}
Variant ftp_put(const Variant &ftp,
                const Variant &remote_filename,
                const Variant &local_filename,
                const Variant &mode,
                const Variant &offset) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2849]);
    }
    return call(fn, {ftp, remote_filename, local_filename, mode, offset});
}
Variant ftp_append(const FTP_Connection &ftp,
                   const Variant &remote_filename,
                   const Variant &local_filename,
                   const Variant &mode) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2850]);
    }
    return call(fn, {ftp.getObject(), remote_filename, local_filename, mode});
}
Variant ftp_append(const Variant &ftp,
                   const Variant &remote_filename,
                   const Variant &local_filename,
                   const Variant &mode) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2850]);
    }
    return call(fn, {ftp, remote_filename, local_filename, mode});
}
Variant ftp_nb_put(const FTP_Connection &ftp,
                   const Variant &remote_filename,
                   const Variant &local_filename,
                   const Variant &mode,
                   const Variant &offset) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2851]);
    }
    return call(fn, {ftp.getObject(), remote_filename, local_filename, mode, offset});
}
Variant ftp_nb_put(const Variant &ftp,
                   const Variant &remote_filename,
                   const Variant &local_filename,
                   const Variant &mode,
                   const Variant &offset) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2851]);
    }
    return call(fn, {ftp, remote_filename, local_filename, mode, offset});
}
Variant ftp_size(const FTP_Connection &ftp, const Variant &filename) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2852]);
    }
    return call(fn, {ftp.getObject(), filename});
}
Variant ftp_size(const Variant &ftp, const Variant &filename) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2852]);
    }
    return call(fn, {ftp, filename});
}
Variant ftp_mdtm(const FTP_Connection &ftp, const Variant &filename) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2853]);
    }
    return call(fn, {ftp.getObject(), filename});
}
Variant ftp_mdtm(const Variant &ftp, const Variant &filename) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2853]);
    }
    return call(fn, {ftp, filename});
}
Variant ftp_rename(const FTP_Connection &ftp, const Variant &from, const Variant &to) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2854]);
    }
    return call(fn, {ftp.getObject(), from, to});
}
Variant ftp_rename(const Variant &ftp, const Variant &from, const Variant &to) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2854]);
    }
    return call(fn, {ftp, from, to});
}
Variant ftp_delete(const FTP_Connection &ftp, const Variant &filename) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2855]);
    }
    return call(fn, {ftp.getObject(), filename});
}
Variant ftp_delete(const Variant &ftp, const Variant &filename) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2855]);
    }
    return call(fn, {ftp, filename});
}
Variant ftp_site(const FTP_Connection &ftp, const Variant &command) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2856]);
    }
    return call(fn, {ftp.getObject(), command});
}
Variant ftp_site(const Variant &ftp, const Variant &command) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2856]);
    }
    return call(fn, {ftp, command});
}
Variant ftp_close(const FTP_Connection &ftp) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2857]);
    }
    return call(fn, {ftp.getObject()});
}
Variant ftp_close(const Variant &ftp) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2857]);
    }
    return call(fn, {ftp});
}
Variant ftp_quit(const FTP_Connection &ftp) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2858]);
    }
    return call(fn, {ftp.getObject()});
}
Variant ftp_quit(const Variant &ftp) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2858]);
    }
    return call(fn, {ftp});
}
Variant ftp_set_option(const FTP_Connection &ftp, const Variant &option, const Variant &value) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2859]);
    }
    return call(fn, {ftp.getObject(), option, value});
}
Variant ftp_set_option(const Variant &ftp, const Variant &option, const Variant &value) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2859]);
    }
    return call(fn, {ftp, option, value});
}
Variant ftp_get_option(const FTP_Connection &ftp, const Variant &option) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2860]);
    }
    return call(fn, {ftp.getObject(), option});
}
Variant ftp_get_option(const Variant &ftp, const Variant &option) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2860]);
    }
    return call(fn, {ftp, option});
}
Variant swoole_tracer_leak_detect(const Variant &threshold) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2861]);
    }
    return call(fn, {threshold});
}
Variant swoole_tracer_prof_begin(const Variant &options) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2862]);
    }
    return call(fn, {options});
}
Variant swoole_tracer_prof_end(const Variant &output_file) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2863]);
    }
    return call(fn, {output_file});
}
Variant go(const Variant &func) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2864]);
    }
    return call(fn, {func});
}
Variant defer(const Variant &callback) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2865]);
    }
    return call(fn, {callback});
}
Variant typed_array(const Variant &type_def, const Variant &init_array) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2866]);
    }
    return call(fn, {type_def, init_array});
}
Variant swoole_event_add(const Variant &fd,
                         const Variant &read_callback,
                         const Variant &write_callback,
                         const Variant &events) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2867]);
    }
    return call(fn, {fd, read_callback, write_callback, events});
}
Variant swoole_event_del(const Variant &fd) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2868]);
    }
    return call(fn, {fd});
}
Variant swoole_event_set(const Variant &fd,
                         const Variant &read_callback,
                         const Variant &write_callback,
                         const Variant &events) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2869]);
    }
    return call(fn, {fd, read_callback, write_callback, events});
}
Variant swoole_event_wait() {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2870]);
    }
    return call(fn, {});
}
Variant swoole_event_isset(const Variant &fd, const Variant &events) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2871]);
    }
    return call(fn, {fd, events});
}
Variant swoole_event_dispatch() {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2872]);
    }
    return call(fn, {});
}
Variant swoole_event_defer(const Variant &callback) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2873]);
    }
    return call(fn, {callback});
}
Variant swoole_event_cycle(const Variant &callback, const Variant &before) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2874]);
    }
    return call(fn, {callback, before});
}
Variant swoole_event_write(const Variant &fd, const Variant &data) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2875]);
    }
    return call(fn, {fd, data});
}
Variant swoole_event_exit() {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2876]);
    }
    return call(fn, {});
}
Variant swoole_event_rshutdown() {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2877]);
    }
    return call(fn, {});
}
Variant swoole_timer_after(const Variant &ms, const Variant &callback) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2878]);
    }
    return call(fn, {ms, callback});
}
Variant swoole_timer_tick(const Variant &ms, const Variant &callback) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2879]);
    }
    return call(fn, {ms, callback});
}
Variant swoole_timer_info(const Variant &timer_id) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2880]);
    }
    return call(fn, {timer_id});
}
Variant swoole_timer_list() {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2881]);
    }
    return call(fn, {});
}
Variant swoole_timer_exists(const Variant &timer_id) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2882]);
    }
    return call(fn, {timer_id});
}
Variant swoole_timer_stats() {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2883]);
    }
    return call(fn, {});
}
Variant swoole_timer_clear(const Variant &timer_id) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2884]);
    }
    return call(fn, {timer_id});
}
Variant swoole_timer_clear_all() {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2885]);
    }
    return call(fn, {});
}
Variant swoole_native_curl_close(const CurlHandle &handle) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2886]);
    }
    return call(fn, {handle.getObject()});
}
Variant swoole_native_curl_close(const Variant &handle) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2886]);
    }
    return call(fn, {handle});
}
CurlHandle swoole_native_curl_copy_handle(const CurlHandle &handle) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2887]);
    }
    auto _rv = call(fn, {handle.getObject()});
    if (!_rv.toBool()) {
        throwException(String("RuntimeException"), "swoole_native_curl_copy_handle() returned false");
    }
    return CurlHandle(Object(std::move(_rv)));
}
Variant swoole_native_curl_copy_handle(const Variant &handle) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2887]);
    }
    return call(fn, {handle});
}
Variant swoole_native_curl_errno(const CurlHandle &handle) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2888]);
    }
    return call(fn, {handle.getObject()});
}
Variant swoole_native_curl_errno(const Variant &handle) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2888]);
    }
    return call(fn, {handle});
}
Variant swoole_native_curl_error(const CurlHandle &handle) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2889]);
    }
    return call(fn, {handle.getObject()});
}
Variant swoole_native_curl_error(const Variant &handle) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2889]);
    }
    return call(fn, {handle});
}
Variant swoole_native_curl_escape(const CurlHandle &handle, const Variant &string) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2890]);
    }
    return call(fn, {handle.getObject(), string});
}
Variant swoole_native_curl_escape(const Variant &handle, const Variant &string) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2890]);
    }
    return call(fn, {handle, string});
}
Variant swoole_native_curl_unescape(const CurlHandle &handle, const Variant &string) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2891]);
    }
    return call(fn, {handle.getObject(), string});
}
Variant swoole_native_curl_unescape(const Variant &handle, const Variant &string) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2891]);
    }
    return call(fn, {handle, string});
}
Variant swoole_native_curl_multi_setopt(const CurlMultiHandle &multi_handle,
                                        const Variant &option,
                                        const Variant &value) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2892]);
    }
    return call(fn, {multi_handle.getObject(), option, value});
}
Variant swoole_native_curl_multi_setopt(const Variant &multi_handle, const Variant &option, const Variant &value) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2892]);
    }
    return call(fn, {multi_handle, option, value});
}
Variant swoole_native_curl_exec(const CurlHandle &handle) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2893]);
    }
    return call(fn, {handle.getObject()});
}
Variant swoole_native_curl_exec(const Variant &handle) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2893]);
    }
    return call(fn, {handle});
}
Variant swoole_native_curl_getinfo(const CurlHandle &handle, const Variant &option) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2894]);
    }
    return call(fn, {handle.getObject(), option});
}
Variant swoole_native_curl_getinfo(const Variant &handle, const Variant &option) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2894]);
    }
    return call(fn, {handle, option});
}
CurlHandle swoole_native_curl_init(const Variant &url) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2895]);
    }
    auto _rv = call(fn, {url});
    if (!_rv.toBool()) {
        throwException(String("RuntimeException"), "swoole_native_curl_init() returned false");
    }
    return CurlHandle(Object(std::move(_rv)));
}
Variant swoole_native_curl_upkeep(const CurlHandle &handle) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2896]);
    }
    return call(fn, {handle.getObject()});
}
Variant swoole_native_curl_upkeep(const Variant &handle) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2896]);
    }
    return call(fn, {handle});
}
Variant swoole_native_curl_multi_add_handle(const CurlMultiHandle &multi_handle, const CurlHandle &handle) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2897]);
    }
    return call(fn, {multi_handle.getObject(), handle.getObject()});
}
Variant swoole_native_curl_multi_add_handle(const Variant &multi_handle, const Variant &handle) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2897]);
    }
    return call(fn, {multi_handle, handle});
}
Variant swoole_native_curl_multi_close(const CurlMultiHandle &multi_handle) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2898]);
    }
    return call(fn, {multi_handle.getObject()});
}
Variant swoole_native_curl_multi_close(const Variant &multi_handle) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2898]);
    }
    return call(fn, {multi_handle});
}
Variant swoole_native_curl_multi_errno(const CurlMultiHandle &multi_handle) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2899]);
    }
    return call(fn, {multi_handle.getObject()});
}
Variant swoole_native_curl_multi_errno(const Variant &multi_handle) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2899]);
    }
    return call(fn, {multi_handle});
}
Variant swoole_native_curl_multi_exec(const CurlMultiHandle &multi_handle, const Reference &still_running) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2900]);
    }
    return call(fn, {multi_handle.getObject(), &still_running});
}
Variant swoole_native_curl_multi_exec(const Variant &multi_handle, const Reference &still_running) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2900]);
    }
    return call(fn, {multi_handle, &still_running});
}
Variant swoole_native_curl_multi_getcontent(const CurlHandle &handle) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2901]);
    }
    return call(fn, {handle.getObject()});
}
Variant swoole_native_curl_multi_getcontent(const Variant &handle) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2901]);
    }
    return call(fn, {handle});
}
Variant swoole_native_curl_multi_info_read(const CurlMultiHandle &multi_handle, const Reference &queued_messages) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2902]);
    }
    return call(fn, {multi_handle.getObject(), &queued_messages});
}
Variant swoole_native_curl_multi_info_read(const Variant &multi_handle, const Reference &queued_messages) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2902]);
    }
    return call(fn, {multi_handle, &queued_messages});
}
CurlMultiHandle swoole_native_curl_multi_init() {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2903]);
    }
    return CurlMultiHandle(Object(call(fn, {})));
}
Variant swoole_native_curl_multi_remove_handle(const CurlMultiHandle &multi_handle, const CurlHandle &handle) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2904]);
    }
    return call(fn, {multi_handle.getObject(), handle.getObject()});
}
Variant swoole_native_curl_multi_remove_handle(const Variant &multi_handle, const Variant &handle) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2904]);
    }
    return call(fn, {multi_handle, handle});
}
Variant swoole_native_curl_multi_select(const CurlMultiHandle &multi_handle, const Variant &timeout) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2905]);
    }
    return call(fn, {multi_handle.getObject(), timeout});
}
Variant swoole_native_curl_multi_select(const Variant &multi_handle, const Variant &timeout) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2905]);
    }
    return call(fn, {multi_handle, timeout});
}
Variant swoole_native_curl_pause(const CurlHandle &handle, const Variant &flags) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2906]);
    }
    return call(fn, {handle.getObject(), flags});
}
Variant swoole_native_curl_pause(const Variant &handle, const Variant &flags) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2906]);
    }
    return call(fn, {handle, flags});
}
Variant swoole_native_curl_reset(const CurlHandle &handle) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2907]);
    }
    return call(fn, {handle.getObject()});
}
Variant swoole_native_curl_reset(const Variant &handle) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2907]);
    }
    return call(fn, {handle});
}
Variant swoole_native_curl_setopt_array(const CurlHandle &handle, const Variant &options) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2908]);
    }
    return call(fn, {handle.getObject(), options});
}
Variant swoole_native_curl_setopt_array(const Variant &handle, const Variant &options) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2908]);
    }
    return call(fn, {handle, options});
}
Variant swoole_native_curl_setopt(const CurlHandle &handle, const Variant &option, const Variant &value) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2909]);
    }
    return call(fn, {handle.getObject(), option, value});
}
Variant swoole_native_curl_setopt(const Variant &handle, const Variant &option, const Variant &value) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2909]);
    }
    return call(fn, {handle, option, value});
}
}  // namespace php

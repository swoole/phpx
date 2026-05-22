#pragma once

#include "phpx.h"
#include "phpx_literal_string.h"
#include "phpx_class.h"

namespace php {

Variant swoole_version();
Variant swoole_cpu_num();
Variant swoole_last_error();
Variant swoole_async_dns_lookup_coro(const Variant &domain_name, const Variant &timeout = 60, const Variant &type = 2);
Variant swoole_async_set(const Variant &settings);
template <typename... Args>
Variant swoole_coroutine_create(const Variant &func, const Args &...params) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2733]);
    }
    return call(fn, {func, params...});
}
Variant swoole_coroutine_defer(const Variant &callback);
Variant swoole_coroutine_socketpair(const Variant &domain, const Variant &type, const Variant &protocol);
Variant swoole_test_kernel_coroutine(const Variant &count = 100, const Variant &sleep_time = 1);
Variant swoole_client_select(const Reference &read,
                             const Reference &write,
                             const Reference &except,
                             const Variant &timeout = 0.5);
Variant swoole_select(const Reference &read,
                      const Reference &write,
                      const Reference &except,
                      const Variant &timeout = 0.5);
Variant swoole_set_process_name(const Variant &process_name);
Variant swoole_get_local_ip(const Variant &family = 2);
Variant swoole_get_local_mac();
Variant swoole_strerror(const Variant &errno, const Variant &error_type = 0);
Variant swoole_errno();
Variant swoole_clear_error();
Variant swoole_error_log(const Variant &level, const Variant &msg);
Variant swoole_error_log_ex(const Variant &level, const Variant &error, const Variant &msg);
Variant swoole_ignore_error(const Variant &error);
Variant swoole_hashcode(const Variant &data, const Variant &type = 0);
Variant swoole_mime_type_add(const Variant &suffix, const Variant &mime_type);
Variant swoole_mime_type_set(const Variant &suffix, const Variant &mime_type);
Variant swoole_mime_type_delete(const Variant &suffix);
Variant swoole_mime_type_get(const Variant &filename);
Variant swoole_get_mime_type(const Variant &filename);
Variant swoole_mime_type_exists(const Variant &filename);
Variant swoole_mime_type_list();
Variant swoole_clear_dns_cache();
Variant swoole_substr_unserialize(const Variant &str,
                                  const Variant &offset,
                                  const Variant &length = 0,
                                  const Variant &options = Array{});
Variant swoole_substr_json_decode(const Variant &str,
                                  const Variant &offset,
                                  const Variant &length = 0,
                                  const Variant &associative = false,
                                  const Variant &depth = 512,
                                  const Variant &flags = 0);
Variant swoole_internal_call_user_shutdown_begin();
Variant swoole_implicit_fn(const Variant &fn, const Variant &args = {});
Variant swoole_get_objects();
Variant swoole_get_vm_status();
Variant swoole_get_object_by_handle(const Variant &handle);
Variant swoole_name_resolver_lookup(const Variant &name, const Swoole_NameResolver_Context &ctx);
Variant swoole_name_resolver_lookup(const Variant &name, const Variant &ctx);
Variant swoole_name_resolver_add(const Variant &ns);
Variant swoole_name_resolver_remove(const Variant &ns);
template <typename... Args>
Variant swoole_call_array_method(const Args &...args) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2767]);
    }
    return call(fn, {args...});
}
template <typename... Args>
Variant swoole_call_string_method(const Args &...args) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2768]);
    }
    return call(fn, {args...});
}
template <typename... Args>
Variant swoole_call_stream_method(const Args &...args) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2769]);
    }
    return call(fn, {args...});
}
Variant swoole_array_search(const Variant &array, const Variant &value, const Variant &strict = false);
Variant swoole_array_contains(const Variant &array, const Variant &needle, const Variant &strict = false);
Variant swoole_array_join(const Variant &array, const Variant &separator);
Variant swoole_array_key_exists(const Variant &array, const Variant &key);
template <typename... Args>
Variant swoole_array_map(const Variant &array, const Variant &callback, const Args &...arrays) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2774]);
    }
    return call(fn, {array, callback, arrays...});
}
Variant swoole_str_split(const Variant &string, const Variant &delimiter, const Variant &limit = LONG_MAX);
Variant swoole_parse_str(const Variant &string);
Variant swoole_hash(const Variant &data,
                    const Variant &algo,
                    const Variant &binary = false,
                    const Variant &options = Array{});
Variant swoole_typed_array(const Variant &type_def, const Variant &init_array = {});
Variant swoole_array_is_typed(const Variant &array, const Variant &type_def = "");
Variant swoole_str_is_empty(const Variant &string);
Variant swoole_array_is_empty(const Variant &array);
Variant swoole_str_match(const Variant &string,
                         const Variant &pattern,
                         const Variant &flags = 0,
                         const Variant &offset = 0);
Variant swoole_str_match_all(const Variant &string,
                             const Variant &pattern,
                             const Variant &flags = 0,
                             const Variant &offset = 0);
Variant swoole_str_json_decode(const Variant &string, const Variant &depth = 512, const Variant &flags = 0);
Variant swoole_str_json_decode_to_object(const Variant &string, const Variant &depth = 512, const Variant &flags = 0);
Variant swoole_str_replace(const Variant &subject, const Variant &search, const Variant &replace);
Variant swoole_str_ireplace(const Variant &subject, const Variant &search, const Variant &replace);
Variant swoole_array_replace_str(const Variant &subjects, const Variant &search, const Variant &replace);
Variant swoole_array_ireplace_str(const Variant &subjects, const Variant &search, const Variant &replace);
Variant ssh2_connect(const Variant &host,
                     const Variant &port = 22,
                     const Variant &methods = {},
                     const Variant &callbacks = {});
Variant ssh2_disconnect(const Variant &session);
Variant ssh2_methods_negotiated(const Variant &session);
Variant ssh2_fingerprint(const Variant &session, const Variant &flags = 0);
Variant ssh2_auth_none(const Variant &session, const Variant &username);
Variant ssh2_auth_password(const Variant &session, const Variant &username, const Variant &password);
Variant ssh2_auth_pubkey_file(const Variant &session,
                              const Variant &username,
                              const Variant &pubkeyfile,
                              const Variant &privkeyfile,
                              const Variant &passphrase = {});
Variant ssh2_auth_pubkey(const Variant &session,
                         const Variant &username,
                         const Variant &pubkey,
                         const Variant &privkey,
                         const Variant &passphrase = {});
Variant ssh2_auth_hostbased_file(const Variant &session,
                                 const Variant &username,
                                 const Variant &hostname,
                                 const Variant &pubkeyfile,
                                 const Variant &privkeyfile,
                                 const Variant &passphrase = {},
                                 const Variant &local_username = {});
Variant ssh2_forward_listen(const Variant &session,
                            const Variant &port,
                            const Variant &host = "127.0.0.1",
                            const Variant &max_connections = 1);
Variant ssh2_forward_accept(const Variant &listener, const Reference &host = {}, const Reference &port = {});
Variant ssh2_shell(const Variant &session,
                   const Variant &termtype = "vanilla",
                   const Variant &env = {},
                   const Variant &width = 80,
                   const Variant &height = 25,
                   const Variant &width_height_type = 0);
Variant ssh2_shell_resize(const Variant &session, const Variant &width, const Variant &height);
Variant ssh2_exec(const Variant &session,
                  const Variant &command,
                  const Variant &pty = false,
                  const Variant &env = {},
                  const Variant &width = 80,
                  const Variant &height = 25,
                  const Variant &width_height_type = 0);
Variant ssh2_tunnel(const Variant &session, const Variant &host, const Variant &port);
Variant ssh2_scp_recv(const Variant &session, const Variant &remote_file, const Variant &local_file);
Variant ssh2_scp_send(const Variant &session,
                      const Variant &local_file,
                      const Variant &remote_file,
                      const Variant &create_mode = 420);
Variant ssh2_fetch_stream(const Variant &channel, const Variant &streamid);
Variant ssh2_send_eof(const Variant &channel);
Variant ssh2_sftp(const Variant &session);
Variant ssh2_sftp_rename(const Variant &sftp, const Variant &from, const Variant &to);
Variant ssh2_sftp_unlink(const Variant &sftp, const Variant &filename);
Variant ssh2_sftp_mkdir(const Variant &sftp,
                        const Variant &dirname,
                        const Variant &mode = 511,
                        const Variant &recursive = false);
Variant ssh2_sftp_rmdir(const Variant &sftp, const Variant &dirname);
Variant ssh2_sftp_chmod(const Variant &sftp, const Variant &filename, const Variant &mode);
Variant ssh2_sftp_stat(const Variant &sftp, const Variant &path);
Variant ssh2_sftp_lstat(const Variant &sftp, const Variant &path);
Variant ssh2_sftp_symlink(const Variant &sftp, const Variant &target, const Variant &link);
Variant ssh2_sftp_readlink(const Variant &sftp, const Variant &link);
Variant ssh2_sftp_realpath(const Variant &sftp, const Variant &filename);
Variant ssh2_publickey_init(const Variant &session);
Variant ssh2_publickey_add(const Variant &pkey,
                           const Variant &algoname,
                           const Variant &blob,
                           const Variant &overwrite = false,
                           const Variant &attributes = {});
Variant ssh2_publickey_remove(const Variant &pkey, const Variant &algoname, const Variant &blob);
Variant ssh2_publickey_list(const Variant &pkey);
Variant ssh2_auth_agent(const Variant &session, const Variant &username);
FTP_Connection ftp_connect(const Variant &hostname, const Variant &port = 21, const Variant &timeout = 90);
FTP_Connection ftp_ssl_connect(const Variant &hostname, const Variant &port = 21, const Variant &timeout = 90);
Variant ftp_login(const FTP_Connection &ftp, const Variant &username, const Variant &password);
Variant ftp_login(const Variant &ftp, const Variant &username, const Variant &password);
Variant ftp_pwd(const FTP_Connection &ftp);
Variant ftp_pwd(const Variant &ftp);
Variant ftp_cdup(const FTP_Connection &ftp);
Variant ftp_cdup(const Variant &ftp);
Variant ftp_chdir(const FTP_Connection &ftp, const Variant &directory);
Variant ftp_chdir(const Variant &ftp, const Variant &directory);
Variant ftp_exec(const FTP_Connection &ftp, const Variant &command);
Variant ftp_exec(const Variant &ftp, const Variant &command);
Variant ftp_raw(const FTP_Connection &ftp, const Variant &command);
Variant ftp_raw(const Variant &ftp, const Variant &command);
Variant ftp_mkdir(const FTP_Connection &ftp, const Variant &directory);
Variant ftp_mkdir(const Variant &ftp, const Variant &directory);
Variant ftp_rmdir(const FTP_Connection &ftp, const Variant &directory);
Variant ftp_rmdir(const Variant &ftp, const Variant &directory);
Variant ftp_chmod(const FTP_Connection &ftp, const Variant &permissions, const Variant &filename);
Variant ftp_chmod(const Variant &ftp, const Variant &permissions, const Variant &filename);
Variant ftp_alloc(const FTP_Connection &ftp, const Variant &size, const Reference &response = {});
Variant ftp_alloc(const Variant &ftp, const Variant &size, const Reference &response = {});
Variant ftp_nlist(const FTP_Connection &ftp, const Variant &directory);
Variant ftp_nlist(const Variant &ftp, const Variant &directory);
Variant ftp_rawlist(const FTP_Connection &ftp, const Variant &directory, const Variant &recursive = false);
Variant ftp_rawlist(const Variant &ftp, const Variant &directory, const Variant &recursive = false);
Variant ftp_mlsd(const FTP_Connection &ftp, const Variant &directory);
Variant ftp_mlsd(const Variant &ftp, const Variant &directory);
Variant ftp_systype(const FTP_Connection &ftp);
Variant ftp_systype(const Variant &ftp);
Variant ftp_fget(const FTP_Connection &ftp,
                 const Variant &stream,
                 const Variant &remote_filename,
                 const Variant &mode = 2,
                 const Variant &offset = 0);
Variant ftp_fget(const Variant &ftp,
                 const Variant &stream,
                 const Variant &remote_filename,
                 const Variant &mode = 2,
                 const Variant &offset = 0);
Variant ftp_nb_fget(const FTP_Connection &ftp,
                    const Variant &stream,
                    const Variant &remote_filename,
                    const Variant &mode = 2,
                    const Variant &offset = 0);
Variant ftp_nb_fget(const Variant &ftp,
                    const Variant &stream,
                    const Variant &remote_filename,
                    const Variant &mode = 2,
                    const Variant &offset = 0);
Variant ftp_pasv(const FTP_Connection &ftp, const Variant &enable);
Variant ftp_pasv(const Variant &ftp, const Variant &enable);
Variant ftp_get(const FTP_Connection &ftp,
                const Variant &local_filename,
                const Variant &remote_filename,
                const Variant &mode = 2,
                const Variant &offset = 0);
Variant ftp_get(const Variant &ftp,
                const Variant &local_filename,
                const Variant &remote_filename,
                const Variant &mode = 2,
                const Variant &offset = 0);
Variant ftp_nb_get(const FTP_Connection &ftp,
                   const Variant &local_filename,
                   const Variant &remote_filename,
                   const Variant &mode = 2,
                   const Variant &offset = 0);
Variant ftp_nb_get(const Variant &ftp,
                   const Variant &local_filename,
                   const Variant &remote_filename,
                   const Variant &mode = 2,
                   const Variant &offset = 0);
Variant ftp_nb_continue(const FTP_Connection &ftp);
Variant ftp_nb_continue(const Variant &ftp);
Variant ftp_fput(const FTP_Connection &ftp,
                 const Variant &remote_filename,
                 const Variant &stream,
                 const Variant &mode = 2,
                 const Variant &offset = 0);
Variant ftp_fput(const Variant &ftp,
                 const Variant &remote_filename,
                 const Variant &stream,
                 const Variant &mode = 2,
                 const Variant &offset = 0);
Variant ftp_nb_fput(const FTP_Connection &ftp,
                    const Variant &remote_filename,
                    const Variant &stream,
                    const Variant &mode = 2,
                    const Variant &offset = 0);
Variant ftp_nb_fput(const Variant &ftp,
                    const Variant &remote_filename,
                    const Variant &stream,
                    const Variant &mode = 2,
                    const Variant &offset = 0);
Variant ftp_put(const FTP_Connection &ftp,
                const Variant &remote_filename,
                const Variant &local_filename,
                const Variant &mode = 2,
                const Variant &offset = 0);
Variant ftp_put(const Variant &ftp,
                const Variant &remote_filename,
                const Variant &local_filename,
                const Variant &mode = 2,
                const Variant &offset = 0);
Variant ftp_append(const FTP_Connection &ftp,
                   const Variant &remote_filename,
                   const Variant &local_filename,
                   const Variant &mode = 2);
Variant ftp_append(const Variant &ftp,
                   const Variant &remote_filename,
                   const Variant &local_filename,
                   const Variant &mode = 2);
Variant ftp_nb_put(const FTP_Connection &ftp,
                   const Variant &remote_filename,
                   const Variant &local_filename,
                   const Variant &mode = 2,
                   const Variant &offset = 0);
Variant ftp_nb_put(const Variant &ftp,
                   const Variant &remote_filename,
                   const Variant &local_filename,
                   const Variant &mode = 2,
                   const Variant &offset = 0);
Variant ftp_size(const FTP_Connection &ftp, const Variant &filename);
Variant ftp_size(const Variant &ftp, const Variant &filename);
Variant ftp_mdtm(const FTP_Connection &ftp, const Variant &filename);
Variant ftp_mdtm(const Variant &ftp, const Variant &filename);
Variant ftp_rename(const FTP_Connection &ftp, const Variant &from, const Variant &to);
Variant ftp_rename(const Variant &ftp, const Variant &from, const Variant &to);
Variant ftp_delete(const FTP_Connection &ftp, const Variant &filename);
Variant ftp_delete(const Variant &ftp, const Variant &filename);
Variant ftp_site(const FTP_Connection &ftp, const Variant &command);
Variant ftp_site(const Variant &ftp, const Variant &command);
Variant ftp_close(const FTP_Connection &ftp);
Variant ftp_close(const Variant &ftp);
Variant ftp_quit(const FTP_Connection &ftp);
Variant ftp_quit(const Variant &ftp);
Variant ftp_set_option(const FTP_Connection &ftp, const Variant &option, const Variant &value);
Variant ftp_set_option(const Variant &ftp, const Variant &option, const Variant &value);
Variant ftp_get_option(const FTP_Connection &ftp, const Variant &option);
Variant ftp_get_option(const Variant &ftp, const Variant &option);
Variant swoole_tracer_leak_detect(const Variant &threshold = 64);
Variant swoole_tracer_prof_begin(const Variant &options = {});
Variant swoole_tracer_prof_end(const Variant &output_file);
Variant go(const Variant &func);
Variant defer(const Variant &callback);
Variant typed_array(const Variant &type_def, const Variant &init_array = {});
Variant swoole_event_add(const Variant &fd,
                         const Variant &read_callback = {},
                         const Variant &write_callback = {},
                         const Variant &events = 512);
Variant swoole_event_del(const Variant &fd);
Variant swoole_event_set(const Variant &fd,
                         const Variant &read_callback = {},
                         const Variant &write_callback = {},
                         const Variant &events = 0);
Variant swoole_event_wait();
Variant swoole_event_isset(const Variant &fd, const Variant &events = 1536);
Variant swoole_event_dispatch();
Variant swoole_event_defer(const Variant &callback);
Variant swoole_event_cycle(const Variant &callback, const Variant &before = false);
Variant swoole_event_write(const Variant &fd, const Variant &data);
Variant swoole_event_exit();
Variant swoole_event_rshutdown();
Variant swoole_timer_after(const Variant &ms, const Variant &callback);
Variant swoole_timer_tick(const Variant &ms, const Variant &callback);
Variant swoole_timer_info(const Variant &timer_id);
Variant swoole_timer_list();
Variant swoole_timer_exists(const Variant &timer_id);
Variant swoole_timer_stats();
Variant swoole_timer_clear(const Variant &timer_id);
Variant swoole_timer_clear_all();
Variant swoole_native_curl_close(const CurlHandle &handle);
Variant swoole_native_curl_close(const Variant &handle);
CurlHandle swoole_native_curl_copy_handle(const CurlHandle &handle);
Variant swoole_native_curl_copy_handle(const Variant &handle);
Variant swoole_native_curl_errno(const CurlHandle &handle);
Variant swoole_native_curl_errno(const Variant &handle);
Variant swoole_native_curl_error(const CurlHandle &handle);
Variant swoole_native_curl_error(const Variant &handle);
Variant swoole_native_curl_escape(const CurlHandle &handle, const Variant &string);
Variant swoole_native_curl_escape(const Variant &handle, const Variant &string);
Variant swoole_native_curl_unescape(const CurlHandle &handle, const Variant &string);
Variant swoole_native_curl_unescape(const Variant &handle, const Variant &string);
Variant swoole_native_curl_multi_setopt(const CurlMultiHandle &multi_handle,
                                        const Variant &option,
                                        const Variant &value);
Variant swoole_native_curl_multi_setopt(const Variant &multi_handle, const Variant &option, const Variant &value);
Variant swoole_native_curl_exec(const CurlHandle &handle);
Variant swoole_native_curl_exec(const Variant &handle);
Variant swoole_native_curl_getinfo(const CurlHandle &handle, const Variant &option = {});
Variant swoole_native_curl_getinfo(const Variant &handle, const Variant &option = {});
CurlHandle swoole_native_curl_init(const Variant &url = {});
Variant swoole_native_curl_upkeep(const CurlHandle &handle);
Variant swoole_native_curl_upkeep(const Variant &handle);
Variant swoole_native_curl_multi_add_handle(const CurlMultiHandle &multi_handle, const CurlHandle &handle);
Variant swoole_native_curl_multi_add_handle(const Variant &multi_handle, const Variant &handle);
Variant swoole_native_curl_multi_close(const CurlMultiHandle &multi_handle);
Variant swoole_native_curl_multi_close(const Variant &multi_handle);
Variant swoole_native_curl_multi_errno(const CurlMultiHandle &multi_handle);
Variant swoole_native_curl_multi_errno(const Variant &multi_handle);
Variant swoole_native_curl_multi_exec(const CurlMultiHandle &multi_handle, const Reference &still_running);
Variant swoole_native_curl_multi_exec(const Variant &multi_handle, const Reference &still_running);
Variant swoole_native_curl_multi_getcontent(const CurlHandle &handle);
Variant swoole_native_curl_multi_getcontent(const Variant &handle);
Variant swoole_native_curl_multi_info_read(const CurlMultiHandle &multi_handle, const Reference &queued_messages = {});
Variant swoole_native_curl_multi_info_read(const Variant &multi_handle, const Reference &queued_messages = {});
CurlMultiHandle swoole_native_curl_multi_init();
Variant swoole_native_curl_multi_remove_handle(const CurlMultiHandle &multi_handle, const CurlHandle &handle);
Variant swoole_native_curl_multi_remove_handle(const Variant &multi_handle, const Variant &handle);
Variant swoole_native_curl_multi_select(const CurlMultiHandle &multi_handle, const Variant &timeout = 1);
Variant swoole_native_curl_multi_select(const Variant &multi_handle, const Variant &timeout = 1);
Variant swoole_native_curl_pause(const CurlHandle &handle, const Variant &flags);
Variant swoole_native_curl_pause(const Variant &handle, const Variant &flags);
Variant swoole_native_curl_reset(const CurlHandle &handle);
Variant swoole_native_curl_reset(const Variant &handle);
Variant swoole_native_curl_setopt_array(const CurlHandle &handle, const Variant &options);
Variant swoole_native_curl_setopt_array(const Variant &handle, const Variant &options);
Variant swoole_native_curl_setopt(const CurlHandle &handle, const Variant &option, const Variant &value);
Variant swoole_native_curl_setopt(const Variant &handle, const Variant &option, const Variant &value);

}  // namespace php

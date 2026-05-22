#pragma once

#include "phpx.h"
#include "phpx_literal_string.h"
#include "phpx_class.h"

namespace php {

Variant mysqli_affected_rows(const mysqli &mysql);
Variant mysqli_affected_rows(const Variant &mysql);
Variant mysqli_autocommit(const mysqli &mysql, const Variant &enable);
Variant mysqli_autocommit(const Variant &mysql, const Variant &enable);
Variant mysqli_begin_transaction(const mysqli &mysql, const Variant &flags = 0, const Variant &name = nullptr);
Variant mysqli_begin_transaction(const Variant &mysql, const Variant &flags = 0, const Variant &name = nullptr);
Variant mysqli_change_user(const mysqli &mysql,
                           const Variant &username,
                           const Variant &password,
                           const Variant &database);
Variant mysqli_change_user(const Variant &mysql,
                           const Variant &username,
                           const Variant &password,
                           const Variant &database);
Variant mysqli_character_set_name(const mysqli &mysql);
Variant mysqli_character_set_name(const Variant &mysql);
Variant mysqli_close(const mysqli &mysql);
Variant mysqli_close(const Variant &mysql);
Variant mysqli_commit(const mysqli &mysql, const Variant &flags = 0, const Variant &name = nullptr);
Variant mysqli_commit(const Variant &mysql, const Variant &flags = 0, const Variant &name = nullptr);
Variant mysqli_connect(const Variant &hostname = nullptr,
                       const Variant &username = nullptr,
                       const Variant &password = nullptr,
                       const Variant &database = nullptr,
                       const Variant &port = nullptr,
                       const Variant &socket = nullptr);
Variant mysqli_connect_errno();
Variant mysqli_connect_error();
Variant mysqli_data_seek(const mysqli_result &result, const Variant &offset);
Variant mysqli_data_seek(const Variant &result, const Variant &offset);
Variant mysqli_dump_debug_info(const mysqli &mysql);
Variant mysqli_dump_debug_info(const Variant &mysql);
Variant mysqli_debug(const Variant &options);
Variant mysqli_errno(const mysqli &mysql);
Variant mysqli_errno(const Variant &mysql);
Variant mysqli_error(const mysqli &mysql);
Variant mysqli_error(const Variant &mysql);
Variant mysqli_error_list(const mysqli &mysql);
Variant mysqli_error_list(const Variant &mysql);
Variant mysqli_stmt_execute(const mysqli_stmt &statement, const Variant &params = nullptr);
Variant mysqli_stmt_execute(const Variant &statement, const Variant &params = nullptr);
Variant mysqli_execute(const mysqli_stmt &statement, const Variant &params = nullptr);
Variant mysqli_execute(const Variant &statement, const Variant &params = nullptr);
Variant mysqli_execute_query(const mysqli &mysql, const Variant &query, const Variant &params = nullptr);
Variant mysqli_execute_query(const Variant &mysql, const Variant &query, const Variant &params = nullptr);
Variant mysqli_fetch_field(const mysqli_result &result);
Variant mysqli_fetch_field(const Variant &result);
Variant mysqli_fetch_fields(const mysqli_result &result);
Variant mysqli_fetch_fields(const Variant &result);
Variant mysqli_fetch_field_direct(const mysqli_result &result, const Variant &index);
Variant mysqli_fetch_field_direct(const Variant &result, const Variant &index);
Variant mysqli_fetch_lengths(const mysqli_result &result);
Variant mysqli_fetch_lengths(const Variant &result);
Variant mysqli_fetch_all(const mysqli_result &result, const Variant &mode = 2);
Variant mysqli_fetch_all(const Variant &result, const Variant &mode = 2);
Variant mysqli_fetch_array(const mysqli_result &result, const Variant &mode = 3);
Variant mysqli_fetch_array(const Variant &result, const Variant &mode = 3);
Variant mysqli_fetch_assoc(const mysqli_result &result);
Variant mysqli_fetch_assoc(const Variant &result);
Variant mysqli_fetch_object(const mysqli_result &result,
                            const Variant &class_ = "stdClass",
                            const Variant &constructor_args = Array{});
Variant mysqli_fetch_object(const Variant &result,
                            const Variant &class_ = "stdClass",
                            const Variant &constructor_args = Array{});
Variant mysqli_fetch_row(const mysqli_result &result);
Variant mysqli_fetch_row(const Variant &result);
Variant mysqli_fetch_column(const mysqli_result &result, const Variant &column = 0);
Variant mysqli_fetch_column(const Variant &result, const Variant &column = 0);
Variant mysqli_field_count(const mysqli &mysql);
Variant mysqli_field_count(const Variant &mysql);
Variant mysqli_field_seek(const mysqli_result &result, const Variant &index);
Variant mysqli_field_seek(const Variant &result, const Variant &index);
Variant mysqli_field_tell(const mysqli_result &result);
Variant mysqli_field_tell(const Variant &result);
Variant mysqli_free_result(const mysqli_result &result);
Variant mysqli_free_result(const Variant &result);
Variant mysqli_get_connection_stats(const mysqli &mysql);
Variant mysqli_get_connection_stats(const Variant &mysql);
Variant mysqli_get_client_stats();
Variant mysqli_get_charset(const mysqli &mysql);
Variant mysqli_get_charset(const Variant &mysql);
Variant mysqli_get_client_info(const Variant &mysql = nullptr);
Variant mysqli_get_client_version();
Variant mysqli_get_links_stats();
Variant mysqli_get_host_info(const mysqli &mysql);
Variant mysqli_get_host_info(const Variant &mysql);
Variant mysqli_get_proto_info(const mysqli &mysql);
Variant mysqli_get_proto_info(const Variant &mysql);
Variant mysqli_get_server_info(const mysqli &mysql);
Variant mysqli_get_server_info(const Variant &mysql);
Variant mysqli_get_server_version(const mysqli &mysql);
Variant mysqli_get_server_version(const Variant &mysql);
Variant mysqli_get_warnings(const mysqli &mysql);
Variant mysqli_get_warnings(const Variant &mysql);
Variant mysqli_init();
Variant mysqli_info(const mysqli &mysql);
Variant mysqli_info(const Variant &mysql);
Variant mysqli_insert_id(const mysqli &mysql);
Variant mysqli_insert_id(const Variant &mysql);
Variant mysqli_kill(const mysqli &mysql, const Variant &process_id);
Variant mysqli_kill(const Variant &mysql, const Variant &process_id);
Variant mysqli_more_results(const mysqli &mysql);
Variant mysqli_more_results(const Variant &mysql);
Variant mysqli_multi_query(const mysqli &mysql, const Variant &query);
Variant mysqli_multi_query(const Variant &mysql, const Variant &query);
Variant mysqli_next_result(const mysqli &mysql);
Variant mysqli_next_result(const Variant &mysql);
Variant mysqli_num_fields(const mysqli_result &result);
Variant mysqli_num_fields(const Variant &result);
Variant mysqli_num_rows(const mysqli_result &result);
Variant mysqli_num_rows(const Variant &result);
Variant mysqli_options(const mysqli &mysql, const Variant &option, const Variant &value);
Variant mysqli_options(const Variant &mysql, const Variant &option, const Variant &value);
Variant mysqli_set_opt(const mysqli &mysql, const Variant &option, const Variant &value);
Variant mysqli_set_opt(const Variant &mysql, const Variant &option, const Variant &value);
Variant mysqli_ping(const mysqli &mysql);
Variant mysqli_ping(const Variant &mysql);
Variant mysqli_poll(const Reference &read,
                    const Reference &error,
                    const Reference &reject,
                    const Variant &seconds,
                    const Variant &microseconds = 0);
Variant mysqli_prepare(const mysqli &mysql, const Variant &query);
Variant mysqli_prepare(const Variant &mysql, const Variant &query);
Variant mysqli_report(const Variant &flags);
Variant mysqli_query(const mysqli &mysql, const Variant &query, const Variant &result_mode = 0);
Variant mysqli_query(const Variant &mysql, const Variant &query, const Variant &result_mode = 0);
Variant mysqli_real_connect(const mysqli &mysql,
                            const Variant &hostname = nullptr,
                            const Variant &username = nullptr,
                            const Variant &password = nullptr,
                            const Variant &database = nullptr,
                            const Variant &port = nullptr,
                            const Variant &socket = nullptr,
                            const Variant &flags = 0);
Variant mysqli_real_connect(const Variant &mysql,
                            const Variant &hostname = nullptr,
                            const Variant &username = nullptr,
                            const Variant &password = nullptr,
                            const Variant &database = nullptr,
                            const Variant &port = nullptr,
                            const Variant &socket = nullptr,
                            const Variant &flags = 0);
Variant mysqli_real_escape_string(const mysqli &mysql, const Variant &string);
Variant mysqli_real_escape_string(const Variant &mysql, const Variant &string);
Variant mysqli_escape_string(const mysqli &mysql, const Variant &string);
Variant mysqli_escape_string(const Variant &mysql, const Variant &string);
Variant mysqli_real_query(const mysqli &mysql, const Variant &query);
Variant mysqli_real_query(const Variant &mysql, const Variant &query);
Variant mysqli_reap_async_query(const mysqli &mysql);
Variant mysqli_reap_async_query(const Variant &mysql);
Variant mysqli_release_savepoint(const mysqli &mysql, const Variant &name);
Variant mysqli_release_savepoint(const Variant &mysql, const Variant &name);
Variant mysqli_rollback(const mysqli &mysql, const Variant &flags = 0, const Variant &name = nullptr);
Variant mysqli_rollback(const Variant &mysql, const Variant &flags = 0, const Variant &name = nullptr);
Variant mysqli_savepoint(const mysqli &mysql, const Variant &name);
Variant mysqli_savepoint(const Variant &mysql, const Variant &name);
Variant mysqli_select_db(const mysqli &mysql, const Variant &database);
Variant mysqli_select_db(const Variant &mysql, const Variant &database);
Variant mysqli_set_charset(const mysqli &mysql, const Variant &charset);
Variant mysqli_set_charset(const Variant &mysql, const Variant &charset);
Variant mysqli_stmt_affected_rows(const mysqli_stmt &statement);
Variant mysqli_stmt_affected_rows(const Variant &statement);
Variant mysqli_stmt_attr_get(const mysqli_stmt &statement, const Variant &attribute);
Variant mysqli_stmt_attr_get(const Variant &statement, const Variant &attribute);
Variant mysqli_stmt_attr_set(const mysqli_stmt &statement, const Variant &attribute, const Variant &value);
Variant mysqli_stmt_attr_set(const Variant &statement, const Variant &attribute, const Variant &value);
template <typename... Args>
Variant mysqli_stmt_bind_param(const mysqli_stmt &statement, const Variant &types, const Args &...vars) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[854]);
    }
    return call(fn, {statement.getObject(), types, vars...});
}
template <typename... Args>
Variant mysqli_stmt_bind_result(const mysqli_stmt &statement, const Args &...vars) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[855]);
    }
    return call(fn, {statement.getObject(), vars...});
}
Variant mysqli_stmt_close(const mysqli_stmt &statement);
Variant mysqli_stmt_close(const Variant &statement);
Variant mysqli_stmt_data_seek(const mysqli_stmt &statement, const Variant &offset);
Variant mysqli_stmt_data_seek(const Variant &statement, const Variant &offset);
Variant mysqli_stmt_errno(const mysqli_stmt &statement);
Variant mysqli_stmt_errno(const Variant &statement);
Variant mysqli_stmt_error(const mysqli_stmt &statement);
Variant mysqli_stmt_error(const Variant &statement);
Variant mysqli_stmt_error_list(const mysqli_stmt &statement);
Variant mysqli_stmt_error_list(const Variant &statement);
Variant mysqli_stmt_fetch(const mysqli_stmt &statement);
Variant mysqli_stmt_fetch(const Variant &statement);
Variant mysqli_stmt_field_count(const mysqli_stmt &statement);
Variant mysqli_stmt_field_count(const Variant &statement);
Variant mysqli_stmt_free_result(const mysqli_stmt &statement);
Variant mysqli_stmt_free_result(const Variant &statement);
Variant mysqli_stmt_get_result(const mysqli_stmt &statement);
Variant mysqli_stmt_get_result(const Variant &statement);
Variant mysqli_stmt_get_warnings(const mysqli_stmt &statement);
Variant mysqli_stmt_get_warnings(const Variant &statement);
Variant mysqli_stmt_init(const mysqli &mysql);
Variant mysqli_stmt_init(const Variant &mysql);
Variant mysqli_stmt_insert_id(const mysqli_stmt &statement);
Variant mysqli_stmt_insert_id(const Variant &statement);
Variant mysqli_stmt_more_results(const mysqli_stmt &statement);
Variant mysqli_stmt_more_results(const Variant &statement);
Variant mysqli_stmt_next_result(const mysqli_stmt &statement);
Variant mysqli_stmt_next_result(const Variant &statement);
Variant mysqli_stmt_num_rows(const mysqli_stmt &statement);
Variant mysqli_stmt_num_rows(const Variant &statement);
Variant mysqli_stmt_param_count(const mysqli_stmt &statement);
Variant mysqli_stmt_param_count(const Variant &statement);
Variant mysqli_stmt_prepare(const mysqli_stmt &statement, const Variant &query);
Variant mysqli_stmt_prepare(const Variant &statement, const Variant &query);
Variant mysqli_stmt_reset(const mysqli_stmt &statement);
Variant mysqli_stmt_reset(const Variant &statement);
Variant mysqli_stmt_result_metadata(const mysqli_stmt &statement);
Variant mysqli_stmt_result_metadata(const Variant &statement);
Variant mysqli_stmt_send_long_data(const mysqli_stmt &statement, const Variant &param_num, const Variant &data);
Variant mysqli_stmt_send_long_data(const Variant &statement, const Variant &param_num, const Variant &data);
Variant mysqli_stmt_store_result(const mysqli_stmt &statement);
Variant mysqli_stmt_store_result(const Variant &statement);
Variant mysqli_stmt_sqlstate(const mysqli_stmt &statement);
Variant mysqli_stmt_sqlstate(const Variant &statement);
Variant mysqli_sqlstate(const mysqli &mysql);
Variant mysqli_sqlstate(const Variant &mysql);
Variant mysqli_ssl_set(const mysqli &mysql,
                       const Variant &key,
                       const Variant &certificate,
                       const Variant &ca_certificate,
                       const Variant &ca_path,
                       const Variant &cipher_algos);
Variant mysqli_ssl_set(const Variant &mysql,
                       const Variant &key,
                       const Variant &certificate,
                       const Variant &ca_certificate,
                       const Variant &ca_path,
                       const Variant &cipher_algos);
Variant mysqli_stat(const mysqli &mysql);
Variant mysqli_stat(const Variant &mysql);
Variant mysqli_store_result(const mysqli &mysql, const Variant &mode = 0);
Variant mysqli_store_result(const Variant &mysql, const Variant &mode = 0);
Variant mysqli_thread_id(const mysqli &mysql);
Variant mysqli_thread_id(const Variant &mysql);
Variant mysqli_thread_safe();
Variant mysqli_use_result(const mysqli &mysql);
Variant mysqli_use_result(const Variant &mysql);
Variant mysqli_warning_count(const mysqli &mysql);
Variant mysqli_warning_count(const Variant &mysql);
Variant mysqli_refresh(const mysqli &mysql, const Variant &flags);
Variant mysqli_refresh(const Variant &mysql, const Variant &flags);

}  // namespace php

#include "phpx.h"
#include "phpx_literal_string.h"
#include "phpx_class.h"

namespace php {
Variant mysqli_affected_rows(const mysqli &mysql) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[781]);
    }
    return call(_fn, {mysql.getObject()});
}
Variant mysqli_affected_rows(const Variant &mysql) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[781]);
    }
    return call(_fn, {mysql});
}
Variant mysqli_autocommit(const mysqli &mysql, const Variant &enable) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[782]);
    }
    return call(_fn, {mysql.getObject(), enable});
}
Variant mysqli_autocommit(const Variant &mysql, const Variant &enable) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[782]);
    }
    return call(_fn, {mysql, enable});
}
Variant mysqli_begin_transaction(const mysqli &mysql, const Variant &flags, const Variant &name) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[783]);
    }
    return call(_fn, {mysql.getObject(), flags, name});
}
Variant mysqli_begin_transaction(const Variant &mysql, const Variant &flags, const Variant &name) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[783]);
    }
    return call(_fn, {mysql, flags, name});
}
Variant mysqli_change_user(const mysqli &mysql,
                           const Variant &username,
                           const Variant &password,
                           const Variant &database) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[784]);
    }
    return call(_fn, {mysql.getObject(), username, password, database});
}
Variant mysqli_change_user(const Variant &mysql,
                           const Variant &username,
                           const Variant &password,
                           const Variant &database) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[784]);
    }
    return call(_fn, {mysql, username, password, database});
}
Variant mysqli_character_set_name(const mysqli &mysql) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[785]);
    }
    return call(_fn, {mysql.getObject()});
}
Variant mysqli_character_set_name(const Variant &mysql) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[785]);
    }
    return call(_fn, {mysql});
}
Variant mysqli_close(const mysqli &mysql) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[786]);
    }
    return call(_fn, {mysql.getObject()});
}
Variant mysqli_close(const Variant &mysql) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[786]);
    }
    return call(_fn, {mysql});
}
Variant mysqli_commit(const mysqli &mysql, const Variant &flags, const Variant &name) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[787]);
    }
    return call(_fn, {mysql.getObject(), flags, name});
}
Variant mysqli_commit(const Variant &mysql, const Variant &flags, const Variant &name) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[787]);
    }
    return call(_fn, {mysql, flags, name});
}
Variant mysqli_connect(const Variant &hostname,
                       const Variant &username,
                       const Variant &password,
                       const Variant &database,
                       const Variant &port,
                       const Variant &socket) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[788]);
    }
    return call(_fn, {hostname, username, password, database, port, socket});
}
Variant mysqli_connect_errno() {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[789]);
    }
    return call(_fn, {});
}
Variant mysqli_connect_error() {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[790]);
    }
    return call(_fn, {});
}
Variant mysqli_data_seek(const mysqli_result &result, const Variant &offset) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[791]);
    }
    return call(_fn, {result.getObject(), offset});
}
Variant mysqli_data_seek(const Variant &result, const Variant &offset) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[791]);
    }
    return call(_fn, {result, offset});
}
Variant mysqli_dump_debug_info(const mysqli &mysql) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[792]);
    }
    return call(_fn, {mysql.getObject()});
}
Variant mysqli_dump_debug_info(const Variant &mysql) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[792]);
    }
    return call(_fn, {mysql});
}
Variant mysqli_debug(const Variant &options) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[793]);
    }
    return call(_fn, {options});
}
Variant mysqli_errno(const mysqli &mysql) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[794]);
    }
    return call(_fn, {mysql.getObject()});
}
Variant mysqli_errno(const Variant &mysql) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[794]);
    }
    return call(_fn, {mysql});
}
Variant mysqli_error(const mysqli &mysql) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[795]);
    }
    return call(_fn, {mysql.getObject()});
}
Variant mysqli_error(const Variant &mysql) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[795]);
    }
    return call(_fn, {mysql});
}
Variant mysqli_error_list(const mysqli &mysql) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[796]);
    }
    return call(_fn, {mysql.getObject()});
}
Variant mysqli_error_list(const Variant &mysql) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[796]);
    }
    return call(_fn, {mysql});
}
Variant mysqli_stmt_execute(const mysqli_stmt &statement, const Variant &params) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[797]);
    }
    return call(_fn, {statement.getObject(), params});
}
Variant mysqli_stmt_execute(const Variant &statement, const Variant &params) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[797]);
    }
    return call(_fn, {statement, params});
}
Variant mysqli_execute(const mysqli_stmt &statement, const Variant &params) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[798]);
    }
    return call(_fn, {statement.getObject(), params});
}
Variant mysqli_execute(const Variant &statement, const Variant &params) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[798]);
    }
    return call(_fn, {statement, params});
}
Variant mysqli_execute_query(const mysqli &mysql, const Variant &query, const Variant &params) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[799]);
    }
    return call(_fn, {mysql.getObject(), query, params});
}
Variant mysqli_execute_query(const Variant &mysql, const Variant &query, const Variant &params) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[799]);
    }
    return call(_fn, {mysql, query, params});
}
Variant mysqli_fetch_field(const mysqli_result &result) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[800]);
    }
    return call(_fn, {result.getObject()});
}
Variant mysqli_fetch_field(const Variant &result) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[800]);
    }
    return call(_fn, {result});
}
Variant mysqli_fetch_fields(const mysqli_result &result) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[801]);
    }
    return call(_fn, {result.getObject()});
}
Variant mysqli_fetch_fields(const Variant &result) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[801]);
    }
    return call(_fn, {result});
}
Variant mysqli_fetch_field_direct(const mysqli_result &result, const Variant &index) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[802]);
    }
    return call(_fn, {result.getObject(), index});
}
Variant mysqli_fetch_field_direct(const Variant &result, const Variant &index) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[802]);
    }
    return call(_fn, {result, index});
}
Variant mysqli_fetch_lengths(const mysqli_result &result) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[803]);
    }
    return call(_fn, {result.getObject()});
}
Variant mysqli_fetch_lengths(const Variant &result) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[803]);
    }
    return call(_fn, {result});
}
Variant mysqli_fetch_all(const mysqli_result &result, const Variant &mode) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[804]);
    }
    return call(_fn, {result.getObject(), mode});
}
Variant mysqli_fetch_all(const Variant &result, const Variant &mode) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[804]);
    }
    return call(_fn, {result, mode});
}
Variant mysqli_fetch_array(const mysqli_result &result, const Variant &mode) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[805]);
    }
    return call(_fn, {result.getObject(), mode});
}
Variant mysqli_fetch_array(const Variant &result, const Variant &mode) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[805]);
    }
    return call(_fn, {result, mode});
}
Variant mysqli_fetch_assoc(const mysqli_result &result) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[806]);
    }
    return call(_fn, {result.getObject()});
}
Variant mysqli_fetch_assoc(const Variant &result) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[806]);
    }
    return call(_fn, {result});
}
Variant mysqli_fetch_object(const mysqli_result &result, const Variant &class_, const Variant &constructor_args) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[807]);
    }
    return call(_fn, {result.getObject(), class_, constructor_args});
}
Variant mysqli_fetch_object(const Variant &result, const Variant &class_, const Variant &constructor_args) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[807]);
    }
    return call(_fn, {result, class_, constructor_args});
}
Variant mysqli_fetch_row(const mysqli_result &result) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[808]);
    }
    return call(_fn, {result.getObject()});
}
Variant mysqli_fetch_row(const Variant &result) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[808]);
    }
    return call(_fn, {result});
}
Variant mysqli_fetch_column(const mysqli_result &result, const Variant &column) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[809]);
    }
    return call(_fn, {result.getObject(), column});
}
Variant mysqli_fetch_column(const Variant &result, const Variant &column) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[809]);
    }
    return call(_fn, {result, column});
}
Variant mysqli_field_count(const mysqli &mysql) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[810]);
    }
    return call(_fn, {mysql.getObject()});
}
Variant mysqli_field_count(const Variant &mysql) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[810]);
    }
    return call(_fn, {mysql});
}
Variant mysqli_field_seek(const mysqli_result &result, const Variant &index) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[811]);
    }
    return call(_fn, {result.getObject(), index});
}
Variant mysqli_field_seek(const Variant &result, const Variant &index) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[811]);
    }
    return call(_fn, {result, index});
}
Variant mysqli_field_tell(const mysqli_result &result) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[812]);
    }
    return call(_fn, {result.getObject()});
}
Variant mysqli_field_tell(const Variant &result) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[812]);
    }
    return call(_fn, {result});
}
Variant mysqli_free_result(const mysqli_result &result) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[813]);
    }
    return call(_fn, {result.getObject()});
}
Variant mysqli_free_result(const Variant &result) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[813]);
    }
    return call(_fn, {result});
}
Variant mysqli_get_connection_stats(const mysqli &mysql) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[814]);
    }
    return call(_fn, {mysql.getObject()});
}
Variant mysqli_get_connection_stats(const Variant &mysql) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[814]);
    }
    return call(_fn, {mysql});
}
Variant mysqli_get_client_stats() {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[815]);
    }
    return call(_fn, {});
}
Variant mysqli_get_charset(const mysqli &mysql) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[816]);
    }
    return call(_fn, {mysql.getObject()});
}
Variant mysqli_get_charset(const Variant &mysql) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[816]);
    }
    return call(_fn, {mysql});
}
Variant mysqli_get_client_info(const Variant &mysql) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[817]);
    }
    return call(_fn, {mysql});
}
Variant mysqli_get_client_version() {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[818]);
    }
    return call(_fn, {});
}
Variant mysqli_get_links_stats() {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[819]);
    }
    return call(_fn, {});
}
Variant mysqli_get_host_info(const mysqli &mysql) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[820]);
    }
    return call(_fn, {mysql.getObject()});
}
Variant mysqli_get_host_info(const Variant &mysql) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[820]);
    }
    return call(_fn, {mysql});
}
Variant mysqli_get_proto_info(const mysqli &mysql) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[821]);
    }
    return call(_fn, {mysql.getObject()});
}
Variant mysqli_get_proto_info(const Variant &mysql) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[821]);
    }
    return call(_fn, {mysql});
}
Variant mysqli_get_server_info(const mysqli &mysql) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[822]);
    }
    return call(_fn, {mysql.getObject()});
}
Variant mysqli_get_server_info(const Variant &mysql) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[822]);
    }
    return call(_fn, {mysql});
}
Variant mysqli_get_server_version(const mysqli &mysql) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[823]);
    }
    return call(_fn, {mysql.getObject()});
}
Variant mysqli_get_server_version(const Variant &mysql) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[823]);
    }
    return call(_fn, {mysql});
}
Variant mysqli_get_warnings(const mysqli &mysql) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[824]);
    }
    return call(_fn, {mysql.getObject()});
}
Variant mysqli_get_warnings(const Variant &mysql) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[824]);
    }
    return call(_fn, {mysql});
}
Variant mysqli_init() {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[825]);
    }
    return call(_fn, {});
}
Variant mysqli_info(const mysqli &mysql) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[826]);
    }
    return call(_fn, {mysql.getObject()});
}
Variant mysqli_info(const Variant &mysql) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[826]);
    }
    return call(_fn, {mysql});
}
Variant mysqli_insert_id(const mysqli &mysql) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[827]);
    }
    return call(_fn, {mysql.getObject()});
}
Variant mysqli_insert_id(const Variant &mysql) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[827]);
    }
    return call(_fn, {mysql});
}
Variant mysqli_kill(const mysqli &mysql, const Variant &process_id) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[828]);
    }
    return call(_fn, {mysql.getObject(), process_id});
}
Variant mysqli_kill(const Variant &mysql, const Variant &process_id) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[828]);
    }
    return call(_fn, {mysql, process_id});
}
Variant mysqli_more_results(const mysqli &mysql) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[829]);
    }
    return call(_fn, {mysql.getObject()});
}
Variant mysqli_more_results(const Variant &mysql) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[829]);
    }
    return call(_fn, {mysql});
}
Variant mysqli_multi_query(const mysqli &mysql, const Variant &query) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[830]);
    }
    return call(_fn, {mysql.getObject(), query});
}
Variant mysqli_multi_query(const Variant &mysql, const Variant &query) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[830]);
    }
    return call(_fn, {mysql, query});
}
Variant mysqli_next_result(const mysqli &mysql) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[831]);
    }
    return call(_fn, {mysql.getObject()});
}
Variant mysqli_next_result(const Variant &mysql) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[831]);
    }
    return call(_fn, {mysql});
}
Variant mysqli_num_fields(const mysqli_result &result) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[832]);
    }
    return call(_fn, {result.getObject()});
}
Variant mysqli_num_fields(const Variant &result) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[832]);
    }
    return call(_fn, {result});
}
Variant mysqli_num_rows(const mysqli_result &result) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[833]);
    }
    return call(_fn, {result.getObject()});
}
Variant mysqli_num_rows(const Variant &result) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[833]);
    }
    return call(_fn, {result});
}
Variant mysqli_options(const mysqli &mysql, const Variant &option, const Variant &value) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[834]);
    }
    return call(_fn, {mysql.getObject(), option, value});
}
Variant mysqli_options(const Variant &mysql, const Variant &option, const Variant &value) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[834]);
    }
    return call(_fn, {mysql, option, value});
}
Variant mysqli_set_opt(const mysqli &mysql, const Variant &option, const Variant &value) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[835]);
    }
    return call(_fn, {mysql.getObject(), option, value});
}
Variant mysqli_set_opt(const Variant &mysql, const Variant &option, const Variant &value) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[835]);
    }
    return call(_fn, {mysql, option, value});
}
Variant mysqli_ping(const mysqli &mysql) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[836]);
    }
    return call(_fn, {mysql.getObject()});
}
Variant mysqli_ping(const Variant &mysql) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[836]);
    }
    return call(_fn, {mysql});
}
Variant mysqli_poll(const Reference &read,
                    const Reference &error,
                    const Reference &reject,
                    const Variant &seconds,
                    const Variant &microseconds) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[837]);
    }
    return call(_fn, {&read, &error, &reject, seconds, microseconds});
}
Variant mysqli_prepare(const mysqli &mysql, const Variant &query) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[838]);
    }
    return call(_fn, {mysql.getObject(), query});
}
Variant mysqli_prepare(const Variant &mysql, const Variant &query) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[838]);
    }
    return call(_fn, {mysql, query});
}
Variant mysqli_report(const Variant &flags) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[839]);
    }
    return call(_fn, {flags});
}
Variant mysqli_query(const mysqli &mysql, const Variant &query, const Variant &result_mode) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[840]);
    }
    return call(_fn, {mysql.getObject(), query, result_mode});
}
Variant mysqli_query(const Variant &mysql, const Variant &query, const Variant &result_mode) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[840]);
    }
    return call(_fn, {mysql, query, result_mode});
}
Variant mysqli_real_connect(const mysqli &mysql,
                            const Variant &hostname,
                            const Variant &username,
                            const Variant &password,
                            const Variant &database,
                            const Variant &port,
                            const Variant &socket,
                            const Variant &flags) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[841]);
    }
    return call(_fn, {mysql.getObject(), hostname, username, password, database, port, socket, flags});
}
Variant mysqli_real_connect(const Variant &mysql,
                            const Variant &hostname,
                            const Variant &username,
                            const Variant &password,
                            const Variant &database,
                            const Variant &port,
                            const Variant &socket,
                            const Variant &flags) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[841]);
    }
    return call(_fn, {mysql, hostname, username, password, database, port, socket, flags});
}
Variant mysqli_real_escape_string(const mysqli &mysql, const Variant &string) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[842]);
    }
    return call(_fn, {mysql.getObject(), string});
}
Variant mysqli_real_escape_string(const Variant &mysql, const Variant &string) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[842]);
    }
    return call(_fn, {mysql, string});
}
Variant mysqli_escape_string(const mysqli &mysql, const Variant &string) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[843]);
    }
    return call(_fn, {mysql.getObject(), string});
}
Variant mysqli_escape_string(const Variant &mysql, const Variant &string) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[843]);
    }
    return call(_fn, {mysql, string});
}
Variant mysqli_real_query(const mysqli &mysql, const Variant &query) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[844]);
    }
    return call(_fn, {mysql.getObject(), query});
}
Variant mysqli_real_query(const Variant &mysql, const Variant &query) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[844]);
    }
    return call(_fn, {mysql, query});
}
Variant mysqli_reap_async_query(const mysqli &mysql) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[845]);
    }
    return call(_fn, {mysql.getObject()});
}
Variant mysqli_reap_async_query(const Variant &mysql) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[845]);
    }
    return call(_fn, {mysql});
}
Variant mysqli_release_savepoint(const mysqli &mysql, const Variant &name) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[846]);
    }
    return call(_fn, {mysql.getObject(), name});
}
Variant mysqli_release_savepoint(const Variant &mysql, const Variant &name) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[846]);
    }
    return call(_fn, {mysql, name});
}
Variant mysqli_rollback(const mysqli &mysql, const Variant &flags, const Variant &name) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[847]);
    }
    return call(_fn, {mysql.getObject(), flags, name});
}
Variant mysqli_rollback(const Variant &mysql, const Variant &flags, const Variant &name) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[847]);
    }
    return call(_fn, {mysql, flags, name});
}
Variant mysqli_savepoint(const mysqli &mysql, const Variant &name) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[848]);
    }
    return call(_fn, {mysql.getObject(), name});
}
Variant mysqli_savepoint(const Variant &mysql, const Variant &name) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[848]);
    }
    return call(_fn, {mysql, name});
}
Variant mysqli_select_db(const mysqli &mysql, const Variant &database) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[849]);
    }
    return call(_fn, {mysql.getObject(), database});
}
Variant mysqli_select_db(const Variant &mysql, const Variant &database) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[849]);
    }
    return call(_fn, {mysql, database});
}
Variant mysqli_set_charset(const mysqli &mysql, const Variant &charset) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[850]);
    }
    return call(_fn, {mysql.getObject(), charset});
}
Variant mysqli_set_charset(const Variant &mysql, const Variant &charset) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[850]);
    }
    return call(_fn, {mysql, charset});
}
Variant mysqli_stmt_affected_rows(const mysqli_stmt &statement) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[851]);
    }
    return call(_fn, {statement.getObject()});
}
Variant mysqli_stmt_affected_rows(const Variant &statement) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[851]);
    }
    return call(_fn, {statement});
}
Variant mysqli_stmt_attr_get(const mysqli_stmt &statement, const Variant &attribute) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[852]);
    }
    return call(_fn, {statement.getObject(), attribute});
}
Variant mysqli_stmt_attr_get(const Variant &statement, const Variant &attribute) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[852]);
    }
    return call(_fn, {statement, attribute});
}
Variant mysqli_stmt_attr_set(const mysqli_stmt &statement, const Variant &attribute, const Variant &value) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[853]);
    }
    return call(_fn, {statement.getObject(), attribute, value});
}
Variant mysqli_stmt_attr_set(const Variant &statement, const Variant &attribute, const Variant &value) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[853]);
    }
    return call(_fn, {statement, attribute, value});
}
Variant mysqli_stmt_close(const mysqli_stmt &statement) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[856]);
    }
    return call(_fn, {statement.getObject()});
}
Variant mysqli_stmt_close(const Variant &statement) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[856]);
    }
    return call(_fn, {statement});
}
Variant mysqli_stmt_data_seek(const mysqli_stmt &statement, const Variant &offset) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[857]);
    }
    return call(_fn, {statement.getObject(), offset});
}
Variant mysqli_stmt_data_seek(const Variant &statement, const Variant &offset) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[857]);
    }
    return call(_fn, {statement, offset});
}
Variant mysqli_stmt_errno(const mysqli_stmt &statement) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[858]);
    }
    return call(_fn, {statement.getObject()});
}
Variant mysqli_stmt_errno(const Variant &statement) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[858]);
    }
    return call(_fn, {statement});
}
Variant mysqli_stmt_error(const mysqli_stmt &statement) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[859]);
    }
    return call(_fn, {statement.getObject()});
}
Variant mysqli_stmt_error(const Variant &statement) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[859]);
    }
    return call(_fn, {statement});
}
Variant mysqli_stmt_error_list(const mysqli_stmt &statement) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[860]);
    }
    return call(_fn, {statement.getObject()});
}
Variant mysqli_stmt_error_list(const Variant &statement) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[860]);
    }
    return call(_fn, {statement});
}
Variant mysqli_stmt_fetch(const mysqli_stmt &statement) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[861]);
    }
    return call(_fn, {statement.getObject()});
}
Variant mysqli_stmt_fetch(const Variant &statement) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[861]);
    }
    return call(_fn, {statement});
}
Variant mysqli_stmt_field_count(const mysqli_stmt &statement) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[862]);
    }
    return call(_fn, {statement.getObject()});
}
Variant mysqli_stmt_field_count(const Variant &statement) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[862]);
    }
    return call(_fn, {statement});
}
Variant mysqli_stmt_free_result(const mysqli_stmt &statement) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[863]);
    }
    return call(_fn, {statement.getObject()});
}
Variant mysqli_stmt_free_result(const Variant &statement) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[863]);
    }
    return call(_fn, {statement});
}
Variant mysqli_stmt_get_result(const mysqli_stmt &statement) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[864]);
    }
    return call(_fn, {statement.getObject()});
}
Variant mysqli_stmt_get_result(const Variant &statement) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[864]);
    }
    return call(_fn, {statement});
}
Variant mysqli_stmt_get_warnings(const mysqli_stmt &statement) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[865]);
    }
    return call(_fn, {statement.getObject()});
}
Variant mysqli_stmt_get_warnings(const Variant &statement) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[865]);
    }
    return call(_fn, {statement});
}
Variant mysqli_stmt_init(const mysqli &mysql) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[866]);
    }
    return call(_fn, {mysql.getObject()});
}
Variant mysqli_stmt_init(const Variant &mysql) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[866]);
    }
    return call(_fn, {mysql});
}
Variant mysqli_stmt_insert_id(const mysqli_stmt &statement) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[867]);
    }
    return call(_fn, {statement.getObject()});
}
Variant mysqli_stmt_insert_id(const Variant &statement) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[867]);
    }
    return call(_fn, {statement});
}
Variant mysqli_stmt_more_results(const mysqli_stmt &statement) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[868]);
    }
    return call(_fn, {statement.getObject()});
}
Variant mysqli_stmt_more_results(const Variant &statement) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[868]);
    }
    return call(_fn, {statement});
}
Variant mysqli_stmt_next_result(const mysqli_stmt &statement) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[869]);
    }
    return call(_fn, {statement.getObject()});
}
Variant mysqli_stmt_next_result(const Variant &statement) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[869]);
    }
    return call(_fn, {statement});
}
Variant mysqli_stmt_num_rows(const mysqli_stmt &statement) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[870]);
    }
    return call(_fn, {statement.getObject()});
}
Variant mysqli_stmt_num_rows(const Variant &statement) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[870]);
    }
    return call(_fn, {statement});
}
Variant mysqli_stmt_param_count(const mysqli_stmt &statement) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[871]);
    }
    return call(_fn, {statement.getObject()});
}
Variant mysqli_stmt_param_count(const Variant &statement) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[871]);
    }
    return call(_fn, {statement});
}
Variant mysqli_stmt_prepare(const mysqli_stmt &statement, const Variant &query) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[872]);
    }
    return call(_fn, {statement.getObject(), query});
}
Variant mysqli_stmt_prepare(const Variant &statement, const Variant &query) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[872]);
    }
    return call(_fn, {statement, query});
}
Variant mysqli_stmt_reset(const mysqli_stmt &statement) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[873]);
    }
    return call(_fn, {statement.getObject()});
}
Variant mysqli_stmt_reset(const Variant &statement) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[873]);
    }
    return call(_fn, {statement});
}
Variant mysqli_stmt_result_metadata(const mysqli_stmt &statement) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[874]);
    }
    return call(_fn, {statement.getObject()});
}
Variant mysqli_stmt_result_metadata(const Variant &statement) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[874]);
    }
    return call(_fn, {statement});
}
Variant mysqli_stmt_send_long_data(const mysqli_stmt &statement, const Variant &param_num, const Variant &data) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[875]);
    }
    return call(_fn, {statement.getObject(), param_num, data});
}
Variant mysqli_stmt_send_long_data(const Variant &statement, const Variant &param_num, const Variant &data) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[875]);
    }
    return call(_fn, {statement, param_num, data});
}
Variant mysqli_stmt_store_result(const mysqli_stmt &statement) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[876]);
    }
    return call(_fn, {statement.getObject()});
}
Variant mysqli_stmt_store_result(const Variant &statement) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[876]);
    }
    return call(_fn, {statement});
}
Variant mysqli_stmt_sqlstate(const mysqli_stmt &statement) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[877]);
    }
    return call(_fn, {statement.getObject()});
}
Variant mysqli_stmt_sqlstate(const Variant &statement) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[877]);
    }
    return call(_fn, {statement});
}
Variant mysqli_sqlstate(const mysqli &mysql) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[878]);
    }
    return call(_fn, {mysql.getObject()});
}
Variant mysqli_sqlstate(const Variant &mysql) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[878]);
    }
    return call(_fn, {mysql});
}
Variant mysqli_ssl_set(const mysqli &mysql,
                       const Variant &key,
                       const Variant &certificate,
                       const Variant &ca_certificate,
                       const Variant &ca_path,
                       const Variant &cipher_algos) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[879]);
    }
    return call(_fn, {mysql.getObject(), key, certificate, ca_certificate, ca_path, cipher_algos});
}
Variant mysqli_ssl_set(const Variant &mysql,
                       const Variant &key,
                       const Variant &certificate,
                       const Variant &ca_certificate,
                       const Variant &ca_path,
                       const Variant &cipher_algos) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[879]);
    }
    return call(_fn, {mysql, key, certificate, ca_certificate, ca_path, cipher_algos});
}
Variant mysqli_stat(const mysqli &mysql) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[880]);
    }
    return call(_fn, {mysql.getObject()});
}
Variant mysqli_stat(const Variant &mysql) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[880]);
    }
    return call(_fn, {mysql});
}
Variant mysqli_store_result(const mysqli &mysql, const Variant &mode) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[881]);
    }
    return call(_fn, {mysql.getObject(), mode});
}
Variant mysqli_store_result(const Variant &mysql, const Variant &mode) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[881]);
    }
    return call(_fn, {mysql, mode});
}
Variant mysqli_thread_id(const mysqli &mysql) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[882]);
    }
    return call(_fn, {mysql.getObject()});
}
Variant mysqli_thread_id(const Variant &mysql) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[882]);
    }
    return call(_fn, {mysql});
}
Variant mysqli_thread_safe() {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[883]);
    }
    return call(_fn, {});
}
Variant mysqli_use_result(const mysqli &mysql) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[884]);
    }
    return call(_fn, {mysql.getObject()});
}
Variant mysqli_use_result(const Variant &mysql) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[884]);
    }
    return call(_fn, {mysql});
}
Variant mysqli_warning_count(const mysqli &mysql) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[885]);
    }
    return call(_fn, {mysql.getObject()});
}
Variant mysqli_warning_count(const Variant &mysql) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[885]);
    }
    return call(_fn, {mysql});
}
Variant mysqli_refresh(const mysqli &mysql, const Variant &flags) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[886]);
    }
    return call(_fn, {mysql.getObject(), flags});
}
Variant mysqli_refresh(const Variant &mysql, const Variant &flags) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[886]);
    }
    return call(_fn, {mysql, flags});
}
}  // namespace php

#include "phpx.h"
#include "phpx_class.h"
#include "class/mysqli.h"

namespace php {
Variant mysqli_sql_exception::getSqlState() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[849]);
    }
    return this_.call(_method_fn, {});
}
mysqli_sql_exception::mysqli_sql_exception(const Variant &message, const Variant &code, const Variant &previous) {
    this_ = newObject(LITERAL_STRING[850], {message, code, previous});
}
mysqli_driver::mysqli_driver() {
    this_ = newObject(LITERAL_STRING[851]);
}
Variant mysqli_warning::next() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[92]);
    }
    return this_.call(_method_fn, {});
}
mysqli_result::mysqli_result(const mysqli &mysql, const Variant &result_mode) {
    this_ = newObject(LITERAL_STRING[897], {mysql.getObject(), result_mode});
}
Variant mysqli_result::close() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[857]);
    }
    return this_.call(_method_fn, {});
}
Variant mysqli_result::free() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[898]);
    }
    return this_.call(_method_fn, {});
}
Variant mysqli_result::data_seek(const Variant &offset) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[899]);
    }
    return this_.call(_method_fn, {offset});
}
Variant mysqli_result::fetch_field() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[900]);
    }
    return this_.call(_method_fn, {});
}
Variant mysqli_result::fetch_fields() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[901]);
    }
    return this_.call(_method_fn, {});
}
Variant mysqli_result::fetch_field_direct(const Variant &index) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[902]);
    }
    return this_.call(_method_fn, {index});
}
Variant mysqli_result::fetch_all(const Variant &mode) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[903]);
    }
    return this_.call(_method_fn, {mode});
}
Variant mysqli_result::fetch_array(const Variant &mode) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[904]);
    }
    return this_.call(_method_fn, {mode});
}
Variant mysqli_result::fetch_assoc() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[905]);
    }
    return this_.call(_method_fn, {});
}
Variant mysqli_result::fetch_object(const Variant &class_, const Variant &constructor_args) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[906]);
    }
    return this_.call(_method_fn, {class_, constructor_args});
}
Variant mysqli_result::fetch_row() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[907]);
    }
    return this_.call(_method_fn, {});
}
Variant mysqli_result::fetch_column(const Variant &column) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[908]);
    }
    return this_.call(_method_fn, {column});
}
Variant mysqli_result::field_seek(const Variant &index) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[909]);
    }
    return this_.call(_method_fn, {index});
}
Variant mysqli_result::free_result() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[910]);
    }
    return this_.call(_method_fn, {});
}
Variant mysqli_result::getIterator() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[141]);
    }
    return this_.call(_method_fn, {});
}
mysqli::mysqli(const Variant &hostname,
               const Variant &username,
               const Variant &password,
               const Variant &database,
               const Variant &port,
               const Variant &socket) {
    this_ = newObject(LITERAL_STRING[852], {hostname, username, password, database, port, socket});
}
Variant mysqli::autocommit(const Variant &enable) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[853]);
    }
    return this_.call(_method_fn, {enable});
}
Variant mysqli::begin_transaction(const Variant &flags, const Variant &name) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[854]);
    }
    return this_.call(_method_fn, {flags, name});
}
Variant mysqli::change_user(const Variant &username, const Variant &password, const Variant &database) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[855]);
    }
    return this_.call(_method_fn, {username, password, database});
}
Variant mysqli::character_set_name() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[856]);
    }
    return this_.call(_method_fn, {});
}
Variant mysqli::close() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[857]);
    }
    return this_.call(_method_fn, {});
}
Variant mysqli::commit(const Variant &flags, const Variant &name) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[858]);
    }
    return this_.call(_method_fn, {flags, name});
}
Variant mysqli::connect(const Variant &hostname,
                        const Variant &username,
                        const Variant &password,
                        const Variant &database,
                        const Variant &port,
                        const Variant &socket) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[859]);
    }
    return this_.call(_method_fn, {hostname, username, password, database, port, socket});
}
Variant mysqli::dump_debug_info() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[860]);
    }
    return this_.call(_method_fn, {});
}
Variant mysqli::debug(const Variant &options) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[861]);
    }
    return this_.call(_method_fn, {options});
}
Variant mysqli::get_charset() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[862]);
    }
    return this_.call(_method_fn, {});
}
Variant mysqli::execute_query(const Variant &query, const Variant &params) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[863]);
    }
    return this_.call(_method_fn, {query, params});
}
Variant mysqli::get_client_info() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[864]);
    }
    return this_.call(_method_fn, {});
}
Variant mysqli::get_connection_stats() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[865]);
    }
    return this_.call(_method_fn, {});
}
Variant mysqli::get_server_info() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[866]);
    }
    return this_.call(_method_fn, {});
}
Variant mysqli::get_warnings() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[867]);
    }
    return this_.call(_method_fn, {});
}
Variant mysqli::init() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[868]);
    }
    return this_.call(_method_fn, {});
}
Variant mysqli::kill(const Variant &process_id) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[869]);
    }
    return this_.call(_method_fn, {process_id});
}
Variant mysqli::multi_query(const Variant &query) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[870]);
    }
    return this_.call(_method_fn, {query});
}
Variant mysqli::more_results() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[871]);
    }
    return this_.call(_method_fn, {});
}
Variant mysqli::next_result() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[872]);
    }
    return this_.call(_method_fn, {});
}
Variant mysqli::ping() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[873]);
    }
    return this_.call(_method_fn, {});
}
Variant mysqli::poll(const Reference &read,
                     const Reference &error,
                     const Reference &reject,
                     const Variant &seconds,
                     const Variant &microseconds) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(LITERAL_STRING[852], LITERAL_STRING[875]);
    }
    return php::call(_method_fn, {&read, &error, &reject, seconds, microseconds});
}
Variant mysqli::prepare(const Variant &query) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[876]);
    }
    return this_.call(_method_fn, {query});
}
Variant mysqli::query(const Variant &query, const Variant &result_mode) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[503]);
    }
    return this_.call(_method_fn, {query, result_mode});
}
Variant mysqli::real_connect(const Variant &hostname,
                             const Variant &username,
                             const Variant &password,
                             const Variant &database,
                             const Variant &port,
                             const Variant &socket,
                             const Variant &flags) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[877]);
    }
    return this_.call(_method_fn, {hostname, username, password, database, port, socket, flags});
}
Variant mysqli::real_escape_string(const Variant &string) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[878]);
    }
    return this_.call(_method_fn, {string});
}
Variant mysqli::reap_async_query() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[879]);
    }
    return this_.call(_method_fn, {});
}
Variant mysqli::escape_string(const Variant &string) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[880]);
    }
    return this_.call(_method_fn, {string});
}
Variant mysqli::real_query(const Variant &query) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[881]);
    }
    return this_.call(_method_fn, {query});
}
Variant mysqli::release_savepoint(const Variant &name) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[882]);
    }
    return this_.call(_method_fn, {name});
}
Variant mysqli::rollback(const Variant &flags, const Variant &name) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[883]);
    }
    return this_.call(_method_fn, {flags, name});
}
Variant mysqli::savepoint(const Variant &name) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[884]);
    }
    return this_.call(_method_fn, {name});
}
Variant mysqli::select_db(const Variant &database) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[885]);
    }
    return this_.call(_method_fn, {database});
}
Variant mysqli::set_charset(const Variant &charset) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[886]);
    }
    return this_.call(_method_fn, {charset});
}
Variant mysqli::options(const Variant &option, const Variant &value) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[887]);
    }
    return this_.call(_method_fn, {option, value});
}
Variant mysqli::set_opt(const Variant &option, const Variant &value) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[888]);
    }
    return this_.call(_method_fn, {option, value});
}
Variant mysqli::ssl_set(const Variant &key,
                        const Variant &certificate,
                        const Variant &ca_certificate,
                        const Variant &ca_path,
                        const Variant &cipher_algos) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[889]);
    }
    return this_.call(_method_fn, {key, certificate, ca_certificate, ca_path, cipher_algos});
}
Variant mysqli::stat() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[890]);
    }
    return this_.call(_method_fn, {});
}
Variant mysqli::stmt_init() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[891]);
    }
    return this_.call(_method_fn, {});
}
Variant mysqli::store_result(const Variant &mode) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[892]);
    }
    return this_.call(_method_fn, {mode});
}
Variant mysqli::thread_safe() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[893]);
    }
    return this_.call(_method_fn, {});
}
Variant mysqli::use_result() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[894]);
    }
    return this_.call(_method_fn, {});
}
Variant mysqli::refresh(const Variant &flags) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[895]);
    }
    return this_.call(_method_fn, {flags});
}
mysqli_stmt::mysqli_stmt(const mysqli &mysql, const Variant &query) {
    this_ = newObject(LITERAL_STRING[911], {mysql.getObject(), query});
}
Variant mysqli_stmt::attr_get(const Variant &attribute) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[912]);
    }
    return this_.call(_method_fn, {attribute});
}
Variant mysqli_stmt::attr_set(const Variant &attribute, const Variant &value) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[913]);
    }
    return this_.call(_method_fn, {attribute, value});
}
Variant mysqli_stmt::close() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[857]);
    }
    return this_.call(_method_fn, {});
}
Variant mysqli_stmt::data_seek(const Variant &offset) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[899]);
    }
    return this_.call(_method_fn, {offset});
}
Variant mysqli_stmt::execute(const Variant &params) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[916]);
    }
    return this_.call(_method_fn, {params});
}
Variant mysqli_stmt::fetch() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[917]);
    }
    return this_.call(_method_fn, {});
}
Variant mysqli_stmt::get_warnings() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[867]);
    }
    return this_.call(_method_fn, {});
}
Variant mysqli_stmt::result_metadata() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[918]);
    }
    return this_.call(_method_fn, {});
}
Variant mysqli_stmt::more_results() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[871]);
    }
    return this_.call(_method_fn, {});
}
Variant mysqli_stmt::next_result() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[872]);
    }
    return this_.call(_method_fn, {});
}
Variant mysqli_stmt::num_rows() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[919]);
    }
    return this_.call(_method_fn, {});
}
Variant mysqli_stmt::send_long_data(const Variant &param_num, const Variant &data) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[920]);
    }
    return this_.call(_method_fn, {param_num, data});
}
Variant mysqli_stmt::free_result() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[910]);
    }
    return this_.call(_method_fn, {});
}
Variant mysqli_stmt::reset() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[921]);
    }
    return this_.call(_method_fn, {});
}
Variant mysqli_stmt::prepare(const Variant &query) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[876]);
    }
    return this_.call(_method_fn, {query});
}
Variant mysqli_stmt::store_result() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[892]);
    }
    return this_.call(_method_fn, {});
}
Variant mysqli_stmt::get_result() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[922]);
    }
    return this_.call(_method_fn, {});
}
}  // namespace php

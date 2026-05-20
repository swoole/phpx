#include "phpx.h"
#include "class/sqlite3.h"

namespace php {
SQLite3Exception::SQLite3Exception(const Variant &message, const Variant &code, const Variant &previous) {
    this_ = newObject(LITERAL_STRING[1889], {message, code, previous});
}
Variant SQLite3Exception::__wakeup() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[97]);
    }
    return this_.call(_method_fn, {});
}
Variant SQLite3Exception::getMessage() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[98]);
    }
    return this_.call(_method_fn, {});
}
Variant SQLite3Exception::getCode() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[99]);
    }
    return this_.call(_method_fn, {});
}
Variant SQLite3Exception::getFile() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[100]);
    }
    return this_.call(_method_fn, {});
}
Variant SQLite3Exception::getLine() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[101]);
    }
    return this_.call(_method_fn, {});
}
Variant SQLite3Exception::getTrace() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[102]);
    }
    return this_.call(_method_fn, {});
}
Variant SQLite3Exception::getPrevious() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[103]);
    }
    return this_.call(_method_fn, {});
}
Variant SQLite3Exception::getTraceAsString() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[104]);
    }
    return this_.call(_method_fn, {});
}
Variant SQLite3Exception::__toString() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[29]);
    }
    return this_.call(_method_fn, {});
}
SQLite3::SQLite3(const Variant &filename, const Variant &flags, const Variant &encryption_key) {
    this_ = newObject(LITERAL_STRING[1890], {filename, flags, encryption_key});
}
Variant SQLite3::open(const Variant &filename, const Variant &flags, const Variant &encryption_key) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1230]);
    }
    return this_.call(_method_fn, {filename, flags, encryption_key});
}
Variant SQLite3::close() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1126]);
    }
    return this_.call(_method_fn, {});
}
Variant SQLite3::version() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(LITERAL_STRING[1890], LITERAL_STRING[1892]);
    }
    return php::call(_method_fn, {});
}
Variant SQLite3::lastInsertRowID() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1893]);
    }
    return this_.call(_method_fn, {});
}
Variant SQLite3::lastErrorCode() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1894]);
    }
    return this_.call(_method_fn, {});
}
Variant SQLite3::lastExtendedErrorCode() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1895]);
    }
    return this_.call(_method_fn, {});
}
Variant SQLite3::lastErrorMsg() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1896]);
    }
    return this_.call(_method_fn, {});
}
Variant SQLite3::changes() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1897]);
    }
    return this_.call(_method_fn, {});
}
Variant SQLite3::busyTimeout(const Variant &milliseconds) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1898]);
    }
    return this_.call(_method_fn, {milliseconds});
}
Variant SQLite3::loadExtension(const Variant &name) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[898]);
    }
    return this_.call(_method_fn, {name});
}
Variant SQLite3::backup(const Variant &destination,
                        const Variant &source_database,
                        const Variant &destination_database) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1899]);
    }
    return this_.call(_method_fn, {destination, source_database, destination_database});
}
Variant SQLite3::escapeString(const Variant &string) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(LITERAL_STRING[1890], LITERAL_STRING[1901]);
    }
    return php::call(_method_fn, {string});
}
Variant SQLite3::prepare(const Variant &query) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[871]);
    }
    return this_.call(_method_fn, {query});
}
Variant SQLite3::exec(const Variant &query) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[866]);
    }
    return this_.call(_method_fn, {query});
}
Variant SQLite3::query(const Variant &query) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[506]);
    }
    return this_.call(_method_fn, {query});
}
Variant SQLite3::querySingle(const Variant &query, const Variant &entire_row) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1902]);
    }
    return this_.call(_method_fn, {query, entire_row});
}
Variant SQLite3::createFunction(const Variant &name,
                                const Variant &callback,
                                const Variant &arg_count,
                                const Variant &flags) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[897]);
    }
    return this_.call(_method_fn, {name, callback, arg_count, flags});
}
Variant SQLite3::createAggregate(const Variant &name,
                                 const Variant &step_callback,
                                 const Variant &final_callback,
                                 const Variant &arg_count) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[895]);
    }
    return this_.call(_method_fn, {name, step_callback, final_callback, arg_count});
}
Variant SQLite3::createCollation(const Variant &name, const Variant &callback) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[896]);
    }
    return this_.call(_method_fn, {name, callback});
}
Variant SQLite3::openBlob(
    const Variant &table, const Variant &column, const Variant &rowid, const Variant &database, const Variant &flags) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[899]);
    }
    return this_.call(_method_fn, {table, column, rowid, database, flags});
}
Variant SQLite3::enableExceptions(const Variant &enable) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1903]);
    }
    return this_.call(_method_fn, {enable});
}
Variant SQLite3::enableExtendedResultCodes(const Variant &enable) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1904]);
    }
    return this_.call(_method_fn, {enable});
}
Variant SQLite3::setAuthorizer(const Variant &callback) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1905]);
    }
    return this_.call(_method_fn, {callback});
}
Variant SQLite3Stmt::bindParam(const Variant &param, const Reference &var, const Variant &type) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[875]);
    }
    return this_.call(_method_fn, {param, &var, type});
}
Variant SQLite3Stmt::bindValue(const Variant &param, const Variant &value, const Variant &type) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[876]);
    }
    return this_.call(_method_fn, {param, value, type});
}
Variant SQLite3Stmt::clear() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1906]);
    }
    return this_.call(_method_fn, {});
}
Variant SQLite3Stmt::close() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1126]);
    }
    return this_.call(_method_fn, {});
}
Variant SQLite3Stmt::execute() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[880]);
    }
    return this_.call(_method_fn, {});
}
Variant SQLite3Stmt::getSQL(const Variant &expand) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1907]);
    }
    return this_.call(_method_fn, {expand});
}
Variant SQLite3Stmt::paramCount() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1908]);
    }
    return this_.call(_method_fn, {});
}
Variant SQLite3Stmt::readOnly() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1909]);
    }
    return this_.call(_method_fn, {});
}
Variant SQLite3Stmt::reset() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1251]);
    }
    return this_.call(_method_fn, {});
}
Variant SQLite3Result::numColumns() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1911]);
    }
    return this_.call(_method_fn, {});
}
Variant SQLite3Result::columnName(const Variant &column) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1912]);
    }
    return this_.call(_method_fn, {column});
}
Variant SQLite3Result::columnType(const Variant &column) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1913]);
    }
    return this_.call(_method_fn, {column});
}
Variant SQLite3Result::fetchArray(const Variant &mode) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1914]);
    }
    return this_.call(_method_fn, {mode});
}
Variant SQLite3Result::reset() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1251]);
    }
    return this_.call(_method_fn, {});
}
Variant SQLite3Result::finalize() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1915]);
    }
    return this_.call(_method_fn, {});
}
}  // namespace php

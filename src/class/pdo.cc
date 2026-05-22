#include "phpx.h"
#include "phpx_class.h"
#include "class/pdo.h"

namespace php {
PDOException::PDOException(const Variant &message, const Variant &code, const Variant &previous) {
    this_ = newObject(LITERAL_STRING[1033], {message, code, previous});
}
PDOStatement::PDOStatement() {
    this_ = newObject(LITERAL_STRING[1045]);
}
Variant PDOStatement::bindColumn(const Variant &column,
                                 const Reference &var,
                                 const Variant &type,
                                 const Variant &max_length,
                                 const Variant &driver_options) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1046]);
    }
    return this_.call(_method_fn, {column, &var, type, max_length, driver_options});
}
Variant PDOStatement::bindParam(const Variant &param,
                                const Reference &var,
                                const Variant &type,
                                const Variant &max_length,
                                const Variant &driver_options) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1047]);
    }
    return this_.call(_method_fn, {param, &var, type, max_length, driver_options});
}
Variant PDOStatement::bindValue(const Variant &param, const Variant &value, const Variant &type) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1048]);
    }
    return this_.call(_method_fn, {param, value, type});
}
Variant PDOStatement::closeCursor() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1049]);
    }
    return this_.call(_method_fn, {});
}
Variant PDOStatement::columnCount() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1050]);
    }
    return this_.call(_method_fn, {});
}
Variant PDOStatement::debugDumpParams() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1051]);
    }
    return this_.call(_method_fn, {});
}
Variant PDOStatement::errorCode() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1037]);
    }
    return this_.call(_method_fn, {});
}
Variant PDOStatement::errorInfo() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1038]);
    }
    return this_.call(_method_fn, {});
}
Variant PDOStatement::execute(const Variant &params) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[916]);
    }
    return this_.call(_method_fn, {params});
}
Variant PDOStatement::fetch(const Variant &mode, const Variant &cursor_orientation, const Variant &cursor_offset) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[917]);
    }
    return this_.call(_method_fn, {mode, cursor_orientation, cursor_offset});
}
Variant PDOStatement::fetchColumn(const Variant &column) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1053]);
    }
    return this_.call(_method_fn, {column});
}
Variant PDOStatement::fetchObject(const Variant &class_, const Variant &constructor_args) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1054]);
    }
    return this_.call(_method_fn, {class_, constructor_args});
}
Variant PDOStatement::getAttribute(const Variant &name) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[456]);
    }
    return this_.call(_method_fn, {name});
}
Variant PDOStatement::getColumnMeta(const Variant &column) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1055]);
    }
    return this_.call(_method_fn, {column});
}
Variant PDOStatement::nextRowset() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1056]);
    }
    return this_.call(_method_fn, {});
}
Variant PDOStatement::rowCount() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1057]);
    }
    return this_.call(_method_fn, {});
}
Variant PDOStatement::setAttribute(const Variant &attribute, const Variant &value) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[466]);
    }
    return this_.call(_method_fn, {attribute, value});
}
Variant PDOStatement::getIterator() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[141]);
    }
    return this_.call(_method_fn, {});
}
PDO::PDO(const Variant &dsn, const Variant &username, const Variant &password, const Variant &options) {
    this_ = newObject(LITERAL_STRING[1034], {dsn, username, password, options});
}
Variant PDO::connect(const Variant &dsn, const Variant &username, const Variant &password, const Variant &options) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(LITERAL_STRING[1034], LITERAL_STRING[859]);
    }
    return php::call(_method_fn, {dsn, username, password, options});
}
Variant PDO::beginTransaction() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1036]);
    }
    return this_.call(_method_fn, {});
}
Variant PDO::commit() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[858]);
    }
    return this_.call(_method_fn, {});
}
Variant PDO::errorCode() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1037]);
    }
    return this_.call(_method_fn, {});
}
Variant PDO::errorInfo() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1038]);
    }
    return this_.call(_method_fn, {});
}
Variant PDO::exec(const Variant &statement) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1039]);
    }
    return this_.call(_method_fn, {statement});
}
Variant PDO::getAttribute(const Variant &attribute) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[456]);
    }
    return this_.call(_method_fn, {attribute});
}
Variant PDO::getAvailableDrivers() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(LITERAL_STRING[1034], LITERAL_STRING[1041]);
    }
    return php::call(_method_fn, {});
}
Variant PDO::inTransaction() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1042]);
    }
    return this_.call(_method_fn, {});
}
Variant PDO::lastInsertId(const Variant &name) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1043]);
    }
    return this_.call(_method_fn, {name});
}
PDOStatement PDO::prepare(const Variant &query, const Variant &options) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[876]);
    }
    auto _rv = this_.call(_method_fn, {query, options});
    if (!_rv.toBool()) {
        throwException(String("RuntimeException"), "PDO::prepare() returned false");
    }
    return PDOStatement(Object(std::move(_rv)));
}
PDOStatement PDO::query(const Variant &query, const Variant &fetch_mode) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[503]);
    }
    auto _rv = this_.call(_method_fn, {query, fetch_mode});
    if (!_rv.toBool()) {
        throwException(String("RuntimeException"), "PDO::query() returned false");
    }
    return PDOStatement(Object(std::move(_rv)));
}
Variant PDO::quote(const Variant &string, const Variant &type) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[508]);
    }
    return this_.call(_method_fn, {string, type});
}
Variant PDO::rollBack() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1044]);
    }
    return this_.call(_method_fn, {});
}
Variant PDO::setAttribute(const Variant &attribute, const Variant &value) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[466]);
    }
    return this_.call(_method_fn, {attribute, value});
}
PDORow::PDORow() {
    this_ = newObject(LITERAL_STRING[1059]);
}
}  // namespace php

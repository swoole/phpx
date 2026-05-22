#include "phpx.h"
#include "phpx_class.h"
#include "class/pdo.h"

namespace php {
PDOException::PDOException(const Variant &message, const Variant &code, const Variant &previous) {
    this_ = newObject(LITERAL_STRING[1071], {message, code, previous});
}
PDOStatement::PDOStatement() {
    this_ = newObject(LITERAL_STRING[1083]);
}
Variant PDOStatement::bindColumn(const Variant &column,
                                 const Reference &var,
                                 const Variant &type,
                                 const Variant &max_length,
                                 const Variant &driver_options) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1084]);
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
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1085]);
    }
    return this_.call(_method_fn, {param, &var, type, max_length, driver_options});
}
Variant PDOStatement::bindValue(const Variant &param, const Variant &value, const Variant &type) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1086]);
    }
    return this_.call(_method_fn, {param, value, type});
}
Variant PDOStatement::closeCursor() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1087]);
    }
    return this_.call(_method_fn, {});
}
Variant PDOStatement::columnCount() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1088]);
    }
    return this_.call(_method_fn, {});
}
Variant PDOStatement::debugDumpParams() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1089]);
    }
    return this_.call(_method_fn, {});
}
Variant PDOStatement::errorCode() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1075]);
    }
    return this_.call(_method_fn, {});
}
Variant PDOStatement::errorInfo() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1076]);
    }
    return this_.call(_method_fn, {});
}
Variant PDOStatement::execute(const Variant &params) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[954]);
    }
    return this_.call(_method_fn, {params});
}
Variant PDOStatement::fetch(const Variant &mode, const Variant &cursor_orientation, const Variant &cursor_offset) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[955]);
    }
    return this_.call(_method_fn, {mode, cursor_orientation, cursor_offset});
}
Variant PDOStatement::fetchColumn(const Variant &column) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1091]);
    }
    return this_.call(_method_fn, {column});
}
Variant PDOStatement::fetchObject(const Variant &class_, const Variant &constructor_args) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1092]);
    }
    return this_.call(_method_fn, {class_, constructor_args});
}
Variant PDOStatement::getAttribute(const Variant &name) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[484]);
    }
    return this_.call(_method_fn, {name});
}
Variant PDOStatement::getColumnMeta(const Variant &column) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1093]);
    }
    return this_.call(_method_fn, {column});
}
Variant PDOStatement::nextRowset() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1094]);
    }
    return this_.call(_method_fn, {});
}
Variant PDOStatement::rowCount() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1095]);
    }
    return this_.call(_method_fn, {});
}
Variant PDOStatement::setAttribute(const Variant &attribute, const Variant &value) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[494]);
    }
    return this_.call(_method_fn, {attribute, value});
}
Variant PDOStatement::getIterator() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[169]);
    }
    return this_.call(_method_fn, {});
}
PDO::PDO(const Variant &dsn, const Variant &username, const Variant &password, const Variant &options) {
    this_ = newObject(LITERAL_STRING[1072], {dsn, username, password, options});
}
Variant PDO::connect(const Variant &dsn, const Variant &username, const Variant &password, const Variant &options) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(LITERAL_STRING[1072], LITERAL_STRING[897]);
    }
    return php::call(_method_fn, {dsn, username, password, options});
}
Variant PDO::beginTransaction() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1074]);
    }
    return this_.call(_method_fn, {});
}
Variant PDO::commit() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[896]);
    }
    return this_.call(_method_fn, {});
}
Variant PDO::errorCode() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1075]);
    }
    return this_.call(_method_fn, {});
}
Variant PDO::errorInfo() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1076]);
    }
    return this_.call(_method_fn, {});
}
Variant PDO::exec(const Variant &statement) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1077]);
    }
    return this_.call(_method_fn, {statement});
}
Variant PDO::getAttribute(const Variant &attribute) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[484]);
    }
    return this_.call(_method_fn, {attribute});
}
Variant PDO::getAvailableDrivers() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(LITERAL_STRING[1072], LITERAL_STRING[1079]);
    }
    return php::call(_method_fn, {});
}
Variant PDO::inTransaction() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1080]);
    }
    return this_.call(_method_fn, {});
}
Variant PDO::lastInsertId(const Variant &name) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1081]);
    }
    return this_.call(_method_fn, {name});
}
PDOStatement PDO::prepare(const Variant &query, const Variant &options) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[914]);
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
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[531]);
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
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[536]);
    }
    return this_.call(_method_fn, {string, type});
}
Variant PDO::rollBack() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1082]);
    }
    return this_.call(_method_fn, {});
}
Variant PDO::setAttribute(const Variant &attribute, const Variant &value) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[494]);
    }
    return this_.call(_method_fn, {attribute, value});
}
PDORow::PDORow() {
    this_ = newObject(LITERAL_STRING[1097]);
}
}  // namespace php

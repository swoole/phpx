#include "phpx.h"
#include "class/pdo.h"

namespace php {
PDOException::PDOException(const Variant &message, const Variant &code, const Variant &previous) {
    _this = newObject("PDOException", message, code, previous);
}

Variant PDOException::__wakeup() {
    return _this.exec("__wakeup");
}

Variant PDOException::getMessage() {
    return _this.exec("getMessage");
}

Variant PDOException::getCode() {
    return _this.exec("getCode");
}

Variant PDOException::getFile() {
    return _this.exec("getFile");
}

Variant PDOException::getLine() {
    return _this.exec("getLine");
}

Variant PDOException::getTrace() {
    return _this.exec("getTrace");
}

Variant PDOException::getPrevious() {
    return _this.exec("getPrevious");
}

Variant PDOException::getTraceAsString() {
    return _this.exec("getTraceAsString");
}

Variant PDOException::__toString() {
    return _this.exec("__toString");
}


PDO::PDO(const Variant &dsn, const Variant &username, const Variant &password, const Variant &options) {
    _this = newObject("PDO", dsn, username, password, options);
}

Variant PDO::beginTransaction() {
    return _this.exec("beginTransaction");
}

Variant PDO::commit() {
    return _this.exec("commit");
}

Variant PDO::errorCode() {
    return _this.exec("errorCode");
}

Variant PDO::errorInfo() {
    return _this.exec("errorInfo");
}

Variant PDO::exec(const Variant &statement) {
    return _this.exec("exec", statement);
}

Variant PDO::getAttribute(const Variant &attribute) {
    return _this.exec("getAttribute", attribute);
}

Variant PDO::getAvailableDrivers() {
    static Variant fn { ZEND_STRL("PDO::getAvailableDrivers"), true };
    return fn();
}

Variant PDO::inTransaction() {
    return _this.exec("inTransaction");
}

Variant PDO::lastInsertId(const Variant &name) {
    return _this.exec("lastInsertId", name);
}

Variant PDO::prepare(const Variant &query, const Array &options) {
    return _this.exec("prepare", query, options);
}

Variant PDO::query(const Variant &query, const Variant &fetch_mode, const Variant &fetch_mode_args) {
    return _this.exec("query", query, fetch_mode, fetch_mode_args);
}

Variant PDO::quote(const Variant &string, const Variant &type) {
    return _this.exec("quote", string, type);
}

Variant PDO::rollBack() {
    return _this.exec("rollBack");
}

Variant PDO::setAttribute(const Variant &attribute, const Variant &value) {
    return _this.exec("setAttribute", attribute, value);
}


Variant PDOStatement::bindColumn(const Variant &column, const Variant &var, const Variant &type, const Variant &max_length, const Variant &driver_options) {
    return _this.exec("bindColumn", column, var, type, max_length, driver_options);
}

Variant PDOStatement::bindParam(const Variant &param, const Variant &var, const Variant &type, const Variant &max_length, const Variant &driver_options) {
    return _this.exec("bindParam", param, var, type, max_length, driver_options);
}

Variant PDOStatement::bindValue(const Variant &param, const Variant &value, const Variant &type) {
    return _this.exec("bindValue", param, value, type);
}

Variant PDOStatement::closeCursor() {
    return _this.exec("closeCursor");
}

Variant PDOStatement::columnCount() {
    return _this.exec("columnCount");
}

Variant PDOStatement::debugDumpParams() {
    return _this.exec("debugDumpParams");
}

Variant PDOStatement::errorCode() {
    return _this.exec("errorCode");
}

Variant PDOStatement::errorInfo() {
    return _this.exec("errorInfo");
}

Variant PDOStatement::execute(const Variant &params) {
    return _this.exec("execute", params);
}

Variant PDOStatement::fetch(const Variant &mode, const Variant &cursor_orientation, const Variant &cursor_offset) {
    return _this.exec("fetch", mode, cursor_orientation, cursor_offset);
}

Variant PDOStatement::fetchAll(const Variant &mode, const Variant &args) {
    return _this.exec("fetchAll", mode, args);
}

Variant PDOStatement::fetchColumn(const Variant &column) {
    return _this.exec("fetchColumn", column);
}

Variant PDOStatement::fetchObject(const Variant &_class, const Array &constructor_args) {
    return _this.exec("fetchObject", _class, constructor_args);
}

Variant PDOStatement::getAttribute(const Variant &name) {
    return _this.exec("getAttribute", name);
}

Variant PDOStatement::getColumnMeta(const Variant &column) {
    return _this.exec("getColumnMeta", column);
}

Variant PDOStatement::nextRowset() {
    return _this.exec("nextRowset");
}

Variant PDOStatement::rowCount() {
    return _this.exec("rowCount");
}

Variant PDOStatement::setAttribute(const Variant &attribute, const Variant &value) {
    return _this.exec("setAttribute", attribute, value);
}

Variant PDOStatement::setFetchMode(const Variant &mode, const Variant &args) {
    return _this.exec("setFetchMode", mode, args);
}

Variant PDOStatement::getIterator() {
    return _this.exec("getIterator");
}


}

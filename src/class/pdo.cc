#include "phpx.h"
#include "class/pdo.h"

namespace php {
PDOException::PDOException(const Variant &message, const Variant &code, const Variant &previous) {
    this_ = newObject("PDOException", message, code, previous);
}

Variant PDOException::__wakeup() {
    return this_.exec("__wakeup");
}

Variant PDOException::getMessage() {
    return this_.exec("getMessage");
}

Variant PDOException::getCode() {
    return this_.exec("getCode");
}

Variant PDOException::getFile() {
    return this_.exec("getFile");
}

Variant PDOException::getLine() {
    return this_.exec("getLine");
}

Variant PDOException::getTrace() {
    return this_.exec("getTrace");
}

Variant PDOException::getPrevious() {
    return this_.exec("getPrevious");
}

Variant PDOException::getTraceAsString() {
    return this_.exec("getTraceAsString");
}

Variant PDOException::__toString() {
    return this_.exec("__toString");
}


PDO::PDO(const Variant &dsn, const Variant &username, const Variant &password, const Variant &options) {
    this_ = newObject("PDO", dsn, username, password, options);
}

Variant PDO::beginTransaction() {
    return this_.exec("beginTransaction");
}

Variant PDO::commit() {
    return this_.exec("commit");
}

Variant PDO::errorCode() {
    return this_.exec("errorCode");
}

Variant PDO::errorInfo() {
    return this_.exec("errorInfo");
}

Variant PDO::exec(const Variant &statement) {
    return this_.exec("exec", statement);
}

Variant PDO::getAttribute(const Variant &attribute) {
    return this_.exec("getAttribute", attribute);
}

Variant PDO::getAvailableDrivers() {
    static Variant fn { ZEND_STRL("PDO::getAvailableDrivers"), true };
    return fn();
}

Variant PDO::inTransaction() {
    return this_.exec("inTransaction");
}

Variant PDO::lastInsertId(const Variant &name) {
    return this_.exec("lastInsertId", name);
}

Variant PDO::prepare(const Variant &query, const Array &options) {
    return this_.exec("prepare", query, options);
}

Variant PDO::query(const Variant &query, const Variant &fetch_mode, const Variant &fetch_mode_args) {
    return this_.exec("query", query, fetch_mode, fetch_mode_args);
}

Variant PDO::quote(const Variant &string, const Variant &type) {
    return this_.exec("quote", string, type);
}

Variant PDO::rollBack() {
    return this_.exec("rollBack");
}

Variant PDO::setAttribute(const Variant &attribute, const Variant &value) {
    return this_.exec("setAttribute", attribute, value);
}


Variant PDOStatement::bindColumn(const Variant &column, const Variant &var, const Variant &type, const Variant &max_length, const Variant &driver_options) {
    return this_.exec("bindColumn", column, var, type, max_length, driver_options);
}

Variant PDOStatement::bindParam(const Variant &param, const Variant &var, const Variant &type, const Variant &max_length, const Variant &driver_options) {
    return this_.exec("bindParam", param, var, type, max_length, driver_options);
}

Variant PDOStatement::bindValue(const Variant &param, const Variant &value, const Variant &type) {
    return this_.exec("bindValue", param, value, type);
}

Variant PDOStatement::closeCursor() {
    return this_.exec("closeCursor");
}

Variant PDOStatement::columnCount() {
    return this_.exec("columnCount");
}

Variant PDOStatement::debugDumpParams() {
    return this_.exec("debugDumpParams");
}

Variant PDOStatement::errorCode() {
    return this_.exec("errorCode");
}

Variant PDOStatement::errorInfo() {
    return this_.exec("errorInfo");
}

Variant PDOStatement::execute(const Variant &params) {
    return this_.exec("execute", params);
}

Variant PDOStatement::fetch(const Variant &mode, const Variant &cursor_orientation, const Variant &cursor_offset) {
    return this_.exec("fetch", mode, cursor_orientation, cursor_offset);
}

Variant PDOStatement::fetchAll(const Variant &mode, const Variant &args) {
    return this_.exec("fetchAll", mode, args);
}

Variant PDOStatement::fetchColumn(const Variant &column) {
    return this_.exec("fetchColumn", column);
}

Variant PDOStatement::fetchObject(const Variant &_class, const Array &constructor_args) {
    return this_.exec("fetchObject", _class, constructor_args);
}

Variant PDOStatement::getAttribute(const Variant &name) {
    return this_.exec("getAttribute", name);
}

Variant PDOStatement::getColumnMeta(const Variant &column) {
    return this_.exec("getColumnMeta", column);
}

Variant PDOStatement::nextRowset() {
    return this_.exec("nextRowset");
}

Variant PDOStatement::rowCount() {
    return this_.exec("rowCount");
}

Variant PDOStatement::setAttribute(const Variant &attribute, const Variant &value) {
    return this_.exec("setAttribute", attribute, value);
}

Variant PDOStatement::setFetchMode(const Variant &mode, const Variant &args) {
    return this_.exec("setFetchMode", mode, args);
}

Variant PDOStatement::getIterator() {
    return this_.exec("getIterator");
}


}

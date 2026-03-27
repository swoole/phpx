#include "phpx.h"
#include "class/pdo.h"

namespace php {
PDOException::PDOException(const Variant &message, const Variant &code, const Variant &previous) {
    this_ = newObject(LITERAL_STRING[820], {message, code, previous});
}
Variant PDOException::__wakeup() {
    return this_.call(LITERAL_STRING[97], {});
}
Variant PDOException::getMessage() {
    return this_.call(LITERAL_STRING[98], {});
}
Variant PDOException::getCode() {
    return this_.call(LITERAL_STRING[99], {});
}
Variant PDOException::getFile() {
    return this_.call(LITERAL_STRING[100], {});
}
Variant PDOException::getLine() {
    return this_.call(LITERAL_STRING[101], {});
}
Variant PDOException::getTrace() {
    return this_.call(LITERAL_STRING[102], {});
}
Variant PDOException::getPrevious() {
    return this_.call(LITERAL_STRING[103], {});
}
Variant PDOException::getTraceAsString() {
    return this_.call(LITERAL_STRING[104], {});
}
Variant PDOException::__toString() {
    return this_.call(LITERAL_STRING[29], {});
}
PDO::PDO(const Variant &dsn, const Variant &username, const Variant &password, const Variant &options) {
    this_ = newObject(LITERAL_STRING[821], {dsn, username, password, options});
}
Variant PDO::connect(const Variant &dsn, const Variant &username, const Variant &password, const Variant &options) {
    return php::call(LITERAL_STRING[822], {dsn, username, password, options});
}
Variant PDO::beginTransaction() {
    return this_.call(LITERAL_STRING[823], {});
}
Variant PDO::commit() {
    return this_.call(LITERAL_STRING[824], {});
}
Variant PDO::errorCode() {
    return this_.call(LITERAL_STRING[825], {});
}
Variant PDO::errorInfo() {
    return this_.call(LITERAL_STRING[826], {});
}
Variant PDO::exec(const Variant &statement) {
    return this_.call(LITERAL_STRING[827], {statement});
}
Variant PDO::getAttribute(const Variant &attribute) {
    return this_.call(LITERAL_STRING[430], {attribute});
}
Variant PDO::getAvailableDrivers() {
    return php::call(LITERAL_STRING[828], {});
}
Variant PDO::inTransaction() {
    return this_.call(LITERAL_STRING[829], {});
}
Variant PDO::lastInsertId(const Variant &name) {
    return this_.call(LITERAL_STRING[830], {name});
}
Variant PDO::prepare(const Variant &query, const Variant &options) {
    return this_.call(LITERAL_STRING[831], {query, options});
}
Variant PDO::quote(const Variant &string, const Variant &type) {
    return this_.call(LITERAL_STRING[832], {string, type});
}
Variant PDO::rollBack() {
    return this_.call(LITERAL_STRING[833], {});
}
Variant PDO::setAttribute(const Variant &attribute, const Variant &value) {
    return this_.call(LITERAL_STRING[440], {attribute, value});
}
Variant PDOStatement::bindColumn(const Variant &column,
                                 const Reference &var,
                                 const Variant &type,
                                 const Variant &max_length,
                                 const Variant &driver_options) {
    return this_.call(LITERAL_STRING[834], {column, &var, type, max_length, driver_options});
}
Variant PDOStatement::bindParam(const Variant &param,
                                const Reference &var,
                                const Variant &type,
                                const Variant &max_length,
                                const Variant &driver_options) {
    return this_.call(LITERAL_STRING[835], {param, &var, type, max_length, driver_options});
}
Variant PDOStatement::bindValue(const Variant &param, const Variant &value, const Variant &type) {
    return this_.call(LITERAL_STRING[836], {param, value, type});
}
Variant PDOStatement::closeCursor() {
    return this_.call(LITERAL_STRING[837], {});
}
Variant PDOStatement::columnCount() {
    return this_.call(LITERAL_STRING[838], {});
}
Variant PDOStatement::debugDumpParams() {
    return this_.call(LITERAL_STRING[839], {});
}
Variant PDOStatement::errorCode() {
    return this_.call(LITERAL_STRING[825], {});
}
Variant PDOStatement::errorInfo() {
    return this_.call(LITERAL_STRING[826], {});
}
Variant PDOStatement::execute(const Variant &params) {
    return this_.call(LITERAL_STRING[840], {params});
}
Variant PDOStatement::fetch(const Variant &mode, const Variant &cursor_orientation, const Variant &cursor_offset) {
    return this_.call(LITERAL_STRING[841], {mode, cursor_orientation, cursor_offset});
}
Variant PDOStatement::fetchColumn(const Variant &column) {
    return this_.call(LITERAL_STRING[843], {column});
}
Variant PDOStatement::fetchObject(const Variant &_class, const Variant &constructor_args) {
    return this_.call(LITERAL_STRING[844], {_class, constructor_args});
}
Variant PDOStatement::getAttribute(const Variant &name) {
    return this_.call(LITERAL_STRING[430], {name});
}
Variant PDOStatement::getColumnMeta(const Variant &column) {
    return this_.call(LITERAL_STRING[845], {column});
}
Variant PDOStatement::nextRowset() {
    return this_.call(LITERAL_STRING[846], {});
}
Variant PDOStatement::rowCount() {
    return this_.call(LITERAL_STRING[847], {});
}
Variant PDOStatement::setAttribute(const Variant &attribute, const Variant &value) {
    return this_.call(LITERAL_STRING[440], {attribute, value});
}
Variant PDOStatement::getIterator() {
    return this_.call(LITERAL_STRING[137], {});
}
}  // namespace php

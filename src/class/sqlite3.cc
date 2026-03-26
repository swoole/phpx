#include "phpx.h"
#include "class/sqlite3.h"

namespace php {
SQLite3Exception::SQLite3Exception(const Variant &message, const Variant &code, const Variant &previous) {
    this_ = newObject(LITERAL_STRING[1826], {message, code, previous});
}
Variant SQLite3Exception::__wakeup() {
    return this_.exec(LITERAL_STRING[97], {});
}
Variant SQLite3Exception::getMessage() {
    return this_.exec(LITERAL_STRING[98], {});
}
Variant SQLite3Exception::getCode() {
    return this_.exec(LITERAL_STRING[99], {});
}
Variant SQLite3Exception::getFile() {
    return this_.exec(LITERAL_STRING[100], {});
}
Variant SQLite3Exception::getLine() {
    return this_.exec(LITERAL_STRING[101], {});
}
Variant SQLite3Exception::getTrace() {
    return this_.exec(LITERAL_STRING[102], {});
}
Variant SQLite3Exception::getPrevious() {
    return this_.exec(LITERAL_STRING[103], {});
}
Variant SQLite3Exception::getTraceAsString() {
    return this_.exec(LITERAL_STRING[104], {});
}
Variant SQLite3Exception::__toString() {
    return this_.exec(LITERAL_STRING[29], {});
}
SQLite3::SQLite3(const Variant &filename, const Variant &flags, const Variant &encryption_key) {
    this_ = newObject(LITERAL_STRING[1827], {filename, flags, encryption_key});
}
Variant SQLite3::open(const Variant &filename, const Variant &flags, const Variant &encryption_key) {
    return this_.exec(LITERAL_STRING[1173], {filename, flags, encryption_key});
}
Variant SQLite3::close() {
    return this_.exec(LITERAL_STRING[1068], {});
}
Variant SQLite3::version() {
    return php::call(LITERAL_STRING[1828], {});
}
Variant SQLite3::lastInsertRowID() {
    return this_.exec(LITERAL_STRING[1829], {});
}
Variant SQLite3::lastErrorCode() {
    return this_.exec(LITERAL_STRING[1830], {});
}
Variant SQLite3::lastExtendedErrorCode() {
    return this_.exec(LITERAL_STRING[1831], {});
}
Variant SQLite3::lastErrorMsg() {
    return this_.exec(LITERAL_STRING[1832], {});
}
Variant SQLite3::changes() {
    return this_.exec(LITERAL_STRING[1833], {});
}
Variant SQLite3::busyTimeout(const Variant &milliseconds) {
    return this_.exec(LITERAL_STRING[1834], {milliseconds});
}
Variant SQLite3::loadExtension(const Variant &name) {
    return this_.exec(LITERAL_STRING[857], {name});
}
Variant SQLite3::backup(const Variant &destination,
                        const Variant &source_database,
                        const Variant &destination_database) {
    return this_.exec(LITERAL_STRING[1835], {destination, source_database, destination_database});
}
Variant SQLite3::escapeString(const Variant &string) {
    return php::call(LITERAL_STRING[1836], {string});
}
Variant SQLite3::prepare(const Variant &query) {
    return this_.exec(LITERAL_STRING[831], {query});
}
Variant SQLite3::exec(const Variant &query) {
    return this_.exec(LITERAL_STRING[827], {query});
}
Variant SQLite3::query(const Variant &query) {
    return this_.exec(LITERAL_STRING[477], {query});
}
Variant SQLite3::querySingle(const Variant &query, const Variant &entire_row) {
    return this_.exec(LITERAL_STRING[1837], {query, entire_row});
}
Variant SQLite3::createFunction(const Variant &name,
                                const Variant &callback,
                                const Variant &arg_count,
                                const Variant &flags) {
    return this_.exec(LITERAL_STRING[856], {name, callback, arg_count, flags});
}
Variant SQLite3::createAggregate(const Variant &name,
                                 const Variant &step_callback,
                                 const Variant &final_callback,
                                 const Variant &arg_count) {
    return this_.exec(LITERAL_STRING[854], {name, step_callback, final_callback, arg_count});
}
Variant SQLite3::createCollation(const Variant &name, const Variant &callback) {
    return this_.exec(LITERAL_STRING[855], {name, callback});
}
Variant SQLite3::openBlob(
    const Variant &table, const Variant &column, const Variant &rowid, const Variant &database, const Variant &flags) {
    return this_.exec(LITERAL_STRING[858], {table, column, rowid, database, flags});
}
Variant SQLite3::enableExceptions(const Variant &enable) {
    return this_.exec(LITERAL_STRING[1838], {enable});
}
Variant SQLite3::enableExtendedResultCodes(const Variant &enable) {
    return this_.exec(LITERAL_STRING[1839], {enable});
}
Variant SQLite3::setAuthorizer(const Variant &callback) {
    return this_.exec(LITERAL_STRING[1840], {callback});
}
Variant SQLite3Stmt::bindParam(const Variant &param, const Reference &var, const Variant &type) {
    return this_.exec(LITERAL_STRING[835], {param, &var, type});
}
Variant SQLite3Stmt::bindValue(const Variant &param, const Variant &value, const Variant &type) {
    return this_.exec(LITERAL_STRING[836], {param, value, type});
}
Variant SQLite3Stmt::clear() {
    return this_.exec(LITERAL_STRING[1841], {});
}
Variant SQLite3Stmt::close() {
    return this_.exec(LITERAL_STRING[1068], {});
}
Variant SQLite3Stmt::execute() {
    return this_.exec(LITERAL_STRING[840], {});
}
Variant SQLite3Stmt::getSQL(const Variant &expand) {
    return this_.exec(LITERAL_STRING[1842], {expand});
}
Variant SQLite3Stmt::paramCount() {
    return this_.exec(LITERAL_STRING[1843], {});
}
Variant SQLite3Stmt::readOnly() {
    return this_.exec(LITERAL_STRING[1844], {});
}
Variant SQLite3Stmt::reset() {
    return this_.exec(LITERAL_STRING[1194], {});
}
Variant SQLite3Result::numColumns() {
    return this_.exec(LITERAL_STRING[1846], {});
}
Variant SQLite3Result::columnName(const Variant &column) {
    return this_.exec(LITERAL_STRING[1847], {column});
}
Variant SQLite3Result::columnType(const Variant &column) {
    return this_.exec(LITERAL_STRING[1848], {column});
}
Variant SQLite3Result::fetchArray(const Variant &mode) {
    return this_.exec(LITERAL_STRING[1849], {mode});
}
Variant SQLite3Result::reset() {
    return this_.exec(LITERAL_STRING[1194], {});
}
Variant SQLite3Result::finalize() {
    return this_.exec(LITERAL_STRING[1850], {});
}
}  // namespace php

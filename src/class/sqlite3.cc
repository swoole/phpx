#include "phpx.h"
#include "class/sqlite3.h"

namespace php {
SQLite3Exception::SQLite3Exception(const Variant &message, const Variant &code, const Variant &previous) {
    this_ = newObject("SQLite3Exception", message, code, previous);
}

Variant SQLite3Exception::__wakeup() {
    return this_.exec("__wakeup");
}

Variant SQLite3Exception::getMessage() {
    return this_.exec("getMessage");
}

Variant SQLite3Exception::getCode() {
    return this_.exec("getCode");
}

Variant SQLite3Exception::getFile() {
    return this_.exec("getFile");
}

Variant SQLite3Exception::getLine() {
    return this_.exec("getLine");
}

Variant SQLite3Exception::getTrace() {
    return this_.exec("getTrace");
}

Variant SQLite3Exception::getPrevious() {
    return this_.exec("getPrevious");
}

Variant SQLite3Exception::getTraceAsString() {
    return this_.exec("getTraceAsString");
}

Variant SQLite3Exception::__toString() {
    return this_.exec("__toString");
}


SQLite3::SQLite3(const Variant &filename, const Variant &flags, const Variant &encryption_key) {
    this_ = newObject("SQLite3", filename, flags, encryption_key);
}

Variant SQLite3::open(const Variant &filename, const Variant &flags, const Variant &encryption_key) {
    return this_.exec("open", filename, flags, encryption_key);
}

Variant SQLite3::close() {
    return this_.exec("close");
}

Variant SQLite3::version() {
    static Variant fn { ZEND_STRL("SQLite3::version"), true };
    return fn();
}

Variant SQLite3::lastInsertRowID() {
    return this_.exec("lastInsertRowID");
}

Variant SQLite3::lastErrorCode() {
    return this_.exec("lastErrorCode");
}

Variant SQLite3::lastExtendedErrorCode() {
    return this_.exec("lastExtendedErrorCode");
}

Variant SQLite3::lastErrorMsg() {
    return this_.exec("lastErrorMsg");
}

Variant SQLite3::changes() {
    return this_.exec("changes");
}

Variant SQLite3::busyTimeout(const Variant &milliseconds) {
    return this_.exec("busyTimeout", milliseconds);
}

Variant SQLite3::loadExtension(const Variant &name) {
    return this_.exec("loadExtension", name);
}

Variant SQLite3::backup(const Variant &destination, const Variant &source_database, const Variant &destination_database) {
    return this_.exec("backup", destination, source_database, destination_database);
}

Variant SQLite3::escapeString(const Variant &string) {
    static Variant fn { ZEND_STRL("SQLite3::escapeString"), true };
    return fn(string);
}

Variant SQLite3::prepare(const Variant &query) {
    return this_.exec("prepare", query);
}

Variant SQLite3::exec(const Variant &query) {
    return this_.exec("exec", query);
}

Variant SQLite3::query(const Variant &query) {
    return this_.exec("query", query);
}

Variant SQLite3::querySingle(const Variant &query, const Variant &entire_row) {
    return this_.exec("querySingle", query, entire_row);
}

Variant SQLite3::createFunction(const Variant &name, const Variant &callback, const Variant &arg_count, const Variant &flags) {
    return this_.exec("createFunction", name, callback, arg_count, flags);
}

Variant SQLite3::createAggregate(const Variant &name, const Variant &step_callback, const Variant &final_callback, const Variant &arg_count) {
    return this_.exec("createAggregate", name, step_callback, final_callback, arg_count);
}

Variant SQLite3::createCollation(const Variant &name, const Variant &callback) {
    return this_.exec("createCollation", name, callback);
}

Variant SQLite3::openBlob(const Variant &table, const Variant &column, const Variant &rowid, const Variant &database, const Variant &flags) {
    return this_.exec("openBlob", table, column, rowid, database, flags);
}

Variant SQLite3::enableExceptions(const Variant &enable) {
    return this_.exec("enableExceptions", enable);
}

Variant SQLite3::enableExtendedResultCodes(const Variant &enable) {
    return this_.exec("enableExtendedResultCodes", enable);
}

Variant SQLite3::setAuthorizer(const Variant &callback) {
    return this_.exec("setAuthorizer", callback);
}


Variant SQLite3Stmt::bindParam(const Variant &param, const Variant &var, const Variant &type) {
    return this_.exec("bindParam", param, var, type);
}

Variant SQLite3Stmt::bindValue(const Variant &param, const Variant &value, const Variant &type) {
    return this_.exec("bindValue", param, value, type);
}

Variant SQLite3Stmt::clear() {
    return this_.exec("clear");
}

Variant SQLite3Stmt::close() {
    return this_.exec("close");
}

Variant SQLite3Stmt::execute() {
    return this_.exec("execute");
}

Variant SQLite3Stmt::getSQL(const Variant &expand) {
    return this_.exec("getSQL", expand);
}

Variant SQLite3Stmt::paramCount() {
    return this_.exec("paramCount");
}

Variant SQLite3Stmt::readOnly() {
    return this_.exec("readOnly");
}

Variant SQLite3Stmt::reset() {
    return this_.exec("reset");
}


Variant SQLite3Result::numColumns() {
    return this_.exec("numColumns");
}

Variant SQLite3Result::columnName(const Variant &column) {
    return this_.exec("columnName", column);
}

Variant SQLite3Result::columnType(const Variant &column) {
    return this_.exec("columnType", column);
}

Variant SQLite3Result::fetchArray(const Variant &mode) {
    return this_.exec("fetchArray", mode);
}

Variant SQLite3Result::reset() {
    return this_.exec("reset");
}

Variant SQLite3Result::finalize() {
    return this_.exec("finalize");
}


}

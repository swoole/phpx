#include "phpx.h"
#include "class/sqlite3.h"

namespace php {
SQLite3::SQLite3(const Variant &filename, const Variant &flags, const Variant &encryption_key) {
    _this = newObject("SQLite3", filename, flags, encryption_key);
}

Variant SQLite3::open(const Variant &filename, const Variant &flags, const Variant &encryption_key) {
    return std::move(_this.exec("open", filename, flags, encryption_key));
}

Variant SQLite3::close() {
    return std::move(_this.exec("close"));
}

Variant SQLite3::version() {
    static Variant fn { ZEND_STRL("SQLite3::version"), true };
    return fn();
}

Variant SQLite3::lastInsertRowID() {
    return std::move(_this.exec("lastInsertRowID"));
}

Variant SQLite3::lastErrorCode() {
    return std::move(_this.exec("lastErrorCode"));
}

Variant SQLite3::lastExtendedErrorCode() {
    return std::move(_this.exec("lastExtendedErrorCode"));
}

Variant SQLite3::lastErrorMsg() {
    return std::move(_this.exec("lastErrorMsg"));
}

Variant SQLite3::changes() {
    return std::move(_this.exec("changes"));
}

Variant SQLite3::busyTimeout(const Variant &milliseconds) {
    return std::move(_this.exec("busyTimeout", milliseconds));
}

Variant SQLite3::loadExtension(const Variant &name) {
    return std::move(_this.exec("loadExtension", name));
}

Variant SQLite3::backup(const Variant &destination, const Variant &source_database, const Variant &destination_database) {
    return std::move(_this.exec("backup", destination, source_database, destination_database));
}

Variant SQLite3::escapeString(const Variant &string) {
    static Variant fn { ZEND_STRL("SQLite3::escapeString"), true };
    return fn(string);
}

Variant SQLite3::prepare(const Variant &query) {
    return std::move(_this.exec("prepare", query));
}

Variant SQLite3::exec(const Variant &query) {
    return std::move(_this.exec("exec", query));
}

Variant SQLite3::query(const Variant &query) {
    return std::move(_this.exec("query", query));
}

Variant SQLite3::querySingle(const Variant &query, const Variant &entire_row) {
    return std::move(_this.exec("querySingle", query, entire_row));
}

Variant SQLite3::createFunction(const Variant &name, const Variant &callback, const Variant &arg_count, const Variant &flags) {
    return std::move(_this.exec("createFunction", name, callback, arg_count, flags));
}

Variant SQLite3::createAggregate(const Variant &name, const Variant &step_callback, const Variant &final_callback, const Variant &arg_count) {
    return std::move(_this.exec("createAggregate", name, step_callback, final_callback, arg_count));
}

Variant SQLite3::createCollation(const Variant &name, const Variant &callback) {
    return std::move(_this.exec("createCollation", name, callback));
}

Variant SQLite3::openBlob(const Variant &table, const Variant &column, const Variant &rowid, const Variant &database, const Variant &flags) {
    return std::move(_this.exec("openBlob", table, column, rowid, database, flags));
}

Variant SQLite3::enableExceptions(const Variant &enable) {
    return std::move(_this.exec("enableExceptions", enable));
}

Variant SQLite3::enableExtendedResultCodes(const Variant &enable) {
    return std::move(_this.exec("enableExtendedResultCodes", enable));
}

Variant SQLite3::setAuthorizer(const Variant &callback) {
    return std::move(_this.exec("setAuthorizer", callback));
}


Variant SQLite3Stmt::bindParam(const Variant &param, const Variant &var, const Variant &type) {
    return std::move(_this.exec("bindParam", param, var, type));
}

Variant SQLite3Stmt::bindValue(const Variant &param, const Variant &value, const Variant &type) {
    return std::move(_this.exec("bindValue", param, value, type));
}

Variant SQLite3Stmt::clear() {
    return std::move(_this.exec("clear"));
}

Variant SQLite3Stmt::close() {
    return std::move(_this.exec("close"));
}

Variant SQLite3Stmt::execute() {
    return std::move(_this.exec("execute"));
}

Variant SQLite3Stmt::getSQL(const Variant &expand) {
    return std::move(_this.exec("getSQL", expand));
}

Variant SQLite3Stmt::paramCount() {
    return std::move(_this.exec("paramCount"));
}

Variant SQLite3Stmt::readOnly() {
    return std::move(_this.exec("readOnly"));
}

Variant SQLite3Stmt::reset() {
    return std::move(_this.exec("reset"));
}


Variant SQLite3Result::numColumns() {
    return std::move(_this.exec("numColumns"));
}

Variant SQLite3Result::columnName(const Variant &column) {
    return std::move(_this.exec("columnName", column));
}

Variant SQLite3Result::columnType(const Variant &column) {
    return std::move(_this.exec("columnType", column));
}

Variant SQLite3Result::fetchArray(const Variant &mode) {
    return std::move(_this.exec("fetchArray", mode));
}

Variant SQLite3Result::reset() {
    return std::move(_this.exec("reset"));
}

Variant SQLite3Result::finalize() {
    return std::move(_this.exec("finalize"));
}


}

#include "phpx.h"
#include "class/pdo_sqlite.h"

namespace php {
Variant Pdo_Sqlite::createAggregate(const Variant &name,
                                    const Variant &step,
                                    const Variant &finalize,
                                    const Variant &num_args) {
    return this_.exec(LITERAL_STRING[854], {name, step, finalize, num_args});
}
Variant Pdo_Sqlite::createCollation(const Variant &name, const Variant &callback) {
    return this_.exec(LITERAL_STRING[855], {name, callback});
}
Variant Pdo_Sqlite::createFunction(const Variant &function_name,
                                   const Variant &callback,
                                   const Variant &num_args,
                                   const Variant &flags) {
    return this_.exec(LITERAL_STRING[856], {function_name, callback, num_args, flags});
}
Variant Pdo_Sqlite::loadExtension(const Variant &name) {
    return this_.exec(LITERAL_STRING[857], {name});
}
Variant Pdo_Sqlite::openBlob(
    const Variant &table, const Variant &column, const Variant &rowid, const Variant &dbname, const Variant &flags) {
    return this_.exec(LITERAL_STRING[858], {table, column, rowid, dbname, flags});
}
Pdo_Sqlite::Pdo_Sqlite(const Variant &dsn, const Variant &username, const Variant &password, const Variant &options) {
    this_ = newObject(LITERAL_STRING[859], {dsn, username, password, options});
}
Variant Pdo_Sqlite::connect(const Variant &dsn,
                            const Variant &username,
                            const Variant &password,
                            const Variant &options) {
    return php::call(LITERAL_STRING[860], {dsn, username, password, options});
}
Variant Pdo_Sqlite::beginTransaction() {
    return this_.exec(LITERAL_STRING[823], {});
}
Variant Pdo_Sqlite::commit() {
    return this_.exec(LITERAL_STRING[824], {});
}
Variant Pdo_Sqlite::errorCode() {
    return this_.exec(LITERAL_STRING[825], {});
}
Variant Pdo_Sqlite::errorInfo() {
    return this_.exec(LITERAL_STRING[826], {});
}
Variant Pdo_Sqlite::exec(const Variant &statement) {
    return this_.exec(LITERAL_STRING[827], {statement});
}
Variant Pdo_Sqlite::getAttribute(const Variant &attribute) {
    return this_.exec(LITERAL_STRING[430], {attribute});
}
Variant Pdo_Sqlite::getAvailableDrivers() {
    return php::call(LITERAL_STRING[861], {});
}
Variant Pdo_Sqlite::inTransaction() {
    return this_.exec(LITERAL_STRING[829], {});
}
Variant Pdo_Sqlite::lastInsertId(const Variant &name) {
    return this_.exec(LITERAL_STRING[830], {name});
}
Variant Pdo_Sqlite::prepare(const Variant &query, const Variant &options) {
    return this_.exec(LITERAL_STRING[831], {query, options});
}
Variant Pdo_Sqlite::quote(const Variant &string, const Variant &type) {
    return this_.exec(LITERAL_STRING[832], {string, type});
}
Variant Pdo_Sqlite::rollBack() {
    return this_.exec(LITERAL_STRING[833], {});
}
Variant Pdo_Sqlite::setAttribute(const Variant &attribute, const Variant &value) {
    return this_.exec(LITERAL_STRING[440], {attribute, value});
}
}  // namespace php

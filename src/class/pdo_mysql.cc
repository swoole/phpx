#include "phpx.h"
#include "class/pdo_mysql.h"

namespace php {
Variant Pdo_Mysql::getWarningCount() {
    return this_.call(LITERAL_STRING[850], {});
}
Pdo_Mysql::Pdo_Mysql(const Variant &dsn, const Variant &username, const Variant &password, const Variant &options) {
    this_ = newObject(LITERAL_STRING[851], {dsn, username, password, options});
}
Variant Pdo_Mysql::connect(const Variant &dsn,
                           const Variant &username,
                           const Variant &password,
                           const Variant &options) {
    return php::call(LITERAL_STRING[852], {dsn, username, password, options});
}
Variant Pdo_Mysql::beginTransaction() {
    return this_.call(LITERAL_STRING[823], {});
}
Variant Pdo_Mysql::commit() {
    return this_.call(LITERAL_STRING[824], {});
}
Variant Pdo_Mysql::errorCode() {
    return this_.call(LITERAL_STRING[825], {});
}
Variant Pdo_Mysql::errorInfo() {
    return this_.call(LITERAL_STRING[826], {});
}
Variant Pdo_Mysql::exec(const Variant &statement) {
    return this_.call(LITERAL_STRING[827], {statement});
}
Variant Pdo_Mysql::getAttribute(const Variant &attribute) {
    return this_.call(LITERAL_STRING[430], {attribute});
}
Variant Pdo_Mysql::getAvailableDrivers() {
    return php::call(LITERAL_STRING[853], {});
}
Variant Pdo_Mysql::inTransaction() {
    return this_.call(LITERAL_STRING[829], {});
}
Variant Pdo_Mysql::lastInsertId(const Variant &name) {
    return this_.call(LITERAL_STRING[830], {name});
}
Variant Pdo_Mysql::prepare(const Variant &query, const Variant &options) {
    return this_.call(LITERAL_STRING[831], {query, options});
}
Variant Pdo_Mysql::quote(const Variant &string, const Variant &type) {
    return this_.call(LITERAL_STRING[832], {string, type});
}
Variant Pdo_Mysql::rollBack() {
    return this_.call(LITERAL_STRING[833], {});
}
Variant Pdo_Mysql::setAttribute(const Variant &attribute, const Variant &value) {
    return this_.call(LITERAL_STRING[440], {attribute, value});
}
}  // namespace php

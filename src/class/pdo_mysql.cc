#include "phpx.h"
#include "class/pdo_mysql.h"

namespace php {
Variant Pdo_Mysql::getWarningCount() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[890]);
    }
    return this_.call(_method_fn, {});
}
Pdo_Mysql::Pdo_Mysql(const Variant &dsn, const Variant &username, const Variant &password, const Variant &options) {
    this_ = newObject(LITERAL_STRING[891], {dsn, username, password, options});
}
Variant Pdo_Mysql::connect(const Variant &dsn,
                           const Variant &username,
                           const Variant &password,
                           const Variant &options) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(LITERAL_STRING[893], LITERAL_STRING[861]);
    }
    return php::call(_method_fn, {dsn, username, password, options});
}
Variant Pdo_Mysql::beginTransaction() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[862]);
    }
    return this_.call(_method_fn, {});
}
Variant Pdo_Mysql::commit() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[863]);
    }
    return this_.call(_method_fn, {});
}
Variant Pdo_Mysql::errorCode() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[864]);
    }
    return this_.call(_method_fn, {});
}
Variant Pdo_Mysql::errorInfo() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[865]);
    }
    return this_.call(_method_fn, {});
}
Variant Pdo_Mysql::exec(const Variant &statement) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[866]);
    }
    return this_.call(_method_fn, {statement});
}
Variant Pdo_Mysql::getAttribute(const Variant &attribute) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[459]);
    }
    return this_.call(_method_fn, {attribute});
}
Variant Pdo_Mysql::getAvailableDrivers() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(LITERAL_STRING[893], LITERAL_STRING[868]);
    }
    return php::call(_method_fn, {});
}
Variant Pdo_Mysql::inTransaction() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[869]);
    }
    return this_.call(_method_fn, {});
}
Variant Pdo_Mysql::lastInsertId(const Variant &name) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[870]);
    }
    return this_.call(_method_fn, {name});
}
Variant Pdo_Mysql::prepare(const Variant &query, const Variant &options) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[871]);
    }
    return this_.call(_method_fn, {query, options});
}
Variant Pdo_Mysql::quote(const Variant &string, const Variant &type) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[511]);
    }
    return this_.call(_method_fn, {string, type});
}
Variant Pdo_Mysql::rollBack() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[872]);
    }
    return this_.call(_method_fn, {});
}
Variant Pdo_Mysql::setAttribute(const Variant &attribute, const Variant &value) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[469]);
    }
    return this_.call(_method_fn, {attribute, value});
}
}  // namespace php

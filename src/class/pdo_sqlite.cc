#include "phpx.h"
#include "class/pdo_sqlite.h"

namespace php {
Variant Pdo_Sqlite::createAggregate(const Variant &name,
                                    const Variant &step,
                                    const Variant &finalize,
                                    const Variant &num_args) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[895]);
    }
    return this_.call(_method_fn, {name, step, finalize, num_args});
}
Variant Pdo_Sqlite::createCollation(const Variant &name, const Variant &callback) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[896]);
    }
    return this_.call(_method_fn, {name, callback});
}
Variant Pdo_Sqlite::createFunction(const Variant &function_name,
                                   const Variant &callback,
                                   const Variant &num_args,
                                   const Variant &flags) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[897]);
    }
    return this_.call(_method_fn, {function_name, callback, num_args, flags});
}
Variant Pdo_Sqlite::loadExtension(const Variant &name) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[898]);
    }
    return this_.call(_method_fn, {name});
}
Variant Pdo_Sqlite::openBlob(
    const Variant &table, const Variant &column, const Variant &rowid, const Variant &dbname, const Variant &flags) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[899]);
    }
    return this_.call(_method_fn, {table, column, rowid, dbname, flags});
}
Pdo_Sqlite::Pdo_Sqlite(const Variant &dsn, const Variant &username, const Variant &password, const Variant &options) {
    this_ = newObject(LITERAL_STRING[900], {dsn, username, password, options});
}
Variant Pdo_Sqlite::connect(const Variant &dsn,
                            const Variant &username,
                            const Variant &password,
                            const Variant &options) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(LITERAL_STRING[902], LITERAL_STRING[861]);
    }
    return php::call(_method_fn, {dsn, username, password, options});
}
Variant Pdo_Sqlite::beginTransaction() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[862]);
    }
    return this_.call(_method_fn, {});
}
Variant Pdo_Sqlite::commit() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[863]);
    }
    return this_.call(_method_fn, {});
}
Variant Pdo_Sqlite::errorCode() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[864]);
    }
    return this_.call(_method_fn, {});
}
Variant Pdo_Sqlite::errorInfo() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[865]);
    }
    return this_.call(_method_fn, {});
}
Variant Pdo_Sqlite::exec(const Variant &statement) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[866]);
    }
    return this_.call(_method_fn, {statement});
}
Variant Pdo_Sqlite::getAttribute(const Variant &attribute) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[459]);
    }
    return this_.call(_method_fn, {attribute});
}
Variant Pdo_Sqlite::getAvailableDrivers() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(LITERAL_STRING[902], LITERAL_STRING[868]);
    }
    return php::call(_method_fn, {});
}
Variant Pdo_Sqlite::inTransaction() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[869]);
    }
    return this_.call(_method_fn, {});
}
Variant Pdo_Sqlite::lastInsertId(const Variant &name) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[870]);
    }
    return this_.call(_method_fn, {name});
}
Variant Pdo_Sqlite::prepare(const Variant &query, const Variant &options) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[871]);
    }
    return this_.call(_method_fn, {query, options});
}
Variant Pdo_Sqlite::quote(const Variant &string, const Variant &type) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[511]);
    }
    return this_.call(_method_fn, {string, type});
}
Variant Pdo_Sqlite::rollBack() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[872]);
    }
    return this_.call(_method_fn, {});
}
Variant Pdo_Sqlite::setAttribute(const Variant &attribute, const Variant &value) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[469]);
    }
    return this_.call(_method_fn, {attribute, value});
}
}  // namespace php

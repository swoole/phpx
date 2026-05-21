#include "phpx.h"
#include "phpx_class.h"
#include "class/pdo_sqlite.h"

namespace php {
Variant Pdo_Sqlite::createAggregate(const Variant &name,
                                    const Variant &step,
                                    const Variant &finalize,
                                    const Variant &num_args) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1067]);
    }
    return this_.call(_method_fn, {name, step, finalize, num_args});
}
Variant Pdo_Sqlite::createCollation(const Variant &name, const Variant &callback) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1068]);
    }
    return this_.call(_method_fn, {name, callback});
}
Variant Pdo_Sqlite::createFunction(const Variant &function_name,
                                   const Variant &callback,
                                   const Variant &num_args,
                                   const Variant &flags) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1069]);
    }
    return this_.call(_method_fn, {function_name, callback, num_args, flags});
}
Variant Pdo_Sqlite::loadExtension(const Variant &name) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1070]);
    }
    return this_.call(_method_fn, {name});
}
Variant Pdo_Sqlite::openBlob(
    const Variant &table, const Variant &column, const Variant &rowid, const Variant &dbname, const Variant &flags) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1071]);
    }
    return this_.call(_method_fn, {table, column, rowid, dbname, flags});
}
Pdo_Sqlite::Pdo_Sqlite(const Variant &dsn, const Variant &username, const Variant &password, const Variant &options) {
    this_ = newObject(LITERAL_STRING[1072], {dsn, username, password, options});
}
}  // namespace php

#include "phpx.h"
#include "phpx_class.h"
#include "class/pdo_sqlite.h"

namespace php::Pdo {
Variant Sqlite::createAggregate(const Variant &name,
                                const Variant &step,
                                const Variant &finalize,
                                const Variant &num_args) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1062]);
    }
    return this_.call(_method_fn, {name, step, finalize, num_args});
}
Variant Sqlite::createCollation(const Variant &name, const Variant &callback) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1063]);
    }
    return this_.call(_method_fn, {name, callback});
}
Variant Sqlite::createFunction(const Variant &function_name,
                               const Variant &callback,
                               const Variant &num_args,
                               const Variant &flags) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1064]);
    }
    return this_.call(_method_fn, {function_name, callback, num_args, flags});
}
Variant Sqlite::loadExtension(const Variant &name) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1065]);
    }
    return this_.call(_method_fn, {name});
}
Variant Sqlite::openBlob(
    const Variant &table, const Variant &column, const Variant &rowid, const Variant &dbname, const Variant &flags) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1066]);
    }
    return this_.call(_method_fn, {table, column, rowid, dbname, flags});
}
Sqlite::Sqlite(const Variant &dsn, const Variant &username, const Variant &password, const Variant &options) {
    this_ = newObject(LITERAL_STRING[1067], {dsn, username, password, options});
}
}  // namespace php::Pdo

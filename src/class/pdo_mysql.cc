#include "phpx.h"
#include "class/pdo_mysql.h"
#include "class/pdo.h"

namespace php::Pdo {
Variant Mysql::getWarningCount() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1098]);
    }
    return this_.call(_method_fn, {});
}
Mysql::Mysql(const Variant &dsn, const Variant &username, const Variant &password, const Variant &options) {
    this_ = newObject(LITERAL_STRING[1099], {dsn, username, password, options});
}
}  // namespace php::Pdo

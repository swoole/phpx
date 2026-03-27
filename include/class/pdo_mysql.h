#include "phpx_literal_string.h"

namespace php {
class Pdo_Mysql {
    Object this_;

  public:
    Variant getWarningCount();
    Pdo_Mysql(const Variant &dsn,
              const Variant &username = {},
              const Variant &password = {},
              const Variant &options = {});
    static Variant connect(const Variant &dsn,
                           const Variant &username = {},
                           const Variant &password = {},
                           const Variant &options = {});
    Variant beginTransaction();
    Variant commit();
    Variant errorCode();
    Variant errorInfo();
    Variant exec(const Variant &statement);
    Variant getAttribute(const Variant &attribute);
    static Variant getAvailableDrivers();
    Variant inTransaction();
    Variant lastInsertId(const Variant &name = {});
    Variant prepare(const Variant &query, const Variant &options = Array{});
    template <typename... Args>
    Variant query(const Variant &query, const Variant &fetch_mode, const Args &...fetch_mode_args) {
        return this_.call(LITERAL_STRING[477], {query, fetch_mode, fetch_mode_args...});
    }
    Variant quote(const Variant &string, const Variant &type = 2);
    Variant rollBack();
    Variant setAttribute(const Variant &attribute, const Variant &value);
};

}  // namespace php

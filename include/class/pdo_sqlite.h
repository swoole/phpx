#include "phpx_literal_string.h"

namespace php {
class Pdo_Sqlite {
    Object this_;

  public:
    Variant createAggregate(const Variant &name,
                            const Variant &step,
                            const Variant &finalize,
                            const Variant &num_args = -1);
    Variant createCollation(const Variant &name, const Variant &callback);
    Variant createFunction(const Variant &function_name,
                           const Variant &callback,
                           const Variant &num_args = -1,
                           const Variant &flags = 0);
    Variant loadExtension(const Variant &name);
    Variant openBlob(const Variant &table,
                     const Variant &column,
                     const Variant &rowid,
                     const Variant &dbname = "main",
                     const Variant &flags = 1);
    Pdo_Sqlite(const Variant &dsn,
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
        return this_.exec(LITERAL_STRING[477], {query, fetch_mode, fetch_mode_args...});
    }
    Variant quote(const Variant &string, const Variant &type = 2);
    Variant rollBack();
    Variant setAttribute(const Variant &attribute, const Variant &value);
};

}  // namespace php

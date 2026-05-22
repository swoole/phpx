#pragma once

#include "phpx.h"
#include "phpx_literal_string.h"
#include "class/pdo.h"

namespace php {
namespace Pdo {
class Sqlite;
}

namespace Pdo {

class Sqlite : public PDO {
  protected:
    Sqlite() = default;

  public:
    static constexpr int DETERMINISTIC = 2048;
    static constexpr int OPEN_READONLY = 1;
    static constexpr int OPEN_READWRITE = 2;
    static constexpr int OPEN_CREATE = 4;
    static constexpr int ATTR_OPEN_FLAGS = 1000;
    static constexpr int ATTR_READONLY_STATEMENT = 1001;
    static constexpr int ATTR_EXTENDED_RESULT_CODES = 1002;

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
    Sqlite(const Variant &dsn,
           const Variant &username = nullptr,
           const Variant &password = nullptr,
           const Variant &options = nullptr);
};

}  // namespace Pdo
}  // namespace php

#pragma once

#include "phpx.h"
#include "phpx_literal_string.h"
#include "class/core.h"

namespace php {
class SQLite3Exception;
class SQLite3Result;
class SQLite3Stmt;
class SQLite3;

class SQLite3Exception : public Exception {
  public:
    SQLite3Exception(const Variant &message = "", const Variant &code = 0, const Variant &previous = nullptr);
};

class SQLite3Result {
  protected:
    Object this_;

  public:
    Object getObject() const {
        return this_;
    }
    Variant numColumns();
    Variant columnName(const Variant &column);
    Variant columnType(const Variant &column);
    Variant fetchArray(const Variant &mode = 3);
    Variant reset();
    Variant finalize();
};

class SQLite3Stmt {
  protected:
    Object this_;
    SQLite3Stmt() = default;

  public:
    Object getObject() const {
        return this_;
    }
    Variant bindParam(const Variant &param, const Reference &var, const Variant &type = 3);
    Variant bindValue(const Variant &param, const Variant &value, const Variant &type = 3);
    Variant clear();
    Variant close();
    Variant execute();
    Variant getSQL(const Variant &expand = false);
    Variant paramCount();
    Variant readOnly();
    Variant reset();
};

class SQLite3 {
  protected:
    Object this_;
    SQLite3() = default;

  public:
    Object getObject() const {
        return this_;
    }
    static constexpr int OK = 0;
    static constexpr int DENY = 1;
    static constexpr int IGNORE = 2;
    static constexpr int CREATE_INDEX = 1;
    static constexpr int CREATE_TABLE = 2;
    static constexpr int CREATE_TEMP_INDEX = 3;
    static constexpr int CREATE_TEMP_TABLE = 4;
    static constexpr int CREATE_TEMP_TRIGGER = 5;
    static constexpr int CREATE_TEMP_VIEW = 6;
    static constexpr int CREATE_TRIGGER = 7;
    static constexpr int CREATE_VIEW = 8;
    static constexpr int DELETE = 9;
    static constexpr int DROP_INDEX = 10;
    static constexpr int DROP_TABLE = 11;
    static constexpr int DROP_TEMP_INDEX = 12;
    static constexpr int DROP_TEMP_TABLE = 13;
    static constexpr int DROP_TEMP_TRIGGER = 14;
    static constexpr int DROP_TEMP_VIEW = 15;
    static constexpr int DROP_TRIGGER = 16;
    static constexpr int DROP_VIEW = 17;
    static constexpr int INSERT = 18;
    static constexpr int PRAGMA = 19;
    static constexpr int READ = 20;
    static constexpr int SELECT = 21;
    static constexpr int TRANSACTION = 22;
    static constexpr int UPDATE = 23;
    static constexpr int ATTACH = 24;
    static constexpr int DETACH = 25;
    static constexpr int ALTER_TABLE = 26;
    static constexpr int REINDEX = 27;
    static constexpr int ANALYZE = 28;
    static constexpr int CREATE_VTABLE = 29;
    static constexpr int DROP_VTABLE = 30;
    static constexpr int FUNCTION = 31;
    static constexpr int SAVEPOINT = 32;
    static constexpr int COPY = 0;
    static constexpr int RECURSIVE = 33;

    SQLite3(const Variant &filename, const Variant &flags = 6, const Variant &encryption_key = "");
    Variant open(const Variant &filename, const Variant &flags = 6, const Variant &encryption_key = "");
    Variant close();
    static Variant version();
    Variant lastInsertRowID();
    Variant lastErrorCode();
    Variant lastExtendedErrorCode();
    Variant lastErrorMsg();
    Variant changes();
    Variant busyTimeout(const Variant &milliseconds);
    Variant loadExtension(const Variant &name);
    Variant backup(const SQLite3 &destination,
                   const Variant &source_database = "main",
                   const Variant &destination_database = "main");
    Variant backup(const Variant &destination,
                   const Variant &source_database = "main",
                   const Variant &destination_database = "main");
    static Variant escapeString(const Variant &string);
    Variant prepare(const Variant &query);
    Variant exec(const Variant &query);
    Variant query(const Variant &query);
    Variant querySingle(const Variant &query, const Variant &entire_row = false);
    Variant createFunction(const Variant &name,
                           const Variant &callback,
                           const Variant &arg_count = -1,
                           const Variant &flags = 0);
    Variant createAggregate(const Variant &name,
                            const Variant &step_callback,
                            const Variant &final_callback,
                            const Variant &arg_count = -1);
    Variant createCollation(const Variant &name, const Variant &callback);
    Variant openBlob(const Variant &table,
                     const Variant &column,
                     const Variant &rowid,
                     const Variant &database = "main",
                     const Variant &flags = 1);
    Variant enableExceptions(const Variant &enable = false);
    Variant enableExtendedResultCodes(const Variant &enable = true);
    Variant setAuthorizer(const Variant &callback);
};

}  // namespace php

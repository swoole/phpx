#pragma once

#include "phpx.h"
#include "phpx_literal_string.h"
#include "class/spl.h"

namespace php {
class PDOException;
class PDOStatement;
class PDO;
class PDORow;

class PDOException : public RuntimeException {
  public:
    PDOException(const Variant &message = "", const Variant &code = 0, const Variant &previous = {});
};

class PDOStatement {
  protected:
    Object this_;

  public:
    Object getObject() const {
        return this_;
    }
    explicit PDOStatement(const Object &obj) : this_(obj) {}
    PDOStatement();
    Variant bindColumn(const Variant &column,
                       const Reference &var,
                       const Variant &type = 2,
                       const Variant &max_length = 0,
                       const Variant &driver_options = {});
    Variant bindParam(const Variant &param,
                      const Reference &var,
                      const Variant &type = 2,
                      const Variant &max_length = 0,
                      const Variant &driver_options = {});
    Variant bindValue(const Variant &param, const Variant &value, const Variant &type = 2);
    Variant closeCursor();
    Variant columnCount();
    Variant debugDumpParams();
    Variant errorCode();
    Variant errorInfo();
    Variant execute(const Variant &params = {});
    Variant fetch(const Variant &mode = 0, const Variant &cursor_orientation = 0, const Variant &cursor_offset = 0);
    template <typename... Args>
    Variant fetchAll(const Variant &mode, const Args &...args) {
        static THREAD_LOCAL zend_function *_method_fn = nullptr;
        if (UNEXPECTED(!_method_fn)) {
            _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1090]);
        }
        return this_.call(_method_fn, {mode, args...});
    }
    Variant fetchColumn(const Variant &column = 0);
    Variant fetchObject(const Variant &class_ = "stdClass", const Variant &constructor_args = Array{});
    Variant getAttribute(const Variant &name);
    Variant getColumnMeta(const Variant &column);
    Variant nextRowset();
    Variant rowCount();
    Variant setAttribute(const Variant &attribute, const Variant &value);
    template <typename... Args>
    Variant setFetchMode(const Variant &mode, const Args &...args) {
        static THREAD_LOCAL zend_function *_method_fn = nullptr;
        if (UNEXPECTED(!_method_fn)) {
            _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1096]);
        }
        return this_.call(_method_fn, {mode, args...});
    }
    Variant getIterator();
};

class PDO {
  protected:
    Object this_;
    PDO() = default;

  public:
    Object getObject() const {
        return this_;
    }
    static constexpr int PARAM_NULL = 0;
    static constexpr int PARAM_BOOL = 5;
    static constexpr int PARAM_INT = 1;
    static constexpr int PARAM_STR = 2;
    static constexpr int PARAM_LOB = 3;
    static constexpr int PARAM_STMT = 4;
    static constexpr int PARAM_INPUT_OUTPUT = 2147483648;
    static constexpr int PARAM_STR_NATL = 1073741824;
    static constexpr int PARAM_STR_CHAR = 536870912;
    static constexpr int PARAM_EVT_ALLOC = 0;
    static constexpr int PARAM_EVT_FREE = 1;
    static constexpr int PARAM_EVT_EXEC_PRE = 2;
    static constexpr int PARAM_EVT_EXEC_POST = 3;
    static constexpr int PARAM_EVT_FETCH_PRE = 4;
    static constexpr int PARAM_EVT_FETCH_POST = 5;
    static constexpr int PARAM_EVT_NORMALIZE = 6;
    static constexpr int FETCH_DEFAULT = 0;
    static constexpr int FETCH_LAZY = 1;
    static constexpr int FETCH_ASSOC = 2;
    static constexpr int FETCH_NUM = 3;
    static constexpr int FETCH_BOTH = 4;
    static constexpr int FETCH_OBJ = 5;
    static constexpr int FETCH_BOUND = 6;
    static constexpr int FETCH_COLUMN = 7;
    static constexpr int FETCH_CLASS = 8;
    static constexpr int FETCH_INTO = 9;
    static constexpr int FETCH_FUNC = 10;
    static constexpr int FETCH_GROUP = 65536;
    static constexpr int FETCH_UNIQUE = 196608;
    static constexpr int FETCH_KEY_PAIR = 12;
    static constexpr int FETCH_CLASSTYPE = 262144;
    static constexpr int FETCH_SERIALIZE = 524288;
    static constexpr int FETCH_PROPS_LATE = 1048576;
    static constexpr int FETCH_NAMED = 11;
    static constexpr int ATTR_AUTOCOMMIT = 0;
    static constexpr int ATTR_PREFETCH = 1;
    static constexpr int ATTR_TIMEOUT = 2;
    static constexpr int ATTR_ERRMODE = 3;
    static constexpr int ATTR_SERVER_VERSION = 4;
    static constexpr int ATTR_CLIENT_VERSION = 5;
    static constexpr int ATTR_SERVER_INFO = 6;
    static constexpr int ATTR_CONNECTION_STATUS = 7;
    static constexpr int ATTR_CASE = 8;
    static constexpr int ATTR_CURSOR_NAME = 9;
    static constexpr int ATTR_CURSOR = 10;
    static constexpr int ATTR_ORACLE_NULLS = 11;
    static constexpr int ATTR_PERSISTENT = 12;
    static constexpr int ATTR_STATEMENT_CLASS = 13;
    static constexpr int ATTR_FETCH_TABLE_NAMES = 14;
    static constexpr int ATTR_FETCH_CATALOG_NAMES = 15;
    static constexpr int ATTR_DRIVER_NAME = 16;
    static constexpr int ATTR_STRINGIFY_FETCHES = 17;
    static constexpr int ATTR_MAX_COLUMN_LEN = 18;
    static constexpr int ATTR_EMULATE_PREPARES = 20;
    static constexpr int ATTR_DEFAULT_FETCH_MODE = 19;
    static constexpr int ATTR_DEFAULT_STR_PARAM = 21;
    static constexpr int ERRMODE_SILENT = 0;
    static constexpr int ERRMODE_WARNING = 1;
    static constexpr int ERRMODE_EXCEPTION = 2;
    static constexpr int CASE_NATURAL = 0;
    static constexpr int CASE_LOWER = 2;
    static constexpr int CASE_UPPER = 1;
    static constexpr int NULL_NATURAL = 0;
    static constexpr int NULL_EMPTY_STRING = 1;
    static constexpr int NULL_TO_STRING = 2;
    static inline const Variant ERR_NONE{ZEND_STRL("00000"), true};
    static constexpr int FETCH_ORI_NEXT = 0;
    static constexpr int FETCH_ORI_PRIOR = 1;
    static constexpr int FETCH_ORI_FIRST = 2;
    static constexpr int FETCH_ORI_LAST = 3;
    static constexpr int FETCH_ORI_ABS = 4;
    static constexpr int FETCH_ORI_REL = 5;
    static constexpr int CURSOR_FWDONLY = 0;
    static constexpr int CURSOR_SCROLL = 1;
    static constexpr int SQLITE_DETERMINISTIC = 2048;
    static constexpr int SQLITE_ATTR_OPEN_FLAGS = 1000;
    static constexpr int SQLITE_OPEN_READONLY = 1;
    static constexpr int SQLITE_OPEN_READWRITE = 2;
    static constexpr int SQLITE_OPEN_CREATE = 4;
    static constexpr int SQLITE_ATTR_READONLY_STATEMENT = 1001;
    static constexpr int SQLITE_ATTR_EXTENDED_RESULT_CODES = 1002;
    static constexpr int MYSQL_ATTR_USE_BUFFERED_QUERY = 1000;
    static constexpr int MYSQL_ATTR_LOCAL_INFILE = 1001;
    static constexpr int MYSQL_ATTR_INIT_COMMAND = 1002;
    static constexpr int MYSQL_ATTR_COMPRESS = 1003;
    static constexpr int MYSQL_ATTR_DIRECT_QUERY = 1004;
    static constexpr int MYSQL_ATTR_FOUND_ROWS = 1005;
    static constexpr int MYSQL_ATTR_IGNORE_SPACE = 1006;
    static constexpr int MYSQL_ATTR_SSL_KEY = 1007;
    static constexpr int MYSQL_ATTR_SSL_CERT = 1008;
    static constexpr int MYSQL_ATTR_SSL_CA = 1009;
    static constexpr int MYSQL_ATTR_SSL_CAPATH = 1010;
    static constexpr int MYSQL_ATTR_SSL_CIPHER = 1011;
    static constexpr int MYSQL_ATTR_SERVER_PUBLIC_KEY = 1012;
    static constexpr int MYSQL_ATTR_MULTI_STATEMENTS = 1013;
    static constexpr int MYSQL_ATTR_SSL_VERIFY_SERVER_CERT = 1014;
    static constexpr int MYSQL_ATTR_LOCAL_INFILE_DIRECTORY = 1015;
    static constexpr int PGSQL_ATTR_DISABLE_PREPARES = 1000;
    static constexpr int PGSQL_TRANSACTION_IDLE = 0;
    static constexpr int PGSQL_TRANSACTION_ACTIVE = 1;
    static constexpr int PGSQL_TRANSACTION_INTRANS = 2;
    static constexpr int PGSQL_TRANSACTION_INERROR = 3;
    static constexpr int PGSQL_TRANSACTION_UNKNOWN = 4;
    static constexpr int ODBC_ATTR_USE_CURSOR_LIBRARY = 1000;
    static constexpr int ODBC_ATTR_ASSUME_UTF8 = 1001;
    static constexpr int ODBC_SQL_USE_IF_NEEDED = 0;
    static constexpr int ODBC_SQL_USE_DRIVER = 2;
    static constexpr int ODBC_SQL_USE_ODBC = 1;
    static constexpr int FB_ATTR_DATE_FORMAT = 1000;
    static constexpr int FB_ATTR_TIME_FORMAT = 1001;
    static constexpr int FB_ATTR_TIMESTAMP_FORMAT = 1002;

    PDO(const Variant &dsn, const Variant &username = {}, const Variant &password = {}, const Variant &options = {});
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
    PDOStatement prepare(const Variant &query, const Variant &options = Array{});
    PDOStatement query(const Variant &query, const Variant &fetch_mode = {});
    Variant quote(const Variant &string, const Variant &type = 2);
    Variant rollBack();
    Variant setAttribute(const Variant &attribute, const Variant &value);
};

class PDORow {
  protected:
    Object this_;

  public:
    Object getObject() const {
        return this_;
    }
    explicit PDORow(const Object &obj) : this_(obj) {}
    PDORow();
};

}  // namespace php

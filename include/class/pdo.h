namespace php {
class PDOException {
    Object _this;
  public:
    PDOException(const Variant &message = "", const Variant &code = 0, const Variant &previous = {});
    Variant __wakeup();
    Variant getMessage();
    Variant getCode();
    Variant getFile();
    Variant getLine();
    Variant getTrace();
    Variant getPrevious();
    Variant getTraceAsString();
    Variant __toString();
};

class PDO {
    Object _this;
  public:
    PDO(const Variant &dsn, const Variant &username = {}, const Variant &password = {}, const Variant &options = {});
    Variant beginTransaction();
    Variant commit();
    Variant errorCode();
    Variant errorInfo();
    Variant exec(const Variant &statement);
    Variant getAttribute(const Variant &attribute);
    static Variant getAvailableDrivers();
    Variant inTransaction();
    Variant lastInsertId(const Variant &name = {});
    Variant prepare(const Variant &query, const Array &options = {});
    Variant query(const Variant &query, const Variant &fetch_mode = {}, const Variant &fetch_mode_args = {});
    Variant quote(const Variant &string, const Variant &type = 2);
    Variant rollBack();
    Variant setAttribute(const Variant &attribute, const Variant &value);
};

class PDOStatement {
    Object _this;
  public:
    Variant bindColumn(const Variant &column, const Variant &var, const Variant &type = 2, const Variant &max_length = 0, const Variant &driver_options = {});
    Variant bindParam(const Variant &param, const Variant &var, const Variant &type = 2, const Variant &max_length = 0, const Variant &driver_options = {});
    Variant bindValue(const Variant &param, const Variant &value, const Variant &type = 2);
    Variant closeCursor();
    Variant columnCount();
    Variant debugDumpParams();
    Variant errorCode();
    Variant errorInfo();
    Variant execute(const Variant &params = {});
    Variant fetch(const Variant &mode = 0, const Variant &cursor_orientation = 0, const Variant &cursor_offset = 0);
    Variant fetchAll(const Variant &mode = 0, const Variant &args = {});
    Variant fetchColumn(const Variant &column = 0);
    Variant fetchObject(const Variant &_class = "stdClass", const Array &constructor_args = {});
    Variant getAttribute(const Variant &name);
    Variant getColumnMeta(const Variant &column);
    Variant nextRowset();
    Variant rowCount();
    Variant setAttribute(const Variant &attribute, const Variant &value);
    Variant setFetchMode(const Variant &mode, const Variant &args = {});
    Variant getIterator();
};

}

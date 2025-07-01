namespace php {
class PDOException {
  private:
    Variant _this;
  public:
    PDOException(const std::initializer_list<Variant> &args);
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
  private:
    Variant _this;
  public:
    PDO(const std::initializer_list<Variant> &args);
    Variant beginTransaction();
    Variant commit();
    Variant errorCode();
    Variant errorInfo();
    Variant exec(const std::initializer_list<Variant> &args);
    Variant getAttribute(const std::initializer_list<Variant> &args);
    static Variant getAvailableDrivers();
    Variant inTransaction();
    Variant lastInsertId(const std::initializer_list<Variant> &args);
    Variant prepare(const std::initializer_list<Variant> &args);
    Variant query(const std::initializer_list<Variant> &args);
    Variant quote(const std::initializer_list<Variant> &args);
    Variant rollBack();
    Variant setAttribute(const std::initializer_list<Variant> &args);
};

class PDOStatement {
  private:
    Variant _this;
  public:
    Variant bindColumn(const std::initializer_list<Variant> &args);
    Variant bindParam(const std::initializer_list<Variant> &args);
    Variant bindValue(const std::initializer_list<Variant> &args);
    Variant closeCursor();
    Variant columnCount();
    Variant debugDumpParams();
    Variant errorCode();
    Variant errorInfo();
    Variant execute(const std::initializer_list<Variant> &args);
    Variant fetch(const std::initializer_list<Variant> &args);
    Variant fetchAll(const std::initializer_list<Variant> &args);
    Variant fetchColumn(const std::initializer_list<Variant> &args);
    Variant fetchObject(const std::initializer_list<Variant> &args);
    Variant getAttribute(const std::initializer_list<Variant> &args);
    Variant getColumnMeta(const std::initializer_list<Variant> &args);
    Variant nextRowset();
    Variant rowCount();
    Variant setAttribute(const std::initializer_list<Variant> &args);
    Variant setFetchMode(const std::initializer_list<Variant> &args);
    Variant getIterator();
};

}

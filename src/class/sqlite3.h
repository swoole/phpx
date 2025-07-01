namespace php {
class SQLite3 {
  private:
    Variant _this;
  public:
    SQLite3(const std::initializer_list<Variant> &args);
    Variant open(const std::initializer_list<Variant> &args);
    Variant close();
    static Variant version();
    Variant lastInsertRowID();
    Variant lastErrorCode();
    Variant lastExtendedErrorCode();
    Variant lastErrorMsg();
    Variant changes();
    Variant busyTimeout(const std::initializer_list<Variant> &args);
    Variant loadExtension(const std::initializer_list<Variant> &args);
    Variant backup(const std::initializer_list<Variant> &args);
    static Variant escapeString(const std::initializer_list<Variant> &args);
    Variant prepare(const std::initializer_list<Variant> &args);
    Variant exec(const std::initializer_list<Variant> &args);
    Variant query(const std::initializer_list<Variant> &args);
    Variant querySingle(const std::initializer_list<Variant> &args);
    Variant createFunction(const std::initializer_list<Variant> &args);
    Variant createAggregate(const std::initializer_list<Variant> &args);
    Variant createCollation(const std::initializer_list<Variant> &args);
    Variant openBlob(const std::initializer_list<Variant> &args);
    Variant enableExceptions(const std::initializer_list<Variant> &args);
    Variant enableExtendedResultCodes(const std::initializer_list<Variant> &args);
    Variant setAuthorizer(const std::initializer_list<Variant> &args);
};

class SQLite3Stmt {
  private:
    Variant _this;
  public:
    Variant bindParam(const std::initializer_list<Variant> &args);
    Variant bindValue(const std::initializer_list<Variant> &args);
    Variant clear();
    Variant close();
    Variant execute();
    Variant getSQL(const std::initializer_list<Variant> &args);
    Variant paramCount();
    Variant readOnly();
    Variant reset();
};

class SQLite3Result {
  private:
    Variant _this;
  public:
    Variant numColumns();
    Variant columnName(const std::initializer_list<Variant> &args);
    Variant columnType(const std::initializer_list<Variant> &args);
    Variant fetchArray(const std::initializer_list<Variant> &args);
    Variant reset();
    Variant finalize();
};

}

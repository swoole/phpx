namespace php {
class SQLite3 {
    Object this_;
  public:
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
    Variant backup(const Variant &destination, const Variant &source_database = "main", const Variant &destination_database = "main");
    static Variant escapeString(const Variant &string);
    Variant prepare(const Variant &query);
    Variant exec(const Variant &query);
    Variant query(const Variant &query);
    Variant querySingle(const Variant &query, const Variant &entire_row = false);
    Variant createFunction(const Variant &name, const Variant &callback, const Variant &arg_count = -1, const Variant &flags = 0);
    Variant createAggregate(const Variant &name, const Variant &step_callback, const Variant &final_callback, const Variant &arg_count = -1);
    Variant createCollation(const Variant &name, const Variant &callback);
    Variant openBlob(const Variant &table, const Variant &column, const Variant &rowid, const Variant &database = "main", const Variant &flags = 1);
    Variant enableExceptions(const Variant &enable = false);
    Variant enableExtendedResultCodes(const Variant &enable = true);
    Variant setAuthorizer(const Variant &callback);
};

class SQLite3Stmt {
    Object this_;
  public:
    Variant bindParam(const Variant &param, const Variant &var, const Variant &type = 3);
    Variant bindValue(const Variant &param, const Variant &value, const Variant &type = 3);
    Variant clear();
    Variant close();
    Variant execute();
    Variant getSQL(const Variant &expand = false);
    Variant paramCount();
    Variant readOnly();
    Variant reset();
};

class SQLite3Result {
    Object this_;
  public:
    Variant numColumns();
    Variant columnName(const Variant &column);
    Variant columnType(const Variant &column);
    Variant fetchArray(const Variant &mode = 3);
    Variant reset();
    Variant finalize();
};

}

namespace php {
class DateTime {
  private:
    Variant _this;
  public:
    DateTime(const std::initializer_list<Variant> &args);
    Variant __serialize();
    Variant __unserialize(const std::initializer_list<Variant> &args);
    Variant __wakeup();
    static Variant __set_state(const std::initializer_list<Variant> &args);
    static Variant createFromImmutable(const std::initializer_list<Variant> &args);
    static Variant createFromInterface(const std::initializer_list<Variant> &args);
    static Variant createFromFormat(const std::initializer_list<Variant> &args);
    static Variant getLastErrors();
    Variant format(const std::initializer_list<Variant> &args);
    Variant modify(const std::initializer_list<Variant> &args);
    Variant add(const std::initializer_list<Variant> &args);
    Variant sub(const std::initializer_list<Variant> &args);
    Variant getTimezone();
    Variant setTimezone(const std::initializer_list<Variant> &args);
    Variant getOffset();
    Variant setTime(const std::initializer_list<Variant> &args);
    Variant setDate(const std::initializer_list<Variant> &args);
    Variant setISODate(const std::initializer_list<Variant> &args);
    Variant setTimestamp(const std::initializer_list<Variant> &args);
    Variant getTimestamp();
    Variant diff(const std::initializer_list<Variant> &args);
};

class DateTimeImmutable {
  private:
    Variant _this;
  public:
    DateTimeImmutable(const std::initializer_list<Variant> &args);
    Variant __serialize();
    Variant __unserialize(const std::initializer_list<Variant> &args);
    Variant __wakeup();
    static Variant __set_state(const std::initializer_list<Variant> &args);
    static Variant createFromFormat(const std::initializer_list<Variant> &args);
    static Variant getLastErrors();
    Variant format(const std::initializer_list<Variant> &args);
    Variant getTimezone();
    Variant getOffset();
    Variant getTimestamp();
    Variant diff(const std::initializer_list<Variant> &args);
    Variant modify(const std::initializer_list<Variant> &args);
    Variant add(const std::initializer_list<Variant> &args);
    Variant sub(const std::initializer_list<Variant> &args);
    Variant setTimezone(const std::initializer_list<Variant> &args);
    Variant setTime(const std::initializer_list<Variant> &args);
    Variant setDate(const std::initializer_list<Variant> &args);
    Variant setISODate(const std::initializer_list<Variant> &args);
    Variant setTimestamp(const std::initializer_list<Variant> &args);
    static Variant createFromMutable(const std::initializer_list<Variant> &args);
    static Variant createFromInterface(const std::initializer_list<Variant> &args);
};

class DateTimeZone {
  private:
    Variant _this;
  public:
    DateTimeZone(const std::initializer_list<Variant> &args);
    Variant getName();
    Variant getOffset(const std::initializer_list<Variant> &args);
    Variant getTransitions(const std::initializer_list<Variant> &args);
    Variant getLocation();
    static Variant listAbbreviations();
    static Variant listIdentifiers(const std::initializer_list<Variant> &args);
    Variant __serialize();
    Variant __unserialize(const std::initializer_list<Variant> &args);
    Variant __wakeup();
    static Variant __set_state(const std::initializer_list<Variant> &args);
};

class DateInterval {
  private:
    Variant _this;
  public:
    DateInterval(const std::initializer_list<Variant> &args);
    static Variant createFromDateString(const std::initializer_list<Variant> &args);
    Variant format(const std::initializer_list<Variant> &args);
    Variant __serialize();
    Variant __unserialize(const std::initializer_list<Variant> &args);
    Variant __wakeup();
    static Variant __set_state(const std::initializer_list<Variant> &args);
};

class DatePeriod {
  private:
    Variant _this;
  public:
    DatePeriod(const std::initializer_list<Variant> &args);
    Variant getStartDate();
    Variant getEndDate();
    Variant getDateInterval();
    Variant getRecurrences();
    Variant __serialize();
    Variant __unserialize(const std::initializer_list<Variant> &args);
    Variant __wakeup();
    static Variant __set_state(const std::initializer_list<Variant> &args);
    Variant getIterator();
};

}

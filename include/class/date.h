namespace php {
class DateTime {
    Object this_;
  public:
    DateTime(const Variant &datetime = "now", const Variant &timezone = {});
    Variant __serialize();
    Variant __unserialize(const Variant &data);
    Variant __wakeup();
    static Variant __set_state(const Variant &array);
    static Variant createFromImmutable(const Variant &object);
    static Variant createFromInterface(const Variant &object);
    static Variant createFromFormat(const Variant &format, const Variant &datetime, const Variant &timezone = {});
    static Variant getLastErrors();
    Variant format(const Variant &format);
    Variant modify(const Variant &modifier);
    Variant add(const Variant &interval);
    Variant sub(const Variant &interval);
    Variant getTimezone();
    Variant setTimezone(const Variant &timezone);
    Variant getOffset();
    Variant setTime(const Variant &hour, const Variant &minute, const Variant &second = 0, const Variant &microsecond = 0);
    Variant setDate(const Variant &year, const Variant &month, const Variant &day);
    Variant setISODate(const Variant &year, const Variant &week, const Variant &day_of_week = 1);
    Variant setTimestamp(const Variant &timestamp);
    Variant getTimestamp();
    Variant diff(const Variant &target_object, const Variant &absolute = false);
};

class DateTimeImmutable {
    Object this_;
  public:
    DateTimeImmutable(const Variant &datetime = "now", const Variant &timezone = {});
    Variant __serialize();
    Variant __unserialize(const Variant &data);
    Variant __wakeup();
    static Variant __set_state(const Variant &array);
    static Variant createFromFormat(const Variant &format, const Variant &datetime, const Variant &timezone = {});
    static Variant getLastErrors();
    Variant format(const Variant &format);
    Variant getTimezone();
    Variant getOffset();
    Variant getTimestamp();
    Variant diff(const Variant &target_object, const Variant &absolute = false);
    Variant modify(const Variant &modifier);
    Variant add(const Variant &interval);
    Variant sub(const Variant &interval);
    Variant setTimezone(const Variant &timezone);
    Variant setTime(const Variant &hour, const Variant &minute, const Variant &second = 0, const Variant &microsecond = 0);
    Variant setDate(const Variant &year, const Variant &month, const Variant &day);
    Variant setISODate(const Variant &year, const Variant &week, const Variant &day_of_week = 1);
    Variant setTimestamp(const Variant &timestamp);
    static Variant createFromMutable(const Variant &object);
    static Variant createFromInterface(const Variant &object);
};

class DateTimeZone {
    Object this_;
  public:
    DateTimeZone(const Variant &timezone);
    Variant getName();
    Variant getOffset(const Variant &datetime);
    Variant getTransitions(const Variant &timestamp_begin = LONG_MIN, const Variant &timestamp_end = LONG_MAX);
    Variant getLocation();
    static Variant listAbbreviations();
    static Variant listIdentifiers(const Variant &timezone_group = 2047, const Variant &country_code = {});
    Variant __serialize();
    Variant __unserialize(const Variant &data);
    Variant __wakeup();
    static Variant __set_state(const Variant &array);
};

class DateInterval {
    Object this_;
  public:
    DateInterval(const Variant &duration);
    static Variant createFromDateString(const Variant &datetime);
    Variant format(const Variant &format);
    Variant __serialize();
    Variant __unserialize(const Variant &data);
    Variant __wakeup();
    static Variant __set_state(const Variant &array);
};

class DatePeriod {
    Object this_;
  public:
    DatePeriod(const Variant &start, const Variant &interval = {}, const Variant &end = {}, const Variant &options = {});
    Variant getStartDate();
    Variant getEndDate();
    Variant getDateInterval();
    Variant getRecurrences();
    Variant __serialize();
    Variant __unserialize(const Variant &data);
    Variant __wakeup();
    static Variant __set_state(const Variant &array);
    Variant getIterator();
};

}

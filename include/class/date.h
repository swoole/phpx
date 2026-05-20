#pragma once

#include "phpx_class.h"
#include "phpx_literal_string.h"

namespace php {
class DateTimeZone {
    Object this_;

  public:
    Object getObject() const {
        return this_;
    }
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
    Object getObject() const {
        return this_;
    }
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
    Object getObject() const {
        return this_;
    }
    static Variant createFromISO8601String(const Variant &specification, const Variant &options = 0);
    DatePeriod(const Variant &start,
               const Variant &interval = {},
               const Variant &end = {},
               const Variant &options = {});
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

class DateError {
    Object this_;

  public:
    Object getObject() const {
        return this_;
    }
    DateError(const Variant &message = "", const Variant &code = 0, const Variant &previous = {});
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

class DateObjectError {
    Object this_;

  public:
    Object getObject() const {
        return this_;
    }
    DateObjectError(const Variant &message = "", const Variant &code = 0, const Variant &previous = {});
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

class DateRangeError {
    Object this_;

  public:
    Object getObject() const {
        return this_;
    }
    DateRangeError(const Variant &message = "", const Variant &code = 0, const Variant &previous = {});
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

class DateException {
    Object this_;

  public:
    Object getObject() const {
        return this_;
    }
    DateException(const Variant &message = "", const Variant &code = 0, const Variant &previous = {});
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

class DateInvalidTimeZoneException {
    Object this_;

  public:
    Object getObject() const {
        return this_;
    }
    DateInvalidTimeZoneException(const Variant &message = "", const Variant &code = 0, const Variant &previous = {});
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

class DateInvalidOperationException {
    Object this_;

  public:
    Object getObject() const {
        return this_;
    }
    DateInvalidOperationException(const Variant &message = "", const Variant &code = 0, const Variant &previous = {});
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

class DateMalformedStringException {
    Object this_;

  public:
    Object getObject() const {
        return this_;
    }
    DateMalformedStringException(const Variant &message = "", const Variant &code = 0, const Variant &previous = {});
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

class DateMalformedIntervalStringException {
    Object this_;

  public:
    Object getObject() const {
        return this_;
    }
    DateMalformedIntervalStringException(const Variant &message = "",
                                         const Variant &code = 0,
                                         const Variant &previous = {});
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

class DateMalformedPeriodStringException {
    Object this_;

  public:
    Object getObject() const {
        return this_;
    }
    DateMalformedPeriodStringException(const Variant &message = "",
                                       const Variant &code = 0,
                                       const Variant &previous = {});
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

class DateTime {
    Object this_;

  public:
    Object getObject() const {
        return this_;
    }
    DateTime(const Variant &datetime = "now", const Variant &timezone = {});
    Variant __serialize();
    Variant __unserialize(const Variant &data);
    Variant __wakeup();
    static Variant __set_state(const Variant &array);
    static Variant createFromImmutable(const Variant &object);
    static Variant createFromInterface(const Variant &object);
    static Variant createFromFormat(const Variant &format, const Variant &datetime, const Variant &timezone = {});
    static Variant createFromTimestamp(const Variant &timestamp);
    static Variant getLastErrors();
    Variant format(const Variant &format);
    Variant modify(const Variant &modifier);
    Variant add(const DateInterval &interval);
    Variant add(const Variant &interval);
    Variant sub(const DateInterval &interval);
    Variant sub(const Variant &interval);
    Variant getTimezone();
    Variant setTimezone(const DateTimeZone &timezone);
    Variant setTimezone(const Variant &timezone);
    Variant getOffset();
    Variant getMicrosecond();
    Variant setTime(const Variant &hour,
                    const Variant &minute,
                    const Variant &second = 0,
                    const Variant &microsecond = 0);
    Variant setDate(const Variant &year, const Variant &month, const Variant &day);
    Variant setISODate(const Variant &year, const Variant &week, const Variant &day_of_week = 1);
    Variant setTimestamp(const Variant &timestamp);
    Variant setMicrosecond(const Variant &microsecond);
    Variant getTimestamp();
    Variant diff(const Variant &target_object, const Variant &absolute = false);
};

class DateTimeImmutable {
    Object this_;

  public:
    Object getObject() const {
        return this_;
    }
    DateTimeImmutable(const Variant &datetime = "now", const Variant &timezone = {});
    Variant __serialize();
    Variant __unserialize(const Variant &data);
    Variant __wakeup();
    static Variant __set_state(const Variant &array);
    static Variant createFromFormat(const Variant &format, const Variant &datetime, const Variant &timezone = {});
    static Variant createFromTimestamp(const Variant &timestamp);
    static Variant getLastErrors();
    Variant format(const Variant &format);
    Variant getTimezone();
    Variant getOffset();
    Variant getTimestamp();
    Variant getMicrosecond();
    Variant diff(const Variant &target_object, const Variant &absolute = false);
    Variant modify(const Variant &modifier);
    Variant add(const DateInterval &interval);
    Variant add(const Variant &interval);
    Variant sub(const DateInterval &interval);
    Variant sub(const Variant &interval);
    Variant setTimezone(const DateTimeZone &timezone);
    Variant setTimezone(const Variant &timezone);
    Variant setTime(const Variant &hour,
                    const Variant &minute,
                    const Variant &second = 0,
                    const Variant &microsecond = 0);
    Variant setDate(const Variant &year, const Variant &month, const Variant &day);
    Variant setISODate(const Variant &year, const Variant &week, const Variant &day_of_week = 1);
    Variant setTimestamp(const Variant &timestamp);
    Variant setMicrosecond(const Variant &microsecond);
    static Variant createFromMutable(const DateTime &object);
    Variant createFromMutable(const Variant &object);
    static Variant createFromInterface(const Variant &object);
};

}  // namespace php

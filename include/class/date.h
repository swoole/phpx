#pragma once

#include "phpx.h"
#include "phpx_literal_string.h"
#include "class/core.h"

namespace php {
class DateTimeZone;
class DateInterval;
class DatePeriod;
class DateError;
class DateObjectError;
class DateRangeError;
class DateException;
class DateInvalidTimeZoneException;
class DateInvalidOperationException;
class DateMalformedStringException;
class DateMalformedIntervalStringException;
class DateMalformedPeriodStringException;
class DateTime;
class DateTimeImmutable;

class DateTimeZone {
  protected:
    Object this_;
    DateTimeZone() = default;

  public:
    Object getObject() const {
        return this_;
    }
    static constexpr int AFRICA = 1;
    static constexpr int AMERICA = 2;
    static constexpr int ANTARCTICA = 4;
    static constexpr int ARCTIC = 8;
    static constexpr int ASIA = 16;
    static constexpr int ATLANTIC = 32;
    static constexpr int AUSTRALIA = 64;
    static constexpr int EUROPE = 128;
    static constexpr int INDIAN = 256;
    static constexpr int PACIFIC = 512;
    static constexpr int UTC = 1024;
    static constexpr int ALL = 2047;
    static constexpr int ALL_WITH_BC = 4095;
    static constexpr int PER_COUNTRY = 4096;

    DateTimeZone(const Variant &timezone);
    Variant getName();
    Variant getOffset(const Variant &datetime);
    Variant getTransitions(const Variant &timestamp_begin = LONG_MIN, const Variant &timestamp_end = LONG_MAX);
    Variant getLocation();
    static Variant listAbbreviations();
    static Variant listIdentifiers(const Variant &timezone_group = 2047, const Variant &country_code = nullptr);
    Variant __serialize();
    Variant __unserialize(const Variant &data);
    Variant __wakeup();
    static Variant __set_state(const Variant &array);
};

class DateInterval {
  protected:
    Object this_;
    DateInterval() = default;

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
  protected:
    Object this_;
    DatePeriod() = default;

  public:
    Object getObject() const {
        return this_;
    }
    static constexpr int EXCLUDE_START_DATE = 1;
    static constexpr int INCLUDE_END_DATE = 2;

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

class DateError : public Error {
  public:
    DateError(const Variant &message = "", const Variant &code = 0, const Variant &previous = nullptr);
};

class DateObjectError : public DateError {
  public:
    DateObjectError(const Variant &message = "", const Variant &code = 0, const Variant &previous = nullptr);
};

class DateRangeError : public DateError {
  public:
    DateRangeError(const Variant &message = "", const Variant &code = 0, const Variant &previous = nullptr);
};

class DateException : public Exception {
  public:
    DateException(const Variant &message = "", const Variant &code = 0, const Variant &previous = nullptr);
};

class DateInvalidTimeZoneException : public DateException {
  public:
    DateInvalidTimeZoneException(const Variant &message = "",
                                 const Variant &code = 0,
                                 const Variant &previous = nullptr);
};

class DateInvalidOperationException : public DateException {
  public:
    DateInvalidOperationException(const Variant &message = "",
                                  const Variant &code = 0,
                                  const Variant &previous = nullptr);
};

class DateMalformedStringException : public DateException {
  public:
    DateMalformedStringException(const Variant &message = "",
                                 const Variant &code = 0,
                                 const Variant &previous = nullptr);
};

class DateMalformedIntervalStringException : public DateException {
  public:
    DateMalformedIntervalStringException(const Variant &message = "",
                                         const Variant &code = 0,
                                         const Variant &previous = nullptr);
};

class DateMalformedPeriodStringException : public DateException {
  public:
    DateMalformedPeriodStringException(const Variant &message = "",
                                       const Variant &code = 0,
                                       const Variant &previous = nullptr);
};

class DateTime {
  protected:
    Object this_;

  public:
    Object getObject() const {
        return this_;
    }
    DateTime(const Variant &datetime = "now", const Variant &timezone = nullptr);
    Variant __serialize();
    Variant __unserialize(const Variant &data);
    Variant __wakeup();
    static Variant __set_state(const Variant &array);
    static Variant createFromImmutable(const DateTimeImmutable &object);
    static Variant createFromImmutable(const Variant &object);
    static Variant createFromInterface(const Variant &object);
    static Variant createFromFormat(const Variant &format, const Variant &datetime, const Variant &timezone = nullptr);
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
  protected:
    Object this_;

  public:
    Object getObject() const {
        return this_;
    }
    DateTimeImmutable(const Variant &datetime = "now", const Variant &timezone = nullptr);
    Variant __serialize();
    Variant __unserialize(const Variant &data);
    Variant __wakeup();
    static Variant __set_state(const Variant &array);
    static Variant createFromFormat(const Variant &format, const Variant &datetime, const Variant &timezone = nullptr);
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
    static Variant createFromMutable(const Variant &object);
    static Variant createFromInterface(const Variant &object);
};

}  // namespace php

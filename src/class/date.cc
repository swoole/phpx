#include "phpx.h"
#include "class/date.h"

namespace php {
DateTime::DateTime(const Variant &datetime, const Variant &timezone) {
    this_ = newObject("DateTime", datetime, timezone);
}

Variant DateTime::__serialize() {
    return this_.exec("__serialize");
}

Variant DateTime::__unserialize(const Variant &data) {
    return this_.exec("__unserialize", data);
}

Variant DateTime::__wakeup() {
    return this_.exec("__wakeup");
}

Variant DateTime::__set_state(const Variant &array) {
    static Variant fn { ZEND_STRL("DateTime::__set_state"), true };
    return fn(array);
}

Variant DateTime::createFromImmutable(const Variant &object) {
    static Variant fn { ZEND_STRL("DateTime::createFromImmutable"), true };
    return fn(object);
}

Variant DateTime::createFromInterface(const Variant &object) {
    static Variant fn { ZEND_STRL("DateTime::createFromInterface"), true };
    return fn(object);
}

Variant DateTime::createFromFormat(const Variant &format, const Variant &datetime, const Variant &timezone) {
    static Variant fn { ZEND_STRL("DateTime::createFromFormat"), true };
    return fn(format, datetime, timezone);
}

Variant DateTime::getLastErrors() {
    static Variant fn { ZEND_STRL("DateTime::getLastErrors"), true };
    return fn();
}

Variant DateTime::format(const Variant &format) {
    return this_.exec("format", format);
}

Variant DateTime::modify(const Variant &modifier) {
    return this_.exec("modify", modifier);
}

Variant DateTime::add(const Variant &interval) {
    return this_.exec("add", interval);
}

Variant DateTime::sub(const Variant &interval) {
    return this_.exec("sub", interval);
}

Variant DateTime::getTimezone() {
    return this_.exec("getTimezone");
}

Variant DateTime::setTimezone(const Variant &timezone) {
    return this_.exec("setTimezone", timezone);
}

Variant DateTime::getOffset() {
    return this_.exec("getOffset");
}

Variant DateTime::setTime(const Variant &hour, const Variant &minute, const Variant &second, const Variant &microsecond) {
    return this_.exec("setTime", hour, minute, second, microsecond);
}

Variant DateTime::setDate(const Variant &year, const Variant &month, const Variant &day) {
    return this_.exec("setDate", year, month, day);
}

Variant DateTime::setISODate(const Variant &year, const Variant &week, const Variant &day_of_week) {
    return this_.exec("setISODate", year, week, day_of_week);
}

Variant DateTime::setTimestamp(const Variant &timestamp) {
    return this_.exec("setTimestamp", timestamp);
}

Variant DateTime::getTimestamp() {
    return this_.exec("getTimestamp");
}

Variant DateTime::diff(const Variant &target_object, const Variant &absolute) {
    return this_.exec("diff", target_object, absolute);
}


DateTimeImmutable::DateTimeImmutable(const Variant &datetime, const Variant &timezone) {
    this_ = newObject("DateTimeImmutable", datetime, timezone);
}

Variant DateTimeImmutable::__serialize() {
    return this_.exec("__serialize");
}

Variant DateTimeImmutable::__unserialize(const Variant &data) {
    return this_.exec("__unserialize", data);
}

Variant DateTimeImmutable::__wakeup() {
    return this_.exec("__wakeup");
}

Variant DateTimeImmutable::__set_state(const Variant &array) {
    static Variant fn { ZEND_STRL("DateTimeImmutable::__set_state"), true };
    return fn(array);
}

Variant DateTimeImmutable::createFromFormat(const Variant &format, const Variant &datetime, const Variant &timezone) {
    static Variant fn { ZEND_STRL("DateTimeImmutable::createFromFormat"), true };
    return fn(format, datetime, timezone);
}

Variant DateTimeImmutable::getLastErrors() {
    static Variant fn { ZEND_STRL("DateTimeImmutable::getLastErrors"), true };
    return fn();
}

Variant DateTimeImmutable::format(const Variant &format) {
    return this_.exec("format", format);
}

Variant DateTimeImmutable::getTimezone() {
    return this_.exec("getTimezone");
}

Variant DateTimeImmutable::getOffset() {
    return this_.exec("getOffset");
}

Variant DateTimeImmutable::getTimestamp() {
    return this_.exec("getTimestamp");
}

Variant DateTimeImmutable::diff(const Variant &target_object, const Variant &absolute) {
    return this_.exec("diff", target_object, absolute);
}

Variant DateTimeImmutable::modify(const Variant &modifier) {
    return this_.exec("modify", modifier);
}

Variant DateTimeImmutable::add(const Variant &interval) {
    return this_.exec("add", interval);
}

Variant DateTimeImmutable::sub(const Variant &interval) {
    return this_.exec("sub", interval);
}

Variant DateTimeImmutable::setTimezone(const Variant &timezone) {
    return this_.exec("setTimezone", timezone);
}

Variant DateTimeImmutable::setTime(const Variant &hour, const Variant &minute, const Variant &second, const Variant &microsecond) {
    return this_.exec("setTime", hour, minute, second, microsecond);
}

Variant DateTimeImmutable::setDate(const Variant &year, const Variant &month, const Variant &day) {
    return this_.exec("setDate", year, month, day);
}

Variant DateTimeImmutable::setISODate(const Variant &year, const Variant &week, const Variant &day_of_week) {
    return this_.exec("setISODate", year, week, day_of_week);
}

Variant DateTimeImmutable::setTimestamp(const Variant &timestamp) {
    return this_.exec("setTimestamp", timestamp);
}

Variant DateTimeImmutable::createFromMutable(const Variant &object) {
    static Variant fn { ZEND_STRL("DateTimeImmutable::createFromMutable"), true };
    return fn(object);
}

Variant DateTimeImmutable::createFromInterface(const Variant &object) {
    static Variant fn { ZEND_STRL("DateTimeImmutable::createFromInterface"), true };
    return fn(object);
}


DateTimeZone::DateTimeZone(const Variant &timezone) {
    this_ = newObject("DateTimeZone", timezone);
}

Variant DateTimeZone::getName() {
    return this_.exec("getName");
}

Variant DateTimeZone::getOffset(const Variant &datetime) {
    return this_.exec("getOffset", datetime);
}

Variant DateTimeZone::getTransitions(const Variant &timestamp_begin, const Variant &timestamp_end) {
    return this_.exec("getTransitions", timestamp_begin, timestamp_end);
}

Variant DateTimeZone::getLocation() {
    return this_.exec("getLocation");
}

Variant DateTimeZone::listAbbreviations() {
    static Variant fn { ZEND_STRL("DateTimeZone::listAbbreviations"), true };
    return fn();
}

Variant DateTimeZone::listIdentifiers(const Variant &timezone_group, const Variant &country_code) {
    static Variant fn { ZEND_STRL("DateTimeZone::listIdentifiers"), true };
    return fn(timezone_group, country_code);
}

Variant DateTimeZone::__serialize() {
    return this_.exec("__serialize");
}

Variant DateTimeZone::__unserialize(const Variant &data) {
    return this_.exec("__unserialize", data);
}

Variant DateTimeZone::__wakeup() {
    return this_.exec("__wakeup");
}

Variant DateTimeZone::__set_state(const Variant &array) {
    static Variant fn { ZEND_STRL("DateTimeZone::__set_state"), true };
    return fn(array);
}


DateInterval::DateInterval(const Variant &duration) {
    this_ = newObject("DateInterval", duration);
}

Variant DateInterval::createFromDateString(const Variant &datetime) {
    static Variant fn { ZEND_STRL("DateInterval::createFromDateString"), true };
    return fn(datetime);
}

Variant DateInterval::format(const Variant &format) {
    return this_.exec("format", format);
}

Variant DateInterval::__serialize() {
    return this_.exec("__serialize");
}

Variant DateInterval::__unserialize(const Variant &data) {
    return this_.exec("__unserialize", data);
}

Variant DateInterval::__wakeup() {
    return this_.exec("__wakeup");
}

Variant DateInterval::__set_state(const Variant &array) {
    static Variant fn { ZEND_STRL("DateInterval::__set_state"), true };
    return fn(array);
}


DatePeriod::DatePeriod(const Variant &start, const Variant &interval, const Variant &end, const Variant &options) {
    this_ = newObject("DatePeriod", start, interval, end, options);
}

Variant DatePeriod::getStartDate() {
    return this_.exec("getStartDate");
}

Variant DatePeriod::getEndDate() {
    return this_.exec("getEndDate");
}

Variant DatePeriod::getDateInterval() {
    return this_.exec("getDateInterval");
}

Variant DatePeriod::getRecurrences() {
    return this_.exec("getRecurrences");
}

Variant DatePeriod::__serialize() {
    return this_.exec("__serialize");
}

Variant DatePeriod::__unserialize(const Variant &data) {
    return this_.exec("__unserialize", data);
}

Variant DatePeriod::__wakeup() {
    return this_.exec("__wakeup");
}

Variant DatePeriod::__set_state(const Variant &array) {
    static Variant fn { ZEND_STRL("DatePeriod::__set_state"), true };
    return fn(array);
}

Variant DatePeriod::getIterator() {
    return this_.exec("getIterator");
}


}

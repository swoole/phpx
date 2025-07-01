#include "phpx.h"
#include "class/date.h"

namespace php {
DateTime::DateTime(const Variant &datetime, const Variant &timezone) {
    _this = newObject("DateTime", datetime, timezone);
}

Variant DateTime::__serialize() {
    return _this.exec("__serialize");
}

Variant DateTime::__unserialize(const Variant &data) {
    return _this.exec("__unserialize", data);
}

Variant DateTime::__wakeup() {
    return _this.exec("__wakeup");
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
    return _this.exec("format", format);
}

Variant DateTime::modify(const Variant &modifier) {
    return _this.exec("modify", modifier);
}

Variant DateTime::add(const Variant &interval) {
    return _this.exec("add", interval);
}

Variant DateTime::sub(const Variant &interval) {
    return _this.exec("sub", interval);
}

Variant DateTime::getTimezone() {
    return _this.exec("getTimezone");
}

Variant DateTime::setTimezone(const Variant &timezone) {
    return _this.exec("setTimezone", timezone);
}

Variant DateTime::getOffset() {
    return _this.exec("getOffset");
}

Variant DateTime::setTime(const Variant &hour, const Variant &minute, const Variant &second, const Variant &microsecond) {
    return _this.exec("setTime", hour, minute, second, microsecond);
}

Variant DateTime::setDate(const Variant &year, const Variant &month, const Variant &day) {
    return _this.exec("setDate", year, month, day);
}

Variant DateTime::setISODate(const Variant &year, const Variant &week, const Variant &day_of_week) {
    return _this.exec("setISODate", year, week, day_of_week);
}

Variant DateTime::setTimestamp(const Variant &timestamp) {
    return _this.exec("setTimestamp", timestamp);
}

Variant DateTime::getTimestamp() {
    return _this.exec("getTimestamp");
}

Variant DateTime::diff(const Variant &target_object, const Variant &absolute) {
    return _this.exec("diff", target_object, absolute);
}


DateTimeImmutable::DateTimeImmutable(const Variant &datetime, const Variant &timezone) {
    _this = newObject("DateTimeImmutable", datetime, timezone);
}

Variant DateTimeImmutable::__serialize() {
    return _this.exec("__serialize");
}

Variant DateTimeImmutable::__unserialize(const Variant &data) {
    return _this.exec("__unserialize", data);
}

Variant DateTimeImmutable::__wakeup() {
    return _this.exec("__wakeup");
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
    return _this.exec("format", format);
}

Variant DateTimeImmutable::getTimezone() {
    return _this.exec("getTimezone");
}

Variant DateTimeImmutable::getOffset() {
    return _this.exec("getOffset");
}

Variant DateTimeImmutable::getTimestamp() {
    return _this.exec("getTimestamp");
}

Variant DateTimeImmutable::diff(const Variant &target_object, const Variant &absolute) {
    return _this.exec("diff", target_object, absolute);
}

Variant DateTimeImmutable::modify(const Variant &modifier) {
    return _this.exec("modify", modifier);
}

Variant DateTimeImmutable::add(const Variant &interval) {
    return _this.exec("add", interval);
}

Variant DateTimeImmutable::sub(const Variant &interval) {
    return _this.exec("sub", interval);
}

Variant DateTimeImmutable::setTimezone(const Variant &timezone) {
    return _this.exec("setTimezone", timezone);
}

Variant DateTimeImmutable::setTime(const Variant &hour, const Variant &minute, const Variant &second, const Variant &microsecond) {
    return _this.exec("setTime", hour, minute, second, microsecond);
}

Variant DateTimeImmutable::setDate(const Variant &year, const Variant &month, const Variant &day) {
    return _this.exec("setDate", year, month, day);
}

Variant DateTimeImmutable::setISODate(const Variant &year, const Variant &week, const Variant &day_of_week) {
    return _this.exec("setISODate", year, week, day_of_week);
}

Variant DateTimeImmutable::setTimestamp(const Variant &timestamp) {
    return _this.exec("setTimestamp", timestamp);
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
    _this = newObject("DateTimeZone", timezone);
}

Variant DateTimeZone::getName() {
    return _this.exec("getName");
}

Variant DateTimeZone::getOffset(const Variant &datetime) {
    return _this.exec("getOffset", datetime);
}

Variant DateTimeZone::getTransitions(const Variant &timestamp_begin, const Variant &timestamp_end) {
    return _this.exec("getTransitions", timestamp_begin, timestamp_end);
}

Variant DateTimeZone::getLocation() {
    return _this.exec("getLocation");
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
    return _this.exec("__serialize");
}

Variant DateTimeZone::__unserialize(const Variant &data) {
    return _this.exec("__unserialize", data);
}

Variant DateTimeZone::__wakeup() {
    return _this.exec("__wakeup");
}

Variant DateTimeZone::__set_state(const Variant &array) {
    static Variant fn { ZEND_STRL("DateTimeZone::__set_state"), true };
    return fn(array);
}


DateInterval::DateInterval(const Variant &duration) {
    _this = newObject("DateInterval", duration);
}

Variant DateInterval::createFromDateString(const Variant &datetime) {
    static Variant fn { ZEND_STRL("DateInterval::createFromDateString"), true };
    return fn(datetime);
}

Variant DateInterval::format(const Variant &format) {
    return _this.exec("format", format);
}

Variant DateInterval::__serialize() {
    return _this.exec("__serialize");
}

Variant DateInterval::__unserialize(const Variant &data) {
    return _this.exec("__unserialize", data);
}

Variant DateInterval::__wakeup() {
    return _this.exec("__wakeup");
}

Variant DateInterval::__set_state(const Variant &array) {
    static Variant fn { ZEND_STRL("DateInterval::__set_state"), true };
    return fn(array);
}


DatePeriod::DatePeriod(const Variant &start, const Variant &interval, const Variant &end, const Variant &options) {
    _this = newObject("DatePeriod", start, interval, end, options);
}

Variant DatePeriod::getStartDate() {
    return _this.exec("getStartDate");
}

Variant DatePeriod::getEndDate() {
    return _this.exec("getEndDate");
}

Variant DatePeriod::getDateInterval() {
    return _this.exec("getDateInterval");
}

Variant DatePeriod::getRecurrences() {
    return _this.exec("getRecurrences");
}

Variant DatePeriod::__serialize() {
    return _this.exec("__serialize");
}

Variant DatePeriod::__unserialize(const Variant &data) {
    return _this.exec("__unserialize", data);
}

Variant DatePeriod::__wakeup() {
    return _this.exec("__wakeup");
}

Variant DatePeriod::__set_state(const Variant &array) {
    static Variant fn { ZEND_STRL("DatePeriod::__set_state"), true };
    return fn(array);
}

Variant DatePeriod::getIterator() {
    return _this.exec("getIterator");
}


}

#include "phpx.h"
#include "phpx_class.h"
#include "class/date.h"

namespace php {
DateTimeZone::DateTimeZone(const Variant &timezone) {
    this_ = newObject(LITERAL_STRING[327], {timezone});
}
Variant DateTimeZone::getName() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[328]);
    }
    return this_.call(_method_fn, {});
}
Variant DateTimeZone::getOffset(const Variant &datetime) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[310]);
    }
    return this_.call(_method_fn, {datetime});
}
Variant DateTimeZone::getTransitions(const Variant &timestamp_begin, const Variant &timestamp_end) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[329]);
    }
    return this_.call(_method_fn, {timestamp_begin, timestamp_end});
}
Variant DateTimeZone::getLocation() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[330]);
    }
    return this_.call(_method_fn, {});
}
Variant DateTimeZone::listAbbreviations() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(LITERAL_STRING[327], LITERAL_STRING[332]);
    }
    return php::call(_method_fn, {});
}
Variant DateTimeZone::listIdentifiers(const Variant &timezone_group, const Variant &country_code) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(LITERAL_STRING[327], LITERAL_STRING[334]);
    }
    return php::call(_method_fn, {timezone_group, country_code});
}
Variant DateTimeZone::__serialize() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[30]);
    }
    return this_.call(_method_fn, {});
}
Variant DateTimeZone::__unserialize(const Variant &data) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[31]);
    }
    return this_.call(_method_fn, {data});
}
Variant DateTimeZone::__wakeup() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[125]);
    }
    return this_.call(_method_fn, {});
}
Variant DateTimeZone::__set_state(const Variant &array) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(LITERAL_STRING[327], LITERAL_STRING[295]);
    }
    return php::call(_method_fn, {array});
}
DateInterval::DateInterval(const Variant &duration) {
    this_ = newObject(LITERAL_STRING[336], {duration});
}
Variant DateInterval::createFromDateString(const Variant &datetime) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(LITERAL_STRING[336], LITERAL_STRING[338]);
    }
    return php::call(_method_fn, {datetime});
}
Variant DateInterval::format(const Variant &format) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[306]);
    }
    return this_.call(_method_fn, {format});
}
Variant DateInterval::__serialize() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[30]);
    }
    return this_.call(_method_fn, {});
}
Variant DateInterval::__unserialize(const Variant &data) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[31]);
    }
    return this_.call(_method_fn, {data});
}
Variant DateInterval::__wakeup() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[125]);
    }
    return this_.call(_method_fn, {});
}
Variant DateInterval::__set_state(const Variant &array) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(LITERAL_STRING[336], LITERAL_STRING[295]);
    }
    return php::call(_method_fn, {array});
}
Variant DatePeriod::createFromISO8601String(const Variant &specification, const Variant &options) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(LITERAL_STRING[341], LITERAL_STRING[342]);
    }
    return php::call(_method_fn, {specification, options});
}
DatePeriod::DatePeriod(const Variant &start, const Variant &interval, const Variant &end, const Variant &options) {
    this_ = newObject(LITERAL_STRING[341], {start, interval, end, options});
}
Variant DatePeriod::getStartDate() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[343]);
    }
    return this_.call(_method_fn, {});
}
Variant DatePeriod::getEndDate() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[344]);
    }
    return this_.call(_method_fn, {});
}
Variant DatePeriod::getDateInterval() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[345]);
    }
    return this_.call(_method_fn, {});
}
Variant DatePeriod::getRecurrences() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[346]);
    }
    return this_.call(_method_fn, {});
}
Variant DatePeriod::__serialize() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[30]);
    }
    return this_.call(_method_fn, {});
}
Variant DatePeriod::__unserialize(const Variant &data) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[31]);
    }
    return this_.call(_method_fn, {data});
}
Variant DatePeriod::__wakeup() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[125]);
    }
    return this_.call(_method_fn, {});
}
Variant DatePeriod::__set_state(const Variant &array) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(LITERAL_STRING[341], LITERAL_STRING[295]);
    }
    return php::call(_method_fn, {array});
}
Variant DatePeriod::getIterator() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[169]);
    }
    return this_.call(_method_fn, {});
}
DateError::DateError(const Variant &message, const Variant &code, const Variant &previous) {
    this_ = newObject(LITERAL_STRING[348], {message, code, previous});
}
DateObjectError::DateObjectError(const Variant &message, const Variant &code, const Variant &previous) {
    this_ = newObject(LITERAL_STRING[349], {message, code, previous});
}
DateRangeError::DateRangeError(const Variant &message, const Variant &code, const Variant &previous) {
    this_ = newObject(LITERAL_STRING[350], {message, code, previous});
}
DateException::DateException(const Variant &message, const Variant &code, const Variant &previous) {
    this_ = newObject(LITERAL_STRING[351], {message, code, previous});
}
DateInvalidTimeZoneException::DateInvalidTimeZoneException(const Variant &message,
                                                           const Variant &code,
                                                           const Variant &previous) {
    this_ = newObject(LITERAL_STRING[352], {message, code, previous});
}
DateInvalidOperationException::DateInvalidOperationException(const Variant &message,
                                                             const Variant &code,
                                                             const Variant &previous) {
    this_ = newObject(LITERAL_STRING[353], {message, code, previous});
}
DateMalformedStringException::DateMalformedStringException(const Variant &message,
                                                           const Variant &code,
                                                           const Variant &previous) {
    this_ = newObject(LITERAL_STRING[354], {message, code, previous});
}
DateMalformedIntervalStringException::DateMalformedIntervalStringException(const Variant &message,
                                                                           const Variant &code,
                                                                           const Variant &previous) {
    this_ = newObject(LITERAL_STRING[355], {message, code, previous});
}
DateMalformedPeriodStringException::DateMalformedPeriodStringException(const Variant &message,
                                                                       const Variant &code,
                                                                       const Variant &previous) {
    this_ = newObject(LITERAL_STRING[356], {message, code, previous});
}
DateTime::DateTime(const Variant &datetime, const Variant &timezone) {
    this_ = newObject(LITERAL_STRING[293], {datetime, timezone});
}
Variant DateTime::__serialize() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[30]);
    }
    return this_.call(_method_fn, {});
}
Variant DateTime::__unserialize(const Variant &data) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[31]);
    }
    return this_.call(_method_fn, {data});
}
Variant DateTime::__wakeup() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[125]);
    }
    return this_.call(_method_fn, {});
}
Variant DateTime::__set_state(const Variant &array) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(LITERAL_STRING[293], LITERAL_STRING[295]);
    }
    return php::call(_method_fn, {array});
}
Variant DateTime::createFromImmutable(const DateTimeImmutable &object) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(LITERAL_STRING[293], LITERAL_STRING[297]);
    }
    return php::call(_method_fn, {object.getObject()});
}
Variant DateTime::createFromImmutable(const Variant &object) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(LITERAL_STRING[293], LITERAL_STRING[297]);
    }
    return php::call(_method_fn, {object});
}
Variant DateTime::createFromInterface(const Variant &object) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(LITERAL_STRING[293], LITERAL_STRING[299]);
    }
    return php::call(_method_fn, {object});
}
Variant DateTime::createFromFormat(const Variant &format, const Variant &datetime, const Variant &timezone) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(LITERAL_STRING[293], LITERAL_STRING[301]);
    }
    return php::call(_method_fn, {format, datetime, timezone});
}
Variant DateTime::createFromTimestamp(const Variant &timestamp) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(LITERAL_STRING[293], LITERAL_STRING[303]);
    }
    return php::call(_method_fn, {timestamp});
}
Variant DateTime::getLastErrors() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(LITERAL_STRING[293], LITERAL_STRING[305]);
    }
    return php::call(_method_fn, {});
}
Variant DateTime::format(const Variant &format) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[306]);
    }
    return this_.call(_method_fn, {format});
}
Variant DateTime::modify(const Variant &modifier) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[307]);
    }
    return this_.call(_method_fn, {modifier});
}
Variant DateTime::add(const DateInterval &interval) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[16]);
    }
    return this_.call(_method_fn, {interval.getObject()});
}
Variant DateTime::add(const Variant &interval) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[16]);
    }
    return this_.call(_method_fn, {interval});
}
Variant DateTime::sub(const DateInterval &interval) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[17]);
    }
    return this_.call(_method_fn, {interval.getObject()});
}
Variant DateTime::sub(const Variant &interval) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[17]);
    }
    return this_.call(_method_fn, {interval});
}
Variant DateTime::getTimezone() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[308]);
    }
    return this_.call(_method_fn, {});
}
Variant DateTime::setTimezone(const DateTimeZone &timezone) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[309]);
    }
    return this_.call(_method_fn, {timezone.getObject()});
}
Variant DateTime::setTimezone(const Variant &timezone) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[309]);
    }
    return this_.call(_method_fn, {timezone});
}
Variant DateTime::getOffset() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[310]);
    }
    return this_.call(_method_fn, {});
}
Variant DateTime::getMicrosecond() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[311]);
    }
    return this_.call(_method_fn, {});
}
Variant DateTime::setTime(const Variant &hour,
                          const Variant &minute,
                          const Variant &second,
                          const Variant &microsecond) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[312]);
    }
    return this_.call(_method_fn, {hour, minute, second, microsecond});
}
Variant DateTime::setDate(const Variant &year, const Variant &month, const Variant &day) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[313]);
    }
    return this_.call(_method_fn, {year, month, day});
}
Variant DateTime::setISODate(const Variant &year, const Variant &week, const Variant &day_of_week) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[314]);
    }
    return this_.call(_method_fn, {year, week, day_of_week});
}
Variant DateTime::setTimestamp(const Variant &timestamp) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[315]);
    }
    return this_.call(_method_fn, {timestamp});
}
Variant DateTime::setMicrosecond(const Variant &microsecond) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[316]);
    }
    return this_.call(_method_fn, {microsecond});
}
Variant DateTime::getTimestamp() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[317]);
    }
    return this_.call(_method_fn, {});
}
Variant DateTime::diff(const Variant &target_object, const Variant &absolute) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[318]);
    }
    return this_.call(_method_fn, {target_object, absolute});
}
DateTimeImmutable::DateTimeImmutable(const Variant &datetime, const Variant &timezone) {
    this_ = newObject(LITERAL_STRING[319], {datetime, timezone});
}
Variant DateTimeImmutable::__serialize() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[30]);
    }
    return this_.call(_method_fn, {});
}
Variant DateTimeImmutable::__unserialize(const Variant &data) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[31]);
    }
    return this_.call(_method_fn, {data});
}
Variant DateTimeImmutable::__wakeup() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[125]);
    }
    return this_.call(_method_fn, {});
}
Variant DateTimeImmutable::__set_state(const Variant &array) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(LITERAL_STRING[319], LITERAL_STRING[295]);
    }
    return php::call(_method_fn, {array});
}
Variant DateTimeImmutable::createFromFormat(const Variant &format, const Variant &datetime, const Variant &timezone) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(LITERAL_STRING[319], LITERAL_STRING[301]);
    }
    return php::call(_method_fn, {format, datetime, timezone});
}
Variant DateTimeImmutable::createFromTimestamp(const Variant &timestamp) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(LITERAL_STRING[319], LITERAL_STRING[303]);
    }
    return php::call(_method_fn, {timestamp});
}
Variant DateTimeImmutable::getLastErrors() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(LITERAL_STRING[319], LITERAL_STRING[305]);
    }
    return php::call(_method_fn, {});
}
Variant DateTimeImmutable::format(const Variant &format) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[306]);
    }
    return this_.call(_method_fn, {format});
}
Variant DateTimeImmutable::getTimezone() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[308]);
    }
    return this_.call(_method_fn, {});
}
Variant DateTimeImmutable::getOffset() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[310]);
    }
    return this_.call(_method_fn, {});
}
Variant DateTimeImmutable::getTimestamp() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[317]);
    }
    return this_.call(_method_fn, {});
}
Variant DateTimeImmutable::getMicrosecond() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[311]);
    }
    return this_.call(_method_fn, {});
}
Variant DateTimeImmutable::diff(const Variant &target_object, const Variant &absolute) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[318]);
    }
    return this_.call(_method_fn, {target_object, absolute});
}
Variant DateTimeImmutable::modify(const Variant &modifier) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[307]);
    }
    return this_.call(_method_fn, {modifier});
}
Variant DateTimeImmutable::add(const DateInterval &interval) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[16]);
    }
    return this_.call(_method_fn, {interval.getObject()});
}
Variant DateTimeImmutable::add(const Variant &interval) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[16]);
    }
    return this_.call(_method_fn, {interval});
}
Variant DateTimeImmutable::sub(const DateInterval &interval) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[17]);
    }
    return this_.call(_method_fn, {interval.getObject()});
}
Variant DateTimeImmutable::sub(const Variant &interval) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[17]);
    }
    return this_.call(_method_fn, {interval});
}
Variant DateTimeImmutable::setTimezone(const DateTimeZone &timezone) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[309]);
    }
    return this_.call(_method_fn, {timezone.getObject()});
}
Variant DateTimeImmutable::setTimezone(const Variant &timezone) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[309]);
    }
    return this_.call(_method_fn, {timezone});
}
Variant DateTimeImmutable::setTime(const Variant &hour,
                                   const Variant &minute,
                                   const Variant &second,
                                   const Variant &microsecond) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[312]);
    }
    return this_.call(_method_fn, {hour, minute, second, microsecond});
}
Variant DateTimeImmutable::setDate(const Variant &year, const Variant &month, const Variant &day) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[313]);
    }
    return this_.call(_method_fn, {year, month, day});
}
Variant DateTimeImmutable::setISODate(const Variant &year, const Variant &week, const Variant &day_of_week) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[314]);
    }
    return this_.call(_method_fn, {year, week, day_of_week});
}
Variant DateTimeImmutable::setTimestamp(const Variant &timestamp) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[315]);
    }
    return this_.call(_method_fn, {timestamp});
}
Variant DateTimeImmutable::setMicrosecond(const Variant &microsecond) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[316]);
    }
    return this_.call(_method_fn, {microsecond});
}
Variant DateTimeImmutable::createFromMutable(const DateTime &object) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(LITERAL_STRING[319], LITERAL_STRING[325]);
    }
    return php::call(_method_fn, {object.getObject()});
}
Variant DateTimeImmutable::createFromMutable(const Variant &object) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(LITERAL_STRING[319], LITERAL_STRING[325]);
    }
    return php::call(_method_fn, {object});
}
Variant DateTimeImmutable::createFromInterface(const Variant &object) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(LITERAL_STRING[319], LITERAL_STRING[299]);
    }
    return php::call(_method_fn, {object});
}
}  // namespace php

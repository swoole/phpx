#include "phpx.h"
#include "class/date.h"

namespace php {
DateTime::DateTime(const Variant &datetime, const Variant &timezone) {
    this_ = newObject(LITERAL_STRING[256], {datetime, timezone});
}
Variant DateTime::__serialize() {
    return this_.exec(LITERAL_STRING[30], {});
}
Variant DateTime::__unserialize(const Variant &data) {
    return this_.exec(LITERAL_STRING[31], {data});
}
Variant DateTime::__wakeup() {
    return this_.exec(LITERAL_STRING[97], {});
}
Variant DateTime::__set_state(const Variant &array) {
    return php::call(LITERAL_STRING[257], {array});
}
Variant DateTime::createFromImmutable(const Variant &object) {
    return php::call(LITERAL_STRING[258], {object});
}
Variant DateTime::createFromInterface(const Variant &object) {
    return php::call(LITERAL_STRING[259], {object});
}
Variant DateTime::createFromFormat(const Variant &format, const Variant &datetime, const Variant &timezone) {
    return php::call(LITERAL_STRING[260], {format, datetime, timezone});
}
Variant DateTime::createFromTimestamp(const Variant &timestamp) {
    return php::call(LITERAL_STRING[261], {timestamp});
}
Variant DateTime::getLastErrors() {
    return php::call(LITERAL_STRING[262], {});
}
Variant DateTime::format(const Variant &format) {
    return this_.exec(LITERAL_STRING[263], {format});
}
Variant DateTime::modify(const Variant &modifier) {
    return this_.exec(LITERAL_STRING[264], {modifier});
}
Variant DateTime::add(const Variant &interval) {
    return this_.exec(LITERAL_STRING[16], {interval});
}
Variant DateTime::sub(const Variant &interval) {
    return this_.exec(LITERAL_STRING[17], {interval});
}
Variant DateTime::getTimezone() {
    return this_.exec(LITERAL_STRING[265], {});
}
Variant DateTime::setTimezone(const Variant &timezone) {
    return this_.exec(LITERAL_STRING[266], {timezone});
}
Variant DateTime::getOffset() {
    return this_.exec(LITERAL_STRING[267], {});
}
Variant DateTime::getMicrosecond() {
    return this_.exec(LITERAL_STRING[268], {});
}
Variant DateTime::setTime(const Variant &hour,
                          const Variant &minute,
                          const Variant &second,
                          const Variant &microsecond) {
    return this_.exec(LITERAL_STRING[269], {hour, minute, second, microsecond});
}
Variant DateTime::setDate(const Variant &year, const Variant &month, const Variant &day) {
    return this_.exec(LITERAL_STRING[270], {year, month, day});
}
Variant DateTime::setISODate(const Variant &year, const Variant &week, const Variant &day_of_week) {
    return this_.exec(LITERAL_STRING[271], {year, week, day_of_week});
}
Variant DateTime::setTimestamp(const Variant &timestamp) {
    return this_.exec(LITERAL_STRING[272], {timestamp});
}
Variant DateTime::setMicrosecond(const Variant &microsecond) {
    return this_.exec(LITERAL_STRING[273], {microsecond});
}
Variant DateTime::getTimestamp() {
    return this_.exec(LITERAL_STRING[274], {});
}
Variant DateTime::diff(const Variant &target_object, const Variant &absolute) {
    return this_.exec(LITERAL_STRING[275], {target_object, absolute});
}
DateTimeImmutable::DateTimeImmutable(const Variant &datetime, const Variant &timezone) {
    this_ = newObject(LITERAL_STRING[276], {datetime, timezone});
}
Variant DateTimeImmutable::__serialize() {
    return this_.exec(LITERAL_STRING[30], {});
}
Variant DateTimeImmutable::__unserialize(const Variant &data) {
    return this_.exec(LITERAL_STRING[31], {data});
}
Variant DateTimeImmutable::__wakeup() {
    return this_.exec(LITERAL_STRING[97], {});
}
Variant DateTimeImmutable::__set_state(const Variant &array) {
    return php::call(LITERAL_STRING[277], {array});
}
Variant DateTimeImmutable::createFromFormat(const Variant &format, const Variant &datetime, const Variant &timezone) {
    return php::call(LITERAL_STRING[278], {format, datetime, timezone});
}
Variant DateTimeImmutable::createFromTimestamp(const Variant &timestamp) {
    return php::call(LITERAL_STRING[279], {timestamp});
}
Variant DateTimeImmutable::getLastErrors() {
    return php::call(LITERAL_STRING[280], {});
}
Variant DateTimeImmutable::format(const Variant &format) {
    return this_.exec(LITERAL_STRING[263], {format});
}
Variant DateTimeImmutable::getTimezone() {
    return this_.exec(LITERAL_STRING[265], {});
}
Variant DateTimeImmutable::getOffset() {
    return this_.exec(LITERAL_STRING[267], {});
}
Variant DateTimeImmutable::getTimestamp() {
    return this_.exec(LITERAL_STRING[274], {});
}
Variant DateTimeImmutable::getMicrosecond() {
    return this_.exec(LITERAL_STRING[268], {});
}
Variant DateTimeImmutable::diff(const Variant &target_object, const Variant &absolute) {
    return this_.exec(LITERAL_STRING[275], {target_object, absolute});
}
Variant DateTimeImmutable::modify(const Variant &modifier) {
    return this_.exec(LITERAL_STRING[264], {modifier});
}
Variant DateTimeImmutable::add(const Variant &interval) {
    return this_.exec(LITERAL_STRING[16], {interval});
}
Variant DateTimeImmutable::sub(const Variant &interval) {
    return this_.exec(LITERAL_STRING[17], {interval});
}
Variant DateTimeImmutable::setTimezone(const Variant &timezone) {
    return this_.exec(LITERAL_STRING[266], {timezone});
}
Variant DateTimeImmutable::setTime(const Variant &hour,
                                   const Variant &minute,
                                   const Variant &second,
                                   const Variant &microsecond) {
    return this_.exec(LITERAL_STRING[269], {hour, minute, second, microsecond});
}
Variant DateTimeImmutable::setDate(const Variant &year, const Variant &month, const Variant &day) {
    return this_.exec(LITERAL_STRING[270], {year, month, day});
}
Variant DateTimeImmutable::setISODate(const Variant &year, const Variant &week, const Variant &day_of_week) {
    return this_.exec(LITERAL_STRING[271], {year, week, day_of_week});
}
Variant DateTimeImmutable::setTimestamp(const Variant &timestamp) {
    return this_.exec(LITERAL_STRING[272], {timestamp});
}
Variant DateTimeImmutable::setMicrosecond(const Variant &microsecond) {
    return this_.exec(LITERAL_STRING[273], {microsecond});
}
Variant DateTimeImmutable::createFromMutable(const Variant &object) {
    return php::call(LITERAL_STRING[281], {object});
}
Variant DateTimeImmutable::createFromInterface(const Variant &object) {
    return php::call(LITERAL_STRING[282], {object});
}
DateTimeZone::DateTimeZone(const Variant &timezone) {
    this_ = newObject(LITERAL_STRING[283], {timezone});
}
Variant DateTimeZone::getName() {
    return this_.exec(LITERAL_STRING[284], {});
}
Variant DateTimeZone::getOffset(const Variant &datetime) {
    return this_.exec(LITERAL_STRING[267], {datetime});
}
Variant DateTimeZone::getTransitions(const Variant &timestamp_begin, const Variant &timestamp_end) {
    return this_.exec(LITERAL_STRING[285], {timestamp_begin, timestamp_end});
}
Variant DateTimeZone::getLocation() {
    return this_.exec(LITERAL_STRING[286], {});
}
Variant DateTimeZone::listAbbreviations() {
    return php::call(LITERAL_STRING[287], {});
}
Variant DateTimeZone::listIdentifiers(const Variant &timezone_group, const Variant &country_code) {
    return php::call(LITERAL_STRING[288], {timezone_group, country_code});
}
Variant DateTimeZone::__serialize() {
    return this_.exec(LITERAL_STRING[30], {});
}
Variant DateTimeZone::__unserialize(const Variant &data) {
    return this_.exec(LITERAL_STRING[31], {data});
}
Variant DateTimeZone::__wakeup() {
    return this_.exec(LITERAL_STRING[97], {});
}
Variant DateTimeZone::__set_state(const Variant &array) {
    return php::call(LITERAL_STRING[289], {array});
}
DateInterval::DateInterval(const Variant &duration) {
    this_ = newObject(LITERAL_STRING[290], {duration});
}
Variant DateInterval::createFromDateString(const Variant &datetime) {
    return php::call(LITERAL_STRING[291], {datetime});
}
Variant DateInterval::format(const Variant &format) {
    return this_.exec(LITERAL_STRING[263], {format});
}
Variant DateInterval::__serialize() {
    return this_.exec(LITERAL_STRING[30], {});
}
Variant DateInterval::__unserialize(const Variant &data) {
    return this_.exec(LITERAL_STRING[31], {data});
}
Variant DateInterval::__wakeup() {
    return this_.exec(LITERAL_STRING[97], {});
}
Variant DateInterval::__set_state(const Variant &array) {
    return php::call(LITERAL_STRING[292], {array});
}
Variant DatePeriod::createFromISO8601String(const Variant &specification, const Variant &options) {
    return php::call(LITERAL_STRING[293], {specification, options});
}
DatePeriod::DatePeriod(const Variant &start, const Variant &interval, const Variant &end, const Variant &options) {
    this_ = newObject(LITERAL_STRING[294], {start, interval, end, options});
}
Variant DatePeriod::getStartDate() {
    return this_.exec(LITERAL_STRING[295], {});
}
Variant DatePeriod::getEndDate() {
    return this_.exec(LITERAL_STRING[296], {});
}
Variant DatePeriod::getDateInterval() {
    return this_.exec(LITERAL_STRING[297], {});
}
Variant DatePeriod::getRecurrences() {
    return this_.exec(LITERAL_STRING[298], {});
}
Variant DatePeriod::__serialize() {
    return this_.exec(LITERAL_STRING[30], {});
}
Variant DatePeriod::__unserialize(const Variant &data) {
    return this_.exec(LITERAL_STRING[31], {data});
}
Variant DatePeriod::__wakeup() {
    return this_.exec(LITERAL_STRING[97], {});
}
Variant DatePeriod::__set_state(const Variant &array) {
    return php::call(LITERAL_STRING[299], {array});
}
Variant DatePeriod::getIterator() {
    return this_.exec(LITERAL_STRING[137], {});
}
DateError::DateError(const Variant &message, const Variant &code, const Variant &previous) {
    this_ = newObject(LITERAL_STRING[300], {message, code, previous});
}
Variant DateError::__wakeup() {
    return this_.exec(LITERAL_STRING[97], {});
}
Variant DateError::getMessage() {
    return this_.exec(LITERAL_STRING[98], {});
}
Variant DateError::getCode() {
    return this_.exec(LITERAL_STRING[99], {});
}
Variant DateError::getFile() {
    return this_.exec(LITERAL_STRING[100], {});
}
Variant DateError::getLine() {
    return this_.exec(LITERAL_STRING[101], {});
}
Variant DateError::getTrace() {
    return this_.exec(LITERAL_STRING[102], {});
}
Variant DateError::getPrevious() {
    return this_.exec(LITERAL_STRING[103], {});
}
Variant DateError::getTraceAsString() {
    return this_.exec(LITERAL_STRING[104], {});
}
Variant DateError::__toString() {
    return this_.exec(LITERAL_STRING[29], {});
}
DateObjectError::DateObjectError(const Variant &message, const Variant &code, const Variant &previous) {
    this_ = newObject(LITERAL_STRING[301], {message, code, previous});
}
Variant DateObjectError::__wakeup() {
    return this_.exec(LITERAL_STRING[97], {});
}
Variant DateObjectError::getMessage() {
    return this_.exec(LITERAL_STRING[98], {});
}
Variant DateObjectError::getCode() {
    return this_.exec(LITERAL_STRING[99], {});
}
Variant DateObjectError::getFile() {
    return this_.exec(LITERAL_STRING[100], {});
}
Variant DateObjectError::getLine() {
    return this_.exec(LITERAL_STRING[101], {});
}
Variant DateObjectError::getTrace() {
    return this_.exec(LITERAL_STRING[102], {});
}
Variant DateObjectError::getPrevious() {
    return this_.exec(LITERAL_STRING[103], {});
}
Variant DateObjectError::getTraceAsString() {
    return this_.exec(LITERAL_STRING[104], {});
}
Variant DateObjectError::__toString() {
    return this_.exec(LITERAL_STRING[29], {});
}
DateRangeError::DateRangeError(const Variant &message, const Variant &code, const Variant &previous) {
    this_ = newObject(LITERAL_STRING[302], {message, code, previous});
}
Variant DateRangeError::__wakeup() {
    return this_.exec(LITERAL_STRING[97], {});
}
Variant DateRangeError::getMessage() {
    return this_.exec(LITERAL_STRING[98], {});
}
Variant DateRangeError::getCode() {
    return this_.exec(LITERAL_STRING[99], {});
}
Variant DateRangeError::getFile() {
    return this_.exec(LITERAL_STRING[100], {});
}
Variant DateRangeError::getLine() {
    return this_.exec(LITERAL_STRING[101], {});
}
Variant DateRangeError::getTrace() {
    return this_.exec(LITERAL_STRING[102], {});
}
Variant DateRangeError::getPrevious() {
    return this_.exec(LITERAL_STRING[103], {});
}
Variant DateRangeError::getTraceAsString() {
    return this_.exec(LITERAL_STRING[104], {});
}
Variant DateRangeError::__toString() {
    return this_.exec(LITERAL_STRING[29], {});
}
DateException::DateException(const Variant &message, const Variant &code, const Variant &previous) {
    this_ = newObject(LITERAL_STRING[303], {message, code, previous});
}
Variant DateException::__wakeup() {
    return this_.exec(LITERAL_STRING[97], {});
}
Variant DateException::getMessage() {
    return this_.exec(LITERAL_STRING[98], {});
}
Variant DateException::getCode() {
    return this_.exec(LITERAL_STRING[99], {});
}
Variant DateException::getFile() {
    return this_.exec(LITERAL_STRING[100], {});
}
Variant DateException::getLine() {
    return this_.exec(LITERAL_STRING[101], {});
}
Variant DateException::getTrace() {
    return this_.exec(LITERAL_STRING[102], {});
}
Variant DateException::getPrevious() {
    return this_.exec(LITERAL_STRING[103], {});
}
Variant DateException::getTraceAsString() {
    return this_.exec(LITERAL_STRING[104], {});
}
Variant DateException::__toString() {
    return this_.exec(LITERAL_STRING[29], {});
}
DateInvalidTimeZoneException::DateInvalidTimeZoneException(const Variant &message,
                                                           const Variant &code,
                                                           const Variant &previous) {
    this_ = newObject(LITERAL_STRING[304], {message, code, previous});
}
Variant DateInvalidTimeZoneException::__wakeup() {
    return this_.exec(LITERAL_STRING[97], {});
}
Variant DateInvalidTimeZoneException::getMessage() {
    return this_.exec(LITERAL_STRING[98], {});
}
Variant DateInvalidTimeZoneException::getCode() {
    return this_.exec(LITERAL_STRING[99], {});
}
Variant DateInvalidTimeZoneException::getFile() {
    return this_.exec(LITERAL_STRING[100], {});
}
Variant DateInvalidTimeZoneException::getLine() {
    return this_.exec(LITERAL_STRING[101], {});
}
Variant DateInvalidTimeZoneException::getTrace() {
    return this_.exec(LITERAL_STRING[102], {});
}
Variant DateInvalidTimeZoneException::getPrevious() {
    return this_.exec(LITERAL_STRING[103], {});
}
Variant DateInvalidTimeZoneException::getTraceAsString() {
    return this_.exec(LITERAL_STRING[104], {});
}
Variant DateInvalidTimeZoneException::__toString() {
    return this_.exec(LITERAL_STRING[29], {});
}
DateInvalidOperationException::DateInvalidOperationException(const Variant &message,
                                                             const Variant &code,
                                                             const Variant &previous) {
    this_ = newObject(LITERAL_STRING[305], {message, code, previous});
}
Variant DateInvalidOperationException::__wakeup() {
    return this_.exec(LITERAL_STRING[97], {});
}
Variant DateInvalidOperationException::getMessage() {
    return this_.exec(LITERAL_STRING[98], {});
}
Variant DateInvalidOperationException::getCode() {
    return this_.exec(LITERAL_STRING[99], {});
}
Variant DateInvalidOperationException::getFile() {
    return this_.exec(LITERAL_STRING[100], {});
}
Variant DateInvalidOperationException::getLine() {
    return this_.exec(LITERAL_STRING[101], {});
}
Variant DateInvalidOperationException::getTrace() {
    return this_.exec(LITERAL_STRING[102], {});
}
Variant DateInvalidOperationException::getPrevious() {
    return this_.exec(LITERAL_STRING[103], {});
}
Variant DateInvalidOperationException::getTraceAsString() {
    return this_.exec(LITERAL_STRING[104], {});
}
Variant DateInvalidOperationException::__toString() {
    return this_.exec(LITERAL_STRING[29], {});
}
DateMalformedStringException::DateMalformedStringException(const Variant &message,
                                                           const Variant &code,
                                                           const Variant &previous) {
    this_ = newObject(LITERAL_STRING[306], {message, code, previous});
}
Variant DateMalformedStringException::__wakeup() {
    return this_.exec(LITERAL_STRING[97], {});
}
Variant DateMalformedStringException::getMessage() {
    return this_.exec(LITERAL_STRING[98], {});
}
Variant DateMalformedStringException::getCode() {
    return this_.exec(LITERAL_STRING[99], {});
}
Variant DateMalformedStringException::getFile() {
    return this_.exec(LITERAL_STRING[100], {});
}
Variant DateMalformedStringException::getLine() {
    return this_.exec(LITERAL_STRING[101], {});
}
Variant DateMalformedStringException::getTrace() {
    return this_.exec(LITERAL_STRING[102], {});
}
Variant DateMalformedStringException::getPrevious() {
    return this_.exec(LITERAL_STRING[103], {});
}
Variant DateMalformedStringException::getTraceAsString() {
    return this_.exec(LITERAL_STRING[104], {});
}
Variant DateMalformedStringException::__toString() {
    return this_.exec(LITERAL_STRING[29], {});
}
DateMalformedIntervalStringException::DateMalformedIntervalStringException(const Variant &message,
                                                                           const Variant &code,
                                                                           const Variant &previous) {
    this_ = newObject(LITERAL_STRING[307], {message, code, previous});
}
Variant DateMalformedIntervalStringException::__wakeup() {
    return this_.exec(LITERAL_STRING[97], {});
}
Variant DateMalformedIntervalStringException::getMessage() {
    return this_.exec(LITERAL_STRING[98], {});
}
Variant DateMalformedIntervalStringException::getCode() {
    return this_.exec(LITERAL_STRING[99], {});
}
Variant DateMalformedIntervalStringException::getFile() {
    return this_.exec(LITERAL_STRING[100], {});
}
Variant DateMalformedIntervalStringException::getLine() {
    return this_.exec(LITERAL_STRING[101], {});
}
Variant DateMalformedIntervalStringException::getTrace() {
    return this_.exec(LITERAL_STRING[102], {});
}
Variant DateMalformedIntervalStringException::getPrevious() {
    return this_.exec(LITERAL_STRING[103], {});
}
Variant DateMalformedIntervalStringException::getTraceAsString() {
    return this_.exec(LITERAL_STRING[104], {});
}
Variant DateMalformedIntervalStringException::__toString() {
    return this_.exec(LITERAL_STRING[29], {});
}
DateMalformedPeriodStringException::DateMalformedPeriodStringException(const Variant &message,
                                                                       const Variant &code,
                                                                       const Variant &previous) {
    this_ = newObject(LITERAL_STRING[308], {message, code, previous});
}
Variant DateMalformedPeriodStringException::__wakeup() {
    return this_.exec(LITERAL_STRING[97], {});
}
Variant DateMalformedPeriodStringException::getMessage() {
    return this_.exec(LITERAL_STRING[98], {});
}
Variant DateMalformedPeriodStringException::getCode() {
    return this_.exec(LITERAL_STRING[99], {});
}
Variant DateMalformedPeriodStringException::getFile() {
    return this_.exec(LITERAL_STRING[100], {});
}
Variant DateMalformedPeriodStringException::getLine() {
    return this_.exec(LITERAL_STRING[101], {});
}
Variant DateMalformedPeriodStringException::getTrace() {
    return this_.exec(LITERAL_STRING[102], {});
}
Variant DateMalformedPeriodStringException::getPrevious() {
    return this_.exec(LITERAL_STRING[103], {});
}
Variant DateMalformedPeriodStringException::getTraceAsString() {
    return this_.exec(LITERAL_STRING[104], {});
}
Variant DateMalformedPeriodStringException::__toString() {
    return this_.exec(LITERAL_STRING[29], {});
}
}  // namespace php

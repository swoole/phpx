#include "phpx.h"
#include "phpx_literal_string.h"
#include "phpx_class.h"

namespace php {
Variant strtotime(const Variant &datetime, const Variant &base_timestamp) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[245]);
    }
    return call(_fn, {datetime, base_timestamp});
}
Variant date(const Variant &format, const Variant &timestamp) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[246]);
    }
    return call(_fn, {format, timestamp});
}
Variant idate(const Variant &format, const Variant &timestamp) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[247]);
    }
    return call(_fn, {format, timestamp});
}
Variant gmdate(const Variant &format, const Variant &timestamp) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[248]);
    }
    return call(_fn, {format, timestamp});
}
Variant mktime(const Variant &hour,
               const Variant &minute,
               const Variant &second,
               const Variant &month,
               const Variant &day,
               const Variant &year) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[249]);
    }
    return call(_fn, {hour, minute, second, month, day, year});
}
Variant gmmktime(const Variant &hour,
                 const Variant &minute,
                 const Variant &second,
                 const Variant &month,
                 const Variant &day,
                 const Variant &year) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[250]);
    }
    return call(_fn, {hour, minute, second, month, day, year});
}
Variant checkdate(const Variant &month, const Variant &day, const Variant &year) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[251]);
    }
    return call(_fn, {month, day, year});
}
Variant strftime(const Variant &format, const Variant &timestamp) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[252]);
    }
    return call(_fn, {format, timestamp});
}
Variant gmstrftime(const Variant &format, const Variant &timestamp) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[253]);
    }
    return call(_fn, {format, timestamp});
}
Variant time() {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[254]);
    }
    return call(_fn, {});
}
Variant localtime(const Variant &timestamp, const Variant &associative) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[255]);
    }
    return call(_fn, {timestamp, associative});
}
Variant getdate(const Variant &timestamp) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[256]);
    }
    return call(_fn, {timestamp});
}
Variant date_create(const Variant &datetime, const Variant &timezone) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[257]);
    }
    return call(_fn, {datetime, timezone});
}
Variant date_create_immutable(const Variant &datetime, const Variant &timezone) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[258]);
    }
    return call(_fn, {datetime, timezone});
}
Variant date_create_from_format(const Variant &format, const Variant &datetime, const Variant &timezone) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[259]);
    }
    return call(_fn, {format, datetime, timezone});
}
Variant date_create_immutable_from_format(const Variant &format, const Variant &datetime, const Variant &timezone) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[260]);
    }
    return call(_fn, {format, datetime, timezone});
}
Variant date_parse(const Variant &datetime) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[261]);
    }
    return call(_fn, {datetime});
}
Variant date_parse_from_format(const Variant &format, const Variant &datetime) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[262]);
    }
    return call(_fn, {format, datetime});
}
Variant date_get_last_errors() {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[263]);
    }
    return call(_fn, {});
}
Variant date_format(const Variant &object, const Variant &format) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[264]);
    }
    return call(_fn, {object, format});
}
Variant date_modify(const DateTime &object, const Variant &modifier) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[265]);
    }
    return call(_fn, {object.getObject(), modifier});
}
Variant date_modify(const Variant &object, const Variant &modifier) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[265]);
    }
    return call(_fn, {object, modifier});
}
Variant date_add(const DateTime &object, const DateInterval &interval) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[266]);
    }
    return call(_fn, {object.getObject(), interval.getObject()});
}
Variant date_add(const Variant &object, const Variant &interval) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[266]);
    }
    return call(_fn, {object, interval});
}
Variant date_sub(const DateTime &object, const DateInterval &interval) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[267]);
    }
    return call(_fn, {object.getObject(), interval.getObject()});
}
Variant date_sub(const Variant &object, const Variant &interval) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[267]);
    }
    return call(_fn, {object, interval});
}
Variant date_timezone_get(const Variant &object) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[268]);
    }
    return call(_fn, {object});
}
Variant date_timezone_set(const DateTime &object, const DateTimeZone &timezone) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[269]);
    }
    return call(_fn, {object.getObject(), timezone.getObject()});
}
Variant date_timezone_set(const Variant &object, const Variant &timezone) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[269]);
    }
    return call(_fn, {object, timezone});
}
Variant date_offset_get(const Variant &object) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[270]);
    }
    return call(_fn, {object});
}
Variant date_diff(const Variant &base_object, const Variant &target_object, const Variant &absolute) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[271]);
    }
    return call(_fn, {base_object, target_object, absolute});
}
Variant date_time_set(const DateTime &object,
                      const Variant &hour,
                      const Variant &minute,
                      const Variant &second,
                      const Variant &microsecond) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[272]);
    }
    return call(_fn, {object.getObject(), hour, minute, second, microsecond});
}
Variant date_time_set(const Variant &object,
                      const Variant &hour,
                      const Variant &minute,
                      const Variant &second,
                      const Variant &microsecond) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[272]);
    }
    return call(_fn, {object, hour, minute, second, microsecond});
}
Variant date_date_set(const DateTime &object, const Variant &year, const Variant &month, const Variant &day) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[273]);
    }
    return call(_fn, {object.getObject(), year, month, day});
}
Variant date_date_set(const Variant &object, const Variant &year, const Variant &month, const Variant &day) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[273]);
    }
    return call(_fn, {object, year, month, day});
}
Variant date_isodate_set(const DateTime &object, const Variant &year, const Variant &week, const Variant &day_of_week) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[274]);
    }
    return call(_fn, {object.getObject(), year, week, day_of_week});
}
Variant date_isodate_set(const Variant &object, const Variant &year, const Variant &week, const Variant &day_of_week) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[274]);
    }
    return call(_fn, {object, year, week, day_of_week});
}
Variant date_timestamp_set(const DateTime &object, const Variant &timestamp) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[275]);
    }
    return call(_fn, {object.getObject(), timestamp});
}
Variant date_timestamp_set(const Variant &object, const Variant &timestamp) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[275]);
    }
    return call(_fn, {object, timestamp});
}
Variant date_timestamp_get(const Variant &object) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[276]);
    }
    return call(_fn, {object});
}
Variant timezone_open(const Variant &timezone) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[277]);
    }
    return call(_fn, {timezone});
}
Variant timezone_name_get(const DateTimeZone &object) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[278]);
    }
    return call(_fn, {object.getObject()});
}
Variant timezone_name_get(const Variant &object) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[278]);
    }
    return call(_fn, {object});
}
Variant timezone_name_from_abbr(const Variant &abbr, const Variant &utc_offset, const Variant &is_d_s_t) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[279]);
    }
    return call(_fn, {abbr, utc_offset, is_d_s_t});
}
Variant timezone_offset_get(const DateTimeZone &object, const Variant &datetime) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[280]);
    }
    return call(_fn, {object.getObject(), datetime});
}
Variant timezone_offset_get(const Variant &object, const Variant &datetime) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[280]);
    }
    return call(_fn, {object, datetime});
}
Variant timezone_transitions_get(const DateTimeZone &object,
                                 const Variant &timestamp_begin,
                                 const Variant &timestamp_end) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[281]);
    }
    return call(_fn, {object.getObject(), timestamp_begin, timestamp_end});
}
Variant timezone_transitions_get(const Variant &object, const Variant &timestamp_begin, const Variant &timestamp_end) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[281]);
    }
    return call(_fn, {object, timestamp_begin, timestamp_end});
}
Variant timezone_location_get(const DateTimeZone &object) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[282]);
    }
    return call(_fn, {object.getObject()});
}
Variant timezone_location_get(const Variant &object) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[282]);
    }
    return call(_fn, {object});
}
Variant timezone_identifiers_list(const Variant &timezone_group, const Variant &country_code) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[283]);
    }
    return call(_fn, {timezone_group, country_code});
}
Variant timezone_abbreviations_list() {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[284]);
    }
    return call(_fn, {});
}
Variant timezone_version_get() {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[285]);
    }
    return call(_fn, {});
}
Variant date_interval_create_from_date_string(const Variant &datetime) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[286]);
    }
    return call(_fn, {datetime});
}
Variant date_interval_format(const DateInterval &object, const Variant &format) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[287]);
    }
    return call(_fn, {object.getObject(), format});
}
Variant date_interval_format(const Variant &object, const Variant &format) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[287]);
    }
    return call(_fn, {object, format});
}
Variant date_default_timezone_set(const Variant &timezone_id) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[288]);
    }
    return call(_fn, {timezone_id});
}
Variant date_default_timezone_get() {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[289]);
    }
    return call(_fn, {});
}
Variant date_sunrise(const Variant &timestamp,
                     const Variant &return_format,
                     const Variant &latitude,
                     const Variant &longitude,
                     const Variant &zenith,
                     const Variant &utc_offset) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[290]);
    }
    return call(_fn, {timestamp, return_format, latitude, longitude, zenith, utc_offset});
}
Variant date_sunset(const Variant &timestamp,
                    const Variant &return_format,
                    const Variant &latitude,
                    const Variant &longitude,
                    const Variant &zenith,
                    const Variant &utc_offset) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[291]);
    }
    return call(_fn, {timestamp, return_format, latitude, longitude, zenith, utc_offset});
}
Variant date_sun_info(const Variant &timestamp, const Variant &latitude, const Variant &longitude) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[292]);
    }
    return call(_fn, {timestamp, latitude, longitude});
}
}  // namespace php

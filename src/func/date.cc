#include "phpx.h"
#include "phpx_literal_string.h"

namespace php {
Variant strtotime(const Variant &datetime, const Variant &base_timestamp) {
    return call(LITERAL_STRING[208], {datetime, base_timestamp});
}
Variant date(const Variant &format, const Variant &timestamp) {
    return call(LITERAL_STRING[209], {format, timestamp});
}
Variant idate(const Variant &format, const Variant &timestamp) {
    return call(LITERAL_STRING[210], {format, timestamp});
}
Variant gmdate(const Variant &format, const Variant &timestamp) {
    return call(LITERAL_STRING[211], {format, timestamp});
}
Variant mktime(const Variant &hour,
               const Variant &minute,
               const Variant &second,
               const Variant &month,
               const Variant &day,
               const Variant &year) {
    return call(LITERAL_STRING[212], {hour, minute, second, month, day, year});
}
Variant gmmktime(const Variant &hour,
                 const Variant &minute,
                 const Variant &second,
                 const Variant &month,
                 const Variant &day,
                 const Variant &year) {
    return call(LITERAL_STRING[213], {hour, minute, second, month, day, year});
}
Variant checkdate(const Variant &month, const Variant &day, const Variant &year) {
    return call(LITERAL_STRING[214], {month, day, year});
}
Variant strftime(const Variant &format, const Variant &timestamp) {
    return call(LITERAL_STRING[215], {format, timestamp});
}
Variant gmstrftime(const Variant &format, const Variant &timestamp) {
    return call(LITERAL_STRING[216], {format, timestamp});
}
Variant time() {
    return call(LITERAL_STRING[217], {});
}
Variant localtime(const Variant &timestamp, const Variant &associative) {
    return call(LITERAL_STRING[218], {timestamp, associative});
}
Variant getdate(const Variant &timestamp) {
    return call(LITERAL_STRING[219], {timestamp});
}
Variant date_create(const Variant &datetime, const Variant &timezone) {
    return call(LITERAL_STRING[220], {datetime, timezone});
}
Variant date_create_immutable(const Variant &datetime, const Variant &timezone) {
    return call(LITERAL_STRING[221], {datetime, timezone});
}
Variant date_create_from_format(const Variant &format, const Variant &datetime, const Variant &timezone) {
    return call(LITERAL_STRING[222], {format, datetime, timezone});
}
Variant date_create_immutable_from_format(const Variant &format, const Variant &datetime, const Variant &timezone) {
    return call(LITERAL_STRING[223], {format, datetime, timezone});
}
Variant date_parse(const Variant &datetime) {
    return call(LITERAL_STRING[224], {datetime});
}
Variant date_parse_from_format(const Variant &format, const Variant &datetime) {
    return call(LITERAL_STRING[225], {format, datetime});
}
Variant date_get_last_errors() {
    return call(LITERAL_STRING[226], {});
}
Variant date_format(const Variant &object, const Variant &format) {
    return call(LITERAL_STRING[227], {object, format});
}
Variant date_modify(const Variant &object, const Variant &modifier) {
    return call(LITERAL_STRING[228], {object, modifier});
}
Variant date_add(const Variant &object, const Variant &interval) {
    return call(LITERAL_STRING[229], {object, interval});
}
Variant date_sub(const Variant &object, const Variant &interval) {
    return call(LITERAL_STRING[230], {object, interval});
}
Variant date_timezone_get(const Variant &object) {
    return call(LITERAL_STRING[231], {object});
}
Variant date_timezone_set(const Variant &object, const Variant &timezone) {
    return call(LITERAL_STRING[232], {object, timezone});
}
Variant date_offset_get(const Variant &object) {
    return call(LITERAL_STRING[233], {object});
}
Variant date_diff(const Variant &base_object, const Variant &target_object, const Variant &absolute) {
    return call(LITERAL_STRING[234], {base_object, target_object, absolute});
}
Variant date_time_set(const Variant &object,
                      const Variant &hour,
                      const Variant &minute,
                      const Variant &second,
                      const Variant &microsecond) {
    return call(LITERAL_STRING[235], {object, hour, minute, second, microsecond});
}
Variant date_date_set(const Variant &object, const Variant &year, const Variant &month, const Variant &day) {
    return call(LITERAL_STRING[236], {object, year, month, day});
}
Variant date_isodate_set(const Variant &object, const Variant &year, const Variant &week, const Variant &day_of_week) {
    return call(LITERAL_STRING[237], {object, year, week, day_of_week});
}
Variant date_timestamp_set(const Variant &object, const Variant &timestamp) {
    return call(LITERAL_STRING[238], {object, timestamp});
}
Variant date_timestamp_get(const Variant &object) {
    return call(LITERAL_STRING[239], {object});
}
Variant timezone_open(const Variant &timezone) {
    return call(LITERAL_STRING[240], {timezone});
}
Variant timezone_name_get(const Variant &object) {
    return call(LITERAL_STRING[241], {object});
}
Variant timezone_name_from_abbr(const Variant &abbr, const Variant &utc_offset, const Variant &is_d_s_t) {
    return call(LITERAL_STRING[242], {abbr, utc_offset, is_d_s_t});
}
Variant timezone_offset_get(const Variant &object, const Variant &datetime) {
    return call(LITERAL_STRING[243], {object, datetime});
}
Variant timezone_transitions_get(const Variant &object, const Variant &timestamp_begin, const Variant &timestamp_end) {
    return call(LITERAL_STRING[244], {object, timestamp_begin, timestamp_end});
}
Variant timezone_location_get(const Variant &object) {
    return call(LITERAL_STRING[245], {object});
}
Variant timezone_identifiers_list(const Variant &timezone_group, const Variant &country_code) {
    return call(LITERAL_STRING[246], {timezone_group, country_code});
}
Variant timezone_abbreviations_list() {
    return call(LITERAL_STRING[247], {});
}
Variant timezone_version_get() {
    return call(LITERAL_STRING[248], {});
}
Variant date_interval_create_from_date_string(const Variant &datetime) {
    return call(LITERAL_STRING[249], {datetime});
}
Variant date_interval_format(const Variant &object, const Variant &format) {
    return call(LITERAL_STRING[250], {object, format});
}
Variant date_default_timezone_set(const Variant &timezone_id) {
    return call(LITERAL_STRING[251], {timezone_id});
}
Variant date_default_timezone_get() {
    return call(LITERAL_STRING[252], {});
}
Variant date_sunrise(const Variant &timestamp,
                     const Variant &return_format,
                     const Variant &latitude,
                     const Variant &longitude,
                     const Variant &zenith,
                     const Variant &utc_offset) {
    return call(LITERAL_STRING[253], {timestamp, return_format, latitude, longitude, zenith, utc_offset});
}
Variant date_sunset(const Variant &timestamp,
                    const Variant &return_format,
                    const Variant &latitude,
                    const Variant &longitude,
                    const Variant &zenith,
                    const Variant &utc_offset) {
    return call(LITERAL_STRING[254], {timestamp, return_format, latitude, longitude, zenith, utc_offset});
}
Variant date_sun_info(const Variant &timestamp, const Variant &latitude, const Variant &longitude) {
    return call(LITERAL_STRING[255], {timestamp, latitude, longitude});
}
}  // namespace php

#include "phpx.h"

namespace php {
Variant strtotime(const Variant &datetime, const Variant &base_timestamp) {
    return call("strtotime", {datetime, base_timestamp});
}
Variant date(const Variant &format, const Variant &timestamp) {
    return call("date", {format, timestamp});
}
Variant idate(const Variant &format, const Variant &timestamp) {
    return call("idate", {format, timestamp});
}
Variant gmdate(const Variant &format, const Variant &timestamp) {
    return call("gmdate", {format, timestamp});
}
Variant mktime(const Variant &hour, const Variant &minute, const Variant &second, const Variant &month, const Variant &day, const Variant &year) {
    return call("mktime", {hour, minute, second, month, day, year});
}
Variant gmmktime(const Variant &hour, const Variant &minute, const Variant &second, const Variant &month, const Variant &day, const Variant &year) {
    return call("gmmktime", {hour, minute, second, month, day, year});
}
Variant checkdate(const Variant &month, const Variant &day, const Variant &year) {
    return call("checkdate", {month, day, year});
}
Variant strftime(const Variant &format, const Variant &timestamp) {
    return call("strftime", {format, timestamp});
}
Variant gmstrftime(const Variant &format, const Variant &timestamp) {
    return call("gmstrftime", {format, timestamp});
}
Variant time() {
    return call("time", {});
}
Variant localtime(const Variant &timestamp, const Variant &associative) {
    return call("localtime", {timestamp, associative});
}
Variant getdate(const Variant &timestamp) {
    return call("getdate", {timestamp});
}
Variant date_create(const Variant &datetime, const Variant &timezone) {
    return call("date_create", {datetime, timezone});
}
Variant date_create_immutable(const Variant &datetime, const Variant &timezone) {
    return call("date_create_immutable", {datetime, timezone});
}
Variant date_create_from_format(const Variant &format, const Variant &datetime, const Variant &timezone) {
    return call("date_create_from_format", {format, datetime, timezone});
}
Variant date_create_immutable_from_format(const Variant &format, const Variant &datetime, const Variant &timezone) {
    return call("date_create_immutable_from_format", {format, datetime, timezone});
}
Variant date_parse(const Variant &datetime) {
    return call("date_parse", {datetime});
}
Variant date_parse_from_format(const Variant &format, const Variant &datetime) {
    return call("date_parse_from_format", {format, datetime});
}
Variant date_get_last_errors() {
    return call("date_get_last_errors", {});
}
Variant date_format(const Variant &object, const Variant &format) {
    return call("date_format", {object, format});
}
Variant date_modify(const Variant &object, const Variant &modifier) {
    return call("date_modify", {object, modifier});
}
Variant date_add(const Variant &object, const Variant &interval) {
    return call("date_add", {object, interval});
}
Variant date_sub(const Variant &object, const Variant &interval) {
    return call("date_sub", {object, interval});
}
Variant date_timezone_get(const Variant &object) {
    return call("date_timezone_get", {object});
}
Variant date_timezone_set(const Variant &object, const Variant &timezone) {
    return call("date_timezone_set", {object, timezone});
}
Variant date_offset_get(const Variant &object) {
    return call("date_offset_get", {object});
}
Variant date_diff(const Variant &base_object, const Variant &target_object, const Variant &absolute) {
    return call("date_diff", {base_object, target_object, absolute});
}
Variant date_time_set(const Variant &object, const Variant &hour, const Variant &minute, const Variant &second, const Variant &microsecond) {
    return call("date_time_set", {object, hour, minute, second, microsecond});
}
Variant date_date_set(const Variant &object, const Variant &year, const Variant &month, const Variant &day) {
    return call("date_date_set", {object, year, month, day});
}
Variant date_isodate_set(const Variant &object, const Variant &year, const Variant &week, const Variant &day_of_week) {
    return call("date_isodate_set", {object, year, week, day_of_week});
}
Variant date_timestamp_set(const Variant &object, const Variant &timestamp) {
    return call("date_timestamp_set", {object, timestamp});
}
Variant date_timestamp_get(const Variant &object) {
    return call("date_timestamp_get", {object});
}
Variant timezone_open(const Variant &timezone) {
    return call("timezone_open", {timezone});
}
Variant timezone_name_get(const Variant &object) {
    return call("timezone_name_get", {object});
}
Variant timezone_name_from_abbr(const Variant &abbr, const Variant &utc_offset, const Variant &is_d_s_t) {
    return call("timezone_name_from_abbr", {abbr, utc_offset, is_d_s_t});
}
Variant timezone_offset_get(const Variant &object, const Variant &datetime) {
    return call("timezone_offset_get", {object, datetime});
}
Variant timezone_transitions_get(const Variant &object, const Variant &timestamp_begin, const Variant &timestamp_end) {
    return call("timezone_transitions_get", {object, timestamp_begin, timestamp_end});
}
Variant timezone_location_get(const Variant &object) {
    return call("timezone_location_get", {object});
}
Variant timezone_identifiers_list(const Variant &timezone_group, const Variant &country_code) {
    return call("timezone_identifiers_list", {timezone_group, country_code});
}
Variant timezone_abbreviations_list() {
    return call("timezone_abbreviations_list", {});
}
Variant timezone_version_get() {
    return call("timezone_version_get", {});
}
Variant date_interval_create_from_date_string(const Variant &datetime) {
    return call("date_interval_create_from_date_string", {datetime});
}
Variant date_interval_format(const Variant &object, const Variant &format) {
    return call("date_interval_format", {object, format});
}
Variant date_default_timezone_set(const Variant &timezone_id) {
    return call("date_default_timezone_set", {timezone_id});
}
Variant date_default_timezone_get() {
    return call("date_default_timezone_get", {});
}
Variant date_sunrise(const Variant &timestamp, const Variant &return_format, const Variant &latitude, const Variant &longitude, const Variant &zenith, const Variant &utc_offset) {
    return call("date_sunrise", {timestamp, return_format, latitude, longitude, zenith, utc_offset});
}
Variant date_sunset(const Variant &timestamp, const Variant &return_format, const Variant &latitude, const Variant &longitude, const Variant &zenith, const Variant &utc_offset) {
    return call("date_sunset", {timestamp, return_format, latitude, longitude, zenith, utc_offset});
}
Variant date_sun_info(const Variant &timestamp, const Variant &latitude, const Variant &longitude) {
    return call("date_sun_info", {timestamp, latitude, longitude});
}
}

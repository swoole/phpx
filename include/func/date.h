#include "phpx.h"
#include "phpx_literal_string.h"

namespace php {
Variant strtotime(const Variant &datetime, const Variant &base_timestamp = {});
Variant date(const Variant &format, const Variant &timestamp = {});
Variant idate(const Variant &format, const Variant &timestamp = {});
Variant gmdate(const Variant &format, const Variant &timestamp = {});
Variant mktime(const Variant &hour,
               const Variant &minute = {},
               const Variant &second = {},
               const Variant &month = {},
               const Variant &day = {},
               const Variant &year = {});
Variant gmmktime(const Variant &hour,
                 const Variant &minute = {},
                 const Variant &second = {},
                 const Variant &month = {},
                 const Variant &day = {},
                 const Variant &year = {});
Variant checkdate(const Variant &month, const Variant &day, const Variant &year);
Variant strftime(const Variant &format, const Variant &timestamp = {});
Variant gmstrftime(const Variant &format, const Variant &timestamp = {});
Variant time();
Variant localtime(const Variant &timestamp = {}, const Variant &associative = false);
Variant getdate(const Variant &timestamp = {});
Variant date_create(const Variant &datetime = "now", const Variant &timezone = {});
Variant date_create_immutable(const Variant &datetime = "now", const Variant &timezone = {});
Variant date_create_from_format(const Variant &format, const Variant &datetime, const Variant &timezone = {});
Variant date_create_immutable_from_format(const Variant &format, const Variant &datetime, const Variant &timezone = {});
Variant date_parse(const Variant &datetime);
Variant date_parse_from_format(const Variant &format, const Variant &datetime);
Variant date_get_last_errors();
Variant date_format(const Variant &object, const Variant &format);
Variant date_modify(const Variant &object, const Variant &modifier);
Variant date_add(const Variant &object, const Variant &interval);
Variant date_sub(const Variant &object, const Variant &interval);
Variant date_timezone_get(const Variant &object);
Variant date_timezone_set(const Variant &object, const Variant &timezone);
Variant date_offset_get(const Variant &object);
Variant date_diff(const Variant &base_object, const Variant &target_object, const Variant &absolute = false);
Variant date_time_set(const Variant &object,
                      const Variant &hour,
                      const Variant &minute,
                      const Variant &second = 0,
                      const Variant &microsecond = 0);
Variant date_date_set(const Variant &object, const Variant &year, const Variant &month, const Variant &day);
Variant date_isodate_set(const Variant &object,
                         const Variant &year,
                         const Variant &week,
                         const Variant &day_of_week = 1);
Variant date_timestamp_set(const Variant &object, const Variant &timestamp);
Variant date_timestamp_get(const Variant &object);
Variant timezone_open(const Variant &timezone);
Variant timezone_name_get(const Variant &object);
Variant timezone_name_from_abbr(const Variant &abbr, const Variant &utc_offset = -1, const Variant &is_d_s_t = -1);
Variant timezone_offset_get(const Variant &object, const Variant &datetime);
Variant timezone_transitions_get(const Variant &object,
                                 const Variant &timestamp_begin = LONG_MIN,
                                 const Variant &timestamp_end = LONG_MAX);
Variant timezone_location_get(const Variant &object);
Variant timezone_identifiers_list(const Variant &timezone_group = 2047, const Variant &country_code = {});
Variant timezone_abbreviations_list();
Variant timezone_version_get();
Variant date_interval_create_from_date_string(const Variant &datetime);
Variant date_interval_format(const Variant &object, const Variant &format);
Variant date_default_timezone_set(const Variant &timezone_id);
Variant date_default_timezone_get();
Variant date_sunrise(const Variant &timestamp,
                     const Variant &return_format = 1,
                     const Variant &latitude = {},
                     const Variant &longitude = {},
                     const Variant &zenith = {},
                     const Variant &utc_offset = {});
Variant date_sunset(const Variant &timestamp,
                    const Variant &return_format = 1,
                    const Variant &latitude = {},
                    const Variant &longitude = {},
                    const Variant &zenith = {},
                    const Variant &utc_offset = {});
Variant date_sun_info(const Variant &timestamp, const Variant &latitude, const Variant &longitude);
}  // namespace php

#include "phpx.h"
#include "phpx_literal_string.h"

namespace php {
Variant set_time_limit(const Variant &seconds) {
    return call(LITERAL_STRING[1852], {seconds});
}
Variant header_register_callback(const Variant &callback) {
    return call(LITERAL_STRING[1853], {callback});
}
Variant ob_start(const Variant &callback, const Variant &chunk_size, const Variant &flags) {
    return call(LITERAL_STRING[1854], {callback, chunk_size, flags});
}
Variant ob_flush() {
    return call(LITERAL_STRING[1855], {});
}
Variant ob_clean() {
    return call(LITERAL_STRING[1856], {});
}
Variant ob_end_flush() {
    return call(LITERAL_STRING[1857], {});
}
Variant ob_end_clean() {
    return call(LITERAL_STRING[1858], {});
}
Variant ob_get_flush() {
    return call(LITERAL_STRING[1859], {});
}
Variant ob_get_clean() {
    return call(LITERAL_STRING[1860], {});
}
Variant ob_get_contents() {
    return call(LITERAL_STRING[1861], {});
}
Variant ob_get_level() {
    return call(LITERAL_STRING[1862], {});
}
Variant ob_get_length() {
    return call(LITERAL_STRING[1863], {});
}
Variant ob_list_handlers() {
    return call(LITERAL_STRING[1864], {});
}
Variant ob_get_status(const Variant &full_status) {
    return call(LITERAL_STRING[1865], {full_status});
}
Variant ob_implicit_flush(const Variant &enable) {
    return call(LITERAL_STRING[1866], {enable});
}
Variant output_reset_rewrite_vars() {
    return call(LITERAL_STRING[1867], {});
}
Variant output_add_rewrite_var(const Variant &name, const Variant &value) {
    return call(LITERAL_STRING[1868], {name, value});
}
Variant stream_wrapper_register(const Variant &protocol, const Variant &_class, const Variant &flags) {
    return call(LITERAL_STRING[1869], {protocol, _class, flags});
}
Variant stream_register_wrapper(const Variant &protocol, const Variant &_class, const Variant &flags) {
    return call(LITERAL_STRING[1870], {protocol, _class, flags});
}
Variant stream_wrapper_unregister(const Variant &protocol) {
    return call(LITERAL_STRING[1871], {protocol});
}
Variant stream_wrapper_restore(const Variant &protocol) {
    return call(LITERAL_STRING[1872], {protocol});
}
Variant krsort(const Reference &array, const Variant &flags) {
    return call(LITERAL_STRING[1874], {&array, flags});
}
Variant ksort(const Reference &array, const Variant &flags) {
    return call(LITERAL_STRING[1744], {&array, flags});
}
Variant count(const Variant &value, const Variant &mode) {
    return call(LITERAL_STRING[136], {value, mode});
}
Variant natsort(const Reference &array) {
    return call(LITERAL_STRING[1747], {&array});
}
Variant natcasesort(const Reference &array) {
    return call(LITERAL_STRING[1748], {&array});
}
Variant asort(const Reference &array, const Variant &flags) {
    return call(LITERAL_STRING[1743], {&array, flags});
}
Variant arsort(const Reference &array, const Variant &flags) {
    return call(LITERAL_STRING[1875], {&array, flags});
}
Variant sort(const Reference &array, const Variant &flags) {
    return call(LITERAL_STRING[1227], {&array, flags});
}
Variant rsort(const Reference &array, const Variant &flags) {
    return call(LITERAL_STRING[1876], {&array, flags});
}
Variant usort(const Reference &array, const Variant &callback) {
    return call(LITERAL_STRING[1877], {&array, callback});
}
Variant uasort(const Reference &array, const Variant &callback) {
    return call(LITERAL_STRING[1745], {&array, callback});
}
Variant uksort(const Reference &array, const Variant &callback) {
    return call(LITERAL_STRING[1746], {&array, callback});
}
Variant end(const Reference &array) {
    return call(LITERAL_STRING[1878], {&array});
}
Variant prev(const Reference &array) {
    return call(LITERAL_STRING[1792], {&array});
}
Variant next(const Reference &array) {
    return call(LITERAL_STRING[92], {&array});
}
Variant reset(const Reference &array) {
    return call(LITERAL_STRING[1194], {&array});
}
Variant current(const Variant &array) {
    return call(LITERAL_STRING[90], {array});
}
Variant pos(const Variant &array) {
    return call(LITERAL_STRING[1879], {array});
}
Variant key(const Variant &array) {
    return call(LITERAL_STRING[91], {array});
}
Variant array_walk(const Reference &array, const Variant &callback, const Variant &arg) {
    return call(LITERAL_STRING[1882], {&array, callback, arg});
}
Variant array_walk_recursive(const Reference &array, const Variant &callback, const Variant &arg) {
    return call(LITERAL_STRING[1883], {&array, callback, arg});
}
Variant in_array(const Variant &needle, const Variant &haystack, const Variant &strict) {
    return call(LITERAL_STRING[1884], {needle, haystack, strict});
}
Variant array_search(const Variant &needle, const Variant &haystack, const Variant &strict) {
    return call(LITERAL_STRING[1885], {needle, haystack, strict});
}
Variant extract(const Reference &array, const Variant &flags, const Variant &prefix) {
    return call(LITERAL_STRING[1798], {&array, flags, prefix});
}
Variant array_fill(const Variant &start_index, const Variant &count, const Variant &value) {
    return call(LITERAL_STRING[1887], {start_index, count, value});
}
Variant array_fill_keys(const Variant &keys, const Variant &value) {
    return call(LITERAL_STRING[1888], {keys, value});
}
Variant range(const Variant &start, const Variant &end, const Variant &step) {
    return call(LITERAL_STRING[1889], {start, end, step});
}
Variant shuffle(const Reference &array) {
    return call(LITERAL_STRING[1890], {&array});
}
Variant array_pop(const Reference &array) {
    return call(LITERAL_STRING[1891], {&array});
}
Variant array_shift(const Reference &array) {
    return call(LITERAL_STRING[1892], {&array});
}
Variant array_splice(const Reference &array, const Variant &offset, const Variant &length, const Variant &replacement) {
    return call(LITERAL_STRING[1894], {&array, offset, length, replacement});
}
Variant array_slice(const Variant &array, const Variant &offset, const Variant &length, const Variant &preserve_keys) {
    return call(LITERAL_STRING[1895], {array, offset, length, preserve_keys});
}
Variant array_keys(const Variant &array, const Variant &filter_value, const Variant &strict) {
    return call(LITERAL_STRING[1900], {array, filter_value, strict});
}
Variant array_key_first(const Variant &array) {
    return call(LITERAL_STRING[1901], {array});
}
Variant array_key_last(const Variant &array) {
    return call(LITERAL_STRING[1902], {array});
}
Variant array_values(const Variant &array) {
    return call(LITERAL_STRING[1903], {array});
}
Variant array_count_values(const Variant &array) {
    return call(LITERAL_STRING[1904], {array});
}
Variant array_column(const Variant &array, const Variant &column_key, const Variant &index_key) {
    return call(LITERAL_STRING[1905], {array, column_key, index_key});
}
Variant array_reverse(const Variant &array, const Variant &preserve_keys) {
    return call(LITERAL_STRING[1906], {array, preserve_keys});
}
Variant array_pad(const Variant &array, const Variant &length, const Variant &value) {
    return call(LITERAL_STRING[1907], {array, length, value});
}
Variant array_flip(const Variant &array) {
    return call(LITERAL_STRING[1908], {array});
}
Variant array_change_key_case(const Variant &array, const Variant &_case) {
    return call(LITERAL_STRING[1909], {array, _case});
}
Variant array_unique(const Variant &array, const Variant &flags) {
    return call(LITERAL_STRING[1910], {array, flags});
}
Variant array_rand(const Variant &array, const Variant &num) {
    return call(LITERAL_STRING[1928], {array, num});
}
Variant array_sum(const Variant &array) {
    return call(LITERAL_STRING[1929], {array});
}
Variant array_product(const Variant &array) {
    return call(LITERAL_STRING[1930], {array});
}
Variant array_reduce(const Variant &array, const Variant &callback, const Variant &initial) {
    return call(LITERAL_STRING[1931], {array, callback, initial});
}
Variant array_filter(const Variant &array, const Variant &callback, const Variant &mode) {
    return call(LITERAL_STRING[1932], {array, callback, mode});
}
Variant array_find(const Variant &array, const Variant &callback) {
    return call(LITERAL_STRING[1933], {array, callback});
}
Variant array_find_key(const Variant &array, const Variant &callback) {
    return call(LITERAL_STRING[1934], {array, callback});
}
Variant array_any(const Variant &array, const Variant &callback) {
    return call(LITERAL_STRING[1935], {array, callback});
}
Variant array_all(const Variant &array, const Variant &callback) {
    return call(LITERAL_STRING[1936], {array, callback});
}
Variant array_key_exists(const Variant &key, const Variant &array) {
    return call(LITERAL_STRING[1938], {key, array});
}
Variant key_exists(const Variant &key, const Variant &array) {
    return call(LITERAL_STRING[1939], {key, array});
}
Variant array_chunk(const Variant &array, const Variant &length, const Variant &preserve_keys) {
    return call(LITERAL_STRING[1940], {array, length, preserve_keys});
}
Variant array_combine(const Variant &keys, const Variant &values) {
    return call(LITERAL_STRING[1941], {keys, values});
}
Variant array_is_list(const Variant &array) {
    return call(LITERAL_STRING[1942], {array});
}
Variant base64_encode(const Variant &string) {
    return call(LITERAL_STRING[1943], {string});
}
Variant base64_decode(const Variant &string, const Variant &strict) {
    return call(LITERAL_STRING[1944], {string, strict});
}
Variant ip2long(const Variant &ip) {
    return call(LITERAL_STRING[1945], {ip});
}
Variant long2ip(const Variant &ip) {
    return call(LITERAL_STRING[1946], {ip});
}
Variant getenv(const Variant &name, const Variant &local_only) {
    return call(LITERAL_STRING[1947], {name, local_only});
}
Variant putenv(const Variant &assignment) {
    return call(LITERAL_STRING[1948], {assignment});
}
Variant getopt(const Variant &short_options, const Variant &long_options, const Reference &rest_index) {
    return call(LITERAL_STRING[1949], {short_options, long_options, &rest_index});
}
Variant flush() {
    return call(LITERAL_STRING[1950], {});
}
Variant sleep(const Variant &seconds) {
    return call(LITERAL_STRING[1951], {seconds});
}
Variant usleep(const Variant &microseconds) {
    return call(LITERAL_STRING[1952], {microseconds});
}
Variant time_nanosleep(const Variant &seconds, const Variant &nanoseconds) {
    return call(LITERAL_STRING[1953], {seconds, nanoseconds});
}
Variant time_sleep_until(const Variant &timestamp) {
    return call(LITERAL_STRING[1954], {timestamp});
}
Variant get_current_user() {
    return call(LITERAL_STRING[1955], {});
}
Variant get_cfg_var(const Variant &option) {
    return call(LITERAL_STRING[1956], {option});
}
Variant error_log(const Variant &message,
                  const Variant &message_type,
                  const Variant &destination,
                  const Variant &additional_headers) {
    return call(LITERAL_STRING[1957], {message, message_type, destination, additional_headers});
}
Variant error_get_last() {
    return call(LITERAL_STRING[1958], {});
}
Variant error_clear_last() {
    return call(LITERAL_STRING[1959], {});
}
Variant call_user_func_array(const Variant &callback, const Variant &args) {
    return call(LITERAL_STRING[1961], {callback, args});
}
Variant forward_static_call_array(const Variant &callback, const Variant &args) {
    return call(LITERAL_STRING[1963], {callback, args});
}
Variant highlight_file(const Variant &filename, const Variant &_return) {
    return call(LITERAL_STRING[1965], {filename, _return});
}
Variant show_source(const Variant &filename, const Variant &_return) {
    return call(LITERAL_STRING[1966], {filename, _return});
}
Variant php_strip_whitespace(const Variant &filename) {
    return call(LITERAL_STRING[1967], {filename});
}
Variant highlight_string(const Variant &string, const Variant &_return) {
    return call(LITERAL_STRING[1968], {string, _return});
}
Variant ini_get(const Variant &option) {
    return call(LITERAL_STRING[1969], {option});
}
Variant ini_get_all(const Variant &extension, const Variant &details) {
    return call(LITERAL_STRING[1970], {extension, details});
}
Variant ini_set(const Variant &option, const Variant &value) {
    return call(LITERAL_STRING[1971], {option, value});
}
Variant ini_alter(const Variant &option, const Variant &value) {
    return call(LITERAL_STRING[1972], {option, value});
}
Variant ini_restore(const Variant &option) {
    return call(LITERAL_STRING[1973], {option});
}
Variant ini_parse_quantity(const Variant &shorthand) {
    return call(LITERAL_STRING[1974], {shorthand});
}
Variant set_include_path(const Variant &include_path) {
    return call(LITERAL_STRING[1975], {include_path});
}
Variant get_include_path() {
    return call(LITERAL_STRING[1976], {});
}
Variant print_r(const Variant &value, const Variant &_return) {
    return call(LITERAL_STRING[1977], {value, _return});
}
Variant connection_aborted() {
    return call(LITERAL_STRING[1978], {});
}
Variant connection_status() {
    return call(LITERAL_STRING[1979], {});
}
Variant ignore_user_abort(const Variant &enable) {
    return call(LITERAL_STRING[1980], {enable});
}
Variant getservbyname(const Variant &service, const Variant &protocol) {
    return call(LITERAL_STRING[1981], {service, protocol});
}
Variant getservbyport(const Variant &port, const Variant &protocol) {
    return call(LITERAL_STRING[1982], {port, protocol});
}
Variant getprotobyname(const Variant &protocol) {
    return call(LITERAL_STRING[1983], {protocol});
}
Variant getprotobynumber(const Variant &protocol) {
    return call(LITERAL_STRING[1984], {protocol});
}
Variant unregister_tick_function(const Variant &callback) {
    return call(LITERAL_STRING[1986], {callback});
}
Variant is_uploaded_file(const Variant &filename) {
    return call(LITERAL_STRING[1987], {filename});
}
Variant move_uploaded_file(const Variant &from, const Variant &to) {
    return call(LITERAL_STRING[1988], {from, to});
}
Variant parse_ini_file(const Variant &filename, const Variant &process_sections, const Variant &scanner_mode) {
    return call(LITERAL_STRING[1989], {filename, process_sections, scanner_mode});
}
Variant parse_ini_string(const Variant &ini_string, const Variant &process_sections, const Variant &scanner_mode) {
    return call(LITERAL_STRING[1990], {ini_string, process_sections, scanner_mode});
}
Variant config_get_hash() {
    return call(LITERAL_STRING[1991], {});
}
Variant sys_getloadavg() {
    return call(LITERAL_STRING[1992], {});
}
Variant get_browser(const Variant &user_agent, const Variant &return_array) {
    return call(LITERAL_STRING[1993], {user_agent, return_array});
}
Variant crc32(const Variant &string) {
    return call(LITERAL_STRING[1994], {string});
}
Variant crypt(const Variant &string, const Variant &salt) {
    return call(LITERAL_STRING[1995], {string, salt});
}
Variant strptime(const Variant &timestamp, const Variant &format) {
    return call(LITERAL_STRING[1996], {timestamp, format});
}
Variant gethostname() {
    return call(LITERAL_STRING[1997], {});
}
Variant gethostbyaddr(const Variant &ip) {
    return call(LITERAL_STRING[1998], {ip});
}
Variant gethostbyname(const Variant &hostname) {
    return call(LITERAL_STRING[1999], {hostname});
}
Variant gethostbynamel(const Variant &hostname) {
    return call(LITERAL_STRING[2000], {hostname});
}
Variant dns_check_record(const Variant &hostname, const Variant &type) {
    return call(LITERAL_STRING[2001], {hostname, type});
}
Variant checkdnsrr(const Variant &hostname, const Variant &type) {
    return call(LITERAL_STRING[2002], {hostname, type});
}
Variant dns_get_record(const Variant &hostname,
                       const Variant &type,
                       const Reference &authoritative_name_servers,
                       const Reference &additional_records,
                       const Variant &raw) {
    return call(LITERAL_STRING[2003], {hostname, type, &authoritative_name_servers, &additional_records, raw});
}
Variant dns_get_mx(const Variant &hostname, const Reference &hosts, const Reference &weights) {
    return call(LITERAL_STRING[2004], {hostname, &hosts, &weights});
}
Variant getmxrr(const Variant &hostname, const Reference &hosts, const Reference &weights) {
    return call(LITERAL_STRING[2005], {hostname, &hosts, &weights});
}
Variant net_get_interfaces() {
    return call(LITERAL_STRING[2006], {});
}
Variant ftok(const Variant &filename, const Variant &project_id) {
    return call(LITERAL_STRING[2007], {filename, project_id});
}
Variant hrtime(const Variant &as_number) {
    return call(LITERAL_STRING[2008], {as_number});
}
Variant md5(const Variant &string, const Variant &binary) {
    return call(LITERAL_STRING[2009], {string, binary});
}
Variant md5_file(const Variant &filename, const Variant &binary) {
    return call(LITERAL_STRING[2010], {filename, binary});
}
Variant getmyuid() {
    return call(LITERAL_STRING[2011], {});
}
Variant getmygid() {
    return call(LITERAL_STRING[2012], {});
}
Variant getmypid() {
    return call(LITERAL_STRING[2013], {});
}
Variant getmyinode() {
    return call(LITERAL_STRING[2014], {});
}
Variant getlastmod() {
    return call(LITERAL_STRING[2015], {});
}
Variant sha1(const Variant &string, const Variant &binary) {
    return call(LITERAL_STRING[2016], {string, binary});
}
Variant sha1_file(const Variant &filename, const Variant &binary) {
    return call(LITERAL_STRING[2017], {filename, binary});
}
Variant openlog(const Variant &prefix, const Variant &flags, const Variant &facility) {
    return call(LITERAL_STRING[2018], {prefix, flags, facility});
}
Variant closelog() {
    return call(LITERAL_STRING[2019], {});
}
Variant syslog(const Variant &priority, const Variant &message) {
    return call(LITERAL_STRING[2020], {priority, message});
}
Variant inet_ntop(const Variant &ip) {
    return call(LITERAL_STRING[2021], {ip});
}
Variant inet_pton(const Variant &ip) {
    return call(LITERAL_STRING[2022], {ip});
}
Variant metaphone(const Variant &string, const Variant &max_phonemes) {
    return call(LITERAL_STRING[2023], {string, max_phonemes});
}
Variant header(const Variant &header, const Variant &replace, const Variant &response_code) {
    return call(LITERAL_STRING[2024], {header, replace, response_code});
}
Variant header_remove(const Variant &name) {
    return call(LITERAL_STRING[2025], {name});
}
Variant setrawcookie(const Variant &name,
                     const Variant &value,
                     const Variant &expires_or_options,
                     const Variant &path,
                     const Variant &domain,
                     const Variant &secure,
                     const Variant &httponly) {
    return call(LITERAL_STRING[2026], {name, value, expires_or_options, path, domain, secure, httponly});
}
Variant setcookie(const Variant &name,
                  const Variant &value,
                  const Variant &expires_or_options,
                  const Variant &path,
                  const Variant &domain,
                  const Variant &secure,
                  const Variant &httponly) {
    return call(LITERAL_STRING[2027], {name, value, expires_or_options, path, domain, secure, httponly});
}
Variant http_response_code(const Variant &response_code) {
    return call(LITERAL_STRING[2028], {response_code});
}
Variant headers_sent(const Reference &filename, const Reference &line) {
    return call(LITERAL_STRING[2029], {&filename, &line});
}
Variant headers_list() {
    return call(LITERAL_STRING[2030], {});
}
Variant htmlspecialchars(const Variant &string,
                         const Variant &flags,
                         const Variant &encoding,
                         const Variant &double_encode) {
    return call(LITERAL_STRING[2031], {string, flags, encoding, double_encode});
}
Variant htmlspecialchars_decode(const Variant &string, const Variant &flags) {
    return call(LITERAL_STRING[2032], {string, flags});
}
Variant html_entity_decode(const Variant &string, const Variant &flags, const Variant &encoding) {
    return call(LITERAL_STRING[2033], {string, flags, encoding});
}
Variant htmlentities(const Variant &string,
                     const Variant &flags,
                     const Variant &encoding,
                     const Variant &double_encode) {
    return call(LITERAL_STRING[2034], {string, flags, encoding, double_encode});
}
Variant get_html_translation_table(const Variant &table, const Variant &flags, const Variant &encoding) {
    return call(LITERAL_STRING[2035], {table, flags, encoding});
}
Variant assert_options(const Variant &option, const Variant &value) {
    return call(LITERAL_STRING[2036], {option, value});
}
Variant bin2hex(const Variant &string) {
    return call(LITERAL_STRING[2037], {string});
}
Variant hex2bin(const Variant &string) {
    return call(LITERAL_STRING[2038], {string});
}
Variant strspn(const Variant &string, const Variant &characters, const Variant &offset, const Variant &length) {
    return call(LITERAL_STRING[2039], {string, characters, offset, length});
}
Variant strcspn(const Variant &string, const Variant &characters, const Variant &offset, const Variant &length) {
    return call(LITERAL_STRING[2040], {string, characters, offset, length});
}
Variant nl_langinfo(const Variant &item) {
    return call(LITERAL_STRING[2041], {item});
}
Variant strcoll(const Variant &string1, const Variant &string2) {
    return call(LITERAL_STRING[2042], {string1, string2});
}
Variant trim(const Variant &string, const Variant &characters) {
    return call(LITERAL_STRING[2043], {string, characters});
}
Variant rtrim(const Variant &string, const Variant &characters) {
    return call(LITERAL_STRING[2044], {string, characters});
}
Variant chop(const Variant &string, const Variant &characters) {
    return call(LITERAL_STRING[2045], {string, characters});
}
Variant ltrim(const Variant &string, const Variant &characters) {
    return call(LITERAL_STRING[1165], {string, characters});
}
Variant wordwrap(const Variant &string, const Variant &width, const Variant &_break, const Variant &cut_long_words) {
    return call(LITERAL_STRING[2046], {string, width, _break, cut_long_words});
}
Variant explode(const Variant &separator, const Variant &string, const Variant &limit) {
    return call(LITERAL_STRING[2047], {separator, string, limit});
}
Variant implode(const Variant &separator, const Variant &array) {
    return call(LITERAL_STRING[2048], {separator, array});
}
Variant join(const Variant &separator, const Variant &array) {
    return call(LITERAL_STRING[2049], {separator, array});
}
Variant strtok(const Variant &string, const Variant &token) {
    return call(LITERAL_STRING[2050], {string, token});
}
Variant strtoupper(const Variant &string) {
    return call(LITERAL_STRING[2051], {string});
}
Variant strtolower(const Variant &string) {
    return call(LITERAL_STRING[2052], {string});
}
Variant str_increment(const Variant &string) {
    return call(LITERAL_STRING[2053], {string});
}
Variant str_decrement(const Variant &string) {
    return call(LITERAL_STRING[2054], {string});
}
Variant basename(const Variant &path, const Variant &suffix) {
    return call(LITERAL_STRING[2055], {path, suffix});
}
Variant dirname(const Variant &path, const Variant &levels) {
    return call(LITERAL_STRING[2056], {path, levels});
}
Variant pathinfo(const Variant &path, const Variant &flags) {
    return call(LITERAL_STRING[2057], {path, flags});
}
Variant stristr(const Variant &haystack, const Variant &needle, const Variant &before_needle) {
    return call(LITERAL_STRING[2058], {haystack, needle, before_needle});
}
Variant strstr(const Variant &haystack, const Variant &needle, const Variant &before_needle) {
    return call(LITERAL_STRING[2059], {haystack, needle, before_needle});
}
Variant strchr(const Variant &haystack, const Variant &needle, const Variant &before_needle) {
    return call(LITERAL_STRING[2060], {haystack, needle, before_needle});
}
Variant strpos(const Variant &haystack, const Variant &needle, const Variant &offset) {
    return call(LITERAL_STRING[2061], {haystack, needle, offset});
}
Variant stripos(const Variant &haystack, const Variant &needle, const Variant &offset) {
    return call(LITERAL_STRING[2062], {haystack, needle, offset});
}
Variant strrpos(const Variant &haystack, const Variant &needle, const Variant &offset) {
    return call(LITERAL_STRING[2063], {haystack, needle, offset});
}
Variant strripos(const Variant &haystack, const Variant &needle, const Variant &offset) {
    return call(LITERAL_STRING[2064], {haystack, needle, offset});
}
Variant strrchr(const Variant &haystack, const Variant &needle, const Variant &before_needle) {
    return call(LITERAL_STRING[2065], {haystack, needle, before_needle});
}
Variant str_contains(const Variant &haystack, const Variant &needle) {
    return call(LITERAL_STRING[2066], {haystack, needle});
}
Variant str_starts_with(const Variant &haystack, const Variant &needle) {
    return call(LITERAL_STRING[2067], {haystack, needle});
}
Variant str_ends_with(const Variant &haystack, const Variant &needle) {
    return call(LITERAL_STRING[2068], {haystack, needle});
}
Variant chunk_split(const Variant &string, const Variant &length, const Variant &separator) {
    return call(LITERAL_STRING[2069], {string, length, separator});
}
Variant substr(const Variant &string, const Variant &offset, const Variant &length) {
    return call(LITERAL_STRING[2070], {string, offset, length});
}
Variant substr_replace(const Variant &string, const Variant &replace, const Variant &offset, const Variant &length) {
    return call(LITERAL_STRING[2071], {string, replace, offset, length});
}
Variant quotemeta(const Variant &string) {
    return call(LITERAL_STRING[2072], {string});
}
Variant ord(const Variant &character) {
    return call(LITERAL_STRING[2073], {character});
}
Variant chr(const Variant &codepoint) {
    return call(LITERAL_STRING[2074], {codepoint});
}
Variant ucfirst(const Variant &string) {
    return call(LITERAL_STRING[2075], {string});
}
Variant lcfirst(const Variant &string) {
    return call(LITERAL_STRING[2076], {string});
}
Variant ucwords(const Variant &string, const Variant &separators) {
    return call(LITERAL_STRING[2077], {string, separators});
}
Variant strtr(const Variant &string, const Variant &from, const Variant &to) {
    return call(LITERAL_STRING[2078], {string, from, to});
}
Variant strrev(const Variant &string) {
    return call(LITERAL_STRING[2079], {string});
}
Variant similar_text(const Variant &string1, const Variant &string2, const Reference &percent) {
    return call(LITERAL_STRING[2080], {string1, string2, &percent});
}
Variant addcslashes(const Variant &string, const Variant &characters) {
    return call(LITERAL_STRING[2081], {string, characters});
}
Variant addslashes(const Variant &string) {
    return call(LITERAL_STRING[2082], {string});
}
Variant stripcslashes(const Variant &string) {
    return call(LITERAL_STRING[2083], {string});
}
Variant stripslashes(const Variant &string) {
    return call(LITERAL_STRING[2084], {string});
}
Variant str_replace(const Variant &search, const Variant &replace, const Variant &subject, const Reference &count) {
    return call(LITERAL_STRING[2085], {search, replace, subject, &count});
}
Variant str_ireplace(const Variant &search, const Variant &replace, const Variant &subject, const Reference &count) {
    return call(LITERAL_STRING[2086], {search, replace, subject, &count});
}
Variant hebrev(const Variant &string, const Variant &max_chars_per_line) {
    return call(LITERAL_STRING[2087], {string, max_chars_per_line});
}
Variant nl2br(const Variant &string, const Variant &use_xhtml) {
    return call(LITERAL_STRING[2088], {string, use_xhtml});
}
Variant strip_tags(const Variant &string, const Variant &allowed_tags) {
    return call(LITERAL_STRING[2089], {string, allowed_tags});
}
Variant parse_str(const Variant &string, const Reference &result) {
    return call(LITERAL_STRING[2091], {string, &result});
}
Variant str_getcsv(const Variant &string, const Variant &separator, const Variant &enclosure, const Variant &escape) {
    return call(LITERAL_STRING[2092], {string, separator, enclosure, escape});
}
Variant str_repeat(const Variant &string, const Variant &times) {
    return call(LITERAL_STRING[2093], {string, times});
}
Variant count_chars(const Variant &string, const Variant &mode) {
    return call(LITERAL_STRING[2094], {string, mode});
}
Variant localeconv() {
    return call(LITERAL_STRING[2095], {});
}
Variant substr_count(const Variant &haystack, const Variant &needle, const Variant &offset, const Variant &length) {
    return call(LITERAL_STRING[2096], {haystack, needle, offset, length});
}
Variant str_pad(const Variant &string, const Variant &length, const Variant &pad_string, const Variant &pad_type) {
    return call(LITERAL_STRING[2097], {string, length, pad_string, pad_type});
}
Variant str_rot13(const Variant &string) {
    return call(LITERAL_STRING[2099], {string});
}
Variant str_shuffle(const Variant &string) {
    return call(LITERAL_STRING[2100], {string});
}
Variant str_word_count(const Variant &string, const Variant &format, const Variant &characters) {
    return call(LITERAL_STRING[2101], {string, format, characters});
}
Variant str_split(const Variant &string, const Variant &length) {
    return call(LITERAL_STRING[2102], {string, length});
}
Variant strpbrk(const Variant &string, const Variant &characters) {
    return call(LITERAL_STRING[2103], {string, characters});
}
Variant substr_compare(const Variant &haystack,
                       const Variant &needle,
                       const Variant &offset,
                       const Variant &length,
                       const Variant &case_insensitive) {
    return call(LITERAL_STRING[2104], {haystack, needle, offset, length, case_insensitive});
}
Variant utf8_encode(const Variant &string) {
    return call(LITERAL_STRING[2105], {string});
}
Variant utf8_decode(const Variant &string) {
    return call(LITERAL_STRING[2106], {string});
}
Variant opendir(const Variant &directory, const Variant &context) {
    return call(LITERAL_STRING[2107], {directory, context});
}
Variant dir(const Variant &directory, const Variant &context) {
    return call(LITERAL_STRING[2108], {directory, context});
}
Variant closedir(const Variant &dir_handle) {
    return call(LITERAL_STRING[2109], {dir_handle});
}
Variant chdir(const Variant &directory) {
    return call(LITERAL_STRING[2110], {directory});
}
Variant getcwd() {
    return call(LITERAL_STRING[2111], {});
}
Variant rewinddir(const Variant &dir_handle) {
    return call(LITERAL_STRING[2112], {dir_handle});
}
Variant readdir(const Variant &dir_handle) {
    return call(LITERAL_STRING[2113], {dir_handle});
}
Variant scandir(const Variant &directory, const Variant &sorting_order, const Variant &context) {
    return call(LITERAL_STRING[2114], {directory, sorting_order, context});
}
Variant glob(const Variant &pattern, const Variant &flags) {
    return call(LITERAL_STRING[2115], {pattern, flags});
}
Variant exec(const Variant &command, const Reference &output, const Reference &result_code) {
    return call(LITERAL_STRING[827], {command, &output, &result_code});
}
Variant system(const Variant &command, const Reference &result_code) {
    return call(LITERAL_STRING[2116], {command, &result_code});
}
Variant passthru(const Variant &command, const Reference &result_code) {
    return call(LITERAL_STRING[2117], {command, &result_code});
}
Variant escapeshellcmd(const Variant &command) {
    return call(LITERAL_STRING[2118], {command});
}
Variant escapeshellarg(const Variant &arg) {
    return call(LITERAL_STRING[2119], {arg});
}
Variant shell_exec(const Variant &command) {
    return call(LITERAL_STRING[2120], {command});
}
Variant proc_nice(const Variant &priority) {
    return call(LITERAL_STRING[2121], {priority});
}
Variant flock(const Variant &stream, const Variant &operation, const Reference &would_block) {
    return call(LITERAL_STRING[1769], {stream, operation, &would_block});
}
Variant get_meta_tags(const Variant &filename, const Variant &use_include_path) {
    return call(LITERAL_STRING[2122], {filename, use_include_path});
}
Variant pclose(const Variant &handle) {
    return call(LITERAL_STRING[2123], {handle});
}
Variant popen(const Variant &command, const Variant &mode) {
    return call(LITERAL_STRING[1183], {command, mode});
}
Variant readfile(const Variant &filename, const Variant &use_include_path, const Variant &context) {
    return call(LITERAL_STRING[2124], {filename, use_include_path, context});
}
Variant rewind(const Variant &stream) {
    return call(LITERAL_STRING[94], {stream});
}
Variant rmdir(const Variant &directory, const Variant &context) {
    return call(LITERAL_STRING[2125], {directory, context});
}
Variant umask(const Variant &mask) {
    return call(LITERAL_STRING[2126], {mask});
}
Variant fclose(const Variant &stream) {
    return call(LITERAL_STRING[2127], {stream});
}
Variant feof(const Variant &stream) {
    return call(LITERAL_STRING[2128], {stream});
}
Variant fgetc(const Variant &stream) {
    return call(LITERAL_STRING[1773], {stream});
}
Variant fgets(const Variant &stream, const Variant &length) {
    return call(LITERAL_STRING[1763], {stream, length});
}
Variant fread(const Variant &stream, const Variant &length) {
    return call(LITERAL_STRING[1764], {stream, length});
}
Variant fopen(const Variant &filename, const Variant &mode, const Variant &use_include_path, const Variant &context) {
    return call(LITERAL_STRING[2129], {filename, mode, use_include_path, context});
}
Variant fpassthru(const Variant &stream) {
    return call(LITERAL_STRING[1774], {stream});
}
Variant ftruncate(const Variant &stream, const Variant &size) {
    return call(LITERAL_STRING[1778], {stream, size});
}
Variant fstat(const Variant &stream) {
    return call(LITERAL_STRING[1777], {stream});
}
Variant fseek(const Variant &stream, const Variant &offset, const Variant &whence) {
    return call(LITERAL_STRING[1772], {stream, offset, whence});
}
Variant ftell(const Variant &stream) {
    return call(LITERAL_STRING[1771], {stream});
}
Variant fflush(const Variant &stream) {
    return call(LITERAL_STRING[1770], {stream});
}
Variant fsync(const Variant &stream) {
    return call(LITERAL_STRING[2130], {stream});
}
Variant fdatasync(const Variant &stream) {
    return call(LITERAL_STRING[2131], {stream});
}
Variant fwrite(const Variant &stream, const Variant &data, const Variant &length) {
    return call(LITERAL_STRING[1776], {stream, data, length});
}
Variant fputs(const Variant &stream, const Variant &data, const Variant &length) {
    return call(LITERAL_STRING[2132], {stream, data, length});
}
Variant mkdir(const Variant &directory, const Variant &permissions, const Variant &recursive, const Variant &context) {
    return call(LITERAL_STRING[2133], {directory, permissions, recursive, context});
}
Variant rename(const Variant &from, const Variant &to, const Variant &context) {
    return call(LITERAL_STRING[427], {from, to, context});
}
Variant copy(const Variant &from, const Variant &to, const Variant &context) {
    return call(LITERAL_STRING[875], {from, to, context});
}
Variant tempnam(const Variant &directory, const Variant &prefix) {
    return call(LITERAL_STRING[2134], {directory, prefix});
}
Variant tmpfile() {
    return call(LITERAL_STRING[2135], {});
}
Variant file(const Variant &filename, const Variant &flags, const Variant &context) {
    return call(LITERAL_STRING[499], {filename, flags, context});
}
Variant file_get_contents(const Variant &filename,
                          const Variant &use_include_path,
                          const Variant &context,
                          const Variant &offset,
                          const Variant &length) {
    return call(LITERAL_STRING[2136], {filename, use_include_path, context, offset, length});
}
Variant unlink(const Variant &filename, const Variant &context) {
    return call(LITERAL_STRING[1242], {filename, context});
}
Variant file_put_contents(const Variant &filename, const Variant &data, const Variant &flags, const Variant &context) {
    return call(LITERAL_STRING[2137], {filename, data, flags, context});
}
Variant fputcsv(const Variant &stream,
                const Variant &fields,
                const Variant &separator,
                const Variant &enclosure,
                const Variant &escape,
                const Variant &eol) {
    return call(LITERAL_STRING[1766], {stream, fields, separator, enclosure, escape, eol});
}
Variant fgetcsv(const Variant &stream,
                const Variant &length,
                const Variant &separator,
                const Variant &enclosure,
                const Variant &escape) {
    return call(LITERAL_STRING[1765], {stream, length, separator, enclosure, escape});
}
Variant realpath(const Variant &path) {
    return call(LITERAL_STRING[2138], {path});
}
Variant fnmatch(const Variant &pattern, const Variant &filename, const Variant &flags) {
    return call(LITERAL_STRING[2139], {pattern, filename, flags});
}
Variant sys_get_temp_dir() {
    return call(LITERAL_STRING[2140], {});
}
Variant fileatime(const Variant &filename) {
    return call(LITERAL_STRING[2141], {filename});
}
Variant filectime(const Variant &filename) {
    return call(LITERAL_STRING[2142], {filename});
}
Variant filegroup(const Variant &filename) {
    return call(LITERAL_STRING[2143], {filename});
}
Variant fileinode(const Variant &filename) {
    return call(LITERAL_STRING[2144], {filename});
}
Variant filemtime(const Variant &filename) {
    return call(LITERAL_STRING[2145], {filename});
}
Variant fileowner(const Variant &filename) {
    return call(LITERAL_STRING[2146], {filename});
}
Variant fileperms(const Variant &filename) {
    return call(LITERAL_STRING[2147], {filename});
}
Variant filesize(const Variant &filename) {
    return call(LITERAL_STRING[2148], {filename});
}
Variant filetype(const Variant &filename) {
    return call(LITERAL_STRING[2149], {filename});
}
Variant file_exists(const Variant &filename) {
    return call(LITERAL_STRING[2150], {filename});
}
Variant is_writable(const Variant &filename) {
    return call(LITERAL_STRING[2151], {filename});
}
Variant is_writeable(const Variant &filename) {
    return call(LITERAL_STRING[2152], {filename});
}
Variant is_readable(const Variant &filename) {
    return call(LITERAL_STRING[2153], {filename});
}
Variant is_executable(const Variant &filename) {
    return call(LITERAL_STRING[2154], {filename});
}
Variant is_file(const Variant &filename) {
    return call(LITERAL_STRING[2155], {filename});
}
Variant is_dir(const Variant &filename) {
    return call(LITERAL_STRING[2156], {filename});
}
Variant is_link(const Variant &filename) {
    return call(LITERAL_STRING[2157], {filename});
}
Variant stat(const Variant &filename) {
    return call(LITERAL_STRING[2158], {filename});
}
Variant lstat(const Variant &filename) {
    return call(LITERAL_STRING[2159], {filename});
}
Variant chown(const Variant &filename, const Variant &user) {
    return call(LITERAL_STRING[2160], {filename, user});
}
Variant chgrp(const Variant &filename, const Variant &group) {
    return call(LITERAL_STRING[2161], {filename, group});
}
Variant lchown(const Variant &filename, const Variant &user) {
    return call(LITERAL_STRING[2162], {filename, user});
}
Variant lchgrp(const Variant &filename, const Variant &group) {
    return call(LITERAL_STRING[2163], {filename, group});
}
Variant chmod(const Variant &filename, const Variant &permissions) {
    return call(LITERAL_STRING[963], {filename, permissions});
}
Variant touch(const Variant &filename, const Variant &mtime, const Variant &atime) {
    return call(LITERAL_STRING[1225], {filename, mtime, atime});
}
Variant clearstatcache(const Variant &clear_realpath_cache, const Variant &filename) {
    return call(LITERAL_STRING[2164], {clear_realpath_cache, filename});
}
Variant disk_total_space(const Variant &directory) {
    return call(LITERAL_STRING[2165], {directory});
}
Variant disk_free_space(const Variant &directory) {
    return call(LITERAL_STRING[2166], {directory});
}
Variant diskfreespace(const Variant &directory) {
    return call(LITERAL_STRING[2167], {directory});
}
Variant realpath_cache_get() {
    return call(LITERAL_STRING[2168], {});
}
Variant realpath_cache_size() {
    return call(LITERAL_STRING[2169], {});
}
Variant vprintf(const Variant &format, const Variant &values) {
    return call(LITERAL_STRING[2172], {format, values});
}
Variant vsprintf(const Variant &format, const Variant &values) {
    return call(LITERAL_STRING[2173], {format, values});
}
Variant vfprintf(const Variant &stream, const Variant &format, const Variant &values) {
    return call(LITERAL_STRING[2175], {stream, format, values});
}
Variant fsockopen(const Variant &hostname,
                  const Variant &port,
                  const Reference &error_code,
                  const Reference &error_message,
                  const Variant &timeout) {
    return call(LITERAL_STRING[2176], {hostname, port, &error_code, &error_message, timeout});
}
Variant pfsockopen(const Variant &hostname,
                   const Variant &port,
                   const Reference &error_code,
                   const Reference &error_message,
                   const Variant &timeout) {
    return call(LITERAL_STRING[2177], {hostname, port, &error_code, &error_message, timeout});
}
Variant http_build_query(const Variant &data,
                         const Variant &numeric_prefix,
                         const Variant &arg_separator,
                         const Variant &encoding_type) {
    return call(LITERAL_STRING[2178], {data, numeric_prefix, arg_separator, encoding_type});
}
Variant http_get_last_response_headers() {
    return call(LITERAL_STRING[2179], {});
}
Variant http_clear_last_response_headers() {
    return call(LITERAL_STRING[2180], {});
}
Variant request_parse_body(const Variant &options) {
    return call(LITERAL_STRING[2181], {options});
}
Variant image_type_to_mime_type(const Variant &image_type) {
    return call(LITERAL_STRING[2182], {image_type});
}
Variant image_type_to_extension(const Variant &image_type, const Variant &include_dot) {
    return call(LITERAL_STRING[2183], {image_type, include_dot});
}
Variant getimagesize(const Variant &filename, const Reference &image_info) {
    return call(LITERAL_STRING[2184], {filename, &image_info});
}
Variant getimagesizefromstring(const Variant &string, const Reference &image_info) {
    return call(LITERAL_STRING[2185], {string, &image_info});
}
Variant phpinfo(const Variant &flags) {
    return call(LITERAL_STRING[2186], {flags});
}
Variant phpversion(const Variant &extension) {
    return call(LITERAL_STRING[2187], {extension});
}
Variant phpcredits(const Variant &flags) {
    return call(LITERAL_STRING[2188], {flags});
}
Variant php_sapi_name() {
    return call(LITERAL_STRING[2189], {});
}
Variant php_uname(const Variant &mode) {
    return call(LITERAL_STRING[2190], {mode});
}
Variant php_ini_scanned_files() {
    return call(LITERAL_STRING[2191], {});
}
Variant php_ini_loaded_file() {
    return call(LITERAL_STRING[2192], {});
}
Variant iptcembed(const Variant &iptc_data, const Variant &filename, const Variant &spool) {
    return call(LITERAL_STRING[2193], {iptc_data, filename, spool});
}
Variant iptcparse(const Variant &iptc_block) {
    return call(LITERAL_STRING[2194], {iptc_block});
}
Variant levenshtein(const Variant &string1,
                    const Variant &string2,
                    const Variant &insertion_cost,
                    const Variant &replacement_cost,
                    const Variant &deletion_cost) {
    return call(LITERAL_STRING[2195], {string1, string2, insertion_cost, replacement_cost, deletion_cost});
}
Variant readlink(const Variant &path) {
    return call(LITERAL_STRING[2196], {path});
}
Variant linkinfo(const Variant &path) {
    return call(LITERAL_STRING[2197], {path});
}
Variant symlink(const Variant &target, const Variant &link) {
    return call(LITERAL_STRING[2198], {target, link});
}
Variant link(const Variant &target, const Variant &link) {
    return call(LITERAL_STRING[2199], {target, link});
}
Variant mail(const Variant &to,
             const Variant &subject,
             const Variant &message,
             const Variant &additional_headers,
             const Variant &additional_params) {
    return call(LITERAL_STRING[2200], {to, subject, message, additional_headers, additional_params});
}
Variant abs(const Variant &num) {
    return call(LITERAL_STRING[2201], {num});
}
Variant ceil(const Variant &num) {
    return call(LITERAL_STRING[26], {num});
}
Variant floor(const Variant &num) {
    return call(LITERAL_STRING[25], {num});
}
Variant round(const Variant &num, const Variant &precision, const Variant &mode) {
    return call(LITERAL_STRING[27], {num, precision, mode});
}
Variant sin(const Variant &num) {
    return call(LITERAL_STRING[2202], {num});
}
Variant cos(const Variant &num) {
    return call(LITERAL_STRING[2203], {num});
}
Variant tan(const Variant &num) {
    return call(LITERAL_STRING[2204], {num});
}
Variant asin(const Variant &num) {
    return call(LITERAL_STRING[2205], {num});
}
Variant acos(const Variant &num) {
    return call(LITERAL_STRING[2206], {num});
}
Variant atan(const Variant &num) {
    return call(LITERAL_STRING[2207], {num});
}
Variant atanh(const Variant &num) {
    return call(LITERAL_STRING[2208], {num});
}
Variant atan2(const Variant &y, const Variant &x) {
    return call(LITERAL_STRING[2209], {y, x});
}
Variant sinh(const Variant &num) {
    return call(LITERAL_STRING[2210], {num});
}
Variant cosh(const Variant &num) {
    return call(LITERAL_STRING[2211], {num});
}
Variant tanh(const Variant &num) {
    return call(LITERAL_STRING[2212], {num});
}
Variant asinh(const Variant &num) {
    return call(LITERAL_STRING[2213], {num});
}
Variant acosh(const Variant &num) {
    return call(LITERAL_STRING[2214], {num});
}
Variant expm1(const Variant &num) {
    return call(LITERAL_STRING[2215], {num});
}
Variant log1p(const Variant &num) {
    return call(LITERAL_STRING[2216], {num});
}
Variant pi() {
    return call(LITERAL_STRING[2217], {});
}
Variant is_finite(const Variant &num) {
    return call(LITERAL_STRING[2218], {num});
}
Variant is_nan(const Variant &num) {
    return call(LITERAL_STRING[2219], {num});
}
Variant intdiv(const Variant &num1, const Variant &num2) {
    return call(LITERAL_STRING[2220], {num1, num2});
}
Variant is_infinite(const Variant &num) {
    return call(LITERAL_STRING[2221], {num});
}
Variant pow(const Variant &num, const Variant &exponent) {
    return call(LITERAL_STRING[23], {num, exponent});
}
Variant exp(const Variant &num) {
    return call(LITERAL_STRING[2222], {num});
}
Variant log(const Variant &num, const Variant &base) {
    return call(LITERAL_STRING[2223], {num, base});
}
Variant log10(const Variant &num) {
    return call(LITERAL_STRING[2224], {num});
}
Variant sqrt(const Variant &num) {
    return call(LITERAL_STRING[24], {num});
}
Variant hypot(const Variant &x, const Variant &y) {
    return call(LITERAL_STRING[2225], {x, y});
}
Variant deg2rad(const Variant &num) {
    return call(LITERAL_STRING[2226], {num});
}
Variant rad2deg(const Variant &num) {
    return call(LITERAL_STRING[2227], {num});
}
Variant bindec(const Variant &binary_string) {
    return call(LITERAL_STRING[2228], {binary_string});
}
Variant hexdec(const Variant &hex_string) {
    return call(LITERAL_STRING[2229], {hex_string});
}
Variant octdec(const Variant &octal_string) {
    return call(LITERAL_STRING[2230], {octal_string});
}
Variant decbin(const Variant &num) {
    return call(LITERAL_STRING[2231], {num});
}
Variant decoct(const Variant &num) {
    return call(LITERAL_STRING[2232], {num});
}
Variant dechex(const Variant &num) {
    return call(LITERAL_STRING[2233], {num});
}
Variant base_convert(const Variant &num, const Variant &from_base, const Variant &to_base) {
    return call(LITERAL_STRING[2234], {num, from_base, to_base});
}
Variant number_format(const Variant &num,
                      const Variant &decimals,
                      const Variant &decimal_separator,
                      const Variant &thousands_separator) {
    return call(LITERAL_STRING[2235], {num, decimals, decimal_separator, thousands_separator});
}
Variant fmod(const Variant &num1, const Variant &num2) {
    return call(LITERAL_STRING[2236], {num1, num2});
}
Variant fdiv(const Variant &num1, const Variant &num2) {
    return call(LITERAL_STRING[2237], {num1, num2});
}
Variant fpow(const Variant &num, const Variant &exponent) {
    return call(LITERAL_STRING[2238], {num, exponent});
}
Variant microtime(const Variant &as_float) {
    return call(LITERAL_STRING[2239], {as_float});
}
Variant gettimeofday(const Variant &as_float) {
    return call(LITERAL_STRING[2240], {as_float});
}
Variant getrusage(const Variant &mode) {
    return call(LITERAL_STRING[2241], {mode});
}
Variant unpack(const Variant &format, const Variant &string, const Variant &offset) {
    return call(LITERAL_STRING[2243], {format, string, offset});
}
Variant password_get_info(const Variant &hash) {
    return call(LITERAL_STRING[2244], {hash});
}
Variant password_hash(const Variant &password, const Variant &algo, const Variant &options) {
    return call(LITERAL_STRING[2245], {password, algo, options});
}
Variant password_needs_rehash(const Variant &hash, const Variant &algo, const Variant &options) {
    return call(LITERAL_STRING[2246], {hash, algo, options});
}
Variant password_verify(const Variant &password, const Variant &hash) {
    return call(LITERAL_STRING[2247], {password, hash});
}
Variant password_algos() {
    return call(LITERAL_STRING[2248], {});
}
Variant proc_open(const Variant &command,
                  const Variant &descriptor_spec,
                  const Reference &pipes,
                  const Variant &cwd,
                  const Variant &env_vars,
                  const Variant &options) {
    return call(LITERAL_STRING[2249], {command, descriptor_spec, &pipes, cwd, env_vars, options});
}
Variant proc_close(const Variant &process) {
    return call(LITERAL_STRING[2250], {process});
}
Variant proc_terminate(const Variant &process, const Variant &signal) {
    return call(LITERAL_STRING[2251], {process, signal});
}
Variant proc_get_status(const Variant &process) {
    return call(LITERAL_STRING[2252], {process});
}
Variant quoted_printable_decode(const Variant &string) {
    return call(LITERAL_STRING[2253], {string});
}
Variant quoted_printable_encode(const Variant &string) {
    return call(LITERAL_STRING[2254], {string});
}
Variant soundex(const Variant &string) {
    return call(LITERAL_STRING[2255], {string});
}
Variant stream_select(const Reference &read,
                      const Reference &write,
                      const Reference &except,
                      const Variant &seconds,
                      const Variant &microseconds) {
    return call(LITERAL_STRING[2256], {&read, &write, &except, seconds, microseconds});
}
Variant stream_context_create(const Variant &options, const Variant &params) {
    return call(LITERAL_STRING[2257], {options, params});
}
Variant stream_context_set_params(const Variant &context, const Variant &params) {
    return call(LITERAL_STRING[2258], {context, params});
}
Variant stream_context_get_params(const Variant &context) {
    return call(LITERAL_STRING[2259], {context});
}
Variant stream_context_set_option(const Variant &context,
                                  const Variant &wrapper_or_options,
                                  const Variant &option_name,
                                  const Variant &value) {
    return call(LITERAL_STRING[2260], {context, wrapper_or_options, option_name, value});
}
Variant stream_context_set_options(const Variant &context, const Variant &options) {
    return call(LITERAL_STRING[2261], {context, options});
}
Variant stream_context_get_options(const Variant &stream_or_context) {
    return call(LITERAL_STRING[2262], {stream_or_context});
}
Variant stream_context_get_default(const Variant &options) {
    return call(LITERAL_STRING[2263], {options});
}
Variant stream_context_set_default(const Variant &options) {
    return call(LITERAL_STRING[2264], {options});
}
Variant stream_filter_prepend(const Variant &stream,
                              const Variant &filter_name,
                              const Variant &mode,
                              const Variant &params) {
    return call(LITERAL_STRING[2265], {stream, filter_name, mode, params});
}
Variant stream_filter_append(const Variant &stream,
                             const Variant &filter_name,
                             const Variant &mode,
                             const Variant &params) {
    return call(LITERAL_STRING[2266], {stream, filter_name, mode, params});
}
Variant stream_filter_remove(const Variant &stream_filter) {
    return call(LITERAL_STRING[2267], {stream_filter});
}
Variant stream_socket_client(const Variant &address,
                             const Reference &error_code,
                             const Reference &error_message,
                             const Variant &timeout,
                             const Variant &flags,
                             const Variant &context) {
    return call(LITERAL_STRING[2268], {address, &error_code, &error_message, timeout, flags, context});
}
Variant stream_socket_server(const Variant &address,
                             const Reference &error_code,
                             const Reference &error_message,
                             const Variant &flags,
                             const Variant &context) {
    return call(LITERAL_STRING[2269], {address, &error_code, &error_message, flags, context});
}
Variant stream_socket_accept(const Variant &socket, const Variant &timeout, const Reference &peer_name) {
    return call(LITERAL_STRING[2270], {socket, timeout, &peer_name});
}
Variant stream_socket_get_name(const Variant &socket, const Variant &remote) {
    return call(LITERAL_STRING[2271], {socket, remote});
}
Variant stream_socket_recvfrom(const Variant &socket,
                               const Variant &length,
                               const Variant &flags,
                               const Reference &address) {
    return call(LITERAL_STRING[2272], {socket, length, flags, &address});
}
Variant stream_socket_sendto(const Variant &socket, const Variant &data, const Variant &flags, const Variant &address) {
    return call(LITERAL_STRING[2273], {socket, data, flags, address});
}
Variant stream_socket_enable_crypto(const Variant &stream,
                                    const Variant &enable,
                                    const Variant &crypto_method,
                                    const Variant &session_stream) {
    return call(LITERAL_STRING[2274], {stream, enable, crypto_method, session_stream});
}
Variant stream_socket_shutdown(const Variant &stream, const Variant &mode) {
    return call(LITERAL_STRING[2275], {stream, mode});
}
Variant stream_socket_pair(const Variant &domain, const Variant &type, const Variant &protocol) {
    return call(LITERAL_STRING[2276], {domain, type, protocol});
}
Variant stream_copy_to_stream(const Variant &from, const Variant &to, const Variant &length, const Variant &offset) {
    return call(LITERAL_STRING[2277], {from, to, length, offset});
}
Variant stream_get_contents(const Variant &stream, const Variant &length, const Variant &offset) {
    return call(LITERAL_STRING[2278], {stream, length, offset});
}
Variant stream_supports_lock(const Variant &stream) {
    return call(LITERAL_STRING[2279], {stream});
}
Variant stream_set_write_buffer(const Variant &stream, const Variant &size) {
    return call(LITERAL_STRING[2280], {stream, size});
}
Variant set_file_buffer(const Variant &stream, const Variant &size) {
    return call(LITERAL_STRING[2281], {stream, size});
}
Variant stream_set_read_buffer(const Variant &stream, const Variant &size) {
    return call(LITERAL_STRING[2282], {stream, size});
}
Variant stream_set_blocking(const Variant &stream, const Variant &enable) {
    return call(LITERAL_STRING[2283], {stream, enable});
}
Variant socket_set_blocking(const Variant &stream, const Variant &enable) {
    return call(LITERAL_STRING[2284], {stream, enable});
}
Variant stream_get_meta_data(const Variant &stream) {
    return call(LITERAL_STRING[2285], {stream});
}
Variant socket_get_status(const Variant &stream) {
    return call(LITERAL_STRING[2286], {stream});
}
Variant stream_get_line(const Variant &stream, const Variant &length, const Variant &ending) {
    return call(LITERAL_STRING[2287], {stream, length, ending});
}
Variant stream_resolve_include_path(const Variant &filename) {
    return call(LITERAL_STRING[2288], {filename});
}
Variant stream_get_wrappers() {
    return call(LITERAL_STRING[2289], {});
}
Variant stream_get_transports() {
    return call(LITERAL_STRING[2290], {});
}
Variant stream_is_local(const Variant &stream) {
    return call(LITERAL_STRING[2291], {stream});
}
Variant stream_isatty(const Variant &stream) {
    return call(LITERAL_STRING[2292], {stream});
}
Variant stream_set_chunk_size(const Variant &stream, const Variant &size) {
    return call(LITERAL_STRING[2293], {stream, size});
}
Variant stream_set_timeout(const Variant &stream, const Variant &seconds, const Variant &microseconds) {
    return call(LITERAL_STRING[2294], {stream, seconds, microseconds});
}
Variant socket_set_timeout(const Variant &stream, const Variant &seconds, const Variant &microseconds) {
    return call(LITERAL_STRING[2295], {stream, seconds, microseconds});
}
Variant gettype(const Variant &value) {
    return call(LITERAL_STRING[2296], {value});
}
Variant get_debug_type(const Variant &value) {
    return call(LITERAL_STRING[2297], {value});
}
Variant settype(const Reference &var, const Variant &type) {
    return call(LITERAL_STRING[2298], {&var, type});
}
Variant intval(const Variant &value, const Variant &base) {
    return call(LITERAL_STRING[2299], {value, base});
}
Variant floatval(const Variant &value) {
    return call(LITERAL_STRING[2300], {value});
}
Variant doubleval(const Variant &value) {
    return call(LITERAL_STRING[2301], {value});
}
Variant boolval(const Variant &value) {
    return call(LITERAL_STRING[2302], {value});
}
Variant strval(const Variant &value) {
    return call(LITERAL_STRING[2303], {value});
}
Variant is_null(const Variant &value) {
    return call(LITERAL_STRING[2304], {value});
}
Variant is_resource(const Variant &value) {
    return call(LITERAL_STRING[2305], {value});
}
Variant is_bool(const Variant &value) {
    return call(LITERAL_STRING[2306], {value});
}
Variant is_int(const Variant &value) {
    return call(LITERAL_STRING[2307], {value});
}
Variant is_integer(const Variant &value) {
    return call(LITERAL_STRING[2308], {value});
}
Variant is_long(const Variant &value) {
    return call(LITERAL_STRING[2309], {value});
}
Variant is_float(const Variant &value) {
    return call(LITERAL_STRING[2310], {value});
}
Variant is_double(const Variant &value) {
    return call(LITERAL_STRING[2311], {value});
}
Variant is_numeric(const Variant &value) {
    return call(LITERAL_STRING[2312], {value});
}
Variant is_string(const Variant &value) {
    return call(LITERAL_STRING[2313], {value});
}
Variant is_array(const Variant &value) {
    return call(LITERAL_STRING[2314], {value});
}
Variant is_object(const Variant &value) {
    return call(LITERAL_STRING[2315], {value});
}
Variant is_scalar(const Variant &value) {
    return call(LITERAL_STRING[2316], {value});
}
Variant is_callable(const Variant &value, const Variant &syntax_only, const Reference &callable_name) {
    return call(LITERAL_STRING[2317], {value, syntax_only, &callable_name});
}
Variant is_iterable(const Variant &value) {
    return call(LITERAL_STRING[2318], {value});
}
Variant is_countable(const Variant &value) {
    return call(LITERAL_STRING[2319], {value});
}
Variant uniqid(const Variant &prefix, const Variant &more_entropy) {
    return call(LITERAL_STRING[2320], {prefix, more_entropy});
}
Variant parse_url(const Variant &url, const Variant &component) {
    return call(LITERAL_STRING[2321], {url, component});
}
Variant urlencode(const Variant &string) {
    return call(LITERAL_STRING[2322], {string});
}
Variant urldecode(const Variant &string) {
    return call(LITERAL_STRING[2323], {string});
}
Variant rawurlencode(const Variant &string) {
    return call(LITERAL_STRING[2324], {string});
}
Variant rawurldecode(const Variant &string) {
    return call(LITERAL_STRING[2325], {string});
}
Variant get_headers(const Variant &url, const Variant &associative, const Variant &context) {
    return call(LITERAL_STRING[2326], {url, associative, context});
}
Variant stream_bucket_make_writeable(const Variant &brigade) {
    return call(LITERAL_STRING[2327], {brigade});
}
Variant stream_bucket_prepend(const Variant &brigade, const Variant &bucket) {
    return call(LITERAL_STRING[2328], {brigade, bucket});
}
Variant stream_bucket_append(const Variant &brigade, const Variant &bucket) {
    return call(LITERAL_STRING[2329], {brigade, bucket});
}
Variant stream_bucket_new(const Variant &stream, const Variant &buffer) {
    return call(LITERAL_STRING[2330], {stream, buffer});
}
Variant stream_get_filters() {
    return call(LITERAL_STRING[2331], {});
}
Variant stream_filter_register(const Variant &filter_name, const Variant &_class) {
    return call(LITERAL_STRING[2332], {filter_name, _class});
}
Variant convert_uuencode(const Variant &string) {
    return call(LITERAL_STRING[2333], {string});
}
Variant convert_uudecode(const Variant &string) {
    return call(LITERAL_STRING[2334], {string});
}
Variant var_export(const Variant &value, const Variant &_return) {
    return call(LITERAL_STRING[2336], {value, _return});
}
Variant serialize(const Variant &value) {
    return call(LITERAL_STRING[1750], {value});
}
Variant unserialize(const Variant &data, const Variant &options) {
    return call(LITERAL_STRING[1749], {data, options});
}
Variant memory_get_usage(const Variant &real_usage) {
    return call(LITERAL_STRING[2338], {real_usage});
}
Variant memory_get_peak_usage(const Variant &real_usage) {
    return call(LITERAL_STRING[2339], {real_usage});
}
Variant memory_reset_peak_usage() {
    return call(LITERAL_STRING[2340], {});
}
Variant version_compare(const Variant &version1, const Variant &version2, const Variant &_operator) {
    return call(LITERAL_STRING[2341], {version1, version2, _operator});
}
Variant dl(const Variant &extension_filename) {
    return call(LITERAL_STRING[2342], {extension_filename});
}
Variant cli_set_process_title(const Variant &title) {
    return call(LITERAL_STRING[2343], {title});
}
Variant cli_get_process_title() {
    return call(LITERAL_STRING[2344], {});
}
}  // namespace php

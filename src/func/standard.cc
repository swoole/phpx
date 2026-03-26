#include "phpx.h"

namespace php {
Variant set_time_limit(const Variant &seconds) {
    return call("set_time_limit", {seconds});
}
Variant header_register_callback(const Variant &callback) {
    return call("header_register_callback", {callback});
}
Variant ob_start(const Variant &callback, const Variant &chunk_size, const Variant &flags) {
    return call("ob_start", {callback, chunk_size, flags});
}
Variant ob_flush() {
    return call("ob_flush", {});
}
Variant ob_clean() {
    return call("ob_clean", {});
}
Variant ob_end_flush() {
    return call("ob_end_flush", {});
}
Variant ob_end_clean() {
    return call("ob_end_clean", {});
}
Variant ob_get_flush() {
    return call("ob_get_flush", {});
}
Variant ob_get_clean() {
    return call("ob_get_clean", {});
}
Variant ob_get_contents() {
    return call("ob_get_contents", {});
}
Variant ob_get_level() {
    return call("ob_get_level", {});
}
Variant ob_get_length() {
    return call("ob_get_length", {});
}
Variant ob_list_handlers() {
    return call("ob_list_handlers", {});
}
Variant ob_get_status(const Variant &full_status) {
    return call("ob_get_status", {full_status});
}
Variant ob_implicit_flush(const Variant &enable) {
    return call("ob_implicit_flush", {enable});
}
Variant output_reset_rewrite_vars() {
    return call("output_reset_rewrite_vars", {});
}
Variant output_add_rewrite_var(const Variant &name, const Variant &value) {
    return call("output_add_rewrite_var", {name, value});
}
Variant stream_wrapper_register(const Variant &protocol, const Variant &_class, const Variant &flags) {
    return call("stream_wrapper_register", {protocol, _class, flags});
}
Variant stream_register_wrapper(const Variant &protocol, const Variant &_class, const Variant &flags) {
    return call("stream_register_wrapper", {protocol, _class, flags});
}
Variant stream_wrapper_unregister(const Variant &protocol) {
    return call("stream_wrapper_unregister", {protocol});
}
Variant stream_wrapper_restore(const Variant &protocol) {
    return call("stream_wrapper_restore", {protocol});
}
Variant krsort(const Reference &array, const Variant &flags) {
    return call("krsort", {&array, flags});
}
Variant ksort(const Reference &array, const Variant &flags) {
    return call("ksort", {&array, flags});
}
Variant count(const Variant &value, const Variant &mode) {
    return call("count", {value, mode});
}
Variant natsort(const Reference &array) {
    return call("natsort", {&array});
}
Variant natcasesort(const Reference &array) {
    return call("natcasesort", {&array});
}
Variant asort(const Reference &array, const Variant &flags) {
    return call("asort", {&array, flags});
}
Variant arsort(const Reference &array, const Variant &flags) {
    return call("arsort", {&array, flags});
}
Variant sort(const Reference &array, const Variant &flags) {
    return call("sort", {&array, flags});
}
Variant rsort(const Reference &array, const Variant &flags) {
    return call("rsort", {&array, flags});
}
Variant usort(const Reference &array, const Variant &callback) {
    return call("usort", {&array, callback});
}
Variant uasort(const Reference &array, const Variant &callback) {
    return call("uasort", {&array, callback});
}
Variant uksort(const Reference &array, const Variant &callback) {
    return call("uksort", {&array, callback});
}
Variant end(const Reference &array) {
    return call("end", {&array});
}
Variant prev(const Reference &array) {
    return call("prev", {&array});
}
Variant next(const Reference &array) {
    return call("next", {&array});
}
Variant reset(const Reference &array) {
    return call("reset", {&array});
}
Variant current(const Variant &array) {
    return call("current", {array});
}
Variant pos(const Variant &array) {
    return call("pos", {array});
}
Variant key(const Variant &array) {
    return call("key", {array});
}
Variant array_walk(const Reference &array, const Variant &callback, const Variant &arg) {
    return call("array_walk", {&array, callback, arg});
}
Variant array_walk_recursive(const Reference &array, const Variant &callback, const Variant &arg) {
    return call("array_walk_recursive", {&array, callback, arg});
}
Variant in_array(const Variant &needle, const Variant &haystack, const Variant &strict) {
    return call("in_array", {needle, haystack, strict});
}
Variant array_search(const Variant &needle, const Variant &haystack, const Variant &strict) {
    return call("array_search", {needle, haystack, strict});
}
Variant extract(const Reference &array, const Variant &flags, const Variant &prefix) {
    return call("extract", {&array, flags, prefix});
}
Variant array_fill(const Variant &start_index, const Variant &count, const Variant &value) {
    return call("array_fill", {start_index, count, value});
}
Variant array_fill_keys(const Variant &keys, const Variant &value) {
    return call("array_fill_keys", {keys, value});
}
Variant range(const Variant &start, const Variant &end, const Variant &step) {
    return call("range", {start, end, step});
}
Variant shuffle(const Reference &array) {
    return call("shuffle", {&array});
}
Variant array_pop(const Reference &array) {
    return call("array_pop", {&array});
}
Variant array_shift(const Reference &array) {
    return call("array_shift", {&array});
}
Variant array_splice(const Reference &array, const Variant &offset, const Variant &length, const Variant &replacement) {
    return call("array_splice", {&array, offset, length, replacement});
}
Variant array_slice(const Variant &array, const Variant &offset, const Variant &length, const Variant &preserve_keys) {
    return call("array_slice", {array, offset, length, preserve_keys});
}
Variant array_keys(const Variant &array, const Variant &filter_value, const Variant &strict) {
    return call("array_keys", {array, filter_value, strict});
}
Variant array_key_first(const Variant &array) {
    return call("array_key_first", {array});
}
Variant array_key_last(const Variant &array) {
    return call("array_key_last", {array});
}
Variant array_values(const Variant &array) {
    return call("array_values", {array});
}
Variant array_count_values(const Variant &array) {
    return call("array_count_values", {array});
}
Variant array_column(const Variant &array, const Variant &column_key, const Variant &index_key) {
    return call("array_column", {array, column_key, index_key});
}
Variant array_reverse(const Variant &array, const Variant &preserve_keys) {
    return call("array_reverse", {array, preserve_keys});
}
Variant array_pad(const Variant &array, const Variant &length, const Variant &value) {
    return call("array_pad", {array, length, value});
}
Variant array_flip(const Variant &array) {
    return call("array_flip", {array});
}
Variant array_change_key_case(const Variant &array, const Variant &_case) {
    return call("array_change_key_case", {array, _case});
}
Variant array_unique(const Variant &array, const Variant &flags) {
    return call("array_unique", {array, flags});
}
Variant array_rand(const Variant &array, const Variant &num) {
    return call("array_rand", {array, num});
}
Variant array_sum(const Variant &array) {
    return call("array_sum", {array});
}
Variant array_product(const Variant &array) {
    return call("array_product", {array});
}
Variant array_reduce(const Variant &array, const Variant &callback, const Variant &initial) {
    return call("array_reduce", {array, callback, initial});
}
Variant array_filter(const Variant &array, const Variant &callback, const Variant &mode) {
    return call("array_filter", {array, callback, mode});
}
Variant array_find(const Variant &array, const Variant &callback) {
    return call("array_find", {array, callback});
}
Variant array_find_key(const Variant &array, const Variant &callback) {
    return call("array_find_key", {array, callback});
}
Variant array_any(const Variant &array, const Variant &callback) {
    return call("array_any", {array, callback});
}
Variant array_all(const Variant &array, const Variant &callback) {
    return call("array_all", {array, callback});
}
Variant array_key_exists(const Variant &key, const Variant &array) {
    return call("array_key_exists", {key, array});
}
Variant key_exists(const Variant &key, const Variant &array) {
    return call("key_exists", {key, array});
}
Variant array_chunk(const Variant &array, const Variant &length, const Variant &preserve_keys) {
    return call("array_chunk", {array, length, preserve_keys});
}
Variant array_combine(const Variant &keys, const Variant &values) {
    return call("array_combine", {keys, values});
}
Variant array_is_list(const Variant &array) {
    return call("array_is_list", {array});
}
Variant base64_encode(const Variant &string) {
    return call("base64_encode", {string});
}
Variant base64_decode(const Variant &string, const Variant &strict) {
    return call("base64_decode", {string, strict});
}
Variant ip2long(const Variant &ip) {
    return call("ip2long", {ip});
}
Variant long2ip(const Variant &ip) {
    return call("long2ip", {ip});
}
Variant getenv(const Variant &name, const Variant &local_only) {
    return call("getenv", {name, local_only});
}
Variant putenv(const Variant &assignment) {
    return call("putenv", {assignment});
}
Variant getopt(const Variant &short_options, const Variant &long_options, const Reference &rest_index) {
    return call("getopt", {short_options, long_options, &rest_index});
}
Variant flush() {
    return call("flush", {});
}
Variant sleep(const Variant &seconds) {
    return call("sleep", {seconds});
}
Variant usleep(const Variant &microseconds) {
    return call("usleep", {microseconds});
}
Variant time_nanosleep(const Variant &seconds, const Variant &nanoseconds) {
    return call("time_nanosleep", {seconds, nanoseconds});
}
Variant time_sleep_until(const Variant &timestamp) {
    return call("time_sleep_until", {timestamp});
}
Variant get_current_user() {
    return call("get_current_user", {});
}
Variant get_cfg_var(const Variant &option) {
    return call("get_cfg_var", {option});
}
Variant error_log(const Variant &message, const Variant &message_type, const Variant &destination, const Variant &additional_headers) {
    return call("error_log", {message, message_type, destination, additional_headers});
}
Variant error_get_last() {
    return call("error_get_last", {});
}
Variant error_clear_last() {
    return call("error_clear_last", {});
}
Variant call_user_func_array(const Variant &callback, const Variant &args) {
    return call("call_user_func_array", {callback, args});
}
Variant forward_static_call_array(const Variant &callback, const Variant &args) {
    return call("forward_static_call_array", {callback, args});
}
Variant highlight_file(const Variant &filename, const Variant &_return) {
    return call("highlight_file", {filename, _return});
}
Variant show_source(const Variant &filename, const Variant &_return) {
    return call("show_source", {filename, _return});
}
Variant php_strip_whitespace(const Variant &filename) {
    return call("php_strip_whitespace", {filename});
}
Variant highlight_string(const Variant &string, const Variant &_return) {
    return call("highlight_string", {string, _return});
}
Variant ini_get(const Variant &option) {
    return call("ini_get", {option});
}
Variant ini_get_all(const Variant &extension, const Variant &details) {
    return call("ini_get_all", {extension, details});
}
Variant ini_set(const Variant &option, const Variant &value) {
    return call("ini_set", {option, value});
}
Variant ini_alter(const Variant &option, const Variant &value) {
    return call("ini_alter", {option, value});
}
Variant ini_restore(const Variant &option) {
    return call("ini_restore", {option});
}
Variant ini_parse_quantity(const Variant &shorthand) {
    return call("ini_parse_quantity", {shorthand});
}
Variant set_include_path(const Variant &include_path) {
    return call("set_include_path", {include_path});
}
Variant get_include_path() {
    return call("get_include_path", {});
}
Variant print_r(const Variant &value, const Variant &_return) {
    return call("print_r", {value, _return});
}
Variant connection_aborted() {
    return call("connection_aborted", {});
}
Variant connection_status() {
    return call("connection_status", {});
}
Variant ignore_user_abort(const Variant &enable) {
    return call("ignore_user_abort", {enable});
}
Variant getservbyname(const Variant &service, const Variant &protocol) {
    return call("getservbyname", {service, protocol});
}
Variant getservbyport(const Variant &port, const Variant &protocol) {
    return call("getservbyport", {port, protocol});
}
Variant getprotobyname(const Variant &protocol) {
    return call("getprotobyname", {protocol});
}
Variant getprotobynumber(const Variant &protocol) {
    return call("getprotobynumber", {protocol});
}
Variant unregister_tick_function(const Variant &callback) {
    return call("unregister_tick_function", {callback});
}
Variant is_uploaded_file(const Variant &filename) {
    return call("is_uploaded_file", {filename});
}
Variant move_uploaded_file(const Variant &from, const Variant &to) {
    return call("move_uploaded_file", {from, to});
}
Variant parse_ini_file(const Variant &filename, const Variant &process_sections, const Variant &scanner_mode) {
    return call("parse_ini_file", {filename, process_sections, scanner_mode});
}
Variant parse_ini_string(const Variant &ini_string, const Variant &process_sections, const Variant &scanner_mode) {
    return call("parse_ini_string", {ini_string, process_sections, scanner_mode});
}
Variant config_get_hash() {
    return call("config_get_hash", {});
}
Variant sys_getloadavg() {
    return call("sys_getloadavg", {});
}
Variant get_browser(const Variant &user_agent, const Variant &return_array) {
    return call("get_browser", {user_agent, return_array});
}
Variant crc32(const Variant &string) {
    return call("crc32", {string});
}
Variant crypt(const Variant &string, const Variant &salt) {
    return call("crypt", {string, salt});
}
Variant strptime(const Variant &timestamp, const Variant &format) {
    return call("strptime", {timestamp, format});
}
Variant gethostname() {
    return call("gethostname", {});
}
Variant gethostbyaddr(const Variant &ip) {
    return call("gethostbyaddr", {ip});
}
Variant gethostbyname(const Variant &hostname) {
    return call("gethostbyname", {hostname});
}
Variant gethostbynamel(const Variant &hostname) {
    return call("gethostbynamel", {hostname});
}
Variant dns_check_record(const Variant &hostname, const Variant &type) {
    return call("dns_check_record", {hostname, type});
}
Variant checkdnsrr(const Variant &hostname, const Variant &type) {
    return call("checkdnsrr", {hostname, type});
}
Variant dns_get_record(const Variant &hostname, const Variant &type, const Reference &authoritative_name_servers, const Reference &additional_records, const Variant &raw) {
    return call("dns_get_record", {hostname, type, &authoritative_name_servers, &additional_records, raw});
}
Variant dns_get_mx(const Variant &hostname, const Reference &hosts, const Reference &weights) {
    return call("dns_get_mx", {hostname, &hosts, &weights});
}
Variant getmxrr(const Variant &hostname, const Reference &hosts, const Reference &weights) {
    return call("getmxrr", {hostname, &hosts, &weights});
}
Variant net_get_interfaces() {
    return call("net_get_interfaces", {});
}
Variant ftok(const Variant &filename, const Variant &project_id) {
    return call("ftok", {filename, project_id});
}
Variant hrtime(const Variant &as_number) {
    return call("hrtime", {as_number});
}
Variant md5(const Variant &string, const Variant &binary) {
    return call("md5", {string, binary});
}
Variant md5_file(const Variant &filename, const Variant &binary) {
    return call("md5_file", {filename, binary});
}
Variant getmyuid() {
    return call("getmyuid", {});
}
Variant getmygid() {
    return call("getmygid", {});
}
Variant getmypid() {
    return call("getmypid", {});
}
Variant getmyinode() {
    return call("getmyinode", {});
}
Variant getlastmod() {
    return call("getlastmod", {});
}
Variant sha1(const Variant &string, const Variant &binary) {
    return call("sha1", {string, binary});
}
Variant sha1_file(const Variant &filename, const Variant &binary) {
    return call("sha1_file", {filename, binary});
}
Variant openlog(const Variant &prefix, const Variant &flags, const Variant &facility) {
    return call("openlog", {prefix, flags, facility});
}
Variant closelog() {
    return call("closelog", {});
}
Variant syslog(const Variant &priority, const Variant &message) {
    return call("syslog", {priority, message});
}
Variant inet_ntop(const Variant &ip) {
    return call("inet_ntop", {ip});
}
Variant inet_pton(const Variant &ip) {
    return call("inet_pton", {ip});
}
Variant metaphone(const Variant &string, const Variant &max_phonemes) {
    return call("metaphone", {string, max_phonemes});
}
Variant header(const Variant &header, const Variant &replace, const Variant &response_code) {
    return call("header", {header, replace, response_code});
}
Variant header_remove(const Variant &name) {
    return call("header_remove", {name});
}
Variant setrawcookie(const Variant &name, const Variant &value, const Variant &expires_or_options, const Variant &path, const Variant &domain, const Variant &secure, const Variant &httponly) {
    return call("setrawcookie", {name, value, expires_or_options, path, domain, secure, httponly});
}
Variant setcookie(const Variant &name, const Variant &value, const Variant &expires_or_options, const Variant &path, const Variant &domain, const Variant &secure, const Variant &httponly) {
    return call("setcookie", {name, value, expires_or_options, path, domain, secure, httponly});
}
Variant http_response_code(const Variant &response_code) {
    return call("http_response_code", {response_code});
}
Variant headers_sent(const Reference &filename, const Reference &line) {
    return call("headers_sent", {&filename, &line});
}
Variant headers_list() {
    return call("headers_list", {});
}
Variant htmlspecialchars(const Variant &string, const Variant &flags, const Variant &encoding, const Variant &double_encode) {
    return call("htmlspecialchars", {string, flags, encoding, double_encode});
}
Variant htmlspecialchars_decode(const Variant &string, const Variant &flags) {
    return call("htmlspecialchars_decode", {string, flags});
}
Variant html_entity_decode(const Variant &string, const Variant &flags, const Variant &encoding) {
    return call("html_entity_decode", {string, flags, encoding});
}
Variant htmlentities(const Variant &string, const Variant &flags, const Variant &encoding, const Variant &double_encode) {
    return call("htmlentities", {string, flags, encoding, double_encode});
}
Variant get_html_translation_table(const Variant &table, const Variant &flags, const Variant &encoding) {
    return call("get_html_translation_table", {table, flags, encoding});
}
Variant assert_options(const Variant &option, const Variant &value) {
    return call("assert_options", {option, value});
}
Variant bin2hex(const Variant &string) {
    return call("bin2hex", {string});
}
Variant hex2bin(const Variant &string) {
    return call("hex2bin", {string});
}
Variant strspn(const Variant &string, const Variant &characters, const Variant &offset, const Variant &length) {
    return call("strspn", {string, characters, offset, length});
}
Variant strcspn(const Variant &string, const Variant &characters, const Variant &offset, const Variant &length) {
    return call("strcspn", {string, characters, offset, length});
}
Variant nl_langinfo(const Variant &item) {
    return call("nl_langinfo", {item});
}
Variant strcoll(const Variant &string1, const Variant &string2) {
    return call("strcoll", {string1, string2});
}
Variant trim(const Variant &string, const Variant &characters) {
    return call("trim", {string, characters});
}
Variant rtrim(const Variant &string, const Variant &characters) {
    return call("rtrim", {string, characters});
}
Variant chop(const Variant &string, const Variant &characters) {
    return call("chop", {string, characters});
}
Variant ltrim(const Variant &string, const Variant &characters) {
    return call("ltrim", {string, characters});
}
Variant wordwrap(const Variant &string, const Variant &width, const Variant &_break, const Variant &cut_long_words) {
    return call("wordwrap", {string, width, _break, cut_long_words});
}
Variant explode(const Variant &separator, const Variant &string, const Variant &limit) {
    return call("explode", {separator, string, limit});
}
Variant implode(const Variant &separator, const Variant &array) {
    return call("implode", {separator, array});
}
Variant join(const Variant &separator, const Variant &array) {
    return call("join", {separator, array});
}
Variant strtok(const Variant &string, const Variant &token) {
    return call("strtok", {string, token});
}
Variant strtoupper(const Variant &string) {
    return call("strtoupper", {string});
}
Variant strtolower(const Variant &string) {
    return call("strtolower", {string});
}
Variant str_increment(const Variant &string) {
    return call("str_increment", {string});
}
Variant str_decrement(const Variant &string) {
    return call("str_decrement", {string});
}
Variant basename(const Variant &path, const Variant &suffix) {
    return call("basename", {path, suffix});
}
Variant dirname(const Variant &path, const Variant &levels) {
    return call("dirname", {path, levels});
}
Variant pathinfo(const Variant &path, const Variant &flags) {
    return call("pathinfo", {path, flags});
}
Variant stristr(const Variant &haystack, const Variant &needle, const Variant &before_needle) {
    return call("stristr", {haystack, needle, before_needle});
}
Variant strstr(const Variant &haystack, const Variant &needle, const Variant &before_needle) {
    return call("strstr", {haystack, needle, before_needle});
}
Variant strchr(const Variant &haystack, const Variant &needle, const Variant &before_needle) {
    return call("strchr", {haystack, needle, before_needle});
}
Variant strpos(const Variant &haystack, const Variant &needle, const Variant &offset) {
    return call("strpos", {haystack, needle, offset});
}
Variant stripos(const Variant &haystack, const Variant &needle, const Variant &offset) {
    return call("stripos", {haystack, needle, offset});
}
Variant strrpos(const Variant &haystack, const Variant &needle, const Variant &offset) {
    return call("strrpos", {haystack, needle, offset});
}
Variant strripos(const Variant &haystack, const Variant &needle, const Variant &offset) {
    return call("strripos", {haystack, needle, offset});
}
Variant strrchr(const Variant &haystack, const Variant &needle, const Variant &before_needle) {
    return call("strrchr", {haystack, needle, before_needle});
}
Variant str_contains(const Variant &haystack, const Variant &needle) {
    return call("str_contains", {haystack, needle});
}
Variant str_starts_with(const Variant &haystack, const Variant &needle) {
    return call("str_starts_with", {haystack, needle});
}
Variant str_ends_with(const Variant &haystack, const Variant &needle) {
    return call("str_ends_with", {haystack, needle});
}
Variant chunk_split(const Variant &string, const Variant &length, const Variant &separator) {
    return call("chunk_split", {string, length, separator});
}
Variant substr(const Variant &string, const Variant &offset, const Variant &length) {
    return call("substr", {string, offset, length});
}
Variant substr_replace(const Variant &string, const Variant &replace, const Variant &offset, const Variant &length) {
    return call("substr_replace", {string, replace, offset, length});
}
Variant quotemeta(const Variant &string) {
    return call("quotemeta", {string});
}
Variant ord(const Variant &character) {
    return call("ord", {character});
}
Variant chr(const Variant &codepoint) {
    return call("chr", {codepoint});
}
Variant ucfirst(const Variant &string) {
    return call("ucfirst", {string});
}
Variant lcfirst(const Variant &string) {
    return call("lcfirst", {string});
}
Variant ucwords(const Variant &string, const Variant &separators) {
    return call("ucwords", {string, separators});
}
Variant strtr(const Variant &string, const Variant &from, const Variant &to) {
    return call("strtr", {string, from, to});
}
Variant strrev(const Variant &string) {
    return call("strrev", {string});
}
Variant similar_text(const Variant &string1, const Variant &string2, const Reference &percent) {
    return call("similar_text", {string1, string2, &percent});
}
Variant addcslashes(const Variant &string, const Variant &characters) {
    return call("addcslashes", {string, characters});
}
Variant addslashes(const Variant &string) {
    return call("addslashes", {string});
}
Variant stripcslashes(const Variant &string) {
    return call("stripcslashes", {string});
}
Variant stripslashes(const Variant &string) {
    return call("stripslashes", {string});
}
Variant str_replace(const Variant &search, const Variant &replace, const Variant &subject, const Reference &count) {
    return call("str_replace", {search, replace, subject, &count});
}
Variant str_ireplace(const Variant &search, const Variant &replace, const Variant &subject, const Reference &count) {
    return call("str_ireplace", {search, replace, subject, &count});
}
Variant hebrev(const Variant &string, const Variant &max_chars_per_line) {
    return call("hebrev", {string, max_chars_per_line});
}
Variant nl2br(const Variant &string, const Variant &use_xhtml) {
    return call("nl2br", {string, use_xhtml});
}
Variant strip_tags(const Variant &string, const Variant &allowed_tags) {
    return call("strip_tags", {string, allowed_tags});
}
Variant parse_str(const Variant &string, const Reference &result) {
    return call("parse_str", {string, &result});
}
Variant str_getcsv(const Variant &string, const Variant &separator, const Variant &enclosure, const Variant &escape) {
    return call("str_getcsv", {string, separator, enclosure, escape});
}
Variant str_repeat(const Variant &string, const Variant &times) {
    return call("str_repeat", {string, times});
}
Variant count_chars(const Variant &string, const Variant &mode) {
    return call("count_chars", {string, mode});
}
Variant localeconv() {
    return call("localeconv", {});
}
Variant substr_count(const Variant &haystack, const Variant &needle, const Variant &offset, const Variant &length) {
    return call("substr_count", {haystack, needle, offset, length});
}
Variant str_pad(const Variant &string, const Variant &length, const Variant &pad_string, const Variant &pad_type) {
    return call("str_pad", {string, length, pad_string, pad_type});
}
Variant str_rot13(const Variant &string) {
    return call("str_rot13", {string});
}
Variant str_shuffle(const Variant &string) {
    return call("str_shuffle", {string});
}
Variant str_word_count(const Variant &string, const Variant &format, const Variant &characters) {
    return call("str_word_count", {string, format, characters});
}
Variant str_split(const Variant &string, const Variant &length) {
    return call("str_split", {string, length});
}
Variant strpbrk(const Variant &string, const Variant &characters) {
    return call("strpbrk", {string, characters});
}
Variant substr_compare(const Variant &haystack, const Variant &needle, const Variant &offset, const Variant &length, const Variant &case_insensitive) {
    return call("substr_compare", {haystack, needle, offset, length, case_insensitive});
}
Variant utf8_encode(const Variant &string) {
    return call("utf8_encode", {string});
}
Variant utf8_decode(const Variant &string) {
    return call("utf8_decode", {string});
}
Variant opendir(const Variant &directory, const Variant &context) {
    return call("opendir", {directory, context});
}
Variant dir(const Variant &directory, const Variant &context) {
    return call("dir", {directory, context});
}
Variant closedir(const Variant &dir_handle) {
    return call("closedir", {dir_handle});
}
Variant chdir(const Variant &directory) {
    return call("chdir", {directory});
}
Variant getcwd() {
    return call("getcwd", {});
}
Variant rewinddir(const Variant &dir_handle) {
    return call("rewinddir", {dir_handle});
}
Variant readdir(const Variant &dir_handle) {
    return call("readdir", {dir_handle});
}
Variant scandir(const Variant &directory, const Variant &sorting_order, const Variant &context) {
    return call("scandir", {directory, sorting_order, context});
}
Variant glob(const Variant &pattern, const Variant &flags) {
    return call("glob", {pattern, flags});
}
Variant exec(const Variant &command, const Reference &output, const Reference &result_code) {
    return call("exec", {command, &output, &result_code});
}
Variant system(const Variant &command, const Reference &result_code) {
    return call("system", {command, &result_code});
}
Variant passthru(const Variant &command, const Reference &result_code) {
    return call("passthru", {command, &result_code});
}
Variant escapeshellcmd(const Variant &command) {
    return call("escapeshellcmd", {command});
}
Variant escapeshellarg(const Variant &arg) {
    return call("escapeshellarg", {arg});
}
Variant shell_exec(const Variant &command) {
    return call("shell_exec", {command});
}
Variant proc_nice(const Variant &priority) {
    return call("proc_nice", {priority});
}
Variant flock(const Variant &stream, const Variant &operation, const Reference &would_block) {
    return call("flock", {stream, operation, &would_block});
}
Variant get_meta_tags(const Variant &filename, const Variant &use_include_path) {
    return call("get_meta_tags", {filename, use_include_path});
}
Variant pclose(const Variant &handle) {
    return call("pclose", {handle});
}
Variant popen(const Variant &command, const Variant &mode) {
    return call("popen", {command, mode});
}
Variant readfile(const Variant &filename, const Variant &use_include_path, const Variant &context) {
    return call("readfile", {filename, use_include_path, context});
}
Variant rewind(const Variant &stream) {
    return call("rewind", {stream});
}
Variant rmdir(const Variant &directory, const Variant &context) {
    return call("rmdir", {directory, context});
}
Variant umask(const Variant &mask) {
    return call("umask", {mask});
}
Variant fclose(const Variant &stream) {
    return call("fclose", {stream});
}
Variant feof(const Variant &stream) {
    return call("feof", {stream});
}
Variant fgetc(const Variant &stream) {
    return call("fgetc", {stream});
}
Variant fgets(const Variant &stream, const Variant &length) {
    return call("fgets", {stream, length});
}
Variant fread(const Variant &stream, const Variant &length) {
    return call("fread", {stream, length});
}
Variant fopen(const Variant &filename, const Variant &mode, const Variant &use_include_path, const Variant &context) {
    return call("fopen", {filename, mode, use_include_path, context});
}
Variant fpassthru(const Variant &stream) {
    return call("fpassthru", {stream});
}
Variant ftruncate(const Variant &stream, const Variant &size) {
    return call("ftruncate", {stream, size});
}
Variant fstat(const Variant &stream) {
    return call("fstat", {stream});
}
Variant fseek(const Variant &stream, const Variant &offset, const Variant &whence) {
    return call("fseek", {stream, offset, whence});
}
Variant ftell(const Variant &stream) {
    return call("ftell", {stream});
}
Variant fflush(const Variant &stream) {
    return call("fflush", {stream});
}
Variant fsync(const Variant &stream) {
    return call("fsync", {stream});
}
Variant fdatasync(const Variant &stream) {
    return call("fdatasync", {stream});
}
Variant fwrite(const Variant &stream, const Variant &data, const Variant &length) {
    return call("fwrite", {stream, data, length});
}
Variant fputs(const Variant &stream, const Variant &data, const Variant &length) {
    return call("fputs", {stream, data, length});
}
Variant mkdir(const Variant &directory, const Variant &permissions, const Variant &recursive, const Variant &context) {
    return call("mkdir", {directory, permissions, recursive, context});
}
Variant rename(const Variant &from, const Variant &to, const Variant &context) {
    return call("rename", {from, to, context});
}
Variant copy(const Variant &from, const Variant &to, const Variant &context) {
    return call("copy", {from, to, context});
}
Variant tempnam(const Variant &directory, const Variant &prefix) {
    return call("tempnam", {directory, prefix});
}
Variant tmpfile() {
    return call("tmpfile", {});
}
Variant file(const Variant &filename, const Variant &flags, const Variant &context) {
    return call("file", {filename, flags, context});
}
Variant file_get_contents(const Variant &filename, const Variant &use_include_path, const Variant &context, const Variant &offset, const Variant &length) {
    return call("file_get_contents", {filename, use_include_path, context, offset, length});
}
Variant unlink(const Variant &filename, const Variant &context) {
    return call("unlink", {filename, context});
}
Variant file_put_contents(const Variant &filename, const Variant &data, const Variant &flags, const Variant &context) {
    return call("file_put_contents", {filename, data, flags, context});
}
Variant fputcsv(const Variant &stream, const Variant &fields, const Variant &separator, const Variant &enclosure, const Variant &escape, const Variant &eol) {
    return call("fputcsv", {stream, fields, separator, enclosure, escape, eol});
}
Variant fgetcsv(const Variant &stream, const Variant &length, const Variant &separator, const Variant &enclosure, const Variant &escape) {
    return call("fgetcsv", {stream, length, separator, enclosure, escape});
}
Variant realpath(const Variant &path) {
    return call("realpath", {path});
}
Variant fnmatch(const Variant &pattern, const Variant &filename, const Variant &flags) {
    return call("fnmatch", {pattern, filename, flags});
}
Variant sys_get_temp_dir() {
    return call("sys_get_temp_dir", {});
}
Variant fileatime(const Variant &filename) {
    return call("fileatime", {filename});
}
Variant filectime(const Variant &filename) {
    return call("filectime", {filename});
}
Variant filegroup(const Variant &filename) {
    return call("filegroup", {filename});
}
Variant fileinode(const Variant &filename) {
    return call("fileinode", {filename});
}
Variant filemtime(const Variant &filename) {
    return call("filemtime", {filename});
}
Variant fileowner(const Variant &filename) {
    return call("fileowner", {filename});
}
Variant fileperms(const Variant &filename) {
    return call("fileperms", {filename});
}
Variant filesize(const Variant &filename) {
    return call("filesize", {filename});
}
Variant filetype(const Variant &filename) {
    return call("filetype", {filename});
}
Variant file_exists(const Variant &filename) {
    return call("file_exists", {filename});
}
Variant is_writable(const Variant &filename) {
    return call("is_writable", {filename});
}
Variant is_writeable(const Variant &filename) {
    return call("is_writeable", {filename});
}
Variant is_readable(const Variant &filename) {
    return call("is_readable", {filename});
}
Variant is_executable(const Variant &filename) {
    return call("is_executable", {filename});
}
Variant is_file(const Variant &filename) {
    return call("is_file", {filename});
}
Variant is_dir(const Variant &filename) {
    return call("is_dir", {filename});
}
Variant is_link(const Variant &filename) {
    return call("is_link", {filename});
}
Variant stat(const Variant &filename) {
    return call("stat", {filename});
}
Variant lstat(const Variant &filename) {
    return call("lstat", {filename});
}
Variant chown(const Variant &filename, const Variant &user) {
    return call("chown", {filename, user});
}
Variant chgrp(const Variant &filename, const Variant &group) {
    return call("chgrp", {filename, group});
}
Variant lchown(const Variant &filename, const Variant &user) {
    return call("lchown", {filename, user});
}
Variant lchgrp(const Variant &filename, const Variant &group) {
    return call("lchgrp", {filename, group});
}
Variant chmod(const Variant &filename, const Variant &permissions) {
    return call("chmod", {filename, permissions});
}
Variant touch(const Variant &filename, const Variant &mtime, const Variant &atime) {
    return call("touch", {filename, mtime, atime});
}
Variant clearstatcache(const Variant &clear_realpath_cache, const Variant &filename) {
    return call("clearstatcache", {clear_realpath_cache, filename});
}
Variant disk_total_space(const Variant &directory) {
    return call("disk_total_space", {directory});
}
Variant disk_free_space(const Variant &directory) {
    return call("disk_free_space", {directory});
}
Variant diskfreespace(const Variant &directory) {
    return call("diskfreespace", {directory});
}
Variant realpath_cache_get() {
    return call("realpath_cache_get", {});
}
Variant realpath_cache_size() {
    return call("realpath_cache_size", {});
}
Variant vprintf(const Variant &format, const Variant &values) {
    return call("vprintf", {format, values});
}
Variant vsprintf(const Variant &format, const Variant &values) {
    return call("vsprintf", {format, values});
}
Variant vfprintf(const Variant &stream, const Variant &format, const Variant &values) {
    return call("vfprintf", {stream, format, values});
}
Variant fsockopen(const Variant &hostname, const Variant &port, const Reference &error_code, const Reference &error_message, const Variant &timeout) {
    return call("fsockopen", {hostname, port, &error_code, &error_message, timeout});
}
Variant pfsockopen(const Variant &hostname, const Variant &port, const Reference &error_code, const Reference &error_message, const Variant &timeout) {
    return call("pfsockopen", {hostname, port, &error_code, &error_message, timeout});
}
Variant http_build_query(const Variant &data, const Variant &numeric_prefix, const Variant &arg_separator, const Variant &encoding_type) {
    return call("http_build_query", {data, numeric_prefix, arg_separator, encoding_type});
}
Variant http_get_last_response_headers() {
    return call("http_get_last_response_headers", {});
}
Variant http_clear_last_response_headers() {
    return call("http_clear_last_response_headers", {});
}
Variant request_parse_body(const Variant &options) {
    return call("request_parse_body", {options});
}
Variant image_type_to_mime_type(const Variant &image_type) {
    return call("image_type_to_mime_type", {image_type});
}
Variant image_type_to_extension(const Variant &image_type, const Variant &include_dot) {
    return call("image_type_to_extension", {image_type, include_dot});
}
Variant getimagesize(const Variant &filename, const Reference &image_info) {
    return call("getimagesize", {filename, &image_info});
}
Variant getimagesizefromstring(const Variant &string, const Reference &image_info) {
    return call("getimagesizefromstring", {string, &image_info});
}
Variant phpinfo(const Variant &flags) {
    return call("phpinfo", {flags});
}
Variant phpversion(const Variant &extension) {
    return call("phpversion", {extension});
}
Variant phpcredits(const Variant &flags) {
    return call("phpcredits", {flags});
}
Variant php_sapi_name() {
    return call("php_sapi_name", {});
}
Variant php_uname(const Variant &mode) {
    return call("php_uname", {mode});
}
Variant php_ini_scanned_files() {
    return call("php_ini_scanned_files", {});
}
Variant php_ini_loaded_file() {
    return call("php_ini_loaded_file", {});
}
Variant iptcembed(const Variant &iptc_data, const Variant &filename, const Variant &spool) {
    return call("iptcembed", {iptc_data, filename, spool});
}
Variant iptcparse(const Variant &iptc_block) {
    return call("iptcparse", {iptc_block});
}
Variant levenshtein(const Variant &string1, const Variant &string2, const Variant &insertion_cost, const Variant &replacement_cost, const Variant &deletion_cost) {
    return call("levenshtein", {string1, string2, insertion_cost, replacement_cost, deletion_cost});
}
Variant readlink(const Variant &path) {
    return call("readlink", {path});
}
Variant linkinfo(const Variant &path) {
    return call("linkinfo", {path});
}
Variant symlink(const Variant &target, const Variant &link) {
    return call("symlink", {target, link});
}
Variant link(const Variant &target, const Variant &link) {
    return call("link", {target, link});
}
Variant mail(const Variant &to, const Variant &subject, const Variant &message, const Variant &additional_headers, const Variant &additional_params) {
    return call("mail", {to, subject, message, additional_headers, additional_params});
}
Variant abs(const Variant &num) {
    return call("abs", {num});
}
Variant ceil(const Variant &num) {
    return call("ceil", {num});
}
Variant floor(const Variant &num) {
    return call("floor", {num});
}
Variant round(const Variant &num, const Variant &precision, const Variant &mode) {
    return call("round", {num, precision, mode});
}
Variant sin(const Variant &num) {
    return call("sin", {num});
}
Variant cos(const Variant &num) {
    return call("cos", {num});
}
Variant tan(const Variant &num) {
    return call("tan", {num});
}
Variant asin(const Variant &num) {
    return call("asin", {num});
}
Variant acos(const Variant &num) {
    return call("acos", {num});
}
Variant atan(const Variant &num) {
    return call("atan", {num});
}
Variant atanh(const Variant &num) {
    return call("atanh", {num});
}
Variant atan2(const Variant &y, const Variant &x) {
    return call("atan2", {y, x});
}
Variant sinh(const Variant &num) {
    return call("sinh", {num});
}
Variant cosh(const Variant &num) {
    return call("cosh", {num});
}
Variant tanh(const Variant &num) {
    return call("tanh", {num});
}
Variant asinh(const Variant &num) {
    return call("asinh", {num});
}
Variant acosh(const Variant &num) {
    return call("acosh", {num});
}
Variant expm1(const Variant &num) {
    return call("expm1", {num});
}
Variant log1p(const Variant &num) {
    return call("log1p", {num});
}
Variant pi() {
    return call("pi", {});
}
Variant is_finite(const Variant &num) {
    return call("is_finite", {num});
}
Variant is_nan(const Variant &num) {
    return call("is_nan", {num});
}
Variant intdiv(const Variant &num1, const Variant &num2) {
    return call("intdiv", {num1, num2});
}
Variant is_infinite(const Variant &num) {
    return call("is_infinite", {num});
}
Variant pow(const Variant &num, const Variant &exponent) {
    return call("pow", {num, exponent});
}
Variant exp(const Variant &num) {
    return call("exp", {num});
}
Variant log(const Variant &num, const Variant &base) {
    return call("log", {num, base});
}
Variant log10(const Variant &num) {
    return call("log10", {num});
}
Variant sqrt(const Variant &num) {
    return call("sqrt", {num});
}
Variant hypot(const Variant &x, const Variant &y) {
    return call("hypot", {x, y});
}
Variant deg2rad(const Variant &num) {
    return call("deg2rad", {num});
}
Variant rad2deg(const Variant &num) {
    return call("rad2deg", {num});
}
Variant bindec(const Variant &binary_string) {
    return call("bindec", {binary_string});
}
Variant hexdec(const Variant &hex_string) {
    return call("hexdec", {hex_string});
}
Variant octdec(const Variant &octal_string) {
    return call("octdec", {octal_string});
}
Variant decbin(const Variant &num) {
    return call("decbin", {num});
}
Variant decoct(const Variant &num) {
    return call("decoct", {num});
}
Variant dechex(const Variant &num) {
    return call("dechex", {num});
}
Variant base_convert(const Variant &num, const Variant &from_base, const Variant &to_base) {
    return call("base_convert", {num, from_base, to_base});
}
Variant number_format(const Variant &num, const Variant &decimals, const Variant &decimal_separator, const Variant &thousands_separator) {
    return call("number_format", {num, decimals, decimal_separator, thousands_separator});
}
Variant fmod(const Variant &num1, const Variant &num2) {
    return call("fmod", {num1, num2});
}
Variant fdiv(const Variant &num1, const Variant &num2) {
    return call("fdiv", {num1, num2});
}
Variant fpow(const Variant &num, const Variant &exponent) {
    return call("fpow", {num, exponent});
}
Variant microtime(const Variant &as_float) {
    return call("microtime", {as_float});
}
Variant gettimeofday(const Variant &as_float) {
    return call("gettimeofday", {as_float});
}
Variant getrusage(const Variant &mode) {
    return call("getrusage", {mode});
}
Variant unpack(const Variant &format, const Variant &string, const Variant &offset) {
    return call("unpack", {format, string, offset});
}
Variant password_get_info(const Variant &hash) {
    return call("password_get_info", {hash});
}
Variant password_hash(const Variant &password, const Variant &algo, const Variant &options) {
    return call("password_hash", {password, algo, options});
}
Variant password_needs_rehash(const Variant &hash, const Variant &algo, const Variant &options) {
    return call("password_needs_rehash", {hash, algo, options});
}
Variant password_verify(const Variant &password, const Variant &hash) {
    return call("password_verify", {password, hash});
}
Variant password_algos() {
    return call("password_algos", {});
}
Variant proc_open(const Variant &command, const Variant &descriptor_spec, const Reference &pipes, const Variant &cwd, const Variant &env_vars, const Variant &options) {
    return call("proc_open", {command, descriptor_spec, &pipes, cwd, env_vars, options});
}
Variant proc_close(const Variant &process) {
    return call("proc_close", {process});
}
Variant proc_terminate(const Variant &process, const Variant &signal) {
    return call("proc_terminate", {process, signal});
}
Variant proc_get_status(const Variant &process) {
    return call("proc_get_status", {process});
}
Variant quoted_printable_decode(const Variant &string) {
    return call("quoted_printable_decode", {string});
}
Variant quoted_printable_encode(const Variant &string) {
    return call("quoted_printable_encode", {string});
}
Variant soundex(const Variant &string) {
    return call("soundex", {string});
}
Variant stream_select(const Reference &read, const Reference &write, const Reference &except, const Variant &seconds, const Variant &microseconds) {
    return call("stream_select", {&read, &write, &except, seconds, microseconds});
}
Variant stream_context_create(const Variant &options, const Variant &params) {
    return call("stream_context_create", {options, params});
}
Variant stream_context_set_params(const Variant &context, const Variant &params) {
    return call("stream_context_set_params", {context, params});
}
Variant stream_context_get_params(const Variant &context) {
    return call("stream_context_get_params", {context});
}
Variant stream_context_set_option(const Variant &context, const Variant &wrapper_or_options, const Variant &option_name, const Variant &value) {
    return call("stream_context_set_option", {context, wrapper_or_options, option_name, value});
}
Variant stream_context_set_options(const Variant &context, const Variant &options) {
    return call("stream_context_set_options", {context, options});
}
Variant stream_context_get_options(const Variant &stream_or_context) {
    return call("stream_context_get_options", {stream_or_context});
}
Variant stream_context_get_default(const Variant &options) {
    return call("stream_context_get_default", {options});
}
Variant stream_context_set_default(const Variant &options) {
    return call("stream_context_set_default", {options});
}
Variant stream_filter_prepend(const Variant &stream, const Variant &filter_name, const Variant &mode, const Variant &params) {
    return call("stream_filter_prepend", {stream, filter_name, mode, params});
}
Variant stream_filter_append(const Variant &stream, const Variant &filter_name, const Variant &mode, const Variant &params) {
    return call("stream_filter_append", {stream, filter_name, mode, params});
}
Variant stream_filter_remove(const Variant &stream_filter) {
    return call("stream_filter_remove", {stream_filter});
}
Variant stream_socket_client(const Variant &address, const Reference &error_code, const Reference &error_message, const Variant &timeout, const Variant &flags, const Variant &context) {
    return call("stream_socket_client", {address, &error_code, &error_message, timeout, flags, context});
}
Variant stream_socket_server(const Variant &address, const Reference &error_code, const Reference &error_message, const Variant &flags, const Variant &context) {
    return call("stream_socket_server", {address, &error_code, &error_message, flags, context});
}
Variant stream_socket_accept(const Variant &socket, const Variant &timeout, const Reference &peer_name) {
    return call("stream_socket_accept", {socket, timeout, &peer_name});
}
Variant stream_socket_get_name(const Variant &socket, const Variant &remote) {
    return call("stream_socket_get_name", {socket, remote});
}
Variant stream_socket_recvfrom(const Variant &socket, const Variant &length, const Variant &flags, const Reference &address) {
    return call("stream_socket_recvfrom", {socket, length, flags, &address});
}
Variant stream_socket_sendto(const Variant &socket, const Variant &data, const Variant &flags, const Variant &address) {
    return call("stream_socket_sendto", {socket, data, flags, address});
}
Variant stream_socket_enable_crypto(const Variant &stream, const Variant &enable, const Variant &crypto_method, const Variant &session_stream) {
    return call("stream_socket_enable_crypto", {stream, enable, crypto_method, session_stream});
}
Variant stream_socket_shutdown(const Variant &stream, const Variant &mode) {
    return call("stream_socket_shutdown", {stream, mode});
}
Variant stream_socket_pair(const Variant &domain, const Variant &type, const Variant &protocol) {
    return call("stream_socket_pair", {domain, type, protocol});
}
Variant stream_copy_to_stream(const Variant &from, const Variant &to, const Variant &length, const Variant &offset) {
    return call("stream_copy_to_stream", {from, to, length, offset});
}
Variant stream_get_contents(const Variant &stream, const Variant &length, const Variant &offset) {
    return call("stream_get_contents", {stream, length, offset});
}
Variant stream_supports_lock(const Variant &stream) {
    return call("stream_supports_lock", {stream});
}
Variant stream_set_write_buffer(const Variant &stream, const Variant &size) {
    return call("stream_set_write_buffer", {stream, size});
}
Variant set_file_buffer(const Variant &stream, const Variant &size) {
    return call("set_file_buffer", {stream, size});
}
Variant stream_set_read_buffer(const Variant &stream, const Variant &size) {
    return call("stream_set_read_buffer", {stream, size});
}
Variant stream_set_blocking(const Variant &stream, const Variant &enable) {
    return call("stream_set_blocking", {stream, enable});
}
Variant socket_set_blocking(const Variant &stream, const Variant &enable) {
    return call("socket_set_blocking", {stream, enable});
}
Variant stream_get_meta_data(const Variant &stream) {
    return call("stream_get_meta_data", {stream});
}
Variant socket_get_status(const Variant &stream) {
    return call("socket_get_status", {stream});
}
Variant stream_get_line(const Variant &stream, const Variant &length, const Variant &ending) {
    return call("stream_get_line", {stream, length, ending});
}
Variant stream_resolve_include_path(const Variant &filename) {
    return call("stream_resolve_include_path", {filename});
}
Variant stream_get_wrappers() {
    return call("stream_get_wrappers", {});
}
Variant stream_get_transports() {
    return call("stream_get_transports", {});
}
Variant stream_is_local(const Variant &stream) {
    return call("stream_is_local", {stream});
}
Variant stream_isatty(const Variant &stream) {
    return call("stream_isatty", {stream});
}
Variant stream_set_chunk_size(const Variant &stream, const Variant &size) {
    return call("stream_set_chunk_size", {stream, size});
}
Variant stream_set_timeout(const Variant &stream, const Variant &seconds, const Variant &microseconds) {
    return call("stream_set_timeout", {stream, seconds, microseconds});
}
Variant socket_set_timeout(const Variant &stream, const Variant &seconds, const Variant &microseconds) {
    return call("socket_set_timeout", {stream, seconds, microseconds});
}
Variant gettype(const Variant &value) {
    return call("gettype", {value});
}
Variant get_debug_type(const Variant &value) {
    return call("get_debug_type", {value});
}
Variant settype(const Reference &var, const Variant &type) {
    return call("settype", {&var, type});
}
Variant intval(const Variant &value, const Variant &base) {
    return call("intval", {value, base});
}
Variant floatval(const Variant &value) {
    return call("floatval", {value});
}
Variant doubleval(const Variant &value) {
    return call("doubleval", {value});
}
Variant boolval(const Variant &value) {
    return call("boolval", {value});
}
Variant strval(const Variant &value) {
    return call("strval", {value});
}
Variant is_null(const Variant &value) {
    return call("is_null", {value});
}
Variant is_resource(const Variant &value) {
    return call("is_resource", {value});
}
Variant is_bool(const Variant &value) {
    return call("is_bool", {value});
}
Variant is_int(const Variant &value) {
    return call("is_int", {value});
}
Variant is_integer(const Variant &value) {
    return call("is_integer", {value});
}
Variant is_long(const Variant &value) {
    return call("is_long", {value});
}
Variant is_float(const Variant &value) {
    return call("is_float", {value});
}
Variant is_double(const Variant &value) {
    return call("is_double", {value});
}
Variant is_numeric(const Variant &value) {
    return call("is_numeric", {value});
}
Variant is_string(const Variant &value) {
    return call("is_string", {value});
}
Variant is_array(const Variant &value) {
    return call("is_array", {value});
}
Variant is_object(const Variant &value) {
    return call("is_object", {value});
}
Variant is_scalar(const Variant &value) {
    return call("is_scalar", {value});
}
Variant is_callable(const Variant &value, const Variant &syntax_only, const Reference &callable_name) {
    return call("is_callable", {value, syntax_only, &callable_name});
}
Variant is_iterable(const Variant &value) {
    return call("is_iterable", {value});
}
Variant is_countable(const Variant &value) {
    return call("is_countable", {value});
}
Variant uniqid(const Variant &prefix, const Variant &more_entropy) {
    return call("uniqid", {prefix, more_entropy});
}
Variant parse_url(const Variant &url, const Variant &component) {
    return call("parse_url", {url, component});
}
Variant urlencode(const Variant &string) {
    return call("urlencode", {string});
}
Variant urldecode(const Variant &string) {
    return call("urldecode", {string});
}
Variant rawurlencode(const Variant &string) {
    return call("rawurlencode", {string});
}
Variant rawurldecode(const Variant &string) {
    return call("rawurldecode", {string});
}
Variant get_headers(const Variant &url, const Variant &associative, const Variant &context) {
    return call("get_headers", {url, associative, context});
}
Variant stream_bucket_make_writeable(const Variant &brigade) {
    return call("stream_bucket_make_writeable", {brigade});
}
Variant stream_bucket_prepend(const Variant &brigade, const Variant &bucket) {
    return call("stream_bucket_prepend", {brigade, bucket});
}
Variant stream_bucket_append(const Variant &brigade, const Variant &bucket) {
    return call("stream_bucket_append", {brigade, bucket});
}
Variant stream_bucket_new(const Variant &stream, const Variant &buffer) {
    return call("stream_bucket_new", {stream, buffer});
}
Variant stream_get_filters() {
    return call("stream_get_filters", {});
}
Variant stream_filter_register(const Variant &filter_name, const Variant &_class) {
    return call("stream_filter_register", {filter_name, _class});
}
Variant convert_uuencode(const Variant &string) {
    return call("convert_uuencode", {string});
}
Variant convert_uudecode(const Variant &string) {
    return call("convert_uudecode", {string});
}
Variant var_export(const Variant &value, const Variant &_return) {
    return call("var_export", {value, _return});
}
Variant serialize(const Variant &value) {
    return call("serialize", {value});
}
Variant unserialize(const Variant &data, const Variant &options) {
    return call("unserialize", {data, options});
}
Variant memory_get_usage(const Variant &real_usage) {
    return call("memory_get_usage", {real_usage});
}
Variant memory_get_peak_usage(const Variant &real_usage) {
    return call("memory_get_peak_usage", {real_usage});
}
Variant memory_reset_peak_usage() {
    return call("memory_reset_peak_usage", {});
}
Variant version_compare(const Variant &version1, const Variant &version2, const Variant &_operator) {
    return call("version_compare", {version1, version2, _operator});
}
Variant dl(const Variant &extension_filename) {
    return call("dl", {extension_filename});
}
Variant cli_set_process_title(const Variant &title) {
    return call("cli_set_process_title", {title});
}
Variant cli_get_process_title() {
    return call("cli_get_process_title", {});
}
}

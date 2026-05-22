#include "phpx.h"
#include "phpx_literal_string.h"
#include "phpx_class.h"

namespace php {
Variant set_time_limit(const Variant &seconds) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2076]);
    }
    return call(fn, {seconds});
}
Variant header_register_callback(const Variant &callback) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2077]);
    }
    return call(fn, {callback});
}
Variant ob_start(const Variant &callback, const Variant &chunk_size, const Variant &flags) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2078]);
    }
    return call(fn, {callback, chunk_size, flags});
}
Variant ob_flush() {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2079]);
    }
    return call(fn, {});
}
Variant ob_clean() {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2080]);
    }
    return call(fn, {});
}
Variant ob_end_flush() {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2081]);
    }
    return call(fn, {});
}
Variant ob_end_clean() {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2082]);
    }
    return call(fn, {});
}
Variant ob_get_flush() {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2083]);
    }
    return call(fn, {});
}
Variant ob_get_clean() {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2084]);
    }
    return call(fn, {});
}
Variant ob_get_contents() {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2085]);
    }
    return call(fn, {});
}
Variant ob_get_level() {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2086]);
    }
    return call(fn, {});
}
Variant ob_get_length() {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2087]);
    }
    return call(fn, {});
}
Variant ob_list_handlers() {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2088]);
    }
    return call(fn, {});
}
Variant ob_get_status(const Variant &full_status) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2089]);
    }
    return call(fn, {full_status});
}
Variant ob_implicit_flush(const Variant &enable) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2090]);
    }
    return call(fn, {enable});
}
Variant output_reset_rewrite_vars() {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2091]);
    }
    return call(fn, {});
}
Variant output_add_rewrite_var(const Variant &name, const Variant &value) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2092]);
    }
    return call(fn, {name, value});
}
Variant stream_wrapper_register(const Variant &protocol, const Variant &class_, const Variant &flags) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2093]);
    }
    return call(fn, {protocol, class_, flags});
}
Variant stream_register_wrapper(const Variant &protocol, const Variant &class_, const Variant &flags) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2094]);
    }
    return call(fn, {protocol, class_, flags});
}
Variant stream_wrapper_unregister(const Variant &protocol) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2095]);
    }
    return call(fn, {protocol});
}
Variant stream_wrapper_restore(const Variant &protocol) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2096]);
    }
    return call(fn, {protocol});
}
Variant krsort(const Reference &array, const Variant &flags) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2098]);
    }
    return call(fn, {&array, flags});
}
Variant ksort(const Reference &array, const Variant &flags) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[1939]);
    }
    return call(fn, {&array, flags});
}
Variant count(const Variant &value, const Variant &mode) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[140]);
    }
    return call(fn, {value, mode});
}
Variant natsort(const Reference &array) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[1942]);
    }
    return call(fn, {&array});
}
Variant natcasesort(const Reference &array) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[1943]);
    }
    return call(fn, {&array});
}
Variant asort(const Reference &array, const Variant &flags) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[1938]);
    }
    return call(fn, {&array, flags});
}
Variant arsort(const Reference &array, const Variant &flags) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2099]);
    }
    return call(fn, {&array, flags});
}
Variant sort(const Reference &array, const Variant &flags) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[1410]);
    }
    return call(fn, {&array, flags});
}
Variant rsort(const Reference &array, const Variant &flags) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2100]);
    }
    return call(fn, {&array, flags});
}
Variant usort(const Reference &array, const Variant &callback) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2101]);
    }
    return call(fn, {&array, callback});
}
Variant uasort(const Reference &array, const Variant &callback) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[1940]);
    }
    return call(fn, {&array, callback});
}
Variant uksort(const Reference &array, const Variant &callback) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[1941]);
    }
    return call(fn, {&array, callback});
}
Variant end(const Reference &array) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2102]);
    }
    return call(fn, {&array});
}
Variant prev(const Reference &array) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2014]);
    }
    return call(fn, {&array});
}
Variant next(const Reference &array) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[92]);
    }
    return call(fn, {&array});
}
Variant reset(const Reference &array) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[921]);
    }
    return call(fn, {&array});
}
Variant current(const Variant &array) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[90]);
    }
    return call(fn, {array});
}
Variant pos(const Variant &array) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2103]);
    }
    return call(fn, {array});
}
Variant key(const Variant &array) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[91]);
    }
    return call(fn, {array});
}
Variant array_walk(const Reference &array, const Variant &callback, const Variant &arg) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2106]);
    }
    return call(fn, {&array, callback, arg});
}
Variant array_walk_recursive(const Reference &array, const Variant &callback, const Variant &arg) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2107]);
    }
    return call(fn, {&array, callback, arg});
}
Variant in_array(const Variant &needle, const Variant &haystack, const Variant &strict) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2108]);
    }
    return call(fn, {needle, haystack, strict});
}
Variant array_search(const Variant &needle, const Variant &haystack, const Variant &strict) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2109]);
    }
    return call(fn, {needle, haystack, strict});
}
Variant extract(const Reference &array, const Variant &flags, const Variant &prefix) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2020]);
    }
    return call(fn, {&array, flags, prefix});
}
Variant array_fill(const Variant &start_index, const Variant &count, const Variant &value) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2111]);
    }
    return call(fn, {start_index, count, value});
}
Variant array_fill_keys(const Variant &keys, const Variant &value) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2112]);
    }
    return call(fn, {keys, value});
}
Variant range(const Variant &start, const Variant &end, const Variant &step) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2113]);
    }
    return call(fn, {start, end, step});
}
Variant shuffle(const Reference &array) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2114]);
    }
    return call(fn, {&array});
}
Variant array_pop(const Reference &array) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2115]);
    }
    return call(fn, {&array});
}
Variant array_shift(const Reference &array) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2116]);
    }
    return call(fn, {&array});
}
Variant array_splice(const Reference &array, const Variant &offset, const Variant &length, const Variant &replacement) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2118]);
    }
    return call(fn, {&array, offset, length, replacement});
}
Variant array_slice(const Variant &array, const Variant &offset, const Variant &length, const Variant &preserve_keys) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2119]);
    }
    return call(fn, {array, offset, length, preserve_keys});
}
Variant array_keys(const Variant &array, const Variant &filter_value, const Variant &strict) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2124]);
    }
    return call(fn, {array, filter_value, strict});
}
Variant array_key_first(const Variant &array) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2125]);
    }
    return call(fn, {array});
}
Variant array_key_last(const Variant &array) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2126]);
    }
    return call(fn, {array});
}
Variant array_values(const Variant &array) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2127]);
    }
    return call(fn, {array});
}
Variant array_count_values(const Variant &array) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2128]);
    }
    return call(fn, {array});
}
Variant array_column(const Variant &array, const Variant &column_key, const Variant &index_key) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2129]);
    }
    return call(fn, {array, column_key, index_key});
}
Variant array_reverse(const Variant &array, const Variant &preserve_keys) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2130]);
    }
    return call(fn, {array, preserve_keys});
}
Variant array_pad(const Variant &array, const Variant &length, const Variant &value) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2131]);
    }
    return call(fn, {array, length, value});
}
Variant array_flip(const Variant &array) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2132]);
    }
    return call(fn, {array});
}
Variant array_change_key_case(const Variant &array, const Variant &case_) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2133]);
    }
    return call(fn, {array, case_});
}
Variant array_unique(const Variant &array, const Variant &flags) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2134]);
    }
    return call(fn, {array, flags});
}
Variant array_rand(const Variant &array, const Variant &num) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2152]);
    }
    return call(fn, {array, num});
}
Variant array_sum(const Variant &array) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2153]);
    }
    return call(fn, {array});
}
Variant array_product(const Variant &array) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2154]);
    }
    return call(fn, {array});
}
Variant array_reduce(const Variant &array, const Variant &callback, const Variant &initial) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2155]);
    }
    return call(fn, {array, callback, initial});
}
Variant array_filter(const Variant &array, const Variant &callback, const Variant &mode) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2156]);
    }
    return call(fn, {array, callback, mode});
}
Variant array_find(const Variant &array, const Variant &callback) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2157]);
    }
    return call(fn, {array, callback});
}
Variant array_find_key(const Variant &array, const Variant &callback) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2158]);
    }
    return call(fn, {array, callback});
}
Variant array_any(const Variant &array, const Variant &callback) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2159]);
    }
    return call(fn, {array, callback});
}
Variant array_all(const Variant &array, const Variant &callback) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2160]);
    }
    return call(fn, {array, callback});
}
Variant array_key_exists(const Variant &key, const Variant &array) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2162]);
    }
    return call(fn, {key, array});
}
Variant key_exists(const Variant &key, const Variant &array) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2163]);
    }
    return call(fn, {key, array});
}
Variant array_chunk(const Variant &array, const Variant &length, const Variant &preserve_keys) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2164]);
    }
    return call(fn, {array, length, preserve_keys});
}
Variant array_combine(const Variant &keys, const Variant &values) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2165]);
    }
    return call(fn, {keys, values});
}
Variant array_is_list(const Variant &array) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2166]);
    }
    return call(fn, {array});
}
Variant base64_encode(const Variant &string) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2167]);
    }
    return call(fn, {string});
}
Variant base64_decode(const Variant &string, const Variant &strict) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2168]);
    }
    return call(fn, {string, strict});
}
Variant ip2long(const Variant &ip) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2169]);
    }
    return call(fn, {ip});
}
Variant long2ip(const Variant &ip) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2170]);
    }
    return call(fn, {ip});
}
Variant getenv(const Variant &name, const Variant &local_only) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2171]);
    }
    return call(fn, {name, local_only});
}
Variant putenv(const Variant &assignment) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2172]);
    }
    return call(fn, {assignment});
}
Variant getopt(const Variant &short_options, const Variant &long_options, const Reference &rest_index) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2173]);
    }
    return call(fn, {short_options, long_options, &rest_index});
}
Variant flush() {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2174]);
    }
    return call(fn, {});
}
Variant sleep(const Variant &seconds) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2175]);
    }
    return call(fn, {seconds});
}
Variant usleep(const Variant &microseconds) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2176]);
    }
    return call(fn, {microseconds});
}
Variant time_nanosleep(const Variant &seconds, const Variant &nanoseconds) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2177]);
    }
    return call(fn, {seconds, nanoseconds});
}
Variant time_sleep_until(const Variant &timestamp) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2178]);
    }
    return call(fn, {timestamp});
}
Variant get_current_user() {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2179]);
    }
    return call(fn, {});
}
Variant get_cfg_var(const Variant &option) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2180]);
    }
    return call(fn, {option});
}
Variant error_log(const Variant &message,
                  const Variant &message_type,
                  const Variant &destination,
                  const Variant &additional_headers) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2181]);
    }
    return call(fn, {message, message_type, destination, additional_headers});
}
Variant error_get_last() {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2182]);
    }
    return call(fn, {});
}
Variant error_clear_last() {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2183]);
    }
    return call(fn, {});
}
Variant call_user_func_array(const Variant &callback, const Variant &args) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2185]);
    }
    return call(fn, {callback, args});
}
Variant forward_static_call_array(const Variant &callback, const Variant &args) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2187]);
    }
    return call(fn, {callback, args});
}
Variant highlight_file(const Variant &filename, const Variant &return_) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2189]);
    }
    return call(fn, {filename, return_});
}
Variant show_source(const Variant &filename, const Variant &return_) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2190]);
    }
    return call(fn, {filename, return_});
}
Variant php_strip_whitespace(const Variant &filename) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2191]);
    }
    return call(fn, {filename});
}
Variant highlight_string(const Variant &string, const Variant &return_) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2192]);
    }
    return call(fn, {string, return_});
}
Variant ini_get(const Variant &option) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2193]);
    }
    return call(fn, {option});
}
Variant ini_get_all(const Variant &extension, const Variant &details) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2194]);
    }
    return call(fn, {extension, details});
}
Variant ini_set(const Variant &option, const Variant &value) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2195]);
    }
    return call(fn, {option, value});
}
Variant ini_alter(const Variant &option, const Variant &value) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2196]);
    }
    return call(fn, {option, value});
}
Variant ini_restore(const Variant &option) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2197]);
    }
    return call(fn, {option});
}
Variant ini_parse_quantity(const Variant &shorthand) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2198]);
    }
    return call(fn, {shorthand});
}
Variant set_include_path(const Variant &include_path) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2199]);
    }
    return call(fn, {include_path});
}
Variant get_include_path() {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2200]);
    }
    return call(fn, {});
}
Variant print_r(const Variant &value, const Variant &return_) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2201]);
    }
    return call(fn, {value, return_});
}
Variant connection_aborted() {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2202]);
    }
    return call(fn, {});
}
Variant connection_status() {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2203]);
    }
    return call(fn, {});
}
Variant ignore_user_abort(const Variant &enable) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2204]);
    }
    return call(fn, {enable});
}
Variant getservbyname(const Variant &service, const Variant &protocol) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2205]);
    }
    return call(fn, {service, protocol});
}
Variant getservbyport(const Variant &port, const Variant &protocol) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2206]);
    }
    return call(fn, {port, protocol});
}
Variant getprotobyname(const Variant &protocol) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2207]);
    }
    return call(fn, {protocol});
}
Variant getprotobynumber(const Variant &protocol) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2208]);
    }
    return call(fn, {protocol});
}
Variant unregister_tick_function(const Variant &callback) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2210]);
    }
    return call(fn, {callback});
}
Variant is_uploaded_file(const Variant &filename) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2211]);
    }
    return call(fn, {filename});
}
Variant move_uploaded_file(const Variant &from, const Variant &to) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2212]);
    }
    return call(fn, {from, to});
}
Variant parse_ini_file(const Variant &filename, const Variant &process_sections, const Variant &scanner_mode) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2213]);
    }
    return call(fn, {filename, process_sections, scanner_mode});
}
Variant parse_ini_string(const Variant &ini_string, const Variant &process_sections, const Variant &scanner_mode) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2214]);
    }
    return call(fn, {ini_string, process_sections, scanner_mode});
}
Variant config_get_hash() {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2215]);
    }
    return call(fn, {});
}
Variant sys_getloadavg() {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2216]);
    }
    return call(fn, {});
}
Variant get_browser(const Variant &user_agent, const Variant &return_array) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2217]);
    }
    return call(fn, {user_agent, return_array});
}
Variant crc32(const Variant &string) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2218]);
    }
    return call(fn, {string});
}
Variant crypt(const Variant &string, const Variant &salt) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2219]);
    }
    return call(fn, {string, salt});
}
Variant strptime(const Variant &timestamp, const Variant &format) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2220]);
    }
    return call(fn, {timestamp, format});
}
Variant gethostname() {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2221]);
    }
    return call(fn, {});
}
Variant gethostbyaddr(const Variant &ip) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2222]);
    }
    return call(fn, {ip});
}
Variant gethostbyname(const Variant &hostname) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2223]);
    }
    return call(fn, {hostname});
}
Variant gethostbynamel(const Variant &hostname) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2224]);
    }
    return call(fn, {hostname});
}
Variant dns_check_record(const Variant &hostname, const Variant &type) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2225]);
    }
    return call(fn, {hostname, type});
}
Variant checkdnsrr(const Variant &hostname, const Variant &type) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2226]);
    }
    return call(fn, {hostname, type});
}
Variant dns_get_record(const Variant &hostname,
                       const Variant &type,
                       const Reference &authoritative_name_servers,
                       const Reference &additional_records,
                       const Variant &raw) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2227]);
    }
    return call(fn, {hostname, type, &authoritative_name_servers, &additional_records, raw});
}
Variant dns_get_mx(const Variant &hostname, const Reference &hosts, const Reference &weights) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2228]);
    }
    return call(fn, {hostname, &hosts, &weights});
}
Variant getmxrr(const Variant &hostname, const Reference &hosts, const Reference &weights) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2229]);
    }
    return call(fn, {hostname, &hosts, &weights});
}
Variant net_get_interfaces() {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2230]);
    }
    return call(fn, {});
}
Variant ftok(const Variant &filename, const Variant &project_id) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2231]);
    }
    return call(fn, {filename, project_id});
}
Variant hrtime(const Variant &as_number) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2232]);
    }
    return call(fn, {as_number});
}
Variant md5(const Variant &string, const Variant &binary) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2233]);
    }
    return call(fn, {string, binary});
}
Variant md5_file(const Variant &filename, const Variant &binary) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2234]);
    }
    return call(fn, {filename, binary});
}
Variant getmyuid() {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2235]);
    }
    return call(fn, {});
}
Variant getmygid() {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2236]);
    }
    return call(fn, {});
}
Variant getmypid() {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2237]);
    }
    return call(fn, {});
}
Variant getmyinode() {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2238]);
    }
    return call(fn, {});
}
Variant getlastmod() {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2239]);
    }
    return call(fn, {});
}
Variant sha1(const Variant &string, const Variant &binary) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2240]);
    }
    return call(fn, {string, binary});
}
Variant sha1_file(const Variant &filename, const Variant &binary) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2241]);
    }
    return call(fn, {filename, binary});
}
Variant openlog(const Variant &prefix, const Variant &flags, const Variant &facility) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2242]);
    }
    return call(fn, {prefix, flags, facility});
}
Variant closelog() {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2243]);
    }
    return call(fn, {});
}
Variant syslog(const Variant &priority, const Variant &message) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2244]);
    }
    return call(fn, {priority, message});
}
Variant inet_ntop(const Variant &ip) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2245]);
    }
    return call(fn, {ip});
}
Variant inet_pton(const Variant &ip) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2246]);
    }
    return call(fn, {ip});
}
Variant metaphone(const Variant &string, const Variant &max_phonemes) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2247]);
    }
    return call(fn, {string, max_phonemes});
}
Variant header(const Variant &header, const Variant &replace, const Variant &response_code) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2248]);
    }
    return call(fn, {header, replace, response_code});
}
Variant header_remove(const Variant &name) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2249]);
    }
    return call(fn, {name});
}
Variant setrawcookie(const Variant &name,
                     const Variant &value,
                     const Variant &expires_or_options,
                     const Variant &path,
                     const Variant &domain,
                     const Variant &secure,
                     const Variant &httponly) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2250]);
    }
    return call(fn, {name, value, expires_or_options, path, domain, secure, httponly});
}
Variant setcookie(const Variant &name,
                  const Variant &value,
                  const Variant &expires_or_options,
                  const Variant &path,
                  const Variant &domain,
                  const Variant &secure,
                  const Variant &httponly) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2251]);
    }
    return call(fn, {name, value, expires_or_options, path, domain, secure, httponly});
}
Variant http_response_code(const Variant &response_code) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2252]);
    }
    return call(fn, {response_code});
}
Variant headers_sent(const Reference &filename, const Reference &line) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2253]);
    }
    return call(fn, {&filename, &line});
}
Variant headers_list() {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2254]);
    }
    return call(fn, {});
}
Variant htmlspecialchars(const Variant &string,
                         const Variant &flags,
                         const Variant &encoding,
                         const Variant &double_encode) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2255]);
    }
    return call(fn, {string, flags, encoding, double_encode});
}
Variant htmlspecialchars_decode(const Variant &string, const Variant &flags) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2256]);
    }
    return call(fn, {string, flags});
}
Variant html_entity_decode(const Variant &string, const Variant &flags, const Variant &encoding) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2257]);
    }
    return call(fn, {string, flags, encoding});
}
Variant htmlentities(const Variant &string,
                     const Variant &flags,
                     const Variant &encoding,
                     const Variant &double_encode) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2258]);
    }
    return call(fn, {string, flags, encoding, double_encode});
}
Variant get_html_translation_table(const Variant &table, const Variant &flags, const Variant &encoding) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2259]);
    }
    return call(fn, {table, flags, encoding});
}
Variant assert_options(const Variant &option, const Variant &value) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2260]);
    }
    return call(fn, {option, value});
}
Variant bin2hex(const Variant &string) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2261]);
    }
    return call(fn, {string});
}
Variant hex2bin(const Variant &string) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2262]);
    }
    return call(fn, {string});
}
Variant strspn(const Variant &string, const Variant &characters, const Variant &offset, const Variant &length) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2263]);
    }
    return call(fn, {string, characters, offset, length});
}
Variant strcspn(const Variant &string, const Variant &characters, const Variant &offset, const Variant &length) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2264]);
    }
    return call(fn, {string, characters, offset, length});
}
Variant nl_langinfo(const Variant &item) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2265]);
    }
    return call(fn, {item});
}
Variant strcoll(const Variant &string1, const Variant &string2) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2266]);
    }
    return call(fn, {string1, string2});
}
Variant trim(const Variant &string, const Variant &characters) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2267]);
    }
    return call(fn, {string, characters});
}
Variant rtrim(const Variant &string, const Variant &characters) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2268]);
    }
    return call(fn, {string, characters});
}
Variant chop(const Variant &string, const Variant &characters) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2269]);
    }
    return call(fn, {string, characters});
}
Variant ltrim(const Variant &string, const Variant &characters) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[1350]);
    }
    return call(fn, {string, characters});
}
Variant wordwrap(const Variant &string, const Variant &width, const Variant &break_, const Variant &cut_long_words) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2270]);
    }
    return call(fn, {string, width, break_, cut_long_words});
}
Variant explode(const Variant &separator, const Variant &string, const Variant &limit) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2271]);
    }
    return call(fn, {separator, string, limit});
}
Variant implode(const Variant &separator, const Variant &array) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2272]);
    }
    return call(fn, {separator, array});
}
Variant join(const Variant &separator, const Variant &array) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2273]);
    }
    return call(fn, {separator, array});
}
Variant strtok(const Variant &string, const Variant &token) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2274]);
    }
    return call(fn, {string, token});
}
Variant strtoupper(const Variant &string) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2275]);
    }
    return call(fn, {string});
}
Variant strtolower(const Variant &string) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2276]);
    }
    return call(fn, {string});
}
Variant str_increment(const Variant &string) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2277]);
    }
    return call(fn, {string});
}
Variant str_decrement(const Variant &string) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2278]);
    }
    return call(fn, {string});
}
Variant basename(const Variant &path, const Variant &suffix) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2279]);
    }
    return call(fn, {path, suffix});
}
Variant dirname(const Variant &path, const Variant &levels) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2280]);
    }
    return call(fn, {path, levels});
}
Variant pathinfo(const Variant &path, const Variant &flags) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2281]);
    }
    return call(fn, {path, flags});
}
Variant stristr(const Variant &haystack, const Variant &needle, const Variant &before_needle) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2282]);
    }
    return call(fn, {haystack, needle, before_needle});
}
Variant strstr(const Variant &haystack, const Variant &needle, const Variant &before_needle) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2283]);
    }
    return call(fn, {haystack, needle, before_needle});
}
Variant strchr(const Variant &haystack, const Variant &needle, const Variant &before_needle) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2284]);
    }
    return call(fn, {haystack, needle, before_needle});
}
Variant strpos(const Variant &haystack, const Variant &needle, const Variant &offset) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2285]);
    }
    return call(fn, {haystack, needle, offset});
}
Variant stripos(const Variant &haystack, const Variant &needle, const Variant &offset) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2286]);
    }
    return call(fn, {haystack, needle, offset});
}
Variant strrpos(const Variant &haystack, const Variant &needle, const Variant &offset) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2287]);
    }
    return call(fn, {haystack, needle, offset});
}
Variant strripos(const Variant &haystack, const Variant &needle, const Variant &offset) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2288]);
    }
    return call(fn, {haystack, needle, offset});
}
Variant strrchr(const Variant &haystack, const Variant &needle, const Variant &before_needle) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2289]);
    }
    return call(fn, {haystack, needle, before_needle});
}
Variant str_contains(const Variant &haystack, const Variant &needle) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2290]);
    }
    return call(fn, {haystack, needle});
}
Variant str_starts_with(const Variant &haystack, const Variant &needle) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2291]);
    }
    return call(fn, {haystack, needle});
}
Variant str_ends_with(const Variant &haystack, const Variant &needle) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2292]);
    }
    return call(fn, {haystack, needle});
}
Variant chunk_split(const Variant &string, const Variant &length, const Variant &separator) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2293]);
    }
    return call(fn, {string, length, separator});
}
Variant substr(const Variant &string, const Variant &offset, const Variant &length) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2294]);
    }
    return call(fn, {string, offset, length});
}
Variant substr_replace(const Variant &string, const Variant &replace, const Variant &offset, const Variant &length) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2295]);
    }
    return call(fn, {string, replace, offset, length});
}
Variant quotemeta(const Variant &string) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2296]);
    }
    return call(fn, {string});
}
Variant ord(const Variant &character) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2297]);
    }
    return call(fn, {character});
}
Variant chr(const Variant &codepoint) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2298]);
    }
    return call(fn, {codepoint});
}
Variant ucfirst(const Variant &string) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2299]);
    }
    return call(fn, {string});
}
Variant lcfirst(const Variant &string) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2300]);
    }
    return call(fn, {string});
}
Variant ucwords(const Variant &string, const Variant &separators) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2301]);
    }
    return call(fn, {string, separators});
}
Variant strtr(const Variant &string, const Variant &from, const Variant &to) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2302]);
    }
    return call(fn, {string, from, to});
}
Variant strrev(const Variant &string) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2303]);
    }
    return call(fn, {string});
}
Variant similar_text(const Variant &string1, const Variant &string2, const Reference &percent) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2304]);
    }
    return call(fn, {string1, string2, &percent});
}
Variant addcslashes(const Variant &string, const Variant &characters) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2305]);
    }
    return call(fn, {string, characters});
}
Variant addslashes(const Variant &string) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2306]);
    }
    return call(fn, {string});
}
Variant stripcslashes(const Variant &string) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2307]);
    }
    return call(fn, {string});
}
Variant stripslashes(const Variant &string) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2308]);
    }
    return call(fn, {string});
}
Variant str_replace(const Variant &search, const Variant &replace, const Variant &subject, const Reference &count) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2309]);
    }
    return call(fn, {search, replace, subject, &count});
}
Variant str_ireplace(const Variant &search, const Variant &replace, const Variant &subject, const Reference &count) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2310]);
    }
    return call(fn, {search, replace, subject, &count});
}
Variant hebrev(const Variant &string, const Variant &max_chars_per_line) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2311]);
    }
    return call(fn, {string, max_chars_per_line});
}
Variant nl2br(const Variant &string, const Variant &use_xhtml) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2312]);
    }
    return call(fn, {string, use_xhtml});
}
Variant strip_tags(const Variant &string, const Variant &allowed_tags) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2313]);
    }
    return call(fn, {string, allowed_tags});
}
Variant parse_str(const Variant &string, const Reference &result) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2315]);
    }
    return call(fn, {string, &result});
}
Variant str_getcsv(const Variant &string, const Variant &separator, const Variant &enclosure, const Variant &escape) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2316]);
    }
    return call(fn, {string, separator, enclosure, escape});
}
Variant str_repeat(const Variant &string, const Variant &times) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2317]);
    }
    return call(fn, {string, times});
}
Variant count_chars(const Variant &string, const Variant &mode) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2318]);
    }
    return call(fn, {string, mode});
}
Variant localeconv() {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2319]);
    }
    return call(fn, {});
}
Variant substr_count(const Variant &haystack, const Variant &needle, const Variant &offset, const Variant &length) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2320]);
    }
    return call(fn, {haystack, needle, offset, length});
}
Variant str_pad(const Variant &string, const Variant &length, const Variant &pad_string, const Variant &pad_type) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2321]);
    }
    return call(fn, {string, length, pad_string, pad_type});
}
Variant str_rot13(const Variant &string) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2323]);
    }
    return call(fn, {string});
}
Variant str_shuffle(const Variant &string) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2324]);
    }
    return call(fn, {string});
}
Variant str_word_count(const Variant &string, const Variant &format, const Variant &characters) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2325]);
    }
    return call(fn, {string, format, characters});
}
Variant str_split(const Variant &string, const Variant &length) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2326]);
    }
    return call(fn, {string, length});
}
Variant strpbrk(const Variant &string, const Variant &characters) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2327]);
    }
    return call(fn, {string, characters});
}
Variant substr_compare(const Variant &haystack,
                       const Variant &needle,
                       const Variant &offset,
                       const Variant &length,
                       const Variant &case_insensitive) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2328]);
    }
    return call(fn, {haystack, needle, offset, length, case_insensitive});
}
Variant utf8_encode(const Variant &string) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2329]);
    }
    return call(fn, {string});
}
Variant utf8_decode(const Variant &string) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2330]);
    }
    return call(fn, {string});
}
Variant opendir(const Variant &directory, const Variant &context) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2331]);
    }
    return call(fn, {directory, context});
}
Directory dir(const Variant &directory, const Variant &context) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2332]);
    }
    auto _rv = call(fn, {directory, context});
    if (!_rv.toBool()) {
        throwException(String("RuntimeException"), "dir() returned false");
    }
    return Directory(Object(std::move(_rv)));
}
Variant closedir(const Variant &dir_handle) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2333]);
    }
    return call(fn, {dir_handle});
}
Variant chdir(const Variant &directory) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2334]);
    }
    return call(fn, {directory});
}
Variant getcwd() {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2335]);
    }
    return call(fn, {});
}
Variant rewinddir(const Variant &dir_handle) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2336]);
    }
    return call(fn, {dir_handle});
}
Variant readdir(const Variant &dir_handle) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2337]);
    }
    return call(fn, {dir_handle});
}
Variant scandir(const Variant &directory, const Variant &sorting_order, const Variant &context) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2338]);
    }
    return call(fn, {directory, sorting_order, context});
}
Variant glob(const Variant &pattern, const Variant &flags) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2339]);
    }
    return call(fn, {pattern, flags});
}
Variant exec(const Variant &command, const Reference &output, const Reference &result_code) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[1039]);
    }
    return call(fn, {command, &output, &result_code});
}
Variant system(const Variant &command, const Reference &result_code) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2340]);
    }
    return call(fn, {command, &result_code});
}
Variant passthru(const Variant &command, const Reference &result_code) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2341]);
    }
    return call(fn, {command, &result_code});
}
Variant escapeshellcmd(const Variant &command) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2342]);
    }
    return call(fn, {command});
}
Variant escapeshellarg(const Variant &arg) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2343]);
    }
    return call(fn, {arg});
}
Variant shell_exec(const Variant &command) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2344]);
    }
    return call(fn, {command});
}
Variant proc_nice(const Variant &priority) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2345]);
    }
    return call(fn, {priority});
}
Variant flock(const Variant &stream, const Variant &operation, const Reference &would_block) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[1990]);
    }
    return call(fn, {stream, operation, &would_block});
}
Variant get_meta_tags(const Variant &filename, const Variant &use_include_path) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2346]);
    }
    return call(fn, {filename, use_include_path});
}
Variant pclose(const Variant &handle) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2347]);
    }
    return call(fn, {handle});
}
Variant popen(const Variant &command, const Variant &mode) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[1367]);
    }
    return call(fn, {command, mode});
}
Variant readfile(const Variant &filename, const Variant &use_include_path, const Variant &context) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2348]);
    }
    return call(fn, {filename, use_include_path, context});
}
Variant rewind(const Variant &stream) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[94]);
    }
    return call(fn, {stream});
}
Variant rmdir(const Variant &directory, const Variant &context) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2349]);
    }
    return call(fn, {directory, context});
}
Variant umask(const Variant &mask) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2350]);
    }
    return call(fn, {mask});
}
Variant fclose(const Variant &stream) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2351]);
    }
    return call(fn, {stream});
}
Variant feof(const Variant &stream) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2352]);
    }
    return call(fn, {stream});
}
Variant fgetc(const Variant &stream) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[1994]);
    }
    return call(fn, {stream});
}
Variant fgets(const Variant &stream, const Variant &length) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[1984]);
    }
    return call(fn, {stream, length});
}
Variant fread(const Variant &stream, const Variant &length) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[1985]);
    }
    return call(fn, {stream, length});
}
Variant fopen(const Variant &filename, const Variant &mode, const Variant &use_include_path, const Variant &context) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2353]);
    }
    return call(fn, {filename, mode, use_include_path, context});
}
Variant fpassthru(const Variant &stream) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[1995]);
    }
    return call(fn, {stream});
}
Variant ftruncate(const Variant &stream, const Variant &size) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[1999]);
    }
    return call(fn, {stream, size});
}
Variant fstat(const Variant &stream) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[1998]);
    }
    return call(fn, {stream});
}
Variant fseek(const Variant &stream, const Variant &offset, const Variant &whence) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[1993]);
    }
    return call(fn, {stream, offset, whence});
}
Variant ftell(const Variant &stream) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[1992]);
    }
    return call(fn, {stream});
}
Variant fflush(const Variant &stream) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[1991]);
    }
    return call(fn, {stream});
}
Variant fsync(const Variant &stream) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2354]);
    }
    return call(fn, {stream});
}
Variant fdatasync(const Variant &stream) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2355]);
    }
    return call(fn, {stream});
}
Variant fwrite(const Variant &stream, const Variant &data, const Variant &length) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[1997]);
    }
    return call(fn, {stream, data, length});
}
Variant fputs(const Variant &stream, const Variant &data, const Variant &length) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2356]);
    }
    return call(fn, {stream, data, length});
}
Variant mkdir(const Variant &directory, const Variant &permissions, const Variant &recursive, const Variant &context) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2357]);
    }
    return call(fn, {directory, permissions, recursive, context});
}
Variant rename(const Variant &from, const Variant &to, const Variant &context) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[454]);
    }
    return call(fn, {from, to, context});
}
Variant copy(const Variant &from, const Variant &to, const Variant &context) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[1081]);
    }
    return call(fn, {from, to, context});
}
Variant tempnam(const Variant &directory, const Variant &prefix) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2358]);
    }
    return call(fn, {directory, prefix});
}
Variant tmpfile() {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2359]);
    }
    return call(fn, {});
}
Variant file(const Variant &filename, const Variant &flags, const Variant &context) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[526]);
    }
    return call(fn, {filename, flags, context});
}
Variant file_get_contents(const Variant &filename,
                          const Variant &use_include_path,
                          const Variant &context,
                          const Variant &offset,
                          const Variant &length) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2360]);
    }
    return call(fn, {filename, use_include_path, context, offset, length});
}
Variant unlink(const Variant &filename, const Variant &context) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[1425]);
    }
    return call(fn, {filename, context});
}
Variant file_put_contents(const Variant &filename, const Variant &data, const Variant &flags, const Variant &context) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2361]);
    }
    return call(fn, {filename, data, flags, context});
}
Variant fputcsv(const Variant &stream,
                const Variant &fields,
                const Variant &separator,
                const Variant &enclosure,
                const Variant &escape,
                const Variant &eol) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[1987]);
    }
    return call(fn, {stream, fields, separator, enclosure, escape, eol});
}
Variant fgetcsv(const Variant &stream,
                const Variant &length,
                const Variant &separator,
                const Variant &enclosure,
                const Variant &escape) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[1986]);
    }
    return call(fn, {stream, length, separator, enclosure, escape});
}
Variant realpath(const Variant &path) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2362]);
    }
    return call(fn, {path});
}
Variant fnmatch(const Variant &pattern, const Variant &filename, const Variant &flags) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2363]);
    }
    return call(fn, {pattern, filename, flags});
}
Variant sys_get_temp_dir() {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2364]);
    }
    return call(fn, {});
}
Variant fileatime(const Variant &filename) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2365]);
    }
    return call(fn, {filename});
}
Variant filectime(const Variant &filename) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2366]);
    }
    return call(fn, {filename});
}
Variant filegroup(const Variant &filename) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2367]);
    }
    return call(fn, {filename});
}
Variant fileinode(const Variant &filename) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2368]);
    }
    return call(fn, {filename});
}
Variant filemtime(const Variant &filename) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2369]);
    }
    return call(fn, {filename});
}
Variant fileowner(const Variant &filename) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2370]);
    }
    return call(fn, {filename});
}
Variant fileperms(const Variant &filename) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2371]);
    }
    return call(fn, {filename});
}
Variant filesize(const Variant &filename) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2372]);
    }
    return call(fn, {filename});
}
Variant filetype(const Variant &filename) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2373]);
    }
    return call(fn, {filename});
}
Variant file_exists(const Variant &filename) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2374]);
    }
    return call(fn, {filename});
}
Variant is_writable(const Variant &filename) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2375]);
    }
    return call(fn, {filename});
}
Variant is_writeable(const Variant &filename) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2376]);
    }
    return call(fn, {filename});
}
Variant is_readable(const Variant &filename) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2377]);
    }
    return call(fn, {filename});
}
Variant is_executable(const Variant &filename) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2378]);
    }
    return call(fn, {filename});
}
Variant is_file(const Variant &filename) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2379]);
    }
    return call(fn, {filename});
}
Variant is_dir(const Variant &filename) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2380]);
    }
    return call(fn, {filename});
}
Variant is_link(const Variant &filename) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2381]);
    }
    return call(fn, {filename});
}
Variant stat(const Variant &filename) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[890]);
    }
    return call(fn, {filename});
}
Variant lstat(const Variant &filename) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2382]);
    }
    return call(fn, {filename});
}
Variant chown(const Variant &filename, const Variant &user) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2383]);
    }
    return call(fn, {filename, user});
}
Variant chgrp(const Variant &filename, const Variant &group) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2384]);
    }
    return call(fn, {filename, group});
}
Variant lchown(const Variant &filename, const Variant &user) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2385]);
    }
    return call(fn, {filename, user});
}
Variant lchgrp(const Variant &filename, const Variant &group) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2386]);
    }
    return call(fn, {filename, group});
}
Variant chmod(const Variant &filename, const Variant &permissions) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[1151]);
    }
    return call(fn, {filename, permissions});
}
Variant touch(const Variant &filename, const Variant &mtime, const Variant &atime) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[1408]);
    }
    return call(fn, {filename, mtime, atime});
}
Variant clearstatcache(const Variant &clear_realpath_cache, const Variant &filename) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2387]);
    }
    return call(fn, {clear_realpath_cache, filename});
}
Variant disk_total_space(const Variant &directory) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2388]);
    }
    return call(fn, {directory});
}
Variant disk_free_space(const Variant &directory) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2389]);
    }
    return call(fn, {directory});
}
Variant diskfreespace(const Variant &directory) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2390]);
    }
    return call(fn, {directory});
}
Variant realpath_cache_get() {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2391]);
    }
    return call(fn, {});
}
Variant realpath_cache_size() {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2392]);
    }
    return call(fn, {});
}
Variant vprintf(const Variant &format, const Variant &values) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2395]);
    }
    return call(fn, {format, values});
}
Variant vsprintf(const Variant &format, const Variant &values) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2396]);
    }
    return call(fn, {format, values});
}
Variant vfprintf(const Variant &stream, const Variant &format, const Variant &values) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2398]);
    }
    return call(fn, {stream, format, values});
}
Variant fsockopen(const Variant &hostname,
                  const Variant &port,
                  const Reference &error_code,
                  const Reference &error_message,
                  const Variant &timeout) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2399]);
    }
    return call(fn, {hostname, port, &error_code, &error_message, timeout});
}
Variant pfsockopen(const Variant &hostname,
                   const Variant &port,
                   const Reference &error_code,
                   const Reference &error_message,
                   const Variant &timeout) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2400]);
    }
    return call(fn, {hostname, port, &error_code, &error_message, timeout});
}
Variant http_build_query(const Variant &data,
                         const Variant &numeric_prefix,
                         const Variant &arg_separator,
                         const Variant &encoding_type) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2401]);
    }
    return call(fn, {data, numeric_prefix, arg_separator, encoding_type});
}
Variant http_get_last_response_headers() {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2402]);
    }
    return call(fn, {});
}
Variant http_clear_last_response_headers() {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2403]);
    }
    return call(fn, {});
}
Variant request_parse_body(const Variant &options) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2404]);
    }
    return call(fn, {options});
}
Variant image_type_to_mime_type(const Variant &image_type) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2405]);
    }
    return call(fn, {image_type});
}
Variant image_type_to_extension(const Variant &image_type, const Variant &include_dot) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2406]);
    }
    return call(fn, {image_type, include_dot});
}
Variant getimagesize(const Variant &filename, const Reference &image_info) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2407]);
    }
    return call(fn, {filename, &image_info});
}
Variant getimagesizefromstring(const Variant &string, const Reference &image_info) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2408]);
    }
    return call(fn, {string, &image_info});
}
Variant phpinfo(const Variant &flags) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2409]);
    }
    return call(fn, {flags});
}
Variant phpversion(const Variant &extension) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2410]);
    }
    return call(fn, {extension});
}
Variant phpcredits(const Variant &flags) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2411]);
    }
    return call(fn, {flags});
}
Variant php_sapi_name() {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2412]);
    }
    return call(fn, {});
}
Variant php_uname(const Variant &mode) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2413]);
    }
    return call(fn, {mode});
}
Variant php_ini_scanned_files() {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2414]);
    }
    return call(fn, {});
}
Variant php_ini_loaded_file() {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2415]);
    }
    return call(fn, {});
}
Variant iptcembed(const Variant &iptc_data, const Variant &filename, const Variant &spool) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2416]);
    }
    return call(fn, {iptc_data, filename, spool});
}
Variant iptcparse(const Variant &iptc_block) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2417]);
    }
    return call(fn, {iptc_block});
}
Variant levenshtein(const Variant &string1,
                    const Variant &string2,
                    const Variant &insertion_cost,
                    const Variant &replacement_cost,
                    const Variant &deletion_cost) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2418]);
    }
    return call(fn, {string1, string2, insertion_cost, replacement_cost, deletion_cost});
}
Variant readlink(const Variant &path) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2419]);
    }
    return call(fn, {path});
}
Variant linkinfo(const Variant &path) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2420]);
    }
    return call(fn, {path});
}
Variant symlink(const Variant &target, const Variant &link) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2421]);
    }
    return call(fn, {target, link});
}
Variant link(const Variant &target, const Variant &link) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2422]);
    }
    return call(fn, {target, link});
}
Variant mail(const Variant &to,
             const Variant &subject,
             const Variant &message,
             const Variant &additional_headers,
             const Variant &additional_params) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2423]);
    }
    return call(fn, {to, subject, message, additional_headers, additional_params});
}
Variant abs(const Variant &num) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2424]);
    }
    return call(fn, {num});
}
Variant ceil(const Variant &num) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[26]);
    }
    return call(fn, {num});
}
Variant floor(const Variant &num) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[25]);
    }
    return call(fn, {num});
}
Variant round(const Variant &num, const Variant &precision, const Variant &mode) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[27]);
    }
    return call(fn, {num, precision, mode});
}
Variant sin(const Variant &num) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2425]);
    }
    return call(fn, {num});
}
Variant cos(const Variant &num) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2426]);
    }
    return call(fn, {num});
}
Variant tan(const Variant &num) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2427]);
    }
    return call(fn, {num});
}
Variant asin(const Variant &num) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2428]);
    }
    return call(fn, {num});
}
Variant acos(const Variant &num) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2429]);
    }
    return call(fn, {num});
}
Variant atan(const Variant &num) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2430]);
    }
    return call(fn, {num});
}
Variant atanh(const Variant &num) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2431]);
    }
    return call(fn, {num});
}
Variant atan2(const Variant &y, const Variant &x) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2432]);
    }
    return call(fn, {y, x});
}
Variant sinh(const Variant &num) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2433]);
    }
    return call(fn, {num});
}
Variant cosh(const Variant &num) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2434]);
    }
    return call(fn, {num});
}
Variant tanh(const Variant &num) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2435]);
    }
    return call(fn, {num});
}
Variant asinh(const Variant &num) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2436]);
    }
    return call(fn, {num});
}
Variant acosh(const Variant &num) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2437]);
    }
    return call(fn, {num});
}
Variant expm1(const Variant &num) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2438]);
    }
    return call(fn, {num});
}
Variant log1p(const Variant &num) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2439]);
    }
    return call(fn, {num});
}
Variant pi() {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2440]);
    }
    return call(fn, {});
}
Variant is_finite(const Variant &num) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2441]);
    }
    return call(fn, {num});
}
Variant is_nan(const Variant &num) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2442]);
    }
    return call(fn, {num});
}
Variant intdiv(const Variant &num1, const Variant &num2) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2443]);
    }
    return call(fn, {num1, num2});
}
Variant is_infinite(const Variant &num) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2444]);
    }
    return call(fn, {num});
}
Variant pow(const Variant &num, const Variant &exponent) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[23]);
    }
    return call(fn, {num, exponent});
}
Variant exp(const Variant &num) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2445]);
    }
    return call(fn, {num});
}
Variant log(const Variant &num, const Variant &base) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2446]);
    }
    return call(fn, {num, base});
}
Variant log10(const Variant &num) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2447]);
    }
    return call(fn, {num});
}
Variant sqrt(const Variant &num) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[24]);
    }
    return call(fn, {num});
}
Variant hypot(const Variant &x, const Variant &y) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2448]);
    }
    return call(fn, {x, y});
}
Variant deg2rad(const Variant &num) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2449]);
    }
    return call(fn, {num});
}
Variant rad2deg(const Variant &num) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2450]);
    }
    return call(fn, {num});
}
Variant bindec(const Variant &binary_string) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2451]);
    }
    return call(fn, {binary_string});
}
Variant hexdec(const Variant &hex_string) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2452]);
    }
    return call(fn, {hex_string});
}
Variant octdec(const Variant &octal_string) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2453]);
    }
    return call(fn, {octal_string});
}
Variant decbin(const Variant &num) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2454]);
    }
    return call(fn, {num});
}
Variant decoct(const Variant &num) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2455]);
    }
    return call(fn, {num});
}
Variant dechex(const Variant &num) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2456]);
    }
    return call(fn, {num});
}
Variant base_convert(const Variant &num, const Variant &from_base, const Variant &to_base) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2457]);
    }
    return call(fn, {num, from_base, to_base});
}
Variant number_format(const Variant &num,
                      const Variant &decimals,
                      const Variant &decimal_separator,
                      const Variant &thousands_separator) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2458]);
    }
    return call(fn, {num, decimals, decimal_separator, thousands_separator});
}
Variant fmod(const Variant &num1, const Variant &num2) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2459]);
    }
    return call(fn, {num1, num2});
}
Variant fdiv(const Variant &num1, const Variant &num2) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2460]);
    }
    return call(fn, {num1, num2});
}
Variant fpow(const Variant &num, const Variant &exponent) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2461]);
    }
    return call(fn, {num, exponent});
}
Variant microtime(const Variant &as_float) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2462]);
    }
    return call(fn, {as_float});
}
Variant gettimeofday(const Variant &as_float) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2463]);
    }
    return call(fn, {as_float});
}
Variant getrusage(const Variant &mode) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2464]);
    }
    return call(fn, {mode});
}
Variant unpack(const Variant &format, const Variant &string, const Variant &offset) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2466]);
    }
    return call(fn, {format, string, offset});
}
Variant password_get_info(const Variant &hash) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2467]);
    }
    return call(fn, {hash});
}
Variant password_hash(const Variant &password, const Variant &algo, const Variant &options) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2468]);
    }
    return call(fn, {password, algo, options});
}
Variant password_needs_rehash(const Variant &hash, const Variant &algo, const Variant &options) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2469]);
    }
    return call(fn, {hash, algo, options});
}
Variant password_verify(const Variant &password, const Variant &hash) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2470]);
    }
    return call(fn, {password, hash});
}
Variant password_algos() {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2471]);
    }
    return call(fn, {});
}
Variant proc_open(const Variant &command,
                  const Variant &descriptor_spec,
                  const Reference &pipes,
                  const Variant &cwd,
                  const Variant &env_vars,
                  const Variant &options) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2472]);
    }
    return call(fn, {command, descriptor_spec, &pipes, cwd, env_vars, options});
}
Variant proc_close(const Variant &process) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2473]);
    }
    return call(fn, {process});
}
Variant proc_terminate(const Variant &process, const Variant &signal) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2474]);
    }
    return call(fn, {process, signal});
}
Variant proc_get_status(const Variant &process) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2475]);
    }
    return call(fn, {process});
}
Variant quoted_printable_decode(const Variant &string) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2476]);
    }
    return call(fn, {string});
}
Variant quoted_printable_encode(const Variant &string) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2477]);
    }
    return call(fn, {string});
}
Variant soundex(const Variant &string) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2478]);
    }
    return call(fn, {string});
}
Variant stream_select(const Reference &read,
                      const Reference &write,
                      const Reference &except,
                      const Variant &seconds,
                      const Variant &microseconds) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2479]);
    }
    return call(fn, {&read, &write, &except, seconds, microseconds});
}
Variant stream_context_create(const Variant &options, const Variant &params) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2480]);
    }
    return call(fn, {options, params});
}
Variant stream_context_set_params(const Variant &context, const Variant &params) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2481]);
    }
    return call(fn, {context, params});
}
Variant stream_context_get_params(const Variant &context) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2482]);
    }
    return call(fn, {context});
}
Variant stream_context_set_option(const Variant &context,
                                  const Variant &wrapper_or_options,
                                  const Variant &option_name,
                                  const Variant &value) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2483]);
    }
    return call(fn, {context, wrapper_or_options, option_name, value});
}
Variant stream_context_set_options(const Variant &context, const Variant &options) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2484]);
    }
    return call(fn, {context, options});
}
Variant stream_context_get_options(const Variant &stream_or_context) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2485]);
    }
    return call(fn, {stream_or_context});
}
Variant stream_context_get_default(const Variant &options) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2486]);
    }
    return call(fn, {options});
}
Variant stream_context_set_default(const Variant &options) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2487]);
    }
    return call(fn, {options});
}
Variant stream_filter_prepend(const Variant &stream,
                              const Variant &filter_name,
                              const Variant &mode,
                              const Variant &params) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2488]);
    }
    return call(fn, {stream, filter_name, mode, params});
}
Variant stream_filter_append(const Variant &stream,
                             const Variant &filter_name,
                             const Variant &mode,
                             const Variant &params) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2489]);
    }
    return call(fn, {stream, filter_name, mode, params});
}
Variant stream_filter_remove(const Variant &stream_filter) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2490]);
    }
    return call(fn, {stream_filter});
}
Variant stream_socket_client(const Variant &address,
                             const Reference &error_code,
                             const Reference &error_message,
                             const Variant &timeout,
                             const Variant &flags,
                             const Variant &context) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2491]);
    }
    return call(fn, {address, &error_code, &error_message, timeout, flags, context});
}
Variant stream_socket_server(const Variant &address,
                             const Reference &error_code,
                             const Reference &error_message,
                             const Variant &flags,
                             const Variant &context) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2492]);
    }
    return call(fn, {address, &error_code, &error_message, flags, context});
}
Variant stream_socket_accept(const Variant &socket, const Variant &timeout, const Reference &peer_name) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2493]);
    }
    return call(fn, {socket, timeout, &peer_name});
}
Variant stream_socket_get_name(const Variant &socket, const Variant &remote) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2494]);
    }
    return call(fn, {socket, remote});
}
Variant stream_socket_recvfrom(const Variant &socket,
                               const Variant &length,
                               const Variant &flags,
                               const Reference &address) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2495]);
    }
    return call(fn, {socket, length, flags, &address});
}
Variant stream_socket_sendto(const Variant &socket, const Variant &data, const Variant &flags, const Variant &address) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2496]);
    }
    return call(fn, {socket, data, flags, address});
}
Variant stream_socket_enable_crypto(const Variant &stream,
                                    const Variant &enable,
                                    const Variant &crypto_method,
                                    const Variant &session_stream) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2497]);
    }
    return call(fn, {stream, enable, crypto_method, session_stream});
}
Variant stream_socket_shutdown(const Variant &stream, const Variant &mode) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2498]);
    }
    return call(fn, {stream, mode});
}
Variant stream_socket_pair(const Variant &domain, const Variant &type, const Variant &protocol) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2499]);
    }
    return call(fn, {domain, type, protocol});
}
Variant stream_copy_to_stream(const Variant &from, const Variant &to, const Variant &length, const Variant &offset) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2500]);
    }
    return call(fn, {from, to, length, offset});
}
Variant stream_get_contents(const Variant &stream, const Variant &length, const Variant &offset) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2501]);
    }
    return call(fn, {stream, length, offset});
}
Variant stream_supports_lock(const Variant &stream) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2502]);
    }
    return call(fn, {stream});
}
Variant stream_set_write_buffer(const Variant &stream, const Variant &size) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2503]);
    }
    return call(fn, {stream, size});
}
Variant set_file_buffer(const Variant &stream, const Variant &size) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2504]);
    }
    return call(fn, {stream, size});
}
Variant stream_set_read_buffer(const Variant &stream, const Variant &size) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2505]);
    }
    return call(fn, {stream, size});
}
Variant stream_set_blocking(const Variant &stream, const Variant &enable) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2506]);
    }
    return call(fn, {stream, enable});
}
Variant socket_set_blocking(const Variant &stream, const Variant &enable) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2507]);
    }
    return call(fn, {stream, enable});
}
Variant stream_get_meta_data(const Variant &stream) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2508]);
    }
    return call(fn, {stream});
}
Variant socket_get_status(const Variant &stream) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2509]);
    }
    return call(fn, {stream});
}
Variant stream_get_line(const Variant &stream, const Variant &length, const Variant &ending) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2510]);
    }
    return call(fn, {stream, length, ending});
}
Variant stream_resolve_include_path(const Variant &filename) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2511]);
    }
    return call(fn, {filename});
}
Variant stream_get_wrappers() {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2512]);
    }
    return call(fn, {});
}
Variant stream_get_transports() {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2513]);
    }
    return call(fn, {});
}
Variant stream_is_local(const Variant &stream) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2514]);
    }
    return call(fn, {stream});
}
Variant stream_isatty(const Variant &stream) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2515]);
    }
    return call(fn, {stream});
}
Variant stream_set_chunk_size(const Variant &stream, const Variant &size) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2516]);
    }
    return call(fn, {stream, size});
}
Variant stream_set_timeout(const Variant &stream, const Variant &seconds, const Variant &microseconds) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2517]);
    }
    return call(fn, {stream, seconds, microseconds});
}
Variant socket_set_timeout(const Variant &stream, const Variant &seconds, const Variant &microseconds) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2518]);
    }
    return call(fn, {stream, seconds, microseconds});
}
Variant gettype(const Variant &value) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2519]);
    }
    return call(fn, {value});
}
Variant get_debug_type(const Variant &value) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2520]);
    }
    return call(fn, {value});
}
Variant settype(const Reference &var, const Variant &type) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2521]);
    }
    return call(fn, {&var, type});
}
Variant intval(const Variant &value, const Variant &base) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2522]);
    }
    return call(fn, {value, base});
}
Variant floatval(const Variant &value) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2523]);
    }
    return call(fn, {value});
}
Variant doubleval(const Variant &value) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2524]);
    }
    return call(fn, {value});
}
Variant boolval(const Variant &value) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2525]);
    }
    return call(fn, {value});
}
Variant strval(const Variant &value) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2526]);
    }
    return call(fn, {value});
}
Variant is_null(const Variant &value) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2527]);
    }
    return call(fn, {value});
}
Variant is_resource(const Variant &value) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2528]);
    }
    return call(fn, {value});
}
Variant is_bool(const Variant &value) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2529]);
    }
    return call(fn, {value});
}
Variant is_int(const Variant &value) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2530]);
    }
    return call(fn, {value});
}
Variant is_integer(const Variant &value) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2531]);
    }
    return call(fn, {value});
}
Variant is_long(const Variant &value) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2532]);
    }
    return call(fn, {value});
}
Variant is_float(const Variant &value) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2533]);
    }
    return call(fn, {value});
}
Variant is_double(const Variant &value) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2534]);
    }
    return call(fn, {value});
}
Variant is_numeric(const Variant &value) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2535]);
    }
    return call(fn, {value});
}
Variant is_string(const Variant &value) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2536]);
    }
    return call(fn, {value});
}
Variant is_array(const Variant &value) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2537]);
    }
    return call(fn, {value});
}
Variant is_object(const Variant &value) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2538]);
    }
    return call(fn, {value});
}
Variant is_scalar(const Variant &value) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2539]);
    }
    return call(fn, {value});
}
Variant is_callable(const Variant &value, const Variant &syntax_only, const Reference &callable_name) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2540]);
    }
    return call(fn, {value, syntax_only, &callable_name});
}
Variant is_iterable(const Variant &value) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2541]);
    }
    return call(fn, {value});
}
Variant is_countable(const Variant &value) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2542]);
    }
    return call(fn, {value});
}
Variant uniqid(const Variant &prefix, const Variant &more_entropy) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2543]);
    }
    return call(fn, {prefix, more_entropy});
}
Variant parse_url(const Variant &url, const Variant &component) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2544]);
    }
    return call(fn, {url, component});
}
Variant urlencode(const Variant &string) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2545]);
    }
    return call(fn, {string});
}
Variant urldecode(const Variant &string) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2546]);
    }
    return call(fn, {string});
}
Variant rawurlencode(const Variant &string) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2547]);
    }
    return call(fn, {string});
}
Variant rawurldecode(const Variant &string) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2548]);
    }
    return call(fn, {string});
}
Variant get_headers(const Variant &url, const Variant &associative, const Variant &context) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2549]);
    }
    return call(fn, {url, associative, context});
}
StreamBucket stream_bucket_make_writeable(const Variant &brigade) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2550]);
    }
    return StreamBucket(Object(call(fn, {brigade})));
}
Variant stream_bucket_prepend(const Variant &brigade, const StreamBucket &bucket) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2551]);
    }
    return call(fn, {brigade, bucket.getObject()});
}
Variant stream_bucket_prepend(const Variant &brigade, const Variant &bucket) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2551]);
    }
    return call(fn, {brigade, bucket});
}
Variant stream_bucket_append(const Variant &brigade, const StreamBucket &bucket) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2552]);
    }
    return call(fn, {brigade, bucket.getObject()});
}
Variant stream_bucket_append(const Variant &brigade, const Variant &bucket) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2552]);
    }
    return call(fn, {brigade, bucket});
}
StreamBucket stream_bucket_new(const Variant &stream, const Variant &buffer) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2553]);
    }
    return StreamBucket(Object(call(fn, {stream, buffer})));
}
Variant stream_get_filters() {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2554]);
    }
    return call(fn, {});
}
Variant stream_filter_register(const Variant &filter_name, const Variant &class_) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2555]);
    }
    return call(fn, {filter_name, class_});
}
Variant convert_uuencode(const Variant &string) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2556]);
    }
    return call(fn, {string});
}
Variant convert_uudecode(const Variant &string) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2557]);
    }
    return call(fn, {string});
}
Variant var_export(const Variant &value, const Variant &return_) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2559]);
    }
    return call(fn, {value, return_});
}
Variant serialize(const Variant &value) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[1945]);
    }
    return call(fn, {value});
}
Variant unserialize(const Variant &data, const Variant &options) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[1944]);
    }
    return call(fn, {data, options});
}
Variant memory_get_usage(const Variant &real_usage) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2561]);
    }
    return call(fn, {real_usage});
}
Variant memory_get_peak_usage(const Variant &real_usage) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2562]);
    }
    return call(fn, {real_usage});
}
Variant memory_reset_peak_usage() {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2563]);
    }
    return call(fn, {});
}
Variant version_compare(const Variant &version1, const Variant &version2, const Variant &operator_) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2564]);
    }
    return call(fn, {version1, version2, operator_});
}
Variant dl(const Variant &extension_filename) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2565]);
    }
    return call(fn, {extension_filename});
}
Variant cli_set_process_title(const Variant &title) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2566]);
    }
    return call(fn, {title});
}
Variant cli_get_process_title() {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[2567]);
    }
    return call(fn, {});
}
}  // namespace php

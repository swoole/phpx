#include "phpx.h"
#include "phpx_literal_string.h"
#include "phpx_class.h"

namespace php {
Variant set_time_limit(const Variant &seconds) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[2226]);
    }
    return call(_fn, {seconds});
}
Variant header_register_callback(const Variant &callback) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[2227]);
    }
    return call(_fn, {callback});
}
Variant ob_start(const Variant &callback, const Variant &chunk_size, const Variant &flags) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[2228]);
    }
    return call(_fn, {callback, chunk_size, flags});
}
Variant ob_flush() {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[2229]);
    }
    return call(_fn, {});
}
Variant ob_clean() {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[2230]);
    }
    return call(_fn, {});
}
Variant ob_end_flush() {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[2231]);
    }
    return call(_fn, {});
}
Variant ob_end_clean() {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[2232]);
    }
    return call(_fn, {});
}
Variant ob_get_flush() {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[2233]);
    }
    return call(_fn, {});
}
Variant ob_get_clean() {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[2234]);
    }
    return call(_fn, {});
}
Variant ob_get_contents() {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[2235]);
    }
    return call(_fn, {});
}
Variant ob_get_level() {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[2236]);
    }
    return call(_fn, {});
}
Variant ob_get_length() {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[2237]);
    }
    return call(_fn, {});
}
Variant ob_list_handlers() {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[2238]);
    }
    return call(_fn, {});
}
Variant ob_get_status(const Variant &full_status) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[2239]);
    }
    return call(_fn, {full_status});
}
Variant ob_implicit_flush(const Variant &enable) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[2240]);
    }
    return call(_fn, {enable});
}
Variant output_reset_rewrite_vars() {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[2241]);
    }
    return call(_fn, {});
}
Variant output_add_rewrite_var(const Variant &name, const Variant &value) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[2242]);
    }
    return call(_fn, {name, value});
}
Variant stream_wrapper_register(const Variant &protocol, const Variant &class_, const Variant &flags) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[2243]);
    }
    return call(_fn, {protocol, class_, flags});
}
Variant stream_register_wrapper(const Variant &protocol, const Variant &class_, const Variant &flags) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[2244]);
    }
    return call(_fn, {protocol, class_, flags});
}
Variant stream_wrapper_unregister(const Variant &protocol) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[2245]);
    }
    return call(_fn, {protocol});
}
Variant stream_wrapper_restore(const Variant &protocol) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[2246]);
    }
    return call(_fn, {protocol});
}
Variant krsort(const Reference &array, const Variant &flags) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[2248]);
    }
    return call(_fn, {&array, flags});
}
Variant ksort(const Reference &array, const Variant &flags) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[2089]);
    }
    return call(_fn, {&array, flags});
}
Variant count(const Variant &value, const Variant &mode) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[168]);
    }
    return call(_fn, {value, mode});
}
Variant natsort(const Reference &array) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[2092]);
    }
    return call(_fn, {&array});
}
Variant natcasesort(const Reference &array) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[2093]);
    }
    return call(_fn, {&array});
}
Variant asort(const Reference &array, const Variant &flags) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[2088]);
    }
    return call(_fn, {&array, flags});
}
Variant arsort(const Reference &array, const Variant &flags) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[2249]);
    }
    return call(_fn, {&array, flags});
}
Variant sort(const Reference &array, const Variant &flags) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[1448]);
    }
    return call(_fn, {&array, flags});
}
Variant rsort(const Reference &array, const Variant &flags) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[2250]);
    }
    return call(_fn, {&array, flags});
}
Variant usort(const Reference &array, const Variant &callback) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[2251]);
    }
    return call(_fn, {&array, callback});
}
Variant uasort(const Reference &array, const Variant &callback) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[2090]);
    }
    return call(_fn, {&array, callback});
}
Variant uksort(const Reference &array, const Variant &callback) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[2091]);
    }
    return call(_fn, {&array, callback});
}
Variant end(const Reference &array) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[2252]);
    }
    return call(_fn, {&array});
}
Variant prev(const Reference &array) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[2164]);
    }
    return call(_fn, {&array});
}
Variant next(const Reference &array) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[120]);
    }
    return call(_fn, {&array});
}
Variant reset(const Reference &array) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[959]);
    }
    return call(_fn, {&array});
}
Variant current(const Variant &array) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[118]);
    }
    return call(_fn, {array});
}
Variant pos(const Variant &array) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[2253]);
    }
    return call(_fn, {array});
}
Variant key(const Variant &array) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[119]);
    }
    return call(_fn, {array});
}
Variant array_walk(const Reference &array, const Variant &callback, const Variant &arg) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[2256]);
    }
    return call(_fn, {&array, callback, arg});
}
Variant array_walk_recursive(const Reference &array, const Variant &callback, const Variant &arg) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[2257]);
    }
    return call(_fn, {&array, callback, arg});
}
Variant in_array(const Variant &needle, const Variant &haystack, const Variant &strict) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[2258]);
    }
    return call(_fn, {needle, haystack, strict});
}
Variant array_search(const Variant &needle, const Variant &haystack, const Variant &strict) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[2259]);
    }
    return call(_fn, {needle, haystack, strict});
}
Variant extract(const Reference &array, const Variant &flags, const Variant &prefix) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[2170]);
    }
    return call(_fn, {&array, flags, prefix});
}
Variant array_fill(const Variant &start_index, const Variant &count, const Variant &value) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[2261]);
    }
    return call(_fn, {start_index, count, value});
}
Variant array_fill_keys(const Variant &keys, const Variant &value) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[2262]);
    }
    return call(_fn, {keys, value});
}
Variant range(const Variant &start, const Variant &end, const Variant &step) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[2263]);
    }
    return call(_fn, {start, end, step});
}
Variant shuffle(const Reference &array) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[2264]);
    }
    return call(_fn, {&array});
}
Variant array_pop(const Reference &array) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[2265]);
    }
    return call(_fn, {&array});
}
Variant array_shift(const Reference &array) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[2266]);
    }
    return call(_fn, {&array});
}
Variant array_splice(const Reference &array, const Variant &offset, const Variant &length, const Variant &replacement) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[2268]);
    }
    return call(_fn, {&array, offset, length, replacement});
}
Variant array_slice(const Variant &array, const Variant &offset, const Variant &length, const Variant &preserve_keys) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[2269]);
    }
    return call(_fn, {array, offset, length, preserve_keys});
}
Variant array_keys(const Variant &array, const Variant &filter_value, const Variant &strict) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[2274]);
    }
    return call(_fn, {array, filter_value, strict});
}
Variant array_key_first(const Variant &array) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[2275]);
    }
    return call(_fn, {array});
}
Variant array_key_last(const Variant &array) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[2276]);
    }
    return call(_fn, {array});
}
Variant array_values(const Variant &array) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[2277]);
    }
    return call(_fn, {array});
}
Variant array_count_values(const Variant &array) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[2278]);
    }
    return call(_fn, {array});
}
Variant array_column(const Variant &array, const Variant &column_key, const Variant &index_key) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[2279]);
    }
    return call(_fn, {array, column_key, index_key});
}
Variant array_reverse(const Variant &array, const Variant &preserve_keys) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[2280]);
    }
    return call(_fn, {array, preserve_keys});
}
Variant array_pad(const Variant &array, const Variant &length, const Variant &value) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[2281]);
    }
    return call(_fn, {array, length, value});
}
Variant array_flip(const Variant &array) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[2282]);
    }
    return call(_fn, {array});
}
Variant array_change_key_case(const Variant &array, const Variant &case_) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[2283]);
    }
    return call(_fn, {array, case_});
}
Variant array_unique(const Variant &array, const Variant &flags) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[2284]);
    }
    return call(_fn, {array, flags});
}
Variant array_rand(const Variant &array, const Variant &num) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[2302]);
    }
    return call(_fn, {array, num});
}
Variant array_sum(const Variant &array) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[2303]);
    }
    return call(_fn, {array});
}
Variant array_product(const Variant &array) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[2304]);
    }
    return call(_fn, {array});
}
Variant array_reduce(const Variant &array, const Variant &callback, const Variant &initial) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[2305]);
    }
    return call(_fn, {array, callback, initial});
}
Variant array_filter(const Variant &array, const Variant &callback, const Variant &mode) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[2306]);
    }
    return call(_fn, {array, callback, mode});
}
Variant array_find(const Variant &array, const Variant &callback) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[2307]);
    }
    return call(_fn, {array, callback});
}
Variant array_find_key(const Variant &array, const Variant &callback) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[2308]);
    }
    return call(_fn, {array, callback});
}
Variant array_any(const Variant &array, const Variant &callback) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[2309]);
    }
    return call(_fn, {array, callback});
}
Variant array_all(const Variant &array, const Variant &callback) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[2310]);
    }
    return call(_fn, {array, callback});
}
Variant array_key_exists(const Variant &key, const Variant &array) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[2312]);
    }
    return call(_fn, {key, array});
}
Variant key_exists(const Variant &key, const Variant &array) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[2313]);
    }
    return call(_fn, {key, array});
}
Variant array_chunk(const Variant &array, const Variant &length, const Variant &preserve_keys) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[2314]);
    }
    return call(_fn, {array, length, preserve_keys});
}
Variant array_combine(const Variant &keys, const Variant &values) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[2315]);
    }
    return call(_fn, {keys, values});
}
Variant array_is_list(const Variant &array) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[2316]);
    }
    return call(_fn, {array});
}
Variant base64_encode(const Variant &string) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[2317]);
    }
    return call(_fn, {string});
}
Variant base64_decode(const Variant &string, const Variant &strict) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[2318]);
    }
    return call(_fn, {string, strict});
}
Variant ip2long(const Variant &ip) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[2319]);
    }
    return call(_fn, {ip});
}
Variant long2ip(const Variant &ip) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[2320]);
    }
    return call(_fn, {ip});
}
Variant getenv(const Variant &name, const Variant &local_only) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[2321]);
    }
    return call(_fn, {name, local_only});
}
Variant putenv(const Variant &assignment) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[2322]);
    }
    return call(_fn, {assignment});
}
Variant getopt(const Variant &short_options, const Variant &long_options, const Reference &rest_index) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[2323]);
    }
    return call(_fn, {short_options, long_options, &rest_index});
}
Variant flush() {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[2324]);
    }
    return call(_fn, {});
}
Variant sleep(const Variant &seconds) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[2325]);
    }
    return call(_fn, {seconds});
}
Variant usleep(const Variant &microseconds) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[2326]);
    }
    return call(_fn, {microseconds});
}
Variant time_nanosleep(const Variant &seconds, const Variant &nanoseconds) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[2327]);
    }
    return call(_fn, {seconds, nanoseconds});
}
Variant time_sleep_until(const Variant &timestamp) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[2328]);
    }
    return call(_fn, {timestamp});
}
Variant get_current_user() {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[2329]);
    }
    return call(_fn, {});
}
Variant get_cfg_var(const Variant &option) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[2330]);
    }
    return call(_fn, {option});
}
Variant error_log(const Variant &message,
                  const Variant &message_type,
                  const Variant &destination,
                  const Variant &additional_headers) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[2331]);
    }
    return call(_fn, {message, message_type, destination, additional_headers});
}
Variant error_get_last() {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[2332]);
    }
    return call(_fn, {});
}
Variant error_clear_last() {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[2333]);
    }
    return call(_fn, {});
}
Variant call_user_func_array(const Variant &callback, const Variant &args) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[2335]);
    }
    return call(_fn, {callback, args});
}
Variant forward_static_call_array(const Variant &callback, const Variant &args) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[2337]);
    }
    return call(_fn, {callback, args});
}
Variant highlight_file(const Variant &filename, const Variant &return_) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[2339]);
    }
    return call(_fn, {filename, return_});
}
Variant show_source(const Variant &filename, const Variant &return_) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[2340]);
    }
    return call(_fn, {filename, return_});
}
Variant php_strip_whitespace(const Variant &filename) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[2341]);
    }
    return call(_fn, {filename});
}
Variant highlight_string(const Variant &string, const Variant &return_) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[2342]);
    }
    return call(_fn, {string, return_});
}
Variant ini_get(const Variant &option) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[2343]);
    }
    return call(_fn, {option});
}
Variant ini_get_all(const Variant &extension, const Variant &details) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[2344]);
    }
    return call(_fn, {extension, details});
}
Variant ini_set(const Variant &option, const Variant &value) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[2345]);
    }
    return call(_fn, {option, value});
}
Variant ini_alter(const Variant &option, const Variant &value) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[2346]);
    }
    return call(_fn, {option, value});
}
Variant ini_restore(const Variant &option) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[2347]);
    }
    return call(_fn, {option});
}
Variant ini_parse_quantity(const Variant &shorthand) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[2348]);
    }
    return call(_fn, {shorthand});
}
Variant set_include_path(const Variant &include_path) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[2349]);
    }
    return call(_fn, {include_path});
}
Variant get_include_path() {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[2350]);
    }
    return call(_fn, {});
}
Variant print_r(const Variant &value, const Variant &return_) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[2351]);
    }
    return call(_fn, {value, return_});
}
Variant connection_aborted() {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[2352]);
    }
    return call(_fn, {});
}
Variant connection_status() {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[2353]);
    }
    return call(_fn, {});
}
Variant ignore_user_abort(const Variant &enable) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[2354]);
    }
    return call(_fn, {enable});
}
Variant getservbyname(const Variant &service, const Variant &protocol) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[2355]);
    }
    return call(_fn, {service, protocol});
}
Variant getservbyport(const Variant &port, const Variant &protocol) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[2356]);
    }
    return call(_fn, {port, protocol});
}
Variant getprotobyname(const Variant &protocol) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[2357]);
    }
    return call(_fn, {protocol});
}
Variant getprotobynumber(const Variant &protocol) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[2358]);
    }
    return call(_fn, {protocol});
}
Variant unregister_tick_function(const Variant &callback) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[2360]);
    }
    return call(_fn, {callback});
}
Variant is_uploaded_file(const Variant &filename) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[2361]);
    }
    return call(_fn, {filename});
}
Variant move_uploaded_file(const Variant &from, const Variant &to) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[2362]);
    }
    return call(_fn, {from, to});
}
Variant parse_ini_file(const Variant &filename, const Variant &process_sections, const Variant &scanner_mode) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[2363]);
    }
    return call(_fn, {filename, process_sections, scanner_mode});
}
Variant parse_ini_string(const Variant &ini_string, const Variant &process_sections, const Variant &scanner_mode) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[2364]);
    }
    return call(_fn, {ini_string, process_sections, scanner_mode});
}
Variant config_get_hash() {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[2365]);
    }
    return call(_fn, {});
}
Variant sys_getloadavg() {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[2366]);
    }
    return call(_fn, {});
}
Variant get_browser(const Variant &user_agent, const Variant &return_array) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[2367]);
    }
    return call(_fn, {user_agent, return_array});
}
Variant crc32(const Variant &string) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[2368]);
    }
    return call(_fn, {string});
}
Variant crypt(const Variant &string, const Variant &salt) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[2369]);
    }
    return call(_fn, {string, salt});
}
Variant strptime(const Variant &timestamp, const Variant &format) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[2370]);
    }
    return call(_fn, {timestamp, format});
}
Variant gethostname() {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[2371]);
    }
    return call(_fn, {});
}
Variant gethostbyaddr(const Variant &ip) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[2372]);
    }
    return call(_fn, {ip});
}
Variant gethostbyname(const Variant &hostname) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[2373]);
    }
    return call(_fn, {hostname});
}
Variant gethostbynamel(const Variant &hostname) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[2374]);
    }
    return call(_fn, {hostname});
}
Variant dns_check_record(const Variant &hostname, const Variant &type) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[2375]);
    }
    return call(_fn, {hostname, type});
}
Variant checkdnsrr(const Variant &hostname, const Variant &type) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[2376]);
    }
    return call(_fn, {hostname, type});
}
Variant dns_get_record(const Variant &hostname,
                       const Variant &type,
                       const Reference &authoritative_name_servers,
                       const Reference &additional_records,
                       const Variant &raw) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[2377]);
    }
    return call(_fn, {hostname, type, &authoritative_name_servers, &additional_records, raw});
}
Variant dns_get_mx(const Variant &hostname, const Reference &hosts, const Reference &weights) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[2378]);
    }
    return call(_fn, {hostname, &hosts, &weights});
}
Variant getmxrr(const Variant &hostname, const Reference &hosts, const Reference &weights) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[2379]);
    }
    return call(_fn, {hostname, &hosts, &weights});
}
Variant net_get_interfaces() {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[2380]);
    }
    return call(_fn, {});
}
Variant ftok(const Variant &filename, const Variant &project_id) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[2381]);
    }
    return call(_fn, {filename, project_id});
}
Variant hrtime(const Variant &as_number) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[2382]);
    }
    return call(_fn, {as_number});
}
Variant md5(const Variant &string, const Variant &binary) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[2383]);
    }
    return call(_fn, {string, binary});
}
Variant md5_file(const Variant &filename, const Variant &binary) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[2384]);
    }
    return call(_fn, {filename, binary});
}
Variant getmyuid() {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[2385]);
    }
    return call(_fn, {});
}
Variant getmygid() {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[2386]);
    }
    return call(_fn, {});
}
Variant getmypid() {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[2387]);
    }
    return call(_fn, {});
}
Variant getmyinode() {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[2388]);
    }
    return call(_fn, {});
}
Variant getlastmod() {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[2389]);
    }
    return call(_fn, {});
}
Variant sha1(const Variant &string, const Variant &binary) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[2390]);
    }
    return call(_fn, {string, binary});
}
Variant sha1_file(const Variant &filename, const Variant &binary) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[2391]);
    }
    return call(_fn, {filename, binary});
}
Variant openlog(const Variant &prefix, const Variant &flags, const Variant &facility) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[2392]);
    }
    return call(_fn, {prefix, flags, facility});
}
Variant closelog() {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[2393]);
    }
    return call(_fn, {});
}
Variant syslog(const Variant &priority, const Variant &message) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[2394]);
    }
    return call(_fn, {priority, message});
}
Variant inet_ntop(const Variant &ip) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[2395]);
    }
    return call(_fn, {ip});
}
Variant inet_pton(const Variant &ip) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[2396]);
    }
    return call(_fn, {ip});
}
Variant metaphone(const Variant &string, const Variant &max_phonemes) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[2397]);
    }
    return call(_fn, {string, max_phonemes});
}
Variant header(const Variant &header, const Variant &replace, const Variant &response_code) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[2398]);
    }
    return call(_fn, {header, replace, response_code});
}
Variant header_remove(const Variant &name) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[2399]);
    }
    return call(_fn, {name});
}
Variant setrawcookie(const Variant &name,
                     const Variant &value,
                     const Variant &expires_or_options,
                     const Variant &path,
                     const Variant &domain,
                     const Variant &secure,
                     const Variant &httponly) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[2400]);
    }
    return call(_fn, {name, value, expires_or_options, path, domain, secure, httponly});
}
Variant setcookie(const Variant &name,
                  const Variant &value,
                  const Variant &expires_or_options,
                  const Variant &path,
                  const Variant &domain,
                  const Variant &secure,
                  const Variant &httponly) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[2401]);
    }
    return call(_fn, {name, value, expires_or_options, path, domain, secure, httponly});
}
Variant http_response_code(const Variant &response_code) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[2402]);
    }
    return call(_fn, {response_code});
}
Variant headers_sent(const Reference &filename, const Reference &line) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[2403]);
    }
    return call(_fn, {&filename, &line});
}
Variant headers_list() {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[2404]);
    }
    return call(_fn, {});
}
Variant htmlspecialchars(const Variant &string,
                         const Variant &flags,
                         const Variant &encoding,
                         const Variant &double_encode) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[2405]);
    }
    return call(_fn, {string, flags, encoding, double_encode});
}
Variant htmlspecialchars_decode(const Variant &string, const Variant &flags) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[2406]);
    }
    return call(_fn, {string, flags});
}
Variant html_entity_decode(const Variant &string, const Variant &flags, const Variant &encoding) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[2407]);
    }
    return call(_fn, {string, flags, encoding});
}
Variant htmlentities(const Variant &string,
                     const Variant &flags,
                     const Variant &encoding,
                     const Variant &double_encode) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[2408]);
    }
    return call(_fn, {string, flags, encoding, double_encode});
}
Variant get_html_translation_table(const Variant &table, const Variant &flags, const Variant &encoding) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[2409]);
    }
    return call(_fn, {table, flags, encoding});
}
Variant assert_options(const Variant &option, const Variant &value) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[2410]);
    }
    return call(_fn, {option, value});
}
Variant bin2hex(const Variant &string) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[2411]);
    }
    return call(_fn, {string});
}
Variant hex2bin(const Variant &string) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[2412]);
    }
    return call(_fn, {string});
}
Variant strspn(const Variant &string, const Variant &characters, const Variant &offset, const Variant &length) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[2413]);
    }
    return call(_fn, {string, characters, offset, length});
}
Variant strcspn(const Variant &string, const Variant &characters, const Variant &offset, const Variant &length) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[2414]);
    }
    return call(_fn, {string, characters, offset, length});
}
Variant nl_langinfo(const Variant &item) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[2415]);
    }
    return call(_fn, {item});
}
Variant strcoll(const Variant &string1, const Variant &string2) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[2416]);
    }
    return call(_fn, {string1, string2});
}
Variant trim(const Variant &string, const Variant &characters) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[2417]);
    }
    return call(_fn, {string, characters});
}
Variant rtrim(const Variant &string, const Variant &characters) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[2418]);
    }
    return call(_fn, {string, characters});
}
Variant chop(const Variant &string, const Variant &characters) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[2419]);
    }
    return call(_fn, {string, characters});
}
Variant ltrim(const Variant &string, const Variant &characters) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[1388]);
    }
    return call(_fn, {string, characters});
}
Variant wordwrap(const Variant &string, const Variant &width, const Variant &break_, const Variant &cut_long_words) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[2420]);
    }
    return call(_fn, {string, width, break_, cut_long_words});
}
Variant explode(const Variant &separator, const Variant &string, const Variant &limit) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[2421]);
    }
    return call(_fn, {separator, string, limit});
}
Variant implode(const Variant &separator, const Variant &array) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[2422]);
    }
    return call(_fn, {separator, array});
}
Variant join(const Variant &separator, const Variant &array) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[2423]);
    }
    return call(_fn, {separator, array});
}
Variant strtok(const Variant &string, const Variant &token) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[2424]);
    }
    return call(_fn, {string, token});
}
Variant strtoupper(const Variant &string) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[2425]);
    }
    return call(_fn, {string});
}
Variant strtolower(const Variant &string) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[2426]);
    }
    return call(_fn, {string});
}
Variant str_increment(const Variant &string) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[2427]);
    }
    return call(_fn, {string});
}
Variant str_decrement(const Variant &string) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[2428]);
    }
    return call(_fn, {string});
}
Variant basename(const Variant &path, const Variant &suffix) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[2429]);
    }
    return call(_fn, {path, suffix});
}
Variant dirname(const Variant &path, const Variant &levels) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[2430]);
    }
    return call(_fn, {path, levels});
}
Variant pathinfo(const Variant &path, const Variant &flags) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[2431]);
    }
    return call(_fn, {path, flags});
}
Variant stristr(const Variant &haystack, const Variant &needle, const Variant &before_needle) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[2432]);
    }
    return call(_fn, {haystack, needle, before_needle});
}
Variant strstr(const Variant &haystack, const Variant &needle, const Variant &before_needle) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[2433]);
    }
    return call(_fn, {haystack, needle, before_needle});
}
Variant strchr(const Variant &haystack, const Variant &needle, const Variant &before_needle) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[2434]);
    }
    return call(_fn, {haystack, needle, before_needle});
}
Variant strpos(const Variant &haystack, const Variant &needle, const Variant &offset) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[2435]);
    }
    return call(_fn, {haystack, needle, offset});
}
Variant stripos(const Variant &haystack, const Variant &needle, const Variant &offset) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[2436]);
    }
    return call(_fn, {haystack, needle, offset});
}
Variant strrpos(const Variant &haystack, const Variant &needle, const Variant &offset) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[2437]);
    }
    return call(_fn, {haystack, needle, offset});
}
Variant strripos(const Variant &haystack, const Variant &needle, const Variant &offset) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[2438]);
    }
    return call(_fn, {haystack, needle, offset});
}
Variant strrchr(const Variant &haystack, const Variant &needle, const Variant &before_needle) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[2439]);
    }
    return call(_fn, {haystack, needle, before_needle});
}
Variant str_contains(const Variant &haystack, const Variant &needle) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[2440]);
    }
    return call(_fn, {haystack, needle});
}
Variant str_starts_with(const Variant &haystack, const Variant &needle) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[2441]);
    }
    return call(_fn, {haystack, needle});
}
Variant str_ends_with(const Variant &haystack, const Variant &needle) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[2442]);
    }
    return call(_fn, {haystack, needle});
}
Variant chunk_split(const Variant &string, const Variant &length, const Variant &separator) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[2443]);
    }
    return call(_fn, {string, length, separator});
}
Variant substr(const Variant &string, const Variant &offset, const Variant &length) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[2444]);
    }
    return call(_fn, {string, offset, length});
}
Variant substr_replace(const Variant &string, const Variant &replace, const Variant &offset, const Variant &length) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[2445]);
    }
    return call(_fn, {string, replace, offset, length});
}
Variant quotemeta(const Variant &string) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[2446]);
    }
    return call(_fn, {string});
}
Variant ord(const Variant &character) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[2447]);
    }
    return call(_fn, {character});
}
Variant chr(const Variant &codepoint) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[2448]);
    }
    return call(_fn, {codepoint});
}
Variant ucfirst(const Variant &string) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[2449]);
    }
    return call(_fn, {string});
}
Variant lcfirst(const Variant &string) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[2450]);
    }
    return call(_fn, {string});
}
Variant ucwords(const Variant &string, const Variant &separators) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[2451]);
    }
    return call(_fn, {string, separators});
}
Variant strtr(const Variant &string, const Variant &from, const Variant &to) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[2452]);
    }
    return call(_fn, {string, from, to});
}
Variant strrev(const Variant &string) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[2453]);
    }
    return call(_fn, {string});
}
Variant similar_text(const Variant &string1, const Variant &string2, const Reference &percent) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[2454]);
    }
    return call(_fn, {string1, string2, &percent});
}
Variant addcslashes(const Variant &string, const Variant &characters) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[2455]);
    }
    return call(_fn, {string, characters});
}
Variant addslashes(const Variant &string) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[2456]);
    }
    return call(_fn, {string});
}
Variant stripcslashes(const Variant &string) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[2457]);
    }
    return call(_fn, {string});
}
Variant stripslashes(const Variant &string) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[2458]);
    }
    return call(_fn, {string});
}
Variant str_replace(const Variant &search, const Variant &replace, const Variant &subject, const Reference &count) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[2459]);
    }
    return call(_fn, {search, replace, subject, &count});
}
Variant str_ireplace(const Variant &search, const Variant &replace, const Variant &subject, const Reference &count) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[2460]);
    }
    return call(_fn, {search, replace, subject, &count});
}
Variant hebrev(const Variant &string, const Variant &max_chars_per_line) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[2461]);
    }
    return call(_fn, {string, max_chars_per_line});
}
Variant nl2br(const Variant &string, const Variant &use_xhtml) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[2462]);
    }
    return call(_fn, {string, use_xhtml});
}
Variant strip_tags(const Variant &string, const Variant &allowed_tags) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[2463]);
    }
    return call(_fn, {string, allowed_tags});
}
Variant parse_str(const Variant &string, const Reference &result) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[2465]);
    }
    return call(_fn, {string, &result});
}
Variant str_getcsv(const Variant &string, const Variant &separator, const Variant &enclosure, const Variant &escape) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[2466]);
    }
    return call(_fn, {string, separator, enclosure, escape});
}
Variant str_repeat(const Variant &string, const Variant &times) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[2467]);
    }
    return call(_fn, {string, times});
}
Variant count_chars(const Variant &string, const Variant &mode) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[2468]);
    }
    return call(_fn, {string, mode});
}
Variant localeconv() {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[2469]);
    }
    return call(_fn, {});
}
Variant substr_count(const Variant &haystack, const Variant &needle, const Variant &offset, const Variant &length) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[2470]);
    }
    return call(_fn, {haystack, needle, offset, length});
}
Variant str_pad(const Variant &string, const Variant &length, const Variant &pad_string, const Variant &pad_type) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[2471]);
    }
    return call(_fn, {string, length, pad_string, pad_type});
}
Variant str_rot13(const Variant &string) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[2473]);
    }
    return call(_fn, {string});
}
Variant str_shuffle(const Variant &string) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[2474]);
    }
    return call(_fn, {string});
}
Variant str_word_count(const Variant &string, const Variant &format, const Variant &characters) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[2475]);
    }
    return call(_fn, {string, format, characters});
}
Variant str_split(const Variant &string, const Variant &length) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[2476]);
    }
    return call(_fn, {string, length});
}
Variant strpbrk(const Variant &string, const Variant &characters) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[2477]);
    }
    return call(_fn, {string, characters});
}
Variant substr_compare(const Variant &haystack,
                       const Variant &needle,
                       const Variant &offset,
                       const Variant &length,
                       const Variant &case_insensitive) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[2478]);
    }
    return call(_fn, {haystack, needle, offset, length, case_insensitive});
}
Variant utf8_encode(const Variant &string) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[2479]);
    }
    return call(_fn, {string});
}
Variant utf8_decode(const Variant &string) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[2480]);
    }
    return call(_fn, {string});
}
Variant opendir(const Variant &directory, const Variant &context) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[2481]);
    }
    return call(_fn, {directory, context});
}
Directory dir(const Variant &directory, const Variant &context) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[2482]);
    }
    auto _rv = call(_fn, {directory, context});
    if (!_rv.toBool()) {
        throwException(String("RuntimeException"), "dir() returned false");
    }
    return Directory(Object(std::move(_rv)));
}
Variant closedir(const Variant &dir_handle) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[2483]);
    }
    return call(_fn, {dir_handle});
}
Variant chdir(const Variant &directory) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[2484]);
    }
    return call(_fn, {directory});
}
Variant getcwd() {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[2485]);
    }
    return call(_fn, {});
}
Variant rewinddir(const Variant &dir_handle) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[2486]);
    }
    return call(_fn, {dir_handle});
}
Variant readdir(const Variant &dir_handle) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[2487]);
    }
    return call(_fn, {dir_handle});
}
Variant scandir(const Variant &directory, const Variant &sorting_order, const Variant &context) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[2488]);
    }
    return call(_fn, {directory, sorting_order, context});
}
Variant glob(const Variant &pattern, const Variant &flags) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[2489]);
    }
    return call(_fn, {pattern, flags});
}
Variant exec(const Variant &command, const Reference &output, const Reference &result_code) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[1077]);
    }
    return call(_fn, {command, &output, &result_code});
}
Variant system(const Variant &command, const Reference &result_code) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[2490]);
    }
    return call(_fn, {command, &result_code});
}
Variant passthru(const Variant &command, const Reference &result_code) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[2491]);
    }
    return call(_fn, {command, &result_code});
}
Variant escapeshellcmd(const Variant &command) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[2492]);
    }
    return call(_fn, {command});
}
Variant escapeshellarg(const Variant &arg) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[2493]);
    }
    return call(_fn, {arg});
}
Variant shell_exec(const Variant &command) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[2494]);
    }
    return call(_fn, {command});
}
Variant proc_nice(const Variant &priority) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[2495]);
    }
    return call(_fn, {priority});
}
Variant flock(const Variant &stream, const Variant &operation, const Reference &would_block) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[2140]);
    }
    return call(_fn, {stream, operation, &would_block});
}
Variant get_meta_tags(const Variant &filename, const Variant &use_include_path) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[2496]);
    }
    return call(_fn, {filename, use_include_path});
}
Variant pclose(const Variant &handle) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[2497]);
    }
    return call(_fn, {handle});
}
Variant popen(const Variant &command, const Variant &mode) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[1405]);
    }
    return call(_fn, {command, mode});
}
Variant readfile(const Variant &filename, const Variant &use_include_path, const Variant &context) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[2498]);
    }
    return call(_fn, {filename, use_include_path, context});
}
Variant rewind(const Variant &stream) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[122]);
    }
    return call(_fn, {stream});
}
Variant rmdir(const Variant &directory, const Variant &context) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[2499]);
    }
    return call(_fn, {directory, context});
}
Variant umask(const Variant &mask) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[2500]);
    }
    return call(_fn, {mask});
}
Variant fclose(const Variant &stream) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[2501]);
    }
    return call(_fn, {stream});
}
Variant feof(const Variant &stream) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[2502]);
    }
    return call(_fn, {stream});
}
Variant fgetc(const Variant &stream) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[2144]);
    }
    return call(_fn, {stream});
}
Variant fgets(const Variant &stream, const Variant &length) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[2134]);
    }
    return call(_fn, {stream, length});
}
Variant fread(const Variant &stream, const Variant &length) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[2135]);
    }
    return call(_fn, {stream, length});
}
Variant fopen(const Variant &filename, const Variant &mode, const Variant &use_include_path, const Variant &context) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[2503]);
    }
    return call(_fn, {filename, mode, use_include_path, context});
}
Variant fpassthru(const Variant &stream) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[2145]);
    }
    return call(_fn, {stream});
}
Variant ftruncate(const Variant &stream, const Variant &size) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[2149]);
    }
    return call(_fn, {stream, size});
}
Variant fstat(const Variant &stream) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[2148]);
    }
    return call(_fn, {stream});
}
Variant fseek(const Variant &stream, const Variant &offset, const Variant &whence) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[2143]);
    }
    return call(_fn, {stream, offset, whence});
}
Variant ftell(const Variant &stream) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[2142]);
    }
    return call(_fn, {stream});
}
Variant fflush(const Variant &stream) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[2141]);
    }
    return call(_fn, {stream});
}
Variant fsync(const Variant &stream) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[2504]);
    }
    return call(_fn, {stream});
}
Variant fdatasync(const Variant &stream) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[2505]);
    }
    return call(_fn, {stream});
}
Variant fwrite(const Variant &stream, const Variant &data, const Variant &length) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[2147]);
    }
    return call(_fn, {stream, data, length});
}
Variant fputs(const Variant &stream, const Variant &data, const Variant &length) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[2506]);
    }
    return call(_fn, {stream, data, length});
}
Variant mkdir(const Variant &directory, const Variant &permissions, const Variant &recursive, const Variant &context) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[2507]);
    }
    return call(_fn, {directory, permissions, recursive, context});
}
Variant rename(const Variant &from, const Variant &to, const Variant &context) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[482]);
    }
    return call(_fn, {from, to, context});
}
Variant copy(const Variant &from, const Variant &to, const Variant &context) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[1119]);
    }
    return call(_fn, {from, to, context});
}
Variant tempnam(const Variant &directory, const Variant &prefix) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[2508]);
    }
    return call(_fn, {directory, prefix});
}
Variant tmpfile() {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[2509]);
    }
    return call(_fn, {});
}
Variant file(const Variant &filename, const Variant &flags, const Variant &context) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[554]);
    }
    return call(_fn, {filename, flags, context});
}
Variant file_get_contents(const Variant &filename,
                          const Variant &use_include_path,
                          const Variant &context,
                          const Variant &offset,
                          const Variant &length) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[2510]);
    }
    return call(_fn, {filename, use_include_path, context, offset, length});
}
Variant unlink(const Variant &filename, const Variant &context) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[1463]);
    }
    return call(_fn, {filename, context});
}
Variant file_put_contents(const Variant &filename, const Variant &data, const Variant &flags, const Variant &context) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[2511]);
    }
    return call(_fn, {filename, data, flags, context});
}
Variant fputcsv(const Variant &stream,
                const Variant &fields,
                const Variant &separator,
                const Variant &enclosure,
                const Variant &escape,
                const Variant &eol) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[2137]);
    }
    return call(_fn, {stream, fields, separator, enclosure, escape, eol});
}
Variant fgetcsv(const Variant &stream,
                const Variant &length,
                const Variant &separator,
                const Variant &enclosure,
                const Variant &escape) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[2136]);
    }
    return call(_fn, {stream, length, separator, enclosure, escape});
}
Variant realpath(const Variant &path) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[2512]);
    }
    return call(_fn, {path});
}
Variant fnmatch(const Variant &pattern, const Variant &filename, const Variant &flags) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[2513]);
    }
    return call(_fn, {pattern, filename, flags});
}
Variant sys_get_temp_dir() {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[2514]);
    }
    return call(_fn, {});
}
Variant fileatime(const Variant &filename) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[2515]);
    }
    return call(_fn, {filename});
}
Variant filectime(const Variant &filename) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[2516]);
    }
    return call(_fn, {filename});
}
Variant filegroup(const Variant &filename) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[2517]);
    }
    return call(_fn, {filename});
}
Variant fileinode(const Variant &filename) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[2518]);
    }
    return call(_fn, {filename});
}
Variant filemtime(const Variant &filename) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[2519]);
    }
    return call(_fn, {filename});
}
Variant fileowner(const Variant &filename) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[2520]);
    }
    return call(_fn, {filename});
}
Variant fileperms(const Variant &filename) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[2521]);
    }
    return call(_fn, {filename});
}
Variant filesize(const Variant &filename) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[2522]);
    }
    return call(_fn, {filename});
}
Variant filetype(const Variant &filename) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[2523]);
    }
    return call(_fn, {filename});
}
Variant file_exists(const Variant &filename) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[2524]);
    }
    return call(_fn, {filename});
}
Variant is_writable(const Variant &filename) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[2525]);
    }
    return call(_fn, {filename});
}
Variant is_writeable(const Variant &filename) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[2526]);
    }
    return call(_fn, {filename});
}
Variant is_readable(const Variant &filename) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[2527]);
    }
    return call(_fn, {filename});
}
Variant is_executable(const Variant &filename) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[2528]);
    }
    return call(_fn, {filename});
}
Variant is_file(const Variant &filename) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[2529]);
    }
    return call(_fn, {filename});
}
Variant is_dir(const Variant &filename) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[2530]);
    }
    return call(_fn, {filename});
}
Variant is_link(const Variant &filename) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[2531]);
    }
    return call(_fn, {filename});
}
Variant stat(const Variant &filename) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[928]);
    }
    return call(_fn, {filename});
}
Variant lstat(const Variant &filename) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[2532]);
    }
    return call(_fn, {filename});
}
Variant chown(const Variant &filename, const Variant &user) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[2533]);
    }
    return call(_fn, {filename, user});
}
Variant chgrp(const Variant &filename, const Variant &group) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[2534]);
    }
    return call(_fn, {filename, group});
}
Variant lchown(const Variant &filename, const Variant &user) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[2535]);
    }
    return call(_fn, {filename, user});
}
Variant lchgrp(const Variant &filename, const Variant &group) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[2536]);
    }
    return call(_fn, {filename, group});
}
Variant chmod(const Variant &filename, const Variant &permissions) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[1189]);
    }
    return call(_fn, {filename, permissions});
}
Variant touch(const Variant &filename, const Variant &mtime, const Variant &atime) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[1446]);
    }
    return call(_fn, {filename, mtime, atime});
}
Variant clearstatcache(const Variant &clear_realpath_cache, const Variant &filename) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[2537]);
    }
    return call(_fn, {clear_realpath_cache, filename});
}
Variant disk_total_space(const Variant &directory) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[2538]);
    }
    return call(_fn, {directory});
}
Variant disk_free_space(const Variant &directory) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[2539]);
    }
    return call(_fn, {directory});
}
Variant diskfreespace(const Variant &directory) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[2540]);
    }
    return call(_fn, {directory});
}
Variant realpath_cache_get() {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[2541]);
    }
    return call(_fn, {});
}
Variant realpath_cache_size() {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[2542]);
    }
    return call(_fn, {});
}
Variant vprintf(const Variant &format, const Variant &values) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[2545]);
    }
    return call(_fn, {format, values});
}
Variant vsprintf(const Variant &format, const Variant &values) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[2546]);
    }
    return call(_fn, {format, values});
}
Variant vfprintf(const Variant &stream, const Variant &format, const Variant &values) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[2548]);
    }
    return call(_fn, {stream, format, values});
}
Variant fsockopen(const Variant &hostname,
                  const Variant &port,
                  const Reference &error_code,
                  const Reference &error_message,
                  const Variant &timeout) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[2549]);
    }
    return call(_fn, {hostname, port, &error_code, &error_message, timeout});
}
Variant pfsockopen(const Variant &hostname,
                   const Variant &port,
                   const Reference &error_code,
                   const Reference &error_message,
                   const Variant &timeout) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[2550]);
    }
    return call(_fn, {hostname, port, &error_code, &error_message, timeout});
}
Variant http_build_query(const Variant &data,
                         const Variant &numeric_prefix,
                         const Variant &arg_separator,
                         const Variant &encoding_type) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[2551]);
    }
    return call(_fn, {data, numeric_prefix, arg_separator, encoding_type});
}
Variant http_get_last_response_headers() {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[2552]);
    }
    return call(_fn, {});
}
Variant http_clear_last_response_headers() {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[2553]);
    }
    return call(_fn, {});
}
Variant request_parse_body(const Variant &options) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[2554]);
    }
    return call(_fn, {options});
}
Variant image_type_to_mime_type(const Variant &image_type) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[2555]);
    }
    return call(_fn, {image_type});
}
Variant image_type_to_extension(const Variant &image_type, const Variant &include_dot) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[2556]);
    }
    return call(_fn, {image_type, include_dot});
}
Variant getimagesize(const Variant &filename, const Reference &image_info) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[2557]);
    }
    return call(_fn, {filename, &image_info});
}
Variant getimagesizefromstring(const Variant &string, const Reference &image_info) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[2558]);
    }
    return call(_fn, {string, &image_info});
}
Variant phpinfo(const Variant &flags) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[2559]);
    }
    return call(_fn, {flags});
}
Variant phpversion(const Variant &extension) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[2560]);
    }
    return call(_fn, {extension});
}
Variant phpcredits(const Variant &flags) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[2561]);
    }
    return call(_fn, {flags});
}
Variant php_sapi_name() {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[2562]);
    }
    return call(_fn, {});
}
Variant php_uname(const Variant &mode) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[2563]);
    }
    return call(_fn, {mode});
}
Variant php_ini_scanned_files() {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[2564]);
    }
    return call(_fn, {});
}
Variant php_ini_loaded_file() {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[2565]);
    }
    return call(_fn, {});
}
Variant iptcembed(const Variant &iptc_data, const Variant &filename, const Variant &spool) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[2566]);
    }
    return call(_fn, {iptc_data, filename, spool});
}
Variant iptcparse(const Variant &iptc_block) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[2567]);
    }
    return call(_fn, {iptc_block});
}
Variant levenshtein(const Variant &string1,
                    const Variant &string2,
                    const Variant &insertion_cost,
                    const Variant &replacement_cost,
                    const Variant &deletion_cost) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[2568]);
    }
    return call(_fn, {string1, string2, insertion_cost, replacement_cost, deletion_cost});
}
Variant readlink(const Variant &path) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[2569]);
    }
    return call(_fn, {path});
}
Variant linkinfo(const Variant &path) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[2570]);
    }
    return call(_fn, {path});
}
Variant symlink(const Variant &target, const Variant &link) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[2571]);
    }
    return call(_fn, {target, link});
}
Variant link(const Variant &target, const Variant &link) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[2572]);
    }
    return call(_fn, {target, link});
}
Variant mail(const Variant &to,
             const Variant &subject,
             const Variant &message,
             const Variant &additional_headers,
             const Variant &additional_params) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[2573]);
    }
    return call(_fn, {to, subject, message, additional_headers, additional_params});
}
Variant abs(const Variant &num) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[2574]);
    }
    return call(_fn, {num});
}
Variant ceil(const Variant &num) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[26]);
    }
    return call(_fn, {num});
}
Variant floor(const Variant &num) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[25]);
    }
    return call(_fn, {num});
}
Variant round(const Variant &num, const Variant &precision, const Variant &mode) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[27]);
    }
    return call(_fn, {num, precision, mode});
}
Variant sin(const Variant &num) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[2575]);
    }
    return call(_fn, {num});
}
Variant cos(const Variant &num) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[2576]);
    }
    return call(_fn, {num});
}
Variant tan(const Variant &num) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[2577]);
    }
    return call(_fn, {num});
}
Variant asin(const Variant &num) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[2578]);
    }
    return call(_fn, {num});
}
Variant acos(const Variant &num) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[2579]);
    }
    return call(_fn, {num});
}
Variant atan(const Variant &num) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[2580]);
    }
    return call(_fn, {num});
}
Variant atanh(const Variant &num) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[2581]);
    }
    return call(_fn, {num});
}
Variant atan2(const Variant &y, const Variant &x) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[2582]);
    }
    return call(_fn, {y, x});
}
Variant sinh(const Variant &num) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[2583]);
    }
    return call(_fn, {num});
}
Variant cosh(const Variant &num) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[2584]);
    }
    return call(_fn, {num});
}
Variant tanh(const Variant &num) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[2585]);
    }
    return call(_fn, {num});
}
Variant asinh(const Variant &num) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[2586]);
    }
    return call(_fn, {num});
}
Variant acosh(const Variant &num) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[2587]);
    }
    return call(_fn, {num});
}
Variant expm1(const Variant &num) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[2588]);
    }
    return call(_fn, {num});
}
Variant log1p(const Variant &num) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[2589]);
    }
    return call(_fn, {num});
}
Variant pi() {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[2590]);
    }
    return call(_fn, {});
}
Variant is_finite(const Variant &num) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[2591]);
    }
    return call(_fn, {num});
}
Variant is_nan(const Variant &num) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[2592]);
    }
    return call(_fn, {num});
}
Variant intdiv(const Variant &num1, const Variant &num2) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[2593]);
    }
    return call(_fn, {num1, num2});
}
Variant is_infinite(const Variant &num) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[2594]);
    }
    return call(_fn, {num});
}
Variant pow(const Variant &num, const Variant &exponent) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[23]);
    }
    return call(_fn, {num, exponent});
}
Variant exp(const Variant &num) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[2595]);
    }
    return call(_fn, {num});
}
Variant log(const Variant &num, const Variant &base) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[2596]);
    }
    return call(_fn, {num, base});
}
Variant log10(const Variant &num) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[2597]);
    }
    return call(_fn, {num});
}
Variant sqrt(const Variant &num) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[24]);
    }
    return call(_fn, {num});
}
Variant hypot(const Variant &x, const Variant &y) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[2598]);
    }
    return call(_fn, {x, y});
}
Variant deg2rad(const Variant &num) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[2599]);
    }
    return call(_fn, {num});
}
Variant rad2deg(const Variant &num) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[2600]);
    }
    return call(_fn, {num});
}
Variant bindec(const Variant &binary_string) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[2601]);
    }
    return call(_fn, {binary_string});
}
Variant hexdec(const Variant &hex_string) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[2602]);
    }
    return call(_fn, {hex_string});
}
Variant octdec(const Variant &octal_string) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[2603]);
    }
    return call(_fn, {octal_string});
}
Variant decbin(const Variant &num) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[2604]);
    }
    return call(_fn, {num});
}
Variant decoct(const Variant &num) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[2605]);
    }
    return call(_fn, {num});
}
Variant dechex(const Variant &num) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[2606]);
    }
    return call(_fn, {num});
}
Variant base_convert(const Variant &num, const Variant &from_base, const Variant &to_base) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[2607]);
    }
    return call(_fn, {num, from_base, to_base});
}
Variant number_format(const Variant &num,
                      const Variant &decimals,
                      const Variant &decimal_separator,
                      const Variant &thousands_separator) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[2608]);
    }
    return call(_fn, {num, decimals, decimal_separator, thousands_separator});
}
Variant fmod(const Variant &num1, const Variant &num2) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[2609]);
    }
    return call(_fn, {num1, num2});
}
Variant fdiv(const Variant &num1, const Variant &num2) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[2610]);
    }
    return call(_fn, {num1, num2});
}
Variant fpow(const Variant &num, const Variant &exponent) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[2611]);
    }
    return call(_fn, {num, exponent});
}
Variant microtime(const Variant &as_float) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[2612]);
    }
    return call(_fn, {as_float});
}
Variant gettimeofday(const Variant &as_float) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[2613]);
    }
    return call(_fn, {as_float});
}
Variant getrusage(const Variant &mode) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[2614]);
    }
    return call(_fn, {mode});
}
Variant unpack(const Variant &format, const Variant &string, const Variant &offset) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[2616]);
    }
    return call(_fn, {format, string, offset});
}
Variant password_get_info(const Variant &hash) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[2617]);
    }
    return call(_fn, {hash});
}
Variant password_hash(const Variant &password, const Variant &algo, const Variant &options) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[2618]);
    }
    return call(_fn, {password, algo, options});
}
Variant password_needs_rehash(const Variant &hash, const Variant &algo, const Variant &options) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[2619]);
    }
    return call(_fn, {hash, algo, options});
}
Variant password_verify(const Variant &password, const Variant &hash) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[2620]);
    }
    return call(_fn, {password, hash});
}
Variant password_algos() {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[2621]);
    }
    return call(_fn, {});
}
Variant proc_open(const Variant &command,
                  const Variant &descriptor_spec,
                  const Reference &pipes,
                  const Variant &cwd,
                  const Variant &env_vars,
                  const Variant &options) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[2622]);
    }
    return call(_fn, {command, descriptor_spec, &pipes, cwd, env_vars, options});
}
Variant proc_close(const Variant &process) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[2623]);
    }
    return call(_fn, {process});
}
Variant proc_terminate(const Variant &process, const Variant &signal) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[2624]);
    }
    return call(_fn, {process, signal});
}
Variant proc_get_status(const Variant &process) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[2625]);
    }
    return call(_fn, {process});
}
Variant quoted_printable_decode(const Variant &string) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[2626]);
    }
    return call(_fn, {string});
}
Variant quoted_printable_encode(const Variant &string) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[2627]);
    }
    return call(_fn, {string});
}
Variant soundex(const Variant &string) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[2628]);
    }
    return call(_fn, {string});
}
Variant stream_select(const Reference &read,
                      const Reference &write,
                      const Reference &except,
                      const Variant &seconds,
                      const Variant &microseconds) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[2629]);
    }
    return call(_fn, {&read, &write, &except, seconds, microseconds});
}
Variant stream_context_create(const Variant &options, const Variant &params) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[2630]);
    }
    return call(_fn, {options, params});
}
Variant stream_context_set_params(const Variant &context, const Variant &params) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[2631]);
    }
    return call(_fn, {context, params});
}
Variant stream_context_get_params(const Variant &context) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[2632]);
    }
    return call(_fn, {context});
}
Variant stream_context_set_option(const Variant &context,
                                  const Variant &wrapper_or_options,
                                  const Variant &option_name,
                                  const Variant &value) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[2633]);
    }
    return call(_fn, {context, wrapper_or_options, option_name, value});
}
Variant stream_context_set_options(const Variant &context, const Variant &options) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[2634]);
    }
    return call(_fn, {context, options});
}
Variant stream_context_get_options(const Variant &stream_or_context) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[2635]);
    }
    return call(_fn, {stream_or_context});
}
Variant stream_context_get_default(const Variant &options) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[2636]);
    }
    return call(_fn, {options});
}
Variant stream_context_set_default(const Variant &options) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[2637]);
    }
    return call(_fn, {options});
}
Variant stream_filter_prepend(const Variant &stream,
                              const Variant &filter_name,
                              const Variant &mode,
                              const Variant &params) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[2638]);
    }
    return call(_fn, {stream, filter_name, mode, params});
}
Variant stream_filter_append(const Variant &stream,
                             const Variant &filter_name,
                             const Variant &mode,
                             const Variant &params) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[2639]);
    }
    return call(_fn, {stream, filter_name, mode, params});
}
Variant stream_filter_remove(const Variant &stream_filter) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[2640]);
    }
    return call(_fn, {stream_filter});
}
Variant stream_socket_client(const Variant &address,
                             const Reference &error_code,
                             const Reference &error_message,
                             const Variant &timeout,
                             const Variant &flags,
                             const Variant &context) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[2641]);
    }
    return call(_fn, {address, &error_code, &error_message, timeout, flags, context});
}
Variant stream_socket_server(const Variant &address,
                             const Reference &error_code,
                             const Reference &error_message,
                             const Variant &flags,
                             const Variant &context) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[2642]);
    }
    return call(_fn, {address, &error_code, &error_message, flags, context});
}
Variant stream_socket_accept(const Variant &socket, const Variant &timeout, const Reference &peer_name) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[2643]);
    }
    return call(_fn, {socket, timeout, &peer_name});
}
Variant stream_socket_get_name(const Variant &socket, const Variant &remote) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[2644]);
    }
    return call(_fn, {socket, remote});
}
Variant stream_socket_recvfrom(const Variant &socket,
                               const Variant &length,
                               const Variant &flags,
                               const Reference &address) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[2645]);
    }
    return call(_fn, {socket, length, flags, &address});
}
Variant stream_socket_sendto(const Variant &socket, const Variant &data, const Variant &flags, const Variant &address) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[2646]);
    }
    return call(_fn, {socket, data, flags, address});
}
Variant stream_socket_enable_crypto(const Variant &stream,
                                    const Variant &enable,
                                    const Variant &crypto_method,
                                    const Variant &session_stream) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[2647]);
    }
    return call(_fn, {stream, enable, crypto_method, session_stream});
}
Variant stream_socket_shutdown(const Variant &stream, const Variant &mode) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[2648]);
    }
    return call(_fn, {stream, mode});
}
Variant stream_socket_pair(const Variant &domain, const Variant &type, const Variant &protocol) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[2649]);
    }
    return call(_fn, {domain, type, protocol});
}
Variant stream_copy_to_stream(const Variant &from, const Variant &to, const Variant &length, const Variant &offset) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[2650]);
    }
    return call(_fn, {from, to, length, offset});
}
Variant stream_get_contents(const Variant &stream, const Variant &length, const Variant &offset) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[2651]);
    }
    return call(_fn, {stream, length, offset});
}
Variant stream_supports_lock(const Variant &stream) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[2652]);
    }
    return call(_fn, {stream});
}
Variant stream_set_write_buffer(const Variant &stream, const Variant &size) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[2653]);
    }
    return call(_fn, {stream, size});
}
Variant set_file_buffer(const Variant &stream, const Variant &size) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[2654]);
    }
    return call(_fn, {stream, size});
}
Variant stream_set_read_buffer(const Variant &stream, const Variant &size) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[2655]);
    }
    return call(_fn, {stream, size});
}
Variant stream_set_blocking(const Variant &stream, const Variant &enable) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[2656]);
    }
    return call(_fn, {stream, enable});
}
Variant socket_set_blocking(const Variant &stream, const Variant &enable) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[2657]);
    }
    return call(_fn, {stream, enable});
}
Variant stream_get_meta_data(const Variant &stream) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[2658]);
    }
    return call(_fn, {stream});
}
Variant socket_get_status(const Variant &stream) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[2659]);
    }
    return call(_fn, {stream});
}
Variant stream_get_line(const Variant &stream, const Variant &length, const Variant &ending) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[2660]);
    }
    return call(_fn, {stream, length, ending});
}
Variant stream_resolve_include_path(const Variant &filename) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[2661]);
    }
    return call(_fn, {filename});
}
Variant stream_get_wrappers() {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[2662]);
    }
    return call(_fn, {});
}
Variant stream_get_transports() {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[2663]);
    }
    return call(_fn, {});
}
Variant stream_is_local(const Variant &stream) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[2664]);
    }
    return call(_fn, {stream});
}
Variant stream_isatty(const Variant &stream) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[2665]);
    }
    return call(_fn, {stream});
}
Variant stream_set_chunk_size(const Variant &stream, const Variant &size) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[2666]);
    }
    return call(_fn, {stream, size});
}
Variant stream_set_timeout(const Variant &stream, const Variant &seconds, const Variant &microseconds) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[2667]);
    }
    return call(_fn, {stream, seconds, microseconds});
}
Variant socket_set_timeout(const Variant &stream, const Variant &seconds, const Variant &microseconds) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[2668]);
    }
    return call(_fn, {stream, seconds, microseconds});
}
Variant gettype(const Variant &value) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[2669]);
    }
    return call(_fn, {value});
}
Variant get_debug_type(const Variant &value) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[2670]);
    }
    return call(_fn, {value});
}
Variant settype(const Reference &var, const Variant &type) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[2671]);
    }
    return call(_fn, {&var, type});
}
Variant intval(const Variant &value, const Variant &base) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[2672]);
    }
    return call(_fn, {value, base});
}
Variant floatval(const Variant &value) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[2673]);
    }
    return call(_fn, {value});
}
Variant doubleval(const Variant &value) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[2674]);
    }
    return call(_fn, {value});
}
Variant boolval(const Variant &value) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[2675]);
    }
    return call(_fn, {value});
}
Variant strval(const Variant &value) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[2676]);
    }
    return call(_fn, {value});
}
Variant is_null(const Variant &value) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[2677]);
    }
    return call(_fn, {value});
}
Variant is_resource(const Variant &value) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[2678]);
    }
    return call(_fn, {value});
}
Variant is_bool(const Variant &value) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[2679]);
    }
    return call(_fn, {value});
}
Variant is_int(const Variant &value) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[2680]);
    }
    return call(_fn, {value});
}
Variant is_integer(const Variant &value) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[2681]);
    }
    return call(_fn, {value});
}
Variant is_long(const Variant &value) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[2682]);
    }
    return call(_fn, {value});
}
Variant is_float(const Variant &value) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[2683]);
    }
    return call(_fn, {value});
}
Variant is_double(const Variant &value) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[2684]);
    }
    return call(_fn, {value});
}
Variant is_numeric(const Variant &value) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[2685]);
    }
    return call(_fn, {value});
}
Variant is_string(const Variant &value) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[2686]);
    }
    return call(_fn, {value});
}
Variant is_array(const Variant &value) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[2687]);
    }
    return call(_fn, {value});
}
Variant is_object(const Variant &value) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[2688]);
    }
    return call(_fn, {value});
}
Variant is_scalar(const Variant &value) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[2689]);
    }
    return call(_fn, {value});
}
Variant is_callable(const Variant &value, const Variant &syntax_only, const Reference &callable_name) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[2690]);
    }
    return call(_fn, {value, syntax_only, &callable_name});
}
Variant is_iterable(const Variant &value) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[2691]);
    }
    return call(_fn, {value});
}
Variant is_countable(const Variant &value) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[2692]);
    }
    return call(_fn, {value});
}
Variant uniqid(const Variant &prefix, const Variant &more_entropy) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[2693]);
    }
    return call(_fn, {prefix, more_entropy});
}
Variant parse_url(const Variant &url, const Variant &component) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[2694]);
    }
    return call(_fn, {url, component});
}
Variant urlencode(const Variant &string) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[2695]);
    }
    return call(_fn, {string});
}
Variant urldecode(const Variant &string) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[2696]);
    }
    return call(_fn, {string});
}
Variant rawurlencode(const Variant &string) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[2697]);
    }
    return call(_fn, {string});
}
Variant rawurldecode(const Variant &string) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[2698]);
    }
    return call(_fn, {string});
}
Variant get_headers(const Variant &url, const Variant &associative, const Variant &context) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[2699]);
    }
    return call(_fn, {url, associative, context});
}
StreamBucket stream_bucket_make_writeable(const Variant &brigade) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[2700]);
    }
    return StreamBucket(Object(call(_fn, {brigade})));
}
Variant stream_bucket_prepend(const Variant &brigade, const StreamBucket &bucket) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[2701]);
    }
    return call(_fn, {brigade, bucket.getObject()});
}
Variant stream_bucket_prepend(const Variant &brigade, const Variant &bucket) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[2701]);
    }
    return call(_fn, {brigade, bucket});
}
Variant stream_bucket_append(const Variant &brigade, const StreamBucket &bucket) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[2702]);
    }
    return call(_fn, {brigade, bucket.getObject()});
}
Variant stream_bucket_append(const Variant &brigade, const Variant &bucket) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[2702]);
    }
    return call(_fn, {brigade, bucket});
}
StreamBucket stream_bucket_new(const Variant &stream, const Variant &buffer) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[2703]);
    }
    return StreamBucket(Object(call(_fn, {stream, buffer})));
}
Variant stream_get_filters() {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[2704]);
    }
    return call(_fn, {});
}
Variant stream_filter_register(const Variant &filter_name, const Variant &class_) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[2705]);
    }
    return call(_fn, {filter_name, class_});
}
Variant convert_uuencode(const Variant &string) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[2706]);
    }
    return call(_fn, {string});
}
Variant convert_uudecode(const Variant &string) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[2707]);
    }
    return call(_fn, {string});
}
Variant var_export(const Variant &value, const Variant &return_) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[2709]);
    }
    return call(_fn, {value, return_});
}
Variant serialize(const Variant &value) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[2095]);
    }
    return call(_fn, {value});
}
Variant unserialize(const Variant &data, const Variant &options) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[2094]);
    }
    return call(_fn, {data, options});
}
Variant memory_get_usage(const Variant &real_usage) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[2711]);
    }
    return call(_fn, {real_usage});
}
Variant memory_get_peak_usage(const Variant &real_usage) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[2712]);
    }
    return call(_fn, {real_usage});
}
Variant memory_reset_peak_usage() {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[2713]);
    }
    return call(_fn, {});
}
Variant version_compare(const Variant &version1, const Variant &version2, const Variant &operator_) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[2714]);
    }
    return call(_fn, {version1, version2, operator_});
}
Variant dl(const Variant &extension_filename) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[2715]);
    }
    return call(_fn, {extension_filename});
}
Variant cli_set_process_title(const Variant &title) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[2716]);
    }
    return call(_fn, {title});
}
Variant cli_get_process_title() {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[2717]);
    }
    return call(_fn, {});
}
}  // namespace php

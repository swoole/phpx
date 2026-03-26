#include "phpx.h"
#include "phpx_literal_string.h"

namespace php {
Variant set_time_limit(const Variant &seconds);
Variant header_register_callback(const Variant &callback);
Variant ob_start(const Variant &callback = {}, const Variant &chunk_size = 0, const Variant &flags = 112);
Variant ob_flush();
Variant ob_clean();
Variant ob_end_flush();
Variant ob_end_clean();
Variant ob_get_flush();
Variant ob_get_clean();
Variant ob_get_contents();
Variant ob_get_level();
Variant ob_get_length();
Variant ob_list_handlers();
Variant ob_get_status(const Variant &full_status = false);
Variant ob_implicit_flush(const Variant &enable = true);
Variant output_reset_rewrite_vars();
Variant output_add_rewrite_var(const Variant &name, const Variant &value);
Variant stream_wrapper_register(const Variant &protocol, const Variant &_class, const Variant &flags = 0);
Variant stream_register_wrapper(const Variant &protocol, const Variant &_class, const Variant &flags = 0);
Variant stream_wrapper_unregister(const Variant &protocol);
Variant stream_wrapper_restore(const Variant &protocol);
template <typename... Args>
Variant array_push(const Reference &array, const Args &...values) {
    return call(LITERAL_STRING[1873], {&array, values...});
}
Variant krsort(const Reference &array, const Variant &flags = 0);
Variant ksort(const Reference &array, const Variant &flags = 0);
Variant count(const Variant &value, const Variant &mode = 0);
Variant natsort(const Reference &array);
Variant natcasesort(const Reference &array);
Variant asort(const Reference &array, const Variant &flags = 0);
Variant arsort(const Reference &array, const Variant &flags = 0);
Variant sort(const Reference &array, const Variant &flags = 0);
Variant rsort(const Reference &array, const Variant &flags = 0);
Variant usort(const Reference &array, const Variant &callback);
Variant uasort(const Reference &array, const Variant &callback);
Variant uksort(const Reference &array, const Variant &callback);
Variant end(const Reference &array);
Variant prev(const Reference &array);
Variant next(const Reference &array);
Variant reset(const Reference &array);
Variant current(const Variant &array);
Variant pos(const Variant &array);
Variant key(const Variant &array);
template <typename... Args>
Variant min(const Variant &value, const Args &...values) {
    return call(LITERAL_STRING[1880], {value, values...});
}
template <typename... Args>
Variant max(const Variant &value, const Args &...values) {
    return call(LITERAL_STRING[1881], {value, values...});
}
Variant array_walk(const Reference &array, const Variant &callback, const Variant &arg = {});
Variant array_walk_recursive(const Reference &array, const Variant &callback, const Variant &arg = {});
Variant in_array(const Variant &needle, const Variant &haystack, const Variant &strict = false);
Variant array_search(const Variant &needle, const Variant &haystack, const Variant &strict = false);
Variant extract(const Reference &array, const Variant &flags = 0, const Variant &prefix = "");
template <typename... Args>
Variant compact(const Variant &var_name, const Args &...var_names) {
    return call(LITERAL_STRING[1886], {var_name, var_names...});
}
Variant array_fill(const Variant &start_index, const Variant &count, const Variant &value);
Variant array_fill_keys(const Variant &keys, const Variant &value);
Variant range(const Variant &start, const Variant &end, const Variant &step = 1);
Variant shuffle(const Reference &array);
Variant array_pop(const Reference &array);
Variant array_shift(const Reference &array);
template <typename... Args>
Variant array_unshift(const Reference &array, const Args &...values) {
    return call(LITERAL_STRING[1893], {&array, values...});
}
Variant array_splice(const Reference &array,
                     const Variant &offset,
                     const Variant &length = {},
                     const Variant &replacement = Array{});
Variant array_slice(const Variant &array,
                    const Variant &offset,
                    const Variant &length = {},
                    const Variant &preserve_keys = false);
template <typename... Args>
Variant array_merge(const Args &...arrays) {
    return call(LITERAL_STRING[1896], {arrays...});
}
template <typename... Args>
Variant array_merge_recursive(const Args &...arrays) {
    return call(LITERAL_STRING[1897], {arrays...});
}
template <typename... Args>
Variant array_replace(const Variant &array, const Args &...replacements) {
    return call(LITERAL_STRING[1898], {array, replacements...});
}
template <typename... Args>
Variant array_replace_recursive(const Variant &array, const Args &...replacements) {
    return call(LITERAL_STRING[1899], {array, replacements...});
}
Variant array_keys(const Variant &array, const Variant &filter_value = {}, const Variant &strict = false);
Variant array_key_first(const Variant &array);
Variant array_key_last(const Variant &array);
Variant array_values(const Variant &array);
Variant array_count_values(const Variant &array);
Variant array_column(const Variant &array, const Variant &column_key, const Variant &index_key = {});
Variant array_reverse(const Variant &array, const Variant &preserve_keys = false);
Variant array_pad(const Variant &array, const Variant &length, const Variant &value);
Variant array_flip(const Variant &array);
Variant array_change_key_case(const Variant &array, const Variant &_case = 0);
Variant array_unique(const Variant &array, const Variant &flags = 2);
template <typename... Args>
Variant array_intersect_key(const Variant &array, const Args &...arrays) {
    return call(LITERAL_STRING[1911], {array, arrays...});
}
template <typename... Args>
Variant array_intersect_ukey(const Variant &array, const Args &...rest) {
    return call(LITERAL_STRING[1912], {array, rest...});
}
template <typename... Args>
Variant array_intersect(const Variant &array, const Args &...arrays) {
    return call(LITERAL_STRING[1913], {array, arrays...});
}
template <typename... Args>
Variant array_uintersect(const Variant &array, const Args &...rest) {
    return call(LITERAL_STRING[1914], {array, rest...});
}
template <typename... Args>
Variant array_intersect_assoc(const Variant &array, const Args &...arrays) {
    return call(LITERAL_STRING[1915], {array, arrays...});
}
template <typename... Args>
Variant array_uintersect_assoc(const Variant &array, const Args &...rest) {
    return call(LITERAL_STRING[1916], {array, rest...});
}
template <typename... Args>
Variant array_intersect_uassoc(const Variant &array, const Args &...rest) {
    return call(LITERAL_STRING[1917], {array, rest...});
}
template <typename... Args>
Variant array_uintersect_uassoc(const Variant &array, const Args &...rest) {
    return call(LITERAL_STRING[1918], {array, rest...});
}
template <typename... Args>
Variant array_diff_key(const Variant &array, const Args &...arrays) {
    return call(LITERAL_STRING[1919], {array, arrays...});
}
template <typename... Args>
Variant array_diff_ukey(const Variant &array, const Args &...rest) {
    return call(LITERAL_STRING[1920], {array, rest...});
}
template <typename... Args>
Variant array_diff(const Variant &array, const Args &...arrays) {
    return call(LITERAL_STRING[1921], {array, arrays...});
}
template <typename... Args>
Variant array_udiff(const Variant &array, const Args &...rest) {
    return call(LITERAL_STRING[1922], {array, rest...});
}
template <typename... Args>
Variant array_diff_assoc(const Variant &array, const Args &...arrays) {
    return call(LITERAL_STRING[1923], {array, arrays...});
}
template <typename... Args>
Variant array_diff_uassoc(const Variant &array, const Args &...rest) {
    return call(LITERAL_STRING[1924], {array, rest...});
}
template <typename... Args>
Variant array_udiff_assoc(const Variant &array, const Args &...rest) {
    return call(LITERAL_STRING[1925], {array, rest...});
}
template <typename... Args>
Variant array_udiff_uassoc(const Variant &array, const Args &...rest) {
    return call(LITERAL_STRING[1926], {array, rest...});
}
template <typename... Args>
Variant array_multisort(const Reference &array, const Args &...rest) {
    return call(LITERAL_STRING[1927], {&array, rest...});
}
Variant array_rand(const Variant &array, const Variant &num = 1);
Variant array_sum(const Variant &array);
Variant array_product(const Variant &array);
Variant array_reduce(const Variant &array, const Variant &callback, const Variant &initial = {});
Variant array_filter(const Variant &array, const Variant &callback = {}, const Variant &mode = 0);
Variant array_find(const Variant &array, const Variant &callback);
Variant array_find_key(const Variant &array, const Variant &callback);
Variant array_any(const Variant &array, const Variant &callback);
Variant array_all(const Variant &array, const Variant &callback);
template <typename... Args>
Variant array_map(const Variant &callback, const Variant &array, const Args &...arrays) {
    return call(LITERAL_STRING[1937], {callback, array, arrays...});
}
Variant array_key_exists(const Variant &key, const Variant &array);
Variant key_exists(const Variant &key, const Variant &array);
Variant array_chunk(const Variant &array, const Variant &length, const Variant &preserve_keys = false);
Variant array_combine(const Variant &keys, const Variant &values);
Variant array_is_list(const Variant &array);
Variant base64_encode(const Variant &string);
Variant base64_decode(const Variant &string, const Variant &strict = false);
Variant ip2long(const Variant &ip);
Variant long2ip(const Variant &ip);
Variant getenv(const Variant &name = {}, const Variant &local_only = false);
Variant putenv(const Variant &assignment);
Variant getopt(const Variant &short_options, const Variant &long_options = Array{}, const Reference &rest_index = {});
Variant flush();
Variant sleep(const Variant &seconds);
Variant usleep(const Variant &microseconds);
Variant time_nanosleep(const Variant &seconds, const Variant &nanoseconds);
Variant time_sleep_until(const Variant &timestamp);
Variant get_current_user();
Variant get_cfg_var(const Variant &option);
Variant error_log(const Variant &message,
                  const Variant &message_type = 0,
                  const Variant &destination = {},
                  const Variant &additional_headers = {});
Variant error_get_last();
Variant error_clear_last();
template <typename... Args>
Variant call_user_func(const Variant &callback, const Args &...args) {
    return call(LITERAL_STRING[1960], {callback, args...});
}
Variant call_user_func_array(const Variant &callback, const Variant &args);
template <typename... Args>
Variant forward_static_call(const Variant &callback, const Args &...args) {
    return call(LITERAL_STRING[1962], {callback, args...});
}
Variant forward_static_call_array(const Variant &callback, const Variant &args);
template <typename... Args>
Variant register_shutdown_function(const Variant &callback, const Args &...args) {
    return call(LITERAL_STRING[1964], {callback, args...});
}
Variant highlight_file(const Variant &filename, const Variant &_return = false);
Variant show_source(const Variant &filename, const Variant &_return = false);
Variant php_strip_whitespace(const Variant &filename);
Variant highlight_string(const Variant &string, const Variant &_return = false);
Variant ini_get(const Variant &option);
Variant ini_get_all(const Variant &extension = {}, const Variant &details = true);
Variant ini_set(const Variant &option, const Variant &value);
Variant ini_alter(const Variant &option, const Variant &value);
Variant ini_restore(const Variant &option);
Variant ini_parse_quantity(const Variant &shorthand);
Variant set_include_path(const Variant &include_path);
Variant get_include_path();
Variant print_r(const Variant &value, const Variant &_return = false);
Variant connection_aborted();
Variant connection_status();
Variant ignore_user_abort(const Variant &enable = {});
Variant getservbyname(const Variant &service, const Variant &protocol);
Variant getservbyport(const Variant &port, const Variant &protocol);
Variant getprotobyname(const Variant &protocol);
Variant getprotobynumber(const Variant &protocol);
template <typename... Args>
Variant register_tick_function(const Variant &callback, const Args &...args) {
    return call(LITERAL_STRING[1985], {callback, args...});
}
Variant unregister_tick_function(const Variant &callback);
Variant is_uploaded_file(const Variant &filename);
Variant move_uploaded_file(const Variant &from, const Variant &to);
Variant parse_ini_file(const Variant &filename,
                       const Variant &process_sections = false,
                       const Variant &scanner_mode = 0);
Variant parse_ini_string(const Variant &ini_string,
                         const Variant &process_sections = false,
                         const Variant &scanner_mode = 0);
Variant config_get_hash();
Variant sys_getloadavg();
Variant get_browser(const Variant &user_agent = {}, const Variant &return_array = false);
Variant crc32(const Variant &string);
Variant crypt(const Variant &string, const Variant &salt);
Variant strptime(const Variant &timestamp, const Variant &format);
Variant gethostname();
Variant gethostbyaddr(const Variant &ip);
Variant gethostbyname(const Variant &hostname);
Variant gethostbynamel(const Variant &hostname);
Variant dns_check_record(const Variant &hostname, const Variant &type = "MX");
Variant checkdnsrr(const Variant &hostname, const Variant &type = "MX");
Variant dns_get_record(const Variant &hostname,
                       const Variant &type = 268435456,
                       const Reference &authoritative_name_servers = {},
                       const Reference &additional_records = {},
                       const Variant &raw = false);
Variant dns_get_mx(const Variant &hostname, const Reference &hosts, const Reference &weights = {});
Variant getmxrr(const Variant &hostname, const Reference &hosts, const Reference &weights = {});
Variant net_get_interfaces();
Variant ftok(const Variant &filename, const Variant &project_id);
Variant hrtime(const Variant &as_number = false);
Variant md5(const Variant &string, const Variant &binary = false);
Variant md5_file(const Variant &filename, const Variant &binary = false);
Variant getmyuid();
Variant getmygid();
Variant getmypid();
Variant getmyinode();
Variant getlastmod();
Variant sha1(const Variant &string, const Variant &binary = false);
Variant sha1_file(const Variant &filename, const Variant &binary = false);
Variant openlog(const Variant &prefix, const Variant &flags, const Variant &facility);
Variant closelog();
Variant syslog(const Variant &priority, const Variant &message);
Variant inet_ntop(const Variant &ip);
Variant inet_pton(const Variant &ip);
Variant metaphone(const Variant &string, const Variant &max_phonemes = 0);
Variant header(const Variant &header, const Variant &replace = true, const Variant &response_code = 0);
Variant header_remove(const Variant &name = {});
Variant setrawcookie(const Variant &name,
                     const Variant &value = "",
                     const Variant &expires_or_options = 0,
                     const Variant &path = "",
                     const Variant &domain = "",
                     const Variant &secure = false,
                     const Variant &httponly = false);
Variant setcookie(const Variant &name,
                  const Variant &value = "",
                  const Variant &expires_or_options = 0,
                  const Variant &path = "",
                  const Variant &domain = "",
                  const Variant &secure = false,
                  const Variant &httponly = false);
Variant http_response_code(const Variant &response_code = 0);
Variant headers_sent(const Reference &filename = {}, const Reference &line = {});
Variant headers_list();
Variant htmlspecialchars(const Variant &string,
                         const Variant &flags = 11,
                         const Variant &encoding = {},
                         const Variant &double_encode = true);
Variant htmlspecialchars_decode(const Variant &string, const Variant &flags = 11);
Variant html_entity_decode(const Variant &string, const Variant &flags = 11, const Variant &encoding = {});
Variant htmlentities(const Variant &string,
                     const Variant &flags = 11,
                     const Variant &encoding = {},
                     const Variant &double_encode = true);
Variant get_html_translation_table(const Variant &table = 0,
                                   const Variant &flags = 11,
                                   const Variant &encoding = "UTF-8");
Variant assert_options(const Variant &option, const Variant &value = {});
Variant bin2hex(const Variant &string);
Variant hex2bin(const Variant &string);
Variant strspn(const Variant &string, const Variant &characters, const Variant &offset = 0, const Variant &length = {});
Variant strcspn(const Variant &string,
                const Variant &characters,
                const Variant &offset = 0,
                const Variant &length = {});
Variant nl_langinfo(const Variant &item);
Variant strcoll(const Variant &string1, const Variant &string2);
Variant trim(const Variant &string, const Variant &characters = " \n\r\t\v\000");
Variant rtrim(const Variant &string, const Variant &characters = " \n\r\t\v\000");
Variant chop(const Variant &string, const Variant &characters = " \n\r\t\v\000");
Variant ltrim(const Variant &string, const Variant &characters = " \n\r\t\v\000");
Variant wordwrap(const Variant &string,
                 const Variant &width = 75,
                 const Variant &_break = "\n",
                 const Variant &cut_long_words = false);
Variant explode(const Variant &separator, const Variant &string, const Variant &limit = LONG_MAX);
Variant implode(const Variant &separator, const Variant &array = {});
Variant join(const Variant &separator, const Variant &array = {});
Variant strtok(const Variant &string, const Variant &token = {});
Variant strtoupper(const Variant &string);
Variant strtolower(const Variant &string);
Variant str_increment(const Variant &string);
Variant str_decrement(const Variant &string);
Variant basename(const Variant &path, const Variant &suffix = "");
Variant dirname(const Variant &path, const Variant &levels = 1);
Variant pathinfo(const Variant &path, const Variant &flags = 15);
Variant stristr(const Variant &haystack, const Variant &needle, const Variant &before_needle = false);
Variant strstr(const Variant &haystack, const Variant &needle, const Variant &before_needle = false);
Variant strchr(const Variant &haystack, const Variant &needle, const Variant &before_needle = false);
Variant strpos(const Variant &haystack, const Variant &needle, const Variant &offset = 0);
Variant stripos(const Variant &haystack, const Variant &needle, const Variant &offset = 0);
Variant strrpos(const Variant &haystack, const Variant &needle, const Variant &offset = 0);
Variant strripos(const Variant &haystack, const Variant &needle, const Variant &offset = 0);
Variant strrchr(const Variant &haystack, const Variant &needle, const Variant &before_needle = false);
Variant str_contains(const Variant &haystack, const Variant &needle);
Variant str_starts_with(const Variant &haystack, const Variant &needle);
Variant str_ends_with(const Variant &haystack, const Variant &needle);
Variant chunk_split(const Variant &string, const Variant &length = 76, const Variant &separator = "\r\n");
Variant substr(const Variant &string, const Variant &offset, const Variant &length = {});
Variant substr_replace(const Variant &string,
                       const Variant &replace,
                       const Variant &offset,
                       const Variant &length = {});
Variant quotemeta(const Variant &string);
Variant ord(const Variant &character);
Variant chr(const Variant &codepoint);
Variant ucfirst(const Variant &string);
Variant lcfirst(const Variant &string);
Variant ucwords(const Variant &string, const Variant &separators = " \t\r\n\f\v");
Variant strtr(const Variant &string, const Variant &from, const Variant &to = {});
Variant strrev(const Variant &string);
Variant similar_text(const Variant &string1, const Variant &string2, const Reference &percent = {});
Variant addcslashes(const Variant &string, const Variant &characters);
Variant addslashes(const Variant &string);
Variant stripcslashes(const Variant &string);
Variant stripslashes(const Variant &string);
Variant str_replace(const Variant &search, const Variant &replace, const Variant &subject, const Reference &count = {});
Variant str_ireplace(const Variant &search,
                     const Variant &replace,
                     const Variant &subject,
                     const Reference &count = {});
Variant hebrev(const Variant &string, const Variant &max_chars_per_line = 0);
Variant nl2br(const Variant &string, const Variant &use_xhtml = true);
Variant strip_tags(const Variant &string, const Variant &allowed_tags = {});
template <typename... Args>
Variant setlocale(const Variant &category, const Variant &locales, const Args &...rest) {
    return call(LITERAL_STRING[2090], {category, locales, rest...});
}
Variant parse_str(const Variant &string, const Reference &result);
Variant str_getcsv(const Variant &string,
                   const Variant &separator = ",",
                   const Variant &enclosure = "\"",
                   const Variant &escape = "\\");
Variant str_repeat(const Variant &string, const Variant &times);
Variant count_chars(const Variant &string, const Variant &mode = 0);
Variant localeconv();
Variant substr_count(const Variant &haystack,
                     const Variant &needle,
                     const Variant &offset = 0,
                     const Variant &length = {});
Variant str_pad(const Variant &string,
                const Variant &length,
                const Variant &pad_string = " ",
                const Variant &pad_type = 1);
template <typename... Args>
Variant sscanf(const Variant &string, const Variant &format, const Args &...vars) {
    return call(LITERAL_STRING[2098], {string, format, vars...});
}
Variant str_rot13(const Variant &string);
Variant str_shuffle(const Variant &string);
Variant str_word_count(const Variant &string, const Variant &format = 0, const Variant &characters = {});
Variant str_split(const Variant &string, const Variant &length = 1);
Variant strpbrk(const Variant &string, const Variant &characters);
Variant substr_compare(const Variant &haystack,
                       const Variant &needle,
                       const Variant &offset,
                       const Variant &length = {},
                       const Variant &case_insensitive = false);
Variant utf8_encode(const Variant &string);
Variant utf8_decode(const Variant &string);
Variant opendir(const Variant &directory, const Variant &context = {});
Variant dir(const Variant &directory, const Variant &context = {});
Variant closedir(const Variant &dir_handle = {});
Variant chdir(const Variant &directory);
Variant getcwd();
Variant rewinddir(const Variant &dir_handle = {});
Variant readdir(const Variant &dir_handle = {});
Variant scandir(const Variant &directory, const Variant &sorting_order = 0, const Variant &context = {});
Variant glob(const Variant &pattern, const Variant &flags = 0);
Variant exec(const Variant &command, const Reference &output = {}, const Reference &result_code = {});
Variant system(const Variant &command, const Reference &result_code = {});
Variant passthru(const Variant &command, const Reference &result_code = {});
Variant escapeshellcmd(const Variant &command);
Variant escapeshellarg(const Variant &arg);
Variant shell_exec(const Variant &command);
Variant proc_nice(const Variant &priority);
Variant flock(const Variant &stream, const Variant &operation, const Reference &would_block = {});
Variant get_meta_tags(const Variant &filename, const Variant &use_include_path = false);
Variant pclose(const Variant &handle);
Variant popen(const Variant &command, const Variant &mode);
Variant readfile(const Variant &filename, const Variant &use_include_path = false, const Variant &context = {});
Variant rewind(const Variant &stream);
Variant rmdir(const Variant &directory, const Variant &context = {});
Variant umask(const Variant &mask = {});
Variant fclose(const Variant &stream);
Variant feof(const Variant &stream);
Variant fgetc(const Variant &stream);
Variant fgets(const Variant &stream, const Variant &length = {});
Variant fread(const Variant &stream, const Variant &length);
Variant fopen(const Variant &filename,
              const Variant &mode,
              const Variant &use_include_path = false,
              const Variant &context = {});
template <typename... Args>
Variant fscanf(const Variant &stream, const Variant &format, const Args &...vars) {
    return call(LITERAL_STRING[1775], {stream, format, vars...});
}
Variant fpassthru(const Variant &stream);
Variant ftruncate(const Variant &stream, const Variant &size);
Variant fstat(const Variant &stream);
Variant fseek(const Variant &stream, const Variant &offset, const Variant &whence = 0);
Variant ftell(const Variant &stream);
Variant fflush(const Variant &stream);
Variant fsync(const Variant &stream);
Variant fdatasync(const Variant &stream);
Variant fwrite(const Variant &stream, const Variant &data, const Variant &length = {});
Variant fputs(const Variant &stream, const Variant &data, const Variant &length = {});
Variant mkdir(const Variant &directory,
              const Variant &permissions = 511,
              const Variant &recursive = false,
              const Variant &context = {});
Variant rename(const Variant &from, const Variant &to, const Variant &context = {});
Variant copy(const Variant &from, const Variant &to, const Variant &context = {});
Variant tempnam(const Variant &directory, const Variant &prefix);
Variant tmpfile();
Variant file(const Variant &filename, const Variant &flags = 0, const Variant &context = {});
Variant file_get_contents(const Variant &filename,
                          const Variant &use_include_path = false,
                          const Variant &context = {},
                          const Variant &offset = 0,
                          const Variant &length = {});
Variant unlink(const Variant &filename, const Variant &context = {});
Variant file_put_contents(const Variant &filename,
                          const Variant &data,
                          const Variant &flags = 0,
                          const Variant &context = {});
Variant fputcsv(const Variant &stream,
                const Variant &fields,
                const Variant &separator = ",",
                const Variant &enclosure = "\"",
                const Variant &escape = "\\",
                const Variant &eol = "\n");
Variant fgetcsv(const Variant &stream,
                const Variant &length = {},
                const Variant &separator = ",",
                const Variant &enclosure = "\"",
                const Variant &escape = "\\");
Variant realpath(const Variant &path);
Variant fnmatch(const Variant &pattern, const Variant &filename, const Variant &flags = 0);
Variant sys_get_temp_dir();
Variant fileatime(const Variant &filename);
Variant filectime(const Variant &filename);
Variant filegroup(const Variant &filename);
Variant fileinode(const Variant &filename);
Variant filemtime(const Variant &filename);
Variant fileowner(const Variant &filename);
Variant fileperms(const Variant &filename);
Variant filesize(const Variant &filename);
Variant filetype(const Variant &filename);
Variant file_exists(const Variant &filename);
Variant is_writable(const Variant &filename);
Variant is_writeable(const Variant &filename);
Variant is_readable(const Variant &filename);
Variant is_executable(const Variant &filename);
Variant is_file(const Variant &filename);
Variant is_dir(const Variant &filename);
Variant is_link(const Variant &filename);
Variant stat(const Variant &filename);
Variant lstat(const Variant &filename);
Variant chown(const Variant &filename, const Variant &user);
Variant chgrp(const Variant &filename, const Variant &group);
Variant lchown(const Variant &filename, const Variant &user);
Variant lchgrp(const Variant &filename, const Variant &group);
Variant chmod(const Variant &filename, const Variant &permissions);
Variant touch(const Variant &filename, const Variant &mtime = {}, const Variant &atime = {});
Variant clearstatcache(const Variant &clear_realpath_cache = false, const Variant &filename = "");
Variant disk_total_space(const Variant &directory);
Variant disk_free_space(const Variant &directory);
Variant diskfreespace(const Variant &directory);
Variant realpath_cache_get();
Variant realpath_cache_size();
template <typename... Args>
Variant sprintf(const Variant &format, const Args &...values) {
    return call(LITERAL_STRING[2170], {format, values...});
}
template <typename... Args>
Variant printf(const Variant &format, const Args &...values) {
    return call(LITERAL_STRING[2171], {format, values...});
}
Variant vprintf(const Variant &format, const Variant &values);
Variant vsprintf(const Variant &format, const Variant &values);
template <typename... Args>
Variant fprintf(const Variant &stream, const Variant &format, const Args &...values) {
    return call(LITERAL_STRING[2174], {stream, format, values...});
}
Variant vfprintf(const Variant &stream, const Variant &format, const Variant &values);
Variant fsockopen(const Variant &hostname,
                  const Variant &port = -1,
                  const Reference &error_code = {},
                  const Reference &error_message = {},
                  const Variant &timeout = {});
Variant pfsockopen(const Variant &hostname,
                   const Variant &port = -1,
                   const Reference &error_code = {},
                   const Reference &error_message = {},
                   const Variant &timeout = {});
Variant http_build_query(const Variant &data,
                         const Variant &numeric_prefix = "",
                         const Variant &arg_separator = {},
                         const Variant &encoding_type = 1);
Variant http_get_last_response_headers();
Variant http_clear_last_response_headers();
Variant request_parse_body(const Variant &options = {});
Variant image_type_to_mime_type(const Variant &image_type);
Variant image_type_to_extension(const Variant &image_type, const Variant &include_dot = true);
Variant getimagesize(const Variant &filename, const Reference &image_info = {});
Variant getimagesizefromstring(const Variant &string, const Reference &image_info = {});
Variant phpinfo(const Variant &flags = 4294967295);
Variant phpversion(const Variant &extension = {});
Variant phpcredits(const Variant &flags = 4294967295);
Variant php_sapi_name();
Variant php_uname(const Variant &mode = "a");
Variant php_ini_scanned_files();
Variant php_ini_loaded_file();
Variant iptcembed(const Variant &iptc_data, const Variant &filename, const Variant &spool = 0);
Variant iptcparse(const Variant &iptc_block);
Variant levenshtein(const Variant &string1,
                    const Variant &string2,
                    const Variant &insertion_cost = 1,
                    const Variant &replacement_cost = 1,
                    const Variant &deletion_cost = 1);
Variant readlink(const Variant &path);
Variant linkinfo(const Variant &path);
Variant symlink(const Variant &target, const Variant &link);
Variant link(const Variant &target, const Variant &link);
Variant mail(const Variant &to,
             const Variant &subject,
             const Variant &message,
             const Variant &additional_headers = Array{},
             const Variant &additional_params = "");
Variant abs(const Variant &num);
Variant ceil(const Variant &num);
Variant floor(const Variant &num);
Variant round(const Variant &num, const Variant &precision = 0, const Variant &mode = {});
Variant sin(const Variant &num);
Variant cos(const Variant &num);
Variant tan(const Variant &num);
Variant asin(const Variant &num);
Variant acos(const Variant &num);
Variant atan(const Variant &num);
Variant atanh(const Variant &num);
Variant atan2(const Variant &y, const Variant &x);
Variant sinh(const Variant &num);
Variant cosh(const Variant &num);
Variant tanh(const Variant &num);
Variant asinh(const Variant &num);
Variant acosh(const Variant &num);
Variant expm1(const Variant &num);
Variant log1p(const Variant &num);
Variant pi();
Variant is_finite(const Variant &num);
Variant is_nan(const Variant &num);
Variant intdiv(const Variant &num1, const Variant &num2);
Variant is_infinite(const Variant &num);
Variant pow(const Variant &num, const Variant &exponent);
Variant exp(const Variant &num);
Variant log(const Variant &num, const Variant &base = 2.7182818284590451);
Variant log10(const Variant &num);
Variant sqrt(const Variant &num);
Variant hypot(const Variant &x, const Variant &y);
Variant deg2rad(const Variant &num);
Variant rad2deg(const Variant &num);
Variant bindec(const Variant &binary_string);
Variant hexdec(const Variant &hex_string);
Variant octdec(const Variant &octal_string);
Variant decbin(const Variant &num);
Variant decoct(const Variant &num);
Variant dechex(const Variant &num);
Variant base_convert(const Variant &num, const Variant &from_base, const Variant &to_base);
Variant number_format(const Variant &num,
                      const Variant &decimals = 0,
                      const Variant &decimal_separator = ".",
                      const Variant &thousands_separator = ",");
Variant fmod(const Variant &num1, const Variant &num2);
Variant fdiv(const Variant &num1, const Variant &num2);
Variant fpow(const Variant &num, const Variant &exponent);
Variant microtime(const Variant &as_float = false);
Variant gettimeofday(const Variant &as_float = false);
Variant getrusage(const Variant &mode = 0);
template <typename... Args>
Variant pack(const Variant &format, const Args &...values) {
    return call(LITERAL_STRING[2242], {format, values...});
}
Variant unpack(const Variant &format, const Variant &string, const Variant &offset = 0);
Variant password_get_info(const Variant &hash);
Variant password_hash(const Variant &password, const Variant &algo, const Variant &options = Array{});
Variant password_needs_rehash(const Variant &hash, const Variant &algo, const Variant &options = Array{});
Variant password_verify(const Variant &password, const Variant &hash);
Variant password_algos();
Variant proc_open(const Variant &command,
                  const Variant &descriptor_spec,
                  const Reference &pipes,
                  const Variant &cwd = {},
                  const Variant &env_vars = {},
                  const Variant &options = {});
Variant proc_close(const Variant &process);
Variant proc_terminate(const Variant &process, const Variant &signal = 15);
Variant proc_get_status(const Variant &process);
Variant quoted_printable_decode(const Variant &string);
Variant quoted_printable_encode(const Variant &string);
Variant soundex(const Variant &string);
Variant stream_select(const Reference &read,
                      const Reference &write,
                      const Reference &except,
                      const Variant &seconds,
                      const Variant &microseconds = {});
Variant stream_context_create(const Variant &options = {}, const Variant &params = {});
Variant stream_context_set_params(const Variant &context, const Variant &params);
Variant stream_context_get_params(const Variant &context);
Variant stream_context_set_option(const Variant &context,
                                  const Variant &wrapper_or_options,
                                  const Variant &option_name = {},
                                  const Variant &value = {});
Variant stream_context_set_options(const Variant &context, const Variant &options);
Variant stream_context_get_options(const Variant &stream_or_context);
Variant stream_context_get_default(const Variant &options = {});
Variant stream_context_set_default(const Variant &options);
Variant stream_filter_prepend(const Variant &stream,
                              const Variant &filter_name,
                              const Variant &mode = 0,
                              const Variant &params = {});
Variant stream_filter_append(const Variant &stream,
                             const Variant &filter_name,
                             const Variant &mode = 0,
                             const Variant &params = {});
Variant stream_filter_remove(const Variant &stream_filter);
Variant stream_socket_client(const Variant &address,
                             const Reference &error_code = {},
                             const Reference &error_message = {},
                             const Variant &timeout = {},
                             const Variant &flags = 4,
                             const Variant &context = {});
Variant stream_socket_server(const Variant &address,
                             const Reference &error_code = {},
                             const Reference &error_message = {},
                             const Variant &flags = 12,
                             const Variant &context = {});
Variant stream_socket_accept(const Variant &socket, const Variant &timeout = {}, const Reference &peer_name = {});
Variant stream_socket_get_name(const Variant &socket, const Variant &remote);
Variant stream_socket_recvfrom(const Variant &socket,
                               const Variant &length,
                               const Variant &flags = 0,
                               const Reference &address = {});
Variant stream_socket_sendto(const Variant &socket,
                             const Variant &data,
                             const Variant &flags = 0,
                             const Variant &address = "");
Variant stream_socket_enable_crypto(const Variant &stream,
                                    const Variant &enable,
                                    const Variant &crypto_method = {},
                                    const Variant &session_stream = {});
Variant stream_socket_shutdown(const Variant &stream, const Variant &mode);
Variant stream_socket_pair(const Variant &domain, const Variant &type, const Variant &protocol);
Variant stream_copy_to_stream(const Variant &from,
                              const Variant &to,
                              const Variant &length = {},
                              const Variant &offset = 0);
Variant stream_get_contents(const Variant &stream, const Variant &length = {}, const Variant &offset = -1);
Variant stream_supports_lock(const Variant &stream);
Variant stream_set_write_buffer(const Variant &stream, const Variant &size);
Variant set_file_buffer(const Variant &stream, const Variant &size);
Variant stream_set_read_buffer(const Variant &stream, const Variant &size);
Variant stream_set_blocking(const Variant &stream, const Variant &enable);
Variant socket_set_blocking(const Variant &stream, const Variant &enable);
Variant stream_get_meta_data(const Variant &stream);
Variant socket_get_status(const Variant &stream);
Variant stream_get_line(const Variant &stream, const Variant &length, const Variant &ending = "");
Variant stream_resolve_include_path(const Variant &filename);
Variant stream_get_wrappers();
Variant stream_get_transports();
Variant stream_is_local(const Variant &stream);
Variant stream_isatty(const Variant &stream);
Variant stream_set_chunk_size(const Variant &stream, const Variant &size);
Variant stream_set_timeout(const Variant &stream, const Variant &seconds, const Variant &microseconds = 0);
Variant socket_set_timeout(const Variant &stream, const Variant &seconds, const Variant &microseconds = 0);
Variant gettype(const Variant &value);
Variant get_debug_type(const Variant &value);
Variant settype(const Reference &var, const Variant &type);
Variant intval(const Variant &value, const Variant &base = 10);
Variant floatval(const Variant &value);
Variant doubleval(const Variant &value);
Variant boolval(const Variant &value);
Variant strval(const Variant &value);
Variant is_null(const Variant &value);
Variant is_resource(const Variant &value);
Variant is_bool(const Variant &value);
Variant is_int(const Variant &value);
Variant is_integer(const Variant &value);
Variant is_long(const Variant &value);
Variant is_float(const Variant &value);
Variant is_double(const Variant &value);
Variant is_numeric(const Variant &value);
Variant is_string(const Variant &value);
Variant is_array(const Variant &value);
Variant is_object(const Variant &value);
Variant is_scalar(const Variant &value);
Variant is_callable(const Variant &value, const Variant &syntax_only = false, const Reference &callable_name = {});
Variant is_iterable(const Variant &value);
Variant is_countable(const Variant &value);
Variant uniqid(const Variant &prefix = "", const Variant &more_entropy = false);
Variant parse_url(const Variant &url, const Variant &component = -1);
Variant urlencode(const Variant &string);
Variant urldecode(const Variant &string);
Variant rawurlencode(const Variant &string);
Variant rawurldecode(const Variant &string);
Variant get_headers(const Variant &url, const Variant &associative = false, const Variant &context = {});
Variant stream_bucket_make_writeable(const Variant &brigade);
Variant stream_bucket_prepend(const Variant &brigade, const Variant &bucket);
Variant stream_bucket_append(const Variant &brigade, const Variant &bucket);
Variant stream_bucket_new(const Variant &stream, const Variant &buffer);
Variant stream_get_filters();
Variant stream_filter_register(const Variant &filter_name, const Variant &_class);
Variant convert_uuencode(const Variant &string);
Variant convert_uudecode(const Variant &string);
template <typename... Args>
Variant var_dump(const Variant &value, const Args &...values) {
    return call(LITERAL_STRING[2335], {value, values...});
}
Variant var_export(const Variant &value, const Variant &_return = false);
template <typename... Args>
Variant debug_zval_dump(const Variant &value, const Args &...values) {
    return call(LITERAL_STRING[2337], {value, values...});
}
Variant serialize(const Variant &value);
Variant unserialize(const Variant &data, const Variant &options = Array{});
Variant memory_get_usage(const Variant &real_usage = false);
Variant memory_get_peak_usage(const Variant &real_usage = false);
Variant memory_reset_peak_usage();
Variant version_compare(const Variant &version1, const Variant &version2, const Variant &_operator = {});
Variant dl(const Variant &extension_filename);
Variant cli_set_process_title(const Variant &title);
Variant cli_get_process_title();
}  // namespace php

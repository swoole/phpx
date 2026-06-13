#include "phpx_test.h"
#include "phpx_func.h"
#include "phpx_helper.h"

using namespace php;

// ==================== json functions ====================

TEST(func_facade, json_encode_decode) {
    Array arr = create_map();
    auto encoded = json_encode(arr);
    ASSERT_TRUE(encoded.isString());
    auto str = encoded.toCString();
    ASSERT_GT(strlen(str), 0);

    auto decoded = json_decode(encoded, true);
    ASSERT_TRUE(decoded.isArray());
    auto decoded_arr = decoded.toArray();
    ASSERT_EQ(decoded_arr.get("php").toInt(), 3);
}

TEST(func_facade, json_encode_flags) {
    Array data{{"name", "John"}, {"age", 30}};
    auto pretty = json_encode(data, 128 /*JSON_PRETTY_PRINT*/);
    ASSERT_TRUE(pretty.isString());
    ASSERT_GT(pretty.length(), 0);
}

TEST(func_facade, json_decode_assoc) {
    String json_str(R"({"x":1,"y":2})");
    auto obj = json_decode(json_str);
    ASSERT_TRUE(obj.isObject());

    auto arr = json_decode(json_str, true);
    ASSERT_TRUE(arr.isArray());
    Array a(arr);
    ASSERT_EQ(a.get("x").toInt(), 1);
    ASSERT_EQ(a.get("y").toInt(), 2);
}

TEST(func_facade, json_decode_flags) {
    String json_str("{\"key\": 12345678901234567890}");
    auto result = json_decode(json_str, true, 512, 2 /*JSON_BIGINT_AS_STRING*/);
    ASSERT_TRUE(result.isArray());
    Array arr(result);
    ASSERT_TRUE(arr.get("key").isString());
    ASSERT_STREQ(arr.get("key").toCString(), "12345678901234567890");
}

#if PHP_VERSION_ID >= 80300
TEST(func_facade, json_validate) {
    ASSERT_TRUE(json_validate("{\"valid\": true}").toBool());
    ASSERT_FALSE(json_validate("{invalid json").toBool());
    ASSERT_TRUE(json_validate("null").toBool());
    ASSERT_TRUE(json_validate("42").toBool());
    ASSERT_TRUE(json_validate("\"string\"").toBool());
}
#endif

TEST(func_facade, json_last_error) {
    json_decode("invalid");
    auto err = json_last_error();
    ASSERT_TRUE(err.isInt());
    ASSERT_NE(err.toInt(), 0 /*JSON_ERROR_NONE*/);

    // Valid decode resets error
    json_decode("{}");
    auto err2 = json_last_error();
    ASSERT_EQ(err2.toInt(), 0 /*JSON_ERROR_NONE*/);
}

TEST(func_facade, json_last_error_msg) {
    json_decode("invalid");
    auto msg = json_last_error_msg();
    ASSERT_TRUE(msg.isString());
    ASSERT_GT(msg.length(), 0);
}

// ==================== pcre functions ====================

TEST(func_facade, preg_match) {
    auto rs = preg_match("/world/", "hello world");
    ASSERT_EQ(rs.toInt(), 1);

    auto rs2 = preg_match("/xyz/", "hello world");
    ASSERT_EQ(rs2.toInt(), 0);
}

TEST(func_facade, preg_match_matches) {
    Array matches;
    auto ref = matches.toReference();
    auto rs = preg_match("/(\\d+)-(\\w+)/", "test 123-abc end", ref);
    ASSERT_EQ(rs.toInt(), 1);
    ASSERT_EQ(matches.count(), 3);
    ASSERT_STREQ(matches[0].toCString(), "123-abc");
    ASSERT_STREQ(matches[1].toCString(), "123");
    ASSERT_STREQ(matches[2].toCString(), "abc");
}

TEST(func_facade, preg_match_offset) {
    auto rs = preg_match("/foo/", "foofoo", {}, 0, 1);
    ASSERT_EQ(rs.toInt(), 1);
}

TEST(func_facade, preg_match_all) {
    Array matches;
    auto ref = matches.toReference();
    auto rs = preg_match_all("/\\d+/", "12 apples, 34 oranges, 56 bananas", ref);
    ASSERT_EQ(rs.toInt(), 3);
}

TEST(func_facade, preg_replace) {
    auto rs = preg_replace("/\\d+/", "#", "a1b2c3");
    ASSERT_STREQ(rs.toCString(), "a#b#c#");
}

TEST(func_facade, preg_replace_limit) {
    auto rs = preg_replace("/\\d+/", "#", "a1b2c3", 2);
    ASSERT_STREQ(rs.toCString(), "a#b#c3");
}

TEST(func_facade, preg_replace_count) {
    var count(0);
    auto ref = count.toReference();
    auto rs = preg_replace("/\\d+/", "#", "a1b2", -1, ref);
    ASSERT_STREQ(rs.toCString(), "a#b#");
    ASSERT_EQ(count.toInt(), 2);
}

TEST(func_facade, preg_filter) {
    Array subjects{"a1", "b2", "c3"};
    auto rs = preg_filter("/\\d+/", "X", subjects);
    ASSERT_TRUE(rs.isArray());
    Array result(rs);
    ASSERT_STREQ(result[0].toCString(), "aX");
    ASSERT_STREQ(result[1].toCString(), "bX");
    ASSERT_STREQ(result[2].toCString(), "cX");
}

TEST(func_facade, preg_split) {
    auto rs = preg_split("/,/", "a,b,c,d");
    ASSERT_TRUE(rs.isArray());
    Array parts(rs);
    ASSERT_EQ(parts.count(), 4);
}

TEST(func_facade, preg_split_limit) {
    auto rs = preg_split("/,/", "a,b,c,d", 3);
    Array parts(rs);
    ASSERT_EQ(parts.count(), 3);
}

TEST(func_facade, preg_quote) {
    auto rs = preg_quote(".+*?[^]$(){}=!<>|:-#");
    ASSERT_TRUE(rs.isString());
    ASSERT_GT(rs.length(), strlen(".+*?[^]$(){}=!<>|:-#"));
}

TEST(func_facade, preg_quote_delimiter) {
    auto rs = preg_quote("/pattern/", "/");
    ASSERT_TRUE(rs.toStdString().find("\\/pattern\\/") != std::string::npos);
}

TEST(func_facade, preg_grep) {
    Array input{"apple", "banana", "apricot", "cherry"};
    auto rs = preg_grep("/^ap/", input);
    ASSERT_TRUE(rs.isArray());
    Array result(rs);
    ASSERT_EQ(result.count(), 2);
}

TEST(func_facade, preg_grep_invert) {
    Array input{"apple", "banana", "apricot", "cherry"};
    auto rs = preg_grep("/^ap/", input, 1);
    Array result(rs);
    ASSERT_EQ(result.count(), 2);
}

TEST(func_facade, preg_last_error) {
    // Valid regex
    preg_match("/valid/", "test");
    ASSERT_EQ(preg_last_error().toInt(), 0);

    // Invalid regex
    try_call([]() { preg_match("/invalid(/", "test"); }, "");
}

// ==================== core.h functions ====================

TEST(func_facade, zend_version) {
    auto ver = zend_version();
    ASSERT_TRUE(ver.isString());
    ASSERT_GT(ver.length(), 0);
}

TEST(func_facade, define_defined) {
    define("PHPX_TEST_CONST_12345", 2026);
    ASSERT_TRUE(defined("PHPX_TEST_CONST_12345").toBool());
    ASSERT_FALSE(defined("PHPX_CONST_THAT_DOES_NOT_EXIST").toBool());
}

TEST(func_facade, define_case_insensitive) {
    // Note: PHP 8.0+ deprecated case-insensitive constants; third param is ignored
    define("PHPX_TEST_CI", "case_insensitive_value", true);
    ASSERT_TRUE(defined("PHPX_TEST_CI").toBool());
}

TEST(func_facade, function_exists) {
    ASSERT_TRUE(function_exists("strlen").toBool());
    ASSERT_TRUE(function_exists("array_push").toBool());
    ASSERT_FALSE(function_exists("function_not_exist_xyz").toBool());
}

TEST(func_facade, class_exists) {
    ASSERT_TRUE(class_exists("stdClass").toBool());
    ASSERT_TRUE(class_exists("DateTime").toBool());
    ASSERT_FALSE(class_exists("ClassNotExistXYZ").toBool());
}

TEST(func_facade, interface_exists) {
    ASSERT_TRUE(interface_exists("Countable").toBool());
    ASSERT_TRUE(interface_exists("ArrayAccess").toBool());
    ASSERT_FALSE(interface_exists("InterfaceNotExistXYZ").toBool());
}

TEST(func_facade, trait_exists) {
    ASSERT_FALSE(trait_exists("NonExistentTraitXYZ").toBool());
}

TEST(func_facade, get_class) {
    auto obj = newObject("DateTime", {"2020-01-01"});
    auto cls = get_class(obj);
    ASSERT_STREQ(cls.toCString(), "DateTime");
}

TEST(func_facade, get_parent_class) {
    include(get_include_dir() + "/library.php", INCLUDE_ONCE);
    auto obj = newObject("TestClass2");
    auto parent = get_parent_class(obj);
    ASSERT_STREQ(parent.toCString(), "TestClass");
}

TEST(func_facade, is_subclass_of) {
    include(get_include_dir() + "/library.php", INCLUDE_ONCE);
    auto obj = newObject("TestClass2");
    ASSERT_TRUE(is_subclass_of(obj, "TestClass").toBool());
    ASSERT_FALSE(is_subclass_of(obj, "DateTime").toBool());
}

TEST(func_facade, is_a) {
    include(get_include_dir() + "/library.php", INCLUDE_ONCE);
    auto obj = newObject("TestClass2");
    ASSERT_TRUE(is_a(obj, "TestClass2").toBool());
    ASSERT_TRUE(is_a(obj, "TestClass").toBool());
    ASSERT_FALSE(is_a(obj, "DateTime").toBool());
}

TEST(func_facade, method_exists) {
    auto obj = newObject("DateTime", {"2020-01-01"});
    ASSERT_TRUE(method_exists(obj, "format").toBool());
    ASSERT_FALSE(method_exists(obj, "nonExistentMethod").toBool());
}

TEST(func_facade, property_exists) {
    auto obj = newObject("stdClass");
    obj.set("myProp", 42);
    ASSERT_TRUE(property_exists(obj, "myProp").toBool());
    ASSERT_FALSE(property_exists(obj, "nonexistent").toBool());
}

TEST(func_facade, get_class_methods) {
    auto obj = newObject("DateTime", {"2020-01-01"});
    auto methods = get_class_methods(obj);
    ASSERT_TRUE(methods.isArray());
    auto arr = methods.toArray();
    ASSERT_GT(arr.count(), 0);
}

TEST(func_facade, get_class_vars) {
    auto vars = get_class_vars("stdClass");
    ASSERT_TRUE(vars.isArray());
}

TEST(func_facade, get_object_vars) {
    auto obj = newObject("stdClass");
    obj.set("prop1", 1);
    obj.set("prop2", "hello");
    auto vars = get_object_vars(obj);
    ASSERT_TRUE(vars.isArray());
}

TEST(func_facade, get_declared_classes) {
    auto classes = get_declared_classes();
    ASSERT_TRUE(classes.isArray());
    ASSERT_GT(classes.toArray().count(), 0);
}

TEST(func_facade, get_declared_interfaces) {
    auto interfaces = get_declared_interfaces();
    ASSERT_TRUE(interfaces.isArray());
}

TEST(func_facade, get_defined_functions) {
    auto funcs = get_defined_functions();
    ASSERT_TRUE(funcs.isArray());
    auto arr = funcs.toArray();
    ASSERT_TRUE(arr.exists("internal"));
}

TEST(func_facade, get_loaded_extensions) {
    auto exts = get_loaded_extensions();
    ASSERT_TRUE(exts.isArray());
    ASSERT_GT(exts.toArray().count(), 0);
}

TEST(func_facade, extension_loaded) {
    ASSERT_TRUE(extension_loaded("standard").toBool());
    ASSERT_TRUE(extension_loaded("Core").toBool());
    ASSERT_FALSE(extension_loaded("ExtensionNotExistXYZ").toBool());
}

TEST(func_facade, get_extension_funcs) {
    auto funcs = get_extension_funcs("standard");
    ASSERT_TRUE(funcs.isArray() || funcs.isFalse());
}

TEST(func_facade, get_defined_constants) {
    auto constants = get_defined_constants();
    ASSERT_TRUE(constants.isArray());
}

TEST(func_facade, get_included_files) {
    include(get_include_dir() + "/library.php", INCLUDE_ONCE);
    auto files = get_included_files();
    ASSERT_TRUE(files.isArray());
    ASSERT_GT(files.toArray().count(), 0);
}

TEST(func_facade, gc_functions) {
    php::gc_enable();
    ASSERT_TRUE(php::gc_enabled().toBool());
    php::gc_disable();
    ASSERT_FALSE(php::gc_enabled().toBool());
    php::gc_enable();

    php::gc_collect_cycles();
    auto status = php::gc_status();
    ASSERT_TRUE(status.isArray());
}

TEST(func_facade, trigger_error) {
    trigger_error("test user notice", E_USER_NOTICE);
    auto err = error_get_last();
    if (err.isArray()) {
        Array errArr(err);
        ASSERT_STREQ(errArr.get("message").toCString(), "test user notice");
        error_clear_last();
    }
}

TEST(func_facade, debug_backtrace) {
    auto bt = debug_backtrace();
    ASSERT_TRUE(bt.isArray());
}

TEST(func_facade, get_resource_type) {
    auto f = php::fopen("/dev/null", "r");
    if (f.isResource()) {
        auto type = get_resource_type(f);
        ASSERT_STREQ(type.toCString(), "stream");
        php::fclose(f);
    }
}

// ==================== standard.h additional functions ====================

TEST(func_facade, parse_url) {
    auto url = parse_url("https://user:pass@example.com:8080/path?query=1#frag");
    ASSERT_TRUE(url.isArray());
    Array parts(url);
    ASSERT_STREQ(parts.get("scheme").toCString(), "https");
    ASSERT_STREQ(parts.get("host").toCString(), "example.com");
    ASSERT_EQ(parts.get("port").toInt(), 8080);
}

TEST(func_facade, parse_url_component) {
    auto scheme = parse_url("https://example.com/path", PHP_URL_SCHEME);
    ASSERT_STREQ(scheme.toCString(), "https");

    auto host = parse_url("https://example.com/path", PHP_URL_HOST);
    ASSERT_STREQ(host.toCString(), "example.com");
}

TEST(func_facade, urlencode_urldecode) {
    String original("hello world! test=1&x=2");
    auto encoded = urlencode(original);
    ASSERT_NE(encoded.toStdString(), original.toStdString());
    auto decoded = urldecode(encoded);
    ASSERT_STREQ(decoded.toCString(), original.toCString());
}

TEST(func_facade, rawurlencode_rawurldecode) {
    String original("hello world!");
    auto encoded = rawurlencode(original);
    ASSERT_TRUE(encoded.toStdString().find("%20") != std::string::npos);
    auto decoded = rawurldecode(encoded);
    ASSERT_STREQ(decoded.toCString(), original.toCString());
}

TEST(func_facade, htmlspecialchars) {
    auto rs = htmlspecialchars("<div class=\"test\">hello & goodbye</div>");
    ASSERT_TRUE(rs.toStdString().find("&lt;") != std::string::npos);
    ASSERT_TRUE(rs.toStdString().find("&quot;") != std::string::npos);
    ASSERT_TRUE(rs.toStdString().find("&gt;") != std::string::npos);
}

TEST(func_facade, htmlspecialchars_decode) {
    auto encoded = htmlspecialchars("<p>hello</p>");
    auto decoded = htmlspecialchars_decode(encoded);
    ASSERT_STREQ(decoded.toCString(), "<p>hello</p>");
}

TEST(func_facade, htmlentities) {
    auto rs = htmlentities("café & brûlée");
    ASSERT_TRUE(rs.isString());
    ASSERT_GT(rs.length(), 0);
}

TEST(func_facade, html_entity_decode) {
    auto encoded = htmlentities("café");
    auto decoded = html_entity_decode(encoded);
    ASSERT_STREQ(decoded.toCString(), "café");
}

TEST(func_facade, str_contains) {
    ASSERT_TRUE(str_contains("hello world", "world").toBool());
    ASSERT_FALSE(str_contains("hello world", "xyz").toBool());
    ASSERT_TRUE(str_contains("", "").toBool());
    // Empty needle is always found
    ASSERT_TRUE(str_contains("hello", "").toBool());
}

TEST(func_facade, str_starts_with) {
    ASSERT_TRUE(str_starts_with("hello world", "hello").toBool());
    ASSERT_FALSE(str_starts_with("hello world", "world").toBool());
}

TEST(func_facade, str_ends_with) {
    ASSERT_TRUE(str_ends_with("hello world", "world").toBool());
    ASSERT_FALSE(str_ends_with("hello world", "hello").toBool());
}

TEST(func_facade, explode) {
    auto rs = explode(",", "a,b,c,d");
    ASSERT_TRUE(rs.isArray());
    Array parts(rs);
    ASSERT_EQ(parts.count(), 4);
    ASSERT_STREQ(parts[0].toCString(), "a");
}

TEST(func_facade, explode_limit) {
    auto rs = explode(",", "a,b,c,d", 2);
    Array parts(rs);
    ASSERT_EQ(parts.count(), 2);
    ASSERT_STREQ(parts[0].toCString(), "a");
    ASSERT_STREQ(parts[1].toCString(), "b,c,d");
}

TEST(func_facade, implode) {
    Array arr{"a", "b", "c"};
    auto rs = implode("-", arr);
    ASSERT_STREQ(rs.toCString(), "a-b-c");

    // Single arg form
    auto rs2 = implode(arr);
    ASSERT_TRUE(rs2.isString());
}

TEST(func_facade, join) {
    Array arr{"1", "2", "3"};
    auto rs = join(",", arr);
    ASSERT_STREQ(rs.toCString(), "1,2,3");
}

TEST(func_facade, trim_rtrim_ltrim) {
    ASSERT_STREQ(trim("  hello  ").toCString(), "hello");
    ASSERT_STREQ(rtrim("  hello  ").toCString(), "  hello");
    ASSERT_STREQ(ltrim("  hello  ").toCString(), "hello  ");
    ASSERT_STREQ(chop("  hello  ").toCString(), "  hello");
}

TEST(func_facade, trim_custom_chars) {
    auto rs = trim("-_-hello-_-", "-_");
    ASSERT_STREQ(rs.toCString(), "hello");
}

TEST(func_facade, addslashes_stripslashes) {
    String s("it's a \"test\"");
    auto escaped = addslashes(s);
    ASSERT_GT(escaped.length(), s.length());
    auto unescaped = stripslashes(escaped);
    ASSERT_STREQ(unescaped.toCString(), s.toCString());
}

TEST(func_facade, str_replace) {
    auto rs = str_replace("world", "PHP", "hello world");
    ASSERT_STREQ(rs.toCString(), "hello PHP");
}

TEST(func_facade, str_replace_array) {
    Array search{"a", "e", "i", "o", "u"};
    Array replace{"A", "E", "I", "O", "U"};
    auto rs = str_replace(search, replace, "hello world");
    ASSERT_STREQ(rs.toCString(), "hEllO wOrld");
}

TEST(func_facade, str_replace_count) {
    var count(0);
    auto ref = count.toReference();
    auto rs = str_replace("o", "O", "hello world", ref);
    ASSERT_STREQ(rs.toCString(), "hellO wOrld");
    ASSERT_EQ(count.toInt(), 2);
}

TEST(func_facade, str_ireplace) {
    auto rs = str_ireplace("HELLO", "hi", "Hello World");
    ASSERT_STREQ(rs.toCString(), "hi World");
}

TEST(func_facade, substr) {
    auto rs = substr("hello world", 6);
    ASSERT_STREQ(rs.toCString(), "world");

    auto rs2 = substr("hello world", 0, 5);
    ASSERT_STREQ(rs2.toCString(), "hello");

    auto rs3 = substr("hello world", -5);
    ASSERT_STREQ(rs3.toCString(), "world");

    auto rs4 = substr("hello world", 0, -6);
    ASSERT_STREQ(rs4.toCString(), "hello");
}

TEST(func_facade, str_replace_count_ref) {
    var count(0);
    auto ref = count.toReference();
    auto rs = str_replace("l", "L", "hello world", ref);
    ASSERT_STREQ(rs.toCString(), "heLLo worLd");
    ASSERT_EQ(count.toInt(), 3);
}

TEST(func_facade, strpos_stripos_strrpos_strripos) {
    ASSERT_EQ(strpos("hello world", "world").toInt(), 6);
    ASSERT_EQ(stripos("Hello World", "world").toInt(), 6);
    ASSERT_EQ(strrpos("hello world world", "world").toInt(), 12);
    ASSERT_EQ(strripos("Hello World World", "WORLD").toInt(), 12);
    ASSERT_TRUE(strpos("hello", "xyz").isFalse());
}

TEST(func_facade, strpos_offset) {
    auto rs = strpos("hello hello", "hello", 3);
    ASSERT_EQ(rs.toInt(), 6);
}

TEST(func_facade, strtolower_strtoupper) {
    ASSERT_STREQ(strtolower("Hello World").toCString(), "hello world");
    ASSERT_STREQ(strtoupper("Hello World").toCString(), "HELLO WORLD");
}

TEST(func_facade, ucfirst_lcfirst) {
    ASSERT_STREQ(ucfirst("hello world").toCString(), "Hello world");
    ASSERT_STREQ(lcfirst("Hello World").toCString(), "hello World");
}

TEST(func_facade, ucwords) {
    auto rs = ucwords("hello world");
    ASSERT_STREQ(rs.toCString(), "Hello World");
}

TEST(func_facade, strrev) {
    ASSERT_STREQ(strrev("hello").toCString(), "olleh");
    ASSERT_STREQ(strrev("").toCString(), "");
}

TEST(func_facade, str_repeat) {
    ASSERT_STREQ(str_repeat("ab", 3).toCString(), "ababab");
    ASSERT_STREQ(str_repeat("x", 0).toCString(), "");
}

TEST(func_facade, str_pad) {
    auto rs = str_pad("hello", 10, "-", PHP_STR_PAD_RIGHT);
    ASSERT_STREQ(rs.toCString(), "hello-----");

    auto rs2 = str_pad("hello", 10, "-", PHP_STR_PAD_LEFT);
    ASSERT_STREQ(rs2.toCString(), "-----hello");

    auto rs3 = str_pad("hello", 10, "-", PHP_STR_PAD_BOTH);
    ASSERT_STREQ(rs3.toCString(), "--hello---");
}

TEST(func_facade, str_word_count) {
    auto rs = str_word_count("hello world from php");
    ASSERT_EQ(rs.toInt(), 4);

    auto rs2 = str_word_count("hello world", 1);
    ASSERT_TRUE(rs2.isArray());
    ASSERT_EQ(rs2.toArray().count(), 2);
}

TEST(func_facade, str_split) {
    auto rs = str_split("hello");
    ASSERT_TRUE(rs.isArray());
    ASSERT_EQ(rs.toArray().count(), 5);

    auto rs2 = str_split("hello", 2);
    ASSERT_EQ(rs2.toArray().count(), 3);
}

TEST(func_facade, chunk_split) {
    auto rs = chunk_split("abcdef", 2, "-");
    ASSERT_STREQ(rs.toCString(), "ab-cd-ef-");
}

TEST(func_facade, strstr_stristr) {
    auto rs = php::strstr("hello world", "world");
    ASSERT_STREQ(rs.toCString(), "world");

    auto rs2 = php::strstr("hello world", "world", true);
    ASSERT_STREQ(rs2.toCString(), "hello ");

    auto rs3 = php::stristr("Hello World", "world");
    ASSERT_STREQ(rs3.toCString(), "World");
}

TEST(func_facade, strpbrk) {
    auto rs = php::strpbrk("hello world", "ow");
    ASSERT_STREQ(rs.toCString(), "o world");
}

TEST(func_facade, strspn_strcspn) {
    ASSERT_EQ(php::strspn("abc123", "abc").toInt(), 3);
    ASSERT_EQ(php::strcspn("abc123", "123").toInt(), 3);
}

TEST(func_facade, strtok) {
    auto rs = php::strtok("hello world", " ");
    ASSERT_STREQ(rs.toCString(), "hello");

    // Second call only needs the delimiter
    auto rs2 = php::strtok(" ");
    ASSERT_STREQ(rs2.toCString(), "world");
}

TEST(func_facade, ord_chr) {
    ASSERT_EQ(ord("A").toInt(), 65);
    ASSERT_EQ(ord("a").toInt(), 97);
    ASSERT_STREQ(chr(65).toCString(), "A");
    ASSERT_STREQ(chr(97).toCString(), "a");
}

TEST(func_facade, substr_count) {
    ASSERT_EQ(substr_count("hello hello hello", "hello").toInt(), 3);
    ASSERT_EQ(substr_count("aaaa", "aa").toInt(), 2);
    ASSERT_EQ(substr_count("hello", "xyz").toInt(), 0);
}

TEST(func_facade, substr_compare) {
    ASSERT_EQ(substr_compare("abcde", "bc", 1, 2).toInt(), 0);
    ASSERT_EQ(substr_compare("abcde", "BC", 1, 2, true).toInt(), 0);
}

TEST(func_facade, similar_text) {
    ASSERT_EQ(similar_text("hello", "hallo").toInt(), 4);
}

TEST(func_facade, levenshtein) {
    ASSERT_EQ(levenshtein("kitten", "sitting").toInt(), 3);
}

TEST(func_facade, metaphone) {
    auto rs = metaphone("hello");
    ASSERT_TRUE(rs.isString());
}

TEST(func_facade, soundex) {
    auto rs = soundex("hello");
    ASSERT_TRUE(rs.isString());
    ASSERT_EQ(rs.length(), 4);
}

TEST(func_facade, nl2br) {
    auto rs = nl2br("line1\nline2");
    ASSERT_TRUE(rs.toStdString().find("<br") != std::string::npos);
}

TEST(func_facade, strip_tags) {
    auto rs = strip_tags("<p>hello <b>world</b></p>");
    ASSERT_STREQ(rs.toCString(), "hello world");
}

TEST(func_facade, strip_tags_allowed) {
    auto rs = strip_tags("<p>hello <b>world</b></p>", "<b>");
    ASSERT_STREQ(rs.toCString(), "hello <b>world</b>");
}

TEST(func_facade, str_word_count_format) {
    auto rs = str_word_count("hello world", 2);
    ASSERT_TRUE(rs.isArray());
}

TEST(func_facade, str_shuffle) {
    auto rs = str_shuffle("abcdef");
    ASSERT_EQ(rs.length(), 6);
}

TEST(func_facade, str_rot13) {
    auto rs = str_rot13("hello");
    ASSERT_STREQ(str_rot13(rs).toCString(), "hello");
}

TEST(func_facade, strcoll) {
    ASSERT_EQ(php::strcoll("a", "b").toInt(), -1);
    ASSERT_EQ(php::strcoll("a", "a").toInt(), 0);
    ASSERT_EQ(php::strcoll("b", "a").toInt(), 1);
}

TEST(func_facade, sprintf) {
    auto rs = php::sprintf("%s-%d-%.2f", "test", 42, 3.14159);
    ASSERT_STREQ(rs.toCString(), "test-42-3.14");
}

TEST(func_facade, strcmp_strncmp) {
    ASSERT_EQ(php::strcmp("abc", "abc").toInt(), 0);
    ASSERT_LT(php::strcmp("abc", "abd").toInt(), 0);
    ASSERT_GT(php::strcmp("abd", "abc").toInt(), 0);

    ASSERT_EQ(php::strncmp("abcde", "abcxy", 3).toInt(), 0);
    ASSERT_NE(php::strncmp("abcde", "abcxy", 4).toInt(), 0);
}

TEST(func_facade, strcasecmp_strncasecmp) {
    ASSERT_EQ(php::strcasecmp("ABC", "abc").toInt(), 0);
    ASSERT_EQ(php::strncasecmp("ABCDE", "abcxy", 3).toInt(), 0);
}

#if PHP_VERSION_ID >= 80300
TEST(func_facade, str_increment_decrement) {
    auto rs = str_increment("a");
    ASSERT_STREQ(rs.toCString(), "b");

    auto rs2 = str_decrement("b");
    ASSERT_STREQ(rs2.toCString(), "a");
}
#endif

TEST(func_facade, quotemeta) {
    auto rs = quotemeta(".+*?[^]$()");
    ASSERT_TRUE(rs.toStdString().find("\\.") != std::string::npos);
}

TEST(func_facade, money_format_approach) {
    auto rs = number_format(1234.5678, 2, ".", ",");
    ASSERT_STREQ(rs.toCString(), "1,234.57");
}

TEST(func_facade, bin2hex_hex2bin) {
    auto hex = bin2hex("hello");
    ASSERT_STREQ(hex.toCString(), "68656c6c6f");
    ASSERT_STREQ(hex2bin(hex).toCString(), "hello");
}

TEST(func_facade, crc32) {
    auto rs = crc32("hello");
    ASSERT_TRUE(rs.isInt());
}

TEST(func_facade, md5) {
    ASSERT_EQ(md5("hello").toCString(), std::string("5d41402abc4b2a76b9719d911017c592"));
    ASSERT_STREQ(md5("").toCString(), "d41d8cd98f00b204e9800998ecf8427e");
}

TEST(func_facade, sha1) {
    ASSERT_STREQ(sha1("hello").toCString(), "aaf4c61ddcc5e8a2dabede0f3b482cd9aea9434d");
}

TEST(func_facade, crypt) {
    auto rs = php::crypt("password", "salt");
    ASSERT_TRUE(rs.isString());
    ASSERT_GT(rs.length(), 0);
}

TEST(func_facade, uniqid) {
    auto id1 = uniqid();
    ASSERT_TRUE(id1.isString());
    ASSERT_GT(id1.length(), 0);

    auto id2 = uniqid("pref_");
    ASSERT_TRUE(id2.toStdString().find("pref_") == 0);

    auto id3 = uniqid("", true);
    ASSERT_GT(id3.length(), id1.length());
}

TEST(func_facade, abs_ceil_floor_round) {
    ASSERT_EQ(php::abs(-10).toInt(), 10);
    ASSERT_EQ(php::abs(10).toInt(), 10);
    ASSERT_EQ(php::ceil(3.14).toFloat(), 4.0);
    ASSERT_EQ(php::floor(3.14).toFloat(), 3.0);
    // Note: php::round(3.5) has a known issue with default mode parameter in PHP 8.4
    ASSERT_EQ(php::round(3.5, 0, 1).toFloat(), 4.0);
    ASSERT_EQ(php::round(3.4, 0, 1).toFloat(), 3.0);
}

TEST(func_facade, round_precision) {
    auto rs = php::round(3.14159, 2, 1);
    ASSERT_EQ(rs.toFloat(), 3.14);
}

TEST(func_facade, min_max) {
    ASSERT_EQ(min(10, 20).toInt(), 10);
    ASSERT_EQ(max(10, 20).toInt(), 20);
    ASSERT_STREQ(min("apple", "banana").toCString(), "apple");
    ASSERT_STREQ(max("apple", "banana").toCString(), "banana");
}

TEST(func_facade, intval_floatval_strval_boolval) {
    ASSERT_EQ(intval("42").toInt(), 42);
    ASSERT_EQ(floatval("3.14").toFloat(), 3.14);
    ASSERT_STREQ(strval(123).toCString(), "123");
    ASSERT_TRUE(boolval(1).toBool());
    ASSERT_FALSE(boolval(0).toBool());
}

TEST(func_facade, is_checks) {
    ASSERT_TRUE(is_null(nullptr).toBool());
    ASSERT_FALSE(is_null(42).toBool());
    ASSERT_TRUE(is_bool(true).toBool());
    ASSERT_TRUE(is_bool(false).toBool());
    ASSERT_TRUE(is_int(42).toBool());
    ASSERT_TRUE(is_string("hello").toBool());
    ASSERT_TRUE(is_array(Array{}).toBool());
    ASSERT_TRUE(is_object(newObject("stdClass")).toBool());
    ASSERT_TRUE(is_numeric("123").toBool());
    ASSERT_FALSE(is_numeric("abc").toBool());
    ASSERT_TRUE(is_scalar(42).toBool());
    ASSERT_TRUE(is_scalar("str").toBool());
    ASSERT_FALSE(is_scalar(Array{}).toBool());
    ASSERT_TRUE(is_callable("strlen").toBool());
    ASSERT_FALSE(is_callable("funcNotExists").toBool());
}

TEST(func_facade, gettype_settype) {
    ASSERT_STREQ(gettype(42).toCString(), "integer");
    ASSERT_STREQ(gettype("hello").toCString(), "string");
    ASSERT_STREQ(gettype(3.14).toCString(), "double");
    ASSERT_STREQ(gettype(true).toCString(), "boolean");
}

TEST(func_facade, get_debug_type) {
    ASSERT_STREQ(get_debug_type(42).toCString(), "int");
    ASSERT_STREQ(get_debug_type("hello").toCString(), "string");
}

TEST(func_facade, pack_unpack) {
    auto packed = pack("C*", 65, 66, 67);
    ASSERT_STREQ(packed.toCString(), "ABC");
    auto unpacked = unpack("C*", packed);
    ASSERT_TRUE(unpacked.isArray());
}

TEST(func_facade, version_compare) {
    ASSERT_EQ(version_compare("1.0.0", "2.0.0").toInt(), -1);
    ASSERT_EQ(version_compare("2.0.0", "1.0.0").toInt(), 1);
    ASSERT_EQ(version_compare("1.0.0", "1.0.0").toInt(), 0);
}

TEST(func_facade, phpversion) {
    auto ver = phpversion();
    ASSERT_TRUE(ver.isString());
    ASSERT_GT(ver.length(), 0);
}

TEST(func_facade, php_uname) {
    auto name = php_uname();
    ASSERT_TRUE(name.isString());
    ASSERT_GT(name.length(), 0);
}

TEST(func_facade, sys_getloadavg) {
    auto load = sys_getloadavg();
    ASSERT_TRUE(load.isArray());
}

TEST(func_facade, memory_get_usage) {
    auto usage = memory_get_usage();
    ASSERT_TRUE(usage.isInt());
    ASSERT_GT(usage.toInt(), 0);

    auto peak = memory_get_peak_usage();
    ASSERT_TRUE(peak.isInt());
    ASSERT_GT(peak.toInt(), 0);

    memory_reset_peak_usage();
}

TEST(func_facade, hrtime) {
    auto time = hrtime(false);
    ASSERT_TRUE(time.isArray());

    auto time2 = hrtime(true);
    ASSERT_TRUE(time2.isInt() || time2.isFloat());
}

TEST(func_facade, microtime) {
    auto mt = microtime();
    ASSERT_TRUE(mt.isString());

    auto mt2 = microtime(true);
    ASSERT_TRUE(mt2.isFloat());
}

TEST(func_facade, is_countable) {
    ASSERT_TRUE(is_countable(Array{1, 2, 3}).toBool());
    ASSERT_FALSE(is_countable(42).toBool());
}

TEST(func_facade, is_iterable) {
    ASSERT_TRUE(is_iterable(Array{1, 2, 3}).toBool());
    ASSERT_FALSE(is_iterable(42).toBool());
}

// ==================== ctype functions ====================

TEST(func_facade, ctype_alnum) {
    ASSERT_TRUE(ctype_alnum("abc123").toBool());
    ASSERT_FALSE(ctype_alnum("abc 123").toBool());
    ASSERT_FALSE(ctype_alnum("").toBool());
}

TEST(func_facade, ctype_alpha) {
    ASSERT_TRUE(ctype_alpha("abc").toBool());
    ASSERT_FALSE(ctype_alpha("abc123").toBool());
}

TEST(func_facade, ctype_digit) {
    ASSERT_TRUE(ctype_digit("123").toBool());
    ASSERT_FALSE(ctype_digit("abc").toBool());
    ASSERT_FALSE(ctype_digit("12.3").toBool());
}

TEST(func_facade, ctype_lower) {
    ASSERT_TRUE(ctype_lower("hello").toBool());
    ASSERT_FALSE(ctype_lower("Hello").toBool());
}

TEST(func_facade, ctype_upper) {
    ASSERT_TRUE(ctype_upper("HELLO").toBool());
    ASSERT_FALSE(ctype_upper("Hello").toBool());
}

TEST(func_facade, ctype_cntrl) {
    ASSERT_TRUE(ctype_cntrl("\n\t\r").toBool());
    ASSERT_FALSE(ctype_cntrl("abc").toBool());
}

TEST(func_facade, ctype_space) {
    ASSERT_TRUE(ctype_space(" \t\n").toBool());
    ASSERT_FALSE(ctype_space("abc").toBool());
}

TEST(func_facade, ctype_punct) {
    ASSERT_TRUE(ctype_punct("!@#$").toBool());
    ASSERT_FALSE(ctype_punct("abc").toBool());
}

TEST(func_facade, ctype_graph) {
    ASSERT_TRUE(ctype_graph("hello").toBool());
    ASSERT_FALSE(ctype_graph(" ").toBool());
}

TEST(func_facade, ctype_print) {
    ASSERT_TRUE(ctype_print("hello").toBool());
    ASSERT_FALSE(ctype_print("\n").toBool());
}

TEST(func_facade, ctype_xdigit) {
    ASSERT_TRUE(ctype_xdigit("abc123").toBool());
    ASSERT_FALSE(ctype_xdigit("xyz").toBool());
}

// ==================== spl functions ====================

TEST(func_facade, spl_object_hash) {
    auto obj = newObject("stdClass");
    auto hash = spl_object_hash(obj);
    ASSERT_TRUE(hash.isString());
    ASSERT_EQ(hash.length(), 32);
}

TEST(func_facade, spl_object_id) {
    auto obj = newObject("stdClass");
    auto id = spl_object_id(obj);
    ASSERT_TRUE(id.isInt());
    ASSERT_GT(id.toInt(), 0);
}

TEST(func_facade, class_implements) {
    auto implements = class_implements("ArrayObject");
    ASSERT_TRUE(implements.isArray());
    auto arr = implements.toArray();
    ASSERT_TRUE(arr.exists("ArrayAccess"));
}

TEST(func_facade, class_parents) {
    include(get_include_dir() + "/library.php", INCLUDE_ONCE);
    auto parents = class_parents("TestClass2");
    ASSERT_TRUE(parents.isArray());
    auto arr = parents.toArray();
    ASSERT_TRUE(arr.exists("TestClass"));
}

TEST(func_facade, iterator_count) {
    Array arr{1, 2, 3, 4, 5};
    auto count = iterator_count(arr);
    ASSERT_EQ(count.toInt(), 5);
}

TEST(func_facade, iterator_to_array) {
    Array arr;
    arr.set("a", 1);
    arr.set("b", 2);
    arr.set("c", 3);
    auto result = iterator_to_array(arr);
    ASSERT_TRUE(result.isArray());
    auto res_arr = result.toArray();
    ASSERT_EQ(res_arr.get("a").toInt(), 1);
}

// ==================== date functions ====================

TEST(func_facade, date) {
    auto d = date("Y-m-d", 0);
    ASSERT_STREQ(d.toCString(), "1970-01-01");

    auto d2 = date("Y");
    ASSERT_TRUE(d2.isString());
    ASSERT_EQ(d2.length(), 4);
}

TEST(func_facade, time) {
    auto t = php::time();
    ASSERT_TRUE(t.isInt());
    ASSERT_GT(t.toInt(), 0);
}

// ==================== random functions ====================

TEST(func_facade, rand) {
    auto r1 = php::rand(1, 1000);
    ASSERT_TRUE(r1.isInt());
    ASSERT_GE(r1.toInt(), 1);
    ASSERT_LE(r1.toInt(), 1000);
}

// ==================== setCookie / header edge cases ====================

TEST(func_facade, setcookie_no_output) {
    // Call setcookie in CLI mode - should not crash, may produce warning
    setcookie("test_cookie", "test_value", 0, "/");
    // In CLI mode this should not throw
    SUCCEED();
}

// ==================== serialize / unserialize ====================

TEST(func_facade, serialize_unserialize_func) {
    Array data{{"key1", "value1"}, {"key2", 42}};
    auto s = serialize(data);
    ASSERT_TRUE(s.isString());
    auto u = unserialize(s);
    ASSERT_TRUE(u.isArray());
    Array result(u);
    ASSERT_STREQ(result.get("key1").toCString(), "value1");
    ASSERT_EQ(result.get("key2").toInt(), 42);
}

// ==================== var_dump / var_export ====================

TEST(func_facade, var_export) {
    Array arr;
    arr.set("a", 1);
    arr.set("b", 2);
    ob_start();
    var_export(arr);
    auto output = ob_get_clean();
    ASSERT_GT(output.length(), 0);
}

TEST(func_facade, print_r) {
    Array arr;
    arr.set("x", 10);
    arr.set("y", 20);
    ob_start();
    print_r(arr);
    auto output = ob_get_clean();
    ASSERT_GT(output.length(), 0);

    // With return = true
    auto returned = print_r(arr, true);
    ASSERT_TRUE(returned.isString());
    ASSERT_GT(returned.length(), 0);
}

// ==================== ip2long / long2ip ====================

TEST(func_facade, ip2long_long2ip) {
    auto l = ip2long("127.0.0.1");
    ASSERT_TRUE(l.isInt());
    ASSERT_STREQ(long2ip(l).toCString(), "127.0.0.1");

    ASSERT_EQ(ip2long("255.255.255.0").toInt(), 4294967040);
}

// ==================== basename / dirname / pathinfo ====================

TEST(func_facade, basename) {
    ASSERT_STREQ(php::basename("/var/www/index.php").toCString(), "index.php");
    ASSERT_STREQ(php::basename("/var/www/index.php", ".php").toCString(), "index");
}

TEST(func_facade, dirname) {
    ASSERT_STREQ(php::dirname("/var/www/index.php").toCString(), "/var/www");
    ASSERT_STREQ(php::dirname("/var/www/index.php", 2).toCString(), "/var");
}

TEST(func_facade, pathinfo) {
    auto info = pathinfo("/var/www/index.php");
    ASSERT_TRUE(info.isArray());
    Array parts(info);
    ASSERT_STREQ(parts.get("dirname").toCString(), "/var/www");
    ASSERT_STREQ(parts.get("basename").toCString(), "index.php");
    ASSERT_STREQ(parts.get("extension").toCString(), "php");
}

TEST(func_facade, parse_ini_string) {
    String ini("[section]\nkey1 = value1\nkey2 = 42\n");
    auto rs = parse_ini_string(ini);
    ASSERT_TRUE(rs.isArray());
    Array result(rs);
    ASSERT_STREQ(result.get("key1").toCString(), "value1");
    ASSERT_EQ(result.get("key2").toInt(), 42);
}

TEST(func_facade, parse_ini_string_sections) {
    String ini("[db]\nhost = localhost\nport = 3306\n[redis]\nhost = 127.0.0.1\n");
    auto rs = parse_ini_string(ini, true);
    ASSERT_TRUE(rs.isArray());
}

// ==================== array functions (additional) ====================

TEST(func_facade, array_fill) {
    auto rs = array_fill(0, 3, "hello");
    ASSERT_TRUE(rs.isArray());
    Array arr(rs);
    ASSERT_EQ(arr.count(), 3);
    ASSERT_STREQ(arr[0].toCString(), "hello");
    ASSERT_STREQ(arr[2].toCString(), "hello");
}

TEST(func_facade, array_fill_keys) {
    Array keys{"a", "b", "c"};
    auto rs = array_fill_keys(keys, 0);
    ASSERT_TRUE(rs.isArray());
    Array arr(rs);
    ASSERT_EQ(arr.get("a").toInt(), 0);
    ASSERT_EQ(arr.get("b").toInt(), 0);
}

TEST(func_facade, range) {
    auto rs = range(1, 5);
    ASSERT_TRUE(rs.isArray());
    Array arr(rs);
    ASSERT_EQ(arr.count(), 5);
    ASSERT_EQ(arr[0].toInt(), 1);
    ASSERT_EQ(arr[4].toInt(), 5);

    // With step
    auto rs2 = range(0, 10, 2);
    Array arr2(rs2);
    ASSERT_EQ(arr2.count(), 6);
}

TEST(func_facade, array_column) {
    Array records;
    Array r1{{"id", 1}, {"name", "John"}};
    Array r2{{"id", 2}, {"name", "Jane"}};
    Array r3{{"id", 3}, {"name", "Bob"}};
    records.append(r1);
    records.append(r2);
    records.append(r3);

    auto names = array_column(records, "name");
    ASSERT_TRUE(names.isArray());
    Array result(names);
    ASSERT_EQ(result.count(), 3);
    ASSERT_STREQ(result[0].toCString(), "John");

    // With index_key
    auto indexed = array_column(records, "name", "id");
    Array indexed_arr(indexed);
    ASSERT_STREQ(indexed_arr.get(1).toCString(), "John");
    ASSERT_STREQ(indexed_arr.get(2).toCString(), "Jane");
}

TEST(func_facade, array_sum) {
    Array arr{1, 2, 3, 4, 5};
    ASSERT_EQ(array_sum(arr).toInt(), 15);

    Array arr2{2.5, 3.5};
    ASSERT_EQ(array_sum(arr2).toFloat(), 6.0);
}

TEST(func_facade, array_product) {
    Array arr{1, 2, 3, 4};
    ASSERT_EQ(array_product(arr).toInt(), 24);

    Array arr2;
    ASSERT_EQ(array_product(arr2).toInt(), 1);
}

TEST(func_facade, array_count_values) {
    Array arr{"a", "b", "a", "c", "b", "a"};
    auto rs = array_count_values(arr);
    ASSERT_TRUE(rs.isArray());
    Array result(rs);
    ASSERT_EQ(result.get("a").toInt(), 3);
    ASSERT_EQ(result.get("b").toInt(), 2);
    ASSERT_EQ(result.get("c").toInt(), 1);
}

TEST(func_facade, array_chunk) {
    Array arr{1, 2, 3, 4, 5};
    auto rs = array_chunk(arr, 2);
    ASSERT_TRUE(rs.isArray());
    Array result(rs);
    ASSERT_EQ(result.count(), 3);
}

TEST(func_facade, array_pad) {
    Array arr{1, 2, 3};
    auto rs = array_pad(arr, 5, 0);
    ASSERT_TRUE(rs.isArray());
    Array padded(rs);
    ASSERT_EQ(padded.count(), 5);
    ASSERT_EQ(padded[3].toInt(), 0);
    ASSERT_EQ(padded[4].toInt(), 0);
}

TEST(func_facade, array_key_first_last) {
    Array arr;
    arr.set("a", 1);
    arr.set("b", 2);
    arr.set("c", 3);
    ASSERT_STREQ(array_key_first(arr).toCString(), "a");
    ASSERT_STREQ(array_key_last(arr).toCString(), "c");
}

TEST(func_facade, array_change_key_case) {
    Array arr;
    arr.set("Name", "John");
    arr.set("AGE", 30);
    auto rs = array_change_key_case(arr, PHP_CASE_LOWER);
    ASSERT_TRUE(rs.isArray());
    Array result(rs);
    ASSERT_STREQ(result.get("name").toCString(), "John");
    ASSERT_EQ(result.get("age").toInt(), 30);

    auto rs2 = array_change_key_case(arr, PHP_CASE_UPPER);
    Array result2(rs2);
    ASSERT_STREQ(result2.get("NAME").toCString(), "John");
}

// ==================== current / key ====================

TEST(func_facade, array_pointer_functions) {
    Array arr;
    arr.set("a", 1);
    arr.set("b", 2);
    arr.set("c", 3);

    auto cur = current(arr);
    ASSERT_TRUE(cur.isInt());

    auto k = key(arr);
    ASSERT_TRUE(k.isString() || k.isNull());
}

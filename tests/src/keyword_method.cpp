#include "phpx_test.h"
#include "typephp_helper.h"

using namespace php;

namespace {

void declareKeywordMethodClasses() {
    static bool declared = false;
    if (declared) {
        return;
    }
    declared = true;
    eval(R"PHP(
class KwOk {
    public function toInt(): int { return 7; }
    public function toFloat(): float { return 1.5; }
    public function toString(): string { return 'kw'; }
    public function toBool(): bool { return false; }
    public function toArray(): array { return ['kw' => 1]; }
}
class KwChild extends KwOk {
    public function toInt(): int { return 8; }
}
class KwMagic {
    public function __toString(): string { return 'magic'; }
}
class KwPlain {
    public $a = 1;
}
class KwBadReturn {
    public function toInt(): string { return '7'; }
    public function toArray(): string { return 'x'; }
}
class KwNullable { public function toInt(): ?int { return 7; } }
class KwParam { public function toInt(int $x = 1): int { return 7; } }
class KwStatic { public static function toInt(): int { return 7; } }
class KwNoType { public function toInt() { return 7; } }
class KwPrivate { private function toInt(): int { return 7; } }
class KwByRef { public function &toInt(): int { static $v = 7; return $v; } }
class KwThrows { public function toInt(): int { throw new LogicException('kw failure'); } }
)PHP");
}

template <typename F>
std::string errorMessage(F &&call) {
    try {
        call();
    } catch (zend_object *) {
        auto e = catchException();
        return e.call("getMessage").toString().toStdString();
    }
    return "";
}

}  // namespace

TEST(keyword_method, declared_methods_are_dispatched) {
    declareKeywordMethodClasses();
    Variant obj = newObject("KwOk");
    ASSERT_EQ(typephp_keyword_to_int(obj), 7);
    ASSERT_DOUBLE_EQ(typephp_keyword_to_float(obj), 1.5);
    ASSERT_STREQ(typephp_keyword_to_string(obj).toCString(), "kw");
    ASSERT_FALSE(typephp_keyword_to_bool(obj));
    ASSERT_EQ(toArray(obj).count(), 1);
}

TEST(keyword_method, child_override_wins) {
    declareKeywordMethodClasses();
    Variant obj = newObject("KwChild");
    ASSERT_EQ(typephp_keyword_to_int(obj), 8);
    ASSERT_STREQ(typephp_keyword_to_string(obj).toCString(), "kw");
}

TEST(keyword_method, undeclared_object_uses_default_conversion) {
    declareKeywordMethodClasses();
    Variant magic = newObject("KwMagic");
    ASSERT_STREQ(typephp_keyword_to_string(magic).toCString(), "magic");
    Variant plain = newObject("KwPlain");
    ASSERT_TRUE(typephp_keyword_to_bool(plain));
    ASSERT_EQ(toArray(plain).count(), 1);
}

TEST(keyword_method, non_objects_use_direct_conversion) {
    Variant text("42");
    ASSERT_EQ(typephp_keyword_to_int(text), 42);
    ASSERT_DOUBLE_EQ(typephp_keyword_to_float(text), 42.0);
    ASSERT_STREQ(typephp_keyword_to_string(Variant(5)).toCString(), "5");
    ASSERT_TRUE(typephp_keyword_to_bool(Variant(1)));

    Variant null;
    ASSERT_EQ(typephp_keyword_to_int(null), 0);
    ASSERT_STREQ(typephp_keyword_to_string(null).toCString(), "");
    ASSERT_FALSE(typephp_keyword_to_bool(null));
    ASSERT_EQ(toArray(null).count(), 0);
}

TEST(keyword_method, closure_is_not_dispatched) {
    Variant closure = eval("return function () { return 1; };");
    ASSERT_EQ(toArray(closure).count(), 1);
}

TEST(keyword_method, signature_mismatch_throws) {
    declareKeywordMethodClasses();
    const char *classes[] = {"KwBadReturn", "KwNullable", "KwParam", "KwStatic", "KwNoType", "KwPrivate", "KwByRef"};
    for (const char *name : classes) {
        Variant obj = newObject(name);
        auto message = errorMessage([&] { typephp_keyword_to_int(obj); });
        ASSERT_NE(message.find(std::string(name) + "::"), std::string::npos) << name;
        ASSERT_NE(message.find("must be a public, non-static method without parameters returning exactly int"),
                  std::string::npos)
            << name << ": " << message;
    }
}

TEST(keyword_method, to_array_shares_signature_check) {
    declareKeywordMethodClasses();
    Variant obj = newObject("KwBadReturn");
    auto message = errorMessage([&] { toArray(obj); });
    ASSERT_NE(message.find("KwBadReturn::toArray() must be a public, non-static method"), std::string::npos)
        << message;
    ASSERT_NE(message.find("returning exactly array"), std::string::npos) << message;
}

TEST(keyword_method, method_exception_propagates) {
    declareKeywordMethodClasses();
    Variant obj = newObject("KwThrows");
    ASSERT_EQ(errorMessage([&] { typephp_keyword_to_int(obj); }), "kw failure");
}

TEST(native_universal_math, keeps_receiver_type) {
    ASSERT_EQ(typephp_native_max(php::Int(1), php::Int(2)), 2);
    ASSERT_EQ(typephp_native_min(php::Int(1), php::Int(2)), 1);
    ASSERT_DOUBLE_EQ(typephp_native_max(php::Float(1.5), php::Float(2.5)), 2.5);
    ASSERT_DOUBLE_EQ(typephp_float_pow(2.0, 3.0), 8.0);
    ASSERT_EQ(typephp_int_abs(-5), 5);
    ASSERT_EQ(typephp_int_abs(INT64_MIN), INT64_MIN);
}

TEST(native_universal_math, to_exact_object_rejects_non_objects) {
    ASSERT_TRUE(toExactObject(newObject("stdClass")).isObject());
    ASSERT_EQ(errorMessage([] { toExactObject(Variant(1)); }), "Return value must be of type object, int returned");
    ASSERT_EQ(errorMessage([] { toExactObject(Variant()); }), "Return value must be of type object, null returned");
}

TEST(native_universal_math, exact_result_helpers_reject_false) {
    ASSERT_STREQ(toExactString(Variant("ok")).toCString(), "ok");
    ASSERT_EQ(toExactInt(Variant(3)), 3);
    ASSERT_EQ(toExactArray(Variant(Array())).count(), 0);
    ASSERT_EQ(errorMessage([] { toExactString(Variant(false)); }), "Return value must be of type string, bool returned");
    ASSERT_EQ(errorMessage([] { toExactInt(Variant(false)); }), "Return value must be of type int, bool returned");
    ASSERT_EQ(errorMessage([] { toExactArray(Variant(false)); }), "Return value must be of type array, bool returned");
}

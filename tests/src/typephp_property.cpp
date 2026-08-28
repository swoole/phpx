#include "phpx_test.h"
#include "typephp_helper.h"

using namespace php;

namespace {

zend_object_handlers property_handlers;

zend_class_entry *property_reference_class() {
    static zend_class_entry *class_entry = nullptr;
    if (class_entry != nullptr) {
        return class_entry;
    }

    eval(R"PHP(
        class PhpxPropertyReferenceCoverage {
            public ?array $value = null;
        }
    )PHP");

    class_entry = getClassEntrySafe("PhpxPropertyReferenceCoverage");
    return class_entry;
}

zend_class_entry *property_hook_class() {
    static zend_class_entry *class_entry = nullptr;
    if (class_entry != nullptr) {
        return class_entry;
    }

    eval(R"PHP(
        class PhpxPropertyHookCoverage {
            private int $stored = 1;
            public int $hooked = 0;
            public int $plain = 3;
            public int $number = 7;
            public float $ratio = 1.5;
            public bool $enabled = true;
            public string $text = 'value';
            public array $items = [1];
            public ?stdClass $object = null;

            public int $privateWrite = 0;
            public int $protectedWrite = 0;

            public function __typephp_property_get_686f6f6b6564(): int {
                return $this->stored + 10;
            }

            public function __typephp_property_set_686f6f6b6564(int $value): void {
                $this->stored = $value * 2;
            }

            public function __typephp_property_get_7669727475616c(): int {
                return 99;
            }

            public function __typephp_property_private_set_707269766174655772697465(): void {}
            public function __typephp_property_set_707269766174655772697465(int $value): void {
                $this->stored = $value;
            }

            public function __typephp_property_protected_set_70726f7465637465645772697465(): void {}
            public function __typephp_property_set_70726f7465637465645772697465(int $value): void {
                $this->stored = $value;
            }
        }

        trait PhpxPropertyHookTraitScope {}
    )PHP");

    class_entry = getClassEntrySafe("PhpxPropertyHookCoverage");
    typephp_install_property_handlers(class_entry, &property_handlers);
    return class_entry;
}

Object new_property_hook_object() {
    return newObject(property_hook_class());
}

}  // namespace

TEST(typephp_property, scoped_read_and_write_use_hooks) {
    auto object = new_property_hook_object();
    auto *scope = property_hook_class();

    ASSERT_EQ(typephp_read_property_scoped(object, "hooked", scope, AttrMode::Get).toInt(), 11);
    typephp_write_property_scoped(object, "hooked", 6, scope);
    ASSERT_EQ(typephp_read_property_scoped(object, "hooked", scope, AttrMode::Get).toInt(), 22);

    typephp_write_property_scoped(object, "plain", 8, scope);
    ASSERT_EQ(typephp_read_property_scoped(object, "plain", scope, AttrMode::Get).toInt(), 8);
}

TEST(typephp_property, getter_without_setter_is_read_only) {
    auto object = new_property_hook_object();
    auto *scope = property_hook_class();

    ASSERT_EQ(typephp_read_property_scoped(object, "virtual", scope, AttrMode::Get).toInt(), 99);
    try_call([&]() { typephp_write_property_scoped(object, "virtual", 1, scope); },
             "Property PhpxPropertyHookCoverage::$virtual is read-only");
}

TEST(typephp_property, typed_unset_resets_supported_types) {
    auto object = new_property_hook_object();
    auto unset_property = [&](const char *name) {
        String member{name};
        object.object()->handlers->unset_property(object.object(), member.str(), nullptr);
        throwErrorIfOccurred();
    };

    unset_property("number");
    unset_property("ratio");
    unset_property("enabled");
    unset_property("text");
    unset_property("items");
    unset_property("object");

    ASSERT_EQ(object.attr("number").toInt(), 0);
    ASSERT_DOUBLE_EQ(object.attr("ratio").toFloat(), 0.0);
    ASSERT_FALSE(object.attr("enabled").toBool());
    ASSERT_STREQ(object.attr("text").toCString(), "");
    ASSERT_TRUE(object.attr("items").toArray().empty());
    ASSERT_FALSE(object.propertyExists("object"));
}

TEST(typephp_property, asymmetric_set_visibility_uses_explicit_scope) {
    auto object = new_property_hook_object();
    auto *scope = property_hook_class();

    try_call([&]() { typephp_write_property_scoped(object, "privateWrite", 1, nullptr); },
             "Cannot modify private(set) property");
    try_call([&]() { typephp_write_property_scoped(object, "protectedWrite", 1, nullptr); },
             "Cannot modify protected(set) property");

    typephp_write_property_scoped(object, "privateWrite", 2, scope);
    typephp_write_property_scoped(object, "protectedWrite", 3, scope);
}

TEST(typephp_property, trait_scope_resolves_to_property_owner) {
    auto object = new_property_hook_object();
    auto *trait_scope = getClassEntry("PhpxPropertyHookTraitScope");

    typephp_write_property_scoped(object, "plain", 17, trait_scope);
    ASSERT_EQ(typephp_read_property_scoped(object, "plain", property_hook_class(), AttrMode::Get).toInt(), 17);
}

TEST(typephp_property, scoped_helpers_reject_non_objects) {
    try_call([]() { (void) typephp_read_property_scoped(42, "value", nullptr, AttrMode::Get); },
             "Attempt to read property `value` on int");
    try_call([]() { typephp_write_property_scoped(42, "value", 1, nullptr); },
             "Attempt to write property `value` on int");
}

TEST(typephp_property, property_reference_rebind_preserves_typed_sources) {
    auto *scope = property_reference_class();
    auto object = newObject(scope);

    Array original;
    auto original_reference = original.toReference();
    typephp_rebind_property_reference(object, "value", original_reference, scope);

    original.set("first", 1);
    ASSERT_EQ(object.attr("value").toArray().get("first").toInt(), 1);

    Variant invalid{"invalid"};
    auto invalid_reference = invalid.toReference();
    try_call([&]() { typephp_rebind_property_reference(object, "value", invalid_reference, scope); },
             "Cannot assign string to property PhpxPropertyReferenceCoverage::$value of type ?array");
    ASSERT_EQ(object.attr("value").toArray().get("first").toInt(), 1);

    Array replacement;
    auto replacement_reference = replacement.toReference();
    typephp_rebind_property_reference(object, "value", replacement_reference, scope);

    original_reference = Variant{"detached"};
    ASSERT_STREQ(original_reference.toCString(), "detached");

    try_call([&]() { replacement_reference = Variant{"invalid"}; },
             "Cannot assign string to reference held by property PhpxPropertyReferenceCoverage::$value of type ?array");
    ASSERT_TRUE(object.attr("value").isArray());
}

TEST(typephp_property, property_reference_rebind_rejects_non_objects) {
    Array value;
    auto reference = value.toReference();
    try_call([&]() { typephp_rebind_property_reference(42, "value", reference, nullptr); },
             "Attempt to write property `value` on int");
}

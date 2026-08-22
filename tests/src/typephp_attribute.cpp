#include "phpx_test.h"
#include "typephp_helper.h"

using namespace php;

namespace {

Var lazy_attribute_value(Bool describe) {
    return describe ? Var("'materialized'") : Var("materialized");
}

zend_function *lazy_attribute_target() {
    static zend_function *function = nullptr;
    if (function == nullptr) {
        eval(R"PHP(
            #[Attribute(Attribute::TARGET_FUNCTION)]
            class PhpxLazyAttribute {
                public function __construct(
                    public mixed $value,
                    public mixed $options,
                    public mixed $named = null,
                ) {}
            }

            #[PhpxLazyAttribute(1, ['list', 'key' => 2], named: 3)]
            function phpx_lazy_attribute_target(): void {}

            #[Attribute]
            class PhpxOrdinaryAttribute {
                public function __construct(public int $value) {}
            }

            #[PhpxOrdinaryAttribute(9)]
            function phpx_ordinary_attribute_target(): void {}

            #[Attribute]
            class PhpxNoConstructorAttribute {}
            #[PhpxNoConstructorAttribute(1)]
            function phpx_no_constructor_attribute_target(): void {}

            #[Attribute]
            class PhpxPrivateConstructorAttribute {
                private function __construct(mixed $value) {}
            }
            #[PhpxPrivateConstructorAttribute(1)]
            function phpx_private_constructor_attribute_target(): void {}

            #[Attribute]
            class PhpxThrowingConstructorAttribute {
                public function __construct(mixed $value) {
                    throw new RuntimeException('attribute constructor failure');
                }
            }
            #[PhpxThrowingConstructorAttribute(1)]
            function phpx_throwing_constructor_attribute_target(): void {}

            #[Attribute(Attribute::TARGET_CLASS)]
            class PhpxClassOnlyAttribute {
                public function __construct(mixed $value) {}
            }
            #[PhpxClassOnlyAttribute(1)]
            function phpx_wrong_target_attribute_target(): void {}

            #[Attribute]
            class PhpxNonRepeatableAttribute {
                public function __construct(mixed $value) {}
            }
            #[PhpxNonRepeatableAttribute(1), PhpxNonRepeatableAttribute(2)]
            function phpx_repeated_attribute_target(): void {}

            class PhpxNotAnAttribute {
                public function __construct(mixed $value) {}
            }
            #[PhpxNotAnAttribute(1)]
            function phpx_non_attribute_target(): void {}

            #[PhpxMissingAttribute(1)]
            function phpx_missing_attribute_target(): void {}
        )PHP");
        function = getFunction("phpx_lazy_attribute_target");
    }
    return function;
}

zend_attribute *find_attribute(zend_function *function, const char *name, size_t name_length) {
    return zend_get_attribute_str(function->common.attributes, name, name_length);
}

Object first_reflection_attribute(const char *function_name) {
    auto reflection = newObject("ReflectionFunction", {function_name});
    Array attributes = reflection.call("getAttributes").toArray();
    return Object(attributes.get(0));
}

void make_first_attribute_argument_lazy(const char *function_name, const char *attribute_name) {
    auto *function = getFunction(function_name);
    auto *attribute = find_attribute(function, attribute_name, strlen(attribute_name));
    ASSERT_NE(attribute, nullptr);
    ASSERT_GT(attribute->argc, 0u);
    typephp_attribute_set_lazy_value_argument(attribute, 0, lazy_attribute_value);
}

class ReflectionAttributeHooks final {
  public:
    ReflectionAttributeHooks() : installed_(typephp_install_reflection_attribute_handlers() == SUCCESS) {}

    ~ReflectionAttributeHooks() {
        if (installed_) {
            typephp_uninstall_reflection_attribute_handlers();
        }
    }

    bool installed() const {
        return installed_;
    }

  private:
    bool installed_;
};

}  // namespace

TEST(typephp_attribute, reflection_handlers_are_reference_counted_and_restored) {
    ASSERT_EQ(typephp_install_reflection_attribute_handlers(), SUCCESS);
    ASSERT_EQ(typephp_install_reflection_attribute_handlers(), SUCCESS);

    typephp_uninstall_reflection_attribute_handlers();
    typephp_uninstall_reflection_attribute_handlers();

    // An extra uninstall is intentionally harmless. This also protects module
    // shutdown paths when initialization stopped before installing the hooks.
    typephp_uninstall_reflection_attribute_handlers();
}

TEST(typephp_attribute, lazy_arguments_materialize_for_reflection_and_instantiation) {
    auto *function = lazy_attribute_target();
    auto *attribute = find_attribute(function, ZEND_STRL("phpxlazyattribute"));
    ASSERT_NE(attribute, nullptr);
    ASSERT_EQ(attribute->argc, 3);
    typephp_attribute_set_lazy_value_argument(attribute, 0, lazy_attribute_value);

    ReflectionAttributeHooks hooks;
    ASSERT_TRUE(hooks.installed());
    auto reflection_attribute = first_reflection_attribute("phpx_lazy_attribute_target");

    Array arguments = reflection_attribute.call("getArguments").toArray();
    ASSERT_STREQ(arguments.get(0).toCString(), "materialized");
    ASSERT_STREQ(arguments.get(1).toArray().get(0).toCString(), "list");
    ASSERT_EQ(arguments.get(1).toArray().get("key").toInt(), 2);
    ASSERT_EQ(arguments.get("named").toInt(), 3);

    auto instance = reflection_attribute.call("newInstance").toObject();
    ASSERT_STREQ(instance.attr("value").toCString(), "materialized");
    ASSERT_EQ(instance.attr("named").toInt(), 3);

    auto description = reflection_attribute.call("__toString").toString();
    auto description_text = description.toStdString();
    ASSERT_NE(description_text.find("'materialized'"), std::string::npos);
    ASSERT_NE(description_text.find("'key' => 2"), std::string::npos);
    ASSERT_NE(description_text.find("named = 3"), std::string::npos);
}

TEST(typephp_attribute, ordinary_attributes_use_original_reflection_handlers) {
    (void) lazy_attribute_target();
    ReflectionAttributeHooks hooks;
    ASSERT_TRUE(hooks.installed());
    auto reflection_attribute = first_reflection_attribute("phpx_ordinary_attribute_target");

    Array arguments = reflection_attribute.call("getArguments").toArray();
    ASSERT_EQ(arguments.get(0).toInt(), 9);
    ASSERT_EQ(reflection_attribute.call("newInstance").toObject().attr("value").toInt(), 9);
    ASSERT_NE(reflection_attribute.call("__toString").toStdString().find("PhpxOrdinaryAttribute"), std::string::npos);
}

TEST(typephp_attribute, lazy_instantiation_reports_invalid_attribute_definitions) {
    (void) lazy_attribute_target();
    ReflectionAttributeHooks hooks;
    ASSERT_TRUE(hooks.installed());

    make_first_attribute_argument_lazy("phpx_no_constructor_attribute_target", "phpxnoconstructorattribute");
    auto no_constructor = first_reflection_attribute("phpx_no_constructor_attribute_target");
    try_call([&]() { no_constructor.call("newInstance"); }, "does not have a constructor, cannot pass arguments");

    make_first_attribute_argument_lazy("phpx_private_constructor_attribute_target", "phpxprivateconstructorattribute");
    auto private_constructor = first_reflection_attribute("phpx_private_constructor_attribute_target");
    try_call([&]() { private_constructor.call("newInstance"); },
             "Attribute constructor of class PhpxPrivateConstructorAttribute must be public");

    make_first_attribute_argument_lazy("phpx_throwing_constructor_attribute_target",
                                       "phpxthrowingconstructorattribute");
    auto throwing_constructor = first_reflection_attribute("phpx_throwing_constructor_attribute_target");
    try_call([&]() { throwing_constructor.call("newInstance"); }, "attribute constructor failure");

    make_first_attribute_argument_lazy("phpx_wrong_target_attribute_target", "phpxclassonlyattribute");
    auto wrong_target = first_reflection_attribute("phpx_wrong_target_attribute_target");
    try_call([&]() { wrong_target.call("newInstance"); }, "cannot target function");

    make_first_attribute_argument_lazy("phpx_repeated_attribute_target", "phpxnonrepeatableattribute");
    auto repeated = first_reflection_attribute("phpx_repeated_attribute_target");
    try_call([&]() { repeated.call("newInstance"); }, "must not be repeated");

    make_first_attribute_argument_lazy("phpx_non_attribute_target", "phpxnotanattribute");
    auto non_attribute = first_reflection_attribute("phpx_non_attribute_target");
    try_call([&]() { non_attribute.call("newInstance"); }, "Attempting to use non-attribute class");

    make_first_attribute_argument_lazy("phpx_missing_attribute_target", "phpxmissingattribute");
    auto missing_attribute = first_reflection_attribute("phpx_missing_attribute_target");
    try_call([&]() { missing_attribute.call("newInstance"); }, "Attribute class \"PhpxMissingAttribute\" not found");
}

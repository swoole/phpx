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

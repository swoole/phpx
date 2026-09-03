#include "phpx_test.h"
#include "typephp_helper.h"

#include <iterator>
#include <string_view>

using namespace php;

namespace {

class TraitMetadataRegistration final {
  public:
    TraitMetadataRegistration(int module_number, const typephp_trait_metadata_entry *entries, size_t entry_count)
        : module_number_(module_number),
          registered_(typephp_register_trait_metadata(module_number, entries, entry_count) == SUCCESS) {}

    ~TraitMetadataRegistration() {
        if (registered_) {
            typephp_unregister_trait_metadata(module_number_);
        }
    }

    bool registered() const {
        return registered_;
    }

  private:
    int module_number_;
    bool registered_;
};

void define_trait_metadata_test_classes() {
    static bool defined = false;
    if (defined) {
        return;
    }
    eval(R"PHP(
        class PhpxMetadataClass {}
        class PhpxMetadataSecondClass {}
        trait PhpxDynamicTrait {}
        class PhpxDynamicTraitUser { use PhpxDynamicTrait; }
    )PHP");
    defined = true;
}

Array call_class_uses(const Variant &target, const Variant &autoload = true) {
    return call("class_uses", {target, autoload}).toArray();
}

}  // namespace

TEST(typephp_trait, resolves_static_metadata_and_dynamic_php_classes) {
    define_trait_metadata_test_classes();

    static constexpr std::string_view outer_traits[] = {"PhpxMetadataLeaf"};
    static constexpr std::string_view class_traits[] = {"PhpxMetadataOuter"};
    static constexpr typephp_trait_metadata_entry entries[] = {
        {"PhpxMetadataLeaf", nullptr, 0, true},
        {"PhpxMetadataOuter", outer_traits, 1, true},
        {"PhpxMetadataClass", class_traits, 1, false},
    };
    TraitMetadataRegistration registration{91001, entries, std::size(entries)};
    ASSERT_TRUE(registration.registered());

    Array direct = call_class_uses("PhpxMetadataClass");
    ASSERT_EQ(direct.length(), 1);
    ASSERT_STREQ(direct.get("PhpxMetadataOuter").toCString(), "PhpxMetadataOuter");
    ASSERT_STREQ(call_class_uses("\\PhpxMetadataClass").get("PhpxMetadataOuter").toCString(), "PhpxMetadataOuter");

    Object object = newObject("PhpxMetadataClass");
    Array from_object = call_class_uses(object);
    ASSERT_STREQ(from_object.get("PhpxMetadataOuter").toCString(), "PhpxMetadataOuter");

    Array nested = call_class_uses("PhpxMetadataOuter");
    ASSERT_STREQ(nested.get("PhpxMetadataLeaf").toCString(), "PhpxMetadataLeaf");
    ASSERT_STREQ(call_class_uses("\\phpxmetadataouter").get("PhpxMetadataLeaf").toCString(), "PhpxMetadataLeaf");
    ASSERT_EQ(call_class_uses("PhpxMetadataLeaf").length(), 0);

    Array dynamic = call_class_uses("PhpxDynamicTraitUser");
    ASSERT_STREQ(dynamic.get("PhpxDynamicTrait").toCString(), "PhpxDynamicTrait");
}

TEST(typephp_trait, keeps_module_registrations_independent) {
    define_trait_metadata_test_classes();

    static constexpr std::string_view first_traits[] = {"PhpxFirstTrait"};
    static constexpr std::string_view second_traits[] = {"PhpxSecondTrait"};
    static constexpr typephp_trait_metadata_entry first_entries[] = {
        {"PhpxFirstTrait", nullptr, 0, true},
        {"PhpxMetadataClass", first_traits, 1, false},
    };
    static constexpr typephp_trait_metadata_entry second_entries[] = {
        {"PhpxSecondTrait", nullptr, 0, true},
        {"PhpxMetadataSecondClass", second_traits, 1, false},
    };

    ASSERT_EQ(typephp_register_trait_metadata(91002, first_entries, std::size(first_entries)), SUCCESS);
    ASSERT_EQ(typephp_register_trait_metadata(91003, second_entries, std::size(second_entries)), SUCCESS);
    ASSERT_STREQ(call_class_uses("PhpxMetadataClass").get("PhpxFirstTrait").toCString(), "PhpxFirstTrait");
    ASSERT_STREQ(call_class_uses("PhpxMetadataSecondClass").get("PhpxSecondTrait").toCString(), "PhpxSecondTrait");

    typephp_unregister_trait_metadata(91002);
    ASSERT_EQ(call_class_uses("PhpxMetadataClass").length(), 0);
    ASSERT_STREQ(call_class_uses("PhpxMetadataSecondClass").get("PhpxSecondTrait").toCString(), "PhpxSecondTrait");
    typephp_unregister_trait_metadata(91003);
}

TEST(typephp_trait, preserves_builtin_argument_validation) {
    define_trait_metadata_test_classes();

    static constexpr typephp_trait_metadata_entry entries[] = {
        {"PhpxMetadataLeaf", nullptr, 0, true},
    };
    TraitMetadataRegistration registration{91004, entries, std::size(entries)};
    ASSERT_TRUE(registration.registered());

    try_call([]() { (void) call("class_uses", {42}); }, "must be of type object|string");
    try_call([]() { (void) call("class_uses", {"PhpxMetadataLeaf", Array{}}); }, "must be of type bool");
}

TEST(typephp_trait, restores_builtin_handler_after_last_module) {
    auto *function = reinterpret_cast<zend_internal_function *>(getFunction("class_uses"));
    zif_handler original_handler = function->handler;
    static constexpr typephp_trait_metadata_entry entries[] = {
        {"PhpxHandlerRestoreTrait", nullptr, 0, true},
    };

    {
        TraitMetadataRegistration registration{91005, entries, std::size(entries)};
        ASSERT_TRUE(registration.registered());
        ASSERT_NE(function->handler, original_handler);
    }

    ASSERT_EQ(function->handler, original_handler);
}

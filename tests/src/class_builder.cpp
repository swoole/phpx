#include "phpx_ext.h"
#include "phpx_test.h"

using namespace php;

TEST(class_builder, activates_inheritance_interface_and_members) {
    auto *base = get_gtest_builder_base();
    auto *child = get_gtest_builder_child();
    auto *interface = get_gtest_builder_interface();

    ASSERT_NE(base, nullptr);
    ASSERT_NE(child, nullptr);
    ASSERT_NE(interface, nullptr);
    ASSERT_STREQ(base->getName().c_str(), "PhpxGtestBuiltBase");
    ASSERT_STREQ(interface->getName().c_str(), "PhpxGtestBuiltInterface");
    ASSERT_TRUE(instanceof_function(child->ptr(), base->ptr()));
    ASSERT_TRUE(instanceof_function(child->ptr(), interface->ptr()));

    auto object = newObject(child->ptr());
    ASSERT_EQ(object.attr("value").toInt(), 7);
    ASSERT_STREQ(object.attr("label").toCString(), "built");
    ASSERT_EQ(object.call("describe", {5}).toInt(), 12);
    ASSERT_EQ(object.call("describe", {8}).toInt(), 15);
    ASSERT_EQ(getStaticProperty(child->ptr(), "counter").toInt(), 3);
    ASSERT_EQ(constant("PhpxGtestBuiltBase::KIND").toInt(), 42);
    ASSERT_STREQ(constant("PhpxGtestBuiltBase::NAME").toCString(), "builder");
    ASSERT_EQ(getClassEntrySafe("PhpxGtestBuiltAlias"), base->ptr());
}

TEST(class_builder, supports_class_entry_overloads) {
    auto *base = get_gtest_builder_base();
    auto *direct_child = get_gtest_builder_direct_child();
    auto *interface = get_gtest_builder_interface();

    ASSERT_NE(direct_child, nullptr);
    ASSERT_TRUE(instanceof_function(direct_child->ptr(), base->ptr()));
    ASSERT_TRUE(instanceof_function(direct_child->ptr(), interface->ptr()));
    ASSERT_EQ(newObject(direct_child->ptr()).call("describe", {2}).toInt(), 9);
}

TEST(class_builder, rejects_metadata_changes_after_activation) {
    auto *base = get_gtest_builder_base();
    auto *child = get_gtest_builder_child();
    auto *interface = get_gtest_builder_interface();

    ASSERT_FALSE(base->addConstant("LATE_CONSTANT", 1));
    ASSERT_FALSE(base->addProperty("lateProperty", 1, PUBLIC));
    ASSERT_FALSE(base->addStaticProperty("lateStaticProperty", 1, PUBLIC));
    ASSERT_FALSE(base->alias("PhpxGtestLateAlias"));
    ASSERT_FALSE(base->extends(child));
    ASSERT_FALSE(base->extends(child->ptr()));
    ASSERT_FALSE(base->implements(interface));
    ASSERT_FALSE(base->implements(interface->ptr()));
    ASSERT_FALSE(base->activate());
    ASSERT_FALSE(interface->activate());
}

#include "phpx_python.h"
#include "phpx_test.h"

using namespace php;

namespace {

bool phpy_is_loaded() {
    return call("extension_loaded", {"phpy"}).toBool();
}

}  // namespace

TEST(python_bridge, native_api_covers_import_call_and_conversion) {
    if (!phpy_is_loaded()) {
        GTEST_SKIP() << "phpy extension is not loaded";
    }
    python::configureRuntime(true);

    auto math = python::importModule("math");
    auto sqrt = python::getAttr(math, "sqrt");

    Args args;
    args.append(81);
    auto result_from_args = python::call(sqrt, args);
    ASSERT_DOUBLE_EQ(python::toValue(result_from_args).toFloat(), 9.0);

    auto result_from_list = python::call(sqrt, {16});
    ASSERT_DOUBLE_EQ(python::toValue(result_from_list).toFloat(), 4.0);

    auto result_from_member = python::callMember(math, "sqrt", {25});
    ASSERT_DOUBLE_EQ(python::toValue(result_from_member).toFloat(), 5.0);
}

TEST(python_bridge, native_api_covers_constructors_and_no_argument_calls) {
    if (!phpy_is_loaded()) {
        GTEST_SKIP() << "phpy extension is not loaded";
    }
    python::configureRuntime(true);

    auto empty_list = python::construct(python::Constructor::List);
    ASSERT_TRUE(python::toArray(empty_list).empty());

    Array source{1, 2, 3};
    auto list = python::construct(python::Constructor::List, source);
    auto converted = python::toArray(list);
    ASSERT_EQ(converted.length(), 3);
    ASSERT_EQ(converted.get(0).toInt(), 1);
    ASSERT_EQ(converted.get(2).toInt(), 3);

    auto builtins = python::importModule("builtins");
    auto list_constructor = python::getAttr(builtins, "list");
    auto called_list = python::call(list_constructor);
    ASSERT_TRUE(python::toArray(called_list).empty());

    auto text = python::construct(python::Constructor::Str, "phpx");
    auto string_result = python::callMember(text, "__str__");
    ASSERT_STREQ(python::toValue(string_result).toCString(), "phpx");
}

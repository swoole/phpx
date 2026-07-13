#include "phpx_test.h"

using namespace php;

TEST(foreach_iterator, array_and_reference) {
    Array values(StdStrKeyMap{{"a", 1}, {"b", 2}});
    ForeachIterator iterator(values, true);
    Array seen;

    while (iterator.next()) {
        seen.set(iterator.key(), iterator.value());
        Reference value = iterator.valueRef();
        value = value.getRefValue().toInt() * 10;
    }

    ASSERT_EQ(seen.get("a").toInt(), 1);
    ASSERT_EQ(seen.get("b").toInt(), 2);
    ASSERT_EQ(values.get("a").toInt(), 10);
    ASSERT_EQ(values.get("b").toInt(), 20);
}

TEST(foreach_iterator, variant_temporary_array_reference) {
    Variant values;
    values = Array{1, 2, 3};
    ForeachIterator iterator(values, true);

    int expected = 1;
    while (iterator.next()) {
        ASSERT_EQ(iterator.value().toInt(), expected);
        Reference value = iterator.valueRef();
        value = expected * 2;
        ++expected;
    }
    ASSERT_EQ(expected, 4);
}

TEST(foreach_iterator, iterator_aggregate) {
    Variant iterable = eval(R"PHP(
        return new class implements IteratorAggregate {
            public function getIterator(): Traversable {
                yield 'first' => 10;
                yield 'second' => 20;
            }
        };
    )PHP");

    ForeachIterator iterator(iterable);
    Array seen;
    while (iterator.next()) {
        seen.set(iterator.key(), iterator.value());
    }

    ASSERT_EQ(seen.get("first").toInt(), 10);
    ASSERT_EQ(seen.get("second").toInt(), 20);
}

TEST(foreach_iterator, plain_object) {
    Variant iterable = eval(R"PHP(
        return new class {
            public string $visible = 'yes';
            private string $hidden = 'no';
        };
    )PHP");

    ForeachIterator iterator(iterable);
    ASSERT_TRUE(iterator.next());
    ASSERT_EQ(iterator.key().toStdString(), "visible");
    ASSERT_EQ(iterator.value().toStdString(), "yes");
    ASSERT_FALSE(iterator.next());
}

TEST(foreach_iterator, rejects_invalid_value_and_object_reference) {
    try_call([]() { ForeachIterator iterator(42); }, "foreach() argument must be of type array|object");

    Variant object = eval("return (object) ['value' => 1];");
    try_call([&object]() { ForeachIterator iterator(object, true); }, "Cannot use & with foreach");
}

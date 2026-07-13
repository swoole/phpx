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

TEST(foreach_iterator, array_reference_separates_copy_on_write_alias) {
    Array values{1, 2};
    Array alias = values;
    ForeachIterator iterator(values, true);

    while (iterator.next()) {
        Reference value = iterator.valueRef();
        value = value.getRefValue().toInt() * 10;
    }

    ASSERT_EQ(values.get(0).toInt(), 10);
    ASSERT_EQ(values.get(1).toInt(), 20);
    ASSERT_EQ(alias.get(0).toInt(), 1);
    ASSERT_EQ(alias.get(1).toInt(), 2);
}

TEST(foreach_iterator, array_reference_tracks_append_and_delete) {
    Array values{1, 2};
    ForeachIterator iterator(values, true);
    Array seen;

    while (iterator.next()) {
        zend_long value = iterator.value().toInt();
        seen.append(value);
        if (value == 1) {
            values.del(1);
            values.append(3);
        }
    }

    ASSERT_EQ(seen.count(), 2);
    ASSERT_EQ(seen.get(0).toInt(), 1);
    ASSERT_EQ(seen.get(1).toInt(), 3);
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

TEST(foreach_iterator, plain_object_uses_live_properties) {
    Variant iterable = eval("return (object) ['a' => 1, 'b' => 2];");
    ForeachIterator iterator(iterable);
    Array seen;

    while (iterator.next()) {
        String key = iterator.key().toString();
        seen.append(key);
        if (key == "a") {
            iterable.unsetProperty("b");
            iterable.setProperty("c", 3);
        }
    }

    ASSERT_EQ(seen.count(), 2);
    ASSERT_EQ(seen.get(0).toStdString(), "a");
    ASSERT_EQ(seen.get(1).toStdString(), "c");
}

TEST(foreach_iterator, plain_object_honors_explicit_scope) {
    Variant iterable = eval(R"PHP(
        class PhpxForeachVisibilityParent {
            public int $public = 1;
            protected int $protected = 2;
            private int $parentPrivate = 3;
        }
        class PhpxForeachVisibilityChild extends PhpxForeachVisibilityParent {
            private int $childPrivate = 4;
        }
        return new PhpxForeachVisibilityChild();
    )PHP");

    ForeachIterator iterator(iterable, false, iterable.ce());
    Array seen;
    while (iterator.next()) {
        seen.set(iterator.key(), iterator.value());
    }

    ASSERT_EQ(seen.get("public").toInt(), 1);
    ASSERT_EQ(seen.get("protected").toInt(), 2);
    ASSERT_TRUE(seen.get("parentPrivate").isNull());
    ASSERT_EQ(seen.get("childPrivate").toInt(), 4);
}

TEST(foreach_iterator, plain_object_reference) {
    Variant iterable = eval("return (object) ['value' => 1];");
    ForeachIterator iterator(iterable, true);
    ASSERT_TRUE(iterator.next());
    Reference value = iterator.valueRef();
    value = 2;
    ASSERT_EQ(iterable.getProperty("value").toInt(), 2);
}

TEST(foreach_iterator, typed_property_reference_enforces_type_sources) {
    Variant iterable = eval("return new class { public int $value = 1; };");
    ForeachIterator iterator(iterable, true);
    ASSERT_TRUE(iterator.next());

    Variant target;
    iterator.assignValueRef(target);
    Variant invalid = nullptr;
    try_call([&target, &invalid]() { target = invalid; }, "Cannot assign null to reference held by property");
    ASSERT_EQ(iterable.getProperty("value").toInt(), 1);

    target = 3;
    ASSERT_EQ(iterable.getProperty("value").toInt(), 3);
}

TEST(foreach_iterator, readonly_property_rejects_reference) {
    Variant iterable = eval(R"PHP(
        return new class {
            public readonly int $value;
            public function __construct() { $this->value = 1; }
        };
    )PHP");
    ForeachIterator iterator(iterable, true);
    ASSERT_TRUE(iterator.next());
    try_call([&iterator]() { iterator.valueRef(); }, "Cannot acquire reference to readonly property");
}

TEST(foreach_iterator, iterator_key_is_lazy) {
    Variant iterable = eval(R"PHP(
        return new class implements Iterator {
            public int $keyCalls = 0;
            private int $position = 0;
            public function rewind(): void { $this->position = 0; }
            public function valid(): bool { return $this->position < 2; }
            public function current(): mixed { return $this->position + 10; }
            public function key(): mixed { ++$this->keyCalls; return $this->position; }
            public function next(): void { ++$this->position; }
        };
    )PHP");

    ForeachIterator iterator(iterable);
    while (iterator.next()) {
        ASSERT_GE(iterator.value().toInt(), 10);
    }
    ASSERT_EQ(iterable.getProperty("keyCalls").toInt(), 0);
}

TEST(foreach_iterator, rewind_exception_releases_iterator) {
    Variant iterable = eval(R"PHP(
        class PhpxForeachThrowingIterator implements Iterator {
            public static int $destroyed = 0;
            public function rewind(): void { throw new RuntimeException('rewind failure'); }
            public function valid(): bool { return true; }
            public function current(): mixed { return 1; }
            public function key(): mixed { return 0; }
            public function next(): void {}
            public function __destruct() { ++self::$destroyed; }
        }
        class PhpxForeachThrowingAggregate implements IteratorAggregate {
            public function getIterator(): Traversable { return new PhpxForeachThrowingIterator(); }
        }
        return new PhpxForeachThrowingAggregate();
    )PHP");

    try_call([&iterable]() { ForeachIterator iterator(iterable); }, "rewind failure");
    ASSERT_EQ(getStaticProperty(getClassEntry("PhpxForeachThrowingIterator"), "destroyed").toInt(), 1);
}

TEST(foreach_iterator, rejects_invalid_value_and_object_reference) {
    try_call([]() { ForeachIterator iterator(42); }, "foreach() argument must be of type array|object");
}

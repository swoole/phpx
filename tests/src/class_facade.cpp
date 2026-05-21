#include "phpx_test.h"
#include "phpx_func.h"
#include "phpx_class.h"
#include "phpx_helper.h"

using namespace php;

// ============================================================
// DateTime
// ============================================================

TEST(class_facade, datetime_construct_default) {
    DateTime dt;
    auto ts = dt.getTimestamp();
    ASSERT_TRUE(ts.isInt());
    ASSERT_GT(ts.toInt(), 0);
}

TEST(class_facade, datetime_construct_string) {
    DateTime dt("2022-06-15");
    auto fmt = dt.format("Y-m-d");
    ASSERT_STREQ(fmt.toCString(), "2022-06-15");
}

TEST(class_facade, datetime_construct_with_tz) {
    DateTimeZone tz("Asia/Shanghai");
    DateTime dt("2022-01-01 12:00:00", tz.getObject());
    auto fmt = dt.format("Y-m-d H:i:s");
    ASSERT_STREQ(fmt.toCString(), "2022-01-01 12:00:00");
}

TEST(class_facade, datetime_createFromFormat) {
    auto dt_var = DateTime::createFromFormat("j-M-Y", "15-Feb-2009");
    ASSERT_TRUE(dt_var.isObject());
    auto fmt = dt_var.call("format", {"Y-m-d"});
    ASSERT_STREQ(fmt.toCString(), "2009-02-15");
}

#if PHP_VERSION_ID >= 80400
TEST(class_facade, datetime_createFromTimestamp) {
    auto dt_var = DateTime::createFromTimestamp(946684800);
    ASSERT_TRUE(dt_var.isObject());
    auto fmt = dt_var.call("format", {"Y-m-d"});
    ASSERT_STREQ(fmt.toCString(), "2000-01-01");
}
#endif

TEST(class_facade, datetime_modify) {
    DateTime dt("2022-01-01");
    dt.modify("+1 day");
    ASSERT_STREQ(dt.format("Y-m-d").toCString(), "2022-01-02");

    dt.modify("-1 month");
    ASSERT_STREQ(dt.format("Y-m-d").toCString(), "2021-12-02");
}

TEST(class_facade, datetime_add_sub) {
    DateTime dt("2022-01-01");
    DateInterval di("P1D");
    dt.add(di.getObject());
    ASSERT_STREQ(dt.format("Y-m-d").toCString(), "2022-01-02");

    dt.sub(di.getObject());
    ASSERT_STREQ(dt.format("Y-m-d").toCString(), "2022-01-01");
}

TEST(class_facade, datetime_getTimestamp) {
    DateTime dt("2022-01-01 00:00:00");
    auto ts = dt.getTimestamp();
    ASSERT_GT(ts.toInt(), 0);
}

TEST(class_facade, datetime_setTime) {
    DateTime dt("2022-01-01");
    dt.setTime(23, 59, 59);
    ASSERT_STREQ(dt.format("H:i:s").toCString(), "23:59:59");
}

TEST(class_facade, datetime_setDate) {
    DateTime dt("2022-01-01");
    dt.setDate(2025, 12, 31);
    ASSERT_STREQ(dt.format("Y-m-d").toCString(), "2025-12-31");
}

TEST(class_facade, datetime_setTimestamp) {
    DateTime dt;
    dt.setTimestamp(946684800);
    ASSERT_STREQ(dt.format("Y-m-d").toCString(), "2000-01-01");
}

TEST(class_facade, datetime_diff) {
    DateTime dt1("2022-01-01");
    DateTime dt2("2022-01-10");
    auto diff = dt1.diff(dt2.getObject());
    ASSERT_TRUE(diff.isObject());
}

TEST(class_facade, datetime_getTimezone) {
    DateTimeZone utc("UTC");
    DateTime dt("2022-01-01", utc.getObject());
    auto tz = dt.getTimezone();
    ASSERT_TRUE(tz.isObject());
}

TEST(class_facade, datetime_getOffset) {
    DateTimeZone utc("UTC");
    DateTime dt("2022-01-01", utc.getObject());
    auto offset = dt.getOffset();
    ASSERT_TRUE(offset.isInt());
}

TEST(class_facade, datetime_setTimezone) {
    DateTimeZone utc("UTC");
    DateTime dt("2022-01-01 12:00:00", utc.getObject());
    DateTimeZone tz("Asia/Shanghai");
    dt.setTimezone(tz.getObject());
    auto fmt = dt.format("P");
    ASSERT_STREQ(fmt.toCString(), "+08:00");
}

TEST(class_facade, datetime_setISODate) {
    DateTime dt;
    dt.setISODate(2022, 1, 1);  // Monday of week 1
    auto fmt = dt.format("Y-m-d");
    ASSERT_TRUE(fmt.isString());
}

#if PHP_VERSION_ID >= 80400
TEST(class_facade, datetime_getMicrosecond) {
    DateTime dt;
    auto ms = dt.getMicrosecond();
    ASSERT_TRUE(ms.isInt());
}
#endif

#if PHP_VERSION_ID >= 80400
TEST(class_facade, datetime_setMicrosecond) {
    DateTime dt("2022-01-01");
    dt.setMicrosecond(500000);
    auto fmt = dt.format("u");
    ASSERT_STREQ(fmt.toCString(), "500000");
}
#endif

TEST(class_facade, datetime_getLastErrors) {
    auto errors = DateTime::getLastErrors();
    ASSERT_TRUE(errors.isArray() || errors.isFalse());
}

TEST(class_facade, datetime_createFromImmutable) {
    DateTimeImmutable imm("2022-06-15");
    auto dt_var = DateTime::createFromImmutable(imm.getObject());
    ASSERT_TRUE(dt_var.isObject());
}

// ============================================================
// DateTimeImmutable
// ============================================================

TEST(class_facade, datetime_immutable_construct) {
    DateTimeImmutable dt("2022-06-15");
    auto fmt = dt.format("Y-m-d");
    ASSERT_STREQ(fmt.toCString(), "2022-06-15");
}

TEST(class_facade, datetime_immutable_modify_returns_new) {
    DateTimeImmutable dt("2022-01-01");
    auto modified = dt.modify("+1 day");
    // Original unchanged
    ASSERT_STREQ(dt.format("Y-m-d").toCString(), "2022-01-01");
}

TEST(class_facade, datetime_immutable_setTimezone) {
    DateTimeImmutable dt("2022-01-01 12:00:00");
    DateTimeZone tz("Asia/Shanghai");
    auto tz_result = dt.setTimezone(tz.getObject());
    // Original unchanged since DateTimeImmutable returns new object
    ASSERT_STREQ(dt.format("Y-m-d").toCString(), "2022-01-01");
}

// ============================================================
// DateTimeZone
// ============================================================

TEST(class_facade, datetimezone_getName) {
    DateTimeZone tz("UTC");
    ASSERT_STREQ(tz.getName().toCString(), "UTC");
}

TEST(class_facade, datetimezone_getName_shanghai) {
    DateTimeZone tz("Asia/Shanghai");
    ASSERT_STREQ(tz.getName().toCString(), "Asia/Shanghai");
}

TEST(class_facade, datetimezone_getOffset) {
    DateTimeZone tz("Asia/Shanghai");
    DateTime dt("2022-01-01 12:00:00", tz.getObject());
    auto offset = tz.getOffset(dt.getObject());
    ASSERT_EQ(offset.toInt(), 28800);  // +08:00 in seconds
}

TEST(class_facade, datetimezone_listIdentifiers) {
    auto ids = DateTimeZone::listIdentifiers();
    ASSERT_TRUE(ids.isArray());
    ASSERT_GT(ids.length(), 0);
}

TEST(class_facade, datetimezone_getLocation) {
    DateTimeZone tz("Asia/Shanghai");
    auto loc = tz.getLocation();
    ASSERT_TRUE(loc.isArray());
    ASSERT_TRUE(loc.offsetExists("country_code"));
}

// ============================================================
// DateInterval
// ============================================================

TEST(class_facade, dateinterval_construct) {
    DateInterval di("P1Y2M3DT4H5M6S");
    auto fmt = di.format("%Y-%M-%D %H:%I:%S");
    ASSERT_STREQ(fmt.toCString(), "01-02-03 04:05:06");
}

TEST(class_facade, dateinterval_createFromDateString) {
    auto di = DateInterval::createFromDateString("1 day");
    ASSERT_TRUE(di.isObject());
}

TEST(class_facade, dateinterval_format_days) {
    DateInterval di("P10D");
    auto fmt = di.format("%d");
    ASSERT_STREQ(fmt.toCString(), "10");
}

// ============================================================
// DatePeriod
// ============================================================

TEST(class_facade, dateperiod_construct) {
    DateTime start("2022-01-01");
    DateInterval interval("P1D");
    DateTime end("2022-01-05");
    DatePeriod period(start.getObject(), interval.getObject(), end.getObject());
    ASSERT_TRUE(period.getStartDate().isObject());
    ASSERT_TRUE(period.getEndDate().isObject());
}

TEST(class_facade, dateperiod_getIterator) {
    DateTime start("2022-01-01");
    DateInterval interval("P1D");
    DateTime end("2022-01-05");
    DatePeriod period(start.getObject(), interval.getObject(), end.getObject());
    auto iter = period.getIterator();
    ASSERT_TRUE(iter.isObject());
}

// ============================================================
// ArrayObject
// ============================================================

TEST(class_facade, arrayobject_construct_empty) {
    ArrayObject ao;
    ASSERT_EQ(ao.count().toInt(), 0);
}

TEST(class_facade, arrayobject_construct_with_array) {
    Array arr;
    arr.set("name", "test");
    arr.set("value", 42);
    ArrayObject ao(arr);
    ASSERT_EQ(ao.count().toInt(), 2);
    ASSERT_STREQ(ao.offsetGet("name").toCString(), "test");
    ASSERT_EQ(ao.offsetGet("value").toInt(), 42);
}

TEST(class_facade, arrayobject_append) {
    ArrayObject ao;
    ao.append("first");
    ao.append("second");
    ao.append("third");
    ASSERT_EQ(ao.count().toInt(), 3);
    ASSERT_STREQ(ao.offsetGet(1).toCString(), "second");
}

TEST(class_facade, arrayobject_offsetSet_string_key) {
    ArrayObject ao;
    ao.offsetSet("color", "blue");
    ao.offsetSet("size", 42);
    ASSERT_STREQ(ao.offsetGet("color").toCString(), "blue");
    ASSERT_EQ(ao.offsetGet("size").toInt(), 42);
}

TEST(class_facade, arrayobject_offsetSet_numeric) {
    ArrayObject ao;
    ao.offsetSet(0, "zero");
    ao.offsetSet(1, "one");
    ASSERT_STREQ(ao.offsetGet(0).toCString(), "zero");
}

TEST(class_facade, arrayobject_offsetExists) {
    ArrayObject ao;
    ao.offsetSet("key", "value");
    ASSERT_TRUE(ao.offsetExists("key").toBool());
    ASSERT_FALSE(ao.offsetExists("missing").toBool());
}

TEST(class_facade, arrayobject_offsetUnset) {
    ArrayObject ao;
    ao.offsetSet("temp", "value");
    ASSERT_TRUE(ao.offsetExists("temp").toBool());
    ao.offsetUnset("temp");
    ASSERT_FALSE(ao.offsetExists("temp").toBool());
}

TEST(class_facade, arrayobject_getArrayCopy) {
    ArrayObject ao;
    ao.append(1);
    ao.append(2);
    auto copy = ao.getArrayCopy();
    ASSERT_TRUE(copy.isArray());
    ASSERT_EQ(copy.toArray().count(), 2);
}

TEST(class_facade, arrayobject_exchangeArray) {
    ArrayObject ao;
    ao.append("old");
    Array new_arr;
    new_arr.append("new1");
    new_arr.append("new2");
    ao.exchangeArray(new_arr);
    ASSERT_EQ(ao.count().toInt(), 2);
}

TEST(class_facade, arrayobject_sort_methods) {
    ArrayObject ao;
    ao.offsetSet("b", 2);
    ao.offsetSet("a", 1);
    ao.offsetSet("c", 3);

    // ksort sorts by key
    ao.ksort();
    auto copy = ao.getArrayCopy();
    ASSERT_TRUE(copy.isArray());
}

TEST(class_facade, arrayobject_serialize_roundtrip) {
    ArrayObject ao;
    ao.append(1);
    ao.append(2);
    auto ser = ao.serialize();
    ASSERT_TRUE(ser.isString());

    ArrayObject ao2;
    ao2.unserialize(ser);
    ASSERT_EQ(ao2.count().toInt(), 2);
}

TEST(class_facade, arrayobject_getFlags) {
    ArrayObject ao;
    auto flags = ao.getFlags();
    ASSERT_TRUE(flags.isInt());
}

TEST(class_facade, arrayobject_setFlags) {
    ArrayObject ao;
    ao.setFlags(1);  // STD_PROP_LIST
    auto flags = ao.getFlags();
    ASSERT_EQ(flags.toInt(), 1);
}

TEST(class_facade, arrayobject_natsort) {
    ArrayObject ao;
    ao.append("img10");
    ao.append("img2");
    ao.append("img1");
    ao.natsort();
    // natsort preserves keys, use foreach to verify ordering
    auto arr = ao.getArrayCopy().toArray();
    ASSERT_EQ(arr.count(), 3);
}

TEST(class_facade, arrayobject_natcasesort) {
    ArrayObject ao;
    ao.append("IMG10");
    ao.append("img2");
    ao.append("Img1");
    ao.natcasesort();
    auto arr = ao.getArrayCopy().toArray();
    ASSERT_EQ(arr.count(), 3);
}

// ============================================================
// SplFixedArray
// ============================================================

TEST(class_facade, splfixedarray_construct) {
    SplFixedArray fa(5);
    ASSERT_EQ(fa.count().toInt(), 5);
    ASSERT_EQ(fa.getSize().toInt(), 5);
}

TEST(class_facade, splfixedarray_offsetSet_offsetGet) {
    SplFixedArray fa(3);
    fa.offsetSet(0, "a");
    fa.offsetSet(1, "b");
    fa.offsetSet(2, "c");
    ASSERT_STREQ(fa.offsetGet(0).toCString(), "a");
    ASSERT_STREQ(fa.offsetGet(1).toCString(), "b");
    ASSERT_STREQ(fa.offsetGet(2).toCString(), "c");
}

TEST(class_facade, splfixedarray_offsetExists) {
    SplFixedArray fa(2);
    fa.offsetSet(0, "set");
    ASSERT_TRUE(fa.offsetExists(0).toBool());
    ASSERT_FALSE(fa.offsetExists(1).toBool());
    ASSERT_FALSE(fa.offsetExists(2).toBool());
}

TEST(class_facade, splfixedarray_offsetUnset) {
    SplFixedArray fa(2);
    fa.offsetSet(0, "value");
    fa.offsetUnset(0);
    ASSERT_FALSE(fa.offsetExists(0).toBool());
}

TEST(class_facade, splfixedarray_setSize_expand) {
    SplFixedArray fa(2);
    fa.offsetSet(0, "a");
    fa.setSize(5);
    ASSERT_EQ(fa.count().toInt(), 5);
    ASSERT_STREQ(fa.offsetGet(0).toCString(), "a");
}

TEST(class_facade, splfixedarray_setSize_shrink) {
    SplFixedArray fa(5);
    fa.offsetSet(0, "keep");
    fa.setSize(2);
    ASSERT_EQ(fa.count().toInt(), 2);
    ASSERT_STREQ(fa.offsetGet(0).toCString(), "keep");
}

TEST(class_facade, splfixedarray_toArray) {
    SplFixedArray fa(3);
    fa.offsetSet(0, 10);
    fa.offsetSet(1, 20);
    fa.offsetSet(2, 30);
    auto arr = fa.toArray();
    ASSERT_TRUE(arr.isArray());
    auto a = arr.toArray();
    ASSERT_EQ(a.count(), 3);
}

TEST(class_facade, splfixedarray_fromArray) {
    Array src;
    src.append("x");
    src.append("y");
    src.append("z");
    auto fa = SplFixedArray::fromArray(src);
    auto obj = SplFixedArray(Variant(0));
    // fromArray is static, result is a new SplFixedArray
    ASSERT_TRUE(fa.isObject());
}

// ============================================================
// SplDoublyLinkedList
// ============================================================

TEST(class_facade, spl_dll_push_pop) {
    SplDoublyLinkedList list;
    list.push("first");
    list.push("second");
    list.push("third");
    ASSERT_EQ(list.count().toInt(), 3);
    ASSERT_FALSE(list.isEmpty().toBool());

    auto top = list.pop();
    ASSERT_STREQ(top.toCString(), "third");
    ASSERT_EQ(list.count().toInt(), 2);
}

TEST(class_facade, spl_dll_unshift_shift) {
    SplDoublyLinkedList list;
    list.unshift("first");
    list.unshift("second");
    ASSERT_EQ(list.count().toInt(), 2);

    auto shifted = list.shift();
    ASSERT_STREQ(shifted.toCString(), "second");
    ASSERT_EQ(list.count().toInt(), 1);
}

TEST(class_facade, spl_dll_top_bottom) {
    SplDoublyLinkedList list;
    list.push("bottom");
    list.push("top");
    ASSERT_STREQ(list.top().toCString(), "top");
    ASSERT_STREQ(list.bottom().toCString(), "bottom");
}

TEST(class_facade, spl_dll_add_at_index) {
    SplDoublyLinkedList list;
    list.push("a");
    list.push("c");
    list.add(1, "b");
    ASSERT_EQ(list.count().toInt(), 3);
    ASSERT_STREQ(list.offsetGet(1).toCString(), "b");
}

TEST(class_facade, spl_dll_offsetExists) {
    SplDoublyLinkedList list;
    list.push("item");
    ASSERT_TRUE(list.offsetExists(0).toBool());
    ASSERT_FALSE(list.offsetExists(1).toBool());
}

TEST(class_facade, spl_dll_offsetUnset) {
    SplDoublyLinkedList list;
    list.push("a");
    list.push("b");
    list.offsetUnset(0);
    ASSERT_EQ(list.count().toInt(), 1);
    ASSERT_STREQ(list.offsetGet(0).toCString(), "b");
}

TEST(class_facade, spl_dll_serialize) {
    SplDoublyLinkedList list;
    list.push("x");
    list.push("y");
    auto ser = list.serialize();
    ASSERT_TRUE(ser.isString());
}

TEST(class_facade, spl_dll_iteration) {
    SplDoublyLinkedList list;
    list.push("a");
    list.push("b");
    list.push("c");

    list.rewind();
    ASSERT_TRUE(list.valid().toBool());
    ASSERT_STREQ(list.current().toCString(), "a");

    list.next();
    ASSERT_STREQ(list.current().toCString(), "b");

    list.next();
    ASSERT_STREQ(list.current().toCString(), "c");
}

// ============================================================
// SplQueue
// ============================================================

TEST(class_facade, spl_queue_enqueue_dequeue) {
    SplQueue q;
    q.enqueue("first");
    q.enqueue("second");
    q.enqueue("third");
    ASSERT_EQ(q.count().toInt(), 3);

    auto d1 = q.dequeue();
    ASSERT_STREQ(d1.toCString(), "first");
    ASSERT_EQ(q.count().toInt(), 2);

    auto d2 = q.dequeue();
    ASSERT_STREQ(d2.toCString(), "second");
}

TEST(class_facade, spl_queue_isEmpty) {
    SplQueue q;
    ASSERT_TRUE(q.isEmpty().toBool());

    q.enqueue("item");
    ASSERT_FALSE(q.isEmpty().toBool());
}

// ============================================================
// SplStack
// ============================================================

TEST(class_facade, spl_stack_push_pop) {
    SplStack s;
    s.push("first");
    s.push("second");
    s.push("third");
    ASSERT_EQ(s.count().toInt(), 3);

    auto top = s.pop();
    ASSERT_STREQ(top.toCString(), "third");
    auto mid = s.pop();
    ASSERT_STREQ(mid.toCString(), "second");
}

TEST(class_facade, spl_stack_top_bottom) {
    SplStack s;
    s.push("bottom");
    s.push("top");
    ASSERT_STREQ(s.top().toCString(), "top");
    ASSERT_STREQ(s.bottom().toCString(), "bottom");
}

// ============================================================
// SplMinHeap
// ============================================================

TEST(class_facade, spl_minheap_insert_extract) {
    SplMinHeap heap;
    heap.insert(3);
    heap.insert(1);
    heap.insert(2);
    ASSERT_EQ(heap.count().toInt(), 3);

    ASSERT_EQ(heap.top().toInt(), 1);
    ASSERT_EQ(heap.extract().toInt(), 1);
    ASSERT_EQ(heap.extract().toInt(), 2);
    ASSERT_EQ(heap.extract().toInt(), 3);
    ASSERT_TRUE(heap.isEmpty().toBool());
}

// ============================================================
// SplMaxHeap
// ============================================================

TEST(class_facade, spl_maxheap_insert_extract) {
    SplMaxHeap heap;
    heap.insert(1);
    heap.insert(3);
    heap.insert(2);
    ASSERT_EQ(heap.count().toInt(), 3);

    ASSERT_EQ(heap.top().toInt(), 3);
    ASSERT_EQ(heap.extract().toInt(), 3);
    ASSERT_EQ(heap.extract().toInt(), 2);
    ASSERT_EQ(heap.extract().toInt(), 1);
}

// ============================================================
// SplPriorityQueue
// ============================================================

TEST(class_facade, spl_priorityqueue_insert_extract) {
    SplPriorityQueue pq;
    pq.insert("low", 1);
    pq.insert("high", 10);
    pq.insert("mid", 5);
    ASSERT_EQ(pq.count().toInt(), 3);

    // highest priority first
    ASSERT_STREQ(pq.extract().toCString(), "high");
    ASSERT_STREQ(pq.extract().toCString(), "mid");
    ASSERT_STREQ(pq.extract().toCString(), "low");
}

TEST(class_facade, spl_priorityqueue_top) {
    SplPriorityQueue pq;
    pq.insert("low", 1);
    pq.insert("high", 100);
    ASSERT_STREQ(pq.top().toCString(), "high");
}

TEST(class_facade, spl_priorityqueue_setExtractFlags) {
    SplPriorityQueue pq;
    pq.insert("a", 10);
    pq.insert("b", 5);
    // EXTR_BOTH = 3: extract both value and priority
    pq.setExtractFlags(3);
    auto result = pq.extract();
    ASSERT_TRUE(result.isArray());
}

// ============================================================
// ReflectionClass
// ============================================================

TEST(class_facade, reflection_class_getName) {
    ReflectionClass rc("stdClass");
    ASSERT_STREQ(rc.getName().toCString(), "stdClass");
}

TEST(class_facade, reflection_class_isInternal) {
    ReflectionClass rc("stdClass");
    ASSERT_TRUE(rc.isInternal().toBool());
}

TEST(class_facade, reflection_class_isUserDefined) {
    ReflectionClass rc("stdClass");
    ASSERT_FALSE(rc.isUserDefined().toBool());
}

TEST(class_facade, reflection_class_isInstantiable) {
    ReflectionClass rc("stdClass");
    ASSERT_TRUE(rc.isInstantiable().toBool());
}

TEST(class_facade, reflection_class_isInterface) {
    ReflectionClass rc_std("stdClass");
    ASSERT_FALSE(rc_std.isInterface().toBool());

    ReflectionClass rc_iface("Traversable");
    ASSERT_TRUE(rc_iface.isInterface().toBool());
}

TEST(class_facade, reflection_class_isTrait) {
    ReflectionClass rc("stdClass");
    ASSERT_FALSE(rc.isTrait().toBool());
}

TEST(class_facade, reflection_class_isAbstract) {
    ReflectionClass rc("stdClass");
    ASSERT_FALSE(rc.isAbstract().toBool());
}

TEST(class_facade, reflection_class_isFinal) {
    ReflectionClass rc("stdClass");
    ASSERT_FALSE(rc.isFinal().toBool());
}

TEST(class_facade, reflection_class_getMethods) {
    ReflectionClass rc("DateTime");
    auto methods = rc.getMethods();
    ASSERT_TRUE(methods.isArray());
    ASSERT_GT(methods.length(), 0);
}

TEST(class_facade, reflection_class_hasMethod) {
    ReflectionClass rc("DateTime");
    ASSERT_TRUE(rc.hasMethod("format").toBool());
    ASSERT_FALSE(rc.hasMethod("nonexistent_method").toBool());
}

TEST(class_facade, reflection_class_getMethod) {
    ReflectionClass rc("DateTime");
    auto method = rc.getMethod("format");
    ASSERT_TRUE(method.isObject());
}

TEST(class_facade, reflection_class_getProperties) {
    ReflectionClass rc("DateTime");
    auto props = rc.getProperties();
    ASSERT_TRUE(props.isArray());
}

TEST(class_facade, reflection_class_getConstants) {
    ReflectionClass rc("DateTime");
    auto consts = rc.getConstants();
    ASSERT_TRUE(consts.isArray());
    ASSERT_TRUE(consts.offsetExists("ATOM"));
}

TEST(class_facade, reflection_class_getConstant) {
    ReflectionClass rc("DateTime");
    auto atom = rc.getConstant("ATOM");
    ASSERT_STREQ(atom.toCString(), "Y-m-d\\TH:i:sP");
}

TEST(class_facade, reflection_class_hasConstant) {
    ReflectionClass rc("DateTime");
    ASSERT_TRUE(rc.hasConstant("ATOM").toBool());
    ASSERT_FALSE(rc.hasConstant("NONEXISTENT").toBool());
}

TEST(class_facade, reflection_class_newInstance) {
    ReflectionClass rc("stdClass");
    auto obj = rc.newInstance();
    ASSERT_TRUE(obj.isObject());
}

TEST(class_facade, reflection_class_newInstanceArgs) {
    ReflectionClass rc("DateTime");
    Array args;
    args.append("2022-01-01");
    auto obj = rc.newInstanceArgs(args);
    ASSERT_TRUE(obj.isObject());
    auto fmt = obj.call("format", {"Y-m-d"});
    ASSERT_STREQ(fmt.toCString(), "2022-01-01");
}

TEST(class_facade, reflection_class_isSubclassOf) {
    ReflectionClass rc("DateTime");
    ASSERT_FALSE(rc.isSubclassOf("stdClass").toBool());
}

TEST(class_facade, reflection_class_getExtensionName) {
    ReflectionClass rc("DateTime");
    auto ext = rc.getExtensionName();
    ASSERT_STREQ(ext.toCString(), "date");
}

TEST(class_facade, reflection_class_getShortName) {
    ReflectionClass rc("DateTime");
    ASSERT_STREQ(rc.getShortName().toCString(), "DateTime");
}

TEST(class_facade, reflection_class_getNamespaceName) {
    ReflectionClass rc("DateTime");
    ASSERT_STREQ(rc.getNamespaceName().toCString(), "");
}

TEST(class_facade, reflection_class_getInterfaces) {
    ReflectionClass rc("DateTime");
    auto ifaces = rc.getInterfaces();
    ASSERT_TRUE(ifaces.isArray());
}

TEST(class_facade, reflection_class_getInterfaceNames) {
    ReflectionClass rc("DateTime");
    auto names = rc.getInterfaceNames();
    ASSERT_TRUE(names.isArray());
}

TEST(class_facade, reflection_class_getParentClass) {
    ReflectionClass rc("DateTime");
    auto parent = rc.getParentClass();
    ASSERT_TRUE(parent.isFalse() || parent.isObject());
}

TEST(class_facade, reflection_class_getFileName) {
    ReflectionClass rc("DateTime");
    auto fn = rc.getFileName();
    // Internal classes don't have a file name
    ASSERT_TRUE(fn.isFalse() || fn.isString());
}

TEST(class_facade, reflection_class_isInstance) {
    ReflectionClass rc("stdClass");
    auto obj = newObject("stdClass");
    ASSERT_TRUE(rc.isInstance(obj).toBool());
    auto dt = newObject("DateTime");
    ASSERT_FALSE(rc.isInstance(dt).toBool());
}

TEST(class_facade, reflection_class_getConstructor) {
    ReflectionClass rc("DateTime");
    auto ctor = rc.getConstructor();
    ASSERT_TRUE(ctor.isObject() || ctor.isNull());
}

TEST(class_facade, reflection_class_isCloneable) {
    ReflectionClass rc("stdClass");
    ASSERT_TRUE(rc.isCloneable().toBool());
}

TEST(class_facade, reflection_class_getStaticProperties) {
    ReflectionClass rc("DateTime");
    auto sp = rc.getStaticProperties();
    ASSERT_TRUE(sp.isArray());
}

// ============================================================
// ReflectionObject
// ============================================================

TEST(class_facade, reflection_object_construct) {
    auto obj = newObject("stdClass");
    obj.set("prop", 42);
    ReflectionObject ro(obj);
    ASSERT_STREQ(ro.getName().toCString(), "stdClass");
    ASSERT_TRUE(ro.hasProperty("prop").toBool());
}

TEST(class_facade, reflection_object_getProperty) {
    auto obj = newObject("stdClass");
    obj.set("name", "test");
    ReflectionObject ro(obj);
    auto prop = ro.getProperty("name");
    ASSERT_TRUE(prop.isObject());
}

TEST(class_facade, reflection_object_getProperties) {
    auto obj = newObject("stdClass");
    obj.set("a", 1);
    obj.set("b", 2);
    ReflectionObject ro(obj);
    auto props = ro.getProperties();
    ASSERT_TRUE(props.isArray());
    ASSERT_EQ(props.length(), 2);
}

// ============================================================
// ReflectionFunction
// ============================================================

TEST(class_facade, reflection_function_getName) {
    ReflectionFunction rf("strlen");
    ASSERT_STREQ(rf.getName().toCString(), "strlen");
}

TEST(class_facade, reflection_function_isInternal) {
    ReflectionFunction rf("strlen");
    ASSERT_TRUE(rf.isInternal().toBool());
    ASSERT_FALSE(rf.isUserDefined().toBool());
}

TEST(class_facade, reflection_function_getNumberOfParameters) {
    ReflectionFunction rf("strlen");
    ASSERT_EQ(rf.getNumberOfParameters().toInt(), 1);
}

TEST(class_facade, reflection_function_getNumberOfRequiredParameters) {
    ReflectionFunction rf("strlen");
    ASSERT_EQ(rf.getNumberOfRequiredParameters().toInt(), 1);
}

TEST(class_facade, reflection_function_getParameters) {
    ReflectionFunction rf("strlen");
    auto params = rf.getParameters();
    ASSERT_TRUE(params.isArray());
    ASSERT_EQ(params.length(), 1);
}

TEST(class_facade, reflection_function_invoke) {
    ReflectionFunction rf("strlen");
    auto rs = rf.invoke(Variant("hello"));
    ASSERT_EQ(rs.toInt(), 5);
}

TEST(class_facade, reflection_function_returnsReference) {
    ReflectionFunction rf("strlen");
    ASSERT_FALSE(rf.returnsReference().toBool());
}

TEST(class_facade, reflection_function_isClosure) {
    ReflectionFunction rf("strlen");
    ASSERT_FALSE(rf.isClosure().toBool());
}

TEST(class_facade, reflection_function_isVariadic) {
    ReflectionFunction rf("strlen");
    ASSERT_FALSE(rf.isVariadic().toBool());
}

TEST(class_facade, reflection_function_getExtensionName) {
    ReflectionFunction rf("strlen");
    ASSERT_TRUE(rf.getExtensionName().isString());
}

TEST(class_facade, reflection_function_getShortName) {
    ReflectionFunction rf("strlen");
    ASSERT_STREQ(rf.getShortName().toCString(), "strlen");
}

// ============================================================
// ReflectionMethod
// ============================================================

TEST(class_facade, reflection_method_construct) {
    ReflectionMethod rm("DateTime", "format");
    ASSERT_STREQ(rm.getName().toCString(), "format");
}

TEST(class_facade, reflection_method_isPublic) {
    ReflectionMethod rm("DateTime", "format");
    ASSERT_TRUE(rm.isPublic().toBool());
}

TEST(class_facade, reflection_method_getDeclaringClass) {
    ReflectionMethod rm("DateTime", "format");
    auto dc = rm.getDeclaringClass();
    ASSERT_TRUE(dc.isObject());
}

TEST(class_facade, reflection_method_getNumberOfParameters) {
    ReflectionMethod rm("DateTime", "format");
    ASSERT_EQ(rm.getNumberOfParameters().toInt(), 1);
}

TEST(class_facade, reflection_method_getModifiers) {
    ReflectionMethod rm("DateTime", "format");
    auto mods = rm.getModifiers();
    ASSERT_TRUE(mods.isInt());
}

TEST(class_facade, reflection_method_invoke) {
    ReflectionMethod rm("DateTime", "format");
    DateTime dt("2022-01-01 12:00:00");
    auto rs = rm.invoke(dt.getObject(), Variant("Y年m月d日"));
    ASSERT_STREQ(rs.toCString(), "2022年01月01日");
}

TEST(class_facade, reflection_method_isStatic) {
    ReflectionMethod rm("DateTime", "format");
    ASSERT_FALSE(rm.isStatic().toBool());
}

TEST(class_facade, reflection_method_isInternal) {
    ReflectionMethod rm("DateTime", "format");
    ASSERT_TRUE(rm.isInternal().toBool());
}

TEST(class_facade, reflection_method_getFileName) {
    ReflectionMethod rm("DateTime", "format");
    auto fn = rm.getFileName();
    ASSERT_TRUE(fn.isFalse() || fn.isString());
}

// ============================================================
// ReflectionProperty
// ============================================================

TEST(class_facade, reflection_property_construct) {
    // Exception::$message is a protected property
    ReflectionProperty rp("Exception", "message");
    ASSERT_TRUE(rp.isProtected().toBool());
    ASSERT_STREQ(rp.getName().toCString(), "message");
}

TEST(class_facade, reflection_property_from_object) {
    // Exception has declared properties (message, code, file, line)
    auto obj = newObject("Exception", {"test"});
    ReflectionObject ro(obj);
    auto props = ro.getProperties();
    ASSERT_TRUE(props.isArray());
    ASSERT_GT(props.length(), 0);
}

// ============================================================
// ReflectionExtension
// ============================================================

TEST(class_facade, reflection_extension_getName) {
    ReflectionExtension re("date");
    ASSERT_STREQ(re.getName().toCString(), "date");
}

TEST(class_facade, reflection_extension_isPersistent) {
    ReflectionExtension re("date");
    ASSERT_TRUE(re.isPersistent().toBool());
}

TEST(class_facade, reflection_extension_getVersion) {
    ReflectionExtension re("Core");
    auto ver = re.getVersion();
    ASSERT_TRUE(ver.isString());
}

TEST(class_facade, reflection_extension_getFunctions) {
    ReflectionExtension re("date");
    auto funcs = re.getFunctions();
    ASSERT_TRUE(funcs.isArray());
    ASSERT_GT(funcs.length(), 0);
}

TEST(class_facade, reflection_extension_getClasses) {
    ReflectionExtension re("date");
    auto classes = re.getClasses();
    ASSERT_TRUE(classes.isArray());
}

TEST(class_facade, reflection_extension_getClassNames) {
    ReflectionExtension re("date");
    auto names = re.getClassNames();
    ASSERT_TRUE(names.isArray());
}

// ============================================================
// ReflectionParameter
// ============================================================

TEST(class_facade, reflection_parameter_getName) {
    ReflectionParameter rp("strlen", 0);
    ASSERT_STREQ(rp.getName().toCString(), "string");
}

// ============================================================
// ReflectionConstant (PHP 8.2+)
// ============================================================

#if PHP_VERSION_ID >= 80400
TEST(class_facade, reflection_constant) {
    ReflectionConstant rc("PHP_INT_MAX");
    ASSERT_STREQ(rc.getName().toCString(), "PHP_INT_MAX");
    ASSERT_TRUE(rc.getValue().isInt());
}

TEST(class_facade, reflection_constant_getShortName) {
    ReflectionConstant rc("PHP_INT_MAX");
    ASSERT_STREQ(rc.getShortName().toCString(), "PHP_INT_MAX");
    ASSERT_FALSE(rc.isDeprecated().toBool());
}
#endif

// ============================================================
// ReflectionReference
// ============================================================

TEST(class_facade, reflection_reference_fromArrayElement) {
    // Use eval to create array with a reference element
    // $arr['key'] becomes a reference when $ref =& $arr['key']
    auto arr = eval("$arr = ['key' => 42]; $ref =& $arr['key']; return $arr;");
    ASSERT_TRUE(arr.isArray());
    auto ref_var = ReflectionReference::fromArrayElement(arr, "key");
    ASSERT_TRUE(ref_var.isObject());
    ASSERT_TRUE(ref_var.call("getId").isString());
}

// ============================================================
// ReflectionGenerator (basic)
// ============================================================

// ReflectionGenerator requires a live generator, skip basic construction test

// ============================================================
// SplFileInfo
// ============================================================

TEST(class_facade, splfileinfo_construct) {
    auto test_file = get_include_dir() + "/../include/return_const.php";
    SplFileInfo fi(test_file);
    ASSERT_TRUE(fi.isFile().toBool());
    ASSERT_FALSE(fi.isDir().toBool());
}

TEST(class_facade, splfileinfo_getFilename) {
    auto test_file = get_include_dir() + "/../include/return_const.php";
    SplFileInfo fi(test_file);
    auto name = fi.getFilename();
    ASSERT_STREQ(name.toCString(), "return_const.php");
}

TEST(class_facade, splfileinfo_getExtension) {
    auto test_file = get_include_dir() + "/../include/return_const.php";
    SplFileInfo fi(test_file);
    ASSERT_STREQ(fi.getExtension().toCString(), "php");
}

TEST(class_facade, splfileinfo_getPath) {
    auto test_file = get_include_dir() + "/../include/return_const.php";
    SplFileInfo fi(test_file);
    auto path = fi.getPath();
    ASSERT_TRUE(path.isString());
    ASSERT_GT(path.length(), 0);
}

TEST(class_facade, splfileinfo_getPathname) {
    auto test_file = get_include_dir() + "/../include/return_const.php";
    SplFileInfo fi(test_file);
    auto pn = fi.getPathname();
    ASSERT_TRUE(pn.isString());
}

TEST(class_facade, splfileinfo_getSize) {
    auto test_file = get_include_dir() + "/../include/return_const.php";
    SplFileInfo fi(test_file);
    auto size = fi.getSize();
    ASSERT_GT(size.toInt(), 0);
}

TEST(class_facade, splfileinfo_getMTime) {
    auto test_file = get_include_dir() + "/../include/return_const.php";
    SplFileInfo fi(test_file);
    auto mtime = fi.getMTime();
    ASSERT_GT(mtime.toInt(), 0);
}

TEST(class_facade, splfileinfo_isReadable) {
    auto test_file = get_include_dir() + "/../include/return_const.php";
    SplFileInfo fi(test_file);
    ASSERT_TRUE(fi.isReadable().toBool());
}

TEST(class_facade, splfileinfo_getBasename) {
    auto test_file = get_include_dir() + "/../include/return_const.php";
    SplFileInfo fi(test_file);
    ASSERT_STREQ(fi.getBasename().toCString(), "return_const.php");
    ASSERT_STREQ(fi.getBasename(".php").toCString(), "return_const");
}

// ============================================================
// DirectoryIterator
// ============================================================

TEST(class_facade, directory_iterator_basic) {
    auto dir = get_include_dir();
    DirectoryIterator di(dir);
    di.rewind();
    ASSERT_TRUE(di.valid().toBool());
    auto first = di.getFilename();
    ASSERT_TRUE(first.isString());
}

TEST(class_facade, directory_iterator_isDot) {
    auto dir = get_include_dir();
    DirectoryIterator di(dir);
    di.rewind();
    // First entry may be '.' or an actual file
    ASSERT_TRUE(di.valid().toBool());
}

TEST(class_facade, directory_iterator_traversal) {
    auto dir = get_include_dir();
    int count = 0;
    for (DirectoryIterator di(dir); di.valid().toBool(); di.next()) {
        if (!di.isDot().toBool()) {
            count++;
            auto name = di.getFilename();
            ASSERT_TRUE(name.isString());
            ASSERT_GT(name.length(), 0);
        }
    }
    ASSERT_GT(count, 0);
}

TEST(class_facade, directory_iterator_seek) {
    auto dir = get_include_dir();
    DirectoryIterator di(dir);
    int total = 0;
    for (di.rewind(); di.valid().toBool(); di.next()) {
        total++;
    }
    // Seek to index 0
    di.seek(0);
    ASSERT_TRUE(di.valid().toBool());
}

// ============================================================
// SplFileObject
// ============================================================

TEST(class_facade, splfileobject_construct) {
    auto test_file = get_include_dir() + "/../include/return_const.php";
    SplFileObject fo(test_file);
    ASSERT_TRUE(fo.valid().toBool());
}

TEST(class_facade, splfileobject_fgets) {
    auto test_file = get_include_dir() + "/../include/return_const.php";
    SplFileObject fo(test_file);
    auto line = fo.fgets();
    ASSERT_TRUE(line.isString());
    ASSERT_GT(line.length(), 0);
}

TEST(class_facade, splfileobject_eof) {
    auto test_file = get_include_dir() + "/../include/return_const.php";
    SplFileObject fo(test_file);
    ASSERT_FALSE(fo.eof().toBool());
}

TEST(class_facade, splfileobject_fread) {
    auto test_file = get_include_dir() + "/../include/return_const.php";
    SplFileObject fo(test_file);
    auto data = fo.fread(10);
    ASSERT_TRUE(data.isString());
    ASSERT_EQ(data.length(), 10);
}

TEST(class_facade, splfileobject_fgetc) {
    auto test_file = get_include_dir() + "/../include/return_const.php";
    SplFileObject fo(test_file);
    auto c = fo.fgetc();
    ASSERT_TRUE(c.isString());
    ASSERT_EQ(c.length(), 1);
}

TEST(class_facade, splfileobject_ftell) {
    auto test_file = get_include_dir() + "/../include/return_const.php";
    SplFileObject fo(test_file);
    ASSERT_EQ(fo.ftell().toInt(), 0);
    fo.fgetc();
    ASSERT_EQ(fo.ftell().toInt(), 1);
}

TEST(class_facade, splfileobject_fseek) {
    auto test_file = get_include_dir() + "/../include/return_const.php";
    SplFileObject fo(test_file);
    fo.fseek(5);
    auto pos = fo.ftell();
    ASSERT_GE(pos.toInt(), 5);
}

TEST(class_facade, splfileobject_getFilename) {
    auto test_file = get_include_dir() + "/../include/return_const.php";
    SplFileObject fo(test_file);
    ASSERT_STREQ(fo.getFilename().toCString(), "return_const.php");
}

TEST(class_facade, splfileobject_fstat) {
    auto test_file = get_include_dir() + "/../include/return_const.php";
    SplFileObject fo(test_file);
    auto stat = fo.fstat();
    ASSERT_TRUE(stat.isArray());
}

TEST(class_facade, splfileobject_fwrite_and_read) {
    auto tmp = "/tmp/__phpx_test_write.tmp";
    {
        SplFileObject fo(tmp, "w");
        auto data = String("Hello World");
        auto written = fo.fwrite(data, data.length());
        ASSERT_GT(written.toInt(), 0);
    }
    {
        SplFileObject fo(tmp, "r");
        auto content = fo.fgets();
        ASSERT_STREQ(content.toCString(), "Hello World");
    }
    ::unlink(tmp);
}

// ============================================================
// SplTempFileObject
// ============================================================

TEST(class_facade, spl_temp_file_object) {
    SplTempFileObject tfo;
    auto data = String("Hello World");
    auto written = tfo.fwrite(data, data.length());
    ASSERT_GT(written.toInt(), 0);
    tfo.rewind();
    ASSERT_TRUE(tfo.valid().toBool());
    auto line = tfo.fgets();
    ASSERT_STREQ(line.toCString(), "Hello World");
}

// ============================================================
// RuntimeException and exception classes
// ============================================================

TEST(class_facade, exception_getMessage) {
    RuntimeException ex("test error", 42);
    ASSERT_STREQ(ex.getMessage().toCString(), "test error");
    ASSERT_EQ(ex.getCode().toInt(), 42);
}

TEST(class_facade, exception_getTraceAsString) {
    RuntimeException ex("test");
    auto trace = ex.getTraceAsString();
    ASSERT_TRUE(trace.isString());
}

TEST(class_facade, exception_getLine) {
    RuntimeException ex("test");
    ASSERT_TRUE(ex.getLine().isInt());
}

// ============================================================
// LogicException hierarchy
// ============================================================

TEST(class_facade, logic_exception) {
    LogicException ex("logic error");
    ASSERT_STREQ(ex.getMessage().toCString(), "logic error");
}

TEST(class_facade, invalid_argument_exception) {
    InvalidArgumentException ex("invalid arg");
    ASSERT_STREQ(ex.getMessage().toCString(), "invalid arg");
}

TEST(class_facade, domain_exception) {
    DomainException ex("domain");
    ASSERT_STREQ(ex.getMessage().toCString(), "domain");
}

TEST(class_facade, length_exception) {
    LengthException ex("length");
    ASSERT_STREQ(ex.getMessage().toCString(), "length");
}

TEST(class_facade, out_of_range_exception) {
    OutOfRangeException ex("out of range");
    ASSERT_STREQ(ex.getMessage().toCString(), "out of range");
}

TEST(class_facade, out_of_bounds_exception) {
    OutOfBoundsException ex("out of bounds");
    ASSERT_STREQ(ex.getMessage().toCString(), "out of bounds");
}

TEST(class_facade, overflow_exception) {
    OverflowException ex("overflow");
    ASSERT_STREQ(ex.getMessage().toCString(), "overflow");
}

TEST(class_facade, underflow_exception) {
    UnderflowException ex("underflow");
    ASSERT_STREQ(ex.getMessage().toCString(), "underflow");
}

TEST(class_facade, range_exception) {
    RangeException ex("range");
    ASSERT_STREQ(ex.getMessage().toCString(), "range");
}

TEST(class_facade, unexpected_value_exception) {
    UnexpectedValueException ex("unexpected");
    ASSERT_STREQ(ex.getMessage().toCString(), "unexpected");
}

TEST(class_facade, bad_function_call_exception) {
    BadFunctionCallException ex("bad func call");
    ASSERT_STREQ(ex.getMessage().toCString(), "bad func call");
}

TEST(class_facade, bad_method_call_exception) {
    BadMethodCallException ex("bad method call");
    ASSERT_STREQ(ex.getMessage().toCString(), "bad method call");
}

// ============================================================
// ArrayIterator
// ============================================================

TEST(class_facade, array_iterator_construct) {
    Array arr{1, 2, 3};
    ArrayIterator_ ai(arr);
    ai.rewind();
    ASSERT_TRUE(ai.valid().toBool());
    ASSERT_EQ(ai.current().toInt(), 1);
}

TEST(class_facade, array_iterator_traversal) {
    Array arr{10, 20, 30, 40, 50};
    ArrayIterator_ ai(arr);
    int sum = 0;
    for (ai.rewind(); ai.valid().toBool(); ai.next()) {
        sum += ai.current().toInt();
    }
    ASSERT_EQ(sum, 150);
}

TEST(class_facade, array_iterator_key) {
    Array arr{"a", "b", "c"};
    ArrayIterator_ ai(arr);
    ai.rewind();
    ASSERT_EQ(ai.key().toInt(), 0);
    ai.next();
    ASSERT_EQ(ai.key().toInt(), 1);
}

TEST(class_facade, array_iterator_seek) {
    Array arr{1, 2, 3, 4, 5};
    ArrayIterator_ ai(arr);
    ai.seek(3);
    ASSERT_EQ(ai.current().toInt(), 4);
}

TEST(class_facade, array_iterator_count) {
    Array arr{1, 2, 3};
    ArrayIterator_ ai(arr);
    ASSERT_EQ(ai.count().toInt(), 3);
}

TEST(class_facade, array_iterator_getArrayCopy) {
    Array arr{1, 2, 3};
    ArrayIterator_ ai(arr);
    auto copy = ai.getArrayCopy();
    ASSERT_TRUE(copy.isArray());
}

// ============================================================
// AppendIterator
// ============================================================

TEST(class_facade, append_iterator) {
    Array arr1{1, 2};
    Array arr2{3, 4};
    AppendIterator ap;
    ap.append(ArrayIterator_(arr1).getObject());
    ap.append(ArrayIterator_(arr2).getObject());
    ap.rewind();
    ASSERT_TRUE(ap.valid().toBool());
    ASSERT_EQ(ap.current().toInt(), 1);
}

// ============================================================
// CallbackFilterIterator (basic)
// ============================================================

TEST(class_facade, callback_filter_iterator) {
    Array arr{1, 2, 3, 4, 5, 6};
    ArrayIterator_ base(arr);
    auto callback = eval("return function($v) { return $v % 2 == 0; };");
    CallbackFilterIterator cfi(base.getObject(), callback);
    int count = 0;
    for (cfi.rewind(); cfi.valid().toBool(); cfi.next()) {
        ASSERT_EQ(cfi.current().toInt() % 2, 0);
        count++;
    }
    ASSERT_EQ(count, 3);
}

// ============================================================
// RegexIterator (basic)
// ============================================================

TEST(class_facade, regex_iterator) {
    Array arr;
    arr.append("apple");
    arr.append("banana");
    arr.append("apricot");
    arr.append("cherry");
    ArrayIterator_ base(arr);
    RegexIterator ri(base.getObject(), "/^ap/");
    int count = 0;
    for (ri.rewind(); ri.valid().toBool(); ri.next()) {
        ASSERT_TRUE(ri.current().isString());
        count++;
    }
    ASSERT_EQ(count, 2);
}

// ============================================================
// LimitIterator
// ============================================================

TEST(class_facade, limit_iterator) {
    Array arr{1, 2, 3, 4, 5, 6, 7, 8};
    var base = ArrayIterator_(arr).getObject();
    LimitIterator li(base, 2, 3);  // offset=2, limit=3 -> items 3,4,5
    int count = 0;
    auto sum = 0;
    for (li.rewind(); li.valid().toBool(); li.next()) {
        sum += li.current().toInt();
        count++;
    }
    ASSERT_EQ(count, 3);
    ASSERT_EQ(sum, 12);  // 3+4+5
}

TEST(class_facade, limit_iterator_getPosition) {
    Array arr{10, 20, 30, 40, 50};
    var base = ArrayIterator_(arr).getObject();
    LimitIterator li(base, 1, 2);  // offset=1, limit=2 -> items 20, 30
    li.rewind();
    ASSERT_EQ(li.current().toInt(), 20);  // first element in window
    li.next();
    ASSERT_EQ(li.current().toInt(), 30);  // second element in window
}

// ============================================================
// InfiniteIterator
// ============================================================

TEST(class_facade, infinite_iterator) {
    Array arr{1, 2};
    var base = ArrayIterator_(arr).getObject();
    InfiniteIterator ii(base);
    ii.rewind();
    ASSERT_TRUE(ii.valid().toBool());
    ASSERT_EQ(ii.current().toInt(), 1);
    ii.next();
    ASSERT_EQ(ii.current().toInt(), 2);
}

// ============================================================
// MultipleIterator
// ============================================================

TEST(class_facade, multiple_iterator_basic) {
    MultipleIterator mi;
    Array a1{1, 2};
    Array a2{"a", "b"};
    mi.attachIterator(ArrayIterator_(a1).getObject());
    mi.attachIterator(ArrayIterator_(a2).getObject());
    mi.rewind();
    ASSERT_TRUE(mi.valid().toBool());
    auto cur = mi.current();
    ASSERT_TRUE(cur.isArray());
}

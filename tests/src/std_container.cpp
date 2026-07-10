#include "phpx_test.h"
#include "phpx_func.h"
#include "typephp_helper.h"

#include <cstring>

using namespace php;

// ============ StdContainerBox ============

TEST(std_container_box, construct_default) {
    Var v = Var(new StdContainerBox<StdVector<Int>>(42));
    auto *box = v.toBox<StdContainerBox<StdVector<Int>>>();
    ASSERT_NE(box, nullptr);
    ASSERT_EQ(box->getTypeInfo(), 42u);
    ASSERT_EQ(box->container.size(), 0u);
}

TEST(std_container_box, construct_with_container_args) {
    Var v = Var(new StdContainerBox<StdVector<Int>>(99, (std::size_t) 10));
    auto *box = v.toBox<StdContainerBox<StdVector<Int>>>();
    ASSERT_NE(box, nullptr);
    ASSERT_EQ(box->getTypeInfo(), 99u);
    ASSERT_EQ(box->container.size(), 10u);
}

TEST(std_container_box, destroy_via_unset) {
    // Box cleanup via Var::unset() — no leak, no crash
    Var v = Var(new StdContainerBox<StdVector<Int>>(1, (std::size_t) 5));
    v.unset();
    // After unset(), Var is in undefined state (not null), but cleanup was done
}

TEST(std_container_box, type_info_preserved) {
    Var v = Var(new StdContainerBox<StdVector<Int>>(0xDEAD));
    auto *box = v.toBox<StdContainerBox<StdVector<Int>>>();
    ASSERT_EQ(box->getTypeInfo(), 0xDEADu);
}

// ============ StdArray via StdContainerBox ============

using StdArray5Int = StdArray<Int, 5>;

TEST(std_container_box, stdarray_access) {
    Var v = Var(new StdContainerBox<StdArray5Int>(0));
    auto &arr = v.toBox<StdContainerBox<StdArray5Int>>()->container;

    arr.offsetSet(0, 10);
    arr.offsetSet(1, 20);
    arr.offsetSet(2, 30);

    ASSERT_EQ(arr.offsetGet(0), 10);
    ASSERT_EQ(arr.offsetGet(1), 20);
    ASSERT_EQ(arr.offsetGet(2), 30);
    ASSERT_EQ(arr.size(), 5u);
}

TEST(std_container_box, stdarray_out_of_bounds) {
    Var v = Var(new StdContainerBox<StdArray5Int>(0));
    auto &arr = v.toBox<StdContainerBox<StdArray5Int>>()->container;

    try_call(
        []() {
            Var v2 = Var(new StdContainerBox<StdArray5Int>(0));
            auto &a = v2.toBox<StdContainerBox<StdArray5Int>>()->container;
            a.offsetGet(100);
        },
        "out of bounds");
}

TEST(std_container_box, stdarray_unset) {
    Var v = Var(new StdContainerBox<StdArray5Int>(0));
    auto &arr = v.toBox<StdContainerBox<StdArray5Int>>()->container;

    arr.offsetSet(0, 42);
    ASSERT_EQ(arr.offsetGet(0), 42);
    arr.offsetUnset(0);
    ASSERT_EQ(arr.offsetGet(0), 0);
}

// ============ StdVector via StdContainerBox ============

TEST(std_container_box, stdvector_push_back) {
    Var v = Var(new StdContainerBox<StdVector<Int>>(0));
    auto &vec = v.toBox<StdContainerBox<StdVector<Int>>>()->container;

    vec.push_back(100);
    vec.push_back(200);
    vec.push_back(300);

    ASSERT_EQ(vec.size(), 3u);
    ASSERT_EQ(vec.offsetGet(0), 100);
    ASSERT_EQ(vec.offsetGet(1), 200);
    ASSERT_EQ(vec.offsetGet(2), 300);
}

TEST(std_container_box, stdvector_offset_set) {
    Var v = Var(new StdContainerBox<StdVector<Int>>(0, (std::size_t) 3));
    auto &vec = v.toBox<StdContainerBox<StdVector<Int>>>()->container;

    vec.offsetSet(0, 10);
    vec.offsetSet(1, 20);
    vec.offsetSet(2, 30);

    ASSERT_EQ(vec[0], 10);
    ASSERT_EQ(vec[1], 20);
    ASSERT_EQ(vec[2], 30);
}

TEST(std_container_box, stdvector_default_value) {
    Var v = Var(new StdContainerBox<StdVector<Int>>(0, (std::size_t) 5));
    auto &vec = v.toBox<StdContainerBox<StdVector<Int>>>()->container;

    for (Int i = 0; i < 5; i++) {
        ASSERT_EQ(vec.offsetGet(i), 0);
    }
}

// ============ StdOrderedMap via StdContainerBox ============

TEST(std_container_box, stdordered_map_set_get) {
    Var v = Var(new StdContainerBox<StdOrderedMap<Int, String>>(0));
    auto &map = v.toBox<StdContainerBox<StdOrderedMap<Int, String>>>()->container;

    map.offsetSet(1, String("one"));
    map.offsetSet(2, String("two"));
    map.offsetSet(3, String("three"));

    ASSERT_EQ(map.size(), 3u);
    ASSERT_STREQ(map.offsetGet(1).toCString(), "one");
    ASSERT_STREQ(map.offsetGet(2).toCString(), "two");
    ASSERT_STREQ(map.offsetGet(3).toCString(), "three");
}

TEST(std_container_box, stdordered_map_overwrite) {
    Var v = Var(new StdContainerBox<StdOrderedMap<Int, String>>(0));
    auto &map = v.toBox<StdContainerBox<StdOrderedMap<Int, String>>>()->container;

    map.offsetSet(1, String("first"));
    map.offsetSet(1, String("second"));

    ASSERT_EQ(map.size(), 1u);
    ASSERT_STREQ(map.offsetGet(1).toCString(), "second");
}

TEST(std_container_box, stdordered_map_unset) {
    Var v = Var(new StdContainerBox<StdOrderedMap<Int, String>>(0));
    auto &map = v.toBox<StdContainerBox<StdOrderedMap<Int, String>>>()->container;

    map.offsetSet(1, String("one"));
    map.offsetSet(2, String("two"));
    ASSERT_EQ(map.size(), 2u);

    map.offsetUnset(1);
    ASSERT_EQ(map.size(), 1u);
}

TEST(std_container_box, stdordered_map_string_keys) {
    Var v = Var(new StdContainerBox<StdOrderedMap<String, Int>>(0));
    auto &map = v.toBox<StdContainerBox<StdOrderedMap<String, Int>>>()->container;

    map.offsetSet(String("aaa"), 100);
    map.offsetSet(String("bbb"), 200);

    ASSERT_EQ(map.size(), 2u);
    ASSERT_EQ(map.offsetGet(String("aaa")), 100);
    ASSERT_EQ(map.offsetGet(String("bbb")), 200);
}

// ============ StdMap via StdContainerBox ============

TEST(std_container_box, stdordered_map__TMP__set_get) {
    Var v = Var(new StdContainerBox<StdMap<Int, Int>>(0));
    auto &map = v.toBox<StdContainerBox<StdMap<Int, Int>>>()->container;

    map.offsetSet(10, 100);
    map.offsetSet(20, 200);
    map.offsetSet(30, 300);

    ASSERT_EQ(map.size(), 3u);
    ASSERT_EQ(map.offsetGet(10), 100);
    ASSERT_EQ(map.offsetGet(20), 200);
    ASSERT_EQ(map.offsetGet(30), 300);
}

TEST(std_container_box, stdordered_map__TMP__string_keys) {
    Var v = Var(new StdContainerBox<StdMap<String, Int>>(0));
    auto &map = v.toBox<StdContainerBox<StdMap<String, Int>>>()->container;

    map.offsetSet(String("foo"), 1);
    map.offsetSet(String("bar"), 2);

    ASSERT_EQ(map.size(), 2u);
    ASSERT_EQ(map.offsetGet(String("foo")), 1);
    ASSERT_EQ(map.offsetGet(String("bar")), 2);
}

TEST(std_container_box, stdordered_map__TMP__unset) {
    Var v = Var(new StdContainerBox<StdMap<Int, Int>>(0));
    auto &map = v.toBox<StdContainerBox<StdMap<Int, Int>>>()->container;

    map.offsetSet(1, 10);
    map.offsetSet(2, 20);
    map.offsetUnset(1);

    ASSERT_EQ(map.size(), 1u);
    ASSERT_EQ(map.offsetGet(2), 20);
}

// ============ php::toStdContainer ============

TEST(std_container_cast, vector_int) {
    Var v = Var(new StdContainerBox<StdVector<Int>>(42, std::initializer_list<Int>{1, 2, 3, 4, 5}));
    auto &vec = php::toStdContainer<StdVector<Int>>(v, 42);

    ASSERT_EQ(vec.size(), 5u);
    ASSERT_EQ(vec[0], 1);
    ASSERT_EQ(vec[4], 5);
}

TEST(std_container_cast, vector_modify) {
    Var v = Var(new StdContainerBox<StdVector<Int>>(100));
    auto &vec = php::toStdContainer<StdVector<Int>>(v, 100);

    vec.push_back(42);
    ASSERT_EQ(vec.size(), 1u);
    ASSERT_EQ(vec[0], 42);
}

TEST(std_container_cast, type_mismatch_throws) {
    try_call(
        []() {
            Var v = Var(new StdContainerBox<StdVector<Int>>(1));
            php::toStdContainer<StdVector<Int>>(v, 999);  // wrong type_id
        },
        "type mismatch");
}

TEST(std_container_cast, array_type) {
    Var v = Var(new StdContainerBox<StdArray<Int, 3>>(7, std::initializer_list<Int>{10, 20, 30}));
    auto &arr = php::toStdContainer<StdArray<Int, 3>>(v, 7);

    ASSERT_EQ(arr.size(), 3u);
    ASSERT_EQ(arr[0], 10);
    ASSERT_EQ(arr[1], 20);
    ASSERT_EQ(arr[2], 30);
}

TEST(std_container_cast, map_type) {
    Var v = Var(new StdContainerBox<StdOrderedMap<Int, String>>(5));
    auto &map = php::toStdContainer<StdOrderedMap<Int, String>>(v, 5);

    map.offsetSet(1, String("alpha"));
    ASSERT_STREQ(map.offsetGet(1).toCString(), "alpha");
}

// ============ toBox recovery ============

TEST(to_box, vector_int) {
    Var v = Var(new StdContainerBox<StdVector<Int>>(42, std::initializer_list<Int>{1, 2, 3, 4, 5}));
    auto &vec = v.toBox<StdContainerBox<StdVector<Int>>>()->container;

    ASSERT_EQ(vec.size(), 5u);
    ASSERT_EQ(vec[0], 1);
    ASSERT_EQ(vec[4], 5);
}

TEST(to_box, vector_modify) {
    Var v = Var(new StdContainerBox<StdVector<Int>>(100));
    auto &vec = v.toBox<StdContainerBox<StdVector<Int>>>()->container;

    vec.push_back(42);
    ASSERT_EQ(vec.size(), 1u);
    ASSERT_EQ(vec[0], 42);
}

TEST(to_box, array_type) {
    Var v = Var(new StdContainerBox<StdArray<Int, 3>>(7, std::initializer_list<Int>{10, 20, 30}));
    auto &arr = v.toBox<StdContainerBox<StdArray<Int, 3>>>()->container;

    ASSERT_EQ(arr.size(), 3u);
    ASSERT_EQ(arr[0], 10);
    ASSERT_EQ(arr[1], 20);
    ASSERT_EQ(arr[2], 30);
}

TEST(to_box, map_type) {
    Var v = Var(new StdContainerBox<StdOrderedMap<Int, String>>(5));
    auto &map = v.toBox<StdContainerBox<StdOrderedMap<Int, String>>>()->container;

    map.offsetSet(1, String("alpha"));
    ASSERT_STREQ(map.offsetGet(1).toCString(), "alpha");
}

// ============ Multiple containers ============

TEST(std_container_box, multiple_independent_containers) {
    Var v1 = Var(new StdContainerBox<StdVector<Int>>(1));
    Var v2 = Var(new StdContainerBox<StdVector<Int>>(2));

    auto &vec1 = v1.toBox<StdContainerBox<StdVector<Int>>>()->container;
    auto &vec2 = v2.toBox<StdContainerBox<StdVector<Int>>>()->container;

    vec1.push_back(100);
    vec2.push_back(200);

    ASSERT_EQ(vec1.size(), 1u);
    ASSERT_EQ(vec2.size(), 1u);
    ASSERT_EQ(vec1[0], 100);
    ASSERT_EQ(vec2[0], 200);
}

TEST(std_container_box, different_container_types) {
    Var v = Var(new StdContainerBox<StdArray<Int, 3>>(10, std::initializer_list<Int>{1, 2, 3}));
    Var v2 = Var(new StdContainerBox<StdVector<Int>>(20, (std::size_t) 3));
    Var v3 = Var(new StdContainerBox<StdOrderedMap<Int, Int>>(30));

    auto &arr = v.toBox<StdContainerBox<StdArray<Int, 3>>>()->container;
    auto &vec = v2.toBox<StdContainerBox<StdVector<Int>>>()->container;
    auto &map = v3.toBox<StdContainerBox<StdOrderedMap<Int, Int>>>()->container;

    ASSERT_EQ(arr.size(), 3u);
    ASSERT_EQ(vec.size(), 3u);
    map.offsetSet(1, 42);
    ASSERT_EQ(map.size(), 1u);
}

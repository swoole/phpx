#include "phpx_test.h"
#include "phpx_func.h"
#include "phpx_big_int.h"
#include "phpx_decimal.h"

using namespace php;

static bool test_box_dtor;

class TestBox : public Box {
    ~TestBox() override {
        test_box_dtor = true;
    }

  public:
    std::vector<bool> list_;

    TestBox(size_t size) {
        list_.reserve(size);
    }
};

TEST(box, create) {
    var a(new TestBox(1024));

    auto box = a.toBox<TestBox>();
    ASSERT_EQ(box->list_.capacity(), 1024);

    test_box_dtor = false;
    a.unset();
    ASSERT_TRUE(test_box_dtor);

    TestBox *box2 = nullptr, *box3 = nullptr;
    try {
        box2 = a.toBox<TestBox>();
    } catch (zend_object *ex) {
        catchException();
    }
    ASSERT_EQ(box2, nullptr);

    try {
        auto fp = php::fopen("/tmp/test.log", "w+");
        box3 = fp.toBox<TestBox>();
    } catch (zend_object *ex) {
        catchException();
    }
    ASSERT_EQ(box3, nullptr);
}

TEST(box, rejects_wrong_concrete_box_type) {
    auto bigint = php::toBigInt((php::Int) 42);
    Decimal *decimal = nullptr;
    bool exception_caught = false;

    try {
        decimal = bigint.toBox<Decimal>();
    } catch (zend_object *ex) {
        exception_caught = true;
        auto exception = catchException();
        ASSERT_TRUE(exception.instanceOf(zend_ce_error));
    }

    ASSERT_EQ(decimal, nullptr);
    ASSERT_TRUE(exception_caught);
    ASSERT_EQ(bigint.toBox<BigInt>()->value, 42);
}

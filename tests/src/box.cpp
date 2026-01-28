#include "phpx_test.h"
#include "phpx_func.h"

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

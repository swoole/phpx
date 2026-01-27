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

    auto box2 = a.toBox<TestBox>();
    ASSERT_EQ(box2, nullptr);

    auto fp = php::fopen("/tmp/test.log", "w+");
    auto box3 = fp.toBox<TestBox>();
    ASSERT_EQ(box3, nullptr);
}

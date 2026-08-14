#include "phpx_test.h"

namespace {
struct NativeGcCounters {
    int finalized = 0;
    int destroyed = 0;
};

struct NativeGcNode {
    NativeGcNode *child = nullptr;
    NativeGcCounters *counters = nullptr;
};

void traceNativeNode(void *object, php::NativeMarker &marker)
{
    marker.mark(static_cast<NativeGcNode *>(object)->child);
}

void finalizeNativeNode(void *object)
{
    static_cast<NativeGcNode *>(object)->counters->finalized++;
}

void destroyNativeNode(void *object) noexcept
{
    auto *node = static_cast<NativeGcNode *>(object);
    node->counters->destroyed++;
    node->~NativeGcNode();
}

const php::NativeTypeDescriptor nativeNodeType = {
    "NativeGcNode",
    sizeof(NativeGcNode),
    alignof(NativeGcNode),
    traceNativeNode,
    finalizeNativeNode,
    destroyNativeNode,
};
} // namespace

TEST(native_gc, root_frame_traces_native_graph)
{
    NativeGcCounters counters;
    NativeGcNode *root = php::nativeNew<NativeGcNode>(nativeNodeType);
    root->counters = &counters;
    root->child = php::nativeNew<NativeGcNode>(nativeNodeType);
    root->child->counters = &counters;

    php::NativeRootSlot slots[] = {reinterpret_cast<void **>(&root)};
    {
        php::NativeRootFrame frame(slots, 1);
        php::nativeGcCollect();
        EXPECT_EQ(2u, php::nativeGcStats().objectCount);
        EXPECT_EQ(0, counters.finalized);
    }

    root = nullptr;
    php::nativeGcCollect();
    EXPECT_EQ(0u, php::nativeGcStats().objectCount);
    EXPECT_EQ(2, counters.finalized);
    EXPECT_EQ(2, counters.destroyed);
}

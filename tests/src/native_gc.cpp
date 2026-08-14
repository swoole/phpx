#include "phpx_test.h"

extern "C" {
#include "wren_gc.h"
}

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

TEST(wren_gc, uses_stable_native_heap_defaults)
{
    WrenGcConfig config;
    wren_gc_config_init(&config);

    EXPECT_EQ(10u * 1024u * 1024u, config.initial_heap_size);
    EXPECT_EQ(1024u * 1024u, config.minimum_heap_size);
    EXPECT_EQ(50u, config.heap_growth_percent);

    WrenGcHeap *heap = wren_gc_heap_new(&config);
    ASSERT_NE(nullptr, heap);
    EXPECT_EQ(config.initial_heap_size, wren_gc_stats(heap).next_collection);
    wren_gc_heap_free(heap);
}

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

TEST(native_gc, request_root_keeps_global_slot_alive)
{
    static NativeGcNode *requestRoot = nullptr;
    NativeGcCounters counters;
    requestRoot = php::nativeNew<NativeGcNode>(nativeNodeType);
    requestRoot->counters = &counters;
    php::nativeGcRegisterRequestRoot(reinterpret_cast<void **>(&requestRoot));

    php::nativeGcCollect();
    EXPECT_EQ(1u, php::nativeGcStats().objectCount);
    EXPECT_EQ(0, counters.finalized);

    requestRoot = nullptr;
    php::nativeGcCollect();
    EXPECT_EQ(0u, php::nativeGcStats().objectCount);
    EXPECT_EQ(1, counters.finalized);
    EXPECT_EQ(1, counters.destroyed);
}

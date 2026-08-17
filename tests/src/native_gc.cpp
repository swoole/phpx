#include "phpx_test.h"

#include <stdexcept>

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
    NativeGcNode **resurrectionRoot = nullptr;
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

NativeGcNode *shutdownResurrectionRoot = nullptr;

void finalizeAndResurrectAtShutdown(void *object)
{
    auto *node = static_cast<NativeGcNode *>(object);
    node->counters->finalized++;
    shutdownResurrectionRoot = node;
}

const php::NativeTypeDescriptor shutdownResurrectionType = {
    "ShutdownResurrectionNode",
    sizeof(NativeGcNode),
    alignof(NativeGcNode),
    traceNativeNode,
    finalizeAndResurrectAtShutdown,
    destroyNativeNode,
};

void finalizeAndResurrect(void *object)
{
    auto *node = static_cast<NativeGcNode *>(object);
    node->counters->finalized++;
    *node->resurrectionRoot = node;
}

const php::NativeTypeDescriptor resurrectionType = {
    "ResurrectionNode",
    sizeof(NativeGcNode),
    alignof(NativeGcNode),
    traceNativeNode,
    finalizeAndResurrect,
    destroyNativeNode,
};

void finalizeAndThrow(void *object)
{
    static_cast<NativeGcNode *>(object)->counters->finalized++;
    throw std::runtime_error("native finalizer failure");
}

const php::NativeTypeDescriptor throwingFinalizerType = {
    "ThrowingFinalizerNode",
    sizeof(NativeGcNode),
    alignof(NativeGcNode),
    traceNativeNode,
    finalizeAndThrow,
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

TEST(native_gc, container_root_frames_follow_sequence_and_map_elements)
{
    NativeGcCounters counters;
    php::StdVector<NativeGcNode *> sequence;
    php::StdMap<php::Int, NativeGcNode *> map;

    auto *first = php::nativeNew<NativeGcNode>(nativeNodeType);
    first->counters = &counters;
    auto *second = php::nativeNew<NativeGcNode>(nativeNodeType);
    second->counters = &counters;
    sequence.push_back(first);
    map.offsetSet(1, second);
    first = nullptr;
    second = nullptr;

    {
        php::NativeContainerRootFrame sequenceRoots(sequence);
        php::NativeContainerRootFrame mapRoots(map);
        php::nativeGcCollect();
        EXPECT_EQ(2u, php::nativeGcStats().objectCount);
        EXPECT_EQ(0, counters.finalized);

        // Root enumeration follows the container's current storage rather
        // than retaining addresses invalidated by mutation or reallocation.
        sequence.offsetUnset(0);
        map.offsetUnset(1);
        php::nativeGcCollect();
        EXPECT_EQ(0u, php::nativeGcStats().objectCount);
    }
    EXPECT_EQ(2, counters.finalized);
    EXPECT_EQ(2, counters.destroyed);
}

TEST(native_gc, shutdown_clears_roots_written_by_finalizers)
{
    NativeGcCounters counters;
    shutdownResurrectionRoot = php::nativeNew<NativeGcNode>(shutdownResurrectionType);
    shutdownResurrectionRoot->counters = &counters;
    php::nativeGcRegisterRequestRoot(reinterpret_cast<void **>(&shutdownResurrectionRoot));

    php::request_shutdown();

    EXPECT_EQ(nullptr, shutdownResurrectionRoot);
    EXPECT_EQ(1, counters.finalized);
    EXPECT_EQ(1, counters.destroyed);

    // The test runner owns the surrounding request and expects subsequent
    // tests, plus its final shutdown, to see an active PHPX request.
    php::request_init();
}

TEST(native_gc, finalizer_can_resurrect_into_request_root_once)
{
    static NativeGcNode *requestRoot = nullptr;
    NativeGcCounters counters;
    requestRoot = php::nativeNew<NativeGcNode>(resurrectionType);
    requestRoot->counters = &counters;
    requestRoot->resurrectionRoot = &requestRoot;
    php::nativeGcRegisterRequestRoot(reinterpret_cast<void **>(&requestRoot));

    requestRoot = nullptr;
    php::nativeGcCollect();
    ASSERT_NE(nullptr, requestRoot);
    EXPECT_EQ(1, counters.finalized);
    EXPECT_EQ(0, counters.destroyed);

    requestRoot = nullptr;
    php::nativeGcCollect();
    EXPECT_EQ(1, counters.finalized);
    EXPECT_EQ(1, counters.destroyed);
}

TEST(native_gc, finalizer_exception_is_rethrown_after_object_is_destroyed)
{
    NativeGcCounters counters;
    NativeGcNode *node = php::nativeNew<NativeGcNode>(throwingFinalizerType);
    node->counters = &counters;

    EXPECT_THROW(php::nativeGcCollect(), std::runtime_error);
    EXPECT_EQ(1, counters.finalized);
    EXPECT_EQ(1, counters.destroyed);
    EXPECT_EQ(0u, php::nativeGcStats().objectCount);

    // The remembered exception must be consumed exactly once.
    EXPECT_NO_THROW(php::nativeGcCollect());
}

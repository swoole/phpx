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

    EXPECT_EQ(16u * 1024u * 1024u, config.initial_heap_size);
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

TEST(native_gc, root_frames_survive_non_lifo_fiber_lifetimes)
{
    NativeGcCounters counters;
    NativeGcNode *first = php::nativeNew<NativeGcNode>(nativeNodeType);
    NativeGcNode *second = php::nativeNew<NativeGcNode>(nativeNodeType);
    first->counters = &counters;
    second->counters = &counters;
    php::NativeRootSlot firstSlots[] = {reinterpret_cast<void **>(&first)};
    php::NativeRootSlot secondSlots[] = {reinterpret_cast<void **>(&second)};

    // A Fiber can suspend the older C++ stack, create a newer root frame on
    // another stack, then resume and destroy the older frame first.
    auto *older = new php::NativeRootFrame(firstSlots, 1);
    auto *newer = new php::NativeRootFrame(secondSlots, 1);
    delete older;
    first = nullptr;

    php::nativeGcCollect();
    EXPECT_EQ(1u, php::nativeGcStats().objectCount);
    EXPECT_EQ(1, counters.finalized);

    delete newer;
    second = nullptr;
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

TEST(native_gc, container_root_frames_survive_non_lifo_fiber_lifetimes)
{
    NativeGcCounters counters;
    php::StdVector<NativeGcNode *> olderContainer;
    php::StdVector<NativeGcNode *> newerContainer;
    auto *olderValue = php::nativeNew<NativeGcNode>(nativeNodeType);
    auto *newerValue = php::nativeNew<NativeGcNode>(nativeNodeType);
    olderValue->counters = &counters;
    newerValue->counters = &counters;
    olderContainer.push_back(olderValue);
    newerContainer.push_back(newerValue);
    olderValue = nullptr;
    newerValue = nullptr;

    auto *older = new php::NativeContainerRootFrame(olderContainer);
    auto *newer = new php::NativeContainerRootFrame(newerContainer);
    delete older;
    olderContainer.offsetUnset(0);

    php::nativeGcCollect();
    EXPECT_EQ(1u, php::nativeGcStats().objectCount);
    EXPECT_EQ(1, counters.finalized);

    delete newer;
    newerContainer.offsetUnset(0);
    php::nativeGcCollect();
    EXPECT_EQ(0u, php::nativeGcStats().objectCount);
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

TEST(native_gc, shutdown_detaches_frames_owned_by_suspended_fibers)
{
    NativeGcCounters counters;
    NativeGcNode *value = php::nativeNew<NativeGcNode>(nativeNodeType);
    value->counters = &counters;
    php::NativeRootSlot slots[] = {reinterpret_cast<void **>(&value)};
    auto *suspendedFrame = new php::NativeRootFrame(slots, 1);

    php::nativeGcRequestShutdown();
    EXPECT_EQ(1, counters.finalized);
    EXPECT_EQ(1, counters.destroyed);

    // Simulate destruction of the suspended Fiber stack after RSHUTDOWN and
    // prove that the stale frame cannot reattach itself to the next request.
    php::nativeGcRequestInit();
    delete suspendedFrame;

    NativeGcNode *nextRequestValue = php::nativeNew<NativeGcNode>(nativeNodeType);
    nextRequestValue->counters = &counters;
    php::nativeGcCollect();
    EXPECT_EQ(0u, php::nativeGcStats().objectCount);
    EXPECT_EQ(2, counters.finalized);
    EXPECT_EQ(2, counters.destroyed);
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

TEST(native_gc, finalizer_chain_runs_all_callbacks_and_preserves_first_cpp_exception)
{
    php::NativeFinalizerChain chain;
    int callbacks = 0;

    chain.run([&] {
        callbacks++;
        throw std::runtime_error("first finalizer");
    });
    chain.run([&] { callbacks++; });

    EXPECT_EQ(2, callbacks);
    try {
        chain.rethrow();
        FAIL() << "Expected the first finalizer exception";
    } catch (const std::runtime_error &exception) {
        EXPECT_STREQ("first finalizer", exception.what());
    }
}

TEST(native_gc, finalizer_chain_clears_zend_state_between_callbacks)
{
    php::NativeFinalizerChain chain;
    int callbacks = 0;

    chain.run([&] {
        callbacks++;
        php::throwError("first Zend finalizer");
    });
    EXPECT_EQ(nullptr, EG(exception));
    chain.run([&] { callbacks++; });

    EXPECT_EQ(2, callbacks);
    try {
        chain.rethrow();
        FAIL() << "Expected the preserved Zend exception";
    } catch (zend_object *) {
        php::Object exception = php::catchException();
        EXPECT_EQ("first Zend finalizer", exception.call("getMessage").toStdString());
    }
    EXPECT_EQ(nullptr, EG(exception));
}

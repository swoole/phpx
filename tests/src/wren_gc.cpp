#include <gtest/gtest.h>

#include <cstddef>
#include <cstdint>
#include <limits>

extern "C" {
#include "wren_gc.h"
}

namespace {
struct Counters {
    int finalized = 0;
    int destroyed = 0;
};

struct alignas(std::max_align_t) Node {
    Node *child = nullptr;
    Node **resurrection_root = nullptr;
    Counters *counters = nullptr;
    WrenGcHeap *heap = nullptr;
    bool allocate_child_on_finalize = false;
};

struct Roots {
    Node *first = nullptr;
    Node *second = nullptr;
};

size_t objectSize(const void *) {
    return sizeof(Node);
}

size_t oversizedObjectSize(const void *) {
    return std::numeric_limits<size_t>::max();
}

bool hasFinalizer(const void *) {
    return true;
}

Node *allocateNode(WrenGcHeap *heap, Counters &counters);

void markRoots(WrenGcVisitFn visit, void *visit_context, void *roots_context) {
    auto *roots = static_cast<Roots *>(roots_context);
    visit(roots->first, visit_context);
    visit(roots->second, visit_context);
}

void traceNode(void *payload, WrenGcVisitFn visit, void *context) {
    auto *node = static_cast<Node *>(payload);
    visit(node->child, context);
}

void finalizeNode(void *payload) {
    auto *node = static_cast<Node *>(payload);
    node->counters->finalized++;
    if (node->allocate_child_on_finalize) {
        node->allocate_child_on_finalize = false;
        allocateNode(node->heap, *node->counters);
    }
    if (node->resurrection_root != nullptr) {
        *node->resurrection_root = node;
    }
}

void destroyNode(void *payload) {
    static_cast<Node *>(payload)->counters->destroyed++;
}

Node *allocateNode(WrenGcHeap *heap, Counters &counters) {
    auto *node = static_cast<Node *>(wren_gc_allocate(heap, alignof(Node), nullptr));
    EXPECT_NE(nullptr, node);
    new (node) Node{};
    node->counters = &counters;
    node->heap = heap;
    return node;
}

void configureHeap(WrenGcConfig &config, Roots &roots) {
    wren_gc_config_init(&config);
    config.mark_roots = markRoots;
    config.roots_context = &roots;
    config.object_size = objectSize;
    config.trace = traceNode;
    config.has_finalizer = hasFinalizer;
    config.finalize = finalizeNode;
    config.destroy = destroyNode;
}
}  // namespace

TEST(wren_gc, uses_compact_sixteen_byte_header) {
    if constexpr (sizeof(void *) == 8) {
        EXPECT_EQ(16u, wren_gc_header_size());
    } else {
        EXPECT_EQ(2u * sizeof(void *), wren_gc_header_size());
    }

    Roots roots;
    WrenGcConfig config;
    configureHeap(config, roots);
    auto *heap = wren_gc_heap_new(&config);
    ASSERT_NE(nullptr, heap);

    Counters counters;
    Node *node = allocateNode(heap, counters);
    EXPECT_EQ(0u, reinterpret_cast<uintptr_t>(node) % alignof(Node));
    if constexpr (sizeof(void *) == 8) {
        EXPECT_EQ(sizeof(Node) + 16u, wren_gc_stats(heap).bytes_allocated);
    }
    wren_gc_heap_free(heap);
}

TEST(wren_gc, rejects_an_allocation_size_that_cannot_include_its_header) {
    Roots roots;
    WrenGcConfig config;
    configureHeap(config, roots);
    config.object_size = oversizedObjectSize;
    auto *heap = wren_gc_heap_new(&config);
    ASSERT_NE(nullptr, heap);

    EXPECT_EQ(nullptr, wren_gc_allocate(heap, alignof(Node), nullptr));
    EXPECT_EQ(0u, wren_gc_stats(heap).object_count);
    EXPECT_EQ(0u, wren_gc_stats(heap).bytes_allocated);
    wren_gc_heap_free(heap);
}

TEST(wren_gc, collects_unreachable_cycle) {
    Roots roots;
    WrenGcConfig config;
    configureHeap(config, roots);
    auto *heap = wren_gc_heap_new(&config);
    ASSERT_NE(nullptr, heap);

    Counters counters;
    Node *first = allocateNode(heap, counters);
    Node *second = allocateNode(heap, counters);
    first->child = second;
    second->child = first;

    wren_gc_collect(heap);
    EXPECT_EQ(2, counters.finalized);
    EXPECT_EQ(2, counters.destroyed);
    EXPECT_EQ(0u, wren_gc_stats(heap).object_count);
    wren_gc_heap_free(heap);
}

TEST(wren_gc, precise_root_retains_reachable_graph) {
    Roots roots;
    WrenGcConfig config;
    configureHeap(config, roots);
    auto *heap = wren_gc_heap_new(&config);
    ASSERT_NE(nullptr, heap);

    Counters counters;
    roots.first = allocateNode(heap, counters);
    roots.first->child = allocateNode(heap, counters);
    wren_gc_collect(heap);
    EXPECT_EQ(0, counters.finalized);
    EXPECT_EQ(0, counters.destroyed);
    EXPECT_EQ(2u, wren_gc_stats(heap).object_count);

    roots.first = nullptr;
    wren_gc_collect(heap);
    EXPECT_EQ(2, counters.finalized);
    EXPECT_EQ(2, counters.destroyed);
    wren_gc_heap_free(heap);
}

TEST(wren_gc, finalizer_can_resurrect_object_only_once) {
    Roots roots;
    WrenGcConfig config;
    configureHeap(config, roots);
    auto *heap = wren_gc_heap_new(&config);
    ASSERT_NE(nullptr, heap);

    Counters counters;
    Node *node = allocateNode(heap, counters);
    node->resurrection_root = &roots.first;
    wren_gc_collect(heap);
    EXPECT_EQ(node, roots.first);
    EXPECT_EQ(1, counters.finalized);
    EXPECT_EQ(0, counters.destroyed);
    EXPECT_TRUE(wren_gc_is_finalized(node));

    roots.first = nullptr;
    wren_gc_collect(heap);
    EXPECT_EQ(1, counters.finalized);
    EXPECT_EQ(1, counters.destroyed);
    wren_gc_heap_free(heap);
}

TEST(wren_gc, allocation_from_finalizer_survives_current_sweep) {
    Roots roots;
    WrenGcConfig config;
    configureHeap(config, roots);
    auto *heap = wren_gc_heap_new(&config);
    ASSERT_NE(nullptr, heap);

    Counters counters;
    Node *node = allocateNode(heap, counters);
    node->allocate_child_on_finalize = true;

    wren_gc_collect(heap);
    EXPECT_EQ(1, counters.finalized);
    EXPECT_EQ(1, counters.destroyed);
    EXPECT_EQ(1u, wren_gc_stats(heap).object_count);

    wren_gc_collect(heap);
    EXPECT_EQ(2, counters.finalized);
    EXPECT_EQ(2, counters.destroyed);
    EXPECT_EQ(0u, wren_gc_stats(heap).object_count);
    wren_gc_heap_free(heap);
}

TEST(wren_gc, reachability_probe_and_finalizer_suppression_preserve_published_failures) {
    Roots roots;
    WrenGcConfig config;
    configureHeap(config, roots);
    auto *heap = wren_gc_heap_new(&config);
    ASSERT_NE(nullptr, heap);

    Counters counters;
    Node *node = allocateNode(heap, counters);
    EXPECT_FALSE(wren_gc_is_reachable(heap, node));

    roots.first = node;
    EXPECT_TRUE(wren_gc_is_reachable(heap, node));
    wren_gc_suppress_finalizer(node);

    roots.first = nullptr;
    wren_gc_collect(heap);
    EXPECT_EQ(0, counters.finalized);
    EXPECT_EQ(1, counters.destroyed);
    EXPECT_EQ(0u, wren_gc_stats(heap).object_count);
    wren_gc_heap_free(heap);
}

#include <gtest/gtest.h>

extern "C" {
#include "wren_gc.h"
}

namespace {
struct Counters {
    int finalized = 0;
    int destroyed = 0;
};

struct Node {
    Node *child = nullptr;
    Node **resurrection_root = nullptr;
    Counters *counters = nullptr;
};

struct Roots {
    Node *first = nullptr;
    Node *second = nullptr;
};

void markRoots(WrenGcVisitFn visit, void *visit_context, void *roots_context)
{
    auto *roots = static_cast<Roots *>(roots_context);
    visit(roots->first, visit_context);
    visit(roots->second, visit_context);
}

void traceNode(void *payload, WrenGcVisitFn visit, void *context)
{
    auto *node = static_cast<Node *>(payload);
    visit(node->child, context);
}

void finalizeNode(void *payload)
{
    auto *node = static_cast<Node *>(payload);
    node->counters->finalized++;
    if (node->resurrection_root != nullptr) {
        *node->resurrection_root = node;
    }
}

void destroyNode(void *payload)
{
    static_cast<Node *>(payload)->counters->destroyed++;
}

Node *allocateNode(WrenGcHeap *heap, Counters &counters)
{
    auto *node = static_cast<Node *>(wren_gc_allocate(
        heap,
        sizeof(Node),
        alignof(Node),
        nullptr,
        traceNode,
        finalizeNode,
        destroyNode
    ));
    EXPECT_NE(nullptr, node);
    new (node) Node{};
    node->counters = &counters;
    return node;
}
} // namespace

TEST(wren_gc, collects_unreachable_cycle)
{
    Roots roots;
    WrenGcConfig config;
    wren_gc_config_init(&config);
    config.mark_roots = markRoots;
    config.roots_context = &roots;
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

TEST(wren_gc, precise_root_retains_reachable_graph)
{
    Roots roots;
    WrenGcConfig config;
    wren_gc_config_init(&config);
    config.mark_roots = markRoots;
    config.roots_context = &roots;
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

TEST(wren_gc, finalizer_can_resurrect_object_only_once)
{
    Roots roots;
    WrenGcConfig config;
    wren_gc_config_init(&config);
    config.mark_roots = markRoots;
    config.roots_context = &roots;
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

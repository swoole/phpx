#ifndef TYPEPHP_WREN_GC_H
#define TYPEPHP_WREN_GC_H

#include <stdbool.h>
#include <stddef.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct WrenGcHeap WrenGcHeap;
typedef void (*WrenGcVisitFn)(void *object, void *context);
typedef void (*WrenGcTraceFn)(void *object, WrenGcVisitFn visit, void *context);
typedef void (*WrenGcFinalizeFn)(void *object);
typedef void (*WrenGcDestroyFn)(void *object);
typedef void (*WrenGcRootsFn)(WrenGcVisitFn visit, void *visit_context, void *roots_context);

typedef struct WrenGcConfig {
    size_t initial_heap_size;
    size_t minimum_heap_size;
    unsigned heap_growth_percent;
    WrenGcRootsFn mark_roots;
    void *roots_context;
} WrenGcConfig;

typedef struct WrenGcStats {
    size_t bytes_allocated;
    size_t next_collection;
    size_t object_count;
    size_t collection_count;
} WrenGcStats;

void wren_gc_config_init(WrenGcConfig *config);
WrenGcHeap *wren_gc_heap_new(const WrenGcConfig *config);
void wren_gc_heap_free(WrenGcHeap *heap);

void *wren_gc_allocate(
    WrenGcHeap *heap,
    size_t size,
    size_t alignment,
    const void *type_data,
    WrenGcTraceFn trace,
    WrenGcFinalizeFn finalize,
    WrenGcDestroyFn destroy
);

void wren_gc_mark(WrenGcHeap *heap, void *object);
void wren_gc_collect(WrenGcHeap *heap);
void wren_gc_abandon(WrenGcHeap *heap, void *object);
bool wren_gc_is_reachable(WrenGcHeap *heap, const void *object);
void wren_gc_suppress_finalizer(void *object);
const void *wren_gc_type_data(const void *object);
bool wren_gc_is_finalized(const void *object);
WrenGcStats wren_gc_stats(const WrenGcHeap *heap);

#ifdef __cplusplus
}
#endif

#endif

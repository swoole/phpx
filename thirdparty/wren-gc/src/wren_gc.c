#include "wren_gc.h"

#include <stddef.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

typedef struct WrenGcObject {
    uintptr_t next_and_flags;
    const void *type_data;
} WrenGcObject;

enum {
    WREN_GC_MARKED = 1u,
    WREN_GC_FINALIZED = 2u,
    WREN_GC_ALLOCATED_DURING_COLLECTION = 4u,
    WREN_GC_FLAGS = 7u,
};

_Static_assert(sizeof(WrenGcObject) == 2u * sizeof(void *), "Wren GC header must contain exactly two words");
_Static_assert(_Alignof(max_align_t) >= 8u, "Wren GC requires three free pointer tag bits");

struct WrenGcHeap {
    WrenGcConfig config;
    WrenGcObject *objects;
    WrenGcObject **gray;
    size_t gray_count;
    size_t gray_capacity;
    size_t bytes_allocated;
    size_t next_collection;
    size_t object_count;
    size_t collection_count;
    bool collecting;
};

static size_t payload_offset(void)
{
    const size_t alignment = _Alignof(max_align_t);
    return (sizeof(WrenGcObject) + alignment - 1u) & ~(alignment - 1u);
}

static WrenGcObject *object_next(const WrenGcObject *object)
{
    return (WrenGcObject *) (object->next_and_flags & ~(uintptr_t) WREN_GC_FLAGS);
}

static void object_set_next(WrenGcObject *object, WrenGcObject *next)
{
    object->next_and_flags = (object->next_and_flags & WREN_GC_FLAGS) | (uintptr_t) next;
}

static bool object_has_flag(const WrenGcObject *object, uintptr_t flag)
{
    return (object->next_and_flags & flag) != 0;
}

static void object_set_flag(WrenGcObject *object, uintptr_t flag, bool enabled)
{
    if (enabled) {
        object->next_and_flags |= flag;
    } else {
        object->next_and_flags &= ~flag;
    }
}

static void *object_payload(WrenGcObject *object)
{
    return (void *) ((unsigned char *) object + payload_offset());
}

static WrenGcObject *object_header(const void *payload)
{
    if (payload == NULL) {
        return NULL;
    }
    return (WrenGcObject *) ((unsigned char *) payload - payload_offset());
}

static size_t object_allocation_size(const WrenGcHeap *heap, const WrenGcObject *object)
{
    return payload_offset() + heap->config.object_size(object->type_data);
}

static void gray_push(WrenGcHeap *heap, WrenGcObject *object)
{
    if (heap->gray_count == heap->gray_capacity) {
        size_t capacity = heap->gray_capacity < 8 ? 8 : heap->gray_capacity * 2;
        WrenGcObject **gray = (WrenGcObject **) realloc(heap->gray, capacity * sizeof(*gray));
        if (gray == NULL) {
            abort();
        }
        heap->gray = gray;
        heap->gray_capacity = capacity;
    }
    heap->gray[heap->gray_count++] = object;
}

void wren_gc_mark(WrenGcHeap *heap, void *payload)
{
    if (heap == NULL || payload == NULL) {
        return;
    }
    WrenGcObject *object = object_header(payload);
    if (object == NULL || object_has_flag(object, WREN_GC_MARKED)) {
        return;
    }
    object_set_flag(object, WREN_GC_MARKED, true);
    gray_push(heap, object);
}

static void visit_object(void *payload, void *context)
{
    wren_gc_mark((WrenGcHeap *) context, payload);
}

static void mark_roots(WrenGcHeap *heap)
{
    if (heap->config.mark_roots != NULL) {
        heap->config.mark_roots(visit_object, heap, heap->config.roots_context);
    }
}

static void trace_gray(WrenGcHeap *heap)
{
    while (heap->gray_count > 0) {
        WrenGcObject *object = heap->gray[--heap->gray_count];
        if (heap->config.trace != NULL) {
            heap->config.trace(object_payload(object), visit_object, heap);
        }
    }
}

static void clear_marks(WrenGcHeap *heap)
{
    for (WrenGcObject *object = heap->objects; object != NULL; object = object_next(object)) {
        object_set_flag(object, WREN_GC_MARKED, false);
    }
    heap->gray_count = 0;
}

static void prepare_post_finalizer_mark(WrenGcHeap *heap)
{
    heap->gray_count = 0;
    for (WrenGcObject *object = heap->objects; object != NULL; object = object_next(object)) {
        const bool allocated = object_has_flag(object, WREN_GC_ALLOCATED_DURING_COLLECTION);
        object_set_flag(object, WREN_GC_MARKED, allocated);
        if (allocated) {
            /* Construction has completed by the time the finalizer returns. */
            gray_push(heap, object);
        }
    }
}

static void mark_reachable(WrenGcHeap *heap)
{
    mark_roots(heap);
    trace_gray(heap);
}

static bool run_finalizers(WrenGcHeap *heap)
{
    if (heap->config.has_finalizer == NULL || heap->config.finalize == NULL) {
        return false;
    }
    bool ran = false;
    for (WrenGcObject *object = heap->objects; object != NULL; object = object_next(object)) {
        if (!object_has_flag(object, WREN_GC_MARKED)
            && !object_has_flag(object, WREN_GC_FINALIZED)
            && heap->config.has_finalizer(object->type_data)) {
            object_set_flag(object, WREN_GC_FINALIZED, true);
            ran = true;
            heap->config.finalize(object_payload(object));
        }
    }
    return ran;
}

void wren_gc_config_init(WrenGcConfig *config)
{
    memset(config, 0, sizeof(*config));
    config->initial_heap_size = 10u * 1024u * 1024u;
    config->minimum_heap_size = 1024u * 1024u;
    config->heap_growth_percent = 50;
}

WrenGcHeap *wren_gc_heap_new(const WrenGcConfig *config)
{
    WrenGcConfig defaults;
    if (config == NULL) {
        wren_gc_config_init(&defaults);
        config = &defaults;
    }
    WrenGcHeap *heap = (WrenGcHeap *) calloc(1, sizeof(*heap));
    if (heap == NULL) {
        return NULL;
    }
    heap->config = *config;
    heap->next_collection = config->initial_heap_size;
    if (heap->next_collection < config->minimum_heap_size) {
        heap->next_collection = config->minimum_heap_size;
    }
    return heap;
}

void *wren_gc_allocate(
    WrenGcHeap *heap,
    size_t alignment,
    const void *type_data
) {
    const size_t size = heap != NULL && heap->config.object_size != NULL
        ? heap->config.object_size(type_data)
        : 0;
    if (heap == NULL
        || size == 0
        || heap->config.object_size == NULL
        || heap->config.destroy == NULL) {
        return NULL;
    }
    if (alignment == 0
        || (alignment & (alignment - 1u)) != 0
        || alignment > _Alignof(max_align_t)
        || size > SIZE_MAX - payload_offset()) {
        return NULL;
    }
    const size_t allocation_size = payload_offset() + size;
    if (!heap->collecting && heap->bytes_allocated + allocation_size > heap->next_collection) {
        wren_gc_collect(heap);
    }

    WrenGcObject *object = (WrenGcObject *) malloc(allocation_size);
    if (object == NULL) {
        return NULL;
    }
    object->next_and_flags = (uintptr_t) heap->objects;
    object->type_data = type_data;
    /*
     * A finalizer may allocate another Native object. The current mark phase
     * has already passed, so a new white object would be swept immediately
     * without ever running its own finalizer. Treat allocations made during a
     * collection as live for this cycle; normal root tracing decides their
     * reachability on the next collection.
     */
    object_set_flag(object, WREN_GC_MARKED, heap->collecting);
    object_set_flag(object, WREN_GC_ALLOCATED_DURING_COLLECTION, heap->collecting);

    heap->objects = object;
    heap->bytes_allocated += allocation_size;
    heap->object_count++;
    return object_payload(object);
}

void wren_gc_collect(WrenGcHeap *heap)
{
    if (heap == NULL || heap->collecting) {
        return;
    }
    heap->collecting = true;
    clear_marks(heap);
    mark_reachable(heap);

    if (run_finalizers(heap)) {
        prepare_post_finalizer_mark(heap);
        mark_reachable(heap);
    }

    WrenGcObject *previous = NULL;
    WrenGcObject *object = heap->objects;
    while (object != NULL) {
        WrenGcObject *next = object_next(object);
        if (!object_has_flag(object, WREN_GC_MARKED)) {
            const size_t allocation_size = object_allocation_size(heap, object);
            if (previous == NULL) {
                heap->objects = next;
            } else {
                object_set_next(previous, next);
            }
            heap->config.destroy(object_payload(object));
            heap->bytes_allocated -= allocation_size;
            heap->object_count--;
            free(object);
        } else {
            object_set_flag(object, WREN_GC_MARKED, false);
            object_set_flag(object, WREN_GC_ALLOCATED_DURING_COLLECTION, false);
            previous = object;
        }
        object = next;
    }

    size_t growth = (heap->bytes_allocated * heap->config.heap_growth_percent) / 100u;
    heap->next_collection = heap->bytes_allocated + growth;
    if (heap->next_collection < heap->config.minimum_heap_size) {
        heap->next_collection = heap->config.minimum_heap_size;
    }
    heap->collection_count++;
    heap->collecting = false;
}

void wren_gc_abandon(WrenGcHeap *heap, void *payload)
{
    if (heap == NULL || payload == NULL) {
        return;
    }
    WrenGcObject *target = object_header(payload);
    WrenGcObject *previous = NULL;
    for (WrenGcObject *object = heap->objects; object != NULL; object = object_next(object)) {
        if (object == target) {
            if (previous == NULL) {
                heap->objects = object_next(target);
            } else {
                object_set_next(previous, object_next(target));
            }
            heap->bytes_allocated -= object_allocation_size(heap, target);
            heap->object_count--;
            free(target);
            return;
        }
        previous = object;
    }
}

bool wren_gc_is_reachable(WrenGcHeap *heap, const void *payload)
{
    if (heap == NULL || payload == NULL) {
        return false;
    }
    WrenGcObject *target = object_header(payload);
    if (heap->collecting) {
        /*
         * Allocations made by a finalizer are protected for the current
         * collection. Conservatively retain a failed construction here and
         * let the next complete root scan decide its reachability.
         */
        return true;
    }
    clear_marks(heap);
    mark_reachable(heap);
    const bool reachable = object_has_flag(target, WREN_GC_MARKED);
    clear_marks(heap);
    return reachable;
}

void wren_gc_suppress_finalizer(void *payload)
{
    WrenGcObject *object = object_header(payload);
    if (object != NULL) {
        object_set_flag(object, WREN_GC_FINALIZED, true);
    }
}

void wren_gc_heap_free(WrenGcHeap *heap)
{
    if (heap == NULL) {
        return;
    }
    while (heap->objects != NULL) {
        WrenGcObject *object = heap->objects;
        heap->objects = object_next(object);
        if (!object_has_flag(object, WREN_GC_FINALIZED)
            && heap->config.has_finalizer != NULL
            && heap->config.finalize != NULL
            && heap->config.has_finalizer(object->type_data)) {
            object_set_flag(object, WREN_GC_FINALIZED, true);
            heap->config.finalize(object_payload(object));
        }
        heap->config.destroy(object_payload(object));
        free(object);
    }
    free(heap->gray);
    free(heap);
}

const void *wren_gc_type_data(const void *payload)
{
    WrenGcObject *object = object_header(payload);
    return object == NULL ? NULL : object->type_data;
}

bool wren_gc_is_finalized(const void *payload)
{
    WrenGcObject *object = object_header(payload);
    return object != NULL && object_has_flag(object, WREN_GC_FINALIZED);
}

WrenGcStats wren_gc_stats(const WrenGcHeap *heap)
{
    WrenGcStats stats = {0, 0, 0, 0};
    if (heap != NULL) {
        stats.bytes_allocated = heap->bytes_allocated;
        stats.next_collection = heap->next_collection;
        stats.object_count = heap->object_count;
        stats.collection_count = heap->collection_count;
    }
    return stats;
}

size_t wren_gc_header_size(void)
{
    return sizeof(WrenGcObject);
}

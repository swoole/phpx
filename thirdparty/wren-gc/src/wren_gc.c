#include "wren_gc.h"

#include <stdint.h>
#include <stdlib.h>
#include <string.h>

typedef struct WrenGcObject {
    struct WrenGcObject *next;
    void *payload;
    size_t allocation_size;
    const void *type_data;
    WrenGcTraceFn trace;
    WrenGcFinalizeFn finalize;
    WrenGcDestroyFn destroy;
    bool marked;
    bool finalized;
    bool allocated_during_collection;
} WrenGcObject;

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

static size_t normalize_alignment(size_t alignment)
{
    const size_t minimum = sizeof(void *);
    if (alignment < minimum) {
        alignment = minimum;
    }
    if ((alignment & (alignment - 1)) != 0) {
        return 0;
    }
    return alignment;
}

static WrenGcObject *object_header(const void *payload)
{
    if (payload == NULL) {
        return NULL;
    }
    return ((WrenGcObject *const *) payload)[-1];
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
    if (object == NULL || object->marked) {
        return;
    }
    object->marked = true;
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
        if (object->trace != NULL) {
            object->trace(object->payload, visit_object, heap);
        }
    }
}

static void clear_marks(WrenGcHeap *heap)
{
    for (WrenGcObject *object = heap->objects; object != NULL; object = object->next) {
        object->marked = false;
    }
    heap->gray_count = 0;
}

static void prepare_post_finalizer_mark(WrenGcHeap *heap)
{
    heap->gray_count = 0;
    for (WrenGcObject *object = heap->objects; object != NULL; object = object->next) {
        object->marked = object->allocated_during_collection;
        if (object->marked) {
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
    bool ran = false;
    for (WrenGcObject *object = heap->objects; object != NULL; object = object->next) {
        if (!object->marked && !object->finalized && object->finalize != NULL) {
            object->finalized = true;
            ran = true;
            object->finalize(object->payload);
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
    size_t size,
    size_t alignment,
    const void *type_data,
    WrenGcTraceFn trace,
    WrenGcFinalizeFn finalize,
    WrenGcDestroyFn destroy
) {
    if (heap == NULL || size == 0) {
        return NULL;
    }
    alignment = normalize_alignment(alignment);
    if (alignment == 0 || size > SIZE_MAX - sizeof(WrenGcObject) - sizeof(void *) - alignment) {
        return NULL;
    }
    const size_t allocation_size = sizeof(WrenGcObject) + sizeof(void *) + alignment - 1 + size;
    if (!heap->collecting && heap->bytes_allocated + allocation_size > heap->next_collection) {
        wren_gc_collect(heap);
    }

    WrenGcObject *object = (WrenGcObject *) malloc(allocation_size);
    if (object == NULL) {
        return NULL;
    }
    uintptr_t start = (uintptr_t) object + sizeof(*object) + sizeof(void *);
    uintptr_t aligned = (start + alignment - 1) & ~(uintptr_t) (alignment - 1);
    object->next = heap->objects;
    object->payload = (void *) aligned;
    object->allocation_size = allocation_size;
    object->type_data = type_data;
    object->trace = trace;
    object->finalize = finalize;
    object->destroy = destroy;
    /*
     * A finalizer may allocate another Native object. The current mark phase
     * has already passed, so a new white object would be swept immediately
     * without ever running its own finalizer. Treat allocations made during a
     * collection as live for this cycle; normal root tracing decides their
     * reachability on the next collection.
     */
    object->marked = heap->collecting;
    object->finalized = false;
    object->allocated_during_collection = heap->collecting;
    ((WrenGcObject **) object->payload)[-1] = object;

    heap->objects = object;
    heap->bytes_allocated += allocation_size;
    heap->object_count++;
    return object->payload;
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

    WrenGcObject **link = &heap->objects;
    while (*link != NULL) {
        WrenGcObject *object = *link;
        if (!object->marked) {
            *link = object->next;
            if (object->destroy != NULL) {
                object->destroy(object->payload);
            }
            heap->bytes_allocated -= object->allocation_size;
            heap->object_count--;
            free(object);
        } else {
            object->marked = false;
            object->allocated_during_collection = false;
            link = &object->next;
        }
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
    WrenGcObject **link = &heap->objects;
    while (*link != NULL) {
        if (*link == target) {
            *link = target->next;
            heap->bytes_allocated -= target->allocation_size;
            heap->object_count--;
            free(target);
            return;
        }
        link = &(*link)->next;
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
    const bool reachable = target->marked;
    clear_marks(heap);
    return reachable;
}

void wren_gc_suppress_finalizer(void *payload)
{
    WrenGcObject *object = object_header(payload);
    if (object != NULL) {
        object->finalized = true;
    }
}

void wren_gc_heap_free(WrenGcHeap *heap)
{
    if (heap == NULL) {
        return;
    }
    while (heap->objects != NULL) {
        WrenGcObject *object = heap->objects;
        heap->objects = object->next;
        if (!object->finalized && object->finalize != NULL) {
            object->finalized = true;
            object->finalize(object->payload);
        }
        if (object->destroy != NULL) {
            object->destroy(object->payload);
        }
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
    return object != NULL && object->finalized;
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

#include "phpx.h"

extern "C" {
#include "wren_gc.h"
}

#include <exception>

namespace php {
namespace {
THREAD_LOCAL WrenGcHeap *native_heap = nullptr;
THREAD_LOCAL NativeRootFrame *native_root_top = nullptr;
THREAD_LOCAL zend_object *pending_zend_exception = nullptr;
THREAD_LOCAL std::exception_ptr pending_cpp_exception;

void markRoots(WrenGcVisitFn visit, void *visit_context, void *)
{
    for (NativeRootFrame *frame = native_root_top; frame != nullptr; frame = frame->previous()) {
        NativeRootSlot *slots = frame->slots();
        for (size_t i = 0; i < frame->count(); ++i) {
            if (slots[i] != nullptr) {
                visit(*slots[i], visit_context);
            }
        }
    }
}

WrenGcHeap *heap()
{
    if (native_heap == nullptr) {
        WrenGcConfig config;
        wren_gc_config_init(&config);
        config.mark_roots = markRoots;
        native_heap = wren_gc_heap_new(&config);
        if (UNEXPECTED(native_heap == nullptr)) {
            throw std::bad_alloc();
        }
    }
    return native_heap;
}

const NativeTypeDescriptor *descriptor(void *object) noexcept
{
    return static_cast<const NativeTypeDescriptor *>(wren_gc_type_data(object));
}

void traceObject(void *object, WrenGcVisitFn visit, void *context)
{
    const NativeTypeDescriptor *type = descriptor(object);
    if (type != nullptr && type->trace != nullptr) {
        NativeMarker marker(visit, context);
        type->trace(object, marker);
    }
}

void rememberZendException(zend_object *exception) noexcept
{
    if (pending_zend_exception == nullptr) {
        GC_ADDREF(exception);
        pending_zend_exception = exception;
    }
    if (EG(exception) != nullptr) {
        zend_clear_exception();
    }
}

void finalizeObject(void *object) noexcept
{
    const NativeTypeDescriptor *type = descriptor(object);
    if (type == nullptr || type->finalize == nullptr) {
        return;
    }
    try {
        type->finalize(object);
    } catch (zend_object *exception) {
        rememberZendException(exception);
    } catch (...) {
        if (!pending_cpp_exception) {
            pending_cpp_exception = std::current_exception();
        }
    }
}

void destroyObject(void *object) noexcept
{
    const NativeTypeDescriptor *type = descriptor(object);
    if (type != nullptr && type->destroy != nullptr) {
        type->destroy(object);
    }
}

void rethrowFinalizerException()
{
    if (pending_zend_exception != nullptr) {
        zend_object *exception = pending_zend_exception;
        pending_zend_exception = nullptr;
        EG(exception) = exception;
        throw exception;
    }
    if (pending_cpp_exception) {
        std::exception_ptr exception = pending_cpp_exception;
        pending_cpp_exception = nullptr;
        std::rethrow_exception(exception);
    }
}

void discardPendingFinalizerException() noexcept
{
    if (pending_zend_exception != nullptr) {
        OBJ_RELEASE(pending_zend_exception);
        pending_zend_exception = nullptr;
    }
    pending_cpp_exception = nullptr;
    if (EG(exception) != nullptr) {
        zend_clear_exception();
    }
}
} // namespace

NativeRootFrame::NativeRootFrame(NativeRootSlot *slots, size_t count) noexcept
    : previous_(native_root_top), slots_(slots), count_(count)
{
    native_root_top = this;
}

NativeRootFrame::~NativeRootFrame() noexcept
{
    ZEND_ASSERT(native_root_top == this);
    native_root_top = previous_;
}

void *nativeGcAllocate(const NativeTypeDescriptor &type)
{
    void *object = wren_gc_allocate(
        heap(),
        type.size,
        type.alignment,
        &type,
        traceObject,
        finalizeObject,
        destroyObject
    );
    if (UNEXPECTED(object == nullptr)) {
        throw std::bad_alloc();
    }
    try {
        rethrowFinalizerException();
    } catch (...) {
        // The allocation is linked into the heap, but its C++ object has not
        // been placement-constructed yet. Remove raw storage without invoking
        // the descriptor destroy callback before propagating the finalizer.
        wren_gc_abandon(native_heap, object);
        throw;
    }
    return object;
}

void *nativeGcRequireObject(void *object, const char *typeName)
{
    if (UNEXPECTED(object == nullptr)) {
        throwError("Call on null native object of type %s", typeName);
    }
    return object;
}

void nativeGcAbandon(void *object) noexcept
{
    if (native_heap != nullptr) {
        wren_gc_abandon(native_heap, object);
    }
}

void nativeGcCollect()
{
    if (native_heap == nullptr) {
        return;
    }
    wren_gc_collect(native_heap);
    rethrowFinalizerException();
}

NativeGcStats nativeGcStats() noexcept
{
    if (native_heap == nullptr) {
        return {};
    }
    WrenGcStats stats = wren_gc_stats(native_heap);
    return {stats.bytes_allocated, stats.next_collection, stats.object_count, stats.collection_count};
}

void nativeGcRequestInit() noexcept
{
    ZEND_ASSERT(native_heap == nullptr);
    ZEND_ASSERT(native_root_top == nullptr);
    discardPendingFinalizerException();
}

void nativeGcRequestShutdown() noexcept
{
    ZEND_ASSERT(native_root_top == nullptr);
    if (native_heap != nullptr) {
        wren_gc_heap_free(native_heap);
        native_heap = nullptr;
    }
    discardPendingFinalizerException();
}

} // namespace php

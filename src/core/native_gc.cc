#include "phpx.h"

extern "C" {
#include "wren_gc.h"
}

#include <exception>
#include <vector>

namespace php {
namespace {
THREAD_LOCAL WrenGcHeap *native_heap = nullptr;
THREAD_LOCAL NativeRootFrame *native_root_top = nullptr;
THREAD_LOCAL NativeContainerRootFrameBase *native_container_root_top = nullptr;
THREAD_LOCAL size_t native_root_request_epoch = 0;
THREAD_LOCAL std::vector<NativeRootSlot> native_request_roots;
THREAD_LOCAL zend_object *pending_zend_exception = nullptr;
THREAD_LOCAL std::exception_ptr pending_cpp_exception;

void markRoots(WrenGcVisitFn visit, void *visit_context, void *)
{
    for (NativeRootSlot slot : native_request_roots) {
        if (slot != nullptr) {
            visit(*slot, visit_context);
        }
    }
    for (NativeRootFrame *frame = native_root_top; frame != nullptr; frame = frame->previous()) {
        NativeRootSlot *slots = frame->slots();
        for (size_t i = 0; i < frame->count(); ++i) {
            if (slots[i] != nullptr) {
                visit(*slots[i], visit_context);
            }
        }
    }
    NativeMarker marker(visit, visit_context);
    for (NativeContainerRootFrameBase *frame = native_container_root_top;
         frame != nullptr;
         frame = frame->previous()) {
        frame->trace(marker);
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
    : previous_(native_root_top), newer_(nullptr), slots_(slots), count_(count),
      requestEpoch_(native_root_request_epoch)
{
    if (previous_ != nullptr) {
        previous_->newer_ = this;
    }
    native_root_top = this;
}

NativeRootFrame::~NativeRootFrame() noexcept
{
    if (requestEpoch_ != native_root_request_epoch) {
        return;
    }
    if (newer_ != nullptr) {
        newer_->previous_ = previous_;
    } else {
        native_root_top = previous_;
    }
    if (previous_ != nullptr) {
        previous_->newer_ = newer_;
    }
}

NativeContainerRootFrameBase::NativeContainerRootFrameBase(const void *container, TraceFn trace) noexcept
    : previous_(native_container_root_top), newer_(nullptr), container_(container), trace_(trace),
      requestEpoch_(native_root_request_epoch)
{
    if (previous_ != nullptr) {
        previous_->newer_ = this;
    }
    native_container_root_top = this;
}

NativeContainerRootFrameBase::~NativeContainerRootFrameBase() noexcept
{
    if (requestEpoch_ != native_root_request_epoch) {
        return;
    }
    if (newer_ != nullptr) {
        newer_->previous_ = previous_;
    } else {
        native_container_root_top = previous_;
    }
    if (previous_ != nullptr) {
        previous_->newer_ = newer_;
    }
}

NativeFinalizerChain::~NativeFinalizerChain() noexcept
{
    if (zendException_ != nullptr) {
        OBJ_RELEASE(zendException_);
    }
}

void NativeFinalizerChain::remember(zend_object *exception) noexcept
{
    if (!failed_) {
        failed_ = true;
        GC_ADDREF(exception);
        zendException_ = exception;
    }
    if (EG(exception) != nullptr) {
        zend_clear_exception();
    }
}

void NativeFinalizerChain::remember(std::exception_ptr exception) noexcept
{
    if (!failed_) {
        failed_ = true;
        cppException_ = std::move(exception);
    }
}

void NativeFinalizerChain::rethrow()
{
    if (zendException_ != nullptr) {
        zend_object *exception = zendException_;
        zendException_ = nullptr;
        EG(exception) = exception;
        throw exception;
    }
    if (cppException_) {
        std::exception_ptr exception = std::move(cppException_);
        cppException_ = nullptr;
        std::rethrow_exception(exception);
    }
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

bool nativeGcIsReachable(const void *object) noexcept
{
    return native_heap != nullptr && wren_gc_is_reachable(native_heap, object);
}

void nativeGcSuppressFinalizer(void *object) noexcept
{
    wren_gc_suppress_finalizer(object);
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

void nativeGcRegisterRequestRoot(NativeRootSlot slot)
{
    ZEND_ASSERT(slot != nullptr);
    native_request_roots.push_back(slot);
}

void nativeGcRequestInit() noexcept
{
    ZEND_ASSERT(native_heap == nullptr);
    ZEND_ASSERT(native_root_top == nullptr);
    ZEND_ASSERT(native_container_root_top == nullptr);
    ZEND_ASSERT(native_request_roots.empty());
    discardPendingFinalizerException();
}

void nativeGcRequestShutdown() noexcept
{
    // Suspended Fibers may still own C++ root frames when PHP reaches module
    // RSHUTDOWN. Detach the complete registry in O(1); their later stack
    // unwinding observes the old epoch and safely skips unlinking.
    native_root_top = nullptr;
    native_container_root_top = nullptr;
    native_root_request_epoch++;
    const auto clear_request_roots = []() noexcept {
        for (NativeRootSlot slot : native_request_roots) {
            if (slot != nullptr) {
                *slot = nullptr;
            }
        }
    };
    clear_request_roots();
    if (native_heap != nullptr) {
        wren_gc_heap_free(native_heap);
        native_heap = nullptr;
    }
    // A shutdown finalizer may publish its object back into a registered
    // global/static slot. The heap is nevertheless being destroyed, so clear
    // those slots again to prevent a dangling pointer from crossing requests.
    clear_request_roots();
    native_request_roots.clear();
    // A finalizer is allowed to call back into TypePHP and may therefore have
    // created another frame. No such frame may survive into the next request.
    native_root_top = nullptr;
    native_container_root_top = nullptr;
    native_root_request_epoch++;
    discardPendingFinalizerException();
}

} // namespace php

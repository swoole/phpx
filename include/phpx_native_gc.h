/*
  +----------------------------------------------------------------------+
  | PHP-X Native Object GC                                                |
  +----------------------------------------------------------------------+
*/

#pragma once

#include <cstddef>
#include <exception>
#include <new>
#include <utility>

namespace php {

class NativeMarker final {
  public:
    using VisitFn = void (*)(void *object, void *context);

    NativeMarker(VisitFn visit, void *context) noexcept : visit_(visit), context_(context) {}

    void mark(void *object) const noexcept {
        if (object != nullptr) {
            visit_(object, context_);
        }
    }

    template <typename T>
    void mark(T *object) const noexcept {
        mark(static_cast<void *>(object));
    }

  private:
    VisitFn visit_;
    void *context_;
};

using NativeTraceFn = void (*)(void *object, NativeMarker &marker);
using NativeFinalizeFn = void (*)(void *object);
using NativeDestroyFn = void (*)(void *object) noexcept;

struct NativeTypeDescriptor {
    const char *name;
    size_t size;
    size_t alignment;
    NativeTraceFn trace;
    NativeFinalizeFn finalize;
    NativeDestroyFn destroy;
};

/**
 * Run an inheritance finalizer chain without allowing an exception from a
 * derived PHP-level destructor to skip base destructors.
 *
 * The first exception is preserved and rethrown after every callback has run.
 * Zend's pending exception is cleared between callbacks so the remaining
 * destructors can safely call PHP APIs. This helper is used only by generated
 * Native Class finalizers; ordinary classes pay no cost for it.
 */
class PHPX_API NativeFinalizerChain final {
  public:
    NativeFinalizerChain() noexcept = default;
    ~NativeFinalizerChain() noexcept;

    NativeFinalizerChain(const NativeFinalizerChain &) = delete;
    NativeFinalizerChain &operator=(const NativeFinalizerChain &) = delete;

    template <typename Callback>
    void run(Callback &&callback) noexcept {
        try {
            std::forward<Callback>(callback)();
        } catch (zend_object *exception) {
            remember(exception);
        } catch (...) {
            remember(std::current_exception());
        }
    }

    void rethrow();

  private:
    void remember(zend_object *exception) noexcept;
    void remember(std::exception_ptr exception) noexcept;

    bool failed_ = false;
    zend_object *zendException_ = nullptr;
    std::exception_ptr cppException_;
};

using NativeRootSlot = void **;

class PHPX_API NativeRootFrame final {
  public:
    NativeRootFrame(NativeRootSlot *slots, size_t count) noexcept;
    ~NativeRootFrame() noexcept;

    NativeRootFrame(const NativeRootFrame &) = delete;
    NativeRootFrame &operator=(const NativeRootFrame &) = delete;

    NativeRootFrame *previous() const noexcept {
        return previous_;
    }

    NativeRootSlot *slots() const noexcept {
        return slots_;
    }

    size_t count() const noexcept {
        return count_;
    }

  private:
    // Intrusive bidirectional links allow a suspended Fiber's older frame to
    // disappear while a newer frame on another Fiber is still alive.
    NativeRootFrame *previous_;
    NativeRootFrame *newer_;
    NativeRootSlot *slots_;
    size_t count_;
    size_t requestEpoch_;
};

/**
 * Roots Native Object pointers held by a compile-time std container.
 *
 * Container storage may move while a vector/map grows, so registering the
 * address of each element as a NativeRootSlot would leave dangling root
 * addresses. This frame instead keeps one stable reference to the container
 * and enumerates its current elements whenever the collector marks roots.
 */
class PHPX_API NativeContainerRootFrameBase {
  public:
    using TraceFn = void (*)(const void *container, NativeMarker &marker) noexcept;

    NativeContainerRootFrameBase(const void *container, TraceFn trace) noexcept;
    ~NativeContainerRootFrameBase() noexcept;

    NativeContainerRootFrameBase(const NativeContainerRootFrameBase &) = delete;
    NativeContainerRootFrameBase &operator=(const NativeContainerRootFrameBase &) = delete;

    NativeContainerRootFrameBase *previous() const noexcept {
        return previous_;
    }

    void trace(NativeMarker &marker) const noexcept {
        trace_(container_, marker);
    }

  private:
    // Container roots obey the same non-LIFO Fiber lifetime as scalar roots.
    NativeContainerRootFrameBase *previous_;
    NativeContainerRootFrameBase *newer_;
    const void *container_;
    TraceFn trace_;
    size_t requestEpoch_;
};

template <typename Entry>
static inline void markNativeContainerEntry(const Entry &entry, NativeMarker &marker) noexcept {
    using Value = std::remove_cv_t<std::remove_reference_t<Entry>>;
    if constexpr (std::is_pointer_v<Value>) {
        marker.mark(entry);
    } else {
        // StdMap/StdOrderedMap iterators expose a key/value pair.
        static_assert(std::is_pointer_v<std::remove_cv_t<std::remove_reference_t<decltype(entry.second)>>>,
                      "Native std containers must store pointer values");
        marker.mark(entry.second);
    }
}

template <typename Container>
class NativeContainerRootFrame final : private NativeContainerRootFrameBase {
  public:
    explicit NativeContainerRootFrame(const Container &container) noexcept
        : NativeContainerRootFrameBase(&container, traceContainer) {}

  private:
    static void traceContainer(const void *container, NativeMarker &marker) noexcept {
        for (const auto &entry : *static_cast<const Container *>(container)) {
            markNativeContainerEntry(entry, marker);
        }
    }
};

struct NativeGcStats {
    size_t bytesAllocated;
    size_t nextCollection;
    size_t objectCount;
    size_t collectionCount;
};

PHPX_API void *nativeGcAllocate(const NativeTypeDescriptor &type);
PHPX_API void *nativeGcRequireObject(void *object, const char *typeName);
PHPX_API void nativeGcAbandon(void *object) noexcept;
PHPX_API bool nativeGcIsReachable(const void *object) noexcept;
PHPX_API void nativeGcSuppressFinalizer(void *object) noexcept;
PHPX_API void nativeGcCollect();
PHPX_API NativeGcStats nativeGcStats() noexcept;
PHPX_API void nativeGcRegisterRequestRoot(NativeRootSlot slot);
PHPX_API void nativeGcRequestInit() noexcept;
PHPX_API void nativeGcRequestShutdown() noexcept;

/**
 * Validate a non-null Native ABI boundary without erasing the concrete
 * pointer type. Keeping T* is important for normal C++ derived-to-base
 * adjustment when a Native subclass is returned as its declared base class.
 */
template <typename T>
T *nativeRequireObject(T *object, const char *typeName) {
    nativeGcRequireObject(object, typeName);
    return object;
}

template <typename T>
T &nativeDeref(T *object, const char *typeName) {
    return *static_cast<T *>(nativeGcRequireObject(object, typeName));
}

template <typename T, typename... Args>
T *nativeNew(const NativeTypeDescriptor &type, Args &&...args) {
    void *storage = nativeGcAllocate(type);
    try {
        return new (storage) T(std::forward<Args>(args)...);
    } catch (...) {
        nativeGcAbandon(storage);
        throw;
    }
}

/**
 * Allocate and root a native object while its PHP-level constructor runs.
 *
 * The constructor callback may allocate enough objects to trigger a collection,
 * so publishing the object only after the callback returns would be unsafe.
 */
template <typename T, typename Initializer>
T *nativeConstruct(const NativeTypeDescriptor &type, Initializer &&initializer) {
    void *storage = nativeGcAllocate(type);
    T *object = nullptr;
    try {
        object = new (storage) T();
        NativeRootSlot slots[] = {reinterpret_cast<void **>(&object)};
        NativeRootFrame roots(slots, 1);
        std::forward<Initializer>(initializer)(*object);
        return object;
    } catch (...) {
        if (object != nullptr) {
            if (nativeGcIsReachable(object)) {
                // PHP permits a constructor to publish `$this` before it
                // throws. Keep that fully allocated object alive, but suppress
                // its user destructor just like Zend does for a failed ctor.
                nativeGcSuppressFinalizer(object);
            } else {
                object->~T();
                nativeGcAbandon(storage);
            }
        } else {
            nativeGcAbandon(storage);
        }
        throw;
    }
}

template <typename T, typename Initializer>
T *nativeClone(const NativeTypeDescriptor &type, const T &source, Initializer &&initializer) {
    void *storage = nativeGcAllocate(type);
    T *object = nullptr;
    try {
        object = new (storage) T(source);
        NativeRootSlot slots[] = {reinterpret_cast<void **>(&object)};
        NativeRootFrame roots(slots, 1);
        std::forward<Initializer>(initializer)(*object);
        return object;
    } catch (...) {
        if (object != nullptr) {
            if (type.finalize == nullptr && !nativeGcIsReachable(object)) {
                // Without a PHP-level destructor there is no observable
                // finalization to defer. Release copied PHPX fields promptly,
                // matching the normal failed-clone cleanup path.
                object->~T();
                nativeGcAbandon(storage);
            }
        } else {
            nativeGcAbandon(storage);
        }
        // The copy itself is fully constructed before the PHP-level __clone()
        // callback runs. A type with __destruct() must still pass through
        // Native finalization, and an escaped `$this` must remain valid. Leave
        // such an object in the tracing heap; roots decide whether it survives
        // this cycle and the finalizer still runs at most once.
        throw;
    }
}

} // namespace php

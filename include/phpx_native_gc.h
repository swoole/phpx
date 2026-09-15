/*
  +----------------------------------------------------------------------+
  | PHP-X Native Object GC                                                |
  +----------------------------------------------------------------------+
*/

#pragma once

#include <cstddef>
#include <cstring>
#include <exception>
#include <new>
#include <type_traits>
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
using NativeSuppressFinalizeFn = void (*)(void *object) noexcept;
using NativeDestroyFn = void (*)(void *object) noexcept;

struct NativeTypeDescriptor {
    const char *name;
    size_t size;
    size_t alignment;
    NativeTraceFn trace;
    NativeFinalizeFn finalize;
    NativeSuppressFinalizeFn suppressFinalize;
    NativeDestroyFn destroy;
};

/** Capture an exception swallowed by a generated C++ Native constructor. */
PHPX_API void nativeConstructorFailed() noexcept;

// Export operations, not the class containing a private STL implementation
// type. All exception_ptr access and lifetime management stay inside PHPX.
class NativeConstructorGuard final {
  public:
    PHPX_API NativeConstructorGuard() noexcept;
    PHPX_API ~NativeConstructorGuard() noexcept;

    NativeConstructorGuard(const NativeConstructorGuard &) = delete;
    NativeConstructorGuard &operator=(const NativeConstructorGuard &) = delete;

    PHPX_API bool failed() const noexcept;

    [[noreturn]] PHPX_API void rethrow();

  private:
    friend PHPX_API void nativeConstructorFailed() noexcept;

    NativeConstructorGuard *previous_;
    std::exception_ptr exception_;
};

/**
 * Per-subobject PHP destructor state.
 *
 * A C++ copy represents a PHP clone and must start with a fresh finalization
 * state even when the source object was resurrected from its destructor.
 */
class NativeDestructorState final {
  public:
    NativeDestructorState() noexcept = default;
    NativeDestructorState(const NativeDestructorState &) noexcept {}

    NativeDestructorState &operator=(const NativeDestructorState &) noexcept {
        finalized_ = false;
        return *this;
    }

    bool beginFinalize() noexcept {
        if (finalized_) {
            return false;
        }
        finalized_ = true;
        return true;
    }

    void suppress() noexcept {
        finalized_ = true;
    }

  private:
    bool finalized_ = false;
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
            rememberCurrentException();
        }
    }

    void rethrow();

  private:
    struct CppExceptionState;

    void remember(zend_object *exception) noexcept;
    void rememberCurrentException() noexcept;

    bool failed_ = false;
    zend_object *zendException_ = nullptr;
    // Keep STL implementation types out of this exported class layout. Apart
    // from avoiding MSVC C4251, the opaque state makes allocation exceptional:
    // the ordinary finalizer path remains allocation-free.
    CppExceptionState *cppException_ = nullptr;
};

/**
 * Type-erased address of one typed Native object pointer.
 *
 * A T** may not be dereferenced through void** under C++ strict-aliasing
 * rules. Keep the original slot type in a generated accessor instead. This
 * costs no allocation and is visited only while tracing or clearing roots.
 */
class NativeRootSlot final {
  public:
    template <typename T>
    NativeRootSlot(T **slot) noexcept : slot_(slot), access_(access<T>) {
        // Generated forward-declaration slots use void*. Concrete method
        // locals use T*. Both are object-pointer representations and retain
        // their exact slot type through access<T>().
        static_assert(std::is_object_v<T> || std::is_void_v<T>, "Native roots must point to object types");
    }

    void *get() const noexcept {
        return access_(slot_, false);
    }

    void clear() const noexcept {
        access_(slot_, true);
    }

    bool valid() const noexcept {
        return slot_ != nullptr;
    }

  private:
    using AccessFn = void *(*) (void *slot, bool clear) noexcept;

    template <typename T>
    static void *access(void *slot, bool clear) noexcept {
        auto **typed_slot = static_cast<T **>(slot);
        if (clear) {
            *typed_slot = nullptr;
            return nullptr;
        }
        return static_cast<void *>(*typed_slot);
    }

    void *slot_;
    AccessFn access_;
};

static_assert(sizeof(NativeRootSlot) == sizeof(void *) * 2);

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

/**
 * Function-local storage for a Native Object proven not to escape.
 *
 * The object itself is not a Wren allocation. Its Native Object properties
 * must nevertheless remain roots while the slot is alive, so this slot traces
 * outgoing edges through the ordinary generated type descriptor.
 *
 * PHP-level __destruct() is intentionally not handled here. The compiler only
 * selects stack storage for descriptors without a finalizer.
 */
template <typename T>
class NativeStackSlot final {
  public:
    explicit NativeStackSlot(const NativeTypeDescriptor &type) noexcept : type_(type), roots_(this, traceSlot) {
        static_assert(std::is_nothrow_destructible_v<T>, "Stack-promoted Native Objects must be nothrow destructible");
        ZEND_ASSERT(type_.size == sizeof(T));
        ZEND_ASSERT(type_.alignment == alignof(T));
        ZEND_ASSERT(type_.finalize == nullptr);
    }

    ~NativeStackSlot() noexcept = default;

    NativeStackSlot(const NativeStackSlot &) = delete;
    NativeStackSlot &operator=(const NativeStackSlot &) = delete;

    template <typename Initializer>
    T *construct(Initializer &&initializer) {
        ZEND_ASSERT(storage_.object == nullptr);
        storage_.object = new (storage_.bytes) T();
        try {
            std::forward<Initializer>(initializer)(*storage_.object);
            return storage_.object;
        } catch (...) {
            // Escape analysis guarantees that a promoted receiver was not
            // published by its constructor. Match nativeConstruct() by
            // releasing a failed construction immediately instead of keeping
            // its PHPX fields alive until the enclosing function returns.
            storage_.object->~T();
            storage_.object = nullptr;
            throw;
        }
    }

    template <typename... Args>
    T *constructObject(Args &&...args) {
        ZEND_ASSERT(storage_.object == nullptr);
        std::memset(storage_.bytes, 0, sizeof(storage_.bytes));
        T *object = reinterpret_cast<T *>(storage_.bytes);
        storage_.object = object;
        bool constructed = false;
        NativeConstructorGuard guard;
        try {
            new (storage_.bytes) T(std::forward<Args>(args)...);
            constructed = true;
            if (guard.failed()) {
                guard.rethrow();
            }
            return object;
        } catch (...) {
            if (constructed) {
                object->~T();
            }
            storage_.object = nullptr;
            throw;
        }
    }

    T *get() noexcept {
        return storage_.object;
    }

  private:
    struct Storage final {
        ~Storage() noexcept {
            if (object != nullptr) {
                object->~T();
            }
        }

        alignas(T) unsigned char bytes[sizeof(T)];
        T *object = nullptr;
    };

    static void traceSlot(const void *slot, NativeMarker &marker) noexcept {
        const auto *self = static_cast<const NativeStackSlot *>(slot);
        if (self->storage_.object != nullptr && self->type_.trace != nullptr) {
            self->type_.trace(self->storage_.object, marker);
        }
    }

    const NativeTypeDescriptor &type_;
    // roots_ is declared after storage_ so it unlinks before Storage destroys
    // the C++ object. A member destructor may invoke PHP code and trigger a GC;
    // the collector must never trace a partially destroyed stack object.
    Storage storage_;
    NativeContainerRootFrameBase roots_;
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
        NativeRootSlot slots[] = {&object};
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
                if (type.suppressFinalize != nullptr) {
                    type.suppressFinalize(object);
                }
            } else {
                if (type.suppressFinalize != nullptr) {
                    type.suppressFinalize(object);
                }
                object->~T();
                nativeGcAbandon(storage);
            }
        } else {
            nativeGcAbandon(storage);
        }
        throw;
    }
}

/**
 * Allocate and root storage before invoking a generated C++ constructor.
 *
 * Generated constructors swallow their PHP body exception through
 * nativeConstructorFailed(), allowing a published `$this` to remain a fully
 * constructed object. This helper then applies the ordinary PHP constructor
 * failure policy and rethrows the captured exception.
 */
template <typename T, typename... Args>
T *nativeConstructObject(const NativeTypeDescriptor &type, Args &&...args) {
    void *storage = nativeGcAllocate(type);
    std::memset(storage, 0, type.size);
    T *object = static_cast<T *>(storage);
    NativeConstructorGuard guard;
    bool constructed = false;
    try {
        {
            NativeRootSlot slots[] = {&object};
            NativeRootFrame roots(slots, 1);
            new (storage) T(std::forward<Args>(args)...);
            constructed = true;
        }
        if (!guard.failed()) {
            return object;
        }

        if (nativeGcIsReachable(object)) {
            nativeGcSuppressFinalizer(object);
            if (type.suppressFinalize != nullptr) {
                type.suppressFinalize(object);
            }
        } else {
            if (type.suppressFinalize != nullptr) {
                type.suppressFinalize(object);
            }
            object->~T();
            nativeGcAbandon(storage);
            object = nullptr;
        }
        guard.rethrow();
    } catch (...) {
        if (!constructed) {
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
        NativeRootSlot slots[] = {&object};
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

}  // namespace php

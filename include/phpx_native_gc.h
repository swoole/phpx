/*
  +----------------------------------------------------------------------+
  | PHP-X Native Object GC                                                |
  +----------------------------------------------------------------------+
*/

#pragma once

#include <cstddef>
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
    NativeRootFrame *previous_;
    NativeRootSlot *slots_;
    size_t count_;
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
PHPX_API void nativeGcCollect();
PHPX_API NativeGcStats nativeGcStats() noexcept;
PHPX_API void nativeGcRegisterRequestRoot(NativeRootSlot slot);
PHPX_API void nativeGcRequestInit() noexcept;
PHPX_API void nativeGcRequestShutdown() noexcept;

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
            object->~T();
        }
        nativeGcAbandon(storage);
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
            object->~T();
        }
        nativeGcAbandon(storage);
        throw;
    }
}

} // namespace php

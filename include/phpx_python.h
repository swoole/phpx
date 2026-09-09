#pragma once

#include "phpx.h"

namespace php {

/** Optional phpy fast path, installed explicitly by the embedding project. */
namespace python {

enum class Constructor : uint32_t {
    List = 0,
    Dict,
    Tuple,
    Set,
    Str,
    Object,
    Int,
    Float,
    Bytes,
};

/**
 * Install a versioned native API table supplied by phpy (or another bridge).
 * The pointer remains owned by the provider and must stay valid until it is
 * replaced or clearNativeApi() is called.
 */
PHPX_API bool installNativeApi(const void *api) noexcept;
PHPX_API void clearNativeApi() noexcept;

PHPX_API void configureRuntime(bool return_as_object = true);
PHPX_API Object importModule(const String &name);
PHPX_API Object construct(Constructor constructor);
PHPX_API Object construct(Constructor constructor, const Variant &argument);
PHPX_API Variant call(const Variant &object);
PHPX_API Variant call(const Variant &object, Args &args, zend_array *named_args = nullptr);
PHPX_API Variant call(const Variant &object, FixedArgs args, zend_array *named_args = nullptr);
PHPX_API Variant call(const Variant &object, const ArgList &args, zend_array *named_args = nullptr);
PHPX_API Variant callMember(const Variant &object, const String &name);
PHPX_API Variant callMember(const Variant &object, const String &name, Args &args, zend_array *named_args = nullptr);
PHPX_API Variant callMember(const Variant &object,
                            const String &name,
                            FixedArgs args,
                            zend_array *named_args = nullptr);
PHPX_API Variant callMember(const Variant &object,
                            const String &name,
                            const ArgList &args,
                            zend_array *named_args = nullptr);
PHPX_API Variant getAttr(const Variant &object, const String &name);
PHPX_API Variant toValue(const Variant &object);
PHPX_API Array toArray(const Variant &object);

}  // namespace python
}  // namespace php

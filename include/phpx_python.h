#pragma once

#include "phpx.h"

namespace php {

/**
 * Optional phpy fast path. The implementation discovers phpy's versioned C
 * ABI at runtime, so PHPX remains independent of Python and libphpy.
 */
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

PHPX_API void configureRuntime(bool return_as_object = true);
PHPX_API Object importModule(const String &name);
PHPX_API Object construct(Constructor constructor);
PHPX_API Object construct(Constructor constructor, const Variant &argument);
PHPX_API Variant call(const Variant &object);
PHPX_API Variant call(const Variant &object, Args &args, zend_array *named_args = nullptr);
PHPX_API Variant call(const Variant &object, const ArgList &args, zend_array *named_args = nullptr);
PHPX_API Variant callMember(const Variant &object, const String &name);
PHPX_API Variant callMember(const Variant &object,
                            const String &name,
                            Args &args,
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

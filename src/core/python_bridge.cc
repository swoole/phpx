#include "phpx_python.h"

#include <cstddef>
#include <cstdint>

namespace php::python {
namespace {

constexpr uint32_t native_abi_version = 1;

struct NativeApi {
    uint32_t abi_version;
    size_t struct_size;
    zend_result (*configure_runtime)(zend_bool return_as_object);
    zend_result (*import_module)(const char *name, size_t name_length, zval *result);
    zend_result (*call_member)(const zval *object,
                               const char *name,
                               size_t name_length,
                               uint32_t argc,
                               zval *argv,
                               zend_array *named_args,
                               zval *result);
    zend_result (*get_attr)(const zval *object, const char *name, size_t name_length, zval *result);
    zend_result (*to_value)(const zval *object, zval *result);
    zend_result (*to_array)(const zval *object, zval *result);
    zend_result (*construct)(uint32_t constructor, const zval *argument, zend_bool has_argument, zval *result);
    zend_result (*call)(const zval *object, uint32_t argc, zval *argv, zend_array *named_args, zval *result);
};

const NativeApi *native_api = nullptr;

const NativeApi &api() {
    if (UNEXPECTED(native_api == nullptr)) {
        throwError("phpy native API is unavailable or ABI-incompatible");
    }
    return *native_api;
}

void check(zend_result status) {
    if (UNEXPECTED(status == FAILURE && EG(exception) == nullptr)) {
        throwError("phpy native API failed without an exception");
    }
    throwErrorIfOccurred();
}

Variant takeResult(zval &result, zend_result status) {
    // Take ownership before propagating an exception. A converter may have
    // produced a partially initialized refcounted value before failing.
    Variant value(&result, Ctor::Move);
    check(status);
    return value;
}

}  // namespace

bool installNativeApi(const void *table) noexcept {
    const auto *candidate = static_cast<const NativeApi *>(table);
    if (candidate == nullptr || candidate->abi_version != native_abi_version ||
        candidate->struct_size < sizeof(NativeApi)) {
        return false;
    }
    native_api = candidate;
    return true;
}

void clearNativeApi() noexcept {
    native_api = nullptr;
}

void configureRuntime(bool return_as_object) {
    check(api().configure_runtime(return_as_object));
}

Object importModule(const String &name) {
    zval result;
    ZVAL_UNDEF(&result);
    Variant value = takeResult(result, api().import_module(name.data(), name.length(), &result));
    return Object(value);
}

Object construct(Constructor constructor) {
    zval result;
    ZVAL_UNDEF(&result);
    Variant value = takeResult(result, api().construct(static_cast<uint32_t>(constructor), nullptr, false, &result));
    return Object(value);
}

Object construct(Constructor constructor, const Variant &argument) {
    zval result;
    ZVAL_UNDEF(&result);
    Variant value =
        takeResult(result, api().construct(static_cast<uint32_t>(constructor), argument.const_ptr(), true, &result));
    return Object(value);
}

Variant call(const Variant &object) {
    zval result;
    ZVAL_UNDEF(&result);
    return takeResult(result, api().call(object.const_ptr(), 0, nullptr, nullptr, &result));
}

Variant call(const Variant &object, Args &args, zend_array *named_args) {
    zval result;
    ZVAL_UNDEF(&result);
    return takeResult(
        result, api().call(object.const_ptr(), static_cast<uint32_t>(args.count()), args.ptr(), named_args, &result));
}

Variant call(const Variant &object, FixedArgs args, zend_array *named_args) {
    zval result;
    ZVAL_UNDEF(&result);
    return takeResult(result, api().call(object.const_ptr(), args.count(), args.ptr(), named_args, &result));
}

Variant call(const Variant &object, const ArgList &args, zend_array *named_args) {
    Args call_args(args);
    return php::python::call(object, call_args, named_args);
}

Variant callMember(const Variant &object, const String &name) {
    zval result;
    ZVAL_UNDEF(&result);
    return takeResult(result,
                      api().call_member(object.const_ptr(), name.data(), name.length(), 0, nullptr, nullptr, &result));
}

Variant callMember(const Variant &object, const String &name, Args &args, zend_array *named_args) {
    zval result;
    ZVAL_UNDEF(&result);
    return takeResult(result,
                      api().call_member(object.const_ptr(),
                                        name.data(),
                                        name.length(),
                                        static_cast<uint32_t>(args.count()),
                                        args.ptr(),
                                        named_args,
                                        &result));
}

Variant callMember(const Variant &object, const String &name, FixedArgs args, zend_array *named_args) {
    zval result;
    ZVAL_UNDEF(&result);
    return takeResult(result,
                      api().call_member(object.const_ptr(),
                                        name.data(),
                                        name.length(),
                                        args.count(),
                                        args.ptr(),
                                        named_args,
                                        &result));
}

Variant callMember(const Variant &object, const String &name, const ArgList &args, zend_array *named_args) {
    Args call_args(args);
    return callMember(object, name, call_args, named_args);
}

Variant getAttr(const Variant &object, const String &name) {
    zval result;
    ZVAL_UNDEF(&result);
    return takeResult(result, api().get_attr(object.const_ptr(), name.data(), name.length(), &result));
}

Variant toValue(const Variant &object) {
    zval result;
    ZVAL_UNDEF(&result);
    return takeResult(result, api().to_value(object.const_ptr(), &result));
}

Array toArray(const Variant &object) {
    zval result;
    ZVAL_UNDEF(&result);
    Variant value = takeResult(result, api().to_array(object.const_ptr(), &result));
    return Array(value);
}

}  // namespace php::python

#include "phpx_helper.h"

namespace php {

void throwArgumentTypeError(const Variant &value,
                            const String &callable_name,
                            zend_long argument_number,
                            const String &parameter_name,
                            const String &expected_type) {
    throwExceptionEx(zend_ce_type_error,
                     0,
                     "%s(): Argument #" ZEND_LONG_FMT " ($%s) must be of type %s, %s given",
                     callable_name.data(),
                     argument_number,
                     parameter_name.data(),
                     expected_type.data(),
                     value.typeStr());
}

void throwReturnTypeError(const Variant &value,
                          const String &callable_name,
                          const String &expected_type,
                          bool use_returned_word) {
    if (use_returned_word) {
        throwExceptionEx(zend_ce_type_error,
                         0,
                         "%s(): Return value must be of type %s, %s returned",
                         callable_name.data(),
                         expected_type.data(),
                         value.typeStr());
    }
    throwExceptionEx(zend_ce_type_error,
                     0,
                     "%s(): Return value must be of type %s, %s given",
                     callable_name.data(),
                     expected_type.data(),
                     value.typeStr());
}

}  // namespace php

/*
  +----------------------------------------------------------------------+
  | PHP-X                                                                |
  +----------------------------------------------------------------------+
  | This source file is subject to version 2.0 of the Apache license.     |
  +----------------------------------------------------------------------+
*/

#include "phpx.h"
#include "phpx_fake_scope_guard.h"

namespace php {

DebugInfo debug_info{
    false,
    {},
    0,
};

void pushDebugFrame(const char *file, int lineno, const char *function) {
    if (!debug_info.enable || debug_info.depth >= PHPX_MAX_DEBUG_DEPTH) {
        return;
    }
    auto &frame = debug_info.frames[debug_info.depth++];
    frame.file = file;
    frame.line = lineno;
    frame.function = function;
}

void popDebugFrame() {
    if (debug_info.depth > 0) {
        debug_info.depth--;
    }
}

void traceDebugInfo(const char *file, int lineno) {
    if (!debug_info.enable) {
        return;
    }
    if (debug_info.depth == 0) {
        pushDebugFrame(file, lineno, nullptr);
    } else {
        auto &frame = debug_info.frames[debug_info.depth - 1];
        frame.file = file;
        frame.line = lineno;
    }
}

void enableDebugInfo(bool enable) {
    debug_info.enable = enable;
}

void augmentException() {
    if (!debug_info.enable || debug_info.depth == 0 || !EG(exception)) {
        return;
    }

    FakeScopeGuard fake_scope_guard{EG(exception)->ce};

    // Set file/line from the innermost frame
    auto &top = debug_info.frames[debug_info.depth - 1];
    zval tmp;
    ZVAL_STRING(&tmp, top.file ? top.file : "");
    zend_update_property_ex(EG(exception)->ce, EG(exception), ZSTR_KNOWN(ZEND_STR_FILE), &tmp);
    zval_ptr_dtor(&tmp);

    ZVAL_LONG(&tmp, top.line);
    zend_update_property_ex(EG(exception)->ce, EG(exception), ZSTR_KNOWN(ZEND_STR_LINE), &tmp);

    // Build backtrace array in zend_fetch_debug_backtrace format
    // Each frame: {file, line, function, class?, type?, args}
    Array trace;
    for (int i = debug_info.depth - 1; i >= 0; i--) {
        auto &frame = debug_info.frames[i];

        Array entry;
        entry.set(ZSTR_KNOWN(ZEND_STR_FILE), String(frame.file ? frame.file : ""));
        entry.set(ZSTR_KNOWN(ZEND_STR_LINE), frame.line);

        const char *func = frame.function ? frame.function : "";
        const char *colon = func ? strstr(func, "::") : nullptr;

        if (colon && colon > func) {
            // ClassName::methodName
            entry.set(ZSTR_KNOWN(ZEND_STR_CLASS), String(func, colon - func));
            entry.set(ZSTR_KNOWN(ZEND_STR_TYPE), String("::"));
            entry.set(ZSTR_KNOWN(ZEND_STR_FUNCTION), String(colon + 2));
        } else {
            entry.set(ZSTR_KNOWN(ZEND_STR_FUNCTION), String(func));
        }

        entry.set(ZSTR_KNOWN(ZEND_STR_ARGS), Array());
        trace.append(entry);
    }

    zend_update_property_ex(EG(exception)->ce, EG(exception), ZSTR_KNOWN(ZEND_STR_TRACE), trace.ptr());
}

}  // namespace php

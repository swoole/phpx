#include "phpx.h"
#include "phpx_literal_string.h"
#include "phpx_class.h"

namespace php {
Variant textdomain(const Variant &domain) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[665]);
    }
    return call(_fn, {domain});
}
Variant gettext(const Variant &message) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[666]);
    }
    return call(_fn, {message});
}
Variant _(const Variant &message) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[667]);
    }
    return call(_fn, {message});
}
Variant dgettext(const Variant &domain, const Variant &message) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[668]);
    }
    return call(_fn, {domain, message});
}
Variant dcgettext(const Variant &domain, const Variant &message, const Variant &category) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[669]);
    }
    return call(_fn, {domain, message, category});
}
Variant bindtextdomain(const Variant &domain, const Variant &directory) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[670]);
    }
    return call(_fn, {domain, directory});
}
Variant ngettext(const Variant &singular, const Variant &plural, const Variant &count) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[671]);
    }
    return call(_fn, {singular, plural, count});
}
Variant dngettext(const Variant &domain, const Variant &singular, const Variant &plural, const Variant &count) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[672]);
    }
    return call(_fn, {domain, singular, plural, count});
}
Variant dcngettext(const Variant &domain,
                   const Variant &singular,
                   const Variant &plural,
                   const Variant &count,
                   const Variant &category) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[673]);
    }
    return call(_fn, {domain, singular, plural, count, category});
}
Variant bind_textdomain_codeset(const Variant &domain, const Variant &codeset) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[674]);
    }
    return call(_fn, {domain, codeset});
}
}  // namespace php

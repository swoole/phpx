#include "phpx.h"
#include "phpx_class.h"
#include "class/spl.h"

namespace php {
LogicException::LogicException(const Variant &message, const Variant &code, const Variant &previous) {
    this_ = newObject(LITERAL_STRING[2029], {message, code, previous});
}
BadFunctionCallException::BadFunctionCallException(const Variant &message,
                                                   const Variant &code,
                                                   const Variant &previous) {
    this_ = newObject(LITERAL_STRING[2030], {message, code, previous});
}
BadMethodCallException::BadMethodCallException(const Variant &message, const Variant &code, const Variant &previous) {
    this_ = newObject(LITERAL_STRING[2031], {message, code, previous});
}
DomainException::DomainException(const Variant &message, const Variant &code, const Variant &previous) {
    this_ = newObject(LITERAL_STRING[2032], {message, code, previous});
}
InvalidArgumentException::InvalidArgumentException(const Variant &message,
                                                   const Variant &code,
                                                   const Variant &previous) {
    this_ = newObject(LITERAL_STRING[2033], {message, code, previous});
}
LengthException::LengthException(const Variant &message, const Variant &code, const Variant &previous) {
    this_ = newObject(LITERAL_STRING[2034], {message, code, previous});
}
OutOfRangeException::OutOfRangeException(const Variant &message, const Variant &code, const Variant &previous) {
    this_ = newObject(LITERAL_STRING[2035], {message, code, previous});
}
RuntimeException::RuntimeException(const Variant &message, const Variant &code, const Variant &previous) {
    this_ = newObject(LITERAL_STRING[2036], {message, code, previous});
}
OutOfBoundsException::OutOfBoundsException(const Variant &message, const Variant &code, const Variant &previous) {
    this_ = newObject(LITERAL_STRING[2037], {message, code, previous});
}
OverflowException::OverflowException(const Variant &message, const Variant &code, const Variant &previous) {
    this_ = newObject(LITERAL_STRING[2038], {message, code, previous});
}
RangeException::RangeException(const Variant &message, const Variant &code, const Variant &previous) {
    this_ = newObject(LITERAL_STRING[2039], {message, code, previous});
}
UnderflowException::UnderflowException(const Variant &message, const Variant &code, const Variant &previous) {
    this_ = newObject(LITERAL_STRING[2040], {message, code, previous});
}
UnexpectedValueException::UnexpectedValueException(const Variant &message,
                                                   const Variant &code,
                                                   const Variant &previous) {
    this_ = newObject(LITERAL_STRING[2041], {message, code, previous});
}
RecursiveIteratorIterator::RecursiveIteratorIterator(const Variant &iterator,
                                                     const Variant &mode,
                                                     const Variant &flags) {
    this_ = newObject(LITERAL_STRING[2042], {iterator, mode, flags});
}
Variant RecursiveIteratorIterator::rewind() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[122]);
    }
    return this_.call(_method_fn, {});
}
Variant RecursiveIteratorIterator::valid() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[121]);
    }
    return this_.call(_method_fn, {});
}
Variant RecursiveIteratorIterator::key() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[119]);
    }
    return this_.call(_method_fn, {});
}
Variant RecursiveIteratorIterator::current() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[118]);
    }
    return this_.call(_method_fn, {});
}
Variant RecursiveIteratorIterator::next() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[120]);
    }
    return this_.call(_method_fn, {});
}
Variant RecursiveIteratorIterator::getDepth() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[2043]);
    }
    return this_.call(_method_fn, {});
}
Variant RecursiveIteratorIterator::getSubIterator(const Variant &level) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[2044]);
    }
    return this_.call(_method_fn, {level});
}
Variant RecursiveIteratorIterator::getInnerIterator() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[2045]);
    }
    return this_.call(_method_fn, {});
}
Variant RecursiveIteratorIterator::beginIteration() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[2046]);
    }
    return this_.call(_method_fn, {});
}
Variant RecursiveIteratorIterator::endIteration() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[2047]);
    }
    return this_.call(_method_fn, {});
}
Variant RecursiveIteratorIterator::callHasChildren() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[2048]);
    }
    return this_.call(_method_fn, {});
}
Variant RecursiveIteratorIterator::callGetChildren() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[2049]);
    }
    return this_.call(_method_fn, {});
}
Variant RecursiveIteratorIterator::beginChildren() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[2050]);
    }
    return this_.call(_method_fn, {});
}
Variant RecursiveIteratorIterator::endChildren() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[2051]);
    }
    return this_.call(_method_fn, {});
}
Variant RecursiveIteratorIterator::nextElement() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[2052]);
    }
    return this_.call(_method_fn, {});
}
Variant RecursiveIteratorIterator::setMaxDepth(const Variant &max_depth) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[2053]);
    }
    return this_.call(_method_fn, {max_depth});
}
Variant RecursiveIteratorIterator::getMaxDepth() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[2054]);
    }
    return this_.call(_method_fn, {});
}
IteratorIterator::IteratorIterator(const Variant &iterator, const Variant &class_) {
    this_ = newObject(LITERAL_STRING[2055], {iterator, class_});
}
Variant IteratorIterator::getInnerIterator() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[2045]);
    }
    return this_.call(_method_fn, {});
}
Variant IteratorIterator::rewind() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[122]);
    }
    return this_.call(_method_fn, {});
}
Variant IteratorIterator::valid() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[121]);
    }
    return this_.call(_method_fn, {});
}
Variant IteratorIterator::key() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[119]);
    }
    return this_.call(_method_fn, {});
}
Variant IteratorIterator::current() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[118]);
    }
    return this_.call(_method_fn, {});
}
Variant IteratorIterator::next() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[120]);
    }
    return this_.call(_method_fn, {});
}
CallbackFilterIterator::CallbackFilterIterator(const Variant &iterator, const Variant &callback) {
    this_ = newObject(LITERAL_STRING[2056], {iterator, callback});
}
Variant CallbackFilterIterator::accept() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[2057]);
    }
    return this_.call(_method_fn, {});
}
Variant CallbackFilterIterator::rewind() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[122]);
    }
    return this_.call(_method_fn, {});
}
Variant CallbackFilterIterator::next() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[120]);
    }
    return this_.call(_method_fn, {});
}
Variant CallbackFilterIterator::getInnerIterator() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[2045]);
    }
    return this_.call(_method_fn, {});
}
Variant CallbackFilterIterator::valid() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[121]);
    }
    return this_.call(_method_fn, {});
}
Variant CallbackFilterIterator::key() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[119]);
    }
    return this_.call(_method_fn, {});
}
Variant CallbackFilterIterator::current() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[118]);
    }
    return this_.call(_method_fn, {});
}
RecursiveCallbackFilterIterator::RecursiveCallbackFilterIterator(const Variant &iterator, const Variant &callback) {
    this_ = newObject(LITERAL_STRING[2058], {iterator, callback});
}
Variant RecursiveCallbackFilterIterator::hasChildren() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1867]);
    }
    return this_.call(_method_fn, {});
}
Variant RecursiveCallbackFilterIterator::getChildren() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1868]);
    }
    return this_.call(_method_fn, {});
}
ParentIterator::ParentIterator(const Variant &iterator) {
    this_ = newObject(LITERAL_STRING[2059], {iterator});
}
Variant ParentIterator::accept() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[2057]);
    }
    return this_.call(_method_fn, {});
}
Variant ParentIterator::hasChildren() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1867]);
    }
    return this_.call(_method_fn, {});
}
Variant ParentIterator::getChildren() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1868]);
    }
    return this_.call(_method_fn, {});
}
Variant ParentIterator::rewind() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[122]);
    }
    return this_.call(_method_fn, {});
}
Variant ParentIterator::next() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[120]);
    }
    return this_.call(_method_fn, {});
}
Variant ParentIterator::getInnerIterator() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[2045]);
    }
    return this_.call(_method_fn, {});
}
Variant ParentIterator::valid() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[121]);
    }
    return this_.call(_method_fn, {});
}
Variant ParentIterator::key() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[119]);
    }
    return this_.call(_method_fn, {});
}
Variant ParentIterator::current() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[118]);
    }
    return this_.call(_method_fn, {});
}
LimitIterator::LimitIterator(const Variant &iterator, const Variant &offset, const Variant &limit) {
    this_ = newObject(LITERAL_STRING[2060], {iterator, offset, limit});
}
Variant LimitIterator::rewind() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[122]);
    }
    return this_.call(_method_fn, {});
}
Variant LimitIterator::valid() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[121]);
    }
    return this_.call(_method_fn, {});
}
Variant LimitIterator::next() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[120]);
    }
    return this_.call(_method_fn, {});
}
Variant LimitIterator::seek(const Variant &offset) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[2061]);
    }
    return this_.call(_method_fn, {offset});
}
Variant LimitIterator::getPosition() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1687]);
    }
    return this_.call(_method_fn, {});
}
CachingIterator::CachingIterator(const Variant &iterator, const Variant &flags) {
    this_ = newObject(LITERAL_STRING[2062], {iterator, flags});
}
Variant CachingIterator::rewind() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[122]);
    }
    return this_.call(_method_fn, {});
}
Variant CachingIterator::valid() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[121]);
    }
    return this_.call(_method_fn, {});
}
Variant CachingIterator::next() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[120]);
    }
    return this_.call(_method_fn, {});
}
Variant CachingIterator::hasNext() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[2063]);
    }
    return this_.call(_method_fn, {});
}
Variant CachingIterator::__toString() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[29]);
    }
    return this_.call(_method_fn, {});
}
Variant CachingIterator::getFlags() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[2064]);
    }
    return this_.call(_method_fn, {});
}
Variant CachingIterator::setFlags(const Variant &flags) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[2065]);
    }
    return this_.call(_method_fn, {flags});
}
Variant CachingIterator::offsetGet(const Variant &key) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[164]);
    }
    return this_.call(_method_fn, {key});
}
Variant CachingIterator::offsetSet(const Variant &key, const Variant &value) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[165]);
    }
    return this_.call(_method_fn, {key, value});
}
Variant CachingIterator::offsetUnset(const Variant &key) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[167]);
    }
    return this_.call(_method_fn, {key});
}
Variant CachingIterator::offsetExists(const Variant &key) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[166]);
    }
    return this_.call(_method_fn, {key});
}
Variant CachingIterator::getCache() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[2066]);
    }
    return this_.call(_method_fn, {});
}
Variant CachingIterator::count() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[168]);
    }
    return this_.call(_method_fn, {});
}
RecursiveCachingIterator::RecursiveCachingIterator(const Variant &iterator, const Variant &flags) {
    this_ = newObject(LITERAL_STRING[2067], {iterator, flags});
}
Variant RecursiveCachingIterator::hasChildren() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1867]);
    }
    return this_.call(_method_fn, {});
}
Variant RecursiveCachingIterator::getChildren() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1868]);
    }
    return this_.call(_method_fn, {});
}
NoRewindIterator::NoRewindIterator(const Variant &iterator) {
    this_ = newObject(LITERAL_STRING[2068], {iterator});
}
Variant NoRewindIterator::rewind() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[122]);
    }
    return this_.call(_method_fn, {});
}
Variant NoRewindIterator::valid() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[121]);
    }
    return this_.call(_method_fn, {});
}
Variant NoRewindIterator::key() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[119]);
    }
    return this_.call(_method_fn, {});
}
Variant NoRewindIterator::current() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[118]);
    }
    return this_.call(_method_fn, {});
}
Variant NoRewindIterator::next() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[120]);
    }
    return this_.call(_method_fn, {});
}
InfiniteIterator::InfiniteIterator(const Variant &iterator) {
    this_ = newObject(LITERAL_STRING[2072], {iterator});
}
Variant InfiniteIterator::next() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[120]);
    }
    return this_.call(_method_fn, {});
}
RegexIterator::RegexIterator(const Variant &iterator,
                             const Variant &pattern,
                             const Variant &mode,
                             const Variant &flags,
                             const Variant &preg_flags) {
    this_ = newObject(LITERAL_STRING[2073], {iterator, pattern, mode, flags, preg_flags});
}
Variant RegexIterator::accept() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[2057]);
    }
    return this_.call(_method_fn, {});
}
Variant RegexIterator::getMode() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1336]);
    }
    return this_.call(_method_fn, {});
}
Variant RegexIterator::setMode(const Variant &mode) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[2074]);
    }
    return this_.call(_method_fn, {mode});
}
Variant RegexIterator::getFlags() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[2064]);
    }
    return this_.call(_method_fn, {});
}
Variant RegexIterator::setFlags(const Variant &flags) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[2065]);
    }
    return this_.call(_method_fn, {flags});
}
Variant RegexIterator::getRegex() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[2075]);
    }
    return this_.call(_method_fn, {});
}
Variant RegexIterator::getPregFlags() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[2076]);
    }
    return this_.call(_method_fn, {});
}
Variant RegexIterator::setPregFlags(const Variant &preg_flags) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[2077]);
    }
    return this_.call(_method_fn, {preg_flags});
}
Variant RegexIterator::rewind() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[122]);
    }
    return this_.call(_method_fn, {});
}
Variant RegexIterator::next() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[120]);
    }
    return this_.call(_method_fn, {});
}
Variant RegexIterator::getInnerIterator() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[2045]);
    }
    return this_.call(_method_fn, {});
}
Variant RegexIterator::valid() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[121]);
    }
    return this_.call(_method_fn, {});
}
Variant RegexIterator::key() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[119]);
    }
    return this_.call(_method_fn, {});
}
Variant RegexIterator::current() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[118]);
    }
    return this_.call(_method_fn, {});
}
RecursiveRegexIterator::RecursiveRegexIterator(const Variant &iterator,
                                               const Variant &pattern,
                                               const Variant &mode,
                                               const Variant &flags,
                                               const Variant &preg_flags) {
    this_ = newObject(LITERAL_STRING[2078], {iterator, pattern, mode, flags, preg_flags});
}
Variant RecursiveRegexIterator::accept() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[2057]);
    }
    return this_.call(_method_fn, {});
}
Variant RecursiveRegexIterator::hasChildren() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1867]);
    }
    return this_.call(_method_fn, {});
}
Variant RecursiveRegexIterator::getChildren() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1868]);
    }
    return this_.call(_method_fn, {});
}
EmptyIterator::EmptyIterator() {
    this_ = newObject(LITERAL_STRING[2079]);
}
Variant EmptyIterator::current() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[118]);
    }
    return this_.call(_method_fn, {});
}
Variant EmptyIterator::next() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[120]);
    }
    return this_.call(_method_fn, {});
}
Variant EmptyIterator::key() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[119]);
    }
    return this_.call(_method_fn, {});
}
Variant EmptyIterator::valid() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[121]);
    }
    return this_.call(_method_fn, {});
}
Variant EmptyIterator::rewind() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[122]);
    }
    return this_.call(_method_fn, {});
}
RecursiveTreeIterator::RecursiveTreeIterator(const Variant &iterator,
                                             const Variant &flags,
                                             const Variant &caching_iterator_flags,
                                             const Variant &mode) {
    this_ = newObject(LITERAL_STRING[2080], {iterator, flags, caching_iterator_flags, mode});
}
Variant RecursiveTreeIterator::key() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[119]);
    }
    return this_.call(_method_fn, {});
}
Variant RecursiveTreeIterator::current() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[118]);
    }
    return this_.call(_method_fn, {});
}
Variant RecursiveTreeIterator::getPrefix() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[2081]);
    }
    return this_.call(_method_fn, {});
}
Variant RecursiveTreeIterator::setPostfix(const Variant &postfix) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[2082]);
    }
    return this_.call(_method_fn, {postfix});
}
Variant RecursiveTreeIterator::setPrefixPart(const Variant &part, const Variant &value) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[2083]);
    }
    return this_.call(_method_fn, {part, value});
}
Variant RecursiveTreeIterator::getEntry() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[2084]);
    }
    return this_.call(_method_fn, {});
}
Variant RecursiveTreeIterator::getPostfix() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[2085]);
    }
    return this_.call(_method_fn, {});
}
ArrayObject::ArrayObject(const Variant &array, const Variant &flags, const Variant &iterator_class) {
    this_ = newObject(LITERAL_STRING[2086], {array, flags, iterator_class});
}
Variant ArrayObject::offsetExists(const Variant &key) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[166]);
    }
    return this_.call(_method_fn, {key});
}
Variant ArrayObject::offsetGet(const Variant &key) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[164]);
    }
    return this_.call(_method_fn, {key});
}
Variant ArrayObject::offsetSet(const Variant &key, const Variant &value) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[165]);
    }
    return this_.call(_method_fn, {key, value});
}
Variant ArrayObject::offsetUnset(const Variant &key) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[167]);
    }
    return this_.call(_method_fn, {key});
}
Variant ArrayObject::append(const Variant &value) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[400]);
    }
    return this_.call(_method_fn, {value});
}
Variant ArrayObject::getArrayCopy() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[2087]);
    }
    return this_.call(_method_fn, {});
}
Variant ArrayObject::count() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[168]);
    }
    return this_.call(_method_fn, {});
}
Variant ArrayObject::getFlags() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[2064]);
    }
    return this_.call(_method_fn, {});
}
Variant ArrayObject::setFlags(const Variant &flags) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[2065]);
    }
    return this_.call(_method_fn, {flags});
}
Variant ArrayObject::asort(const Variant &flags) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[2088]);
    }
    return this_.call(_method_fn, {flags});
}
Variant ArrayObject::ksort(const Variant &flags) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[2089]);
    }
    return this_.call(_method_fn, {flags});
}
Variant ArrayObject::uasort(const Variant &callback) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[2090]);
    }
    return this_.call(_method_fn, {callback});
}
Variant ArrayObject::uksort(const Variant &callback) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[2091]);
    }
    return this_.call(_method_fn, {callback});
}
Variant ArrayObject::natsort() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[2092]);
    }
    return this_.call(_method_fn, {});
}
Variant ArrayObject::natcasesort() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[2093]);
    }
    return this_.call(_method_fn, {});
}
Variant ArrayObject::unserialize(const Variant &data) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[2094]);
    }
    return this_.call(_method_fn, {data});
}
Variant ArrayObject::serialize() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[2095]);
    }
    return this_.call(_method_fn, {});
}
Variant ArrayObject::__serialize() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[30]);
    }
    return this_.call(_method_fn, {});
}
Variant ArrayObject::__unserialize(const Variant &data) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[31]);
    }
    return this_.call(_method_fn, {data});
}
Variant ArrayObject::getIterator() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[169]);
    }
    return this_.call(_method_fn, {});
}
Variant ArrayObject::exchangeArray(const Variant &array) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[2096]);
    }
    return this_.call(_method_fn, {array});
}
Variant ArrayObject::setIteratorClass(const Variant &iterator_class) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[2097]);
    }
    return this_.call(_method_fn, {iterator_class});
}
Variant ArrayObject::getIteratorClass() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[2098]);
    }
    return this_.call(_method_fn, {});
}
Variant ArrayObject::__debugInfo() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[157]);
    }
    return this_.call(_method_fn, {});
}
ArrayIterator_::ArrayIterator_(const Variant &array, const Variant &flags) {
    this_ = newObject(LITERAL_STRING[2099], {array, flags});
}
Variant ArrayIterator_::offsetExists(const Variant &key) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[166]);
    }
    return this_.call(_method_fn, {key});
}
Variant ArrayIterator_::offsetGet(const Variant &key) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[164]);
    }
    return this_.call(_method_fn, {key});
}
Variant ArrayIterator_::offsetSet(const Variant &key, const Variant &value) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[165]);
    }
    return this_.call(_method_fn, {key, value});
}
Variant ArrayIterator_::offsetUnset(const Variant &key) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[167]);
    }
    return this_.call(_method_fn, {key});
}
Variant ArrayIterator_::append(const Variant &value) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[400]);
    }
    return this_.call(_method_fn, {value});
}
Variant ArrayIterator_::getArrayCopy() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[2087]);
    }
    return this_.call(_method_fn, {});
}
Variant ArrayIterator_::count() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[168]);
    }
    return this_.call(_method_fn, {});
}
Variant ArrayIterator_::getFlags() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[2064]);
    }
    return this_.call(_method_fn, {});
}
Variant ArrayIterator_::setFlags(const Variant &flags) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[2065]);
    }
    return this_.call(_method_fn, {flags});
}
Variant ArrayIterator_::asort(const Variant &flags) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[2088]);
    }
    return this_.call(_method_fn, {flags});
}
Variant ArrayIterator_::ksort(const Variant &flags) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[2089]);
    }
    return this_.call(_method_fn, {flags});
}
Variant ArrayIterator_::uasort(const Variant &callback) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[2090]);
    }
    return this_.call(_method_fn, {callback});
}
Variant ArrayIterator_::uksort(const Variant &callback) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[2091]);
    }
    return this_.call(_method_fn, {callback});
}
Variant ArrayIterator_::natsort() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[2092]);
    }
    return this_.call(_method_fn, {});
}
Variant ArrayIterator_::natcasesort() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[2093]);
    }
    return this_.call(_method_fn, {});
}
Variant ArrayIterator_::unserialize(const Variant &data) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[2094]);
    }
    return this_.call(_method_fn, {data});
}
Variant ArrayIterator_::serialize() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[2095]);
    }
    return this_.call(_method_fn, {});
}
Variant ArrayIterator_::__serialize() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[30]);
    }
    return this_.call(_method_fn, {});
}
Variant ArrayIterator_::__unserialize(const Variant &data) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[31]);
    }
    return this_.call(_method_fn, {data});
}
Variant ArrayIterator_::rewind() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[122]);
    }
    return this_.call(_method_fn, {});
}
Variant ArrayIterator_::current() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[118]);
    }
    return this_.call(_method_fn, {});
}
Variant ArrayIterator_::key() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[119]);
    }
    return this_.call(_method_fn, {});
}
Variant ArrayIterator_::next() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[120]);
    }
    return this_.call(_method_fn, {});
}
Variant ArrayIterator_::valid() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[121]);
    }
    return this_.call(_method_fn, {});
}
Variant ArrayIterator_::seek(const Variant &offset) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[2061]);
    }
    return this_.call(_method_fn, {offset});
}
Variant ArrayIterator_::__debugInfo() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[157]);
    }
    return this_.call(_method_fn, {});
}
AppendIterator::AppendIterator() {
    this_ = newObject(LITERAL_STRING[2069], {});
}
Variant AppendIterator::append(const Variant &iterator) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[400]);
    }
    return this_.call(_method_fn, {iterator});
}
Variant AppendIterator::rewind() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[122]);
    }
    return this_.call(_method_fn, {});
}
Variant AppendIterator::valid() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[121]);
    }
    return this_.call(_method_fn, {});
}
Variant AppendIterator::current() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[118]);
    }
    return this_.call(_method_fn, {});
}
Variant AppendIterator::next() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[120]);
    }
    return this_.call(_method_fn, {});
}
Variant AppendIterator::getIteratorIndex() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[2070]);
    }
    return this_.call(_method_fn, {});
}
Variant AppendIterator::getArrayIterator() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[2071]);
    }
    return this_.call(_method_fn, {});
}
Variant RecursiveArrayIterator::hasChildren() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1867]);
    }
    return this_.call(_method_fn, {});
}
Variant RecursiveArrayIterator::getChildren() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1868]);
    }
    return this_.call(_method_fn, {});
}
RecursiveArrayIterator::RecursiveArrayIterator(const Variant &array, const Variant &flags) {
    this_ = newObject(LITERAL_STRING[2100], {array, flags});
}
SplDoublyLinkedList::SplDoublyLinkedList() {
    this_ = newObject(LITERAL_STRING[2154]);
}
Variant SplDoublyLinkedList::add(const Variant &index, const Variant &value) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[16]);
    }
    return this_.call(_method_fn, {index, value});
}
Variant SplDoublyLinkedList::pop() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[2155]);
    }
    return this_.call(_method_fn, {});
}
Variant SplDoublyLinkedList::shift() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[2156]);
    }
    return this_.call(_method_fn, {});
}
Variant SplDoublyLinkedList::push(const Variant &value) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[2157]);
    }
    return this_.call(_method_fn, {value});
}
Variant SplDoublyLinkedList::unshift(const Variant &value) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[2158]);
    }
    return this_.call(_method_fn, {value});
}
Variant SplDoublyLinkedList::top() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[2159]);
    }
    return this_.call(_method_fn, {});
}
Variant SplDoublyLinkedList::bottom() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[2160]);
    }
    return this_.call(_method_fn, {});
}
Variant SplDoublyLinkedList::__debugInfo() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[157]);
    }
    return this_.call(_method_fn, {});
}
Variant SplDoublyLinkedList::count() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[168]);
    }
    return this_.call(_method_fn, {});
}
Variant SplDoublyLinkedList::isEmpty() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[2161]);
    }
    return this_.call(_method_fn, {});
}
Variant SplDoublyLinkedList::setIteratorMode(const Variant &mode) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[2162]);
    }
    return this_.call(_method_fn, {mode});
}
Variant SplDoublyLinkedList::getIteratorMode() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[2163]);
    }
    return this_.call(_method_fn, {});
}
Variant SplDoublyLinkedList::offsetExists(const Variant &index) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[166]);
    }
    return this_.call(_method_fn, {index});
}
Variant SplDoublyLinkedList::offsetGet(const Variant &index) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[164]);
    }
    return this_.call(_method_fn, {index});
}
Variant SplDoublyLinkedList::offsetSet(const Variant &index, const Variant &value) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[165]);
    }
    return this_.call(_method_fn, {index, value});
}
Variant SplDoublyLinkedList::offsetUnset(const Variant &index) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[167]);
    }
    return this_.call(_method_fn, {index});
}
Variant SplDoublyLinkedList::rewind() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[122]);
    }
    return this_.call(_method_fn, {});
}
Variant SplDoublyLinkedList::current() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[118]);
    }
    return this_.call(_method_fn, {});
}
Variant SplDoublyLinkedList::key() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[119]);
    }
    return this_.call(_method_fn, {});
}
Variant SplDoublyLinkedList::prev() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[2164]);
    }
    return this_.call(_method_fn, {});
}
Variant SplDoublyLinkedList::next() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[120]);
    }
    return this_.call(_method_fn, {});
}
Variant SplDoublyLinkedList::valid() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[121]);
    }
    return this_.call(_method_fn, {});
}
Variant SplDoublyLinkedList::unserialize(const Variant &data) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[2094]);
    }
    return this_.call(_method_fn, {data});
}
Variant SplDoublyLinkedList::serialize() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[2095]);
    }
    return this_.call(_method_fn, {});
}
Variant SplDoublyLinkedList::__serialize() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[30]);
    }
    return this_.call(_method_fn, {});
}
Variant SplDoublyLinkedList::__unserialize(const Variant &data) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[31]);
    }
    return this_.call(_method_fn, {data});
}
SplQueue::SplQueue() {
    this_ = newObject(LITERAL_STRING[2165]);
}
Variant SplQueue::enqueue(const Variant &value) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[2166]);
    }
    return this_.call(_method_fn, {value});
}
Variant SplQueue::dequeue() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[2167]);
    }
    return this_.call(_method_fn, {});
}
SplStack::SplStack() {
    this_ = newObject(LITERAL_STRING[2168]);
}
SplMinHeap::SplMinHeap() {
    this_ = newObject(LITERAL_STRING[2169]);
}
Variant SplMinHeap::extract() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[2170]);
    }
    return this_.call(_method_fn, {});
}
Variant SplMinHeap::insert(const Variant &value) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[2171]);
    }
    return this_.call(_method_fn, {value});
}
Variant SplMinHeap::top() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[2159]);
    }
    return this_.call(_method_fn, {});
}
Variant SplMinHeap::count() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[168]);
    }
    return this_.call(_method_fn, {});
}
Variant SplMinHeap::isEmpty() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[2161]);
    }
    return this_.call(_method_fn, {});
}
Variant SplMinHeap::rewind() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[122]);
    }
    return this_.call(_method_fn, {});
}
Variant SplMinHeap::current() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[118]);
    }
    return this_.call(_method_fn, {});
}
Variant SplMinHeap::key() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[119]);
    }
    return this_.call(_method_fn, {});
}
Variant SplMinHeap::next() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[120]);
    }
    return this_.call(_method_fn, {});
}
Variant SplMinHeap::valid() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[121]);
    }
    return this_.call(_method_fn, {});
}
Variant SplMinHeap::recoverFromCorruption() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[2172]);
    }
    return this_.call(_method_fn, {});
}
Variant SplMinHeap::isCorrupted() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[2173]);
    }
    return this_.call(_method_fn, {});
}
Variant SplMinHeap::__debugInfo() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[157]);
    }
    return this_.call(_method_fn, {});
}
SplMaxHeap::SplMaxHeap() {
    this_ = newObject(LITERAL_STRING[2174]);
}
Variant SplMaxHeap::extract() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[2170]);
    }
    return this_.call(_method_fn, {});
}
Variant SplMaxHeap::insert(const Variant &value) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[2171]);
    }
    return this_.call(_method_fn, {value});
}
Variant SplMaxHeap::top() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[2159]);
    }
    return this_.call(_method_fn, {});
}
Variant SplMaxHeap::count() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[168]);
    }
    return this_.call(_method_fn, {});
}
Variant SplMaxHeap::isEmpty() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[2161]);
    }
    return this_.call(_method_fn, {});
}
Variant SplMaxHeap::rewind() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[122]);
    }
    return this_.call(_method_fn, {});
}
Variant SplMaxHeap::current() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[118]);
    }
    return this_.call(_method_fn, {});
}
Variant SplMaxHeap::key() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[119]);
    }
    return this_.call(_method_fn, {});
}
Variant SplMaxHeap::next() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[120]);
    }
    return this_.call(_method_fn, {});
}
Variant SplMaxHeap::valid() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[121]);
    }
    return this_.call(_method_fn, {});
}
Variant SplMaxHeap::recoverFromCorruption() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[2172]);
    }
    return this_.call(_method_fn, {});
}
Variant SplMaxHeap::isCorrupted() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[2173]);
    }
    return this_.call(_method_fn, {});
}
Variant SplMaxHeap::__debugInfo() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[157]);
    }
    return this_.call(_method_fn, {});
}
SplPriorityQueue::SplPriorityQueue() {
    this_ = newObject(LITERAL_STRING[2175]);
}
Variant SplPriorityQueue::compare(const Variant &priority1, const Variant &priority2) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[28]);
    }
    return this_.call(_method_fn, {priority1, priority2});
}
Variant SplPriorityQueue::insert(const Variant &value, const Variant &priority) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[2171]);
    }
    return this_.call(_method_fn, {value, priority});
}
Variant SplPriorityQueue::setExtractFlags(const Variant &flags) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[2176]);
    }
    return this_.call(_method_fn, {flags});
}
Variant SplPriorityQueue::top() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[2159]);
    }
    return this_.call(_method_fn, {});
}
Variant SplPriorityQueue::extract() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[2170]);
    }
    return this_.call(_method_fn, {});
}
Variant SplPriorityQueue::count() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[168]);
    }
    return this_.call(_method_fn, {});
}
Variant SplPriorityQueue::isEmpty() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[2161]);
    }
    return this_.call(_method_fn, {});
}
Variant SplPriorityQueue::rewind() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[122]);
    }
    return this_.call(_method_fn, {});
}
Variant SplPriorityQueue::current() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[118]);
    }
    return this_.call(_method_fn, {});
}
Variant SplPriorityQueue::key() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[119]);
    }
    return this_.call(_method_fn, {});
}
Variant SplPriorityQueue::next() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[120]);
    }
    return this_.call(_method_fn, {});
}
Variant SplPriorityQueue::valid() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[121]);
    }
    return this_.call(_method_fn, {});
}
Variant SplPriorityQueue::recoverFromCorruption() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[2172]);
    }
    return this_.call(_method_fn, {});
}
Variant SplPriorityQueue::isCorrupted() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[2173]);
    }
    return this_.call(_method_fn, {});
}
Variant SplPriorityQueue::getExtractFlags() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[2177]);
    }
    return this_.call(_method_fn, {});
}
Variant SplPriorityQueue::__debugInfo() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[157]);
    }
    return this_.call(_method_fn, {});
}
SplFixedArray::SplFixedArray(const Variant &size) {
    this_ = newObject(LITERAL_STRING[2178], {size});
}
Variant SplFixedArray::__wakeup() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[125]);
    }
    return this_.call(_method_fn, {});
}
Variant SplFixedArray::__serialize() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[30]);
    }
    return this_.call(_method_fn, {});
}
Variant SplFixedArray::__unserialize(const Variant &data) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[31]);
    }
    return this_.call(_method_fn, {data});
}
Variant SplFixedArray::count() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[168]);
    }
    return this_.call(_method_fn, {});
}
Variant SplFixedArray::toArray() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[2179]);
    }
    return this_.call(_method_fn, {});
}
Variant SplFixedArray::fromArray(const Variant &array, const Variant &preserve_keys) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(LITERAL_STRING[2178], LITERAL_STRING[2181]);
    }
    return php::call(_method_fn, {array, preserve_keys});
}
Variant SplFixedArray::getSize() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[2106]);
    }
    return this_.call(_method_fn, {});
}
Variant SplFixedArray::setSize(const Variant &size) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[2182]);
    }
    return this_.call(_method_fn, {size});
}
Variant SplFixedArray::offsetExists(const Variant &index) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[166]);
    }
    return this_.call(_method_fn, {index});
}
Variant SplFixedArray::offsetGet(const Variant &index) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[164]);
    }
    return this_.call(_method_fn, {index});
}
Variant SplFixedArray::offsetSet(const Variant &index, const Variant &value) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[165]);
    }
    return this_.call(_method_fn, {index, value});
}
Variant SplFixedArray::offsetUnset(const Variant &index) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[167]);
    }
    return this_.call(_method_fn, {index});
}
Variant SplFixedArray::getIterator() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[169]);
    }
    return this_.call(_method_fn, {});
}
Variant SplFixedArray::jsonSerialize() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[2183]);
    }
    return this_.call(_method_fn, {});
}
SplObjectStorage::SplObjectStorage() {
    this_ = newObject(LITERAL_STRING[2184]);
}
Variant SplObjectStorage::attach(const Variant &object, const Variant &info) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[2185]);
    }
    return this_.call(_method_fn, {object, info});
}
Variant SplObjectStorage::detach(const Variant &object) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[2186]);
    }
    return this_.call(_method_fn, {object});
}
Variant SplObjectStorage::contains(const Variant &object) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[392]);
    }
    return this_.call(_method_fn, {object});
}
Variant SplObjectStorage::addAll(const SplObjectStorage &storage) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[2187]);
    }
    return this_.call(_method_fn, {storage.getObject()});
}
Variant SplObjectStorage::addAll(const Variant &storage) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[2187]);
    }
    return this_.call(_method_fn, {storage});
}
Variant SplObjectStorage::removeAll(const SplObjectStorage &storage) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[2188]);
    }
    return this_.call(_method_fn, {storage.getObject()});
}
Variant SplObjectStorage::removeAll(const Variant &storage) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[2188]);
    }
    return this_.call(_method_fn, {storage});
}
Variant SplObjectStorage::removeAllExcept(const SplObjectStorage &storage) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[2189]);
    }
    return this_.call(_method_fn, {storage.getObject()});
}
Variant SplObjectStorage::removeAllExcept(const Variant &storage) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[2189]);
    }
    return this_.call(_method_fn, {storage});
}
Variant SplObjectStorage::getInfo() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[2190]);
    }
    return this_.call(_method_fn, {});
}
Variant SplObjectStorage::setInfo(const Variant &info) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[2191]);
    }
    return this_.call(_method_fn, {info});
}
Variant SplObjectStorage::count(const Variant &mode) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[168]);
    }
    return this_.call(_method_fn, {mode});
}
Variant SplObjectStorage::rewind() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[122]);
    }
    return this_.call(_method_fn, {});
}
Variant SplObjectStorage::valid() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[121]);
    }
    return this_.call(_method_fn, {});
}
Variant SplObjectStorage::key() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[119]);
    }
    return this_.call(_method_fn, {});
}
Variant SplObjectStorage::current() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[118]);
    }
    return this_.call(_method_fn, {});
}
Variant SplObjectStorage::next() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[120]);
    }
    return this_.call(_method_fn, {});
}
Variant SplObjectStorage::seek(const Variant &offset) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[2061]);
    }
    return this_.call(_method_fn, {offset});
}
Variant SplObjectStorage::unserialize(const Variant &data) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[2094]);
    }
    return this_.call(_method_fn, {data});
}
Variant SplObjectStorage::serialize() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[2095]);
    }
    return this_.call(_method_fn, {});
}
Variant SplObjectStorage::offsetExists(const Variant &object) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[166]);
    }
    return this_.call(_method_fn, {object});
}
Variant SplObjectStorage::offsetGet(const Variant &object) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[164]);
    }
    return this_.call(_method_fn, {object});
}
Variant SplObjectStorage::offsetSet(const Variant &object, const Variant &info) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[165]);
    }
    return this_.call(_method_fn, {object, info});
}
Variant SplObjectStorage::offsetUnset(const Variant &object) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[167]);
    }
    return this_.call(_method_fn, {object});
}
Variant SplObjectStorage::getHash(const Variant &object) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[2192]);
    }
    return this_.call(_method_fn, {object});
}
Variant SplObjectStorage::__serialize() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[30]);
    }
    return this_.call(_method_fn, {});
}
Variant SplObjectStorage::__unserialize(const Variant &data) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[31]);
    }
    return this_.call(_method_fn, {data});
}
Variant SplObjectStorage::__debugInfo() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[157]);
    }
    return this_.call(_method_fn, {});
}
MultipleIterator::MultipleIterator(const Variant &flags) {
    this_ = newObject(LITERAL_STRING[2193], {flags});
}
Variant MultipleIterator::getFlags() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[2064]);
    }
    return this_.call(_method_fn, {});
}
Variant MultipleIterator::setFlags(const Variant &flags) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[2065]);
    }
    return this_.call(_method_fn, {flags});
}
Variant MultipleIterator::attachIterator(const Variant &iterator, const Variant &info) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[2194]);
    }
    return this_.call(_method_fn, {iterator, info});
}
Variant MultipleIterator::detachIterator(const Variant &iterator) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[2195]);
    }
    return this_.call(_method_fn, {iterator});
}
Variant MultipleIterator::containsIterator(const Variant &iterator) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[2196]);
    }
    return this_.call(_method_fn, {iterator});
}
Variant MultipleIterator::countIterators() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[2197]);
    }
    return this_.call(_method_fn, {});
}
Variant MultipleIterator::rewind() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[122]);
    }
    return this_.call(_method_fn, {});
}
Variant MultipleIterator::valid() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[121]);
    }
    return this_.call(_method_fn, {});
}
Variant MultipleIterator::key() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[119]);
    }
    return this_.call(_method_fn, {});
}
Variant MultipleIterator::current() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[118]);
    }
    return this_.call(_method_fn, {});
}
Variant MultipleIterator::next() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[120]);
    }
    return this_.call(_method_fn, {});
}
Variant MultipleIterator::__debugInfo() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[157]);
    }
    return this_.call(_method_fn, {});
}
SplFileInfo::SplFileInfo(const Variant &filename) {
    this_ = newObject(LITERAL_STRING[2101], {filename});
}
Variant SplFileInfo::getPath() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1124]);
    }
    return this_.call(_method_fn, {});
}
Variant SplFileInfo::getFilename() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[239]);
    }
    return this_.call(_method_fn, {});
}
Variant SplFileInfo::getExtension() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1653]);
    }
    return this_.call(_method_fn, {});
}
Variant SplFileInfo::getBasename(const Variant &suffix) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[2102]);
    }
    return this_.call(_method_fn, {suffix});
}
Variant SplFileInfo::getPathname() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[2103]);
    }
    return this_.call(_method_fn, {});
}
Variant SplFileInfo::getPerms() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[2104]);
    }
    return this_.call(_method_fn, {});
}
Variant SplFileInfo::getInode() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[2105]);
    }
    return this_.call(_method_fn, {});
}
Variant SplFileInfo::getSize() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[2106]);
    }
    return this_.call(_method_fn, {});
}
Variant SplFileInfo::getOwner() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[2107]);
    }
    return this_.call(_method_fn, {});
}
Variant SplFileInfo::getGroup() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[2108]);
    }
    return this_.call(_method_fn, {});
}
Variant SplFileInfo::getATime() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[2109]);
    }
    return this_.call(_method_fn, {});
}
Variant SplFileInfo::getMTime() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[2110]);
    }
    return this_.call(_method_fn, {});
}
Variant SplFileInfo::getCTime() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[2111]);
    }
    return this_.call(_method_fn, {});
}
Variant SplFileInfo::getType() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1683]);
    }
    return this_.call(_method_fn, {});
}
Variant SplFileInfo::isWritable() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1134]);
    }
    return this_.call(_method_fn, {});
}
Variant SplFileInfo::isReadable() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[2112]);
    }
    return this_.call(_method_fn, {});
}
Variant SplFileInfo::isExecutable() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[2113]);
    }
    return this_.call(_method_fn, {});
}
Variant SplFileInfo::isFile() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[2114]);
    }
    return this_.call(_method_fn, {});
}
Variant SplFileInfo::isDir() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[2115]);
    }
    return this_.call(_method_fn, {});
}
Variant SplFileInfo::isLink() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[2116]);
    }
    return this_.call(_method_fn, {});
}
Variant SplFileInfo::getLinkTarget() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[2117]);
    }
    return this_.call(_method_fn, {});
}
Variant SplFileInfo::getRealPath() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[2118]);
    }
    return this_.call(_method_fn, {});
}
Variant SplFileInfo::getFileInfo(const Variant &class_) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[2119]);
    }
    return this_.call(_method_fn, {class_});
}
Variant SplFileInfo::getPathInfo(const Variant &class_) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[2120]);
    }
    return this_.call(_method_fn, {class_});
}
Variant SplFileInfo::openFile(const Variant &mode, const Variant &use_include_path, const Variant &context) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[2121]);
    }
    return this_.call(_method_fn, {mode, use_include_path, context});
}
Variant SplFileInfo::setFileClass(const Variant &class_) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[2122]);
    }
    return this_.call(_method_fn, {class_});
}
Variant SplFileInfo::setInfoClass(const Variant &class_) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[2123]);
    }
    return this_.call(_method_fn, {class_});
}
Variant SplFileInfo::__toString() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[29]);
    }
    return this_.call(_method_fn, {});
}
Variant SplFileInfo::__debugInfo() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[157]);
    }
    return this_.call(_method_fn, {});
}
Variant SplFileInfo::_bad_state_ex() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[2124]);
    }
    return this_.call(_method_fn, {});
}
SplFileObject::SplFileObject(const Variant &filename,
                             const Variant &mode,
                             const Variant &use_include_path,
                             const Variant &context) {
    this_ = newObject(LITERAL_STRING[2132], {filename, mode, use_include_path, context});
}
Variant SplFileObject::rewind() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[122]);
    }
    return this_.call(_method_fn, {});
}
Variant SplFileObject::eof() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[2133]);
    }
    return this_.call(_method_fn, {});
}
Variant SplFileObject::valid() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[121]);
    }
    return this_.call(_method_fn, {});
}
Variant SplFileObject::fgets() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[2134]);
    }
    return this_.call(_method_fn, {});
}
Variant SplFileObject::fread(const Variant &length) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[2135]);
    }
    return this_.call(_method_fn, {length});
}
Variant SplFileObject::fgetcsv(const Variant &separator, const Variant &enclosure, const Variant &escape) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[2136]);
    }
    return this_.call(_method_fn, {separator, enclosure, escape});
}
Variant SplFileObject::fputcsv(const Variant &fields,
                               const Variant &separator,
                               const Variant &enclosure,
                               const Variant &escape,
                               const Variant &eol) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[2137]);
    }
    return this_.call(_method_fn, {fields, separator, enclosure, escape, eol});
}
Variant SplFileObject::setCsvControl(const Variant &separator, const Variant &enclosure, const Variant &escape) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[2138]);
    }
    return this_.call(_method_fn, {separator, enclosure, escape});
}
Variant SplFileObject::getCsvControl() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[2139]);
    }
    return this_.call(_method_fn, {});
}
Variant SplFileObject::flock(const Variant &operation, const Reference &would_block) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[2140]);
    }
    return this_.call(_method_fn, {operation, &would_block});
}
Variant SplFileObject::fflush() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[2141]);
    }
    return this_.call(_method_fn, {});
}
Variant SplFileObject::ftell() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[2142]);
    }
    return this_.call(_method_fn, {});
}
Variant SplFileObject::fseek(const Variant &offset, const Variant &whence) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[2143]);
    }
    return this_.call(_method_fn, {offset, whence});
}
Variant SplFileObject::fgetc() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[2144]);
    }
    return this_.call(_method_fn, {});
}
Variant SplFileObject::fpassthru() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[2145]);
    }
    return this_.call(_method_fn, {});
}
Variant SplFileObject::fwrite(const Variant &data, const Variant &length) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[2147]);
    }
    return this_.call(_method_fn, {data, length});
}
Variant SplFileObject::fstat() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[2148]);
    }
    return this_.call(_method_fn, {});
}
Variant SplFileObject::ftruncate(const Variant &size) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[2149]);
    }
    return this_.call(_method_fn, {size});
}
Variant SplFileObject::current() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[118]);
    }
    return this_.call(_method_fn, {});
}
Variant SplFileObject::key() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[119]);
    }
    return this_.call(_method_fn, {});
}
Variant SplFileObject::next() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[120]);
    }
    return this_.call(_method_fn, {});
}
Variant SplFileObject::setFlags(const Variant &flags) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[2065]);
    }
    return this_.call(_method_fn, {flags});
}
Variant SplFileObject::getFlags() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[2064]);
    }
    return this_.call(_method_fn, {});
}
Variant SplFileObject::setMaxLineLen(const Variant &max_length) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[2150]);
    }
    return this_.call(_method_fn, {max_length});
}
Variant SplFileObject::getMaxLineLen() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[2151]);
    }
    return this_.call(_method_fn, {});
}
Variant SplFileObject::hasChildren() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1867]);
    }
    return this_.call(_method_fn, {});
}
Variant SplFileObject::getChildren() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1868]);
    }
    return this_.call(_method_fn, {});
}
Variant SplFileObject::seek(const Variant &line) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[2061]);
    }
    return this_.call(_method_fn, {line});
}
Variant SplFileObject::getCurrentLine() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[2152]);
    }
    return this_.call(_method_fn, {});
}
Variant SplFileObject::__toString() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[29]);
    }
    return this_.call(_method_fn, {});
}
DirectoryIterator::DirectoryIterator(const Variant &directory) {
    this_ = newObject(LITERAL_STRING[2125], {directory});
}
Variant DirectoryIterator::getFilename() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[239]);
    }
    return this_.call(_method_fn, {});
}
Variant DirectoryIterator::getExtension() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1653]);
    }
    return this_.call(_method_fn, {});
}
Variant DirectoryIterator::getBasename(const Variant &suffix) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[2102]);
    }
    return this_.call(_method_fn, {suffix});
}
Variant DirectoryIterator::isDot() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[2126]);
    }
    return this_.call(_method_fn, {});
}
Variant DirectoryIterator::rewind() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[122]);
    }
    return this_.call(_method_fn, {});
}
Variant DirectoryIterator::valid() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[121]);
    }
    return this_.call(_method_fn, {});
}
Variant DirectoryIterator::key() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[119]);
    }
    return this_.call(_method_fn, {});
}
Variant DirectoryIterator::current() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[118]);
    }
    return this_.call(_method_fn, {});
}
Variant DirectoryIterator::next() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[120]);
    }
    return this_.call(_method_fn, {});
}
Variant DirectoryIterator::seek(const Variant &offset) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[2061]);
    }
    return this_.call(_method_fn, {offset});
}
Variant DirectoryIterator::__toString() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[29]);
    }
    return this_.call(_method_fn, {});
}
FilesystemIterator::FilesystemIterator(const Variant &directory, const Variant &flags) {
    this_ = newObject(LITERAL_STRING[2127], {directory, flags});
}
Variant FilesystemIterator::rewind() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[122]);
    }
    return this_.call(_method_fn, {});
}
Variant FilesystemIterator::key() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[119]);
    }
    return this_.call(_method_fn, {});
}
Variant FilesystemIterator::current() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[118]);
    }
    return this_.call(_method_fn, {});
}
Variant FilesystemIterator::getFlags() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[2064]);
    }
    return this_.call(_method_fn, {});
}
Variant FilesystemIterator::setFlags(const Variant &flags) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[2065]);
    }
    return this_.call(_method_fn, {flags});
}
RecursiveDirectoryIterator::RecursiveDirectoryIterator(const Variant &directory, const Variant &flags) {
    this_ = newObject(LITERAL_STRING[2128], {directory, flags});
}
Variant RecursiveDirectoryIterator::hasChildren(const Variant &allow_links) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1867]);
    }
    return this_.call(_method_fn, {allow_links});
}
Variant RecursiveDirectoryIterator::getChildren() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1868]);
    }
    return this_.call(_method_fn, {});
}
Variant RecursiveDirectoryIterator::getSubPath() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[2129]);
    }
    return this_.call(_method_fn, {});
}
Variant RecursiveDirectoryIterator::getSubPathname() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[2130]);
    }
    return this_.call(_method_fn, {});
}
GlobIterator::GlobIterator(const Variant &pattern, const Variant &flags) {
    this_ = newObject(LITERAL_STRING[2131], {pattern, flags});
}
Variant GlobIterator::count() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[168]);
    }
    return this_.call(_method_fn, {});
}
SplTempFileObject::SplTempFileObject(const Variant &max_memory) {
    this_ = newObject(LITERAL_STRING[2153], {max_memory});
}
}  // namespace php

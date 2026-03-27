#include "phpx.h"
#include "class/spl.h"

namespace php {
LogicException::LogicException(const Variant &message, const Variant &code, const Variant &previous) {
    this_ = newObject(LITERAL_STRING[1687], {message, code, previous});
}
Variant LogicException::__wakeup() {
    return this_.call(LITERAL_STRING[97], {});
}
Variant LogicException::getMessage() {
    return this_.call(LITERAL_STRING[98], {});
}
Variant LogicException::getCode() {
    return this_.call(LITERAL_STRING[99], {});
}
Variant LogicException::getFile() {
    return this_.call(LITERAL_STRING[100], {});
}
Variant LogicException::getLine() {
    return this_.call(LITERAL_STRING[101], {});
}
Variant LogicException::getTrace() {
    return this_.call(LITERAL_STRING[102], {});
}
Variant LogicException::getPrevious() {
    return this_.call(LITERAL_STRING[103], {});
}
Variant LogicException::getTraceAsString() {
    return this_.call(LITERAL_STRING[104], {});
}
Variant LogicException::__toString() {
    return this_.call(LITERAL_STRING[29], {});
}
BadFunctionCallException::BadFunctionCallException(const Variant &message,
                                                   const Variant &code,
                                                   const Variant &previous) {
    this_ = newObject(LITERAL_STRING[1688], {message, code, previous});
}
Variant BadFunctionCallException::__wakeup() {
    return this_.call(LITERAL_STRING[97], {});
}
Variant BadFunctionCallException::getMessage() {
    return this_.call(LITERAL_STRING[98], {});
}
Variant BadFunctionCallException::getCode() {
    return this_.call(LITERAL_STRING[99], {});
}
Variant BadFunctionCallException::getFile() {
    return this_.call(LITERAL_STRING[100], {});
}
Variant BadFunctionCallException::getLine() {
    return this_.call(LITERAL_STRING[101], {});
}
Variant BadFunctionCallException::getTrace() {
    return this_.call(LITERAL_STRING[102], {});
}
Variant BadFunctionCallException::getPrevious() {
    return this_.call(LITERAL_STRING[103], {});
}
Variant BadFunctionCallException::getTraceAsString() {
    return this_.call(LITERAL_STRING[104], {});
}
Variant BadFunctionCallException::__toString() {
    return this_.call(LITERAL_STRING[29], {});
}
BadMethodCallException::BadMethodCallException(const Variant &message, const Variant &code, const Variant &previous) {
    this_ = newObject(LITERAL_STRING[1689], {message, code, previous});
}
Variant BadMethodCallException::__wakeup() {
    return this_.call(LITERAL_STRING[97], {});
}
Variant BadMethodCallException::getMessage() {
    return this_.call(LITERAL_STRING[98], {});
}
Variant BadMethodCallException::getCode() {
    return this_.call(LITERAL_STRING[99], {});
}
Variant BadMethodCallException::getFile() {
    return this_.call(LITERAL_STRING[100], {});
}
Variant BadMethodCallException::getLine() {
    return this_.call(LITERAL_STRING[101], {});
}
Variant BadMethodCallException::getTrace() {
    return this_.call(LITERAL_STRING[102], {});
}
Variant BadMethodCallException::getPrevious() {
    return this_.call(LITERAL_STRING[103], {});
}
Variant BadMethodCallException::getTraceAsString() {
    return this_.call(LITERAL_STRING[104], {});
}
Variant BadMethodCallException::__toString() {
    return this_.call(LITERAL_STRING[29], {});
}
DomainException::DomainException(const Variant &message, const Variant &code, const Variant &previous) {
    this_ = newObject(LITERAL_STRING[1690], {message, code, previous});
}
Variant DomainException::__wakeup() {
    return this_.call(LITERAL_STRING[97], {});
}
Variant DomainException::getMessage() {
    return this_.call(LITERAL_STRING[98], {});
}
Variant DomainException::getCode() {
    return this_.call(LITERAL_STRING[99], {});
}
Variant DomainException::getFile() {
    return this_.call(LITERAL_STRING[100], {});
}
Variant DomainException::getLine() {
    return this_.call(LITERAL_STRING[101], {});
}
Variant DomainException::getTrace() {
    return this_.call(LITERAL_STRING[102], {});
}
Variant DomainException::getPrevious() {
    return this_.call(LITERAL_STRING[103], {});
}
Variant DomainException::getTraceAsString() {
    return this_.call(LITERAL_STRING[104], {});
}
Variant DomainException::__toString() {
    return this_.call(LITERAL_STRING[29], {});
}
InvalidArgumentException::InvalidArgumentException(const Variant &message,
                                                   const Variant &code,
                                                   const Variant &previous) {
    this_ = newObject(LITERAL_STRING[1691], {message, code, previous});
}
Variant InvalidArgumentException::__wakeup() {
    return this_.call(LITERAL_STRING[97], {});
}
Variant InvalidArgumentException::getMessage() {
    return this_.call(LITERAL_STRING[98], {});
}
Variant InvalidArgumentException::getCode() {
    return this_.call(LITERAL_STRING[99], {});
}
Variant InvalidArgumentException::getFile() {
    return this_.call(LITERAL_STRING[100], {});
}
Variant InvalidArgumentException::getLine() {
    return this_.call(LITERAL_STRING[101], {});
}
Variant InvalidArgumentException::getTrace() {
    return this_.call(LITERAL_STRING[102], {});
}
Variant InvalidArgumentException::getPrevious() {
    return this_.call(LITERAL_STRING[103], {});
}
Variant InvalidArgumentException::getTraceAsString() {
    return this_.call(LITERAL_STRING[104], {});
}
Variant InvalidArgumentException::__toString() {
    return this_.call(LITERAL_STRING[29], {});
}
LengthException::LengthException(const Variant &message, const Variant &code, const Variant &previous) {
    this_ = newObject(LITERAL_STRING[1692], {message, code, previous});
}
Variant LengthException::__wakeup() {
    return this_.call(LITERAL_STRING[97], {});
}
Variant LengthException::getMessage() {
    return this_.call(LITERAL_STRING[98], {});
}
Variant LengthException::getCode() {
    return this_.call(LITERAL_STRING[99], {});
}
Variant LengthException::getFile() {
    return this_.call(LITERAL_STRING[100], {});
}
Variant LengthException::getLine() {
    return this_.call(LITERAL_STRING[101], {});
}
Variant LengthException::getTrace() {
    return this_.call(LITERAL_STRING[102], {});
}
Variant LengthException::getPrevious() {
    return this_.call(LITERAL_STRING[103], {});
}
Variant LengthException::getTraceAsString() {
    return this_.call(LITERAL_STRING[104], {});
}
Variant LengthException::__toString() {
    return this_.call(LITERAL_STRING[29], {});
}
OutOfRangeException::OutOfRangeException(const Variant &message, const Variant &code, const Variant &previous) {
    this_ = newObject(LITERAL_STRING[1693], {message, code, previous});
}
Variant OutOfRangeException::__wakeup() {
    return this_.call(LITERAL_STRING[97], {});
}
Variant OutOfRangeException::getMessage() {
    return this_.call(LITERAL_STRING[98], {});
}
Variant OutOfRangeException::getCode() {
    return this_.call(LITERAL_STRING[99], {});
}
Variant OutOfRangeException::getFile() {
    return this_.call(LITERAL_STRING[100], {});
}
Variant OutOfRangeException::getLine() {
    return this_.call(LITERAL_STRING[101], {});
}
Variant OutOfRangeException::getTrace() {
    return this_.call(LITERAL_STRING[102], {});
}
Variant OutOfRangeException::getPrevious() {
    return this_.call(LITERAL_STRING[103], {});
}
Variant OutOfRangeException::getTraceAsString() {
    return this_.call(LITERAL_STRING[104], {});
}
Variant OutOfRangeException::__toString() {
    return this_.call(LITERAL_STRING[29], {});
}
RuntimeException::RuntimeException(const Variant &message, const Variant &code, const Variant &previous) {
    this_ = newObject(LITERAL_STRING[1694], {message, code, previous});
}
Variant RuntimeException::__wakeup() {
    return this_.call(LITERAL_STRING[97], {});
}
Variant RuntimeException::getMessage() {
    return this_.call(LITERAL_STRING[98], {});
}
Variant RuntimeException::getCode() {
    return this_.call(LITERAL_STRING[99], {});
}
Variant RuntimeException::getFile() {
    return this_.call(LITERAL_STRING[100], {});
}
Variant RuntimeException::getLine() {
    return this_.call(LITERAL_STRING[101], {});
}
Variant RuntimeException::getTrace() {
    return this_.call(LITERAL_STRING[102], {});
}
Variant RuntimeException::getPrevious() {
    return this_.call(LITERAL_STRING[103], {});
}
Variant RuntimeException::getTraceAsString() {
    return this_.call(LITERAL_STRING[104], {});
}
Variant RuntimeException::__toString() {
    return this_.call(LITERAL_STRING[29], {});
}
OutOfBoundsException::OutOfBoundsException(const Variant &message, const Variant &code, const Variant &previous) {
    this_ = newObject(LITERAL_STRING[1695], {message, code, previous});
}
Variant OutOfBoundsException::__wakeup() {
    return this_.call(LITERAL_STRING[97], {});
}
Variant OutOfBoundsException::getMessage() {
    return this_.call(LITERAL_STRING[98], {});
}
Variant OutOfBoundsException::getCode() {
    return this_.call(LITERAL_STRING[99], {});
}
Variant OutOfBoundsException::getFile() {
    return this_.call(LITERAL_STRING[100], {});
}
Variant OutOfBoundsException::getLine() {
    return this_.call(LITERAL_STRING[101], {});
}
Variant OutOfBoundsException::getTrace() {
    return this_.call(LITERAL_STRING[102], {});
}
Variant OutOfBoundsException::getPrevious() {
    return this_.call(LITERAL_STRING[103], {});
}
Variant OutOfBoundsException::getTraceAsString() {
    return this_.call(LITERAL_STRING[104], {});
}
Variant OutOfBoundsException::__toString() {
    return this_.call(LITERAL_STRING[29], {});
}
OverflowException::OverflowException(const Variant &message, const Variant &code, const Variant &previous) {
    this_ = newObject(LITERAL_STRING[1696], {message, code, previous});
}
Variant OverflowException::__wakeup() {
    return this_.call(LITERAL_STRING[97], {});
}
Variant OverflowException::getMessage() {
    return this_.call(LITERAL_STRING[98], {});
}
Variant OverflowException::getCode() {
    return this_.call(LITERAL_STRING[99], {});
}
Variant OverflowException::getFile() {
    return this_.call(LITERAL_STRING[100], {});
}
Variant OverflowException::getLine() {
    return this_.call(LITERAL_STRING[101], {});
}
Variant OverflowException::getTrace() {
    return this_.call(LITERAL_STRING[102], {});
}
Variant OverflowException::getPrevious() {
    return this_.call(LITERAL_STRING[103], {});
}
Variant OverflowException::getTraceAsString() {
    return this_.call(LITERAL_STRING[104], {});
}
Variant OverflowException::__toString() {
    return this_.call(LITERAL_STRING[29], {});
}
RangeException::RangeException(const Variant &message, const Variant &code, const Variant &previous) {
    this_ = newObject(LITERAL_STRING[1697], {message, code, previous});
}
Variant RangeException::__wakeup() {
    return this_.call(LITERAL_STRING[97], {});
}
Variant RangeException::getMessage() {
    return this_.call(LITERAL_STRING[98], {});
}
Variant RangeException::getCode() {
    return this_.call(LITERAL_STRING[99], {});
}
Variant RangeException::getFile() {
    return this_.call(LITERAL_STRING[100], {});
}
Variant RangeException::getLine() {
    return this_.call(LITERAL_STRING[101], {});
}
Variant RangeException::getTrace() {
    return this_.call(LITERAL_STRING[102], {});
}
Variant RangeException::getPrevious() {
    return this_.call(LITERAL_STRING[103], {});
}
Variant RangeException::getTraceAsString() {
    return this_.call(LITERAL_STRING[104], {});
}
Variant RangeException::__toString() {
    return this_.call(LITERAL_STRING[29], {});
}
UnderflowException::UnderflowException(const Variant &message, const Variant &code, const Variant &previous) {
    this_ = newObject(LITERAL_STRING[1698], {message, code, previous});
}
Variant UnderflowException::__wakeup() {
    return this_.call(LITERAL_STRING[97], {});
}
Variant UnderflowException::getMessage() {
    return this_.call(LITERAL_STRING[98], {});
}
Variant UnderflowException::getCode() {
    return this_.call(LITERAL_STRING[99], {});
}
Variant UnderflowException::getFile() {
    return this_.call(LITERAL_STRING[100], {});
}
Variant UnderflowException::getLine() {
    return this_.call(LITERAL_STRING[101], {});
}
Variant UnderflowException::getTrace() {
    return this_.call(LITERAL_STRING[102], {});
}
Variant UnderflowException::getPrevious() {
    return this_.call(LITERAL_STRING[103], {});
}
Variant UnderflowException::getTraceAsString() {
    return this_.call(LITERAL_STRING[104], {});
}
Variant UnderflowException::__toString() {
    return this_.call(LITERAL_STRING[29], {});
}
UnexpectedValueException::UnexpectedValueException(const Variant &message,
                                                   const Variant &code,
                                                   const Variant &previous) {
    this_ = newObject(LITERAL_STRING[1699], {message, code, previous});
}
Variant UnexpectedValueException::__wakeup() {
    return this_.call(LITERAL_STRING[97], {});
}
Variant UnexpectedValueException::getMessage() {
    return this_.call(LITERAL_STRING[98], {});
}
Variant UnexpectedValueException::getCode() {
    return this_.call(LITERAL_STRING[99], {});
}
Variant UnexpectedValueException::getFile() {
    return this_.call(LITERAL_STRING[100], {});
}
Variant UnexpectedValueException::getLine() {
    return this_.call(LITERAL_STRING[101], {});
}
Variant UnexpectedValueException::getTrace() {
    return this_.call(LITERAL_STRING[102], {});
}
Variant UnexpectedValueException::getPrevious() {
    return this_.call(LITERAL_STRING[103], {});
}
Variant UnexpectedValueException::getTraceAsString() {
    return this_.call(LITERAL_STRING[104], {});
}
Variant UnexpectedValueException::__toString() {
    return this_.call(LITERAL_STRING[29], {});
}
RecursiveIteratorIterator::RecursiveIteratorIterator(const Variant &iterator,
                                                     const Variant &mode,
                                                     const Variant &flags) {
    this_ = newObject(LITERAL_STRING[1700], {iterator, mode, flags});
}
Variant RecursiveIteratorIterator::rewind() {
    return this_.call(LITERAL_STRING[94], {});
}
Variant RecursiveIteratorIterator::valid() {
    return this_.call(LITERAL_STRING[93], {});
}
Variant RecursiveIteratorIterator::key() {
    return this_.call(LITERAL_STRING[91], {});
}
Variant RecursiveIteratorIterator::current() {
    return this_.call(LITERAL_STRING[90], {});
}
Variant RecursiveIteratorIterator::next() {
    return this_.call(LITERAL_STRING[92], {});
}
Variant RecursiveIteratorIterator::getDepth() {
    return this_.call(LITERAL_STRING[1701], {});
}
Variant RecursiveIteratorIterator::getSubIterator(const Variant &level) {
    return this_.call(LITERAL_STRING[1702], {level});
}
Variant RecursiveIteratorIterator::getInnerIterator() {
    return this_.call(LITERAL_STRING[1703], {});
}
Variant RecursiveIteratorIterator::beginIteration() {
    return this_.call(LITERAL_STRING[1704], {});
}
Variant RecursiveIteratorIterator::endIteration() {
    return this_.call(LITERAL_STRING[1705], {});
}
Variant RecursiveIteratorIterator::callHasChildren() {
    return this_.call(LITERAL_STRING[1706], {});
}
Variant RecursiveIteratorIterator::callGetChildren() {
    return this_.call(LITERAL_STRING[1707], {});
}
Variant RecursiveIteratorIterator::beginChildren() {
    return this_.call(LITERAL_STRING[1708], {});
}
Variant RecursiveIteratorIterator::endChildren() {
    return this_.call(LITERAL_STRING[1709], {});
}
Variant RecursiveIteratorIterator::nextElement() {
    return this_.call(LITERAL_STRING[1710], {});
}
Variant RecursiveIteratorIterator::setMaxDepth(const Variant &max_depth) {
    return this_.call(LITERAL_STRING[1711], {max_depth});
}
Variant RecursiveIteratorIterator::getMaxDepth() {
    return this_.call(LITERAL_STRING[1712], {});
}
IteratorIterator::IteratorIterator(const Variant &iterator, const Variant &_class) {
    this_ = newObject(LITERAL_STRING[1713], {iterator, _class});
}
Variant IteratorIterator::getInnerIterator() {
    return this_.call(LITERAL_STRING[1703], {});
}
Variant IteratorIterator::rewind() {
    return this_.call(LITERAL_STRING[94], {});
}
Variant IteratorIterator::valid() {
    return this_.call(LITERAL_STRING[93], {});
}
Variant IteratorIterator::key() {
    return this_.call(LITERAL_STRING[91], {});
}
Variant IteratorIterator::current() {
    return this_.call(LITERAL_STRING[90], {});
}
Variant IteratorIterator::next() {
    return this_.call(LITERAL_STRING[92], {});
}
CallbackFilterIterator::CallbackFilterIterator(const Variant &iterator, const Variant &callback) {
    this_ = newObject(LITERAL_STRING[1714], {iterator, callback});
}
Variant CallbackFilterIterator::accept() {
    return this_.call(LITERAL_STRING[1715], {});
}
Variant CallbackFilterIterator::rewind() {
    return this_.call(LITERAL_STRING[94], {});
}
Variant CallbackFilterIterator::next() {
    return this_.call(LITERAL_STRING[92], {});
}
Variant CallbackFilterIterator::getInnerIterator() {
    return this_.call(LITERAL_STRING[1703], {});
}
Variant CallbackFilterIterator::valid() {
    return this_.call(LITERAL_STRING[93], {});
}
Variant CallbackFilterIterator::key() {
    return this_.call(LITERAL_STRING[91], {});
}
Variant CallbackFilterIterator::current() {
    return this_.call(LITERAL_STRING[90], {});
}
RecursiveCallbackFilterIterator::RecursiveCallbackFilterIterator(const Variant &iterator, const Variant &callback) {
    this_ = newObject(LITERAL_STRING[1716], {iterator, callback});
}
Variant RecursiveCallbackFilterIterator::hasChildren() {
    return this_.call(LITERAL_STRING[913], {});
}
Variant RecursiveCallbackFilterIterator::getChildren() {
    return this_.call(LITERAL_STRING[914], {});
}
Variant RecursiveCallbackFilterIterator::accept() {
    return this_.call(LITERAL_STRING[1715], {});
}
Variant RecursiveCallbackFilterIterator::rewind() {
    return this_.call(LITERAL_STRING[94], {});
}
Variant RecursiveCallbackFilterIterator::next() {
    return this_.call(LITERAL_STRING[92], {});
}
Variant RecursiveCallbackFilterIterator::getInnerIterator() {
    return this_.call(LITERAL_STRING[1703], {});
}
Variant RecursiveCallbackFilterIterator::valid() {
    return this_.call(LITERAL_STRING[93], {});
}
Variant RecursiveCallbackFilterIterator::key() {
    return this_.call(LITERAL_STRING[91], {});
}
Variant RecursiveCallbackFilterIterator::current() {
    return this_.call(LITERAL_STRING[90], {});
}
ParentIterator::ParentIterator(const Variant &iterator) {
    this_ = newObject(LITERAL_STRING[1717], {iterator});
}
Variant ParentIterator::accept() {
    return this_.call(LITERAL_STRING[1715], {});
}
Variant ParentIterator::hasChildren() {
    return this_.call(LITERAL_STRING[913], {});
}
Variant ParentIterator::getChildren() {
    return this_.call(LITERAL_STRING[914], {});
}
Variant ParentIterator::rewind() {
    return this_.call(LITERAL_STRING[94], {});
}
Variant ParentIterator::next() {
    return this_.call(LITERAL_STRING[92], {});
}
Variant ParentIterator::getInnerIterator() {
    return this_.call(LITERAL_STRING[1703], {});
}
Variant ParentIterator::valid() {
    return this_.call(LITERAL_STRING[93], {});
}
Variant ParentIterator::key() {
    return this_.call(LITERAL_STRING[91], {});
}
Variant ParentIterator::current() {
    return this_.call(LITERAL_STRING[90], {});
}
LimitIterator::LimitIterator(const Variant &iterator, const Variant &offset, const Variant &limit) {
    this_ = newObject(LITERAL_STRING[1718], {iterator, offset, limit});
}
Variant LimitIterator::rewind() {
    return this_.call(LITERAL_STRING[94], {});
}
Variant LimitIterator::valid() {
    return this_.call(LITERAL_STRING[93], {});
}
Variant LimitIterator::next() {
    return this_.call(LITERAL_STRING[92], {});
}
Variant LimitIterator::seek(const Variant &offset) {
    return this_.call(LITERAL_STRING[922], {offset});
}
Variant LimitIterator::getPosition() {
    return this_.call(LITERAL_STRING[1463], {});
}
Variant LimitIterator::getInnerIterator() {
    return this_.call(LITERAL_STRING[1703], {});
}
Variant LimitIterator::key() {
    return this_.call(LITERAL_STRING[91], {});
}
Variant LimitIterator::current() {
    return this_.call(LITERAL_STRING[90], {});
}
CachingIterator::CachingIterator(const Variant &iterator, const Variant &flags) {
    this_ = newObject(LITERAL_STRING[1719], {iterator, flags});
}
Variant CachingIterator::rewind() {
    return this_.call(LITERAL_STRING[94], {});
}
Variant CachingIterator::valid() {
    return this_.call(LITERAL_STRING[93], {});
}
Variant CachingIterator::next() {
    return this_.call(LITERAL_STRING[92], {});
}
Variant CachingIterator::hasNext() {
    return this_.call(LITERAL_STRING[1720], {});
}
Variant CachingIterator::__toString() {
    return this_.call(LITERAL_STRING[29], {});
}
Variant CachingIterator::getFlags() {
    return this_.call(LITERAL_STRING[917], {});
}
Variant CachingIterator::setFlags(const Variant &flags) {
    return this_.call(LITERAL_STRING[918], {flags});
}
Variant CachingIterator::offsetGet(const Variant &key) {
    return this_.call(LITERAL_STRING[132], {key});
}
Variant CachingIterator::offsetSet(const Variant &key, const Variant &value) {
    return this_.call(LITERAL_STRING[133], {key, value});
}
Variant CachingIterator::offsetUnset(const Variant &key) {
    return this_.call(LITERAL_STRING[135], {key});
}
Variant CachingIterator::offsetExists(const Variant &key) {
    return this_.call(LITERAL_STRING[134], {key});
}
Variant CachingIterator::getCache() {
    return this_.call(LITERAL_STRING[1721], {});
}
Variant CachingIterator::count() {
    return this_.call(LITERAL_STRING[136], {});
}
Variant CachingIterator::getInnerIterator() {
    return this_.call(LITERAL_STRING[1703], {});
}
Variant CachingIterator::key() {
    return this_.call(LITERAL_STRING[91], {});
}
Variant CachingIterator::current() {
    return this_.call(LITERAL_STRING[90], {});
}
RecursiveCachingIterator::RecursiveCachingIterator(const Variant &iterator, const Variant &flags) {
    this_ = newObject(LITERAL_STRING[1722], {iterator, flags});
}
Variant RecursiveCachingIterator::hasChildren() {
    return this_.call(LITERAL_STRING[913], {});
}
Variant RecursiveCachingIterator::getChildren() {
    return this_.call(LITERAL_STRING[914], {});
}
Variant RecursiveCachingIterator::rewind() {
    return this_.call(LITERAL_STRING[94], {});
}
Variant RecursiveCachingIterator::valid() {
    return this_.call(LITERAL_STRING[93], {});
}
Variant RecursiveCachingIterator::next() {
    return this_.call(LITERAL_STRING[92], {});
}
Variant RecursiveCachingIterator::hasNext() {
    return this_.call(LITERAL_STRING[1720], {});
}
Variant RecursiveCachingIterator::__toString() {
    return this_.call(LITERAL_STRING[29], {});
}
Variant RecursiveCachingIterator::getFlags() {
    return this_.call(LITERAL_STRING[917], {});
}
Variant RecursiveCachingIterator::setFlags(const Variant &flags) {
    return this_.call(LITERAL_STRING[918], {flags});
}
Variant RecursiveCachingIterator::offsetGet(const Variant &key) {
    return this_.call(LITERAL_STRING[132], {key});
}
Variant RecursiveCachingIterator::offsetSet(const Variant &key, const Variant &value) {
    return this_.call(LITERAL_STRING[133], {key, value});
}
Variant RecursiveCachingIterator::offsetUnset(const Variant &key) {
    return this_.call(LITERAL_STRING[135], {key});
}
Variant RecursiveCachingIterator::offsetExists(const Variant &key) {
    return this_.call(LITERAL_STRING[134], {key});
}
Variant RecursiveCachingIterator::getCache() {
    return this_.call(LITERAL_STRING[1721], {});
}
Variant RecursiveCachingIterator::count() {
    return this_.call(LITERAL_STRING[136], {});
}
Variant RecursiveCachingIterator::getInnerIterator() {
    return this_.call(LITERAL_STRING[1703], {});
}
Variant RecursiveCachingIterator::key() {
    return this_.call(LITERAL_STRING[91], {});
}
Variant RecursiveCachingIterator::current() {
    return this_.call(LITERAL_STRING[90], {});
}
NoRewindIterator::NoRewindIterator(const Variant &iterator) {
    this_ = newObject(LITERAL_STRING[1723], {iterator});
}
Variant NoRewindIterator::rewind() {
    return this_.call(LITERAL_STRING[94], {});
}
Variant NoRewindIterator::valid() {
    return this_.call(LITERAL_STRING[93], {});
}
Variant NoRewindIterator::key() {
    return this_.call(LITERAL_STRING[91], {});
}
Variant NoRewindIterator::current() {
    return this_.call(LITERAL_STRING[90], {});
}
Variant NoRewindIterator::next() {
    return this_.call(LITERAL_STRING[92], {});
}
Variant NoRewindIterator::getInnerIterator() {
    return this_.call(LITERAL_STRING[1703], {});
}
AppendIterator::AppendIterator() {
    this_ = newObject(LITERAL_STRING[1724], {});
}
Variant AppendIterator::append(const Variant &iterator) {
    return this_.call(LITERAL_STRING[349], {iterator});
}
Variant AppendIterator::rewind() {
    return this_.call(LITERAL_STRING[94], {});
}
Variant AppendIterator::valid() {
    return this_.call(LITERAL_STRING[93], {});
}
Variant AppendIterator::current() {
    return this_.call(LITERAL_STRING[90], {});
}
Variant AppendIterator::next() {
    return this_.call(LITERAL_STRING[92], {});
}
Variant AppendIterator::getIteratorIndex() {
    return this_.call(LITERAL_STRING[1725], {});
}
Variant AppendIterator::getArrayIterator() {
    return this_.call(LITERAL_STRING[1726], {});
}
Variant AppendIterator::getInnerIterator() {
    return this_.call(LITERAL_STRING[1703], {});
}
Variant AppendIterator::key() {
    return this_.call(LITERAL_STRING[91], {});
}
InfiniteIterator::InfiniteIterator(const Variant &iterator) {
    this_ = newObject(LITERAL_STRING[1727], {iterator});
}
Variant InfiniteIterator::next() {
    return this_.call(LITERAL_STRING[92], {});
}
Variant InfiniteIterator::getInnerIterator() {
    return this_.call(LITERAL_STRING[1703], {});
}
Variant InfiniteIterator::rewind() {
    return this_.call(LITERAL_STRING[94], {});
}
Variant InfiniteIterator::valid() {
    return this_.call(LITERAL_STRING[93], {});
}
Variant InfiniteIterator::key() {
    return this_.call(LITERAL_STRING[91], {});
}
Variant InfiniteIterator::current() {
    return this_.call(LITERAL_STRING[90], {});
}
RegexIterator::RegexIterator(const Variant &iterator,
                             const Variant &pattern,
                             const Variant &mode,
                             const Variant &flags,
                             const Variant &preg_flags) {
    this_ = newObject(LITERAL_STRING[1728], {iterator, pattern, mode, flags, preg_flags});
}
Variant RegexIterator::accept() {
    return this_.call(LITERAL_STRING[1715], {});
}
Variant RegexIterator::getMode() {
    return this_.call(LITERAL_STRING[1113], {});
}
Variant RegexIterator::setMode(const Variant &mode) {
    return this_.call(LITERAL_STRING[1729], {mode});
}
Variant RegexIterator::getFlags() {
    return this_.call(LITERAL_STRING[917], {});
}
Variant RegexIterator::setFlags(const Variant &flags) {
    return this_.call(LITERAL_STRING[918], {flags});
}
Variant RegexIterator::getRegex() {
    return this_.call(LITERAL_STRING[1730], {});
}
Variant RegexIterator::getPregFlags() {
    return this_.call(LITERAL_STRING[1731], {});
}
Variant RegexIterator::setPregFlags(const Variant &preg_flags) {
    return this_.call(LITERAL_STRING[1732], {preg_flags});
}
Variant RegexIterator::rewind() {
    return this_.call(LITERAL_STRING[94], {});
}
Variant RegexIterator::next() {
    return this_.call(LITERAL_STRING[92], {});
}
Variant RegexIterator::getInnerIterator() {
    return this_.call(LITERAL_STRING[1703], {});
}
Variant RegexIterator::valid() {
    return this_.call(LITERAL_STRING[93], {});
}
Variant RegexIterator::key() {
    return this_.call(LITERAL_STRING[91], {});
}
Variant RegexIterator::current() {
    return this_.call(LITERAL_STRING[90], {});
}
RecursiveRegexIterator::RecursiveRegexIterator(const Variant &iterator,
                                               const Variant &pattern,
                                               const Variant &mode,
                                               const Variant &flags,
                                               const Variant &preg_flags) {
    this_ = newObject(LITERAL_STRING[1733], {iterator, pattern, mode, flags, preg_flags});
}
Variant RecursiveRegexIterator::accept() {
    return this_.call(LITERAL_STRING[1715], {});
}
Variant RecursiveRegexIterator::hasChildren() {
    return this_.call(LITERAL_STRING[913], {});
}
Variant RecursiveRegexIterator::getChildren() {
    return this_.call(LITERAL_STRING[914], {});
}
Variant RecursiveRegexIterator::getMode() {
    return this_.call(LITERAL_STRING[1113], {});
}
Variant RecursiveRegexIterator::setMode(const Variant &mode) {
    return this_.call(LITERAL_STRING[1729], {mode});
}
Variant RecursiveRegexIterator::getFlags() {
    return this_.call(LITERAL_STRING[917], {});
}
Variant RecursiveRegexIterator::setFlags(const Variant &flags) {
    return this_.call(LITERAL_STRING[918], {flags});
}
Variant RecursiveRegexIterator::getRegex() {
    return this_.call(LITERAL_STRING[1730], {});
}
Variant RecursiveRegexIterator::getPregFlags() {
    return this_.call(LITERAL_STRING[1731], {});
}
Variant RecursiveRegexIterator::setPregFlags(const Variant &preg_flags) {
    return this_.call(LITERAL_STRING[1732], {preg_flags});
}
Variant RecursiveRegexIterator::rewind() {
    return this_.call(LITERAL_STRING[94], {});
}
Variant RecursiveRegexIterator::next() {
    return this_.call(LITERAL_STRING[92], {});
}
Variant RecursiveRegexIterator::getInnerIterator() {
    return this_.call(LITERAL_STRING[1703], {});
}
Variant RecursiveRegexIterator::valid() {
    return this_.call(LITERAL_STRING[93], {});
}
Variant RecursiveRegexIterator::key() {
    return this_.call(LITERAL_STRING[91], {});
}
Variant RecursiveRegexIterator::current() {
    return this_.call(LITERAL_STRING[90], {});
}
Variant EmptyIterator::current() {
    return this_.call(LITERAL_STRING[90], {});
}
Variant EmptyIterator::next() {
    return this_.call(LITERAL_STRING[92], {});
}
Variant EmptyIterator::key() {
    return this_.call(LITERAL_STRING[91], {});
}
Variant EmptyIterator::valid() {
    return this_.call(LITERAL_STRING[93], {});
}
Variant EmptyIterator::rewind() {
    return this_.call(LITERAL_STRING[94], {});
}
RecursiveTreeIterator::RecursiveTreeIterator(const Variant &iterator,
                                             const Variant &flags,
                                             const Variant &caching_iterator_flags,
                                             const Variant &mode) {
    this_ = newObject(LITERAL_STRING[1735], {iterator, flags, caching_iterator_flags, mode});
}
Variant RecursiveTreeIterator::key() {
    return this_.call(LITERAL_STRING[91], {});
}
Variant RecursiveTreeIterator::current() {
    return this_.call(LITERAL_STRING[90], {});
}
Variant RecursiveTreeIterator::getPrefix() {
    return this_.call(LITERAL_STRING[1736], {});
}
Variant RecursiveTreeIterator::setPostfix(const Variant &postfix) {
    return this_.call(LITERAL_STRING[1737], {postfix});
}
Variant RecursiveTreeIterator::setPrefixPart(const Variant &part, const Variant &value) {
    return this_.call(LITERAL_STRING[1738], {part, value});
}
Variant RecursiveTreeIterator::getEntry() {
    return this_.call(LITERAL_STRING[1739], {});
}
Variant RecursiveTreeIterator::getPostfix() {
    return this_.call(LITERAL_STRING[1740], {});
}
Variant RecursiveTreeIterator::rewind() {
    return this_.call(LITERAL_STRING[94], {});
}
Variant RecursiveTreeIterator::valid() {
    return this_.call(LITERAL_STRING[93], {});
}
Variant RecursiveTreeIterator::next() {
    return this_.call(LITERAL_STRING[92], {});
}
Variant RecursiveTreeIterator::getDepth() {
    return this_.call(LITERAL_STRING[1701], {});
}
Variant RecursiveTreeIterator::getSubIterator(const Variant &level) {
    return this_.call(LITERAL_STRING[1702], {level});
}
Variant RecursiveTreeIterator::getInnerIterator() {
    return this_.call(LITERAL_STRING[1703], {});
}
Variant RecursiveTreeIterator::beginIteration() {
    return this_.call(LITERAL_STRING[1704], {});
}
Variant RecursiveTreeIterator::endIteration() {
    return this_.call(LITERAL_STRING[1705], {});
}
Variant RecursiveTreeIterator::callHasChildren() {
    return this_.call(LITERAL_STRING[1706], {});
}
Variant RecursiveTreeIterator::callGetChildren() {
    return this_.call(LITERAL_STRING[1707], {});
}
Variant RecursiveTreeIterator::beginChildren() {
    return this_.call(LITERAL_STRING[1708], {});
}
Variant RecursiveTreeIterator::endChildren() {
    return this_.call(LITERAL_STRING[1709], {});
}
Variant RecursiveTreeIterator::nextElement() {
    return this_.call(LITERAL_STRING[1710], {});
}
Variant RecursiveTreeIterator::setMaxDepth(const Variant &max_depth) {
    return this_.call(LITERAL_STRING[1711], {max_depth});
}
Variant RecursiveTreeIterator::getMaxDepth() {
    return this_.call(LITERAL_STRING[1712], {});
}
ArrayObject::ArrayObject(const Variant &array, const Variant &flags, const Variant &iterator_class) {
    this_ = newObject(LITERAL_STRING[1741], {array, flags, iterator_class});
}
Variant ArrayObject::offsetExists(const Variant &key) {
    return this_.call(LITERAL_STRING[134], {key});
}
Variant ArrayObject::offsetGet(const Variant &key) {
    return this_.call(LITERAL_STRING[132], {key});
}
Variant ArrayObject::offsetSet(const Variant &key, const Variant &value) {
    return this_.call(LITERAL_STRING[133], {key, value});
}
Variant ArrayObject::offsetUnset(const Variant &key) {
    return this_.call(LITERAL_STRING[135], {key});
}
Variant ArrayObject::append(const Variant &value) {
    return this_.call(LITERAL_STRING[349], {value});
}
Variant ArrayObject::getArrayCopy() {
    return this_.call(LITERAL_STRING[1742], {});
}
Variant ArrayObject::count() {
    return this_.call(LITERAL_STRING[136], {});
}
Variant ArrayObject::getFlags() {
    return this_.call(LITERAL_STRING[917], {});
}
Variant ArrayObject::setFlags(const Variant &flags) {
    return this_.call(LITERAL_STRING[918], {flags});
}
Variant ArrayObject::asort(const Variant &flags) {
    return this_.call(LITERAL_STRING[1743], {flags});
}
Variant ArrayObject::ksort(const Variant &flags) {
    return this_.call(LITERAL_STRING[1744], {flags});
}
Variant ArrayObject::uasort(const Variant &callback) {
    return this_.call(LITERAL_STRING[1745], {callback});
}
Variant ArrayObject::uksort(const Variant &callback) {
    return this_.call(LITERAL_STRING[1746], {callback});
}
Variant ArrayObject::natsort() {
    return this_.call(LITERAL_STRING[1747], {});
}
Variant ArrayObject::natcasesort() {
    return this_.call(LITERAL_STRING[1748], {});
}
Variant ArrayObject::unserialize(const Variant &data) {
    return this_.call(LITERAL_STRING[1749], {data});
}
Variant ArrayObject::serialize() {
    return this_.call(LITERAL_STRING[1750], {});
}
Variant ArrayObject::__serialize() {
    return this_.call(LITERAL_STRING[30], {});
}
Variant ArrayObject::__unserialize(const Variant &data) {
    return this_.call(LITERAL_STRING[31], {data});
}
Variant ArrayObject::getIterator() {
    return this_.call(LITERAL_STRING[137], {});
}
Variant ArrayObject::exchangeArray(const Variant &array) {
    return this_.call(LITERAL_STRING[1751], {array});
}
Variant ArrayObject::setIteratorClass(const Variant &iterator_class) {
    return this_.call(LITERAL_STRING[1752], {iterator_class});
}
Variant ArrayObject::getIteratorClass() {
    return this_.call(LITERAL_STRING[1753], {});
}
Variant ArrayObject::__debugInfo() {
    return this_.call(LITERAL_STRING[126], {});
}
_ArrayIterator::_ArrayIterator(const Variant &array, const Variant &flags) {
    this_ = newObject(LITERAL_STRING[1754], {array, flags});
}
Variant _ArrayIterator::offsetExists(const Variant &key) {
    return this_.call(LITERAL_STRING[134], {key});
}
Variant _ArrayIterator::offsetGet(const Variant &key) {
    return this_.call(LITERAL_STRING[132], {key});
}
Variant _ArrayIterator::offsetSet(const Variant &key, const Variant &value) {
    return this_.call(LITERAL_STRING[133], {key, value});
}
Variant _ArrayIterator::offsetUnset(const Variant &key) {
    return this_.call(LITERAL_STRING[135], {key});
}
Variant _ArrayIterator::append(const Variant &value) {
    return this_.call(LITERAL_STRING[349], {value});
}
Variant _ArrayIterator::getArrayCopy() {
    return this_.call(LITERAL_STRING[1742], {});
}
Variant _ArrayIterator::count() {
    return this_.call(LITERAL_STRING[136], {});
}
Variant _ArrayIterator::getFlags() {
    return this_.call(LITERAL_STRING[917], {});
}
Variant _ArrayIterator::setFlags(const Variant &flags) {
    return this_.call(LITERAL_STRING[918], {flags});
}
Variant _ArrayIterator::asort(const Variant &flags) {
    return this_.call(LITERAL_STRING[1743], {flags});
}
Variant _ArrayIterator::ksort(const Variant &flags) {
    return this_.call(LITERAL_STRING[1744], {flags});
}
Variant _ArrayIterator::uasort(const Variant &callback) {
    return this_.call(LITERAL_STRING[1745], {callback});
}
Variant _ArrayIterator::uksort(const Variant &callback) {
    return this_.call(LITERAL_STRING[1746], {callback});
}
Variant _ArrayIterator::natsort() {
    return this_.call(LITERAL_STRING[1747], {});
}
Variant _ArrayIterator::natcasesort() {
    return this_.call(LITERAL_STRING[1748], {});
}
Variant _ArrayIterator::unserialize(const Variant &data) {
    return this_.call(LITERAL_STRING[1749], {data});
}
Variant _ArrayIterator::serialize() {
    return this_.call(LITERAL_STRING[1750], {});
}
Variant _ArrayIterator::__serialize() {
    return this_.call(LITERAL_STRING[30], {});
}
Variant _ArrayIterator::__unserialize(const Variant &data) {
    return this_.call(LITERAL_STRING[31], {data});
}
Variant _ArrayIterator::rewind() {
    return this_.call(LITERAL_STRING[94], {});
}
Variant _ArrayIterator::current() {
    return this_.call(LITERAL_STRING[90], {});
}
Variant _ArrayIterator::key() {
    return this_.call(LITERAL_STRING[91], {});
}
Variant _ArrayIterator::next() {
    return this_.call(LITERAL_STRING[92], {});
}
Variant _ArrayIterator::valid() {
    return this_.call(LITERAL_STRING[93], {});
}
Variant _ArrayIterator::seek(const Variant &offset) {
    return this_.call(LITERAL_STRING[922], {offset});
}
Variant _ArrayIterator::__debugInfo() {
    return this_.call(LITERAL_STRING[126], {});
}
Variant RecursiveArrayIterator::hasChildren() {
    return this_.call(LITERAL_STRING[913], {});
}
Variant RecursiveArrayIterator::getChildren() {
    return this_.call(LITERAL_STRING[914], {});
}
RecursiveArrayIterator::RecursiveArrayIterator(const Variant &array, const Variant &flags) {
    this_ = newObject(LITERAL_STRING[1755], {array, flags});
}
Variant RecursiveArrayIterator::offsetExists(const Variant &key) {
    return this_.call(LITERAL_STRING[134], {key});
}
Variant RecursiveArrayIterator::offsetGet(const Variant &key) {
    return this_.call(LITERAL_STRING[132], {key});
}
Variant RecursiveArrayIterator::offsetSet(const Variant &key, const Variant &value) {
    return this_.call(LITERAL_STRING[133], {key, value});
}
Variant RecursiveArrayIterator::offsetUnset(const Variant &key) {
    return this_.call(LITERAL_STRING[135], {key});
}
Variant RecursiveArrayIterator::append(const Variant &value) {
    return this_.call(LITERAL_STRING[349], {value});
}
Variant RecursiveArrayIterator::getArrayCopy() {
    return this_.call(LITERAL_STRING[1742], {});
}
Variant RecursiveArrayIterator::count() {
    return this_.call(LITERAL_STRING[136], {});
}
Variant RecursiveArrayIterator::getFlags() {
    return this_.call(LITERAL_STRING[917], {});
}
Variant RecursiveArrayIterator::setFlags(const Variant &flags) {
    return this_.call(LITERAL_STRING[918], {flags});
}
Variant RecursiveArrayIterator::asort(const Variant &flags) {
    return this_.call(LITERAL_STRING[1743], {flags});
}
Variant RecursiveArrayIterator::ksort(const Variant &flags) {
    return this_.call(LITERAL_STRING[1744], {flags});
}
Variant RecursiveArrayIterator::uasort(const Variant &callback) {
    return this_.call(LITERAL_STRING[1745], {callback});
}
Variant RecursiveArrayIterator::uksort(const Variant &callback) {
    return this_.call(LITERAL_STRING[1746], {callback});
}
Variant RecursiveArrayIterator::natsort() {
    return this_.call(LITERAL_STRING[1747], {});
}
Variant RecursiveArrayIterator::natcasesort() {
    return this_.call(LITERAL_STRING[1748], {});
}
Variant RecursiveArrayIterator::unserialize(const Variant &data) {
    return this_.call(LITERAL_STRING[1749], {data});
}
Variant RecursiveArrayIterator::serialize() {
    return this_.call(LITERAL_STRING[1750], {});
}
Variant RecursiveArrayIterator::__serialize() {
    return this_.call(LITERAL_STRING[30], {});
}
Variant RecursiveArrayIterator::__unserialize(const Variant &data) {
    return this_.call(LITERAL_STRING[31], {data});
}
Variant RecursiveArrayIterator::rewind() {
    return this_.call(LITERAL_STRING[94], {});
}
Variant RecursiveArrayIterator::current() {
    return this_.call(LITERAL_STRING[90], {});
}
Variant RecursiveArrayIterator::key() {
    return this_.call(LITERAL_STRING[91], {});
}
Variant RecursiveArrayIterator::next() {
    return this_.call(LITERAL_STRING[92], {});
}
Variant RecursiveArrayIterator::valid() {
    return this_.call(LITERAL_STRING[93], {});
}
Variant RecursiveArrayIterator::seek(const Variant &offset) {
    return this_.call(LITERAL_STRING[922], {offset});
}
Variant RecursiveArrayIterator::__debugInfo() {
    return this_.call(LITERAL_STRING[126], {});
}
SplFileInfo::SplFileInfo(const Variant &filename) {
    this_ = newObject(LITERAL_STRING[1756], {filename});
}
Variant SplFileInfo::getPath() {
    return this_.call(LITERAL_STRING[880], {});
}
Variant SplFileInfo::getFilename() {
    return this_.call(LITERAL_STRING[202], {});
}
Variant SplFileInfo::getExtension() {
    return this_.call(LITERAL_STRING[919], {});
}
Variant SplFileInfo::getBasename(const Variant &suffix) {
    return this_.call(LITERAL_STRING[920], {suffix});
}
Variant SplFileInfo::getPathname() {
    return this_.call(LITERAL_STRING[923], {});
}
Variant SplFileInfo::getPerms() {
    return this_.call(LITERAL_STRING[924], {});
}
Variant SplFileInfo::getInode() {
    return this_.call(LITERAL_STRING[925], {});
}
Variant SplFileInfo::getSize() {
    return this_.call(LITERAL_STRING[926], {});
}
Variant SplFileInfo::getOwner() {
    return this_.call(LITERAL_STRING[927], {});
}
Variant SplFileInfo::getGroup() {
    return this_.call(LITERAL_STRING[928], {});
}
Variant SplFileInfo::getATime() {
    return this_.call(LITERAL_STRING[929], {});
}
Variant SplFileInfo::getMTime() {
    return this_.call(LITERAL_STRING[930], {});
}
Variant SplFileInfo::getCTime() {
    return this_.call(LITERAL_STRING[931], {});
}
Variant SplFileInfo::getType() {
    return this_.call(LITERAL_STRING[932], {});
}
Variant SplFileInfo::isWritable() {
    return this_.call(LITERAL_STRING[890], {});
}
Variant SplFileInfo::isReadable() {
    return this_.call(LITERAL_STRING[933], {});
}
Variant SplFileInfo::isExecutable() {
    return this_.call(LITERAL_STRING[934], {});
}
Variant SplFileInfo::isFile() {
    return this_.call(LITERAL_STRING[935], {});
}
Variant SplFileInfo::isDir() {
    return this_.call(LITERAL_STRING[936], {});
}
Variant SplFileInfo::isLink() {
    return this_.call(LITERAL_STRING[937], {});
}
Variant SplFileInfo::getLinkTarget() {
    return this_.call(LITERAL_STRING[938], {});
}
Variant SplFileInfo::getRealPath() {
    return this_.call(LITERAL_STRING[939], {});
}
Variant SplFileInfo::getFileInfo(const Variant &_class) {
    return this_.call(LITERAL_STRING[940], {_class});
}
Variant SplFileInfo::getPathInfo(const Variant &_class) {
    return this_.call(LITERAL_STRING[941], {_class});
}
Variant SplFileInfo::openFile(const Variant &mode, const Variant &use_include_path, const Variant &context) {
    return this_.call(LITERAL_STRING[942], {mode, use_include_path, context});
}
Variant SplFileInfo::setFileClass(const Variant &_class) {
    return this_.call(LITERAL_STRING[943], {_class});
}
Variant SplFileInfo::setInfoClass(const Variant &_class) {
    return this_.call(LITERAL_STRING[944], {_class});
}
Variant SplFileInfo::__toString() {
    return this_.call(LITERAL_STRING[29], {});
}
Variant SplFileInfo::__debugInfo() {
    return this_.call(LITERAL_STRING[126], {});
}
Variant SplFileInfo::_bad_state_ex() {
    return this_.call(LITERAL_STRING[945], {});
}
DirectoryIterator::DirectoryIterator(const Variant &directory) {
    this_ = newObject(LITERAL_STRING[1757], {directory});
}
Variant DirectoryIterator::getFilename() {
    return this_.call(LITERAL_STRING[202], {});
}
Variant DirectoryIterator::getExtension() {
    return this_.call(LITERAL_STRING[919], {});
}
Variant DirectoryIterator::getBasename(const Variant &suffix) {
    return this_.call(LITERAL_STRING[920], {suffix});
}
Variant DirectoryIterator::isDot() {
    return this_.call(LITERAL_STRING[921], {});
}
Variant DirectoryIterator::rewind() {
    return this_.call(LITERAL_STRING[94], {});
}
Variant DirectoryIterator::valid() {
    return this_.call(LITERAL_STRING[93], {});
}
Variant DirectoryIterator::key() {
    return this_.call(LITERAL_STRING[91], {});
}
Variant DirectoryIterator::current() {
    return this_.call(LITERAL_STRING[90], {});
}
Variant DirectoryIterator::next() {
    return this_.call(LITERAL_STRING[92], {});
}
Variant DirectoryIterator::seek(const Variant &offset) {
    return this_.call(LITERAL_STRING[922], {offset});
}
Variant DirectoryIterator::__toString() {
    return this_.call(LITERAL_STRING[29], {});
}
Variant DirectoryIterator::getPath() {
    return this_.call(LITERAL_STRING[880], {});
}
Variant DirectoryIterator::getPathname() {
    return this_.call(LITERAL_STRING[923], {});
}
Variant DirectoryIterator::getPerms() {
    return this_.call(LITERAL_STRING[924], {});
}
Variant DirectoryIterator::getInode() {
    return this_.call(LITERAL_STRING[925], {});
}
Variant DirectoryIterator::getSize() {
    return this_.call(LITERAL_STRING[926], {});
}
Variant DirectoryIterator::getOwner() {
    return this_.call(LITERAL_STRING[927], {});
}
Variant DirectoryIterator::getGroup() {
    return this_.call(LITERAL_STRING[928], {});
}
Variant DirectoryIterator::getATime() {
    return this_.call(LITERAL_STRING[929], {});
}
Variant DirectoryIterator::getMTime() {
    return this_.call(LITERAL_STRING[930], {});
}
Variant DirectoryIterator::getCTime() {
    return this_.call(LITERAL_STRING[931], {});
}
Variant DirectoryIterator::getType() {
    return this_.call(LITERAL_STRING[932], {});
}
Variant DirectoryIterator::isWritable() {
    return this_.call(LITERAL_STRING[890], {});
}
Variant DirectoryIterator::isReadable() {
    return this_.call(LITERAL_STRING[933], {});
}
Variant DirectoryIterator::isExecutable() {
    return this_.call(LITERAL_STRING[934], {});
}
Variant DirectoryIterator::isFile() {
    return this_.call(LITERAL_STRING[935], {});
}
Variant DirectoryIterator::isDir() {
    return this_.call(LITERAL_STRING[936], {});
}
Variant DirectoryIterator::isLink() {
    return this_.call(LITERAL_STRING[937], {});
}
Variant DirectoryIterator::getLinkTarget() {
    return this_.call(LITERAL_STRING[938], {});
}
Variant DirectoryIterator::getRealPath() {
    return this_.call(LITERAL_STRING[939], {});
}
Variant DirectoryIterator::getFileInfo(const Variant &_class) {
    return this_.call(LITERAL_STRING[940], {_class});
}
Variant DirectoryIterator::getPathInfo(const Variant &_class) {
    return this_.call(LITERAL_STRING[941], {_class});
}
Variant DirectoryIterator::openFile(const Variant &mode, const Variant &use_include_path, const Variant &context) {
    return this_.call(LITERAL_STRING[942], {mode, use_include_path, context});
}
Variant DirectoryIterator::setFileClass(const Variant &_class) {
    return this_.call(LITERAL_STRING[943], {_class});
}
Variant DirectoryIterator::setInfoClass(const Variant &_class) {
    return this_.call(LITERAL_STRING[944], {_class});
}
Variant DirectoryIterator::__debugInfo() {
    return this_.call(LITERAL_STRING[126], {});
}
Variant DirectoryIterator::_bad_state_ex() {
    return this_.call(LITERAL_STRING[945], {});
}
FilesystemIterator::FilesystemIterator(const Variant &directory, const Variant &flags) {
    this_ = newObject(LITERAL_STRING[1758], {directory, flags});
}
Variant FilesystemIterator::rewind() {
    return this_.call(LITERAL_STRING[94], {});
}
Variant FilesystemIterator::key() {
    return this_.call(LITERAL_STRING[91], {});
}
Variant FilesystemIterator::current() {
    return this_.call(LITERAL_STRING[90], {});
}
Variant FilesystemIterator::getFlags() {
    return this_.call(LITERAL_STRING[917], {});
}
Variant FilesystemIterator::setFlags(const Variant &flags) {
    return this_.call(LITERAL_STRING[918], {flags});
}
Variant FilesystemIterator::getFilename() {
    return this_.call(LITERAL_STRING[202], {});
}
Variant FilesystemIterator::getExtension() {
    return this_.call(LITERAL_STRING[919], {});
}
Variant FilesystemIterator::getBasename(const Variant &suffix) {
    return this_.call(LITERAL_STRING[920], {suffix});
}
Variant FilesystemIterator::isDot() {
    return this_.call(LITERAL_STRING[921], {});
}
Variant FilesystemIterator::valid() {
    return this_.call(LITERAL_STRING[93], {});
}
Variant FilesystemIterator::next() {
    return this_.call(LITERAL_STRING[92], {});
}
Variant FilesystemIterator::seek(const Variant &offset) {
    return this_.call(LITERAL_STRING[922], {offset});
}
Variant FilesystemIterator::__toString() {
    return this_.call(LITERAL_STRING[29], {});
}
Variant FilesystemIterator::getPath() {
    return this_.call(LITERAL_STRING[880], {});
}
Variant FilesystemIterator::getPathname() {
    return this_.call(LITERAL_STRING[923], {});
}
Variant FilesystemIterator::getPerms() {
    return this_.call(LITERAL_STRING[924], {});
}
Variant FilesystemIterator::getInode() {
    return this_.call(LITERAL_STRING[925], {});
}
Variant FilesystemIterator::getSize() {
    return this_.call(LITERAL_STRING[926], {});
}
Variant FilesystemIterator::getOwner() {
    return this_.call(LITERAL_STRING[927], {});
}
Variant FilesystemIterator::getGroup() {
    return this_.call(LITERAL_STRING[928], {});
}
Variant FilesystemIterator::getATime() {
    return this_.call(LITERAL_STRING[929], {});
}
Variant FilesystemIterator::getMTime() {
    return this_.call(LITERAL_STRING[930], {});
}
Variant FilesystemIterator::getCTime() {
    return this_.call(LITERAL_STRING[931], {});
}
Variant FilesystemIterator::getType() {
    return this_.call(LITERAL_STRING[932], {});
}
Variant FilesystemIterator::isWritable() {
    return this_.call(LITERAL_STRING[890], {});
}
Variant FilesystemIterator::isReadable() {
    return this_.call(LITERAL_STRING[933], {});
}
Variant FilesystemIterator::isExecutable() {
    return this_.call(LITERAL_STRING[934], {});
}
Variant FilesystemIterator::isFile() {
    return this_.call(LITERAL_STRING[935], {});
}
Variant FilesystemIterator::isDir() {
    return this_.call(LITERAL_STRING[936], {});
}
Variant FilesystemIterator::isLink() {
    return this_.call(LITERAL_STRING[937], {});
}
Variant FilesystemIterator::getLinkTarget() {
    return this_.call(LITERAL_STRING[938], {});
}
Variant FilesystemIterator::getRealPath() {
    return this_.call(LITERAL_STRING[939], {});
}
Variant FilesystemIterator::getFileInfo(const Variant &_class) {
    return this_.call(LITERAL_STRING[940], {_class});
}
Variant FilesystemIterator::getPathInfo(const Variant &_class) {
    return this_.call(LITERAL_STRING[941], {_class});
}
Variant FilesystemIterator::openFile(const Variant &mode, const Variant &use_include_path, const Variant &context) {
    return this_.call(LITERAL_STRING[942], {mode, use_include_path, context});
}
Variant FilesystemIterator::setFileClass(const Variant &_class) {
    return this_.call(LITERAL_STRING[943], {_class});
}
Variant FilesystemIterator::setInfoClass(const Variant &_class) {
    return this_.call(LITERAL_STRING[944], {_class});
}
Variant FilesystemIterator::__debugInfo() {
    return this_.call(LITERAL_STRING[126], {});
}
Variant FilesystemIterator::_bad_state_ex() {
    return this_.call(LITERAL_STRING[945], {});
}
RecursiveDirectoryIterator::RecursiveDirectoryIterator(const Variant &directory, const Variant &flags) {
    this_ = newObject(LITERAL_STRING[1759], {directory, flags});
}
Variant RecursiveDirectoryIterator::hasChildren(const Variant &allow_links) {
    return this_.call(LITERAL_STRING[913], {allow_links});
}
Variant RecursiveDirectoryIterator::getChildren() {
    return this_.call(LITERAL_STRING[914], {});
}
Variant RecursiveDirectoryIterator::getSubPath() {
    return this_.call(LITERAL_STRING[915], {});
}
Variant RecursiveDirectoryIterator::getSubPathname() {
    return this_.call(LITERAL_STRING[916], {});
}
Variant RecursiveDirectoryIterator::rewind() {
    return this_.call(LITERAL_STRING[94], {});
}
Variant RecursiveDirectoryIterator::key() {
    return this_.call(LITERAL_STRING[91], {});
}
Variant RecursiveDirectoryIterator::current() {
    return this_.call(LITERAL_STRING[90], {});
}
Variant RecursiveDirectoryIterator::getFlags() {
    return this_.call(LITERAL_STRING[917], {});
}
Variant RecursiveDirectoryIterator::setFlags(const Variant &flags) {
    return this_.call(LITERAL_STRING[918], {flags});
}
Variant RecursiveDirectoryIterator::getFilename() {
    return this_.call(LITERAL_STRING[202], {});
}
Variant RecursiveDirectoryIterator::getExtension() {
    return this_.call(LITERAL_STRING[919], {});
}
Variant RecursiveDirectoryIterator::getBasename(const Variant &suffix) {
    return this_.call(LITERAL_STRING[920], {suffix});
}
Variant RecursiveDirectoryIterator::isDot() {
    return this_.call(LITERAL_STRING[921], {});
}
Variant RecursiveDirectoryIterator::valid() {
    return this_.call(LITERAL_STRING[93], {});
}
Variant RecursiveDirectoryIterator::next() {
    return this_.call(LITERAL_STRING[92], {});
}
Variant RecursiveDirectoryIterator::seek(const Variant &offset) {
    return this_.call(LITERAL_STRING[922], {offset});
}
Variant RecursiveDirectoryIterator::__toString() {
    return this_.call(LITERAL_STRING[29], {});
}
Variant RecursiveDirectoryIterator::getPath() {
    return this_.call(LITERAL_STRING[880], {});
}
Variant RecursiveDirectoryIterator::getPathname() {
    return this_.call(LITERAL_STRING[923], {});
}
Variant RecursiveDirectoryIterator::getPerms() {
    return this_.call(LITERAL_STRING[924], {});
}
Variant RecursiveDirectoryIterator::getInode() {
    return this_.call(LITERAL_STRING[925], {});
}
Variant RecursiveDirectoryIterator::getSize() {
    return this_.call(LITERAL_STRING[926], {});
}
Variant RecursiveDirectoryIterator::getOwner() {
    return this_.call(LITERAL_STRING[927], {});
}
Variant RecursiveDirectoryIterator::getGroup() {
    return this_.call(LITERAL_STRING[928], {});
}
Variant RecursiveDirectoryIterator::getATime() {
    return this_.call(LITERAL_STRING[929], {});
}
Variant RecursiveDirectoryIterator::getMTime() {
    return this_.call(LITERAL_STRING[930], {});
}
Variant RecursiveDirectoryIterator::getCTime() {
    return this_.call(LITERAL_STRING[931], {});
}
Variant RecursiveDirectoryIterator::getType() {
    return this_.call(LITERAL_STRING[932], {});
}
Variant RecursiveDirectoryIterator::isWritable() {
    return this_.call(LITERAL_STRING[890], {});
}
Variant RecursiveDirectoryIterator::isReadable() {
    return this_.call(LITERAL_STRING[933], {});
}
Variant RecursiveDirectoryIterator::isExecutable() {
    return this_.call(LITERAL_STRING[934], {});
}
Variant RecursiveDirectoryIterator::isFile() {
    return this_.call(LITERAL_STRING[935], {});
}
Variant RecursiveDirectoryIterator::isDir() {
    return this_.call(LITERAL_STRING[936], {});
}
Variant RecursiveDirectoryIterator::isLink() {
    return this_.call(LITERAL_STRING[937], {});
}
Variant RecursiveDirectoryIterator::getLinkTarget() {
    return this_.call(LITERAL_STRING[938], {});
}
Variant RecursiveDirectoryIterator::getRealPath() {
    return this_.call(LITERAL_STRING[939], {});
}
Variant RecursiveDirectoryIterator::getFileInfo(const Variant &_class) {
    return this_.call(LITERAL_STRING[940], {_class});
}
Variant RecursiveDirectoryIterator::getPathInfo(const Variant &_class) {
    return this_.call(LITERAL_STRING[941], {_class});
}
Variant RecursiveDirectoryIterator::openFile(const Variant &mode,
                                             const Variant &use_include_path,
                                             const Variant &context) {
    return this_.call(LITERAL_STRING[942], {mode, use_include_path, context});
}
Variant RecursiveDirectoryIterator::setFileClass(const Variant &_class) {
    return this_.call(LITERAL_STRING[943], {_class});
}
Variant RecursiveDirectoryIterator::setInfoClass(const Variant &_class) {
    return this_.call(LITERAL_STRING[944], {_class});
}
Variant RecursiveDirectoryIterator::__debugInfo() {
    return this_.call(LITERAL_STRING[126], {});
}
Variant RecursiveDirectoryIterator::_bad_state_ex() {
    return this_.call(LITERAL_STRING[945], {});
}
GlobIterator::GlobIterator(const Variant &pattern, const Variant &flags) {
    this_ = newObject(LITERAL_STRING[1760], {pattern, flags});
}
Variant GlobIterator::count() {
    return this_.call(LITERAL_STRING[136], {});
}
Variant GlobIterator::rewind() {
    return this_.call(LITERAL_STRING[94], {});
}
Variant GlobIterator::key() {
    return this_.call(LITERAL_STRING[91], {});
}
Variant GlobIterator::current() {
    return this_.call(LITERAL_STRING[90], {});
}
Variant GlobIterator::getFlags() {
    return this_.call(LITERAL_STRING[917], {});
}
Variant GlobIterator::setFlags(const Variant &flags) {
    return this_.call(LITERAL_STRING[918], {flags});
}
Variant GlobIterator::getFilename() {
    return this_.call(LITERAL_STRING[202], {});
}
Variant GlobIterator::getExtension() {
    return this_.call(LITERAL_STRING[919], {});
}
Variant GlobIterator::getBasename(const Variant &suffix) {
    return this_.call(LITERAL_STRING[920], {suffix});
}
Variant GlobIterator::isDot() {
    return this_.call(LITERAL_STRING[921], {});
}
Variant GlobIterator::valid() {
    return this_.call(LITERAL_STRING[93], {});
}
Variant GlobIterator::next() {
    return this_.call(LITERAL_STRING[92], {});
}
Variant GlobIterator::seek(const Variant &offset) {
    return this_.call(LITERAL_STRING[922], {offset});
}
Variant GlobIterator::__toString() {
    return this_.call(LITERAL_STRING[29], {});
}
Variant GlobIterator::getPath() {
    return this_.call(LITERAL_STRING[880], {});
}
Variant GlobIterator::getPathname() {
    return this_.call(LITERAL_STRING[923], {});
}
Variant GlobIterator::getPerms() {
    return this_.call(LITERAL_STRING[924], {});
}
Variant GlobIterator::getInode() {
    return this_.call(LITERAL_STRING[925], {});
}
Variant GlobIterator::getSize() {
    return this_.call(LITERAL_STRING[926], {});
}
Variant GlobIterator::getOwner() {
    return this_.call(LITERAL_STRING[927], {});
}
Variant GlobIterator::getGroup() {
    return this_.call(LITERAL_STRING[928], {});
}
Variant GlobIterator::getATime() {
    return this_.call(LITERAL_STRING[929], {});
}
Variant GlobIterator::getMTime() {
    return this_.call(LITERAL_STRING[930], {});
}
Variant GlobIterator::getCTime() {
    return this_.call(LITERAL_STRING[931], {});
}
Variant GlobIterator::getType() {
    return this_.call(LITERAL_STRING[932], {});
}
Variant GlobIterator::isWritable() {
    return this_.call(LITERAL_STRING[890], {});
}
Variant GlobIterator::isReadable() {
    return this_.call(LITERAL_STRING[933], {});
}
Variant GlobIterator::isExecutable() {
    return this_.call(LITERAL_STRING[934], {});
}
Variant GlobIterator::isFile() {
    return this_.call(LITERAL_STRING[935], {});
}
Variant GlobIterator::isDir() {
    return this_.call(LITERAL_STRING[936], {});
}
Variant GlobIterator::isLink() {
    return this_.call(LITERAL_STRING[937], {});
}
Variant GlobIterator::getLinkTarget() {
    return this_.call(LITERAL_STRING[938], {});
}
Variant GlobIterator::getRealPath() {
    return this_.call(LITERAL_STRING[939], {});
}
Variant GlobIterator::getFileInfo(const Variant &_class) {
    return this_.call(LITERAL_STRING[940], {_class});
}
Variant GlobIterator::getPathInfo(const Variant &_class) {
    return this_.call(LITERAL_STRING[941], {_class});
}
Variant GlobIterator::openFile(const Variant &mode, const Variant &use_include_path, const Variant &context) {
    return this_.call(LITERAL_STRING[942], {mode, use_include_path, context});
}
Variant GlobIterator::setFileClass(const Variant &_class) {
    return this_.call(LITERAL_STRING[943], {_class});
}
Variant GlobIterator::setInfoClass(const Variant &_class) {
    return this_.call(LITERAL_STRING[944], {_class});
}
Variant GlobIterator::__debugInfo() {
    return this_.call(LITERAL_STRING[126], {});
}
Variant GlobIterator::_bad_state_ex() {
    return this_.call(LITERAL_STRING[945], {});
}
SplFileObject::SplFileObject(const Variant &filename,
                             const Variant &mode,
                             const Variant &use_include_path,
                             const Variant &context) {
    this_ = newObject(LITERAL_STRING[1761], {filename, mode, use_include_path, context});
}
Variant SplFileObject::rewind() {
    return this_.call(LITERAL_STRING[94], {});
}
Variant SplFileObject::eof() {
    return this_.call(LITERAL_STRING[1762], {});
}
Variant SplFileObject::valid() {
    return this_.call(LITERAL_STRING[93], {});
}
Variant SplFileObject::fgets() {
    return this_.call(LITERAL_STRING[1763], {});
}
Variant SplFileObject::fread(const Variant &length) {
    return this_.call(LITERAL_STRING[1764], {length});
}
Variant SplFileObject::fgetcsv(const Variant &separator, const Variant &enclosure, const Variant &escape) {
    return this_.call(LITERAL_STRING[1765], {separator, enclosure, escape});
}
Variant SplFileObject::fputcsv(const Variant &fields,
                               const Variant &separator,
                               const Variant &enclosure,
                               const Variant &escape,
                               const Variant &eol) {
    return this_.call(LITERAL_STRING[1766], {fields, separator, enclosure, escape, eol});
}
Variant SplFileObject::setCsvControl(const Variant &separator, const Variant &enclosure, const Variant &escape) {
    return this_.call(LITERAL_STRING[1767], {separator, enclosure, escape});
}
Variant SplFileObject::getCsvControl() {
    return this_.call(LITERAL_STRING[1768], {});
}
Variant SplFileObject::flock(const Variant &operation, const Reference &would_block) {
    return this_.call(LITERAL_STRING[1769], {operation, &would_block});
}
Variant SplFileObject::fflush() {
    return this_.call(LITERAL_STRING[1770], {});
}
Variant SplFileObject::ftell() {
    return this_.call(LITERAL_STRING[1771], {});
}
Variant SplFileObject::fseek(const Variant &offset, const Variant &whence) {
    return this_.call(LITERAL_STRING[1772], {offset, whence});
}
Variant SplFileObject::fgetc() {
    return this_.call(LITERAL_STRING[1773], {});
}
Variant SplFileObject::fpassthru() {
    return this_.call(LITERAL_STRING[1774], {});
}
Variant SplFileObject::fwrite(const Variant &data, const Variant &length) {
    return this_.call(LITERAL_STRING[1776], {data, length});
}
Variant SplFileObject::fstat() {
    return this_.call(LITERAL_STRING[1777], {});
}
Variant SplFileObject::ftruncate(const Variant &size) {
    return this_.call(LITERAL_STRING[1778], {size});
}
Variant SplFileObject::current() {
    return this_.call(LITERAL_STRING[90], {});
}
Variant SplFileObject::key() {
    return this_.call(LITERAL_STRING[91], {});
}
Variant SplFileObject::next() {
    return this_.call(LITERAL_STRING[92], {});
}
Variant SplFileObject::setFlags(const Variant &flags) {
    return this_.call(LITERAL_STRING[918], {flags});
}
Variant SplFileObject::getFlags() {
    return this_.call(LITERAL_STRING[917], {});
}
Variant SplFileObject::setMaxLineLen(const Variant &max_length) {
    return this_.call(LITERAL_STRING[1779], {max_length});
}
Variant SplFileObject::getMaxLineLen() {
    return this_.call(LITERAL_STRING[1780], {});
}
Variant SplFileObject::hasChildren() {
    return this_.call(LITERAL_STRING[913], {});
}
Variant SplFileObject::getChildren() {
    return this_.call(LITERAL_STRING[914], {});
}
Variant SplFileObject::seek(const Variant &line) {
    return this_.call(LITERAL_STRING[922], {line});
}
Variant SplFileObject::getCurrentLine() {
    return this_.call(LITERAL_STRING[1781], {});
}
Variant SplFileObject::__toString() {
    return this_.call(LITERAL_STRING[29], {});
}
Variant SplFileObject::getPath() {
    return this_.call(LITERAL_STRING[880], {});
}
Variant SplFileObject::getFilename() {
    return this_.call(LITERAL_STRING[202], {});
}
Variant SplFileObject::getExtension() {
    return this_.call(LITERAL_STRING[919], {});
}
Variant SplFileObject::getBasename(const Variant &suffix) {
    return this_.call(LITERAL_STRING[920], {suffix});
}
Variant SplFileObject::getPathname() {
    return this_.call(LITERAL_STRING[923], {});
}
Variant SplFileObject::getPerms() {
    return this_.call(LITERAL_STRING[924], {});
}
Variant SplFileObject::getInode() {
    return this_.call(LITERAL_STRING[925], {});
}
Variant SplFileObject::getSize() {
    return this_.call(LITERAL_STRING[926], {});
}
Variant SplFileObject::getOwner() {
    return this_.call(LITERAL_STRING[927], {});
}
Variant SplFileObject::getGroup() {
    return this_.call(LITERAL_STRING[928], {});
}
Variant SplFileObject::getATime() {
    return this_.call(LITERAL_STRING[929], {});
}
Variant SplFileObject::getMTime() {
    return this_.call(LITERAL_STRING[930], {});
}
Variant SplFileObject::getCTime() {
    return this_.call(LITERAL_STRING[931], {});
}
Variant SplFileObject::getType() {
    return this_.call(LITERAL_STRING[932], {});
}
Variant SplFileObject::isWritable() {
    return this_.call(LITERAL_STRING[890], {});
}
Variant SplFileObject::isReadable() {
    return this_.call(LITERAL_STRING[933], {});
}
Variant SplFileObject::isExecutable() {
    return this_.call(LITERAL_STRING[934], {});
}
Variant SplFileObject::isFile() {
    return this_.call(LITERAL_STRING[935], {});
}
Variant SplFileObject::isDir() {
    return this_.call(LITERAL_STRING[936], {});
}
Variant SplFileObject::isLink() {
    return this_.call(LITERAL_STRING[937], {});
}
Variant SplFileObject::getLinkTarget() {
    return this_.call(LITERAL_STRING[938], {});
}
Variant SplFileObject::getRealPath() {
    return this_.call(LITERAL_STRING[939], {});
}
Variant SplFileObject::getFileInfo(const Variant &_class) {
    return this_.call(LITERAL_STRING[940], {_class});
}
Variant SplFileObject::getPathInfo(const Variant &_class) {
    return this_.call(LITERAL_STRING[941], {_class});
}
Variant SplFileObject::openFile(const Variant &mode, const Variant &use_include_path, const Variant &context) {
    return this_.call(LITERAL_STRING[942], {mode, use_include_path, context});
}
Variant SplFileObject::setFileClass(const Variant &_class) {
    return this_.call(LITERAL_STRING[943], {_class});
}
Variant SplFileObject::setInfoClass(const Variant &_class) {
    return this_.call(LITERAL_STRING[944], {_class});
}
Variant SplFileObject::__debugInfo() {
    return this_.call(LITERAL_STRING[126], {});
}
Variant SplFileObject::_bad_state_ex() {
    return this_.call(LITERAL_STRING[945], {});
}
SplTempFileObject::SplTempFileObject(const Variant &max_memory) {
    this_ = newObject(LITERAL_STRING[1782], {max_memory});
}
Variant SplTempFileObject::rewind() {
    return this_.call(LITERAL_STRING[94], {});
}
Variant SplTempFileObject::eof() {
    return this_.call(LITERAL_STRING[1762], {});
}
Variant SplTempFileObject::valid() {
    return this_.call(LITERAL_STRING[93], {});
}
Variant SplTempFileObject::fgets() {
    return this_.call(LITERAL_STRING[1763], {});
}
Variant SplTempFileObject::fread(const Variant &length) {
    return this_.call(LITERAL_STRING[1764], {length});
}
Variant SplTempFileObject::fgetcsv(const Variant &separator, const Variant &enclosure, const Variant &escape) {
    return this_.call(LITERAL_STRING[1765], {separator, enclosure, escape});
}
Variant SplTempFileObject::fputcsv(const Variant &fields,
                                   const Variant &separator,
                                   const Variant &enclosure,
                                   const Variant &escape,
                                   const Variant &eol) {
    return this_.call(LITERAL_STRING[1766], {fields, separator, enclosure, escape, eol});
}
Variant SplTempFileObject::setCsvControl(const Variant &separator, const Variant &enclosure, const Variant &escape) {
    return this_.call(LITERAL_STRING[1767], {separator, enclosure, escape});
}
Variant SplTempFileObject::getCsvControl() {
    return this_.call(LITERAL_STRING[1768], {});
}
Variant SplTempFileObject::flock(const Variant &operation, const Reference &would_block) {
    return this_.call(LITERAL_STRING[1769], {operation, &would_block});
}
Variant SplTempFileObject::fflush() {
    return this_.call(LITERAL_STRING[1770], {});
}
Variant SplTempFileObject::ftell() {
    return this_.call(LITERAL_STRING[1771], {});
}
Variant SplTempFileObject::fseek(const Variant &offset, const Variant &whence) {
    return this_.call(LITERAL_STRING[1772], {offset, whence});
}
Variant SplTempFileObject::fgetc() {
    return this_.call(LITERAL_STRING[1773], {});
}
Variant SplTempFileObject::fpassthru() {
    return this_.call(LITERAL_STRING[1774], {});
}
Variant SplTempFileObject::fwrite(const Variant &data, const Variant &length) {
    return this_.call(LITERAL_STRING[1776], {data, length});
}
Variant SplTempFileObject::fstat() {
    return this_.call(LITERAL_STRING[1777], {});
}
Variant SplTempFileObject::ftruncate(const Variant &size) {
    return this_.call(LITERAL_STRING[1778], {size});
}
Variant SplTempFileObject::current() {
    return this_.call(LITERAL_STRING[90], {});
}
Variant SplTempFileObject::key() {
    return this_.call(LITERAL_STRING[91], {});
}
Variant SplTempFileObject::next() {
    return this_.call(LITERAL_STRING[92], {});
}
Variant SplTempFileObject::setFlags(const Variant &flags) {
    return this_.call(LITERAL_STRING[918], {flags});
}
Variant SplTempFileObject::getFlags() {
    return this_.call(LITERAL_STRING[917], {});
}
Variant SplTempFileObject::setMaxLineLen(const Variant &max_length) {
    return this_.call(LITERAL_STRING[1779], {max_length});
}
Variant SplTempFileObject::getMaxLineLen() {
    return this_.call(LITERAL_STRING[1780], {});
}
Variant SplTempFileObject::hasChildren() {
    return this_.call(LITERAL_STRING[913], {});
}
Variant SplTempFileObject::getChildren() {
    return this_.call(LITERAL_STRING[914], {});
}
Variant SplTempFileObject::seek(const Variant &line) {
    return this_.call(LITERAL_STRING[922], {line});
}
Variant SplTempFileObject::getCurrentLine() {
    return this_.call(LITERAL_STRING[1781], {});
}
Variant SplTempFileObject::__toString() {
    return this_.call(LITERAL_STRING[29], {});
}
Variant SplTempFileObject::getPath() {
    return this_.call(LITERAL_STRING[880], {});
}
Variant SplTempFileObject::getFilename() {
    return this_.call(LITERAL_STRING[202], {});
}
Variant SplTempFileObject::getExtension() {
    return this_.call(LITERAL_STRING[919], {});
}
Variant SplTempFileObject::getBasename(const Variant &suffix) {
    return this_.call(LITERAL_STRING[920], {suffix});
}
Variant SplTempFileObject::getPathname() {
    return this_.call(LITERAL_STRING[923], {});
}
Variant SplTempFileObject::getPerms() {
    return this_.call(LITERAL_STRING[924], {});
}
Variant SplTempFileObject::getInode() {
    return this_.call(LITERAL_STRING[925], {});
}
Variant SplTempFileObject::getSize() {
    return this_.call(LITERAL_STRING[926], {});
}
Variant SplTempFileObject::getOwner() {
    return this_.call(LITERAL_STRING[927], {});
}
Variant SplTempFileObject::getGroup() {
    return this_.call(LITERAL_STRING[928], {});
}
Variant SplTempFileObject::getATime() {
    return this_.call(LITERAL_STRING[929], {});
}
Variant SplTempFileObject::getMTime() {
    return this_.call(LITERAL_STRING[930], {});
}
Variant SplTempFileObject::getCTime() {
    return this_.call(LITERAL_STRING[931], {});
}
Variant SplTempFileObject::getType() {
    return this_.call(LITERAL_STRING[932], {});
}
Variant SplTempFileObject::isWritable() {
    return this_.call(LITERAL_STRING[890], {});
}
Variant SplTempFileObject::isReadable() {
    return this_.call(LITERAL_STRING[933], {});
}
Variant SplTempFileObject::isExecutable() {
    return this_.call(LITERAL_STRING[934], {});
}
Variant SplTempFileObject::isFile() {
    return this_.call(LITERAL_STRING[935], {});
}
Variant SplTempFileObject::isDir() {
    return this_.call(LITERAL_STRING[936], {});
}
Variant SplTempFileObject::isLink() {
    return this_.call(LITERAL_STRING[937], {});
}
Variant SplTempFileObject::getLinkTarget() {
    return this_.call(LITERAL_STRING[938], {});
}
Variant SplTempFileObject::getRealPath() {
    return this_.call(LITERAL_STRING[939], {});
}
Variant SplTempFileObject::getFileInfo(const Variant &_class) {
    return this_.call(LITERAL_STRING[940], {_class});
}
Variant SplTempFileObject::getPathInfo(const Variant &_class) {
    return this_.call(LITERAL_STRING[941], {_class});
}
Variant SplTempFileObject::openFile(const Variant &mode, const Variant &use_include_path, const Variant &context) {
    return this_.call(LITERAL_STRING[942], {mode, use_include_path, context});
}
Variant SplTempFileObject::setFileClass(const Variant &_class) {
    return this_.call(LITERAL_STRING[943], {_class});
}
Variant SplTempFileObject::setInfoClass(const Variant &_class) {
    return this_.call(LITERAL_STRING[944], {_class});
}
Variant SplTempFileObject::__debugInfo() {
    return this_.call(LITERAL_STRING[126], {});
}
Variant SplTempFileObject::_bad_state_ex() {
    return this_.call(LITERAL_STRING[945], {});
}
Variant SplDoublyLinkedList::add(const Variant &index, const Variant &value) {
    return this_.call(LITERAL_STRING[16], {index, value});
}
Variant SplDoublyLinkedList::pop() {
    return this_.call(LITERAL_STRING[1783], {});
}
Variant SplDoublyLinkedList::shift() {
    return this_.call(LITERAL_STRING[1784], {});
}
Variant SplDoublyLinkedList::push(const Variant &value) {
    return this_.call(LITERAL_STRING[1785], {value});
}
Variant SplDoublyLinkedList::unshift(const Variant &value) {
    return this_.call(LITERAL_STRING[1786], {value});
}
Variant SplDoublyLinkedList::top() {
    return this_.call(LITERAL_STRING[1787], {});
}
Variant SplDoublyLinkedList::bottom() {
    return this_.call(LITERAL_STRING[1788], {});
}
Variant SplDoublyLinkedList::__debugInfo() {
    return this_.call(LITERAL_STRING[126], {});
}
Variant SplDoublyLinkedList::count() {
    return this_.call(LITERAL_STRING[136], {});
}
Variant SplDoublyLinkedList::isEmpty() {
    return this_.call(LITERAL_STRING[1789], {});
}
Variant SplDoublyLinkedList::setIteratorMode(const Variant &mode) {
    return this_.call(LITERAL_STRING[1790], {mode});
}
Variant SplDoublyLinkedList::getIteratorMode() {
    return this_.call(LITERAL_STRING[1791], {});
}
Variant SplDoublyLinkedList::offsetExists(const Variant &index) {
    return this_.call(LITERAL_STRING[134], {index});
}
Variant SplDoublyLinkedList::offsetGet(const Variant &index) {
    return this_.call(LITERAL_STRING[132], {index});
}
Variant SplDoublyLinkedList::offsetSet(const Variant &index, const Variant &value) {
    return this_.call(LITERAL_STRING[133], {index, value});
}
Variant SplDoublyLinkedList::offsetUnset(const Variant &index) {
    return this_.call(LITERAL_STRING[135], {index});
}
Variant SplDoublyLinkedList::rewind() {
    return this_.call(LITERAL_STRING[94], {});
}
Variant SplDoublyLinkedList::current() {
    return this_.call(LITERAL_STRING[90], {});
}
Variant SplDoublyLinkedList::key() {
    return this_.call(LITERAL_STRING[91], {});
}
Variant SplDoublyLinkedList::prev() {
    return this_.call(LITERAL_STRING[1792], {});
}
Variant SplDoublyLinkedList::next() {
    return this_.call(LITERAL_STRING[92], {});
}
Variant SplDoublyLinkedList::valid() {
    return this_.call(LITERAL_STRING[93], {});
}
Variant SplDoublyLinkedList::unserialize(const Variant &data) {
    return this_.call(LITERAL_STRING[1749], {data});
}
Variant SplDoublyLinkedList::serialize() {
    return this_.call(LITERAL_STRING[1750], {});
}
Variant SplDoublyLinkedList::__serialize() {
    return this_.call(LITERAL_STRING[30], {});
}
Variant SplDoublyLinkedList::__unserialize(const Variant &data) {
    return this_.call(LITERAL_STRING[31], {data});
}
Variant SplQueue::enqueue(const Variant &value) {
    return this_.call(LITERAL_STRING[1794], {value});
}
Variant SplQueue::dequeue() {
    return this_.call(LITERAL_STRING[1795], {});
}
Variant SplQueue::add(const Variant &index, const Variant &value) {
    return this_.call(LITERAL_STRING[16], {index, value});
}
Variant SplQueue::pop() {
    return this_.call(LITERAL_STRING[1783], {});
}
Variant SplQueue::shift() {
    return this_.call(LITERAL_STRING[1784], {});
}
Variant SplQueue::push(const Variant &value) {
    return this_.call(LITERAL_STRING[1785], {value});
}
Variant SplQueue::unshift(const Variant &value) {
    return this_.call(LITERAL_STRING[1786], {value});
}
Variant SplQueue::top() {
    return this_.call(LITERAL_STRING[1787], {});
}
Variant SplQueue::bottom() {
    return this_.call(LITERAL_STRING[1788], {});
}
Variant SplQueue::__debugInfo() {
    return this_.call(LITERAL_STRING[126], {});
}
Variant SplQueue::count() {
    return this_.call(LITERAL_STRING[136], {});
}
Variant SplQueue::isEmpty() {
    return this_.call(LITERAL_STRING[1789], {});
}
Variant SplQueue::setIteratorMode(const Variant &mode) {
    return this_.call(LITERAL_STRING[1790], {mode});
}
Variant SplQueue::getIteratorMode() {
    return this_.call(LITERAL_STRING[1791], {});
}
Variant SplQueue::offsetExists(const Variant &index) {
    return this_.call(LITERAL_STRING[134], {index});
}
Variant SplQueue::offsetGet(const Variant &index) {
    return this_.call(LITERAL_STRING[132], {index});
}
Variant SplQueue::offsetSet(const Variant &index, const Variant &value) {
    return this_.call(LITERAL_STRING[133], {index, value});
}
Variant SplQueue::offsetUnset(const Variant &index) {
    return this_.call(LITERAL_STRING[135], {index});
}
Variant SplQueue::rewind() {
    return this_.call(LITERAL_STRING[94], {});
}
Variant SplQueue::current() {
    return this_.call(LITERAL_STRING[90], {});
}
Variant SplQueue::key() {
    return this_.call(LITERAL_STRING[91], {});
}
Variant SplQueue::prev() {
    return this_.call(LITERAL_STRING[1792], {});
}
Variant SplQueue::next() {
    return this_.call(LITERAL_STRING[92], {});
}
Variant SplQueue::valid() {
    return this_.call(LITERAL_STRING[93], {});
}
Variant SplQueue::unserialize(const Variant &data) {
    return this_.call(LITERAL_STRING[1749], {data});
}
Variant SplQueue::serialize() {
    return this_.call(LITERAL_STRING[1750], {});
}
Variant SplQueue::__serialize() {
    return this_.call(LITERAL_STRING[30], {});
}
Variant SplQueue::__unserialize(const Variant &data) {
    return this_.call(LITERAL_STRING[31], {data});
}
Variant SplStack::add(const Variant &index, const Variant &value) {
    return this_.call(LITERAL_STRING[16], {index, value});
}
Variant SplStack::pop() {
    return this_.call(LITERAL_STRING[1783], {});
}
Variant SplStack::shift() {
    return this_.call(LITERAL_STRING[1784], {});
}
Variant SplStack::push(const Variant &value) {
    return this_.call(LITERAL_STRING[1785], {value});
}
Variant SplStack::unshift(const Variant &value) {
    return this_.call(LITERAL_STRING[1786], {value});
}
Variant SplStack::top() {
    return this_.call(LITERAL_STRING[1787], {});
}
Variant SplStack::bottom() {
    return this_.call(LITERAL_STRING[1788], {});
}
Variant SplStack::__debugInfo() {
    return this_.call(LITERAL_STRING[126], {});
}
Variant SplStack::count() {
    return this_.call(LITERAL_STRING[136], {});
}
Variant SplStack::isEmpty() {
    return this_.call(LITERAL_STRING[1789], {});
}
Variant SplStack::setIteratorMode(const Variant &mode) {
    return this_.call(LITERAL_STRING[1790], {mode});
}
Variant SplStack::getIteratorMode() {
    return this_.call(LITERAL_STRING[1791], {});
}
Variant SplStack::offsetExists(const Variant &index) {
    return this_.call(LITERAL_STRING[134], {index});
}
Variant SplStack::offsetGet(const Variant &index) {
    return this_.call(LITERAL_STRING[132], {index});
}
Variant SplStack::offsetSet(const Variant &index, const Variant &value) {
    return this_.call(LITERAL_STRING[133], {index, value});
}
Variant SplStack::offsetUnset(const Variant &index) {
    return this_.call(LITERAL_STRING[135], {index});
}
Variant SplStack::rewind() {
    return this_.call(LITERAL_STRING[94], {});
}
Variant SplStack::current() {
    return this_.call(LITERAL_STRING[90], {});
}
Variant SplStack::key() {
    return this_.call(LITERAL_STRING[91], {});
}
Variant SplStack::prev() {
    return this_.call(LITERAL_STRING[1792], {});
}
Variant SplStack::next() {
    return this_.call(LITERAL_STRING[92], {});
}
Variant SplStack::valid() {
    return this_.call(LITERAL_STRING[93], {});
}
Variant SplStack::unserialize(const Variant &data) {
    return this_.call(LITERAL_STRING[1749], {data});
}
Variant SplStack::serialize() {
    return this_.call(LITERAL_STRING[1750], {});
}
Variant SplStack::__serialize() {
    return this_.call(LITERAL_STRING[30], {});
}
Variant SplStack::__unserialize(const Variant &data) {
    return this_.call(LITERAL_STRING[31], {data});
}
Variant SplMinHeap::extract() {
    return this_.call(LITERAL_STRING[1798], {});
}
Variant SplMinHeap::insert(const Variant &value) {
    return this_.call(LITERAL_STRING[1799], {value});
}
Variant SplMinHeap::top() {
    return this_.call(LITERAL_STRING[1787], {});
}
Variant SplMinHeap::count() {
    return this_.call(LITERAL_STRING[136], {});
}
Variant SplMinHeap::isEmpty() {
    return this_.call(LITERAL_STRING[1789], {});
}
Variant SplMinHeap::rewind() {
    return this_.call(LITERAL_STRING[94], {});
}
Variant SplMinHeap::current() {
    return this_.call(LITERAL_STRING[90], {});
}
Variant SplMinHeap::key() {
    return this_.call(LITERAL_STRING[91], {});
}
Variant SplMinHeap::next() {
    return this_.call(LITERAL_STRING[92], {});
}
Variant SplMinHeap::valid() {
    return this_.call(LITERAL_STRING[93], {});
}
Variant SplMinHeap::recoverFromCorruption() {
    return this_.call(LITERAL_STRING[1800], {});
}
Variant SplMinHeap::isCorrupted() {
    return this_.call(LITERAL_STRING[1801], {});
}
Variant SplMinHeap::__debugInfo() {
    return this_.call(LITERAL_STRING[126], {});
}
Variant SplMaxHeap::extract() {
    return this_.call(LITERAL_STRING[1798], {});
}
Variant SplMaxHeap::insert(const Variant &value) {
    return this_.call(LITERAL_STRING[1799], {value});
}
Variant SplMaxHeap::top() {
    return this_.call(LITERAL_STRING[1787], {});
}
Variant SplMaxHeap::count() {
    return this_.call(LITERAL_STRING[136], {});
}
Variant SplMaxHeap::isEmpty() {
    return this_.call(LITERAL_STRING[1789], {});
}
Variant SplMaxHeap::rewind() {
    return this_.call(LITERAL_STRING[94], {});
}
Variant SplMaxHeap::current() {
    return this_.call(LITERAL_STRING[90], {});
}
Variant SplMaxHeap::key() {
    return this_.call(LITERAL_STRING[91], {});
}
Variant SplMaxHeap::next() {
    return this_.call(LITERAL_STRING[92], {});
}
Variant SplMaxHeap::valid() {
    return this_.call(LITERAL_STRING[93], {});
}
Variant SplMaxHeap::recoverFromCorruption() {
    return this_.call(LITERAL_STRING[1800], {});
}
Variant SplMaxHeap::isCorrupted() {
    return this_.call(LITERAL_STRING[1801], {});
}
Variant SplMaxHeap::__debugInfo() {
    return this_.call(LITERAL_STRING[126], {});
}
Variant SplPriorityQueue::compare(const Variant &priority1, const Variant &priority2) {
    return this_.call(LITERAL_STRING[28], {priority1, priority2});
}
Variant SplPriorityQueue::insert(const Variant &value, const Variant &priority) {
    return this_.call(LITERAL_STRING[1799], {value, priority});
}
Variant SplPriorityQueue::setExtractFlags(const Variant &flags) {
    return this_.call(LITERAL_STRING[1804], {flags});
}
Variant SplPriorityQueue::top() {
    return this_.call(LITERAL_STRING[1787], {});
}
Variant SplPriorityQueue::extract() {
    return this_.call(LITERAL_STRING[1798], {});
}
Variant SplPriorityQueue::count() {
    return this_.call(LITERAL_STRING[136], {});
}
Variant SplPriorityQueue::isEmpty() {
    return this_.call(LITERAL_STRING[1789], {});
}
Variant SplPriorityQueue::rewind() {
    return this_.call(LITERAL_STRING[94], {});
}
Variant SplPriorityQueue::current() {
    return this_.call(LITERAL_STRING[90], {});
}
Variant SplPriorityQueue::key() {
    return this_.call(LITERAL_STRING[91], {});
}
Variant SplPriorityQueue::next() {
    return this_.call(LITERAL_STRING[92], {});
}
Variant SplPriorityQueue::valid() {
    return this_.call(LITERAL_STRING[93], {});
}
Variant SplPriorityQueue::recoverFromCorruption() {
    return this_.call(LITERAL_STRING[1800], {});
}
Variant SplPriorityQueue::isCorrupted() {
    return this_.call(LITERAL_STRING[1801], {});
}
Variant SplPriorityQueue::getExtractFlags() {
    return this_.call(LITERAL_STRING[1805], {});
}
Variant SplPriorityQueue::__debugInfo() {
    return this_.call(LITERAL_STRING[126], {});
}
SplFixedArray::SplFixedArray(const Variant &size) {
    this_ = newObject(LITERAL_STRING[1807], {size});
}
Variant SplFixedArray::__wakeup() {
    return this_.call(LITERAL_STRING[97], {});
}
Variant SplFixedArray::__serialize() {
    return this_.call(LITERAL_STRING[30], {});
}
Variant SplFixedArray::__unserialize(const Variant &data) {
    return this_.call(LITERAL_STRING[31], {data});
}
Variant SplFixedArray::count() {
    return this_.call(LITERAL_STRING[136], {});
}
Variant SplFixedArray::toArray() {
    return this_.call(LITERAL_STRING[1808], {});
}
Variant SplFixedArray::fromArray(const Variant &array, const Variant &preserve_keys) {
    return php::call(LITERAL_STRING[1809], {array, preserve_keys});
}
Variant SplFixedArray::getSize() {
    return this_.call(LITERAL_STRING[926], {});
}
Variant SplFixedArray::setSize(const Variant &size) {
    return this_.call(LITERAL_STRING[1810], {size});
}
Variant SplFixedArray::offsetExists(const Variant &index) {
    return this_.call(LITERAL_STRING[134], {index});
}
Variant SplFixedArray::offsetGet(const Variant &index) {
    return this_.call(LITERAL_STRING[132], {index});
}
Variant SplFixedArray::offsetSet(const Variant &index, const Variant &value) {
    return this_.call(LITERAL_STRING[133], {index, value});
}
Variant SplFixedArray::offsetUnset(const Variant &index) {
    return this_.call(LITERAL_STRING[135], {index});
}
Variant SplFixedArray::getIterator() {
    return this_.call(LITERAL_STRING[137], {});
}
Variant SplFixedArray::jsonSerialize() {
    return this_.call(LITERAL_STRING[1811], {});
}
Variant SplObjectStorage::attach(const Variant &object, const Variant &info) {
    return this_.call(LITERAL_STRING[1812], {object, info});
}
Variant SplObjectStorage::detach(const Variant &object) {
    return this_.call(LITERAL_STRING[1813], {object});
}
Variant SplObjectStorage::contains(const Variant &object) {
    return this_.call(LITERAL_STRING[340], {object});
}
Variant SplObjectStorage::addAll(const Variant &storage) {
    return this_.call(LITERAL_STRING[1814], {storage});
}
Variant SplObjectStorage::removeAll(const Variant &storage) {
    return this_.call(LITERAL_STRING[1815], {storage});
}
Variant SplObjectStorage::removeAllExcept(const Variant &storage) {
    return this_.call(LITERAL_STRING[1816], {storage});
}
Variant SplObjectStorage::getInfo() {
    return this_.call(LITERAL_STRING[1817], {});
}
Variant SplObjectStorage::setInfo(const Variant &info) {
    return this_.call(LITERAL_STRING[1818], {info});
}
Variant SplObjectStorage::count(const Variant &mode) {
    return this_.call(LITERAL_STRING[136], {mode});
}
Variant SplObjectStorage::rewind() {
    return this_.call(LITERAL_STRING[94], {});
}
Variant SplObjectStorage::valid() {
    return this_.call(LITERAL_STRING[93], {});
}
Variant SplObjectStorage::key() {
    return this_.call(LITERAL_STRING[91], {});
}
Variant SplObjectStorage::current() {
    return this_.call(LITERAL_STRING[90], {});
}
Variant SplObjectStorage::next() {
    return this_.call(LITERAL_STRING[92], {});
}
Variant SplObjectStorage::seek(const Variant &offset) {
    return this_.call(LITERAL_STRING[922], {offset});
}
Variant SplObjectStorage::unserialize(const Variant &data) {
    return this_.call(LITERAL_STRING[1749], {data});
}
Variant SplObjectStorage::serialize() {
    return this_.call(LITERAL_STRING[1750], {});
}
Variant SplObjectStorage::offsetExists(const Variant &object) {
    return this_.call(LITERAL_STRING[134], {object});
}
Variant SplObjectStorage::offsetGet(const Variant &object) {
    return this_.call(LITERAL_STRING[132], {object});
}
Variant SplObjectStorage::offsetSet(const Variant &object, const Variant &info) {
    return this_.call(LITERAL_STRING[133], {object, info});
}
Variant SplObjectStorage::offsetUnset(const Variant &object) {
    return this_.call(LITERAL_STRING[135], {object});
}
Variant SplObjectStorage::getHash(const Variant &object) {
    return this_.call(LITERAL_STRING[1819], {object});
}
Variant SplObjectStorage::__serialize() {
    return this_.call(LITERAL_STRING[30], {});
}
Variant SplObjectStorage::__unserialize(const Variant &data) {
    return this_.call(LITERAL_STRING[31], {data});
}
Variant SplObjectStorage::__debugInfo() {
    return this_.call(LITERAL_STRING[126], {});
}
MultipleIterator::MultipleIterator(const Variant &flags) {
    this_ = newObject(LITERAL_STRING[1821], {flags});
}
Variant MultipleIterator::getFlags() {
    return this_.call(LITERAL_STRING[917], {});
}
Variant MultipleIterator::setFlags(const Variant &flags) {
    return this_.call(LITERAL_STRING[918], {flags});
}
Variant MultipleIterator::attachIterator(const Variant &iterator, const Variant &info) {
    return this_.call(LITERAL_STRING[1822], {iterator, info});
}
Variant MultipleIterator::detachIterator(const Variant &iterator) {
    return this_.call(LITERAL_STRING[1823], {iterator});
}
Variant MultipleIterator::containsIterator(const Variant &iterator) {
    return this_.call(LITERAL_STRING[1824], {iterator});
}
Variant MultipleIterator::countIterators() {
    return this_.call(LITERAL_STRING[1825], {});
}
Variant MultipleIterator::rewind() {
    return this_.call(LITERAL_STRING[94], {});
}
Variant MultipleIterator::valid() {
    return this_.call(LITERAL_STRING[93], {});
}
Variant MultipleIterator::key() {
    return this_.call(LITERAL_STRING[91], {});
}
Variant MultipleIterator::current() {
    return this_.call(LITERAL_STRING[90], {});
}
Variant MultipleIterator::next() {
    return this_.call(LITERAL_STRING[92], {});
}
Variant MultipleIterator::__debugInfo() {
    return this_.call(LITERAL_STRING[126], {});
}
}  // namespace php

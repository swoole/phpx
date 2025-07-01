#include "phpx.h"
#include "class/spl.h"

namespace php {
LogicException::LogicException(const Variant &message, const Variant &code, const Variant &previous) {
    _this = newObject("LogicException", message, code, previous);
}

Variant LogicException::__wakeup() {
    return std::move(_this.exec("__wakeup"));
}

Variant LogicException::getMessage() {
    return std::move(_this.exec("getMessage"));
}

Variant LogicException::getCode() {
    return std::move(_this.exec("getCode"));
}

Variant LogicException::getFile() {
    return std::move(_this.exec("getFile"));
}

Variant LogicException::getLine() {
    return std::move(_this.exec("getLine"));
}

Variant LogicException::getTrace() {
    return std::move(_this.exec("getTrace"));
}

Variant LogicException::getPrevious() {
    return std::move(_this.exec("getPrevious"));
}

Variant LogicException::getTraceAsString() {
    return std::move(_this.exec("getTraceAsString"));
}

Variant LogicException::__toString() {
    return std::move(_this.exec("__toString"));
}


BadFunctionCallException::BadFunctionCallException(const Variant &message, const Variant &code, const Variant &previous) {
    _this = newObject("BadFunctionCallException", message, code, previous);
}

Variant BadFunctionCallException::__wakeup() {
    return std::move(_this.exec("__wakeup"));
}

Variant BadFunctionCallException::getMessage() {
    return std::move(_this.exec("getMessage"));
}

Variant BadFunctionCallException::getCode() {
    return std::move(_this.exec("getCode"));
}

Variant BadFunctionCallException::getFile() {
    return std::move(_this.exec("getFile"));
}

Variant BadFunctionCallException::getLine() {
    return std::move(_this.exec("getLine"));
}

Variant BadFunctionCallException::getTrace() {
    return std::move(_this.exec("getTrace"));
}

Variant BadFunctionCallException::getPrevious() {
    return std::move(_this.exec("getPrevious"));
}

Variant BadFunctionCallException::getTraceAsString() {
    return std::move(_this.exec("getTraceAsString"));
}

Variant BadFunctionCallException::__toString() {
    return std::move(_this.exec("__toString"));
}


BadMethodCallException::BadMethodCallException(const Variant &message, const Variant &code, const Variant &previous) {
    _this = newObject("BadMethodCallException", message, code, previous);
}

Variant BadMethodCallException::__wakeup() {
    return std::move(_this.exec("__wakeup"));
}

Variant BadMethodCallException::getMessage() {
    return std::move(_this.exec("getMessage"));
}

Variant BadMethodCallException::getCode() {
    return std::move(_this.exec("getCode"));
}

Variant BadMethodCallException::getFile() {
    return std::move(_this.exec("getFile"));
}

Variant BadMethodCallException::getLine() {
    return std::move(_this.exec("getLine"));
}

Variant BadMethodCallException::getTrace() {
    return std::move(_this.exec("getTrace"));
}

Variant BadMethodCallException::getPrevious() {
    return std::move(_this.exec("getPrevious"));
}

Variant BadMethodCallException::getTraceAsString() {
    return std::move(_this.exec("getTraceAsString"));
}

Variant BadMethodCallException::__toString() {
    return std::move(_this.exec("__toString"));
}


DomainException::DomainException(const Variant &message, const Variant &code, const Variant &previous) {
    _this = newObject("DomainException", message, code, previous);
}

Variant DomainException::__wakeup() {
    return std::move(_this.exec("__wakeup"));
}

Variant DomainException::getMessage() {
    return std::move(_this.exec("getMessage"));
}

Variant DomainException::getCode() {
    return std::move(_this.exec("getCode"));
}

Variant DomainException::getFile() {
    return std::move(_this.exec("getFile"));
}

Variant DomainException::getLine() {
    return std::move(_this.exec("getLine"));
}

Variant DomainException::getTrace() {
    return std::move(_this.exec("getTrace"));
}

Variant DomainException::getPrevious() {
    return std::move(_this.exec("getPrevious"));
}

Variant DomainException::getTraceAsString() {
    return std::move(_this.exec("getTraceAsString"));
}

Variant DomainException::__toString() {
    return std::move(_this.exec("__toString"));
}


InvalidArgumentException::InvalidArgumentException(const Variant &message, const Variant &code, const Variant &previous) {
    _this = newObject("InvalidArgumentException", message, code, previous);
}

Variant InvalidArgumentException::__wakeup() {
    return std::move(_this.exec("__wakeup"));
}

Variant InvalidArgumentException::getMessage() {
    return std::move(_this.exec("getMessage"));
}

Variant InvalidArgumentException::getCode() {
    return std::move(_this.exec("getCode"));
}

Variant InvalidArgumentException::getFile() {
    return std::move(_this.exec("getFile"));
}

Variant InvalidArgumentException::getLine() {
    return std::move(_this.exec("getLine"));
}

Variant InvalidArgumentException::getTrace() {
    return std::move(_this.exec("getTrace"));
}

Variant InvalidArgumentException::getPrevious() {
    return std::move(_this.exec("getPrevious"));
}

Variant InvalidArgumentException::getTraceAsString() {
    return std::move(_this.exec("getTraceAsString"));
}

Variant InvalidArgumentException::__toString() {
    return std::move(_this.exec("__toString"));
}


LengthException::LengthException(const Variant &message, const Variant &code, const Variant &previous) {
    _this = newObject("LengthException", message, code, previous);
}

Variant LengthException::__wakeup() {
    return std::move(_this.exec("__wakeup"));
}

Variant LengthException::getMessage() {
    return std::move(_this.exec("getMessage"));
}

Variant LengthException::getCode() {
    return std::move(_this.exec("getCode"));
}

Variant LengthException::getFile() {
    return std::move(_this.exec("getFile"));
}

Variant LengthException::getLine() {
    return std::move(_this.exec("getLine"));
}

Variant LengthException::getTrace() {
    return std::move(_this.exec("getTrace"));
}

Variant LengthException::getPrevious() {
    return std::move(_this.exec("getPrevious"));
}

Variant LengthException::getTraceAsString() {
    return std::move(_this.exec("getTraceAsString"));
}

Variant LengthException::__toString() {
    return std::move(_this.exec("__toString"));
}


OutOfRangeException::OutOfRangeException(const Variant &message, const Variant &code, const Variant &previous) {
    _this = newObject("OutOfRangeException", message, code, previous);
}

Variant OutOfRangeException::__wakeup() {
    return std::move(_this.exec("__wakeup"));
}

Variant OutOfRangeException::getMessage() {
    return std::move(_this.exec("getMessage"));
}

Variant OutOfRangeException::getCode() {
    return std::move(_this.exec("getCode"));
}

Variant OutOfRangeException::getFile() {
    return std::move(_this.exec("getFile"));
}

Variant OutOfRangeException::getLine() {
    return std::move(_this.exec("getLine"));
}

Variant OutOfRangeException::getTrace() {
    return std::move(_this.exec("getTrace"));
}

Variant OutOfRangeException::getPrevious() {
    return std::move(_this.exec("getPrevious"));
}

Variant OutOfRangeException::getTraceAsString() {
    return std::move(_this.exec("getTraceAsString"));
}

Variant OutOfRangeException::__toString() {
    return std::move(_this.exec("__toString"));
}


RuntimeException::RuntimeException(const Variant &message, const Variant &code, const Variant &previous) {
    _this = newObject("RuntimeException", message, code, previous);
}

Variant RuntimeException::__wakeup() {
    return std::move(_this.exec("__wakeup"));
}

Variant RuntimeException::getMessage() {
    return std::move(_this.exec("getMessage"));
}

Variant RuntimeException::getCode() {
    return std::move(_this.exec("getCode"));
}

Variant RuntimeException::getFile() {
    return std::move(_this.exec("getFile"));
}

Variant RuntimeException::getLine() {
    return std::move(_this.exec("getLine"));
}

Variant RuntimeException::getTrace() {
    return std::move(_this.exec("getTrace"));
}

Variant RuntimeException::getPrevious() {
    return std::move(_this.exec("getPrevious"));
}

Variant RuntimeException::getTraceAsString() {
    return std::move(_this.exec("getTraceAsString"));
}

Variant RuntimeException::__toString() {
    return std::move(_this.exec("__toString"));
}


OutOfBoundsException::OutOfBoundsException(const Variant &message, const Variant &code, const Variant &previous) {
    _this = newObject("OutOfBoundsException", message, code, previous);
}

Variant OutOfBoundsException::__wakeup() {
    return std::move(_this.exec("__wakeup"));
}

Variant OutOfBoundsException::getMessage() {
    return std::move(_this.exec("getMessage"));
}

Variant OutOfBoundsException::getCode() {
    return std::move(_this.exec("getCode"));
}

Variant OutOfBoundsException::getFile() {
    return std::move(_this.exec("getFile"));
}

Variant OutOfBoundsException::getLine() {
    return std::move(_this.exec("getLine"));
}

Variant OutOfBoundsException::getTrace() {
    return std::move(_this.exec("getTrace"));
}

Variant OutOfBoundsException::getPrevious() {
    return std::move(_this.exec("getPrevious"));
}

Variant OutOfBoundsException::getTraceAsString() {
    return std::move(_this.exec("getTraceAsString"));
}

Variant OutOfBoundsException::__toString() {
    return std::move(_this.exec("__toString"));
}


OverflowException::OverflowException(const Variant &message, const Variant &code, const Variant &previous) {
    _this = newObject("OverflowException", message, code, previous);
}

Variant OverflowException::__wakeup() {
    return std::move(_this.exec("__wakeup"));
}

Variant OverflowException::getMessage() {
    return std::move(_this.exec("getMessage"));
}

Variant OverflowException::getCode() {
    return std::move(_this.exec("getCode"));
}

Variant OverflowException::getFile() {
    return std::move(_this.exec("getFile"));
}

Variant OverflowException::getLine() {
    return std::move(_this.exec("getLine"));
}

Variant OverflowException::getTrace() {
    return std::move(_this.exec("getTrace"));
}

Variant OverflowException::getPrevious() {
    return std::move(_this.exec("getPrevious"));
}

Variant OverflowException::getTraceAsString() {
    return std::move(_this.exec("getTraceAsString"));
}

Variant OverflowException::__toString() {
    return std::move(_this.exec("__toString"));
}


RangeException::RangeException(const Variant &message, const Variant &code, const Variant &previous) {
    _this = newObject("RangeException", message, code, previous);
}

Variant RangeException::__wakeup() {
    return std::move(_this.exec("__wakeup"));
}

Variant RangeException::getMessage() {
    return std::move(_this.exec("getMessage"));
}

Variant RangeException::getCode() {
    return std::move(_this.exec("getCode"));
}

Variant RangeException::getFile() {
    return std::move(_this.exec("getFile"));
}

Variant RangeException::getLine() {
    return std::move(_this.exec("getLine"));
}

Variant RangeException::getTrace() {
    return std::move(_this.exec("getTrace"));
}

Variant RangeException::getPrevious() {
    return std::move(_this.exec("getPrevious"));
}

Variant RangeException::getTraceAsString() {
    return std::move(_this.exec("getTraceAsString"));
}

Variant RangeException::__toString() {
    return std::move(_this.exec("__toString"));
}


UnderflowException::UnderflowException(const Variant &message, const Variant &code, const Variant &previous) {
    _this = newObject("UnderflowException", message, code, previous);
}

Variant UnderflowException::__wakeup() {
    return std::move(_this.exec("__wakeup"));
}

Variant UnderflowException::getMessage() {
    return std::move(_this.exec("getMessage"));
}

Variant UnderflowException::getCode() {
    return std::move(_this.exec("getCode"));
}

Variant UnderflowException::getFile() {
    return std::move(_this.exec("getFile"));
}

Variant UnderflowException::getLine() {
    return std::move(_this.exec("getLine"));
}

Variant UnderflowException::getTrace() {
    return std::move(_this.exec("getTrace"));
}

Variant UnderflowException::getPrevious() {
    return std::move(_this.exec("getPrevious"));
}

Variant UnderflowException::getTraceAsString() {
    return std::move(_this.exec("getTraceAsString"));
}

Variant UnderflowException::__toString() {
    return std::move(_this.exec("__toString"));
}


UnexpectedValueException::UnexpectedValueException(const Variant &message, const Variant &code, const Variant &previous) {
    _this = newObject("UnexpectedValueException", message, code, previous);
}

Variant UnexpectedValueException::__wakeup() {
    return std::move(_this.exec("__wakeup"));
}

Variant UnexpectedValueException::getMessage() {
    return std::move(_this.exec("getMessage"));
}

Variant UnexpectedValueException::getCode() {
    return std::move(_this.exec("getCode"));
}

Variant UnexpectedValueException::getFile() {
    return std::move(_this.exec("getFile"));
}

Variant UnexpectedValueException::getLine() {
    return std::move(_this.exec("getLine"));
}

Variant UnexpectedValueException::getTrace() {
    return std::move(_this.exec("getTrace"));
}

Variant UnexpectedValueException::getPrevious() {
    return std::move(_this.exec("getPrevious"));
}

Variant UnexpectedValueException::getTraceAsString() {
    return std::move(_this.exec("getTraceAsString"));
}

Variant UnexpectedValueException::__toString() {
    return std::move(_this.exec("__toString"));
}


RecursiveIteratorIterator::RecursiveIteratorIterator(const Variant &iterator, const Variant &mode, const Variant &flags) {
    _this = newObject("RecursiveIteratorIterator", iterator, mode, flags);
}

Variant RecursiveIteratorIterator::rewind() {
    return std::move(_this.exec("rewind"));
}

Variant RecursiveIteratorIterator::valid() {
    return std::move(_this.exec("valid"));
}

Variant RecursiveIteratorIterator::key() {
    return std::move(_this.exec("key"));
}

Variant RecursiveIteratorIterator::current() {
    return std::move(_this.exec("current"));
}

Variant RecursiveIteratorIterator::next() {
    return std::move(_this.exec("next"));
}

Variant RecursiveIteratorIterator::getDepth() {
    return std::move(_this.exec("getDepth"));
}

Variant RecursiveIteratorIterator::getSubIterator(const Variant &level) {
    return std::move(_this.exec("getSubIterator", level));
}

Variant RecursiveIteratorIterator::getInnerIterator() {
    return std::move(_this.exec("getInnerIterator"));
}

Variant RecursiveIteratorIterator::beginIteration() {
    return std::move(_this.exec("beginIteration"));
}

Variant RecursiveIteratorIterator::endIteration() {
    return std::move(_this.exec("endIteration"));
}

Variant RecursiveIteratorIterator::callHasChildren() {
    return std::move(_this.exec("callHasChildren"));
}

Variant RecursiveIteratorIterator::callGetChildren() {
    return std::move(_this.exec("callGetChildren"));
}

Variant RecursiveIteratorIterator::beginChildren() {
    return std::move(_this.exec("beginChildren"));
}

Variant RecursiveIteratorIterator::endChildren() {
    return std::move(_this.exec("endChildren"));
}

Variant RecursiveIteratorIterator::nextElement() {
    return std::move(_this.exec("nextElement"));
}

Variant RecursiveIteratorIterator::setMaxDepth(const Variant &max_depth) {
    return std::move(_this.exec("setMaxDepth", max_depth));
}

Variant RecursiveIteratorIterator::getMaxDepth() {
    return std::move(_this.exec("getMaxDepth"));
}


IteratorIterator::IteratorIterator(const Variant &iterator, const Variant &_class) {
    _this = newObject("IteratorIterator", iterator, _class);
}

Variant IteratorIterator::getInnerIterator() {
    return std::move(_this.exec("getInnerIterator"));
}

Variant IteratorIterator::rewind() {
    return std::move(_this.exec("rewind"));
}

Variant IteratorIterator::valid() {
    return std::move(_this.exec("valid"));
}

Variant IteratorIterator::key() {
    return std::move(_this.exec("key"));
}

Variant IteratorIterator::current() {
    return std::move(_this.exec("current"));
}

Variant IteratorIterator::next() {
    return std::move(_this.exec("next"));
}


CallbackFilterIterator::CallbackFilterIterator(const Variant &iterator, const Variant &callback) {
    _this = newObject("CallbackFilterIterator", iterator, callback);
}

Variant CallbackFilterIterator::accept() {
    return std::move(_this.exec("accept"));
}

Variant CallbackFilterIterator::rewind() {
    return std::move(_this.exec("rewind"));
}

Variant CallbackFilterIterator::next() {
    return std::move(_this.exec("next"));
}

Variant CallbackFilterIterator::getInnerIterator() {
    return std::move(_this.exec("getInnerIterator"));
}

Variant CallbackFilterIterator::valid() {
    return std::move(_this.exec("valid"));
}

Variant CallbackFilterIterator::key() {
    return std::move(_this.exec("key"));
}

Variant CallbackFilterIterator::current() {
    return std::move(_this.exec("current"));
}


RecursiveCallbackFilterIterator::RecursiveCallbackFilterIterator(const Variant &iterator, const Variant &callback) {
    _this = newObject("RecursiveCallbackFilterIterator", iterator, callback);
}

Variant RecursiveCallbackFilterIterator::hasChildren() {
    return std::move(_this.exec("hasChildren"));
}

Variant RecursiveCallbackFilterIterator::getChildren() {
    return std::move(_this.exec("getChildren"));
}

Variant RecursiveCallbackFilterIterator::accept() {
    return std::move(_this.exec("accept"));
}

Variant RecursiveCallbackFilterIterator::rewind() {
    return std::move(_this.exec("rewind"));
}

Variant RecursiveCallbackFilterIterator::next() {
    return std::move(_this.exec("next"));
}

Variant RecursiveCallbackFilterIterator::getInnerIterator() {
    return std::move(_this.exec("getInnerIterator"));
}

Variant RecursiveCallbackFilterIterator::valid() {
    return std::move(_this.exec("valid"));
}

Variant RecursiveCallbackFilterIterator::key() {
    return std::move(_this.exec("key"));
}

Variant RecursiveCallbackFilterIterator::current() {
    return std::move(_this.exec("current"));
}


ParentIterator::ParentIterator(const Variant &iterator) {
    _this = newObject("ParentIterator", iterator);
}

Variant ParentIterator::accept() {
    return std::move(_this.exec("accept"));
}

Variant ParentIterator::hasChildren() {
    return std::move(_this.exec("hasChildren"));
}

Variant ParentIterator::getChildren() {
    return std::move(_this.exec("getChildren"));
}

Variant ParentIterator::rewind() {
    return std::move(_this.exec("rewind"));
}

Variant ParentIterator::next() {
    return std::move(_this.exec("next"));
}

Variant ParentIterator::getInnerIterator() {
    return std::move(_this.exec("getInnerIterator"));
}

Variant ParentIterator::valid() {
    return std::move(_this.exec("valid"));
}

Variant ParentIterator::key() {
    return std::move(_this.exec("key"));
}

Variant ParentIterator::current() {
    return std::move(_this.exec("current"));
}


LimitIterator::LimitIterator(const Variant &iterator, const Variant &offset, const Variant &limit) {
    _this = newObject("LimitIterator", iterator, offset, limit);
}

Variant LimitIterator::rewind() {
    return std::move(_this.exec("rewind"));
}

Variant LimitIterator::valid() {
    return std::move(_this.exec("valid"));
}

Variant LimitIterator::next() {
    return std::move(_this.exec("next"));
}

Variant LimitIterator::seek(const Variant &offset) {
    return std::move(_this.exec("seek", offset));
}

Variant LimitIterator::getPosition() {
    return std::move(_this.exec("getPosition"));
}

Variant LimitIterator::getInnerIterator() {
    return std::move(_this.exec("getInnerIterator"));
}

Variant LimitIterator::key() {
    return std::move(_this.exec("key"));
}

Variant LimitIterator::current() {
    return std::move(_this.exec("current"));
}


CachingIterator::CachingIterator(const Variant &iterator, const Variant &flags) {
    _this = newObject("CachingIterator", iterator, flags);
}

Variant CachingIterator::rewind() {
    return std::move(_this.exec("rewind"));
}

Variant CachingIterator::valid() {
    return std::move(_this.exec("valid"));
}

Variant CachingIterator::next() {
    return std::move(_this.exec("next"));
}

Variant CachingIterator::hasNext() {
    return std::move(_this.exec("hasNext"));
}

Variant CachingIterator::__toString() {
    return std::move(_this.exec("__toString"));
}

Variant CachingIterator::getFlags() {
    return std::move(_this.exec("getFlags"));
}

Variant CachingIterator::setFlags(const Variant &flags) {
    return std::move(_this.exec("setFlags", flags));
}

Variant CachingIterator::offsetGet(const Variant &key) {
    return std::move(_this.exec("offsetGet", key));
}

Variant CachingIterator::offsetSet(const Variant &key, const Variant &value) {
    return std::move(_this.exec("offsetSet", key, value));
}

Variant CachingIterator::offsetUnset(const Variant &key) {
    return std::move(_this.exec("offsetUnset", key));
}

Variant CachingIterator::offsetExists(const Variant &key) {
    return std::move(_this.exec("offsetExists", key));
}

Variant CachingIterator::getCache() {
    return std::move(_this.exec("getCache"));
}

Variant CachingIterator::count() {
    return std::move(_this.exec("count"));
}

Variant CachingIterator::getInnerIterator() {
    return std::move(_this.exec("getInnerIterator"));
}

Variant CachingIterator::key() {
    return std::move(_this.exec("key"));
}

Variant CachingIterator::current() {
    return std::move(_this.exec("current"));
}


RecursiveCachingIterator::RecursiveCachingIterator(const Variant &iterator, const Variant &flags) {
    _this = newObject("RecursiveCachingIterator", iterator, flags);
}

Variant RecursiveCachingIterator::hasChildren() {
    return std::move(_this.exec("hasChildren"));
}

Variant RecursiveCachingIterator::getChildren() {
    return std::move(_this.exec("getChildren"));
}

Variant RecursiveCachingIterator::rewind() {
    return std::move(_this.exec("rewind"));
}

Variant RecursiveCachingIterator::valid() {
    return std::move(_this.exec("valid"));
}

Variant RecursiveCachingIterator::next() {
    return std::move(_this.exec("next"));
}

Variant RecursiveCachingIterator::hasNext() {
    return std::move(_this.exec("hasNext"));
}

Variant RecursiveCachingIterator::__toString() {
    return std::move(_this.exec("__toString"));
}

Variant RecursiveCachingIterator::getFlags() {
    return std::move(_this.exec("getFlags"));
}

Variant RecursiveCachingIterator::setFlags(const Variant &flags) {
    return std::move(_this.exec("setFlags", flags));
}

Variant RecursiveCachingIterator::offsetGet(const Variant &key) {
    return std::move(_this.exec("offsetGet", key));
}

Variant RecursiveCachingIterator::offsetSet(const Variant &key, const Variant &value) {
    return std::move(_this.exec("offsetSet", key, value));
}

Variant RecursiveCachingIterator::offsetUnset(const Variant &key) {
    return std::move(_this.exec("offsetUnset", key));
}

Variant RecursiveCachingIterator::offsetExists(const Variant &key) {
    return std::move(_this.exec("offsetExists", key));
}

Variant RecursiveCachingIterator::getCache() {
    return std::move(_this.exec("getCache"));
}

Variant RecursiveCachingIterator::count() {
    return std::move(_this.exec("count"));
}

Variant RecursiveCachingIterator::getInnerIterator() {
    return std::move(_this.exec("getInnerIterator"));
}

Variant RecursiveCachingIterator::key() {
    return std::move(_this.exec("key"));
}

Variant RecursiveCachingIterator::current() {
    return std::move(_this.exec("current"));
}


NoRewindIterator::NoRewindIterator(const Variant &iterator) {
    _this = newObject("NoRewindIterator", iterator);
}

Variant NoRewindIterator::rewind() {
    return std::move(_this.exec("rewind"));
}

Variant NoRewindIterator::valid() {
    return std::move(_this.exec("valid"));
}

Variant NoRewindIterator::key() {
    return std::move(_this.exec("key"));
}

Variant NoRewindIterator::current() {
    return std::move(_this.exec("current"));
}

Variant NoRewindIterator::next() {
    return std::move(_this.exec("next"));
}

Variant NoRewindIterator::getInnerIterator() {
    return std::move(_this.exec("getInnerIterator"));
}


AppendIterator::AppendIterator() {
    _this = newObject("AppendIterator");
}

Variant AppendIterator::append(const Variant &iterator) {
    return std::move(_this.exec("append", iterator));
}

Variant AppendIterator::rewind() {
    return std::move(_this.exec("rewind"));
}

Variant AppendIterator::valid() {
    return std::move(_this.exec("valid"));
}

Variant AppendIterator::current() {
    return std::move(_this.exec("current"));
}

Variant AppendIterator::next() {
    return std::move(_this.exec("next"));
}

Variant AppendIterator::getIteratorIndex() {
    return std::move(_this.exec("getIteratorIndex"));
}

Variant AppendIterator::getArrayIterator() {
    return std::move(_this.exec("getArrayIterator"));
}

Variant AppendIterator::getInnerIterator() {
    return std::move(_this.exec("getInnerIterator"));
}

Variant AppendIterator::key() {
    return std::move(_this.exec("key"));
}


InfiniteIterator::InfiniteIterator(const Variant &iterator) {
    _this = newObject("InfiniteIterator", iterator);
}

Variant InfiniteIterator::next() {
    return std::move(_this.exec("next"));
}

Variant InfiniteIterator::getInnerIterator() {
    return std::move(_this.exec("getInnerIterator"));
}

Variant InfiniteIterator::rewind() {
    return std::move(_this.exec("rewind"));
}

Variant InfiniteIterator::valid() {
    return std::move(_this.exec("valid"));
}

Variant InfiniteIterator::key() {
    return std::move(_this.exec("key"));
}

Variant InfiniteIterator::current() {
    return std::move(_this.exec("current"));
}


RegexIterator::RegexIterator(const Variant &iterator, const Variant &pattern, const Variant &mode, const Variant &flags, const Variant &preg_flags) {
    _this = newObject("RegexIterator", iterator, pattern, mode, flags, preg_flags);
}

Variant RegexIterator::accept() {
    return std::move(_this.exec("accept"));
}

Variant RegexIterator::getMode() {
    return std::move(_this.exec("getMode"));
}

Variant RegexIterator::setMode(const Variant &mode) {
    return std::move(_this.exec("setMode", mode));
}

Variant RegexIterator::getFlags() {
    return std::move(_this.exec("getFlags"));
}

Variant RegexIterator::setFlags(const Variant &flags) {
    return std::move(_this.exec("setFlags", flags));
}

Variant RegexIterator::getRegex() {
    return std::move(_this.exec("getRegex"));
}

Variant RegexIterator::getPregFlags() {
    return std::move(_this.exec("getPregFlags"));
}

Variant RegexIterator::setPregFlags(const Variant &preg_flags) {
    return std::move(_this.exec("setPregFlags", preg_flags));
}

Variant RegexIterator::rewind() {
    return std::move(_this.exec("rewind"));
}

Variant RegexIterator::next() {
    return std::move(_this.exec("next"));
}

Variant RegexIterator::getInnerIterator() {
    return std::move(_this.exec("getInnerIterator"));
}

Variant RegexIterator::valid() {
    return std::move(_this.exec("valid"));
}

Variant RegexIterator::key() {
    return std::move(_this.exec("key"));
}

Variant RegexIterator::current() {
    return std::move(_this.exec("current"));
}


RecursiveRegexIterator::RecursiveRegexIterator(const Variant &iterator, const Variant &pattern, const Variant &mode, const Variant &flags, const Variant &preg_flags) {
    _this = newObject("RecursiveRegexIterator", iterator, pattern, mode, flags, preg_flags);
}

Variant RecursiveRegexIterator::accept() {
    return std::move(_this.exec("accept"));
}

Variant RecursiveRegexIterator::hasChildren() {
    return std::move(_this.exec("hasChildren"));
}

Variant RecursiveRegexIterator::getChildren() {
    return std::move(_this.exec("getChildren"));
}

Variant RecursiveRegexIterator::getMode() {
    return std::move(_this.exec("getMode"));
}

Variant RecursiveRegexIterator::setMode(const Variant &mode) {
    return std::move(_this.exec("setMode", mode));
}

Variant RecursiveRegexIterator::getFlags() {
    return std::move(_this.exec("getFlags"));
}

Variant RecursiveRegexIterator::setFlags(const Variant &flags) {
    return std::move(_this.exec("setFlags", flags));
}

Variant RecursiveRegexIterator::getRegex() {
    return std::move(_this.exec("getRegex"));
}

Variant RecursiveRegexIterator::getPregFlags() {
    return std::move(_this.exec("getPregFlags"));
}

Variant RecursiveRegexIterator::setPregFlags(const Variant &preg_flags) {
    return std::move(_this.exec("setPregFlags", preg_flags));
}

Variant RecursiveRegexIterator::rewind() {
    return std::move(_this.exec("rewind"));
}

Variant RecursiveRegexIterator::next() {
    return std::move(_this.exec("next"));
}

Variant RecursiveRegexIterator::getInnerIterator() {
    return std::move(_this.exec("getInnerIterator"));
}

Variant RecursiveRegexIterator::valid() {
    return std::move(_this.exec("valid"));
}

Variant RecursiveRegexIterator::key() {
    return std::move(_this.exec("key"));
}

Variant RecursiveRegexIterator::current() {
    return std::move(_this.exec("current"));
}


Variant EmptyIterator::current() {
    return std::move(_this.exec("current"));
}

Variant EmptyIterator::next() {
    return std::move(_this.exec("next"));
}

Variant EmptyIterator::key() {
    return std::move(_this.exec("key"));
}

Variant EmptyIterator::valid() {
    return std::move(_this.exec("valid"));
}

Variant EmptyIterator::rewind() {
    return std::move(_this.exec("rewind"));
}


RecursiveTreeIterator::RecursiveTreeIterator(const Variant &iterator, const Variant &flags, const Variant &caching_iterator_flags, const Variant &mode) {
    _this = newObject("RecursiveTreeIterator", iterator, flags, caching_iterator_flags, mode);
}

Variant RecursiveTreeIterator::key() {
    return std::move(_this.exec("key"));
}

Variant RecursiveTreeIterator::current() {
    return std::move(_this.exec("current"));
}

Variant RecursiveTreeIterator::getPrefix() {
    return std::move(_this.exec("getPrefix"));
}

Variant RecursiveTreeIterator::setPostfix(const Variant &postfix) {
    return std::move(_this.exec("setPostfix", postfix));
}

Variant RecursiveTreeIterator::setPrefixPart(const Variant &part, const Variant &value) {
    return std::move(_this.exec("setPrefixPart", part, value));
}

Variant RecursiveTreeIterator::getEntry() {
    return std::move(_this.exec("getEntry"));
}

Variant RecursiveTreeIterator::getPostfix() {
    return std::move(_this.exec("getPostfix"));
}

Variant RecursiveTreeIterator::rewind() {
    return std::move(_this.exec("rewind"));
}

Variant RecursiveTreeIterator::valid() {
    return std::move(_this.exec("valid"));
}

Variant RecursiveTreeIterator::next() {
    return std::move(_this.exec("next"));
}

Variant RecursiveTreeIterator::getDepth() {
    return std::move(_this.exec("getDepth"));
}

Variant RecursiveTreeIterator::getSubIterator(const Variant &level) {
    return std::move(_this.exec("getSubIterator", level));
}

Variant RecursiveTreeIterator::getInnerIterator() {
    return std::move(_this.exec("getInnerIterator"));
}

Variant RecursiveTreeIterator::beginIteration() {
    return std::move(_this.exec("beginIteration"));
}

Variant RecursiveTreeIterator::endIteration() {
    return std::move(_this.exec("endIteration"));
}

Variant RecursiveTreeIterator::callHasChildren() {
    return std::move(_this.exec("callHasChildren"));
}

Variant RecursiveTreeIterator::callGetChildren() {
    return std::move(_this.exec("callGetChildren"));
}

Variant RecursiveTreeIterator::beginChildren() {
    return std::move(_this.exec("beginChildren"));
}

Variant RecursiveTreeIterator::endChildren() {
    return std::move(_this.exec("endChildren"));
}

Variant RecursiveTreeIterator::nextElement() {
    return std::move(_this.exec("nextElement"));
}

Variant RecursiveTreeIterator::setMaxDepth(const Variant &max_depth) {
    return std::move(_this.exec("setMaxDepth", max_depth));
}

Variant RecursiveTreeIterator::getMaxDepth() {
    return std::move(_this.exec("getMaxDepth"));
}


ArrayObject::ArrayObject(const Array &array, const Variant &flags, const Variant &iterator_class) {
    _this = newObject("ArrayObject", array, flags, iterator_class);
}

Variant ArrayObject::offsetExists(const Variant &key) {
    return std::move(_this.exec("offsetExists", key));
}

Variant ArrayObject::offsetGet(const Variant &key) {
    return std::move(_this.exec("offsetGet", key));
}

Variant ArrayObject::offsetSet(const Variant &key, const Variant &value) {
    return std::move(_this.exec("offsetSet", key, value));
}

Variant ArrayObject::offsetUnset(const Variant &key) {
    return std::move(_this.exec("offsetUnset", key));
}

Variant ArrayObject::append(const Variant &value) {
    return std::move(_this.exec("append", value));
}

Variant ArrayObject::getArrayCopy() {
    return std::move(_this.exec("getArrayCopy"));
}

Variant ArrayObject::count() {
    return std::move(_this.exec("count"));
}

Variant ArrayObject::getFlags() {
    return std::move(_this.exec("getFlags"));
}

Variant ArrayObject::setFlags(const Variant &flags) {
    return std::move(_this.exec("setFlags", flags));
}

Variant ArrayObject::asort(const Variant &flags) {
    return std::move(_this.exec("asort", flags));
}

Variant ArrayObject::ksort(const Variant &flags) {
    return std::move(_this.exec("ksort", flags));
}

Variant ArrayObject::uasort(const Variant &callback) {
    return std::move(_this.exec("uasort", callback));
}

Variant ArrayObject::uksort(const Variant &callback) {
    return std::move(_this.exec("uksort", callback));
}

Variant ArrayObject::natsort() {
    return std::move(_this.exec("natsort"));
}

Variant ArrayObject::natcasesort() {
    return std::move(_this.exec("natcasesort"));
}

Variant ArrayObject::unserialize(const Variant &data) {
    return std::move(_this.exec("unserialize", data));
}

Variant ArrayObject::serialize() {
    return std::move(_this.exec("serialize"));
}

Variant ArrayObject::__serialize() {
    return std::move(_this.exec("__serialize"));
}

Variant ArrayObject::__unserialize(const Variant &data) {
    return std::move(_this.exec("__unserialize", data));
}

Variant ArrayObject::getIterator() {
    return std::move(_this.exec("getIterator"));
}

Variant ArrayObject::exchangeArray(const Variant &array) {
    return std::move(_this.exec("exchangeArray", array));
}

Variant ArrayObject::setIteratorClass(const Variant &iterator_class) {
    return std::move(_this.exec("setIteratorClass", iterator_class));
}

Variant ArrayObject::getIteratorClass() {
    return std::move(_this.exec("getIteratorClass"));
}

Variant ArrayObject::__debugInfo() {
    return std::move(_this.exec("__debugInfo"));
}


_ArrayIterator::_ArrayIterator(const Array &array, const Variant &flags) {
    _this = newObject("ArrayIterator", array, flags);
}

Variant _ArrayIterator::offsetExists(const Variant &key) {
    return std::move(_this.exec("offsetExists", key));
}

Variant _ArrayIterator::offsetGet(const Variant &key) {
    return std::move(_this.exec("offsetGet", key));
}

Variant _ArrayIterator::offsetSet(const Variant &key, const Variant &value) {
    return std::move(_this.exec("offsetSet", key, value));
}

Variant _ArrayIterator::offsetUnset(const Variant &key) {
    return std::move(_this.exec("offsetUnset", key));
}

Variant _ArrayIterator::append(const Variant &value) {
    return std::move(_this.exec("append", value));
}

Variant _ArrayIterator::getArrayCopy() {
    return std::move(_this.exec("getArrayCopy"));
}

Variant _ArrayIterator::count() {
    return std::move(_this.exec("count"));
}

Variant _ArrayIterator::getFlags() {
    return std::move(_this.exec("getFlags"));
}

Variant _ArrayIterator::setFlags(const Variant &flags) {
    return std::move(_this.exec("setFlags", flags));
}

Variant _ArrayIterator::asort(const Variant &flags) {
    return std::move(_this.exec("asort", flags));
}

Variant _ArrayIterator::ksort(const Variant &flags) {
    return std::move(_this.exec("ksort", flags));
}

Variant _ArrayIterator::uasort(const Variant &callback) {
    return std::move(_this.exec("uasort", callback));
}

Variant _ArrayIterator::uksort(const Variant &callback) {
    return std::move(_this.exec("uksort", callback));
}

Variant _ArrayIterator::natsort() {
    return std::move(_this.exec("natsort"));
}

Variant _ArrayIterator::natcasesort() {
    return std::move(_this.exec("natcasesort"));
}

Variant _ArrayIterator::unserialize(const Variant &data) {
    return std::move(_this.exec("unserialize", data));
}

Variant _ArrayIterator::serialize() {
    return std::move(_this.exec("serialize"));
}

Variant _ArrayIterator::__serialize() {
    return std::move(_this.exec("__serialize"));
}

Variant _ArrayIterator::__unserialize(const Variant &data) {
    return std::move(_this.exec("__unserialize", data));
}

Variant _ArrayIterator::rewind() {
    return std::move(_this.exec("rewind"));
}

Variant _ArrayIterator::current() {
    return std::move(_this.exec("current"));
}

Variant _ArrayIterator::key() {
    return std::move(_this.exec("key"));
}

Variant _ArrayIterator::next() {
    return std::move(_this.exec("next"));
}

Variant _ArrayIterator::valid() {
    return std::move(_this.exec("valid"));
}

Variant _ArrayIterator::seek(const Variant &offset) {
    return std::move(_this.exec("seek", offset));
}

Variant _ArrayIterator::__debugInfo() {
    return std::move(_this.exec("__debugInfo"));
}


Variant RecursiveArrayIterator::hasChildren() {
    return std::move(_this.exec("hasChildren"));
}

Variant RecursiveArrayIterator::getChildren() {
    return std::move(_this.exec("getChildren"));
}

RecursiveArrayIterator::RecursiveArrayIterator(const Array &array, const Variant &flags) {
    _this = newObject("RecursiveArrayIterator", array, flags);
}

Variant RecursiveArrayIterator::offsetExists(const Variant &key) {
    return std::move(_this.exec("offsetExists", key));
}

Variant RecursiveArrayIterator::offsetGet(const Variant &key) {
    return std::move(_this.exec("offsetGet", key));
}

Variant RecursiveArrayIterator::offsetSet(const Variant &key, const Variant &value) {
    return std::move(_this.exec("offsetSet", key, value));
}

Variant RecursiveArrayIterator::offsetUnset(const Variant &key) {
    return std::move(_this.exec("offsetUnset", key));
}

Variant RecursiveArrayIterator::append(const Variant &value) {
    return std::move(_this.exec("append", value));
}

Variant RecursiveArrayIterator::getArrayCopy() {
    return std::move(_this.exec("getArrayCopy"));
}

Variant RecursiveArrayIterator::count() {
    return std::move(_this.exec("count"));
}

Variant RecursiveArrayIterator::getFlags() {
    return std::move(_this.exec("getFlags"));
}

Variant RecursiveArrayIterator::setFlags(const Variant &flags) {
    return std::move(_this.exec("setFlags", flags));
}

Variant RecursiveArrayIterator::asort(const Variant &flags) {
    return std::move(_this.exec("asort", flags));
}

Variant RecursiveArrayIterator::ksort(const Variant &flags) {
    return std::move(_this.exec("ksort", flags));
}

Variant RecursiveArrayIterator::uasort(const Variant &callback) {
    return std::move(_this.exec("uasort", callback));
}

Variant RecursiveArrayIterator::uksort(const Variant &callback) {
    return std::move(_this.exec("uksort", callback));
}

Variant RecursiveArrayIterator::natsort() {
    return std::move(_this.exec("natsort"));
}

Variant RecursiveArrayIterator::natcasesort() {
    return std::move(_this.exec("natcasesort"));
}

Variant RecursiveArrayIterator::unserialize(const Variant &data) {
    return std::move(_this.exec("unserialize", data));
}

Variant RecursiveArrayIterator::serialize() {
    return std::move(_this.exec("serialize"));
}

Variant RecursiveArrayIterator::__serialize() {
    return std::move(_this.exec("__serialize"));
}

Variant RecursiveArrayIterator::__unserialize(const Variant &data) {
    return std::move(_this.exec("__unserialize", data));
}

Variant RecursiveArrayIterator::rewind() {
    return std::move(_this.exec("rewind"));
}

Variant RecursiveArrayIterator::current() {
    return std::move(_this.exec("current"));
}

Variant RecursiveArrayIterator::key() {
    return std::move(_this.exec("key"));
}

Variant RecursiveArrayIterator::next() {
    return std::move(_this.exec("next"));
}

Variant RecursiveArrayIterator::valid() {
    return std::move(_this.exec("valid"));
}

Variant RecursiveArrayIterator::seek(const Variant &offset) {
    return std::move(_this.exec("seek", offset));
}

Variant RecursiveArrayIterator::__debugInfo() {
    return std::move(_this.exec("__debugInfo"));
}


SplFileInfo::SplFileInfo(const Variant &filename) {
    _this = newObject("SplFileInfo", filename);
}

Variant SplFileInfo::getPath() {
    return std::move(_this.exec("getPath"));
}

Variant SplFileInfo::getFilename() {
    return std::move(_this.exec("getFilename"));
}

Variant SplFileInfo::getExtension() {
    return std::move(_this.exec("getExtension"));
}

Variant SplFileInfo::getBasename(const Variant &suffix) {
    return std::move(_this.exec("getBasename", suffix));
}

Variant SplFileInfo::getPathname() {
    return std::move(_this.exec("getPathname"));
}

Variant SplFileInfo::getPerms() {
    return std::move(_this.exec("getPerms"));
}

Variant SplFileInfo::getInode() {
    return std::move(_this.exec("getInode"));
}

Variant SplFileInfo::getSize() {
    return std::move(_this.exec("getSize"));
}

Variant SplFileInfo::getOwner() {
    return std::move(_this.exec("getOwner"));
}

Variant SplFileInfo::getGroup() {
    return std::move(_this.exec("getGroup"));
}

Variant SplFileInfo::getATime() {
    return std::move(_this.exec("getATime"));
}

Variant SplFileInfo::getMTime() {
    return std::move(_this.exec("getMTime"));
}

Variant SplFileInfo::getCTime() {
    return std::move(_this.exec("getCTime"));
}

Variant SplFileInfo::getType() {
    return std::move(_this.exec("getType"));
}

Variant SplFileInfo::isWritable() {
    return std::move(_this.exec("isWritable"));
}

Variant SplFileInfo::isReadable() {
    return std::move(_this.exec("isReadable"));
}

Variant SplFileInfo::isExecutable() {
    return std::move(_this.exec("isExecutable"));
}

Variant SplFileInfo::isFile() {
    return std::move(_this.exec("isFile"));
}

Variant SplFileInfo::isDir() {
    return std::move(_this.exec("isDir"));
}

Variant SplFileInfo::isLink() {
    return std::move(_this.exec("isLink"));
}

Variant SplFileInfo::getLinkTarget() {
    return std::move(_this.exec("getLinkTarget"));
}

Variant SplFileInfo::getRealPath() {
    return std::move(_this.exec("getRealPath"));
}

Variant SplFileInfo::getFileInfo(const Variant &_class) {
    return std::move(_this.exec("getFileInfo", _class));
}

Variant SplFileInfo::getPathInfo(const Variant &_class) {
    return std::move(_this.exec("getPathInfo", _class));
}

Variant SplFileInfo::openFile(const Variant &mode, const Variant &use_include_path, const Variant &context) {
    return std::move(_this.exec("openFile", mode, use_include_path, context));
}

Variant SplFileInfo::setFileClass(const Variant &_class) {
    return std::move(_this.exec("setFileClass", _class));
}

Variant SplFileInfo::setInfoClass(const Variant &_class) {
    return std::move(_this.exec("setInfoClass", _class));
}

Variant SplFileInfo::__toString() {
    return std::move(_this.exec("__toString"));
}

Variant SplFileInfo::__debugInfo() {
    return std::move(_this.exec("__debugInfo"));
}

Variant SplFileInfo::_bad_state_ex() {
    return std::move(_this.exec("_bad_state_ex"));
}


DirectoryIterator::DirectoryIterator(const Variant &directory) {
    _this = newObject("DirectoryIterator", directory);
}

Variant DirectoryIterator::getFilename() {
    return std::move(_this.exec("getFilename"));
}

Variant DirectoryIterator::getExtension() {
    return std::move(_this.exec("getExtension"));
}

Variant DirectoryIterator::getBasename(const Variant &suffix) {
    return std::move(_this.exec("getBasename", suffix));
}

Variant DirectoryIterator::isDot() {
    return std::move(_this.exec("isDot"));
}

Variant DirectoryIterator::rewind() {
    return std::move(_this.exec("rewind"));
}

Variant DirectoryIterator::valid() {
    return std::move(_this.exec("valid"));
}

Variant DirectoryIterator::key() {
    return std::move(_this.exec("key"));
}

Variant DirectoryIterator::current() {
    return std::move(_this.exec("current"));
}

Variant DirectoryIterator::next() {
    return std::move(_this.exec("next"));
}

Variant DirectoryIterator::seek(const Variant &offset) {
    return std::move(_this.exec("seek", offset));
}

Variant DirectoryIterator::__toString() {
    return std::move(_this.exec("__toString"));
}

Variant DirectoryIterator::getPath() {
    return std::move(_this.exec("getPath"));
}

Variant DirectoryIterator::getPathname() {
    return std::move(_this.exec("getPathname"));
}

Variant DirectoryIterator::getPerms() {
    return std::move(_this.exec("getPerms"));
}

Variant DirectoryIterator::getInode() {
    return std::move(_this.exec("getInode"));
}

Variant DirectoryIterator::getSize() {
    return std::move(_this.exec("getSize"));
}

Variant DirectoryIterator::getOwner() {
    return std::move(_this.exec("getOwner"));
}

Variant DirectoryIterator::getGroup() {
    return std::move(_this.exec("getGroup"));
}

Variant DirectoryIterator::getATime() {
    return std::move(_this.exec("getATime"));
}

Variant DirectoryIterator::getMTime() {
    return std::move(_this.exec("getMTime"));
}

Variant DirectoryIterator::getCTime() {
    return std::move(_this.exec("getCTime"));
}

Variant DirectoryIterator::getType() {
    return std::move(_this.exec("getType"));
}

Variant DirectoryIterator::isWritable() {
    return std::move(_this.exec("isWritable"));
}

Variant DirectoryIterator::isReadable() {
    return std::move(_this.exec("isReadable"));
}

Variant DirectoryIterator::isExecutable() {
    return std::move(_this.exec("isExecutable"));
}

Variant DirectoryIterator::isFile() {
    return std::move(_this.exec("isFile"));
}

Variant DirectoryIterator::isDir() {
    return std::move(_this.exec("isDir"));
}

Variant DirectoryIterator::isLink() {
    return std::move(_this.exec("isLink"));
}

Variant DirectoryIterator::getLinkTarget() {
    return std::move(_this.exec("getLinkTarget"));
}

Variant DirectoryIterator::getRealPath() {
    return std::move(_this.exec("getRealPath"));
}

Variant DirectoryIterator::getFileInfo(const Variant &_class) {
    return std::move(_this.exec("getFileInfo", _class));
}

Variant DirectoryIterator::getPathInfo(const Variant &_class) {
    return std::move(_this.exec("getPathInfo", _class));
}

Variant DirectoryIterator::openFile(const Variant &mode, const Variant &use_include_path, const Variant &context) {
    return std::move(_this.exec("openFile", mode, use_include_path, context));
}

Variant DirectoryIterator::setFileClass(const Variant &_class) {
    return std::move(_this.exec("setFileClass", _class));
}

Variant DirectoryIterator::setInfoClass(const Variant &_class) {
    return std::move(_this.exec("setInfoClass", _class));
}

Variant DirectoryIterator::__debugInfo() {
    return std::move(_this.exec("__debugInfo"));
}

Variant DirectoryIterator::_bad_state_ex() {
    return std::move(_this.exec("_bad_state_ex"));
}


FilesystemIterator::FilesystemIterator(const Variant &directory, const Variant &flags) {
    _this = newObject("FilesystemIterator", directory, flags);
}

Variant FilesystemIterator::rewind() {
    return std::move(_this.exec("rewind"));
}

Variant FilesystemIterator::key() {
    return std::move(_this.exec("key"));
}

Variant FilesystemIterator::current() {
    return std::move(_this.exec("current"));
}

Variant FilesystemIterator::getFlags() {
    return std::move(_this.exec("getFlags"));
}

Variant FilesystemIterator::setFlags(const Variant &flags) {
    return std::move(_this.exec("setFlags", flags));
}

Variant FilesystemIterator::getFilename() {
    return std::move(_this.exec("getFilename"));
}

Variant FilesystemIterator::getExtension() {
    return std::move(_this.exec("getExtension"));
}

Variant FilesystemIterator::getBasename(const Variant &suffix) {
    return std::move(_this.exec("getBasename", suffix));
}

Variant FilesystemIterator::isDot() {
    return std::move(_this.exec("isDot"));
}

Variant FilesystemIterator::valid() {
    return std::move(_this.exec("valid"));
}

Variant FilesystemIterator::next() {
    return std::move(_this.exec("next"));
}

Variant FilesystemIterator::seek(const Variant &offset) {
    return std::move(_this.exec("seek", offset));
}

Variant FilesystemIterator::__toString() {
    return std::move(_this.exec("__toString"));
}

Variant FilesystemIterator::getPath() {
    return std::move(_this.exec("getPath"));
}

Variant FilesystemIterator::getPathname() {
    return std::move(_this.exec("getPathname"));
}

Variant FilesystemIterator::getPerms() {
    return std::move(_this.exec("getPerms"));
}

Variant FilesystemIterator::getInode() {
    return std::move(_this.exec("getInode"));
}

Variant FilesystemIterator::getSize() {
    return std::move(_this.exec("getSize"));
}

Variant FilesystemIterator::getOwner() {
    return std::move(_this.exec("getOwner"));
}

Variant FilesystemIterator::getGroup() {
    return std::move(_this.exec("getGroup"));
}

Variant FilesystemIterator::getATime() {
    return std::move(_this.exec("getATime"));
}

Variant FilesystemIterator::getMTime() {
    return std::move(_this.exec("getMTime"));
}

Variant FilesystemIterator::getCTime() {
    return std::move(_this.exec("getCTime"));
}

Variant FilesystemIterator::getType() {
    return std::move(_this.exec("getType"));
}

Variant FilesystemIterator::isWritable() {
    return std::move(_this.exec("isWritable"));
}

Variant FilesystemIterator::isReadable() {
    return std::move(_this.exec("isReadable"));
}

Variant FilesystemIterator::isExecutable() {
    return std::move(_this.exec("isExecutable"));
}

Variant FilesystemIterator::isFile() {
    return std::move(_this.exec("isFile"));
}

Variant FilesystemIterator::isDir() {
    return std::move(_this.exec("isDir"));
}

Variant FilesystemIterator::isLink() {
    return std::move(_this.exec("isLink"));
}

Variant FilesystemIterator::getLinkTarget() {
    return std::move(_this.exec("getLinkTarget"));
}

Variant FilesystemIterator::getRealPath() {
    return std::move(_this.exec("getRealPath"));
}

Variant FilesystemIterator::getFileInfo(const Variant &_class) {
    return std::move(_this.exec("getFileInfo", _class));
}

Variant FilesystemIterator::getPathInfo(const Variant &_class) {
    return std::move(_this.exec("getPathInfo", _class));
}

Variant FilesystemIterator::openFile(const Variant &mode, const Variant &use_include_path, const Variant &context) {
    return std::move(_this.exec("openFile", mode, use_include_path, context));
}

Variant FilesystemIterator::setFileClass(const Variant &_class) {
    return std::move(_this.exec("setFileClass", _class));
}

Variant FilesystemIterator::setInfoClass(const Variant &_class) {
    return std::move(_this.exec("setInfoClass", _class));
}

Variant FilesystemIterator::__debugInfo() {
    return std::move(_this.exec("__debugInfo"));
}

Variant FilesystemIterator::_bad_state_ex() {
    return std::move(_this.exec("_bad_state_ex"));
}


RecursiveDirectoryIterator::RecursiveDirectoryIterator(const Variant &directory, const Variant &flags) {
    _this = newObject("RecursiveDirectoryIterator", directory, flags);
}

Variant RecursiveDirectoryIterator::hasChildren(const Variant &allow_links) {
    return std::move(_this.exec("hasChildren", allow_links));
}

Variant RecursiveDirectoryIterator::getChildren() {
    return std::move(_this.exec("getChildren"));
}

Variant RecursiveDirectoryIterator::getSubPath() {
    return std::move(_this.exec("getSubPath"));
}

Variant RecursiveDirectoryIterator::getSubPathname() {
    return std::move(_this.exec("getSubPathname"));
}

Variant RecursiveDirectoryIterator::rewind() {
    return std::move(_this.exec("rewind"));
}

Variant RecursiveDirectoryIterator::key() {
    return std::move(_this.exec("key"));
}

Variant RecursiveDirectoryIterator::current() {
    return std::move(_this.exec("current"));
}

Variant RecursiveDirectoryIterator::getFlags() {
    return std::move(_this.exec("getFlags"));
}

Variant RecursiveDirectoryIterator::setFlags(const Variant &flags) {
    return std::move(_this.exec("setFlags", flags));
}

Variant RecursiveDirectoryIterator::getFilename() {
    return std::move(_this.exec("getFilename"));
}

Variant RecursiveDirectoryIterator::getExtension() {
    return std::move(_this.exec("getExtension"));
}

Variant RecursiveDirectoryIterator::getBasename(const Variant &suffix) {
    return std::move(_this.exec("getBasename", suffix));
}

Variant RecursiveDirectoryIterator::isDot() {
    return std::move(_this.exec("isDot"));
}

Variant RecursiveDirectoryIterator::valid() {
    return std::move(_this.exec("valid"));
}

Variant RecursiveDirectoryIterator::next() {
    return std::move(_this.exec("next"));
}

Variant RecursiveDirectoryIterator::seek(const Variant &offset) {
    return std::move(_this.exec("seek", offset));
}

Variant RecursiveDirectoryIterator::__toString() {
    return std::move(_this.exec("__toString"));
}

Variant RecursiveDirectoryIterator::getPath() {
    return std::move(_this.exec("getPath"));
}

Variant RecursiveDirectoryIterator::getPathname() {
    return std::move(_this.exec("getPathname"));
}

Variant RecursiveDirectoryIterator::getPerms() {
    return std::move(_this.exec("getPerms"));
}

Variant RecursiveDirectoryIterator::getInode() {
    return std::move(_this.exec("getInode"));
}

Variant RecursiveDirectoryIterator::getSize() {
    return std::move(_this.exec("getSize"));
}

Variant RecursiveDirectoryIterator::getOwner() {
    return std::move(_this.exec("getOwner"));
}

Variant RecursiveDirectoryIterator::getGroup() {
    return std::move(_this.exec("getGroup"));
}

Variant RecursiveDirectoryIterator::getATime() {
    return std::move(_this.exec("getATime"));
}

Variant RecursiveDirectoryIterator::getMTime() {
    return std::move(_this.exec("getMTime"));
}

Variant RecursiveDirectoryIterator::getCTime() {
    return std::move(_this.exec("getCTime"));
}

Variant RecursiveDirectoryIterator::getType() {
    return std::move(_this.exec("getType"));
}

Variant RecursiveDirectoryIterator::isWritable() {
    return std::move(_this.exec("isWritable"));
}

Variant RecursiveDirectoryIterator::isReadable() {
    return std::move(_this.exec("isReadable"));
}

Variant RecursiveDirectoryIterator::isExecutable() {
    return std::move(_this.exec("isExecutable"));
}

Variant RecursiveDirectoryIterator::isFile() {
    return std::move(_this.exec("isFile"));
}

Variant RecursiveDirectoryIterator::isDir() {
    return std::move(_this.exec("isDir"));
}

Variant RecursiveDirectoryIterator::isLink() {
    return std::move(_this.exec("isLink"));
}

Variant RecursiveDirectoryIterator::getLinkTarget() {
    return std::move(_this.exec("getLinkTarget"));
}

Variant RecursiveDirectoryIterator::getRealPath() {
    return std::move(_this.exec("getRealPath"));
}

Variant RecursiveDirectoryIterator::getFileInfo(const Variant &_class) {
    return std::move(_this.exec("getFileInfo", _class));
}

Variant RecursiveDirectoryIterator::getPathInfo(const Variant &_class) {
    return std::move(_this.exec("getPathInfo", _class));
}

Variant RecursiveDirectoryIterator::openFile(const Variant &mode, const Variant &use_include_path, const Variant &context) {
    return std::move(_this.exec("openFile", mode, use_include_path, context));
}

Variant RecursiveDirectoryIterator::setFileClass(const Variant &_class) {
    return std::move(_this.exec("setFileClass", _class));
}

Variant RecursiveDirectoryIterator::setInfoClass(const Variant &_class) {
    return std::move(_this.exec("setInfoClass", _class));
}

Variant RecursiveDirectoryIterator::__debugInfo() {
    return std::move(_this.exec("__debugInfo"));
}

Variant RecursiveDirectoryIterator::_bad_state_ex() {
    return std::move(_this.exec("_bad_state_ex"));
}


GlobIterator::GlobIterator(const Variant &pattern, const Variant &flags) {
    _this = newObject("GlobIterator", pattern, flags);
}

Variant GlobIterator::count() {
    return std::move(_this.exec("count"));
}

Variant GlobIterator::rewind() {
    return std::move(_this.exec("rewind"));
}

Variant GlobIterator::key() {
    return std::move(_this.exec("key"));
}

Variant GlobIterator::current() {
    return std::move(_this.exec("current"));
}

Variant GlobIterator::getFlags() {
    return std::move(_this.exec("getFlags"));
}

Variant GlobIterator::setFlags(const Variant &flags) {
    return std::move(_this.exec("setFlags", flags));
}

Variant GlobIterator::getFilename() {
    return std::move(_this.exec("getFilename"));
}

Variant GlobIterator::getExtension() {
    return std::move(_this.exec("getExtension"));
}

Variant GlobIterator::getBasename(const Variant &suffix) {
    return std::move(_this.exec("getBasename", suffix));
}

Variant GlobIterator::isDot() {
    return std::move(_this.exec("isDot"));
}

Variant GlobIterator::valid() {
    return std::move(_this.exec("valid"));
}

Variant GlobIterator::next() {
    return std::move(_this.exec("next"));
}

Variant GlobIterator::seek(const Variant &offset) {
    return std::move(_this.exec("seek", offset));
}

Variant GlobIterator::__toString() {
    return std::move(_this.exec("__toString"));
}

Variant GlobIterator::getPath() {
    return std::move(_this.exec("getPath"));
}

Variant GlobIterator::getPathname() {
    return std::move(_this.exec("getPathname"));
}

Variant GlobIterator::getPerms() {
    return std::move(_this.exec("getPerms"));
}

Variant GlobIterator::getInode() {
    return std::move(_this.exec("getInode"));
}

Variant GlobIterator::getSize() {
    return std::move(_this.exec("getSize"));
}

Variant GlobIterator::getOwner() {
    return std::move(_this.exec("getOwner"));
}

Variant GlobIterator::getGroup() {
    return std::move(_this.exec("getGroup"));
}

Variant GlobIterator::getATime() {
    return std::move(_this.exec("getATime"));
}

Variant GlobIterator::getMTime() {
    return std::move(_this.exec("getMTime"));
}

Variant GlobIterator::getCTime() {
    return std::move(_this.exec("getCTime"));
}

Variant GlobIterator::getType() {
    return std::move(_this.exec("getType"));
}

Variant GlobIterator::isWritable() {
    return std::move(_this.exec("isWritable"));
}

Variant GlobIterator::isReadable() {
    return std::move(_this.exec("isReadable"));
}

Variant GlobIterator::isExecutable() {
    return std::move(_this.exec("isExecutable"));
}

Variant GlobIterator::isFile() {
    return std::move(_this.exec("isFile"));
}

Variant GlobIterator::isDir() {
    return std::move(_this.exec("isDir"));
}

Variant GlobIterator::isLink() {
    return std::move(_this.exec("isLink"));
}

Variant GlobIterator::getLinkTarget() {
    return std::move(_this.exec("getLinkTarget"));
}

Variant GlobIterator::getRealPath() {
    return std::move(_this.exec("getRealPath"));
}

Variant GlobIterator::getFileInfo(const Variant &_class) {
    return std::move(_this.exec("getFileInfo", _class));
}

Variant GlobIterator::getPathInfo(const Variant &_class) {
    return std::move(_this.exec("getPathInfo", _class));
}

Variant GlobIterator::openFile(const Variant &mode, const Variant &use_include_path, const Variant &context) {
    return std::move(_this.exec("openFile", mode, use_include_path, context));
}

Variant GlobIterator::setFileClass(const Variant &_class) {
    return std::move(_this.exec("setFileClass", _class));
}

Variant GlobIterator::setInfoClass(const Variant &_class) {
    return std::move(_this.exec("setInfoClass", _class));
}

Variant GlobIterator::__debugInfo() {
    return std::move(_this.exec("__debugInfo"));
}

Variant GlobIterator::_bad_state_ex() {
    return std::move(_this.exec("_bad_state_ex"));
}


SplFileObject::SplFileObject(const Variant &filename, const Variant &mode, const Variant &use_include_path, const Variant &context) {
    _this = newObject("SplFileObject", filename, mode, use_include_path, context);
}

Variant SplFileObject::rewind() {
    return std::move(_this.exec("rewind"));
}

Variant SplFileObject::eof() {
    return std::move(_this.exec("eof"));
}

Variant SplFileObject::valid() {
    return std::move(_this.exec("valid"));
}

Variant SplFileObject::fgets() {
    return std::move(_this.exec("fgets"));
}

Variant SplFileObject::fread(const Variant &length) {
    return std::move(_this.exec("fread", length));
}

Variant SplFileObject::fgetcsv(const Variant &separator, const Variant &enclosure, const Variant &escape) {
    return std::move(_this.exec("fgetcsv", separator, enclosure, escape));
}

Variant SplFileObject::fputcsv(const Variant &fields, const Variant &separator, const Variant &enclosure, const Variant &escape, const Variant &eol) {
    return std::move(_this.exec("fputcsv", fields, separator, enclosure, escape, eol));
}

Variant SplFileObject::setCsvControl(const Variant &separator, const Variant &enclosure, const Variant &escape) {
    return std::move(_this.exec("setCsvControl", separator, enclosure, escape));
}

Variant SplFileObject::getCsvControl() {
    return std::move(_this.exec("getCsvControl"));
}

Variant SplFileObject::flock(const Variant &operation, const Variant &would_block) {
    return std::move(_this.exec("flock", operation, would_block));
}

Variant SplFileObject::fflush() {
    return std::move(_this.exec("fflush"));
}

Variant SplFileObject::ftell() {
    return std::move(_this.exec("ftell"));
}

Variant SplFileObject::fseek(const Variant &offset, const Variant &whence) {
    return std::move(_this.exec("fseek", offset, whence));
}

Variant SplFileObject::fgetc() {
    return std::move(_this.exec("fgetc"));
}

Variant SplFileObject::fpassthru() {
    return std::move(_this.exec("fpassthru"));
}

Variant SplFileObject::fscanf(const Variant &format, const Variant &vars) {
    return std::move(_this.exec("fscanf", format, vars));
}

Variant SplFileObject::fwrite(const Variant &data, const Variant &length) {
    return std::move(_this.exec("fwrite", data, length));
}

Variant SplFileObject::fstat() {
    return std::move(_this.exec("fstat"));
}

Variant SplFileObject::ftruncate(const Variant &size) {
    return std::move(_this.exec("ftruncate", size));
}

Variant SplFileObject::current() {
    return std::move(_this.exec("current"));
}

Variant SplFileObject::key() {
    return std::move(_this.exec("key"));
}

Variant SplFileObject::next() {
    return std::move(_this.exec("next"));
}

Variant SplFileObject::setFlags(const Variant &flags) {
    return std::move(_this.exec("setFlags", flags));
}

Variant SplFileObject::getFlags() {
    return std::move(_this.exec("getFlags"));
}

Variant SplFileObject::setMaxLineLen(const Variant &max_length) {
    return std::move(_this.exec("setMaxLineLen", max_length));
}

Variant SplFileObject::getMaxLineLen() {
    return std::move(_this.exec("getMaxLineLen"));
}

Variant SplFileObject::hasChildren() {
    return std::move(_this.exec("hasChildren"));
}

Variant SplFileObject::getChildren() {
    return std::move(_this.exec("getChildren"));
}

Variant SplFileObject::seek(const Variant &line) {
    return std::move(_this.exec("seek", line));
}

Variant SplFileObject::getCurrentLine() {
    return std::move(_this.exec("getCurrentLine"));
}

Variant SplFileObject::__toString() {
    return std::move(_this.exec("__toString"));
}

Variant SplFileObject::getPath() {
    return std::move(_this.exec("getPath"));
}

Variant SplFileObject::getFilename() {
    return std::move(_this.exec("getFilename"));
}

Variant SplFileObject::getExtension() {
    return std::move(_this.exec("getExtension"));
}

Variant SplFileObject::getBasename(const Variant &suffix) {
    return std::move(_this.exec("getBasename", suffix));
}

Variant SplFileObject::getPathname() {
    return std::move(_this.exec("getPathname"));
}

Variant SplFileObject::getPerms() {
    return std::move(_this.exec("getPerms"));
}

Variant SplFileObject::getInode() {
    return std::move(_this.exec("getInode"));
}

Variant SplFileObject::getSize() {
    return std::move(_this.exec("getSize"));
}

Variant SplFileObject::getOwner() {
    return std::move(_this.exec("getOwner"));
}

Variant SplFileObject::getGroup() {
    return std::move(_this.exec("getGroup"));
}

Variant SplFileObject::getATime() {
    return std::move(_this.exec("getATime"));
}

Variant SplFileObject::getMTime() {
    return std::move(_this.exec("getMTime"));
}

Variant SplFileObject::getCTime() {
    return std::move(_this.exec("getCTime"));
}

Variant SplFileObject::getType() {
    return std::move(_this.exec("getType"));
}

Variant SplFileObject::isWritable() {
    return std::move(_this.exec("isWritable"));
}

Variant SplFileObject::isReadable() {
    return std::move(_this.exec("isReadable"));
}

Variant SplFileObject::isExecutable() {
    return std::move(_this.exec("isExecutable"));
}

Variant SplFileObject::isFile() {
    return std::move(_this.exec("isFile"));
}

Variant SplFileObject::isDir() {
    return std::move(_this.exec("isDir"));
}

Variant SplFileObject::isLink() {
    return std::move(_this.exec("isLink"));
}

Variant SplFileObject::getLinkTarget() {
    return std::move(_this.exec("getLinkTarget"));
}

Variant SplFileObject::getRealPath() {
    return std::move(_this.exec("getRealPath"));
}

Variant SplFileObject::getFileInfo(const Variant &_class) {
    return std::move(_this.exec("getFileInfo", _class));
}

Variant SplFileObject::getPathInfo(const Variant &_class) {
    return std::move(_this.exec("getPathInfo", _class));
}

Variant SplFileObject::openFile(const Variant &mode, const Variant &use_include_path, const Variant &context) {
    return std::move(_this.exec("openFile", mode, use_include_path, context));
}

Variant SplFileObject::setFileClass(const Variant &_class) {
    return std::move(_this.exec("setFileClass", _class));
}

Variant SplFileObject::setInfoClass(const Variant &_class) {
    return std::move(_this.exec("setInfoClass", _class));
}

Variant SplFileObject::__debugInfo() {
    return std::move(_this.exec("__debugInfo"));
}

Variant SplFileObject::_bad_state_ex() {
    return std::move(_this.exec("_bad_state_ex"));
}


SplTempFileObject::SplTempFileObject(const Variant &max_memory) {
    _this = newObject("SplTempFileObject", max_memory);
}

Variant SplTempFileObject::rewind() {
    return std::move(_this.exec("rewind"));
}

Variant SplTempFileObject::eof() {
    return std::move(_this.exec("eof"));
}

Variant SplTempFileObject::valid() {
    return std::move(_this.exec("valid"));
}

Variant SplTempFileObject::fgets() {
    return std::move(_this.exec("fgets"));
}

Variant SplTempFileObject::fread(const Variant &length) {
    return std::move(_this.exec("fread", length));
}

Variant SplTempFileObject::fgetcsv(const Variant &separator, const Variant &enclosure, const Variant &escape) {
    return std::move(_this.exec("fgetcsv", separator, enclosure, escape));
}

Variant SplTempFileObject::fputcsv(const Variant &fields, const Variant &separator, const Variant &enclosure, const Variant &escape, const Variant &eol) {
    return std::move(_this.exec("fputcsv", fields, separator, enclosure, escape, eol));
}

Variant SplTempFileObject::setCsvControl(const Variant &separator, const Variant &enclosure, const Variant &escape) {
    return std::move(_this.exec("setCsvControl", separator, enclosure, escape));
}

Variant SplTempFileObject::getCsvControl() {
    return std::move(_this.exec("getCsvControl"));
}

Variant SplTempFileObject::flock(const Variant &operation, const Variant &would_block) {
    return std::move(_this.exec("flock", operation, would_block));
}

Variant SplTempFileObject::fflush() {
    return std::move(_this.exec("fflush"));
}

Variant SplTempFileObject::ftell() {
    return std::move(_this.exec("ftell"));
}

Variant SplTempFileObject::fseek(const Variant &offset, const Variant &whence) {
    return std::move(_this.exec("fseek", offset, whence));
}

Variant SplTempFileObject::fgetc() {
    return std::move(_this.exec("fgetc"));
}

Variant SplTempFileObject::fpassthru() {
    return std::move(_this.exec("fpassthru"));
}

Variant SplTempFileObject::fscanf(const Variant &format, const Variant &vars) {
    return std::move(_this.exec("fscanf", format, vars));
}

Variant SplTempFileObject::fwrite(const Variant &data, const Variant &length) {
    return std::move(_this.exec("fwrite", data, length));
}

Variant SplTempFileObject::fstat() {
    return std::move(_this.exec("fstat"));
}

Variant SplTempFileObject::ftruncate(const Variant &size) {
    return std::move(_this.exec("ftruncate", size));
}

Variant SplTempFileObject::current() {
    return std::move(_this.exec("current"));
}

Variant SplTempFileObject::key() {
    return std::move(_this.exec("key"));
}

Variant SplTempFileObject::next() {
    return std::move(_this.exec("next"));
}

Variant SplTempFileObject::setFlags(const Variant &flags) {
    return std::move(_this.exec("setFlags", flags));
}

Variant SplTempFileObject::getFlags() {
    return std::move(_this.exec("getFlags"));
}

Variant SplTempFileObject::setMaxLineLen(const Variant &max_length) {
    return std::move(_this.exec("setMaxLineLen", max_length));
}

Variant SplTempFileObject::getMaxLineLen() {
    return std::move(_this.exec("getMaxLineLen"));
}

Variant SplTempFileObject::hasChildren() {
    return std::move(_this.exec("hasChildren"));
}

Variant SplTempFileObject::getChildren() {
    return std::move(_this.exec("getChildren"));
}

Variant SplTempFileObject::seek(const Variant &line) {
    return std::move(_this.exec("seek", line));
}

Variant SplTempFileObject::getCurrentLine() {
    return std::move(_this.exec("getCurrentLine"));
}

Variant SplTempFileObject::__toString() {
    return std::move(_this.exec("__toString"));
}

Variant SplTempFileObject::getPath() {
    return std::move(_this.exec("getPath"));
}

Variant SplTempFileObject::getFilename() {
    return std::move(_this.exec("getFilename"));
}

Variant SplTempFileObject::getExtension() {
    return std::move(_this.exec("getExtension"));
}

Variant SplTempFileObject::getBasename(const Variant &suffix) {
    return std::move(_this.exec("getBasename", suffix));
}

Variant SplTempFileObject::getPathname() {
    return std::move(_this.exec("getPathname"));
}

Variant SplTempFileObject::getPerms() {
    return std::move(_this.exec("getPerms"));
}

Variant SplTempFileObject::getInode() {
    return std::move(_this.exec("getInode"));
}

Variant SplTempFileObject::getSize() {
    return std::move(_this.exec("getSize"));
}

Variant SplTempFileObject::getOwner() {
    return std::move(_this.exec("getOwner"));
}

Variant SplTempFileObject::getGroup() {
    return std::move(_this.exec("getGroup"));
}

Variant SplTempFileObject::getATime() {
    return std::move(_this.exec("getATime"));
}

Variant SplTempFileObject::getMTime() {
    return std::move(_this.exec("getMTime"));
}

Variant SplTempFileObject::getCTime() {
    return std::move(_this.exec("getCTime"));
}

Variant SplTempFileObject::getType() {
    return std::move(_this.exec("getType"));
}

Variant SplTempFileObject::isWritable() {
    return std::move(_this.exec("isWritable"));
}

Variant SplTempFileObject::isReadable() {
    return std::move(_this.exec("isReadable"));
}

Variant SplTempFileObject::isExecutable() {
    return std::move(_this.exec("isExecutable"));
}

Variant SplTempFileObject::isFile() {
    return std::move(_this.exec("isFile"));
}

Variant SplTempFileObject::isDir() {
    return std::move(_this.exec("isDir"));
}

Variant SplTempFileObject::isLink() {
    return std::move(_this.exec("isLink"));
}

Variant SplTempFileObject::getLinkTarget() {
    return std::move(_this.exec("getLinkTarget"));
}

Variant SplTempFileObject::getRealPath() {
    return std::move(_this.exec("getRealPath"));
}

Variant SplTempFileObject::getFileInfo(const Variant &_class) {
    return std::move(_this.exec("getFileInfo", _class));
}

Variant SplTempFileObject::getPathInfo(const Variant &_class) {
    return std::move(_this.exec("getPathInfo", _class));
}

Variant SplTempFileObject::openFile(const Variant &mode, const Variant &use_include_path, const Variant &context) {
    return std::move(_this.exec("openFile", mode, use_include_path, context));
}

Variant SplTempFileObject::setFileClass(const Variant &_class) {
    return std::move(_this.exec("setFileClass", _class));
}

Variant SplTempFileObject::setInfoClass(const Variant &_class) {
    return std::move(_this.exec("setInfoClass", _class));
}

Variant SplTempFileObject::__debugInfo() {
    return std::move(_this.exec("__debugInfo"));
}

Variant SplTempFileObject::_bad_state_ex() {
    return std::move(_this.exec("_bad_state_ex"));
}


Variant SplDoublyLinkedList::add(const Variant &index, const Variant &value) {
    return std::move(_this.exec("add", index, value));
}

Variant SplDoublyLinkedList::pop() {
    return std::move(_this.exec("pop"));
}

Variant SplDoublyLinkedList::shift() {
    return std::move(_this.exec("shift"));
}

Variant SplDoublyLinkedList::push(const Variant &value) {
    return std::move(_this.exec("push", value));
}

Variant SplDoublyLinkedList::unshift(const Variant &value) {
    return std::move(_this.exec("unshift", value));
}

Variant SplDoublyLinkedList::top() {
    return std::move(_this.exec("top"));
}

Variant SplDoublyLinkedList::bottom() {
    return std::move(_this.exec("bottom"));
}

Variant SplDoublyLinkedList::__debugInfo() {
    return std::move(_this.exec("__debugInfo"));
}

Variant SplDoublyLinkedList::count() {
    return std::move(_this.exec("count"));
}

Variant SplDoublyLinkedList::isEmpty() {
    return std::move(_this.exec("isEmpty"));
}

Variant SplDoublyLinkedList::setIteratorMode(const Variant &mode) {
    return std::move(_this.exec("setIteratorMode", mode));
}

Variant SplDoublyLinkedList::getIteratorMode() {
    return std::move(_this.exec("getIteratorMode"));
}

Variant SplDoublyLinkedList::offsetExists(const Variant &index) {
    return std::move(_this.exec("offsetExists", index));
}

Variant SplDoublyLinkedList::offsetGet(const Variant &index) {
    return std::move(_this.exec("offsetGet", index));
}

Variant SplDoublyLinkedList::offsetSet(const Variant &index, const Variant &value) {
    return std::move(_this.exec("offsetSet", index, value));
}

Variant SplDoublyLinkedList::offsetUnset(const Variant &index) {
    return std::move(_this.exec("offsetUnset", index));
}

Variant SplDoublyLinkedList::rewind() {
    return std::move(_this.exec("rewind"));
}

Variant SplDoublyLinkedList::current() {
    return std::move(_this.exec("current"));
}

Variant SplDoublyLinkedList::key() {
    return std::move(_this.exec("key"));
}

Variant SplDoublyLinkedList::prev() {
    return std::move(_this.exec("prev"));
}

Variant SplDoublyLinkedList::next() {
    return std::move(_this.exec("next"));
}

Variant SplDoublyLinkedList::valid() {
    return std::move(_this.exec("valid"));
}

Variant SplDoublyLinkedList::unserialize(const Variant &data) {
    return std::move(_this.exec("unserialize", data));
}

Variant SplDoublyLinkedList::serialize() {
    return std::move(_this.exec("serialize"));
}

Variant SplDoublyLinkedList::__serialize() {
    return std::move(_this.exec("__serialize"));
}

Variant SplDoublyLinkedList::__unserialize(const Variant &data) {
    return std::move(_this.exec("__unserialize", data));
}


Variant SplQueue::enqueue(const Variant &value) {
    return std::move(_this.exec("enqueue", value));
}

Variant SplQueue::dequeue() {
    return std::move(_this.exec("dequeue"));
}

Variant SplQueue::add(const Variant &index, const Variant &value) {
    return std::move(_this.exec("add", index, value));
}

Variant SplQueue::pop() {
    return std::move(_this.exec("pop"));
}

Variant SplQueue::shift() {
    return std::move(_this.exec("shift"));
}

Variant SplQueue::push(const Variant &value) {
    return std::move(_this.exec("push", value));
}

Variant SplQueue::unshift(const Variant &value) {
    return std::move(_this.exec("unshift", value));
}

Variant SplQueue::top() {
    return std::move(_this.exec("top"));
}

Variant SplQueue::bottom() {
    return std::move(_this.exec("bottom"));
}

Variant SplQueue::__debugInfo() {
    return std::move(_this.exec("__debugInfo"));
}

Variant SplQueue::count() {
    return std::move(_this.exec("count"));
}

Variant SplQueue::isEmpty() {
    return std::move(_this.exec("isEmpty"));
}

Variant SplQueue::setIteratorMode(const Variant &mode) {
    return std::move(_this.exec("setIteratorMode", mode));
}

Variant SplQueue::getIteratorMode() {
    return std::move(_this.exec("getIteratorMode"));
}

Variant SplQueue::offsetExists(const Variant &index) {
    return std::move(_this.exec("offsetExists", index));
}

Variant SplQueue::offsetGet(const Variant &index) {
    return std::move(_this.exec("offsetGet", index));
}

Variant SplQueue::offsetSet(const Variant &index, const Variant &value) {
    return std::move(_this.exec("offsetSet", index, value));
}

Variant SplQueue::offsetUnset(const Variant &index) {
    return std::move(_this.exec("offsetUnset", index));
}

Variant SplQueue::rewind() {
    return std::move(_this.exec("rewind"));
}

Variant SplQueue::current() {
    return std::move(_this.exec("current"));
}

Variant SplQueue::key() {
    return std::move(_this.exec("key"));
}

Variant SplQueue::prev() {
    return std::move(_this.exec("prev"));
}

Variant SplQueue::next() {
    return std::move(_this.exec("next"));
}

Variant SplQueue::valid() {
    return std::move(_this.exec("valid"));
}

Variant SplQueue::unserialize(const Variant &data) {
    return std::move(_this.exec("unserialize", data));
}

Variant SplQueue::serialize() {
    return std::move(_this.exec("serialize"));
}

Variant SplQueue::__serialize() {
    return std::move(_this.exec("__serialize"));
}

Variant SplQueue::__unserialize(const Variant &data) {
    return std::move(_this.exec("__unserialize", data));
}


Variant SplStack::add(const Variant &index, const Variant &value) {
    return std::move(_this.exec("add", index, value));
}

Variant SplStack::pop() {
    return std::move(_this.exec("pop"));
}

Variant SplStack::shift() {
    return std::move(_this.exec("shift"));
}

Variant SplStack::push(const Variant &value) {
    return std::move(_this.exec("push", value));
}

Variant SplStack::unshift(const Variant &value) {
    return std::move(_this.exec("unshift", value));
}

Variant SplStack::top() {
    return std::move(_this.exec("top"));
}

Variant SplStack::bottom() {
    return std::move(_this.exec("bottom"));
}

Variant SplStack::__debugInfo() {
    return std::move(_this.exec("__debugInfo"));
}

Variant SplStack::count() {
    return std::move(_this.exec("count"));
}

Variant SplStack::isEmpty() {
    return std::move(_this.exec("isEmpty"));
}

Variant SplStack::setIteratorMode(const Variant &mode) {
    return std::move(_this.exec("setIteratorMode", mode));
}

Variant SplStack::getIteratorMode() {
    return std::move(_this.exec("getIteratorMode"));
}

Variant SplStack::offsetExists(const Variant &index) {
    return std::move(_this.exec("offsetExists", index));
}

Variant SplStack::offsetGet(const Variant &index) {
    return std::move(_this.exec("offsetGet", index));
}

Variant SplStack::offsetSet(const Variant &index, const Variant &value) {
    return std::move(_this.exec("offsetSet", index, value));
}

Variant SplStack::offsetUnset(const Variant &index) {
    return std::move(_this.exec("offsetUnset", index));
}

Variant SplStack::rewind() {
    return std::move(_this.exec("rewind"));
}

Variant SplStack::current() {
    return std::move(_this.exec("current"));
}

Variant SplStack::key() {
    return std::move(_this.exec("key"));
}

Variant SplStack::prev() {
    return std::move(_this.exec("prev"));
}

Variant SplStack::next() {
    return std::move(_this.exec("next"));
}

Variant SplStack::valid() {
    return std::move(_this.exec("valid"));
}

Variant SplStack::unserialize(const Variant &data) {
    return std::move(_this.exec("unserialize", data));
}

Variant SplStack::serialize() {
    return std::move(_this.exec("serialize"));
}

Variant SplStack::__serialize() {
    return std::move(_this.exec("__serialize"));
}

Variant SplStack::__unserialize(const Variant &data) {
    return std::move(_this.exec("__unserialize", data));
}


Variant SplMinHeap::extract() {
    return std::move(_this.exec("extract"));
}

Variant SplMinHeap::insert(const Variant &value) {
    return std::move(_this.exec("insert", value));
}

Variant SplMinHeap::top() {
    return std::move(_this.exec("top"));
}

Variant SplMinHeap::count() {
    return std::move(_this.exec("count"));
}

Variant SplMinHeap::isEmpty() {
    return std::move(_this.exec("isEmpty"));
}

Variant SplMinHeap::rewind() {
    return std::move(_this.exec("rewind"));
}

Variant SplMinHeap::current() {
    return std::move(_this.exec("current"));
}

Variant SplMinHeap::key() {
    return std::move(_this.exec("key"));
}

Variant SplMinHeap::next() {
    return std::move(_this.exec("next"));
}

Variant SplMinHeap::valid() {
    return std::move(_this.exec("valid"));
}

Variant SplMinHeap::recoverFromCorruption() {
    return std::move(_this.exec("recoverFromCorruption"));
}

Variant SplMinHeap::isCorrupted() {
    return std::move(_this.exec("isCorrupted"));
}

Variant SplMinHeap::__debugInfo() {
    return std::move(_this.exec("__debugInfo"));
}


Variant SplMaxHeap::extract() {
    return std::move(_this.exec("extract"));
}

Variant SplMaxHeap::insert(const Variant &value) {
    return std::move(_this.exec("insert", value));
}

Variant SplMaxHeap::top() {
    return std::move(_this.exec("top"));
}

Variant SplMaxHeap::count() {
    return std::move(_this.exec("count"));
}

Variant SplMaxHeap::isEmpty() {
    return std::move(_this.exec("isEmpty"));
}

Variant SplMaxHeap::rewind() {
    return std::move(_this.exec("rewind"));
}

Variant SplMaxHeap::current() {
    return std::move(_this.exec("current"));
}

Variant SplMaxHeap::key() {
    return std::move(_this.exec("key"));
}

Variant SplMaxHeap::next() {
    return std::move(_this.exec("next"));
}

Variant SplMaxHeap::valid() {
    return std::move(_this.exec("valid"));
}

Variant SplMaxHeap::recoverFromCorruption() {
    return std::move(_this.exec("recoverFromCorruption"));
}

Variant SplMaxHeap::isCorrupted() {
    return std::move(_this.exec("isCorrupted"));
}

Variant SplMaxHeap::__debugInfo() {
    return std::move(_this.exec("__debugInfo"));
}


Variant SplPriorityQueue::compare(const Variant &priority1, const Variant &priority2) {
    return std::move(_this.exec("compare", priority1, priority2));
}

Variant SplPriorityQueue::insert(const Variant &value, const Variant &priority) {
    return std::move(_this.exec("insert", value, priority));
}

Variant SplPriorityQueue::setExtractFlags(const Variant &flags) {
    return std::move(_this.exec("setExtractFlags", flags));
}

Variant SplPriorityQueue::top() {
    return std::move(_this.exec("top"));
}

Variant SplPriorityQueue::extract() {
    return std::move(_this.exec("extract"));
}

Variant SplPriorityQueue::count() {
    return std::move(_this.exec("count"));
}

Variant SplPriorityQueue::isEmpty() {
    return std::move(_this.exec("isEmpty"));
}

Variant SplPriorityQueue::rewind() {
    return std::move(_this.exec("rewind"));
}

Variant SplPriorityQueue::current() {
    return std::move(_this.exec("current"));
}

Variant SplPriorityQueue::key() {
    return std::move(_this.exec("key"));
}

Variant SplPriorityQueue::next() {
    return std::move(_this.exec("next"));
}

Variant SplPriorityQueue::valid() {
    return std::move(_this.exec("valid"));
}

Variant SplPriorityQueue::recoverFromCorruption() {
    return std::move(_this.exec("recoverFromCorruption"));
}

Variant SplPriorityQueue::isCorrupted() {
    return std::move(_this.exec("isCorrupted"));
}

Variant SplPriorityQueue::getExtractFlags() {
    return std::move(_this.exec("getExtractFlags"));
}

Variant SplPriorityQueue::__debugInfo() {
    return std::move(_this.exec("__debugInfo"));
}


SplFixedArray::SplFixedArray(const Variant &size) {
    _this = newObject("SplFixedArray", size);
}

Variant SplFixedArray::__wakeup() {
    return std::move(_this.exec("__wakeup"));
}

Variant SplFixedArray::__serialize() {
    return std::move(_this.exec("__serialize"));
}

Variant SplFixedArray::__unserialize(const Variant &data) {
    return std::move(_this.exec("__unserialize", data));
}

Variant SplFixedArray::count() {
    return std::move(_this.exec("count"));
}

Variant SplFixedArray::toArray() {
    return std::move(_this.exec("toArray"));
}

Variant SplFixedArray::fromArray(const Variant &array, const Variant &preserve_keys) {
    static Variant fn { ZEND_STRL("SplFixedArray::fromArray"), true };
    return fn(array, preserve_keys);
}

Variant SplFixedArray::getSize() {
    return std::move(_this.exec("getSize"));
}

Variant SplFixedArray::setSize(const Variant &size) {
    return std::move(_this.exec("setSize", size));
}

Variant SplFixedArray::offsetExists(const Variant &index) {
    return std::move(_this.exec("offsetExists", index));
}

Variant SplFixedArray::offsetGet(const Variant &index) {
    return std::move(_this.exec("offsetGet", index));
}

Variant SplFixedArray::offsetSet(const Variant &index, const Variant &value) {
    return std::move(_this.exec("offsetSet", index, value));
}

Variant SplFixedArray::offsetUnset(const Variant &index) {
    return std::move(_this.exec("offsetUnset", index));
}

Variant SplFixedArray::getIterator() {
    return std::move(_this.exec("getIterator"));
}

Variant SplFixedArray::jsonSerialize() {
    return std::move(_this.exec("jsonSerialize"));
}


Variant SplObjectStorage::attach(const Variant &object, const Variant &info) {
    return std::move(_this.exec("attach", object, info));
}

Variant SplObjectStorage::detach(const Variant &object) {
    return std::move(_this.exec("detach", object));
}

Variant SplObjectStorage::contains(const Variant &object) {
    return std::move(_this.exec("contains", object));
}

Variant SplObjectStorage::addAll(const Variant &storage) {
    return std::move(_this.exec("addAll", storage));
}

Variant SplObjectStorage::removeAll(const Variant &storage) {
    return std::move(_this.exec("removeAll", storage));
}

Variant SplObjectStorage::removeAllExcept(const Variant &storage) {
    return std::move(_this.exec("removeAllExcept", storage));
}

Variant SplObjectStorage::getInfo() {
    return std::move(_this.exec("getInfo"));
}

Variant SplObjectStorage::setInfo(const Variant &info) {
    return std::move(_this.exec("setInfo", info));
}

Variant SplObjectStorage::count(const Variant &mode) {
    return std::move(_this.exec("count", mode));
}

Variant SplObjectStorage::rewind() {
    return std::move(_this.exec("rewind"));
}

Variant SplObjectStorage::valid() {
    return std::move(_this.exec("valid"));
}

Variant SplObjectStorage::key() {
    return std::move(_this.exec("key"));
}

Variant SplObjectStorage::current() {
    return std::move(_this.exec("current"));
}

Variant SplObjectStorage::next() {
    return std::move(_this.exec("next"));
}

Variant SplObjectStorage::unserialize(const Variant &data) {
    return std::move(_this.exec("unserialize", data));
}

Variant SplObjectStorage::serialize() {
    return std::move(_this.exec("serialize"));
}

Variant SplObjectStorage::offsetExists(const Variant &object) {
    return std::move(_this.exec("offsetExists", object));
}

Variant SplObjectStorage::offsetGet(const Variant &object) {
    return std::move(_this.exec("offsetGet", object));
}

Variant SplObjectStorage::offsetSet(const Variant &object, const Variant &info) {
    return std::move(_this.exec("offsetSet", object, info));
}

Variant SplObjectStorage::offsetUnset(const Variant &object) {
    return std::move(_this.exec("offsetUnset", object));
}

Variant SplObjectStorage::getHash(const Variant &object) {
    return std::move(_this.exec("getHash", object));
}

Variant SplObjectStorage::__serialize() {
    return std::move(_this.exec("__serialize"));
}

Variant SplObjectStorage::__unserialize(const Variant &data) {
    return std::move(_this.exec("__unserialize", data));
}

Variant SplObjectStorage::__debugInfo() {
    return std::move(_this.exec("__debugInfo"));
}


MultipleIterator::MultipleIterator(const Variant &flags) {
    _this = newObject("MultipleIterator", flags);
}

Variant MultipleIterator::getFlags() {
    return std::move(_this.exec("getFlags"));
}

Variant MultipleIterator::setFlags(const Variant &flags) {
    return std::move(_this.exec("setFlags", flags));
}

Variant MultipleIterator::attachIterator(const Variant &iterator, const Variant &info) {
    return std::move(_this.exec("attachIterator", iterator, info));
}

Variant MultipleIterator::detachIterator(const Variant &iterator) {
    return std::move(_this.exec("detachIterator", iterator));
}

Variant MultipleIterator::containsIterator(const Variant &iterator) {
    return std::move(_this.exec("containsIterator", iterator));
}

Variant MultipleIterator::countIterators() {
    return std::move(_this.exec("countIterators"));
}

Variant MultipleIterator::rewind() {
    return std::move(_this.exec("rewind"));
}

Variant MultipleIterator::valid() {
    return std::move(_this.exec("valid"));
}

Variant MultipleIterator::key() {
    return std::move(_this.exec("key"));
}

Variant MultipleIterator::current() {
    return std::move(_this.exec("current"));
}

Variant MultipleIterator::next() {
    return std::move(_this.exec("next"));
}

Variant MultipleIterator::__debugInfo() {
    return std::move(_this.exec("__debugInfo"));
}


}

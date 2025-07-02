#include "phpx.h"
#include "class/spl.h"

namespace php {
LogicException::LogicException(const Variant &message, const Variant &code, const Variant &previous) {
    this_ = newObject("LogicException", message, code, previous);
}

Variant LogicException::__wakeup() {
    return this_.exec("__wakeup");
}

Variant LogicException::getMessage() {
    return this_.exec("getMessage");
}

Variant LogicException::getCode() {
    return this_.exec("getCode");
}

Variant LogicException::getFile() {
    return this_.exec("getFile");
}

Variant LogicException::getLine() {
    return this_.exec("getLine");
}

Variant LogicException::getTrace() {
    return this_.exec("getTrace");
}

Variant LogicException::getPrevious() {
    return this_.exec("getPrevious");
}

Variant LogicException::getTraceAsString() {
    return this_.exec("getTraceAsString");
}

Variant LogicException::__toString() {
    return this_.exec("__toString");
}


BadFunctionCallException::BadFunctionCallException(const Variant &message, const Variant &code, const Variant &previous) {
    this_ = newObject("BadFunctionCallException", message, code, previous);
}

Variant BadFunctionCallException::__wakeup() {
    return this_.exec("__wakeup");
}

Variant BadFunctionCallException::getMessage() {
    return this_.exec("getMessage");
}

Variant BadFunctionCallException::getCode() {
    return this_.exec("getCode");
}

Variant BadFunctionCallException::getFile() {
    return this_.exec("getFile");
}

Variant BadFunctionCallException::getLine() {
    return this_.exec("getLine");
}

Variant BadFunctionCallException::getTrace() {
    return this_.exec("getTrace");
}

Variant BadFunctionCallException::getPrevious() {
    return this_.exec("getPrevious");
}

Variant BadFunctionCallException::getTraceAsString() {
    return this_.exec("getTraceAsString");
}

Variant BadFunctionCallException::__toString() {
    return this_.exec("__toString");
}


BadMethodCallException::BadMethodCallException(const Variant &message, const Variant &code, const Variant &previous) {
    this_ = newObject("BadMethodCallException", message, code, previous);
}

Variant BadMethodCallException::__wakeup() {
    return this_.exec("__wakeup");
}

Variant BadMethodCallException::getMessage() {
    return this_.exec("getMessage");
}

Variant BadMethodCallException::getCode() {
    return this_.exec("getCode");
}

Variant BadMethodCallException::getFile() {
    return this_.exec("getFile");
}

Variant BadMethodCallException::getLine() {
    return this_.exec("getLine");
}

Variant BadMethodCallException::getTrace() {
    return this_.exec("getTrace");
}

Variant BadMethodCallException::getPrevious() {
    return this_.exec("getPrevious");
}

Variant BadMethodCallException::getTraceAsString() {
    return this_.exec("getTraceAsString");
}

Variant BadMethodCallException::__toString() {
    return this_.exec("__toString");
}


DomainException::DomainException(const Variant &message, const Variant &code, const Variant &previous) {
    this_ = newObject("DomainException", message, code, previous);
}

Variant DomainException::__wakeup() {
    return this_.exec("__wakeup");
}

Variant DomainException::getMessage() {
    return this_.exec("getMessage");
}

Variant DomainException::getCode() {
    return this_.exec("getCode");
}

Variant DomainException::getFile() {
    return this_.exec("getFile");
}

Variant DomainException::getLine() {
    return this_.exec("getLine");
}

Variant DomainException::getTrace() {
    return this_.exec("getTrace");
}

Variant DomainException::getPrevious() {
    return this_.exec("getPrevious");
}

Variant DomainException::getTraceAsString() {
    return this_.exec("getTraceAsString");
}

Variant DomainException::__toString() {
    return this_.exec("__toString");
}


InvalidArgumentException::InvalidArgumentException(const Variant &message, const Variant &code, const Variant &previous) {
    this_ = newObject("InvalidArgumentException", message, code, previous);
}

Variant InvalidArgumentException::__wakeup() {
    return this_.exec("__wakeup");
}

Variant InvalidArgumentException::getMessage() {
    return this_.exec("getMessage");
}

Variant InvalidArgumentException::getCode() {
    return this_.exec("getCode");
}

Variant InvalidArgumentException::getFile() {
    return this_.exec("getFile");
}

Variant InvalidArgumentException::getLine() {
    return this_.exec("getLine");
}

Variant InvalidArgumentException::getTrace() {
    return this_.exec("getTrace");
}

Variant InvalidArgumentException::getPrevious() {
    return this_.exec("getPrevious");
}

Variant InvalidArgumentException::getTraceAsString() {
    return this_.exec("getTraceAsString");
}

Variant InvalidArgumentException::__toString() {
    return this_.exec("__toString");
}


LengthException::LengthException(const Variant &message, const Variant &code, const Variant &previous) {
    this_ = newObject("LengthException", message, code, previous);
}

Variant LengthException::__wakeup() {
    return this_.exec("__wakeup");
}

Variant LengthException::getMessage() {
    return this_.exec("getMessage");
}

Variant LengthException::getCode() {
    return this_.exec("getCode");
}

Variant LengthException::getFile() {
    return this_.exec("getFile");
}

Variant LengthException::getLine() {
    return this_.exec("getLine");
}

Variant LengthException::getTrace() {
    return this_.exec("getTrace");
}

Variant LengthException::getPrevious() {
    return this_.exec("getPrevious");
}

Variant LengthException::getTraceAsString() {
    return this_.exec("getTraceAsString");
}

Variant LengthException::__toString() {
    return this_.exec("__toString");
}


OutOfRangeException::OutOfRangeException(const Variant &message, const Variant &code, const Variant &previous) {
    this_ = newObject("OutOfRangeException", message, code, previous);
}

Variant OutOfRangeException::__wakeup() {
    return this_.exec("__wakeup");
}

Variant OutOfRangeException::getMessage() {
    return this_.exec("getMessage");
}

Variant OutOfRangeException::getCode() {
    return this_.exec("getCode");
}

Variant OutOfRangeException::getFile() {
    return this_.exec("getFile");
}

Variant OutOfRangeException::getLine() {
    return this_.exec("getLine");
}

Variant OutOfRangeException::getTrace() {
    return this_.exec("getTrace");
}

Variant OutOfRangeException::getPrevious() {
    return this_.exec("getPrevious");
}

Variant OutOfRangeException::getTraceAsString() {
    return this_.exec("getTraceAsString");
}

Variant OutOfRangeException::__toString() {
    return this_.exec("__toString");
}


RuntimeException::RuntimeException(const Variant &message, const Variant &code, const Variant &previous) {
    this_ = newObject("RuntimeException", message, code, previous);
}

Variant RuntimeException::__wakeup() {
    return this_.exec("__wakeup");
}

Variant RuntimeException::getMessage() {
    return this_.exec("getMessage");
}

Variant RuntimeException::getCode() {
    return this_.exec("getCode");
}

Variant RuntimeException::getFile() {
    return this_.exec("getFile");
}

Variant RuntimeException::getLine() {
    return this_.exec("getLine");
}

Variant RuntimeException::getTrace() {
    return this_.exec("getTrace");
}

Variant RuntimeException::getPrevious() {
    return this_.exec("getPrevious");
}

Variant RuntimeException::getTraceAsString() {
    return this_.exec("getTraceAsString");
}

Variant RuntimeException::__toString() {
    return this_.exec("__toString");
}


OutOfBoundsException::OutOfBoundsException(const Variant &message, const Variant &code, const Variant &previous) {
    this_ = newObject("OutOfBoundsException", message, code, previous);
}

Variant OutOfBoundsException::__wakeup() {
    return this_.exec("__wakeup");
}

Variant OutOfBoundsException::getMessage() {
    return this_.exec("getMessage");
}

Variant OutOfBoundsException::getCode() {
    return this_.exec("getCode");
}

Variant OutOfBoundsException::getFile() {
    return this_.exec("getFile");
}

Variant OutOfBoundsException::getLine() {
    return this_.exec("getLine");
}

Variant OutOfBoundsException::getTrace() {
    return this_.exec("getTrace");
}

Variant OutOfBoundsException::getPrevious() {
    return this_.exec("getPrevious");
}

Variant OutOfBoundsException::getTraceAsString() {
    return this_.exec("getTraceAsString");
}

Variant OutOfBoundsException::__toString() {
    return this_.exec("__toString");
}


OverflowException::OverflowException(const Variant &message, const Variant &code, const Variant &previous) {
    this_ = newObject("OverflowException", message, code, previous);
}

Variant OverflowException::__wakeup() {
    return this_.exec("__wakeup");
}

Variant OverflowException::getMessage() {
    return this_.exec("getMessage");
}

Variant OverflowException::getCode() {
    return this_.exec("getCode");
}

Variant OverflowException::getFile() {
    return this_.exec("getFile");
}

Variant OverflowException::getLine() {
    return this_.exec("getLine");
}

Variant OverflowException::getTrace() {
    return this_.exec("getTrace");
}

Variant OverflowException::getPrevious() {
    return this_.exec("getPrevious");
}

Variant OverflowException::getTraceAsString() {
    return this_.exec("getTraceAsString");
}

Variant OverflowException::__toString() {
    return this_.exec("__toString");
}


RangeException::RangeException(const Variant &message, const Variant &code, const Variant &previous) {
    this_ = newObject("RangeException", message, code, previous);
}

Variant RangeException::__wakeup() {
    return this_.exec("__wakeup");
}

Variant RangeException::getMessage() {
    return this_.exec("getMessage");
}

Variant RangeException::getCode() {
    return this_.exec("getCode");
}

Variant RangeException::getFile() {
    return this_.exec("getFile");
}

Variant RangeException::getLine() {
    return this_.exec("getLine");
}

Variant RangeException::getTrace() {
    return this_.exec("getTrace");
}

Variant RangeException::getPrevious() {
    return this_.exec("getPrevious");
}

Variant RangeException::getTraceAsString() {
    return this_.exec("getTraceAsString");
}

Variant RangeException::__toString() {
    return this_.exec("__toString");
}


UnderflowException::UnderflowException(const Variant &message, const Variant &code, const Variant &previous) {
    this_ = newObject("UnderflowException", message, code, previous);
}

Variant UnderflowException::__wakeup() {
    return this_.exec("__wakeup");
}

Variant UnderflowException::getMessage() {
    return this_.exec("getMessage");
}

Variant UnderflowException::getCode() {
    return this_.exec("getCode");
}

Variant UnderflowException::getFile() {
    return this_.exec("getFile");
}

Variant UnderflowException::getLine() {
    return this_.exec("getLine");
}

Variant UnderflowException::getTrace() {
    return this_.exec("getTrace");
}

Variant UnderflowException::getPrevious() {
    return this_.exec("getPrevious");
}

Variant UnderflowException::getTraceAsString() {
    return this_.exec("getTraceAsString");
}

Variant UnderflowException::__toString() {
    return this_.exec("__toString");
}


UnexpectedValueException::UnexpectedValueException(const Variant &message, const Variant &code, const Variant &previous) {
    this_ = newObject("UnexpectedValueException", message, code, previous);
}

Variant UnexpectedValueException::__wakeup() {
    return this_.exec("__wakeup");
}

Variant UnexpectedValueException::getMessage() {
    return this_.exec("getMessage");
}

Variant UnexpectedValueException::getCode() {
    return this_.exec("getCode");
}

Variant UnexpectedValueException::getFile() {
    return this_.exec("getFile");
}

Variant UnexpectedValueException::getLine() {
    return this_.exec("getLine");
}

Variant UnexpectedValueException::getTrace() {
    return this_.exec("getTrace");
}

Variant UnexpectedValueException::getPrevious() {
    return this_.exec("getPrevious");
}

Variant UnexpectedValueException::getTraceAsString() {
    return this_.exec("getTraceAsString");
}

Variant UnexpectedValueException::__toString() {
    return this_.exec("__toString");
}


RecursiveIteratorIterator::RecursiveIteratorIterator(const Variant &iterator, const Variant &mode, const Variant &flags) {
    this_ = newObject("RecursiveIteratorIterator", iterator, mode, flags);
}

Variant RecursiveIteratorIterator::rewind() {
    return this_.exec("rewind");
}

Variant RecursiveIteratorIterator::valid() {
    return this_.exec("valid");
}

Variant RecursiveIteratorIterator::key() {
    return this_.exec("key");
}

Variant RecursiveIteratorIterator::current() {
    return this_.exec("current");
}

Variant RecursiveIteratorIterator::next() {
    return this_.exec("next");
}

Variant RecursiveIteratorIterator::getDepth() {
    return this_.exec("getDepth");
}

Variant RecursiveIteratorIterator::getSubIterator(const Variant &level) {
    return this_.exec("getSubIterator", level);
}

Variant RecursiveIteratorIterator::getInnerIterator() {
    return this_.exec("getInnerIterator");
}

Variant RecursiveIteratorIterator::beginIteration() {
    return this_.exec("beginIteration");
}

Variant RecursiveIteratorIterator::endIteration() {
    return this_.exec("endIteration");
}

Variant RecursiveIteratorIterator::callHasChildren() {
    return this_.exec("callHasChildren");
}

Variant RecursiveIteratorIterator::callGetChildren() {
    return this_.exec("callGetChildren");
}

Variant RecursiveIteratorIterator::beginChildren() {
    return this_.exec("beginChildren");
}

Variant RecursiveIteratorIterator::endChildren() {
    return this_.exec("endChildren");
}

Variant RecursiveIteratorIterator::nextElement() {
    return this_.exec("nextElement");
}

Variant RecursiveIteratorIterator::setMaxDepth(const Variant &max_depth) {
    return this_.exec("setMaxDepth", max_depth);
}

Variant RecursiveIteratorIterator::getMaxDepth() {
    return this_.exec("getMaxDepth");
}


IteratorIterator::IteratorIterator(const Variant &iterator, const Variant &_class) {
    this_ = newObject("IteratorIterator", iterator, _class);
}

Variant IteratorIterator::getInnerIterator() {
    return this_.exec("getInnerIterator");
}

Variant IteratorIterator::rewind() {
    return this_.exec("rewind");
}

Variant IteratorIterator::valid() {
    return this_.exec("valid");
}

Variant IteratorIterator::key() {
    return this_.exec("key");
}

Variant IteratorIterator::current() {
    return this_.exec("current");
}

Variant IteratorIterator::next() {
    return this_.exec("next");
}


CallbackFilterIterator::CallbackFilterIterator(const Variant &iterator, const Variant &callback) {
    this_ = newObject("CallbackFilterIterator", iterator, callback);
}

Variant CallbackFilterIterator::accept() {
    return this_.exec("accept");
}

Variant CallbackFilterIterator::rewind() {
    return this_.exec("rewind");
}

Variant CallbackFilterIterator::next() {
    return this_.exec("next");
}

Variant CallbackFilterIterator::getInnerIterator() {
    return this_.exec("getInnerIterator");
}

Variant CallbackFilterIterator::valid() {
    return this_.exec("valid");
}

Variant CallbackFilterIterator::key() {
    return this_.exec("key");
}

Variant CallbackFilterIterator::current() {
    return this_.exec("current");
}


RecursiveCallbackFilterIterator::RecursiveCallbackFilterIterator(const Variant &iterator, const Variant &callback) {
    this_ = newObject("RecursiveCallbackFilterIterator", iterator, callback);
}

Variant RecursiveCallbackFilterIterator::hasChildren() {
    return this_.exec("hasChildren");
}

Variant RecursiveCallbackFilterIterator::getChildren() {
    return this_.exec("getChildren");
}

Variant RecursiveCallbackFilterIterator::accept() {
    return this_.exec("accept");
}

Variant RecursiveCallbackFilterIterator::rewind() {
    return this_.exec("rewind");
}

Variant RecursiveCallbackFilterIterator::next() {
    return this_.exec("next");
}

Variant RecursiveCallbackFilterIterator::getInnerIterator() {
    return this_.exec("getInnerIterator");
}

Variant RecursiveCallbackFilterIterator::valid() {
    return this_.exec("valid");
}

Variant RecursiveCallbackFilterIterator::key() {
    return this_.exec("key");
}

Variant RecursiveCallbackFilterIterator::current() {
    return this_.exec("current");
}


ParentIterator::ParentIterator(const Variant &iterator) {
    this_ = newObject("ParentIterator", iterator);
}

Variant ParentIterator::accept() {
    return this_.exec("accept");
}

Variant ParentIterator::hasChildren() {
    return this_.exec("hasChildren");
}

Variant ParentIterator::getChildren() {
    return this_.exec("getChildren");
}

Variant ParentIterator::rewind() {
    return this_.exec("rewind");
}

Variant ParentIterator::next() {
    return this_.exec("next");
}

Variant ParentIterator::getInnerIterator() {
    return this_.exec("getInnerIterator");
}

Variant ParentIterator::valid() {
    return this_.exec("valid");
}

Variant ParentIterator::key() {
    return this_.exec("key");
}

Variant ParentIterator::current() {
    return this_.exec("current");
}


LimitIterator::LimitIterator(const Variant &iterator, const Variant &offset, const Variant &limit) {
    this_ = newObject("LimitIterator", iterator, offset, limit);
}

Variant LimitIterator::rewind() {
    return this_.exec("rewind");
}

Variant LimitIterator::valid() {
    return this_.exec("valid");
}

Variant LimitIterator::next() {
    return this_.exec("next");
}

Variant LimitIterator::seek(const Variant &offset) {
    return this_.exec("seek", offset);
}

Variant LimitIterator::getPosition() {
    return this_.exec("getPosition");
}

Variant LimitIterator::getInnerIterator() {
    return this_.exec("getInnerIterator");
}

Variant LimitIterator::key() {
    return this_.exec("key");
}

Variant LimitIterator::current() {
    return this_.exec("current");
}


CachingIterator::CachingIterator(const Variant &iterator, const Variant &flags) {
    this_ = newObject("CachingIterator", iterator, flags);
}

Variant CachingIterator::rewind() {
    return this_.exec("rewind");
}

Variant CachingIterator::valid() {
    return this_.exec("valid");
}

Variant CachingIterator::next() {
    return this_.exec("next");
}

Variant CachingIterator::hasNext() {
    return this_.exec("hasNext");
}

Variant CachingIterator::__toString() {
    return this_.exec("__toString");
}

Variant CachingIterator::getFlags() {
    return this_.exec("getFlags");
}

Variant CachingIterator::setFlags(const Variant &flags) {
    return this_.exec("setFlags", flags);
}

Variant CachingIterator::offsetGet(const Variant &key) {
    return this_.exec("offsetGet", key);
}

Variant CachingIterator::offsetSet(const Variant &key, const Variant &value) {
    return this_.exec("offsetSet", key, value);
}

Variant CachingIterator::offsetUnset(const Variant &key) {
    return this_.exec("offsetUnset", key);
}

Variant CachingIterator::offsetExists(const Variant &key) {
    return this_.exec("offsetExists", key);
}

Variant CachingIterator::getCache() {
    return this_.exec("getCache");
}

Variant CachingIterator::count() {
    return this_.exec("count");
}

Variant CachingIterator::getInnerIterator() {
    return this_.exec("getInnerIterator");
}

Variant CachingIterator::key() {
    return this_.exec("key");
}

Variant CachingIterator::current() {
    return this_.exec("current");
}


RecursiveCachingIterator::RecursiveCachingIterator(const Variant &iterator, const Variant &flags) {
    this_ = newObject("RecursiveCachingIterator", iterator, flags);
}

Variant RecursiveCachingIterator::hasChildren() {
    return this_.exec("hasChildren");
}

Variant RecursiveCachingIterator::getChildren() {
    return this_.exec("getChildren");
}

Variant RecursiveCachingIterator::rewind() {
    return this_.exec("rewind");
}

Variant RecursiveCachingIterator::valid() {
    return this_.exec("valid");
}

Variant RecursiveCachingIterator::next() {
    return this_.exec("next");
}

Variant RecursiveCachingIterator::hasNext() {
    return this_.exec("hasNext");
}

Variant RecursiveCachingIterator::__toString() {
    return this_.exec("__toString");
}

Variant RecursiveCachingIterator::getFlags() {
    return this_.exec("getFlags");
}

Variant RecursiveCachingIterator::setFlags(const Variant &flags) {
    return this_.exec("setFlags", flags);
}

Variant RecursiveCachingIterator::offsetGet(const Variant &key) {
    return this_.exec("offsetGet", key);
}

Variant RecursiveCachingIterator::offsetSet(const Variant &key, const Variant &value) {
    return this_.exec("offsetSet", key, value);
}

Variant RecursiveCachingIterator::offsetUnset(const Variant &key) {
    return this_.exec("offsetUnset", key);
}

Variant RecursiveCachingIterator::offsetExists(const Variant &key) {
    return this_.exec("offsetExists", key);
}

Variant RecursiveCachingIterator::getCache() {
    return this_.exec("getCache");
}

Variant RecursiveCachingIterator::count() {
    return this_.exec("count");
}

Variant RecursiveCachingIterator::getInnerIterator() {
    return this_.exec("getInnerIterator");
}

Variant RecursiveCachingIterator::key() {
    return this_.exec("key");
}

Variant RecursiveCachingIterator::current() {
    return this_.exec("current");
}


NoRewindIterator::NoRewindIterator(const Variant &iterator) {
    this_ = newObject("NoRewindIterator", iterator);
}

Variant NoRewindIterator::rewind() {
    return this_.exec("rewind");
}

Variant NoRewindIterator::valid() {
    return this_.exec("valid");
}

Variant NoRewindIterator::key() {
    return this_.exec("key");
}

Variant NoRewindIterator::current() {
    return this_.exec("current");
}

Variant NoRewindIterator::next() {
    return this_.exec("next");
}

Variant NoRewindIterator::getInnerIterator() {
    return this_.exec("getInnerIterator");
}


AppendIterator::AppendIterator() {
    this_ = newObject("AppendIterator");
}

Variant AppendIterator::append(const Variant &iterator) {
    return this_.exec("append", iterator);
}

Variant AppendIterator::rewind() {
    return this_.exec("rewind");
}

Variant AppendIterator::valid() {
    return this_.exec("valid");
}

Variant AppendIterator::current() {
    return this_.exec("current");
}

Variant AppendIterator::next() {
    return this_.exec("next");
}

Variant AppendIterator::getIteratorIndex() {
    return this_.exec("getIteratorIndex");
}

Variant AppendIterator::getArrayIterator() {
    return this_.exec("getArrayIterator");
}

Variant AppendIterator::getInnerIterator() {
    return this_.exec("getInnerIterator");
}

Variant AppendIterator::key() {
    return this_.exec("key");
}


InfiniteIterator::InfiniteIterator(const Variant &iterator) {
    this_ = newObject("InfiniteIterator", iterator);
}

Variant InfiniteIterator::next() {
    return this_.exec("next");
}

Variant InfiniteIterator::getInnerIterator() {
    return this_.exec("getInnerIterator");
}

Variant InfiniteIterator::rewind() {
    return this_.exec("rewind");
}

Variant InfiniteIterator::valid() {
    return this_.exec("valid");
}

Variant InfiniteIterator::key() {
    return this_.exec("key");
}

Variant InfiniteIterator::current() {
    return this_.exec("current");
}


RegexIterator::RegexIterator(const Variant &iterator, const Variant &pattern, const Variant &mode, const Variant &flags, const Variant &preg_flags) {
    this_ = newObject("RegexIterator", iterator, pattern, mode, flags, preg_flags);
}

Variant RegexIterator::accept() {
    return this_.exec("accept");
}

Variant RegexIterator::getMode() {
    return this_.exec("getMode");
}

Variant RegexIterator::setMode(const Variant &mode) {
    return this_.exec("setMode", mode);
}

Variant RegexIterator::getFlags() {
    return this_.exec("getFlags");
}

Variant RegexIterator::setFlags(const Variant &flags) {
    return this_.exec("setFlags", flags);
}

Variant RegexIterator::getRegex() {
    return this_.exec("getRegex");
}

Variant RegexIterator::getPregFlags() {
    return this_.exec("getPregFlags");
}

Variant RegexIterator::setPregFlags(const Variant &preg_flags) {
    return this_.exec("setPregFlags", preg_flags);
}

Variant RegexIterator::rewind() {
    return this_.exec("rewind");
}

Variant RegexIterator::next() {
    return this_.exec("next");
}

Variant RegexIterator::getInnerIterator() {
    return this_.exec("getInnerIterator");
}

Variant RegexIterator::valid() {
    return this_.exec("valid");
}

Variant RegexIterator::key() {
    return this_.exec("key");
}

Variant RegexIterator::current() {
    return this_.exec("current");
}


RecursiveRegexIterator::RecursiveRegexIterator(const Variant &iterator, const Variant &pattern, const Variant &mode, const Variant &flags, const Variant &preg_flags) {
    this_ = newObject("RecursiveRegexIterator", iterator, pattern, mode, flags, preg_flags);
}

Variant RecursiveRegexIterator::accept() {
    return this_.exec("accept");
}

Variant RecursiveRegexIterator::hasChildren() {
    return this_.exec("hasChildren");
}

Variant RecursiveRegexIterator::getChildren() {
    return this_.exec("getChildren");
}

Variant RecursiveRegexIterator::getMode() {
    return this_.exec("getMode");
}

Variant RecursiveRegexIterator::setMode(const Variant &mode) {
    return this_.exec("setMode", mode);
}

Variant RecursiveRegexIterator::getFlags() {
    return this_.exec("getFlags");
}

Variant RecursiveRegexIterator::setFlags(const Variant &flags) {
    return this_.exec("setFlags", flags);
}

Variant RecursiveRegexIterator::getRegex() {
    return this_.exec("getRegex");
}

Variant RecursiveRegexIterator::getPregFlags() {
    return this_.exec("getPregFlags");
}

Variant RecursiveRegexIterator::setPregFlags(const Variant &preg_flags) {
    return this_.exec("setPregFlags", preg_flags);
}

Variant RecursiveRegexIterator::rewind() {
    return this_.exec("rewind");
}

Variant RecursiveRegexIterator::next() {
    return this_.exec("next");
}

Variant RecursiveRegexIterator::getInnerIterator() {
    return this_.exec("getInnerIterator");
}

Variant RecursiveRegexIterator::valid() {
    return this_.exec("valid");
}

Variant RecursiveRegexIterator::key() {
    return this_.exec("key");
}

Variant RecursiveRegexIterator::current() {
    return this_.exec("current");
}


Variant EmptyIterator::current() {
    return this_.exec("current");
}

Variant EmptyIterator::next() {
    return this_.exec("next");
}

Variant EmptyIterator::key() {
    return this_.exec("key");
}

Variant EmptyIterator::valid() {
    return this_.exec("valid");
}

Variant EmptyIterator::rewind() {
    return this_.exec("rewind");
}


RecursiveTreeIterator::RecursiveTreeIterator(const Variant &iterator, const Variant &flags, const Variant &caching_iterator_flags, const Variant &mode) {
    this_ = newObject("RecursiveTreeIterator", iterator, flags, caching_iterator_flags, mode);
}

Variant RecursiveTreeIterator::key() {
    return this_.exec("key");
}

Variant RecursiveTreeIterator::current() {
    return this_.exec("current");
}

Variant RecursiveTreeIterator::getPrefix() {
    return this_.exec("getPrefix");
}

Variant RecursiveTreeIterator::setPostfix(const Variant &postfix) {
    return this_.exec("setPostfix", postfix);
}

Variant RecursiveTreeIterator::setPrefixPart(const Variant &part, const Variant &value) {
    return this_.exec("setPrefixPart", part, value);
}

Variant RecursiveTreeIterator::getEntry() {
    return this_.exec("getEntry");
}

Variant RecursiveTreeIterator::getPostfix() {
    return this_.exec("getPostfix");
}

Variant RecursiveTreeIterator::rewind() {
    return this_.exec("rewind");
}

Variant RecursiveTreeIterator::valid() {
    return this_.exec("valid");
}

Variant RecursiveTreeIterator::next() {
    return this_.exec("next");
}

Variant RecursiveTreeIterator::getDepth() {
    return this_.exec("getDepth");
}

Variant RecursiveTreeIterator::getSubIterator(const Variant &level) {
    return this_.exec("getSubIterator", level);
}

Variant RecursiveTreeIterator::getInnerIterator() {
    return this_.exec("getInnerIterator");
}

Variant RecursiveTreeIterator::beginIteration() {
    return this_.exec("beginIteration");
}

Variant RecursiveTreeIterator::endIteration() {
    return this_.exec("endIteration");
}

Variant RecursiveTreeIterator::callHasChildren() {
    return this_.exec("callHasChildren");
}

Variant RecursiveTreeIterator::callGetChildren() {
    return this_.exec("callGetChildren");
}

Variant RecursiveTreeIterator::beginChildren() {
    return this_.exec("beginChildren");
}

Variant RecursiveTreeIterator::endChildren() {
    return this_.exec("endChildren");
}

Variant RecursiveTreeIterator::nextElement() {
    return this_.exec("nextElement");
}

Variant RecursiveTreeIterator::setMaxDepth(const Variant &max_depth) {
    return this_.exec("setMaxDepth", max_depth);
}

Variant RecursiveTreeIterator::getMaxDepth() {
    return this_.exec("getMaxDepth");
}


ArrayObject::ArrayObject(const Array &array, const Variant &flags, const Variant &iterator_class) {
    this_ = newObject("ArrayObject", array, flags, iterator_class);
}

Variant ArrayObject::offsetExists(const Variant &key) {
    return this_.exec("offsetExists", key);
}

Variant ArrayObject::offsetGet(const Variant &key) {
    return this_.exec("offsetGet", key);
}

Variant ArrayObject::offsetSet(const Variant &key, const Variant &value) {
    return this_.exec("offsetSet", key, value);
}

Variant ArrayObject::offsetUnset(const Variant &key) {
    return this_.exec("offsetUnset", key);
}

Variant ArrayObject::append(const Variant &value) {
    return this_.exec("append", value);
}

Variant ArrayObject::getArrayCopy() {
    return this_.exec("getArrayCopy");
}

Variant ArrayObject::count() {
    return this_.exec("count");
}

Variant ArrayObject::getFlags() {
    return this_.exec("getFlags");
}

Variant ArrayObject::setFlags(const Variant &flags) {
    return this_.exec("setFlags", flags);
}

Variant ArrayObject::asort(const Variant &flags) {
    return this_.exec("asort", flags);
}

Variant ArrayObject::ksort(const Variant &flags) {
    return this_.exec("ksort", flags);
}

Variant ArrayObject::uasort(const Variant &callback) {
    return this_.exec("uasort", callback);
}

Variant ArrayObject::uksort(const Variant &callback) {
    return this_.exec("uksort", callback);
}

Variant ArrayObject::natsort() {
    return this_.exec("natsort");
}

Variant ArrayObject::natcasesort() {
    return this_.exec("natcasesort");
}

Variant ArrayObject::unserialize(const Variant &data) {
    return this_.exec("unserialize", data);
}

Variant ArrayObject::serialize() {
    return this_.exec("serialize");
}

Variant ArrayObject::__serialize() {
    return this_.exec("__serialize");
}

Variant ArrayObject::__unserialize(const Variant &data) {
    return this_.exec("__unserialize", data);
}

Variant ArrayObject::getIterator() {
    return this_.exec("getIterator");
}

Variant ArrayObject::exchangeArray(const Variant &array) {
    return this_.exec("exchangeArray", array);
}

Variant ArrayObject::setIteratorClass(const Variant &iterator_class) {
    return this_.exec("setIteratorClass", iterator_class);
}

Variant ArrayObject::getIteratorClass() {
    return this_.exec("getIteratorClass");
}

Variant ArrayObject::__debugInfo() {
    return this_.exec("__debugInfo");
}


_ArrayIterator::_ArrayIterator(const Array &array, const Variant &flags) {
    this_ = newObject("ArrayIterator", array, flags);
}

Variant _ArrayIterator::offsetExists(const Variant &key) {
    return this_.exec("offsetExists", key);
}

Variant _ArrayIterator::offsetGet(const Variant &key) {
    return this_.exec("offsetGet", key);
}

Variant _ArrayIterator::offsetSet(const Variant &key, const Variant &value) {
    return this_.exec("offsetSet", key, value);
}

Variant _ArrayIterator::offsetUnset(const Variant &key) {
    return this_.exec("offsetUnset", key);
}

Variant _ArrayIterator::append(const Variant &value) {
    return this_.exec("append", value);
}

Variant _ArrayIterator::getArrayCopy() {
    return this_.exec("getArrayCopy");
}

Variant _ArrayIterator::count() {
    return this_.exec("count");
}

Variant _ArrayIterator::getFlags() {
    return this_.exec("getFlags");
}

Variant _ArrayIterator::setFlags(const Variant &flags) {
    return this_.exec("setFlags", flags);
}

Variant _ArrayIterator::asort(const Variant &flags) {
    return this_.exec("asort", flags);
}

Variant _ArrayIterator::ksort(const Variant &flags) {
    return this_.exec("ksort", flags);
}

Variant _ArrayIterator::uasort(const Variant &callback) {
    return this_.exec("uasort", callback);
}

Variant _ArrayIterator::uksort(const Variant &callback) {
    return this_.exec("uksort", callback);
}

Variant _ArrayIterator::natsort() {
    return this_.exec("natsort");
}

Variant _ArrayIterator::natcasesort() {
    return this_.exec("natcasesort");
}

Variant _ArrayIterator::unserialize(const Variant &data) {
    return this_.exec("unserialize", data);
}

Variant _ArrayIterator::serialize() {
    return this_.exec("serialize");
}

Variant _ArrayIterator::__serialize() {
    return this_.exec("__serialize");
}

Variant _ArrayIterator::__unserialize(const Variant &data) {
    return this_.exec("__unserialize", data);
}

Variant _ArrayIterator::rewind() {
    return this_.exec("rewind");
}

Variant _ArrayIterator::current() {
    return this_.exec("current");
}

Variant _ArrayIterator::key() {
    return this_.exec("key");
}

Variant _ArrayIterator::next() {
    return this_.exec("next");
}

Variant _ArrayIterator::valid() {
    return this_.exec("valid");
}

Variant _ArrayIterator::seek(const Variant &offset) {
    return this_.exec("seek", offset);
}

Variant _ArrayIterator::__debugInfo() {
    return this_.exec("__debugInfo");
}


Variant RecursiveArrayIterator::hasChildren() {
    return this_.exec("hasChildren");
}

Variant RecursiveArrayIterator::getChildren() {
    return this_.exec("getChildren");
}

RecursiveArrayIterator::RecursiveArrayIterator(const Array &array, const Variant &flags) {
    this_ = newObject("RecursiveArrayIterator", array, flags);
}

Variant RecursiveArrayIterator::offsetExists(const Variant &key) {
    return this_.exec("offsetExists", key);
}

Variant RecursiveArrayIterator::offsetGet(const Variant &key) {
    return this_.exec("offsetGet", key);
}

Variant RecursiveArrayIterator::offsetSet(const Variant &key, const Variant &value) {
    return this_.exec("offsetSet", key, value);
}

Variant RecursiveArrayIterator::offsetUnset(const Variant &key) {
    return this_.exec("offsetUnset", key);
}

Variant RecursiveArrayIterator::append(const Variant &value) {
    return this_.exec("append", value);
}

Variant RecursiveArrayIterator::getArrayCopy() {
    return this_.exec("getArrayCopy");
}

Variant RecursiveArrayIterator::count() {
    return this_.exec("count");
}

Variant RecursiveArrayIterator::getFlags() {
    return this_.exec("getFlags");
}

Variant RecursiveArrayIterator::setFlags(const Variant &flags) {
    return this_.exec("setFlags", flags);
}

Variant RecursiveArrayIterator::asort(const Variant &flags) {
    return this_.exec("asort", flags);
}

Variant RecursiveArrayIterator::ksort(const Variant &flags) {
    return this_.exec("ksort", flags);
}

Variant RecursiveArrayIterator::uasort(const Variant &callback) {
    return this_.exec("uasort", callback);
}

Variant RecursiveArrayIterator::uksort(const Variant &callback) {
    return this_.exec("uksort", callback);
}

Variant RecursiveArrayIterator::natsort() {
    return this_.exec("natsort");
}

Variant RecursiveArrayIterator::natcasesort() {
    return this_.exec("natcasesort");
}

Variant RecursiveArrayIterator::unserialize(const Variant &data) {
    return this_.exec("unserialize", data);
}

Variant RecursiveArrayIterator::serialize() {
    return this_.exec("serialize");
}

Variant RecursiveArrayIterator::__serialize() {
    return this_.exec("__serialize");
}

Variant RecursiveArrayIterator::__unserialize(const Variant &data) {
    return this_.exec("__unserialize", data);
}

Variant RecursiveArrayIterator::rewind() {
    return this_.exec("rewind");
}

Variant RecursiveArrayIterator::current() {
    return this_.exec("current");
}

Variant RecursiveArrayIterator::key() {
    return this_.exec("key");
}

Variant RecursiveArrayIterator::next() {
    return this_.exec("next");
}

Variant RecursiveArrayIterator::valid() {
    return this_.exec("valid");
}

Variant RecursiveArrayIterator::seek(const Variant &offset) {
    return this_.exec("seek", offset);
}

Variant RecursiveArrayIterator::__debugInfo() {
    return this_.exec("__debugInfo");
}


SplFileInfo::SplFileInfo(const Variant &filename) {
    this_ = newObject("SplFileInfo", filename);
}

Variant SplFileInfo::getPath() {
    return this_.exec("getPath");
}

Variant SplFileInfo::getFilename() {
    return this_.exec("getFilename");
}

Variant SplFileInfo::getExtension() {
    return this_.exec("getExtension");
}

Variant SplFileInfo::getBasename(const Variant &suffix) {
    return this_.exec("getBasename", suffix);
}

Variant SplFileInfo::getPathname() {
    return this_.exec("getPathname");
}

Variant SplFileInfo::getPerms() {
    return this_.exec("getPerms");
}

Variant SplFileInfo::getInode() {
    return this_.exec("getInode");
}

Variant SplFileInfo::getSize() {
    return this_.exec("getSize");
}

Variant SplFileInfo::getOwner() {
    return this_.exec("getOwner");
}

Variant SplFileInfo::getGroup() {
    return this_.exec("getGroup");
}

Variant SplFileInfo::getATime() {
    return this_.exec("getATime");
}

Variant SplFileInfo::getMTime() {
    return this_.exec("getMTime");
}

Variant SplFileInfo::getCTime() {
    return this_.exec("getCTime");
}

Variant SplFileInfo::getType() {
    return this_.exec("getType");
}

Variant SplFileInfo::isWritable() {
    return this_.exec("isWritable");
}

Variant SplFileInfo::isReadable() {
    return this_.exec("isReadable");
}

Variant SplFileInfo::isExecutable() {
    return this_.exec("isExecutable");
}

Variant SplFileInfo::isFile() {
    return this_.exec("isFile");
}

Variant SplFileInfo::isDir() {
    return this_.exec("isDir");
}

Variant SplFileInfo::isLink() {
    return this_.exec("isLink");
}

Variant SplFileInfo::getLinkTarget() {
    return this_.exec("getLinkTarget");
}

Variant SplFileInfo::getRealPath() {
    return this_.exec("getRealPath");
}

Variant SplFileInfo::getFileInfo(const Variant &_class) {
    return this_.exec("getFileInfo", _class);
}

Variant SplFileInfo::getPathInfo(const Variant &_class) {
    return this_.exec("getPathInfo", _class);
}

Variant SplFileInfo::openFile(const Variant &mode, const Variant &use_include_path, const Variant &context) {
    return this_.exec("openFile", mode, use_include_path, context);
}

Variant SplFileInfo::setFileClass(const Variant &_class) {
    return this_.exec("setFileClass", _class);
}

Variant SplFileInfo::setInfoClass(const Variant &_class) {
    return this_.exec("setInfoClass", _class);
}

Variant SplFileInfo::__toString() {
    return this_.exec("__toString");
}

Variant SplFileInfo::__debugInfo() {
    return this_.exec("__debugInfo");
}

Variant SplFileInfo::_bad_state_ex() {
    return this_.exec("_bad_state_ex");
}


DirectoryIterator::DirectoryIterator(const Variant &directory) {
    this_ = newObject("DirectoryIterator", directory);
}

Variant DirectoryIterator::getFilename() {
    return this_.exec("getFilename");
}

Variant DirectoryIterator::getExtension() {
    return this_.exec("getExtension");
}

Variant DirectoryIterator::getBasename(const Variant &suffix) {
    return this_.exec("getBasename", suffix);
}

Variant DirectoryIterator::isDot() {
    return this_.exec("isDot");
}

Variant DirectoryIterator::rewind() {
    return this_.exec("rewind");
}

Variant DirectoryIterator::valid() {
    return this_.exec("valid");
}

Variant DirectoryIterator::key() {
    return this_.exec("key");
}

Variant DirectoryIterator::current() {
    return this_.exec("current");
}

Variant DirectoryIterator::next() {
    return this_.exec("next");
}

Variant DirectoryIterator::seek(const Variant &offset) {
    return this_.exec("seek", offset);
}

Variant DirectoryIterator::__toString() {
    return this_.exec("__toString");
}

Variant DirectoryIterator::getPath() {
    return this_.exec("getPath");
}

Variant DirectoryIterator::getPathname() {
    return this_.exec("getPathname");
}

Variant DirectoryIterator::getPerms() {
    return this_.exec("getPerms");
}

Variant DirectoryIterator::getInode() {
    return this_.exec("getInode");
}

Variant DirectoryIterator::getSize() {
    return this_.exec("getSize");
}

Variant DirectoryIterator::getOwner() {
    return this_.exec("getOwner");
}

Variant DirectoryIterator::getGroup() {
    return this_.exec("getGroup");
}

Variant DirectoryIterator::getATime() {
    return this_.exec("getATime");
}

Variant DirectoryIterator::getMTime() {
    return this_.exec("getMTime");
}

Variant DirectoryIterator::getCTime() {
    return this_.exec("getCTime");
}

Variant DirectoryIterator::getType() {
    return this_.exec("getType");
}

Variant DirectoryIterator::isWritable() {
    return this_.exec("isWritable");
}

Variant DirectoryIterator::isReadable() {
    return this_.exec("isReadable");
}

Variant DirectoryIterator::isExecutable() {
    return this_.exec("isExecutable");
}

Variant DirectoryIterator::isFile() {
    return this_.exec("isFile");
}

Variant DirectoryIterator::isDir() {
    return this_.exec("isDir");
}

Variant DirectoryIterator::isLink() {
    return this_.exec("isLink");
}

Variant DirectoryIterator::getLinkTarget() {
    return this_.exec("getLinkTarget");
}

Variant DirectoryIterator::getRealPath() {
    return this_.exec("getRealPath");
}

Variant DirectoryIterator::getFileInfo(const Variant &_class) {
    return this_.exec("getFileInfo", _class);
}

Variant DirectoryIterator::getPathInfo(const Variant &_class) {
    return this_.exec("getPathInfo", _class);
}

Variant DirectoryIterator::openFile(const Variant &mode, const Variant &use_include_path, const Variant &context) {
    return this_.exec("openFile", mode, use_include_path, context);
}

Variant DirectoryIterator::setFileClass(const Variant &_class) {
    return this_.exec("setFileClass", _class);
}

Variant DirectoryIterator::setInfoClass(const Variant &_class) {
    return this_.exec("setInfoClass", _class);
}

Variant DirectoryIterator::__debugInfo() {
    return this_.exec("__debugInfo");
}

Variant DirectoryIterator::_bad_state_ex() {
    return this_.exec("_bad_state_ex");
}


FilesystemIterator::FilesystemIterator(const Variant &directory, const Variant &flags) {
    this_ = newObject("FilesystemIterator", directory, flags);
}

Variant FilesystemIterator::rewind() {
    return this_.exec("rewind");
}

Variant FilesystemIterator::key() {
    return this_.exec("key");
}

Variant FilesystemIterator::current() {
    return this_.exec("current");
}

Variant FilesystemIterator::getFlags() {
    return this_.exec("getFlags");
}

Variant FilesystemIterator::setFlags(const Variant &flags) {
    return this_.exec("setFlags", flags);
}

Variant FilesystemIterator::getFilename() {
    return this_.exec("getFilename");
}

Variant FilesystemIterator::getExtension() {
    return this_.exec("getExtension");
}

Variant FilesystemIterator::getBasename(const Variant &suffix) {
    return this_.exec("getBasename", suffix);
}

Variant FilesystemIterator::isDot() {
    return this_.exec("isDot");
}

Variant FilesystemIterator::valid() {
    return this_.exec("valid");
}

Variant FilesystemIterator::next() {
    return this_.exec("next");
}

Variant FilesystemIterator::seek(const Variant &offset) {
    return this_.exec("seek", offset);
}

Variant FilesystemIterator::__toString() {
    return this_.exec("__toString");
}

Variant FilesystemIterator::getPath() {
    return this_.exec("getPath");
}

Variant FilesystemIterator::getPathname() {
    return this_.exec("getPathname");
}

Variant FilesystemIterator::getPerms() {
    return this_.exec("getPerms");
}

Variant FilesystemIterator::getInode() {
    return this_.exec("getInode");
}

Variant FilesystemIterator::getSize() {
    return this_.exec("getSize");
}

Variant FilesystemIterator::getOwner() {
    return this_.exec("getOwner");
}

Variant FilesystemIterator::getGroup() {
    return this_.exec("getGroup");
}

Variant FilesystemIterator::getATime() {
    return this_.exec("getATime");
}

Variant FilesystemIterator::getMTime() {
    return this_.exec("getMTime");
}

Variant FilesystemIterator::getCTime() {
    return this_.exec("getCTime");
}

Variant FilesystemIterator::getType() {
    return this_.exec("getType");
}

Variant FilesystemIterator::isWritable() {
    return this_.exec("isWritable");
}

Variant FilesystemIterator::isReadable() {
    return this_.exec("isReadable");
}

Variant FilesystemIterator::isExecutable() {
    return this_.exec("isExecutable");
}

Variant FilesystemIterator::isFile() {
    return this_.exec("isFile");
}

Variant FilesystemIterator::isDir() {
    return this_.exec("isDir");
}

Variant FilesystemIterator::isLink() {
    return this_.exec("isLink");
}

Variant FilesystemIterator::getLinkTarget() {
    return this_.exec("getLinkTarget");
}

Variant FilesystemIterator::getRealPath() {
    return this_.exec("getRealPath");
}

Variant FilesystemIterator::getFileInfo(const Variant &_class) {
    return this_.exec("getFileInfo", _class);
}

Variant FilesystemIterator::getPathInfo(const Variant &_class) {
    return this_.exec("getPathInfo", _class);
}

Variant FilesystemIterator::openFile(const Variant &mode, const Variant &use_include_path, const Variant &context) {
    return this_.exec("openFile", mode, use_include_path, context);
}

Variant FilesystemIterator::setFileClass(const Variant &_class) {
    return this_.exec("setFileClass", _class);
}

Variant FilesystemIterator::setInfoClass(const Variant &_class) {
    return this_.exec("setInfoClass", _class);
}

Variant FilesystemIterator::__debugInfo() {
    return this_.exec("__debugInfo");
}

Variant FilesystemIterator::_bad_state_ex() {
    return this_.exec("_bad_state_ex");
}


RecursiveDirectoryIterator::RecursiveDirectoryIterator(const Variant &directory, const Variant &flags) {
    this_ = newObject("RecursiveDirectoryIterator", directory, flags);
}

Variant RecursiveDirectoryIterator::hasChildren(const Variant &allow_links) {
    return this_.exec("hasChildren", allow_links);
}

Variant RecursiveDirectoryIterator::getChildren() {
    return this_.exec("getChildren");
}

Variant RecursiveDirectoryIterator::getSubPath() {
    return this_.exec("getSubPath");
}

Variant RecursiveDirectoryIterator::getSubPathname() {
    return this_.exec("getSubPathname");
}

Variant RecursiveDirectoryIterator::rewind() {
    return this_.exec("rewind");
}

Variant RecursiveDirectoryIterator::key() {
    return this_.exec("key");
}

Variant RecursiveDirectoryIterator::current() {
    return this_.exec("current");
}

Variant RecursiveDirectoryIterator::getFlags() {
    return this_.exec("getFlags");
}

Variant RecursiveDirectoryIterator::setFlags(const Variant &flags) {
    return this_.exec("setFlags", flags);
}

Variant RecursiveDirectoryIterator::getFilename() {
    return this_.exec("getFilename");
}

Variant RecursiveDirectoryIterator::getExtension() {
    return this_.exec("getExtension");
}

Variant RecursiveDirectoryIterator::getBasename(const Variant &suffix) {
    return this_.exec("getBasename", suffix);
}

Variant RecursiveDirectoryIterator::isDot() {
    return this_.exec("isDot");
}

Variant RecursiveDirectoryIterator::valid() {
    return this_.exec("valid");
}

Variant RecursiveDirectoryIterator::next() {
    return this_.exec("next");
}

Variant RecursiveDirectoryIterator::seek(const Variant &offset) {
    return this_.exec("seek", offset);
}

Variant RecursiveDirectoryIterator::__toString() {
    return this_.exec("__toString");
}

Variant RecursiveDirectoryIterator::getPath() {
    return this_.exec("getPath");
}

Variant RecursiveDirectoryIterator::getPathname() {
    return this_.exec("getPathname");
}

Variant RecursiveDirectoryIterator::getPerms() {
    return this_.exec("getPerms");
}

Variant RecursiveDirectoryIterator::getInode() {
    return this_.exec("getInode");
}

Variant RecursiveDirectoryIterator::getSize() {
    return this_.exec("getSize");
}

Variant RecursiveDirectoryIterator::getOwner() {
    return this_.exec("getOwner");
}

Variant RecursiveDirectoryIterator::getGroup() {
    return this_.exec("getGroup");
}

Variant RecursiveDirectoryIterator::getATime() {
    return this_.exec("getATime");
}

Variant RecursiveDirectoryIterator::getMTime() {
    return this_.exec("getMTime");
}

Variant RecursiveDirectoryIterator::getCTime() {
    return this_.exec("getCTime");
}

Variant RecursiveDirectoryIterator::getType() {
    return this_.exec("getType");
}

Variant RecursiveDirectoryIterator::isWritable() {
    return this_.exec("isWritable");
}

Variant RecursiveDirectoryIterator::isReadable() {
    return this_.exec("isReadable");
}

Variant RecursiveDirectoryIterator::isExecutable() {
    return this_.exec("isExecutable");
}

Variant RecursiveDirectoryIterator::isFile() {
    return this_.exec("isFile");
}

Variant RecursiveDirectoryIterator::isDir() {
    return this_.exec("isDir");
}

Variant RecursiveDirectoryIterator::isLink() {
    return this_.exec("isLink");
}

Variant RecursiveDirectoryIterator::getLinkTarget() {
    return this_.exec("getLinkTarget");
}

Variant RecursiveDirectoryIterator::getRealPath() {
    return this_.exec("getRealPath");
}

Variant RecursiveDirectoryIterator::getFileInfo(const Variant &_class) {
    return this_.exec("getFileInfo", _class);
}

Variant RecursiveDirectoryIterator::getPathInfo(const Variant &_class) {
    return this_.exec("getPathInfo", _class);
}

Variant RecursiveDirectoryIterator::openFile(const Variant &mode, const Variant &use_include_path, const Variant &context) {
    return this_.exec("openFile", mode, use_include_path, context);
}

Variant RecursiveDirectoryIterator::setFileClass(const Variant &_class) {
    return this_.exec("setFileClass", _class);
}

Variant RecursiveDirectoryIterator::setInfoClass(const Variant &_class) {
    return this_.exec("setInfoClass", _class);
}

Variant RecursiveDirectoryIterator::__debugInfo() {
    return this_.exec("__debugInfo");
}

Variant RecursiveDirectoryIterator::_bad_state_ex() {
    return this_.exec("_bad_state_ex");
}


GlobIterator::GlobIterator(const Variant &pattern, const Variant &flags) {
    this_ = newObject("GlobIterator", pattern, flags);
}

Variant GlobIterator::count() {
    return this_.exec("count");
}

Variant GlobIterator::rewind() {
    return this_.exec("rewind");
}

Variant GlobIterator::key() {
    return this_.exec("key");
}

Variant GlobIterator::current() {
    return this_.exec("current");
}

Variant GlobIterator::getFlags() {
    return this_.exec("getFlags");
}

Variant GlobIterator::setFlags(const Variant &flags) {
    return this_.exec("setFlags", flags);
}

Variant GlobIterator::getFilename() {
    return this_.exec("getFilename");
}

Variant GlobIterator::getExtension() {
    return this_.exec("getExtension");
}

Variant GlobIterator::getBasename(const Variant &suffix) {
    return this_.exec("getBasename", suffix);
}

Variant GlobIterator::isDot() {
    return this_.exec("isDot");
}

Variant GlobIterator::valid() {
    return this_.exec("valid");
}

Variant GlobIterator::next() {
    return this_.exec("next");
}

Variant GlobIterator::seek(const Variant &offset) {
    return this_.exec("seek", offset);
}

Variant GlobIterator::__toString() {
    return this_.exec("__toString");
}

Variant GlobIterator::getPath() {
    return this_.exec("getPath");
}

Variant GlobIterator::getPathname() {
    return this_.exec("getPathname");
}

Variant GlobIterator::getPerms() {
    return this_.exec("getPerms");
}

Variant GlobIterator::getInode() {
    return this_.exec("getInode");
}

Variant GlobIterator::getSize() {
    return this_.exec("getSize");
}

Variant GlobIterator::getOwner() {
    return this_.exec("getOwner");
}

Variant GlobIterator::getGroup() {
    return this_.exec("getGroup");
}

Variant GlobIterator::getATime() {
    return this_.exec("getATime");
}

Variant GlobIterator::getMTime() {
    return this_.exec("getMTime");
}

Variant GlobIterator::getCTime() {
    return this_.exec("getCTime");
}

Variant GlobIterator::getType() {
    return this_.exec("getType");
}

Variant GlobIterator::isWritable() {
    return this_.exec("isWritable");
}

Variant GlobIterator::isReadable() {
    return this_.exec("isReadable");
}

Variant GlobIterator::isExecutable() {
    return this_.exec("isExecutable");
}

Variant GlobIterator::isFile() {
    return this_.exec("isFile");
}

Variant GlobIterator::isDir() {
    return this_.exec("isDir");
}

Variant GlobIterator::isLink() {
    return this_.exec("isLink");
}

Variant GlobIterator::getLinkTarget() {
    return this_.exec("getLinkTarget");
}

Variant GlobIterator::getRealPath() {
    return this_.exec("getRealPath");
}

Variant GlobIterator::getFileInfo(const Variant &_class) {
    return this_.exec("getFileInfo", _class);
}

Variant GlobIterator::getPathInfo(const Variant &_class) {
    return this_.exec("getPathInfo", _class);
}

Variant GlobIterator::openFile(const Variant &mode, const Variant &use_include_path, const Variant &context) {
    return this_.exec("openFile", mode, use_include_path, context);
}

Variant GlobIterator::setFileClass(const Variant &_class) {
    return this_.exec("setFileClass", _class);
}

Variant GlobIterator::setInfoClass(const Variant &_class) {
    return this_.exec("setInfoClass", _class);
}

Variant GlobIterator::__debugInfo() {
    return this_.exec("__debugInfo");
}

Variant GlobIterator::_bad_state_ex() {
    return this_.exec("_bad_state_ex");
}


SplFileObject::SplFileObject(const Variant &filename, const Variant &mode, const Variant &use_include_path, const Variant &context) {
    this_ = newObject("SplFileObject", filename, mode, use_include_path, context);
}

Variant SplFileObject::rewind() {
    return this_.exec("rewind");
}

Variant SplFileObject::eof() {
    return this_.exec("eof");
}

Variant SplFileObject::valid() {
    return this_.exec("valid");
}

Variant SplFileObject::fgets() {
    return this_.exec("fgets");
}

Variant SplFileObject::fread(const Variant &length) {
    return this_.exec("fread", length);
}

Variant SplFileObject::fgetcsv(const Variant &separator, const Variant &enclosure, const Variant &escape) {
    return this_.exec("fgetcsv", separator, enclosure, escape);
}

Variant SplFileObject::fputcsv(const Variant &fields, const Variant &separator, const Variant &enclosure, const Variant &escape, const Variant &eol) {
    return this_.exec("fputcsv", fields, separator, enclosure, escape, eol);
}

Variant SplFileObject::setCsvControl(const Variant &separator, const Variant &enclosure, const Variant &escape) {
    return this_.exec("setCsvControl", separator, enclosure, escape);
}

Variant SplFileObject::getCsvControl() {
    return this_.exec("getCsvControl");
}

Variant SplFileObject::flock(const Variant &operation, const Variant &would_block) {
    return this_.exec("flock", operation, would_block);
}

Variant SplFileObject::fflush() {
    return this_.exec("fflush");
}

Variant SplFileObject::ftell() {
    return this_.exec("ftell");
}

Variant SplFileObject::fseek(const Variant &offset, const Variant &whence) {
    return this_.exec("fseek", offset, whence);
}

Variant SplFileObject::fgetc() {
    return this_.exec("fgetc");
}

Variant SplFileObject::fpassthru() {
    return this_.exec("fpassthru");
}

Variant SplFileObject::fscanf(const Variant &format, const Variant &vars) {
    return this_.exec("fscanf", format, vars);
}

Variant SplFileObject::fwrite(const Variant &data, const Variant &length) {
    return this_.exec("fwrite", data, length);
}

Variant SplFileObject::fstat() {
    return this_.exec("fstat");
}

Variant SplFileObject::ftruncate(const Variant &size) {
    return this_.exec("ftruncate", size);
}

Variant SplFileObject::current() {
    return this_.exec("current");
}

Variant SplFileObject::key() {
    return this_.exec("key");
}

Variant SplFileObject::next() {
    return this_.exec("next");
}

Variant SplFileObject::setFlags(const Variant &flags) {
    return this_.exec("setFlags", flags);
}

Variant SplFileObject::getFlags() {
    return this_.exec("getFlags");
}

Variant SplFileObject::setMaxLineLen(const Variant &max_length) {
    return this_.exec("setMaxLineLen", max_length);
}

Variant SplFileObject::getMaxLineLen() {
    return this_.exec("getMaxLineLen");
}

Variant SplFileObject::hasChildren() {
    return this_.exec("hasChildren");
}

Variant SplFileObject::getChildren() {
    return this_.exec("getChildren");
}

Variant SplFileObject::seek(const Variant &line) {
    return this_.exec("seek", line);
}

Variant SplFileObject::getCurrentLine() {
    return this_.exec("getCurrentLine");
}

Variant SplFileObject::__toString() {
    return this_.exec("__toString");
}

Variant SplFileObject::getPath() {
    return this_.exec("getPath");
}

Variant SplFileObject::getFilename() {
    return this_.exec("getFilename");
}

Variant SplFileObject::getExtension() {
    return this_.exec("getExtension");
}

Variant SplFileObject::getBasename(const Variant &suffix) {
    return this_.exec("getBasename", suffix);
}

Variant SplFileObject::getPathname() {
    return this_.exec("getPathname");
}

Variant SplFileObject::getPerms() {
    return this_.exec("getPerms");
}

Variant SplFileObject::getInode() {
    return this_.exec("getInode");
}

Variant SplFileObject::getSize() {
    return this_.exec("getSize");
}

Variant SplFileObject::getOwner() {
    return this_.exec("getOwner");
}

Variant SplFileObject::getGroup() {
    return this_.exec("getGroup");
}

Variant SplFileObject::getATime() {
    return this_.exec("getATime");
}

Variant SplFileObject::getMTime() {
    return this_.exec("getMTime");
}

Variant SplFileObject::getCTime() {
    return this_.exec("getCTime");
}

Variant SplFileObject::getType() {
    return this_.exec("getType");
}

Variant SplFileObject::isWritable() {
    return this_.exec("isWritable");
}

Variant SplFileObject::isReadable() {
    return this_.exec("isReadable");
}

Variant SplFileObject::isExecutable() {
    return this_.exec("isExecutable");
}

Variant SplFileObject::isFile() {
    return this_.exec("isFile");
}

Variant SplFileObject::isDir() {
    return this_.exec("isDir");
}

Variant SplFileObject::isLink() {
    return this_.exec("isLink");
}

Variant SplFileObject::getLinkTarget() {
    return this_.exec("getLinkTarget");
}

Variant SplFileObject::getRealPath() {
    return this_.exec("getRealPath");
}

Variant SplFileObject::getFileInfo(const Variant &_class) {
    return this_.exec("getFileInfo", _class);
}

Variant SplFileObject::getPathInfo(const Variant &_class) {
    return this_.exec("getPathInfo", _class);
}

Variant SplFileObject::openFile(const Variant &mode, const Variant &use_include_path, const Variant &context) {
    return this_.exec("openFile", mode, use_include_path, context);
}

Variant SplFileObject::setFileClass(const Variant &_class) {
    return this_.exec("setFileClass", _class);
}

Variant SplFileObject::setInfoClass(const Variant &_class) {
    return this_.exec("setInfoClass", _class);
}

Variant SplFileObject::__debugInfo() {
    return this_.exec("__debugInfo");
}

Variant SplFileObject::_bad_state_ex() {
    return this_.exec("_bad_state_ex");
}


SplTempFileObject::SplTempFileObject(const Variant &max_memory) {
    this_ = newObject("SplTempFileObject", max_memory);
}

Variant SplTempFileObject::rewind() {
    return this_.exec("rewind");
}

Variant SplTempFileObject::eof() {
    return this_.exec("eof");
}

Variant SplTempFileObject::valid() {
    return this_.exec("valid");
}

Variant SplTempFileObject::fgets() {
    return this_.exec("fgets");
}

Variant SplTempFileObject::fread(const Variant &length) {
    return this_.exec("fread", length);
}

Variant SplTempFileObject::fgetcsv(const Variant &separator, const Variant &enclosure, const Variant &escape) {
    return this_.exec("fgetcsv", separator, enclosure, escape);
}

Variant SplTempFileObject::fputcsv(const Variant &fields, const Variant &separator, const Variant &enclosure, const Variant &escape, const Variant &eol) {
    return this_.exec("fputcsv", fields, separator, enclosure, escape, eol);
}

Variant SplTempFileObject::setCsvControl(const Variant &separator, const Variant &enclosure, const Variant &escape) {
    return this_.exec("setCsvControl", separator, enclosure, escape);
}

Variant SplTempFileObject::getCsvControl() {
    return this_.exec("getCsvControl");
}

Variant SplTempFileObject::flock(const Variant &operation, const Variant &would_block) {
    return this_.exec("flock", operation, would_block);
}

Variant SplTempFileObject::fflush() {
    return this_.exec("fflush");
}

Variant SplTempFileObject::ftell() {
    return this_.exec("ftell");
}

Variant SplTempFileObject::fseek(const Variant &offset, const Variant &whence) {
    return this_.exec("fseek", offset, whence);
}

Variant SplTempFileObject::fgetc() {
    return this_.exec("fgetc");
}

Variant SplTempFileObject::fpassthru() {
    return this_.exec("fpassthru");
}

Variant SplTempFileObject::fscanf(const Variant &format, const Variant &vars) {
    return this_.exec("fscanf", format, vars);
}

Variant SplTempFileObject::fwrite(const Variant &data, const Variant &length) {
    return this_.exec("fwrite", data, length);
}

Variant SplTempFileObject::fstat() {
    return this_.exec("fstat");
}

Variant SplTempFileObject::ftruncate(const Variant &size) {
    return this_.exec("ftruncate", size);
}

Variant SplTempFileObject::current() {
    return this_.exec("current");
}

Variant SplTempFileObject::key() {
    return this_.exec("key");
}

Variant SplTempFileObject::next() {
    return this_.exec("next");
}

Variant SplTempFileObject::setFlags(const Variant &flags) {
    return this_.exec("setFlags", flags);
}

Variant SplTempFileObject::getFlags() {
    return this_.exec("getFlags");
}

Variant SplTempFileObject::setMaxLineLen(const Variant &max_length) {
    return this_.exec("setMaxLineLen", max_length);
}

Variant SplTempFileObject::getMaxLineLen() {
    return this_.exec("getMaxLineLen");
}

Variant SplTempFileObject::hasChildren() {
    return this_.exec("hasChildren");
}

Variant SplTempFileObject::getChildren() {
    return this_.exec("getChildren");
}

Variant SplTempFileObject::seek(const Variant &line) {
    return this_.exec("seek", line);
}

Variant SplTempFileObject::getCurrentLine() {
    return this_.exec("getCurrentLine");
}

Variant SplTempFileObject::__toString() {
    return this_.exec("__toString");
}

Variant SplTempFileObject::getPath() {
    return this_.exec("getPath");
}

Variant SplTempFileObject::getFilename() {
    return this_.exec("getFilename");
}

Variant SplTempFileObject::getExtension() {
    return this_.exec("getExtension");
}

Variant SplTempFileObject::getBasename(const Variant &suffix) {
    return this_.exec("getBasename", suffix);
}

Variant SplTempFileObject::getPathname() {
    return this_.exec("getPathname");
}

Variant SplTempFileObject::getPerms() {
    return this_.exec("getPerms");
}

Variant SplTempFileObject::getInode() {
    return this_.exec("getInode");
}

Variant SplTempFileObject::getSize() {
    return this_.exec("getSize");
}

Variant SplTempFileObject::getOwner() {
    return this_.exec("getOwner");
}

Variant SplTempFileObject::getGroup() {
    return this_.exec("getGroup");
}

Variant SplTempFileObject::getATime() {
    return this_.exec("getATime");
}

Variant SplTempFileObject::getMTime() {
    return this_.exec("getMTime");
}

Variant SplTempFileObject::getCTime() {
    return this_.exec("getCTime");
}

Variant SplTempFileObject::getType() {
    return this_.exec("getType");
}

Variant SplTempFileObject::isWritable() {
    return this_.exec("isWritable");
}

Variant SplTempFileObject::isReadable() {
    return this_.exec("isReadable");
}

Variant SplTempFileObject::isExecutable() {
    return this_.exec("isExecutable");
}

Variant SplTempFileObject::isFile() {
    return this_.exec("isFile");
}

Variant SplTempFileObject::isDir() {
    return this_.exec("isDir");
}

Variant SplTempFileObject::isLink() {
    return this_.exec("isLink");
}

Variant SplTempFileObject::getLinkTarget() {
    return this_.exec("getLinkTarget");
}

Variant SplTempFileObject::getRealPath() {
    return this_.exec("getRealPath");
}

Variant SplTempFileObject::getFileInfo(const Variant &_class) {
    return this_.exec("getFileInfo", _class);
}

Variant SplTempFileObject::getPathInfo(const Variant &_class) {
    return this_.exec("getPathInfo", _class);
}

Variant SplTempFileObject::openFile(const Variant &mode, const Variant &use_include_path, const Variant &context) {
    return this_.exec("openFile", mode, use_include_path, context);
}

Variant SplTempFileObject::setFileClass(const Variant &_class) {
    return this_.exec("setFileClass", _class);
}

Variant SplTempFileObject::setInfoClass(const Variant &_class) {
    return this_.exec("setInfoClass", _class);
}

Variant SplTempFileObject::__debugInfo() {
    return this_.exec("__debugInfo");
}

Variant SplTempFileObject::_bad_state_ex() {
    return this_.exec("_bad_state_ex");
}


Variant SplDoublyLinkedList::add(const Variant &index, const Variant &value) {
    return this_.exec("add", index, value);
}

Variant SplDoublyLinkedList::pop() {
    return this_.exec("pop");
}

Variant SplDoublyLinkedList::shift() {
    return this_.exec("shift");
}

Variant SplDoublyLinkedList::push(const Variant &value) {
    return this_.exec("push", value);
}

Variant SplDoublyLinkedList::unshift(const Variant &value) {
    return this_.exec("unshift", value);
}

Variant SplDoublyLinkedList::top() {
    return this_.exec("top");
}

Variant SplDoublyLinkedList::bottom() {
    return this_.exec("bottom");
}

Variant SplDoublyLinkedList::__debugInfo() {
    return this_.exec("__debugInfo");
}

Variant SplDoublyLinkedList::count() {
    return this_.exec("count");
}

Variant SplDoublyLinkedList::isEmpty() {
    return this_.exec("isEmpty");
}

Variant SplDoublyLinkedList::setIteratorMode(const Variant &mode) {
    return this_.exec("setIteratorMode", mode);
}

Variant SplDoublyLinkedList::getIteratorMode() {
    return this_.exec("getIteratorMode");
}

Variant SplDoublyLinkedList::offsetExists(const Variant &index) {
    return this_.exec("offsetExists", index);
}

Variant SplDoublyLinkedList::offsetGet(const Variant &index) {
    return this_.exec("offsetGet", index);
}

Variant SplDoublyLinkedList::offsetSet(const Variant &index, const Variant &value) {
    return this_.exec("offsetSet", index, value);
}

Variant SplDoublyLinkedList::offsetUnset(const Variant &index) {
    return this_.exec("offsetUnset", index);
}

Variant SplDoublyLinkedList::rewind() {
    return this_.exec("rewind");
}

Variant SplDoublyLinkedList::current() {
    return this_.exec("current");
}

Variant SplDoublyLinkedList::key() {
    return this_.exec("key");
}

Variant SplDoublyLinkedList::prev() {
    return this_.exec("prev");
}

Variant SplDoublyLinkedList::next() {
    return this_.exec("next");
}

Variant SplDoublyLinkedList::valid() {
    return this_.exec("valid");
}

Variant SplDoublyLinkedList::unserialize(const Variant &data) {
    return this_.exec("unserialize", data);
}

Variant SplDoublyLinkedList::serialize() {
    return this_.exec("serialize");
}

Variant SplDoublyLinkedList::__serialize() {
    return this_.exec("__serialize");
}

Variant SplDoublyLinkedList::__unserialize(const Variant &data) {
    return this_.exec("__unserialize", data);
}


Variant SplQueue::enqueue(const Variant &value) {
    return this_.exec("enqueue", value);
}

Variant SplQueue::dequeue() {
    return this_.exec("dequeue");
}

Variant SplQueue::add(const Variant &index, const Variant &value) {
    return this_.exec("add", index, value);
}

Variant SplQueue::pop() {
    return this_.exec("pop");
}

Variant SplQueue::shift() {
    return this_.exec("shift");
}

Variant SplQueue::push(const Variant &value) {
    return this_.exec("push", value);
}

Variant SplQueue::unshift(const Variant &value) {
    return this_.exec("unshift", value);
}

Variant SplQueue::top() {
    return this_.exec("top");
}

Variant SplQueue::bottom() {
    return this_.exec("bottom");
}

Variant SplQueue::__debugInfo() {
    return this_.exec("__debugInfo");
}

Variant SplQueue::count() {
    return this_.exec("count");
}

Variant SplQueue::isEmpty() {
    return this_.exec("isEmpty");
}

Variant SplQueue::setIteratorMode(const Variant &mode) {
    return this_.exec("setIteratorMode", mode);
}

Variant SplQueue::getIteratorMode() {
    return this_.exec("getIteratorMode");
}

Variant SplQueue::offsetExists(const Variant &index) {
    return this_.exec("offsetExists", index);
}

Variant SplQueue::offsetGet(const Variant &index) {
    return this_.exec("offsetGet", index);
}

Variant SplQueue::offsetSet(const Variant &index, const Variant &value) {
    return this_.exec("offsetSet", index, value);
}

Variant SplQueue::offsetUnset(const Variant &index) {
    return this_.exec("offsetUnset", index);
}

Variant SplQueue::rewind() {
    return this_.exec("rewind");
}

Variant SplQueue::current() {
    return this_.exec("current");
}

Variant SplQueue::key() {
    return this_.exec("key");
}

Variant SplQueue::prev() {
    return this_.exec("prev");
}

Variant SplQueue::next() {
    return this_.exec("next");
}

Variant SplQueue::valid() {
    return this_.exec("valid");
}

Variant SplQueue::unserialize(const Variant &data) {
    return this_.exec("unserialize", data);
}

Variant SplQueue::serialize() {
    return this_.exec("serialize");
}

Variant SplQueue::__serialize() {
    return this_.exec("__serialize");
}

Variant SplQueue::__unserialize(const Variant &data) {
    return this_.exec("__unserialize", data);
}


Variant SplStack::add(const Variant &index, const Variant &value) {
    return this_.exec("add", index, value);
}

Variant SplStack::pop() {
    return this_.exec("pop");
}

Variant SplStack::shift() {
    return this_.exec("shift");
}

Variant SplStack::push(const Variant &value) {
    return this_.exec("push", value);
}

Variant SplStack::unshift(const Variant &value) {
    return this_.exec("unshift", value);
}

Variant SplStack::top() {
    return this_.exec("top");
}

Variant SplStack::bottom() {
    return this_.exec("bottom");
}

Variant SplStack::__debugInfo() {
    return this_.exec("__debugInfo");
}

Variant SplStack::count() {
    return this_.exec("count");
}

Variant SplStack::isEmpty() {
    return this_.exec("isEmpty");
}

Variant SplStack::setIteratorMode(const Variant &mode) {
    return this_.exec("setIteratorMode", mode);
}

Variant SplStack::getIteratorMode() {
    return this_.exec("getIteratorMode");
}

Variant SplStack::offsetExists(const Variant &index) {
    return this_.exec("offsetExists", index);
}

Variant SplStack::offsetGet(const Variant &index) {
    return this_.exec("offsetGet", index);
}

Variant SplStack::offsetSet(const Variant &index, const Variant &value) {
    return this_.exec("offsetSet", index, value);
}

Variant SplStack::offsetUnset(const Variant &index) {
    return this_.exec("offsetUnset", index);
}

Variant SplStack::rewind() {
    return this_.exec("rewind");
}

Variant SplStack::current() {
    return this_.exec("current");
}

Variant SplStack::key() {
    return this_.exec("key");
}

Variant SplStack::prev() {
    return this_.exec("prev");
}

Variant SplStack::next() {
    return this_.exec("next");
}

Variant SplStack::valid() {
    return this_.exec("valid");
}

Variant SplStack::unserialize(const Variant &data) {
    return this_.exec("unserialize", data);
}

Variant SplStack::serialize() {
    return this_.exec("serialize");
}

Variant SplStack::__serialize() {
    return this_.exec("__serialize");
}

Variant SplStack::__unserialize(const Variant &data) {
    return this_.exec("__unserialize", data);
}


Variant SplMinHeap::extract() {
    return this_.exec("extract");
}

Variant SplMinHeap::insert(const Variant &value) {
    return this_.exec("insert", value);
}

Variant SplMinHeap::top() {
    return this_.exec("top");
}

Variant SplMinHeap::count() {
    return this_.exec("count");
}

Variant SplMinHeap::isEmpty() {
    return this_.exec("isEmpty");
}

Variant SplMinHeap::rewind() {
    return this_.exec("rewind");
}

Variant SplMinHeap::current() {
    return this_.exec("current");
}

Variant SplMinHeap::key() {
    return this_.exec("key");
}

Variant SplMinHeap::next() {
    return this_.exec("next");
}

Variant SplMinHeap::valid() {
    return this_.exec("valid");
}

Variant SplMinHeap::recoverFromCorruption() {
    return this_.exec("recoverFromCorruption");
}

Variant SplMinHeap::isCorrupted() {
    return this_.exec("isCorrupted");
}

Variant SplMinHeap::__debugInfo() {
    return this_.exec("__debugInfo");
}


Variant SplMaxHeap::extract() {
    return this_.exec("extract");
}

Variant SplMaxHeap::insert(const Variant &value) {
    return this_.exec("insert", value);
}

Variant SplMaxHeap::top() {
    return this_.exec("top");
}

Variant SplMaxHeap::count() {
    return this_.exec("count");
}

Variant SplMaxHeap::isEmpty() {
    return this_.exec("isEmpty");
}

Variant SplMaxHeap::rewind() {
    return this_.exec("rewind");
}

Variant SplMaxHeap::current() {
    return this_.exec("current");
}

Variant SplMaxHeap::key() {
    return this_.exec("key");
}

Variant SplMaxHeap::next() {
    return this_.exec("next");
}

Variant SplMaxHeap::valid() {
    return this_.exec("valid");
}

Variant SplMaxHeap::recoverFromCorruption() {
    return this_.exec("recoverFromCorruption");
}

Variant SplMaxHeap::isCorrupted() {
    return this_.exec("isCorrupted");
}

Variant SplMaxHeap::__debugInfo() {
    return this_.exec("__debugInfo");
}


Variant SplPriorityQueue::compare(const Variant &priority1, const Variant &priority2) {
    return this_.exec("compare", priority1, priority2);
}

Variant SplPriorityQueue::insert(const Variant &value, const Variant &priority) {
    return this_.exec("insert", value, priority);
}

Variant SplPriorityQueue::setExtractFlags(const Variant &flags) {
    return this_.exec("setExtractFlags", flags);
}

Variant SplPriorityQueue::top() {
    return this_.exec("top");
}

Variant SplPriorityQueue::extract() {
    return this_.exec("extract");
}

Variant SplPriorityQueue::count() {
    return this_.exec("count");
}

Variant SplPriorityQueue::isEmpty() {
    return this_.exec("isEmpty");
}

Variant SplPriorityQueue::rewind() {
    return this_.exec("rewind");
}

Variant SplPriorityQueue::current() {
    return this_.exec("current");
}

Variant SplPriorityQueue::key() {
    return this_.exec("key");
}

Variant SplPriorityQueue::next() {
    return this_.exec("next");
}

Variant SplPriorityQueue::valid() {
    return this_.exec("valid");
}

Variant SplPriorityQueue::recoverFromCorruption() {
    return this_.exec("recoverFromCorruption");
}

Variant SplPriorityQueue::isCorrupted() {
    return this_.exec("isCorrupted");
}

Variant SplPriorityQueue::getExtractFlags() {
    return this_.exec("getExtractFlags");
}

Variant SplPriorityQueue::__debugInfo() {
    return this_.exec("__debugInfo");
}


SplFixedArray::SplFixedArray(const Variant &size) {
    this_ = newObject("SplFixedArray", size);
}

Variant SplFixedArray::__wakeup() {
    return this_.exec("__wakeup");
}

Variant SplFixedArray::__serialize() {
    return this_.exec("__serialize");
}

Variant SplFixedArray::__unserialize(const Variant &data) {
    return this_.exec("__unserialize", data);
}

Variant SplFixedArray::count() {
    return this_.exec("count");
}

Variant SplFixedArray::toArray() {
    return this_.exec("toArray");
}

Variant SplFixedArray::fromArray(const Variant &array, const Variant &preserve_keys) {
    static Variant fn { ZEND_STRL("SplFixedArray::fromArray"), true };
    return fn(array, preserve_keys);
}

Variant SplFixedArray::getSize() {
    return this_.exec("getSize");
}

Variant SplFixedArray::setSize(const Variant &size) {
    return this_.exec("setSize", size);
}

Variant SplFixedArray::offsetExists(const Variant &index) {
    return this_.exec("offsetExists", index);
}

Variant SplFixedArray::offsetGet(const Variant &index) {
    return this_.exec("offsetGet", index);
}

Variant SplFixedArray::offsetSet(const Variant &index, const Variant &value) {
    return this_.exec("offsetSet", index, value);
}

Variant SplFixedArray::offsetUnset(const Variant &index) {
    return this_.exec("offsetUnset", index);
}

Variant SplFixedArray::getIterator() {
    return this_.exec("getIterator");
}

Variant SplFixedArray::jsonSerialize() {
    return this_.exec("jsonSerialize");
}


Variant SplObjectStorage::attach(const Variant &object, const Variant &info) {
    return this_.exec("attach", object, info);
}

Variant SplObjectStorage::detach(const Variant &object) {
    return this_.exec("detach", object);
}

Variant SplObjectStorage::contains(const Variant &object) {
    return this_.exec("contains", object);
}

Variant SplObjectStorage::addAll(const Variant &storage) {
    return this_.exec("addAll", storage);
}

Variant SplObjectStorage::removeAll(const Variant &storage) {
    return this_.exec("removeAll", storage);
}

Variant SplObjectStorage::removeAllExcept(const Variant &storage) {
    return this_.exec("removeAllExcept", storage);
}

Variant SplObjectStorage::getInfo() {
    return this_.exec("getInfo");
}

Variant SplObjectStorage::setInfo(const Variant &info) {
    return this_.exec("setInfo", info);
}

Variant SplObjectStorage::count(const Variant &mode) {
    return this_.exec("count", mode);
}

Variant SplObjectStorage::rewind() {
    return this_.exec("rewind");
}

Variant SplObjectStorage::valid() {
    return this_.exec("valid");
}

Variant SplObjectStorage::key() {
    return this_.exec("key");
}

Variant SplObjectStorage::current() {
    return this_.exec("current");
}

Variant SplObjectStorage::next() {
    return this_.exec("next");
}

Variant SplObjectStorage::unserialize(const Variant &data) {
    return this_.exec("unserialize", data);
}

Variant SplObjectStorage::serialize() {
    return this_.exec("serialize");
}

Variant SplObjectStorage::offsetExists(const Variant &object) {
    return this_.exec("offsetExists", object);
}

Variant SplObjectStorage::offsetGet(const Variant &object) {
    return this_.exec("offsetGet", object);
}

Variant SplObjectStorage::offsetSet(const Variant &object, const Variant &info) {
    return this_.exec("offsetSet", object, info);
}

Variant SplObjectStorage::offsetUnset(const Variant &object) {
    return this_.exec("offsetUnset", object);
}

Variant SplObjectStorage::getHash(const Variant &object) {
    return this_.exec("getHash", object);
}

Variant SplObjectStorage::__serialize() {
    return this_.exec("__serialize");
}

Variant SplObjectStorage::__unserialize(const Variant &data) {
    return this_.exec("__unserialize", data);
}

Variant SplObjectStorage::__debugInfo() {
    return this_.exec("__debugInfo");
}


MultipleIterator::MultipleIterator(const Variant &flags) {
    this_ = newObject("MultipleIterator", flags);
}

Variant MultipleIterator::getFlags() {
    return this_.exec("getFlags");
}

Variant MultipleIterator::setFlags(const Variant &flags) {
    return this_.exec("setFlags", flags);
}

Variant MultipleIterator::attachIterator(const Variant &iterator, const Variant &info) {
    return this_.exec("attachIterator", iterator, info);
}

Variant MultipleIterator::detachIterator(const Variant &iterator) {
    return this_.exec("detachIterator", iterator);
}

Variant MultipleIterator::containsIterator(const Variant &iterator) {
    return this_.exec("containsIterator", iterator);
}

Variant MultipleIterator::countIterators() {
    return this_.exec("countIterators");
}

Variant MultipleIterator::rewind() {
    return this_.exec("rewind");
}

Variant MultipleIterator::valid() {
    return this_.exec("valid");
}

Variant MultipleIterator::key() {
    return this_.exec("key");
}

Variant MultipleIterator::current() {
    return this_.exec("current");
}

Variant MultipleIterator::next() {
    return this_.exec("next");
}

Variant MultipleIterator::__debugInfo() {
    return this_.exec("__debugInfo");
}


}

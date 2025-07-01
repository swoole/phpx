#include "phpx.h"
#include "class/spl.h"

namespace php {
LogicException::LogicException(const Variant &message, const Variant &code, const Variant &previous) {
    _this = newObject("LogicException", message, code, previous);
}

Variant LogicException::__wakeup() {
    return _this.exec("__wakeup");
}

Variant LogicException::getMessage() {
    return _this.exec("getMessage");
}

Variant LogicException::getCode() {
    return _this.exec("getCode");
}

Variant LogicException::getFile() {
    return _this.exec("getFile");
}

Variant LogicException::getLine() {
    return _this.exec("getLine");
}

Variant LogicException::getTrace() {
    return _this.exec("getTrace");
}

Variant LogicException::getPrevious() {
    return _this.exec("getPrevious");
}

Variant LogicException::getTraceAsString() {
    return _this.exec("getTraceAsString");
}

Variant LogicException::__toString() {
    return _this.exec("__toString");
}


BadFunctionCallException::BadFunctionCallException(const Variant &message, const Variant &code, const Variant &previous) {
    _this = newObject("BadFunctionCallException", message, code, previous);
}

Variant BadFunctionCallException::__wakeup() {
    return _this.exec("__wakeup");
}

Variant BadFunctionCallException::getMessage() {
    return _this.exec("getMessage");
}

Variant BadFunctionCallException::getCode() {
    return _this.exec("getCode");
}

Variant BadFunctionCallException::getFile() {
    return _this.exec("getFile");
}

Variant BadFunctionCallException::getLine() {
    return _this.exec("getLine");
}

Variant BadFunctionCallException::getTrace() {
    return _this.exec("getTrace");
}

Variant BadFunctionCallException::getPrevious() {
    return _this.exec("getPrevious");
}

Variant BadFunctionCallException::getTraceAsString() {
    return _this.exec("getTraceAsString");
}

Variant BadFunctionCallException::__toString() {
    return _this.exec("__toString");
}


BadMethodCallException::BadMethodCallException(const Variant &message, const Variant &code, const Variant &previous) {
    _this = newObject("BadMethodCallException", message, code, previous);
}

Variant BadMethodCallException::__wakeup() {
    return _this.exec("__wakeup");
}

Variant BadMethodCallException::getMessage() {
    return _this.exec("getMessage");
}

Variant BadMethodCallException::getCode() {
    return _this.exec("getCode");
}

Variant BadMethodCallException::getFile() {
    return _this.exec("getFile");
}

Variant BadMethodCallException::getLine() {
    return _this.exec("getLine");
}

Variant BadMethodCallException::getTrace() {
    return _this.exec("getTrace");
}

Variant BadMethodCallException::getPrevious() {
    return _this.exec("getPrevious");
}

Variant BadMethodCallException::getTraceAsString() {
    return _this.exec("getTraceAsString");
}

Variant BadMethodCallException::__toString() {
    return _this.exec("__toString");
}


DomainException::DomainException(const Variant &message, const Variant &code, const Variant &previous) {
    _this = newObject("DomainException", message, code, previous);
}

Variant DomainException::__wakeup() {
    return _this.exec("__wakeup");
}

Variant DomainException::getMessage() {
    return _this.exec("getMessage");
}

Variant DomainException::getCode() {
    return _this.exec("getCode");
}

Variant DomainException::getFile() {
    return _this.exec("getFile");
}

Variant DomainException::getLine() {
    return _this.exec("getLine");
}

Variant DomainException::getTrace() {
    return _this.exec("getTrace");
}

Variant DomainException::getPrevious() {
    return _this.exec("getPrevious");
}

Variant DomainException::getTraceAsString() {
    return _this.exec("getTraceAsString");
}

Variant DomainException::__toString() {
    return _this.exec("__toString");
}


InvalidArgumentException::InvalidArgumentException(const Variant &message, const Variant &code, const Variant &previous) {
    _this = newObject("InvalidArgumentException", message, code, previous);
}

Variant InvalidArgumentException::__wakeup() {
    return _this.exec("__wakeup");
}

Variant InvalidArgumentException::getMessage() {
    return _this.exec("getMessage");
}

Variant InvalidArgumentException::getCode() {
    return _this.exec("getCode");
}

Variant InvalidArgumentException::getFile() {
    return _this.exec("getFile");
}

Variant InvalidArgumentException::getLine() {
    return _this.exec("getLine");
}

Variant InvalidArgumentException::getTrace() {
    return _this.exec("getTrace");
}

Variant InvalidArgumentException::getPrevious() {
    return _this.exec("getPrevious");
}

Variant InvalidArgumentException::getTraceAsString() {
    return _this.exec("getTraceAsString");
}

Variant InvalidArgumentException::__toString() {
    return _this.exec("__toString");
}


LengthException::LengthException(const Variant &message, const Variant &code, const Variant &previous) {
    _this = newObject("LengthException", message, code, previous);
}

Variant LengthException::__wakeup() {
    return _this.exec("__wakeup");
}

Variant LengthException::getMessage() {
    return _this.exec("getMessage");
}

Variant LengthException::getCode() {
    return _this.exec("getCode");
}

Variant LengthException::getFile() {
    return _this.exec("getFile");
}

Variant LengthException::getLine() {
    return _this.exec("getLine");
}

Variant LengthException::getTrace() {
    return _this.exec("getTrace");
}

Variant LengthException::getPrevious() {
    return _this.exec("getPrevious");
}

Variant LengthException::getTraceAsString() {
    return _this.exec("getTraceAsString");
}

Variant LengthException::__toString() {
    return _this.exec("__toString");
}


OutOfRangeException::OutOfRangeException(const Variant &message, const Variant &code, const Variant &previous) {
    _this = newObject("OutOfRangeException", message, code, previous);
}

Variant OutOfRangeException::__wakeup() {
    return _this.exec("__wakeup");
}

Variant OutOfRangeException::getMessage() {
    return _this.exec("getMessage");
}

Variant OutOfRangeException::getCode() {
    return _this.exec("getCode");
}

Variant OutOfRangeException::getFile() {
    return _this.exec("getFile");
}

Variant OutOfRangeException::getLine() {
    return _this.exec("getLine");
}

Variant OutOfRangeException::getTrace() {
    return _this.exec("getTrace");
}

Variant OutOfRangeException::getPrevious() {
    return _this.exec("getPrevious");
}

Variant OutOfRangeException::getTraceAsString() {
    return _this.exec("getTraceAsString");
}

Variant OutOfRangeException::__toString() {
    return _this.exec("__toString");
}


RuntimeException::RuntimeException(const Variant &message, const Variant &code, const Variant &previous) {
    _this = newObject("RuntimeException", message, code, previous);
}

Variant RuntimeException::__wakeup() {
    return _this.exec("__wakeup");
}

Variant RuntimeException::getMessage() {
    return _this.exec("getMessage");
}

Variant RuntimeException::getCode() {
    return _this.exec("getCode");
}

Variant RuntimeException::getFile() {
    return _this.exec("getFile");
}

Variant RuntimeException::getLine() {
    return _this.exec("getLine");
}

Variant RuntimeException::getTrace() {
    return _this.exec("getTrace");
}

Variant RuntimeException::getPrevious() {
    return _this.exec("getPrevious");
}

Variant RuntimeException::getTraceAsString() {
    return _this.exec("getTraceAsString");
}

Variant RuntimeException::__toString() {
    return _this.exec("__toString");
}


OutOfBoundsException::OutOfBoundsException(const Variant &message, const Variant &code, const Variant &previous) {
    _this = newObject("OutOfBoundsException", message, code, previous);
}

Variant OutOfBoundsException::__wakeup() {
    return _this.exec("__wakeup");
}

Variant OutOfBoundsException::getMessage() {
    return _this.exec("getMessage");
}

Variant OutOfBoundsException::getCode() {
    return _this.exec("getCode");
}

Variant OutOfBoundsException::getFile() {
    return _this.exec("getFile");
}

Variant OutOfBoundsException::getLine() {
    return _this.exec("getLine");
}

Variant OutOfBoundsException::getTrace() {
    return _this.exec("getTrace");
}

Variant OutOfBoundsException::getPrevious() {
    return _this.exec("getPrevious");
}

Variant OutOfBoundsException::getTraceAsString() {
    return _this.exec("getTraceAsString");
}

Variant OutOfBoundsException::__toString() {
    return _this.exec("__toString");
}


OverflowException::OverflowException(const Variant &message, const Variant &code, const Variant &previous) {
    _this = newObject("OverflowException", message, code, previous);
}

Variant OverflowException::__wakeup() {
    return _this.exec("__wakeup");
}

Variant OverflowException::getMessage() {
    return _this.exec("getMessage");
}

Variant OverflowException::getCode() {
    return _this.exec("getCode");
}

Variant OverflowException::getFile() {
    return _this.exec("getFile");
}

Variant OverflowException::getLine() {
    return _this.exec("getLine");
}

Variant OverflowException::getTrace() {
    return _this.exec("getTrace");
}

Variant OverflowException::getPrevious() {
    return _this.exec("getPrevious");
}

Variant OverflowException::getTraceAsString() {
    return _this.exec("getTraceAsString");
}

Variant OverflowException::__toString() {
    return _this.exec("__toString");
}


RangeException::RangeException(const Variant &message, const Variant &code, const Variant &previous) {
    _this = newObject("RangeException", message, code, previous);
}

Variant RangeException::__wakeup() {
    return _this.exec("__wakeup");
}

Variant RangeException::getMessage() {
    return _this.exec("getMessage");
}

Variant RangeException::getCode() {
    return _this.exec("getCode");
}

Variant RangeException::getFile() {
    return _this.exec("getFile");
}

Variant RangeException::getLine() {
    return _this.exec("getLine");
}

Variant RangeException::getTrace() {
    return _this.exec("getTrace");
}

Variant RangeException::getPrevious() {
    return _this.exec("getPrevious");
}

Variant RangeException::getTraceAsString() {
    return _this.exec("getTraceAsString");
}

Variant RangeException::__toString() {
    return _this.exec("__toString");
}


UnderflowException::UnderflowException(const Variant &message, const Variant &code, const Variant &previous) {
    _this = newObject("UnderflowException", message, code, previous);
}

Variant UnderflowException::__wakeup() {
    return _this.exec("__wakeup");
}

Variant UnderflowException::getMessage() {
    return _this.exec("getMessage");
}

Variant UnderflowException::getCode() {
    return _this.exec("getCode");
}

Variant UnderflowException::getFile() {
    return _this.exec("getFile");
}

Variant UnderflowException::getLine() {
    return _this.exec("getLine");
}

Variant UnderflowException::getTrace() {
    return _this.exec("getTrace");
}

Variant UnderflowException::getPrevious() {
    return _this.exec("getPrevious");
}

Variant UnderflowException::getTraceAsString() {
    return _this.exec("getTraceAsString");
}

Variant UnderflowException::__toString() {
    return _this.exec("__toString");
}


UnexpectedValueException::UnexpectedValueException(const Variant &message, const Variant &code, const Variant &previous) {
    _this = newObject("UnexpectedValueException", message, code, previous);
}

Variant UnexpectedValueException::__wakeup() {
    return _this.exec("__wakeup");
}

Variant UnexpectedValueException::getMessage() {
    return _this.exec("getMessage");
}

Variant UnexpectedValueException::getCode() {
    return _this.exec("getCode");
}

Variant UnexpectedValueException::getFile() {
    return _this.exec("getFile");
}

Variant UnexpectedValueException::getLine() {
    return _this.exec("getLine");
}

Variant UnexpectedValueException::getTrace() {
    return _this.exec("getTrace");
}

Variant UnexpectedValueException::getPrevious() {
    return _this.exec("getPrevious");
}

Variant UnexpectedValueException::getTraceAsString() {
    return _this.exec("getTraceAsString");
}

Variant UnexpectedValueException::__toString() {
    return _this.exec("__toString");
}


RecursiveIteratorIterator::RecursiveIteratorIterator(const Variant &iterator, const Variant &mode, const Variant &flags) {
    _this = newObject("RecursiveIteratorIterator", iterator, mode, flags);
}

Variant RecursiveIteratorIterator::rewind() {
    return _this.exec("rewind");
}

Variant RecursiveIteratorIterator::valid() {
    return _this.exec("valid");
}

Variant RecursiveIteratorIterator::key() {
    return _this.exec("key");
}

Variant RecursiveIteratorIterator::current() {
    return _this.exec("current");
}

Variant RecursiveIteratorIterator::next() {
    return _this.exec("next");
}

Variant RecursiveIteratorIterator::getDepth() {
    return _this.exec("getDepth");
}

Variant RecursiveIteratorIterator::getSubIterator(const Variant &level) {
    return _this.exec("getSubIterator", level);
}

Variant RecursiveIteratorIterator::getInnerIterator() {
    return _this.exec("getInnerIterator");
}

Variant RecursiveIteratorIterator::beginIteration() {
    return _this.exec("beginIteration");
}

Variant RecursiveIteratorIterator::endIteration() {
    return _this.exec("endIteration");
}

Variant RecursiveIteratorIterator::callHasChildren() {
    return _this.exec("callHasChildren");
}

Variant RecursiveIteratorIterator::callGetChildren() {
    return _this.exec("callGetChildren");
}

Variant RecursiveIteratorIterator::beginChildren() {
    return _this.exec("beginChildren");
}

Variant RecursiveIteratorIterator::endChildren() {
    return _this.exec("endChildren");
}

Variant RecursiveIteratorIterator::nextElement() {
    return _this.exec("nextElement");
}

Variant RecursiveIteratorIterator::setMaxDepth(const Variant &max_depth) {
    return _this.exec("setMaxDepth", max_depth);
}

Variant RecursiveIteratorIterator::getMaxDepth() {
    return _this.exec("getMaxDepth");
}


IteratorIterator::IteratorIterator(const Variant &iterator, const Variant &_class) {
    _this = newObject("IteratorIterator", iterator, _class);
}

Variant IteratorIterator::getInnerIterator() {
    return _this.exec("getInnerIterator");
}

Variant IteratorIterator::rewind() {
    return _this.exec("rewind");
}

Variant IteratorIterator::valid() {
    return _this.exec("valid");
}

Variant IteratorIterator::key() {
    return _this.exec("key");
}

Variant IteratorIterator::current() {
    return _this.exec("current");
}

Variant IteratorIterator::next() {
    return _this.exec("next");
}


CallbackFilterIterator::CallbackFilterIterator(const Variant &iterator, const Variant &callback) {
    _this = newObject("CallbackFilterIterator", iterator, callback);
}

Variant CallbackFilterIterator::accept() {
    return _this.exec("accept");
}

Variant CallbackFilterIterator::rewind() {
    return _this.exec("rewind");
}

Variant CallbackFilterIterator::next() {
    return _this.exec("next");
}

Variant CallbackFilterIterator::getInnerIterator() {
    return _this.exec("getInnerIterator");
}

Variant CallbackFilterIterator::valid() {
    return _this.exec("valid");
}

Variant CallbackFilterIterator::key() {
    return _this.exec("key");
}

Variant CallbackFilterIterator::current() {
    return _this.exec("current");
}


RecursiveCallbackFilterIterator::RecursiveCallbackFilterIterator(const Variant &iterator, const Variant &callback) {
    _this = newObject("RecursiveCallbackFilterIterator", iterator, callback);
}

Variant RecursiveCallbackFilterIterator::hasChildren() {
    return _this.exec("hasChildren");
}

Variant RecursiveCallbackFilterIterator::getChildren() {
    return _this.exec("getChildren");
}

Variant RecursiveCallbackFilterIterator::accept() {
    return _this.exec("accept");
}

Variant RecursiveCallbackFilterIterator::rewind() {
    return _this.exec("rewind");
}

Variant RecursiveCallbackFilterIterator::next() {
    return _this.exec("next");
}

Variant RecursiveCallbackFilterIterator::getInnerIterator() {
    return _this.exec("getInnerIterator");
}

Variant RecursiveCallbackFilterIterator::valid() {
    return _this.exec("valid");
}

Variant RecursiveCallbackFilterIterator::key() {
    return _this.exec("key");
}

Variant RecursiveCallbackFilterIterator::current() {
    return _this.exec("current");
}


ParentIterator::ParentIterator(const Variant &iterator) {
    _this = newObject("ParentIterator", iterator);
}

Variant ParentIterator::accept() {
    return _this.exec("accept");
}

Variant ParentIterator::hasChildren() {
    return _this.exec("hasChildren");
}

Variant ParentIterator::getChildren() {
    return _this.exec("getChildren");
}

Variant ParentIterator::rewind() {
    return _this.exec("rewind");
}

Variant ParentIterator::next() {
    return _this.exec("next");
}

Variant ParentIterator::getInnerIterator() {
    return _this.exec("getInnerIterator");
}

Variant ParentIterator::valid() {
    return _this.exec("valid");
}

Variant ParentIterator::key() {
    return _this.exec("key");
}

Variant ParentIterator::current() {
    return _this.exec("current");
}


LimitIterator::LimitIterator(const Variant &iterator, const Variant &offset, const Variant &limit) {
    _this = newObject("LimitIterator", iterator, offset, limit);
}

Variant LimitIterator::rewind() {
    return _this.exec("rewind");
}

Variant LimitIterator::valid() {
    return _this.exec("valid");
}

Variant LimitIterator::next() {
    return _this.exec("next");
}

Variant LimitIterator::seek(const Variant &offset) {
    return _this.exec("seek", offset);
}

Variant LimitIterator::getPosition() {
    return _this.exec("getPosition");
}

Variant LimitIterator::getInnerIterator() {
    return _this.exec("getInnerIterator");
}

Variant LimitIterator::key() {
    return _this.exec("key");
}

Variant LimitIterator::current() {
    return _this.exec("current");
}


CachingIterator::CachingIterator(const Variant &iterator, const Variant &flags) {
    _this = newObject("CachingIterator", iterator, flags);
}

Variant CachingIterator::rewind() {
    return _this.exec("rewind");
}

Variant CachingIterator::valid() {
    return _this.exec("valid");
}

Variant CachingIterator::next() {
    return _this.exec("next");
}

Variant CachingIterator::hasNext() {
    return _this.exec("hasNext");
}

Variant CachingIterator::__toString() {
    return _this.exec("__toString");
}

Variant CachingIterator::getFlags() {
    return _this.exec("getFlags");
}

Variant CachingIterator::setFlags(const Variant &flags) {
    return _this.exec("setFlags", flags);
}

Variant CachingIterator::offsetGet(const Variant &key) {
    return _this.exec("offsetGet", key);
}

Variant CachingIterator::offsetSet(const Variant &key, const Variant &value) {
    return _this.exec("offsetSet", key, value);
}

Variant CachingIterator::offsetUnset(const Variant &key) {
    return _this.exec("offsetUnset", key);
}

Variant CachingIterator::offsetExists(const Variant &key) {
    return _this.exec("offsetExists", key);
}

Variant CachingIterator::getCache() {
    return _this.exec("getCache");
}

Variant CachingIterator::count() {
    return _this.exec("count");
}

Variant CachingIterator::getInnerIterator() {
    return _this.exec("getInnerIterator");
}

Variant CachingIterator::key() {
    return _this.exec("key");
}

Variant CachingIterator::current() {
    return _this.exec("current");
}


RecursiveCachingIterator::RecursiveCachingIterator(const Variant &iterator, const Variant &flags) {
    _this = newObject("RecursiveCachingIterator", iterator, flags);
}

Variant RecursiveCachingIterator::hasChildren() {
    return _this.exec("hasChildren");
}

Variant RecursiveCachingIterator::getChildren() {
    return _this.exec("getChildren");
}

Variant RecursiveCachingIterator::rewind() {
    return _this.exec("rewind");
}

Variant RecursiveCachingIterator::valid() {
    return _this.exec("valid");
}

Variant RecursiveCachingIterator::next() {
    return _this.exec("next");
}

Variant RecursiveCachingIterator::hasNext() {
    return _this.exec("hasNext");
}

Variant RecursiveCachingIterator::__toString() {
    return _this.exec("__toString");
}

Variant RecursiveCachingIterator::getFlags() {
    return _this.exec("getFlags");
}

Variant RecursiveCachingIterator::setFlags(const Variant &flags) {
    return _this.exec("setFlags", flags);
}

Variant RecursiveCachingIterator::offsetGet(const Variant &key) {
    return _this.exec("offsetGet", key);
}

Variant RecursiveCachingIterator::offsetSet(const Variant &key, const Variant &value) {
    return _this.exec("offsetSet", key, value);
}

Variant RecursiveCachingIterator::offsetUnset(const Variant &key) {
    return _this.exec("offsetUnset", key);
}

Variant RecursiveCachingIterator::offsetExists(const Variant &key) {
    return _this.exec("offsetExists", key);
}

Variant RecursiveCachingIterator::getCache() {
    return _this.exec("getCache");
}

Variant RecursiveCachingIterator::count() {
    return _this.exec("count");
}

Variant RecursiveCachingIterator::getInnerIterator() {
    return _this.exec("getInnerIterator");
}

Variant RecursiveCachingIterator::key() {
    return _this.exec("key");
}

Variant RecursiveCachingIterator::current() {
    return _this.exec("current");
}


NoRewindIterator::NoRewindIterator(const Variant &iterator) {
    _this = newObject("NoRewindIterator", iterator);
}

Variant NoRewindIterator::rewind() {
    return _this.exec("rewind");
}

Variant NoRewindIterator::valid() {
    return _this.exec("valid");
}

Variant NoRewindIterator::key() {
    return _this.exec("key");
}

Variant NoRewindIterator::current() {
    return _this.exec("current");
}

Variant NoRewindIterator::next() {
    return _this.exec("next");
}

Variant NoRewindIterator::getInnerIterator() {
    return _this.exec("getInnerIterator");
}


AppendIterator::AppendIterator() {
    _this = newObject("AppendIterator");
}

Variant AppendIterator::append(const Variant &iterator) {
    return _this.exec("append", iterator);
}

Variant AppendIterator::rewind() {
    return _this.exec("rewind");
}

Variant AppendIterator::valid() {
    return _this.exec("valid");
}

Variant AppendIterator::current() {
    return _this.exec("current");
}

Variant AppendIterator::next() {
    return _this.exec("next");
}

Variant AppendIterator::getIteratorIndex() {
    return _this.exec("getIteratorIndex");
}

Variant AppendIterator::getArrayIterator() {
    return _this.exec("getArrayIterator");
}

Variant AppendIterator::getInnerIterator() {
    return _this.exec("getInnerIterator");
}

Variant AppendIterator::key() {
    return _this.exec("key");
}


InfiniteIterator::InfiniteIterator(const Variant &iterator) {
    _this = newObject("InfiniteIterator", iterator);
}

Variant InfiniteIterator::next() {
    return _this.exec("next");
}

Variant InfiniteIterator::getInnerIterator() {
    return _this.exec("getInnerIterator");
}

Variant InfiniteIterator::rewind() {
    return _this.exec("rewind");
}

Variant InfiniteIterator::valid() {
    return _this.exec("valid");
}

Variant InfiniteIterator::key() {
    return _this.exec("key");
}

Variant InfiniteIterator::current() {
    return _this.exec("current");
}


RegexIterator::RegexIterator(const Variant &iterator, const Variant &pattern, const Variant &mode, const Variant &flags, const Variant &preg_flags) {
    _this = newObject("RegexIterator", iterator, pattern, mode, flags, preg_flags);
}

Variant RegexIterator::accept() {
    return _this.exec("accept");
}

Variant RegexIterator::getMode() {
    return _this.exec("getMode");
}

Variant RegexIterator::setMode(const Variant &mode) {
    return _this.exec("setMode", mode);
}

Variant RegexIterator::getFlags() {
    return _this.exec("getFlags");
}

Variant RegexIterator::setFlags(const Variant &flags) {
    return _this.exec("setFlags", flags);
}

Variant RegexIterator::getRegex() {
    return _this.exec("getRegex");
}

Variant RegexIterator::getPregFlags() {
    return _this.exec("getPregFlags");
}

Variant RegexIterator::setPregFlags(const Variant &preg_flags) {
    return _this.exec("setPregFlags", preg_flags);
}

Variant RegexIterator::rewind() {
    return _this.exec("rewind");
}

Variant RegexIterator::next() {
    return _this.exec("next");
}

Variant RegexIterator::getInnerIterator() {
    return _this.exec("getInnerIterator");
}

Variant RegexIterator::valid() {
    return _this.exec("valid");
}

Variant RegexIterator::key() {
    return _this.exec("key");
}

Variant RegexIterator::current() {
    return _this.exec("current");
}


RecursiveRegexIterator::RecursiveRegexIterator(const Variant &iterator, const Variant &pattern, const Variant &mode, const Variant &flags, const Variant &preg_flags) {
    _this = newObject("RecursiveRegexIterator", iterator, pattern, mode, flags, preg_flags);
}

Variant RecursiveRegexIterator::accept() {
    return _this.exec("accept");
}

Variant RecursiveRegexIterator::hasChildren() {
    return _this.exec("hasChildren");
}

Variant RecursiveRegexIterator::getChildren() {
    return _this.exec("getChildren");
}

Variant RecursiveRegexIterator::getMode() {
    return _this.exec("getMode");
}

Variant RecursiveRegexIterator::setMode(const Variant &mode) {
    return _this.exec("setMode", mode);
}

Variant RecursiveRegexIterator::getFlags() {
    return _this.exec("getFlags");
}

Variant RecursiveRegexIterator::setFlags(const Variant &flags) {
    return _this.exec("setFlags", flags);
}

Variant RecursiveRegexIterator::getRegex() {
    return _this.exec("getRegex");
}

Variant RecursiveRegexIterator::getPregFlags() {
    return _this.exec("getPregFlags");
}

Variant RecursiveRegexIterator::setPregFlags(const Variant &preg_flags) {
    return _this.exec("setPregFlags", preg_flags);
}

Variant RecursiveRegexIterator::rewind() {
    return _this.exec("rewind");
}

Variant RecursiveRegexIterator::next() {
    return _this.exec("next");
}

Variant RecursiveRegexIterator::getInnerIterator() {
    return _this.exec("getInnerIterator");
}

Variant RecursiveRegexIterator::valid() {
    return _this.exec("valid");
}

Variant RecursiveRegexIterator::key() {
    return _this.exec("key");
}

Variant RecursiveRegexIterator::current() {
    return _this.exec("current");
}


Variant EmptyIterator::current() {
    return _this.exec("current");
}

Variant EmptyIterator::next() {
    return _this.exec("next");
}

Variant EmptyIterator::key() {
    return _this.exec("key");
}

Variant EmptyIterator::valid() {
    return _this.exec("valid");
}

Variant EmptyIterator::rewind() {
    return _this.exec("rewind");
}


RecursiveTreeIterator::RecursiveTreeIterator(const Variant &iterator, const Variant &flags, const Variant &caching_iterator_flags, const Variant &mode) {
    _this = newObject("RecursiveTreeIterator", iterator, flags, caching_iterator_flags, mode);
}

Variant RecursiveTreeIterator::key() {
    return _this.exec("key");
}

Variant RecursiveTreeIterator::current() {
    return _this.exec("current");
}

Variant RecursiveTreeIterator::getPrefix() {
    return _this.exec("getPrefix");
}

Variant RecursiveTreeIterator::setPostfix(const Variant &postfix) {
    return _this.exec("setPostfix", postfix);
}

Variant RecursiveTreeIterator::setPrefixPart(const Variant &part, const Variant &value) {
    return _this.exec("setPrefixPart", part, value);
}

Variant RecursiveTreeIterator::getEntry() {
    return _this.exec("getEntry");
}

Variant RecursiveTreeIterator::getPostfix() {
    return _this.exec("getPostfix");
}

Variant RecursiveTreeIterator::rewind() {
    return _this.exec("rewind");
}

Variant RecursiveTreeIterator::valid() {
    return _this.exec("valid");
}

Variant RecursiveTreeIterator::next() {
    return _this.exec("next");
}

Variant RecursiveTreeIterator::getDepth() {
    return _this.exec("getDepth");
}

Variant RecursiveTreeIterator::getSubIterator(const Variant &level) {
    return _this.exec("getSubIterator", level);
}

Variant RecursiveTreeIterator::getInnerIterator() {
    return _this.exec("getInnerIterator");
}

Variant RecursiveTreeIterator::beginIteration() {
    return _this.exec("beginIteration");
}

Variant RecursiveTreeIterator::endIteration() {
    return _this.exec("endIteration");
}

Variant RecursiveTreeIterator::callHasChildren() {
    return _this.exec("callHasChildren");
}

Variant RecursiveTreeIterator::callGetChildren() {
    return _this.exec("callGetChildren");
}

Variant RecursiveTreeIterator::beginChildren() {
    return _this.exec("beginChildren");
}

Variant RecursiveTreeIterator::endChildren() {
    return _this.exec("endChildren");
}

Variant RecursiveTreeIterator::nextElement() {
    return _this.exec("nextElement");
}

Variant RecursiveTreeIterator::setMaxDepth(const Variant &max_depth) {
    return _this.exec("setMaxDepth", max_depth);
}

Variant RecursiveTreeIterator::getMaxDepth() {
    return _this.exec("getMaxDepth");
}


ArrayObject::ArrayObject(const Array &array, const Variant &flags, const Variant &iterator_class) {
    _this = newObject("ArrayObject", array, flags, iterator_class);
}

Variant ArrayObject::offsetExists(const Variant &key) {
    return _this.exec("offsetExists", key);
}

Variant ArrayObject::offsetGet(const Variant &key) {
    return _this.exec("offsetGet", key);
}

Variant ArrayObject::offsetSet(const Variant &key, const Variant &value) {
    return _this.exec("offsetSet", key, value);
}

Variant ArrayObject::offsetUnset(const Variant &key) {
    return _this.exec("offsetUnset", key);
}

Variant ArrayObject::append(const Variant &value) {
    return _this.exec("append", value);
}

Variant ArrayObject::getArrayCopy() {
    return _this.exec("getArrayCopy");
}

Variant ArrayObject::count() {
    return _this.exec("count");
}

Variant ArrayObject::getFlags() {
    return _this.exec("getFlags");
}

Variant ArrayObject::setFlags(const Variant &flags) {
    return _this.exec("setFlags", flags);
}

Variant ArrayObject::asort(const Variant &flags) {
    return _this.exec("asort", flags);
}

Variant ArrayObject::ksort(const Variant &flags) {
    return _this.exec("ksort", flags);
}

Variant ArrayObject::uasort(const Variant &callback) {
    return _this.exec("uasort", callback);
}

Variant ArrayObject::uksort(const Variant &callback) {
    return _this.exec("uksort", callback);
}

Variant ArrayObject::natsort() {
    return _this.exec("natsort");
}

Variant ArrayObject::natcasesort() {
    return _this.exec("natcasesort");
}

Variant ArrayObject::unserialize(const Variant &data) {
    return _this.exec("unserialize", data);
}

Variant ArrayObject::serialize() {
    return _this.exec("serialize");
}

Variant ArrayObject::__serialize() {
    return _this.exec("__serialize");
}

Variant ArrayObject::__unserialize(const Variant &data) {
    return _this.exec("__unserialize", data);
}

Variant ArrayObject::getIterator() {
    return _this.exec("getIterator");
}

Variant ArrayObject::exchangeArray(const Variant &array) {
    return _this.exec("exchangeArray", array);
}

Variant ArrayObject::setIteratorClass(const Variant &iterator_class) {
    return _this.exec("setIteratorClass", iterator_class);
}

Variant ArrayObject::getIteratorClass() {
    return _this.exec("getIteratorClass");
}

Variant ArrayObject::__debugInfo() {
    return _this.exec("__debugInfo");
}


_ArrayIterator::_ArrayIterator(const Array &array, const Variant &flags) {
    _this = newObject("ArrayIterator", array, flags);
}

Variant _ArrayIterator::offsetExists(const Variant &key) {
    return _this.exec("offsetExists", key);
}

Variant _ArrayIterator::offsetGet(const Variant &key) {
    return _this.exec("offsetGet", key);
}

Variant _ArrayIterator::offsetSet(const Variant &key, const Variant &value) {
    return _this.exec("offsetSet", key, value);
}

Variant _ArrayIterator::offsetUnset(const Variant &key) {
    return _this.exec("offsetUnset", key);
}

Variant _ArrayIterator::append(const Variant &value) {
    return _this.exec("append", value);
}

Variant _ArrayIterator::getArrayCopy() {
    return _this.exec("getArrayCopy");
}

Variant _ArrayIterator::count() {
    return _this.exec("count");
}

Variant _ArrayIterator::getFlags() {
    return _this.exec("getFlags");
}

Variant _ArrayIterator::setFlags(const Variant &flags) {
    return _this.exec("setFlags", flags);
}

Variant _ArrayIterator::asort(const Variant &flags) {
    return _this.exec("asort", flags);
}

Variant _ArrayIterator::ksort(const Variant &flags) {
    return _this.exec("ksort", flags);
}

Variant _ArrayIterator::uasort(const Variant &callback) {
    return _this.exec("uasort", callback);
}

Variant _ArrayIterator::uksort(const Variant &callback) {
    return _this.exec("uksort", callback);
}

Variant _ArrayIterator::natsort() {
    return _this.exec("natsort");
}

Variant _ArrayIterator::natcasesort() {
    return _this.exec("natcasesort");
}

Variant _ArrayIterator::unserialize(const Variant &data) {
    return _this.exec("unserialize", data);
}

Variant _ArrayIterator::serialize() {
    return _this.exec("serialize");
}

Variant _ArrayIterator::__serialize() {
    return _this.exec("__serialize");
}

Variant _ArrayIterator::__unserialize(const Variant &data) {
    return _this.exec("__unserialize", data);
}

Variant _ArrayIterator::rewind() {
    return _this.exec("rewind");
}

Variant _ArrayIterator::current() {
    return _this.exec("current");
}

Variant _ArrayIterator::key() {
    return _this.exec("key");
}

Variant _ArrayIterator::next() {
    return _this.exec("next");
}

Variant _ArrayIterator::valid() {
    return _this.exec("valid");
}

Variant _ArrayIterator::seek(const Variant &offset) {
    return _this.exec("seek", offset);
}

Variant _ArrayIterator::__debugInfo() {
    return _this.exec("__debugInfo");
}


Variant RecursiveArrayIterator::hasChildren() {
    return _this.exec("hasChildren");
}

Variant RecursiveArrayIterator::getChildren() {
    return _this.exec("getChildren");
}

RecursiveArrayIterator::RecursiveArrayIterator(const Array &array, const Variant &flags) {
    _this = newObject("RecursiveArrayIterator", array, flags);
}

Variant RecursiveArrayIterator::offsetExists(const Variant &key) {
    return _this.exec("offsetExists", key);
}

Variant RecursiveArrayIterator::offsetGet(const Variant &key) {
    return _this.exec("offsetGet", key);
}

Variant RecursiveArrayIterator::offsetSet(const Variant &key, const Variant &value) {
    return _this.exec("offsetSet", key, value);
}

Variant RecursiveArrayIterator::offsetUnset(const Variant &key) {
    return _this.exec("offsetUnset", key);
}

Variant RecursiveArrayIterator::append(const Variant &value) {
    return _this.exec("append", value);
}

Variant RecursiveArrayIterator::getArrayCopy() {
    return _this.exec("getArrayCopy");
}

Variant RecursiveArrayIterator::count() {
    return _this.exec("count");
}

Variant RecursiveArrayIterator::getFlags() {
    return _this.exec("getFlags");
}

Variant RecursiveArrayIterator::setFlags(const Variant &flags) {
    return _this.exec("setFlags", flags);
}

Variant RecursiveArrayIterator::asort(const Variant &flags) {
    return _this.exec("asort", flags);
}

Variant RecursiveArrayIterator::ksort(const Variant &flags) {
    return _this.exec("ksort", flags);
}

Variant RecursiveArrayIterator::uasort(const Variant &callback) {
    return _this.exec("uasort", callback);
}

Variant RecursiveArrayIterator::uksort(const Variant &callback) {
    return _this.exec("uksort", callback);
}

Variant RecursiveArrayIterator::natsort() {
    return _this.exec("natsort");
}

Variant RecursiveArrayIterator::natcasesort() {
    return _this.exec("natcasesort");
}

Variant RecursiveArrayIterator::unserialize(const Variant &data) {
    return _this.exec("unserialize", data);
}

Variant RecursiveArrayIterator::serialize() {
    return _this.exec("serialize");
}

Variant RecursiveArrayIterator::__serialize() {
    return _this.exec("__serialize");
}

Variant RecursiveArrayIterator::__unserialize(const Variant &data) {
    return _this.exec("__unserialize", data);
}

Variant RecursiveArrayIterator::rewind() {
    return _this.exec("rewind");
}

Variant RecursiveArrayIterator::current() {
    return _this.exec("current");
}

Variant RecursiveArrayIterator::key() {
    return _this.exec("key");
}

Variant RecursiveArrayIterator::next() {
    return _this.exec("next");
}

Variant RecursiveArrayIterator::valid() {
    return _this.exec("valid");
}

Variant RecursiveArrayIterator::seek(const Variant &offset) {
    return _this.exec("seek", offset);
}

Variant RecursiveArrayIterator::__debugInfo() {
    return _this.exec("__debugInfo");
}


SplFileInfo::SplFileInfo(const Variant &filename) {
    _this = newObject("SplFileInfo", filename);
}

Variant SplFileInfo::getPath() {
    return _this.exec("getPath");
}

Variant SplFileInfo::getFilename() {
    return _this.exec("getFilename");
}

Variant SplFileInfo::getExtension() {
    return _this.exec("getExtension");
}

Variant SplFileInfo::getBasename(const Variant &suffix) {
    return _this.exec("getBasename", suffix);
}

Variant SplFileInfo::getPathname() {
    return _this.exec("getPathname");
}

Variant SplFileInfo::getPerms() {
    return _this.exec("getPerms");
}

Variant SplFileInfo::getInode() {
    return _this.exec("getInode");
}

Variant SplFileInfo::getSize() {
    return _this.exec("getSize");
}

Variant SplFileInfo::getOwner() {
    return _this.exec("getOwner");
}

Variant SplFileInfo::getGroup() {
    return _this.exec("getGroup");
}

Variant SplFileInfo::getATime() {
    return _this.exec("getATime");
}

Variant SplFileInfo::getMTime() {
    return _this.exec("getMTime");
}

Variant SplFileInfo::getCTime() {
    return _this.exec("getCTime");
}

Variant SplFileInfo::getType() {
    return _this.exec("getType");
}

Variant SplFileInfo::isWritable() {
    return _this.exec("isWritable");
}

Variant SplFileInfo::isReadable() {
    return _this.exec("isReadable");
}

Variant SplFileInfo::isExecutable() {
    return _this.exec("isExecutable");
}

Variant SplFileInfo::isFile() {
    return _this.exec("isFile");
}

Variant SplFileInfo::isDir() {
    return _this.exec("isDir");
}

Variant SplFileInfo::isLink() {
    return _this.exec("isLink");
}

Variant SplFileInfo::getLinkTarget() {
    return _this.exec("getLinkTarget");
}

Variant SplFileInfo::getRealPath() {
    return _this.exec("getRealPath");
}

Variant SplFileInfo::getFileInfo(const Variant &_class) {
    return _this.exec("getFileInfo", _class);
}

Variant SplFileInfo::getPathInfo(const Variant &_class) {
    return _this.exec("getPathInfo", _class);
}

Variant SplFileInfo::openFile(const Variant &mode, const Variant &use_include_path, const Variant &context) {
    return _this.exec("openFile", mode, use_include_path, context);
}

Variant SplFileInfo::setFileClass(const Variant &_class) {
    return _this.exec("setFileClass", _class);
}

Variant SplFileInfo::setInfoClass(const Variant &_class) {
    return _this.exec("setInfoClass", _class);
}

Variant SplFileInfo::__toString() {
    return _this.exec("__toString");
}

Variant SplFileInfo::__debugInfo() {
    return _this.exec("__debugInfo");
}

Variant SplFileInfo::_bad_state_ex() {
    return _this.exec("_bad_state_ex");
}


DirectoryIterator::DirectoryIterator(const Variant &directory) {
    _this = newObject("DirectoryIterator", directory);
}

Variant DirectoryIterator::getFilename() {
    return _this.exec("getFilename");
}

Variant DirectoryIterator::getExtension() {
    return _this.exec("getExtension");
}

Variant DirectoryIterator::getBasename(const Variant &suffix) {
    return _this.exec("getBasename", suffix);
}

Variant DirectoryIterator::isDot() {
    return _this.exec("isDot");
}

Variant DirectoryIterator::rewind() {
    return _this.exec("rewind");
}

Variant DirectoryIterator::valid() {
    return _this.exec("valid");
}

Variant DirectoryIterator::key() {
    return _this.exec("key");
}

Variant DirectoryIterator::current() {
    return _this.exec("current");
}

Variant DirectoryIterator::next() {
    return _this.exec("next");
}

Variant DirectoryIterator::seek(const Variant &offset) {
    return _this.exec("seek", offset);
}

Variant DirectoryIterator::__toString() {
    return _this.exec("__toString");
}

Variant DirectoryIterator::getPath() {
    return _this.exec("getPath");
}

Variant DirectoryIterator::getPathname() {
    return _this.exec("getPathname");
}

Variant DirectoryIterator::getPerms() {
    return _this.exec("getPerms");
}

Variant DirectoryIterator::getInode() {
    return _this.exec("getInode");
}

Variant DirectoryIterator::getSize() {
    return _this.exec("getSize");
}

Variant DirectoryIterator::getOwner() {
    return _this.exec("getOwner");
}

Variant DirectoryIterator::getGroup() {
    return _this.exec("getGroup");
}

Variant DirectoryIterator::getATime() {
    return _this.exec("getATime");
}

Variant DirectoryIterator::getMTime() {
    return _this.exec("getMTime");
}

Variant DirectoryIterator::getCTime() {
    return _this.exec("getCTime");
}

Variant DirectoryIterator::getType() {
    return _this.exec("getType");
}

Variant DirectoryIterator::isWritable() {
    return _this.exec("isWritable");
}

Variant DirectoryIterator::isReadable() {
    return _this.exec("isReadable");
}

Variant DirectoryIterator::isExecutable() {
    return _this.exec("isExecutable");
}

Variant DirectoryIterator::isFile() {
    return _this.exec("isFile");
}

Variant DirectoryIterator::isDir() {
    return _this.exec("isDir");
}

Variant DirectoryIterator::isLink() {
    return _this.exec("isLink");
}

Variant DirectoryIterator::getLinkTarget() {
    return _this.exec("getLinkTarget");
}

Variant DirectoryIterator::getRealPath() {
    return _this.exec("getRealPath");
}

Variant DirectoryIterator::getFileInfo(const Variant &_class) {
    return _this.exec("getFileInfo", _class);
}

Variant DirectoryIterator::getPathInfo(const Variant &_class) {
    return _this.exec("getPathInfo", _class);
}

Variant DirectoryIterator::openFile(const Variant &mode, const Variant &use_include_path, const Variant &context) {
    return _this.exec("openFile", mode, use_include_path, context);
}

Variant DirectoryIterator::setFileClass(const Variant &_class) {
    return _this.exec("setFileClass", _class);
}

Variant DirectoryIterator::setInfoClass(const Variant &_class) {
    return _this.exec("setInfoClass", _class);
}

Variant DirectoryIterator::__debugInfo() {
    return _this.exec("__debugInfo");
}

Variant DirectoryIterator::_bad_state_ex() {
    return _this.exec("_bad_state_ex");
}


FilesystemIterator::FilesystemIterator(const Variant &directory, const Variant &flags) {
    _this = newObject("FilesystemIterator", directory, flags);
}

Variant FilesystemIterator::rewind() {
    return _this.exec("rewind");
}

Variant FilesystemIterator::key() {
    return _this.exec("key");
}

Variant FilesystemIterator::current() {
    return _this.exec("current");
}

Variant FilesystemIterator::getFlags() {
    return _this.exec("getFlags");
}

Variant FilesystemIterator::setFlags(const Variant &flags) {
    return _this.exec("setFlags", flags);
}

Variant FilesystemIterator::getFilename() {
    return _this.exec("getFilename");
}

Variant FilesystemIterator::getExtension() {
    return _this.exec("getExtension");
}

Variant FilesystemIterator::getBasename(const Variant &suffix) {
    return _this.exec("getBasename", suffix);
}

Variant FilesystemIterator::isDot() {
    return _this.exec("isDot");
}

Variant FilesystemIterator::valid() {
    return _this.exec("valid");
}

Variant FilesystemIterator::next() {
    return _this.exec("next");
}

Variant FilesystemIterator::seek(const Variant &offset) {
    return _this.exec("seek", offset);
}

Variant FilesystemIterator::__toString() {
    return _this.exec("__toString");
}

Variant FilesystemIterator::getPath() {
    return _this.exec("getPath");
}

Variant FilesystemIterator::getPathname() {
    return _this.exec("getPathname");
}

Variant FilesystemIterator::getPerms() {
    return _this.exec("getPerms");
}

Variant FilesystemIterator::getInode() {
    return _this.exec("getInode");
}

Variant FilesystemIterator::getSize() {
    return _this.exec("getSize");
}

Variant FilesystemIterator::getOwner() {
    return _this.exec("getOwner");
}

Variant FilesystemIterator::getGroup() {
    return _this.exec("getGroup");
}

Variant FilesystemIterator::getATime() {
    return _this.exec("getATime");
}

Variant FilesystemIterator::getMTime() {
    return _this.exec("getMTime");
}

Variant FilesystemIterator::getCTime() {
    return _this.exec("getCTime");
}

Variant FilesystemIterator::getType() {
    return _this.exec("getType");
}

Variant FilesystemIterator::isWritable() {
    return _this.exec("isWritable");
}

Variant FilesystemIterator::isReadable() {
    return _this.exec("isReadable");
}

Variant FilesystemIterator::isExecutable() {
    return _this.exec("isExecutable");
}

Variant FilesystemIterator::isFile() {
    return _this.exec("isFile");
}

Variant FilesystemIterator::isDir() {
    return _this.exec("isDir");
}

Variant FilesystemIterator::isLink() {
    return _this.exec("isLink");
}

Variant FilesystemIterator::getLinkTarget() {
    return _this.exec("getLinkTarget");
}

Variant FilesystemIterator::getRealPath() {
    return _this.exec("getRealPath");
}

Variant FilesystemIterator::getFileInfo(const Variant &_class) {
    return _this.exec("getFileInfo", _class);
}

Variant FilesystemIterator::getPathInfo(const Variant &_class) {
    return _this.exec("getPathInfo", _class);
}

Variant FilesystemIterator::openFile(const Variant &mode, const Variant &use_include_path, const Variant &context) {
    return _this.exec("openFile", mode, use_include_path, context);
}

Variant FilesystemIterator::setFileClass(const Variant &_class) {
    return _this.exec("setFileClass", _class);
}

Variant FilesystemIterator::setInfoClass(const Variant &_class) {
    return _this.exec("setInfoClass", _class);
}

Variant FilesystemIterator::__debugInfo() {
    return _this.exec("__debugInfo");
}

Variant FilesystemIterator::_bad_state_ex() {
    return _this.exec("_bad_state_ex");
}


RecursiveDirectoryIterator::RecursiveDirectoryIterator(const Variant &directory, const Variant &flags) {
    _this = newObject("RecursiveDirectoryIterator", directory, flags);
}

Variant RecursiveDirectoryIterator::hasChildren(const Variant &allow_links) {
    return _this.exec("hasChildren", allow_links);
}

Variant RecursiveDirectoryIterator::getChildren() {
    return _this.exec("getChildren");
}

Variant RecursiveDirectoryIterator::getSubPath() {
    return _this.exec("getSubPath");
}

Variant RecursiveDirectoryIterator::getSubPathname() {
    return _this.exec("getSubPathname");
}

Variant RecursiveDirectoryIterator::rewind() {
    return _this.exec("rewind");
}

Variant RecursiveDirectoryIterator::key() {
    return _this.exec("key");
}

Variant RecursiveDirectoryIterator::current() {
    return _this.exec("current");
}

Variant RecursiveDirectoryIterator::getFlags() {
    return _this.exec("getFlags");
}

Variant RecursiveDirectoryIterator::setFlags(const Variant &flags) {
    return _this.exec("setFlags", flags);
}

Variant RecursiveDirectoryIterator::getFilename() {
    return _this.exec("getFilename");
}

Variant RecursiveDirectoryIterator::getExtension() {
    return _this.exec("getExtension");
}

Variant RecursiveDirectoryIterator::getBasename(const Variant &suffix) {
    return _this.exec("getBasename", suffix);
}

Variant RecursiveDirectoryIterator::isDot() {
    return _this.exec("isDot");
}

Variant RecursiveDirectoryIterator::valid() {
    return _this.exec("valid");
}

Variant RecursiveDirectoryIterator::next() {
    return _this.exec("next");
}

Variant RecursiveDirectoryIterator::seek(const Variant &offset) {
    return _this.exec("seek", offset);
}

Variant RecursiveDirectoryIterator::__toString() {
    return _this.exec("__toString");
}

Variant RecursiveDirectoryIterator::getPath() {
    return _this.exec("getPath");
}

Variant RecursiveDirectoryIterator::getPathname() {
    return _this.exec("getPathname");
}

Variant RecursiveDirectoryIterator::getPerms() {
    return _this.exec("getPerms");
}

Variant RecursiveDirectoryIterator::getInode() {
    return _this.exec("getInode");
}

Variant RecursiveDirectoryIterator::getSize() {
    return _this.exec("getSize");
}

Variant RecursiveDirectoryIterator::getOwner() {
    return _this.exec("getOwner");
}

Variant RecursiveDirectoryIterator::getGroup() {
    return _this.exec("getGroup");
}

Variant RecursiveDirectoryIterator::getATime() {
    return _this.exec("getATime");
}

Variant RecursiveDirectoryIterator::getMTime() {
    return _this.exec("getMTime");
}

Variant RecursiveDirectoryIterator::getCTime() {
    return _this.exec("getCTime");
}

Variant RecursiveDirectoryIterator::getType() {
    return _this.exec("getType");
}

Variant RecursiveDirectoryIterator::isWritable() {
    return _this.exec("isWritable");
}

Variant RecursiveDirectoryIterator::isReadable() {
    return _this.exec("isReadable");
}

Variant RecursiveDirectoryIterator::isExecutable() {
    return _this.exec("isExecutable");
}

Variant RecursiveDirectoryIterator::isFile() {
    return _this.exec("isFile");
}

Variant RecursiveDirectoryIterator::isDir() {
    return _this.exec("isDir");
}

Variant RecursiveDirectoryIterator::isLink() {
    return _this.exec("isLink");
}

Variant RecursiveDirectoryIterator::getLinkTarget() {
    return _this.exec("getLinkTarget");
}

Variant RecursiveDirectoryIterator::getRealPath() {
    return _this.exec("getRealPath");
}

Variant RecursiveDirectoryIterator::getFileInfo(const Variant &_class) {
    return _this.exec("getFileInfo", _class);
}

Variant RecursiveDirectoryIterator::getPathInfo(const Variant &_class) {
    return _this.exec("getPathInfo", _class);
}

Variant RecursiveDirectoryIterator::openFile(const Variant &mode, const Variant &use_include_path, const Variant &context) {
    return _this.exec("openFile", mode, use_include_path, context);
}

Variant RecursiveDirectoryIterator::setFileClass(const Variant &_class) {
    return _this.exec("setFileClass", _class);
}

Variant RecursiveDirectoryIterator::setInfoClass(const Variant &_class) {
    return _this.exec("setInfoClass", _class);
}

Variant RecursiveDirectoryIterator::__debugInfo() {
    return _this.exec("__debugInfo");
}

Variant RecursiveDirectoryIterator::_bad_state_ex() {
    return _this.exec("_bad_state_ex");
}


GlobIterator::GlobIterator(const Variant &pattern, const Variant &flags) {
    _this = newObject("GlobIterator", pattern, flags);
}

Variant GlobIterator::count() {
    return _this.exec("count");
}

Variant GlobIterator::rewind() {
    return _this.exec("rewind");
}

Variant GlobIterator::key() {
    return _this.exec("key");
}

Variant GlobIterator::current() {
    return _this.exec("current");
}

Variant GlobIterator::getFlags() {
    return _this.exec("getFlags");
}

Variant GlobIterator::setFlags(const Variant &flags) {
    return _this.exec("setFlags", flags);
}

Variant GlobIterator::getFilename() {
    return _this.exec("getFilename");
}

Variant GlobIterator::getExtension() {
    return _this.exec("getExtension");
}

Variant GlobIterator::getBasename(const Variant &suffix) {
    return _this.exec("getBasename", suffix);
}

Variant GlobIterator::isDot() {
    return _this.exec("isDot");
}

Variant GlobIterator::valid() {
    return _this.exec("valid");
}

Variant GlobIterator::next() {
    return _this.exec("next");
}

Variant GlobIterator::seek(const Variant &offset) {
    return _this.exec("seek", offset);
}

Variant GlobIterator::__toString() {
    return _this.exec("__toString");
}

Variant GlobIterator::getPath() {
    return _this.exec("getPath");
}

Variant GlobIterator::getPathname() {
    return _this.exec("getPathname");
}

Variant GlobIterator::getPerms() {
    return _this.exec("getPerms");
}

Variant GlobIterator::getInode() {
    return _this.exec("getInode");
}

Variant GlobIterator::getSize() {
    return _this.exec("getSize");
}

Variant GlobIterator::getOwner() {
    return _this.exec("getOwner");
}

Variant GlobIterator::getGroup() {
    return _this.exec("getGroup");
}

Variant GlobIterator::getATime() {
    return _this.exec("getATime");
}

Variant GlobIterator::getMTime() {
    return _this.exec("getMTime");
}

Variant GlobIterator::getCTime() {
    return _this.exec("getCTime");
}

Variant GlobIterator::getType() {
    return _this.exec("getType");
}

Variant GlobIterator::isWritable() {
    return _this.exec("isWritable");
}

Variant GlobIterator::isReadable() {
    return _this.exec("isReadable");
}

Variant GlobIterator::isExecutable() {
    return _this.exec("isExecutable");
}

Variant GlobIterator::isFile() {
    return _this.exec("isFile");
}

Variant GlobIterator::isDir() {
    return _this.exec("isDir");
}

Variant GlobIterator::isLink() {
    return _this.exec("isLink");
}

Variant GlobIterator::getLinkTarget() {
    return _this.exec("getLinkTarget");
}

Variant GlobIterator::getRealPath() {
    return _this.exec("getRealPath");
}

Variant GlobIterator::getFileInfo(const Variant &_class) {
    return _this.exec("getFileInfo", _class);
}

Variant GlobIterator::getPathInfo(const Variant &_class) {
    return _this.exec("getPathInfo", _class);
}

Variant GlobIterator::openFile(const Variant &mode, const Variant &use_include_path, const Variant &context) {
    return _this.exec("openFile", mode, use_include_path, context);
}

Variant GlobIterator::setFileClass(const Variant &_class) {
    return _this.exec("setFileClass", _class);
}

Variant GlobIterator::setInfoClass(const Variant &_class) {
    return _this.exec("setInfoClass", _class);
}

Variant GlobIterator::__debugInfo() {
    return _this.exec("__debugInfo");
}

Variant GlobIterator::_bad_state_ex() {
    return _this.exec("_bad_state_ex");
}


SplFileObject::SplFileObject(const Variant &filename, const Variant &mode, const Variant &use_include_path, const Variant &context) {
    _this = newObject("SplFileObject", filename, mode, use_include_path, context);
}

Variant SplFileObject::rewind() {
    return _this.exec("rewind");
}

Variant SplFileObject::eof() {
    return _this.exec("eof");
}

Variant SplFileObject::valid() {
    return _this.exec("valid");
}

Variant SplFileObject::fgets() {
    return _this.exec("fgets");
}

Variant SplFileObject::fread(const Variant &length) {
    return _this.exec("fread", length);
}

Variant SplFileObject::fgetcsv(const Variant &separator, const Variant &enclosure, const Variant &escape) {
    return _this.exec("fgetcsv", separator, enclosure, escape);
}

Variant SplFileObject::fputcsv(const Variant &fields, const Variant &separator, const Variant &enclosure, const Variant &escape, const Variant &eol) {
    return _this.exec("fputcsv", fields, separator, enclosure, escape, eol);
}

Variant SplFileObject::setCsvControl(const Variant &separator, const Variant &enclosure, const Variant &escape) {
    return _this.exec("setCsvControl", separator, enclosure, escape);
}

Variant SplFileObject::getCsvControl() {
    return _this.exec("getCsvControl");
}

Variant SplFileObject::flock(const Variant &operation, const Variant &would_block) {
    return _this.exec("flock", operation, would_block);
}

Variant SplFileObject::fflush() {
    return _this.exec("fflush");
}

Variant SplFileObject::ftell() {
    return _this.exec("ftell");
}

Variant SplFileObject::fseek(const Variant &offset, const Variant &whence) {
    return _this.exec("fseek", offset, whence);
}

Variant SplFileObject::fgetc() {
    return _this.exec("fgetc");
}

Variant SplFileObject::fpassthru() {
    return _this.exec("fpassthru");
}

Variant SplFileObject::fscanf(const Variant &format, const Variant &vars) {
    return _this.exec("fscanf", format, vars);
}

Variant SplFileObject::fwrite(const Variant &data, const Variant &length) {
    return _this.exec("fwrite", data, length);
}

Variant SplFileObject::fstat() {
    return _this.exec("fstat");
}

Variant SplFileObject::ftruncate(const Variant &size) {
    return _this.exec("ftruncate", size);
}

Variant SplFileObject::current() {
    return _this.exec("current");
}

Variant SplFileObject::key() {
    return _this.exec("key");
}

Variant SplFileObject::next() {
    return _this.exec("next");
}

Variant SplFileObject::setFlags(const Variant &flags) {
    return _this.exec("setFlags", flags);
}

Variant SplFileObject::getFlags() {
    return _this.exec("getFlags");
}

Variant SplFileObject::setMaxLineLen(const Variant &max_length) {
    return _this.exec("setMaxLineLen", max_length);
}

Variant SplFileObject::getMaxLineLen() {
    return _this.exec("getMaxLineLen");
}

Variant SplFileObject::hasChildren() {
    return _this.exec("hasChildren");
}

Variant SplFileObject::getChildren() {
    return _this.exec("getChildren");
}

Variant SplFileObject::seek(const Variant &line) {
    return _this.exec("seek", line);
}

Variant SplFileObject::getCurrentLine() {
    return _this.exec("getCurrentLine");
}

Variant SplFileObject::__toString() {
    return _this.exec("__toString");
}

Variant SplFileObject::getPath() {
    return _this.exec("getPath");
}

Variant SplFileObject::getFilename() {
    return _this.exec("getFilename");
}

Variant SplFileObject::getExtension() {
    return _this.exec("getExtension");
}

Variant SplFileObject::getBasename(const Variant &suffix) {
    return _this.exec("getBasename", suffix);
}

Variant SplFileObject::getPathname() {
    return _this.exec("getPathname");
}

Variant SplFileObject::getPerms() {
    return _this.exec("getPerms");
}

Variant SplFileObject::getInode() {
    return _this.exec("getInode");
}

Variant SplFileObject::getSize() {
    return _this.exec("getSize");
}

Variant SplFileObject::getOwner() {
    return _this.exec("getOwner");
}

Variant SplFileObject::getGroup() {
    return _this.exec("getGroup");
}

Variant SplFileObject::getATime() {
    return _this.exec("getATime");
}

Variant SplFileObject::getMTime() {
    return _this.exec("getMTime");
}

Variant SplFileObject::getCTime() {
    return _this.exec("getCTime");
}

Variant SplFileObject::getType() {
    return _this.exec("getType");
}

Variant SplFileObject::isWritable() {
    return _this.exec("isWritable");
}

Variant SplFileObject::isReadable() {
    return _this.exec("isReadable");
}

Variant SplFileObject::isExecutable() {
    return _this.exec("isExecutable");
}

Variant SplFileObject::isFile() {
    return _this.exec("isFile");
}

Variant SplFileObject::isDir() {
    return _this.exec("isDir");
}

Variant SplFileObject::isLink() {
    return _this.exec("isLink");
}

Variant SplFileObject::getLinkTarget() {
    return _this.exec("getLinkTarget");
}

Variant SplFileObject::getRealPath() {
    return _this.exec("getRealPath");
}

Variant SplFileObject::getFileInfo(const Variant &_class) {
    return _this.exec("getFileInfo", _class);
}

Variant SplFileObject::getPathInfo(const Variant &_class) {
    return _this.exec("getPathInfo", _class);
}

Variant SplFileObject::openFile(const Variant &mode, const Variant &use_include_path, const Variant &context) {
    return _this.exec("openFile", mode, use_include_path, context);
}

Variant SplFileObject::setFileClass(const Variant &_class) {
    return _this.exec("setFileClass", _class);
}

Variant SplFileObject::setInfoClass(const Variant &_class) {
    return _this.exec("setInfoClass", _class);
}

Variant SplFileObject::__debugInfo() {
    return _this.exec("__debugInfo");
}

Variant SplFileObject::_bad_state_ex() {
    return _this.exec("_bad_state_ex");
}


SplTempFileObject::SplTempFileObject(const Variant &max_memory) {
    _this = newObject("SplTempFileObject", max_memory);
}

Variant SplTempFileObject::rewind() {
    return _this.exec("rewind");
}

Variant SplTempFileObject::eof() {
    return _this.exec("eof");
}

Variant SplTempFileObject::valid() {
    return _this.exec("valid");
}

Variant SplTempFileObject::fgets() {
    return _this.exec("fgets");
}

Variant SplTempFileObject::fread(const Variant &length) {
    return _this.exec("fread", length);
}

Variant SplTempFileObject::fgetcsv(const Variant &separator, const Variant &enclosure, const Variant &escape) {
    return _this.exec("fgetcsv", separator, enclosure, escape);
}

Variant SplTempFileObject::fputcsv(const Variant &fields, const Variant &separator, const Variant &enclosure, const Variant &escape, const Variant &eol) {
    return _this.exec("fputcsv", fields, separator, enclosure, escape, eol);
}

Variant SplTempFileObject::setCsvControl(const Variant &separator, const Variant &enclosure, const Variant &escape) {
    return _this.exec("setCsvControl", separator, enclosure, escape);
}

Variant SplTempFileObject::getCsvControl() {
    return _this.exec("getCsvControl");
}

Variant SplTempFileObject::flock(const Variant &operation, const Variant &would_block) {
    return _this.exec("flock", operation, would_block);
}

Variant SplTempFileObject::fflush() {
    return _this.exec("fflush");
}

Variant SplTempFileObject::ftell() {
    return _this.exec("ftell");
}

Variant SplTempFileObject::fseek(const Variant &offset, const Variant &whence) {
    return _this.exec("fseek", offset, whence);
}

Variant SplTempFileObject::fgetc() {
    return _this.exec("fgetc");
}

Variant SplTempFileObject::fpassthru() {
    return _this.exec("fpassthru");
}

Variant SplTempFileObject::fscanf(const Variant &format, const Variant &vars) {
    return _this.exec("fscanf", format, vars);
}

Variant SplTempFileObject::fwrite(const Variant &data, const Variant &length) {
    return _this.exec("fwrite", data, length);
}

Variant SplTempFileObject::fstat() {
    return _this.exec("fstat");
}

Variant SplTempFileObject::ftruncate(const Variant &size) {
    return _this.exec("ftruncate", size);
}

Variant SplTempFileObject::current() {
    return _this.exec("current");
}

Variant SplTempFileObject::key() {
    return _this.exec("key");
}

Variant SplTempFileObject::next() {
    return _this.exec("next");
}

Variant SplTempFileObject::setFlags(const Variant &flags) {
    return _this.exec("setFlags", flags);
}

Variant SplTempFileObject::getFlags() {
    return _this.exec("getFlags");
}

Variant SplTempFileObject::setMaxLineLen(const Variant &max_length) {
    return _this.exec("setMaxLineLen", max_length);
}

Variant SplTempFileObject::getMaxLineLen() {
    return _this.exec("getMaxLineLen");
}

Variant SplTempFileObject::hasChildren() {
    return _this.exec("hasChildren");
}

Variant SplTempFileObject::getChildren() {
    return _this.exec("getChildren");
}

Variant SplTempFileObject::seek(const Variant &line) {
    return _this.exec("seek", line);
}

Variant SplTempFileObject::getCurrentLine() {
    return _this.exec("getCurrentLine");
}

Variant SplTempFileObject::__toString() {
    return _this.exec("__toString");
}

Variant SplTempFileObject::getPath() {
    return _this.exec("getPath");
}

Variant SplTempFileObject::getFilename() {
    return _this.exec("getFilename");
}

Variant SplTempFileObject::getExtension() {
    return _this.exec("getExtension");
}

Variant SplTempFileObject::getBasename(const Variant &suffix) {
    return _this.exec("getBasename", suffix);
}

Variant SplTempFileObject::getPathname() {
    return _this.exec("getPathname");
}

Variant SplTempFileObject::getPerms() {
    return _this.exec("getPerms");
}

Variant SplTempFileObject::getInode() {
    return _this.exec("getInode");
}

Variant SplTempFileObject::getSize() {
    return _this.exec("getSize");
}

Variant SplTempFileObject::getOwner() {
    return _this.exec("getOwner");
}

Variant SplTempFileObject::getGroup() {
    return _this.exec("getGroup");
}

Variant SplTempFileObject::getATime() {
    return _this.exec("getATime");
}

Variant SplTempFileObject::getMTime() {
    return _this.exec("getMTime");
}

Variant SplTempFileObject::getCTime() {
    return _this.exec("getCTime");
}

Variant SplTempFileObject::getType() {
    return _this.exec("getType");
}

Variant SplTempFileObject::isWritable() {
    return _this.exec("isWritable");
}

Variant SplTempFileObject::isReadable() {
    return _this.exec("isReadable");
}

Variant SplTempFileObject::isExecutable() {
    return _this.exec("isExecutable");
}

Variant SplTempFileObject::isFile() {
    return _this.exec("isFile");
}

Variant SplTempFileObject::isDir() {
    return _this.exec("isDir");
}

Variant SplTempFileObject::isLink() {
    return _this.exec("isLink");
}

Variant SplTempFileObject::getLinkTarget() {
    return _this.exec("getLinkTarget");
}

Variant SplTempFileObject::getRealPath() {
    return _this.exec("getRealPath");
}

Variant SplTempFileObject::getFileInfo(const Variant &_class) {
    return _this.exec("getFileInfo", _class);
}

Variant SplTempFileObject::getPathInfo(const Variant &_class) {
    return _this.exec("getPathInfo", _class);
}

Variant SplTempFileObject::openFile(const Variant &mode, const Variant &use_include_path, const Variant &context) {
    return _this.exec("openFile", mode, use_include_path, context);
}

Variant SplTempFileObject::setFileClass(const Variant &_class) {
    return _this.exec("setFileClass", _class);
}

Variant SplTempFileObject::setInfoClass(const Variant &_class) {
    return _this.exec("setInfoClass", _class);
}

Variant SplTempFileObject::__debugInfo() {
    return _this.exec("__debugInfo");
}

Variant SplTempFileObject::_bad_state_ex() {
    return _this.exec("_bad_state_ex");
}


Variant SplDoublyLinkedList::add(const Variant &index, const Variant &value) {
    return _this.exec("add", index, value);
}

Variant SplDoublyLinkedList::pop() {
    return _this.exec("pop");
}

Variant SplDoublyLinkedList::shift() {
    return _this.exec("shift");
}

Variant SplDoublyLinkedList::push(const Variant &value) {
    return _this.exec("push", value);
}

Variant SplDoublyLinkedList::unshift(const Variant &value) {
    return _this.exec("unshift", value);
}

Variant SplDoublyLinkedList::top() {
    return _this.exec("top");
}

Variant SplDoublyLinkedList::bottom() {
    return _this.exec("bottom");
}

Variant SplDoublyLinkedList::__debugInfo() {
    return _this.exec("__debugInfo");
}

Variant SplDoublyLinkedList::count() {
    return _this.exec("count");
}

Variant SplDoublyLinkedList::isEmpty() {
    return _this.exec("isEmpty");
}

Variant SplDoublyLinkedList::setIteratorMode(const Variant &mode) {
    return _this.exec("setIteratorMode", mode);
}

Variant SplDoublyLinkedList::getIteratorMode() {
    return _this.exec("getIteratorMode");
}

Variant SplDoublyLinkedList::offsetExists(const Variant &index) {
    return _this.exec("offsetExists", index);
}

Variant SplDoublyLinkedList::offsetGet(const Variant &index) {
    return _this.exec("offsetGet", index);
}

Variant SplDoublyLinkedList::offsetSet(const Variant &index, const Variant &value) {
    return _this.exec("offsetSet", index, value);
}

Variant SplDoublyLinkedList::offsetUnset(const Variant &index) {
    return _this.exec("offsetUnset", index);
}

Variant SplDoublyLinkedList::rewind() {
    return _this.exec("rewind");
}

Variant SplDoublyLinkedList::current() {
    return _this.exec("current");
}

Variant SplDoublyLinkedList::key() {
    return _this.exec("key");
}

Variant SplDoublyLinkedList::prev() {
    return _this.exec("prev");
}

Variant SplDoublyLinkedList::next() {
    return _this.exec("next");
}

Variant SplDoublyLinkedList::valid() {
    return _this.exec("valid");
}

Variant SplDoublyLinkedList::unserialize(const Variant &data) {
    return _this.exec("unserialize", data);
}

Variant SplDoublyLinkedList::serialize() {
    return _this.exec("serialize");
}

Variant SplDoublyLinkedList::__serialize() {
    return _this.exec("__serialize");
}

Variant SplDoublyLinkedList::__unserialize(const Variant &data) {
    return _this.exec("__unserialize", data);
}


Variant SplQueue::enqueue(const Variant &value) {
    return _this.exec("enqueue", value);
}

Variant SplQueue::dequeue() {
    return _this.exec("dequeue");
}

Variant SplQueue::add(const Variant &index, const Variant &value) {
    return _this.exec("add", index, value);
}

Variant SplQueue::pop() {
    return _this.exec("pop");
}

Variant SplQueue::shift() {
    return _this.exec("shift");
}

Variant SplQueue::push(const Variant &value) {
    return _this.exec("push", value);
}

Variant SplQueue::unshift(const Variant &value) {
    return _this.exec("unshift", value);
}

Variant SplQueue::top() {
    return _this.exec("top");
}

Variant SplQueue::bottom() {
    return _this.exec("bottom");
}

Variant SplQueue::__debugInfo() {
    return _this.exec("__debugInfo");
}

Variant SplQueue::count() {
    return _this.exec("count");
}

Variant SplQueue::isEmpty() {
    return _this.exec("isEmpty");
}

Variant SplQueue::setIteratorMode(const Variant &mode) {
    return _this.exec("setIteratorMode", mode);
}

Variant SplQueue::getIteratorMode() {
    return _this.exec("getIteratorMode");
}

Variant SplQueue::offsetExists(const Variant &index) {
    return _this.exec("offsetExists", index);
}

Variant SplQueue::offsetGet(const Variant &index) {
    return _this.exec("offsetGet", index);
}

Variant SplQueue::offsetSet(const Variant &index, const Variant &value) {
    return _this.exec("offsetSet", index, value);
}

Variant SplQueue::offsetUnset(const Variant &index) {
    return _this.exec("offsetUnset", index);
}

Variant SplQueue::rewind() {
    return _this.exec("rewind");
}

Variant SplQueue::current() {
    return _this.exec("current");
}

Variant SplQueue::key() {
    return _this.exec("key");
}

Variant SplQueue::prev() {
    return _this.exec("prev");
}

Variant SplQueue::next() {
    return _this.exec("next");
}

Variant SplQueue::valid() {
    return _this.exec("valid");
}

Variant SplQueue::unserialize(const Variant &data) {
    return _this.exec("unserialize", data);
}

Variant SplQueue::serialize() {
    return _this.exec("serialize");
}

Variant SplQueue::__serialize() {
    return _this.exec("__serialize");
}

Variant SplQueue::__unserialize(const Variant &data) {
    return _this.exec("__unserialize", data);
}


Variant SplStack::add(const Variant &index, const Variant &value) {
    return _this.exec("add", index, value);
}

Variant SplStack::pop() {
    return _this.exec("pop");
}

Variant SplStack::shift() {
    return _this.exec("shift");
}

Variant SplStack::push(const Variant &value) {
    return _this.exec("push", value);
}

Variant SplStack::unshift(const Variant &value) {
    return _this.exec("unshift", value);
}

Variant SplStack::top() {
    return _this.exec("top");
}

Variant SplStack::bottom() {
    return _this.exec("bottom");
}

Variant SplStack::__debugInfo() {
    return _this.exec("__debugInfo");
}

Variant SplStack::count() {
    return _this.exec("count");
}

Variant SplStack::isEmpty() {
    return _this.exec("isEmpty");
}

Variant SplStack::setIteratorMode(const Variant &mode) {
    return _this.exec("setIteratorMode", mode);
}

Variant SplStack::getIteratorMode() {
    return _this.exec("getIteratorMode");
}

Variant SplStack::offsetExists(const Variant &index) {
    return _this.exec("offsetExists", index);
}

Variant SplStack::offsetGet(const Variant &index) {
    return _this.exec("offsetGet", index);
}

Variant SplStack::offsetSet(const Variant &index, const Variant &value) {
    return _this.exec("offsetSet", index, value);
}

Variant SplStack::offsetUnset(const Variant &index) {
    return _this.exec("offsetUnset", index);
}

Variant SplStack::rewind() {
    return _this.exec("rewind");
}

Variant SplStack::current() {
    return _this.exec("current");
}

Variant SplStack::key() {
    return _this.exec("key");
}

Variant SplStack::prev() {
    return _this.exec("prev");
}

Variant SplStack::next() {
    return _this.exec("next");
}

Variant SplStack::valid() {
    return _this.exec("valid");
}

Variant SplStack::unserialize(const Variant &data) {
    return _this.exec("unserialize", data);
}

Variant SplStack::serialize() {
    return _this.exec("serialize");
}

Variant SplStack::__serialize() {
    return _this.exec("__serialize");
}

Variant SplStack::__unserialize(const Variant &data) {
    return _this.exec("__unserialize", data);
}


Variant SplMinHeap::extract() {
    return _this.exec("extract");
}

Variant SplMinHeap::insert(const Variant &value) {
    return _this.exec("insert", value);
}

Variant SplMinHeap::top() {
    return _this.exec("top");
}

Variant SplMinHeap::count() {
    return _this.exec("count");
}

Variant SplMinHeap::isEmpty() {
    return _this.exec("isEmpty");
}

Variant SplMinHeap::rewind() {
    return _this.exec("rewind");
}

Variant SplMinHeap::current() {
    return _this.exec("current");
}

Variant SplMinHeap::key() {
    return _this.exec("key");
}

Variant SplMinHeap::next() {
    return _this.exec("next");
}

Variant SplMinHeap::valid() {
    return _this.exec("valid");
}

Variant SplMinHeap::recoverFromCorruption() {
    return _this.exec("recoverFromCorruption");
}

Variant SplMinHeap::isCorrupted() {
    return _this.exec("isCorrupted");
}

Variant SplMinHeap::__debugInfo() {
    return _this.exec("__debugInfo");
}


Variant SplMaxHeap::extract() {
    return _this.exec("extract");
}

Variant SplMaxHeap::insert(const Variant &value) {
    return _this.exec("insert", value);
}

Variant SplMaxHeap::top() {
    return _this.exec("top");
}

Variant SplMaxHeap::count() {
    return _this.exec("count");
}

Variant SplMaxHeap::isEmpty() {
    return _this.exec("isEmpty");
}

Variant SplMaxHeap::rewind() {
    return _this.exec("rewind");
}

Variant SplMaxHeap::current() {
    return _this.exec("current");
}

Variant SplMaxHeap::key() {
    return _this.exec("key");
}

Variant SplMaxHeap::next() {
    return _this.exec("next");
}

Variant SplMaxHeap::valid() {
    return _this.exec("valid");
}

Variant SplMaxHeap::recoverFromCorruption() {
    return _this.exec("recoverFromCorruption");
}

Variant SplMaxHeap::isCorrupted() {
    return _this.exec("isCorrupted");
}

Variant SplMaxHeap::__debugInfo() {
    return _this.exec("__debugInfo");
}


Variant SplPriorityQueue::compare(const Variant &priority1, const Variant &priority2) {
    return _this.exec("compare", priority1, priority2);
}

Variant SplPriorityQueue::insert(const Variant &value, const Variant &priority) {
    return _this.exec("insert", value, priority);
}

Variant SplPriorityQueue::setExtractFlags(const Variant &flags) {
    return _this.exec("setExtractFlags", flags);
}

Variant SplPriorityQueue::top() {
    return _this.exec("top");
}

Variant SplPriorityQueue::extract() {
    return _this.exec("extract");
}

Variant SplPriorityQueue::count() {
    return _this.exec("count");
}

Variant SplPriorityQueue::isEmpty() {
    return _this.exec("isEmpty");
}

Variant SplPriorityQueue::rewind() {
    return _this.exec("rewind");
}

Variant SplPriorityQueue::current() {
    return _this.exec("current");
}

Variant SplPriorityQueue::key() {
    return _this.exec("key");
}

Variant SplPriorityQueue::next() {
    return _this.exec("next");
}

Variant SplPriorityQueue::valid() {
    return _this.exec("valid");
}

Variant SplPriorityQueue::recoverFromCorruption() {
    return _this.exec("recoverFromCorruption");
}

Variant SplPriorityQueue::isCorrupted() {
    return _this.exec("isCorrupted");
}

Variant SplPriorityQueue::getExtractFlags() {
    return _this.exec("getExtractFlags");
}

Variant SplPriorityQueue::__debugInfo() {
    return _this.exec("__debugInfo");
}


SplFixedArray::SplFixedArray(const Variant &size) {
    _this = newObject("SplFixedArray", size);
}

Variant SplFixedArray::__wakeup() {
    return _this.exec("__wakeup");
}

Variant SplFixedArray::__serialize() {
    return _this.exec("__serialize");
}

Variant SplFixedArray::__unserialize(const Variant &data) {
    return _this.exec("__unserialize", data);
}

Variant SplFixedArray::count() {
    return _this.exec("count");
}

Variant SplFixedArray::toArray() {
    return _this.exec("toArray");
}

Variant SplFixedArray::fromArray(const Variant &array, const Variant &preserve_keys) {
    static Variant fn { ZEND_STRL("SplFixedArray::fromArray"), true };
    return fn(array, preserve_keys);
}

Variant SplFixedArray::getSize() {
    return _this.exec("getSize");
}

Variant SplFixedArray::setSize(const Variant &size) {
    return _this.exec("setSize", size);
}

Variant SplFixedArray::offsetExists(const Variant &index) {
    return _this.exec("offsetExists", index);
}

Variant SplFixedArray::offsetGet(const Variant &index) {
    return _this.exec("offsetGet", index);
}

Variant SplFixedArray::offsetSet(const Variant &index, const Variant &value) {
    return _this.exec("offsetSet", index, value);
}

Variant SplFixedArray::offsetUnset(const Variant &index) {
    return _this.exec("offsetUnset", index);
}

Variant SplFixedArray::getIterator() {
    return _this.exec("getIterator");
}

Variant SplFixedArray::jsonSerialize() {
    return _this.exec("jsonSerialize");
}


Variant SplObjectStorage::attach(const Variant &object, const Variant &info) {
    return _this.exec("attach", object, info);
}

Variant SplObjectStorage::detach(const Variant &object) {
    return _this.exec("detach", object);
}

Variant SplObjectStorage::contains(const Variant &object) {
    return _this.exec("contains", object);
}

Variant SplObjectStorage::addAll(const Variant &storage) {
    return _this.exec("addAll", storage);
}

Variant SplObjectStorage::removeAll(const Variant &storage) {
    return _this.exec("removeAll", storage);
}

Variant SplObjectStorage::removeAllExcept(const Variant &storage) {
    return _this.exec("removeAllExcept", storage);
}

Variant SplObjectStorage::getInfo() {
    return _this.exec("getInfo");
}

Variant SplObjectStorage::setInfo(const Variant &info) {
    return _this.exec("setInfo", info);
}

Variant SplObjectStorage::count(const Variant &mode) {
    return _this.exec("count", mode);
}

Variant SplObjectStorage::rewind() {
    return _this.exec("rewind");
}

Variant SplObjectStorage::valid() {
    return _this.exec("valid");
}

Variant SplObjectStorage::key() {
    return _this.exec("key");
}

Variant SplObjectStorage::current() {
    return _this.exec("current");
}

Variant SplObjectStorage::next() {
    return _this.exec("next");
}

Variant SplObjectStorage::unserialize(const Variant &data) {
    return _this.exec("unserialize", data);
}

Variant SplObjectStorage::serialize() {
    return _this.exec("serialize");
}

Variant SplObjectStorage::offsetExists(const Variant &object) {
    return _this.exec("offsetExists", object);
}

Variant SplObjectStorage::offsetGet(const Variant &object) {
    return _this.exec("offsetGet", object);
}

Variant SplObjectStorage::offsetSet(const Variant &object, const Variant &info) {
    return _this.exec("offsetSet", object, info);
}

Variant SplObjectStorage::offsetUnset(const Variant &object) {
    return _this.exec("offsetUnset", object);
}

Variant SplObjectStorage::getHash(const Variant &object) {
    return _this.exec("getHash", object);
}

Variant SplObjectStorage::__serialize() {
    return _this.exec("__serialize");
}

Variant SplObjectStorage::__unserialize(const Variant &data) {
    return _this.exec("__unserialize", data);
}

Variant SplObjectStorage::__debugInfo() {
    return _this.exec("__debugInfo");
}


MultipleIterator::MultipleIterator(const Variant &flags) {
    _this = newObject("MultipleIterator", flags);
}

Variant MultipleIterator::getFlags() {
    return _this.exec("getFlags");
}

Variant MultipleIterator::setFlags(const Variant &flags) {
    return _this.exec("setFlags", flags);
}

Variant MultipleIterator::attachIterator(const Variant &iterator, const Variant &info) {
    return _this.exec("attachIterator", iterator, info);
}

Variant MultipleIterator::detachIterator(const Variant &iterator) {
    return _this.exec("detachIterator", iterator);
}

Variant MultipleIterator::containsIterator(const Variant &iterator) {
    return _this.exec("containsIterator", iterator);
}

Variant MultipleIterator::countIterators() {
    return _this.exec("countIterators");
}

Variant MultipleIterator::rewind() {
    return _this.exec("rewind");
}

Variant MultipleIterator::valid() {
    return _this.exec("valid");
}

Variant MultipleIterator::key() {
    return _this.exec("key");
}

Variant MultipleIterator::current() {
    return _this.exec("current");
}

Variant MultipleIterator::next() {
    return _this.exec("next");
}

Variant MultipleIterator::__debugInfo() {
    return _this.exec("__debugInfo");
}


}

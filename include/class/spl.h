#pragma once

#include "phpx.h"
#include "phpx_literal_string.h"
#include "class/core.h"

namespace php {
class LogicException;
class BadFunctionCallException;
class BadMethodCallException;
class DomainException;
class InvalidArgumentException;
class LengthException;
class OutOfRangeException;
class RuntimeException;
class OutOfBoundsException;
class OverflowException;
class RangeException;
class UnderflowException;
class UnexpectedValueException;
class RecursiveIteratorIterator;
class IteratorIterator;
class CallbackFilterIterator;
class RecursiveCallbackFilterIterator;
class ParentIterator;
class LimitIterator;
class CachingIterator;
class RecursiveCachingIterator;
class NoRewindIterator;
class InfiniteIterator;
class RegexIterator;
class RecursiveRegexIterator;
class EmptyIterator;
class RecursiveTreeIterator;
class ArrayObject;
class ArrayIterator_;
class AppendIterator;
class RecursiveArrayIterator;
class SplDoublyLinkedList;
class SplQueue;
class SplStack;
class SplMinHeap;
class SplMaxHeap;
class SplPriorityQueue;
class SplFixedArray;
class SplObjectStorage;
class MultipleIterator;
class SplFileInfo;
class SplFileObject;
class DirectoryIterator;
class FilesystemIterator;
class RecursiveDirectoryIterator;
class GlobIterator;
class SplTempFileObject;

class LogicException : public Exception {
  public:
    LogicException(const Variant &message = "", const Variant &code = 0, const Variant &previous = {});
};

class BadFunctionCallException : public LogicException {
  public:
    BadFunctionCallException(const Variant &message = "", const Variant &code = 0, const Variant &previous = {});
};

class BadMethodCallException : public BadFunctionCallException {
  public:
    BadMethodCallException(const Variant &message = "", const Variant &code = 0, const Variant &previous = {});
};

class DomainException : public LogicException {
  public:
    DomainException(const Variant &message = "", const Variant &code = 0, const Variant &previous = {});
};

class InvalidArgumentException : public LogicException {
  public:
    InvalidArgumentException(const Variant &message = "", const Variant &code = 0, const Variant &previous = {});
};

class LengthException : public LogicException {
  public:
    LengthException(const Variant &message = "", const Variant &code = 0, const Variant &previous = {});
};

class OutOfRangeException : public LogicException {
  public:
    OutOfRangeException(const Variant &message = "", const Variant &code = 0, const Variant &previous = {});
};

class RuntimeException : public Exception {
  public:
    RuntimeException(const Variant &message = "", const Variant &code = 0, const Variant &previous = {});
};

class OutOfBoundsException : public RuntimeException {
  public:
    OutOfBoundsException(const Variant &message = "", const Variant &code = 0, const Variant &previous = {});
};

class OverflowException : public RuntimeException {
  public:
    OverflowException(const Variant &message = "", const Variant &code = 0, const Variant &previous = {});
};

class RangeException : public RuntimeException {
  public:
    RangeException(const Variant &message = "", const Variant &code = 0, const Variant &previous = {});
};

class UnderflowException : public RuntimeException {
  public:
    UnderflowException(const Variant &message = "", const Variant &code = 0, const Variant &previous = {});
};

class UnexpectedValueException : public RuntimeException {
  public:
    UnexpectedValueException(const Variant &message = "", const Variant &code = 0, const Variant &previous = {});
};

class RecursiveIteratorIterator {
  protected:
    Object this_;
    RecursiveIteratorIterator() = default;

  public:
    Object getObject() const {
        return this_;
    }
    static constexpr int LEAVES_ONLY = 0;
    static constexpr int SELF_FIRST = 1;
    static constexpr int CHILD_FIRST = 2;
    static constexpr int CATCH_GET_CHILD = 16;

    RecursiveIteratorIterator(const Variant &iterator, const Variant &mode = 0, const Variant &flags = 0);
    Variant rewind();
    Variant valid();
    Variant key();
    Variant current();
    Variant next();
    Variant getDepth();
    Variant getSubIterator(const Variant &level = {});
    Variant getInnerIterator();
    Variant beginIteration();
    Variant endIteration();
    Variant callHasChildren();
    Variant callGetChildren();
    Variant beginChildren();
    Variant endChildren();
    Variant nextElement();
    Variant setMaxDepth(const Variant &max_depth = -1);
    Variant getMaxDepth();
};

class IteratorIterator {
  protected:
    Object this_;
    IteratorIterator() = default;

  public:
    Object getObject() const {
        return this_;
    }
    IteratorIterator(const Variant &iterator, const Variant &class_ = {});
    Variant getInnerIterator();
    Variant rewind();
    Variant valid();
    Variant key();
    Variant current();
    Variant next();
};

class CallbackFilterIterator {
  protected:
    Object this_;
    CallbackFilterIterator() = default;

  public:
    Object getObject() const {
        return this_;
    }
    CallbackFilterIterator(const Variant &iterator, const Variant &callback);
    Variant accept();
    Variant rewind();
    Variant next();
    Variant getInnerIterator();
    Variant valid();
    Variant key();
    Variant current();
};

class RecursiveCallbackFilterIterator : public CallbackFilterIterator {
  protected:
    RecursiveCallbackFilterIterator() = default;

  public:
    RecursiveCallbackFilterIterator(const Variant &iterator, const Variant &callback);
    Variant hasChildren();
    Variant getChildren();
};

class ParentIterator {
  protected:
    Object this_;
    ParentIterator() = default;

  public:
    Object getObject() const {
        return this_;
    }
    ParentIterator(const Variant &iterator);
    Variant accept();
    Variant hasChildren();
    Variant getChildren();
    Variant rewind();
    Variant next();
    Variant getInnerIterator();
    Variant valid();
    Variant key();
    Variant current();
};

class LimitIterator : public IteratorIterator {
  protected:
    LimitIterator() = default;

  public:
    LimitIterator(const Variant &iterator, const Variant &offset = 0, const Variant &limit = -1);
    Variant rewind();
    Variant valid();
    Variant next();
    Variant seek(const Variant &offset);
    Variant getPosition();
};

class CachingIterator : public IteratorIterator {
  protected:
    CachingIterator() = default;

  public:
    static constexpr int CALL_TOSTRING = 1;
    static constexpr int CATCH_GET_CHILD = 16;
    static constexpr int TOSTRING_USE_KEY = 2;
    static constexpr int TOSTRING_USE_CURRENT = 4;
    static constexpr int TOSTRING_USE_INNER = 8;
    static constexpr int FULL_CACHE = 256;

    CachingIterator(const Variant &iterator, const Variant &flags = 1);
    Variant rewind();
    Variant valid();
    Variant next();
    Variant hasNext();
    Variant __toString();
    Variant getFlags();
    Variant setFlags(const Variant &flags);
    Variant offsetGet(const Variant &key);
    Variant offsetSet(const Variant &key, const Variant &value);
    Variant offsetUnset(const Variant &key);
    Variant offsetExists(const Variant &key);
    Variant getCache();
    Variant count();
};

class RecursiveCachingIterator : public CachingIterator {
  protected:
    RecursiveCachingIterator() = default;

  public:
    RecursiveCachingIterator(const Variant &iterator, const Variant &flags = 1);
    Variant hasChildren();
    Variant getChildren();
};

class NoRewindIterator : public IteratorIterator {
  protected:
    NoRewindIterator() = default;

  public:
    NoRewindIterator(const Variant &iterator);
    Variant rewind();
    Variant valid();
    Variant key();
    Variant current();
    Variant next();
};

class InfiniteIterator : public IteratorIterator {
  protected:
    InfiniteIterator() = default;

  public:
    InfiniteIterator(const Variant &iterator);
    Variant next();
};

class RegexIterator {
  protected:
    Object this_;
    RegexIterator() = default;

  public:
    Object getObject() const {
        return this_;
    }
    static constexpr int USE_KEY = 1;
    static constexpr int INVERT_MATCH = 2;
    static constexpr int MATCH = 0;
    static constexpr int GET_MATCH = 1;
    static constexpr int ALL_MATCHES = 2;
    static constexpr int SPLIT = 3;
    static constexpr int REPLACE = 4;

    RegexIterator(const Variant &iterator,
                  const Variant &pattern,
                  const Variant &mode = 0,
                  const Variant &flags = 0,
                  const Variant &preg_flags = 0);
    Variant accept();
    Variant getMode();
    Variant setMode(const Variant &mode);
    Variant getFlags();
    Variant setFlags(const Variant &flags);
    Variant getRegex();
    Variant getPregFlags();
    Variant setPregFlags(const Variant &preg_flags);
    Variant rewind();
    Variant next();
    Variant getInnerIterator();
    Variant valid();
    Variant key();
    Variant current();
};

class RecursiveRegexIterator : public RegexIterator {
  protected:
    RecursiveRegexIterator() = default;

  public:
    RecursiveRegexIterator(const Variant &iterator,
                           const Variant &pattern,
                           const Variant &mode = 0,
                           const Variant &flags = 0,
                           const Variant &preg_flags = 0);
    Variant accept();
    Variant hasChildren();
    Variant getChildren();
};

class EmptyIterator {
  protected:
    Object this_;

  public:
    Object getObject() const {
        return this_;
    }
    explicit EmptyIterator(const Object &obj) : this_(obj) {}
    EmptyIterator();
    Variant current();
    Variant next();
    Variant key();
    Variant valid();
    Variant rewind();
};

class RecursiveTreeIterator : public RecursiveIteratorIterator {
  protected:
    RecursiveTreeIterator() = default;

  public:
    static constexpr int BYPASS_CURRENT = 4;
    static constexpr int BYPASS_KEY = 8;
    static constexpr int PREFIX_LEFT = 0;
    static constexpr int PREFIX_MID_HAS_NEXT = 1;
    static constexpr int PREFIX_MID_LAST = 2;
    static constexpr int PREFIX_END_HAS_NEXT = 3;
    static constexpr int PREFIX_END_LAST = 4;
    static constexpr int PREFIX_RIGHT = 5;

    RecursiveTreeIterator(const Variant &iterator,
                          const Variant &flags = 8,
                          const Variant &caching_iterator_flags = 16,
                          const Variant &mode = 1);
    Variant key();
    Variant current();
    Variant getPrefix();
    Variant setPostfix(const Variant &postfix);
    Variant setPrefixPart(const Variant &part, const Variant &value);
    Variant getEntry();
    Variant getPostfix();
};

class ArrayObject {
  protected:
    Object this_;

  public:
    Object getObject() const {
        return this_;
    }
    static constexpr int STD_PROP_LIST = 1;
    static constexpr int ARRAY_AS_PROPS = 2;

    ArrayObject(const Variant &array = Array{},
                const Variant &flags = 0,
                const Variant &iterator_class = "ArrayIterator");
    Variant offsetExists(const Variant &key);
    Variant offsetGet(const Variant &key);
    Variant offsetSet(const Variant &key, const Variant &value);
    Variant offsetUnset(const Variant &key);
    Variant append(const Variant &value);
    Variant getArrayCopy();
    Variant count();
    Variant getFlags();
    Variant setFlags(const Variant &flags);
    Variant asort(const Variant &flags = 0);
    Variant ksort(const Variant &flags = 0);
    Variant uasort(const Variant &callback);
    Variant uksort(const Variant &callback);
    Variant natsort();
    Variant natcasesort();
    Variant unserialize(const Variant &data);
    Variant serialize();
    Variant __serialize();
    Variant __unserialize(const Variant &data);
    Variant getIterator();
    Variant exchangeArray(const Variant &array);
    Variant setIteratorClass(const Variant &iterator_class);
    Variant getIteratorClass();
    Variant __debugInfo();
};

class ArrayIterator_ {
  protected:
    Object this_;

  public:
    Object getObject() const {
        return this_;
    }
    static constexpr int STD_PROP_LIST = 1;
    static constexpr int ARRAY_AS_PROPS = 2;

    ArrayIterator_(const Variant &array = Array{}, const Variant &flags = 0);
    Variant offsetExists(const Variant &key);
    Variant offsetGet(const Variant &key);
    Variant offsetSet(const Variant &key, const Variant &value);
    Variant offsetUnset(const Variant &key);
    Variant append(const Variant &value);
    Variant getArrayCopy();
    Variant count();
    Variant getFlags();
    Variant setFlags(const Variant &flags);
    Variant asort(const Variant &flags = 0);
    Variant ksort(const Variant &flags = 0);
    Variant uasort(const Variant &callback);
    Variant uksort(const Variant &callback);
    Variant natsort();
    Variant natcasesort();
    Variant unserialize(const Variant &data);
    Variant serialize();
    Variant __serialize();
    Variant __unserialize(const Variant &data);
    Variant rewind();
    Variant current();
    Variant key();
    Variant next();
    Variant valid();
    Variant seek(const Variant &offset);
    Variant __debugInfo();
};

class AppendIterator : public IteratorIterator {
  public:
    AppendIterator();
    Variant append(const Variant &iterator);
    Variant rewind();
    Variant valid();
    Variant current();
    Variant next();
    Variant getIteratorIndex();
    Variant getArrayIterator();
};

class RecursiveArrayIterator : public ArrayIterator_ {
  public:
    static constexpr int CHILD_ARRAYS_ONLY = 4;

    Variant hasChildren();
    Variant getChildren();
    RecursiveArrayIterator(const Variant &array = Array{}, const Variant &flags = 0);
};

class SplDoublyLinkedList {
  protected:
    Object this_;

  public:
    Object getObject() const {
        return this_;
    }
    explicit SplDoublyLinkedList(const Object &obj) : this_(obj) {}
    static constexpr int IT_MODE_LIFO = 2;
    static constexpr int IT_MODE_FIFO = 0;
    static constexpr int IT_MODE_DELETE = 1;
    static constexpr int IT_MODE_KEEP = 0;

    SplDoublyLinkedList();
    Variant add(const Variant &index, const Variant &value);
    Variant pop();
    Variant shift();
    Variant push(const Variant &value);
    Variant unshift(const Variant &value);
    Variant top();
    Variant bottom();
    Variant __debugInfo();
    Variant count();
    Variant isEmpty();
    Variant setIteratorMode(const Variant &mode);
    Variant getIteratorMode();
    Variant offsetExists(const Variant &index);
    Variant offsetGet(const Variant &index);
    Variant offsetSet(const Variant &index, const Variant &value);
    Variant offsetUnset(const Variant &index);
    Variant rewind();
    Variant current();
    Variant key();
    Variant prev();
    Variant next();
    Variant valid();
    Variant unserialize(const Variant &data);
    Variant serialize();
    Variant __serialize();
    Variant __unserialize(const Variant &data);
};

class SplQueue : public SplDoublyLinkedList {
  public:
    explicit SplQueue(const Object &obj) : SplDoublyLinkedList(obj) {}
    SplQueue();
    Variant enqueue(const Variant &value);
    Variant dequeue();
};

class SplStack : public SplDoublyLinkedList {
  public:
    explicit SplStack(const Object &obj) : SplDoublyLinkedList(obj) {}
    SplStack();
};

class SplMinHeap {
  protected:
    Object this_;

  public:
    Object getObject() const {
        return this_;
    }
    explicit SplMinHeap(const Object &obj) : this_(obj) {}
    SplMinHeap();
    Variant extract();
    Variant insert(const Variant &value);
    Variant top();
    Variant count();
    Variant isEmpty();
    Variant rewind();
    Variant current();
    Variant key();
    Variant next();
    Variant valid();
    Variant recoverFromCorruption();
    Variant isCorrupted();
    Variant __debugInfo();
};

class SplMaxHeap {
  protected:
    Object this_;

  public:
    Object getObject() const {
        return this_;
    }
    explicit SplMaxHeap(const Object &obj) : this_(obj) {}
    SplMaxHeap();
    Variant extract();
    Variant insert(const Variant &value);
    Variant top();
    Variant count();
    Variant isEmpty();
    Variant rewind();
    Variant current();
    Variant key();
    Variant next();
    Variant valid();
    Variant recoverFromCorruption();
    Variant isCorrupted();
    Variant __debugInfo();
};

class SplPriorityQueue {
  protected:
    Object this_;

  public:
    Object getObject() const {
        return this_;
    }
    explicit SplPriorityQueue(const Object &obj) : this_(obj) {}
    static constexpr int EXTR_BOTH = 3;
    static constexpr int EXTR_PRIORITY = 2;
    static constexpr int EXTR_DATA = 1;

    SplPriorityQueue();
    Variant compare(const Variant &priority1, const Variant &priority2);
    Variant insert(const Variant &value, const Variant &priority);
    Variant setExtractFlags(const Variant &flags);
    Variant top();
    Variant extract();
    Variant count();
    Variant isEmpty();
    Variant rewind();
    Variant current();
    Variant key();
    Variant next();
    Variant valid();
    Variant recoverFromCorruption();
    Variant isCorrupted();
    Variant getExtractFlags();
    Variant __debugInfo();
};

class SplFixedArray {
  protected:
    Object this_;

  public:
    Object getObject() const {
        return this_;
    }
    SplFixedArray(const Variant &size = 0);
    Variant __wakeup();
    Variant __serialize();
    Variant __unserialize(const Variant &data);
    Variant count();
    Variant toArray();
    static Variant fromArray(const Variant &array, const Variant &preserve_keys = true);
    Variant getSize();
    Variant setSize(const Variant &size);
    Variant offsetExists(const Variant &index);
    Variant offsetGet(const Variant &index);
    Variant offsetSet(const Variant &index, const Variant &value);
    Variant offsetUnset(const Variant &index);
    Variant getIterator();
    Variant jsonSerialize();
};

class SplObjectStorage {
  protected:
    Object this_;

  public:
    Object getObject() const {
        return this_;
    }
    explicit SplObjectStorage(const Object &obj) : this_(obj) {}
    SplObjectStorage();
    Variant attach(const Variant &object, const Variant &info = {});
    Variant detach(const Variant &object);
    Variant contains(const Variant &object);
    Variant addAll(const SplObjectStorage &storage);
    Variant addAll(const Variant &storage);
    Variant removeAll(const SplObjectStorage &storage);
    Variant removeAll(const Variant &storage);
    Variant removeAllExcept(const SplObjectStorage &storage);
    Variant removeAllExcept(const Variant &storage);
    Variant getInfo();
    Variant setInfo(const Variant &info);
    Variant count(const Variant &mode = 0);
    Variant rewind();
    Variant valid();
    Variant key();
    Variant current();
    Variant next();
    Variant seek(const Variant &offset);
    Variant unserialize(const Variant &data);
    Variant serialize();
    Variant offsetExists(const Variant &object);
    Variant offsetGet(const Variant &object);
    Variant offsetSet(const Variant &object, const Variant &info = {});
    Variant offsetUnset(const Variant &object);
    Variant getHash(const Variant &object);
    Variant __serialize();
    Variant __unserialize(const Variant &data);
    Variant __debugInfo();
};

class MultipleIterator {
  protected:
    Object this_;

  public:
    Object getObject() const {
        return this_;
    }
    static constexpr int MIT_NEED_ANY = 0;
    static constexpr int MIT_NEED_ALL = 1;
    static constexpr int MIT_KEYS_NUMERIC = 0;
    static constexpr int MIT_KEYS_ASSOC = 2;

    MultipleIterator(const Variant &flags = 1);
    Variant getFlags();
    Variant setFlags(const Variant &flags);
    Variant attachIterator(const Variant &iterator, const Variant &info = {});
    Variant detachIterator(const Variant &iterator);
    Variant containsIterator(const Variant &iterator);
    Variant countIterators();
    Variant rewind();
    Variant valid();
    Variant key();
    Variant current();
    Variant next();
    Variant __debugInfo();
};

class SplFileInfo {
  protected:
    Object this_;
    SplFileInfo() = default;

  public:
    Object getObject() const {
        return this_;
    }
    SplFileInfo(const Variant &filename);
    Variant getPath();
    Variant getFilename();
    Variant getExtension();
    Variant getBasename(const Variant &suffix = "");
    Variant getPathname();
    Variant getPerms();
    Variant getInode();
    Variant getSize();
    Variant getOwner();
    Variant getGroup();
    Variant getATime();
    Variant getMTime();
    Variant getCTime();
    Variant getType();
    Variant isWritable();
    Variant isReadable();
    Variant isExecutable();
    Variant isFile();
    Variant isDir();
    Variant isLink();
    Variant getLinkTarget();
    Variant getRealPath();
    Variant getFileInfo(const Variant &class_ = {});
    Variant getPathInfo(const Variant &class_ = {});
    Variant openFile(const Variant &mode = "r", const Variant &use_include_path = false, const Variant &context = {});
    Variant setFileClass(const Variant &class_ = "SplFileObject");
    Variant setInfoClass(const Variant &class_ = "SplFileInfo");
    Variant __toString();
    Variant __debugInfo();
    Variant _bad_state_ex();
};

class SplFileObject : public SplFileInfo {
  protected:
    SplFileObject() = default;

  public:
    static constexpr int DROP_NEW_LINE = 1;
    static constexpr int READ_AHEAD = 2;
    static constexpr int SKIP_EMPTY = 4;
    static constexpr int READ_CSV = 8;

    SplFileObject(const Variant &filename,
                  const Variant &mode = "r",
                  const Variant &use_include_path = false,
                  const Variant &context = {});
    Variant rewind();
    Variant eof();
    Variant valid();
    Variant fgets();
    Variant fread(const Variant &length);
    Variant fgetcsv(const Variant &separator = ",", const Variant &enclosure = "\"", const Variant &escape = "\\");
    Variant fputcsv(const Variant &fields,
                    const Variant &separator = ",",
                    const Variant &enclosure = "\"",
                    const Variant &escape = "\\",
                    const Variant &eol = "\n");
    Variant setCsvControl(const Variant &separator = ",",
                          const Variant &enclosure = "\"",
                          const Variant &escape = "\\");
    Variant getCsvControl();
    Variant flock(const Variant &operation, const Reference &would_block = {});
    Variant fflush();
    Variant ftell();
    Variant fseek(const Variant &offset, const Variant &whence = 0);
    Variant fgetc();
    Variant fpassthru();
    template <typename... Args>
    Variant fscanf(const Variant &format, const Args &...vars) {
        static THREAD_LOCAL zend_function *_method_fn = nullptr;
        if (UNEXPECTED(!_method_fn)) {
            _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[2146]);
        }
        return this_.call(_method_fn, {format, vars...});
    }
    Variant fwrite(const Variant &data, const Variant &length = 0);
    Variant fstat();
    Variant ftruncate(const Variant &size);
    Variant current();
    Variant key();
    Variant next();
    Variant setFlags(const Variant &flags);
    Variant getFlags();
    Variant setMaxLineLen(const Variant &max_length);
    Variant getMaxLineLen();
    Variant hasChildren();
    Variant getChildren();
    Variant seek(const Variant &line);
    Variant getCurrentLine();
    Variant __toString();
};

class DirectoryIterator : public SplFileInfo {
  protected:
    DirectoryIterator() = default;

  public:
    DirectoryIterator(const Variant &directory);
    Variant getFilename();
    Variant getExtension();
    Variant getBasename(const Variant &suffix = "");
    Variant isDot();
    Variant rewind();
    Variant valid();
    Variant key();
    Variant current();
    Variant next();
    Variant seek(const Variant &offset);
    Variant __toString();
};

class FilesystemIterator : public DirectoryIterator {
  protected:
    FilesystemIterator() = default;

  public:
    static constexpr int CURRENT_MODE_MASK = 240;
    static constexpr int CURRENT_AS_PATHNAME = 32;
    static constexpr int CURRENT_AS_FILEINFO = 0;
    static constexpr int CURRENT_AS_SELF = 16;
    static constexpr int KEY_MODE_MASK = 3840;
    static constexpr int KEY_AS_PATHNAME = 0;
    static constexpr int FOLLOW_SYMLINKS = 16384;
    static constexpr int KEY_AS_FILENAME = 256;
    static constexpr int NEW_CURRENT_AND_KEY = 256;
    static constexpr int OTHER_MODE_MASK = 28672;
    static constexpr int SKIP_DOTS = 4096;
    static constexpr int UNIX_PATHS = 8192;

    FilesystemIterator(const Variant &directory, const Variant &flags = 4096);
    Variant rewind();
    Variant key();
    Variant current();
    Variant getFlags();
    Variant setFlags(const Variant &flags);
};

class RecursiveDirectoryIterator : public FilesystemIterator {
  protected:
    RecursiveDirectoryIterator() = default;

  public:
    RecursiveDirectoryIterator(const Variant &directory, const Variant &flags = 0);
    Variant hasChildren(const Variant &allow_links = false);
    Variant getChildren();
    Variant getSubPath();
    Variant getSubPathname();
};

class GlobIterator : public FilesystemIterator {
  protected:
    GlobIterator() = default;

  public:
    GlobIterator(const Variant &pattern, const Variant &flags = 0);
    Variant count();
};

class SplTempFileObject : public SplFileObject {
  public:
    SplTempFileObject(const Variant &max_memory = 2097152);
};

}  // namespace php

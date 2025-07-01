namespace php {
class LogicException {
    Object _this;
  public:
    LogicException(const Variant &message = "", const Variant &code = 0, const Variant &previous = {});
    Variant __wakeup();
    Variant getMessage();
    Variant getCode();
    Variant getFile();
    Variant getLine();
    Variant getTrace();
    Variant getPrevious();
    Variant getTraceAsString();
    Variant __toString();
};

class BadFunctionCallException {
    Object _this;
  public:
    BadFunctionCallException(const Variant &message = "", const Variant &code = 0, const Variant &previous = {});
    Variant __wakeup();
    Variant getMessage();
    Variant getCode();
    Variant getFile();
    Variant getLine();
    Variant getTrace();
    Variant getPrevious();
    Variant getTraceAsString();
    Variant __toString();
};

class BadMethodCallException {
    Object _this;
  public:
    BadMethodCallException(const Variant &message = "", const Variant &code = 0, const Variant &previous = {});
    Variant __wakeup();
    Variant getMessage();
    Variant getCode();
    Variant getFile();
    Variant getLine();
    Variant getTrace();
    Variant getPrevious();
    Variant getTraceAsString();
    Variant __toString();
};

class DomainException {
    Object _this;
  public:
    DomainException(const Variant &message = "", const Variant &code = 0, const Variant &previous = {});
    Variant __wakeup();
    Variant getMessage();
    Variant getCode();
    Variant getFile();
    Variant getLine();
    Variant getTrace();
    Variant getPrevious();
    Variant getTraceAsString();
    Variant __toString();
};

class InvalidArgumentException {
    Object _this;
  public:
    InvalidArgumentException(const Variant &message = "", const Variant &code = 0, const Variant &previous = {});
    Variant __wakeup();
    Variant getMessage();
    Variant getCode();
    Variant getFile();
    Variant getLine();
    Variant getTrace();
    Variant getPrevious();
    Variant getTraceAsString();
    Variant __toString();
};

class LengthException {
    Object _this;
  public:
    LengthException(const Variant &message = "", const Variant &code = 0, const Variant &previous = {});
    Variant __wakeup();
    Variant getMessage();
    Variant getCode();
    Variant getFile();
    Variant getLine();
    Variant getTrace();
    Variant getPrevious();
    Variant getTraceAsString();
    Variant __toString();
};

class OutOfRangeException {
    Object _this;
  public:
    OutOfRangeException(const Variant &message = "", const Variant &code = 0, const Variant &previous = {});
    Variant __wakeup();
    Variant getMessage();
    Variant getCode();
    Variant getFile();
    Variant getLine();
    Variant getTrace();
    Variant getPrevious();
    Variant getTraceAsString();
    Variant __toString();
};

class RuntimeException {
    Object _this;
  public:
    RuntimeException(const Variant &message = "", const Variant &code = 0, const Variant &previous = {});
    Variant __wakeup();
    Variant getMessage();
    Variant getCode();
    Variant getFile();
    Variant getLine();
    Variant getTrace();
    Variant getPrevious();
    Variant getTraceAsString();
    Variant __toString();
};

class OutOfBoundsException {
    Object _this;
  public:
    OutOfBoundsException(const Variant &message = "", const Variant &code = 0, const Variant &previous = {});
    Variant __wakeup();
    Variant getMessage();
    Variant getCode();
    Variant getFile();
    Variant getLine();
    Variant getTrace();
    Variant getPrevious();
    Variant getTraceAsString();
    Variant __toString();
};

class OverflowException {
    Object _this;
  public:
    OverflowException(const Variant &message = "", const Variant &code = 0, const Variant &previous = {});
    Variant __wakeup();
    Variant getMessage();
    Variant getCode();
    Variant getFile();
    Variant getLine();
    Variant getTrace();
    Variant getPrevious();
    Variant getTraceAsString();
    Variant __toString();
};

class RangeException {
    Object _this;
  public:
    RangeException(const Variant &message = "", const Variant &code = 0, const Variant &previous = {});
    Variant __wakeup();
    Variant getMessage();
    Variant getCode();
    Variant getFile();
    Variant getLine();
    Variant getTrace();
    Variant getPrevious();
    Variant getTraceAsString();
    Variant __toString();
};

class UnderflowException {
    Object _this;
  public:
    UnderflowException(const Variant &message = "", const Variant &code = 0, const Variant &previous = {});
    Variant __wakeup();
    Variant getMessage();
    Variant getCode();
    Variant getFile();
    Variant getLine();
    Variant getTrace();
    Variant getPrevious();
    Variant getTraceAsString();
    Variant __toString();
};

class UnexpectedValueException {
    Object _this;
  public:
    UnexpectedValueException(const Variant &message = "", const Variant &code = 0, const Variant &previous = {});
    Variant __wakeup();
    Variant getMessage();
    Variant getCode();
    Variant getFile();
    Variant getLine();
    Variant getTrace();
    Variant getPrevious();
    Variant getTraceAsString();
    Variant __toString();
};

class RecursiveIteratorIterator {
    Object _this;
  public:
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
    Object _this;
  public:
    IteratorIterator(const Variant &iterator, const Variant &_class = {});
    Variant getInnerIterator();
    Variant rewind();
    Variant valid();
    Variant key();
    Variant current();
    Variant next();
};

class CallbackFilterIterator {
    Object _this;
  public:
    CallbackFilterIterator(const Variant &iterator, const Variant &callback);
    Variant accept();
    Variant rewind();
    Variant next();
    Variant getInnerIterator();
    Variant valid();
    Variant key();
    Variant current();
};

class RecursiveCallbackFilterIterator {
    Object _this;
  public:
    RecursiveCallbackFilterIterator(const Variant &iterator, const Variant &callback);
    Variant hasChildren();
    Variant getChildren();
    Variant accept();
    Variant rewind();
    Variant next();
    Variant getInnerIterator();
    Variant valid();
    Variant key();
    Variant current();
};

class ParentIterator {
    Object _this;
  public:
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

class LimitIterator {
    Object _this;
  public:
    LimitIterator(const Variant &iterator, const Variant &offset = 0, const Variant &limit = -1);
    Variant rewind();
    Variant valid();
    Variant next();
    Variant seek(const Variant &offset);
    Variant getPosition();
    Variant getInnerIterator();
    Variant key();
    Variant current();
};

class CachingIterator {
    Object _this;
  public:
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
    Variant getInnerIterator();
    Variant key();
    Variant current();
};

class RecursiveCachingIterator {
    Object _this;
  public:
    RecursiveCachingIterator(const Variant &iterator, const Variant &flags = 1);
    Variant hasChildren();
    Variant getChildren();
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
    Variant getInnerIterator();
    Variant key();
    Variant current();
};

class NoRewindIterator {
    Object _this;
  public:
    NoRewindIterator(const Variant &iterator);
    Variant rewind();
    Variant valid();
    Variant key();
    Variant current();
    Variant next();
    Variant getInnerIterator();
};

class AppendIterator {
    Object _this;
  public:
    AppendIterator();
    Variant append(const Variant &iterator);
    Variant rewind();
    Variant valid();
    Variant current();
    Variant next();
    Variant getIteratorIndex();
    Variant getArrayIterator();
    Variant getInnerIterator();
    Variant key();
};

class InfiniteIterator {
    Object _this;
  public:
    InfiniteIterator(const Variant &iterator);
    Variant next();
    Variant getInnerIterator();
    Variant rewind();
    Variant valid();
    Variant key();
    Variant current();
};

class RegexIterator {
    Object _this;
  public:
    RegexIterator(const Variant &iterator, const Variant &pattern, const Variant &mode = 0, const Variant &flags = 0, const Variant &preg_flags = 0);
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

class RecursiveRegexIterator {
    Object _this;
  public:
    RecursiveRegexIterator(const Variant &iterator, const Variant &pattern, const Variant &mode = 0, const Variant &flags = 0, const Variant &preg_flags = 0);
    Variant accept();
    Variant hasChildren();
    Variant getChildren();
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

class EmptyIterator {
    Object _this;
  public:
    Variant current();
    Variant next();
    Variant key();
    Variant valid();
    Variant rewind();
};

class RecursiveTreeIterator {
    Object _this;
  public:
    RecursiveTreeIterator(const Variant &iterator, const Variant &flags = 8, const Variant &caching_iterator_flags = 16, const Variant &mode = 1);
    Variant key();
    Variant current();
    Variant getPrefix();
    Variant setPostfix(const Variant &postfix);
    Variant setPrefixPart(const Variant &part, const Variant &value);
    Variant getEntry();
    Variant getPostfix();
    Variant rewind();
    Variant valid();
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

class ArrayObject {
    Object _this;
  public:
    ArrayObject(const Array &array = {}, const Variant &flags = 0, const Variant &iterator_class = "ArrayIterator");
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

class _ArrayIterator {
    Object _this;
  public:
    _ArrayIterator(const Array &array = {}, const Variant &flags = 0);
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

class RecursiveArrayIterator {
    Object _this;
  public:
    Variant hasChildren();
    Variant getChildren();
    RecursiveArrayIterator(const Array &array = {}, const Variant &flags = 0);
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

class SplFileInfo {
    Object _this;
  public:
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
    Variant getFileInfo(const Variant &_class = {});
    Variant getPathInfo(const Variant &_class = {});
    Variant openFile(const Variant &mode = "r", const Variant &use_include_path = false, const Variant &context = {});
    Variant setFileClass(const Variant &_class = "SplFileObject");
    Variant setInfoClass(const Variant &_class = "SplFileInfo");
    Variant __toString();
    Variant __debugInfo();
    Variant _bad_state_ex();
};

class DirectoryIterator {
    Object _this;
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
    Variant getPath();
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
    Variant getFileInfo(const Variant &_class = {});
    Variant getPathInfo(const Variant &_class = {});
    Variant openFile(const Variant &mode = "r", const Variant &use_include_path = false, const Variant &context = {});
    Variant setFileClass(const Variant &_class = "SplFileObject");
    Variant setInfoClass(const Variant &_class = "SplFileInfo");
    Variant __debugInfo();
    Variant _bad_state_ex();
};

class FilesystemIterator {
    Object _this;
  public:
    FilesystemIterator(const Variant &directory, const Variant &flags = 4096);
    Variant rewind();
    Variant key();
    Variant current();
    Variant getFlags();
    Variant setFlags(const Variant &flags);
    Variant getFilename();
    Variant getExtension();
    Variant getBasename(const Variant &suffix = "");
    Variant isDot();
    Variant valid();
    Variant next();
    Variant seek(const Variant &offset);
    Variant __toString();
    Variant getPath();
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
    Variant getFileInfo(const Variant &_class = {});
    Variant getPathInfo(const Variant &_class = {});
    Variant openFile(const Variant &mode = "r", const Variant &use_include_path = false, const Variant &context = {});
    Variant setFileClass(const Variant &_class = "SplFileObject");
    Variant setInfoClass(const Variant &_class = "SplFileInfo");
    Variant __debugInfo();
    Variant _bad_state_ex();
};

class RecursiveDirectoryIterator {
    Object _this;
  public:
    RecursiveDirectoryIterator(const Variant &directory, const Variant &flags = 0);
    Variant hasChildren(const Variant &allow_links = false);
    Variant getChildren();
    Variant getSubPath();
    Variant getSubPathname();
    Variant rewind();
    Variant key();
    Variant current();
    Variant getFlags();
    Variant setFlags(const Variant &flags);
    Variant getFilename();
    Variant getExtension();
    Variant getBasename(const Variant &suffix = "");
    Variant isDot();
    Variant valid();
    Variant next();
    Variant seek(const Variant &offset);
    Variant __toString();
    Variant getPath();
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
    Variant getFileInfo(const Variant &_class = {});
    Variant getPathInfo(const Variant &_class = {});
    Variant openFile(const Variant &mode = "r", const Variant &use_include_path = false, const Variant &context = {});
    Variant setFileClass(const Variant &_class = "SplFileObject");
    Variant setInfoClass(const Variant &_class = "SplFileInfo");
    Variant __debugInfo();
    Variant _bad_state_ex();
};

class GlobIterator {
    Object _this;
  public:
    GlobIterator(const Variant &pattern, const Variant &flags = 0);
    Variant count();
    Variant rewind();
    Variant key();
    Variant current();
    Variant getFlags();
    Variant setFlags(const Variant &flags);
    Variant getFilename();
    Variant getExtension();
    Variant getBasename(const Variant &suffix = "");
    Variant isDot();
    Variant valid();
    Variant next();
    Variant seek(const Variant &offset);
    Variant __toString();
    Variant getPath();
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
    Variant getFileInfo(const Variant &_class = {});
    Variant getPathInfo(const Variant &_class = {});
    Variant openFile(const Variant &mode = "r", const Variant &use_include_path = false, const Variant &context = {});
    Variant setFileClass(const Variant &_class = "SplFileObject");
    Variant setInfoClass(const Variant &_class = "SplFileInfo");
    Variant __debugInfo();
    Variant _bad_state_ex();
};

class SplFileObject {
    Object _this;
  public:
    SplFileObject(const Variant &filename, const Variant &mode = "r", const Variant &use_include_path = false, const Variant &context = {});
    Variant rewind();
    Variant eof();
    Variant valid();
    Variant fgets();
    Variant fread(const Variant &length);
    Variant fgetcsv(const Variant &separator = ",", const Variant &enclosure = "\"", const Variant &escape = "\\");
    Variant fputcsv(const Variant &fields, const Variant &separator = ",", const Variant &enclosure = "\"", const Variant &escape = "\\", const Variant &eol = "\n");
    Variant setCsvControl(const Variant &separator = ",", const Variant &enclosure = "\"", const Variant &escape = "\\");
    Variant getCsvControl();
    Variant flock(const Variant &operation, const Variant &would_block = {});
    Variant fflush();
    Variant ftell();
    Variant fseek(const Variant &offset, const Variant &whence = 0);
    Variant fgetc();
    Variant fpassthru();
    Variant fscanf(const Variant &format, const Variant &vars = {});
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
    Variant getFileInfo(const Variant &_class = {});
    Variant getPathInfo(const Variant &_class = {});
    Variant openFile(const Variant &mode = "r", const Variant &use_include_path = false, const Variant &context = {});
    Variant setFileClass(const Variant &_class = "SplFileObject");
    Variant setInfoClass(const Variant &_class = "SplFileInfo");
    Variant __debugInfo();
    Variant _bad_state_ex();
};

class SplTempFileObject {
    Object _this;
  public:
    SplTempFileObject(const Variant &max_memory = 2097152);
    Variant rewind();
    Variant eof();
    Variant valid();
    Variant fgets();
    Variant fread(const Variant &length);
    Variant fgetcsv(const Variant &separator = ",", const Variant &enclosure = "\"", const Variant &escape = "\\");
    Variant fputcsv(const Variant &fields, const Variant &separator = ",", const Variant &enclosure = "\"", const Variant &escape = "\\", const Variant &eol = "\n");
    Variant setCsvControl(const Variant &separator = ",", const Variant &enclosure = "\"", const Variant &escape = "\\");
    Variant getCsvControl();
    Variant flock(const Variant &operation, const Variant &would_block = {});
    Variant fflush();
    Variant ftell();
    Variant fseek(const Variant &offset, const Variant &whence = 0);
    Variant fgetc();
    Variant fpassthru();
    Variant fscanf(const Variant &format, const Variant &vars = {});
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
    Variant getFileInfo(const Variant &_class = {});
    Variant getPathInfo(const Variant &_class = {});
    Variant openFile(const Variant &mode = "r", const Variant &use_include_path = false, const Variant &context = {});
    Variant setFileClass(const Variant &_class = "SplFileObject");
    Variant setInfoClass(const Variant &_class = "SplFileInfo");
    Variant __debugInfo();
    Variant _bad_state_ex();
};

class SplDoublyLinkedList {
    Object _this;
  public:
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

class SplQueue {
    Object _this;
  public:
    Variant enqueue(const Variant &value);
    Variant dequeue();
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

class SplStack {
    Object _this;
  public:
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

class SplMinHeap {
    Object _this;
  public:
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
    Object _this;
  public:
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
    Object _this;
  public:
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
    Object _this;
  public:
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
    Object _this;
  public:
    Variant attach(const Variant &object, const Variant &info = {});
    Variant detach(const Variant &object);
    Variant contains(const Variant &object);
    Variant addAll(const Variant &storage);
    Variant removeAll(const Variant &storage);
    Variant removeAllExcept(const Variant &storage);
    Variant getInfo();
    Variant setInfo(const Variant &info);
    Variant count(const Variant &mode = 0);
    Variant rewind();
    Variant valid();
    Variant key();
    Variant current();
    Variant next();
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
    Object _this;
  public:
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

}

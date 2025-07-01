namespace php {
class LogicException {
  private:
    Variant _this;
  public:
    LogicException(const std::initializer_list<Variant> &args);
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
  private:
    Variant _this;
  public:
    BadFunctionCallException(const std::initializer_list<Variant> &args);
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
  private:
    Variant _this;
  public:
    BadMethodCallException(const std::initializer_list<Variant> &args);
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
  private:
    Variant _this;
  public:
    DomainException(const std::initializer_list<Variant> &args);
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
  private:
    Variant _this;
  public:
    InvalidArgumentException(const std::initializer_list<Variant> &args);
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
  private:
    Variant _this;
  public:
    LengthException(const std::initializer_list<Variant> &args);
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
  private:
    Variant _this;
  public:
    OutOfRangeException(const std::initializer_list<Variant> &args);
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
  private:
    Variant _this;
  public:
    RuntimeException(const std::initializer_list<Variant> &args);
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
  private:
    Variant _this;
  public:
    OutOfBoundsException(const std::initializer_list<Variant> &args);
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
  private:
    Variant _this;
  public:
    OverflowException(const std::initializer_list<Variant> &args);
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
  private:
    Variant _this;
  public:
    RangeException(const std::initializer_list<Variant> &args);
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
  private:
    Variant _this;
  public:
    UnderflowException(const std::initializer_list<Variant> &args);
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
  private:
    Variant _this;
  public:
    UnexpectedValueException(const std::initializer_list<Variant> &args);
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
  private:
    Variant _this;
  public:
    RecursiveIteratorIterator(const std::initializer_list<Variant> &args);
    Variant rewind();
    Variant valid();
    Variant key();
    Variant current();
    Variant next();
    Variant getDepth();
    Variant getSubIterator(const std::initializer_list<Variant> &args);
    Variant getInnerIterator();
    Variant beginIteration();
    Variant endIteration();
    Variant callHasChildren();
    Variant callGetChildren();
    Variant beginChildren();
    Variant endChildren();
    Variant nextElement();
    Variant setMaxDepth(const std::initializer_list<Variant> &args);
    Variant getMaxDepth();
};

class IteratorIterator {
  private:
    Variant _this;
  public:
    IteratorIterator(const std::initializer_list<Variant> &args);
    Variant getInnerIterator();
    Variant rewind();
    Variant valid();
    Variant key();
    Variant current();
    Variant next();
};

class CallbackFilterIterator {
  private:
    Variant _this;
  public:
    CallbackFilterIterator(const std::initializer_list<Variant> &args);
    Variant accept();
    Variant rewind();
    Variant next();
    Variant getInnerIterator();
    Variant valid();
    Variant key();
    Variant current();
};

class RecursiveCallbackFilterIterator {
  private:
    Variant _this;
  public:
    RecursiveCallbackFilterIterator(const std::initializer_list<Variant> &args);
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
  private:
    Variant _this;
  public:
    ParentIterator(const std::initializer_list<Variant> &args);
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
  private:
    Variant _this;
  public:
    LimitIterator(const std::initializer_list<Variant> &args);
    Variant rewind();
    Variant valid();
    Variant next();
    Variant seek(const std::initializer_list<Variant> &args);
    Variant getPosition();
    Variant getInnerIterator();
    Variant key();
    Variant current();
};

class CachingIterator {
  private:
    Variant _this;
  public:
    CachingIterator(const std::initializer_list<Variant> &args);
    Variant rewind();
    Variant valid();
    Variant next();
    Variant hasNext();
    Variant __toString();
    Variant getFlags();
    Variant setFlags(const std::initializer_list<Variant> &args);
    Variant offsetGet(const std::initializer_list<Variant> &args);
    Variant offsetSet(const std::initializer_list<Variant> &args);
    Variant offsetUnset(const std::initializer_list<Variant> &args);
    Variant offsetExists(const std::initializer_list<Variant> &args);
    Variant getCache();
    Variant count();
    Variant getInnerIterator();
    Variant key();
    Variant current();
};

class RecursiveCachingIterator {
  private:
    Variant _this;
  public:
    RecursiveCachingIterator(const std::initializer_list<Variant> &args);
    Variant hasChildren();
    Variant getChildren();
    Variant rewind();
    Variant valid();
    Variant next();
    Variant hasNext();
    Variant __toString();
    Variant getFlags();
    Variant setFlags(const std::initializer_list<Variant> &args);
    Variant offsetGet(const std::initializer_list<Variant> &args);
    Variant offsetSet(const std::initializer_list<Variant> &args);
    Variant offsetUnset(const std::initializer_list<Variant> &args);
    Variant offsetExists(const std::initializer_list<Variant> &args);
    Variant getCache();
    Variant count();
    Variant getInnerIterator();
    Variant key();
    Variant current();
};

class NoRewindIterator {
  private:
    Variant _this;
  public:
    NoRewindIterator(const std::initializer_list<Variant> &args);
    Variant rewind();
    Variant valid();
    Variant key();
    Variant current();
    Variant next();
    Variant getInnerIterator();
};

class AppendIterator {
  private:
    Variant _this;
  public:
    AppendIterator();
    Variant append(const std::initializer_list<Variant> &args);
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
  private:
    Variant _this;
  public:
    InfiniteIterator(const std::initializer_list<Variant> &args);
    Variant next();
    Variant getInnerIterator();
    Variant rewind();
    Variant valid();
    Variant key();
    Variant current();
};

class RegexIterator {
  private:
    Variant _this;
  public:
    RegexIterator(const std::initializer_list<Variant> &args);
    Variant accept();
    Variant getMode();
    Variant setMode(const std::initializer_list<Variant> &args);
    Variant getFlags();
    Variant setFlags(const std::initializer_list<Variant> &args);
    Variant getRegex();
    Variant getPregFlags();
    Variant setPregFlags(const std::initializer_list<Variant> &args);
    Variant rewind();
    Variant next();
    Variant getInnerIterator();
    Variant valid();
    Variant key();
    Variant current();
};

class RecursiveRegexIterator {
  private:
    Variant _this;
  public:
    RecursiveRegexIterator(const std::initializer_list<Variant> &args);
    Variant accept();
    Variant hasChildren();
    Variant getChildren();
    Variant getMode();
    Variant setMode(const std::initializer_list<Variant> &args);
    Variant getFlags();
    Variant setFlags(const std::initializer_list<Variant> &args);
    Variant getRegex();
    Variant getPregFlags();
    Variant setPregFlags(const std::initializer_list<Variant> &args);
    Variant rewind();
    Variant next();
    Variant getInnerIterator();
    Variant valid();
    Variant key();
    Variant current();
};

class EmptyIterator {
  private:
    Variant _this;
  public:
    Variant current();
    Variant next();
    Variant key();
    Variant valid();
    Variant rewind();
};

class RecursiveTreeIterator {
  private:
    Variant _this;
  public:
    RecursiveTreeIterator(const std::initializer_list<Variant> &args);
    Variant key();
    Variant current();
    Variant getPrefix();
    Variant setPostfix(const std::initializer_list<Variant> &args);
    Variant setPrefixPart(const std::initializer_list<Variant> &args);
    Variant getEntry();
    Variant getPostfix();
    Variant rewind();
    Variant valid();
    Variant next();
    Variant getDepth();
    Variant getSubIterator(const std::initializer_list<Variant> &args);
    Variant getInnerIterator();
    Variant beginIteration();
    Variant endIteration();
    Variant callHasChildren();
    Variant callGetChildren();
    Variant beginChildren();
    Variant endChildren();
    Variant nextElement();
    Variant setMaxDepth(const std::initializer_list<Variant> &args);
    Variant getMaxDepth();
};

class ArrayObject {
  private:
    Variant _this;
  public:
    ArrayObject(const std::initializer_list<Variant> &args);
    Variant offsetExists(const std::initializer_list<Variant> &args);
    Variant offsetGet(const std::initializer_list<Variant> &args);
    Variant offsetSet(const std::initializer_list<Variant> &args);
    Variant offsetUnset(const std::initializer_list<Variant> &args);
    Variant append(const std::initializer_list<Variant> &args);
    Variant getArrayCopy();
    Variant count();
    Variant getFlags();
    Variant setFlags(const std::initializer_list<Variant> &args);
    Variant asort(const std::initializer_list<Variant> &args);
    Variant ksort(const std::initializer_list<Variant> &args);
    Variant uasort(const std::initializer_list<Variant> &args);
    Variant uksort(const std::initializer_list<Variant> &args);
    Variant natsort();
    Variant natcasesort();
    Variant unserialize(const std::initializer_list<Variant> &args);
    Variant serialize();
    Variant __serialize();
    Variant __unserialize(const std::initializer_list<Variant> &args);
    Variant getIterator();
    Variant exchangeArray(const std::initializer_list<Variant> &args);
    Variant setIteratorClass(const std::initializer_list<Variant> &args);
    Variant getIteratorClass();
    Variant __debugInfo();
};

class _ArrayIterator {
  private:
    Variant _this;
  public:
    _ArrayIterator(const std::initializer_list<Variant> &args);
    Variant offsetExists(const std::initializer_list<Variant> &args);
    Variant offsetGet(const std::initializer_list<Variant> &args);
    Variant offsetSet(const std::initializer_list<Variant> &args);
    Variant offsetUnset(const std::initializer_list<Variant> &args);
    Variant append(const std::initializer_list<Variant> &args);
    Variant getArrayCopy();
    Variant count();
    Variant getFlags();
    Variant setFlags(const std::initializer_list<Variant> &args);
    Variant asort(const std::initializer_list<Variant> &args);
    Variant ksort(const std::initializer_list<Variant> &args);
    Variant uasort(const std::initializer_list<Variant> &args);
    Variant uksort(const std::initializer_list<Variant> &args);
    Variant natsort();
    Variant natcasesort();
    Variant unserialize(const std::initializer_list<Variant> &args);
    Variant serialize();
    Variant __serialize();
    Variant __unserialize(const std::initializer_list<Variant> &args);
    Variant rewind();
    Variant current();
    Variant key();
    Variant next();
    Variant valid();
    Variant seek(const std::initializer_list<Variant> &args);
    Variant __debugInfo();
};

class RecursiveArrayIterator {
  private:
    Variant _this;
  public:
    Variant hasChildren();
    Variant getChildren();
    RecursiveArrayIterator(const std::initializer_list<Variant> &args);
    Variant offsetExists(const std::initializer_list<Variant> &args);
    Variant offsetGet(const std::initializer_list<Variant> &args);
    Variant offsetSet(const std::initializer_list<Variant> &args);
    Variant offsetUnset(const std::initializer_list<Variant> &args);
    Variant append(const std::initializer_list<Variant> &args);
    Variant getArrayCopy();
    Variant count();
    Variant getFlags();
    Variant setFlags(const std::initializer_list<Variant> &args);
    Variant asort(const std::initializer_list<Variant> &args);
    Variant ksort(const std::initializer_list<Variant> &args);
    Variant uasort(const std::initializer_list<Variant> &args);
    Variant uksort(const std::initializer_list<Variant> &args);
    Variant natsort();
    Variant natcasesort();
    Variant unserialize(const std::initializer_list<Variant> &args);
    Variant serialize();
    Variant __serialize();
    Variant __unserialize(const std::initializer_list<Variant> &args);
    Variant rewind();
    Variant current();
    Variant key();
    Variant next();
    Variant valid();
    Variant seek(const std::initializer_list<Variant> &args);
    Variant __debugInfo();
};

class SplFileInfo {
  private:
    Variant _this;
  public:
    SplFileInfo(const std::initializer_list<Variant> &args);
    Variant getPath();
    Variant getFilename();
    Variant getExtension();
    Variant getBasename(const std::initializer_list<Variant> &args);
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
    Variant getFileInfo(const std::initializer_list<Variant> &args);
    Variant getPathInfo(const std::initializer_list<Variant> &args);
    Variant openFile(const std::initializer_list<Variant> &args);
    Variant setFileClass(const std::initializer_list<Variant> &args);
    Variant setInfoClass(const std::initializer_list<Variant> &args);
    Variant __toString();
    Variant __debugInfo();
    Variant _bad_state_ex();
};

class DirectoryIterator {
  private:
    Variant _this;
  public:
    DirectoryIterator(const std::initializer_list<Variant> &args);
    Variant getFilename();
    Variant getExtension();
    Variant getBasename(const std::initializer_list<Variant> &args);
    Variant isDot();
    Variant rewind();
    Variant valid();
    Variant key();
    Variant current();
    Variant next();
    Variant seek(const std::initializer_list<Variant> &args);
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
    Variant getFileInfo(const std::initializer_list<Variant> &args);
    Variant getPathInfo(const std::initializer_list<Variant> &args);
    Variant openFile(const std::initializer_list<Variant> &args);
    Variant setFileClass(const std::initializer_list<Variant> &args);
    Variant setInfoClass(const std::initializer_list<Variant> &args);
    Variant __debugInfo();
    Variant _bad_state_ex();
};

class FilesystemIterator {
  private:
    Variant _this;
  public:
    FilesystemIterator(const std::initializer_list<Variant> &args);
    Variant rewind();
    Variant key();
    Variant current();
    Variant getFlags();
    Variant setFlags(const std::initializer_list<Variant> &args);
    Variant getFilename();
    Variant getExtension();
    Variant getBasename(const std::initializer_list<Variant> &args);
    Variant isDot();
    Variant valid();
    Variant next();
    Variant seek(const std::initializer_list<Variant> &args);
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
    Variant getFileInfo(const std::initializer_list<Variant> &args);
    Variant getPathInfo(const std::initializer_list<Variant> &args);
    Variant openFile(const std::initializer_list<Variant> &args);
    Variant setFileClass(const std::initializer_list<Variant> &args);
    Variant setInfoClass(const std::initializer_list<Variant> &args);
    Variant __debugInfo();
    Variant _bad_state_ex();
};

class RecursiveDirectoryIterator {
  private:
    Variant _this;
  public:
    RecursiveDirectoryIterator(const std::initializer_list<Variant> &args);
    Variant hasChildren(const std::initializer_list<Variant> &args);
    Variant getChildren();
    Variant getSubPath();
    Variant getSubPathname();
    Variant rewind();
    Variant key();
    Variant current();
    Variant getFlags();
    Variant setFlags(const std::initializer_list<Variant> &args);
    Variant getFilename();
    Variant getExtension();
    Variant getBasename(const std::initializer_list<Variant> &args);
    Variant isDot();
    Variant valid();
    Variant next();
    Variant seek(const std::initializer_list<Variant> &args);
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
    Variant getFileInfo(const std::initializer_list<Variant> &args);
    Variant getPathInfo(const std::initializer_list<Variant> &args);
    Variant openFile(const std::initializer_list<Variant> &args);
    Variant setFileClass(const std::initializer_list<Variant> &args);
    Variant setInfoClass(const std::initializer_list<Variant> &args);
    Variant __debugInfo();
    Variant _bad_state_ex();
};

class GlobIterator {
  private:
    Variant _this;
  public:
    GlobIterator(const std::initializer_list<Variant> &args);
    Variant count();
    Variant rewind();
    Variant key();
    Variant current();
    Variant getFlags();
    Variant setFlags(const std::initializer_list<Variant> &args);
    Variant getFilename();
    Variant getExtension();
    Variant getBasename(const std::initializer_list<Variant> &args);
    Variant isDot();
    Variant valid();
    Variant next();
    Variant seek(const std::initializer_list<Variant> &args);
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
    Variant getFileInfo(const std::initializer_list<Variant> &args);
    Variant getPathInfo(const std::initializer_list<Variant> &args);
    Variant openFile(const std::initializer_list<Variant> &args);
    Variant setFileClass(const std::initializer_list<Variant> &args);
    Variant setInfoClass(const std::initializer_list<Variant> &args);
    Variant __debugInfo();
    Variant _bad_state_ex();
};

class SplFileObject {
  private:
    Variant _this;
  public:
    SplFileObject(const std::initializer_list<Variant> &args);
    Variant rewind();
    Variant eof();
    Variant valid();
    Variant fgets();
    Variant fread(const std::initializer_list<Variant> &args);
    Variant fgetcsv(const std::initializer_list<Variant> &args);
    Variant fputcsv(const std::initializer_list<Variant> &args);
    Variant setCsvControl(const std::initializer_list<Variant> &args);
    Variant getCsvControl();
    Variant flock(const std::initializer_list<Variant> &args);
    Variant fflush();
    Variant ftell();
    Variant fseek(const std::initializer_list<Variant> &args);
    Variant fgetc();
    Variant fpassthru();
    Variant fscanf(const std::initializer_list<Variant> &args);
    Variant fwrite(const std::initializer_list<Variant> &args);
    Variant fstat();
    Variant ftruncate(const std::initializer_list<Variant> &args);
    Variant current();
    Variant key();
    Variant next();
    Variant setFlags(const std::initializer_list<Variant> &args);
    Variant getFlags();
    Variant setMaxLineLen(const std::initializer_list<Variant> &args);
    Variant getMaxLineLen();
    Variant hasChildren();
    Variant getChildren();
    Variant seek(const std::initializer_list<Variant> &args);
    Variant getCurrentLine();
    Variant __toString();
    Variant getPath();
    Variant getFilename();
    Variant getExtension();
    Variant getBasename(const std::initializer_list<Variant> &args);
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
    Variant getFileInfo(const std::initializer_list<Variant> &args);
    Variant getPathInfo(const std::initializer_list<Variant> &args);
    Variant openFile(const std::initializer_list<Variant> &args);
    Variant setFileClass(const std::initializer_list<Variant> &args);
    Variant setInfoClass(const std::initializer_list<Variant> &args);
    Variant __debugInfo();
    Variant _bad_state_ex();
};

class SplTempFileObject {
  private:
    Variant _this;
  public:
    SplTempFileObject(const std::initializer_list<Variant> &args);
    Variant rewind();
    Variant eof();
    Variant valid();
    Variant fgets();
    Variant fread(const std::initializer_list<Variant> &args);
    Variant fgetcsv(const std::initializer_list<Variant> &args);
    Variant fputcsv(const std::initializer_list<Variant> &args);
    Variant setCsvControl(const std::initializer_list<Variant> &args);
    Variant getCsvControl();
    Variant flock(const std::initializer_list<Variant> &args);
    Variant fflush();
    Variant ftell();
    Variant fseek(const std::initializer_list<Variant> &args);
    Variant fgetc();
    Variant fpassthru();
    Variant fscanf(const std::initializer_list<Variant> &args);
    Variant fwrite(const std::initializer_list<Variant> &args);
    Variant fstat();
    Variant ftruncate(const std::initializer_list<Variant> &args);
    Variant current();
    Variant key();
    Variant next();
    Variant setFlags(const std::initializer_list<Variant> &args);
    Variant getFlags();
    Variant setMaxLineLen(const std::initializer_list<Variant> &args);
    Variant getMaxLineLen();
    Variant hasChildren();
    Variant getChildren();
    Variant seek(const std::initializer_list<Variant> &args);
    Variant getCurrentLine();
    Variant __toString();
    Variant getPath();
    Variant getFilename();
    Variant getExtension();
    Variant getBasename(const std::initializer_list<Variant> &args);
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
    Variant getFileInfo(const std::initializer_list<Variant> &args);
    Variant getPathInfo(const std::initializer_list<Variant> &args);
    Variant openFile(const std::initializer_list<Variant> &args);
    Variant setFileClass(const std::initializer_list<Variant> &args);
    Variant setInfoClass(const std::initializer_list<Variant> &args);
    Variant __debugInfo();
    Variant _bad_state_ex();
};

class SplDoublyLinkedList {
  private:
    Variant _this;
  public:
    Variant add(const std::initializer_list<Variant> &args);
    Variant pop();
    Variant shift();
    Variant push(const std::initializer_list<Variant> &args);
    Variant unshift(const std::initializer_list<Variant> &args);
    Variant top();
    Variant bottom();
    Variant __debugInfo();
    Variant count();
    Variant isEmpty();
    Variant setIteratorMode(const std::initializer_list<Variant> &args);
    Variant getIteratorMode();
    Variant offsetExists(const std::initializer_list<Variant> &args);
    Variant offsetGet(const std::initializer_list<Variant> &args);
    Variant offsetSet(const std::initializer_list<Variant> &args);
    Variant offsetUnset(const std::initializer_list<Variant> &args);
    Variant rewind();
    Variant current();
    Variant key();
    Variant prev();
    Variant next();
    Variant valid();
    Variant unserialize(const std::initializer_list<Variant> &args);
    Variant serialize();
    Variant __serialize();
    Variant __unserialize(const std::initializer_list<Variant> &args);
};

class SplQueue {
  private:
    Variant _this;
  public:
    Variant enqueue(const std::initializer_list<Variant> &args);
    Variant dequeue();
    Variant add(const std::initializer_list<Variant> &args);
    Variant pop();
    Variant shift();
    Variant push(const std::initializer_list<Variant> &args);
    Variant unshift(const std::initializer_list<Variant> &args);
    Variant top();
    Variant bottom();
    Variant __debugInfo();
    Variant count();
    Variant isEmpty();
    Variant setIteratorMode(const std::initializer_list<Variant> &args);
    Variant getIteratorMode();
    Variant offsetExists(const std::initializer_list<Variant> &args);
    Variant offsetGet(const std::initializer_list<Variant> &args);
    Variant offsetSet(const std::initializer_list<Variant> &args);
    Variant offsetUnset(const std::initializer_list<Variant> &args);
    Variant rewind();
    Variant current();
    Variant key();
    Variant prev();
    Variant next();
    Variant valid();
    Variant unserialize(const std::initializer_list<Variant> &args);
    Variant serialize();
    Variant __serialize();
    Variant __unserialize(const std::initializer_list<Variant> &args);
};

class SplStack {
  private:
    Variant _this;
  public:
    Variant add(const std::initializer_list<Variant> &args);
    Variant pop();
    Variant shift();
    Variant push(const std::initializer_list<Variant> &args);
    Variant unshift(const std::initializer_list<Variant> &args);
    Variant top();
    Variant bottom();
    Variant __debugInfo();
    Variant count();
    Variant isEmpty();
    Variant setIteratorMode(const std::initializer_list<Variant> &args);
    Variant getIteratorMode();
    Variant offsetExists(const std::initializer_list<Variant> &args);
    Variant offsetGet(const std::initializer_list<Variant> &args);
    Variant offsetSet(const std::initializer_list<Variant> &args);
    Variant offsetUnset(const std::initializer_list<Variant> &args);
    Variant rewind();
    Variant current();
    Variant key();
    Variant prev();
    Variant next();
    Variant valid();
    Variant unserialize(const std::initializer_list<Variant> &args);
    Variant serialize();
    Variant __serialize();
    Variant __unserialize(const std::initializer_list<Variant> &args);
};

class SplMinHeap {
  private:
    Variant _this;
  public:
    Variant extract();
    Variant insert(const std::initializer_list<Variant> &args);
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
  private:
    Variant _this;
  public:
    Variant extract();
    Variant insert(const std::initializer_list<Variant> &args);
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
  private:
    Variant _this;
  public:
    Variant compare(const std::initializer_list<Variant> &args);
    Variant insert(const std::initializer_list<Variant> &args);
    Variant setExtractFlags(const std::initializer_list<Variant> &args);
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
  private:
    Variant _this;
  public:
    SplFixedArray(const std::initializer_list<Variant> &args);
    Variant __wakeup();
    Variant __serialize();
    Variant __unserialize(const std::initializer_list<Variant> &args);
    Variant count();
    Variant toArray();
    static Variant fromArray(const std::initializer_list<Variant> &args);
    Variant getSize();
    Variant setSize(const std::initializer_list<Variant> &args);
    Variant offsetExists(const std::initializer_list<Variant> &args);
    Variant offsetGet(const std::initializer_list<Variant> &args);
    Variant offsetSet(const std::initializer_list<Variant> &args);
    Variant offsetUnset(const std::initializer_list<Variant> &args);
    Variant getIterator();
    Variant jsonSerialize();
};

class SplObjectStorage {
  private:
    Variant _this;
  public:
    Variant attach(const std::initializer_list<Variant> &args);
    Variant detach(const std::initializer_list<Variant> &args);
    Variant contains(const std::initializer_list<Variant> &args);
    Variant addAll(const std::initializer_list<Variant> &args);
    Variant removeAll(const std::initializer_list<Variant> &args);
    Variant removeAllExcept(const std::initializer_list<Variant> &args);
    Variant getInfo();
    Variant setInfo(const std::initializer_list<Variant> &args);
    Variant count(const std::initializer_list<Variant> &args);
    Variant rewind();
    Variant valid();
    Variant key();
    Variant current();
    Variant next();
    Variant unserialize(const std::initializer_list<Variant> &args);
    Variant serialize();
    Variant offsetExists(const std::initializer_list<Variant> &args);
    Variant offsetGet(const std::initializer_list<Variant> &args);
    Variant offsetSet(const std::initializer_list<Variant> &args);
    Variant offsetUnset(const std::initializer_list<Variant> &args);
    Variant getHash(const std::initializer_list<Variant> &args);
    Variant __serialize();
    Variant __unserialize(const std::initializer_list<Variant> &args);
    Variant __debugInfo();
};

class MultipleIterator {
  private:
    Variant _this;
  public:
    MultipleIterator(const std::initializer_list<Variant> &args);
    Variant getFlags();
    Variant setFlags(const std::initializer_list<Variant> &args);
    Variant attachIterator(const std::initializer_list<Variant> &args);
    Variant detachIterator(const std::initializer_list<Variant> &args);
    Variant containsIterator(const std::initializer_list<Variant> &args);
    Variant countIterators();
    Variant rewind();
    Variant valid();
    Variant key();
    Variant current();
    Variant next();
    Variant __debugInfo();
};

}

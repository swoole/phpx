#pragma once

#include "phpx.h"
#include "phpx_literal_string.h"

namespace php {
class ZipArchive;

class ZipArchive {
  protected:
    Object this_;

  public:
    Object getObject() const {
        return this_;
    }
    explicit ZipArchive(const Object &obj) : this_(obj) {}
    static constexpr int CREATE = 1;
    static constexpr int EXCL = 2;
    static constexpr int CHECKCONS = 4;
    static constexpr int OVERWRITE = 8;
    static constexpr int RDONLY = 16;
    static constexpr int FL_NOCASE = 1;
    static constexpr int FL_NODIR = 2;
    static constexpr int FL_COMPRESSED = 4;
    static constexpr int FL_UNCHANGED = 8;
    static constexpr int FL_RECOMPRESS = 16;
    static constexpr int FL_ENCRYPTED = 32;
    static constexpr int FL_OVERWRITE = 8192;
    static constexpr int FL_LOCAL = 256;
    static constexpr int FL_CENTRAL = 512;
    static constexpr int FL_ENC_GUESS = 0;
    static constexpr int FL_ENC_RAW = 64;
    static constexpr int FL_ENC_STRICT = 128;
    static constexpr int FL_ENC_UTF_8 = 2048;
    static constexpr int FL_ENC_CP437 = 4096;
    static constexpr int FL_OPEN_FILE_NOW = 1073741824;
    static constexpr int CM_DEFAULT = -1;
    static constexpr int CM_STORE = 0;
    static constexpr int CM_SHRINK = 1;
    static constexpr int CM_REDUCE_1 = 2;
    static constexpr int CM_REDUCE_2 = 3;
    static constexpr int CM_REDUCE_3 = 4;
    static constexpr int CM_REDUCE_4 = 5;
    static constexpr int CM_IMPLODE = 6;
    static constexpr int CM_DEFLATE = 8;
    static constexpr int CM_DEFLATE64 = 9;
    static constexpr int CM_PKWARE_IMPLODE = 10;
    static constexpr int CM_BZIP2 = 12;
    static constexpr int CM_LZMA = 14;
    static constexpr int CM_LZMA2 = 33;
    static constexpr int CM_XZ = 95;
    static constexpr int CM_TERSE = 18;
    static constexpr int CM_LZ77 = 19;
    static constexpr int CM_WAVPACK = 97;
    static constexpr int CM_PPMD = 98;
    static constexpr int ER_OK = 0;
    static constexpr int ER_MULTIDISK = 1;
    static constexpr int ER_RENAME = 2;
    static constexpr int ER_CLOSE = 3;
    static constexpr int ER_SEEK = 4;
    static constexpr int ER_READ = 5;
    static constexpr int ER_WRITE = 6;
    static constexpr int ER_CRC = 7;
    static constexpr int ER_ZIPCLOSED = 8;
    static constexpr int ER_NOENT = 9;
    static constexpr int ER_EXISTS = 10;
    static constexpr int ER_OPEN = 11;
    static constexpr int ER_TMPOPEN = 12;
    static constexpr int ER_ZLIB = 13;
    static constexpr int ER_MEMORY = 14;
    static constexpr int ER_CHANGED = 15;
    static constexpr int ER_COMPNOTSUPP = 16;
    static constexpr int ER_EOF = 17;
    static constexpr int ER_INVAL = 18;
    static constexpr int ER_NOZIP = 19;
    static constexpr int ER_INTERNAL = 20;
    static constexpr int ER_INCONS = 21;
    static constexpr int ER_REMOVE = 22;
    static constexpr int ER_DELETED = 23;
    static constexpr int ER_ENCRNOTSUPP = 24;
    static constexpr int ER_RDONLY = 25;
    static constexpr int ER_NOPASSWD = 26;
    static constexpr int ER_WRONGPASSWD = 27;
    static constexpr int ER_OPNOTSUPP = 28;
    static constexpr int ER_INUSE = 29;
    static constexpr int ER_TELL = 30;
    static constexpr int ER_COMPRESSED_DATA = 31;
    static constexpr int ER_CANCELLED = 32;
    static constexpr int AFL_RDONLY = 2;
    static constexpr int OPSYS_DOS = 0;
    static constexpr int OPSYS_AMIGA = 1;
    static constexpr int OPSYS_OPENVMS = 2;
    static constexpr int OPSYS_UNIX = 3;
    static constexpr int OPSYS_VM_CMS = 4;
    static constexpr int OPSYS_ATARI_ST = 5;
    static constexpr int OPSYS_OS_2 = 6;
    static constexpr int OPSYS_MACINTOSH = 7;
    static constexpr int OPSYS_Z_SYSTEM = 8;
    static constexpr int OPSYS_CPM = 9;
    static constexpr int OPSYS_WINDOWS_NTFS = 10;
    static constexpr int OPSYS_MVS = 11;
    static constexpr int OPSYS_VSE = 12;
    static constexpr int OPSYS_ACORN_RISC = 13;
    static constexpr int OPSYS_VFAT = 14;
    static constexpr int OPSYS_ALTERNATE_MVS = 15;
    static constexpr int OPSYS_BEOS = 16;
    static constexpr int OPSYS_TANDEM = 17;
    static constexpr int OPSYS_OS_400 = 18;
    static constexpr int OPSYS_OS_X = 19;
    static constexpr int OPSYS_DEFAULT = 3;
    static constexpr int EM_NONE = 0;
    static constexpr int EM_TRAD_PKWARE = 1;
    static constexpr int EM_AES_128 = 257;
    static constexpr int EM_AES_192 = 258;
    static constexpr int EM_AES_256 = 259;
    static constexpr int EM_UNKNOWN = 65535;
    static inline const Variant LIBZIP_VERSION{ZEND_STRL("1.7.3"), true};
    static constexpr int LENGTH_TO_END = 0;

    ZipArchive();
    Variant open(const Variant &filename, const Variant &flags = 0);
    Variant setPassword(const Variant &password);
    Variant close();
    Variant count();
    Variant getStatusString();
    Variant clearError();
    Variant addEmptyDir(const Variant &dirname, const Variant &flags = 0);
    Variant addFromString(const Variant &name, const Variant &content, const Variant &flags = 8192);
    Variant addFile(const Variant &filepath,
                    const Variant &entryname = "",
                    const Variant &start = 0,
                    const Variant &length = 0,
                    const Variant &flags = 8192);
    Variant replaceFile(const Variant &filepath,
                        const Variant &index,
                        const Variant &start = 0,
                        const Variant &length = 0,
                        const Variant &flags = 0);
    Variant addGlob(const Variant &pattern, const Variant &flags = 0, const Variant &options = Array{});
    Variant addPattern(const Variant &pattern, const Variant &path = ".", const Variant &options = Array{});
    Variant renameIndex(const Variant &index, const Variant &new_name);
    Variant renameName(const Variant &name, const Variant &new_name);
    Variant setArchiveComment(const Variant &comment);
    Variant getArchiveComment(const Variant &flags = 0);
    Variant setArchiveFlag(const Variant &flag, const Variant &value);
    Variant getArchiveFlag(const Variant &flag, const Variant &flags = 0);
    Variant setCommentIndex(const Variant &index, const Variant &comment);
    Variant setCommentName(const Variant &name, const Variant &comment);
    Variant setMtimeIndex(const Variant &index, const Variant &timestamp, const Variant &flags = 0);
    Variant setMtimeName(const Variant &name, const Variant &timestamp, const Variant &flags = 0);
    Variant getCommentIndex(const Variant &index, const Variant &flags = 0);
    Variant getCommentName(const Variant &name, const Variant &flags = 0);
    Variant deleteIndex(const Variant &index);
    Variant deleteName(const Variant &name);
    Variant statName(const Variant &name, const Variant &flags = 0);
    Variant statIndex(const Variant &index, const Variant &flags = 0);
    Variant locateName(const Variant &name, const Variant &flags = 0);
    Variant getNameIndex(const Variant &index, const Variant &flags = 0);
    Variant unchangeArchive();
    Variant unchangeAll();
    Variant unchangeIndex(const Variant &index);
    Variant unchangeName(const Variant &name);
    Variant extractTo(const Variant &pathto, const Variant &files = nullptr);
    Variant getFromName(const Variant &name, const Variant &len = 0, const Variant &flags = 0);
    Variant getFromIndex(const Variant &index, const Variant &len = 0, const Variant &flags = 0);
    Variant getStreamIndex(const Variant &index, const Variant &flags = 0);
    Variant getStreamName(const Variant &name, const Variant &flags = 0);
    Variant getStream(const Variant &name);
    Variant setExternalAttributesName(const Variant &name,
                                      const Variant &opsys,
                                      const Variant &attr,
                                      const Variant &flags = 0);
    Variant setExternalAttributesIndex(const Variant &index,
                                       const Variant &opsys,
                                       const Variant &attr,
                                       const Variant &flags = 0);
    Variant getExternalAttributesName(const Variant &name,
                                      const Reference &opsys,
                                      const Reference &attr,
                                      const Variant &flags = 0);
    Variant getExternalAttributesIndex(const Variant &index,
                                       const Reference &opsys,
                                       const Reference &attr,
                                       const Variant &flags = 0);
    Variant setCompressionName(const Variant &name, const Variant &method, const Variant &compflags = 0);
    Variant setCompressionIndex(const Variant &index, const Variant &method, const Variant &compflags = 0);
    Variant setEncryptionName(const Variant &name, const Variant &method, const Variant &password = nullptr);
    Variant setEncryptionIndex(const Variant &index, const Variant &method, const Variant &password = nullptr);
    Variant registerProgressCallback(const Variant &rate, const Variant &callback);
    Variant registerCancelCallback(const Variant &callback);
    static Variant isCompressionMethodSupported(const Variant &method, const Variant &enc = true);
    static Variant isEncryptionMethodSupported(const Variant &method, const Variant &enc = true);
};

}  // namespace php

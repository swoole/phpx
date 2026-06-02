#pragma once

#include "phpx.h"
#include "phpx_literal_string.h"
#include "class/core.h"
#include "class/spl.h"

namespace php {
class PharException;
class PharFileInfo;
class Phar;
class PharData;

class PharException : public Exception {
  public:
    PharException(const Variant &message = "", const Variant &code = 0, const Variant &previous = nullptr);
};

class PharFileInfo : public SplFileInfo {
  protected:
    PharFileInfo() = default;

  public:
    PharFileInfo(const Variant &filename);
    Variant chmod(const Variant &perms);
    Variant compress(const Variant &compression);
    Variant decompress();
    Variant delMetadata();
    Variant getCompressedSize();
    Variant getCRC32();
    Variant getContent();
    Variant getMetadata(const Variant &unserialize_options = Array{});
    Variant getPharFlags();
    Variant hasMetadata();
    Variant isCompressed(const Variant &compression = nullptr);
    Variant isCRCChecked();
    Variant setMetadata(const Variant &metadata);
};

class Phar : public RecursiveDirectoryIterator {
  protected:
    Phar() = default;

  public:
    static constexpr zend_long BZ2 = 8192;
    static constexpr zend_long GZ = 4096;
    static constexpr zend_long NONE = 0;
    static constexpr zend_long PHAR = 1;
    static constexpr zend_long TAR = 2;
    static constexpr zend_long ZIP = 3;
    static constexpr zend_long COMPRESSED = 61440;
    static constexpr zend_long PHP = 0;
    static constexpr zend_long PHPS = 1;
    static constexpr zend_long MD5 = 1;
    static constexpr zend_long OPENSSL = 16;
    static constexpr zend_long OPENSSL_SHA256 = 17;
    static constexpr zend_long OPENSSL_SHA512 = 18;
    static constexpr zend_long SHA1 = 2;
    static constexpr zend_long SHA256 = 3;
    static constexpr zend_long SHA512 = 4;

    Phar(const Variant &filename, const Variant &flags = 12288, const Variant &alias = nullptr);
    Variant addEmptyDir(const Variant &directory);
    Variant addFile(const Variant &filename, const Variant &local_name = nullptr);
    Variant addFromString(const Variant &local_name, const Variant &contents);
    Variant buildFromDirectory(const Variant &directory, const Variant &pattern = "");
    Variant buildFromIterator(const Variant &iterator, const Variant &base_directory = nullptr);
    Variant compressFiles(const Variant &compression);
    Variant decompressFiles();
    Variant compress(const Variant &compression, const Variant &extension = nullptr);
    Variant decompress(const Variant &extension = nullptr);
    Variant convertToExecutable(const Variant &format = nullptr,
                                const Variant &compression = nullptr,
                                const Variant &extension = nullptr);
    Variant convertToData(const Variant &format = nullptr,
                          const Variant &compression = nullptr,
                          const Variant &extension = nullptr);
    Variant copy(const Variant &from, const Variant &to);
    Variant count(const Variant &mode = 0);
    Variant delete_(const Variant &local_name);
    Variant delMetadata();
    Variant extractTo(const Variant &directory, const Variant &files = nullptr, const Variant &overwrite = false);
    Variant getAlias();
    Variant getPath();
    Variant getMetadata(const Variant &unserialize_options = Array{});
    Variant getModified();
    Variant getSignature();
    Variant getStub();
    Variant getVersion();
    Variant hasMetadata();
    Variant isBuffering();
    Variant isCompressed();
    Variant isFileFormat(const Variant &format);
    Variant isWritable();
    Variant offsetExists(const Variant &local_name);
    Variant offsetGet(const Variant &local_name);
    Variant offsetSet(const Variant &local_name, const Variant &value);
    Variant offsetUnset(const Variant &local_name);
    Variant setAlias(const Variant &alias);
    Variant setDefaultStub(const Variant &index = nullptr, const Variant &web_index = nullptr);
    Variant setMetadata(const Variant &metadata);
    Variant setSignatureAlgorithm(const Variant &algo, const Variant &private_key = nullptr);
    Variant setStub(const Variant &stub, const Variant &length = {});
    Variant startBuffering();
    Variant stopBuffering();
    static Variant apiVersion();
    static Variant canCompress(const Variant &compression = 0);
    static Variant canWrite();
    static Variant createDefaultStub(const Variant &index = nullptr, const Variant &web_index = nullptr);
    static Variant getSupportedCompression();
    static Variant getSupportedSignatures();
    static Variant interceptFileFuncs();
    static Variant isValidPharFilename(const Variant &filename, const Variant &executable = true);
    static Variant loadPhar(const Variant &filename, const Variant &alias = nullptr);
    static Variant mapPhar(const Variant &alias = nullptr, const Variant &offset = 0);
    static Variant running(const Variant &return_phar = true);
    static Variant mount(const Variant &phar_path, const Variant &external_path);
    static Variant mungServer(const Variant &variables);
    static Variant unlinkArchive(const Variant &filename);
    static Variant webPhar(const Variant &alias = nullptr,
                           const Variant &index = nullptr,
                           const Variant &file_not_found_script = nullptr,
                           const Variant &mime_types = Array{},
                           const Variant &rewrite = nullptr);
};

class PharData : public RecursiveDirectoryIterator {
  protected:
    PharData() = default;

  public:
    PharData(const Variant &filename,
             const Variant &flags = 12288,
             const Variant &alias = nullptr,
             const Variant &format = 0);
    Variant addEmptyDir(const Variant &directory);
    Variant addFile(const Variant &filename, const Variant &local_name = nullptr);
    Variant addFromString(const Variant &local_name, const Variant &contents);
    Variant buildFromDirectory(const Variant &directory, const Variant &pattern = "");
    Variant buildFromIterator(const Variant &iterator, const Variant &base_directory = nullptr);
    Variant compressFiles(const Variant &compression);
    Variant decompressFiles();
    Variant compress(const Variant &compression, const Variant &extension = nullptr);
    Variant decompress(const Variant &extension = nullptr);
    Variant convertToExecutable(const Variant &format = nullptr,
                                const Variant &compression = nullptr,
                                const Variant &extension = nullptr);
    Variant convertToData(const Variant &format = nullptr,
                          const Variant &compression = nullptr,
                          const Variant &extension = nullptr);
    Variant copy(const Variant &from, const Variant &to);
    Variant count(const Variant &mode = 0);
    Variant delete_(const Variant &local_name);
    Variant delMetadata();
    Variant extractTo(const Variant &directory, const Variant &files = nullptr, const Variant &overwrite = false);
    Variant getAlias();
    Variant getPath();
    Variant getMetadata(const Variant &unserialize_options = Array{});
    Variant getModified();
    Variant getSignature();
    Variant getStub();
    Variant getVersion();
    Variant hasMetadata();
    Variant isBuffering();
    Variant isCompressed();
    Variant isFileFormat(const Variant &format);
    Variant isWritable();
    Variant offsetExists(const Variant &local_name);
    Variant offsetGet(const Variant &local_name);
    Variant offsetSet(const Variant &local_name, const Variant &value);
    Variant offsetUnset(const Variant &local_name);
    Variant setAlias(const Variant &alias);
    Variant setDefaultStub(const Variant &index = nullptr, const Variant &web_index = nullptr);
    Variant setMetadata(const Variant &metadata);
    Variant setSignatureAlgorithm(const Variant &algo, const Variant &private_key = nullptr);
    Variant setStub(const Variant &stub, const Variant &length = {});
    Variant startBuffering();
    Variant stopBuffering();
    static Variant apiVersion();
    static Variant canCompress(const Variant &compression = 0);
    static Variant canWrite();
    static Variant createDefaultStub(const Variant &index = nullptr, const Variant &web_index = nullptr);
    static Variant getSupportedCompression();
    static Variant getSupportedSignatures();
    static Variant interceptFileFuncs();
    static Variant isValidPharFilename(const Variant &filename, const Variant &executable = true);
    static Variant loadPhar(const Variant &filename, const Variant &alias = nullptr);
    static Variant mapPhar(const Variant &alias = nullptr, const Variant &offset = 0);
    static Variant running(const Variant &return_phar = true);
    static Variant mount(const Variant &phar_path, const Variant &external_path);
    static Variant mungServer(const Variant &variables);
    static Variant unlinkArchive(const Variant &filename);
    static Variant webPhar(const Variant &alias = nullptr,
                           const Variant &index = nullptr,
                           const Variant &file_not_found_script = nullptr,
                           const Variant &mime_types = Array{},
                           const Variant &rewrite = nullptr);
};

}  // namespace php

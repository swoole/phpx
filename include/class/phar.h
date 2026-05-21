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
    PharException(const Variant &message = "", const Variant &code = 0, const Variant &previous = {});
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
    Variant isCompressed(const Variant &compression = {});
    Variant isCRCChecked();
    Variant setMetadata(const Variant &metadata);
};

class Phar : public RecursiveDirectoryIterator {
  protected:
    Phar() = default;

  public:
    static constexpr int BZ2 = 8192;
    static constexpr int GZ = 4096;
    static constexpr int NONE = 0;
    static constexpr int PHAR = 1;
    static constexpr int TAR = 2;
    static constexpr int ZIP = 3;
    static constexpr int COMPRESSED = 61440;
    static constexpr int PHP = 0;
    static constexpr int PHPS = 1;
    static constexpr int MD5 = 1;
    static constexpr int OPENSSL = 16;
    static constexpr int OPENSSL_SHA256 = 17;
    static constexpr int OPENSSL_SHA512 = 18;
    static constexpr int SHA1 = 2;
    static constexpr int SHA256 = 3;
    static constexpr int SHA512 = 4;

    Phar(const Variant &filename, const Variant &flags = 12288, const Variant &alias = {});
    Variant addEmptyDir(const Variant &directory);
    Variant addFile(const Variant &filename, const Variant &local_name = {});
    Variant addFromString(const Variant &local_name, const Variant &contents);
    Variant buildFromDirectory(const Variant &directory, const Variant &pattern = "");
    Variant buildFromIterator(const Variant &iterator, const Variant &base_directory = {});
    Variant compressFiles(const Variant &compression);
    Variant decompressFiles();
    Variant compress(const Variant &compression, const Variant &extension = {});
    Variant decompress(const Variant &extension = {});
    Variant convertToExecutable(const Variant &format = {},
                                const Variant &compression = {},
                                const Variant &extension = {});
    Variant convertToData(const Variant &format = {}, const Variant &compression = {}, const Variant &extension = {});
    Variant copy(const Variant &from, const Variant &to);
    Variant count(const Variant &mode = 0);
    Variant delete_(const Variant &local_name);
    Variant delMetadata();
    Variant extractTo(const Variant &directory, const Variant &files = {}, const Variant &overwrite = false);
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
    Variant setDefaultStub(const Variant &index = {}, const Variant &web_index = {});
    Variant setMetadata(const Variant &metadata);
    Variant setSignatureAlgorithm(const Variant &algo, const Variant &private_key = {});
    Variant setStub(const Variant &stub, const Variant &length = {});
    Variant startBuffering();
    Variant stopBuffering();
    static Variant apiVersion();
    static Variant canCompress(const Variant &compression = 0);
    static Variant canWrite();
    static Variant createDefaultStub(const Variant &index = {}, const Variant &web_index = {});
    static Variant getSupportedCompression();
    static Variant getSupportedSignatures();
    static Variant interceptFileFuncs();
    static Variant isValidPharFilename(const Variant &filename, const Variant &executable = true);
    static Variant loadPhar(const Variant &filename, const Variant &alias = {});
    static Variant mapPhar(const Variant &alias = {}, const Variant &offset = 0);
    static Variant running(const Variant &return_phar = true);
    static Variant mount(const Variant &phar_path, const Variant &external_path);
    static Variant mungServer(const Variant &variables);
    static Variant unlinkArchive(const Variant &filename);
    static Variant webPhar(const Variant &alias = {},
                           const Variant &index = {},
                           const Variant &file_not_found_script = {},
                           const Variant &mime_types = Array{},
                           const Variant &rewrite = {});
};

class PharData : public RecursiveDirectoryIterator {
  protected:
    PharData() = default;

  public:
    PharData(const Variant &filename,
             const Variant &flags = 12288,
             const Variant &alias = {},
             const Variant &format = 0);
    Variant addEmptyDir(const Variant &directory);
    Variant addFile(const Variant &filename, const Variant &local_name = {});
    Variant addFromString(const Variant &local_name, const Variant &contents);
    Variant buildFromDirectory(const Variant &directory, const Variant &pattern = "");
    Variant buildFromIterator(const Variant &iterator, const Variant &base_directory = {});
    Variant compressFiles(const Variant &compression);
    Variant decompressFiles();
    Variant compress(const Variant &compression, const Variant &extension = {});
    Variant decompress(const Variant &extension = {});
    Variant convertToExecutable(const Variant &format = {},
                                const Variant &compression = {},
                                const Variant &extension = {});
    Variant convertToData(const Variant &format = {}, const Variant &compression = {}, const Variant &extension = {});
    Variant copy(const Variant &from, const Variant &to);
    Variant count(const Variant &mode = 0);
    Variant delete_(const Variant &local_name);
    Variant delMetadata();
    Variant extractTo(const Variant &directory, const Variant &files = {}, const Variant &overwrite = false);
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
    Variant setDefaultStub(const Variant &index = {}, const Variant &web_index = {});
    Variant setMetadata(const Variant &metadata);
    Variant setSignatureAlgorithm(const Variant &algo, const Variant &private_key = {});
    Variant setStub(const Variant &stub, const Variant &length = {});
    Variant startBuffering();
    Variant stopBuffering();
    static Variant apiVersion();
    static Variant canCompress(const Variant &compression = 0);
    static Variant canWrite();
    static Variant createDefaultStub(const Variant &index = {}, const Variant &web_index = {});
    static Variant getSupportedCompression();
    static Variant getSupportedSignatures();
    static Variant interceptFileFuncs();
    static Variant isValidPharFilename(const Variant &filename, const Variant &executable = true);
    static Variant loadPhar(const Variant &filename, const Variant &alias = {});
    static Variant mapPhar(const Variant &alias = {}, const Variant &offset = 0);
    static Variant running(const Variant &return_phar = true);
    static Variant mount(const Variant &phar_path, const Variant &external_path);
    static Variant mungServer(const Variant &variables);
    static Variant unlinkArchive(const Variant &filename);
    static Variant webPhar(const Variant &alias = {},
                           const Variant &index = {},
                           const Variant &file_not_found_script = {},
                           const Variant &mime_types = Array{},
                           const Variant &rewrite = {});
};

}  // namespace php

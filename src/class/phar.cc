#include "phpx.h"
#include "class/phar.h"

namespace php {
PharException::PharException(const Variant &message, const Variant &code, const Variant &previous) {
    this_ = newObject("PharException", message, code, previous);
}

Variant PharException::__wakeup() {
    return this_.exec("__wakeup");
}

Variant PharException::getMessage() {
    return this_.exec("getMessage");
}

Variant PharException::getCode() {
    return this_.exec("getCode");
}

Variant PharException::getFile() {
    return this_.exec("getFile");
}

Variant PharException::getLine() {
    return this_.exec("getLine");
}

Variant PharException::getTrace() {
    return this_.exec("getTrace");
}

Variant PharException::getPrevious() {
    return this_.exec("getPrevious");
}

Variant PharException::getTraceAsString() {
    return this_.exec("getTraceAsString");
}

Variant PharException::__toString() {
    return this_.exec("__toString");
}


Phar::Phar(const Variant &filename, const Variant &flags, const Variant &alias) {
    this_ = newObject("Phar", filename, flags, alias);
}

Variant Phar::addEmptyDir(const Variant &directory) {
    return this_.exec("addEmptyDir", directory);
}

Variant Phar::addFile(const Variant &filename, const Variant &local_name) {
    return this_.exec("addFile", filename, local_name);
}

Variant Phar::addFromString(const Variant &local_name, const Variant &contents) {
    return this_.exec("addFromString", local_name, contents);
}

Variant Phar::buildFromDirectory(const Variant &directory, const Variant &pattern) {
    return this_.exec("buildFromDirectory", directory, pattern);
}

Variant Phar::buildFromIterator(const Variant &iterator, const Variant &base_directory) {
    return this_.exec("buildFromIterator", iterator, base_directory);
}

Variant Phar::compressFiles(const Variant &compression) {
    return this_.exec("compressFiles", compression);
}

Variant Phar::decompressFiles() {
    return this_.exec("decompressFiles");
}

Variant Phar::compress(const Variant &compression, const Variant &extension) {
    return this_.exec("compress", compression, extension);
}

Variant Phar::decompress(const Variant &extension) {
    return this_.exec("decompress", extension);
}

Variant Phar::convertToExecutable(const Variant &format, const Variant &compression, const Variant &extension) {
    return this_.exec("convertToExecutable", format, compression, extension);
}

Variant Phar::convertToData(const Variant &format, const Variant &compression, const Variant &extension) {
    return this_.exec("convertToData", format, compression, extension);
}

Variant Phar::copy(const Variant &from, const Variant &to) {
    return this_.exec("copy", from, to);
}

Variant Phar::count(const Variant &mode) {
    return this_.exec("count", mode);
}

Variant Phar::_delete(const Variant &local_name) {
    return this_.exec("delete", local_name);
}

Variant Phar::delMetadata() {
    return this_.exec("delMetadata");
}

Variant Phar::extractTo(const Variant &directory, const Variant &files, const Variant &overwrite) {
    return this_.exec("extractTo", directory, files, overwrite);
}

Variant Phar::getAlias() {
    return this_.exec("getAlias");
}

Variant Phar::getPath() {
    return this_.exec("getPath");
}

Variant Phar::getMetadata(const Array &unserialize_options) {
    return this_.exec("getMetadata", unserialize_options);
}

Variant Phar::getModified() {
    return this_.exec("getModified");
}

Variant Phar::getSignature() {
    return this_.exec("getSignature");
}

Variant Phar::getStub() {
    return this_.exec("getStub");
}

Variant Phar::getVersion() {
    return this_.exec("getVersion");
}

Variant Phar::hasMetadata() {
    return this_.exec("hasMetadata");
}

Variant Phar::isBuffering() {
    return this_.exec("isBuffering");
}

Variant Phar::isCompressed() {
    return this_.exec("isCompressed");
}

Variant Phar::isFileFormat(const Variant &format) {
    return this_.exec("isFileFormat", format);
}

Variant Phar::isWritable() {
    return this_.exec("isWritable");
}

Variant Phar::offsetExists(const Variant &local_name) {
    return this_.exec("offsetExists", local_name);
}

Variant Phar::offsetGet(const Variant &local_name) {
    return this_.exec("offsetGet", local_name);
}

Variant Phar::offsetSet(const Variant &local_name, const Variant &value) {
    return this_.exec("offsetSet", local_name, value);
}

Variant Phar::offsetUnset(const Variant &local_name) {
    return this_.exec("offsetUnset", local_name);
}

Variant Phar::setAlias(const Variant &alias) {
    return this_.exec("setAlias", alias);
}

Variant Phar::setDefaultStub(const Variant &index, const Variant &web_index) {
    return this_.exec("setDefaultStub", index, web_index);
}

Variant Phar::setMetadata(const Variant &metadata) {
    return this_.exec("setMetadata", metadata);
}

Variant Phar::setSignatureAlgorithm(const Variant &algo, const Variant &private_key) {
    return this_.exec("setSignatureAlgorithm", algo, private_key);
}

Variant Phar::setStub(const Variant &stub, const Variant &length) {
    return this_.exec("setStub", stub, length);
}

Variant Phar::startBuffering() {
    return this_.exec("startBuffering");
}

Variant Phar::stopBuffering() {
    return this_.exec("stopBuffering");
}

Variant Phar::apiVersion() {
    static Variant fn { ZEND_STRL("Phar::apiVersion"), true };
    return fn();
}

Variant Phar::canCompress(const Variant &compression) {
    static Variant fn { ZEND_STRL("Phar::canCompress"), true };
    return fn(compression);
}

Variant Phar::canWrite() {
    static Variant fn { ZEND_STRL("Phar::canWrite"), true };
    return fn();
}

Variant Phar::createDefaultStub(const Variant &index, const Variant &web_index) {
    static Variant fn { ZEND_STRL("Phar::createDefaultStub"), true };
    return fn(index, web_index);
}

Variant Phar::getSupportedCompression() {
    static Variant fn { ZEND_STRL("Phar::getSupportedCompression"), true };
    return fn();
}

Variant Phar::getSupportedSignatures() {
    static Variant fn { ZEND_STRL("Phar::getSupportedSignatures"), true };
    return fn();
}

Variant Phar::interceptFileFuncs() {
    static Variant fn { ZEND_STRL("Phar::interceptFileFuncs"), true };
    return fn();
}

Variant Phar::isValidPharFilename(const Variant &filename, const Variant &executable) {
    static Variant fn { ZEND_STRL("Phar::isValidPharFilename"), true };
    return fn(filename, executable);
}

Variant Phar::loadPhar(const Variant &filename, const Variant &alias) {
    static Variant fn { ZEND_STRL("Phar::loadPhar"), true };
    return fn(filename, alias);
}

Variant Phar::mapPhar(const Variant &alias, const Variant &offset) {
    static Variant fn { ZEND_STRL("Phar::mapPhar"), true };
    return fn(alias, offset);
}

Variant Phar::running(const Variant &return_phar) {
    static Variant fn { ZEND_STRL("Phar::running"), true };
    return fn(return_phar);
}

Variant Phar::mount(const Variant &phar_path, const Variant &external_path) {
    static Variant fn { ZEND_STRL("Phar::mount"), true };
    return fn(phar_path, external_path);
}

Variant Phar::mungServer(const Variant &variables) {
    static Variant fn { ZEND_STRL("Phar::mungServer"), true };
    return fn(variables);
}

Variant Phar::unlinkArchive(const Variant &filename) {
    static Variant fn { ZEND_STRL("Phar::unlinkArchive"), true };
    return fn(filename);
}

Variant Phar::webPhar(const Variant &alias, const Variant &index, const Variant &file_not_found_script, const Array &mime_types, const Variant &rewrite) {
    static Variant fn { ZEND_STRL("Phar::webPhar"), true };
    return fn(alias, index, file_not_found_script, mime_types, rewrite);
}

Variant Phar::hasChildren(const Variant &allow_links) {
    return this_.exec("hasChildren", allow_links);
}

Variant Phar::getChildren() {
    return this_.exec("getChildren");
}

Variant Phar::getSubPath() {
    return this_.exec("getSubPath");
}

Variant Phar::getSubPathname() {
    return this_.exec("getSubPathname");
}

Variant Phar::rewind() {
    return this_.exec("rewind");
}

Variant Phar::key() {
    return this_.exec("key");
}

Variant Phar::current() {
    return this_.exec("current");
}

Variant Phar::getFlags() {
    return this_.exec("getFlags");
}

Variant Phar::setFlags(const Variant &flags) {
    return this_.exec("setFlags", flags);
}

Variant Phar::getFilename() {
    return this_.exec("getFilename");
}

Variant Phar::getExtension() {
    return this_.exec("getExtension");
}

Variant Phar::getBasename(const Variant &suffix) {
    return this_.exec("getBasename", suffix);
}

Variant Phar::isDot() {
    return this_.exec("isDot");
}

Variant Phar::valid() {
    return this_.exec("valid");
}

Variant Phar::next() {
    return this_.exec("next");
}

Variant Phar::seek(const Variant &offset) {
    return this_.exec("seek", offset);
}

Variant Phar::__toString() {
    return this_.exec("__toString");
}

Variant Phar::getPathname() {
    return this_.exec("getPathname");
}

Variant Phar::getPerms() {
    return this_.exec("getPerms");
}

Variant Phar::getInode() {
    return this_.exec("getInode");
}

Variant Phar::getSize() {
    return this_.exec("getSize");
}

Variant Phar::getOwner() {
    return this_.exec("getOwner");
}

Variant Phar::getGroup() {
    return this_.exec("getGroup");
}

Variant Phar::getATime() {
    return this_.exec("getATime");
}

Variant Phar::getMTime() {
    return this_.exec("getMTime");
}

Variant Phar::getCTime() {
    return this_.exec("getCTime");
}

Variant Phar::getType() {
    return this_.exec("getType");
}

Variant Phar::isReadable() {
    return this_.exec("isReadable");
}

Variant Phar::isExecutable() {
    return this_.exec("isExecutable");
}

Variant Phar::isFile() {
    return this_.exec("isFile");
}

Variant Phar::isDir() {
    return this_.exec("isDir");
}

Variant Phar::isLink() {
    return this_.exec("isLink");
}

Variant Phar::getLinkTarget() {
    return this_.exec("getLinkTarget");
}

Variant Phar::getRealPath() {
    return this_.exec("getRealPath");
}

Variant Phar::getFileInfo(const Variant &_class) {
    return this_.exec("getFileInfo", _class);
}

Variant Phar::getPathInfo(const Variant &_class) {
    return this_.exec("getPathInfo", _class);
}

Variant Phar::openFile(const Variant &mode, const Variant &use_include_path, const Variant &context) {
    return this_.exec("openFile", mode, use_include_path, context);
}

Variant Phar::setFileClass(const Variant &_class) {
    return this_.exec("setFileClass", _class);
}

Variant Phar::setInfoClass(const Variant &_class) {
    return this_.exec("setInfoClass", _class);
}

Variant Phar::__debugInfo() {
    return this_.exec("__debugInfo");
}

Variant Phar::_bad_state_ex() {
    return this_.exec("_bad_state_ex");
}


PharData::PharData(const Variant &filename, const Variant &flags, const Variant &alias, const Variant &format) {
    this_ = newObject("PharData", filename, flags, alias, format);
}

Variant PharData::addEmptyDir(const Variant &directory) {
    return this_.exec("addEmptyDir", directory);
}

Variant PharData::addFile(const Variant &filename, const Variant &local_name) {
    return this_.exec("addFile", filename, local_name);
}

Variant PharData::addFromString(const Variant &local_name, const Variant &contents) {
    return this_.exec("addFromString", local_name, contents);
}

Variant PharData::buildFromDirectory(const Variant &directory, const Variant &pattern) {
    return this_.exec("buildFromDirectory", directory, pattern);
}

Variant PharData::buildFromIterator(const Variant &iterator, const Variant &base_directory) {
    return this_.exec("buildFromIterator", iterator, base_directory);
}

Variant PharData::compressFiles(const Variant &compression) {
    return this_.exec("compressFiles", compression);
}

Variant PharData::decompressFiles() {
    return this_.exec("decompressFiles");
}

Variant PharData::compress(const Variant &compression, const Variant &extension) {
    return this_.exec("compress", compression, extension);
}

Variant PharData::decompress(const Variant &extension) {
    return this_.exec("decompress", extension);
}

Variant PharData::convertToExecutable(const Variant &format, const Variant &compression, const Variant &extension) {
    return this_.exec("convertToExecutable", format, compression, extension);
}

Variant PharData::convertToData(const Variant &format, const Variant &compression, const Variant &extension) {
    return this_.exec("convertToData", format, compression, extension);
}

Variant PharData::copy(const Variant &from, const Variant &to) {
    return this_.exec("copy", from, to);
}

Variant PharData::count(const Variant &mode) {
    return this_.exec("count", mode);
}

Variant PharData::_delete(const Variant &local_name) {
    return this_.exec("delete", local_name);
}

Variant PharData::delMetadata() {
    return this_.exec("delMetadata");
}

Variant PharData::extractTo(const Variant &directory, const Variant &files, const Variant &overwrite) {
    return this_.exec("extractTo", directory, files, overwrite);
}

Variant PharData::getAlias() {
    return this_.exec("getAlias");
}

Variant PharData::getPath() {
    return this_.exec("getPath");
}

Variant PharData::getMetadata(const Array &unserialize_options) {
    return this_.exec("getMetadata", unserialize_options);
}

Variant PharData::getModified() {
    return this_.exec("getModified");
}

Variant PharData::getSignature() {
    return this_.exec("getSignature");
}

Variant PharData::getStub() {
    return this_.exec("getStub");
}

Variant PharData::getVersion() {
    return this_.exec("getVersion");
}

Variant PharData::hasMetadata() {
    return this_.exec("hasMetadata");
}

Variant PharData::isBuffering() {
    return this_.exec("isBuffering");
}

Variant PharData::isCompressed() {
    return this_.exec("isCompressed");
}

Variant PharData::isFileFormat(const Variant &format) {
    return this_.exec("isFileFormat", format);
}

Variant PharData::isWritable() {
    return this_.exec("isWritable");
}

Variant PharData::offsetExists(const Variant &local_name) {
    return this_.exec("offsetExists", local_name);
}

Variant PharData::offsetGet(const Variant &local_name) {
    return this_.exec("offsetGet", local_name);
}

Variant PharData::offsetSet(const Variant &local_name, const Variant &value) {
    return this_.exec("offsetSet", local_name, value);
}

Variant PharData::offsetUnset(const Variant &local_name) {
    return this_.exec("offsetUnset", local_name);
}

Variant PharData::setAlias(const Variant &alias) {
    return this_.exec("setAlias", alias);
}

Variant PharData::setDefaultStub(const Variant &index, const Variant &web_index) {
    return this_.exec("setDefaultStub", index, web_index);
}

Variant PharData::setMetadata(const Variant &metadata) {
    return this_.exec("setMetadata", metadata);
}

Variant PharData::setSignatureAlgorithm(const Variant &algo, const Variant &private_key) {
    return this_.exec("setSignatureAlgorithm", algo, private_key);
}

Variant PharData::setStub(const Variant &stub, const Variant &length) {
    return this_.exec("setStub", stub, length);
}

Variant PharData::startBuffering() {
    return this_.exec("startBuffering");
}

Variant PharData::stopBuffering() {
    return this_.exec("stopBuffering");
}

Variant PharData::apiVersion() {
    static Variant fn { ZEND_STRL("PharData::apiVersion"), true };
    return fn();
}

Variant PharData::canCompress(const Variant &compression) {
    static Variant fn { ZEND_STRL("PharData::canCompress"), true };
    return fn(compression);
}

Variant PharData::canWrite() {
    static Variant fn { ZEND_STRL("PharData::canWrite"), true };
    return fn();
}

Variant PharData::createDefaultStub(const Variant &index, const Variant &web_index) {
    static Variant fn { ZEND_STRL("PharData::createDefaultStub"), true };
    return fn(index, web_index);
}

Variant PharData::getSupportedCompression() {
    static Variant fn { ZEND_STRL("PharData::getSupportedCompression"), true };
    return fn();
}

Variant PharData::getSupportedSignatures() {
    static Variant fn { ZEND_STRL("PharData::getSupportedSignatures"), true };
    return fn();
}

Variant PharData::interceptFileFuncs() {
    static Variant fn { ZEND_STRL("PharData::interceptFileFuncs"), true };
    return fn();
}

Variant PharData::isValidPharFilename(const Variant &filename, const Variant &executable) {
    static Variant fn { ZEND_STRL("PharData::isValidPharFilename"), true };
    return fn(filename, executable);
}

Variant PharData::loadPhar(const Variant &filename, const Variant &alias) {
    static Variant fn { ZEND_STRL("PharData::loadPhar"), true };
    return fn(filename, alias);
}

Variant PharData::mapPhar(const Variant &alias, const Variant &offset) {
    static Variant fn { ZEND_STRL("PharData::mapPhar"), true };
    return fn(alias, offset);
}

Variant PharData::running(const Variant &return_phar) {
    static Variant fn { ZEND_STRL("PharData::running"), true };
    return fn(return_phar);
}

Variant PharData::mount(const Variant &phar_path, const Variant &external_path) {
    static Variant fn { ZEND_STRL("PharData::mount"), true };
    return fn(phar_path, external_path);
}

Variant PharData::mungServer(const Variant &variables) {
    static Variant fn { ZEND_STRL("PharData::mungServer"), true };
    return fn(variables);
}

Variant PharData::unlinkArchive(const Variant &filename) {
    static Variant fn { ZEND_STRL("PharData::unlinkArchive"), true };
    return fn(filename);
}

Variant PharData::webPhar(const Variant &alias, const Variant &index, const Variant &file_not_found_script, const Array &mime_types, const Variant &rewrite) {
    static Variant fn { ZEND_STRL("PharData::webPhar"), true };
    return fn(alias, index, file_not_found_script, mime_types, rewrite);
}

Variant PharData::hasChildren(const Variant &allow_links) {
    return this_.exec("hasChildren", allow_links);
}

Variant PharData::getChildren() {
    return this_.exec("getChildren");
}

Variant PharData::getSubPath() {
    return this_.exec("getSubPath");
}

Variant PharData::getSubPathname() {
    return this_.exec("getSubPathname");
}

Variant PharData::rewind() {
    return this_.exec("rewind");
}

Variant PharData::key() {
    return this_.exec("key");
}

Variant PharData::current() {
    return this_.exec("current");
}

Variant PharData::getFlags() {
    return this_.exec("getFlags");
}

Variant PharData::setFlags(const Variant &flags) {
    return this_.exec("setFlags", flags);
}

Variant PharData::getFilename() {
    return this_.exec("getFilename");
}

Variant PharData::getExtension() {
    return this_.exec("getExtension");
}

Variant PharData::getBasename(const Variant &suffix) {
    return this_.exec("getBasename", suffix);
}

Variant PharData::isDot() {
    return this_.exec("isDot");
}

Variant PharData::valid() {
    return this_.exec("valid");
}

Variant PharData::next() {
    return this_.exec("next");
}

Variant PharData::seek(const Variant &offset) {
    return this_.exec("seek", offset);
}

Variant PharData::__toString() {
    return this_.exec("__toString");
}

Variant PharData::getPathname() {
    return this_.exec("getPathname");
}

Variant PharData::getPerms() {
    return this_.exec("getPerms");
}

Variant PharData::getInode() {
    return this_.exec("getInode");
}

Variant PharData::getSize() {
    return this_.exec("getSize");
}

Variant PharData::getOwner() {
    return this_.exec("getOwner");
}

Variant PharData::getGroup() {
    return this_.exec("getGroup");
}

Variant PharData::getATime() {
    return this_.exec("getATime");
}

Variant PharData::getMTime() {
    return this_.exec("getMTime");
}

Variant PharData::getCTime() {
    return this_.exec("getCTime");
}

Variant PharData::getType() {
    return this_.exec("getType");
}

Variant PharData::isReadable() {
    return this_.exec("isReadable");
}

Variant PharData::isExecutable() {
    return this_.exec("isExecutable");
}

Variant PharData::isFile() {
    return this_.exec("isFile");
}

Variant PharData::isDir() {
    return this_.exec("isDir");
}

Variant PharData::isLink() {
    return this_.exec("isLink");
}

Variant PharData::getLinkTarget() {
    return this_.exec("getLinkTarget");
}

Variant PharData::getRealPath() {
    return this_.exec("getRealPath");
}

Variant PharData::getFileInfo(const Variant &_class) {
    return this_.exec("getFileInfo", _class);
}

Variant PharData::getPathInfo(const Variant &_class) {
    return this_.exec("getPathInfo", _class);
}

Variant PharData::openFile(const Variant &mode, const Variant &use_include_path, const Variant &context) {
    return this_.exec("openFile", mode, use_include_path, context);
}

Variant PharData::setFileClass(const Variant &_class) {
    return this_.exec("setFileClass", _class);
}

Variant PharData::setInfoClass(const Variant &_class) {
    return this_.exec("setInfoClass", _class);
}

Variant PharData::__debugInfo() {
    return this_.exec("__debugInfo");
}

Variant PharData::_bad_state_ex() {
    return this_.exec("_bad_state_ex");
}


PharFileInfo::PharFileInfo(const Variant &filename) {
    this_ = newObject("PharFileInfo", filename);
}

Variant PharFileInfo::chmod(const Variant &perms) {
    return this_.exec("chmod", perms);
}

Variant PharFileInfo::compress(const Variant &compression) {
    return this_.exec("compress", compression);
}

Variant PharFileInfo::decompress() {
    return this_.exec("decompress");
}

Variant PharFileInfo::delMetadata() {
    return this_.exec("delMetadata");
}

Variant PharFileInfo::getCompressedSize() {
    return this_.exec("getCompressedSize");
}

Variant PharFileInfo::getCRC32() {
    return this_.exec("getCRC32");
}

Variant PharFileInfo::getContent() {
    return this_.exec("getContent");
}

Variant PharFileInfo::getMetadata(const Array &unserialize_options) {
    return this_.exec("getMetadata", unserialize_options);
}

Variant PharFileInfo::getPharFlags() {
    return this_.exec("getPharFlags");
}

Variant PharFileInfo::hasMetadata() {
    return this_.exec("hasMetadata");
}

Variant PharFileInfo::isCompressed(const Variant &compression) {
    return this_.exec("isCompressed", compression);
}

Variant PharFileInfo::isCRCChecked() {
    return this_.exec("isCRCChecked");
}

Variant PharFileInfo::setMetadata(const Variant &metadata) {
    return this_.exec("setMetadata", metadata);
}

Variant PharFileInfo::getPath() {
    return this_.exec("getPath");
}

Variant PharFileInfo::getFilename() {
    return this_.exec("getFilename");
}

Variant PharFileInfo::getExtension() {
    return this_.exec("getExtension");
}

Variant PharFileInfo::getBasename(const Variant &suffix) {
    return this_.exec("getBasename", suffix);
}

Variant PharFileInfo::getPathname() {
    return this_.exec("getPathname");
}

Variant PharFileInfo::getPerms() {
    return this_.exec("getPerms");
}

Variant PharFileInfo::getInode() {
    return this_.exec("getInode");
}

Variant PharFileInfo::getSize() {
    return this_.exec("getSize");
}

Variant PharFileInfo::getOwner() {
    return this_.exec("getOwner");
}

Variant PharFileInfo::getGroup() {
    return this_.exec("getGroup");
}

Variant PharFileInfo::getATime() {
    return this_.exec("getATime");
}

Variant PharFileInfo::getMTime() {
    return this_.exec("getMTime");
}

Variant PharFileInfo::getCTime() {
    return this_.exec("getCTime");
}

Variant PharFileInfo::getType() {
    return this_.exec("getType");
}

Variant PharFileInfo::isWritable() {
    return this_.exec("isWritable");
}

Variant PharFileInfo::isReadable() {
    return this_.exec("isReadable");
}

Variant PharFileInfo::isExecutable() {
    return this_.exec("isExecutable");
}

Variant PharFileInfo::isFile() {
    return this_.exec("isFile");
}

Variant PharFileInfo::isDir() {
    return this_.exec("isDir");
}

Variant PharFileInfo::isLink() {
    return this_.exec("isLink");
}

Variant PharFileInfo::getLinkTarget() {
    return this_.exec("getLinkTarget");
}

Variant PharFileInfo::getRealPath() {
    return this_.exec("getRealPath");
}

Variant PharFileInfo::getFileInfo(const Variant &_class) {
    return this_.exec("getFileInfo", _class);
}

Variant PharFileInfo::getPathInfo(const Variant &_class) {
    return this_.exec("getPathInfo", _class);
}

Variant PharFileInfo::openFile(const Variant &mode, const Variant &use_include_path, const Variant &context) {
    return this_.exec("openFile", mode, use_include_path, context);
}

Variant PharFileInfo::setFileClass(const Variant &_class) {
    return this_.exec("setFileClass", _class);
}

Variant PharFileInfo::setInfoClass(const Variant &_class) {
    return this_.exec("setInfoClass", _class);
}

Variant PharFileInfo::__toString() {
    return this_.exec("__toString");
}

Variant PharFileInfo::__debugInfo() {
    return this_.exec("__debugInfo");
}

Variant PharFileInfo::_bad_state_ex() {
    return this_.exec("_bad_state_ex");
}


}

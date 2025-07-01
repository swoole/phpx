#include "phpx.h"
#include "class/phar.h"

namespace php {
PharException::PharException(const Variant &message, const Variant &code, const Variant &previous) {
    _this = newObject("PharException", message, code, previous);
}

Variant PharException::__wakeup() {
    return _this.exec("__wakeup");
}

Variant PharException::getMessage() {
    return _this.exec("getMessage");
}

Variant PharException::getCode() {
    return _this.exec("getCode");
}

Variant PharException::getFile() {
    return _this.exec("getFile");
}

Variant PharException::getLine() {
    return _this.exec("getLine");
}

Variant PharException::getTrace() {
    return _this.exec("getTrace");
}

Variant PharException::getPrevious() {
    return _this.exec("getPrevious");
}

Variant PharException::getTraceAsString() {
    return _this.exec("getTraceAsString");
}

Variant PharException::__toString() {
    return _this.exec("__toString");
}


Phar::Phar(const Variant &filename, const Variant &flags, const Variant &alias) {
    _this = newObject("Phar", filename, flags, alias);
}

Variant Phar::addEmptyDir(const Variant &directory) {
    return _this.exec("addEmptyDir", directory);
}

Variant Phar::addFile(const Variant &filename, const Variant &local_name) {
    return _this.exec("addFile", filename, local_name);
}

Variant Phar::addFromString(const Variant &local_name, const Variant &contents) {
    return _this.exec("addFromString", local_name, contents);
}

Variant Phar::buildFromDirectory(const Variant &directory, const Variant &pattern) {
    return _this.exec("buildFromDirectory", directory, pattern);
}

Variant Phar::buildFromIterator(const Variant &iterator, const Variant &base_directory) {
    return _this.exec("buildFromIterator", iterator, base_directory);
}

Variant Phar::compressFiles(const Variant &compression) {
    return _this.exec("compressFiles", compression);
}

Variant Phar::decompressFiles() {
    return _this.exec("decompressFiles");
}

Variant Phar::compress(const Variant &compression, const Variant &extension) {
    return _this.exec("compress", compression, extension);
}

Variant Phar::decompress(const Variant &extension) {
    return _this.exec("decompress", extension);
}

Variant Phar::convertToExecutable(const Variant &format, const Variant &compression, const Variant &extension) {
    return _this.exec("convertToExecutable", format, compression, extension);
}

Variant Phar::convertToData(const Variant &format, const Variant &compression, const Variant &extension) {
    return _this.exec("convertToData", format, compression, extension);
}

Variant Phar::copy(const Variant &from, const Variant &to) {
    return _this.exec("copy", from, to);
}

Variant Phar::count(const Variant &mode) {
    return _this.exec("count", mode);
}

Variant Phar::_delete(const Variant &local_name) {
    return _this.exec("delete", local_name);
}

Variant Phar::delMetadata() {
    return _this.exec("delMetadata");
}

Variant Phar::extractTo(const Variant &directory, const Variant &files, const Variant &overwrite) {
    return _this.exec("extractTo", directory, files, overwrite);
}

Variant Phar::getAlias() {
    return _this.exec("getAlias");
}

Variant Phar::getPath() {
    return _this.exec("getPath");
}

Variant Phar::getMetadata(const Array &unserialize_options) {
    return _this.exec("getMetadata", unserialize_options);
}

Variant Phar::getModified() {
    return _this.exec("getModified");
}

Variant Phar::getSignature() {
    return _this.exec("getSignature");
}

Variant Phar::getStub() {
    return _this.exec("getStub");
}

Variant Phar::getVersion() {
    return _this.exec("getVersion");
}

Variant Phar::hasMetadata() {
    return _this.exec("hasMetadata");
}

Variant Phar::isBuffering() {
    return _this.exec("isBuffering");
}

Variant Phar::isCompressed() {
    return _this.exec("isCompressed");
}

Variant Phar::isFileFormat(const Variant &format) {
    return _this.exec("isFileFormat", format);
}

Variant Phar::isWritable() {
    return _this.exec("isWritable");
}

Variant Phar::offsetExists(const Variant &local_name) {
    return _this.exec("offsetExists", local_name);
}

Variant Phar::offsetGet(const Variant &local_name) {
    return _this.exec("offsetGet", local_name);
}

Variant Phar::offsetSet(const Variant &local_name, const Variant &value) {
    return _this.exec("offsetSet", local_name, value);
}

Variant Phar::offsetUnset(const Variant &local_name) {
    return _this.exec("offsetUnset", local_name);
}

Variant Phar::setAlias(const Variant &alias) {
    return _this.exec("setAlias", alias);
}

Variant Phar::setDefaultStub(const Variant &index, const Variant &web_index) {
    return _this.exec("setDefaultStub", index, web_index);
}

Variant Phar::setMetadata(const Variant &metadata) {
    return _this.exec("setMetadata", metadata);
}

Variant Phar::setSignatureAlgorithm(const Variant &algo, const Variant &private_key) {
    return _this.exec("setSignatureAlgorithm", algo, private_key);
}

Variant Phar::setStub(const Variant &stub, const Variant &length) {
    return _this.exec("setStub", stub, length);
}

Variant Phar::startBuffering() {
    return _this.exec("startBuffering");
}

Variant Phar::stopBuffering() {
    return _this.exec("stopBuffering");
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
    return _this.exec("hasChildren", allow_links);
}

Variant Phar::getChildren() {
    return _this.exec("getChildren");
}

Variant Phar::getSubPath() {
    return _this.exec("getSubPath");
}

Variant Phar::getSubPathname() {
    return _this.exec("getSubPathname");
}

Variant Phar::rewind() {
    return _this.exec("rewind");
}

Variant Phar::key() {
    return _this.exec("key");
}

Variant Phar::current() {
    return _this.exec("current");
}

Variant Phar::getFlags() {
    return _this.exec("getFlags");
}

Variant Phar::setFlags(const Variant &flags) {
    return _this.exec("setFlags", flags);
}

Variant Phar::getFilename() {
    return _this.exec("getFilename");
}

Variant Phar::getExtension() {
    return _this.exec("getExtension");
}

Variant Phar::getBasename(const Variant &suffix) {
    return _this.exec("getBasename", suffix);
}

Variant Phar::isDot() {
    return _this.exec("isDot");
}

Variant Phar::valid() {
    return _this.exec("valid");
}

Variant Phar::next() {
    return _this.exec("next");
}

Variant Phar::seek(const Variant &offset) {
    return _this.exec("seek", offset);
}

Variant Phar::__toString() {
    return _this.exec("__toString");
}

Variant Phar::getPathname() {
    return _this.exec("getPathname");
}

Variant Phar::getPerms() {
    return _this.exec("getPerms");
}

Variant Phar::getInode() {
    return _this.exec("getInode");
}

Variant Phar::getSize() {
    return _this.exec("getSize");
}

Variant Phar::getOwner() {
    return _this.exec("getOwner");
}

Variant Phar::getGroup() {
    return _this.exec("getGroup");
}

Variant Phar::getATime() {
    return _this.exec("getATime");
}

Variant Phar::getMTime() {
    return _this.exec("getMTime");
}

Variant Phar::getCTime() {
    return _this.exec("getCTime");
}

Variant Phar::getType() {
    return _this.exec("getType");
}

Variant Phar::isReadable() {
    return _this.exec("isReadable");
}

Variant Phar::isExecutable() {
    return _this.exec("isExecutable");
}

Variant Phar::isFile() {
    return _this.exec("isFile");
}

Variant Phar::isDir() {
    return _this.exec("isDir");
}

Variant Phar::isLink() {
    return _this.exec("isLink");
}

Variant Phar::getLinkTarget() {
    return _this.exec("getLinkTarget");
}

Variant Phar::getRealPath() {
    return _this.exec("getRealPath");
}

Variant Phar::getFileInfo(const Variant &_class) {
    return _this.exec("getFileInfo", _class);
}

Variant Phar::getPathInfo(const Variant &_class) {
    return _this.exec("getPathInfo", _class);
}

Variant Phar::openFile(const Variant &mode, const Variant &use_include_path, const Variant &context) {
    return _this.exec("openFile", mode, use_include_path, context);
}

Variant Phar::setFileClass(const Variant &_class) {
    return _this.exec("setFileClass", _class);
}

Variant Phar::setInfoClass(const Variant &_class) {
    return _this.exec("setInfoClass", _class);
}

Variant Phar::__debugInfo() {
    return _this.exec("__debugInfo");
}

Variant Phar::_bad_state_ex() {
    return _this.exec("_bad_state_ex");
}


PharData::PharData(const Variant &filename, const Variant &flags, const Variant &alias, const Variant &format) {
    _this = newObject("PharData", filename, flags, alias, format);
}

Variant PharData::addEmptyDir(const Variant &directory) {
    return _this.exec("addEmptyDir", directory);
}

Variant PharData::addFile(const Variant &filename, const Variant &local_name) {
    return _this.exec("addFile", filename, local_name);
}

Variant PharData::addFromString(const Variant &local_name, const Variant &contents) {
    return _this.exec("addFromString", local_name, contents);
}

Variant PharData::buildFromDirectory(const Variant &directory, const Variant &pattern) {
    return _this.exec("buildFromDirectory", directory, pattern);
}

Variant PharData::buildFromIterator(const Variant &iterator, const Variant &base_directory) {
    return _this.exec("buildFromIterator", iterator, base_directory);
}

Variant PharData::compressFiles(const Variant &compression) {
    return _this.exec("compressFiles", compression);
}

Variant PharData::decompressFiles() {
    return _this.exec("decompressFiles");
}

Variant PharData::compress(const Variant &compression, const Variant &extension) {
    return _this.exec("compress", compression, extension);
}

Variant PharData::decompress(const Variant &extension) {
    return _this.exec("decompress", extension);
}

Variant PharData::convertToExecutable(const Variant &format, const Variant &compression, const Variant &extension) {
    return _this.exec("convertToExecutable", format, compression, extension);
}

Variant PharData::convertToData(const Variant &format, const Variant &compression, const Variant &extension) {
    return _this.exec("convertToData", format, compression, extension);
}

Variant PharData::copy(const Variant &from, const Variant &to) {
    return _this.exec("copy", from, to);
}

Variant PharData::count(const Variant &mode) {
    return _this.exec("count", mode);
}

Variant PharData::_delete(const Variant &local_name) {
    return _this.exec("delete", local_name);
}

Variant PharData::delMetadata() {
    return _this.exec("delMetadata");
}

Variant PharData::extractTo(const Variant &directory, const Variant &files, const Variant &overwrite) {
    return _this.exec("extractTo", directory, files, overwrite);
}

Variant PharData::getAlias() {
    return _this.exec("getAlias");
}

Variant PharData::getPath() {
    return _this.exec("getPath");
}

Variant PharData::getMetadata(const Array &unserialize_options) {
    return _this.exec("getMetadata", unserialize_options);
}

Variant PharData::getModified() {
    return _this.exec("getModified");
}

Variant PharData::getSignature() {
    return _this.exec("getSignature");
}

Variant PharData::getStub() {
    return _this.exec("getStub");
}

Variant PharData::getVersion() {
    return _this.exec("getVersion");
}

Variant PharData::hasMetadata() {
    return _this.exec("hasMetadata");
}

Variant PharData::isBuffering() {
    return _this.exec("isBuffering");
}

Variant PharData::isCompressed() {
    return _this.exec("isCompressed");
}

Variant PharData::isFileFormat(const Variant &format) {
    return _this.exec("isFileFormat", format);
}

Variant PharData::isWritable() {
    return _this.exec("isWritable");
}

Variant PharData::offsetExists(const Variant &local_name) {
    return _this.exec("offsetExists", local_name);
}

Variant PharData::offsetGet(const Variant &local_name) {
    return _this.exec("offsetGet", local_name);
}

Variant PharData::offsetSet(const Variant &local_name, const Variant &value) {
    return _this.exec("offsetSet", local_name, value);
}

Variant PharData::offsetUnset(const Variant &local_name) {
    return _this.exec("offsetUnset", local_name);
}

Variant PharData::setAlias(const Variant &alias) {
    return _this.exec("setAlias", alias);
}

Variant PharData::setDefaultStub(const Variant &index, const Variant &web_index) {
    return _this.exec("setDefaultStub", index, web_index);
}

Variant PharData::setMetadata(const Variant &metadata) {
    return _this.exec("setMetadata", metadata);
}

Variant PharData::setSignatureAlgorithm(const Variant &algo, const Variant &private_key) {
    return _this.exec("setSignatureAlgorithm", algo, private_key);
}

Variant PharData::setStub(const Variant &stub, const Variant &length) {
    return _this.exec("setStub", stub, length);
}

Variant PharData::startBuffering() {
    return _this.exec("startBuffering");
}

Variant PharData::stopBuffering() {
    return _this.exec("stopBuffering");
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
    return _this.exec("hasChildren", allow_links);
}

Variant PharData::getChildren() {
    return _this.exec("getChildren");
}

Variant PharData::getSubPath() {
    return _this.exec("getSubPath");
}

Variant PharData::getSubPathname() {
    return _this.exec("getSubPathname");
}

Variant PharData::rewind() {
    return _this.exec("rewind");
}

Variant PharData::key() {
    return _this.exec("key");
}

Variant PharData::current() {
    return _this.exec("current");
}

Variant PharData::getFlags() {
    return _this.exec("getFlags");
}

Variant PharData::setFlags(const Variant &flags) {
    return _this.exec("setFlags", flags);
}

Variant PharData::getFilename() {
    return _this.exec("getFilename");
}

Variant PharData::getExtension() {
    return _this.exec("getExtension");
}

Variant PharData::getBasename(const Variant &suffix) {
    return _this.exec("getBasename", suffix);
}

Variant PharData::isDot() {
    return _this.exec("isDot");
}

Variant PharData::valid() {
    return _this.exec("valid");
}

Variant PharData::next() {
    return _this.exec("next");
}

Variant PharData::seek(const Variant &offset) {
    return _this.exec("seek", offset);
}

Variant PharData::__toString() {
    return _this.exec("__toString");
}

Variant PharData::getPathname() {
    return _this.exec("getPathname");
}

Variant PharData::getPerms() {
    return _this.exec("getPerms");
}

Variant PharData::getInode() {
    return _this.exec("getInode");
}

Variant PharData::getSize() {
    return _this.exec("getSize");
}

Variant PharData::getOwner() {
    return _this.exec("getOwner");
}

Variant PharData::getGroup() {
    return _this.exec("getGroup");
}

Variant PharData::getATime() {
    return _this.exec("getATime");
}

Variant PharData::getMTime() {
    return _this.exec("getMTime");
}

Variant PharData::getCTime() {
    return _this.exec("getCTime");
}

Variant PharData::getType() {
    return _this.exec("getType");
}

Variant PharData::isReadable() {
    return _this.exec("isReadable");
}

Variant PharData::isExecutable() {
    return _this.exec("isExecutable");
}

Variant PharData::isFile() {
    return _this.exec("isFile");
}

Variant PharData::isDir() {
    return _this.exec("isDir");
}

Variant PharData::isLink() {
    return _this.exec("isLink");
}

Variant PharData::getLinkTarget() {
    return _this.exec("getLinkTarget");
}

Variant PharData::getRealPath() {
    return _this.exec("getRealPath");
}

Variant PharData::getFileInfo(const Variant &_class) {
    return _this.exec("getFileInfo", _class);
}

Variant PharData::getPathInfo(const Variant &_class) {
    return _this.exec("getPathInfo", _class);
}

Variant PharData::openFile(const Variant &mode, const Variant &use_include_path, const Variant &context) {
    return _this.exec("openFile", mode, use_include_path, context);
}

Variant PharData::setFileClass(const Variant &_class) {
    return _this.exec("setFileClass", _class);
}

Variant PharData::setInfoClass(const Variant &_class) {
    return _this.exec("setInfoClass", _class);
}

Variant PharData::__debugInfo() {
    return _this.exec("__debugInfo");
}

Variant PharData::_bad_state_ex() {
    return _this.exec("_bad_state_ex");
}


PharFileInfo::PharFileInfo(const Variant &filename) {
    _this = newObject("PharFileInfo", filename);
}

Variant PharFileInfo::chmod(const Variant &perms) {
    return _this.exec("chmod", perms);
}

Variant PharFileInfo::compress(const Variant &compression) {
    return _this.exec("compress", compression);
}

Variant PharFileInfo::decompress() {
    return _this.exec("decompress");
}

Variant PharFileInfo::delMetadata() {
    return _this.exec("delMetadata");
}

Variant PharFileInfo::getCompressedSize() {
    return _this.exec("getCompressedSize");
}

Variant PharFileInfo::getCRC32() {
    return _this.exec("getCRC32");
}

Variant PharFileInfo::getContent() {
    return _this.exec("getContent");
}

Variant PharFileInfo::getMetadata(const Array &unserialize_options) {
    return _this.exec("getMetadata", unserialize_options);
}

Variant PharFileInfo::getPharFlags() {
    return _this.exec("getPharFlags");
}

Variant PharFileInfo::hasMetadata() {
    return _this.exec("hasMetadata");
}

Variant PharFileInfo::isCompressed(const Variant &compression) {
    return _this.exec("isCompressed", compression);
}

Variant PharFileInfo::isCRCChecked() {
    return _this.exec("isCRCChecked");
}

Variant PharFileInfo::setMetadata(const Variant &metadata) {
    return _this.exec("setMetadata", metadata);
}

Variant PharFileInfo::getPath() {
    return _this.exec("getPath");
}

Variant PharFileInfo::getFilename() {
    return _this.exec("getFilename");
}

Variant PharFileInfo::getExtension() {
    return _this.exec("getExtension");
}

Variant PharFileInfo::getBasename(const Variant &suffix) {
    return _this.exec("getBasename", suffix);
}

Variant PharFileInfo::getPathname() {
    return _this.exec("getPathname");
}

Variant PharFileInfo::getPerms() {
    return _this.exec("getPerms");
}

Variant PharFileInfo::getInode() {
    return _this.exec("getInode");
}

Variant PharFileInfo::getSize() {
    return _this.exec("getSize");
}

Variant PharFileInfo::getOwner() {
    return _this.exec("getOwner");
}

Variant PharFileInfo::getGroup() {
    return _this.exec("getGroup");
}

Variant PharFileInfo::getATime() {
    return _this.exec("getATime");
}

Variant PharFileInfo::getMTime() {
    return _this.exec("getMTime");
}

Variant PharFileInfo::getCTime() {
    return _this.exec("getCTime");
}

Variant PharFileInfo::getType() {
    return _this.exec("getType");
}

Variant PharFileInfo::isWritable() {
    return _this.exec("isWritable");
}

Variant PharFileInfo::isReadable() {
    return _this.exec("isReadable");
}

Variant PharFileInfo::isExecutable() {
    return _this.exec("isExecutable");
}

Variant PharFileInfo::isFile() {
    return _this.exec("isFile");
}

Variant PharFileInfo::isDir() {
    return _this.exec("isDir");
}

Variant PharFileInfo::isLink() {
    return _this.exec("isLink");
}

Variant PharFileInfo::getLinkTarget() {
    return _this.exec("getLinkTarget");
}

Variant PharFileInfo::getRealPath() {
    return _this.exec("getRealPath");
}

Variant PharFileInfo::getFileInfo(const Variant &_class) {
    return _this.exec("getFileInfo", _class);
}

Variant PharFileInfo::getPathInfo(const Variant &_class) {
    return _this.exec("getPathInfo", _class);
}

Variant PharFileInfo::openFile(const Variant &mode, const Variant &use_include_path, const Variant &context) {
    return _this.exec("openFile", mode, use_include_path, context);
}

Variant PharFileInfo::setFileClass(const Variant &_class) {
    return _this.exec("setFileClass", _class);
}

Variant PharFileInfo::setInfoClass(const Variant &_class) {
    return _this.exec("setInfoClass", _class);
}

Variant PharFileInfo::__toString() {
    return _this.exec("__toString");
}

Variant PharFileInfo::__debugInfo() {
    return _this.exec("__debugInfo");
}

Variant PharFileInfo::_bad_state_ex() {
    return _this.exec("_bad_state_ex");
}


}

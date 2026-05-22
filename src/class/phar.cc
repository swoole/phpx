#include "phpx.h"
#include "phpx_class.h"
#include "class/phar.h"

namespace php {
PharException::PharException(const Variant &message, const Variant &code, const Variant &previous) {
    this_ = newObject(LITERAL_STRING[1068], {message, code, previous});
}
PharFileInfo::PharFileInfo(const Variant &filename) {
    this_ = newObject(LITERAL_STRING[1150], {filename});
}
Variant PharFileInfo::chmod(const Variant &perms) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1151]);
    }
    return this_.call(_method_fn, {perms});
}
Variant PharFileInfo::compress(const Variant &compression) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1077]);
    }
    return this_.call(_method_fn, {compression});
}
Variant PharFileInfo::decompress() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1078]);
    }
    return this_.call(_method_fn, {});
}
Variant PharFileInfo::delMetadata() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1083]);
    }
    return this_.call(_method_fn, {});
}
Variant PharFileInfo::getCompressedSize() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1152]);
    }
    return this_.call(_method_fn, {});
}
Variant PharFileInfo::getCRC32() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1153]);
    }
    return this_.call(_method_fn, {});
}
Variant PharFileInfo::getContent() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1154]);
    }
    return this_.call(_method_fn, {});
}
Variant PharFileInfo::getMetadata(const Variant &unserialize_options) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1087]);
    }
    return this_.call(_method_fn, {unserialize_options});
}
Variant PharFileInfo::getPharFlags() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1155]);
    }
    return this_.call(_method_fn, {});
}
Variant PharFileInfo::hasMetadata() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1092]);
    }
    return this_.call(_method_fn, {});
}
Variant PharFileInfo::isCompressed(const Variant &compression) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1094]);
    }
    return this_.call(_method_fn, {compression});
}
Variant PharFileInfo::isCRCChecked() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1156]);
    }
    return this_.call(_method_fn, {});
}
Variant PharFileInfo::setMetadata(const Variant &metadata) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1099]);
    }
    return this_.call(_method_fn, {metadata});
}
Phar::Phar(const Variant &filename, const Variant &flags, const Variant &alias) {
    this_ = newObject(LITERAL_STRING[1069], {filename, flags, alias});
}
Variant Phar::addEmptyDir(const Variant &directory) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1070]);
    }
    return this_.call(_method_fn, {directory});
}
Variant Phar::addFile(const Variant &filename, const Variant &local_name) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1071]);
    }
    return this_.call(_method_fn, {filename, local_name});
}
Variant Phar::addFromString(const Variant &local_name, const Variant &contents) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1072]);
    }
    return this_.call(_method_fn, {local_name, contents});
}
Variant Phar::buildFromDirectory(const Variant &directory, const Variant &pattern) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1073]);
    }
    return this_.call(_method_fn, {directory, pattern});
}
Variant Phar::buildFromIterator(const Variant &iterator, const Variant &base_directory) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1074]);
    }
    return this_.call(_method_fn, {iterator, base_directory});
}
Variant Phar::compressFiles(const Variant &compression) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1075]);
    }
    return this_.call(_method_fn, {compression});
}
Variant Phar::decompressFiles() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1076]);
    }
    return this_.call(_method_fn, {});
}
Variant Phar::compress(const Variant &compression, const Variant &extension) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1077]);
    }
    return this_.call(_method_fn, {compression, extension});
}
Variant Phar::decompress(const Variant &extension) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1078]);
    }
    return this_.call(_method_fn, {extension});
}
Variant Phar::convertToExecutable(const Variant &format, const Variant &compression, const Variant &extension) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1079]);
    }
    return this_.call(_method_fn, {format, compression, extension});
}
Variant Phar::convertToData(const Variant &format, const Variant &compression, const Variant &extension) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1080]);
    }
    return this_.call(_method_fn, {format, compression, extension});
}
Variant Phar::copy(const Variant &from, const Variant &to) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1081]);
    }
    return this_.call(_method_fn, {from, to});
}
Variant Phar::count(const Variant &mode) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[140]);
    }
    return this_.call(_method_fn, {mode});
}
Variant Phar::delete_(const Variant &local_name) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1082]);
    }
    return this_.call(_method_fn, {local_name});
}
Variant Phar::delMetadata() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1083]);
    }
    return this_.call(_method_fn, {});
}
Variant Phar::extractTo(const Variant &directory, const Variant &files, const Variant &overwrite) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1084]);
    }
    return this_.call(_method_fn, {directory, files, overwrite});
}
Variant Phar::getAlias() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1085]);
    }
    return this_.call(_method_fn, {});
}
Variant Phar::getPath() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1086]);
    }
    return this_.call(_method_fn, {});
}
Variant Phar::getMetadata(const Variant &unserialize_options) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1087]);
    }
    return this_.call(_method_fn, {unserialize_options});
}
Variant Phar::getModified() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1088]);
    }
    return this_.call(_method_fn, {});
}
Variant Phar::getSignature() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1089]);
    }
    return this_.call(_method_fn, {});
}
Variant Phar::getStub() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1090]);
    }
    return this_.call(_method_fn, {});
}
Variant Phar::getVersion() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1091]);
    }
    return this_.call(_method_fn, {});
}
Variant Phar::hasMetadata() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1092]);
    }
    return this_.call(_method_fn, {});
}
Variant Phar::isBuffering() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1093]);
    }
    return this_.call(_method_fn, {});
}
Variant Phar::isCompressed() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1094]);
    }
    return this_.call(_method_fn, {});
}
Variant Phar::isFileFormat(const Variant &format) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1095]);
    }
    return this_.call(_method_fn, {format});
}
Variant Phar::isWritable() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1096]);
    }
    return this_.call(_method_fn, {});
}
Variant Phar::offsetExists(const Variant &local_name) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[138]);
    }
    return this_.call(_method_fn, {local_name});
}
Variant Phar::offsetGet(const Variant &local_name) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[136]);
    }
    return this_.call(_method_fn, {local_name});
}
Variant Phar::offsetSet(const Variant &local_name, const Variant &value) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[137]);
    }
    return this_.call(_method_fn, {local_name, value});
}
Variant Phar::offsetUnset(const Variant &local_name) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[139]);
    }
    return this_.call(_method_fn, {local_name});
}
Variant Phar::setAlias(const Variant &alias) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1097]);
    }
    return this_.call(_method_fn, {alias});
}
Variant Phar::setDefaultStub(const Variant &index, const Variant &web_index) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1098]);
    }
    return this_.call(_method_fn, {index, web_index});
}
Variant Phar::setMetadata(const Variant &metadata) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1099]);
    }
    return this_.call(_method_fn, {metadata});
}
Variant Phar::setSignatureAlgorithm(const Variant &algo, const Variant &private_key) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1100]);
    }
    return this_.call(_method_fn, {algo, private_key});
}
Variant Phar::setStub(const Variant &stub, const Variant &length) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1101]);
    }
    return this_.call(_method_fn, {stub, length});
}
Variant Phar::startBuffering() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1102]);
    }
    return this_.call(_method_fn, {});
}
Variant Phar::stopBuffering() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1103]);
    }
    return this_.call(_method_fn, {});
}
Variant Phar::apiVersion() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(LITERAL_STRING[1069], LITERAL_STRING[1105]);
    }
    return php::call(_method_fn, {});
}
Variant Phar::canCompress(const Variant &compression) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(LITERAL_STRING[1069], LITERAL_STRING[1107]);
    }
    return php::call(_method_fn, {compression});
}
Variant Phar::canWrite() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(LITERAL_STRING[1069], LITERAL_STRING[1109]);
    }
    return php::call(_method_fn, {});
}
Variant Phar::createDefaultStub(const Variant &index, const Variant &web_index) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(LITERAL_STRING[1069], LITERAL_STRING[1111]);
    }
    return php::call(_method_fn, {index, web_index});
}
Variant Phar::getSupportedCompression() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(LITERAL_STRING[1069], LITERAL_STRING[1113]);
    }
    return php::call(_method_fn, {});
}
Variant Phar::getSupportedSignatures() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(LITERAL_STRING[1069], LITERAL_STRING[1115]);
    }
    return php::call(_method_fn, {});
}
Variant Phar::interceptFileFuncs() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(LITERAL_STRING[1069], LITERAL_STRING[1117]);
    }
    return php::call(_method_fn, {});
}
Variant Phar::isValidPharFilename(const Variant &filename, const Variant &executable) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(LITERAL_STRING[1069], LITERAL_STRING[1119]);
    }
    return php::call(_method_fn, {filename, executable});
}
Variant Phar::loadPhar(const Variant &filename, const Variant &alias) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(LITERAL_STRING[1069], LITERAL_STRING[1121]);
    }
    return php::call(_method_fn, {filename, alias});
}
Variant Phar::mapPhar(const Variant &alias, const Variant &offset) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(LITERAL_STRING[1069], LITERAL_STRING[1123]);
    }
    return php::call(_method_fn, {alias, offset});
}
Variant Phar::running(const Variant &return_phar) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(LITERAL_STRING[1069], LITERAL_STRING[1125]);
    }
    return php::call(_method_fn, {return_phar});
}
Variant Phar::mount(const Variant &phar_path, const Variant &external_path) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(LITERAL_STRING[1069], LITERAL_STRING[1127]);
    }
    return php::call(_method_fn, {phar_path, external_path});
}
Variant Phar::mungServer(const Variant &variables) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(LITERAL_STRING[1069], LITERAL_STRING[1129]);
    }
    return php::call(_method_fn, {variables});
}
Variant Phar::unlinkArchive(const Variant &filename) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(LITERAL_STRING[1069], LITERAL_STRING[1131]);
    }
    return php::call(_method_fn, {filename});
}
Variant Phar::webPhar(const Variant &alias,
                      const Variant &index,
                      const Variant &file_not_found_script,
                      const Variant &mime_types,
                      const Variant &rewrite) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(LITERAL_STRING[1069], LITERAL_STRING[1133]);
    }
    return php::call(_method_fn, {alias, index, file_not_found_script, mime_types, rewrite});
}
PharData::PharData(const Variant &filename, const Variant &flags, const Variant &alias, const Variant &format) {
    this_ = newObject(LITERAL_STRING[1134], {filename, flags, alias, format});
}
Variant PharData::addEmptyDir(const Variant &directory) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1070]);
    }
    return this_.call(_method_fn, {directory});
}
Variant PharData::addFile(const Variant &filename, const Variant &local_name) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1071]);
    }
    return this_.call(_method_fn, {filename, local_name});
}
Variant PharData::addFromString(const Variant &local_name, const Variant &contents) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1072]);
    }
    return this_.call(_method_fn, {local_name, contents});
}
Variant PharData::buildFromDirectory(const Variant &directory, const Variant &pattern) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1073]);
    }
    return this_.call(_method_fn, {directory, pattern});
}
Variant PharData::buildFromIterator(const Variant &iterator, const Variant &base_directory) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1074]);
    }
    return this_.call(_method_fn, {iterator, base_directory});
}
Variant PharData::compressFiles(const Variant &compression) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1075]);
    }
    return this_.call(_method_fn, {compression});
}
Variant PharData::decompressFiles() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1076]);
    }
    return this_.call(_method_fn, {});
}
Variant PharData::compress(const Variant &compression, const Variant &extension) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1077]);
    }
    return this_.call(_method_fn, {compression, extension});
}
Variant PharData::decompress(const Variant &extension) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1078]);
    }
    return this_.call(_method_fn, {extension});
}
Variant PharData::convertToExecutable(const Variant &format, const Variant &compression, const Variant &extension) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1079]);
    }
    return this_.call(_method_fn, {format, compression, extension});
}
Variant PharData::convertToData(const Variant &format, const Variant &compression, const Variant &extension) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1080]);
    }
    return this_.call(_method_fn, {format, compression, extension});
}
Variant PharData::copy(const Variant &from, const Variant &to) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1081]);
    }
    return this_.call(_method_fn, {from, to});
}
Variant PharData::count(const Variant &mode) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[140]);
    }
    return this_.call(_method_fn, {mode});
}
Variant PharData::delete_(const Variant &local_name) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1082]);
    }
    return this_.call(_method_fn, {local_name});
}
Variant PharData::delMetadata() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1083]);
    }
    return this_.call(_method_fn, {});
}
Variant PharData::extractTo(const Variant &directory, const Variant &files, const Variant &overwrite) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1084]);
    }
    return this_.call(_method_fn, {directory, files, overwrite});
}
Variant PharData::getAlias() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1085]);
    }
    return this_.call(_method_fn, {});
}
Variant PharData::getPath() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1086]);
    }
    return this_.call(_method_fn, {});
}
Variant PharData::getMetadata(const Variant &unserialize_options) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1087]);
    }
    return this_.call(_method_fn, {unserialize_options});
}
Variant PharData::getModified() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1088]);
    }
    return this_.call(_method_fn, {});
}
Variant PharData::getSignature() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1089]);
    }
    return this_.call(_method_fn, {});
}
Variant PharData::getStub() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1090]);
    }
    return this_.call(_method_fn, {});
}
Variant PharData::getVersion() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1091]);
    }
    return this_.call(_method_fn, {});
}
Variant PharData::hasMetadata() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1092]);
    }
    return this_.call(_method_fn, {});
}
Variant PharData::isBuffering() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1093]);
    }
    return this_.call(_method_fn, {});
}
Variant PharData::isCompressed() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1094]);
    }
    return this_.call(_method_fn, {});
}
Variant PharData::isFileFormat(const Variant &format) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1095]);
    }
    return this_.call(_method_fn, {format});
}
Variant PharData::isWritable() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1096]);
    }
    return this_.call(_method_fn, {});
}
Variant PharData::offsetExists(const Variant &local_name) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[138]);
    }
    return this_.call(_method_fn, {local_name});
}
Variant PharData::offsetGet(const Variant &local_name) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[136]);
    }
    return this_.call(_method_fn, {local_name});
}
Variant PharData::offsetSet(const Variant &local_name, const Variant &value) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[137]);
    }
    return this_.call(_method_fn, {local_name, value});
}
Variant PharData::offsetUnset(const Variant &local_name) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[139]);
    }
    return this_.call(_method_fn, {local_name});
}
Variant PharData::setAlias(const Variant &alias) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1097]);
    }
    return this_.call(_method_fn, {alias});
}
Variant PharData::setDefaultStub(const Variant &index, const Variant &web_index) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1098]);
    }
    return this_.call(_method_fn, {index, web_index});
}
Variant PharData::setMetadata(const Variant &metadata) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1099]);
    }
    return this_.call(_method_fn, {metadata});
}
Variant PharData::setSignatureAlgorithm(const Variant &algo, const Variant &private_key) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1100]);
    }
    return this_.call(_method_fn, {algo, private_key});
}
Variant PharData::setStub(const Variant &stub, const Variant &length) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1101]);
    }
    return this_.call(_method_fn, {stub, length});
}
Variant PharData::startBuffering() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1102]);
    }
    return this_.call(_method_fn, {});
}
Variant PharData::stopBuffering() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1103]);
    }
    return this_.call(_method_fn, {});
}
Variant PharData::apiVersion() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(LITERAL_STRING[1134], LITERAL_STRING[1105]);
    }
    return php::call(_method_fn, {});
}
Variant PharData::canCompress(const Variant &compression) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(LITERAL_STRING[1134], LITERAL_STRING[1107]);
    }
    return php::call(_method_fn, {compression});
}
Variant PharData::canWrite() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(LITERAL_STRING[1134], LITERAL_STRING[1109]);
    }
    return php::call(_method_fn, {});
}
Variant PharData::createDefaultStub(const Variant &index, const Variant &web_index) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(LITERAL_STRING[1134], LITERAL_STRING[1111]);
    }
    return php::call(_method_fn, {index, web_index});
}
Variant PharData::getSupportedCompression() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(LITERAL_STRING[1134], LITERAL_STRING[1113]);
    }
    return php::call(_method_fn, {});
}
Variant PharData::getSupportedSignatures() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(LITERAL_STRING[1134], LITERAL_STRING[1115]);
    }
    return php::call(_method_fn, {});
}
Variant PharData::interceptFileFuncs() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(LITERAL_STRING[1134], LITERAL_STRING[1117]);
    }
    return php::call(_method_fn, {});
}
Variant PharData::isValidPharFilename(const Variant &filename, const Variant &executable) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(LITERAL_STRING[1134], LITERAL_STRING[1119]);
    }
    return php::call(_method_fn, {filename, executable});
}
Variant PharData::loadPhar(const Variant &filename, const Variant &alias) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(LITERAL_STRING[1134], LITERAL_STRING[1121]);
    }
    return php::call(_method_fn, {filename, alias});
}
Variant PharData::mapPhar(const Variant &alias, const Variant &offset) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(LITERAL_STRING[1134], LITERAL_STRING[1123]);
    }
    return php::call(_method_fn, {alias, offset});
}
Variant PharData::running(const Variant &return_phar) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(LITERAL_STRING[1134], LITERAL_STRING[1125]);
    }
    return php::call(_method_fn, {return_phar});
}
Variant PharData::mount(const Variant &phar_path, const Variant &external_path) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(LITERAL_STRING[1134], LITERAL_STRING[1127]);
    }
    return php::call(_method_fn, {phar_path, external_path});
}
Variant PharData::mungServer(const Variant &variables) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(LITERAL_STRING[1134], LITERAL_STRING[1129]);
    }
    return php::call(_method_fn, {variables});
}
Variant PharData::unlinkArchive(const Variant &filename) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(LITERAL_STRING[1134], LITERAL_STRING[1131]);
    }
    return php::call(_method_fn, {filename});
}
Variant PharData::webPhar(const Variant &alias,
                          const Variant &index,
                          const Variant &file_not_found_script,
                          const Variant &mime_types,
                          const Variant &rewrite) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(LITERAL_STRING[1134], LITERAL_STRING[1133]);
    }
    return php::call(_method_fn, {alias, index, file_not_found_script, mime_types, rewrite});
}
}  // namespace php

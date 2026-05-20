#include "phpx.h"
#include "class/phar.h"

namespace php {
PharException::PharException(const Variant &message, const Variant &code, const Variant &previous) {
    this_ = newObject(LITERAL_STRING[904], {message, code, previous});
}
Variant PharException::__wakeup() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[97]);
    }
    return this_.call(_method_fn, {});
}
Variant PharException::getMessage() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[98]);
    }
    return this_.call(_method_fn, {});
}
Variant PharException::getCode() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[99]);
    }
    return this_.call(_method_fn, {});
}
Variant PharException::getFile() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[100]);
    }
    return this_.call(_method_fn, {});
}
Variant PharException::getLine() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[101]);
    }
    return this_.call(_method_fn, {});
}
Variant PharException::getTrace() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[102]);
    }
    return this_.call(_method_fn, {});
}
Variant PharException::getPrevious() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[103]);
    }
    return this_.call(_method_fn, {});
}
Variant PharException::getTraceAsString() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[104]);
    }
    return this_.call(_method_fn, {});
}
Variant PharException::__toString() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[29]);
    }
    return this_.call(_method_fn, {});
}
Phar::Phar(const Variant &filename, const Variant &flags, const Variant &alias) {
    this_ = newObject(LITERAL_STRING[905], {filename, flags, alias});
}
Variant Phar::addEmptyDir(const Variant &directory) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[906]);
    }
    return this_.call(_method_fn, {directory});
}
Variant Phar::addFile(const Variant &filename, const Variant &local_name) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[907]);
    }
    return this_.call(_method_fn, {filename, local_name});
}
Variant Phar::addFromString(const Variant &local_name, const Variant &contents) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[908]);
    }
    return this_.call(_method_fn, {local_name, contents});
}
Variant Phar::buildFromDirectory(const Variant &directory, const Variant &pattern) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[909]);
    }
    return this_.call(_method_fn, {directory, pattern});
}
Variant Phar::buildFromIterator(const Variant &iterator, const Variant &base_directory) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[910]);
    }
    return this_.call(_method_fn, {iterator, base_directory});
}
Variant Phar::compressFiles(const Variant &compression) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[911]);
    }
    return this_.call(_method_fn, {compression});
}
Variant Phar::decompressFiles() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[912]);
    }
    return this_.call(_method_fn, {});
}
Variant Phar::compress(const Variant &compression, const Variant &extension) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[913]);
    }
    return this_.call(_method_fn, {compression, extension});
}
Variant Phar::decompress(const Variant &extension) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[914]);
    }
    return this_.call(_method_fn, {extension});
}
Variant Phar::convertToExecutable(const Variant &format, const Variant &compression, const Variant &extension) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[915]);
    }
    return this_.call(_method_fn, {format, compression, extension});
}
Variant Phar::convertToData(const Variant &format, const Variant &compression, const Variant &extension) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[916]);
    }
    return this_.call(_method_fn, {format, compression, extension});
}
Variant Phar::copy(const Variant &from, const Variant &to) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[917]);
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
Variant Phar::_delete(const Variant &local_name) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[918]);
    }
    return this_.call(_method_fn, {local_name});
}
Variant Phar::delMetadata() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[919]);
    }
    return this_.call(_method_fn, {});
}
Variant Phar::extractTo(const Variant &directory, const Variant &files, const Variant &overwrite) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[920]);
    }
    return this_.call(_method_fn, {directory, files, overwrite});
}
Variant Phar::getAlias() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[921]);
    }
    return this_.call(_method_fn, {});
}
Variant Phar::getPath() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[922]);
    }
    return this_.call(_method_fn, {});
}
Variant Phar::getMetadata(const Variant &unserialize_options) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[923]);
    }
    return this_.call(_method_fn, {unserialize_options});
}
Variant Phar::getModified() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[924]);
    }
    return this_.call(_method_fn, {});
}
Variant Phar::getSignature() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[925]);
    }
    return this_.call(_method_fn, {});
}
Variant Phar::getStub() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[926]);
    }
    return this_.call(_method_fn, {});
}
Variant Phar::getVersion() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[927]);
    }
    return this_.call(_method_fn, {});
}
Variant Phar::hasMetadata() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[928]);
    }
    return this_.call(_method_fn, {});
}
Variant Phar::isBuffering() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[929]);
    }
    return this_.call(_method_fn, {});
}
Variant Phar::isCompressed() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[930]);
    }
    return this_.call(_method_fn, {});
}
Variant Phar::isFileFormat(const Variant &format) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[931]);
    }
    return this_.call(_method_fn, {format});
}
Variant Phar::isWritable() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[932]);
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
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[933]);
    }
    return this_.call(_method_fn, {alias});
}
Variant Phar::setDefaultStub(const Variant &index, const Variant &web_index) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[934]);
    }
    return this_.call(_method_fn, {index, web_index});
}
Variant Phar::setMetadata(const Variant &metadata) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[935]);
    }
    return this_.call(_method_fn, {metadata});
}
Variant Phar::setSignatureAlgorithm(const Variant &algo, const Variant &private_key) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[936]);
    }
    return this_.call(_method_fn, {algo, private_key});
}
Variant Phar::setStub(const Variant &stub, const Variant &length) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[937]);
    }
    return this_.call(_method_fn, {stub, length});
}
Variant Phar::startBuffering() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[938]);
    }
    return this_.call(_method_fn, {});
}
Variant Phar::stopBuffering() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[939]);
    }
    return this_.call(_method_fn, {});
}
Variant Phar::apiVersion() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(LITERAL_STRING[905], LITERAL_STRING[941]);
    }
    return php::call(_method_fn, {});
}
Variant Phar::canCompress(const Variant &compression) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(LITERAL_STRING[905], LITERAL_STRING[943]);
    }
    return php::call(_method_fn, {compression});
}
Variant Phar::canWrite() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(LITERAL_STRING[905], LITERAL_STRING[945]);
    }
    return php::call(_method_fn, {});
}
Variant Phar::createDefaultStub(const Variant &index, const Variant &web_index) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(LITERAL_STRING[905], LITERAL_STRING[947]);
    }
    return php::call(_method_fn, {index, web_index});
}
Variant Phar::getSupportedCompression() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(LITERAL_STRING[905], LITERAL_STRING[949]);
    }
    return php::call(_method_fn, {});
}
Variant Phar::getSupportedSignatures() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(LITERAL_STRING[905], LITERAL_STRING[951]);
    }
    return php::call(_method_fn, {});
}
Variant Phar::interceptFileFuncs() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(LITERAL_STRING[905], LITERAL_STRING[953]);
    }
    return php::call(_method_fn, {});
}
Variant Phar::isValidPharFilename(const Variant &filename, const Variant &executable) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(LITERAL_STRING[905], LITERAL_STRING[955]);
    }
    return php::call(_method_fn, {filename, executable});
}
Variant Phar::loadPhar(const Variant &filename, const Variant &alias) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(LITERAL_STRING[905], LITERAL_STRING[957]);
    }
    return php::call(_method_fn, {filename, alias});
}
Variant Phar::mapPhar(const Variant &alias, const Variant &offset) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(LITERAL_STRING[905], LITERAL_STRING[959]);
    }
    return php::call(_method_fn, {alias, offset});
}
Variant Phar::running(const Variant &return_phar) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(LITERAL_STRING[905], LITERAL_STRING[961]);
    }
    return php::call(_method_fn, {return_phar});
}
Variant Phar::mount(const Variant &phar_path, const Variant &external_path) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(LITERAL_STRING[905], LITERAL_STRING[963]);
    }
    return php::call(_method_fn, {phar_path, external_path});
}
Variant Phar::mungServer(const Variant &variables) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(LITERAL_STRING[905], LITERAL_STRING[965]);
    }
    return php::call(_method_fn, {variables});
}
Variant Phar::unlinkArchive(const Variant &filename) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(LITERAL_STRING[905], LITERAL_STRING[967]);
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
        _method_fn = php::getMethod(LITERAL_STRING[905], LITERAL_STRING[969]);
    }
    return php::call(_method_fn, {alias, index, file_not_found_script, mime_types, rewrite});
}
Variant Phar::hasChildren(const Variant &allow_links) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[970]);
    }
    return this_.call(_method_fn, {allow_links});
}
Variant Phar::getChildren() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[971]);
    }
    return this_.call(_method_fn, {});
}
Variant Phar::getSubPath() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[972]);
    }
    return this_.call(_method_fn, {});
}
Variant Phar::getSubPathname() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[973]);
    }
    return this_.call(_method_fn, {});
}
Variant Phar::rewind() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[94]);
    }
    return this_.call(_method_fn, {});
}
Variant Phar::key() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[91]);
    }
    return this_.call(_method_fn, {});
}
Variant Phar::current() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[90]);
    }
    return this_.call(_method_fn, {});
}
Variant Phar::getFlags() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[974]);
    }
    return this_.call(_method_fn, {});
}
Variant Phar::setFlags(const Variant &flags) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[975]);
    }
    return this_.call(_method_fn, {flags});
}
Variant Phar::getFilename() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[211]);
    }
    return this_.call(_method_fn, {});
}
Variant Phar::getExtension() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[976]);
    }
    return this_.call(_method_fn, {});
}
Variant Phar::getBasename(const Variant &suffix) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[977]);
    }
    return this_.call(_method_fn, {suffix});
}
Variant Phar::isDot() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[978]);
    }
    return this_.call(_method_fn, {});
}
Variant Phar::valid() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[93]);
    }
    return this_.call(_method_fn, {});
}
Variant Phar::next() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[92]);
    }
    return this_.call(_method_fn, {});
}
Variant Phar::seek(const Variant &offset) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[979]);
    }
    return this_.call(_method_fn, {offset});
}
Variant Phar::__toString() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[29]);
    }
    return this_.call(_method_fn, {});
}
Variant Phar::getPathname() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[980]);
    }
    return this_.call(_method_fn, {});
}
Variant Phar::getPerms() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[981]);
    }
    return this_.call(_method_fn, {});
}
Variant Phar::getInode() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[982]);
    }
    return this_.call(_method_fn, {});
}
Variant Phar::getSize() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[983]);
    }
    return this_.call(_method_fn, {});
}
Variant Phar::getOwner() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[984]);
    }
    return this_.call(_method_fn, {});
}
Variant Phar::getGroup() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[985]);
    }
    return this_.call(_method_fn, {});
}
Variant Phar::getATime() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[986]);
    }
    return this_.call(_method_fn, {});
}
Variant Phar::getMTime() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[987]);
    }
    return this_.call(_method_fn, {});
}
Variant Phar::getCTime() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[988]);
    }
    return this_.call(_method_fn, {});
}
Variant Phar::getType() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[989]);
    }
    return this_.call(_method_fn, {});
}
Variant Phar::isReadable() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[990]);
    }
    return this_.call(_method_fn, {});
}
Variant Phar::isExecutable() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[991]);
    }
    return this_.call(_method_fn, {});
}
Variant Phar::isFile() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[992]);
    }
    return this_.call(_method_fn, {});
}
Variant Phar::isDir() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[993]);
    }
    return this_.call(_method_fn, {});
}
Variant Phar::isLink() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[994]);
    }
    return this_.call(_method_fn, {});
}
Variant Phar::getLinkTarget() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[995]);
    }
    return this_.call(_method_fn, {});
}
Variant Phar::getRealPath() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[996]);
    }
    return this_.call(_method_fn, {});
}
Variant Phar::getFileInfo(const Variant &_class) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[997]);
    }
    return this_.call(_method_fn, {_class});
}
Variant Phar::getPathInfo(const Variant &_class) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[998]);
    }
    return this_.call(_method_fn, {_class});
}
Variant Phar::openFile(const Variant &mode, const Variant &use_include_path, const Variant &context) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[999]);
    }
    return this_.call(_method_fn, {mode, use_include_path, context});
}
Variant Phar::setFileClass(const Variant &_class) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1000]);
    }
    return this_.call(_method_fn, {_class});
}
Variant Phar::setInfoClass(const Variant &_class) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1001]);
    }
    return this_.call(_method_fn, {_class});
}
Variant Phar::__debugInfo() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[129]);
    }
    return this_.call(_method_fn, {});
}
Variant Phar::_bad_state_ex() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1002]);
    }
    return this_.call(_method_fn, {});
}
PharData::PharData(const Variant &filename, const Variant &flags, const Variant &alias, const Variant &format) {
    this_ = newObject(LITERAL_STRING[1003], {filename, flags, alias, format});
}
Variant PharData::addEmptyDir(const Variant &directory) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[906]);
    }
    return this_.call(_method_fn, {directory});
}
Variant PharData::addFile(const Variant &filename, const Variant &local_name) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[907]);
    }
    return this_.call(_method_fn, {filename, local_name});
}
Variant PharData::addFromString(const Variant &local_name, const Variant &contents) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[908]);
    }
    return this_.call(_method_fn, {local_name, contents});
}
Variant PharData::buildFromDirectory(const Variant &directory, const Variant &pattern) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[909]);
    }
    return this_.call(_method_fn, {directory, pattern});
}
Variant PharData::buildFromIterator(const Variant &iterator, const Variant &base_directory) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[910]);
    }
    return this_.call(_method_fn, {iterator, base_directory});
}
Variant PharData::compressFiles(const Variant &compression) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[911]);
    }
    return this_.call(_method_fn, {compression});
}
Variant PharData::decompressFiles() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[912]);
    }
    return this_.call(_method_fn, {});
}
Variant PharData::compress(const Variant &compression, const Variant &extension) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[913]);
    }
    return this_.call(_method_fn, {compression, extension});
}
Variant PharData::decompress(const Variant &extension) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[914]);
    }
    return this_.call(_method_fn, {extension});
}
Variant PharData::convertToExecutable(const Variant &format, const Variant &compression, const Variant &extension) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[915]);
    }
    return this_.call(_method_fn, {format, compression, extension});
}
Variant PharData::convertToData(const Variant &format, const Variant &compression, const Variant &extension) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[916]);
    }
    return this_.call(_method_fn, {format, compression, extension});
}
Variant PharData::copy(const Variant &from, const Variant &to) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[917]);
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
Variant PharData::_delete(const Variant &local_name) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[918]);
    }
    return this_.call(_method_fn, {local_name});
}
Variant PharData::delMetadata() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[919]);
    }
    return this_.call(_method_fn, {});
}
Variant PharData::extractTo(const Variant &directory, const Variant &files, const Variant &overwrite) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[920]);
    }
    return this_.call(_method_fn, {directory, files, overwrite});
}
Variant PharData::getAlias() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[921]);
    }
    return this_.call(_method_fn, {});
}
Variant PharData::getPath() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[922]);
    }
    return this_.call(_method_fn, {});
}
Variant PharData::getMetadata(const Variant &unserialize_options) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[923]);
    }
    return this_.call(_method_fn, {unserialize_options});
}
Variant PharData::getModified() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[924]);
    }
    return this_.call(_method_fn, {});
}
Variant PharData::getSignature() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[925]);
    }
    return this_.call(_method_fn, {});
}
Variant PharData::getStub() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[926]);
    }
    return this_.call(_method_fn, {});
}
Variant PharData::getVersion() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[927]);
    }
    return this_.call(_method_fn, {});
}
Variant PharData::hasMetadata() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[928]);
    }
    return this_.call(_method_fn, {});
}
Variant PharData::isBuffering() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[929]);
    }
    return this_.call(_method_fn, {});
}
Variant PharData::isCompressed() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[930]);
    }
    return this_.call(_method_fn, {});
}
Variant PharData::isFileFormat(const Variant &format) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[931]);
    }
    return this_.call(_method_fn, {format});
}
Variant PharData::isWritable() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[932]);
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
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[933]);
    }
    return this_.call(_method_fn, {alias});
}
Variant PharData::setDefaultStub(const Variant &index, const Variant &web_index) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[934]);
    }
    return this_.call(_method_fn, {index, web_index});
}
Variant PharData::setMetadata(const Variant &metadata) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[935]);
    }
    return this_.call(_method_fn, {metadata});
}
Variant PharData::setSignatureAlgorithm(const Variant &algo, const Variant &private_key) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[936]);
    }
    return this_.call(_method_fn, {algo, private_key});
}
Variant PharData::setStub(const Variant &stub, const Variant &length) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[937]);
    }
    return this_.call(_method_fn, {stub, length});
}
Variant PharData::startBuffering() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[938]);
    }
    return this_.call(_method_fn, {});
}
Variant PharData::stopBuffering() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[939]);
    }
    return this_.call(_method_fn, {});
}
Variant PharData::apiVersion() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(LITERAL_STRING[1003], LITERAL_STRING[941]);
    }
    return php::call(_method_fn, {});
}
Variant PharData::canCompress(const Variant &compression) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(LITERAL_STRING[1003], LITERAL_STRING[943]);
    }
    return php::call(_method_fn, {compression});
}
Variant PharData::canWrite() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(LITERAL_STRING[1003], LITERAL_STRING[945]);
    }
    return php::call(_method_fn, {});
}
Variant PharData::createDefaultStub(const Variant &index, const Variant &web_index) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(LITERAL_STRING[1003], LITERAL_STRING[947]);
    }
    return php::call(_method_fn, {index, web_index});
}
Variant PharData::getSupportedCompression() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(LITERAL_STRING[1003], LITERAL_STRING[949]);
    }
    return php::call(_method_fn, {});
}
Variant PharData::getSupportedSignatures() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(LITERAL_STRING[1003], LITERAL_STRING[951]);
    }
    return php::call(_method_fn, {});
}
Variant PharData::interceptFileFuncs() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(LITERAL_STRING[1003], LITERAL_STRING[953]);
    }
    return php::call(_method_fn, {});
}
Variant PharData::isValidPharFilename(const Variant &filename, const Variant &executable) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(LITERAL_STRING[1003], LITERAL_STRING[955]);
    }
    return php::call(_method_fn, {filename, executable});
}
Variant PharData::loadPhar(const Variant &filename, const Variant &alias) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(LITERAL_STRING[1003], LITERAL_STRING[957]);
    }
    return php::call(_method_fn, {filename, alias});
}
Variant PharData::mapPhar(const Variant &alias, const Variant &offset) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(LITERAL_STRING[1003], LITERAL_STRING[959]);
    }
    return php::call(_method_fn, {alias, offset});
}
Variant PharData::running(const Variant &return_phar) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(LITERAL_STRING[1003], LITERAL_STRING[961]);
    }
    return php::call(_method_fn, {return_phar});
}
Variant PharData::mount(const Variant &phar_path, const Variant &external_path) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(LITERAL_STRING[1003], LITERAL_STRING[963]);
    }
    return php::call(_method_fn, {phar_path, external_path});
}
Variant PharData::mungServer(const Variant &variables) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(LITERAL_STRING[1003], LITERAL_STRING[965]);
    }
    return php::call(_method_fn, {variables});
}
Variant PharData::unlinkArchive(const Variant &filename) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(LITERAL_STRING[1003], LITERAL_STRING[967]);
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
        _method_fn = php::getMethod(LITERAL_STRING[1003], LITERAL_STRING[969]);
    }
    return php::call(_method_fn, {alias, index, file_not_found_script, mime_types, rewrite});
}
Variant PharData::hasChildren(const Variant &allow_links) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[970]);
    }
    return this_.call(_method_fn, {allow_links});
}
Variant PharData::getChildren() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[971]);
    }
    return this_.call(_method_fn, {});
}
Variant PharData::getSubPath() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[972]);
    }
    return this_.call(_method_fn, {});
}
Variant PharData::getSubPathname() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[973]);
    }
    return this_.call(_method_fn, {});
}
Variant PharData::rewind() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[94]);
    }
    return this_.call(_method_fn, {});
}
Variant PharData::key() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[91]);
    }
    return this_.call(_method_fn, {});
}
Variant PharData::current() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[90]);
    }
    return this_.call(_method_fn, {});
}
Variant PharData::getFlags() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[974]);
    }
    return this_.call(_method_fn, {});
}
Variant PharData::setFlags(const Variant &flags) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[975]);
    }
    return this_.call(_method_fn, {flags});
}
Variant PharData::getFilename() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[211]);
    }
    return this_.call(_method_fn, {});
}
Variant PharData::getExtension() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[976]);
    }
    return this_.call(_method_fn, {});
}
Variant PharData::getBasename(const Variant &suffix) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[977]);
    }
    return this_.call(_method_fn, {suffix});
}
Variant PharData::isDot() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[978]);
    }
    return this_.call(_method_fn, {});
}
Variant PharData::valid() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[93]);
    }
    return this_.call(_method_fn, {});
}
Variant PharData::next() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[92]);
    }
    return this_.call(_method_fn, {});
}
Variant PharData::seek(const Variant &offset) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[979]);
    }
    return this_.call(_method_fn, {offset});
}
Variant PharData::__toString() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[29]);
    }
    return this_.call(_method_fn, {});
}
Variant PharData::getPathname() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[980]);
    }
    return this_.call(_method_fn, {});
}
Variant PharData::getPerms() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[981]);
    }
    return this_.call(_method_fn, {});
}
Variant PharData::getInode() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[982]);
    }
    return this_.call(_method_fn, {});
}
Variant PharData::getSize() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[983]);
    }
    return this_.call(_method_fn, {});
}
Variant PharData::getOwner() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[984]);
    }
    return this_.call(_method_fn, {});
}
Variant PharData::getGroup() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[985]);
    }
    return this_.call(_method_fn, {});
}
Variant PharData::getATime() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[986]);
    }
    return this_.call(_method_fn, {});
}
Variant PharData::getMTime() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[987]);
    }
    return this_.call(_method_fn, {});
}
Variant PharData::getCTime() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[988]);
    }
    return this_.call(_method_fn, {});
}
Variant PharData::getType() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[989]);
    }
    return this_.call(_method_fn, {});
}
Variant PharData::isReadable() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[990]);
    }
    return this_.call(_method_fn, {});
}
Variant PharData::isExecutable() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[991]);
    }
    return this_.call(_method_fn, {});
}
Variant PharData::isFile() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[992]);
    }
    return this_.call(_method_fn, {});
}
Variant PharData::isDir() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[993]);
    }
    return this_.call(_method_fn, {});
}
Variant PharData::isLink() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[994]);
    }
    return this_.call(_method_fn, {});
}
Variant PharData::getLinkTarget() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[995]);
    }
    return this_.call(_method_fn, {});
}
Variant PharData::getRealPath() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[996]);
    }
    return this_.call(_method_fn, {});
}
Variant PharData::getFileInfo(const Variant &_class) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[997]);
    }
    return this_.call(_method_fn, {_class});
}
Variant PharData::getPathInfo(const Variant &_class) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[998]);
    }
    return this_.call(_method_fn, {_class});
}
Variant PharData::openFile(const Variant &mode, const Variant &use_include_path, const Variant &context) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[999]);
    }
    return this_.call(_method_fn, {mode, use_include_path, context});
}
Variant PharData::setFileClass(const Variant &_class) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1000]);
    }
    return this_.call(_method_fn, {_class});
}
Variant PharData::setInfoClass(const Variant &_class) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1001]);
    }
    return this_.call(_method_fn, {_class});
}
Variant PharData::__debugInfo() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[129]);
    }
    return this_.call(_method_fn, {});
}
Variant PharData::_bad_state_ex() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1002]);
    }
    return this_.call(_method_fn, {});
}
PharFileInfo::PharFileInfo(const Variant &filename) {
    this_ = newObject(LITERAL_STRING[1019], {filename});
}
Variant PharFileInfo::chmod(const Variant &perms) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1020]);
    }
    return this_.call(_method_fn, {perms});
}
Variant PharFileInfo::compress(const Variant &compression) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[913]);
    }
    return this_.call(_method_fn, {compression});
}
Variant PharFileInfo::decompress() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[914]);
    }
    return this_.call(_method_fn, {});
}
Variant PharFileInfo::delMetadata() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[919]);
    }
    return this_.call(_method_fn, {});
}
Variant PharFileInfo::getCompressedSize() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1021]);
    }
    return this_.call(_method_fn, {});
}
Variant PharFileInfo::getCRC32() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1022]);
    }
    return this_.call(_method_fn, {});
}
Variant PharFileInfo::getContent() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1023]);
    }
    return this_.call(_method_fn, {});
}
Variant PharFileInfo::getMetadata(const Variant &unserialize_options) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[923]);
    }
    return this_.call(_method_fn, {unserialize_options});
}
Variant PharFileInfo::getPharFlags() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1024]);
    }
    return this_.call(_method_fn, {});
}
Variant PharFileInfo::hasMetadata() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[928]);
    }
    return this_.call(_method_fn, {});
}
Variant PharFileInfo::isCompressed(const Variant &compression) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[930]);
    }
    return this_.call(_method_fn, {compression});
}
Variant PharFileInfo::isCRCChecked() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1025]);
    }
    return this_.call(_method_fn, {});
}
Variant PharFileInfo::setMetadata(const Variant &metadata) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[935]);
    }
    return this_.call(_method_fn, {metadata});
}
Variant PharFileInfo::getPath() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[922]);
    }
    return this_.call(_method_fn, {});
}
Variant PharFileInfo::getFilename() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[211]);
    }
    return this_.call(_method_fn, {});
}
Variant PharFileInfo::getExtension() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[976]);
    }
    return this_.call(_method_fn, {});
}
Variant PharFileInfo::getBasename(const Variant &suffix) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[977]);
    }
    return this_.call(_method_fn, {suffix});
}
Variant PharFileInfo::getPathname() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[980]);
    }
    return this_.call(_method_fn, {});
}
Variant PharFileInfo::getPerms() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[981]);
    }
    return this_.call(_method_fn, {});
}
Variant PharFileInfo::getInode() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[982]);
    }
    return this_.call(_method_fn, {});
}
Variant PharFileInfo::getSize() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[983]);
    }
    return this_.call(_method_fn, {});
}
Variant PharFileInfo::getOwner() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[984]);
    }
    return this_.call(_method_fn, {});
}
Variant PharFileInfo::getGroup() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[985]);
    }
    return this_.call(_method_fn, {});
}
Variant PharFileInfo::getATime() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[986]);
    }
    return this_.call(_method_fn, {});
}
Variant PharFileInfo::getMTime() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[987]);
    }
    return this_.call(_method_fn, {});
}
Variant PharFileInfo::getCTime() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[988]);
    }
    return this_.call(_method_fn, {});
}
Variant PharFileInfo::getType() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[989]);
    }
    return this_.call(_method_fn, {});
}
Variant PharFileInfo::isWritable() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[932]);
    }
    return this_.call(_method_fn, {});
}
Variant PharFileInfo::isReadable() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[990]);
    }
    return this_.call(_method_fn, {});
}
Variant PharFileInfo::isExecutable() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[991]);
    }
    return this_.call(_method_fn, {});
}
Variant PharFileInfo::isFile() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[992]);
    }
    return this_.call(_method_fn, {});
}
Variant PharFileInfo::isDir() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[993]);
    }
    return this_.call(_method_fn, {});
}
Variant PharFileInfo::isLink() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[994]);
    }
    return this_.call(_method_fn, {});
}
Variant PharFileInfo::getLinkTarget() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[995]);
    }
    return this_.call(_method_fn, {});
}
Variant PharFileInfo::getRealPath() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[996]);
    }
    return this_.call(_method_fn, {});
}
Variant PharFileInfo::getFileInfo(const Variant &_class) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[997]);
    }
    return this_.call(_method_fn, {_class});
}
Variant PharFileInfo::getPathInfo(const Variant &_class) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[998]);
    }
    return this_.call(_method_fn, {_class});
}
Variant PharFileInfo::openFile(const Variant &mode, const Variant &use_include_path, const Variant &context) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[999]);
    }
    return this_.call(_method_fn, {mode, use_include_path, context});
}
Variant PharFileInfo::setFileClass(const Variant &_class) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1000]);
    }
    return this_.call(_method_fn, {_class});
}
Variant PharFileInfo::setInfoClass(const Variant &_class) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1001]);
    }
    return this_.call(_method_fn, {_class});
}
Variant PharFileInfo::__toString() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[29]);
    }
    return this_.call(_method_fn, {});
}
Variant PharFileInfo::__debugInfo() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[129]);
    }
    return this_.call(_method_fn, {});
}
Variant PharFileInfo::_bad_state_ex() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1002]);
    }
    return this_.call(_method_fn, {});
}
}  // namespace php

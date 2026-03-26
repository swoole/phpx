#include "phpx.h"
#include "class/phar.h"

namespace php {
PharException::PharException(const Variant &message, const Variant &code, const Variant &previous) {
    this_ = newObject(LITERAL_STRING[862], {message, code, previous});
}
Variant PharException::__wakeup() {
    return this_.exec(LITERAL_STRING[97], {});
}
Variant PharException::getMessage() {
    return this_.exec(LITERAL_STRING[98], {});
}
Variant PharException::getCode() {
    return this_.exec(LITERAL_STRING[99], {});
}
Variant PharException::getFile() {
    return this_.exec(LITERAL_STRING[100], {});
}
Variant PharException::getLine() {
    return this_.exec(LITERAL_STRING[101], {});
}
Variant PharException::getTrace() {
    return this_.exec(LITERAL_STRING[102], {});
}
Variant PharException::getPrevious() {
    return this_.exec(LITERAL_STRING[103], {});
}
Variant PharException::getTraceAsString() {
    return this_.exec(LITERAL_STRING[104], {});
}
Variant PharException::__toString() {
    return this_.exec(LITERAL_STRING[29], {});
}
Phar::Phar(const Variant &filename, const Variant &flags, const Variant &alias) {
    this_ = newObject(LITERAL_STRING[863], {filename, flags, alias});
}
Variant Phar::addEmptyDir(const Variant &directory) {
    return this_.exec(LITERAL_STRING[864], {directory});
}
Variant Phar::addFile(const Variant &filename, const Variant &local_name) {
    return this_.exec(LITERAL_STRING[865], {filename, local_name});
}
Variant Phar::addFromString(const Variant &local_name, const Variant &contents) {
    return this_.exec(LITERAL_STRING[866], {local_name, contents});
}
Variant Phar::buildFromDirectory(const Variant &directory, const Variant &pattern) {
    return this_.exec(LITERAL_STRING[867], {directory, pattern});
}
Variant Phar::buildFromIterator(const Variant &iterator, const Variant &base_directory) {
    return this_.exec(LITERAL_STRING[868], {iterator, base_directory});
}
Variant Phar::compressFiles(const Variant &compression) {
    return this_.exec(LITERAL_STRING[869], {compression});
}
Variant Phar::decompressFiles() {
    return this_.exec(LITERAL_STRING[870], {});
}
Variant Phar::compress(const Variant &compression, const Variant &extension) {
    return this_.exec(LITERAL_STRING[871], {compression, extension});
}
Variant Phar::decompress(const Variant &extension) {
    return this_.exec(LITERAL_STRING[872], {extension});
}
Variant Phar::convertToExecutable(const Variant &format, const Variant &compression, const Variant &extension) {
    return this_.exec(LITERAL_STRING[873], {format, compression, extension});
}
Variant Phar::convertToData(const Variant &format, const Variant &compression, const Variant &extension) {
    return this_.exec(LITERAL_STRING[874], {format, compression, extension});
}
Variant Phar::copy(const Variant &from, const Variant &to) {
    return this_.exec(LITERAL_STRING[875], {from, to});
}
Variant Phar::count(const Variant &mode) {
    return this_.exec(LITERAL_STRING[136], {mode});
}
Variant Phar::_delete(const Variant &local_name) {
    return this_.exec(LITERAL_STRING[876], {local_name});
}
Variant Phar::delMetadata() {
    return this_.exec(LITERAL_STRING[877], {});
}
Variant Phar::extractTo(const Variant &directory, const Variant &files, const Variant &overwrite) {
    return this_.exec(LITERAL_STRING[878], {directory, files, overwrite});
}
Variant Phar::getAlias() {
    return this_.exec(LITERAL_STRING[879], {});
}
Variant Phar::getPath() {
    return this_.exec(LITERAL_STRING[880], {});
}
Variant Phar::getMetadata(const Variant &unserialize_options) {
    return this_.exec(LITERAL_STRING[881], {unserialize_options});
}
Variant Phar::getModified() {
    return this_.exec(LITERAL_STRING[882], {});
}
Variant Phar::getSignature() {
    return this_.exec(LITERAL_STRING[883], {});
}
Variant Phar::getStub() {
    return this_.exec(LITERAL_STRING[884], {});
}
Variant Phar::getVersion() {
    return this_.exec(LITERAL_STRING[885], {});
}
Variant Phar::hasMetadata() {
    return this_.exec(LITERAL_STRING[886], {});
}
Variant Phar::isBuffering() {
    return this_.exec(LITERAL_STRING[887], {});
}
Variant Phar::isCompressed() {
    return this_.exec(LITERAL_STRING[888], {});
}
Variant Phar::isFileFormat(const Variant &format) {
    return this_.exec(LITERAL_STRING[889], {format});
}
Variant Phar::isWritable() {
    return this_.exec(LITERAL_STRING[890], {});
}
Variant Phar::offsetExists(const Variant &local_name) {
    return this_.exec(LITERAL_STRING[134], {local_name});
}
Variant Phar::offsetGet(const Variant &local_name) {
    return this_.exec(LITERAL_STRING[132], {local_name});
}
Variant Phar::offsetSet(const Variant &local_name, const Variant &value) {
    return this_.exec(LITERAL_STRING[133], {local_name, value});
}
Variant Phar::offsetUnset(const Variant &local_name) {
    return this_.exec(LITERAL_STRING[135], {local_name});
}
Variant Phar::setAlias(const Variant &alias) {
    return this_.exec(LITERAL_STRING[891], {alias});
}
Variant Phar::setDefaultStub(const Variant &index, const Variant &web_index) {
    return this_.exec(LITERAL_STRING[892], {index, web_index});
}
Variant Phar::setMetadata(const Variant &metadata) {
    return this_.exec(LITERAL_STRING[893], {metadata});
}
Variant Phar::setSignatureAlgorithm(const Variant &algo, const Variant &private_key) {
    return this_.exec(LITERAL_STRING[894], {algo, private_key});
}
Variant Phar::setStub(const Variant &stub, const Variant &length) {
    return this_.exec(LITERAL_STRING[895], {stub, length});
}
Variant Phar::startBuffering() {
    return this_.exec(LITERAL_STRING[896], {});
}
Variant Phar::stopBuffering() {
    return this_.exec(LITERAL_STRING[897], {});
}
Variant Phar::apiVersion() {
    return php::call(LITERAL_STRING[898], {});
}
Variant Phar::canCompress(const Variant &compression) {
    return php::call(LITERAL_STRING[899], {compression});
}
Variant Phar::canWrite() {
    return php::call(LITERAL_STRING[900], {});
}
Variant Phar::createDefaultStub(const Variant &index, const Variant &web_index) {
    return php::call(LITERAL_STRING[901], {index, web_index});
}
Variant Phar::getSupportedCompression() {
    return php::call(LITERAL_STRING[902], {});
}
Variant Phar::getSupportedSignatures() {
    return php::call(LITERAL_STRING[903], {});
}
Variant Phar::interceptFileFuncs() {
    return php::call(LITERAL_STRING[904], {});
}
Variant Phar::isValidPharFilename(const Variant &filename, const Variant &executable) {
    return php::call(LITERAL_STRING[905], {filename, executable});
}
Variant Phar::loadPhar(const Variant &filename, const Variant &alias) {
    return php::call(LITERAL_STRING[906], {filename, alias});
}
Variant Phar::mapPhar(const Variant &alias, const Variant &offset) {
    return php::call(LITERAL_STRING[907], {alias, offset});
}
Variant Phar::running(const Variant &return_phar) {
    return php::call(LITERAL_STRING[908], {return_phar});
}
Variant Phar::mount(const Variant &phar_path, const Variant &external_path) {
    return php::call(LITERAL_STRING[909], {phar_path, external_path});
}
Variant Phar::mungServer(const Variant &variables) {
    return php::call(LITERAL_STRING[910], {variables});
}
Variant Phar::unlinkArchive(const Variant &filename) {
    return php::call(LITERAL_STRING[911], {filename});
}
Variant Phar::webPhar(const Variant &alias,
                      const Variant &index,
                      const Variant &file_not_found_script,
                      const Variant &mime_types,
                      const Variant &rewrite) {
    return php::call(LITERAL_STRING[912], {alias, index, file_not_found_script, mime_types, rewrite});
}
Variant Phar::hasChildren(const Variant &allow_links) {
    return this_.exec(LITERAL_STRING[913], {allow_links});
}
Variant Phar::getChildren() {
    return this_.exec(LITERAL_STRING[914], {});
}
Variant Phar::getSubPath() {
    return this_.exec(LITERAL_STRING[915], {});
}
Variant Phar::getSubPathname() {
    return this_.exec(LITERAL_STRING[916], {});
}
Variant Phar::rewind() {
    return this_.exec(LITERAL_STRING[94], {});
}
Variant Phar::key() {
    return this_.exec(LITERAL_STRING[91], {});
}
Variant Phar::current() {
    return this_.exec(LITERAL_STRING[90], {});
}
Variant Phar::getFlags() {
    return this_.exec(LITERAL_STRING[917], {});
}
Variant Phar::setFlags(const Variant &flags) {
    return this_.exec(LITERAL_STRING[918], {flags});
}
Variant Phar::getFilename() {
    return this_.exec(LITERAL_STRING[202], {});
}
Variant Phar::getExtension() {
    return this_.exec(LITERAL_STRING[919], {});
}
Variant Phar::getBasename(const Variant &suffix) {
    return this_.exec(LITERAL_STRING[920], {suffix});
}
Variant Phar::isDot() {
    return this_.exec(LITERAL_STRING[921], {});
}
Variant Phar::valid() {
    return this_.exec(LITERAL_STRING[93], {});
}
Variant Phar::next() {
    return this_.exec(LITERAL_STRING[92], {});
}
Variant Phar::seek(const Variant &offset) {
    return this_.exec(LITERAL_STRING[922], {offset});
}
Variant Phar::__toString() {
    return this_.exec(LITERAL_STRING[29], {});
}
Variant Phar::getPathname() {
    return this_.exec(LITERAL_STRING[923], {});
}
Variant Phar::getPerms() {
    return this_.exec(LITERAL_STRING[924], {});
}
Variant Phar::getInode() {
    return this_.exec(LITERAL_STRING[925], {});
}
Variant Phar::getSize() {
    return this_.exec(LITERAL_STRING[926], {});
}
Variant Phar::getOwner() {
    return this_.exec(LITERAL_STRING[927], {});
}
Variant Phar::getGroup() {
    return this_.exec(LITERAL_STRING[928], {});
}
Variant Phar::getATime() {
    return this_.exec(LITERAL_STRING[929], {});
}
Variant Phar::getMTime() {
    return this_.exec(LITERAL_STRING[930], {});
}
Variant Phar::getCTime() {
    return this_.exec(LITERAL_STRING[931], {});
}
Variant Phar::getType() {
    return this_.exec(LITERAL_STRING[932], {});
}
Variant Phar::isReadable() {
    return this_.exec(LITERAL_STRING[933], {});
}
Variant Phar::isExecutable() {
    return this_.exec(LITERAL_STRING[934], {});
}
Variant Phar::isFile() {
    return this_.exec(LITERAL_STRING[935], {});
}
Variant Phar::isDir() {
    return this_.exec(LITERAL_STRING[936], {});
}
Variant Phar::isLink() {
    return this_.exec(LITERAL_STRING[937], {});
}
Variant Phar::getLinkTarget() {
    return this_.exec(LITERAL_STRING[938], {});
}
Variant Phar::getRealPath() {
    return this_.exec(LITERAL_STRING[939], {});
}
Variant Phar::getFileInfo(const Variant &_class) {
    return this_.exec(LITERAL_STRING[940], {_class});
}
Variant Phar::getPathInfo(const Variant &_class) {
    return this_.exec(LITERAL_STRING[941], {_class});
}
Variant Phar::openFile(const Variant &mode, const Variant &use_include_path, const Variant &context) {
    return this_.exec(LITERAL_STRING[942], {mode, use_include_path, context});
}
Variant Phar::setFileClass(const Variant &_class) {
    return this_.exec(LITERAL_STRING[943], {_class});
}
Variant Phar::setInfoClass(const Variant &_class) {
    return this_.exec(LITERAL_STRING[944], {_class});
}
Variant Phar::__debugInfo() {
    return this_.exec(LITERAL_STRING[126], {});
}
Variant Phar::_bad_state_ex() {
    return this_.exec(LITERAL_STRING[945], {});
}
PharData::PharData(const Variant &filename, const Variant &flags, const Variant &alias, const Variant &format) {
    this_ = newObject(LITERAL_STRING[946], {filename, flags, alias, format});
}
Variant PharData::addEmptyDir(const Variant &directory) {
    return this_.exec(LITERAL_STRING[864], {directory});
}
Variant PharData::addFile(const Variant &filename, const Variant &local_name) {
    return this_.exec(LITERAL_STRING[865], {filename, local_name});
}
Variant PharData::addFromString(const Variant &local_name, const Variant &contents) {
    return this_.exec(LITERAL_STRING[866], {local_name, contents});
}
Variant PharData::buildFromDirectory(const Variant &directory, const Variant &pattern) {
    return this_.exec(LITERAL_STRING[867], {directory, pattern});
}
Variant PharData::buildFromIterator(const Variant &iterator, const Variant &base_directory) {
    return this_.exec(LITERAL_STRING[868], {iterator, base_directory});
}
Variant PharData::compressFiles(const Variant &compression) {
    return this_.exec(LITERAL_STRING[869], {compression});
}
Variant PharData::decompressFiles() {
    return this_.exec(LITERAL_STRING[870], {});
}
Variant PharData::compress(const Variant &compression, const Variant &extension) {
    return this_.exec(LITERAL_STRING[871], {compression, extension});
}
Variant PharData::decompress(const Variant &extension) {
    return this_.exec(LITERAL_STRING[872], {extension});
}
Variant PharData::convertToExecutable(const Variant &format, const Variant &compression, const Variant &extension) {
    return this_.exec(LITERAL_STRING[873], {format, compression, extension});
}
Variant PharData::convertToData(const Variant &format, const Variant &compression, const Variant &extension) {
    return this_.exec(LITERAL_STRING[874], {format, compression, extension});
}
Variant PharData::copy(const Variant &from, const Variant &to) {
    return this_.exec(LITERAL_STRING[875], {from, to});
}
Variant PharData::count(const Variant &mode) {
    return this_.exec(LITERAL_STRING[136], {mode});
}
Variant PharData::_delete(const Variant &local_name) {
    return this_.exec(LITERAL_STRING[876], {local_name});
}
Variant PharData::delMetadata() {
    return this_.exec(LITERAL_STRING[877], {});
}
Variant PharData::extractTo(const Variant &directory, const Variant &files, const Variant &overwrite) {
    return this_.exec(LITERAL_STRING[878], {directory, files, overwrite});
}
Variant PharData::getAlias() {
    return this_.exec(LITERAL_STRING[879], {});
}
Variant PharData::getPath() {
    return this_.exec(LITERAL_STRING[880], {});
}
Variant PharData::getMetadata(const Variant &unserialize_options) {
    return this_.exec(LITERAL_STRING[881], {unserialize_options});
}
Variant PharData::getModified() {
    return this_.exec(LITERAL_STRING[882], {});
}
Variant PharData::getSignature() {
    return this_.exec(LITERAL_STRING[883], {});
}
Variant PharData::getStub() {
    return this_.exec(LITERAL_STRING[884], {});
}
Variant PharData::getVersion() {
    return this_.exec(LITERAL_STRING[885], {});
}
Variant PharData::hasMetadata() {
    return this_.exec(LITERAL_STRING[886], {});
}
Variant PharData::isBuffering() {
    return this_.exec(LITERAL_STRING[887], {});
}
Variant PharData::isCompressed() {
    return this_.exec(LITERAL_STRING[888], {});
}
Variant PharData::isFileFormat(const Variant &format) {
    return this_.exec(LITERAL_STRING[889], {format});
}
Variant PharData::isWritable() {
    return this_.exec(LITERAL_STRING[890], {});
}
Variant PharData::offsetExists(const Variant &local_name) {
    return this_.exec(LITERAL_STRING[134], {local_name});
}
Variant PharData::offsetGet(const Variant &local_name) {
    return this_.exec(LITERAL_STRING[132], {local_name});
}
Variant PharData::offsetSet(const Variant &local_name, const Variant &value) {
    return this_.exec(LITERAL_STRING[133], {local_name, value});
}
Variant PharData::offsetUnset(const Variant &local_name) {
    return this_.exec(LITERAL_STRING[135], {local_name});
}
Variant PharData::setAlias(const Variant &alias) {
    return this_.exec(LITERAL_STRING[891], {alias});
}
Variant PharData::setDefaultStub(const Variant &index, const Variant &web_index) {
    return this_.exec(LITERAL_STRING[892], {index, web_index});
}
Variant PharData::setMetadata(const Variant &metadata) {
    return this_.exec(LITERAL_STRING[893], {metadata});
}
Variant PharData::setSignatureAlgorithm(const Variant &algo, const Variant &private_key) {
    return this_.exec(LITERAL_STRING[894], {algo, private_key});
}
Variant PharData::setStub(const Variant &stub, const Variant &length) {
    return this_.exec(LITERAL_STRING[895], {stub, length});
}
Variant PharData::startBuffering() {
    return this_.exec(LITERAL_STRING[896], {});
}
Variant PharData::stopBuffering() {
    return this_.exec(LITERAL_STRING[897], {});
}
Variant PharData::apiVersion() {
    return php::call(LITERAL_STRING[947], {});
}
Variant PharData::canCompress(const Variant &compression) {
    return php::call(LITERAL_STRING[948], {compression});
}
Variant PharData::canWrite() {
    return php::call(LITERAL_STRING[949], {});
}
Variant PharData::createDefaultStub(const Variant &index, const Variant &web_index) {
    return php::call(LITERAL_STRING[950], {index, web_index});
}
Variant PharData::getSupportedCompression() {
    return php::call(LITERAL_STRING[951], {});
}
Variant PharData::getSupportedSignatures() {
    return php::call(LITERAL_STRING[952], {});
}
Variant PharData::interceptFileFuncs() {
    return php::call(LITERAL_STRING[953], {});
}
Variant PharData::isValidPharFilename(const Variant &filename, const Variant &executable) {
    return php::call(LITERAL_STRING[954], {filename, executable});
}
Variant PharData::loadPhar(const Variant &filename, const Variant &alias) {
    return php::call(LITERAL_STRING[955], {filename, alias});
}
Variant PharData::mapPhar(const Variant &alias, const Variant &offset) {
    return php::call(LITERAL_STRING[956], {alias, offset});
}
Variant PharData::running(const Variant &return_phar) {
    return php::call(LITERAL_STRING[957], {return_phar});
}
Variant PharData::mount(const Variant &phar_path, const Variant &external_path) {
    return php::call(LITERAL_STRING[958], {phar_path, external_path});
}
Variant PharData::mungServer(const Variant &variables) {
    return php::call(LITERAL_STRING[959], {variables});
}
Variant PharData::unlinkArchive(const Variant &filename) {
    return php::call(LITERAL_STRING[960], {filename});
}
Variant PharData::webPhar(const Variant &alias,
                          const Variant &index,
                          const Variant &file_not_found_script,
                          const Variant &mime_types,
                          const Variant &rewrite) {
    return php::call(LITERAL_STRING[961], {alias, index, file_not_found_script, mime_types, rewrite});
}
Variant PharData::hasChildren(const Variant &allow_links) {
    return this_.exec(LITERAL_STRING[913], {allow_links});
}
Variant PharData::getChildren() {
    return this_.exec(LITERAL_STRING[914], {});
}
Variant PharData::getSubPath() {
    return this_.exec(LITERAL_STRING[915], {});
}
Variant PharData::getSubPathname() {
    return this_.exec(LITERAL_STRING[916], {});
}
Variant PharData::rewind() {
    return this_.exec(LITERAL_STRING[94], {});
}
Variant PharData::key() {
    return this_.exec(LITERAL_STRING[91], {});
}
Variant PharData::current() {
    return this_.exec(LITERAL_STRING[90], {});
}
Variant PharData::getFlags() {
    return this_.exec(LITERAL_STRING[917], {});
}
Variant PharData::setFlags(const Variant &flags) {
    return this_.exec(LITERAL_STRING[918], {flags});
}
Variant PharData::getFilename() {
    return this_.exec(LITERAL_STRING[202], {});
}
Variant PharData::getExtension() {
    return this_.exec(LITERAL_STRING[919], {});
}
Variant PharData::getBasename(const Variant &suffix) {
    return this_.exec(LITERAL_STRING[920], {suffix});
}
Variant PharData::isDot() {
    return this_.exec(LITERAL_STRING[921], {});
}
Variant PharData::valid() {
    return this_.exec(LITERAL_STRING[93], {});
}
Variant PharData::next() {
    return this_.exec(LITERAL_STRING[92], {});
}
Variant PharData::seek(const Variant &offset) {
    return this_.exec(LITERAL_STRING[922], {offset});
}
Variant PharData::__toString() {
    return this_.exec(LITERAL_STRING[29], {});
}
Variant PharData::getPathname() {
    return this_.exec(LITERAL_STRING[923], {});
}
Variant PharData::getPerms() {
    return this_.exec(LITERAL_STRING[924], {});
}
Variant PharData::getInode() {
    return this_.exec(LITERAL_STRING[925], {});
}
Variant PharData::getSize() {
    return this_.exec(LITERAL_STRING[926], {});
}
Variant PharData::getOwner() {
    return this_.exec(LITERAL_STRING[927], {});
}
Variant PharData::getGroup() {
    return this_.exec(LITERAL_STRING[928], {});
}
Variant PharData::getATime() {
    return this_.exec(LITERAL_STRING[929], {});
}
Variant PharData::getMTime() {
    return this_.exec(LITERAL_STRING[930], {});
}
Variant PharData::getCTime() {
    return this_.exec(LITERAL_STRING[931], {});
}
Variant PharData::getType() {
    return this_.exec(LITERAL_STRING[932], {});
}
Variant PharData::isReadable() {
    return this_.exec(LITERAL_STRING[933], {});
}
Variant PharData::isExecutable() {
    return this_.exec(LITERAL_STRING[934], {});
}
Variant PharData::isFile() {
    return this_.exec(LITERAL_STRING[935], {});
}
Variant PharData::isDir() {
    return this_.exec(LITERAL_STRING[936], {});
}
Variant PharData::isLink() {
    return this_.exec(LITERAL_STRING[937], {});
}
Variant PharData::getLinkTarget() {
    return this_.exec(LITERAL_STRING[938], {});
}
Variant PharData::getRealPath() {
    return this_.exec(LITERAL_STRING[939], {});
}
Variant PharData::getFileInfo(const Variant &_class) {
    return this_.exec(LITERAL_STRING[940], {_class});
}
Variant PharData::getPathInfo(const Variant &_class) {
    return this_.exec(LITERAL_STRING[941], {_class});
}
Variant PharData::openFile(const Variant &mode, const Variant &use_include_path, const Variant &context) {
    return this_.exec(LITERAL_STRING[942], {mode, use_include_path, context});
}
Variant PharData::setFileClass(const Variant &_class) {
    return this_.exec(LITERAL_STRING[943], {_class});
}
Variant PharData::setInfoClass(const Variant &_class) {
    return this_.exec(LITERAL_STRING[944], {_class});
}
Variant PharData::__debugInfo() {
    return this_.exec(LITERAL_STRING[126], {});
}
Variant PharData::_bad_state_ex() {
    return this_.exec(LITERAL_STRING[945], {});
}
PharFileInfo::PharFileInfo(const Variant &filename) {
    this_ = newObject(LITERAL_STRING[962], {filename});
}
Variant PharFileInfo::chmod(const Variant &perms) {
    return this_.exec(LITERAL_STRING[963], {perms});
}
Variant PharFileInfo::compress(const Variant &compression) {
    return this_.exec(LITERAL_STRING[871], {compression});
}
Variant PharFileInfo::decompress() {
    return this_.exec(LITERAL_STRING[872], {});
}
Variant PharFileInfo::delMetadata() {
    return this_.exec(LITERAL_STRING[877], {});
}
Variant PharFileInfo::getCompressedSize() {
    return this_.exec(LITERAL_STRING[964], {});
}
Variant PharFileInfo::getCRC32() {
    return this_.exec(LITERAL_STRING[965], {});
}
Variant PharFileInfo::getContent() {
    return this_.exec(LITERAL_STRING[966], {});
}
Variant PharFileInfo::getMetadata(const Variant &unserialize_options) {
    return this_.exec(LITERAL_STRING[881], {unserialize_options});
}
Variant PharFileInfo::getPharFlags() {
    return this_.exec(LITERAL_STRING[967], {});
}
Variant PharFileInfo::hasMetadata() {
    return this_.exec(LITERAL_STRING[886], {});
}
Variant PharFileInfo::isCompressed(const Variant &compression) {
    return this_.exec(LITERAL_STRING[888], {compression});
}
Variant PharFileInfo::isCRCChecked() {
    return this_.exec(LITERAL_STRING[968], {});
}
Variant PharFileInfo::setMetadata(const Variant &metadata) {
    return this_.exec(LITERAL_STRING[893], {metadata});
}
Variant PharFileInfo::getPath() {
    return this_.exec(LITERAL_STRING[880], {});
}
Variant PharFileInfo::getFilename() {
    return this_.exec(LITERAL_STRING[202], {});
}
Variant PharFileInfo::getExtension() {
    return this_.exec(LITERAL_STRING[919], {});
}
Variant PharFileInfo::getBasename(const Variant &suffix) {
    return this_.exec(LITERAL_STRING[920], {suffix});
}
Variant PharFileInfo::getPathname() {
    return this_.exec(LITERAL_STRING[923], {});
}
Variant PharFileInfo::getPerms() {
    return this_.exec(LITERAL_STRING[924], {});
}
Variant PharFileInfo::getInode() {
    return this_.exec(LITERAL_STRING[925], {});
}
Variant PharFileInfo::getSize() {
    return this_.exec(LITERAL_STRING[926], {});
}
Variant PharFileInfo::getOwner() {
    return this_.exec(LITERAL_STRING[927], {});
}
Variant PharFileInfo::getGroup() {
    return this_.exec(LITERAL_STRING[928], {});
}
Variant PharFileInfo::getATime() {
    return this_.exec(LITERAL_STRING[929], {});
}
Variant PharFileInfo::getMTime() {
    return this_.exec(LITERAL_STRING[930], {});
}
Variant PharFileInfo::getCTime() {
    return this_.exec(LITERAL_STRING[931], {});
}
Variant PharFileInfo::getType() {
    return this_.exec(LITERAL_STRING[932], {});
}
Variant PharFileInfo::isWritable() {
    return this_.exec(LITERAL_STRING[890], {});
}
Variant PharFileInfo::isReadable() {
    return this_.exec(LITERAL_STRING[933], {});
}
Variant PharFileInfo::isExecutable() {
    return this_.exec(LITERAL_STRING[934], {});
}
Variant PharFileInfo::isFile() {
    return this_.exec(LITERAL_STRING[935], {});
}
Variant PharFileInfo::isDir() {
    return this_.exec(LITERAL_STRING[936], {});
}
Variant PharFileInfo::isLink() {
    return this_.exec(LITERAL_STRING[937], {});
}
Variant PharFileInfo::getLinkTarget() {
    return this_.exec(LITERAL_STRING[938], {});
}
Variant PharFileInfo::getRealPath() {
    return this_.exec(LITERAL_STRING[939], {});
}
Variant PharFileInfo::getFileInfo(const Variant &_class) {
    return this_.exec(LITERAL_STRING[940], {_class});
}
Variant PharFileInfo::getPathInfo(const Variant &_class) {
    return this_.exec(LITERAL_STRING[941], {_class});
}
Variant PharFileInfo::openFile(const Variant &mode, const Variant &use_include_path, const Variant &context) {
    return this_.exec(LITERAL_STRING[942], {mode, use_include_path, context});
}
Variant PharFileInfo::setFileClass(const Variant &_class) {
    return this_.exec(LITERAL_STRING[943], {_class});
}
Variant PharFileInfo::setInfoClass(const Variant &_class) {
    return this_.exec(LITERAL_STRING[944], {_class});
}
Variant PharFileInfo::__toString() {
    return this_.exec(LITERAL_STRING[29], {});
}
Variant PharFileInfo::__debugInfo() {
    return this_.exec(LITERAL_STRING[126], {});
}
Variant PharFileInfo::_bad_state_ex() {
    return this_.exec(LITERAL_STRING[945], {});
}
}  // namespace php

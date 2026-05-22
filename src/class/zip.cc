#include "phpx.h"
#include "phpx_class.h"
#include "class/zip.h"

namespace php {
ZipArchive::ZipArchive() {
    this_ = newObject(LITERAL_STRING[3472]);
}
Variant ZipArchive::open(const Variant &filename, const Variant &flags) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1396]);
    }
    return this_.call(_method_fn, {filename, flags});
}
Variant ZipArchive::setPassword(const Variant &password) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[3473]);
    }
    return this_.call(_method_fn, {password});
}
Variant ZipArchive::close() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[895]);
    }
    return this_.call(_method_fn, {});
}
Variant ZipArchive::count() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[168]);
    }
    return this_.call(_method_fn, {});
}
Variant ZipArchive::getStatusString() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[3474]);
    }
    return this_.call(_method_fn, {});
}
Variant ZipArchive::clearError() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[3475]);
    }
    return this_.call(_method_fn, {});
}
Variant ZipArchive::addEmptyDir(const Variant &dirname, const Variant &flags) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1108]);
    }
    return this_.call(_method_fn, {dirname, flags});
}
Variant ZipArchive::addFromString(const Variant &name, const Variant &content, const Variant &flags) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1110]);
    }
    return this_.call(_method_fn, {name, content, flags});
}
Variant ZipArchive::addFile(const Variant &filepath,
                            const Variant &entryname,
                            const Variant &start,
                            const Variant &length,
                            const Variant &flags) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1109]);
    }
    return this_.call(_method_fn, {filepath, entryname, start, length, flags});
}
Variant ZipArchive::replaceFile(
    const Variant &filepath, const Variant &index, const Variant &start, const Variant &length, const Variant &flags) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[3476]);
    }
    return this_.call(_method_fn, {filepath, index, start, length, flags});
}
Variant ZipArchive::addGlob(const Variant &pattern, const Variant &flags, const Variant &options) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[3477]);
    }
    return this_.call(_method_fn, {pattern, flags, options});
}
Variant ZipArchive::addPattern(const Variant &pattern, const Variant &path, const Variant &options) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[3478]);
    }
    return this_.call(_method_fn, {pattern, path, options});
}
Variant ZipArchive::renameIndex(const Variant &index, const Variant &new_name) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[3479]);
    }
    return this_.call(_method_fn, {index, new_name});
}
Variant ZipArchive::renameName(const Variant &name, const Variant &new_name) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[3480]);
    }
    return this_.call(_method_fn, {name, new_name});
}
Variant ZipArchive::setArchiveComment(const Variant &comment) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[3481]);
    }
    return this_.call(_method_fn, {comment});
}
Variant ZipArchive::getArchiveComment(const Variant &flags) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[3482]);
    }
    return this_.call(_method_fn, {flags});
}
Variant ZipArchive::setArchiveFlag(const Variant &flag, const Variant &value) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[3483]);
    }
    return this_.call(_method_fn, {flag, value});
}
Variant ZipArchive::getArchiveFlag(const Variant &flag, const Variant &flags) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[3484]);
    }
    return this_.call(_method_fn, {flag, flags});
}
Variant ZipArchive::setCommentIndex(const Variant &index, const Variant &comment) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[3485]);
    }
    return this_.call(_method_fn, {index, comment});
}
Variant ZipArchive::setCommentName(const Variant &name, const Variant &comment) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[3486]);
    }
    return this_.call(_method_fn, {name, comment});
}
Variant ZipArchive::setMtimeIndex(const Variant &index, const Variant &timestamp, const Variant &flags) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[3487]);
    }
    return this_.call(_method_fn, {index, timestamp, flags});
}
Variant ZipArchive::setMtimeName(const Variant &name, const Variant &timestamp, const Variant &flags) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[3488]);
    }
    return this_.call(_method_fn, {name, timestamp, flags});
}
Variant ZipArchive::getCommentIndex(const Variant &index, const Variant &flags) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[3489]);
    }
    return this_.call(_method_fn, {index, flags});
}
Variant ZipArchive::getCommentName(const Variant &name, const Variant &flags) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[3490]);
    }
    return this_.call(_method_fn, {name, flags});
}
Variant ZipArchive::deleteIndex(const Variant &index) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[3491]);
    }
    return this_.call(_method_fn, {index});
}
Variant ZipArchive::deleteName(const Variant &name) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[3492]);
    }
    return this_.call(_method_fn, {name});
}
Variant ZipArchive::statName(const Variant &name, const Variant &flags) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[3493]);
    }
    return this_.call(_method_fn, {name, flags});
}
Variant ZipArchive::statIndex(const Variant &index, const Variant &flags) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[3494]);
    }
    return this_.call(_method_fn, {index, flags});
}
Variant ZipArchive::locateName(const Variant &name, const Variant &flags) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[3495]);
    }
    return this_.call(_method_fn, {name, flags});
}
Variant ZipArchive::getNameIndex(const Variant &index, const Variant &flags) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[3496]);
    }
    return this_.call(_method_fn, {index, flags});
}
Variant ZipArchive::unchangeArchive() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[3497]);
    }
    return this_.call(_method_fn, {});
}
Variant ZipArchive::unchangeAll() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[3498]);
    }
    return this_.call(_method_fn, {});
}
Variant ZipArchive::unchangeIndex(const Variant &index) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[3499]);
    }
    return this_.call(_method_fn, {index});
}
Variant ZipArchive::unchangeName(const Variant &name) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[3500]);
    }
    return this_.call(_method_fn, {name});
}
Variant ZipArchive::extractTo(const Variant &pathto, const Variant &files) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1122]);
    }
    return this_.call(_method_fn, {pathto, files});
}
Variant ZipArchive::getFromName(const Variant &name, const Variant &len, const Variant &flags) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[3501]);
    }
    return this_.call(_method_fn, {name, len, flags});
}
Variant ZipArchive::getFromIndex(const Variant &index, const Variant &len, const Variant &flags) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[3502]);
    }
    return this_.call(_method_fn, {index, len, flags});
}
Variant ZipArchive::getStreamIndex(const Variant &index, const Variant &flags) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[3503]);
    }
    return this_.call(_method_fn, {index, flags});
}
Variant ZipArchive::getStreamName(const Variant &name, const Variant &flags) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[3504]);
    }
    return this_.call(_method_fn, {name, flags});
}
Variant ZipArchive::getStream(const Variant &name) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[3505]);
    }
    return this_.call(_method_fn, {name});
}
Variant ZipArchive::setExternalAttributesName(const Variant &name,
                                              const Variant &opsys,
                                              const Variant &attr,
                                              const Variant &flags) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[3506]);
    }
    return this_.call(_method_fn, {name, opsys, attr, flags});
}
Variant ZipArchive::setExternalAttributesIndex(const Variant &index,
                                               const Variant &opsys,
                                               const Variant &attr,
                                               const Variant &flags) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[3507]);
    }
    return this_.call(_method_fn, {index, opsys, attr, flags});
}
Variant ZipArchive::getExternalAttributesName(const Variant &name,
                                              const Reference &opsys,
                                              const Reference &attr,
                                              const Variant &flags) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[3508]);
    }
    return this_.call(_method_fn, {name, &opsys, &attr, flags});
}
Variant ZipArchive::getExternalAttributesIndex(const Variant &index,
                                               const Reference &opsys,
                                               const Reference &attr,
                                               const Variant &flags) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[3509]);
    }
    return this_.call(_method_fn, {index, &opsys, &attr, flags});
}
Variant ZipArchive::setCompressionName(const Variant &name, const Variant &method, const Variant &compflags) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[3510]);
    }
    return this_.call(_method_fn, {name, method, compflags});
}
Variant ZipArchive::setCompressionIndex(const Variant &index, const Variant &method, const Variant &compflags) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[3511]);
    }
    return this_.call(_method_fn, {index, method, compflags});
}
Variant ZipArchive::setEncryptionName(const Variant &name, const Variant &method, const Variant &password) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[3512]);
    }
    return this_.call(_method_fn, {name, method, password});
}
Variant ZipArchive::setEncryptionIndex(const Variant &index, const Variant &method, const Variant &password) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[3513]);
    }
    return this_.call(_method_fn, {index, method, password});
}
Variant ZipArchive::registerProgressCallback(const Variant &rate, const Variant &callback) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[3514]);
    }
    return this_.call(_method_fn, {rate, callback});
}
Variant ZipArchive::registerCancelCallback(const Variant &callback) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[3515]);
    }
    return this_.call(_method_fn, {callback});
}
Variant ZipArchive::isCompressionMethodSupported(const Variant &method, const Variant &enc) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(LITERAL_STRING[3472], LITERAL_STRING[3517]);
    }
    return php::call(_method_fn, {method, enc});
}
Variant ZipArchive::isEncryptionMethodSupported(const Variant &method, const Variant &enc) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(LITERAL_STRING[3472], LITERAL_STRING[3519]);
    }
    return php::call(_method_fn, {method, enc});
}
}  // namespace php

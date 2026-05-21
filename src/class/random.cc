#include "phpx.h"
#include "phpx_class.h"
#include "class/random.h"

namespace php {
Random_RandomError::Random_RandomError(const Variant &message, const Variant &code, const Variant &previous) {
    this_ = newObject(LITERAL_STRING[1212], {message, code, previous});
}
Random_BrokenRandomEngineError::Random_BrokenRandomEngineError(const Variant &message,
                                                               const Variant &code,
                                                               const Variant &previous) {
    this_ = newObject(LITERAL_STRING[1213], {message, code, previous});
}
Random_RandomException::Random_RandomException(const Variant &message, const Variant &code, const Variant &previous) {
    this_ = newObject(LITERAL_STRING[1214], {message, code, previous});
}
Random_Engine_Mt19937::Random_Engine_Mt19937(const Variant &seed, const Variant &mode) {
    this_ = newObject(LITERAL_STRING[1215], {seed, mode});
}
Variant Random_Engine_Mt19937::generate() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1216]);
    }
    return this_.call(_method_fn, {});
}
Variant Random_Engine_Mt19937::__serialize() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[30]);
    }
    return this_.call(_method_fn, {});
}
Variant Random_Engine_Mt19937::__unserialize(const Variant &data) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[31]);
    }
    return this_.call(_method_fn, {data});
}
Variant Random_Engine_Mt19937::__debugInfo() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[129]);
    }
    return this_.call(_method_fn, {});
}
Random_Engine_PcgOneseq128XslRr64::Random_Engine_PcgOneseq128XslRr64(const Variant &seed) {
    this_ = newObject(LITERAL_STRING[1217], {seed});
}
Variant Random_Engine_PcgOneseq128XslRr64::generate() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1216]);
    }
    return this_.call(_method_fn, {});
}
Variant Random_Engine_PcgOneseq128XslRr64::jump(const Variant &advance) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1218]);
    }
    return this_.call(_method_fn, {advance});
}
Variant Random_Engine_PcgOneseq128XslRr64::__serialize() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[30]);
    }
    return this_.call(_method_fn, {});
}
Variant Random_Engine_PcgOneseq128XslRr64::__unserialize(const Variant &data) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[31]);
    }
    return this_.call(_method_fn, {data});
}
Variant Random_Engine_PcgOneseq128XslRr64::__debugInfo() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[129]);
    }
    return this_.call(_method_fn, {});
}
Random_Engine_Xoshiro256StarStar::Random_Engine_Xoshiro256StarStar(const Variant &seed) {
    this_ = newObject(LITERAL_STRING[1219], {seed});
}
Variant Random_Engine_Xoshiro256StarStar::generate() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1216]);
    }
    return this_.call(_method_fn, {});
}
Variant Random_Engine_Xoshiro256StarStar::jump() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1218]);
    }
    return this_.call(_method_fn, {});
}
Variant Random_Engine_Xoshiro256StarStar::jumpLong() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1220]);
    }
    return this_.call(_method_fn, {});
}
Variant Random_Engine_Xoshiro256StarStar::__serialize() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[30]);
    }
    return this_.call(_method_fn, {});
}
Variant Random_Engine_Xoshiro256StarStar::__unserialize(const Variant &data) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[31]);
    }
    return this_.call(_method_fn, {data});
}
Variant Random_Engine_Xoshiro256StarStar::__debugInfo() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[129]);
    }
    return this_.call(_method_fn, {});
}
Random_Engine_Secure::Random_Engine_Secure() {
    this_ = newObject(LITERAL_STRING[1221]);
}
Variant Random_Engine_Secure::generate() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1216]);
    }
    return this_.call(_method_fn, {});
}
Random_IntervalBoundary::Random_IntervalBoundary() {
    this_ = newObject(LITERAL_STRING[1232]);
}
Variant Random_IntervalBoundary::cases() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(LITERAL_STRING[1234], LITERAL_STRING[334]);
    }
    return php::call(_method_fn, {});
}
Random_Randomizer::Random_Randomizer(const Variant &engine) {
    this_ = newObject(LITERAL_STRING[1222], {engine});
}
Variant Random_Randomizer::nextInt() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1223]);
    }
    return this_.call(_method_fn, {});
}
Variant Random_Randomizer::nextFloat() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1224]);
    }
    return this_.call(_method_fn, {});
}
Variant Random_Randomizer::getFloat(const Variant &min, const Variant &max, const Variant &boundary) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1225]);
    }
    return this_.call(_method_fn, {min, max, boundary});
}
Variant Random_Randomizer::getInt(const Variant &min, const Variant &max) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1226]);
    }
    return this_.call(_method_fn, {min, max});
}
Variant Random_Randomizer::getBytes(const Variant &length) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1227]);
    }
    return this_.call(_method_fn, {length});
}
Variant Random_Randomizer::getBytesFromString(const Variant &string, const Variant &length) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1228]);
    }
    return this_.call(_method_fn, {string, length});
}
Variant Random_Randomizer::shuffleArray(const Variant &array) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1229]);
    }
    return this_.call(_method_fn, {array});
}
Variant Random_Randomizer::shuffleBytes(const Variant &bytes) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1230]);
    }
    return this_.call(_method_fn, {bytes});
}
Variant Random_Randomizer::pickArrayKeys(const Variant &array, const Variant &num) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1231]);
    }
    return this_.call(_method_fn, {array, num});
}
Variant Random_Randomizer::__serialize() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[30]);
    }
    return this_.call(_method_fn, {});
}
Variant Random_Randomizer::__unserialize(const Variant &data) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[31]);
    }
    return this_.call(_method_fn, {data});
}
}  // namespace php

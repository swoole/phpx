#include "phpx.h"
#include "class/random.h"
#include "class/core.h"

namespace php::Random {
RandomError::RandomError(const Variant &message, const Variant &code, const Variant &previous) {
    this_ = newObject(LITERAL_STRING[1245], {message, code, previous});
}
BrokenRandomEngineError::BrokenRandomEngineError(const Variant &message, const Variant &code, const Variant &previous) {
    this_ = newObject(LITERAL_STRING[1246], {message, code, previous});
}
RandomException::RandomException(const Variant &message, const Variant &code, const Variant &previous) {
    this_ = newObject(LITERAL_STRING[1247], {message, code, previous});
}
IntervalBoundary::IntervalBoundary() {
    this_ = newObject(LITERAL_STRING[1265]);
}
Variant IntervalBoundary::cases() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(LITERAL_STRING[1265], LITERAL_STRING[361]);
    }
    return php::call(_method_fn, {});
}
Randomizer::Randomizer(const Variant &engine) {
    this_ = newObject(LITERAL_STRING[1255], {engine});
}
Variant Randomizer::nextInt() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1256]);
    }
    return this_.call(_method_fn, {});
}
Variant Randomizer::nextFloat() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1257]);
    }
    return this_.call(_method_fn, {});
}
Variant Randomizer::getFloat(const Variant &min, const Variant &max, const Variant &boundary) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1258]);
    }
    return this_.call(_method_fn, {min, max, boundary});
}
Variant Randomizer::getInt(const Variant &min, const Variant &max) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1259]);
    }
    return this_.call(_method_fn, {min, max});
}
Variant Randomizer::getBytes(const Variant &length) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1260]);
    }
    return this_.call(_method_fn, {length});
}
Variant Randomizer::getBytesFromString(const Variant &string, const Variant &length) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1261]);
    }
    return this_.call(_method_fn, {string, length});
}
Variant Randomizer::shuffleArray(const Variant &array) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1262]);
    }
    return this_.call(_method_fn, {array});
}
Variant Randomizer::shuffleBytes(const Variant &bytes) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1263]);
    }
    return this_.call(_method_fn, {bytes});
}
Variant Randomizer::pickArrayKeys(const Variant &array, const Variant &num) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1264]);
    }
    return this_.call(_method_fn, {array, num});
}
Variant Randomizer::__serialize() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[30]);
    }
    return this_.call(_method_fn, {});
}
Variant Randomizer::__unserialize(const Variant &data) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[31]);
    }
    return this_.call(_method_fn, {data});
}
}  // namespace php::Random
namespace php::Random::Engine {
Mt19937::Mt19937(const Variant &seed, const Variant &mode) {
    this_ = newObject(LITERAL_STRING[1248], {seed, mode});
}
Variant Mt19937::generate() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1249]);
    }
    return this_.call(_method_fn, {});
}
Variant Mt19937::__serialize() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[30]);
    }
    return this_.call(_method_fn, {});
}
Variant Mt19937::__unserialize(const Variant &data) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[31]);
    }
    return this_.call(_method_fn, {data});
}
Variant Mt19937::__debugInfo() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[157]);
    }
    return this_.call(_method_fn, {});
}
PcgOneseq128XslRr64::PcgOneseq128XslRr64(const Variant &seed) {
    this_ = newObject(LITERAL_STRING[1250], {seed});
}
Variant PcgOneseq128XslRr64::generate() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1249]);
    }
    return this_.call(_method_fn, {});
}
Variant PcgOneseq128XslRr64::jump(const Variant &advance) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1251]);
    }
    return this_.call(_method_fn, {advance});
}
Variant PcgOneseq128XslRr64::__serialize() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[30]);
    }
    return this_.call(_method_fn, {});
}
Variant PcgOneseq128XslRr64::__unserialize(const Variant &data) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[31]);
    }
    return this_.call(_method_fn, {data});
}
Variant PcgOneseq128XslRr64::__debugInfo() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[157]);
    }
    return this_.call(_method_fn, {});
}
Xoshiro256StarStar::Xoshiro256StarStar(const Variant &seed) {
    this_ = newObject(LITERAL_STRING[1252], {seed});
}
Variant Xoshiro256StarStar::generate() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1249]);
    }
    return this_.call(_method_fn, {});
}
Variant Xoshiro256StarStar::jump() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1251]);
    }
    return this_.call(_method_fn, {});
}
Variant Xoshiro256StarStar::jumpLong() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1253]);
    }
    return this_.call(_method_fn, {});
}
Variant Xoshiro256StarStar::__serialize() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[30]);
    }
    return this_.call(_method_fn, {});
}
Variant Xoshiro256StarStar::__unserialize(const Variant &data) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[31]);
    }
    return this_.call(_method_fn, {data});
}
Variant Xoshiro256StarStar::__debugInfo() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[157]);
    }
    return this_.call(_method_fn, {});
}
Secure::Secure() {
    this_ = newObject(LITERAL_STRING[1254]);
}
Variant Secure::generate() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1249]);
    }
    return this_.call(_method_fn, {});
}
}  // namespace php::Random::Engine

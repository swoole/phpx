#include "phpx.h"
#include "phpx_class.h"
#include "class/random.h"

namespace php::Random {
RandomError::RandomError(const Variant &message, const Variant &code, const Variant &previous) {
    this_ = newObject(LITERAL_STRING[1207], {message, code, previous});
}
BrokenRandomEngineError::BrokenRandomEngineError(const Variant &message, const Variant &code, const Variant &previous) {
    this_ = newObject(LITERAL_STRING[1208], {message, code, previous});
}
RandomException::RandomException(const Variant &message, const Variant &code, const Variant &previous) {
    this_ = newObject(LITERAL_STRING[1209], {message, code, previous});
}
IntervalBoundary::IntervalBoundary() {
    this_ = newObject(LITERAL_STRING[1227]);
}
Variant IntervalBoundary::cases() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(LITERAL_STRING[1227], LITERAL_STRING[333]);
    }
    return php::call(_method_fn, {});
}
Randomizer::Randomizer(const Variant &engine) {
    this_ = newObject(LITERAL_STRING[1217], {engine});
}
Variant Randomizer::nextInt() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1218]);
    }
    return this_.call(_method_fn, {});
}
Variant Randomizer::nextFloat() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1219]);
    }
    return this_.call(_method_fn, {});
}
Variant Randomizer::getFloat(const Variant &min, const Variant &max, const Variant &boundary) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1220]);
    }
    return this_.call(_method_fn, {min, max, boundary});
}
Variant Randomizer::getInt(const Variant &min, const Variant &max) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1221]);
    }
    return this_.call(_method_fn, {min, max});
}
Variant Randomizer::getBytes(const Variant &length) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1222]);
    }
    return this_.call(_method_fn, {length});
}
Variant Randomizer::getBytesFromString(const Variant &string, const Variant &length) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1223]);
    }
    return this_.call(_method_fn, {string, length});
}
Variant Randomizer::shuffleArray(const Variant &array) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1224]);
    }
    return this_.call(_method_fn, {array});
}
Variant Randomizer::shuffleBytes(const Variant &bytes) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1225]);
    }
    return this_.call(_method_fn, {bytes});
}
Variant Randomizer::pickArrayKeys(const Variant &array, const Variant &num) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1226]);
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
    this_ = newObject(LITERAL_STRING[1210], {seed, mode});
}
Variant Mt19937::generate() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1211]);
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
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[129]);
    }
    return this_.call(_method_fn, {});
}
PcgOneseq128XslRr64::PcgOneseq128XslRr64(const Variant &seed) {
    this_ = newObject(LITERAL_STRING[1212], {seed});
}
Variant PcgOneseq128XslRr64::generate() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1211]);
    }
    return this_.call(_method_fn, {});
}
Variant PcgOneseq128XslRr64::jump(const Variant &advance) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1213]);
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
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[129]);
    }
    return this_.call(_method_fn, {});
}
Xoshiro256StarStar::Xoshiro256StarStar(const Variant &seed) {
    this_ = newObject(LITERAL_STRING[1214], {seed});
}
Variant Xoshiro256StarStar::generate() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1211]);
    }
    return this_.call(_method_fn, {});
}
Variant Xoshiro256StarStar::jump() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1213]);
    }
    return this_.call(_method_fn, {});
}
Variant Xoshiro256StarStar::jumpLong() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1215]);
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
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[129]);
    }
    return this_.call(_method_fn, {});
}
Secure::Secure() {
    this_ = newObject(LITERAL_STRING[1216]);
}
Variant Secure::generate() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1211]);
    }
    return this_.call(_method_fn, {});
}
}  // namespace php::Random::Engine

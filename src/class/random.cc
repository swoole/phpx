#include "phpx.h"
#include "class/random.h"

namespace php {
Random_RandomError::Random_RandomError(const Variant &message, const Variant &code, const Variant &previous) {
    this_ = newObject("Random\\RandomError", message, code, previous);
}

Variant Random_RandomError::__wakeup() {
    return this_.exec("__wakeup");
}

Variant Random_RandomError::getMessage() {
    return this_.exec("getMessage");
}

Variant Random_RandomError::getCode() {
    return this_.exec("getCode");
}

Variant Random_RandomError::getFile() {
    return this_.exec("getFile");
}

Variant Random_RandomError::getLine() {
    return this_.exec("getLine");
}

Variant Random_RandomError::getTrace() {
    return this_.exec("getTrace");
}

Variant Random_RandomError::getPrevious() {
    return this_.exec("getPrevious");
}

Variant Random_RandomError::getTraceAsString() {
    return this_.exec("getTraceAsString");
}

Variant Random_RandomError::__toString() {
    return this_.exec("__toString");
}


Random_BrokenRandomEngineError::Random_BrokenRandomEngineError(const Variant &message, const Variant &code, const Variant &previous) {
    this_ = newObject("Random\\BrokenRandomEngineError", message, code, previous);
}

Variant Random_BrokenRandomEngineError::__wakeup() {
    return this_.exec("__wakeup");
}

Variant Random_BrokenRandomEngineError::getMessage() {
    return this_.exec("getMessage");
}

Variant Random_BrokenRandomEngineError::getCode() {
    return this_.exec("getCode");
}

Variant Random_BrokenRandomEngineError::getFile() {
    return this_.exec("getFile");
}

Variant Random_BrokenRandomEngineError::getLine() {
    return this_.exec("getLine");
}

Variant Random_BrokenRandomEngineError::getTrace() {
    return this_.exec("getTrace");
}

Variant Random_BrokenRandomEngineError::getPrevious() {
    return this_.exec("getPrevious");
}

Variant Random_BrokenRandomEngineError::getTraceAsString() {
    return this_.exec("getTraceAsString");
}

Variant Random_BrokenRandomEngineError::__toString() {
    return this_.exec("__toString");
}


Random_RandomException::Random_RandomException(const Variant &message, const Variant &code, const Variant &previous) {
    this_ = newObject("Random\\RandomException", message, code, previous);
}

Variant Random_RandomException::__wakeup() {
    return this_.exec("__wakeup");
}

Variant Random_RandomException::getMessage() {
    return this_.exec("getMessage");
}

Variant Random_RandomException::getCode() {
    return this_.exec("getCode");
}

Variant Random_RandomException::getFile() {
    return this_.exec("getFile");
}

Variant Random_RandomException::getLine() {
    return this_.exec("getLine");
}

Variant Random_RandomException::getTrace() {
    return this_.exec("getTrace");
}

Variant Random_RandomException::getPrevious() {
    return this_.exec("getPrevious");
}

Variant Random_RandomException::getTraceAsString() {
    return this_.exec("getTraceAsString");
}

Variant Random_RandomException::__toString() {
    return this_.exec("__toString");
}


Random_Engine_Mt19937::Random_Engine_Mt19937(const Variant &seed, const Variant &mode) {
    this_ = newObject("Random\\Engine\\Mt19937", seed, mode);
}

Variant Random_Engine_Mt19937::generate() {
    return this_.exec("generate");
}

Variant Random_Engine_Mt19937::__serialize() {
    return this_.exec("__serialize");
}

Variant Random_Engine_Mt19937::__unserialize(const Variant &data) {
    return this_.exec("__unserialize", data);
}

Variant Random_Engine_Mt19937::__debugInfo() {
    return this_.exec("__debugInfo");
}


Random_Engine_PcgOneseq128XslRr64::Random_Engine_PcgOneseq128XslRr64(const Variant &seed) {
    this_ = newObject("Random\\Engine\\PcgOneseq128XslRr64", seed);
}

Variant Random_Engine_PcgOneseq128XslRr64::generate() {
    return this_.exec("generate");
}

Variant Random_Engine_PcgOneseq128XslRr64::jump(const Variant &advance) {
    return this_.exec("jump", advance);
}

Variant Random_Engine_PcgOneseq128XslRr64::__serialize() {
    return this_.exec("__serialize");
}

Variant Random_Engine_PcgOneseq128XslRr64::__unserialize(const Variant &data) {
    return this_.exec("__unserialize", data);
}

Variant Random_Engine_PcgOneseq128XslRr64::__debugInfo() {
    return this_.exec("__debugInfo");
}


Random_Engine_Xoshiro256StarStar::Random_Engine_Xoshiro256StarStar(const Variant &seed) {
    this_ = newObject("Random\\Engine\\Xoshiro256StarStar", seed);
}

Variant Random_Engine_Xoshiro256StarStar::generate() {
    return this_.exec("generate");
}

Variant Random_Engine_Xoshiro256StarStar::jump() {
    return this_.exec("jump");
}

Variant Random_Engine_Xoshiro256StarStar::jumpLong() {
    return this_.exec("jumpLong");
}

Variant Random_Engine_Xoshiro256StarStar::__serialize() {
    return this_.exec("__serialize");
}

Variant Random_Engine_Xoshiro256StarStar::__unserialize(const Variant &data) {
    return this_.exec("__unserialize", data);
}

Variant Random_Engine_Xoshiro256StarStar::__debugInfo() {
    return this_.exec("__debugInfo");
}


Variant Random_Engine_Secure::generate() {
    return this_.exec("generate");
}


Random_Randomizer::Random_Randomizer(const Variant &engine) {
    this_ = newObject("Random\\Randomizer", engine);
}

Variant Random_Randomizer::nextInt() {
    return this_.exec("nextInt");
}

Variant Random_Randomizer::nextFloat() {
    return this_.exec("nextFloat");
}

Variant Random_Randomizer::getFloat(const Variant &min, const Variant &max, const Object &boundary) {
    return this_.exec("getFloat", min, max, boundary);
}

Variant Random_Randomizer::getInt(const Variant &min, const Variant &max) {
    return this_.exec("getInt", min, max);
}

Variant Random_Randomizer::getBytes(const Variant &length) {
    return this_.exec("getBytes", length);
}

Variant Random_Randomizer::getBytesFromString(const Variant &string, const Variant &length) {
    return this_.exec("getBytesFromString", string, length);
}

Variant Random_Randomizer::shuffleArray(const Variant &array) {
    return this_.exec("shuffleArray", array);
}

Variant Random_Randomizer::shuffleBytes(const Variant &bytes) {
    return this_.exec("shuffleBytes", bytes);
}

Variant Random_Randomizer::pickArrayKeys(const Variant &array, const Variant &num) {
    return this_.exec("pickArrayKeys", array, num);
}

Variant Random_Randomizer::__serialize() {
    return this_.exec("__serialize");
}

Variant Random_Randomizer::__unserialize(const Variant &data) {
    return this_.exec("__unserialize", data);
}


Variant Random_IntervalBoundary::cases() {
    static Variant fn { ZEND_STRL("Random_IntervalBoundary::cases"), true };
    return fn();
}


}

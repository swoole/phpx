#include "phpx.h"
#include "class/random.h"

namespace php {
Random_RandomError::Random_RandomError(const Variant &message, const Variant &code, const Variant &previous) {
    _this = newObject("Random\\RandomError", message, code, previous);
}

Variant Random_RandomError::__wakeup() {
    return _this.exec("__wakeup");
}

Variant Random_RandomError::getMessage() {
    return _this.exec("getMessage");
}

Variant Random_RandomError::getCode() {
    return _this.exec("getCode");
}

Variant Random_RandomError::getFile() {
    return _this.exec("getFile");
}

Variant Random_RandomError::getLine() {
    return _this.exec("getLine");
}

Variant Random_RandomError::getTrace() {
    return _this.exec("getTrace");
}

Variant Random_RandomError::getPrevious() {
    return _this.exec("getPrevious");
}

Variant Random_RandomError::getTraceAsString() {
    return _this.exec("getTraceAsString");
}

Variant Random_RandomError::__toString() {
    return _this.exec("__toString");
}


Random_BrokenRandomEngineError::Random_BrokenRandomEngineError(const Variant &message, const Variant &code, const Variant &previous) {
    _this = newObject("Random\\BrokenRandomEngineError", message, code, previous);
}

Variant Random_BrokenRandomEngineError::__wakeup() {
    return _this.exec("__wakeup");
}

Variant Random_BrokenRandomEngineError::getMessage() {
    return _this.exec("getMessage");
}

Variant Random_BrokenRandomEngineError::getCode() {
    return _this.exec("getCode");
}

Variant Random_BrokenRandomEngineError::getFile() {
    return _this.exec("getFile");
}

Variant Random_BrokenRandomEngineError::getLine() {
    return _this.exec("getLine");
}

Variant Random_BrokenRandomEngineError::getTrace() {
    return _this.exec("getTrace");
}

Variant Random_BrokenRandomEngineError::getPrevious() {
    return _this.exec("getPrevious");
}

Variant Random_BrokenRandomEngineError::getTraceAsString() {
    return _this.exec("getTraceAsString");
}

Variant Random_BrokenRandomEngineError::__toString() {
    return _this.exec("__toString");
}


Random_RandomException::Random_RandomException(const Variant &message, const Variant &code, const Variant &previous) {
    _this = newObject("Random\\RandomException", message, code, previous);
}

Variant Random_RandomException::__wakeup() {
    return _this.exec("__wakeup");
}

Variant Random_RandomException::getMessage() {
    return _this.exec("getMessage");
}

Variant Random_RandomException::getCode() {
    return _this.exec("getCode");
}

Variant Random_RandomException::getFile() {
    return _this.exec("getFile");
}

Variant Random_RandomException::getLine() {
    return _this.exec("getLine");
}

Variant Random_RandomException::getTrace() {
    return _this.exec("getTrace");
}

Variant Random_RandomException::getPrevious() {
    return _this.exec("getPrevious");
}

Variant Random_RandomException::getTraceAsString() {
    return _this.exec("getTraceAsString");
}

Variant Random_RandomException::__toString() {
    return _this.exec("__toString");
}


Random_Engine_Mt19937::Random_Engine_Mt19937(const Variant &seed, const Variant &mode) {
    _this = newObject("Random\\Engine\\Mt19937", seed, mode);
}

Variant Random_Engine_Mt19937::generate() {
    return _this.exec("generate");
}

Variant Random_Engine_Mt19937::__serialize() {
    return _this.exec("__serialize");
}

Variant Random_Engine_Mt19937::__unserialize(const Variant &data) {
    return _this.exec("__unserialize", data);
}

Variant Random_Engine_Mt19937::__debugInfo() {
    return _this.exec("__debugInfo");
}


Random_Engine_PcgOneseq128XslRr64::Random_Engine_PcgOneseq128XslRr64(const Variant &seed) {
    _this = newObject("Random\\Engine\\PcgOneseq128XslRr64", seed);
}

Variant Random_Engine_PcgOneseq128XslRr64::generate() {
    return _this.exec("generate");
}

Variant Random_Engine_PcgOneseq128XslRr64::jump(const Variant &advance) {
    return _this.exec("jump", advance);
}

Variant Random_Engine_PcgOneseq128XslRr64::__serialize() {
    return _this.exec("__serialize");
}

Variant Random_Engine_PcgOneseq128XslRr64::__unserialize(const Variant &data) {
    return _this.exec("__unserialize", data);
}

Variant Random_Engine_PcgOneseq128XslRr64::__debugInfo() {
    return _this.exec("__debugInfo");
}


Random_Engine_Xoshiro256StarStar::Random_Engine_Xoshiro256StarStar(const Variant &seed) {
    _this = newObject("Random\\Engine\\Xoshiro256StarStar", seed);
}

Variant Random_Engine_Xoshiro256StarStar::generate() {
    return _this.exec("generate");
}

Variant Random_Engine_Xoshiro256StarStar::jump() {
    return _this.exec("jump");
}

Variant Random_Engine_Xoshiro256StarStar::jumpLong() {
    return _this.exec("jumpLong");
}

Variant Random_Engine_Xoshiro256StarStar::__serialize() {
    return _this.exec("__serialize");
}

Variant Random_Engine_Xoshiro256StarStar::__unserialize(const Variant &data) {
    return _this.exec("__unserialize", data);
}

Variant Random_Engine_Xoshiro256StarStar::__debugInfo() {
    return _this.exec("__debugInfo");
}


Variant Random_Engine_Secure::generate() {
    return _this.exec("generate");
}


Random_Randomizer::Random_Randomizer(const Variant &engine) {
    _this = newObject("Random\\Randomizer", engine);
}

Variant Random_Randomizer::nextInt() {
    return _this.exec("nextInt");
}

Variant Random_Randomizer::getInt(const Variant &min, const Variant &max) {
    return _this.exec("getInt", min, max);
}

Variant Random_Randomizer::getBytes(const Variant &length) {
    return _this.exec("getBytes", length);
}

Variant Random_Randomizer::shuffleArray(const Variant &array) {
    return _this.exec("shuffleArray", array);
}

Variant Random_Randomizer::shuffleBytes(const Variant &bytes) {
    return _this.exec("shuffleBytes", bytes);
}

Variant Random_Randomizer::pickArrayKeys(const Variant &array, const Variant &num) {
    return _this.exec("pickArrayKeys", array, num);
}

Variant Random_Randomizer::__serialize() {
    return _this.exec("__serialize");
}

Variant Random_Randomizer::__unserialize(const Variant &data) {
    return _this.exec("__unserialize", data);
}


}

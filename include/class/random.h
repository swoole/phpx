#pragma once

#include "phpx.h"
#include "phpx_literal_string.h"
#include "class/core.h"

namespace php {
namespace Random {
class RandomError;
class BrokenRandomEngineError;
class RandomException;
class IntervalBoundary;
class Randomizer;
}  // namespace Random
namespace Random::Engine {
class Mt19937;
class PcgOneseq128XslRr64;
class Xoshiro256StarStar;
class Secure;
}  // namespace Random::Engine

namespace Random {

class RandomError : public Error {
  public:
    RandomError(const Variant &message = "", const Variant &code = 0, const Variant &previous = nullptr);
};

class BrokenRandomEngineError : public RandomError {
  public:
    BrokenRandomEngineError(const Variant &message = "", const Variant &code = 0, const Variant &previous = nullptr);
};

class RandomException : public Exception {
  public:
    RandomException(const Variant &message = "", const Variant &code = 0, const Variant &previous = nullptr);
};

class IntervalBoundary {
  protected:
    Object this_;

  public:
    Object getObject() const {
        return this_;
    }
    explicit IntervalBoundary(const Object &obj) : this_(obj) {}
    IntervalBoundary();
    static Variant cases();
};

class Randomizer {
  protected:
    Object this_;

  public:
    Object getObject() const {
        return this_;
    }
    Randomizer(const Variant &engine = nullptr);
    Variant nextInt();
    Variant nextFloat();
    Variant getFloat(const Variant &min, const Variant &max, const Variant &boundary = {});
    Variant getInt(const Variant &min, const Variant &max);
    Variant getBytes(const Variant &length);
    Variant getBytesFromString(const Variant &string, const Variant &length);
    Variant shuffleArray(const Variant &array);
    Variant shuffleBytes(const Variant &bytes);
    Variant pickArrayKeys(const Variant &array, const Variant &num);
    Variant __serialize();
    Variant __unserialize(const Variant &data);
};

}  // namespace Random
namespace Random::Engine {

class Mt19937 {
  protected:
    Object this_;

  public:
    Object getObject() const {
        return this_;
    }
    Mt19937(const Variant &seed = nullptr, const Variant &mode = 0);
    Variant generate();
    Variant __serialize();
    Variant __unserialize(const Variant &data);
    Variant __debugInfo();
};

class PcgOneseq128XslRr64 {
  protected:
    Object this_;

  public:
    Object getObject() const {
        return this_;
    }
    PcgOneseq128XslRr64(const Variant &seed = nullptr);
    Variant generate();
    Variant jump(const Variant &advance);
    Variant __serialize();
    Variant __unserialize(const Variant &data);
    Variant __debugInfo();
};

class Xoshiro256StarStar {
  protected:
    Object this_;

  public:
    Object getObject() const {
        return this_;
    }
    Xoshiro256StarStar(const Variant &seed = nullptr);
    Variant generate();
    Variant jump();
    Variant jumpLong();
    Variant __serialize();
    Variant __unserialize(const Variant &data);
    Variant __debugInfo();
};

class Secure {
  protected:
    Object this_;

  public:
    Object getObject() const {
        return this_;
    }
    explicit Secure(const Object &obj) : this_(obj) {}
    Secure();
    Variant generate();
};

}  // namespace Random::Engine
}  // namespace php

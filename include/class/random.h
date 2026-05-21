#pragma once

#include "phpx.h"
#include "phpx_literal_string.h"
#include "class/core.h"

namespace php {
class Random_RandomError;
class Random_BrokenRandomEngineError;
class Random_RandomException;
class Random_Engine_Mt19937;
class Random_Engine_PcgOneseq128XslRr64;
class Random_Engine_Xoshiro256StarStar;
class Random_Engine_Secure;
class Random_IntervalBoundary;
class Random_Randomizer;

class Random_RandomError : public Error {
  public:
    Random_RandomError(const Variant &message = "", const Variant &code = 0, const Variant &previous = {});
};

class Random_BrokenRandomEngineError : public Random_RandomError {
  public:
    Random_BrokenRandomEngineError(const Variant &message = "", const Variant &code = 0, const Variant &previous = {});
};

class Random_RandomException : public Exception {
  public:
    Random_RandomException(const Variant &message = "", const Variant &code = 0, const Variant &previous = {});
};

class Random_Engine_Mt19937 {
  protected:
    Object this_;

  public:
    Object getObject() const {
        return this_;
    }
    Random_Engine_Mt19937(const Variant &seed = {}, const Variant &mode = 0);
    Variant generate();
    Variant __serialize();
    Variant __unserialize(const Variant &data);
    Variant __debugInfo();
};

class Random_Engine_PcgOneseq128XslRr64 {
  protected:
    Object this_;

  public:
    Object getObject() const {
        return this_;
    }
    Random_Engine_PcgOneseq128XslRr64(const Variant &seed = {});
    Variant generate();
    Variant jump(const Variant &advance);
    Variant __serialize();
    Variant __unserialize(const Variant &data);
    Variant __debugInfo();
};

class Random_Engine_Xoshiro256StarStar {
  protected:
    Object this_;

  public:
    Object getObject() const {
        return this_;
    }
    Random_Engine_Xoshiro256StarStar(const Variant &seed = {});
    Variant generate();
    Variant jump();
    Variant jumpLong();
    Variant __serialize();
    Variant __unserialize(const Variant &data);
    Variant __debugInfo();
};

class Random_Engine_Secure {
  protected:
    Object this_;

  public:
    Object getObject() const {
        return this_;
    }
    explicit Random_Engine_Secure(const Object &obj) : this_(obj) {}
    Random_Engine_Secure();
    Variant generate();
};

class Random_IntervalBoundary {
  protected:
    Object this_;

  public:
    Object getObject() const {
        return this_;
    }
    explicit Random_IntervalBoundary(const Object &obj) : this_(obj) {}
    Random_IntervalBoundary();
    static Variant cases();
};

class Random_Randomizer {
  protected:
    Object this_;

  public:
    Object getObject() const {
        return this_;
    }
    Random_Randomizer(const Variant &engine = {});
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

}  // namespace php

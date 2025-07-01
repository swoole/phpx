namespace php {
class Random_RandomError {
    Object _this;
  public:
    Random_RandomError(const Variant &message = "", const Variant &code = 0, const Variant &previous = {});
    Variant __wakeup();
    Variant getMessage();
    Variant getCode();
    Variant getFile();
    Variant getLine();
    Variant getTrace();
    Variant getPrevious();
    Variant getTraceAsString();
    Variant __toString();
};

class Random_BrokenRandomEngineError {
    Object _this;
  public:
    Random_BrokenRandomEngineError(const Variant &message = "", const Variant &code = 0, const Variant &previous = {});
    Variant __wakeup();
    Variant getMessage();
    Variant getCode();
    Variant getFile();
    Variant getLine();
    Variant getTrace();
    Variant getPrevious();
    Variant getTraceAsString();
    Variant __toString();
};

class Random_RandomException {
    Object _this;
  public:
    Random_RandomException(const Variant &message = "", const Variant &code = 0, const Variant &previous = {});
    Variant __wakeup();
    Variant getMessage();
    Variant getCode();
    Variant getFile();
    Variant getLine();
    Variant getTrace();
    Variant getPrevious();
    Variant getTraceAsString();
    Variant __toString();
};

class Random_Engine_Mt19937 {
    Object _this;
  public:
    Random_Engine_Mt19937(const Variant &seed = {}, const Variant &mode = 0);
    Variant generate();
    Variant __serialize();
    Variant __unserialize(const Variant &data);
    Variant __debugInfo();
};

class Random_Engine_PcgOneseq128XslRr64 {
    Object _this;
  public:
    Random_Engine_PcgOneseq128XslRr64(const Variant &seed = {});
    Variant generate();
    Variant jump(const Variant &advance);
    Variant __serialize();
    Variant __unserialize(const Variant &data);
    Variant __debugInfo();
};

class Random_Engine_Xoshiro256StarStar {
    Object _this;
  public:
    Random_Engine_Xoshiro256StarStar(const Variant &seed = {});
    Variant generate();
    Variant jump();
    Variant jumpLong();
    Variant __serialize();
    Variant __unserialize(const Variant &data);
    Variant __debugInfo();
};

class Random_Engine_Secure {
    Object _this;
  public:
    Variant generate();
};

class Random_Randomizer {
    Object _this;
  public:
    Random_Randomizer(const Variant &engine = {});
    Variant nextInt();
    Variant getInt(const Variant &min, const Variant &max);
    Variant getBytes(const Variant &length);
    Variant shuffleArray(const Variant &array);
    Variant shuffleBytes(const Variant &bytes);
    Variant pickArrayKeys(const Variant &array, const Variant &num);
    Variant __serialize();
    Variant __unserialize(const Variant &data);
};

}

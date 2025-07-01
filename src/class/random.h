namespace php {
class Random_RandomError {
  private:
    Variant _this;
  public:
    Random_RandomError(const std::initializer_list<Variant> &args);
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
  private:
    Variant _this;
  public:
    Random_BrokenRandomEngineError(const std::initializer_list<Variant> &args);
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
  private:
    Variant _this;
  public:
    Random_RandomException(const std::initializer_list<Variant> &args);
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
  private:
    Variant _this;
  public:
    Random_Engine_Mt19937(const std::initializer_list<Variant> &args);
    Variant generate();
    Variant __serialize();
    Variant __unserialize(const std::initializer_list<Variant> &args);
    Variant __debugInfo();
};

class Random_Engine_PcgOneseq128XslRr64 {
  private:
    Variant _this;
  public:
    Random_Engine_PcgOneseq128XslRr64(const std::initializer_list<Variant> &args);
    Variant generate();
    Variant jump(const std::initializer_list<Variant> &args);
    Variant __serialize();
    Variant __unserialize(const std::initializer_list<Variant> &args);
    Variant __debugInfo();
};

class Random_Engine_Xoshiro256StarStar {
  private:
    Variant _this;
  public:
    Random_Engine_Xoshiro256StarStar(const std::initializer_list<Variant> &args);
    Variant generate();
    Variant jump();
    Variant jumpLong();
    Variant __serialize();
    Variant __unserialize(const std::initializer_list<Variant> &args);
    Variant __debugInfo();
};

class Random_Engine_Secure {
  private:
    Variant _this;
  public:
    Variant generate();
};

class Random_Randomizer {
  private:
    Variant _this;
  public:
    Random_Randomizer(const std::initializer_list<Variant> &args);
    Variant nextInt();
    Variant getInt(const std::initializer_list<Variant> &args);
    Variant getBytes(const std::initializer_list<Variant> &args);
    Variant shuffleArray(const std::initializer_list<Variant> &args);
    Variant shuffleBytes(const std::initializer_list<Variant> &args);
    Variant pickArrayKeys(const std::initializer_list<Variant> &args);
    Variant __serialize();
    Variant __unserialize(const std::initializer_list<Variant> &args);
};

}

namespace php {
class HashContext {
  private:
    Variant _this;
  public:
    Variant __serialize();
    Variant __unserialize(const std::initializer_list<Variant> &args);
};

}

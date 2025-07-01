namespace php {
class SessionHandler {
  private:
    Variant _this;
  public:
    Variant open(const std::initializer_list<Variant> &args);
    Variant close();
    Variant read(const std::initializer_list<Variant> &args);
    Variant write(const std::initializer_list<Variant> &args);
    Variant destroy(const std::initializer_list<Variant> &args);
    Variant gc(const std::initializer_list<Variant> &args);
    Variant create_sid();
};

}

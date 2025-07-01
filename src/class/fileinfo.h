namespace php {
class finfo {
  private:
    Variant _this;
  public:
    finfo(const std::initializer_list<Variant> &args);
    Variant file(const std::initializer_list<Variant> &args);
    Variant buffer(const std::initializer_list<Variant> &args);
    Variant set_flags(const std::initializer_list<Variant> &args);
};

}

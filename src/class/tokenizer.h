namespace php {
class PhpToken {
  private:
    Variant _this;
  public:
    static Variant tokenize(const std::initializer_list<Variant> &args);
    PhpToken(const std::initializer_list<Variant> &args);
    Variant is(const std::initializer_list<Variant> &args);
    Variant isIgnorable();
    Variant getTokenName();
    Variant __toString();
};

}

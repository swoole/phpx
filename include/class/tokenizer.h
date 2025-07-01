namespace php {
class PhpToken {
    Object _this;
  public:
    static Variant tokenize(const Variant &code, const Variant &flags = 0);
    PhpToken(const Variant &id, const Variant &text, const Variant &line = -1, const Variant &pos = -1);
    Variant is(const Variant &kind);
    Variant isIgnorable();
    Variant getTokenName();
    Variant __toString();
};

}

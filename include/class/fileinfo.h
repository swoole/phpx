namespace php {
class finfo {
    Object _this;
  public:
    finfo(const Variant &flags = 0, const Variant &magic_database = {});
    Variant file(const Variant &filename, const Variant &flags = 0, const Variant &context = {});
    Variant buffer(const Variant &string, const Variant &flags = 0, const Variant &context = {});
    Variant set_flags(const Variant &flags);
};

}

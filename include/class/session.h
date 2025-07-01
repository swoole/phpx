namespace php {
class SessionHandler {
    Object _this;
  public:
    Variant open(const Variant &path, const Variant &name);
    Variant close();
    Variant read(const Variant &id);
    Variant write(const Variant &id, const Variant &data);
    Variant destroy(const Variant &id);
    Variant gc(const Variant &max_lifetime);
    Variant create_sid();
};

}

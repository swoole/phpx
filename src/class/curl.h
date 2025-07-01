namespace php {
class CURLFile {
  private:
    Variant _this;
  public:
    CURLFile(const std::initializer_list<Variant> &args);
    Variant getFilename();
    Variant getMimeType();
    Variant getPostFilename();
    Variant setMimeType(const std::initializer_list<Variant> &args);
    Variant setPostFilename(const std::initializer_list<Variant> &args);
};

class CURLStringFile {
  private:
    Variant _this;
  public:
    CURLStringFile(const std::initializer_list<Variant> &args);
};

}

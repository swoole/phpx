namespace php {
class CURLFile {
    Object this_;
  public:
    CURLFile(const Variant &filename, const Variant &mime_type = {}, const Variant &posted_filename = {});
    Variant getFilename();
    Variant getMimeType();
    Variant getPostFilename();
    Variant setMimeType(const Variant &mime_type);
    Variant setPostFilename(const Variant &posted_filename);
};

class CURLStringFile {
    Object this_;
  public:
    CURLStringFile(const Variant &data, const Variant &postname, const Variant &mime = "application/octet-stream");
};

}

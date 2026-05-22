#pragma once

#include "phpx.h"
#include "phpx_literal_string.h"
#include "class/dom.h"

namespace php {
class XMLReader;

class XMLReader {
  protected:
    Object this_;

  public:
    Object getObject() const {
        return this_;
    }
    explicit XMLReader(const Object &obj) : this_(obj) {}
    static constexpr int NONE = 0;
    static constexpr int ELEMENT = 1;
    static constexpr int ATTRIBUTE = 2;
    static constexpr int TEXT = 3;
    static constexpr int CDATA = 4;
    static constexpr int ENTITY_REF = 5;
    static constexpr int ENTITY = 6;
    static constexpr int PI = 7;
    static constexpr int COMMENT = 8;
    static constexpr int DOC = 9;
    static constexpr int DOC_TYPE = 10;
    static constexpr int DOC_FRAGMENT = 11;
    static constexpr int NOTATION = 12;
    static constexpr int WHITESPACE = 13;
    static constexpr int SIGNIFICANT_WHITESPACE = 14;
    static constexpr int END_ELEMENT = 15;
    static constexpr int END_ENTITY = 16;
    static constexpr int XML_DECLARATION = 17;
    static constexpr int LOADDTD = 1;
    static constexpr int DEFAULTATTRS = 2;
    static constexpr int VALIDATE = 3;
    static constexpr int SUBST_ENTITIES = 4;

    XMLReader();
    Variant close();
    Variant getAttribute(const Variant &name);
    Variant getAttributeNo(const Variant &index);
    Variant getAttributeNs(const Variant &name, const Variant &namespace_);
    Variant getParserProperty(const Variant &property);
    Variant isValid();
    Variant lookupNamespace(const Variant &prefix);
    Variant moveToAttribute(const Variant &name);
    Variant moveToAttributeNo(const Variant &index);
    Variant moveToAttributeNs(const Variant &name, const Variant &namespace_);
    Variant moveToElement();
    Variant moveToFirstAttribute();
    Variant moveToNextAttribute();
    Variant read();
    Variant next(const Variant &name = nullptr);
    static Variant open(const Variant &uri, const Variant &encoding = nullptr, const Variant &flags = 0);
    static Variant fromUri(const Variant &uri, const Variant &encoding = nullptr, const Variant &flags = 0);
    static Variant fromStream(const Variant &stream,
                              const Variant &encoding = nullptr,
                              const Variant &flags = 0,
                              const Variant &document_uri = nullptr);
    Variant readInnerXml();
    Variant readOuterXml();
    Variant readString();
    Variant setSchema(const Variant &filename);
    Variant setParserProperty(const Variant &property, const Variant &value);
    Variant setRelaxNGSchema(const Variant &filename);
    Variant setRelaxNGSchemaSource(const Variant &source);
    static Variant XML(const Variant &source, const Variant &encoding = nullptr, const Variant &flags = 0);
    static Variant fromString(const Variant &source, const Variant &encoding = nullptr, const Variant &flags = 0);
    DOMNode expand(const Variant &base_node = nullptr);
};

}  // namespace php

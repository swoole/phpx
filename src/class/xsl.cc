#include "phpx.h"
#include "class/xsl.h"

namespace php {
Variant XSLTProcessor::importStylesheet(const Variant &stylesheet) {
    return _this.exec("importStylesheet", stylesheet);
}

Variant XSLTProcessor::transformToDoc(const Variant &document, const Variant &return_class) {
    return _this.exec("transformToDoc", document, return_class);
}

Variant XSLTProcessor::transformToUri(const Variant &document, const Variant &uri) {
    return _this.exec("transformToUri", document, uri);
}

Variant XSLTProcessor::transformToXml(const Variant &document) {
    return _this.exec("transformToXml", document);
}

Variant XSLTProcessor::setParameter(const Variant &_namespace, const Variant &name, const Variant &value) {
    return _this.exec("setParameter", _namespace, name, value);
}

Variant XSLTProcessor::getParameter(const Variant &_namespace, const Variant &name) {
    return _this.exec("getParameter", _namespace, name);
}

Variant XSLTProcessor::removeParameter(const Variant &_namespace, const Variant &name) {
    return _this.exec("removeParameter", _namespace, name);
}

Variant XSLTProcessor::hasExsltSupport() {
    return _this.exec("hasExsltSupport");
}

Variant XSLTProcessor::registerPHPFunctions(const Variant &functions) {
    return _this.exec("registerPHPFunctions", functions);
}

Variant XSLTProcessor::setProfiling(const Variant &filename) {
    return _this.exec("setProfiling", filename);
}

Variant XSLTProcessor::setSecurityPrefs(const Variant &preferences) {
    return _this.exec("setSecurityPrefs", preferences);
}

Variant XSLTProcessor::getSecurityPrefs() {
    return _this.exec("getSecurityPrefs");
}


}

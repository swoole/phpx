#include "phpx.h"
#include "class/xsl.h"

namespace php {
Variant XSLTProcessor::importStylesheet(const Variant &stylesheet) {
    return std::move(_this.exec("importStylesheet", stylesheet));
}

Variant XSLTProcessor::transformToDoc(const Variant &document, const Variant &return_class) {
    return std::move(_this.exec("transformToDoc", document, return_class));
}

Variant XSLTProcessor::transformToUri(const Variant &document, const Variant &uri) {
    return std::move(_this.exec("transformToUri", document, uri));
}

Variant XSLTProcessor::transformToXml(const Variant &document) {
    return std::move(_this.exec("transformToXml", document));
}

Variant XSLTProcessor::setParameter(const Variant &_namespace, const Variant &name, const Variant &value) {
    return std::move(_this.exec("setParameter", _namespace, name, value));
}

Variant XSLTProcessor::getParameter(const Variant &_namespace, const Variant &name) {
    return std::move(_this.exec("getParameter", _namespace, name));
}

Variant XSLTProcessor::removeParameter(const Variant &_namespace, const Variant &name) {
    return std::move(_this.exec("removeParameter", _namespace, name));
}

Variant XSLTProcessor::hasExsltSupport() {
    return std::move(_this.exec("hasExsltSupport"));
}

Variant XSLTProcessor::registerPHPFunctions(const Variant &functions) {
    return std::move(_this.exec("registerPHPFunctions", functions));
}

Variant XSLTProcessor::setProfiling(const Variant &filename) {
    return std::move(_this.exec("setProfiling", filename));
}

Variant XSLTProcessor::setSecurityPrefs(const Variant &preferences) {
    return std::move(_this.exec("setSecurityPrefs", preferences));
}

Variant XSLTProcessor::getSecurityPrefs() {
    return std::move(_this.exec("getSecurityPrefs"));
}


}

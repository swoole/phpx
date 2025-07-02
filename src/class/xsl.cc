#include "phpx.h"
#include "class/xsl.h"

namespace php {
Variant XSLTProcessor::importStylesheet(const Variant &stylesheet) {
    return this_.exec("importStylesheet", stylesheet);
}

Variant XSLTProcessor::transformToDoc(const Variant &document, const Variant &return_class) {
    return this_.exec("transformToDoc", document, return_class);
}

Variant XSLTProcessor::transformToUri(const Variant &document, const Variant &uri) {
    return this_.exec("transformToUri", document, uri);
}

Variant XSLTProcessor::transformToXml(const Variant &document) {
    return this_.exec("transformToXml", document);
}

Variant XSLTProcessor::setParameter(const Variant &_namespace, const Variant &name, const Variant &value) {
    return this_.exec("setParameter", _namespace, name, value);
}

Variant XSLTProcessor::getParameter(const Variant &_namespace, const Variant &name) {
    return this_.exec("getParameter", _namespace, name);
}

Variant XSLTProcessor::removeParameter(const Variant &_namespace, const Variant &name) {
    return this_.exec("removeParameter", _namespace, name);
}

Variant XSLTProcessor::hasExsltSupport() {
    return this_.exec("hasExsltSupport");
}

Variant XSLTProcessor::registerPHPFunctions(const Variant &functions) {
    return this_.exec("registerPHPFunctions", functions);
}

Variant XSLTProcessor::setProfiling(const Variant &filename) {
    return this_.exec("setProfiling", filename);
}

Variant XSLTProcessor::setSecurityPrefs(const Variant &preferences) {
    return this_.exec("setSecurityPrefs", preferences);
}

Variant XSLTProcessor::getSecurityPrefs() {
    return this_.exec("getSecurityPrefs");
}


}

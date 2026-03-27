#include "phpx.h"
#include "class/xsl.h"

namespace php {
Variant XSLTProcessor::importStylesheet(const Variant &stylesheet) {
    return this_.call(LITERAL_STRING[2494], {stylesheet});
}
Variant XSLTProcessor::transformToDoc(const Variant &document, const Variant &return_class) {
    return this_.call(LITERAL_STRING[2495], {document, return_class});
}
Variant XSLTProcessor::transformToUri(const Variant &document, const Variant &uri) {
    return this_.call(LITERAL_STRING[2496], {document, uri});
}
Variant XSLTProcessor::transformToXml(const Variant &document) {
    return this_.call(LITERAL_STRING[2497], {document});
}
Variant XSLTProcessor::setParameter(const Variant &_namespace, const Variant &name, const Variant &value) {
    return this_.call(LITERAL_STRING[2498], {_namespace, name, value});
}
Variant XSLTProcessor::getParameter(const Variant &_namespace, const Variant &name) {
    return this_.call(LITERAL_STRING[2499], {_namespace, name});
}
Variant XSLTProcessor::removeParameter(const Variant &_namespace, const Variant &name) {
    return this_.call(LITERAL_STRING[2500], {_namespace, name});
}
Variant XSLTProcessor::hasExsltSupport() {
    return this_.call(LITERAL_STRING[2501], {});
}
Variant XSLTProcessor::registerPHPFunctions(const Variant &functions) {
    return this_.call(LITERAL_STRING[2502], {functions});
}
Variant XSLTProcessor::registerPHPFunctionNS(const Variant &namespace_u_r_i,
                                             const Variant &name,
                                             const Variant &callable) {
    return this_.call(LITERAL_STRING[2503], {namespace_u_r_i, name, callable});
}
Variant XSLTProcessor::setProfiling(const Variant &filename) {
    return this_.call(LITERAL_STRING[2504], {filename});
}
Variant XSLTProcessor::setSecurityPrefs(const Variant &preferences) {
    return this_.call(LITERAL_STRING[2505], {preferences});
}
Variant XSLTProcessor::getSecurityPrefs() {
    return this_.call(LITERAL_STRING[2506], {});
}
}  // namespace php

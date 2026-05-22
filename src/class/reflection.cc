#include "phpx.h"
#include "phpx_class.h"
#include "class/reflection.h"

namespace php {
ReflectionException::ReflectionException(const Variant &message, const Variant &code, const Variant &previous) {
    this_ = newObject(LITERAL_STRING[1629], {message, code, previous});
}
Reflection::Reflection() {
    this_ = newObject(LITERAL_STRING[1630]);
}
Variant Reflection::getModifierNames(const Variant &modifiers) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(LITERAL_STRING[1630], LITERAL_STRING[1632]);
    }
    return php::call(_method_fn, {modifiers});
}
ReflectionGenerator::ReflectionGenerator(const Generator &generator) {
    this_ = newObject(LITERAL_STRING[1669], {generator.getObject()});
}
Variant ReflectionGenerator::getExecutingLine() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1670]);
    }
    return this_.call(_method_fn, {});
}
Variant ReflectionGenerator::getExecutingFile() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1671]);
    }
    return this_.call(_method_fn, {});
}
Variant ReflectionGenerator::getTrace(const Variant &options) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[130]);
    }
    return this_.call(_method_fn, {options});
}
Variant ReflectionGenerator::getFunction() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1672]);
    }
    return this_.call(_method_fn, {});
}
Variant ReflectionGenerator::getThis_() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1673]);
    }
    return this_.call(_method_fn, {});
}
Generator ReflectionGenerator::getExecutingGenerator() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1674]);
    }
    return Generator(Object(this_.call(_method_fn, {})));
}
Variant ReflectionGenerator::isClosed() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1675]);
    }
    return this_.call(_method_fn, {});
}
ReflectionNamedType::ReflectionNamedType() {
    this_ = newObject(LITERAL_STRING[1694]);
}
Variant ReflectionNamedType::getName() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[328]);
    }
    return this_.call(_method_fn, {});
}
Variant ReflectionNamedType::isBuiltin() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1695]);
    }
    return this_.call(_method_fn, {});
}
Variant ReflectionNamedType::allowsNull() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1686]);
    }
    return this_.call(_method_fn, {});
}
Variant ReflectionNamedType::__toString() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[29]);
    }
    return this_.call(_method_fn, {});
}
ReflectionUnionType::ReflectionUnionType() {
    this_ = newObject(LITERAL_STRING[1696]);
}
Variant ReflectionUnionType::getTypes() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1697]);
    }
    return this_.call(_method_fn, {});
}
Variant ReflectionUnionType::allowsNull() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1686]);
    }
    return this_.call(_method_fn, {});
}
Variant ReflectionUnionType::__toString() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[29]);
    }
    return this_.call(_method_fn, {});
}
ReflectionIntersectionType::ReflectionIntersectionType() {
    this_ = newObject(LITERAL_STRING[1698]);
}
Variant ReflectionIntersectionType::getTypes() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1697]);
    }
    return this_.call(_method_fn, {});
}
Variant ReflectionIntersectionType::allowsNull() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1686]);
    }
    return this_.call(_method_fn, {});
}
Variant ReflectionIntersectionType::__toString() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[29]);
    }
    return this_.call(_method_fn, {});
}
ReflectionExtension::ReflectionExtension(const Variant &name) {
    this_ = newObject(LITERAL_STRING[1780], {name});
}
Variant ReflectionExtension::__toString() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[29]);
    }
    return this_.call(_method_fn, {});
}
Variant ReflectionExtension::getName() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[328]);
    }
    return this_.call(_method_fn, {});
}
Variant ReflectionExtension::getVersion() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1129]);
    }
    return this_.call(_method_fn, {});
}
Variant ReflectionExtension::getFunctions() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1781]);
    }
    return this_.call(_method_fn, {});
}
Variant ReflectionExtension::getConstants() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1724]);
    }
    return this_.call(_method_fn, {});
}
Variant ReflectionExtension::getINIEntries() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1782]);
    }
    return this_.call(_method_fn, {});
}
Variant ReflectionExtension::getClasses() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1783]);
    }
    return this_.call(_method_fn, {});
}
Variant ReflectionExtension::getClassNames() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1784]);
    }
    return this_.call(_method_fn, {});
}
Variant ReflectionExtension::getDependencies() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1785]);
    }
    return this_.call(_method_fn, {});
}
Variant ReflectionExtension::info() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1370]);
    }
    return this_.call(_method_fn, {});
}
Variant ReflectionExtension::isPersistent() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1786]);
    }
    return this_.call(_method_fn, {});
}
Variant ReflectionExtension::isTemporary() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1787]);
    }
    return this_.call(_method_fn, {});
}
ReflectionZendExtension::ReflectionZendExtension(const Variant &name) {
    this_ = newObject(LITERAL_STRING[1788], {name});
}
Variant ReflectionZendExtension::__toString() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[29]);
    }
    return this_.call(_method_fn, {});
}
Variant ReflectionZendExtension::getName() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[328]);
    }
    return this_.call(_method_fn, {});
}
Variant ReflectionZendExtension::getVersion() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1129]);
    }
    return this_.call(_method_fn, {});
}
Variant ReflectionZendExtension::getAuthor() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1789]);
    }
    return this_.call(_method_fn, {});
}
Variant ReflectionZendExtension::getURL() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1790]);
    }
    return this_.call(_method_fn, {});
}
Variant ReflectionZendExtension::getCopyright() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1791]);
    }
    return this_.call(_method_fn, {});
}
Variant ReflectionReference::fromArrayElement(const Variant &array, const Variant &key) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(LITERAL_STRING[1793], LITERAL_STRING[1794]);
    }
    return php::call(_method_fn, {array, key});
}
Variant ReflectionReference::getId() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1795]);
    }
    return this_.call(_method_fn, {});
}
Variant ReflectionAttribute::getName() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[328]);
    }
    return this_.call(_method_fn, {});
}
Variant ReflectionAttribute::getTarget() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1796]);
    }
    return this_.call(_method_fn, {});
}
Variant ReflectionAttribute::isRepeated() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1797]);
    }
    return this_.call(_method_fn, {});
}
Variant ReflectionAttribute::getArguments() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1798]);
    }
    return this_.call(_method_fn, {});
}
Variant ReflectionAttribute::newInstance() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1738]);
    }
    return this_.call(_method_fn, {});
}
Variant ReflectionAttribute::__toString() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[29]);
    }
    return this_.call(_method_fn, {});
}
ReflectionFiber::ReflectionFiber(const Fiber &fiber) {
    this_ = newObject(LITERAL_STRING[1810], {fiber.getObject()});
}
Variant ReflectionFiber::getFiber() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1811]);
    }
    return this_.call(_method_fn, {});
}
Variant ReflectionFiber::getExecutingFile() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1671]);
    }
    return this_.call(_method_fn, {});
}
Variant ReflectionFiber::getExecutingLine() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1670]);
    }
    return this_.call(_method_fn, {});
}
Variant ReflectionFiber::getCallable() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1812]);
    }
    return this_.call(_method_fn, {});
}
Variant ReflectionFiber::getTrace(const Variant &options) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[130]);
    }
    return this_.call(_method_fn, {options});
}
ReflectionConstant::ReflectionConstant(const Variant &name) {
    this_ = newObject(LITERAL_STRING[1813], {name});
}
Variant ReflectionConstant::getName() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[328]);
    }
    return this_.call(_method_fn, {});
}
Variant ReflectionConstant::getNamespaceName() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1656]);
    }
    return this_.call(_method_fn, {});
}
Variant ReflectionConstant::getShortName() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1660]);
    }
    return this_.call(_method_fn, {});
}
Variant ReflectionConstant::getValue() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[175]);
    }
    return this_.call(_method_fn, {});
}
Variant ReflectionConstant::isDeprecated() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1641]);
    }
    return this_.call(_method_fn, {});
}
Variant ReflectionConstant::__toString() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[29]);
    }
    return this_.call(_method_fn, {});
}
PropertyHookType::PropertyHookType() {
    this_ = newObject(LITERAL_STRING[1814]);
}
Variant PropertyHookType::cases() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(LITERAL_STRING[1814], LITERAL_STRING[361]);
    }
    return php::call(_method_fn, {});
}
Variant PropertyHookType::from(const Variant &value) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(LITERAL_STRING[1814], LITERAL_STRING[363]);
    }
    return php::call(_method_fn, {value});
}
Variant PropertyHookType::tryFrom(const Variant &value) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(LITERAL_STRING[1814], LITERAL_STRING[365]);
    }
    return php::call(_method_fn, {value});
}
ReflectionFunction::ReflectionFunction(const Variant &function) {
    this_ = newObject(LITERAL_STRING[1633], {function});
}
Variant ReflectionFunction::__toString() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[29]);
    }
    return this_.call(_method_fn, {});
}
Variant ReflectionFunction::isAnonymous() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1634]);
    }
    return this_.call(_method_fn, {});
}
Variant ReflectionFunction::isDisabled() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1635]);
    }
    return this_.call(_method_fn, {});
}
Variant ReflectionFunction::invokeArgs(const Variant &args) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1637]);
    }
    return this_.call(_method_fn, {args});
}
Variant ReflectionFunction::getClosure() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1638]);
    }
    return this_.call(_method_fn, {});
}
Variant ReflectionFunction::inNamespace() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1639]);
    }
    return this_.call(_method_fn, {});
}
Variant ReflectionFunction::isClosure() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1640]);
    }
    return this_.call(_method_fn, {});
}
Variant ReflectionFunction::isDeprecated() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1641]);
    }
    return this_.call(_method_fn, {});
}
Variant ReflectionFunction::isInternal() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1642]);
    }
    return this_.call(_method_fn, {});
}
Variant ReflectionFunction::isUserDefined() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1643]);
    }
    return this_.call(_method_fn, {});
}
Variant ReflectionFunction::isGenerator() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1644]);
    }
    return this_.call(_method_fn, {});
}
Variant ReflectionFunction::isVariadic() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1645]);
    }
    return this_.call(_method_fn, {});
}
Variant ReflectionFunction::isStatic() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1646]);
    }
    return this_.call(_method_fn, {});
}
Variant ReflectionFunction::getClosureThis() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1647]);
    }
    return this_.call(_method_fn, {});
}
Variant ReflectionFunction::getClosureScopeClass() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1648]);
    }
    return this_.call(_method_fn, {});
}
Variant ReflectionFunction::getClosureCalledClass() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1649]);
    }
    return this_.call(_method_fn, {});
}
Variant ReflectionFunction::getClosureUsedVariables() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1650]);
    }
    return this_.call(_method_fn, {});
}
Variant ReflectionFunction::getDocComment() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1651]);
    }
    return this_.call(_method_fn, {});
}
Variant ReflectionFunction::getEndLine() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1652]);
    }
    return this_.call(_method_fn, {});
}
Variant ReflectionFunction::getExtension() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1653]);
    }
    return this_.call(_method_fn, {});
}
Variant ReflectionFunction::getExtensionName() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1654]);
    }
    return this_.call(_method_fn, {});
}
Variant ReflectionFunction::getFileName() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1655]);
    }
    return this_.call(_method_fn, {});
}
Variant ReflectionFunction::getName() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[328]);
    }
    return this_.call(_method_fn, {});
}
Variant ReflectionFunction::getNamespaceName() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1656]);
    }
    return this_.call(_method_fn, {});
}
Variant ReflectionFunction::getNumberOfParameters() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1657]);
    }
    return this_.call(_method_fn, {});
}
Variant ReflectionFunction::getNumberOfRequiredParameters() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1658]);
    }
    return this_.call(_method_fn, {});
}
Variant ReflectionFunction::getParameters() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1659]);
    }
    return this_.call(_method_fn, {});
}
Variant ReflectionFunction::getShortName() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1660]);
    }
    return this_.call(_method_fn, {});
}
Variant ReflectionFunction::getStartLine() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1661]);
    }
    return this_.call(_method_fn, {});
}
Variant ReflectionFunction::getStaticVariables() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1662]);
    }
    return this_.call(_method_fn, {});
}
Variant ReflectionFunction::returnsReference() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1663]);
    }
    return this_.call(_method_fn, {});
}
Variant ReflectionFunction::hasReturnType() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1664]);
    }
    return this_.call(_method_fn, {});
}
Variant ReflectionFunction::getReturnType() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1665]);
    }
    return this_.call(_method_fn, {});
}
Variant ReflectionFunction::hasTentativeReturnType() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1666]);
    }
    return this_.call(_method_fn, {});
}
Variant ReflectionFunction::getTentativeReturnType() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1667]);
    }
    return this_.call(_method_fn, {});
}
Variant ReflectionFunction::getAttributes(const Variant &name, const Variant &flags) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1668]);
    }
    return this_.call(_method_fn, {name, flags});
}
ReflectionParameter::ReflectionParameter(const Variant &function, const Variant &param) {
    this_ = newObject(LITERAL_STRING[1676], {function, param});
}
Variant ReflectionParameter::__toString() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[29]);
    }
    return this_.call(_method_fn, {});
}
Variant ReflectionParameter::getName() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[328]);
    }
    return this_.call(_method_fn, {});
}
Variant ReflectionParameter::isPassedByReference() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1677]);
    }
    return this_.call(_method_fn, {});
}
Variant ReflectionParameter::canBePassedByValue() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1678]);
    }
    return this_.call(_method_fn, {});
}
Variant ReflectionParameter::getDeclaringFunction() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1679]);
    }
    return this_.call(_method_fn, {});
}
Variant ReflectionParameter::getDeclaringClass() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1680]);
    }
    return this_.call(_method_fn, {});
}
Variant ReflectionParameter::getClass() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1681]);
    }
    return this_.call(_method_fn, {});
}
Variant ReflectionParameter::hasType() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1682]);
    }
    return this_.call(_method_fn, {});
}
Variant ReflectionParameter::getType() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1683]);
    }
    return this_.call(_method_fn, {});
}
Variant ReflectionParameter::isArray() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1684]);
    }
    return this_.call(_method_fn, {});
}
Variant ReflectionParameter::isCallable() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1685]);
    }
    return this_.call(_method_fn, {});
}
Variant ReflectionParameter::allowsNull() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1686]);
    }
    return this_.call(_method_fn, {});
}
Variant ReflectionParameter::getPosition() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1687]);
    }
    return this_.call(_method_fn, {});
}
Variant ReflectionParameter::isOptional() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1688]);
    }
    return this_.call(_method_fn, {});
}
Variant ReflectionParameter::isDefaultValueAvailable() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1689]);
    }
    return this_.call(_method_fn, {});
}
Variant ReflectionParameter::getDefaultValue() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1690]);
    }
    return this_.call(_method_fn, {});
}
Variant ReflectionParameter::isDefaultValueConstant() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1691]);
    }
    return this_.call(_method_fn, {});
}
Variant ReflectionParameter::getDefaultValueConstantName() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1692]);
    }
    return this_.call(_method_fn, {});
}
Variant ReflectionParameter::isVariadic() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1645]);
    }
    return this_.call(_method_fn, {});
}
Variant ReflectionParameter::isPromoted() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1693]);
    }
    return this_.call(_method_fn, {});
}
Variant ReflectionParameter::getAttributes(const Variant &name, const Variant &flags) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1668]);
    }
    return this_.call(_method_fn, {name, flags});
}
ReflectionMethod::ReflectionMethod(const Variant &object_or_method, const Variant &method) {
    this_ = newObject(LITERAL_STRING[1699], {object_or_method, method});
}
Variant ReflectionMethod::createFromMethodName(const Variant &method) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(LITERAL_STRING[1699], LITERAL_STRING[1701]);
    }
    return php::call(_method_fn, {method});
}
Variant ReflectionMethod::__toString() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[29]);
    }
    return this_.call(_method_fn, {});
}
Variant ReflectionMethod::isPublic() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1702]);
    }
    return this_.call(_method_fn, {});
}
Variant ReflectionMethod::isPrivate() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1703]);
    }
    return this_.call(_method_fn, {});
}
Variant ReflectionMethod::isProtected() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1704]);
    }
    return this_.call(_method_fn, {});
}
Variant ReflectionMethod::isAbstract() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1705]);
    }
    return this_.call(_method_fn, {});
}
Variant ReflectionMethod::isFinal() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1706]);
    }
    return this_.call(_method_fn, {});
}
Variant ReflectionMethod::isConstructor() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1707]);
    }
    return this_.call(_method_fn, {});
}
Variant ReflectionMethod::isDestructor() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1708]);
    }
    return this_.call(_method_fn, {});
}
Variant ReflectionMethod::getClosure(const Variant &object) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1638]);
    }
    return this_.call(_method_fn, {object});
}
Variant ReflectionMethod::getModifiers() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1709]);
    }
    return this_.call(_method_fn, {});
}
Variant ReflectionMethod::invokeArgs(const Variant &object, const Variant &args) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1637]);
    }
    return this_.call(_method_fn, {object, args});
}
Variant ReflectionMethod::getDeclaringClass() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1680]);
    }
    return this_.call(_method_fn, {});
}
Variant ReflectionMethod::getPrototype() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1710]);
    }
    return this_.call(_method_fn, {});
}
Variant ReflectionMethod::hasPrototype() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1711]);
    }
    return this_.call(_method_fn, {});
}
Variant ReflectionMethod::setAccessible(const Variant &accessible) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1712]);
    }
    return this_.call(_method_fn, {accessible});
}
Variant ReflectionMethod::inNamespace() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1639]);
    }
    return this_.call(_method_fn, {});
}
Variant ReflectionMethod::isClosure() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1640]);
    }
    return this_.call(_method_fn, {});
}
Variant ReflectionMethod::isDeprecated() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1641]);
    }
    return this_.call(_method_fn, {});
}
Variant ReflectionMethod::isInternal() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1642]);
    }
    return this_.call(_method_fn, {});
}
Variant ReflectionMethod::isUserDefined() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1643]);
    }
    return this_.call(_method_fn, {});
}
Variant ReflectionMethod::isGenerator() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1644]);
    }
    return this_.call(_method_fn, {});
}
Variant ReflectionMethod::isVariadic() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1645]);
    }
    return this_.call(_method_fn, {});
}
Variant ReflectionMethod::isStatic() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1646]);
    }
    return this_.call(_method_fn, {});
}
Variant ReflectionMethod::getClosureThis() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1647]);
    }
    return this_.call(_method_fn, {});
}
Variant ReflectionMethod::getClosureScopeClass() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1648]);
    }
    return this_.call(_method_fn, {});
}
Variant ReflectionMethod::getClosureCalledClass() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1649]);
    }
    return this_.call(_method_fn, {});
}
Variant ReflectionMethod::getClosureUsedVariables() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1650]);
    }
    return this_.call(_method_fn, {});
}
Variant ReflectionMethod::getDocComment() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1651]);
    }
    return this_.call(_method_fn, {});
}
Variant ReflectionMethod::getEndLine() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1652]);
    }
    return this_.call(_method_fn, {});
}
Variant ReflectionMethod::getExtension() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1653]);
    }
    return this_.call(_method_fn, {});
}
Variant ReflectionMethod::getExtensionName() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1654]);
    }
    return this_.call(_method_fn, {});
}
Variant ReflectionMethod::getFileName() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1655]);
    }
    return this_.call(_method_fn, {});
}
Variant ReflectionMethod::getName() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[328]);
    }
    return this_.call(_method_fn, {});
}
Variant ReflectionMethod::getNamespaceName() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1656]);
    }
    return this_.call(_method_fn, {});
}
Variant ReflectionMethod::getNumberOfParameters() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1657]);
    }
    return this_.call(_method_fn, {});
}
Variant ReflectionMethod::getNumberOfRequiredParameters() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1658]);
    }
    return this_.call(_method_fn, {});
}
Variant ReflectionMethod::getParameters() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1659]);
    }
    return this_.call(_method_fn, {});
}
Variant ReflectionMethod::getShortName() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1660]);
    }
    return this_.call(_method_fn, {});
}
Variant ReflectionMethod::getStartLine() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1661]);
    }
    return this_.call(_method_fn, {});
}
Variant ReflectionMethod::getStaticVariables() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1662]);
    }
    return this_.call(_method_fn, {});
}
Variant ReflectionMethod::returnsReference() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1663]);
    }
    return this_.call(_method_fn, {});
}
Variant ReflectionMethod::hasReturnType() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1664]);
    }
    return this_.call(_method_fn, {});
}
Variant ReflectionMethod::getReturnType() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1665]);
    }
    return this_.call(_method_fn, {});
}
Variant ReflectionMethod::hasTentativeReturnType() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1666]);
    }
    return this_.call(_method_fn, {});
}
Variant ReflectionMethod::getTentativeReturnType() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1667]);
    }
    return this_.call(_method_fn, {});
}
Variant ReflectionMethod::getAttributes(const Variant &name, const Variant &flags) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1668]);
    }
    return this_.call(_method_fn, {name, flags});
}
ReflectionProperty::ReflectionProperty(const Variant &class_, const Variant &property) {
    this_ = newObject(LITERAL_STRING[1759], {class_, property});
}
Variant ReflectionProperty::__toString() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[29]);
    }
    return this_.call(_method_fn, {});
}
Variant ReflectionProperty::getName() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[328]);
    }
    return this_.call(_method_fn, {});
}
Variant ReflectionProperty::getValue(const Variant &object) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[175]);
    }
    return this_.call(_method_fn, {object});
}
Variant ReflectionProperty::setValue(const Variant &object_or_value, const Variant &value) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1760]);
    }
    return this_.call(_method_fn, {object_or_value, value});
}
Variant ReflectionProperty::getRawValue(const Variant &object) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1761]);
    }
    return this_.call(_method_fn, {object});
}
Variant ReflectionProperty::setRawValue(const Variant &object, const Variant &value) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1762]);
    }
    return this_.call(_method_fn, {object, value});
}
Variant ReflectionProperty::setRawValueWithoutLazyInitialization(const Variant &object, const Variant &value) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1763]);
    }
    return this_.call(_method_fn, {object, value});
}
Variant ReflectionProperty::skipLazyInitialization(const Variant &object) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1764]);
    }
    return this_.call(_method_fn, {object});
}
Variant ReflectionProperty::isLazy(const Variant &object) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1765]);
    }
    return this_.call(_method_fn, {object});
}
Variant ReflectionProperty::isInitialized(const Variant &object) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1766]);
    }
    return this_.call(_method_fn, {object});
}
Variant ReflectionProperty::isPublic() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1702]);
    }
    return this_.call(_method_fn, {});
}
Variant ReflectionProperty::isPrivate() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1703]);
    }
    return this_.call(_method_fn, {});
}
Variant ReflectionProperty::isProtected() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1704]);
    }
    return this_.call(_method_fn, {});
}
Variant ReflectionProperty::isPrivateSet() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1767]);
    }
    return this_.call(_method_fn, {});
}
Variant ReflectionProperty::isProtectedSet() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1768]);
    }
    return this_.call(_method_fn, {});
}
Variant ReflectionProperty::isStatic() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1646]);
    }
    return this_.call(_method_fn, {});
}
Variant ReflectionProperty::isReadOnly() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1736]);
    }
    return this_.call(_method_fn, {});
}
Variant ReflectionProperty::isDefault() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1769]);
    }
    return this_.call(_method_fn, {});
}
Variant ReflectionProperty::isDynamic() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1770]);
    }
    return this_.call(_method_fn, {});
}
Variant ReflectionProperty::isAbstract() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1705]);
    }
    return this_.call(_method_fn, {});
}
Variant ReflectionProperty::isVirtual() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1771]);
    }
    return this_.call(_method_fn, {});
}
Variant ReflectionProperty::isPromoted() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1693]);
    }
    return this_.call(_method_fn, {});
}
Variant ReflectionProperty::getModifiers() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1709]);
    }
    return this_.call(_method_fn, {});
}
Variant ReflectionProperty::getDeclaringClass() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1680]);
    }
    return this_.call(_method_fn, {});
}
Variant ReflectionProperty::getDocComment() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1651]);
    }
    return this_.call(_method_fn, {});
}
Variant ReflectionProperty::setAccessible(const Variant &accessible) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1712]);
    }
    return this_.call(_method_fn, {accessible});
}
Variant ReflectionProperty::getType() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1683]);
    }
    return this_.call(_method_fn, {});
}
Variant ReflectionProperty::getSettableType() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1772]);
    }
    return this_.call(_method_fn, {});
}
Variant ReflectionProperty::hasType() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1682]);
    }
    return this_.call(_method_fn, {});
}
Variant ReflectionProperty::hasDefaultValue() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1773]);
    }
    return this_.call(_method_fn, {});
}
Variant ReflectionProperty::getDefaultValue() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1690]);
    }
    return this_.call(_method_fn, {});
}
Variant ReflectionProperty::getAttributes(const Variant &name, const Variant &flags) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1668]);
    }
    return this_.call(_method_fn, {name, flags});
}
Variant ReflectionProperty::hasHooks() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1774]);
    }
    return this_.call(_method_fn, {});
}
Variant ReflectionProperty::getHooks() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1775]);
    }
    return this_.call(_method_fn, {});
}
Variant ReflectionProperty::hasHook(const PropertyHookType &type) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1776]);
    }
    return this_.call(_method_fn, {type.getObject()});
}
Variant ReflectionProperty::hasHook(const Variant &type) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1776]);
    }
    return this_.call(_method_fn, {type});
}
Variant ReflectionProperty::getHook(const PropertyHookType &type) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1777]);
    }
    return this_.call(_method_fn, {type.getObject()});
}
Variant ReflectionProperty::getHook(const Variant &type) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1777]);
    }
    return this_.call(_method_fn, {type});
}
Variant ReflectionProperty::isFinal() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1706]);
    }
    return this_.call(_method_fn, {});
}
ReflectionClass::ReflectionClass(const Variant &object_or_class) {
    this_ = newObject(LITERAL_STRING[1713], {object_or_class});
}
Variant ReflectionClass::__toString() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[29]);
    }
    return this_.call(_method_fn, {});
}
Variant ReflectionClass::getName() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[328]);
    }
    return this_.call(_method_fn, {});
}
Variant ReflectionClass::isInternal() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1642]);
    }
    return this_.call(_method_fn, {});
}
Variant ReflectionClass::isUserDefined() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1643]);
    }
    return this_.call(_method_fn, {});
}
Variant ReflectionClass::isAnonymous() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1634]);
    }
    return this_.call(_method_fn, {});
}
Variant ReflectionClass::isInstantiable() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1714]);
    }
    return this_.call(_method_fn, {});
}
Variant ReflectionClass::isCloneable() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1715]);
    }
    return this_.call(_method_fn, {});
}
Variant ReflectionClass::getFileName() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1655]);
    }
    return this_.call(_method_fn, {});
}
Variant ReflectionClass::getStartLine() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1661]);
    }
    return this_.call(_method_fn, {});
}
Variant ReflectionClass::getEndLine() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1652]);
    }
    return this_.call(_method_fn, {});
}
Variant ReflectionClass::getDocComment() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1651]);
    }
    return this_.call(_method_fn, {});
}
Variant ReflectionClass::getConstructor() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1716]);
    }
    return this_.call(_method_fn, {});
}
Variant ReflectionClass::hasMethod(const Variant &name) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1717]);
    }
    return this_.call(_method_fn, {name});
}
Variant ReflectionClass::getMethod(const Variant &name) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1718]);
    }
    return this_.call(_method_fn, {name});
}
Variant ReflectionClass::getMethods(const Variant &filter) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1719]);
    }
    return this_.call(_method_fn, {filter});
}
Variant ReflectionClass::hasProperty(const Variant &name) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1720]);
    }
    return this_.call(_method_fn, {name});
}
Variant ReflectionClass::getProperty(const Variant &name) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1721]);
    }
    return this_.call(_method_fn, {name});
}
Variant ReflectionClass::getProperties(const Variant &filter) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1722]);
    }
    return this_.call(_method_fn, {filter});
}
Variant ReflectionClass::hasConstant(const Variant &name) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1723]);
    }
    return this_.call(_method_fn, {name});
}
Variant ReflectionClass::getConstants(const Variant &filter) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1724]);
    }
    return this_.call(_method_fn, {filter});
}
Variant ReflectionClass::getReflectionConstants(const Variant &filter) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1725]);
    }
    return this_.call(_method_fn, {filter});
}
Variant ReflectionClass::getConstant(const Variant &name) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1726]);
    }
    return this_.call(_method_fn, {name});
}
Variant ReflectionClass::getReflectionConstant(const Variant &name) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1727]);
    }
    return this_.call(_method_fn, {name});
}
Variant ReflectionClass::getInterfaces() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1728]);
    }
    return this_.call(_method_fn, {});
}
Variant ReflectionClass::getInterfaceNames() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1729]);
    }
    return this_.call(_method_fn, {});
}
Variant ReflectionClass::isInterface() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1730]);
    }
    return this_.call(_method_fn, {});
}
Variant ReflectionClass::getTraits() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1731]);
    }
    return this_.call(_method_fn, {});
}
Variant ReflectionClass::getTraitNames() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1732]);
    }
    return this_.call(_method_fn, {});
}
Variant ReflectionClass::getTraitAliases() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1733]);
    }
    return this_.call(_method_fn, {});
}
Variant ReflectionClass::isTrait() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1734]);
    }
    return this_.call(_method_fn, {});
}
Variant ReflectionClass::isEnum() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1735]);
    }
    return this_.call(_method_fn, {});
}
Variant ReflectionClass::isAbstract() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1705]);
    }
    return this_.call(_method_fn, {});
}
Variant ReflectionClass::isFinal() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1706]);
    }
    return this_.call(_method_fn, {});
}
Variant ReflectionClass::isReadOnly() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1736]);
    }
    return this_.call(_method_fn, {});
}
Variant ReflectionClass::getModifiers() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1709]);
    }
    return this_.call(_method_fn, {});
}
Variant ReflectionClass::isInstance(const Variant &object) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1737]);
    }
    return this_.call(_method_fn, {object});
}
Variant ReflectionClass::newInstanceWithoutConstructor() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1739]);
    }
    return this_.call(_method_fn, {});
}
Variant ReflectionClass::newInstanceArgs(const Variant &args) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1740]);
    }
    return this_.call(_method_fn, {args});
}
Variant ReflectionClass::newLazyGhost(const Variant &initializer, const Variant &options) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1741]);
    }
    return this_.call(_method_fn, {initializer, options});
}
Variant ReflectionClass::newLazyProxy(const Variant &factory, const Variant &options) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1742]);
    }
    return this_.call(_method_fn, {factory, options});
}
Variant ReflectionClass::resetAsLazyGhost(const Variant &object, const Variant &initializer, const Variant &options) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1743]);
    }
    return this_.call(_method_fn, {object, initializer, options});
}
Variant ReflectionClass::resetAsLazyProxy(const Variant &object, const Variant &factory, const Variant &options) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1744]);
    }
    return this_.call(_method_fn, {object, factory, options});
}
Variant ReflectionClass::initializeLazyObject(const Variant &object) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1745]);
    }
    return this_.call(_method_fn, {object});
}
Variant ReflectionClass::isUninitializedLazyObject(const Variant &object) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1746]);
    }
    return this_.call(_method_fn, {object});
}
Variant ReflectionClass::markLazyObjectAsInitialized(const Variant &object) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1747]);
    }
    return this_.call(_method_fn, {object});
}
Variant ReflectionClass::getLazyInitializer(const Variant &object) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1748]);
    }
    return this_.call(_method_fn, {object});
}
Variant ReflectionClass::getParentClass() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1749]);
    }
    return this_.call(_method_fn, {});
}
Variant ReflectionClass::isSubclassOf(const Variant &class_) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1750]);
    }
    return this_.call(_method_fn, {class_});
}
Variant ReflectionClass::getStaticProperties() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1751]);
    }
    return this_.call(_method_fn, {});
}
Variant ReflectionClass::getStaticPropertyValue(const Variant &name, const Variant &default_) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1752]);
    }
    return this_.call(_method_fn, {name, default_});
}
Variant ReflectionClass::setStaticPropertyValue(const Variant &name, const Variant &value) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1753]);
    }
    return this_.call(_method_fn, {name, value});
}
Variant ReflectionClass::getDefaultProperties() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1754]);
    }
    return this_.call(_method_fn, {});
}
Variant ReflectionClass::isIterable() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1755]);
    }
    return this_.call(_method_fn, {});
}
Variant ReflectionClass::isIterateable() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1756]);
    }
    return this_.call(_method_fn, {});
}
Variant ReflectionClass::implementsInterface(const Variant &interface) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1757]);
    }
    return this_.call(_method_fn, {interface});
}
Variant ReflectionClass::getExtension() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1653]);
    }
    return this_.call(_method_fn, {});
}
Variant ReflectionClass::getExtensionName() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1654]);
    }
    return this_.call(_method_fn, {});
}
Variant ReflectionClass::inNamespace() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1639]);
    }
    return this_.call(_method_fn, {});
}
Variant ReflectionClass::getNamespaceName() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1656]);
    }
    return this_.call(_method_fn, {});
}
Variant ReflectionClass::getShortName() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1660]);
    }
    return this_.call(_method_fn, {});
}
Variant ReflectionClass::getAttributes(const Variant &name, const Variant &flags) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1668]);
    }
    return this_.call(_method_fn, {name, flags});
}
ReflectionClassConstant::ReflectionClassConstant(const Variant &class_, const Variant &constant) {
    this_ = newObject(LITERAL_STRING[1778], {class_, constant});
}
Variant ReflectionClassConstant::__toString() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[29]);
    }
    return this_.call(_method_fn, {});
}
Variant ReflectionClassConstant::getName() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[328]);
    }
    return this_.call(_method_fn, {});
}
Variant ReflectionClassConstant::getValue() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[175]);
    }
    return this_.call(_method_fn, {});
}
Variant ReflectionClassConstant::isPublic() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1702]);
    }
    return this_.call(_method_fn, {});
}
Variant ReflectionClassConstant::isPrivate() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1703]);
    }
    return this_.call(_method_fn, {});
}
Variant ReflectionClassConstant::isProtected() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1704]);
    }
    return this_.call(_method_fn, {});
}
Variant ReflectionClassConstant::isFinal() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1706]);
    }
    return this_.call(_method_fn, {});
}
Variant ReflectionClassConstant::getModifiers() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1709]);
    }
    return this_.call(_method_fn, {});
}
Variant ReflectionClassConstant::getDeclaringClass() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1680]);
    }
    return this_.call(_method_fn, {});
}
Variant ReflectionClassConstant::getDocComment() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1651]);
    }
    return this_.call(_method_fn, {});
}
Variant ReflectionClassConstant::getAttributes(const Variant &name, const Variant &flags) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1668]);
    }
    return this_.call(_method_fn, {name, flags});
}
Variant ReflectionClassConstant::isEnumCase() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1779]);
    }
    return this_.call(_method_fn, {});
}
Variant ReflectionClassConstant::isDeprecated() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1641]);
    }
    return this_.call(_method_fn, {});
}
Variant ReflectionClassConstant::hasType() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1682]);
    }
    return this_.call(_method_fn, {});
}
Variant ReflectionClassConstant::getType() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1683]);
    }
    return this_.call(_method_fn, {});
}
ReflectionObject::ReflectionObject(const Variant &object) {
    this_ = newObject(LITERAL_STRING[1758], {object});
}
ReflectionEnum::ReflectionEnum(const Variant &object_or_class) {
    this_ = newObject(LITERAL_STRING[1800], {object_or_class});
}
Variant ReflectionEnum::hasCase(const Variant &name) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1801]);
    }
    return this_.call(_method_fn, {name});
}
Variant ReflectionEnum::getCase(const Variant &name) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1802]);
    }
    return this_.call(_method_fn, {name});
}
Variant ReflectionEnum::getCases() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1803]);
    }
    return this_.call(_method_fn, {});
}
Variant ReflectionEnum::isBacked() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1804]);
    }
    return this_.call(_method_fn, {});
}
ReflectionNamedType ReflectionEnum::getBackingType() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1805]);
    }
    return ReflectionNamedType(Object(this_.call(_method_fn, {})));
}
ReflectionEnumUnitCase::ReflectionEnumUnitCase(const Variant &class_, const Variant &constant) {
    this_ = newObject(LITERAL_STRING[1806], {class_, constant});
}
Variant ReflectionEnumUnitCase::getEnum() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1807]);
    }
    return this_.call(_method_fn, {});
}
Variant ReflectionEnumUnitCase::getValue() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[175]);
    }
    return this_.call(_method_fn, {});
}
ReflectionEnumBackedCase::ReflectionEnumBackedCase(const Variant &class_, const Variant &constant) {
    this_ = newObject(LITERAL_STRING[1808], {class_, constant});
}
Variant ReflectionEnumBackedCase::getBackingValue() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1809]);
    }
    return this_.call(_method_fn, {});
}
}  // namespace php

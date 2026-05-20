#include "phpx.h"
#include "class/reflection.h"

namespace php {
ReflectionException::ReflectionException(const Variant &message, const Variant &code, const Variant &previous) {
    this_ = newObject(LITERAL_STRING[1465], {message, code, previous});
}
Variant ReflectionException::__wakeup() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[97]);
    }
    return this_.call(_method_fn, {});
}
Variant ReflectionException::getMessage() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[98]);
    }
    return this_.call(_method_fn, {});
}
Variant ReflectionException::getCode() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[99]);
    }
    return this_.call(_method_fn, {});
}
Variant ReflectionException::getFile() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[100]);
    }
    return this_.call(_method_fn, {});
}
Variant ReflectionException::getLine() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[101]);
    }
    return this_.call(_method_fn, {});
}
Variant ReflectionException::getTrace() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[102]);
    }
    return this_.call(_method_fn, {});
}
Variant ReflectionException::getPrevious() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[103]);
    }
    return this_.call(_method_fn, {});
}
Variant ReflectionException::getTraceAsString() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[104]);
    }
    return this_.call(_method_fn, {});
}
Variant ReflectionException::__toString() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[29]);
    }
    return this_.call(_method_fn, {});
}
Reflection::Reflection() {
    this_ = newObject(LITERAL_STRING[1466]);
}
Variant Reflection::getModifierNames(const Variant &modifiers) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(LITERAL_STRING[1466], LITERAL_STRING[1468]);
    }
    return php::call(_method_fn, {modifiers});
}
ReflectionFunction::ReflectionFunction(const Variant &function) {
    this_ = newObject(LITERAL_STRING[1469], {function});
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
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1470]);
    }
    return this_.call(_method_fn, {});
}
Variant ReflectionFunction::isDisabled() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1471]);
    }
    return this_.call(_method_fn, {});
}
Variant ReflectionFunction::invokeArgs(const Variant &args) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1473]);
    }
    return this_.call(_method_fn, {args});
}
Variant ReflectionFunction::getClosure() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1474]);
    }
    return this_.call(_method_fn, {});
}
Variant ReflectionFunction::inNamespace() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1475]);
    }
    return this_.call(_method_fn, {});
}
Variant ReflectionFunction::isClosure() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1476]);
    }
    return this_.call(_method_fn, {});
}
Variant ReflectionFunction::isDeprecated() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1477]);
    }
    return this_.call(_method_fn, {});
}
Variant ReflectionFunction::isInternal() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1478]);
    }
    return this_.call(_method_fn, {});
}
Variant ReflectionFunction::isUserDefined() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1479]);
    }
    return this_.call(_method_fn, {});
}
Variant ReflectionFunction::isGenerator() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1480]);
    }
    return this_.call(_method_fn, {});
}
Variant ReflectionFunction::isVariadic() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1481]);
    }
    return this_.call(_method_fn, {});
}
Variant ReflectionFunction::isStatic() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1482]);
    }
    return this_.call(_method_fn, {});
}
Variant ReflectionFunction::getClosureThis() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1483]);
    }
    return this_.call(_method_fn, {});
}
Variant ReflectionFunction::getClosureScopeClass() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1484]);
    }
    return this_.call(_method_fn, {});
}
Variant ReflectionFunction::getClosureCalledClass() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1485]);
    }
    return this_.call(_method_fn, {});
}
Variant ReflectionFunction::getClosureUsedVariables() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1486]);
    }
    return this_.call(_method_fn, {});
}
Variant ReflectionFunction::getDocComment() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1487]);
    }
    return this_.call(_method_fn, {});
}
Variant ReflectionFunction::getEndLine() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1488]);
    }
    return this_.call(_method_fn, {});
}
Variant ReflectionFunction::getExtension() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[976]);
    }
    return this_.call(_method_fn, {});
}
Variant ReflectionFunction::getExtensionName() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1489]);
    }
    return this_.call(_method_fn, {});
}
Variant ReflectionFunction::getFileName() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1490]);
    }
    return this_.call(_method_fn, {});
}
Variant ReflectionFunction::getName() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[300]);
    }
    return this_.call(_method_fn, {});
}
Variant ReflectionFunction::getNamespaceName() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1491]);
    }
    return this_.call(_method_fn, {});
}
Variant ReflectionFunction::getNumberOfParameters() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1492]);
    }
    return this_.call(_method_fn, {});
}
Variant ReflectionFunction::getNumberOfRequiredParameters() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1493]);
    }
    return this_.call(_method_fn, {});
}
Variant ReflectionFunction::getParameters() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1494]);
    }
    return this_.call(_method_fn, {});
}
Variant ReflectionFunction::getShortName() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1495]);
    }
    return this_.call(_method_fn, {});
}
Variant ReflectionFunction::getStartLine() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1496]);
    }
    return this_.call(_method_fn, {});
}
Variant ReflectionFunction::getStaticVariables() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1497]);
    }
    return this_.call(_method_fn, {});
}
Variant ReflectionFunction::returnsReference() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1498]);
    }
    return this_.call(_method_fn, {});
}
Variant ReflectionFunction::hasReturnType() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1499]);
    }
    return this_.call(_method_fn, {});
}
Variant ReflectionFunction::getReturnType() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1500]);
    }
    return this_.call(_method_fn, {});
}
Variant ReflectionFunction::hasTentativeReturnType() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1501]);
    }
    return this_.call(_method_fn, {});
}
Variant ReflectionFunction::getTentativeReturnType() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1502]);
    }
    return this_.call(_method_fn, {});
}
Variant ReflectionFunction::getAttributes(const Variant &name, const Variant &flags) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1503]);
    }
    return this_.call(_method_fn, {name, flags});
}
ReflectionGenerator::ReflectionGenerator(const Variant &generator) {
    this_ = newObject(LITERAL_STRING[1504], {generator});
}
Variant ReflectionGenerator::getExecutingLine() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1505]);
    }
    return this_.call(_method_fn, {});
}
Variant ReflectionGenerator::getExecutingFile() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1506]);
    }
    return this_.call(_method_fn, {});
}
Variant ReflectionGenerator::getTrace(const Variant &options) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[102]);
    }
    return this_.call(_method_fn, {options});
}
Variant ReflectionGenerator::getFunction() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1507]);
    }
    return this_.call(_method_fn, {});
}
Variant ReflectionGenerator::_getThis() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1508]);
    }
    return this_.call(_method_fn, {});
}
Variant ReflectionGenerator::getExecutingGenerator() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1509]);
    }
    return this_.call(_method_fn, {});
}
Variant ReflectionGenerator::isClosed() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1510]);
    }
    return this_.call(_method_fn, {});
}
ReflectionParameter::ReflectionParameter(const Variant &function, const Variant &param) {
    this_ = newObject(LITERAL_STRING[1511], {function, param});
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
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[300]);
    }
    return this_.call(_method_fn, {});
}
Variant ReflectionParameter::isPassedByReference() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1512]);
    }
    return this_.call(_method_fn, {});
}
Variant ReflectionParameter::canBePassedByValue() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1513]);
    }
    return this_.call(_method_fn, {});
}
Variant ReflectionParameter::getDeclaringFunction() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1514]);
    }
    return this_.call(_method_fn, {});
}
Variant ReflectionParameter::getDeclaringClass() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1515]);
    }
    return this_.call(_method_fn, {});
}
Variant ReflectionParameter::getClass() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1516]);
    }
    return this_.call(_method_fn, {});
}
Variant ReflectionParameter::hasType() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1517]);
    }
    return this_.call(_method_fn, {});
}
Variant ReflectionParameter::getType() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[989]);
    }
    return this_.call(_method_fn, {});
}
Variant ReflectionParameter::isArray() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1518]);
    }
    return this_.call(_method_fn, {});
}
Variant ReflectionParameter::isCallable() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1519]);
    }
    return this_.call(_method_fn, {});
}
Variant ReflectionParameter::allowsNull() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1520]);
    }
    return this_.call(_method_fn, {});
}
Variant ReflectionParameter::getPosition() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1521]);
    }
    return this_.call(_method_fn, {});
}
Variant ReflectionParameter::isOptional() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1522]);
    }
    return this_.call(_method_fn, {});
}
Variant ReflectionParameter::isDefaultValueAvailable() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1523]);
    }
    return this_.call(_method_fn, {});
}
Variant ReflectionParameter::getDefaultValue() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1524]);
    }
    return this_.call(_method_fn, {});
}
Variant ReflectionParameter::isDefaultValueConstant() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1525]);
    }
    return this_.call(_method_fn, {});
}
Variant ReflectionParameter::getDefaultValueConstantName() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1526]);
    }
    return this_.call(_method_fn, {});
}
Variant ReflectionParameter::isVariadic() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1481]);
    }
    return this_.call(_method_fn, {});
}
Variant ReflectionParameter::isPromoted() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1527]);
    }
    return this_.call(_method_fn, {});
}
Variant ReflectionParameter::getAttributes(const Variant &name, const Variant &flags) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1503]);
    }
    return this_.call(_method_fn, {name, flags});
}
ReflectionNamedType::ReflectionNamedType() {
    this_ = newObject(LITERAL_STRING[1528]);
}
Variant ReflectionNamedType::getName() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[300]);
    }
    return this_.call(_method_fn, {});
}
Variant ReflectionNamedType::isBuiltin() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1529]);
    }
    return this_.call(_method_fn, {});
}
Variant ReflectionNamedType::allowsNull() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1520]);
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
    this_ = newObject(LITERAL_STRING[1530]);
}
Variant ReflectionUnionType::getTypes() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1531]);
    }
    return this_.call(_method_fn, {});
}
Variant ReflectionUnionType::allowsNull() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1520]);
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
    this_ = newObject(LITERAL_STRING[1532]);
}
Variant ReflectionIntersectionType::getTypes() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1531]);
    }
    return this_.call(_method_fn, {});
}
Variant ReflectionIntersectionType::allowsNull() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1520]);
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
ReflectionMethod::ReflectionMethod(const Variant &object_or_method, const Variant &method) {
    this_ = newObject(LITERAL_STRING[1533], {object_or_method, method});
}
Variant ReflectionMethod::createFromMethodName(const Variant &method) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(LITERAL_STRING[1533], LITERAL_STRING[1535]);
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
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1536]);
    }
    return this_.call(_method_fn, {});
}
Variant ReflectionMethod::isPrivate() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1537]);
    }
    return this_.call(_method_fn, {});
}
Variant ReflectionMethod::isProtected() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1538]);
    }
    return this_.call(_method_fn, {});
}
Variant ReflectionMethod::isAbstract() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1539]);
    }
    return this_.call(_method_fn, {});
}
Variant ReflectionMethod::isFinal() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1540]);
    }
    return this_.call(_method_fn, {});
}
Variant ReflectionMethod::isConstructor() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1541]);
    }
    return this_.call(_method_fn, {});
}
Variant ReflectionMethod::isDestructor() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1542]);
    }
    return this_.call(_method_fn, {});
}
Variant ReflectionMethod::getClosure(const Variant &object) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1474]);
    }
    return this_.call(_method_fn, {object});
}
Variant ReflectionMethod::getModifiers() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1543]);
    }
    return this_.call(_method_fn, {});
}
Variant ReflectionMethod::invokeArgs(const Variant &object, const Variant &args) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1473]);
    }
    return this_.call(_method_fn, {object, args});
}
Variant ReflectionMethod::getDeclaringClass() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1515]);
    }
    return this_.call(_method_fn, {});
}
Variant ReflectionMethod::getPrototype() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1544]);
    }
    return this_.call(_method_fn, {});
}
Variant ReflectionMethod::hasPrototype() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1545]);
    }
    return this_.call(_method_fn, {});
}
Variant ReflectionMethod::setAccessible(const Variant &accessible) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1546]);
    }
    return this_.call(_method_fn, {accessible});
}
Variant ReflectionMethod::inNamespace() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1475]);
    }
    return this_.call(_method_fn, {});
}
Variant ReflectionMethod::isClosure() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1476]);
    }
    return this_.call(_method_fn, {});
}
Variant ReflectionMethod::isDeprecated() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1477]);
    }
    return this_.call(_method_fn, {});
}
Variant ReflectionMethod::isInternal() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1478]);
    }
    return this_.call(_method_fn, {});
}
Variant ReflectionMethod::isUserDefined() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1479]);
    }
    return this_.call(_method_fn, {});
}
Variant ReflectionMethod::isGenerator() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1480]);
    }
    return this_.call(_method_fn, {});
}
Variant ReflectionMethod::isVariadic() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1481]);
    }
    return this_.call(_method_fn, {});
}
Variant ReflectionMethod::isStatic() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1482]);
    }
    return this_.call(_method_fn, {});
}
Variant ReflectionMethod::getClosureThis() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1483]);
    }
    return this_.call(_method_fn, {});
}
Variant ReflectionMethod::getClosureScopeClass() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1484]);
    }
    return this_.call(_method_fn, {});
}
Variant ReflectionMethod::getClosureCalledClass() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1485]);
    }
    return this_.call(_method_fn, {});
}
Variant ReflectionMethod::getClosureUsedVariables() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1486]);
    }
    return this_.call(_method_fn, {});
}
Variant ReflectionMethod::getDocComment() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1487]);
    }
    return this_.call(_method_fn, {});
}
Variant ReflectionMethod::getEndLine() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1488]);
    }
    return this_.call(_method_fn, {});
}
Variant ReflectionMethod::getExtension() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[976]);
    }
    return this_.call(_method_fn, {});
}
Variant ReflectionMethod::getExtensionName() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1489]);
    }
    return this_.call(_method_fn, {});
}
Variant ReflectionMethod::getFileName() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1490]);
    }
    return this_.call(_method_fn, {});
}
Variant ReflectionMethod::getName() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[300]);
    }
    return this_.call(_method_fn, {});
}
Variant ReflectionMethod::getNamespaceName() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1491]);
    }
    return this_.call(_method_fn, {});
}
Variant ReflectionMethod::getNumberOfParameters() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1492]);
    }
    return this_.call(_method_fn, {});
}
Variant ReflectionMethod::getNumberOfRequiredParameters() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1493]);
    }
    return this_.call(_method_fn, {});
}
Variant ReflectionMethod::getParameters() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1494]);
    }
    return this_.call(_method_fn, {});
}
Variant ReflectionMethod::getShortName() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1495]);
    }
    return this_.call(_method_fn, {});
}
Variant ReflectionMethod::getStartLine() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1496]);
    }
    return this_.call(_method_fn, {});
}
Variant ReflectionMethod::getStaticVariables() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1497]);
    }
    return this_.call(_method_fn, {});
}
Variant ReflectionMethod::returnsReference() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1498]);
    }
    return this_.call(_method_fn, {});
}
Variant ReflectionMethod::hasReturnType() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1499]);
    }
    return this_.call(_method_fn, {});
}
Variant ReflectionMethod::getReturnType() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1500]);
    }
    return this_.call(_method_fn, {});
}
Variant ReflectionMethod::hasTentativeReturnType() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1501]);
    }
    return this_.call(_method_fn, {});
}
Variant ReflectionMethod::getTentativeReturnType() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1502]);
    }
    return this_.call(_method_fn, {});
}
Variant ReflectionMethod::getAttributes(const Variant &name, const Variant &flags) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1503]);
    }
    return this_.call(_method_fn, {name, flags});
}
ReflectionClass::ReflectionClass(const Variant &object_or_class) {
    this_ = newObject(LITERAL_STRING[1547], {object_or_class});
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
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[300]);
    }
    return this_.call(_method_fn, {});
}
Variant ReflectionClass::isInternal() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1478]);
    }
    return this_.call(_method_fn, {});
}
Variant ReflectionClass::isUserDefined() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1479]);
    }
    return this_.call(_method_fn, {});
}
Variant ReflectionClass::isAnonymous() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1470]);
    }
    return this_.call(_method_fn, {});
}
Variant ReflectionClass::isInstantiable() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1548]);
    }
    return this_.call(_method_fn, {});
}
Variant ReflectionClass::isCloneable() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1549]);
    }
    return this_.call(_method_fn, {});
}
Variant ReflectionClass::getFileName() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1490]);
    }
    return this_.call(_method_fn, {});
}
Variant ReflectionClass::getStartLine() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1496]);
    }
    return this_.call(_method_fn, {});
}
Variant ReflectionClass::getEndLine() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1488]);
    }
    return this_.call(_method_fn, {});
}
Variant ReflectionClass::getDocComment() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1487]);
    }
    return this_.call(_method_fn, {});
}
Variant ReflectionClass::getConstructor() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1550]);
    }
    return this_.call(_method_fn, {});
}
Variant ReflectionClass::hasMethod(const Variant &name) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1551]);
    }
    return this_.call(_method_fn, {name});
}
Variant ReflectionClass::getMethod(const Variant &name) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1552]);
    }
    return this_.call(_method_fn, {name});
}
Variant ReflectionClass::getMethods(const Variant &filter) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1553]);
    }
    return this_.call(_method_fn, {filter});
}
Variant ReflectionClass::hasProperty(const Variant &name) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1554]);
    }
    return this_.call(_method_fn, {name});
}
Variant ReflectionClass::getProperty(const Variant &name) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1555]);
    }
    return this_.call(_method_fn, {name});
}
Variant ReflectionClass::getProperties(const Variant &filter) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1556]);
    }
    return this_.call(_method_fn, {filter});
}
Variant ReflectionClass::hasConstant(const Variant &name) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1557]);
    }
    return this_.call(_method_fn, {name});
}
Variant ReflectionClass::getConstants(const Variant &filter) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1558]);
    }
    return this_.call(_method_fn, {filter});
}
Variant ReflectionClass::getReflectionConstants(const Variant &filter) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1559]);
    }
    return this_.call(_method_fn, {filter});
}
Variant ReflectionClass::getConstant(const Variant &name) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1560]);
    }
    return this_.call(_method_fn, {name});
}
Variant ReflectionClass::getReflectionConstant(const Variant &name) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1561]);
    }
    return this_.call(_method_fn, {name});
}
Variant ReflectionClass::getInterfaces() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1562]);
    }
    return this_.call(_method_fn, {});
}
Variant ReflectionClass::getInterfaceNames() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1563]);
    }
    return this_.call(_method_fn, {});
}
Variant ReflectionClass::isInterface() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1564]);
    }
    return this_.call(_method_fn, {});
}
Variant ReflectionClass::getTraits() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1565]);
    }
    return this_.call(_method_fn, {});
}
Variant ReflectionClass::getTraitNames() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1566]);
    }
    return this_.call(_method_fn, {});
}
Variant ReflectionClass::getTraitAliases() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1567]);
    }
    return this_.call(_method_fn, {});
}
Variant ReflectionClass::isTrait() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1568]);
    }
    return this_.call(_method_fn, {});
}
Variant ReflectionClass::isEnum() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1569]);
    }
    return this_.call(_method_fn, {});
}
Variant ReflectionClass::isAbstract() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1539]);
    }
    return this_.call(_method_fn, {});
}
Variant ReflectionClass::isFinal() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1540]);
    }
    return this_.call(_method_fn, {});
}
Variant ReflectionClass::isReadOnly() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1570]);
    }
    return this_.call(_method_fn, {});
}
Variant ReflectionClass::getModifiers() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1543]);
    }
    return this_.call(_method_fn, {});
}
Variant ReflectionClass::isInstance(const Variant &object) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1571]);
    }
    return this_.call(_method_fn, {object});
}
Variant ReflectionClass::newInstanceWithoutConstructor() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1573]);
    }
    return this_.call(_method_fn, {});
}
Variant ReflectionClass::newInstanceArgs(const Variant &args) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1574]);
    }
    return this_.call(_method_fn, {args});
}
Variant ReflectionClass::newLazyGhost(const Variant &initializer, const Variant &options) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1575]);
    }
    return this_.call(_method_fn, {initializer, options});
}
Variant ReflectionClass::newLazyProxy(const Variant &factory, const Variant &options) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1576]);
    }
    return this_.call(_method_fn, {factory, options});
}
Variant ReflectionClass::resetAsLazyGhost(const Variant &object, const Variant &initializer, const Variant &options) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1577]);
    }
    return this_.call(_method_fn, {object, initializer, options});
}
Variant ReflectionClass::resetAsLazyProxy(const Variant &object, const Variant &factory, const Variant &options) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1578]);
    }
    return this_.call(_method_fn, {object, factory, options});
}
Variant ReflectionClass::initializeLazyObject(const Variant &object) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1579]);
    }
    return this_.call(_method_fn, {object});
}
Variant ReflectionClass::isUninitializedLazyObject(const Variant &object) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1580]);
    }
    return this_.call(_method_fn, {object});
}
Variant ReflectionClass::markLazyObjectAsInitialized(const Variant &object) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1581]);
    }
    return this_.call(_method_fn, {object});
}
Variant ReflectionClass::getLazyInitializer(const Variant &object) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1582]);
    }
    return this_.call(_method_fn, {object});
}
Variant ReflectionClass::getParentClass() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1583]);
    }
    return this_.call(_method_fn, {});
}
Variant ReflectionClass::isSubclassOf(const Variant &_class) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1584]);
    }
    return this_.call(_method_fn, {_class});
}
Variant ReflectionClass::getStaticProperties() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1585]);
    }
    return this_.call(_method_fn, {});
}
Variant ReflectionClass::getStaticPropertyValue(const Variant &name, const Variant &_default) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1586]);
    }
    return this_.call(_method_fn, {name, _default});
}
Variant ReflectionClass::setStaticPropertyValue(const Variant &name, const Variant &value) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1587]);
    }
    return this_.call(_method_fn, {name, value});
}
Variant ReflectionClass::getDefaultProperties() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1588]);
    }
    return this_.call(_method_fn, {});
}
Variant ReflectionClass::isIterable() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1589]);
    }
    return this_.call(_method_fn, {});
}
Variant ReflectionClass::isIterateable() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1590]);
    }
    return this_.call(_method_fn, {});
}
Variant ReflectionClass::implementsInterface(const Variant &interface) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1591]);
    }
    return this_.call(_method_fn, {interface});
}
Variant ReflectionClass::getExtension() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[976]);
    }
    return this_.call(_method_fn, {});
}
Variant ReflectionClass::getExtensionName() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1489]);
    }
    return this_.call(_method_fn, {});
}
Variant ReflectionClass::inNamespace() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1475]);
    }
    return this_.call(_method_fn, {});
}
Variant ReflectionClass::getNamespaceName() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1491]);
    }
    return this_.call(_method_fn, {});
}
Variant ReflectionClass::getShortName() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1495]);
    }
    return this_.call(_method_fn, {});
}
Variant ReflectionClass::getAttributes(const Variant &name, const Variant &flags) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1503]);
    }
    return this_.call(_method_fn, {name, flags});
}
ReflectionObject::ReflectionObject(const Variant &object) {
    this_ = newObject(LITERAL_STRING[1592], {object});
}
Variant ReflectionObject::__toString() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[29]);
    }
    return this_.call(_method_fn, {});
}
Variant ReflectionObject::getName() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[300]);
    }
    return this_.call(_method_fn, {});
}
Variant ReflectionObject::isInternal() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1478]);
    }
    return this_.call(_method_fn, {});
}
Variant ReflectionObject::isUserDefined() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1479]);
    }
    return this_.call(_method_fn, {});
}
Variant ReflectionObject::isAnonymous() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1470]);
    }
    return this_.call(_method_fn, {});
}
Variant ReflectionObject::isInstantiable() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1548]);
    }
    return this_.call(_method_fn, {});
}
Variant ReflectionObject::isCloneable() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1549]);
    }
    return this_.call(_method_fn, {});
}
Variant ReflectionObject::getFileName() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1490]);
    }
    return this_.call(_method_fn, {});
}
Variant ReflectionObject::getStartLine() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1496]);
    }
    return this_.call(_method_fn, {});
}
Variant ReflectionObject::getEndLine() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1488]);
    }
    return this_.call(_method_fn, {});
}
Variant ReflectionObject::getDocComment() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1487]);
    }
    return this_.call(_method_fn, {});
}
Variant ReflectionObject::getConstructor() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1550]);
    }
    return this_.call(_method_fn, {});
}
Variant ReflectionObject::hasMethod(const Variant &name) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1551]);
    }
    return this_.call(_method_fn, {name});
}
Variant ReflectionObject::getMethod(const Variant &name) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1552]);
    }
    return this_.call(_method_fn, {name});
}
Variant ReflectionObject::getMethods(const Variant &filter) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1553]);
    }
    return this_.call(_method_fn, {filter});
}
Variant ReflectionObject::hasProperty(const Variant &name) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1554]);
    }
    return this_.call(_method_fn, {name});
}
Variant ReflectionObject::getProperty(const Variant &name) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1555]);
    }
    return this_.call(_method_fn, {name});
}
Variant ReflectionObject::getProperties(const Variant &filter) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1556]);
    }
    return this_.call(_method_fn, {filter});
}
Variant ReflectionObject::hasConstant(const Variant &name) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1557]);
    }
    return this_.call(_method_fn, {name});
}
Variant ReflectionObject::getConstants(const Variant &filter) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1558]);
    }
    return this_.call(_method_fn, {filter});
}
Variant ReflectionObject::getReflectionConstants(const Variant &filter) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1559]);
    }
    return this_.call(_method_fn, {filter});
}
Variant ReflectionObject::getConstant(const Variant &name) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1560]);
    }
    return this_.call(_method_fn, {name});
}
Variant ReflectionObject::getReflectionConstant(const Variant &name) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1561]);
    }
    return this_.call(_method_fn, {name});
}
Variant ReflectionObject::getInterfaces() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1562]);
    }
    return this_.call(_method_fn, {});
}
Variant ReflectionObject::getInterfaceNames() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1563]);
    }
    return this_.call(_method_fn, {});
}
Variant ReflectionObject::isInterface() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1564]);
    }
    return this_.call(_method_fn, {});
}
Variant ReflectionObject::getTraits() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1565]);
    }
    return this_.call(_method_fn, {});
}
Variant ReflectionObject::getTraitNames() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1566]);
    }
    return this_.call(_method_fn, {});
}
Variant ReflectionObject::getTraitAliases() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1567]);
    }
    return this_.call(_method_fn, {});
}
Variant ReflectionObject::isTrait() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1568]);
    }
    return this_.call(_method_fn, {});
}
Variant ReflectionObject::isEnum() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1569]);
    }
    return this_.call(_method_fn, {});
}
Variant ReflectionObject::isAbstract() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1539]);
    }
    return this_.call(_method_fn, {});
}
Variant ReflectionObject::isFinal() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1540]);
    }
    return this_.call(_method_fn, {});
}
Variant ReflectionObject::isReadOnly() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1570]);
    }
    return this_.call(_method_fn, {});
}
Variant ReflectionObject::getModifiers() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1543]);
    }
    return this_.call(_method_fn, {});
}
Variant ReflectionObject::isInstance(const Variant &object) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1571]);
    }
    return this_.call(_method_fn, {object});
}
Variant ReflectionObject::newInstanceWithoutConstructor() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1573]);
    }
    return this_.call(_method_fn, {});
}
Variant ReflectionObject::newInstanceArgs(const Variant &args) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1574]);
    }
    return this_.call(_method_fn, {args});
}
Variant ReflectionObject::newLazyGhost(const Variant &initializer, const Variant &options) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1575]);
    }
    return this_.call(_method_fn, {initializer, options});
}
Variant ReflectionObject::newLazyProxy(const Variant &factory, const Variant &options) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1576]);
    }
    return this_.call(_method_fn, {factory, options});
}
Variant ReflectionObject::resetAsLazyGhost(const Variant &object, const Variant &initializer, const Variant &options) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1577]);
    }
    return this_.call(_method_fn, {object, initializer, options});
}
Variant ReflectionObject::resetAsLazyProxy(const Variant &object, const Variant &factory, const Variant &options) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1578]);
    }
    return this_.call(_method_fn, {object, factory, options});
}
Variant ReflectionObject::initializeLazyObject(const Variant &object) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1579]);
    }
    return this_.call(_method_fn, {object});
}
Variant ReflectionObject::isUninitializedLazyObject(const Variant &object) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1580]);
    }
    return this_.call(_method_fn, {object});
}
Variant ReflectionObject::markLazyObjectAsInitialized(const Variant &object) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1581]);
    }
    return this_.call(_method_fn, {object});
}
Variant ReflectionObject::getLazyInitializer(const Variant &object) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1582]);
    }
    return this_.call(_method_fn, {object});
}
Variant ReflectionObject::getParentClass() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1583]);
    }
    return this_.call(_method_fn, {});
}
Variant ReflectionObject::isSubclassOf(const Variant &_class) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1584]);
    }
    return this_.call(_method_fn, {_class});
}
Variant ReflectionObject::getStaticProperties() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1585]);
    }
    return this_.call(_method_fn, {});
}
Variant ReflectionObject::getStaticPropertyValue(const Variant &name, const Variant &_default) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1586]);
    }
    return this_.call(_method_fn, {name, _default});
}
Variant ReflectionObject::setStaticPropertyValue(const Variant &name, const Variant &value) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1587]);
    }
    return this_.call(_method_fn, {name, value});
}
Variant ReflectionObject::getDefaultProperties() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1588]);
    }
    return this_.call(_method_fn, {});
}
Variant ReflectionObject::isIterable() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1589]);
    }
    return this_.call(_method_fn, {});
}
Variant ReflectionObject::isIterateable() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1590]);
    }
    return this_.call(_method_fn, {});
}
Variant ReflectionObject::implementsInterface(const Variant &interface) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1591]);
    }
    return this_.call(_method_fn, {interface});
}
Variant ReflectionObject::getExtension() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[976]);
    }
    return this_.call(_method_fn, {});
}
Variant ReflectionObject::getExtensionName() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1489]);
    }
    return this_.call(_method_fn, {});
}
Variant ReflectionObject::inNamespace() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1475]);
    }
    return this_.call(_method_fn, {});
}
Variant ReflectionObject::getNamespaceName() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1491]);
    }
    return this_.call(_method_fn, {});
}
Variant ReflectionObject::getShortName() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1495]);
    }
    return this_.call(_method_fn, {});
}
Variant ReflectionObject::getAttributes(const Variant &name, const Variant &flags) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1503]);
    }
    return this_.call(_method_fn, {name, flags});
}
ReflectionProperty::ReflectionProperty(const Variant &_class, const Variant &property) {
    this_ = newObject(LITERAL_STRING[1593], {_class, property});
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
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[300]);
    }
    return this_.call(_method_fn, {});
}
Variant ReflectionProperty::getValue(const Variant &object) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[147]);
    }
    return this_.call(_method_fn, {object});
}
Variant ReflectionProperty::setValue(const Variant &object_or_value, const Variant &value) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1594]);
    }
    return this_.call(_method_fn, {object_or_value, value});
}
Variant ReflectionProperty::getRawValue(const Variant &object) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1595]);
    }
    return this_.call(_method_fn, {object});
}
Variant ReflectionProperty::setRawValue(const Variant &object, const Variant &value) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1596]);
    }
    return this_.call(_method_fn, {object, value});
}
Variant ReflectionProperty::setRawValueWithoutLazyInitialization(const Variant &object, const Variant &value) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1597]);
    }
    return this_.call(_method_fn, {object, value});
}
Variant ReflectionProperty::skipLazyInitialization(const Variant &object) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1598]);
    }
    return this_.call(_method_fn, {object});
}
Variant ReflectionProperty::isLazy(const Variant &object) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1599]);
    }
    return this_.call(_method_fn, {object});
}
Variant ReflectionProperty::isInitialized(const Variant &object) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1600]);
    }
    return this_.call(_method_fn, {object});
}
Variant ReflectionProperty::isPublic() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1536]);
    }
    return this_.call(_method_fn, {});
}
Variant ReflectionProperty::isPrivate() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1537]);
    }
    return this_.call(_method_fn, {});
}
Variant ReflectionProperty::isProtected() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1538]);
    }
    return this_.call(_method_fn, {});
}
Variant ReflectionProperty::isPrivateSet() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1601]);
    }
    return this_.call(_method_fn, {});
}
Variant ReflectionProperty::isProtectedSet() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1602]);
    }
    return this_.call(_method_fn, {});
}
Variant ReflectionProperty::isStatic() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1482]);
    }
    return this_.call(_method_fn, {});
}
Variant ReflectionProperty::isReadOnly() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1570]);
    }
    return this_.call(_method_fn, {});
}
Variant ReflectionProperty::isDefault() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1603]);
    }
    return this_.call(_method_fn, {});
}
Variant ReflectionProperty::isDynamic() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1604]);
    }
    return this_.call(_method_fn, {});
}
Variant ReflectionProperty::isAbstract() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1539]);
    }
    return this_.call(_method_fn, {});
}
Variant ReflectionProperty::isVirtual() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1605]);
    }
    return this_.call(_method_fn, {});
}
Variant ReflectionProperty::isPromoted() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1527]);
    }
    return this_.call(_method_fn, {});
}
Variant ReflectionProperty::getModifiers() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1543]);
    }
    return this_.call(_method_fn, {});
}
Variant ReflectionProperty::getDeclaringClass() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1515]);
    }
    return this_.call(_method_fn, {});
}
Variant ReflectionProperty::getDocComment() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1487]);
    }
    return this_.call(_method_fn, {});
}
Variant ReflectionProperty::setAccessible(const Variant &accessible) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1546]);
    }
    return this_.call(_method_fn, {accessible});
}
Variant ReflectionProperty::getType() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[989]);
    }
    return this_.call(_method_fn, {});
}
Variant ReflectionProperty::getSettableType() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1606]);
    }
    return this_.call(_method_fn, {});
}
Variant ReflectionProperty::hasType() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1517]);
    }
    return this_.call(_method_fn, {});
}
Variant ReflectionProperty::hasDefaultValue() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1607]);
    }
    return this_.call(_method_fn, {});
}
Variant ReflectionProperty::getDefaultValue() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1524]);
    }
    return this_.call(_method_fn, {});
}
Variant ReflectionProperty::getAttributes(const Variant &name, const Variant &flags) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1503]);
    }
    return this_.call(_method_fn, {name, flags});
}
Variant ReflectionProperty::hasHooks() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1608]);
    }
    return this_.call(_method_fn, {});
}
Variant ReflectionProperty::getHooks() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1609]);
    }
    return this_.call(_method_fn, {});
}
Variant ReflectionProperty::hasHook(const Variant &type) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1610]);
    }
    return this_.call(_method_fn, {type});
}
Variant ReflectionProperty::getHook(const Variant &type) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1611]);
    }
    return this_.call(_method_fn, {type});
}
Variant ReflectionProperty::isFinal() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1540]);
    }
    return this_.call(_method_fn, {});
}
ReflectionClassConstant::ReflectionClassConstant(const Variant &_class, const Variant &constant) {
    this_ = newObject(LITERAL_STRING[1612], {_class, constant});
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
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[300]);
    }
    return this_.call(_method_fn, {});
}
Variant ReflectionClassConstant::getValue() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[147]);
    }
    return this_.call(_method_fn, {});
}
Variant ReflectionClassConstant::isPublic() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1536]);
    }
    return this_.call(_method_fn, {});
}
Variant ReflectionClassConstant::isPrivate() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1537]);
    }
    return this_.call(_method_fn, {});
}
Variant ReflectionClassConstant::isProtected() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1538]);
    }
    return this_.call(_method_fn, {});
}
Variant ReflectionClassConstant::isFinal() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1540]);
    }
    return this_.call(_method_fn, {});
}
Variant ReflectionClassConstant::getModifiers() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1543]);
    }
    return this_.call(_method_fn, {});
}
Variant ReflectionClassConstant::getDeclaringClass() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1515]);
    }
    return this_.call(_method_fn, {});
}
Variant ReflectionClassConstant::getDocComment() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1487]);
    }
    return this_.call(_method_fn, {});
}
Variant ReflectionClassConstant::getAttributes(const Variant &name, const Variant &flags) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1503]);
    }
    return this_.call(_method_fn, {name, flags});
}
Variant ReflectionClassConstant::isEnumCase() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1613]);
    }
    return this_.call(_method_fn, {});
}
Variant ReflectionClassConstant::isDeprecated() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1477]);
    }
    return this_.call(_method_fn, {});
}
Variant ReflectionClassConstant::hasType() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1517]);
    }
    return this_.call(_method_fn, {});
}
Variant ReflectionClassConstant::getType() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[989]);
    }
    return this_.call(_method_fn, {});
}
ReflectionExtension::ReflectionExtension(const Variant &name) {
    this_ = newObject(LITERAL_STRING[1614], {name});
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
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[300]);
    }
    return this_.call(_method_fn, {});
}
Variant ReflectionExtension::getVersion() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[927]);
    }
    return this_.call(_method_fn, {});
}
Variant ReflectionExtension::getFunctions() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1615]);
    }
    return this_.call(_method_fn, {});
}
Variant ReflectionExtension::getConstants() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1558]);
    }
    return this_.call(_method_fn, {});
}
Variant ReflectionExtension::getINIEntries() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1616]);
    }
    return this_.call(_method_fn, {});
}
Variant ReflectionExtension::getClasses() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1617]);
    }
    return this_.call(_method_fn, {});
}
Variant ReflectionExtension::getClassNames() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1618]);
    }
    return this_.call(_method_fn, {});
}
Variant ReflectionExtension::getDependencies() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1619]);
    }
    return this_.call(_method_fn, {});
}
Variant ReflectionExtension::info() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1204]);
    }
    return this_.call(_method_fn, {});
}
Variant ReflectionExtension::isPersistent() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1620]);
    }
    return this_.call(_method_fn, {});
}
Variant ReflectionExtension::isTemporary() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1621]);
    }
    return this_.call(_method_fn, {});
}
ReflectionZendExtension::ReflectionZendExtension(const Variant &name) {
    this_ = newObject(LITERAL_STRING[1622], {name});
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
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[300]);
    }
    return this_.call(_method_fn, {});
}
Variant ReflectionZendExtension::getVersion() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[927]);
    }
    return this_.call(_method_fn, {});
}
Variant ReflectionZendExtension::getAuthor() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1623]);
    }
    return this_.call(_method_fn, {});
}
Variant ReflectionZendExtension::getURL() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1624]);
    }
    return this_.call(_method_fn, {});
}
Variant ReflectionZendExtension::getCopyright() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1625]);
    }
    return this_.call(_method_fn, {});
}
Variant ReflectionReference::fromArrayElement(const Variant &array, const Variant &key) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(LITERAL_STRING[1627], LITERAL_STRING[1628]);
    }
    return php::call(_method_fn, {array, key});
}
Variant ReflectionReference::getId() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1629]);
    }
    return this_.call(_method_fn, {});
}
Variant ReflectionAttribute::getName() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[300]);
    }
    return this_.call(_method_fn, {});
}
Variant ReflectionAttribute::getTarget() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1630]);
    }
    return this_.call(_method_fn, {});
}
Variant ReflectionAttribute::isRepeated() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1631]);
    }
    return this_.call(_method_fn, {});
}
Variant ReflectionAttribute::getArguments() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1632]);
    }
    return this_.call(_method_fn, {});
}
Variant ReflectionAttribute::newInstance() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1572]);
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
ReflectionEnum::ReflectionEnum(const Variant &object_or_class) {
    this_ = newObject(LITERAL_STRING[1634], {object_or_class});
}
Variant ReflectionEnum::hasCase(const Variant &name) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1635]);
    }
    return this_.call(_method_fn, {name});
}
Variant ReflectionEnum::getCase(const Variant &name) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1636]);
    }
    return this_.call(_method_fn, {name});
}
Variant ReflectionEnum::getCases() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1637]);
    }
    return this_.call(_method_fn, {});
}
Variant ReflectionEnum::isBacked() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1638]);
    }
    return this_.call(_method_fn, {});
}
Variant ReflectionEnum::getBackingType() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1639]);
    }
    return this_.call(_method_fn, {});
}
Variant ReflectionEnum::__toString() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[29]);
    }
    return this_.call(_method_fn, {});
}
Variant ReflectionEnum::getName() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[300]);
    }
    return this_.call(_method_fn, {});
}
Variant ReflectionEnum::isInternal() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1478]);
    }
    return this_.call(_method_fn, {});
}
Variant ReflectionEnum::isUserDefined() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1479]);
    }
    return this_.call(_method_fn, {});
}
Variant ReflectionEnum::isAnonymous() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1470]);
    }
    return this_.call(_method_fn, {});
}
Variant ReflectionEnum::isInstantiable() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1548]);
    }
    return this_.call(_method_fn, {});
}
Variant ReflectionEnum::isCloneable() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1549]);
    }
    return this_.call(_method_fn, {});
}
Variant ReflectionEnum::getFileName() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1490]);
    }
    return this_.call(_method_fn, {});
}
Variant ReflectionEnum::getStartLine() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1496]);
    }
    return this_.call(_method_fn, {});
}
Variant ReflectionEnum::getEndLine() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1488]);
    }
    return this_.call(_method_fn, {});
}
Variant ReflectionEnum::getDocComment() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1487]);
    }
    return this_.call(_method_fn, {});
}
Variant ReflectionEnum::getConstructor() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1550]);
    }
    return this_.call(_method_fn, {});
}
Variant ReflectionEnum::hasMethod(const Variant &name) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1551]);
    }
    return this_.call(_method_fn, {name});
}
Variant ReflectionEnum::getMethod(const Variant &name) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1552]);
    }
    return this_.call(_method_fn, {name});
}
Variant ReflectionEnum::getMethods(const Variant &filter) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1553]);
    }
    return this_.call(_method_fn, {filter});
}
Variant ReflectionEnum::hasProperty(const Variant &name) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1554]);
    }
    return this_.call(_method_fn, {name});
}
Variant ReflectionEnum::getProperty(const Variant &name) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1555]);
    }
    return this_.call(_method_fn, {name});
}
Variant ReflectionEnum::getProperties(const Variant &filter) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1556]);
    }
    return this_.call(_method_fn, {filter});
}
Variant ReflectionEnum::hasConstant(const Variant &name) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1557]);
    }
    return this_.call(_method_fn, {name});
}
Variant ReflectionEnum::getConstants(const Variant &filter) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1558]);
    }
    return this_.call(_method_fn, {filter});
}
Variant ReflectionEnum::getReflectionConstants(const Variant &filter) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1559]);
    }
    return this_.call(_method_fn, {filter});
}
Variant ReflectionEnum::getConstant(const Variant &name) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1560]);
    }
    return this_.call(_method_fn, {name});
}
Variant ReflectionEnum::getReflectionConstant(const Variant &name) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1561]);
    }
    return this_.call(_method_fn, {name});
}
Variant ReflectionEnum::getInterfaces() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1562]);
    }
    return this_.call(_method_fn, {});
}
Variant ReflectionEnum::getInterfaceNames() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1563]);
    }
    return this_.call(_method_fn, {});
}
Variant ReflectionEnum::isInterface() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1564]);
    }
    return this_.call(_method_fn, {});
}
Variant ReflectionEnum::getTraits() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1565]);
    }
    return this_.call(_method_fn, {});
}
Variant ReflectionEnum::getTraitNames() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1566]);
    }
    return this_.call(_method_fn, {});
}
Variant ReflectionEnum::getTraitAliases() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1567]);
    }
    return this_.call(_method_fn, {});
}
Variant ReflectionEnum::isTrait() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1568]);
    }
    return this_.call(_method_fn, {});
}
Variant ReflectionEnum::isEnum() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1569]);
    }
    return this_.call(_method_fn, {});
}
Variant ReflectionEnum::isAbstract() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1539]);
    }
    return this_.call(_method_fn, {});
}
Variant ReflectionEnum::isFinal() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1540]);
    }
    return this_.call(_method_fn, {});
}
Variant ReflectionEnum::isReadOnly() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1570]);
    }
    return this_.call(_method_fn, {});
}
Variant ReflectionEnum::getModifiers() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1543]);
    }
    return this_.call(_method_fn, {});
}
Variant ReflectionEnum::isInstance(const Variant &object) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1571]);
    }
    return this_.call(_method_fn, {object});
}
Variant ReflectionEnum::newInstanceWithoutConstructor() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1573]);
    }
    return this_.call(_method_fn, {});
}
Variant ReflectionEnum::newInstanceArgs(const Variant &args) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1574]);
    }
    return this_.call(_method_fn, {args});
}
Variant ReflectionEnum::newLazyGhost(const Variant &initializer, const Variant &options) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1575]);
    }
    return this_.call(_method_fn, {initializer, options});
}
Variant ReflectionEnum::newLazyProxy(const Variant &factory, const Variant &options) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1576]);
    }
    return this_.call(_method_fn, {factory, options});
}
Variant ReflectionEnum::resetAsLazyGhost(const Variant &object, const Variant &initializer, const Variant &options) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1577]);
    }
    return this_.call(_method_fn, {object, initializer, options});
}
Variant ReflectionEnum::resetAsLazyProxy(const Variant &object, const Variant &factory, const Variant &options) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1578]);
    }
    return this_.call(_method_fn, {object, factory, options});
}
Variant ReflectionEnum::initializeLazyObject(const Variant &object) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1579]);
    }
    return this_.call(_method_fn, {object});
}
Variant ReflectionEnum::isUninitializedLazyObject(const Variant &object) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1580]);
    }
    return this_.call(_method_fn, {object});
}
Variant ReflectionEnum::markLazyObjectAsInitialized(const Variant &object) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1581]);
    }
    return this_.call(_method_fn, {object});
}
Variant ReflectionEnum::getLazyInitializer(const Variant &object) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1582]);
    }
    return this_.call(_method_fn, {object});
}
Variant ReflectionEnum::getParentClass() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1583]);
    }
    return this_.call(_method_fn, {});
}
Variant ReflectionEnum::isSubclassOf(const Variant &_class) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1584]);
    }
    return this_.call(_method_fn, {_class});
}
Variant ReflectionEnum::getStaticProperties() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1585]);
    }
    return this_.call(_method_fn, {});
}
Variant ReflectionEnum::getStaticPropertyValue(const Variant &name, const Variant &_default) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1586]);
    }
    return this_.call(_method_fn, {name, _default});
}
Variant ReflectionEnum::setStaticPropertyValue(const Variant &name, const Variant &value) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1587]);
    }
    return this_.call(_method_fn, {name, value});
}
Variant ReflectionEnum::getDefaultProperties() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1588]);
    }
    return this_.call(_method_fn, {});
}
Variant ReflectionEnum::isIterable() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1589]);
    }
    return this_.call(_method_fn, {});
}
Variant ReflectionEnum::isIterateable() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1590]);
    }
    return this_.call(_method_fn, {});
}
Variant ReflectionEnum::implementsInterface(const Variant &interface) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1591]);
    }
    return this_.call(_method_fn, {interface});
}
Variant ReflectionEnum::getExtension() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[976]);
    }
    return this_.call(_method_fn, {});
}
Variant ReflectionEnum::getExtensionName() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1489]);
    }
    return this_.call(_method_fn, {});
}
Variant ReflectionEnum::inNamespace() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1475]);
    }
    return this_.call(_method_fn, {});
}
Variant ReflectionEnum::getNamespaceName() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1491]);
    }
    return this_.call(_method_fn, {});
}
Variant ReflectionEnum::getShortName() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1495]);
    }
    return this_.call(_method_fn, {});
}
Variant ReflectionEnum::getAttributes(const Variant &name, const Variant &flags) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1503]);
    }
    return this_.call(_method_fn, {name, flags});
}
ReflectionEnumUnitCase::ReflectionEnumUnitCase(const Variant &_class, const Variant &constant) {
    this_ = newObject(LITERAL_STRING[1640], {_class, constant});
}
Variant ReflectionEnumUnitCase::getEnum() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1641]);
    }
    return this_.call(_method_fn, {});
}
Variant ReflectionEnumUnitCase::getValue() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[147]);
    }
    return this_.call(_method_fn, {});
}
Variant ReflectionEnumUnitCase::__toString() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[29]);
    }
    return this_.call(_method_fn, {});
}
Variant ReflectionEnumUnitCase::getName() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[300]);
    }
    return this_.call(_method_fn, {});
}
Variant ReflectionEnumUnitCase::isPublic() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1536]);
    }
    return this_.call(_method_fn, {});
}
Variant ReflectionEnumUnitCase::isPrivate() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1537]);
    }
    return this_.call(_method_fn, {});
}
Variant ReflectionEnumUnitCase::isProtected() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1538]);
    }
    return this_.call(_method_fn, {});
}
Variant ReflectionEnumUnitCase::isFinal() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1540]);
    }
    return this_.call(_method_fn, {});
}
Variant ReflectionEnumUnitCase::getModifiers() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1543]);
    }
    return this_.call(_method_fn, {});
}
Variant ReflectionEnumUnitCase::getDeclaringClass() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1515]);
    }
    return this_.call(_method_fn, {});
}
Variant ReflectionEnumUnitCase::getDocComment() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1487]);
    }
    return this_.call(_method_fn, {});
}
Variant ReflectionEnumUnitCase::getAttributes(const Variant &name, const Variant &flags) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1503]);
    }
    return this_.call(_method_fn, {name, flags});
}
Variant ReflectionEnumUnitCase::isEnumCase() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1613]);
    }
    return this_.call(_method_fn, {});
}
Variant ReflectionEnumUnitCase::isDeprecated() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1477]);
    }
    return this_.call(_method_fn, {});
}
Variant ReflectionEnumUnitCase::hasType() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1517]);
    }
    return this_.call(_method_fn, {});
}
Variant ReflectionEnumUnitCase::getType() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[989]);
    }
    return this_.call(_method_fn, {});
}
ReflectionEnumBackedCase::ReflectionEnumBackedCase(const Variant &_class, const Variant &constant) {
    this_ = newObject(LITERAL_STRING[1642], {_class, constant});
}
Variant ReflectionEnumBackedCase::getBackingValue() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1643]);
    }
    return this_.call(_method_fn, {});
}
Variant ReflectionEnumBackedCase::getEnum() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1641]);
    }
    return this_.call(_method_fn, {});
}
Variant ReflectionEnumBackedCase::getValue() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[147]);
    }
    return this_.call(_method_fn, {});
}
Variant ReflectionEnumBackedCase::__toString() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[29]);
    }
    return this_.call(_method_fn, {});
}
Variant ReflectionEnumBackedCase::getName() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[300]);
    }
    return this_.call(_method_fn, {});
}
Variant ReflectionEnumBackedCase::isPublic() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1536]);
    }
    return this_.call(_method_fn, {});
}
Variant ReflectionEnumBackedCase::isPrivate() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1537]);
    }
    return this_.call(_method_fn, {});
}
Variant ReflectionEnumBackedCase::isProtected() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1538]);
    }
    return this_.call(_method_fn, {});
}
Variant ReflectionEnumBackedCase::isFinal() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1540]);
    }
    return this_.call(_method_fn, {});
}
Variant ReflectionEnumBackedCase::getModifiers() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1543]);
    }
    return this_.call(_method_fn, {});
}
Variant ReflectionEnumBackedCase::getDeclaringClass() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1515]);
    }
    return this_.call(_method_fn, {});
}
Variant ReflectionEnumBackedCase::getDocComment() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1487]);
    }
    return this_.call(_method_fn, {});
}
Variant ReflectionEnumBackedCase::getAttributes(const Variant &name, const Variant &flags) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1503]);
    }
    return this_.call(_method_fn, {name, flags});
}
Variant ReflectionEnumBackedCase::isEnumCase() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1613]);
    }
    return this_.call(_method_fn, {});
}
Variant ReflectionEnumBackedCase::isDeprecated() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1477]);
    }
    return this_.call(_method_fn, {});
}
Variant ReflectionEnumBackedCase::hasType() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1517]);
    }
    return this_.call(_method_fn, {});
}
Variant ReflectionEnumBackedCase::getType() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[989]);
    }
    return this_.call(_method_fn, {});
}
ReflectionFiber::ReflectionFiber(const Variant &fiber) {
    this_ = newObject(LITERAL_STRING[1644], {fiber});
}
Variant ReflectionFiber::getFiber() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1645]);
    }
    return this_.call(_method_fn, {});
}
Variant ReflectionFiber::getExecutingFile() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1506]);
    }
    return this_.call(_method_fn, {});
}
Variant ReflectionFiber::getExecutingLine() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1505]);
    }
    return this_.call(_method_fn, {});
}
Variant ReflectionFiber::getCallable() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1646]);
    }
    return this_.call(_method_fn, {});
}
Variant ReflectionFiber::getTrace(const Variant &options) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[102]);
    }
    return this_.call(_method_fn, {options});
}
ReflectionConstant::ReflectionConstant(const Variant &name) {
    this_ = newObject(LITERAL_STRING[1647], {name});
}
Variant ReflectionConstant::getName() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[300]);
    }
    return this_.call(_method_fn, {});
}
Variant ReflectionConstant::getNamespaceName() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1491]);
    }
    return this_.call(_method_fn, {});
}
Variant ReflectionConstant::getShortName() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1495]);
    }
    return this_.call(_method_fn, {});
}
Variant ReflectionConstant::getValue() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[147]);
    }
    return this_.call(_method_fn, {});
}
Variant ReflectionConstant::isDeprecated() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1477]);
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
    this_ = newObject(LITERAL_STRING[1648]);
}
Variant PropertyHookType::cases() {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(LITERAL_STRING[1648], LITERAL_STRING[334]);
    }
    return php::call(_method_fn, {});
}
Variant PropertyHookType::from(const Variant &value) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(LITERAL_STRING[1648], LITERAL_STRING[336]);
    }
    return php::call(_method_fn, {value});
}
Variant PropertyHookType::tryFrom(const Variant &value) {
    static THREAD_LOCAL zend_function *_method_fn = nullptr;
    if (UNEXPECTED(!_method_fn)) {
        _method_fn = php::getMethod(LITERAL_STRING[1648], LITERAL_STRING[338]);
    }
    return php::call(_method_fn, {value});
}
}  // namespace php

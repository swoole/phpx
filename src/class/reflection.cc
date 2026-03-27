#include "phpx.h"
#include "class/reflection.h"

namespace php {
ReflectionException::ReflectionException(const Variant &message, const Variant &code, const Variant &previous) {
    this_ = newObject(LITERAL_STRING[1408], {message, code, previous});
}
Variant ReflectionException::__wakeup() {
    return this_.call(LITERAL_STRING[97], {});
}
Variant ReflectionException::getMessage() {
    return this_.call(LITERAL_STRING[98], {});
}
Variant ReflectionException::getCode() {
    return this_.call(LITERAL_STRING[99], {});
}
Variant ReflectionException::getFile() {
    return this_.call(LITERAL_STRING[100], {});
}
Variant ReflectionException::getLine() {
    return this_.call(LITERAL_STRING[101], {});
}
Variant ReflectionException::getTrace() {
    return this_.call(LITERAL_STRING[102], {});
}
Variant ReflectionException::getPrevious() {
    return this_.call(LITERAL_STRING[103], {});
}
Variant ReflectionException::getTraceAsString() {
    return this_.call(LITERAL_STRING[104], {});
}
Variant ReflectionException::__toString() {
    return this_.call(LITERAL_STRING[29], {});
}
Variant Reflection::getModifierNames(const Variant &modifiers) {
    return php::call(LITERAL_STRING[1409], {modifiers});
}
ReflectionFunction::ReflectionFunction(const Variant &function) {
    this_ = newObject(LITERAL_STRING[1411], {function});
}
Variant ReflectionFunction::__toString() {
    return this_.call(LITERAL_STRING[29], {});
}
Variant ReflectionFunction::isAnonymous() {
    return this_.call(LITERAL_STRING[1412], {});
}
Variant ReflectionFunction::isDisabled() {
    return this_.call(LITERAL_STRING[1413], {});
}
Variant ReflectionFunction::invokeArgs(const Variant &args) {
    return this_.call(LITERAL_STRING[1415], {args});
}
Variant ReflectionFunction::getClosure() {
    return this_.call(LITERAL_STRING[1416], {});
}
Variant ReflectionFunction::inNamespace() {
    return this_.call(LITERAL_STRING[1417], {});
}
Variant ReflectionFunction::isClosure() {
    return this_.call(LITERAL_STRING[1418], {});
}
Variant ReflectionFunction::isDeprecated() {
    return this_.call(LITERAL_STRING[1419], {});
}
Variant ReflectionFunction::isInternal() {
    return this_.call(LITERAL_STRING[1420], {});
}
Variant ReflectionFunction::isUserDefined() {
    return this_.call(LITERAL_STRING[1421], {});
}
Variant ReflectionFunction::isGenerator() {
    return this_.call(LITERAL_STRING[1422], {});
}
Variant ReflectionFunction::isVariadic() {
    return this_.call(LITERAL_STRING[1423], {});
}
Variant ReflectionFunction::isStatic() {
    return this_.call(LITERAL_STRING[1424], {});
}
Variant ReflectionFunction::getClosureThis() {
    return this_.call(LITERAL_STRING[1425], {});
}
Variant ReflectionFunction::getClosureScopeClass() {
    return this_.call(LITERAL_STRING[1426], {});
}
Variant ReflectionFunction::getClosureCalledClass() {
    return this_.call(LITERAL_STRING[1427], {});
}
Variant ReflectionFunction::getClosureUsedVariables() {
    return this_.call(LITERAL_STRING[1428], {});
}
Variant ReflectionFunction::getDocComment() {
    return this_.call(LITERAL_STRING[1429], {});
}
Variant ReflectionFunction::getEndLine() {
    return this_.call(LITERAL_STRING[1430], {});
}
Variant ReflectionFunction::getExtension() {
    return this_.call(LITERAL_STRING[919], {});
}
Variant ReflectionFunction::getExtensionName() {
    return this_.call(LITERAL_STRING[1431], {});
}
Variant ReflectionFunction::getFileName() {
    return this_.call(LITERAL_STRING[1432], {});
}
Variant ReflectionFunction::getName() {
    return this_.call(LITERAL_STRING[284], {});
}
Variant ReflectionFunction::getNamespaceName() {
    return this_.call(LITERAL_STRING[1433], {});
}
Variant ReflectionFunction::getNumberOfParameters() {
    return this_.call(LITERAL_STRING[1434], {});
}
Variant ReflectionFunction::getNumberOfRequiredParameters() {
    return this_.call(LITERAL_STRING[1435], {});
}
Variant ReflectionFunction::getParameters() {
    return this_.call(LITERAL_STRING[1436], {});
}
Variant ReflectionFunction::getShortName() {
    return this_.call(LITERAL_STRING[1437], {});
}
Variant ReflectionFunction::getStartLine() {
    return this_.call(LITERAL_STRING[1438], {});
}
Variant ReflectionFunction::getStaticVariables() {
    return this_.call(LITERAL_STRING[1439], {});
}
Variant ReflectionFunction::returnsReference() {
    return this_.call(LITERAL_STRING[1440], {});
}
Variant ReflectionFunction::hasReturnType() {
    return this_.call(LITERAL_STRING[1441], {});
}
Variant ReflectionFunction::getReturnType() {
    return this_.call(LITERAL_STRING[1442], {});
}
Variant ReflectionFunction::hasTentativeReturnType() {
    return this_.call(LITERAL_STRING[1443], {});
}
Variant ReflectionFunction::getTentativeReturnType() {
    return this_.call(LITERAL_STRING[1444], {});
}
Variant ReflectionFunction::getAttributes(const Variant &name, const Variant &flags) {
    return this_.call(LITERAL_STRING[1445], {name, flags});
}
ReflectionGenerator::ReflectionGenerator(const Variant &generator) {
    this_ = newObject(LITERAL_STRING[1446], {generator});
}
Variant ReflectionGenerator::getExecutingLine() {
    return this_.call(LITERAL_STRING[1447], {});
}
Variant ReflectionGenerator::getExecutingFile() {
    return this_.call(LITERAL_STRING[1448], {});
}
Variant ReflectionGenerator::getTrace(const Variant &options) {
    return this_.call(LITERAL_STRING[102], {options});
}
Variant ReflectionGenerator::getFunction() {
    return this_.call(LITERAL_STRING[1449], {});
}
Variant ReflectionGenerator::_getThis() {
    return this_.call(LITERAL_STRING[1450], {});
}
Variant ReflectionGenerator::getExecutingGenerator() {
    return this_.call(LITERAL_STRING[1451], {});
}
Variant ReflectionGenerator::isClosed() {
    return this_.call(LITERAL_STRING[1452], {});
}
ReflectionParameter::ReflectionParameter(const Variant &function, const Variant &param) {
    this_ = newObject(LITERAL_STRING[1453], {function, param});
}
Variant ReflectionParameter::__toString() {
    return this_.call(LITERAL_STRING[29], {});
}
Variant ReflectionParameter::getName() {
    return this_.call(LITERAL_STRING[284], {});
}
Variant ReflectionParameter::isPassedByReference() {
    return this_.call(LITERAL_STRING[1454], {});
}
Variant ReflectionParameter::canBePassedByValue() {
    return this_.call(LITERAL_STRING[1455], {});
}
Variant ReflectionParameter::getDeclaringFunction() {
    return this_.call(LITERAL_STRING[1456], {});
}
Variant ReflectionParameter::getDeclaringClass() {
    return this_.call(LITERAL_STRING[1457], {});
}
Variant ReflectionParameter::getClass() {
    return this_.call(LITERAL_STRING[1458], {});
}
Variant ReflectionParameter::hasType() {
    return this_.call(LITERAL_STRING[1459], {});
}
Variant ReflectionParameter::getType() {
    return this_.call(LITERAL_STRING[932], {});
}
Variant ReflectionParameter::isArray() {
    return this_.call(LITERAL_STRING[1460], {});
}
Variant ReflectionParameter::isCallable() {
    return this_.call(LITERAL_STRING[1461], {});
}
Variant ReflectionParameter::allowsNull() {
    return this_.call(LITERAL_STRING[1462], {});
}
Variant ReflectionParameter::getPosition() {
    return this_.call(LITERAL_STRING[1463], {});
}
Variant ReflectionParameter::isOptional() {
    return this_.call(LITERAL_STRING[1464], {});
}
Variant ReflectionParameter::isDefaultValueAvailable() {
    return this_.call(LITERAL_STRING[1465], {});
}
Variant ReflectionParameter::getDefaultValue() {
    return this_.call(LITERAL_STRING[1466], {});
}
Variant ReflectionParameter::isDefaultValueConstant() {
    return this_.call(LITERAL_STRING[1467], {});
}
Variant ReflectionParameter::getDefaultValueConstantName() {
    return this_.call(LITERAL_STRING[1468], {});
}
Variant ReflectionParameter::isVariadic() {
    return this_.call(LITERAL_STRING[1423], {});
}
Variant ReflectionParameter::isPromoted() {
    return this_.call(LITERAL_STRING[1469], {});
}
Variant ReflectionParameter::getAttributes(const Variant &name, const Variant &flags) {
    return this_.call(LITERAL_STRING[1445], {name, flags});
}
Variant ReflectionNamedType::getName() {
    return this_.call(LITERAL_STRING[284], {});
}
Variant ReflectionNamedType::isBuiltin() {
    return this_.call(LITERAL_STRING[1470], {});
}
Variant ReflectionNamedType::allowsNull() {
    return this_.call(LITERAL_STRING[1462], {});
}
Variant ReflectionNamedType::__toString() {
    return this_.call(LITERAL_STRING[29], {});
}
Variant ReflectionUnionType::getTypes() {
    return this_.call(LITERAL_STRING[1472], {});
}
Variant ReflectionUnionType::allowsNull() {
    return this_.call(LITERAL_STRING[1462], {});
}
Variant ReflectionUnionType::__toString() {
    return this_.call(LITERAL_STRING[29], {});
}
Variant ReflectionIntersectionType::getTypes() {
    return this_.call(LITERAL_STRING[1472], {});
}
Variant ReflectionIntersectionType::allowsNull() {
    return this_.call(LITERAL_STRING[1462], {});
}
Variant ReflectionIntersectionType::__toString() {
    return this_.call(LITERAL_STRING[29], {});
}
ReflectionMethod::ReflectionMethod(const Variant &object_or_method, const Variant &method) {
    this_ = newObject(LITERAL_STRING[1475], {object_or_method, method});
}
Variant ReflectionMethod::createFromMethodName(const Variant &method) {
    return php::call(LITERAL_STRING[1476], {method});
}
Variant ReflectionMethod::__toString() {
    return this_.call(LITERAL_STRING[29], {});
}
Variant ReflectionMethod::isPublic() {
    return this_.call(LITERAL_STRING[1477], {});
}
Variant ReflectionMethod::isPrivate() {
    return this_.call(LITERAL_STRING[1478], {});
}
Variant ReflectionMethod::isProtected() {
    return this_.call(LITERAL_STRING[1479], {});
}
Variant ReflectionMethod::isAbstract() {
    return this_.call(LITERAL_STRING[1480], {});
}
Variant ReflectionMethod::isFinal() {
    return this_.call(LITERAL_STRING[1481], {});
}
Variant ReflectionMethod::isConstructor() {
    return this_.call(LITERAL_STRING[1482], {});
}
Variant ReflectionMethod::isDestructor() {
    return this_.call(LITERAL_STRING[1483], {});
}
Variant ReflectionMethod::getClosure(const Variant &object) {
    return this_.call(LITERAL_STRING[1416], {object});
}
Variant ReflectionMethod::getModifiers() {
    return this_.call(LITERAL_STRING[1484], {});
}
Variant ReflectionMethod::invokeArgs(const Variant &object, const Variant &args) {
    return this_.call(LITERAL_STRING[1415], {object, args});
}
Variant ReflectionMethod::getDeclaringClass() {
    return this_.call(LITERAL_STRING[1457], {});
}
Variant ReflectionMethod::getPrototype() {
    return this_.call(LITERAL_STRING[1485], {});
}
Variant ReflectionMethod::hasPrototype() {
    return this_.call(LITERAL_STRING[1486], {});
}
Variant ReflectionMethod::setAccessible(const Variant &accessible) {
    return this_.call(LITERAL_STRING[1487], {accessible});
}
Variant ReflectionMethod::inNamespace() {
    return this_.call(LITERAL_STRING[1417], {});
}
Variant ReflectionMethod::isClosure() {
    return this_.call(LITERAL_STRING[1418], {});
}
Variant ReflectionMethod::isDeprecated() {
    return this_.call(LITERAL_STRING[1419], {});
}
Variant ReflectionMethod::isInternal() {
    return this_.call(LITERAL_STRING[1420], {});
}
Variant ReflectionMethod::isUserDefined() {
    return this_.call(LITERAL_STRING[1421], {});
}
Variant ReflectionMethod::isGenerator() {
    return this_.call(LITERAL_STRING[1422], {});
}
Variant ReflectionMethod::isVariadic() {
    return this_.call(LITERAL_STRING[1423], {});
}
Variant ReflectionMethod::isStatic() {
    return this_.call(LITERAL_STRING[1424], {});
}
Variant ReflectionMethod::getClosureThis() {
    return this_.call(LITERAL_STRING[1425], {});
}
Variant ReflectionMethod::getClosureScopeClass() {
    return this_.call(LITERAL_STRING[1426], {});
}
Variant ReflectionMethod::getClosureCalledClass() {
    return this_.call(LITERAL_STRING[1427], {});
}
Variant ReflectionMethod::getClosureUsedVariables() {
    return this_.call(LITERAL_STRING[1428], {});
}
Variant ReflectionMethod::getDocComment() {
    return this_.call(LITERAL_STRING[1429], {});
}
Variant ReflectionMethod::getEndLine() {
    return this_.call(LITERAL_STRING[1430], {});
}
Variant ReflectionMethod::getExtension() {
    return this_.call(LITERAL_STRING[919], {});
}
Variant ReflectionMethod::getExtensionName() {
    return this_.call(LITERAL_STRING[1431], {});
}
Variant ReflectionMethod::getFileName() {
    return this_.call(LITERAL_STRING[1432], {});
}
Variant ReflectionMethod::getName() {
    return this_.call(LITERAL_STRING[284], {});
}
Variant ReflectionMethod::getNamespaceName() {
    return this_.call(LITERAL_STRING[1433], {});
}
Variant ReflectionMethod::getNumberOfParameters() {
    return this_.call(LITERAL_STRING[1434], {});
}
Variant ReflectionMethod::getNumberOfRequiredParameters() {
    return this_.call(LITERAL_STRING[1435], {});
}
Variant ReflectionMethod::getParameters() {
    return this_.call(LITERAL_STRING[1436], {});
}
Variant ReflectionMethod::getShortName() {
    return this_.call(LITERAL_STRING[1437], {});
}
Variant ReflectionMethod::getStartLine() {
    return this_.call(LITERAL_STRING[1438], {});
}
Variant ReflectionMethod::getStaticVariables() {
    return this_.call(LITERAL_STRING[1439], {});
}
Variant ReflectionMethod::returnsReference() {
    return this_.call(LITERAL_STRING[1440], {});
}
Variant ReflectionMethod::hasReturnType() {
    return this_.call(LITERAL_STRING[1441], {});
}
Variant ReflectionMethod::getReturnType() {
    return this_.call(LITERAL_STRING[1442], {});
}
Variant ReflectionMethod::hasTentativeReturnType() {
    return this_.call(LITERAL_STRING[1443], {});
}
Variant ReflectionMethod::getTentativeReturnType() {
    return this_.call(LITERAL_STRING[1444], {});
}
Variant ReflectionMethod::getAttributes(const Variant &name, const Variant &flags) {
    return this_.call(LITERAL_STRING[1445], {name, flags});
}
ReflectionClass::ReflectionClass(const Variant &object_or_class) {
    this_ = newObject(LITERAL_STRING[1488], {object_or_class});
}
Variant ReflectionClass::__toString() {
    return this_.call(LITERAL_STRING[29], {});
}
Variant ReflectionClass::getName() {
    return this_.call(LITERAL_STRING[284], {});
}
Variant ReflectionClass::isInternal() {
    return this_.call(LITERAL_STRING[1420], {});
}
Variant ReflectionClass::isUserDefined() {
    return this_.call(LITERAL_STRING[1421], {});
}
Variant ReflectionClass::isAnonymous() {
    return this_.call(LITERAL_STRING[1412], {});
}
Variant ReflectionClass::isInstantiable() {
    return this_.call(LITERAL_STRING[1489], {});
}
Variant ReflectionClass::isCloneable() {
    return this_.call(LITERAL_STRING[1490], {});
}
Variant ReflectionClass::getFileName() {
    return this_.call(LITERAL_STRING[1432], {});
}
Variant ReflectionClass::getStartLine() {
    return this_.call(LITERAL_STRING[1438], {});
}
Variant ReflectionClass::getEndLine() {
    return this_.call(LITERAL_STRING[1430], {});
}
Variant ReflectionClass::getDocComment() {
    return this_.call(LITERAL_STRING[1429], {});
}
Variant ReflectionClass::getConstructor() {
    return this_.call(LITERAL_STRING[1491], {});
}
Variant ReflectionClass::hasMethod(const Variant &name) {
    return this_.call(LITERAL_STRING[1492], {name});
}
Variant ReflectionClass::getMethod(const Variant &name) {
    return this_.call(LITERAL_STRING[1493], {name});
}
Variant ReflectionClass::getMethods(const Variant &filter) {
    return this_.call(LITERAL_STRING[1494], {filter});
}
Variant ReflectionClass::hasProperty(const Variant &name) {
    return this_.call(LITERAL_STRING[1495], {name});
}
Variant ReflectionClass::getProperty(const Variant &name) {
    return this_.call(LITERAL_STRING[1496], {name});
}
Variant ReflectionClass::getProperties(const Variant &filter) {
    return this_.call(LITERAL_STRING[1497], {filter});
}
Variant ReflectionClass::hasConstant(const Variant &name) {
    return this_.call(LITERAL_STRING[1498], {name});
}
Variant ReflectionClass::getConstants(const Variant &filter) {
    return this_.call(LITERAL_STRING[1499], {filter});
}
Variant ReflectionClass::getReflectionConstants(const Variant &filter) {
    return this_.call(LITERAL_STRING[1500], {filter});
}
Variant ReflectionClass::getConstant(const Variant &name) {
    return this_.call(LITERAL_STRING[1501], {name});
}
Variant ReflectionClass::getReflectionConstant(const Variant &name) {
    return this_.call(LITERAL_STRING[1502], {name});
}
Variant ReflectionClass::getInterfaces() {
    return this_.call(LITERAL_STRING[1503], {});
}
Variant ReflectionClass::getInterfaceNames() {
    return this_.call(LITERAL_STRING[1504], {});
}
Variant ReflectionClass::isInterface() {
    return this_.call(LITERAL_STRING[1505], {});
}
Variant ReflectionClass::getTraits() {
    return this_.call(LITERAL_STRING[1506], {});
}
Variant ReflectionClass::getTraitNames() {
    return this_.call(LITERAL_STRING[1507], {});
}
Variant ReflectionClass::getTraitAliases() {
    return this_.call(LITERAL_STRING[1508], {});
}
Variant ReflectionClass::isTrait() {
    return this_.call(LITERAL_STRING[1509], {});
}
Variant ReflectionClass::isEnum() {
    return this_.call(LITERAL_STRING[1510], {});
}
Variant ReflectionClass::isAbstract() {
    return this_.call(LITERAL_STRING[1480], {});
}
Variant ReflectionClass::isFinal() {
    return this_.call(LITERAL_STRING[1481], {});
}
Variant ReflectionClass::isReadOnly() {
    return this_.call(LITERAL_STRING[1511], {});
}
Variant ReflectionClass::getModifiers() {
    return this_.call(LITERAL_STRING[1484], {});
}
Variant ReflectionClass::isInstance(const Variant &object) {
    return this_.call(LITERAL_STRING[1512], {object});
}
Variant ReflectionClass::newInstanceWithoutConstructor() {
    return this_.call(LITERAL_STRING[1514], {});
}
Variant ReflectionClass::newInstanceArgs(const Variant &args) {
    return this_.call(LITERAL_STRING[1515], {args});
}
Variant ReflectionClass::newLazyGhost(const Variant &initializer, const Variant &options) {
    return this_.call(LITERAL_STRING[1516], {initializer, options});
}
Variant ReflectionClass::newLazyProxy(const Variant &factory, const Variant &options) {
    return this_.call(LITERAL_STRING[1517], {factory, options});
}
Variant ReflectionClass::resetAsLazyGhost(const Variant &object, const Variant &initializer, const Variant &options) {
    return this_.call(LITERAL_STRING[1518], {object, initializer, options});
}
Variant ReflectionClass::resetAsLazyProxy(const Variant &object, const Variant &factory, const Variant &options) {
    return this_.call(LITERAL_STRING[1519], {object, factory, options});
}
Variant ReflectionClass::initializeLazyObject(const Variant &object) {
    return this_.call(LITERAL_STRING[1520], {object});
}
Variant ReflectionClass::isUninitializedLazyObject(const Variant &object) {
    return this_.call(LITERAL_STRING[1521], {object});
}
Variant ReflectionClass::markLazyObjectAsInitialized(const Variant &object) {
    return this_.call(LITERAL_STRING[1522], {object});
}
Variant ReflectionClass::getLazyInitializer(const Variant &object) {
    return this_.call(LITERAL_STRING[1523], {object});
}
Variant ReflectionClass::getParentClass() {
    return this_.call(LITERAL_STRING[1524], {});
}
Variant ReflectionClass::isSubclassOf(const Variant &_class) {
    return this_.call(LITERAL_STRING[1525], {_class});
}
Variant ReflectionClass::getStaticProperties() {
    return this_.call(LITERAL_STRING[1526], {});
}
Variant ReflectionClass::getStaticPropertyValue(const Variant &name, const Variant &_default) {
    return this_.call(LITERAL_STRING[1527], {name, _default});
}
Variant ReflectionClass::setStaticPropertyValue(const Variant &name, const Variant &value) {
    return this_.call(LITERAL_STRING[1528], {name, value});
}
Variant ReflectionClass::getDefaultProperties() {
    return this_.call(LITERAL_STRING[1529], {});
}
Variant ReflectionClass::isIterable() {
    return this_.call(LITERAL_STRING[1530], {});
}
Variant ReflectionClass::isIterateable() {
    return this_.call(LITERAL_STRING[1531], {});
}
Variant ReflectionClass::implementsInterface(const Variant &interface) {
    return this_.call(LITERAL_STRING[1532], {interface});
}
Variant ReflectionClass::getExtension() {
    return this_.call(LITERAL_STRING[919], {});
}
Variant ReflectionClass::getExtensionName() {
    return this_.call(LITERAL_STRING[1431], {});
}
Variant ReflectionClass::inNamespace() {
    return this_.call(LITERAL_STRING[1417], {});
}
Variant ReflectionClass::getNamespaceName() {
    return this_.call(LITERAL_STRING[1433], {});
}
Variant ReflectionClass::getShortName() {
    return this_.call(LITERAL_STRING[1437], {});
}
Variant ReflectionClass::getAttributes(const Variant &name, const Variant &flags) {
    return this_.call(LITERAL_STRING[1445], {name, flags});
}
ReflectionObject::ReflectionObject(const Variant &object) {
    this_ = newObject(LITERAL_STRING[1533], {object});
}
Variant ReflectionObject::__toString() {
    return this_.call(LITERAL_STRING[29], {});
}
Variant ReflectionObject::getName() {
    return this_.call(LITERAL_STRING[284], {});
}
Variant ReflectionObject::isInternal() {
    return this_.call(LITERAL_STRING[1420], {});
}
Variant ReflectionObject::isUserDefined() {
    return this_.call(LITERAL_STRING[1421], {});
}
Variant ReflectionObject::isAnonymous() {
    return this_.call(LITERAL_STRING[1412], {});
}
Variant ReflectionObject::isInstantiable() {
    return this_.call(LITERAL_STRING[1489], {});
}
Variant ReflectionObject::isCloneable() {
    return this_.call(LITERAL_STRING[1490], {});
}
Variant ReflectionObject::getFileName() {
    return this_.call(LITERAL_STRING[1432], {});
}
Variant ReflectionObject::getStartLine() {
    return this_.call(LITERAL_STRING[1438], {});
}
Variant ReflectionObject::getEndLine() {
    return this_.call(LITERAL_STRING[1430], {});
}
Variant ReflectionObject::getDocComment() {
    return this_.call(LITERAL_STRING[1429], {});
}
Variant ReflectionObject::getConstructor() {
    return this_.call(LITERAL_STRING[1491], {});
}
Variant ReflectionObject::hasMethod(const Variant &name) {
    return this_.call(LITERAL_STRING[1492], {name});
}
Variant ReflectionObject::getMethod(const Variant &name) {
    return this_.call(LITERAL_STRING[1493], {name});
}
Variant ReflectionObject::getMethods(const Variant &filter) {
    return this_.call(LITERAL_STRING[1494], {filter});
}
Variant ReflectionObject::hasProperty(const Variant &name) {
    return this_.call(LITERAL_STRING[1495], {name});
}
Variant ReflectionObject::getProperty(const Variant &name) {
    return this_.call(LITERAL_STRING[1496], {name});
}
Variant ReflectionObject::getProperties(const Variant &filter) {
    return this_.call(LITERAL_STRING[1497], {filter});
}
Variant ReflectionObject::hasConstant(const Variant &name) {
    return this_.call(LITERAL_STRING[1498], {name});
}
Variant ReflectionObject::getConstants(const Variant &filter) {
    return this_.call(LITERAL_STRING[1499], {filter});
}
Variant ReflectionObject::getReflectionConstants(const Variant &filter) {
    return this_.call(LITERAL_STRING[1500], {filter});
}
Variant ReflectionObject::getConstant(const Variant &name) {
    return this_.call(LITERAL_STRING[1501], {name});
}
Variant ReflectionObject::getReflectionConstant(const Variant &name) {
    return this_.call(LITERAL_STRING[1502], {name});
}
Variant ReflectionObject::getInterfaces() {
    return this_.call(LITERAL_STRING[1503], {});
}
Variant ReflectionObject::getInterfaceNames() {
    return this_.call(LITERAL_STRING[1504], {});
}
Variant ReflectionObject::isInterface() {
    return this_.call(LITERAL_STRING[1505], {});
}
Variant ReflectionObject::getTraits() {
    return this_.call(LITERAL_STRING[1506], {});
}
Variant ReflectionObject::getTraitNames() {
    return this_.call(LITERAL_STRING[1507], {});
}
Variant ReflectionObject::getTraitAliases() {
    return this_.call(LITERAL_STRING[1508], {});
}
Variant ReflectionObject::isTrait() {
    return this_.call(LITERAL_STRING[1509], {});
}
Variant ReflectionObject::isEnum() {
    return this_.call(LITERAL_STRING[1510], {});
}
Variant ReflectionObject::isAbstract() {
    return this_.call(LITERAL_STRING[1480], {});
}
Variant ReflectionObject::isFinal() {
    return this_.call(LITERAL_STRING[1481], {});
}
Variant ReflectionObject::isReadOnly() {
    return this_.call(LITERAL_STRING[1511], {});
}
Variant ReflectionObject::getModifiers() {
    return this_.call(LITERAL_STRING[1484], {});
}
Variant ReflectionObject::isInstance(const Variant &object) {
    return this_.call(LITERAL_STRING[1512], {object});
}
Variant ReflectionObject::newInstanceWithoutConstructor() {
    return this_.call(LITERAL_STRING[1514], {});
}
Variant ReflectionObject::newInstanceArgs(const Variant &args) {
    return this_.call(LITERAL_STRING[1515], {args});
}
Variant ReflectionObject::newLazyGhost(const Variant &initializer, const Variant &options) {
    return this_.call(LITERAL_STRING[1516], {initializer, options});
}
Variant ReflectionObject::newLazyProxy(const Variant &factory, const Variant &options) {
    return this_.call(LITERAL_STRING[1517], {factory, options});
}
Variant ReflectionObject::resetAsLazyGhost(const Variant &object, const Variant &initializer, const Variant &options) {
    return this_.call(LITERAL_STRING[1518], {object, initializer, options});
}
Variant ReflectionObject::resetAsLazyProxy(const Variant &object, const Variant &factory, const Variant &options) {
    return this_.call(LITERAL_STRING[1519], {object, factory, options});
}
Variant ReflectionObject::initializeLazyObject(const Variant &object) {
    return this_.call(LITERAL_STRING[1520], {object});
}
Variant ReflectionObject::isUninitializedLazyObject(const Variant &object) {
    return this_.call(LITERAL_STRING[1521], {object});
}
Variant ReflectionObject::markLazyObjectAsInitialized(const Variant &object) {
    return this_.call(LITERAL_STRING[1522], {object});
}
Variant ReflectionObject::getLazyInitializer(const Variant &object) {
    return this_.call(LITERAL_STRING[1523], {object});
}
Variant ReflectionObject::getParentClass() {
    return this_.call(LITERAL_STRING[1524], {});
}
Variant ReflectionObject::isSubclassOf(const Variant &_class) {
    return this_.call(LITERAL_STRING[1525], {_class});
}
Variant ReflectionObject::getStaticProperties() {
    return this_.call(LITERAL_STRING[1526], {});
}
Variant ReflectionObject::getStaticPropertyValue(const Variant &name, const Variant &_default) {
    return this_.call(LITERAL_STRING[1527], {name, _default});
}
Variant ReflectionObject::setStaticPropertyValue(const Variant &name, const Variant &value) {
    return this_.call(LITERAL_STRING[1528], {name, value});
}
Variant ReflectionObject::getDefaultProperties() {
    return this_.call(LITERAL_STRING[1529], {});
}
Variant ReflectionObject::isIterable() {
    return this_.call(LITERAL_STRING[1530], {});
}
Variant ReflectionObject::isIterateable() {
    return this_.call(LITERAL_STRING[1531], {});
}
Variant ReflectionObject::implementsInterface(const Variant &interface) {
    return this_.call(LITERAL_STRING[1532], {interface});
}
Variant ReflectionObject::getExtension() {
    return this_.call(LITERAL_STRING[919], {});
}
Variant ReflectionObject::getExtensionName() {
    return this_.call(LITERAL_STRING[1431], {});
}
Variant ReflectionObject::inNamespace() {
    return this_.call(LITERAL_STRING[1417], {});
}
Variant ReflectionObject::getNamespaceName() {
    return this_.call(LITERAL_STRING[1433], {});
}
Variant ReflectionObject::getShortName() {
    return this_.call(LITERAL_STRING[1437], {});
}
Variant ReflectionObject::getAttributes(const Variant &name, const Variant &flags) {
    return this_.call(LITERAL_STRING[1445], {name, flags});
}
ReflectionProperty::ReflectionProperty(const Variant &_class, const Variant &property) {
    this_ = newObject(LITERAL_STRING[1534], {_class, property});
}
Variant ReflectionProperty::__toString() {
    return this_.call(LITERAL_STRING[29], {});
}
Variant ReflectionProperty::getName() {
    return this_.call(LITERAL_STRING[284], {});
}
Variant ReflectionProperty::getValue(const Variant &object) {
    return this_.call(LITERAL_STRING[144], {object});
}
Variant ReflectionProperty::setValue(const Variant &object_or_value, const Variant &value) {
    return this_.call(LITERAL_STRING[1535], {object_or_value, value});
}
Variant ReflectionProperty::getRawValue(const Variant &object) {
    return this_.call(LITERAL_STRING[1536], {object});
}
Variant ReflectionProperty::setRawValue(const Variant &object, const Variant &value) {
    return this_.call(LITERAL_STRING[1537], {object, value});
}
Variant ReflectionProperty::setRawValueWithoutLazyInitialization(const Variant &object, const Variant &value) {
    return this_.call(LITERAL_STRING[1538], {object, value});
}
Variant ReflectionProperty::skipLazyInitialization(const Variant &object) {
    return this_.call(LITERAL_STRING[1539], {object});
}
Variant ReflectionProperty::isLazy(const Variant &object) {
    return this_.call(LITERAL_STRING[1540], {object});
}
Variant ReflectionProperty::isInitialized(const Variant &object) {
    return this_.call(LITERAL_STRING[1541], {object});
}
Variant ReflectionProperty::isPublic() {
    return this_.call(LITERAL_STRING[1477], {});
}
Variant ReflectionProperty::isPrivate() {
    return this_.call(LITERAL_STRING[1478], {});
}
Variant ReflectionProperty::isProtected() {
    return this_.call(LITERAL_STRING[1479], {});
}
Variant ReflectionProperty::isPrivateSet() {
    return this_.call(LITERAL_STRING[1542], {});
}
Variant ReflectionProperty::isProtectedSet() {
    return this_.call(LITERAL_STRING[1543], {});
}
Variant ReflectionProperty::isStatic() {
    return this_.call(LITERAL_STRING[1424], {});
}
Variant ReflectionProperty::isReadOnly() {
    return this_.call(LITERAL_STRING[1511], {});
}
Variant ReflectionProperty::isDefault() {
    return this_.call(LITERAL_STRING[1544], {});
}
Variant ReflectionProperty::isDynamic() {
    return this_.call(LITERAL_STRING[1545], {});
}
Variant ReflectionProperty::isAbstract() {
    return this_.call(LITERAL_STRING[1480], {});
}
Variant ReflectionProperty::isVirtual() {
    return this_.call(LITERAL_STRING[1546], {});
}
Variant ReflectionProperty::isPromoted() {
    return this_.call(LITERAL_STRING[1469], {});
}
Variant ReflectionProperty::getModifiers() {
    return this_.call(LITERAL_STRING[1484], {});
}
Variant ReflectionProperty::getDeclaringClass() {
    return this_.call(LITERAL_STRING[1457], {});
}
Variant ReflectionProperty::getDocComment() {
    return this_.call(LITERAL_STRING[1429], {});
}
Variant ReflectionProperty::setAccessible(const Variant &accessible) {
    return this_.call(LITERAL_STRING[1487], {accessible});
}
Variant ReflectionProperty::getType() {
    return this_.call(LITERAL_STRING[932], {});
}
Variant ReflectionProperty::getSettableType() {
    return this_.call(LITERAL_STRING[1547], {});
}
Variant ReflectionProperty::hasType() {
    return this_.call(LITERAL_STRING[1459], {});
}
Variant ReflectionProperty::hasDefaultValue() {
    return this_.call(LITERAL_STRING[1548], {});
}
Variant ReflectionProperty::getDefaultValue() {
    return this_.call(LITERAL_STRING[1466], {});
}
Variant ReflectionProperty::getAttributes(const Variant &name, const Variant &flags) {
    return this_.call(LITERAL_STRING[1445], {name, flags});
}
Variant ReflectionProperty::hasHooks() {
    return this_.call(LITERAL_STRING[1549], {});
}
Variant ReflectionProperty::getHooks() {
    return this_.call(LITERAL_STRING[1550], {});
}
Variant ReflectionProperty::hasHook(const Variant &type) {
    return this_.call(LITERAL_STRING[1551], {type});
}
Variant ReflectionProperty::getHook(const Variant &type) {
    return this_.call(LITERAL_STRING[1552], {type});
}
Variant ReflectionProperty::isFinal() {
    return this_.call(LITERAL_STRING[1481], {});
}
ReflectionClassConstant::ReflectionClassConstant(const Variant &_class, const Variant &constant) {
    this_ = newObject(LITERAL_STRING[1553], {_class, constant});
}
Variant ReflectionClassConstant::__toString() {
    return this_.call(LITERAL_STRING[29], {});
}
Variant ReflectionClassConstant::getName() {
    return this_.call(LITERAL_STRING[284], {});
}
Variant ReflectionClassConstant::getValue() {
    return this_.call(LITERAL_STRING[144], {});
}
Variant ReflectionClassConstant::isPublic() {
    return this_.call(LITERAL_STRING[1477], {});
}
Variant ReflectionClassConstant::isPrivate() {
    return this_.call(LITERAL_STRING[1478], {});
}
Variant ReflectionClassConstant::isProtected() {
    return this_.call(LITERAL_STRING[1479], {});
}
Variant ReflectionClassConstant::isFinal() {
    return this_.call(LITERAL_STRING[1481], {});
}
Variant ReflectionClassConstant::getModifiers() {
    return this_.call(LITERAL_STRING[1484], {});
}
Variant ReflectionClassConstant::getDeclaringClass() {
    return this_.call(LITERAL_STRING[1457], {});
}
Variant ReflectionClassConstant::getDocComment() {
    return this_.call(LITERAL_STRING[1429], {});
}
Variant ReflectionClassConstant::getAttributes(const Variant &name, const Variant &flags) {
    return this_.call(LITERAL_STRING[1445], {name, flags});
}
Variant ReflectionClassConstant::isEnumCase() {
    return this_.call(LITERAL_STRING[1554], {});
}
Variant ReflectionClassConstant::isDeprecated() {
    return this_.call(LITERAL_STRING[1419], {});
}
Variant ReflectionClassConstant::hasType() {
    return this_.call(LITERAL_STRING[1459], {});
}
Variant ReflectionClassConstant::getType() {
    return this_.call(LITERAL_STRING[932], {});
}
ReflectionExtension::ReflectionExtension(const Variant &name) {
    this_ = newObject(LITERAL_STRING[1555], {name});
}
Variant ReflectionExtension::__toString() {
    return this_.call(LITERAL_STRING[29], {});
}
Variant ReflectionExtension::getName() {
    return this_.call(LITERAL_STRING[284], {});
}
Variant ReflectionExtension::getVersion() {
    return this_.call(LITERAL_STRING[885], {});
}
Variant ReflectionExtension::getFunctions() {
    return this_.call(LITERAL_STRING[1556], {});
}
Variant ReflectionExtension::getConstants() {
    return this_.call(LITERAL_STRING[1499], {});
}
Variant ReflectionExtension::getINIEntries() {
    return this_.call(LITERAL_STRING[1557], {});
}
Variant ReflectionExtension::getClasses() {
    return this_.call(LITERAL_STRING[1558], {});
}
Variant ReflectionExtension::getClassNames() {
    return this_.call(LITERAL_STRING[1559], {});
}
Variant ReflectionExtension::getDependencies() {
    return this_.call(LITERAL_STRING[1560], {});
}
Variant ReflectionExtension::info() {
    return this_.call(LITERAL_STRING[1147], {});
}
Variant ReflectionExtension::isPersistent() {
    return this_.call(LITERAL_STRING[1561], {});
}
Variant ReflectionExtension::isTemporary() {
    return this_.call(LITERAL_STRING[1562], {});
}
ReflectionZendExtension::ReflectionZendExtension(const Variant &name) {
    this_ = newObject(LITERAL_STRING[1563], {name});
}
Variant ReflectionZendExtension::__toString() {
    return this_.call(LITERAL_STRING[29], {});
}
Variant ReflectionZendExtension::getName() {
    return this_.call(LITERAL_STRING[284], {});
}
Variant ReflectionZendExtension::getVersion() {
    return this_.call(LITERAL_STRING[885], {});
}
Variant ReflectionZendExtension::getAuthor() {
    return this_.call(LITERAL_STRING[1564], {});
}
Variant ReflectionZendExtension::getURL() {
    return this_.call(LITERAL_STRING[1565], {});
}
Variant ReflectionZendExtension::getCopyright() {
    return this_.call(LITERAL_STRING[1566], {});
}
Variant ReflectionReference::fromArrayElement(const Variant &array, const Variant &key) {
    return php::call(LITERAL_STRING[1567], {array, key});
}
Variant ReflectionReference::getId() {
    return this_.call(LITERAL_STRING[1568], {});
}
Variant ReflectionAttribute::getName() {
    return this_.call(LITERAL_STRING[284], {});
}
Variant ReflectionAttribute::getTarget() {
    return this_.call(LITERAL_STRING[1570], {});
}
Variant ReflectionAttribute::isRepeated() {
    return this_.call(LITERAL_STRING[1571], {});
}
Variant ReflectionAttribute::getArguments() {
    return this_.call(LITERAL_STRING[1572], {});
}
Variant ReflectionAttribute::newInstance() {
    return this_.call(LITERAL_STRING[1513], {});
}
Variant ReflectionAttribute::__toString() {
    return this_.call(LITERAL_STRING[29], {});
}
ReflectionEnum::ReflectionEnum(const Variant &object_or_class) {
    this_ = newObject(LITERAL_STRING[1574], {object_or_class});
}
Variant ReflectionEnum::hasCase(const Variant &name) {
    return this_.call(LITERAL_STRING[1575], {name});
}
Variant ReflectionEnum::getCase(const Variant &name) {
    return this_.call(LITERAL_STRING[1576], {name});
}
Variant ReflectionEnum::getCases() {
    return this_.call(LITERAL_STRING[1577], {});
}
Variant ReflectionEnum::isBacked() {
    return this_.call(LITERAL_STRING[1578], {});
}
Variant ReflectionEnum::getBackingType() {
    return this_.call(LITERAL_STRING[1579], {});
}
Variant ReflectionEnum::__toString() {
    return this_.call(LITERAL_STRING[29], {});
}
Variant ReflectionEnum::getName() {
    return this_.call(LITERAL_STRING[284], {});
}
Variant ReflectionEnum::isInternal() {
    return this_.call(LITERAL_STRING[1420], {});
}
Variant ReflectionEnum::isUserDefined() {
    return this_.call(LITERAL_STRING[1421], {});
}
Variant ReflectionEnum::isAnonymous() {
    return this_.call(LITERAL_STRING[1412], {});
}
Variant ReflectionEnum::isInstantiable() {
    return this_.call(LITERAL_STRING[1489], {});
}
Variant ReflectionEnum::isCloneable() {
    return this_.call(LITERAL_STRING[1490], {});
}
Variant ReflectionEnum::getFileName() {
    return this_.call(LITERAL_STRING[1432], {});
}
Variant ReflectionEnum::getStartLine() {
    return this_.call(LITERAL_STRING[1438], {});
}
Variant ReflectionEnum::getEndLine() {
    return this_.call(LITERAL_STRING[1430], {});
}
Variant ReflectionEnum::getDocComment() {
    return this_.call(LITERAL_STRING[1429], {});
}
Variant ReflectionEnum::getConstructor() {
    return this_.call(LITERAL_STRING[1491], {});
}
Variant ReflectionEnum::hasMethod(const Variant &name) {
    return this_.call(LITERAL_STRING[1492], {name});
}
Variant ReflectionEnum::getMethod(const Variant &name) {
    return this_.call(LITERAL_STRING[1493], {name});
}
Variant ReflectionEnum::getMethods(const Variant &filter) {
    return this_.call(LITERAL_STRING[1494], {filter});
}
Variant ReflectionEnum::hasProperty(const Variant &name) {
    return this_.call(LITERAL_STRING[1495], {name});
}
Variant ReflectionEnum::getProperty(const Variant &name) {
    return this_.call(LITERAL_STRING[1496], {name});
}
Variant ReflectionEnum::getProperties(const Variant &filter) {
    return this_.call(LITERAL_STRING[1497], {filter});
}
Variant ReflectionEnum::hasConstant(const Variant &name) {
    return this_.call(LITERAL_STRING[1498], {name});
}
Variant ReflectionEnum::getConstants(const Variant &filter) {
    return this_.call(LITERAL_STRING[1499], {filter});
}
Variant ReflectionEnum::getReflectionConstants(const Variant &filter) {
    return this_.call(LITERAL_STRING[1500], {filter});
}
Variant ReflectionEnum::getConstant(const Variant &name) {
    return this_.call(LITERAL_STRING[1501], {name});
}
Variant ReflectionEnum::getReflectionConstant(const Variant &name) {
    return this_.call(LITERAL_STRING[1502], {name});
}
Variant ReflectionEnum::getInterfaces() {
    return this_.call(LITERAL_STRING[1503], {});
}
Variant ReflectionEnum::getInterfaceNames() {
    return this_.call(LITERAL_STRING[1504], {});
}
Variant ReflectionEnum::isInterface() {
    return this_.call(LITERAL_STRING[1505], {});
}
Variant ReflectionEnum::getTraits() {
    return this_.call(LITERAL_STRING[1506], {});
}
Variant ReflectionEnum::getTraitNames() {
    return this_.call(LITERAL_STRING[1507], {});
}
Variant ReflectionEnum::getTraitAliases() {
    return this_.call(LITERAL_STRING[1508], {});
}
Variant ReflectionEnum::isTrait() {
    return this_.call(LITERAL_STRING[1509], {});
}
Variant ReflectionEnum::isEnum() {
    return this_.call(LITERAL_STRING[1510], {});
}
Variant ReflectionEnum::isAbstract() {
    return this_.call(LITERAL_STRING[1480], {});
}
Variant ReflectionEnum::isFinal() {
    return this_.call(LITERAL_STRING[1481], {});
}
Variant ReflectionEnum::isReadOnly() {
    return this_.call(LITERAL_STRING[1511], {});
}
Variant ReflectionEnum::getModifiers() {
    return this_.call(LITERAL_STRING[1484], {});
}
Variant ReflectionEnum::isInstance(const Variant &object) {
    return this_.call(LITERAL_STRING[1512], {object});
}
Variant ReflectionEnum::newInstanceWithoutConstructor() {
    return this_.call(LITERAL_STRING[1514], {});
}
Variant ReflectionEnum::newInstanceArgs(const Variant &args) {
    return this_.call(LITERAL_STRING[1515], {args});
}
Variant ReflectionEnum::newLazyGhost(const Variant &initializer, const Variant &options) {
    return this_.call(LITERAL_STRING[1516], {initializer, options});
}
Variant ReflectionEnum::newLazyProxy(const Variant &factory, const Variant &options) {
    return this_.call(LITERAL_STRING[1517], {factory, options});
}
Variant ReflectionEnum::resetAsLazyGhost(const Variant &object, const Variant &initializer, const Variant &options) {
    return this_.call(LITERAL_STRING[1518], {object, initializer, options});
}
Variant ReflectionEnum::resetAsLazyProxy(const Variant &object, const Variant &factory, const Variant &options) {
    return this_.call(LITERAL_STRING[1519], {object, factory, options});
}
Variant ReflectionEnum::initializeLazyObject(const Variant &object) {
    return this_.call(LITERAL_STRING[1520], {object});
}
Variant ReflectionEnum::isUninitializedLazyObject(const Variant &object) {
    return this_.call(LITERAL_STRING[1521], {object});
}
Variant ReflectionEnum::markLazyObjectAsInitialized(const Variant &object) {
    return this_.call(LITERAL_STRING[1522], {object});
}
Variant ReflectionEnum::getLazyInitializer(const Variant &object) {
    return this_.call(LITERAL_STRING[1523], {object});
}
Variant ReflectionEnum::getParentClass() {
    return this_.call(LITERAL_STRING[1524], {});
}
Variant ReflectionEnum::isSubclassOf(const Variant &_class) {
    return this_.call(LITERAL_STRING[1525], {_class});
}
Variant ReflectionEnum::getStaticProperties() {
    return this_.call(LITERAL_STRING[1526], {});
}
Variant ReflectionEnum::getStaticPropertyValue(const Variant &name, const Variant &_default) {
    return this_.call(LITERAL_STRING[1527], {name, _default});
}
Variant ReflectionEnum::setStaticPropertyValue(const Variant &name, const Variant &value) {
    return this_.call(LITERAL_STRING[1528], {name, value});
}
Variant ReflectionEnum::getDefaultProperties() {
    return this_.call(LITERAL_STRING[1529], {});
}
Variant ReflectionEnum::isIterable() {
    return this_.call(LITERAL_STRING[1530], {});
}
Variant ReflectionEnum::isIterateable() {
    return this_.call(LITERAL_STRING[1531], {});
}
Variant ReflectionEnum::implementsInterface(const Variant &interface) {
    return this_.call(LITERAL_STRING[1532], {interface});
}
Variant ReflectionEnum::getExtension() {
    return this_.call(LITERAL_STRING[919], {});
}
Variant ReflectionEnum::getExtensionName() {
    return this_.call(LITERAL_STRING[1431], {});
}
Variant ReflectionEnum::inNamespace() {
    return this_.call(LITERAL_STRING[1417], {});
}
Variant ReflectionEnum::getNamespaceName() {
    return this_.call(LITERAL_STRING[1433], {});
}
Variant ReflectionEnum::getShortName() {
    return this_.call(LITERAL_STRING[1437], {});
}
Variant ReflectionEnum::getAttributes(const Variant &name, const Variant &flags) {
    return this_.call(LITERAL_STRING[1445], {name, flags});
}
ReflectionEnumUnitCase::ReflectionEnumUnitCase(const Variant &_class, const Variant &constant) {
    this_ = newObject(LITERAL_STRING[1580], {_class, constant});
}
Variant ReflectionEnumUnitCase::getEnum() {
    return this_.call(LITERAL_STRING[1581], {});
}
Variant ReflectionEnumUnitCase::getValue() {
    return this_.call(LITERAL_STRING[144], {});
}
Variant ReflectionEnumUnitCase::__toString() {
    return this_.call(LITERAL_STRING[29], {});
}
Variant ReflectionEnumUnitCase::getName() {
    return this_.call(LITERAL_STRING[284], {});
}
Variant ReflectionEnumUnitCase::isPublic() {
    return this_.call(LITERAL_STRING[1477], {});
}
Variant ReflectionEnumUnitCase::isPrivate() {
    return this_.call(LITERAL_STRING[1478], {});
}
Variant ReflectionEnumUnitCase::isProtected() {
    return this_.call(LITERAL_STRING[1479], {});
}
Variant ReflectionEnumUnitCase::isFinal() {
    return this_.call(LITERAL_STRING[1481], {});
}
Variant ReflectionEnumUnitCase::getModifiers() {
    return this_.call(LITERAL_STRING[1484], {});
}
Variant ReflectionEnumUnitCase::getDeclaringClass() {
    return this_.call(LITERAL_STRING[1457], {});
}
Variant ReflectionEnumUnitCase::getDocComment() {
    return this_.call(LITERAL_STRING[1429], {});
}
Variant ReflectionEnumUnitCase::getAttributes(const Variant &name, const Variant &flags) {
    return this_.call(LITERAL_STRING[1445], {name, flags});
}
Variant ReflectionEnumUnitCase::isEnumCase() {
    return this_.call(LITERAL_STRING[1554], {});
}
Variant ReflectionEnumUnitCase::isDeprecated() {
    return this_.call(LITERAL_STRING[1419], {});
}
Variant ReflectionEnumUnitCase::hasType() {
    return this_.call(LITERAL_STRING[1459], {});
}
Variant ReflectionEnumUnitCase::getType() {
    return this_.call(LITERAL_STRING[932], {});
}
ReflectionEnumBackedCase::ReflectionEnumBackedCase(const Variant &_class, const Variant &constant) {
    this_ = newObject(LITERAL_STRING[1582], {_class, constant});
}
Variant ReflectionEnumBackedCase::getBackingValue() {
    return this_.call(LITERAL_STRING[1583], {});
}
Variant ReflectionEnumBackedCase::getEnum() {
    return this_.call(LITERAL_STRING[1581], {});
}
Variant ReflectionEnumBackedCase::getValue() {
    return this_.call(LITERAL_STRING[144], {});
}
Variant ReflectionEnumBackedCase::__toString() {
    return this_.call(LITERAL_STRING[29], {});
}
Variant ReflectionEnumBackedCase::getName() {
    return this_.call(LITERAL_STRING[284], {});
}
Variant ReflectionEnumBackedCase::isPublic() {
    return this_.call(LITERAL_STRING[1477], {});
}
Variant ReflectionEnumBackedCase::isPrivate() {
    return this_.call(LITERAL_STRING[1478], {});
}
Variant ReflectionEnumBackedCase::isProtected() {
    return this_.call(LITERAL_STRING[1479], {});
}
Variant ReflectionEnumBackedCase::isFinal() {
    return this_.call(LITERAL_STRING[1481], {});
}
Variant ReflectionEnumBackedCase::getModifiers() {
    return this_.call(LITERAL_STRING[1484], {});
}
Variant ReflectionEnumBackedCase::getDeclaringClass() {
    return this_.call(LITERAL_STRING[1457], {});
}
Variant ReflectionEnumBackedCase::getDocComment() {
    return this_.call(LITERAL_STRING[1429], {});
}
Variant ReflectionEnumBackedCase::getAttributes(const Variant &name, const Variant &flags) {
    return this_.call(LITERAL_STRING[1445], {name, flags});
}
Variant ReflectionEnumBackedCase::isEnumCase() {
    return this_.call(LITERAL_STRING[1554], {});
}
Variant ReflectionEnumBackedCase::isDeprecated() {
    return this_.call(LITERAL_STRING[1419], {});
}
Variant ReflectionEnumBackedCase::hasType() {
    return this_.call(LITERAL_STRING[1459], {});
}
Variant ReflectionEnumBackedCase::getType() {
    return this_.call(LITERAL_STRING[932], {});
}
ReflectionFiber::ReflectionFiber(const Variant &fiber) {
    this_ = newObject(LITERAL_STRING[1584], {fiber});
}
Variant ReflectionFiber::getFiber() {
    return this_.call(LITERAL_STRING[1585], {});
}
Variant ReflectionFiber::getExecutingFile() {
    return this_.call(LITERAL_STRING[1448], {});
}
Variant ReflectionFiber::getExecutingLine() {
    return this_.call(LITERAL_STRING[1447], {});
}
Variant ReflectionFiber::getCallable() {
    return this_.call(LITERAL_STRING[1586], {});
}
Variant ReflectionFiber::getTrace(const Variant &options) {
    return this_.call(LITERAL_STRING[102], {options});
}
ReflectionConstant::ReflectionConstant(const Variant &name) {
    this_ = newObject(LITERAL_STRING[1587], {name});
}
Variant ReflectionConstant::getName() {
    return this_.call(LITERAL_STRING[284], {});
}
Variant ReflectionConstant::getNamespaceName() {
    return this_.call(LITERAL_STRING[1433], {});
}
Variant ReflectionConstant::getShortName() {
    return this_.call(LITERAL_STRING[1437], {});
}
Variant ReflectionConstant::getValue() {
    return this_.call(LITERAL_STRING[144], {});
}
Variant ReflectionConstant::isDeprecated() {
    return this_.call(LITERAL_STRING[1419], {});
}
Variant ReflectionConstant::__toString() {
    return this_.call(LITERAL_STRING[29], {});
}
Variant PropertyHookType::cases() {
    return php::call(LITERAL_STRING[1588], {});
}
Variant PropertyHookType::from(const Variant &value) {
    return php::call(LITERAL_STRING[1589], {value});
}
Variant PropertyHookType::tryFrom(const Variant &value) {
    return php::call(LITERAL_STRING[1590], {value});
}
}  // namespace php

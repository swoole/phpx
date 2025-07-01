#include "phpx.h"
#include "class/reflection.h"

namespace php {
ReflectionException::ReflectionException(const Variant &message, const Variant &code, const Variant &previous) {
    _this = newObject("ReflectionException", message, code, previous);
}

Variant ReflectionException::__wakeup() {
    return std::move(_this.exec("__wakeup"));
}

Variant ReflectionException::getMessage() {
    return std::move(_this.exec("getMessage"));
}

Variant ReflectionException::getCode() {
    return std::move(_this.exec("getCode"));
}

Variant ReflectionException::getFile() {
    return std::move(_this.exec("getFile"));
}

Variant ReflectionException::getLine() {
    return std::move(_this.exec("getLine"));
}

Variant ReflectionException::getTrace() {
    return std::move(_this.exec("getTrace"));
}

Variant ReflectionException::getPrevious() {
    return std::move(_this.exec("getPrevious"));
}

Variant ReflectionException::getTraceAsString() {
    return std::move(_this.exec("getTraceAsString"));
}

Variant ReflectionException::__toString() {
    return std::move(_this.exec("__toString"));
}


Variant Reflection::getModifierNames(const Variant &modifiers) {
    static Variant fn { ZEND_STRL("Reflection::getModifierNames"), true };
    return fn(modifiers);
}


ReflectionFunction::ReflectionFunction(const Variant &function) {
    _this = newObject("ReflectionFunction", function);
}

Variant ReflectionFunction::__toString() {
    return std::move(_this.exec("__toString"));
}

Variant ReflectionFunction::isAnonymous() {
    return std::move(_this.exec("isAnonymous"));
}

Variant ReflectionFunction::isDisabled() {
    return std::move(_this.exec("isDisabled"));
}

Variant ReflectionFunction::invoke(const Variant &args) {
    return std::move(_this.exec("invoke", args));
}

Variant ReflectionFunction::invokeArgs(const Variant &args) {
    return std::move(_this.exec("invokeArgs", args));
}

Variant ReflectionFunction::getClosure() {
    return std::move(_this.exec("getClosure"));
}

Variant ReflectionFunction::inNamespace() {
    return std::move(_this.exec("inNamespace"));
}

Variant ReflectionFunction::isClosure() {
    return std::move(_this.exec("isClosure"));
}

Variant ReflectionFunction::isDeprecated() {
    return std::move(_this.exec("isDeprecated"));
}

Variant ReflectionFunction::isInternal() {
    return std::move(_this.exec("isInternal"));
}

Variant ReflectionFunction::isUserDefined() {
    return std::move(_this.exec("isUserDefined"));
}

Variant ReflectionFunction::isGenerator() {
    return std::move(_this.exec("isGenerator"));
}

Variant ReflectionFunction::isVariadic() {
    return std::move(_this.exec("isVariadic"));
}

Variant ReflectionFunction::isStatic() {
    return std::move(_this.exec("isStatic"));
}

Variant ReflectionFunction::getClosureThis() {
    return std::move(_this.exec("getClosureThis"));
}

Variant ReflectionFunction::getClosureScopeClass() {
    return std::move(_this.exec("getClosureScopeClass"));
}

Variant ReflectionFunction::getClosureCalledClass() {
    return std::move(_this.exec("getClosureCalledClass"));
}

Variant ReflectionFunction::getClosureUsedVariables() {
    return std::move(_this.exec("getClosureUsedVariables"));
}

Variant ReflectionFunction::getDocComment() {
    return std::move(_this.exec("getDocComment"));
}

Variant ReflectionFunction::getEndLine() {
    return std::move(_this.exec("getEndLine"));
}

Variant ReflectionFunction::getExtension() {
    return std::move(_this.exec("getExtension"));
}

Variant ReflectionFunction::getExtensionName() {
    return std::move(_this.exec("getExtensionName"));
}

Variant ReflectionFunction::getFileName() {
    return std::move(_this.exec("getFileName"));
}

Variant ReflectionFunction::getName() {
    return std::move(_this.exec("getName"));
}

Variant ReflectionFunction::getNamespaceName() {
    return std::move(_this.exec("getNamespaceName"));
}

Variant ReflectionFunction::getNumberOfParameters() {
    return std::move(_this.exec("getNumberOfParameters"));
}

Variant ReflectionFunction::getNumberOfRequiredParameters() {
    return std::move(_this.exec("getNumberOfRequiredParameters"));
}

Variant ReflectionFunction::getParameters() {
    return std::move(_this.exec("getParameters"));
}

Variant ReflectionFunction::getShortName() {
    return std::move(_this.exec("getShortName"));
}

Variant ReflectionFunction::getStartLine() {
    return std::move(_this.exec("getStartLine"));
}

Variant ReflectionFunction::getStaticVariables() {
    return std::move(_this.exec("getStaticVariables"));
}

Variant ReflectionFunction::returnsReference() {
    return std::move(_this.exec("returnsReference"));
}

Variant ReflectionFunction::hasReturnType() {
    return std::move(_this.exec("hasReturnType"));
}

Variant ReflectionFunction::getReturnType() {
    return std::move(_this.exec("getReturnType"));
}

Variant ReflectionFunction::hasTentativeReturnType() {
    return std::move(_this.exec("hasTentativeReturnType"));
}

Variant ReflectionFunction::getTentativeReturnType() {
    return std::move(_this.exec("getTentativeReturnType"));
}

Variant ReflectionFunction::getAttributes(const Variant &name, const Variant &flags) {
    return std::move(_this.exec("getAttributes", name, flags));
}


ReflectionGenerator::ReflectionGenerator(const Variant &generator) {
    _this = newObject("ReflectionGenerator", generator);
}

Variant ReflectionGenerator::getExecutingLine() {
    return std::move(_this.exec("getExecutingLine"));
}

Variant ReflectionGenerator::getExecutingFile() {
    return std::move(_this.exec("getExecutingFile"));
}

Variant ReflectionGenerator::getTrace(const Variant &options) {
    return std::move(_this.exec("getTrace", options));
}

Variant ReflectionGenerator::getFunction() {
    return std::move(_this.exec("getFunction"));
}

Variant ReflectionGenerator::_getThis() {
    return std::move(_this.exec("getThis"));
}

Variant ReflectionGenerator::getExecutingGenerator() {
    return std::move(_this.exec("getExecutingGenerator"));
}


ReflectionParameter::ReflectionParameter(const Variant &function, const Variant &param) {
    _this = newObject("ReflectionParameter", function, param);
}

Variant ReflectionParameter::__toString() {
    return std::move(_this.exec("__toString"));
}

Variant ReflectionParameter::getName() {
    return std::move(_this.exec("getName"));
}

Variant ReflectionParameter::isPassedByReference() {
    return std::move(_this.exec("isPassedByReference"));
}

Variant ReflectionParameter::canBePassedByValue() {
    return std::move(_this.exec("canBePassedByValue"));
}

Variant ReflectionParameter::getDeclaringFunction() {
    return std::move(_this.exec("getDeclaringFunction"));
}

Variant ReflectionParameter::getDeclaringClass() {
    return std::move(_this.exec("getDeclaringClass"));
}

Variant ReflectionParameter::getClass() {
    return std::move(_this.exec("getClass"));
}

Variant ReflectionParameter::hasType() {
    return std::move(_this.exec("hasType"));
}

Variant ReflectionParameter::getType() {
    return std::move(_this.exec("getType"));
}

Variant ReflectionParameter::isArray() {
    return std::move(_this.exec("isArray"));
}

Variant ReflectionParameter::isCallable() {
    return std::move(_this.exec("isCallable"));
}

Variant ReflectionParameter::allowsNull() {
    return std::move(_this.exec("allowsNull"));
}

Variant ReflectionParameter::getPosition() {
    return std::move(_this.exec("getPosition"));
}

Variant ReflectionParameter::isOptional() {
    return std::move(_this.exec("isOptional"));
}

Variant ReflectionParameter::isDefaultValueAvailable() {
    return std::move(_this.exec("isDefaultValueAvailable"));
}

Variant ReflectionParameter::getDefaultValue() {
    return std::move(_this.exec("getDefaultValue"));
}

Variant ReflectionParameter::isDefaultValueConstant() {
    return std::move(_this.exec("isDefaultValueConstant"));
}

Variant ReflectionParameter::getDefaultValueConstantName() {
    return std::move(_this.exec("getDefaultValueConstantName"));
}

Variant ReflectionParameter::isVariadic() {
    return std::move(_this.exec("isVariadic"));
}

Variant ReflectionParameter::isPromoted() {
    return std::move(_this.exec("isPromoted"));
}

Variant ReflectionParameter::getAttributes(const Variant &name, const Variant &flags) {
    return std::move(_this.exec("getAttributes", name, flags));
}


Variant ReflectionNamedType::getName() {
    return std::move(_this.exec("getName"));
}

Variant ReflectionNamedType::isBuiltin() {
    return std::move(_this.exec("isBuiltin"));
}

Variant ReflectionNamedType::allowsNull() {
    return std::move(_this.exec("allowsNull"));
}

Variant ReflectionNamedType::__toString() {
    return std::move(_this.exec("__toString"));
}


Variant ReflectionUnionType::getTypes() {
    return std::move(_this.exec("getTypes"));
}

Variant ReflectionUnionType::allowsNull() {
    return std::move(_this.exec("allowsNull"));
}

Variant ReflectionUnionType::__toString() {
    return std::move(_this.exec("__toString"));
}


Variant ReflectionIntersectionType::getTypes() {
    return std::move(_this.exec("getTypes"));
}

Variant ReflectionIntersectionType::allowsNull() {
    return std::move(_this.exec("allowsNull"));
}

Variant ReflectionIntersectionType::__toString() {
    return std::move(_this.exec("__toString"));
}


ReflectionMethod::ReflectionMethod(const Variant &object_or_method, const Variant &method) {
    _this = newObject("ReflectionMethod", object_or_method, method);
}

Variant ReflectionMethod::__toString() {
    return std::move(_this.exec("__toString"));
}

Variant ReflectionMethod::isPublic() {
    return std::move(_this.exec("isPublic"));
}

Variant ReflectionMethod::isPrivate() {
    return std::move(_this.exec("isPrivate"));
}

Variant ReflectionMethod::isProtected() {
    return std::move(_this.exec("isProtected"));
}

Variant ReflectionMethod::isAbstract() {
    return std::move(_this.exec("isAbstract"));
}

Variant ReflectionMethod::isFinal() {
    return std::move(_this.exec("isFinal"));
}

Variant ReflectionMethod::isConstructor() {
    return std::move(_this.exec("isConstructor"));
}

Variant ReflectionMethod::isDestructor() {
    return std::move(_this.exec("isDestructor"));
}

Variant ReflectionMethod::getClosure(const Variant &object) {
    return std::move(_this.exec("getClosure", object));
}

Variant ReflectionMethod::getModifiers() {
    return std::move(_this.exec("getModifiers"));
}

Variant ReflectionMethod::invoke(const Variant &object, const Variant &args) {
    return std::move(_this.exec("invoke", object, args));
}

Variant ReflectionMethod::invokeArgs(const Variant &object, const Variant &args) {
    return std::move(_this.exec("invokeArgs", object, args));
}

Variant ReflectionMethod::getDeclaringClass() {
    return std::move(_this.exec("getDeclaringClass"));
}

Variant ReflectionMethod::getPrototype() {
    return std::move(_this.exec("getPrototype"));
}

Variant ReflectionMethod::hasPrototype() {
    return std::move(_this.exec("hasPrototype"));
}

Variant ReflectionMethod::setAccessible(const Variant &accessible) {
    return std::move(_this.exec("setAccessible", accessible));
}

Variant ReflectionMethod::inNamespace() {
    return std::move(_this.exec("inNamespace"));
}

Variant ReflectionMethod::isClosure() {
    return std::move(_this.exec("isClosure"));
}

Variant ReflectionMethod::isDeprecated() {
    return std::move(_this.exec("isDeprecated"));
}

Variant ReflectionMethod::isInternal() {
    return std::move(_this.exec("isInternal"));
}

Variant ReflectionMethod::isUserDefined() {
    return std::move(_this.exec("isUserDefined"));
}

Variant ReflectionMethod::isGenerator() {
    return std::move(_this.exec("isGenerator"));
}

Variant ReflectionMethod::isVariadic() {
    return std::move(_this.exec("isVariadic"));
}

Variant ReflectionMethod::isStatic() {
    return std::move(_this.exec("isStatic"));
}

Variant ReflectionMethod::getClosureThis() {
    return std::move(_this.exec("getClosureThis"));
}

Variant ReflectionMethod::getClosureScopeClass() {
    return std::move(_this.exec("getClosureScopeClass"));
}

Variant ReflectionMethod::getClosureCalledClass() {
    return std::move(_this.exec("getClosureCalledClass"));
}

Variant ReflectionMethod::getClosureUsedVariables() {
    return std::move(_this.exec("getClosureUsedVariables"));
}

Variant ReflectionMethod::getDocComment() {
    return std::move(_this.exec("getDocComment"));
}

Variant ReflectionMethod::getEndLine() {
    return std::move(_this.exec("getEndLine"));
}

Variant ReflectionMethod::getExtension() {
    return std::move(_this.exec("getExtension"));
}

Variant ReflectionMethod::getExtensionName() {
    return std::move(_this.exec("getExtensionName"));
}

Variant ReflectionMethod::getFileName() {
    return std::move(_this.exec("getFileName"));
}

Variant ReflectionMethod::getName() {
    return std::move(_this.exec("getName"));
}

Variant ReflectionMethod::getNamespaceName() {
    return std::move(_this.exec("getNamespaceName"));
}

Variant ReflectionMethod::getNumberOfParameters() {
    return std::move(_this.exec("getNumberOfParameters"));
}

Variant ReflectionMethod::getNumberOfRequiredParameters() {
    return std::move(_this.exec("getNumberOfRequiredParameters"));
}

Variant ReflectionMethod::getParameters() {
    return std::move(_this.exec("getParameters"));
}

Variant ReflectionMethod::getShortName() {
    return std::move(_this.exec("getShortName"));
}

Variant ReflectionMethod::getStartLine() {
    return std::move(_this.exec("getStartLine"));
}

Variant ReflectionMethod::getStaticVariables() {
    return std::move(_this.exec("getStaticVariables"));
}

Variant ReflectionMethod::returnsReference() {
    return std::move(_this.exec("returnsReference"));
}

Variant ReflectionMethod::hasReturnType() {
    return std::move(_this.exec("hasReturnType"));
}

Variant ReflectionMethod::getReturnType() {
    return std::move(_this.exec("getReturnType"));
}

Variant ReflectionMethod::hasTentativeReturnType() {
    return std::move(_this.exec("hasTentativeReturnType"));
}

Variant ReflectionMethod::getTentativeReturnType() {
    return std::move(_this.exec("getTentativeReturnType"));
}

Variant ReflectionMethod::getAttributes(const Variant &name, const Variant &flags) {
    return std::move(_this.exec("getAttributes", name, flags));
}


ReflectionClass::ReflectionClass(const Variant &object_or_class) {
    _this = newObject("ReflectionClass", object_or_class);
}

Variant ReflectionClass::__toString() {
    return std::move(_this.exec("__toString"));
}

Variant ReflectionClass::getName() {
    return std::move(_this.exec("getName"));
}

Variant ReflectionClass::isInternal() {
    return std::move(_this.exec("isInternal"));
}

Variant ReflectionClass::isUserDefined() {
    return std::move(_this.exec("isUserDefined"));
}

Variant ReflectionClass::isAnonymous() {
    return std::move(_this.exec("isAnonymous"));
}

Variant ReflectionClass::isInstantiable() {
    return std::move(_this.exec("isInstantiable"));
}

Variant ReflectionClass::isCloneable() {
    return std::move(_this.exec("isCloneable"));
}

Variant ReflectionClass::getFileName() {
    return std::move(_this.exec("getFileName"));
}

Variant ReflectionClass::getStartLine() {
    return std::move(_this.exec("getStartLine"));
}

Variant ReflectionClass::getEndLine() {
    return std::move(_this.exec("getEndLine"));
}

Variant ReflectionClass::getDocComment() {
    return std::move(_this.exec("getDocComment"));
}

Variant ReflectionClass::getConstructor() {
    return std::move(_this.exec("getConstructor"));
}

Variant ReflectionClass::hasMethod(const Variant &name) {
    return std::move(_this.exec("hasMethod", name));
}

Variant ReflectionClass::getMethod(const Variant &name) {
    return std::move(_this.exec("getMethod", name));
}

Variant ReflectionClass::getMethods(const Variant &filter) {
    return std::move(_this.exec("getMethods", filter));
}

Variant ReflectionClass::hasProperty(const Variant &name) {
    return std::move(_this.exec("hasProperty", name));
}

Variant ReflectionClass::getProperty(const Variant &name) {
    return std::move(_this.exec("getProperty", name));
}

Variant ReflectionClass::getProperties(const Variant &filter) {
    return std::move(_this.exec("getProperties", filter));
}

Variant ReflectionClass::hasConstant(const Variant &name) {
    return std::move(_this.exec("hasConstant", name));
}

Variant ReflectionClass::getConstants(const Variant &filter) {
    return std::move(_this.exec("getConstants", filter));
}

Variant ReflectionClass::getReflectionConstants(const Variant &filter) {
    return std::move(_this.exec("getReflectionConstants", filter));
}

Variant ReflectionClass::getConstant(const Variant &name) {
    return std::move(_this.exec("getConstant", name));
}

Variant ReflectionClass::getReflectionConstant(const Variant &name) {
    return std::move(_this.exec("getReflectionConstant", name));
}

Variant ReflectionClass::getInterfaces() {
    return std::move(_this.exec("getInterfaces"));
}

Variant ReflectionClass::getInterfaceNames() {
    return std::move(_this.exec("getInterfaceNames"));
}

Variant ReflectionClass::isInterface() {
    return std::move(_this.exec("isInterface"));
}

Variant ReflectionClass::getTraits() {
    return std::move(_this.exec("getTraits"));
}

Variant ReflectionClass::getTraitNames() {
    return std::move(_this.exec("getTraitNames"));
}

Variant ReflectionClass::getTraitAliases() {
    return std::move(_this.exec("getTraitAliases"));
}

Variant ReflectionClass::isTrait() {
    return std::move(_this.exec("isTrait"));
}

Variant ReflectionClass::isEnum() {
    return std::move(_this.exec("isEnum"));
}

Variant ReflectionClass::isAbstract() {
    return std::move(_this.exec("isAbstract"));
}

Variant ReflectionClass::isFinal() {
    return std::move(_this.exec("isFinal"));
}

Variant ReflectionClass::isReadOnly() {
    return std::move(_this.exec("isReadOnly"));
}

Variant ReflectionClass::getModifiers() {
    return std::move(_this.exec("getModifiers"));
}

Variant ReflectionClass::isInstance(const Variant &object) {
    return std::move(_this.exec("isInstance", object));
}

Variant ReflectionClass::newInstance(const Variant &args) {
    return std::move(_this.exec("newInstance", args));
}

Variant ReflectionClass::newInstanceWithoutConstructor() {
    return std::move(_this.exec("newInstanceWithoutConstructor"));
}

Variant ReflectionClass::newInstanceArgs(const Array &args) {
    return std::move(_this.exec("newInstanceArgs", args));
}

Variant ReflectionClass::getParentClass() {
    return std::move(_this.exec("getParentClass"));
}

Variant ReflectionClass::isSubclassOf(const Variant &_class) {
    return std::move(_this.exec("isSubclassOf", _class));
}

Variant ReflectionClass::getStaticProperties() {
    return std::move(_this.exec("getStaticProperties"));
}

Variant ReflectionClass::getStaticPropertyValue(const Variant &name, const Variant &_default) {
    return std::move(_this.exec("getStaticPropertyValue", name, _default));
}

Variant ReflectionClass::setStaticPropertyValue(const Variant &name, const Variant &value) {
    return std::move(_this.exec("setStaticPropertyValue", name, value));
}

Variant ReflectionClass::getDefaultProperties() {
    return std::move(_this.exec("getDefaultProperties"));
}

Variant ReflectionClass::isIterable() {
    return std::move(_this.exec("isIterable"));
}

Variant ReflectionClass::isIterateable() {
    return std::move(_this.exec("isIterateable"));
}

Variant ReflectionClass::implementsInterface(const Variant &interface) {
    return std::move(_this.exec("implementsInterface", interface));
}

Variant ReflectionClass::getExtension() {
    return std::move(_this.exec("getExtension"));
}

Variant ReflectionClass::getExtensionName() {
    return std::move(_this.exec("getExtensionName"));
}

Variant ReflectionClass::inNamespace() {
    return std::move(_this.exec("inNamespace"));
}

Variant ReflectionClass::getNamespaceName() {
    return std::move(_this.exec("getNamespaceName"));
}

Variant ReflectionClass::getShortName() {
    return std::move(_this.exec("getShortName"));
}

Variant ReflectionClass::getAttributes(const Variant &name, const Variant &flags) {
    return std::move(_this.exec("getAttributes", name, flags));
}


ReflectionObject::ReflectionObject(const Variant &object) {
    _this = newObject("ReflectionObject", object);
}

Variant ReflectionObject::__toString() {
    return std::move(_this.exec("__toString"));
}

Variant ReflectionObject::getName() {
    return std::move(_this.exec("getName"));
}

Variant ReflectionObject::isInternal() {
    return std::move(_this.exec("isInternal"));
}

Variant ReflectionObject::isUserDefined() {
    return std::move(_this.exec("isUserDefined"));
}

Variant ReflectionObject::isAnonymous() {
    return std::move(_this.exec("isAnonymous"));
}

Variant ReflectionObject::isInstantiable() {
    return std::move(_this.exec("isInstantiable"));
}

Variant ReflectionObject::isCloneable() {
    return std::move(_this.exec("isCloneable"));
}

Variant ReflectionObject::getFileName() {
    return std::move(_this.exec("getFileName"));
}

Variant ReflectionObject::getStartLine() {
    return std::move(_this.exec("getStartLine"));
}

Variant ReflectionObject::getEndLine() {
    return std::move(_this.exec("getEndLine"));
}

Variant ReflectionObject::getDocComment() {
    return std::move(_this.exec("getDocComment"));
}

Variant ReflectionObject::getConstructor() {
    return std::move(_this.exec("getConstructor"));
}

Variant ReflectionObject::hasMethod(const Variant &name) {
    return std::move(_this.exec("hasMethod", name));
}

Variant ReflectionObject::getMethod(const Variant &name) {
    return std::move(_this.exec("getMethod", name));
}

Variant ReflectionObject::getMethods(const Variant &filter) {
    return std::move(_this.exec("getMethods", filter));
}

Variant ReflectionObject::hasProperty(const Variant &name) {
    return std::move(_this.exec("hasProperty", name));
}

Variant ReflectionObject::getProperty(const Variant &name) {
    return std::move(_this.exec("getProperty", name));
}

Variant ReflectionObject::getProperties(const Variant &filter) {
    return std::move(_this.exec("getProperties", filter));
}

Variant ReflectionObject::hasConstant(const Variant &name) {
    return std::move(_this.exec("hasConstant", name));
}

Variant ReflectionObject::getConstants(const Variant &filter) {
    return std::move(_this.exec("getConstants", filter));
}

Variant ReflectionObject::getReflectionConstants(const Variant &filter) {
    return std::move(_this.exec("getReflectionConstants", filter));
}

Variant ReflectionObject::getConstant(const Variant &name) {
    return std::move(_this.exec("getConstant", name));
}

Variant ReflectionObject::getReflectionConstant(const Variant &name) {
    return std::move(_this.exec("getReflectionConstant", name));
}

Variant ReflectionObject::getInterfaces() {
    return std::move(_this.exec("getInterfaces"));
}

Variant ReflectionObject::getInterfaceNames() {
    return std::move(_this.exec("getInterfaceNames"));
}

Variant ReflectionObject::isInterface() {
    return std::move(_this.exec("isInterface"));
}

Variant ReflectionObject::getTraits() {
    return std::move(_this.exec("getTraits"));
}

Variant ReflectionObject::getTraitNames() {
    return std::move(_this.exec("getTraitNames"));
}

Variant ReflectionObject::getTraitAliases() {
    return std::move(_this.exec("getTraitAliases"));
}

Variant ReflectionObject::isTrait() {
    return std::move(_this.exec("isTrait"));
}

Variant ReflectionObject::isEnum() {
    return std::move(_this.exec("isEnum"));
}

Variant ReflectionObject::isAbstract() {
    return std::move(_this.exec("isAbstract"));
}

Variant ReflectionObject::isFinal() {
    return std::move(_this.exec("isFinal"));
}

Variant ReflectionObject::isReadOnly() {
    return std::move(_this.exec("isReadOnly"));
}

Variant ReflectionObject::getModifiers() {
    return std::move(_this.exec("getModifiers"));
}

Variant ReflectionObject::isInstance(const Variant &object) {
    return std::move(_this.exec("isInstance", object));
}

Variant ReflectionObject::newInstance(const Variant &args) {
    return std::move(_this.exec("newInstance", args));
}

Variant ReflectionObject::newInstanceWithoutConstructor() {
    return std::move(_this.exec("newInstanceWithoutConstructor"));
}

Variant ReflectionObject::newInstanceArgs(const Array &args) {
    return std::move(_this.exec("newInstanceArgs", args));
}

Variant ReflectionObject::getParentClass() {
    return std::move(_this.exec("getParentClass"));
}

Variant ReflectionObject::isSubclassOf(const Variant &_class) {
    return std::move(_this.exec("isSubclassOf", _class));
}

Variant ReflectionObject::getStaticProperties() {
    return std::move(_this.exec("getStaticProperties"));
}

Variant ReflectionObject::getStaticPropertyValue(const Variant &name, const Variant &_default) {
    return std::move(_this.exec("getStaticPropertyValue", name, _default));
}

Variant ReflectionObject::setStaticPropertyValue(const Variant &name, const Variant &value) {
    return std::move(_this.exec("setStaticPropertyValue", name, value));
}

Variant ReflectionObject::getDefaultProperties() {
    return std::move(_this.exec("getDefaultProperties"));
}

Variant ReflectionObject::isIterable() {
    return std::move(_this.exec("isIterable"));
}

Variant ReflectionObject::isIterateable() {
    return std::move(_this.exec("isIterateable"));
}

Variant ReflectionObject::implementsInterface(const Variant &interface) {
    return std::move(_this.exec("implementsInterface", interface));
}

Variant ReflectionObject::getExtension() {
    return std::move(_this.exec("getExtension"));
}

Variant ReflectionObject::getExtensionName() {
    return std::move(_this.exec("getExtensionName"));
}

Variant ReflectionObject::inNamespace() {
    return std::move(_this.exec("inNamespace"));
}

Variant ReflectionObject::getNamespaceName() {
    return std::move(_this.exec("getNamespaceName"));
}

Variant ReflectionObject::getShortName() {
    return std::move(_this.exec("getShortName"));
}

Variant ReflectionObject::getAttributes(const Variant &name, const Variant &flags) {
    return std::move(_this.exec("getAttributes", name, flags));
}


ReflectionProperty::ReflectionProperty(const Variant &_class, const Variant &property) {
    _this = newObject("ReflectionProperty", _class, property);
}

Variant ReflectionProperty::__toString() {
    return std::move(_this.exec("__toString"));
}

Variant ReflectionProperty::getName() {
    return std::move(_this.exec("getName"));
}

Variant ReflectionProperty::getValue(const Variant &object) {
    return std::move(_this.exec("getValue", object));
}

Variant ReflectionProperty::setValue(const Variant &object_or_value, const Variant &value) {
    return std::move(_this.exec("setValue", object_or_value, value));
}

Variant ReflectionProperty::isInitialized(const Variant &object) {
    return std::move(_this.exec("isInitialized", object));
}

Variant ReflectionProperty::isPublic() {
    return std::move(_this.exec("isPublic"));
}

Variant ReflectionProperty::isPrivate() {
    return std::move(_this.exec("isPrivate"));
}

Variant ReflectionProperty::isProtected() {
    return std::move(_this.exec("isProtected"));
}

Variant ReflectionProperty::isStatic() {
    return std::move(_this.exec("isStatic"));
}

Variant ReflectionProperty::isReadOnly() {
    return std::move(_this.exec("isReadOnly"));
}

Variant ReflectionProperty::isDefault() {
    return std::move(_this.exec("isDefault"));
}

Variant ReflectionProperty::isPromoted() {
    return std::move(_this.exec("isPromoted"));
}

Variant ReflectionProperty::getModifiers() {
    return std::move(_this.exec("getModifiers"));
}

Variant ReflectionProperty::getDeclaringClass() {
    return std::move(_this.exec("getDeclaringClass"));
}

Variant ReflectionProperty::getDocComment() {
    return std::move(_this.exec("getDocComment"));
}

Variant ReflectionProperty::setAccessible(const Variant &accessible) {
    return std::move(_this.exec("setAccessible", accessible));
}

Variant ReflectionProperty::getType() {
    return std::move(_this.exec("getType"));
}

Variant ReflectionProperty::hasType() {
    return std::move(_this.exec("hasType"));
}

Variant ReflectionProperty::hasDefaultValue() {
    return std::move(_this.exec("hasDefaultValue"));
}

Variant ReflectionProperty::getDefaultValue() {
    return std::move(_this.exec("getDefaultValue"));
}

Variant ReflectionProperty::getAttributes(const Variant &name, const Variant &flags) {
    return std::move(_this.exec("getAttributes", name, flags));
}


ReflectionClassConstant::ReflectionClassConstant(const Variant &_class, const Variant &constant) {
    _this = newObject("ReflectionClassConstant", _class, constant);
}

Variant ReflectionClassConstant::__toString() {
    return std::move(_this.exec("__toString"));
}

Variant ReflectionClassConstant::getName() {
    return std::move(_this.exec("getName"));
}

Variant ReflectionClassConstant::getValue() {
    return std::move(_this.exec("getValue"));
}

Variant ReflectionClassConstant::isPublic() {
    return std::move(_this.exec("isPublic"));
}

Variant ReflectionClassConstant::isPrivate() {
    return std::move(_this.exec("isPrivate"));
}

Variant ReflectionClassConstant::isProtected() {
    return std::move(_this.exec("isProtected"));
}

Variant ReflectionClassConstant::isFinal() {
    return std::move(_this.exec("isFinal"));
}

Variant ReflectionClassConstant::getModifiers() {
    return std::move(_this.exec("getModifiers"));
}

Variant ReflectionClassConstant::getDeclaringClass() {
    return std::move(_this.exec("getDeclaringClass"));
}

Variant ReflectionClassConstant::getDocComment() {
    return std::move(_this.exec("getDocComment"));
}

Variant ReflectionClassConstant::getAttributes(const Variant &name, const Variant &flags) {
    return std::move(_this.exec("getAttributes", name, flags));
}

Variant ReflectionClassConstant::isEnumCase() {
    return std::move(_this.exec("isEnumCase"));
}


ReflectionExtension::ReflectionExtension(const Variant &name) {
    _this = newObject("ReflectionExtension", name);
}

Variant ReflectionExtension::__toString() {
    return std::move(_this.exec("__toString"));
}

Variant ReflectionExtension::getName() {
    return std::move(_this.exec("getName"));
}

Variant ReflectionExtension::getVersion() {
    return std::move(_this.exec("getVersion"));
}

Variant ReflectionExtension::getFunctions() {
    return std::move(_this.exec("getFunctions"));
}

Variant ReflectionExtension::getConstants() {
    return std::move(_this.exec("getConstants"));
}

Variant ReflectionExtension::getINIEntries() {
    return std::move(_this.exec("getINIEntries"));
}

Variant ReflectionExtension::getClasses() {
    return std::move(_this.exec("getClasses"));
}

Variant ReflectionExtension::getClassNames() {
    return std::move(_this.exec("getClassNames"));
}

Variant ReflectionExtension::getDependencies() {
    return std::move(_this.exec("getDependencies"));
}

Variant ReflectionExtension::info() {
    return std::move(_this.exec("info"));
}

Variant ReflectionExtension::isPersistent() {
    return std::move(_this.exec("isPersistent"));
}

Variant ReflectionExtension::isTemporary() {
    return std::move(_this.exec("isTemporary"));
}


ReflectionZendExtension::ReflectionZendExtension(const Variant &name) {
    _this = newObject("ReflectionZendExtension", name);
}

Variant ReflectionZendExtension::__toString() {
    return std::move(_this.exec("__toString"));
}

Variant ReflectionZendExtension::getName() {
    return std::move(_this.exec("getName"));
}

Variant ReflectionZendExtension::getVersion() {
    return std::move(_this.exec("getVersion"));
}

Variant ReflectionZendExtension::getAuthor() {
    return std::move(_this.exec("getAuthor"));
}

Variant ReflectionZendExtension::getURL() {
    return std::move(_this.exec("getURL"));
}

Variant ReflectionZendExtension::getCopyright() {
    return std::move(_this.exec("getCopyright"));
}


Variant ReflectionReference::fromArrayElement(const Variant &array, const Variant &key) {
    static Variant fn { ZEND_STRL("ReflectionReference::fromArrayElement"), true };
    return fn(array, key);
}

Variant ReflectionReference::getId() {
    return std::move(_this.exec("getId"));
}


Variant ReflectionAttribute::getName() {
    return std::move(_this.exec("getName"));
}

Variant ReflectionAttribute::getTarget() {
    return std::move(_this.exec("getTarget"));
}

Variant ReflectionAttribute::isRepeated() {
    return std::move(_this.exec("isRepeated"));
}

Variant ReflectionAttribute::getArguments() {
    return std::move(_this.exec("getArguments"));
}

Variant ReflectionAttribute::newInstance() {
    return std::move(_this.exec("newInstance"));
}

Variant ReflectionAttribute::__toString() {
    return std::move(_this.exec("__toString"));
}


ReflectionEnum::ReflectionEnum(const Variant &object_or_class) {
    _this = newObject("ReflectionEnum", object_or_class);
}

Variant ReflectionEnum::hasCase(const Variant &name) {
    return std::move(_this.exec("hasCase", name));
}

Variant ReflectionEnum::getCase(const Variant &name) {
    return std::move(_this.exec("getCase", name));
}

Variant ReflectionEnum::getCases() {
    return std::move(_this.exec("getCases"));
}

Variant ReflectionEnum::isBacked() {
    return std::move(_this.exec("isBacked"));
}

Variant ReflectionEnum::getBackingType() {
    return std::move(_this.exec("getBackingType"));
}

Variant ReflectionEnum::__toString() {
    return std::move(_this.exec("__toString"));
}

Variant ReflectionEnum::getName() {
    return std::move(_this.exec("getName"));
}

Variant ReflectionEnum::isInternal() {
    return std::move(_this.exec("isInternal"));
}

Variant ReflectionEnum::isUserDefined() {
    return std::move(_this.exec("isUserDefined"));
}

Variant ReflectionEnum::isAnonymous() {
    return std::move(_this.exec("isAnonymous"));
}

Variant ReflectionEnum::isInstantiable() {
    return std::move(_this.exec("isInstantiable"));
}

Variant ReflectionEnum::isCloneable() {
    return std::move(_this.exec("isCloneable"));
}

Variant ReflectionEnum::getFileName() {
    return std::move(_this.exec("getFileName"));
}

Variant ReflectionEnum::getStartLine() {
    return std::move(_this.exec("getStartLine"));
}

Variant ReflectionEnum::getEndLine() {
    return std::move(_this.exec("getEndLine"));
}

Variant ReflectionEnum::getDocComment() {
    return std::move(_this.exec("getDocComment"));
}

Variant ReflectionEnum::getConstructor() {
    return std::move(_this.exec("getConstructor"));
}

Variant ReflectionEnum::hasMethod(const Variant &name) {
    return std::move(_this.exec("hasMethod", name));
}

Variant ReflectionEnum::getMethod(const Variant &name) {
    return std::move(_this.exec("getMethod", name));
}

Variant ReflectionEnum::getMethods(const Variant &filter) {
    return std::move(_this.exec("getMethods", filter));
}

Variant ReflectionEnum::hasProperty(const Variant &name) {
    return std::move(_this.exec("hasProperty", name));
}

Variant ReflectionEnum::getProperty(const Variant &name) {
    return std::move(_this.exec("getProperty", name));
}

Variant ReflectionEnum::getProperties(const Variant &filter) {
    return std::move(_this.exec("getProperties", filter));
}

Variant ReflectionEnum::hasConstant(const Variant &name) {
    return std::move(_this.exec("hasConstant", name));
}

Variant ReflectionEnum::getConstants(const Variant &filter) {
    return std::move(_this.exec("getConstants", filter));
}

Variant ReflectionEnum::getReflectionConstants(const Variant &filter) {
    return std::move(_this.exec("getReflectionConstants", filter));
}

Variant ReflectionEnum::getConstant(const Variant &name) {
    return std::move(_this.exec("getConstant", name));
}

Variant ReflectionEnum::getReflectionConstant(const Variant &name) {
    return std::move(_this.exec("getReflectionConstant", name));
}

Variant ReflectionEnum::getInterfaces() {
    return std::move(_this.exec("getInterfaces"));
}

Variant ReflectionEnum::getInterfaceNames() {
    return std::move(_this.exec("getInterfaceNames"));
}

Variant ReflectionEnum::isInterface() {
    return std::move(_this.exec("isInterface"));
}

Variant ReflectionEnum::getTraits() {
    return std::move(_this.exec("getTraits"));
}

Variant ReflectionEnum::getTraitNames() {
    return std::move(_this.exec("getTraitNames"));
}

Variant ReflectionEnum::getTraitAliases() {
    return std::move(_this.exec("getTraitAliases"));
}

Variant ReflectionEnum::isTrait() {
    return std::move(_this.exec("isTrait"));
}

Variant ReflectionEnum::isEnum() {
    return std::move(_this.exec("isEnum"));
}

Variant ReflectionEnum::isAbstract() {
    return std::move(_this.exec("isAbstract"));
}

Variant ReflectionEnum::isFinal() {
    return std::move(_this.exec("isFinal"));
}

Variant ReflectionEnum::isReadOnly() {
    return std::move(_this.exec("isReadOnly"));
}

Variant ReflectionEnum::getModifiers() {
    return std::move(_this.exec("getModifiers"));
}

Variant ReflectionEnum::isInstance(const Variant &object) {
    return std::move(_this.exec("isInstance", object));
}

Variant ReflectionEnum::newInstance(const Variant &args) {
    return std::move(_this.exec("newInstance", args));
}

Variant ReflectionEnum::newInstanceWithoutConstructor() {
    return std::move(_this.exec("newInstanceWithoutConstructor"));
}

Variant ReflectionEnum::newInstanceArgs(const Array &args) {
    return std::move(_this.exec("newInstanceArgs", args));
}

Variant ReflectionEnum::getParentClass() {
    return std::move(_this.exec("getParentClass"));
}

Variant ReflectionEnum::isSubclassOf(const Variant &_class) {
    return std::move(_this.exec("isSubclassOf", _class));
}

Variant ReflectionEnum::getStaticProperties() {
    return std::move(_this.exec("getStaticProperties"));
}

Variant ReflectionEnum::getStaticPropertyValue(const Variant &name, const Variant &_default) {
    return std::move(_this.exec("getStaticPropertyValue", name, _default));
}

Variant ReflectionEnum::setStaticPropertyValue(const Variant &name, const Variant &value) {
    return std::move(_this.exec("setStaticPropertyValue", name, value));
}

Variant ReflectionEnum::getDefaultProperties() {
    return std::move(_this.exec("getDefaultProperties"));
}

Variant ReflectionEnum::isIterable() {
    return std::move(_this.exec("isIterable"));
}

Variant ReflectionEnum::isIterateable() {
    return std::move(_this.exec("isIterateable"));
}

Variant ReflectionEnum::implementsInterface(const Variant &interface) {
    return std::move(_this.exec("implementsInterface", interface));
}

Variant ReflectionEnum::getExtension() {
    return std::move(_this.exec("getExtension"));
}

Variant ReflectionEnum::getExtensionName() {
    return std::move(_this.exec("getExtensionName"));
}

Variant ReflectionEnum::inNamespace() {
    return std::move(_this.exec("inNamespace"));
}

Variant ReflectionEnum::getNamespaceName() {
    return std::move(_this.exec("getNamespaceName"));
}

Variant ReflectionEnum::getShortName() {
    return std::move(_this.exec("getShortName"));
}

Variant ReflectionEnum::getAttributes(const Variant &name, const Variant &flags) {
    return std::move(_this.exec("getAttributes", name, flags));
}


ReflectionEnumUnitCase::ReflectionEnumUnitCase(const Variant &_class, const Variant &constant) {
    _this = newObject("ReflectionEnumUnitCase", _class, constant);
}

Variant ReflectionEnumUnitCase::getEnum() {
    return std::move(_this.exec("getEnum"));
}

Variant ReflectionEnumUnitCase::getValue() {
    return std::move(_this.exec("getValue"));
}

Variant ReflectionEnumUnitCase::__toString() {
    return std::move(_this.exec("__toString"));
}

Variant ReflectionEnumUnitCase::getName() {
    return std::move(_this.exec("getName"));
}

Variant ReflectionEnumUnitCase::isPublic() {
    return std::move(_this.exec("isPublic"));
}

Variant ReflectionEnumUnitCase::isPrivate() {
    return std::move(_this.exec("isPrivate"));
}

Variant ReflectionEnumUnitCase::isProtected() {
    return std::move(_this.exec("isProtected"));
}

Variant ReflectionEnumUnitCase::isFinal() {
    return std::move(_this.exec("isFinal"));
}

Variant ReflectionEnumUnitCase::getModifiers() {
    return std::move(_this.exec("getModifiers"));
}

Variant ReflectionEnumUnitCase::getDeclaringClass() {
    return std::move(_this.exec("getDeclaringClass"));
}

Variant ReflectionEnumUnitCase::getDocComment() {
    return std::move(_this.exec("getDocComment"));
}

Variant ReflectionEnumUnitCase::getAttributes(const Variant &name, const Variant &flags) {
    return std::move(_this.exec("getAttributes", name, flags));
}

Variant ReflectionEnumUnitCase::isEnumCase() {
    return std::move(_this.exec("isEnumCase"));
}


ReflectionEnumBackedCase::ReflectionEnumBackedCase(const Variant &_class, const Variant &constant) {
    _this = newObject("ReflectionEnumBackedCase", _class, constant);
}

Variant ReflectionEnumBackedCase::getBackingValue() {
    return std::move(_this.exec("getBackingValue"));
}

Variant ReflectionEnumBackedCase::getEnum() {
    return std::move(_this.exec("getEnum"));
}

Variant ReflectionEnumBackedCase::getValue() {
    return std::move(_this.exec("getValue"));
}

Variant ReflectionEnumBackedCase::__toString() {
    return std::move(_this.exec("__toString"));
}

Variant ReflectionEnumBackedCase::getName() {
    return std::move(_this.exec("getName"));
}

Variant ReflectionEnumBackedCase::isPublic() {
    return std::move(_this.exec("isPublic"));
}

Variant ReflectionEnumBackedCase::isPrivate() {
    return std::move(_this.exec("isPrivate"));
}

Variant ReflectionEnumBackedCase::isProtected() {
    return std::move(_this.exec("isProtected"));
}

Variant ReflectionEnumBackedCase::isFinal() {
    return std::move(_this.exec("isFinal"));
}

Variant ReflectionEnumBackedCase::getModifiers() {
    return std::move(_this.exec("getModifiers"));
}

Variant ReflectionEnumBackedCase::getDeclaringClass() {
    return std::move(_this.exec("getDeclaringClass"));
}

Variant ReflectionEnumBackedCase::getDocComment() {
    return std::move(_this.exec("getDocComment"));
}

Variant ReflectionEnumBackedCase::getAttributes(const Variant &name, const Variant &flags) {
    return std::move(_this.exec("getAttributes", name, flags));
}

Variant ReflectionEnumBackedCase::isEnumCase() {
    return std::move(_this.exec("isEnumCase"));
}


ReflectionFiber::ReflectionFiber(const Variant &fiber) {
    _this = newObject("ReflectionFiber", fiber);
}

Variant ReflectionFiber::getFiber() {
    return std::move(_this.exec("getFiber"));
}

Variant ReflectionFiber::getExecutingFile() {
    return std::move(_this.exec("getExecutingFile"));
}

Variant ReflectionFiber::getExecutingLine() {
    return std::move(_this.exec("getExecutingLine"));
}

Variant ReflectionFiber::getCallable() {
    return std::move(_this.exec("getCallable"));
}

Variant ReflectionFiber::getTrace(const Variant &options) {
    return std::move(_this.exec("getTrace", options));
}


}

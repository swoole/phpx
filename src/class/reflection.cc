#include "phpx.h"
#include "class/reflection.h"

namespace php {
ReflectionException::ReflectionException(const Variant &message, const Variant &code, const Variant &previous) {
    this_ = newObject("ReflectionException", message, code, previous);
}

Variant ReflectionException::__wakeup() {
    return this_.exec("__wakeup");
}

Variant ReflectionException::getMessage() {
    return this_.exec("getMessage");
}

Variant ReflectionException::getCode() {
    return this_.exec("getCode");
}

Variant ReflectionException::getFile() {
    return this_.exec("getFile");
}

Variant ReflectionException::getLine() {
    return this_.exec("getLine");
}

Variant ReflectionException::getTrace() {
    return this_.exec("getTrace");
}

Variant ReflectionException::getPrevious() {
    return this_.exec("getPrevious");
}

Variant ReflectionException::getTraceAsString() {
    return this_.exec("getTraceAsString");
}

Variant ReflectionException::__toString() {
    return this_.exec("__toString");
}


Variant Reflection::getModifierNames(const Variant &modifiers) {
    static Variant fn { ZEND_STRL("Reflection::getModifierNames"), true };
    return fn(modifiers);
}


ReflectionFunction::ReflectionFunction(const Variant &function) {
    this_ = newObject("ReflectionFunction", function);
}

Variant ReflectionFunction::__toString() {
    return this_.exec("__toString");
}

Variant ReflectionFunction::isAnonymous() {
    return this_.exec("isAnonymous");
}

Variant ReflectionFunction::isDisabled() {
    return this_.exec("isDisabled");
}

Variant ReflectionFunction::invoke(const Variant &args) {
    return this_.exec("invoke", args);
}

Variant ReflectionFunction::invokeArgs(const Variant &args) {
    return this_.exec("invokeArgs", args);
}

Variant ReflectionFunction::getClosure() {
    return this_.exec("getClosure");
}

Variant ReflectionFunction::inNamespace() {
    return this_.exec("inNamespace");
}

Variant ReflectionFunction::isClosure() {
    return this_.exec("isClosure");
}

Variant ReflectionFunction::isDeprecated() {
    return this_.exec("isDeprecated");
}

Variant ReflectionFunction::isInternal() {
    return this_.exec("isInternal");
}

Variant ReflectionFunction::isUserDefined() {
    return this_.exec("isUserDefined");
}

Variant ReflectionFunction::isGenerator() {
    return this_.exec("isGenerator");
}

Variant ReflectionFunction::isVariadic() {
    return this_.exec("isVariadic");
}

Variant ReflectionFunction::isStatic() {
    return this_.exec("isStatic");
}

Variant ReflectionFunction::getClosureThis() {
    return this_.exec("getClosureThis");
}

Variant ReflectionFunction::getClosureScopeClass() {
    return this_.exec("getClosureScopeClass");
}

Variant ReflectionFunction::getClosureCalledClass() {
    return this_.exec("getClosureCalledClass");
}

Variant ReflectionFunction::getClosureUsedVariables() {
    return this_.exec("getClosureUsedVariables");
}

Variant ReflectionFunction::getDocComment() {
    return this_.exec("getDocComment");
}

Variant ReflectionFunction::getEndLine() {
    return this_.exec("getEndLine");
}

Variant ReflectionFunction::getExtension() {
    return this_.exec("getExtension");
}

Variant ReflectionFunction::getExtensionName() {
    return this_.exec("getExtensionName");
}

Variant ReflectionFunction::getFileName() {
    return this_.exec("getFileName");
}

Variant ReflectionFunction::getName() {
    return this_.exec("getName");
}

Variant ReflectionFunction::getNamespaceName() {
    return this_.exec("getNamespaceName");
}

Variant ReflectionFunction::getNumberOfParameters() {
    return this_.exec("getNumberOfParameters");
}

Variant ReflectionFunction::getNumberOfRequiredParameters() {
    return this_.exec("getNumberOfRequiredParameters");
}

Variant ReflectionFunction::getParameters() {
    return this_.exec("getParameters");
}

Variant ReflectionFunction::getShortName() {
    return this_.exec("getShortName");
}

Variant ReflectionFunction::getStartLine() {
    return this_.exec("getStartLine");
}

Variant ReflectionFunction::getStaticVariables() {
    return this_.exec("getStaticVariables");
}

Variant ReflectionFunction::returnsReference() {
    return this_.exec("returnsReference");
}

Variant ReflectionFunction::hasReturnType() {
    return this_.exec("hasReturnType");
}

Variant ReflectionFunction::getReturnType() {
    return this_.exec("getReturnType");
}

Variant ReflectionFunction::hasTentativeReturnType() {
    return this_.exec("hasTentativeReturnType");
}

Variant ReflectionFunction::getTentativeReturnType() {
    return this_.exec("getTentativeReturnType");
}

Variant ReflectionFunction::getAttributes(const Variant &name, const Variant &flags) {
    return this_.exec("getAttributes", name, flags);
}


ReflectionGenerator::ReflectionGenerator(const Variant &generator) {
    this_ = newObject("ReflectionGenerator", generator);
}

Variant ReflectionGenerator::getExecutingLine() {
    return this_.exec("getExecutingLine");
}

Variant ReflectionGenerator::getExecutingFile() {
    return this_.exec("getExecutingFile");
}

Variant ReflectionGenerator::getTrace(const Variant &options) {
    return this_.exec("getTrace", options);
}

Variant ReflectionGenerator::getFunction() {
    return this_.exec("getFunction");
}

Variant ReflectionGenerator::_getThis() {
    return this_.exec("getThis");
}

Variant ReflectionGenerator::getExecutingGenerator() {
    return this_.exec("getExecutingGenerator");
}


ReflectionParameter::ReflectionParameter(const Variant &function, const Variant &param) {
    this_ = newObject("ReflectionParameter", function, param);
}

Variant ReflectionParameter::__toString() {
    return this_.exec("__toString");
}

Variant ReflectionParameter::getName() {
    return this_.exec("getName");
}

Variant ReflectionParameter::isPassedByReference() {
    return this_.exec("isPassedByReference");
}

Variant ReflectionParameter::canBePassedByValue() {
    return this_.exec("canBePassedByValue");
}

Variant ReflectionParameter::getDeclaringFunction() {
    return this_.exec("getDeclaringFunction");
}

Variant ReflectionParameter::getDeclaringClass() {
    return this_.exec("getDeclaringClass");
}

Variant ReflectionParameter::getClass() {
    return this_.exec("getClass");
}

Variant ReflectionParameter::hasType() {
    return this_.exec("hasType");
}

Variant ReflectionParameter::getType() {
    return this_.exec("getType");
}

Variant ReflectionParameter::isArray() {
    return this_.exec("isArray");
}

Variant ReflectionParameter::isCallable() {
    return this_.exec("isCallable");
}

Variant ReflectionParameter::allowsNull() {
    return this_.exec("allowsNull");
}

Variant ReflectionParameter::getPosition() {
    return this_.exec("getPosition");
}

Variant ReflectionParameter::isOptional() {
    return this_.exec("isOptional");
}

Variant ReflectionParameter::isDefaultValueAvailable() {
    return this_.exec("isDefaultValueAvailable");
}

Variant ReflectionParameter::getDefaultValue() {
    return this_.exec("getDefaultValue");
}

Variant ReflectionParameter::isDefaultValueConstant() {
    return this_.exec("isDefaultValueConstant");
}

Variant ReflectionParameter::getDefaultValueConstantName() {
    return this_.exec("getDefaultValueConstantName");
}

Variant ReflectionParameter::isVariadic() {
    return this_.exec("isVariadic");
}

Variant ReflectionParameter::isPromoted() {
    return this_.exec("isPromoted");
}

Variant ReflectionParameter::getAttributes(const Variant &name, const Variant &flags) {
    return this_.exec("getAttributes", name, flags);
}


Variant ReflectionNamedType::getName() {
    return this_.exec("getName");
}

Variant ReflectionNamedType::isBuiltin() {
    return this_.exec("isBuiltin");
}

Variant ReflectionNamedType::allowsNull() {
    return this_.exec("allowsNull");
}

Variant ReflectionNamedType::__toString() {
    return this_.exec("__toString");
}


Variant ReflectionUnionType::getTypes() {
    return this_.exec("getTypes");
}

Variant ReflectionUnionType::allowsNull() {
    return this_.exec("allowsNull");
}

Variant ReflectionUnionType::__toString() {
    return this_.exec("__toString");
}


Variant ReflectionIntersectionType::getTypes() {
    return this_.exec("getTypes");
}

Variant ReflectionIntersectionType::allowsNull() {
    return this_.exec("allowsNull");
}

Variant ReflectionIntersectionType::__toString() {
    return this_.exec("__toString");
}


ReflectionMethod::ReflectionMethod(const Variant &object_or_method, const Variant &method) {
    this_ = newObject("ReflectionMethod", object_or_method, method);
}

Variant ReflectionMethod::createFromMethodName(const Variant &method) {
    static Variant fn { ZEND_STRL("ReflectionMethod::createFromMethodName"), true };
    return fn(method);
}

Variant ReflectionMethod::__toString() {
    return this_.exec("__toString");
}

Variant ReflectionMethod::isPublic() {
    return this_.exec("isPublic");
}

Variant ReflectionMethod::isPrivate() {
    return this_.exec("isPrivate");
}

Variant ReflectionMethod::isProtected() {
    return this_.exec("isProtected");
}

Variant ReflectionMethod::isAbstract() {
    return this_.exec("isAbstract");
}

Variant ReflectionMethod::isFinal() {
    return this_.exec("isFinal");
}

Variant ReflectionMethod::isConstructor() {
    return this_.exec("isConstructor");
}

Variant ReflectionMethod::isDestructor() {
    return this_.exec("isDestructor");
}

Variant ReflectionMethod::getClosure(const Variant &object) {
    return this_.exec("getClosure", object);
}

Variant ReflectionMethod::getModifiers() {
    return this_.exec("getModifiers");
}

Variant ReflectionMethod::invoke(const Variant &object, const Variant &args) {
    return this_.exec("invoke", object, args);
}

Variant ReflectionMethod::invokeArgs(const Variant &object, const Variant &args) {
    return this_.exec("invokeArgs", object, args);
}

Variant ReflectionMethod::getDeclaringClass() {
    return this_.exec("getDeclaringClass");
}

Variant ReflectionMethod::getPrototype() {
    return this_.exec("getPrototype");
}

Variant ReflectionMethod::hasPrototype() {
    return this_.exec("hasPrototype");
}

Variant ReflectionMethod::setAccessible(const Variant &accessible) {
    return this_.exec("setAccessible", accessible);
}

Variant ReflectionMethod::inNamespace() {
    return this_.exec("inNamespace");
}

Variant ReflectionMethod::isClosure() {
    return this_.exec("isClosure");
}

Variant ReflectionMethod::isDeprecated() {
    return this_.exec("isDeprecated");
}

Variant ReflectionMethod::isInternal() {
    return this_.exec("isInternal");
}

Variant ReflectionMethod::isUserDefined() {
    return this_.exec("isUserDefined");
}

Variant ReflectionMethod::isGenerator() {
    return this_.exec("isGenerator");
}

Variant ReflectionMethod::isVariadic() {
    return this_.exec("isVariadic");
}

Variant ReflectionMethod::isStatic() {
    return this_.exec("isStatic");
}

Variant ReflectionMethod::getClosureThis() {
    return this_.exec("getClosureThis");
}

Variant ReflectionMethod::getClosureScopeClass() {
    return this_.exec("getClosureScopeClass");
}

Variant ReflectionMethod::getClosureCalledClass() {
    return this_.exec("getClosureCalledClass");
}

Variant ReflectionMethod::getClosureUsedVariables() {
    return this_.exec("getClosureUsedVariables");
}

Variant ReflectionMethod::getDocComment() {
    return this_.exec("getDocComment");
}

Variant ReflectionMethod::getEndLine() {
    return this_.exec("getEndLine");
}

Variant ReflectionMethod::getExtension() {
    return this_.exec("getExtension");
}

Variant ReflectionMethod::getExtensionName() {
    return this_.exec("getExtensionName");
}

Variant ReflectionMethod::getFileName() {
    return this_.exec("getFileName");
}

Variant ReflectionMethod::getName() {
    return this_.exec("getName");
}

Variant ReflectionMethod::getNamespaceName() {
    return this_.exec("getNamespaceName");
}

Variant ReflectionMethod::getNumberOfParameters() {
    return this_.exec("getNumberOfParameters");
}

Variant ReflectionMethod::getNumberOfRequiredParameters() {
    return this_.exec("getNumberOfRequiredParameters");
}

Variant ReflectionMethod::getParameters() {
    return this_.exec("getParameters");
}

Variant ReflectionMethod::getShortName() {
    return this_.exec("getShortName");
}

Variant ReflectionMethod::getStartLine() {
    return this_.exec("getStartLine");
}

Variant ReflectionMethod::getStaticVariables() {
    return this_.exec("getStaticVariables");
}

Variant ReflectionMethod::returnsReference() {
    return this_.exec("returnsReference");
}

Variant ReflectionMethod::hasReturnType() {
    return this_.exec("hasReturnType");
}

Variant ReflectionMethod::getReturnType() {
    return this_.exec("getReturnType");
}

Variant ReflectionMethod::hasTentativeReturnType() {
    return this_.exec("hasTentativeReturnType");
}

Variant ReflectionMethod::getTentativeReturnType() {
    return this_.exec("getTentativeReturnType");
}

Variant ReflectionMethod::getAttributes(const Variant &name, const Variant &flags) {
    return this_.exec("getAttributes", name, flags);
}


ReflectionClass::ReflectionClass(const Variant &object_or_class) {
    this_ = newObject("ReflectionClass", object_or_class);
}

Variant ReflectionClass::__toString() {
    return this_.exec("__toString");
}

Variant ReflectionClass::getName() {
    return this_.exec("getName");
}

Variant ReflectionClass::isInternal() {
    return this_.exec("isInternal");
}

Variant ReflectionClass::isUserDefined() {
    return this_.exec("isUserDefined");
}

Variant ReflectionClass::isAnonymous() {
    return this_.exec("isAnonymous");
}

Variant ReflectionClass::isInstantiable() {
    return this_.exec("isInstantiable");
}

Variant ReflectionClass::isCloneable() {
    return this_.exec("isCloneable");
}

Variant ReflectionClass::getFileName() {
    return this_.exec("getFileName");
}

Variant ReflectionClass::getStartLine() {
    return this_.exec("getStartLine");
}

Variant ReflectionClass::getEndLine() {
    return this_.exec("getEndLine");
}

Variant ReflectionClass::getDocComment() {
    return this_.exec("getDocComment");
}

Variant ReflectionClass::getConstructor() {
    return this_.exec("getConstructor");
}

Variant ReflectionClass::hasMethod(const Variant &name) {
    return this_.exec("hasMethod", name);
}

Variant ReflectionClass::getMethod(const Variant &name) {
    return this_.exec("getMethod", name);
}

Variant ReflectionClass::getMethods(const Variant &filter) {
    return this_.exec("getMethods", filter);
}

Variant ReflectionClass::hasProperty(const Variant &name) {
    return this_.exec("hasProperty", name);
}

Variant ReflectionClass::getProperty(const Variant &name) {
    return this_.exec("getProperty", name);
}

Variant ReflectionClass::getProperties(const Variant &filter) {
    return this_.exec("getProperties", filter);
}

Variant ReflectionClass::hasConstant(const Variant &name) {
    return this_.exec("hasConstant", name);
}

Variant ReflectionClass::getConstants(const Variant &filter) {
    return this_.exec("getConstants", filter);
}

Variant ReflectionClass::getReflectionConstants(const Variant &filter) {
    return this_.exec("getReflectionConstants", filter);
}

Variant ReflectionClass::getConstant(const Variant &name) {
    return this_.exec("getConstant", name);
}

Variant ReflectionClass::getReflectionConstant(const Variant &name) {
    return this_.exec("getReflectionConstant", name);
}

Variant ReflectionClass::getInterfaces() {
    return this_.exec("getInterfaces");
}

Variant ReflectionClass::getInterfaceNames() {
    return this_.exec("getInterfaceNames");
}

Variant ReflectionClass::isInterface() {
    return this_.exec("isInterface");
}

Variant ReflectionClass::getTraits() {
    return this_.exec("getTraits");
}

Variant ReflectionClass::getTraitNames() {
    return this_.exec("getTraitNames");
}

Variant ReflectionClass::getTraitAliases() {
    return this_.exec("getTraitAliases");
}

Variant ReflectionClass::isTrait() {
    return this_.exec("isTrait");
}

Variant ReflectionClass::isEnum() {
    return this_.exec("isEnum");
}

Variant ReflectionClass::isAbstract() {
    return this_.exec("isAbstract");
}

Variant ReflectionClass::isFinal() {
    return this_.exec("isFinal");
}

Variant ReflectionClass::isReadOnly() {
    return this_.exec("isReadOnly");
}

Variant ReflectionClass::getModifiers() {
    return this_.exec("getModifiers");
}

Variant ReflectionClass::isInstance(const Variant &object) {
    return this_.exec("isInstance", object);
}

Variant ReflectionClass::newInstance(const Variant &args) {
    return this_.exec("newInstance", args);
}

Variant ReflectionClass::newInstanceWithoutConstructor() {
    return this_.exec("newInstanceWithoutConstructor");
}

Variant ReflectionClass::newInstanceArgs(const Array &args) {
    return this_.exec("newInstanceArgs", args);
}

Variant ReflectionClass::getParentClass() {
    return this_.exec("getParentClass");
}

Variant ReflectionClass::isSubclassOf(const Variant &_class) {
    return this_.exec("isSubclassOf", _class);
}

Variant ReflectionClass::getStaticProperties() {
    return this_.exec("getStaticProperties");
}

Variant ReflectionClass::getStaticPropertyValue(const Variant &name, const Variant &_default) {
    return this_.exec("getStaticPropertyValue", name, _default);
}

Variant ReflectionClass::setStaticPropertyValue(const Variant &name, const Variant &value) {
    return this_.exec("setStaticPropertyValue", name, value);
}

Variant ReflectionClass::getDefaultProperties() {
    return this_.exec("getDefaultProperties");
}

Variant ReflectionClass::isIterable() {
    return this_.exec("isIterable");
}

Variant ReflectionClass::isIterateable() {
    return this_.exec("isIterateable");
}

Variant ReflectionClass::implementsInterface(const Variant &interface) {
    return this_.exec("implementsInterface", interface);
}

Variant ReflectionClass::getExtension() {
    return this_.exec("getExtension");
}

Variant ReflectionClass::getExtensionName() {
    return this_.exec("getExtensionName");
}

Variant ReflectionClass::inNamespace() {
    return this_.exec("inNamespace");
}

Variant ReflectionClass::getNamespaceName() {
    return this_.exec("getNamespaceName");
}

Variant ReflectionClass::getShortName() {
    return this_.exec("getShortName");
}

Variant ReflectionClass::getAttributes(const Variant &name, const Variant &flags) {
    return this_.exec("getAttributes", name, flags);
}


ReflectionObject::ReflectionObject(const Variant &object) {
    this_ = newObject("ReflectionObject", object);
}

Variant ReflectionObject::__toString() {
    return this_.exec("__toString");
}

Variant ReflectionObject::getName() {
    return this_.exec("getName");
}

Variant ReflectionObject::isInternal() {
    return this_.exec("isInternal");
}

Variant ReflectionObject::isUserDefined() {
    return this_.exec("isUserDefined");
}

Variant ReflectionObject::isAnonymous() {
    return this_.exec("isAnonymous");
}

Variant ReflectionObject::isInstantiable() {
    return this_.exec("isInstantiable");
}

Variant ReflectionObject::isCloneable() {
    return this_.exec("isCloneable");
}

Variant ReflectionObject::getFileName() {
    return this_.exec("getFileName");
}

Variant ReflectionObject::getStartLine() {
    return this_.exec("getStartLine");
}

Variant ReflectionObject::getEndLine() {
    return this_.exec("getEndLine");
}

Variant ReflectionObject::getDocComment() {
    return this_.exec("getDocComment");
}

Variant ReflectionObject::getConstructor() {
    return this_.exec("getConstructor");
}

Variant ReflectionObject::hasMethod(const Variant &name) {
    return this_.exec("hasMethod", name);
}

Variant ReflectionObject::getMethod(const Variant &name) {
    return this_.exec("getMethod", name);
}

Variant ReflectionObject::getMethods(const Variant &filter) {
    return this_.exec("getMethods", filter);
}

Variant ReflectionObject::hasProperty(const Variant &name) {
    return this_.exec("hasProperty", name);
}

Variant ReflectionObject::getProperty(const Variant &name) {
    return this_.exec("getProperty", name);
}

Variant ReflectionObject::getProperties(const Variant &filter) {
    return this_.exec("getProperties", filter);
}

Variant ReflectionObject::hasConstant(const Variant &name) {
    return this_.exec("hasConstant", name);
}

Variant ReflectionObject::getConstants(const Variant &filter) {
    return this_.exec("getConstants", filter);
}

Variant ReflectionObject::getReflectionConstants(const Variant &filter) {
    return this_.exec("getReflectionConstants", filter);
}

Variant ReflectionObject::getConstant(const Variant &name) {
    return this_.exec("getConstant", name);
}

Variant ReflectionObject::getReflectionConstant(const Variant &name) {
    return this_.exec("getReflectionConstant", name);
}

Variant ReflectionObject::getInterfaces() {
    return this_.exec("getInterfaces");
}

Variant ReflectionObject::getInterfaceNames() {
    return this_.exec("getInterfaceNames");
}

Variant ReflectionObject::isInterface() {
    return this_.exec("isInterface");
}

Variant ReflectionObject::getTraits() {
    return this_.exec("getTraits");
}

Variant ReflectionObject::getTraitNames() {
    return this_.exec("getTraitNames");
}

Variant ReflectionObject::getTraitAliases() {
    return this_.exec("getTraitAliases");
}

Variant ReflectionObject::isTrait() {
    return this_.exec("isTrait");
}

Variant ReflectionObject::isEnum() {
    return this_.exec("isEnum");
}

Variant ReflectionObject::isAbstract() {
    return this_.exec("isAbstract");
}

Variant ReflectionObject::isFinal() {
    return this_.exec("isFinal");
}

Variant ReflectionObject::isReadOnly() {
    return this_.exec("isReadOnly");
}

Variant ReflectionObject::getModifiers() {
    return this_.exec("getModifiers");
}

Variant ReflectionObject::isInstance(const Variant &object) {
    return this_.exec("isInstance", object);
}

Variant ReflectionObject::newInstance(const Variant &args) {
    return this_.exec("newInstance", args);
}

Variant ReflectionObject::newInstanceWithoutConstructor() {
    return this_.exec("newInstanceWithoutConstructor");
}

Variant ReflectionObject::newInstanceArgs(const Array &args) {
    return this_.exec("newInstanceArgs", args);
}

Variant ReflectionObject::getParentClass() {
    return this_.exec("getParentClass");
}

Variant ReflectionObject::isSubclassOf(const Variant &_class) {
    return this_.exec("isSubclassOf", _class);
}

Variant ReflectionObject::getStaticProperties() {
    return this_.exec("getStaticProperties");
}

Variant ReflectionObject::getStaticPropertyValue(const Variant &name, const Variant &_default) {
    return this_.exec("getStaticPropertyValue", name, _default);
}

Variant ReflectionObject::setStaticPropertyValue(const Variant &name, const Variant &value) {
    return this_.exec("setStaticPropertyValue", name, value);
}

Variant ReflectionObject::getDefaultProperties() {
    return this_.exec("getDefaultProperties");
}

Variant ReflectionObject::isIterable() {
    return this_.exec("isIterable");
}

Variant ReflectionObject::isIterateable() {
    return this_.exec("isIterateable");
}

Variant ReflectionObject::implementsInterface(const Variant &interface) {
    return this_.exec("implementsInterface", interface);
}

Variant ReflectionObject::getExtension() {
    return this_.exec("getExtension");
}

Variant ReflectionObject::getExtensionName() {
    return this_.exec("getExtensionName");
}

Variant ReflectionObject::inNamespace() {
    return this_.exec("inNamespace");
}

Variant ReflectionObject::getNamespaceName() {
    return this_.exec("getNamespaceName");
}

Variant ReflectionObject::getShortName() {
    return this_.exec("getShortName");
}

Variant ReflectionObject::getAttributes(const Variant &name, const Variant &flags) {
    return this_.exec("getAttributes", name, flags);
}


ReflectionProperty::ReflectionProperty(const Variant &_class, const Variant &property) {
    this_ = newObject("ReflectionProperty", _class, property);
}

Variant ReflectionProperty::__toString() {
    return this_.exec("__toString");
}

Variant ReflectionProperty::getName() {
    return this_.exec("getName");
}

Variant ReflectionProperty::getValue(const Variant &object) {
    return this_.exec("getValue", object);
}

Variant ReflectionProperty::setValue(const Variant &object_or_value, const Variant &value) {
    return this_.exec("setValue", object_or_value, value);
}

Variant ReflectionProperty::isInitialized(const Variant &object) {
    return this_.exec("isInitialized", object);
}

Variant ReflectionProperty::isPublic() {
    return this_.exec("isPublic");
}

Variant ReflectionProperty::isPrivate() {
    return this_.exec("isPrivate");
}

Variant ReflectionProperty::isProtected() {
    return this_.exec("isProtected");
}

Variant ReflectionProperty::isStatic() {
    return this_.exec("isStatic");
}

Variant ReflectionProperty::isReadOnly() {
    return this_.exec("isReadOnly");
}

Variant ReflectionProperty::isDefault() {
    return this_.exec("isDefault");
}

Variant ReflectionProperty::isPromoted() {
    return this_.exec("isPromoted");
}

Variant ReflectionProperty::getModifiers() {
    return this_.exec("getModifiers");
}

Variant ReflectionProperty::getDeclaringClass() {
    return this_.exec("getDeclaringClass");
}

Variant ReflectionProperty::getDocComment() {
    return this_.exec("getDocComment");
}

Variant ReflectionProperty::setAccessible(const Variant &accessible) {
    return this_.exec("setAccessible", accessible);
}

Variant ReflectionProperty::getType() {
    return this_.exec("getType");
}

Variant ReflectionProperty::hasType() {
    return this_.exec("hasType");
}

Variant ReflectionProperty::hasDefaultValue() {
    return this_.exec("hasDefaultValue");
}

Variant ReflectionProperty::getDefaultValue() {
    return this_.exec("getDefaultValue");
}

Variant ReflectionProperty::getAttributes(const Variant &name, const Variant &flags) {
    return this_.exec("getAttributes", name, flags);
}


ReflectionClassConstant::ReflectionClassConstant(const Variant &_class, const Variant &constant) {
    this_ = newObject("ReflectionClassConstant", _class, constant);
}

Variant ReflectionClassConstant::__toString() {
    return this_.exec("__toString");
}

Variant ReflectionClassConstant::getName() {
    return this_.exec("getName");
}

Variant ReflectionClassConstant::getValue() {
    return this_.exec("getValue");
}

Variant ReflectionClassConstant::isPublic() {
    return this_.exec("isPublic");
}

Variant ReflectionClassConstant::isPrivate() {
    return this_.exec("isPrivate");
}

Variant ReflectionClassConstant::isProtected() {
    return this_.exec("isProtected");
}

Variant ReflectionClassConstant::isFinal() {
    return this_.exec("isFinal");
}

Variant ReflectionClassConstant::getModifiers() {
    return this_.exec("getModifiers");
}

Variant ReflectionClassConstant::getDeclaringClass() {
    return this_.exec("getDeclaringClass");
}

Variant ReflectionClassConstant::getDocComment() {
    return this_.exec("getDocComment");
}

Variant ReflectionClassConstant::getAttributes(const Variant &name, const Variant &flags) {
    return this_.exec("getAttributes", name, flags);
}

Variant ReflectionClassConstant::isEnumCase() {
    return this_.exec("isEnumCase");
}

Variant ReflectionClassConstant::hasType() {
    return this_.exec("hasType");
}

Variant ReflectionClassConstant::getType() {
    return this_.exec("getType");
}


ReflectionExtension::ReflectionExtension(const Variant &name) {
    this_ = newObject("ReflectionExtension", name);
}

Variant ReflectionExtension::__toString() {
    return this_.exec("__toString");
}

Variant ReflectionExtension::getName() {
    return this_.exec("getName");
}

Variant ReflectionExtension::getVersion() {
    return this_.exec("getVersion");
}

Variant ReflectionExtension::getFunctions() {
    return this_.exec("getFunctions");
}

Variant ReflectionExtension::getConstants() {
    return this_.exec("getConstants");
}

Variant ReflectionExtension::getINIEntries() {
    return this_.exec("getINIEntries");
}

Variant ReflectionExtension::getClasses() {
    return this_.exec("getClasses");
}

Variant ReflectionExtension::getClassNames() {
    return this_.exec("getClassNames");
}

Variant ReflectionExtension::getDependencies() {
    return this_.exec("getDependencies");
}

Variant ReflectionExtension::info() {
    return this_.exec("info");
}

Variant ReflectionExtension::isPersistent() {
    return this_.exec("isPersistent");
}

Variant ReflectionExtension::isTemporary() {
    return this_.exec("isTemporary");
}


ReflectionZendExtension::ReflectionZendExtension(const Variant &name) {
    this_ = newObject("ReflectionZendExtension", name);
}

Variant ReflectionZendExtension::__toString() {
    return this_.exec("__toString");
}

Variant ReflectionZendExtension::getName() {
    return this_.exec("getName");
}

Variant ReflectionZendExtension::getVersion() {
    return this_.exec("getVersion");
}

Variant ReflectionZendExtension::getAuthor() {
    return this_.exec("getAuthor");
}

Variant ReflectionZendExtension::getURL() {
    return this_.exec("getURL");
}

Variant ReflectionZendExtension::getCopyright() {
    return this_.exec("getCopyright");
}


Variant ReflectionReference::fromArrayElement(const Variant &array, const Variant &key) {
    static Variant fn { ZEND_STRL("ReflectionReference::fromArrayElement"), true };
    return fn(array, key);
}

Variant ReflectionReference::getId() {
    return this_.exec("getId");
}


Variant ReflectionAttribute::getName() {
    return this_.exec("getName");
}

Variant ReflectionAttribute::getTarget() {
    return this_.exec("getTarget");
}

Variant ReflectionAttribute::isRepeated() {
    return this_.exec("isRepeated");
}

Variant ReflectionAttribute::getArguments() {
    return this_.exec("getArguments");
}

Variant ReflectionAttribute::newInstance() {
    return this_.exec("newInstance");
}

Variant ReflectionAttribute::__toString() {
    return this_.exec("__toString");
}


ReflectionEnum::ReflectionEnum(const Variant &object_or_class) {
    this_ = newObject("ReflectionEnum", object_or_class);
}

Variant ReflectionEnum::hasCase(const Variant &name) {
    return this_.exec("hasCase", name);
}

Variant ReflectionEnum::getCase(const Variant &name) {
    return this_.exec("getCase", name);
}

Variant ReflectionEnum::getCases() {
    return this_.exec("getCases");
}

Variant ReflectionEnum::isBacked() {
    return this_.exec("isBacked");
}

Variant ReflectionEnum::getBackingType() {
    return this_.exec("getBackingType");
}

Variant ReflectionEnum::__toString() {
    return this_.exec("__toString");
}

Variant ReflectionEnum::getName() {
    return this_.exec("getName");
}

Variant ReflectionEnum::isInternal() {
    return this_.exec("isInternal");
}

Variant ReflectionEnum::isUserDefined() {
    return this_.exec("isUserDefined");
}

Variant ReflectionEnum::isAnonymous() {
    return this_.exec("isAnonymous");
}

Variant ReflectionEnum::isInstantiable() {
    return this_.exec("isInstantiable");
}

Variant ReflectionEnum::isCloneable() {
    return this_.exec("isCloneable");
}

Variant ReflectionEnum::getFileName() {
    return this_.exec("getFileName");
}

Variant ReflectionEnum::getStartLine() {
    return this_.exec("getStartLine");
}

Variant ReflectionEnum::getEndLine() {
    return this_.exec("getEndLine");
}

Variant ReflectionEnum::getDocComment() {
    return this_.exec("getDocComment");
}

Variant ReflectionEnum::getConstructor() {
    return this_.exec("getConstructor");
}

Variant ReflectionEnum::hasMethod(const Variant &name) {
    return this_.exec("hasMethod", name);
}

Variant ReflectionEnum::getMethod(const Variant &name) {
    return this_.exec("getMethod", name);
}

Variant ReflectionEnum::getMethods(const Variant &filter) {
    return this_.exec("getMethods", filter);
}

Variant ReflectionEnum::hasProperty(const Variant &name) {
    return this_.exec("hasProperty", name);
}

Variant ReflectionEnum::getProperty(const Variant &name) {
    return this_.exec("getProperty", name);
}

Variant ReflectionEnum::getProperties(const Variant &filter) {
    return this_.exec("getProperties", filter);
}

Variant ReflectionEnum::hasConstant(const Variant &name) {
    return this_.exec("hasConstant", name);
}

Variant ReflectionEnum::getConstants(const Variant &filter) {
    return this_.exec("getConstants", filter);
}

Variant ReflectionEnum::getReflectionConstants(const Variant &filter) {
    return this_.exec("getReflectionConstants", filter);
}

Variant ReflectionEnum::getConstant(const Variant &name) {
    return this_.exec("getConstant", name);
}

Variant ReflectionEnum::getReflectionConstant(const Variant &name) {
    return this_.exec("getReflectionConstant", name);
}

Variant ReflectionEnum::getInterfaces() {
    return this_.exec("getInterfaces");
}

Variant ReflectionEnum::getInterfaceNames() {
    return this_.exec("getInterfaceNames");
}

Variant ReflectionEnum::isInterface() {
    return this_.exec("isInterface");
}

Variant ReflectionEnum::getTraits() {
    return this_.exec("getTraits");
}

Variant ReflectionEnum::getTraitNames() {
    return this_.exec("getTraitNames");
}

Variant ReflectionEnum::getTraitAliases() {
    return this_.exec("getTraitAliases");
}

Variant ReflectionEnum::isTrait() {
    return this_.exec("isTrait");
}

Variant ReflectionEnum::isEnum() {
    return this_.exec("isEnum");
}

Variant ReflectionEnum::isAbstract() {
    return this_.exec("isAbstract");
}

Variant ReflectionEnum::isFinal() {
    return this_.exec("isFinal");
}

Variant ReflectionEnum::isReadOnly() {
    return this_.exec("isReadOnly");
}

Variant ReflectionEnum::getModifiers() {
    return this_.exec("getModifiers");
}

Variant ReflectionEnum::isInstance(const Variant &object) {
    return this_.exec("isInstance", object);
}

Variant ReflectionEnum::newInstance(const Variant &args) {
    return this_.exec("newInstance", args);
}

Variant ReflectionEnum::newInstanceWithoutConstructor() {
    return this_.exec("newInstanceWithoutConstructor");
}

Variant ReflectionEnum::newInstanceArgs(const Array &args) {
    return this_.exec("newInstanceArgs", args);
}

Variant ReflectionEnum::getParentClass() {
    return this_.exec("getParentClass");
}

Variant ReflectionEnum::isSubclassOf(const Variant &_class) {
    return this_.exec("isSubclassOf", _class);
}

Variant ReflectionEnum::getStaticProperties() {
    return this_.exec("getStaticProperties");
}

Variant ReflectionEnum::getStaticPropertyValue(const Variant &name, const Variant &_default) {
    return this_.exec("getStaticPropertyValue", name, _default);
}

Variant ReflectionEnum::setStaticPropertyValue(const Variant &name, const Variant &value) {
    return this_.exec("setStaticPropertyValue", name, value);
}

Variant ReflectionEnum::getDefaultProperties() {
    return this_.exec("getDefaultProperties");
}

Variant ReflectionEnum::isIterable() {
    return this_.exec("isIterable");
}

Variant ReflectionEnum::isIterateable() {
    return this_.exec("isIterateable");
}

Variant ReflectionEnum::implementsInterface(const Variant &interface) {
    return this_.exec("implementsInterface", interface);
}

Variant ReflectionEnum::getExtension() {
    return this_.exec("getExtension");
}

Variant ReflectionEnum::getExtensionName() {
    return this_.exec("getExtensionName");
}

Variant ReflectionEnum::inNamespace() {
    return this_.exec("inNamespace");
}

Variant ReflectionEnum::getNamespaceName() {
    return this_.exec("getNamespaceName");
}

Variant ReflectionEnum::getShortName() {
    return this_.exec("getShortName");
}

Variant ReflectionEnum::getAttributes(const Variant &name, const Variant &flags) {
    return this_.exec("getAttributes", name, flags);
}


ReflectionEnumUnitCase::ReflectionEnumUnitCase(const Variant &_class, const Variant &constant) {
    this_ = newObject("ReflectionEnumUnitCase", _class, constant);
}

Variant ReflectionEnumUnitCase::getEnum() {
    return this_.exec("getEnum");
}

Variant ReflectionEnumUnitCase::getValue() {
    return this_.exec("getValue");
}

Variant ReflectionEnumUnitCase::__toString() {
    return this_.exec("__toString");
}

Variant ReflectionEnumUnitCase::getName() {
    return this_.exec("getName");
}

Variant ReflectionEnumUnitCase::isPublic() {
    return this_.exec("isPublic");
}

Variant ReflectionEnumUnitCase::isPrivate() {
    return this_.exec("isPrivate");
}

Variant ReflectionEnumUnitCase::isProtected() {
    return this_.exec("isProtected");
}

Variant ReflectionEnumUnitCase::isFinal() {
    return this_.exec("isFinal");
}

Variant ReflectionEnumUnitCase::getModifiers() {
    return this_.exec("getModifiers");
}

Variant ReflectionEnumUnitCase::getDeclaringClass() {
    return this_.exec("getDeclaringClass");
}

Variant ReflectionEnumUnitCase::getDocComment() {
    return this_.exec("getDocComment");
}

Variant ReflectionEnumUnitCase::getAttributes(const Variant &name, const Variant &flags) {
    return this_.exec("getAttributes", name, flags);
}

Variant ReflectionEnumUnitCase::isEnumCase() {
    return this_.exec("isEnumCase");
}

Variant ReflectionEnumUnitCase::hasType() {
    return this_.exec("hasType");
}

Variant ReflectionEnumUnitCase::getType() {
    return this_.exec("getType");
}


ReflectionEnumBackedCase::ReflectionEnumBackedCase(const Variant &_class, const Variant &constant) {
    this_ = newObject("ReflectionEnumBackedCase", _class, constant);
}

Variant ReflectionEnumBackedCase::getBackingValue() {
    return this_.exec("getBackingValue");
}

Variant ReflectionEnumBackedCase::getEnum() {
    return this_.exec("getEnum");
}

Variant ReflectionEnumBackedCase::getValue() {
    return this_.exec("getValue");
}

Variant ReflectionEnumBackedCase::__toString() {
    return this_.exec("__toString");
}

Variant ReflectionEnumBackedCase::getName() {
    return this_.exec("getName");
}

Variant ReflectionEnumBackedCase::isPublic() {
    return this_.exec("isPublic");
}

Variant ReflectionEnumBackedCase::isPrivate() {
    return this_.exec("isPrivate");
}

Variant ReflectionEnumBackedCase::isProtected() {
    return this_.exec("isProtected");
}

Variant ReflectionEnumBackedCase::isFinal() {
    return this_.exec("isFinal");
}

Variant ReflectionEnumBackedCase::getModifiers() {
    return this_.exec("getModifiers");
}

Variant ReflectionEnumBackedCase::getDeclaringClass() {
    return this_.exec("getDeclaringClass");
}

Variant ReflectionEnumBackedCase::getDocComment() {
    return this_.exec("getDocComment");
}

Variant ReflectionEnumBackedCase::getAttributes(const Variant &name, const Variant &flags) {
    return this_.exec("getAttributes", name, flags);
}

Variant ReflectionEnumBackedCase::isEnumCase() {
    return this_.exec("isEnumCase");
}

Variant ReflectionEnumBackedCase::hasType() {
    return this_.exec("hasType");
}

Variant ReflectionEnumBackedCase::getType() {
    return this_.exec("getType");
}


ReflectionFiber::ReflectionFiber(const Variant &fiber) {
    this_ = newObject("ReflectionFiber", fiber);
}

Variant ReflectionFiber::getFiber() {
    return this_.exec("getFiber");
}

Variant ReflectionFiber::getExecutingFile() {
    return this_.exec("getExecutingFile");
}

Variant ReflectionFiber::getExecutingLine() {
    return this_.exec("getExecutingLine");
}

Variant ReflectionFiber::getCallable() {
    return this_.exec("getCallable");
}

Variant ReflectionFiber::getTrace(const Variant &options) {
    return this_.exec("getTrace", options);
}


}

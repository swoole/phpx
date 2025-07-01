#include "phpx.h"
#include "class/reflection.h"

namespace php {
ReflectionException::ReflectionException(const Variant &message, const Variant &code, const Variant &previous) {
    _this = newObject("ReflectionException", message, code, previous);
}

Variant ReflectionException::__wakeup() {
    return _this.exec("__wakeup");
}

Variant ReflectionException::getMessage() {
    return _this.exec("getMessage");
}

Variant ReflectionException::getCode() {
    return _this.exec("getCode");
}

Variant ReflectionException::getFile() {
    return _this.exec("getFile");
}

Variant ReflectionException::getLine() {
    return _this.exec("getLine");
}

Variant ReflectionException::getTrace() {
    return _this.exec("getTrace");
}

Variant ReflectionException::getPrevious() {
    return _this.exec("getPrevious");
}

Variant ReflectionException::getTraceAsString() {
    return _this.exec("getTraceAsString");
}

Variant ReflectionException::__toString() {
    return _this.exec("__toString");
}


Variant Reflection::getModifierNames(const Variant &modifiers) {
    static Variant fn { ZEND_STRL("Reflection::getModifierNames"), true };
    return fn(modifiers);
}


ReflectionFunction::ReflectionFunction(const Variant &function) {
    _this = newObject("ReflectionFunction", function);
}

Variant ReflectionFunction::__toString() {
    return _this.exec("__toString");
}

Variant ReflectionFunction::isAnonymous() {
    return _this.exec("isAnonymous");
}

Variant ReflectionFunction::isDisabled() {
    return _this.exec("isDisabled");
}

Variant ReflectionFunction::invoke(const Variant &args) {
    return _this.exec("invoke", args);
}

Variant ReflectionFunction::invokeArgs(const Variant &args) {
    return _this.exec("invokeArgs", args);
}

Variant ReflectionFunction::getClosure() {
    return _this.exec("getClosure");
}

Variant ReflectionFunction::inNamespace() {
    return _this.exec("inNamespace");
}

Variant ReflectionFunction::isClosure() {
    return _this.exec("isClosure");
}

Variant ReflectionFunction::isDeprecated() {
    return _this.exec("isDeprecated");
}

Variant ReflectionFunction::isInternal() {
    return _this.exec("isInternal");
}

Variant ReflectionFunction::isUserDefined() {
    return _this.exec("isUserDefined");
}

Variant ReflectionFunction::isGenerator() {
    return _this.exec("isGenerator");
}

Variant ReflectionFunction::isVariadic() {
    return _this.exec("isVariadic");
}

Variant ReflectionFunction::isStatic() {
    return _this.exec("isStatic");
}

Variant ReflectionFunction::getClosureThis() {
    return _this.exec("getClosureThis");
}

Variant ReflectionFunction::getClosureScopeClass() {
    return _this.exec("getClosureScopeClass");
}

Variant ReflectionFunction::getClosureCalledClass() {
    return _this.exec("getClosureCalledClass");
}

Variant ReflectionFunction::getClosureUsedVariables() {
    return _this.exec("getClosureUsedVariables");
}

Variant ReflectionFunction::getDocComment() {
    return _this.exec("getDocComment");
}

Variant ReflectionFunction::getEndLine() {
    return _this.exec("getEndLine");
}

Variant ReflectionFunction::getExtension() {
    return _this.exec("getExtension");
}

Variant ReflectionFunction::getExtensionName() {
    return _this.exec("getExtensionName");
}

Variant ReflectionFunction::getFileName() {
    return _this.exec("getFileName");
}

Variant ReflectionFunction::getName() {
    return _this.exec("getName");
}

Variant ReflectionFunction::getNamespaceName() {
    return _this.exec("getNamespaceName");
}

Variant ReflectionFunction::getNumberOfParameters() {
    return _this.exec("getNumberOfParameters");
}

Variant ReflectionFunction::getNumberOfRequiredParameters() {
    return _this.exec("getNumberOfRequiredParameters");
}

Variant ReflectionFunction::getParameters() {
    return _this.exec("getParameters");
}

Variant ReflectionFunction::getShortName() {
    return _this.exec("getShortName");
}

Variant ReflectionFunction::getStartLine() {
    return _this.exec("getStartLine");
}

Variant ReflectionFunction::getStaticVariables() {
    return _this.exec("getStaticVariables");
}

Variant ReflectionFunction::returnsReference() {
    return _this.exec("returnsReference");
}

Variant ReflectionFunction::hasReturnType() {
    return _this.exec("hasReturnType");
}

Variant ReflectionFunction::getReturnType() {
    return _this.exec("getReturnType");
}

Variant ReflectionFunction::hasTentativeReturnType() {
    return _this.exec("hasTentativeReturnType");
}

Variant ReflectionFunction::getTentativeReturnType() {
    return _this.exec("getTentativeReturnType");
}

Variant ReflectionFunction::getAttributes(const Variant &name, const Variant &flags) {
    return _this.exec("getAttributes", name, flags);
}


ReflectionGenerator::ReflectionGenerator(const Variant &generator) {
    _this = newObject("ReflectionGenerator", generator);
}

Variant ReflectionGenerator::getExecutingLine() {
    return _this.exec("getExecutingLine");
}

Variant ReflectionGenerator::getExecutingFile() {
    return _this.exec("getExecutingFile");
}

Variant ReflectionGenerator::getTrace(const Variant &options) {
    return _this.exec("getTrace", options);
}

Variant ReflectionGenerator::getFunction() {
    return _this.exec("getFunction");
}

Variant ReflectionGenerator::_getThis() {
    return _this.exec("getThis");
}

Variant ReflectionGenerator::getExecutingGenerator() {
    return _this.exec("getExecutingGenerator");
}


ReflectionParameter::ReflectionParameter(const Variant &function, const Variant &param) {
    _this = newObject("ReflectionParameter", function, param);
}

Variant ReflectionParameter::__toString() {
    return _this.exec("__toString");
}

Variant ReflectionParameter::getName() {
    return _this.exec("getName");
}

Variant ReflectionParameter::isPassedByReference() {
    return _this.exec("isPassedByReference");
}

Variant ReflectionParameter::canBePassedByValue() {
    return _this.exec("canBePassedByValue");
}

Variant ReflectionParameter::getDeclaringFunction() {
    return _this.exec("getDeclaringFunction");
}

Variant ReflectionParameter::getDeclaringClass() {
    return _this.exec("getDeclaringClass");
}

Variant ReflectionParameter::getClass() {
    return _this.exec("getClass");
}

Variant ReflectionParameter::hasType() {
    return _this.exec("hasType");
}

Variant ReflectionParameter::getType() {
    return _this.exec("getType");
}

Variant ReflectionParameter::isArray() {
    return _this.exec("isArray");
}

Variant ReflectionParameter::isCallable() {
    return _this.exec("isCallable");
}

Variant ReflectionParameter::allowsNull() {
    return _this.exec("allowsNull");
}

Variant ReflectionParameter::getPosition() {
    return _this.exec("getPosition");
}

Variant ReflectionParameter::isOptional() {
    return _this.exec("isOptional");
}

Variant ReflectionParameter::isDefaultValueAvailable() {
    return _this.exec("isDefaultValueAvailable");
}

Variant ReflectionParameter::getDefaultValue() {
    return _this.exec("getDefaultValue");
}

Variant ReflectionParameter::isDefaultValueConstant() {
    return _this.exec("isDefaultValueConstant");
}

Variant ReflectionParameter::getDefaultValueConstantName() {
    return _this.exec("getDefaultValueConstantName");
}

Variant ReflectionParameter::isVariadic() {
    return _this.exec("isVariadic");
}

Variant ReflectionParameter::isPromoted() {
    return _this.exec("isPromoted");
}

Variant ReflectionParameter::getAttributes(const Variant &name, const Variant &flags) {
    return _this.exec("getAttributes", name, flags);
}


Variant ReflectionNamedType::getName() {
    return _this.exec("getName");
}

Variant ReflectionNamedType::isBuiltin() {
    return _this.exec("isBuiltin");
}

Variant ReflectionNamedType::allowsNull() {
    return _this.exec("allowsNull");
}

Variant ReflectionNamedType::__toString() {
    return _this.exec("__toString");
}


Variant ReflectionUnionType::getTypes() {
    return _this.exec("getTypes");
}

Variant ReflectionUnionType::allowsNull() {
    return _this.exec("allowsNull");
}

Variant ReflectionUnionType::__toString() {
    return _this.exec("__toString");
}


Variant ReflectionIntersectionType::getTypes() {
    return _this.exec("getTypes");
}

Variant ReflectionIntersectionType::allowsNull() {
    return _this.exec("allowsNull");
}

Variant ReflectionIntersectionType::__toString() {
    return _this.exec("__toString");
}


ReflectionMethod::ReflectionMethod(const Variant &object_or_method, const Variant &method) {
    _this = newObject("ReflectionMethod", object_or_method, method);
}

Variant ReflectionMethod::__toString() {
    return _this.exec("__toString");
}

Variant ReflectionMethod::isPublic() {
    return _this.exec("isPublic");
}

Variant ReflectionMethod::isPrivate() {
    return _this.exec("isPrivate");
}

Variant ReflectionMethod::isProtected() {
    return _this.exec("isProtected");
}

Variant ReflectionMethod::isAbstract() {
    return _this.exec("isAbstract");
}

Variant ReflectionMethod::isFinal() {
    return _this.exec("isFinal");
}

Variant ReflectionMethod::isConstructor() {
    return _this.exec("isConstructor");
}

Variant ReflectionMethod::isDestructor() {
    return _this.exec("isDestructor");
}

Variant ReflectionMethod::getClosure(const Variant &object) {
    return _this.exec("getClosure", object);
}

Variant ReflectionMethod::getModifiers() {
    return _this.exec("getModifiers");
}

Variant ReflectionMethod::invoke(const Variant &object, const Variant &args) {
    return _this.exec("invoke", object, args);
}

Variant ReflectionMethod::invokeArgs(const Variant &object, const Variant &args) {
    return _this.exec("invokeArgs", object, args);
}

Variant ReflectionMethod::getDeclaringClass() {
    return _this.exec("getDeclaringClass");
}

Variant ReflectionMethod::getPrototype() {
    return _this.exec("getPrototype");
}

Variant ReflectionMethod::hasPrototype() {
    return _this.exec("hasPrototype");
}

Variant ReflectionMethod::setAccessible(const Variant &accessible) {
    return _this.exec("setAccessible", accessible);
}

Variant ReflectionMethod::inNamespace() {
    return _this.exec("inNamespace");
}

Variant ReflectionMethod::isClosure() {
    return _this.exec("isClosure");
}

Variant ReflectionMethod::isDeprecated() {
    return _this.exec("isDeprecated");
}

Variant ReflectionMethod::isInternal() {
    return _this.exec("isInternal");
}

Variant ReflectionMethod::isUserDefined() {
    return _this.exec("isUserDefined");
}

Variant ReflectionMethod::isGenerator() {
    return _this.exec("isGenerator");
}

Variant ReflectionMethod::isVariadic() {
    return _this.exec("isVariadic");
}

Variant ReflectionMethod::isStatic() {
    return _this.exec("isStatic");
}

Variant ReflectionMethod::getClosureThis() {
    return _this.exec("getClosureThis");
}

Variant ReflectionMethod::getClosureScopeClass() {
    return _this.exec("getClosureScopeClass");
}

Variant ReflectionMethod::getClosureCalledClass() {
    return _this.exec("getClosureCalledClass");
}

Variant ReflectionMethod::getClosureUsedVariables() {
    return _this.exec("getClosureUsedVariables");
}

Variant ReflectionMethod::getDocComment() {
    return _this.exec("getDocComment");
}

Variant ReflectionMethod::getEndLine() {
    return _this.exec("getEndLine");
}

Variant ReflectionMethod::getExtension() {
    return _this.exec("getExtension");
}

Variant ReflectionMethod::getExtensionName() {
    return _this.exec("getExtensionName");
}

Variant ReflectionMethod::getFileName() {
    return _this.exec("getFileName");
}

Variant ReflectionMethod::getName() {
    return _this.exec("getName");
}

Variant ReflectionMethod::getNamespaceName() {
    return _this.exec("getNamespaceName");
}

Variant ReflectionMethod::getNumberOfParameters() {
    return _this.exec("getNumberOfParameters");
}

Variant ReflectionMethod::getNumberOfRequiredParameters() {
    return _this.exec("getNumberOfRequiredParameters");
}

Variant ReflectionMethod::getParameters() {
    return _this.exec("getParameters");
}

Variant ReflectionMethod::getShortName() {
    return _this.exec("getShortName");
}

Variant ReflectionMethod::getStartLine() {
    return _this.exec("getStartLine");
}

Variant ReflectionMethod::getStaticVariables() {
    return _this.exec("getStaticVariables");
}

Variant ReflectionMethod::returnsReference() {
    return _this.exec("returnsReference");
}

Variant ReflectionMethod::hasReturnType() {
    return _this.exec("hasReturnType");
}

Variant ReflectionMethod::getReturnType() {
    return _this.exec("getReturnType");
}

Variant ReflectionMethod::hasTentativeReturnType() {
    return _this.exec("hasTentativeReturnType");
}

Variant ReflectionMethod::getTentativeReturnType() {
    return _this.exec("getTentativeReturnType");
}

Variant ReflectionMethod::getAttributes(const Variant &name, const Variant &flags) {
    return _this.exec("getAttributes", name, flags);
}


ReflectionClass::ReflectionClass(const Variant &object_or_class) {
    _this = newObject("ReflectionClass", object_or_class);
}

Variant ReflectionClass::__toString() {
    return _this.exec("__toString");
}

Variant ReflectionClass::getName() {
    return _this.exec("getName");
}

Variant ReflectionClass::isInternal() {
    return _this.exec("isInternal");
}

Variant ReflectionClass::isUserDefined() {
    return _this.exec("isUserDefined");
}

Variant ReflectionClass::isAnonymous() {
    return _this.exec("isAnonymous");
}

Variant ReflectionClass::isInstantiable() {
    return _this.exec("isInstantiable");
}

Variant ReflectionClass::isCloneable() {
    return _this.exec("isCloneable");
}

Variant ReflectionClass::getFileName() {
    return _this.exec("getFileName");
}

Variant ReflectionClass::getStartLine() {
    return _this.exec("getStartLine");
}

Variant ReflectionClass::getEndLine() {
    return _this.exec("getEndLine");
}

Variant ReflectionClass::getDocComment() {
    return _this.exec("getDocComment");
}

Variant ReflectionClass::getConstructor() {
    return _this.exec("getConstructor");
}

Variant ReflectionClass::hasMethod(const Variant &name) {
    return _this.exec("hasMethod", name);
}

Variant ReflectionClass::getMethod(const Variant &name) {
    return _this.exec("getMethod", name);
}

Variant ReflectionClass::getMethods(const Variant &filter) {
    return _this.exec("getMethods", filter);
}

Variant ReflectionClass::hasProperty(const Variant &name) {
    return _this.exec("hasProperty", name);
}

Variant ReflectionClass::getProperty(const Variant &name) {
    return _this.exec("getProperty", name);
}

Variant ReflectionClass::getProperties(const Variant &filter) {
    return _this.exec("getProperties", filter);
}

Variant ReflectionClass::hasConstant(const Variant &name) {
    return _this.exec("hasConstant", name);
}

Variant ReflectionClass::getConstants(const Variant &filter) {
    return _this.exec("getConstants", filter);
}

Variant ReflectionClass::getReflectionConstants(const Variant &filter) {
    return _this.exec("getReflectionConstants", filter);
}

Variant ReflectionClass::getConstant(const Variant &name) {
    return _this.exec("getConstant", name);
}

Variant ReflectionClass::getReflectionConstant(const Variant &name) {
    return _this.exec("getReflectionConstant", name);
}

Variant ReflectionClass::getInterfaces() {
    return _this.exec("getInterfaces");
}

Variant ReflectionClass::getInterfaceNames() {
    return _this.exec("getInterfaceNames");
}

Variant ReflectionClass::isInterface() {
    return _this.exec("isInterface");
}

Variant ReflectionClass::getTraits() {
    return _this.exec("getTraits");
}

Variant ReflectionClass::getTraitNames() {
    return _this.exec("getTraitNames");
}

Variant ReflectionClass::getTraitAliases() {
    return _this.exec("getTraitAliases");
}

Variant ReflectionClass::isTrait() {
    return _this.exec("isTrait");
}

Variant ReflectionClass::isEnum() {
    return _this.exec("isEnum");
}

Variant ReflectionClass::isAbstract() {
    return _this.exec("isAbstract");
}

Variant ReflectionClass::isFinal() {
    return _this.exec("isFinal");
}

Variant ReflectionClass::isReadOnly() {
    return _this.exec("isReadOnly");
}

Variant ReflectionClass::getModifiers() {
    return _this.exec("getModifiers");
}

Variant ReflectionClass::isInstance(const Variant &object) {
    return _this.exec("isInstance", object);
}

Variant ReflectionClass::newInstance(const Variant &args) {
    return _this.exec("newInstance", args);
}

Variant ReflectionClass::newInstanceWithoutConstructor() {
    return _this.exec("newInstanceWithoutConstructor");
}

Variant ReflectionClass::newInstanceArgs(const Array &args) {
    return _this.exec("newInstanceArgs", args);
}

Variant ReflectionClass::getParentClass() {
    return _this.exec("getParentClass");
}

Variant ReflectionClass::isSubclassOf(const Variant &_class) {
    return _this.exec("isSubclassOf", _class);
}

Variant ReflectionClass::getStaticProperties() {
    return _this.exec("getStaticProperties");
}

Variant ReflectionClass::getStaticPropertyValue(const Variant &name, const Variant &_default) {
    return _this.exec("getStaticPropertyValue", name, _default);
}

Variant ReflectionClass::setStaticPropertyValue(const Variant &name, const Variant &value) {
    return _this.exec("setStaticPropertyValue", name, value);
}

Variant ReflectionClass::getDefaultProperties() {
    return _this.exec("getDefaultProperties");
}

Variant ReflectionClass::isIterable() {
    return _this.exec("isIterable");
}

Variant ReflectionClass::isIterateable() {
    return _this.exec("isIterateable");
}

Variant ReflectionClass::implementsInterface(const Variant &interface) {
    return _this.exec("implementsInterface", interface);
}

Variant ReflectionClass::getExtension() {
    return _this.exec("getExtension");
}

Variant ReflectionClass::getExtensionName() {
    return _this.exec("getExtensionName");
}

Variant ReflectionClass::inNamespace() {
    return _this.exec("inNamespace");
}

Variant ReflectionClass::getNamespaceName() {
    return _this.exec("getNamespaceName");
}

Variant ReflectionClass::getShortName() {
    return _this.exec("getShortName");
}

Variant ReflectionClass::getAttributes(const Variant &name, const Variant &flags) {
    return _this.exec("getAttributes", name, flags);
}


ReflectionObject::ReflectionObject(const Variant &object) {
    _this = newObject("ReflectionObject", object);
}

Variant ReflectionObject::__toString() {
    return _this.exec("__toString");
}

Variant ReflectionObject::getName() {
    return _this.exec("getName");
}

Variant ReflectionObject::isInternal() {
    return _this.exec("isInternal");
}

Variant ReflectionObject::isUserDefined() {
    return _this.exec("isUserDefined");
}

Variant ReflectionObject::isAnonymous() {
    return _this.exec("isAnonymous");
}

Variant ReflectionObject::isInstantiable() {
    return _this.exec("isInstantiable");
}

Variant ReflectionObject::isCloneable() {
    return _this.exec("isCloneable");
}

Variant ReflectionObject::getFileName() {
    return _this.exec("getFileName");
}

Variant ReflectionObject::getStartLine() {
    return _this.exec("getStartLine");
}

Variant ReflectionObject::getEndLine() {
    return _this.exec("getEndLine");
}

Variant ReflectionObject::getDocComment() {
    return _this.exec("getDocComment");
}

Variant ReflectionObject::getConstructor() {
    return _this.exec("getConstructor");
}

Variant ReflectionObject::hasMethod(const Variant &name) {
    return _this.exec("hasMethod", name);
}

Variant ReflectionObject::getMethod(const Variant &name) {
    return _this.exec("getMethod", name);
}

Variant ReflectionObject::getMethods(const Variant &filter) {
    return _this.exec("getMethods", filter);
}

Variant ReflectionObject::hasProperty(const Variant &name) {
    return _this.exec("hasProperty", name);
}

Variant ReflectionObject::getProperty(const Variant &name) {
    return _this.exec("getProperty", name);
}

Variant ReflectionObject::getProperties(const Variant &filter) {
    return _this.exec("getProperties", filter);
}

Variant ReflectionObject::hasConstant(const Variant &name) {
    return _this.exec("hasConstant", name);
}

Variant ReflectionObject::getConstants(const Variant &filter) {
    return _this.exec("getConstants", filter);
}

Variant ReflectionObject::getReflectionConstants(const Variant &filter) {
    return _this.exec("getReflectionConstants", filter);
}

Variant ReflectionObject::getConstant(const Variant &name) {
    return _this.exec("getConstant", name);
}

Variant ReflectionObject::getReflectionConstant(const Variant &name) {
    return _this.exec("getReflectionConstant", name);
}

Variant ReflectionObject::getInterfaces() {
    return _this.exec("getInterfaces");
}

Variant ReflectionObject::getInterfaceNames() {
    return _this.exec("getInterfaceNames");
}

Variant ReflectionObject::isInterface() {
    return _this.exec("isInterface");
}

Variant ReflectionObject::getTraits() {
    return _this.exec("getTraits");
}

Variant ReflectionObject::getTraitNames() {
    return _this.exec("getTraitNames");
}

Variant ReflectionObject::getTraitAliases() {
    return _this.exec("getTraitAliases");
}

Variant ReflectionObject::isTrait() {
    return _this.exec("isTrait");
}

Variant ReflectionObject::isEnum() {
    return _this.exec("isEnum");
}

Variant ReflectionObject::isAbstract() {
    return _this.exec("isAbstract");
}

Variant ReflectionObject::isFinal() {
    return _this.exec("isFinal");
}

Variant ReflectionObject::isReadOnly() {
    return _this.exec("isReadOnly");
}

Variant ReflectionObject::getModifiers() {
    return _this.exec("getModifiers");
}

Variant ReflectionObject::isInstance(const Variant &object) {
    return _this.exec("isInstance", object);
}

Variant ReflectionObject::newInstance(const Variant &args) {
    return _this.exec("newInstance", args);
}

Variant ReflectionObject::newInstanceWithoutConstructor() {
    return _this.exec("newInstanceWithoutConstructor");
}

Variant ReflectionObject::newInstanceArgs(const Array &args) {
    return _this.exec("newInstanceArgs", args);
}

Variant ReflectionObject::getParentClass() {
    return _this.exec("getParentClass");
}

Variant ReflectionObject::isSubclassOf(const Variant &_class) {
    return _this.exec("isSubclassOf", _class);
}

Variant ReflectionObject::getStaticProperties() {
    return _this.exec("getStaticProperties");
}

Variant ReflectionObject::getStaticPropertyValue(const Variant &name, const Variant &_default) {
    return _this.exec("getStaticPropertyValue", name, _default);
}

Variant ReflectionObject::setStaticPropertyValue(const Variant &name, const Variant &value) {
    return _this.exec("setStaticPropertyValue", name, value);
}

Variant ReflectionObject::getDefaultProperties() {
    return _this.exec("getDefaultProperties");
}

Variant ReflectionObject::isIterable() {
    return _this.exec("isIterable");
}

Variant ReflectionObject::isIterateable() {
    return _this.exec("isIterateable");
}

Variant ReflectionObject::implementsInterface(const Variant &interface) {
    return _this.exec("implementsInterface", interface);
}

Variant ReflectionObject::getExtension() {
    return _this.exec("getExtension");
}

Variant ReflectionObject::getExtensionName() {
    return _this.exec("getExtensionName");
}

Variant ReflectionObject::inNamespace() {
    return _this.exec("inNamespace");
}

Variant ReflectionObject::getNamespaceName() {
    return _this.exec("getNamespaceName");
}

Variant ReflectionObject::getShortName() {
    return _this.exec("getShortName");
}

Variant ReflectionObject::getAttributes(const Variant &name, const Variant &flags) {
    return _this.exec("getAttributes", name, flags);
}


ReflectionProperty::ReflectionProperty(const Variant &_class, const Variant &property) {
    _this = newObject("ReflectionProperty", _class, property);
}

Variant ReflectionProperty::__toString() {
    return _this.exec("__toString");
}

Variant ReflectionProperty::getName() {
    return _this.exec("getName");
}

Variant ReflectionProperty::getValue(const Variant &object) {
    return _this.exec("getValue", object);
}

Variant ReflectionProperty::setValue(const Variant &object_or_value, const Variant &value) {
    return _this.exec("setValue", object_or_value, value);
}

Variant ReflectionProperty::isInitialized(const Variant &object) {
    return _this.exec("isInitialized", object);
}

Variant ReflectionProperty::isPublic() {
    return _this.exec("isPublic");
}

Variant ReflectionProperty::isPrivate() {
    return _this.exec("isPrivate");
}

Variant ReflectionProperty::isProtected() {
    return _this.exec("isProtected");
}

Variant ReflectionProperty::isStatic() {
    return _this.exec("isStatic");
}

Variant ReflectionProperty::isReadOnly() {
    return _this.exec("isReadOnly");
}

Variant ReflectionProperty::isDefault() {
    return _this.exec("isDefault");
}

Variant ReflectionProperty::isPromoted() {
    return _this.exec("isPromoted");
}

Variant ReflectionProperty::getModifiers() {
    return _this.exec("getModifiers");
}

Variant ReflectionProperty::getDeclaringClass() {
    return _this.exec("getDeclaringClass");
}

Variant ReflectionProperty::getDocComment() {
    return _this.exec("getDocComment");
}

Variant ReflectionProperty::setAccessible(const Variant &accessible) {
    return _this.exec("setAccessible", accessible);
}

Variant ReflectionProperty::getType() {
    return _this.exec("getType");
}

Variant ReflectionProperty::hasType() {
    return _this.exec("hasType");
}

Variant ReflectionProperty::hasDefaultValue() {
    return _this.exec("hasDefaultValue");
}

Variant ReflectionProperty::getDefaultValue() {
    return _this.exec("getDefaultValue");
}

Variant ReflectionProperty::getAttributes(const Variant &name, const Variant &flags) {
    return _this.exec("getAttributes", name, flags);
}


ReflectionClassConstant::ReflectionClassConstant(const Variant &_class, const Variant &constant) {
    _this = newObject("ReflectionClassConstant", _class, constant);
}

Variant ReflectionClassConstant::__toString() {
    return _this.exec("__toString");
}

Variant ReflectionClassConstant::getName() {
    return _this.exec("getName");
}

Variant ReflectionClassConstant::getValue() {
    return _this.exec("getValue");
}

Variant ReflectionClassConstant::isPublic() {
    return _this.exec("isPublic");
}

Variant ReflectionClassConstant::isPrivate() {
    return _this.exec("isPrivate");
}

Variant ReflectionClassConstant::isProtected() {
    return _this.exec("isProtected");
}

Variant ReflectionClassConstant::isFinal() {
    return _this.exec("isFinal");
}

Variant ReflectionClassConstant::getModifiers() {
    return _this.exec("getModifiers");
}

Variant ReflectionClassConstant::getDeclaringClass() {
    return _this.exec("getDeclaringClass");
}

Variant ReflectionClassConstant::getDocComment() {
    return _this.exec("getDocComment");
}

Variant ReflectionClassConstant::getAttributes(const Variant &name, const Variant &flags) {
    return _this.exec("getAttributes", name, flags);
}

Variant ReflectionClassConstant::isEnumCase() {
    return _this.exec("isEnumCase");
}


ReflectionExtension::ReflectionExtension(const Variant &name) {
    _this = newObject("ReflectionExtension", name);
}

Variant ReflectionExtension::__toString() {
    return _this.exec("__toString");
}

Variant ReflectionExtension::getName() {
    return _this.exec("getName");
}

Variant ReflectionExtension::getVersion() {
    return _this.exec("getVersion");
}

Variant ReflectionExtension::getFunctions() {
    return _this.exec("getFunctions");
}

Variant ReflectionExtension::getConstants() {
    return _this.exec("getConstants");
}

Variant ReflectionExtension::getINIEntries() {
    return _this.exec("getINIEntries");
}

Variant ReflectionExtension::getClasses() {
    return _this.exec("getClasses");
}

Variant ReflectionExtension::getClassNames() {
    return _this.exec("getClassNames");
}

Variant ReflectionExtension::getDependencies() {
    return _this.exec("getDependencies");
}

Variant ReflectionExtension::info() {
    return _this.exec("info");
}

Variant ReflectionExtension::isPersistent() {
    return _this.exec("isPersistent");
}

Variant ReflectionExtension::isTemporary() {
    return _this.exec("isTemporary");
}


ReflectionZendExtension::ReflectionZendExtension(const Variant &name) {
    _this = newObject("ReflectionZendExtension", name);
}

Variant ReflectionZendExtension::__toString() {
    return _this.exec("__toString");
}

Variant ReflectionZendExtension::getName() {
    return _this.exec("getName");
}

Variant ReflectionZendExtension::getVersion() {
    return _this.exec("getVersion");
}

Variant ReflectionZendExtension::getAuthor() {
    return _this.exec("getAuthor");
}

Variant ReflectionZendExtension::getURL() {
    return _this.exec("getURL");
}

Variant ReflectionZendExtension::getCopyright() {
    return _this.exec("getCopyright");
}


Variant ReflectionReference::fromArrayElement(const Variant &array, const Variant &key) {
    static Variant fn { ZEND_STRL("ReflectionReference::fromArrayElement"), true };
    return fn(array, key);
}

Variant ReflectionReference::getId() {
    return _this.exec("getId");
}


Variant ReflectionAttribute::getName() {
    return _this.exec("getName");
}

Variant ReflectionAttribute::getTarget() {
    return _this.exec("getTarget");
}

Variant ReflectionAttribute::isRepeated() {
    return _this.exec("isRepeated");
}

Variant ReflectionAttribute::getArguments() {
    return _this.exec("getArguments");
}

Variant ReflectionAttribute::newInstance() {
    return _this.exec("newInstance");
}

Variant ReflectionAttribute::__toString() {
    return _this.exec("__toString");
}


ReflectionEnum::ReflectionEnum(const Variant &object_or_class) {
    _this = newObject("ReflectionEnum", object_or_class);
}

Variant ReflectionEnum::hasCase(const Variant &name) {
    return _this.exec("hasCase", name);
}

Variant ReflectionEnum::getCase(const Variant &name) {
    return _this.exec("getCase", name);
}

Variant ReflectionEnum::getCases() {
    return _this.exec("getCases");
}

Variant ReflectionEnum::isBacked() {
    return _this.exec("isBacked");
}

Variant ReflectionEnum::getBackingType() {
    return _this.exec("getBackingType");
}

Variant ReflectionEnum::__toString() {
    return _this.exec("__toString");
}

Variant ReflectionEnum::getName() {
    return _this.exec("getName");
}

Variant ReflectionEnum::isInternal() {
    return _this.exec("isInternal");
}

Variant ReflectionEnum::isUserDefined() {
    return _this.exec("isUserDefined");
}

Variant ReflectionEnum::isAnonymous() {
    return _this.exec("isAnonymous");
}

Variant ReflectionEnum::isInstantiable() {
    return _this.exec("isInstantiable");
}

Variant ReflectionEnum::isCloneable() {
    return _this.exec("isCloneable");
}

Variant ReflectionEnum::getFileName() {
    return _this.exec("getFileName");
}

Variant ReflectionEnum::getStartLine() {
    return _this.exec("getStartLine");
}

Variant ReflectionEnum::getEndLine() {
    return _this.exec("getEndLine");
}

Variant ReflectionEnum::getDocComment() {
    return _this.exec("getDocComment");
}

Variant ReflectionEnum::getConstructor() {
    return _this.exec("getConstructor");
}

Variant ReflectionEnum::hasMethod(const Variant &name) {
    return _this.exec("hasMethod", name);
}

Variant ReflectionEnum::getMethod(const Variant &name) {
    return _this.exec("getMethod", name);
}

Variant ReflectionEnum::getMethods(const Variant &filter) {
    return _this.exec("getMethods", filter);
}

Variant ReflectionEnum::hasProperty(const Variant &name) {
    return _this.exec("hasProperty", name);
}

Variant ReflectionEnum::getProperty(const Variant &name) {
    return _this.exec("getProperty", name);
}

Variant ReflectionEnum::getProperties(const Variant &filter) {
    return _this.exec("getProperties", filter);
}

Variant ReflectionEnum::hasConstant(const Variant &name) {
    return _this.exec("hasConstant", name);
}

Variant ReflectionEnum::getConstants(const Variant &filter) {
    return _this.exec("getConstants", filter);
}

Variant ReflectionEnum::getReflectionConstants(const Variant &filter) {
    return _this.exec("getReflectionConstants", filter);
}

Variant ReflectionEnum::getConstant(const Variant &name) {
    return _this.exec("getConstant", name);
}

Variant ReflectionEnum::getReflectionConstant(const Variant &name) {
    return _this.exec("getReflectionConstant", name);
}

Variant ReflectionEnum::getInterfaces() {
    return _this.exec("getInterfaces");
}

Variant ReflectionEnum::getInterfaceNames() {
    return _this.exec("getInterfaceNames");
}

Variant ReflectionEnum::isInterface() {
    return _this.exec("isInterface");
}

Variant ReflectionEnum::getTraits() {
    return _this.exec("getTraits");
}

Variant ReflectionEnum::getTraitNames() {
    return _this.exec("getTraitNames");
}

Variant ReflectionEnum::getTraitAliases() {
    return _this.exec("getTraitAliases");
}

Variant ReflectionEnum::isTrait() {
    return _this.exec("isTrait");
}

Variant ReflectionEnum::isEnum() {
    return _this.exec("isEnum");
}

Variant ReflectionEnum::isAbstract() {
    return _this.exec("isAbstract");
}

Variant ReflectionEnum::isFinal() {
    return _this.exec("isFinal");
}

Variant ReflectionEnum::isReadOnly() {
    return _this.exec("isReadOnly");
}

Variant ReflectionEnum::getModifiers() {
    return _this.exec("getModifiers");
}

Variant ReflectionEnum::isInstance(const Variant &object) {
    return _this.exec("isInstance", object);
}

Variant ReflectionEnum::newInstance(const Variant &args) {
    return _this.exec("newInstance", args);
}

Variant ReflectionEnum::newInstanceWithoutConstructor() {
    return _this.exec("newInstanceWithoutConstructor");
}

Variant ReflectionEnum::newInstanceArgs(const Array &args) {
    return _this.exec("newInstanceArgs", args);
}

Variant ReflectionEnum::getParentClass() {
    return _this.exec("getParentClass");
}

Variant ReflectionEnum::isSubclassOf(const Variant &_class) {
    return _this.exec("isSubclassOf", _class);
}

Variant ReflectionEnum::getStaticProperties() {
    return _this.exec("getStaticProperties");
}

Variant ReflectionEnum::getStaticPropertyValue(const Variant &name, const Variant &_default) {
    return _this.exec("getStaticPropertyValue", name, _default);
}

Variant ReflectionEnum::setStaticPropertyValue(const Variant &name, const Variant &value) {
    return _this.exec("setStaticPropertyValue", name, value);
}

Variant ReflectionEnum::getDefaultProperties() {
    return _this.exec("getDefaultProperties");
}

Variant ReflectionEnum::isIterable() {
    return _this.exec("isIterable");
}

Variant ReflectionEnum::isIterateable() {
    return _this.exec("isIterateable");
}

Variant ReflectionEnum::implementsInterface(const Variant &interface) {
    return _this.exec("implementsInterface", interface);
}

Variant ReflectionEnum::getExtension() {
    return _this.exec("getExtension");
}

Variant ReflectionEnum::getExtensionName() {
    return _this.exec("getExtensionName");
}

Variant ReflectionEnum::inNamespace() {
    return _this.exec("inNamespace");
}

Variant ReflectionEnum::getNamespaceName() {
    return _this.exec("getNamespaceName");
}

Variant ReflectionEnum::getShortName() {
    return _this.exec("getShortName");
}

Variant ReflectionEnum::getAttributes(const Variant &name, const Variant &flags) {
    return _this.exec("getAttributes", name, flags);
}


ReflectionEnumUnitCase::ReflectionEnumUnitCase(const Variant &_class, const Variant &constant) {
    _this = newObject("ReflectionEnumUnitCase", _class, constant);
}

Variant ReflectionEnumUnitCase::getEnum() {
    return _this.exec("getEnum");
}

Variant ReflectionEnumUnitCase::getValue() {
    return _this.exec("getValue");
}

Variant ReflectionEnumUnitCase::__toString() {
    return _this.exec("__toString");
}

Variant ReflectionEnumUnitCase::getName() {
    return _this.exec("getName");
}

Variant ReflectionEnumUnitCase::isPublic() {
    return _this.exec("isPublic");
}

Variant ReflectionEnumUnitCase::isPrivate() {
    return _this.exec("isPrivate");
}

Variant ReflectionEnumUnitCase::isProtected() {
    return _this.exec("isProtected");
}

Variant ReflectionEnumUnitCase::isFinal() {
    return _this.exec("isFinal");
}

Variant ReflectionEnumUnitCase::getModifiers() {
    return _this.exec("getModifiers");
}

Variant ReflectionEnumUnitCase::getDeclaringClass() {
    return _this.exec("getDeclaringClass");
}

Variant ReflectionEnumUnitCase::getDocComment() {
    return _this.exec("getDocComment");
}

Variant ReflectionEnumUnitCase::getAttributes(const Variant &name, const Variant &flags) {
    return _this.exec("getAttributes", name, flags);
}

Variant ReflectionEnumUnitCase::isEnumCase() {
    return _this.exec("isEnumCase");
}


ReflectionEnumBackedCase::ReflectionEnumBackedCase(const Variant &_class, const Variant &constant) {
    _this = newObject("ReflectionEnumBackedCase", _class, constant);
}

Variant ReflectionEnumBackedCase::getBackingValue() {
    return _this.exec("getBackingValue");
}

Variant ReflectionEnumBackedCase::getEnum() {
    return _this.exec("getEnum");
}

Variant ReflectionEnumBackedCase::getValue() {
    return _this.exec("getValue");
}

Variant ReflectionEnumBackedCase::__toString() {
    return _this.exec("__toString");
}

Variant ReflectionEnumBackedCase::getName() {
    return _this.exec("getName");
}

Variant ReflectionEnumBackedCase::isPublic() {
    return _this.exec("isPublic");
}

Variant ReflectionEnumBackedCase::isPrivate() {
    return _this.exec("isPrivate");
}

Variant ReflectionEnumBackedCase::isProtected() {
    return _this.exec("isProtected");
}

Variant ReflectionEnumBackedCase::isFinal() {
    return _this.exec("isFinal");
}

Variant ReflectionEnumBackedCase::getModifiers() {
    return _this.exec("getModifiers");
}

Variant ReflectionEnumBackedCase::getDeclaringClass() {
    return _this.exec("getDeclaringClass");
}

Variant ReflectionEnumBackedCase::getDocComment() {
    return _this.exec("getDocComment");
}

Variant ReflectionEnumBackedCase::getAttributes(const Variant &name, const Variant &flags) {
    return _this.exec("getAttributes", name, flags);
}

Variant ReflectionEnumBackedCase::isEnumCase() {
    return _this.exec("isEnumCase");
}


ReflectionFiber::ReflectionFiber(const Variant &fiber) {
    _this = newObject("ReflectionFiber", fiber);
}

Variant ReflectionFiber::getFiber() {
    return _this.exec("getFiber");
}

Variant ReflectionFiber::getExecutingFile() {
    return _this.exec("getExecutingFile");
}

Variant ReflectionFiber::getExecutingLine() {
    return _this.exec("getExecutingLine");
}

Variant ReflectionFiber::getCallable() {
    return _this.exec("getCallable");
}

Variant ReflectionFiber::getTrace(const Variant &options) {
    return _this.exec("getTrace", options);
}


}

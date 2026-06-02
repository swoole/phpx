#pragma once

#include "phpx.h"
#include "phpx_literal_string.h"
#include "class/core.h"

namespace php {
class ReflectionException;
class Reflection;
class ReflectionGenerator;
class ReflectionNamedType;
class ReflectionUnionType;
class ReflectionIntersectionType;
class ReflectionExtension;
class ReflectionZendExtension;
class ReflectionReference;
class ReflectionAttribute;
class ReflectionFiber;
class ReflectionConstant;
class PropertyHookType;
class ReflectionFunction;
class ReflectionParameter;
class ReflectionMethod;
class ReflectionProperty;
class ReflectionClass;
class ReflectionClassConstant;
class ReflectionObject;
class ReflectionEnum;
class ReflectionEnumUnitCase;
class ReflectionEnumBackedCase;

class ReflectionException : public Exception {
  public:
    ReflectionException(const Variant &message = "", const Variant &code = 0, const Variant &previous = nullptr);
};

class Reflection {
  protected:
    Object this_;

  public:
    Object getObject() const {
        return this_;
    }
    explicit Reflection(const Object &obj) : this_(obj) {}
    Reflection();
    static Variant getModifierNames(const Variant &modifiers);
};

class ReflectionGenerator {
  protected:
    Object this_;
    ReflectionGenerator() = default;

  public:
    Object getObject() const {
        return this_;
    }
    ReflectionGenerator(const Generator &generator);
    Variant getExecutingLine();
    Variant getExecutingFile();
    Variant getTrace(const Variant &options = 1);
    Variant getFunction();
    Variant getThis_();
    Generator getExecutingGenerator();
    Variant isClosed();
};

class ReflectionNamedType {
  protected:
    Object this_;

  public:
    Object getObject() const {
        return this_;
    }
    explicit ReflectionNamedType(const Object &obj) : this_(obj) {}
    ReflectionNamedType();
    Variant getName();
    Variant isBuiltin();
    Variant allowsNull();
    Variant __toString();
};

class ReflectionUnionType {
  protected:
    Object this_;

  public:
    Object getObject() const {
        return this_;
    }
    explicit ReflectionUnionType(const Object &obj) : this_(obj) {}
    ReflectionUnionType();
    Variant getTypes();
    Variant allowsNull();
    Variant __toString();
};

class ReflectionIntersectionType {
  protected:
    Object this_;

  public:
    Object getObject() const {
        return this_;
    }
    explicit ReflectionIntersectionType(const Object &obj) : this_(obj) {}
    ReflectionIntersectionType();
    Variant getTypes();
    Variant allowsNull();
    Variant __toString();
};

class ReflectionExtension {
  protected:
    Object this_;
    ReflectionExtension() = default;

  public:
    Object getObject() const {
        return this_;
    }
    ReflectionExtension(const Variant &name);
    Variant __toString();
    Variant getName();
    Variant getVersion();
    Variant getFunctions();
    Variant getConstants();
    Variant getINIEntries();
    Variant getClasses();
    Variant getClassNames();
    Variant getDependencies();
    Variant info();
    Variant isPersistent();
    Variant isTemporary();
};

class ReflectionZendExtension {
  protected:
    Object this_;
    ReflectionZendExtension() = default;

  public:
    Object getObject() const {
        return this_;
    }
    ReflectionZendExtension(const Variant &name);
    Variant __toString();
    Variant getName();
    Variant getVersion();
    Variant getAuthor();
    Variant getURL();
    Variant getCopyright();
};

class ReflectionReference {
  protected:
    Object this_;

  public:
    Object getObject() const {
        return this_;
    }
    static Variant fromArrayElement(const Variant &array, const Variant &key);
    Variant getId();
};

class ReflectionAttribute {
  protected:
    Object this_;

  public:
    Object getObject() const {
        return this_;
    }
    static constexpr zend_long IS_INSTANCEOF = 2;

    Variant getName();
    Variant getTarget();
    Variant isRepeated();
    Variant getArguments();
    Variant newInstance();
    Variant __toString();
};

class ReflectionFiber {
  protected:
    Object this_;
    ReflectionFiber() = default;

  public:
    Object getObject() const {
        return this_;
    }
    ReflectionFiber(const Fiber &fiber);
    Variant getFiber();
    Variant getExecutingFile();
    Variant getExecutingLine();
    Variant getCallable();
    Variant getTrace(const Variant &options = 1);
};

class ReflectionConstant {
  protected:
    Object this_;
    ReflectionConstant() = default;

  public:
    Object getObject() const {
        return this_;
    }
    ReflectionConstant(const Variant &name);
    Variant getName();
    Variant getNamespaceName();
    Variant getShortName();
    Variant getValue();
    Variant isDeprecated();
    Variant __toString();
};

class PropertyHookType {
  protected:
    Object this_;

  public:
    Object getObject() const {
        return this_;
    }
    explicit PropertyHookType(const Object &obj) : this_(obj) {}
    PropertyHookType();
    static Variant cases();
    static Variant from(const Variant &value);
    static Variant tryFrom(const Variant &value);
};

class ReflectionFunction {
  protected:
    Object this_;
    ReflectionFunction() = default;

  public:
    Object getObject() const {
        return this_;
    }
    static constexpr zend_long IS_DEPRECATED = 2048;

    ReflectionFunction(const Variant &function);
    Variant __toString();
    Variant isAnonymous();
    Variant isDisabled();
    template <typename... Args>
    Variant invoke(const Args &...args) {
        static THREAD_LOCAL zend_function *_method_fn = nullptr;
        if (UNEXPECTED(!_method_fn)) {
            _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1636]);
        }
        return this_.call(_method_fn, {args...});
    }
    Variant invokeArgs(const Variant &args);
    Variant getClosure();
    Variant inNamespace();
    Variant isClosure();
    Variant isDeprecated();
    Variant isInternal();
    Variant isUserDefined();
    Variant isGenerator();
    Variant isVariadic();
    Variant isStatic();
    Variant getClosureThis();
    Variant getClosureScopeClass();
    Variant getClosureCalledClass();
    Variant getClosureUsedVariables();
    Variant getDocComment();
    Variant getEndLine();
    Variant getExtension();
    Variant getExtensionName();
    Variant getFileName();
    Variant getName();
    Variant getNamespaceName();
    Variant getNumberOfParameters();
    Variant getNumberOfRequiredParameters();
    Variant getParameters();
    Variant getShortName();
    Variant getStartLine();
    Variant getStaticVariables();
    Variant returnsReference();
    Variant hasReturnType();
    Variant getReturnType();
    Variant hasTentativeReturnType();
    Variant getTentativeReturnType();
    Variant getAttributes(const Variant &name = nullptr, const Variant &flags = 0);
};

class ReflectionParameter {
  protected:
    Object this_;
    ReflectionParameter() = default;

  public:
    Object getObject() const {
        return this_;
    }
    ReflectionParameter(const Variant &function, const Variant &param);
    Variant __toString();
    Variant getName();
    Variant isPassedByReference();
    Variant canBePassedByValue();
    Variant getDeclaringFunction();
    Variant getDeclaringClass();
    Variant getClass();
    Variant hasType();
    Variant getType();
    Variant isArray();
    Variant isCallable();
    Variant allowsNull();
    Variant getPosition();
    Variant isOptional();
    Variant isDefaultValueAvailable();
    Variant getDefaultValue();
    Variant isDefaultValueConstant();
    Variant getDefaultValueConstantName();
    Variant isVariadic();
    Variant isPromoted();
    Variant getAttributes(const Variant &name = nullptr, const Variant &flags = 0);
};

class ReflectionMethod {
  protected:
    Object this_;
    ReflectionMethod() = default;

  public:
    Object getObject() const {
        return this_;
    }
    static constexpr zend_long IS_STATIC_ = 16;
    static constexpr zend_long IS_PUBLIC = 1;
    static constexpr zend_long IS_PROTECTED = 2;
    static constexpr zend_long IS_PRIVATE = 4;
    static constexpr zend_long IS_ABSTRACT = 64;
    static constexpr zend_long IS_FINAL = 32;

    ReflectionMethod(const Variant &object_or_method, const Variant &method = nullptr);
    static Variant createFromMethodName(const Variant &method);
    Variant __toString();
    Variant isPublic();
    Variant isPrivate();
    Variant isProtected();
    Variant isAbstract();
    Variant isFinal();
    Variant isConstructor();
    Variant isDestructor();
    Variant getClosure(const Variant &object = nullptr);
    Variant getModifiers();
    template <typename... Args>
    Variant invoke(const Variant &object, const Args &...args) {
        static THREAD_LOCAL zend_function *_method_fn = nullptr;
        if (UNEXPECTED(!_method_fn)) {
            _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1636]);
        }
        return this_.call(_method_fn, {object, args...});
    }
    Variant invokeArgs(const Variant &object, const Variant &args);
    Variant getDeclaringClass();
    Variant getPrototype();
    Variant hasPrototype();
    Variant setAccessible(const Variant &accessible);
    Variant inNamespace();
    Variant isClosure();
    Variant isDeprecated();
    Variant isInternal();
    Variant isUserDefined();
    Variant isGenerator();
    Variant isVariadic();
    Variant isStatic();
    Variant getClosureThis();
    Variant getClosureScopeClass();
    Variant getClosureCalledClass();
    Variant getClosureUsedVariables();
    Variant getDocComment();
    Variant getEndLine();
    Variant getExtension();
    Variant getExtensionName();
    Variant getFileName();
    Variant getName();
    Variant getNamespaceName();
    Variant getNumberOfParameters();
    Variant getNumberOfRequiredParameters();
    Variant getParameters();
    Variant getShortName();
    Variant getStartLine();
    Variant getStaticVariables();
    Variant returnsReference();
    Variant hasReturnType();
    Variant getReturnType();
    Variant hasTentativeReturnType();
    Variant getTentativeReturnType();
    Variant getAttributes(const Variant &name = nullptr, const Variant &flags = 0);
};

class ReflectionProperty {
  protected:
    Object this_;
    ReflectionProperty() = default;

  public:
    Object getObject() const {
        return this_;
    }
    static constexpr zend_long IS_STATIC_ = 16;
    static constexpr zend_long IS_READONLY = 128;
    static constexpr zend_long IS_PUBLIC = 1;
    static constexpr zend_long IS_PROTECTED = 2;
    static constexpr zend_long IS_PRIVATE = 4;
    static constexpr zend_long IS_ABSTRACT = 64;
    static constexpr zend_long IS_PROTECTED_SET = 2048;
    static constexpr zend_long IS_PRIVATE_SET = 4096;
    static constexpr zend_long IS_VIRTUAL = 512;
    static constexpr zend_long IS_FINAL = 32;

    ReflectionProperty(const Variant &class_, const Variant &property);
    Variant __toString();
    Variant getName();
    Variant getValue(const Variant &object = nullptr);
    Variant setValue(const Variant &object_or_value, const Variant &value = {});
    Variant getRawValue(const Variant &object);
    Variant setRawValue(const Variant &object, const Variant &value);
    Variant setRawValueWithoutLazyInitialization(const Variant &object, const Variant &value);
    Variant skipLazyInitialization(const Variant &object);
    Variant isLazy(const Variant &object);
    Variant isInitialized(const Variant &object = nullptr);
    Variant isPublic();
    Variant isPrivate();
    Variant isProtected();
    Variant isPrivateSet();
    Variant isProtectedSet();
    Variant isStatic();
    Variant isReadOnly();
    Variant isDefault();
    Variant isDynamic();
    Variant isAbstract();
    Variant isVirtual();
    Variant isPromoted();
    Variant getModifiers();
    Variant getDeclaringClass();
    Variant getDocComment();
    Variant setAccessible(const Variant &accessible);
    Variant getType();
    Variant getSettableType();
    Variant hasType();
    Variant hasDefaultValue();
    Variant getDefaultValue();
    Variant getAttributes(const Variant &name = nullptr, const Variant &flags = 0);
    Variant hasHooks();
    Variant getHooks();
    Variant hasHook(const PropertyHookType &type);
    Variant hasHook(const Variant &type);
    Variant getHook(const PropertyHookType &type);
    Variant getHook(const Variant &type);
    Variant isFinal();
};

class ReflectionClass {
  protected:
    Object this_;
    ReflectionClass() = default;

  public:
    Object getObject() const {
        return this_;
    }
    static constexpr zend_long IS_IMPLICIT_ABSTRACT = 16;
    static constexpr zend_long IS_EXPLICIT_ABSTRACT = 64;
    static constexpr zend_long IS_FINAL = 32;
    static constexpr zend_long IS_READONLY = 65536;
    static constexpr zend_long SKIP_INITIALIZATION_ON_SERIALIZE = 8;
    static constexpr zend_long SKIP_DESTRUCTOR = 16;

    ReflectionClass(const Variant &object_or_class);
    Variant __toString();
    Variant getName();
    Variant isInternal();
    Variant isUserDefined();
    Variant isAnonymous();
    Variant isInstantiable();
    Variant isCloneable();
    Variant getFileName();
    Variant getStartLine();
    Variant getEndLine();
    Variant getDocComment();
    Variant getConstructor();
    Variant hasMethod(const Variant &name);
    Variant getMethod(const Variant &name);
    Variant getMethods(const Variant &filter = nullptr);
    Variant hasProperty(const Variant &name);
    Variant getProperty(const Variant &name);
    Variant getProperties(const Variant &filter = nullptr);
    Variant hasConstant(const Variant &name);
    Variant getConstants(const Variant &filter = nullptr);
    Variant getReflectionConstants(const Variant &filter = nullptr);
    Variant getConstant(const Variant &name);
    Variant getReflectionConstant(const Variant &name);
    Variant getInterfaces();
    Variant getInterfaceNames();
    Variant isInterface();
    Variant getTraits();
    Variant getTraitNames();
    Variant getTraitAliases();
    Variant isTrait();
    Variant isEnum();
    Variant isAbstract();
    Variant isFinal();
    Variant isReadOnly();
    Variant getModifiers();
    Variant isInstance(const Variant &object);
    template <typename... Args>
    Variant newInstance(const Args &...args) {
        static THREAD_LOCAL zend_function *_method_fn = nullptr;
        if (UNEXPECTED(!_method_fn)) {
            _method_fn = php::getMethod(this_.ce(), LITERAL_STRING[1738]);
        }
        return this_.call(_method_fn, {args...});
    }
    Variant newInstanceWithoutConstructor();
    Variant newInstanceArgs(const Variant &args = Array{});
    Variant newLazyGhost(const Variant &initializer, const Variant &options = 0);
    Variant newLazyProxy(const Variant &factory, const Variant &options = 0);
    Variant resetAsLazyGhost(const Variant &object, const Variant &initializer, const Variant &options = 0);
    Variant resetAsLazyProxy(const Variant &object, const Variant &factory, const Variant &options = 0);
    Variant initializeLazyObject(const Variant &object);
    Variant isUninitializedLazyObject(const Variant &object);
    Variant markLazyObjectAsInitialized(const Variant &object);
    Variant getLazyInitializer(const Variant &object);
    Variant getParentClass();
    Variant isSubclassOf(const Variant &class_);
    Variant getStaticProperties();
    Variant getStaticPropertyValue(const Variant &name, const Variant &default_ = {});
    Variant setStaticPropertyValue(const Variant &name, const Variant &value);
    Variant getDefaultProperties();
    Variant isIterable();
    Variant isIterateable();
    Variant implementsInterface(const Variant &interface);
    Variant getExtension();
    Variant getExtensionName();
    Variant inNamespace();
    Variant getNamespaceName();
    Variant getShortName();
    Variant getAttributes(const Variant &name = nullptr, const Variant &flags = 0);
};

class ReflectionClassConstant {
  protected:
    Object this_;
    ReflectionClassConstant() = default;

  public:
    Object getObject() const {
        return this_;
    }
    static constexpr zend_long IS_PUBLIC = 1;
    static constexpr zend_long IS_PROTECTED = 2;
    static constexpr zend_long IS_PRIVATE = 4;
    static constexpr zend_long IS_FINAL = 32;

    ReflectionClassConstant(const Variant &class_, const Variant &constant);
    Variant __toString();
    Variant getName();
    Variant getValue();
    Variant isPublic();
    Variant isPrivate();
    Variant isProtected();
    Variant isFinal();
    Variant getModifiers();
    Variant getDeclaringClass();
    Variant getDocComment();
    Variant getAttributes(const Variant &name = nullptr, const Variant &flags = 0);
    Variant isEnumCase();
    Variant isDeprecated();
    Variant hasType();
    Variant getType();
};

class ReflectionObject : public ReflectionClass {
  protected:
    ReflectionObject() = default;

  public:
    ReflectionObject(const Variant &object);
};

class ReflectionEnum : public ReflectionClass {
  protected:
    ReflectionEnum() = default;

  public:
    ReflectionEnum(const Variant &object_or_class);
    Variant hasCase(const Variant &name);
    Variant getCase(const Variant &name);
    Variant getCases();
    Variant isBacked();
    ReflectionNamedType getBackingType();
};

class ReflectionEnumUnitCase : public ReflectionClassConstant {
  protected:
    ReflectionEnumUnitCase() = default;

  public:
    ReflectionEnumUnitCase(const Variant &class_, const Variant &constant);
    Variant getEnum();
    Variant getValue();
};

class ReflectionEnumBackedCase : public ReflectionEnumUnitCase {
  protected:
    ReflectionEnumBackedCase() = default;

  public:
    ReflectionEnumBackedCase(const Variant &class_, const Variant &constant);
    Variant getBackingValue();
};

}  // namespace php

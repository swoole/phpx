namespace php {
class ReflectionException {
    Object _this;
  public:
    ReflectionException(const Variant &message = "", const Variant &code = 0, const Variant &previous = {});
    Variant __wakeup();
    Variant getMessage();
    Variant getCode();
    Variant getFile();
    Variant getLine();
    Variant getTrace();
    Variant getPrevious();
    Variant getTraceAsString();
    Variant __toString();
};

class Reflection {
    Object _this;
  public:
    static Variant getModifierNames(const Variant &modifiers);
};

class ReflectionFunction {
    Object _this;
  public:
    ReflectionFunction(const Variant &function);
    Variant __toString();
    Variant isAnonymous();
    Variant isDisabled();
    Variant invoke(const Variant &args = {});
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
    Variant getAttributes(const Variant &name = {}, const Variant &flags = 0);
};

class ReflectionGenerator {
    Object _this;
  public:
    ReflectionGenerator(const Variant &generator);
    Variant getExecutingLine();
    Variant getExecutingFile();
    Variant getTrace(const Variant &options = 1);
    Variant getFunction();
    Variant _getThis();
    Variant getExecutingGenerator();
};

class ReflectionParameter {
    Object _this;
  public:
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
    Variant getAttributes(const Variant &name = {}, const Variant &flags = 0);
};

class ReflectionNamedType {
    Object _this;
  public:
    Variant getName();
    Variant isBuiltin();
    Variant allowsNull();
    Variant __toString();
};

class ReflectionUnionType {
    Object _this;
  public:
    Variant getTypes();
    Variant allowsNull();
    Variant __toString();
};

class ReflectionIntersectionType {
    Object _this;
  public:
    Variant getTypes();
    Variant allowsNull();
    Variant __toString();
};

class ReflectionMethod {
    Object _this;
  public:
    ReflectionMethod(const Variant &object_or_method, const Variant &method = {});
    Variant __toString();
    Variant isPublic();
    Variant isPrivate();
    Variant isProtected();
    Variant isAbstract();
    Variant isFinal();
    Variant isConstructor();
    Variant isDestructor();
    Variant getClosure(const Variant &object = {});
    Variant getModifiers();
    Variant invoke(const Variant &object, const Variant &args = {});
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
    Variant getAttributes(const Variant &name = {}, const Variant &flags = 0);
};

class ReflectionClass {
    Object _this;
  public:
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
    Variant getMethods(const Variant &filter = {});
    Variant hasProperty(const Variant &name);
    Variant getProperty(const Variant &name);
    Variant getProperties(const Variant &filter = {});
    Variant hasConstant(const Variant &name);
    Variant getConstants(const Variant &filter = {});
    Variant getReflectionConstants(const Variant &filter = {});
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
    Variant newInstance(const Variant &args = {});
    Variant newInstanceWithoutConstructor();
    Variant newInstanceArgs(const Array &args = {});
    Variant getParentClass();
    Variant isSubclassOf(const Variant &_class);
    Variant getStaticProperties();
    Variant getStaticPropertyValue(const Variant &name, const Variant &_default = {});
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
    Variant getAttributes(const Variant &name = {}, const Variant &flags = 0);
};

class ReflectionObject {
    Object _this;
  public:
    ReflectionObject(const Variant &object);
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
    Variant getMethods(const Variant &filter = {});
    Variant hasProperty(const Variant &name);
    Variant getProperty(const Variant &name);
    Variant getProperties(const Variant &filter = {});
    Variant hasConstant(const Variant &name);
    Variant getConstants(const Variant &filter = {});
    Variant getReflectionConstants(const Variant &filter = {});
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
    Variant newInstance(const Variant &args = {});
    Variant newInstanceWithoutConstructor();
    Variant newInstanceArgs(const Array &args = {});
    Variant getParentClass();
    Variant isSubclassOf(const Variant &_class);
    Variant getStaticProperties();
    Variant getStaticPropertyValue(const Variant &name, const Variant &_default = {});
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
    Variant getAttributes(const Variant &name = {}, const Variant &flags = 0);
};

class ReflectionProperty {
    Object _this;
  public:
    ReflectionProperty(const Variant &_class, const Variant &property);
    Variant __toString();
    Variant getName();
    Variant getValue(const Variant &object = {});
    Variant setValue(const Variant &object_or_value, const Variant &value = {});
    Variant isInitialized(const Variant &object = {});
    Variant isPublic();
    Variant isPrivate();
    Variant isProtected();
    Variant isStatic();
    Variant isReadOnly();
    Variant isDefault();
    Variant isPromoted();
    Variant getModifiers();
    Variant getDeclaringClass();
    Variant getDocComment();
    Variant setAccessible(const Variant &accessible);
    Variant getType();
    Variant hasType();
    Variant hasDefaultValue();
    Variant getDefaultValue();
    Variant getAttributes(const Variant &name = {}, const Variant &flags = 0);
};

class ReflectionClassConstant {
    Object _this;
  public:
    ReflectionClassConstant(const Variant &_class, const Variant &constant);
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
    Variant getAttributes(const Variant &name = {}, const Variant &flags = 0);
    Variant isEnumCase();
};

class ReflectionExtension {
    Object _this;
  public:
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
    Object _this;
  public:
    ReflectionZendExtension(const Variant &name);
    Variant __toString();
    Variant getName();
    Variant getVersion();
    Variant getAuthor();
    Variant getURL();
    Variant getCopyright();
};

class ReflectionReference {
    Object _this;
  public:
    static Variant fromArrayElement(const Variant &array, const Variant &key);
    Variant getId();
};

class ReflectionAttribute {
    Object _this;
  public:
    Variant getName();
    Variant getTarget();
    Variant isRepeated();
    Variant getArguments();
    Variant newInstance();
    Variant __toString();
};

class ReflectionEnum {
    Object _this;
  public:
    ReflectionEnum(const Variant &object_or_class);
    Variant hasCase(const Variant &name);
    Variant getCase(const Variant &name);
    Variant getCases();
    Variant isBacked();
    Variant getBackingType();
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
    Variant getMethods(const Variant &filter = {});
    Variant hasProperty(const Variant &name);
    Variant getProperty(const Variant &name);
    Variant getProperties(const Variant &filter = {});
    Variant hasConstant(const Variant &name);
    Variant getConstants(const Variant &filter = {});
    Variant getReflectionConstants(const Variant &filter = {});
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
    Variant newInstance(const Variant &args = {});
    Variant newInstanceWithoutConstructor();
    Variant newInstanceArgs(const Array &args = {});
    Variant getParentClass();
    Variant isSubclassOf(const Variant &_class);
    Variant getStaticProperties();
    Variant getStaticPropertyValue(const Variant &name, const Variant &_default = {});
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
    Variant getAttributes(const Variant &name = {}, const Variant &flags = 0);
};

class ReflectionEnumUnitCase {
    Object _this;
  public:
    ReflectionEnumUnitCase(const Variant &_class, const Variant &constant);
    Variant getEnum();
    Variant getValue();
    Variant __toString();
    Variant getName();
    Variant isPublic();
    Variant isPrivate();
    Variant isProtected();
    Variant isFinal();
    Variant getModifiers();
    Variant getDeclaringClass();
    Variant getDocComment();
    Variant getAttributes(const Variant &name = {}, const Variant &flags = 0);
    Variant isEnumCase();
};

class ReflectionEnumBackedCase {
    Object _this;
  public:
    ReflectionEnumBackedCase(const Variant &_class, const Variant &constant);
    Variant getBackingValue();
    Variant getEnum();
    Variant getValue();
    Variant __toString();
    Variant getName();
    Variant isPublic();
    Variant isPrivate();
    Variant isProtected();
    Variant isFinal();
    Variant getModifiers();
    Variant getDeclaringClass();
    Variant getDocComment();
    Variant getAttributes(const Variant &name = {}, const Variant &flags = 0);
    Variant isEnumCase();
};

class ReflectionFiber {
    Object _this;
  public:
    ReflectionFiber(const Variant &fiber);
    Variant getFiber();
    Variant getExecutingFile();
    Variant getExecutingLine();
    Variant getCallable();
    Variant getTrace(const Variant &options = 1);
};

}

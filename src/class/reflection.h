namespace php {
class ReflectionException {
  private:
    Variant _this;
  public:
    ReflectionException(const std::initializer_list<Variant> &args);
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
  private:
    Variant _this;
  public:
    static Variant getModifierNames(const std::initializer_list<Variant> &args);
};

class ReflectionFunction {
  private:
    Variant _this;
  public:
    ReflectionFunction(const std::initializer_list<Variant> &args);
    Variant __toString();
    Variant isAnonymous();
    Variant isDisabled();
    Variant invoke(const std::initializer_list<Variant> &args);
    Variant invokeArgs(const std::initializer_list<Variant> &args);
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
    Variant getAttributes(const std::initializer_list<Variant> &args);
};

class ReflectionGenerator {
  private:
    Variant _this;
  public:
    ReflectionGenerator(const std::initializer_list<Variant> &args);
    Variant getExecutingLine();
    Variant getExecutingFile();
    Variant getTrace(const std::initializer_list<Variant> &args);
    Variant getFunction();
    Variant _getThis();
    Variant getExecutingGenerator();
};

class ReflectionParameter {
  private:
    Variant _this;
  public:
    ReflectionParameter(const std::initializer_list<Variant> &args);
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
    Variant getAttributes(const std::initializer_list<Variant> &args);
};

class ReflectionNamedType {
  private:
    Variant _this;
  public:
    Variant getName();
    Variant isBuiltin();
    Variant allowsNull();
    Variant __toString();
};

class ReflectionUnionType {
  private:
    Variant _this;
  public:
    Variant getTypes();
    Variant allowsNull();
    Variant __toString();
};

class ReflectionIntersectionType {
  private:
    Variant _this;
  public:
    Variant getTypes();
    Variant allowsNull();
    Variant __toString();
};

class ReflectionMethod {
  private:
    Variant _this;
  public:
    ReflectionMethod(const std::initializer_list<Variant> &args);
    Variant __toString();
    Variant isPublic();
    Variant isPrivate();
    Variant isProtected();
    Variant isAbstract();
    Variant isFinal();
    Variant isConstructor();
    Variant isDestructor();
    Variant getClosure(const std::initializer_list<Variant> &args);
    Variant getModifiers();
    Variant invoke(const std::initializer_list<Variant> &args);
    Variant invokeArgs(const std::initializer_list<Variant> &args);
    Variant getDeclaringClass();
    Variant getPrototype();
    Variant hasPrototype();
    Variant setAccessible(const std::initializer_list<Variant> &args);
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
    Variant getAttributes(const std::initializer_list<Variant> &args);
};

class ReflectionClass {
  private:
    Variant _this;
  public:
    ReflectionClass(const std::initializer_list<Variant> &args);
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
    Variant hasMethod(const std::initializer_list<Variant> &args);
    Variant getMethod(const std::initializer_list<Variant> &args);
    Variant getMethods(const std::initializer_list<Variant> &args);
    Variant hasProperty(const std::initializer_list<Variant> &args);
    Variant getProperty(const std::initializer_list<Variant> &args);
    Variant getProperties(const std::initializer_list<Variant> &args);
    Variant hasConstant(const std::initializer_list<Variant> &args);
    Variant getConstants(const std::initializer_list<Variant> &args);
    Variant getReflectionConstants(const std::initializer_list<Variant> &args);
    Variant getConstant(const std::initializer_list<Variant> &args);
    Variant getReflectionConstant(const std::initializer_list<Variant> &args);
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
    Variant isInstance(const std::initializer_list<Variant> &args);
    Variant newInstance(const std::initializer_list<Variant> &args);
    Variant newInstanceWithoutConstructor();
    Variant newInstanceArgs(const std::initializer_list<Variant> &args);
    Variant getParentClass();
    Variant isSubclassOf(const std::initializer_list<Variant> &args);
    Variant getStaticProperties();
    Variant getStaticPropertyValue(const std::initializer_list<Variant> &args);
    Variant setStaticPropertyValue(const std::initializer_list<Variant> &args);
    Variant getDefaultProperties();
    Variant isIterable();
    Variant isIterateable();
    Variant implementsInterface(const std::initializer_list<Variant> &args);
    Variant getExtension();
    Variant getExtensionName();
    Variant inNamespace();
    Variant getNamespaceName();
    Variant getShortName();
    Variant getAttributes(const std::initializer_list<Variant> &args);
};

class ReflectionObject {
  private:
    Variant _this;
  public:
    ReflectionObject(const std::initializer_list<Variant> &args);
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
    Variant hasMethod(const std::initializer_list<Variant> &args);
    Variant getMethod(const std::initializer_list<Variant> &args);
    Variant getMethods(const std::initializer_list<Variant> &args);
    Variant hasProperty(const std::initializer_list<Variant> &args);
    Variant getProperty(const std::initializer_list<Variant> &args);
    Variant getProperties(const std::initializer_list<Variant> &args);
    Variant hasConstant(const std::initializer_list<Variant> &args);
    Variant getConstants(const std::initializer_list<Variant> &args);
    Variant getReflectionConstants(const std::initializer_list<Variant> &args);
    Variant getConstant(const std::initializer_list<Variant> &args);
    Variant getReflectionConstant(const std::initializer_list<Variant> &args);
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
    Variant isInstance(const std::initializer_list<Variant> &args);
    Variant newInstance(const std::initializer_list<Variant> &args);
    Variant newInstanceWithoutConstructor();
    Variant newInstanceArgs(const std::initializer_list<Variant> &args);
    Variant getParentClass();
    Variant isSubclassOf(const std::initializer_list<Variant> &args);
    Variant getStaticProperties();
    Variant getStaticPropertyValue(const std::initializer_list<Variant> &args);
    Variant setStaticPropertyValue(const std::initializer_list<Variant> &args);
    Variant getDefaultProperties();
    Variant isIterable();
    Variant isIterateable();
    Variant implementsInterface(const std::initializer_list<Variant> &args);
    Variant getExtension();
    Variant getExtensionName();
    Variant inNamespace();
    Variant getNamespaceName();
    Variant getShortName();
    Variant getAttributes(const std::initializer_list<Variant> &args);
};

class ReflectionProperty {
  private:
    Variant _this;
  public:
    ReflectionProperty(const std::initializer_list<Variant> &args);
    Variant __toString();
    Variant getName();
    Variant getValue(const std::initializer_list<Variant> &args);
    Variant setValue(const std::initializer_list<Variant> &args);
    Variant isInitialized(const std::initializer_list<Variant> &args);
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
    Variant setAccessible(const std::initializer_list<Variant> &args);
    Variant getType();
    Variant hasType();
    Variant hasDefaultValue();
    Variant getDefaultValue();
    Variant getAttributes(const std::initializer_list<Variant> &args);
};

class ReflectionClassConstant {
  private:
    Variant _this;
  public:
    ReflectionClassConstant(const std::initializer_list<Variant> &args);
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
    Variant getAttributes(const std::initializer_list<Variant> &args);
    Variant isEnumCase();
};

class ReflectionExtension {
  private:
    Variant _this;
  public:
    ReflectionExtension(const std::initializer_list<Variant> &args);
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
  private:
    Variant _this;
  public:
    ReflectionZendExtension(const std::initializer_list<Variant> &args);
    Variant __toString();
    Variant getName();
    Variant getVersion();
    Variant getAuthor();
    Variant getURL();
    Variant getCopyright();
};

class ReflectionReference {
  private:
    Variant _this;
  public:
    static Variant fromArrayElement(const std::initializer_list<Variant> &args);
    Variant getId();
};

class ReflectionAttribute {
  private:
    Variant _this;
  public:
    Variant getName();
    Variant getTarget();
    Variant isRepeated();
    Variant getArguments();
    Variant newInstance();
    Variant __toString();
};

class ReflectionEnum {
  private:
    Variant _this;
  public:
    ReflectionEnum(const std::initializer_list<Variant> &args);
    Variant hasCase(const std::initializer_list<Variant> &args);
    Variant getCase(const std::initializer_list<Variant> &args);
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
    Variant hasMethod(const std::initializer_list<Variant> &args);
    Variant getMethod(const std::initializer_list<Variant> &args);
    Variant getMethods(const std::initializer_list<Variant> &args);
    Variant hasProperty(const std::initializer_list<Variant> &args);
    Variant getProperty(const std::initializer_list<Variant> &args);
    Variant getProperties(const std::initializer_list<Variant> &args);
    Variant hasConstant(const std::initializer_list<Variant> &args);
    Variant getConstants(const std::initializer_list<Variant> &args);
    Variant getReflectionConstants(const std::initializer_list<Variant> &args);
    Variant getConstant(const std::initializer_list<Variant> &args);
    Variant getReflectionConstant(const std::initializer_list<Variant> &args);
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
    Variant isInstance(const std::initializer_list<Variant> &args);
    Variant newInstance(const std::initializer_list<Variant> &args);
    Variant newInstanceWithoutConstructor();
    Variant newInstanceArgs(const std::initializer_list<Variant> &args);
    Variant getParentClass();
    Variant isSubclassOf(const std::initializer_list<Variant> &args);
    Variant getStaticProperties();
    Variant getStaticPropertyValue(const std::initializer_list<Variant> &args);
    Variant setStaticPropertyValue(const std::initializer_list<Variant> &args);
    Variant getDefaultProperties();
    Variant isIterable();
    Variant isIterateable();
    Variant implementsInterface(const std::initializer_list<Variant> &args);
    Variant getExtension();
    Variant getExtensionName();
    Variant inNamespace();
    Variant getNamespaceName();
    Variant getShortName();
    Variant getAttributes(const std::initializer_list<Variant> &args);
};

class ReflectionEnumUnitCase {
  private:
    Variant _this;
  public:
    ReflectionEnumUnitCase(const std::initializer_list<Variant> &args);
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
    Variant getAttributes(const std::initializer_list<Variant> &args);
    Variant isEnumCase();
};

class ReflectionEnumBackedCase {
  private:
    Variant _this;
  public:
    ReflectionEnumBackedCase(const std::initializer_list<Variant> &args);
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
    Variant getAttributes(const std::initializer_list<Variant> &args);
    Variant isEnumCase();
};

class ReflectionFiber {
  private:
    Variant _this;
  public:
    ReflectionFiber(const std::initializer_list<Variant> &args);
    Variant getFiber();
    Variant getExecutingFile();
    Variant getExecutingLine();
    Variant getCallable();
    Variant getTrace(const std::initializer_list<Variant> &args);
};

}

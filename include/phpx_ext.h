/*
  +----------------------------------------------------------------------+
  | PHP-X                                                                |
  +----------------------------------------------------------------------+
  | This source file is subject to version 2.0 of the Apache license,    |
  | that is bundled with this package in the file LICENSE, and is        |
  | available through the world-wide-web at the following url:           |
  | http://www.apache.org/licenses/LICENSE-2.0.html                      |
  | If you did not receive a copy of the Apache2.0 license and are unable|
  | to obtain it through the world-wide-web, please send a note to       |
  | license@swoole.com so we can mail you a copy immediately.            |
  +----------------------------------------------------------------------+
  | Author: Tianfeng Han  <rango@swoole.com>                             |
  +----------------------------------------------------------------------+
*/

#pragma once

#include "phpx.h"

namespace php {

#define PHPX_EXTENSION()                                                                                               \
    extern "C" {                                                                                                       \
    ZEND_DLEXPORT Extension *get_module();                                                                             \
    }                                                                                                                  \
    ZEND_DLEXPORT Extension *get_module()

class Function;
class Method;

extern std::unordered_map<std::string, std::map<std::string, Method *>> method_map;
extern std::unordered_map<std::string, Function *> function_map;

#define PHPX_FN(n) #n, n
#define PHPX_ME(c, m) #m, c##_##m

class Function {
    const char *name_;

  public:
    explicit Function(const char *name) {
        name_ = name;
    }
    virtual ~Function() = default;
    virtual Variant impl(Args &) = 0;
};

#define PHPX_FUNCTION(func)                                                                                            \
    class phpx_function_##func : Function {                                                                            \
      public:                                                                                                          \
        Variant impl(Args &);                                                                                          \
        explicit phpx_function_##func(const char *name) : Function(name) {                                             \
            function_map[name] = this;                                                                                 \
        }                                                                                                              \
        ~phpx_function_##func() {}                                                                                     \
    };                                                                                                                 \
    static phpx_function_##func f_##func(#func);                                                                       \
    PHP_FUNCTION(func) {}                                                                                              \
    Variant phpx_function_##func::impl(Args &args)

class Method {
    const char *class_;
    const char *name_;

  public:
    Method(const char *_class, const char *_name) {
        name_ = _name;
        class_ = _class;
    }
    virtual ~Method() = default;
    virtual Variant impl(Object &, Args &) = 0;
};

#define PHPX_METHOD(class_, method)                                                                                    \
    class phpx_method_##class_##_##method : Method {                                                                   \
      public:                                                                                                          \
        Variant impl(Object &_this, Args &);                                                                           \
        phpx_method_##class_##_##method(const char *_class, const char *_name) : Method(_class, _name) {               \
            method_map[_class][_name] = this;                                                                          \
        }                                                                                                              \
        ~phpx_method_##class_##_##method() {}                                                                          \
    };                                                                                                                 \
    static phpx_method_##class_##_##method m_##class_##_##method(#class_, #method);                                    \
    PHP_METHOD(class_, method) {}                                                                                      \
    Variant phpx_method_##class_##_##method::impl(Object &_this, Args &args)

extern void _exec_function(zend_execute_data *data, zval *return_value);
extern void _exec_method(zend_execute_data *data, zval *return_value);

zend_function_entry *copy_function_entries(const zend_function_entry *_functions);

enum ClassFlags {
    STATIC = ZEND_ACC_STATIC,
    ABSTRACT = ZEND_ACC_ABSTRACT,
    FINAL = ZEND_ACC_FINAL,
    INTERFACE = ZEND_ACC_INTERFACE,
    TRAIT = ZEND_ACC_TRAIT,
    PUBLIC = ZEND_ACC_PUBLIC,
    PROTECTED = ZEND_ACC_PROTECTED,
    PRIVATE = ZEND_ACC_PRIVATE,
    CONSTRUCT = ZEND_ACC_CTOR,
#ifdef ZEND_ACC_DTOR
    DESTRUCT = ZEND_ACC_DTOR,
#else
    DESTRUCT = 0,
#endif
#ifdef ZEND_ACC_CLONE
    CLONE = ZEND_ACC_CLONE,
#else
    CLONE = 0,
#endif
};

enum SortFlags {
    SORT_REGULAR = 0,
    SORT_NUMERIC = 1,
    SORT_STRING = 2,
    SORT_DESC = 3,
    SORT_ASC = 4,
    SORT_LOCALE_STRING = 5,
    SORT_NATURAL = 6,
    SORT_FLAG_CASE = 8,
};

class Interface;

class Class {
    struct Property {
        std::string name;
        zval value;
        int flags;
    };

    struct Constant {
        std::string name;
        zval value;
    };

  public:
    explicit Class(const char *name);
    bool extends(zend_class_entry *_parent_class);
    bool extends(Class *parent);
    bool implements(zend_class_entry *if_ce);
    bool implements(const Interface *);
    bool addConstant(const char *name, const Variant &v);
    bool addProperty(const char *name, const Variant &v, int flags);
    bool addStaticProperty(const char *name, const Variant &v, int flags);
    bool registerFunctions(const zend_function_entry *functions);
    bool activate();
    bool alias(const char *alias_name);

    const std::string &getName() {
        return class_name;
    }

    zend_class_entry *ptr() const {
        return ce;
    }

  protected:
    bool activated;
    std::string class_name;
    std::string parent_class_name;
    zend_class_entry *parent_ce;
    zend_class_entry _ce{};
    zend_class_entry *ce;
    std::vector<zend_class_entry *> interfaces;
    zend_function_entry *functions;
    std::vector<Property> properties;
    std::vector<Constant> constants;
    std::vector<std::string> aliases;
};

class Interface {
  public:
    explicit Interface(const char *name);
    std::string getName() {
        return name;
    }
    void registerFunctions(const zend_function_entry *_functions) {
        functions = _functions;
    }
    bool activate();

    zend_class_entry *ptr() const {
        return ce;
    }

  protected:
    bool activated = false;
    std::string name;
    zend_class_entry _ce{};
    zend_class_entry *ce;
    const zend_function_entry *functions;
};

extern zend_result extension_startup(int type, int module_number);
extern void extension_info(zend_module_entry *module);
extern zend_result extension_shutdown(int type, int module_number);
extern zend_result extension_before_request(int type, int module_number);
extern zend_result extension_after_request(int type, int module_number);

class Extension {
    struct IniEntry {
        std::string name;
        std::string default_value;
        int modifiable;
    };

  protected:
    zend_module_entry module = {
        STANDARD_MODULE_HEADER_EX,
        nullptr,
        nullptr,
        nullptr,
        nullptr,
        extension_startup,
        extension_shutdown,
        extension_before_request,
        extension_after_request,
        extension_info,
        nullptr,
        STANDARD_MODULE_PROPERTIES,
    };

    friend zend_result extension_startup(int type, int module_number);
    friend zend_result extension_shutdown(int type, int module_number);
    bool started = false;

    int function_count = 0;
    int deps_count = 0;
    int function_array_size = 0;

    zend_function_entry *functions;
    std::vector<IniEntry> ini_entries;
    std::vector<zend_module_dep> deps_;

    void registerIniEntries(int module_number);
    void unregisterIniEntries(int module_number) const;

  public:
    enum StartupStatus {
        BEFORE_START,
        AFTER_START,
    };

    std::string name;
    std::string version;

    std::function<void()> onStart = nullptr;
    std::function<void()> onShutdown = nullptr;
    std::function<void()> onBeforeRequest = nullptr;
    std::function<void()> onAfterRequest = nullptr;

    std::vector<std::string> header;
    std::vector<std::vector<std::string>> body;

    Extension(const char *name, const char *version);
    void checkStartupStatus(StartupStatus status, const char *func) const;

    bool registerClass(Class *c) const;
    bool registerInterface(Interface *i) const;
    bool registerFunctions(const zend_function_entry *functions);
    bool registerResource(const char *name, resource_dtor dtor) const;
    void registerConstant(const char *name, long v) const;
    void registerConstant(const char *name, int v) const;
    void registerConstant(const char *name, bool v) const;
    void registerConstant(const char *name, double v) const;
    void registerConstant(const char *name, const char *v) const;
    void registerConstant(const char *name, const char *v, size_t len) const;
    void registerConstant(const char *name, const std::string &v) const;

    void require(const char *name, const char *version = nullptr);

    void info(const std::vector<std::string> &header, const std::vector<std::vector<std::string>> &body) {
        this->header = header;
        this->body = body;
    }

    // modifiable can be one of these:PHP_INI_SYSTEM/PHP_INI_PERDIR/PHP_INI_USER/PHP_INI_ALL
    void addIniEntry(const char *name, const char *default_value = "", int modifiable = PHP_INI_ALL);
    void printInfo() const;
};
}  // namespace php

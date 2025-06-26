/* This is a generated file, edit the .stub.php file instead.
 * Stub hash: 6d9b189c55ed70f0d0f9bea40fa7f9bbdd48542d */

ZEND_BEGIN_ARG_INFO_EX(arginfo_cpp_ext_test, 0, 0, 0)
	ZEND_ARG_VARIADIC_INFO(0, args)
ZEND_END_ARG_INFO()

#define arginfo_cpp_ext_test2 arginfo_cpp_ext_test

ZEND_BEGIN_ARG_INFO_EX(arginfo_class_MyClass_test, 0, 0, 0)
ZEND_END_ARG_INFO()

#define arginfo_class_MyClass_pget arginfo_class_MyClass_test

#define arginfo_class_MyClass_pset arginfo_class_MyClass_test

ZEND_BEGIN_ARG_INFO_EX(arginfo_class_MyInterface_test, 0, 0, 2)
	ZEND_ARG_INFO(0, a)
	ZEND_ARG_INFO(0, b)
ZEND_END_ARG_INFO()


ZEND_FUNCTION(cpp_ext_test);
ZEND_FUNCTION(cpp_ext_test2);
ZEND_METHOD(MyClass, test);
ZEND_METHOD(MyClass, pget);
ZEND_METHOD(MyClass, pset);


static const zend_function_entry ext_functions[] = {
	ZEND_FE(cpp_ext_test, arginfo_cpp_ext_test)
	ZEND_FE(cpp_ext_test2, arginfo_cpp_ext_test2)
	ZEND_FE_END
};


static const zend_function_entry class_MyClass_methods[] = {
	ZEND_ME(MyClass, test, arginfo_class_MyClass_test, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	ZEND_ME(MyClass, pget, arginfo_class_MyClass_pget, ZEND_ACC_PUBLIC)
	ZEND_ME(MyClass, pset, arginfo_class_MyClass_pset, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};


static const zend_function_entry class_MyInterface_methods[] = {
	ZEND_ABSTRACT_ME_WITH_FLAGS(MyInterface, test, arginfo_class_MyInterface_test, ZEND_ACC_PUBLIC|ZEND_ACC_ABSTRACT)
	ZEND_FE_END
};

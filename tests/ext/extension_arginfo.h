/* This is a generated file, edit the .stub.php file instead.
 * Stub hash: c05740fcc7ab8d2acf472710a2e171cfa72a92db */

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_cpp_ext_test, 0, 0, IS_LONG, 0)
	ZEND_ARG_VARIADIC_TYPE_INFO(0, args, IS_MIXED, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_cpp_ext_test2, 0, 0, IS_ARRAY, 0)
	ZEND_ARG_VARIADIC_TYPE_INFO(0, args, IS_MIXED, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_MyClass_test, 0, 0, IS_DOUBLE, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_MyClass_pget, 0, 0, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_MyClass_pset, 0, 0, IS_VOID, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_MyClass_count, 0, 0, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_MyInterface_test, 0, 2, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, a, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, b, IS_STRING, 0)
ZEND_END_ARG_INFO()


ZEND_FUNCTION(cpp_ext_test);
ZEND_FUNCTION(cpp_ext_test2);
ZEND_METHOD(MyClass, test);
ZEND_METHOD(MyClass, pget);
ZEND_METHOD(MyClass, pset);
ZEND_METHOD(MyClass, count);


static const zend_function_entry ext_functions[] = {
	ZEND_FE(cpp_ext_test, arginfo_cpp_ext_test)
	ZEND_FE(cpp_ext_test2, arginfo_cpp_ext_test2)
	ZEND_FE_END
};


static const zend_function_entry class_MyClass_methods[] = {
	ZEND_ME(MyClass, test, arginfo_class_MyClass_test, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	ZEND_ME(MyClass, pget, arginfo_class_MyClass_pget, ZEND_ACC_PUBLIC)
	ZEND_ME(MyClass, pset, arginfo_class_MyClass_pset, ZEND_ACC_PUBLIC)
	ZEND_ME(MyClass, count, arginfo_class_MyClass_count, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};


static const zend_function_entry class_MyInterface_methods[] = {
	ZEND_ABSTRACT_ME_WITH_FLAGS(MyInterface, test, arginfo_class_MyInterface_test, ZEND_ACC_PUBLIC|ZEND_ACC_ABSTRACT)
	ZEND_FE_END
};

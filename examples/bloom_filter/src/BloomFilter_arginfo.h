/* This is a generated file, edit the .stub.php file instead.
 * Stub hash: d826fa2e57b14e7a9963d0d03923ea84c84d8fc5 */

ZEND_BEGIN_ARG_INFO_EX(arginfo_class_BloomFilter___construct, 0, 0, 1)
	ZEND_ARG_TYPE_INFO(0, size, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_BloomFilter_add, 0, 1, IS_VOID, 0)
	ZEND_ARG_TYPE_INFO(0, value, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_BloomFilter_has, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, value, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_BloomFilter_clear, 0, 0, IS_VOID, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_BloomFilter_load, 0, 1, IS_MIXED, 0)
	ZEND_ARG_TYPE_INFO(0, file, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_BloomFilter_dump, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, file, IS_STRING, 0)
ZEND_END_ARG_INFO()


ZEND_METHOD(BloomFilter, __construct);
ZEND_METHOD(BloomFilter, add);
ZEND_METHOD(BloomFilter, has);
ZEND_METHOD(BloomFilter, clear);
ZEND_METHOD(BloomFilter, load);
ZEND_METHOD(BloomFilter, dump);


static const zend_function_entry class_BloomFilter_methods[] = {
	ZEND_ME(BloomFilter, __construct, arginfo_class_BloomFilter___construct, ZEND_ACC_PUBLIC)
	ZEND_ME(BloomFilter, add, arginfo_class_BloomFilter_add, ZEND_ACC_PUBLIC)
	ZEND_ME(BloomFilter, has, arginfo_class_BloomFilter_has, ZEND_ACC_PUBLIC)
	ZEND_ME(BloomFilter, clear, arginfo_class_BloomFilter_clear, ZEND_ACC_PUBLIC)
	ZEND_ME(BloomFilter, load, arginfo_class_BloomFilter_load, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	ZEND_ME(BloomFilter, dump, arginfo_class_BloomFilter_dump, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};

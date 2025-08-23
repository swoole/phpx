/* This is a generated file, edit the .stub.php file instead.
 * Stub hash: 00d4b9d9635767ee265c5fcdef73df22a800674f */

ZEND_BEGIN_ARG_INFO_EX(arginfo_class_rocksDB___construct, 0, 0, 1)
	ZEND_ARG_TYPE_INFO(0, path, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, options, IS_ARRAY, 0, "[]")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, _readoption, IS_ARRAY, 0, "[]")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, _writeoption, IS_ARRAY, 0, "[]")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, mode, IS_LONG, 0, "0")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, ttl, IS_LONG, 0, "0")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, secondary_path, IS_STRING, 0, "\'\'")
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_rocksDB_put, 0, 2, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, key, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, value, IS_STRING, 0)
ZEND_END_ARG_INFO()

#define arginfo_class_rocksDB_merge arginfo_class_rocksDB_put

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_rocksDB_get, 0, 1, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, key, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_rocksDB_delete, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, key, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_rocksDB_syncWAL, 0, 0, _IS_BOOL, 0)
ZEND_END_ARG_INFO()


ZEND_METHOD(rocksDB, __construct);
ZEND_METHOD(rocksDB, put);
ZEND_METHOD(rocksDB, merge);
ZEND_METHOD(rocksDB, get);
ZEND_METHOD(rocksDB, delete);
ZEND_METHOD(rocksDB, syncWAL);


static const zend_function_entry class_rocksDB_methods[] = {
	ZEND_ME(rocksDB, __construct, arginfo_class_rocksDB___construct, ZEND_ACC_PUBLIC)
	ZEND_ME(rocksDB, put, arginfo_class_rocksDB_put, ZEND_ACC_PUBLIC)
	ZEND_ME(rocksDB, merge, arginfo_class_rocksDB_merge, ZEND_ACC_PUBLIC)
	ZEND_ME(rocksDB, get, arginfo_class_rocksDB_get, ZEND_ACC_PUBLIC)
	ZEND_ME(rocksDB, delete, arginfo_class_rocksDB_delete, ZEND_ACC_PUBLIC)
	ZEND_ME(rocksDB, syncWAL, arginfo_class_rocksDB_syncWAL, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};

/* This is a generated file, edit the .stub.php file instead.
 * Stub hash: acdf0a4b725dca23eb85635fa0b9bd994ab07081 */

ZEND_BEGIN_ARG_INFO_EX(arginfo_class_Queue___construct, 0, 0, 0)
	ZEND_ARG_INFO(0, size)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_class_Queue_count, 0, 0, 0)
ZEND_END_ARG_INFO()

#define arginfo_class_Queue_isEmpty arginfo_class_Queue_count

ZEND_BEGIN_ARG_INFO_EX(arginfo_class_Queue_push, 0, 0, 1)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

#define arginfo_class_Queue_pull arginfo_class_Queue_count

#define arginfo_class_Queue_first arginfo_class_Queue_count

#define arginfo_class_Queue_traverse arginfo_class_Queue_count


ZEND_METHOD(Queue, __construct);
ZEND_METHOD(Queue, count);
ZEND_METHOD(Queue, isEmpty);
ZEND_METHOD(Queue, push);
ZEND_METHOD(Queue, pull);
ZEND_METHOD(Queue, first);
ZEND_METHOD(Queue, traverse);


static const zend_function_entry class_Queue_methods[] = {
	ZEND_ME(Queue, __construct, arginfo_class_Queue___construct, ZEND_ACC_PUBLIC)
	ZEND_ME(Queue, count, arginfo_class_Queue_count, ZEND_ACC_PUBLIC)
	ZEND_ME(Queue, isEmpty, arginfo_class_Queue_isEmpty, ZEND_ACC_PUBLIC)
	ZEND_ME(Queue, push, arginfo_class_Queue_push, ZEND_ACC_PUBLIC)
	ZEND_ME(Queue, pull, arginfo_class_Queue_pull, ZEND_ACC_PUBLIC)
	ZEND_ME(Queue, first, arginfo_class_Queue_first, ZEND_ACC_PUBLIC)
	ZEND_ME(Queue, traverse, arginfo_class_Queue_traverse, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};

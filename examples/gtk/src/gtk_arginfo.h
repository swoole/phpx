/* This is a generated file, edit the .stub.php file instead.
 * Stub hash: b39494adbc8a75e6afad29a61d1c083fe0a3246d */

ZEND_BEGIN_ARG_INFO_EX(arginfo_class_Gtk_Application___construct, 0, 0, 2)
	ZEND_ARG_TYPE_INFO(0, glade_file, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, window_name, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Gtk_Application_find, 0, 1, IS_MIXED, 0)
	ZEND_ARG_TYPE_INFO(0, object, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Gtk_Application_run, 0, 0, IS_VOID, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Gtk_Application_setTitle, 0, 1, IS_VOID, 0)
	ZEND_ARG_TYPE_INFO(0, value, IS_MIXED, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Gtk_Application_setIcon, 0, 1, IS_MIXED, 0)
	ZEND_ARG_TYPE_INFO(0, icon, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Gtk_Application_quit, 0, 0, IS_MIXED, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Gtk_Widget_on, 0, 2, IS_VOID, 0)
	ZEND_ARG_TYPE_INFO(0, event, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, fn, IS_CALLABLE, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Gtk_Entry_getText, 0, 0, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Gtk_Entry_setText, 0, 1, IS_VOID, 0)
	ZEND_ARG_TYPE_INFO(0, text, IS_STRING, 0)
ZEND_END_ARG_INFO()

#define arginfo_class_Gtk_Label_getText arginfo_class_Gtk_Entry_getText

#define arginfo_class_Gtk_Label_setText arginfo_class_Gtk_Entry_setText


ZEND_METHOD(Gtk_Application, __construct);
ZEND_METHOD(Gtk_Application, find);
ZEND_METHOD(Gtk_Application, run);
ZEND_METHOD(Gtk_Application, setTitle);
ZEND_METHOD(Gtk_Application, setIcon);
ZEND_METHOD(Gtk_Application, quit);
ZEND_METHOD(Gtk_Widget, on);
ZEND_METHOD(Gtk_Entry, getText);
ZEND_METHOD(Gtk_Entry, setText);
ZEND_METHOD(Gtk_Label, getText);
ZEND_METHOD(Gtk_Label, setText);


static const zend_function_entry class_Gtk_Application_methods[] = {
	ZEND_ME(Gtk_Application, __construct, arginfo_class_Gtk_Application___construct, ZEND_ACC_PUBLIC)
	ZEND_ME(Gtk_Application, find, arginfo_class_Gtk_Application_find, ZEND_ACC_PUBLIC)
	ZEND_ME(Gtk_Application, run, arginfo_class_Gtk_Application_run, ZEND_ACC_PUBLIC)
	ZEND_ME(Gtk_Application, setTitle, arginfo_class_Gtk_Application_setTitle, ZEND_ACC_PUBLIC)
	ZEND_ME(Gtk_Application, setIcon, arginfo_class_Gtk_Application_setIcon, ZEND_ACC_PUBLIC)
	ZEND_ME(Gtk_Application, quit, arginfo_class_Gtk_Application_quit, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};


static const zend_function_entry class_Gtk_Widget_methods[] = {
	ZEND_ME(Gtk_Widget, on, arginfo_class_Gtk_Widget_on, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};


static const zend_function_entry class_Gtk_Entry_methods[] = {
	ZEND_ME(Gtk_Entry, getText, arginfo_class_Gtk_Entry_getText, ZEND_ACC_PUBLIC)
	ZEND_ME(Gtk_Entry, setText, arginfo_class_Gtk_Entry_setText, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};


static const zend_function_entry class_Gtk_Label_methods[] = {
	ZEND_ME(Gtk_Label, getText, arginfo_class_Gtk_Label_getText, ZEND_ACC_PUBLIC)
	ZEND_ME(Gtk_Label, setText, arginfo_class_Gtk_Label_setText, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};

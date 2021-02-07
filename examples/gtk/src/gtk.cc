/*
  +----------------------------------------------------------------------+
  | Swoole                                                               |
  +----------------------------------------------------------------------+
  | This source file is subject to version 2.0 of the Apache license,    |
  | that is bundled with this package in the file LICENSE, and is        |
  | available through the world-wide-web at the following url:           |
  | http://www.apache.org/licenses/LICENSE-2.0.html                      |
  | If you did not receive a copy of the Apache2.0 license and are unable|
  | to obtain it through the world-wide-web, please send a note to       |
  | license@swoole.com so we can mail you a copy immediately.            |
  +----------------------------------------------------------------------+
  | Author: Tianfeng Han  <mikan.tenny@gmail.com>                        |
  +----------------------------------------------------------------------+
*/

#include "phpx.h"

BEGIN_EXTERN_C()
#if PHP_VERSION_ID < 80000
#include "gtk_legacy_arginfo.h"
#else
#include "gtk_arginfo.h"
#endif
END_EXTERN_C()

#include <gtk/gtk.h>

#include <iostream>

using namespace php;
using namespace std;

struct PHP_Gtk_Application {
    GtkBuilder *builder;
    GtkWindow *main_window;
};

static vector<Variant *> callbacks;

void PHP_Gtk_callback(GtkApplication *app, gpointer user_data) {
    Variant v = *(Variant *) user_data;
    call(v);
}

void on_main_window_destroy(GtkApplication *app, gpointer user_data) {
    Variant v = *(Variant *) user_data;
    Object o(v);
    o.exec("quit");
}

PHPX_METHOD(Gtk_Application, __construct) {
    if (args.count() < 2) {
        error(E_ERROR, "invalid parameters.");
        return;
    }

    int argc = 0;
    gtk_init(&argc, NULL);

    GtkBuilder *builder = gtk_builder_new_from_file(args[0].toCString());
    if (builder == nullptr) {
        error(E_ERROR, "invalid parameters.");
        return;
    }

    GtkWindow *window = GTK_WINDOW(gtk_builder_get_object(builder, args[1].toCString()));
    if (window == nullptr) {
        error(E_ERROR, "main window[id=%s] is not eixsts.", args[1].toCString());
        return;
    }

    auto app_object = _this.dup();
    g_signal_connect(window, "destroy", G_CALLBACK(on_main_window_destroy), app_object);
    callbacks.push_back(app_object);

    PHP_Gtk_Application *app = new PHP_Gtk_Application;
    app->builder = builder;
    app->main_window = window;
    auto res = newResource<PHP_Gtk_Application>("GtkApplication", app);
    _this.set("app", res);
}

PHPX_METHOD(Gtk_Application, run) {
    // g_object_unref(builder);
    PHP_Gtk_Application *app = _this.get("app").toResource<PHP_Gtk_Application>("GtkApplication");
    gtk_widget_show(GTK_WIDGET(app->main_window));
    gtk_main();
}

PHPX_METHOD(Gtk_Application, setTitle) {
    PHP_Gtk_Application *app = _this.get("app").toResource<PHP_Gtk_Application>("GtkApplication");
    gtk_window_set_title(app->main_window, args[0].toCString());
}

PHPX_METHOD(Gtk_Application, setIcon) {
    PHP_Gtk_Application *app = _this.get("app").toResource<PHP_Gtk_Application>("GtkApplication");
    GError *error = NULL;
    auto file = args[0].toCString();
    if (gtk_window_set_icon_from_file(app->main_window, file, &error)) {
        retval = true;
    } else {
        retval = false;
        php::error(E_WARNING, "%s [%d]", error->message, error->code);
    }
}

PHPX_METHOD(Gtk_Application, find) {
    PHP_Gtk_Application *app = _this.get("app").toResource<PHP_Gtk_Application>("GtkApplication");
    GObject *gobject = gtk_builder_get_object(app->builder, args[0].toCString());
    if (gobject == nullptr) {
        retval = false;
        return;
    }

    String type(G_OBJECT_TYPE_NAME(gobject));
    const char *className;

    if (type.equals("GtkEntry")) {
        className = "Gtk\\Entry";
    } else if (type.equals("GtkLabel")) {
        className = "Gtk\\Label";
    } else {
        className = "Gtk\\Widget";
    }

    Object widget = newObject(className);
    auto res = newResource<GObject>("GObject", gobject);
    widget.set("resource", res);
    retval = widget;
}

PHPX_METHOD(Gtk_Application, quit) {
    gtk_main_quit();
    for (int i = 0; i < callbacks.size(); i++) {
        auto callback = callbacks[i];
        delete callbacks[i];
    }
}

PHPX_METHOD(Gtk_Widget, on) {
    GObject *object = _this.get("resource").toResource<GObject>("GObject");
    auto callback = args[1].dup();
    g_signal_connect(object, args[0].toCString(), G_CALLBACK(PHP_Gtk_callback), callback);
    callbacks.push_back(callback);
}

PHPX_METHOD(Gtk_Entry, getText) {
    GtkEntry *entry = GTK_ENTRY(_this.get("resource").toResource<GObject>("GObject"));
    auto text = gtk_entry_get_text(entry);
    retval = Variant(text);
}

PHPX_METHOD(Gtk_Entry, setText) {
    GtkEntry *entry = GTK_ENTRY(_this.get("resource").toResource<GObject>("GObject"));
    gtk_entry_set_text(entry, args[0].toCString());
}

PHPX_METHOD(Gtk_Label, getText) {
    GtkLabel *label = GTK_LABEL(_this.get("resource").toResource<GObject>("GObject"));
    retval = Variant(gtk_label_get_text(label));
}

PHPX_METHOD(Gtk_Label, setText) {
    GtkLabel *label = GTK_LABEL(_this.get("resource").toResource<GObject>("GObject"));
    gtk_label_set_text(label, args[0].toCString());
}

void GtkApplication_dtor(zend_resource *res) {
    PHP_Gtk_Application *app = static_cast<PHP_Gtk_Application *>(res->ptr);
    delete app;
}

void GObject_dtor(zend_resource *res) {
    GObject *o = static_cast<GObject *>(res->ptr);
}

PHPX_EXTENSION() {
    Extension *ext = new Extension("gtk", "0.0.1");

    ext->onStart = [ext]() {
        /**
         * Gtk\\Application
         */
        Class *c = new Class("Gtk_Application");
        c->registerFunctions(class_Gtk_Application_methods);
        c->alias("Gtk\\Application");
        ext->registerClass(c);
        /**
         * Gtk\\Widget
         */
        Class *widget_class = new Class("Gtk_Widget");
        widget_class->registerFunctions(class_Gtk_Widget_methods);
        widget_class->alias("Gtk\\Widget");
        ext->registerClass(widget_class);
        /**
         * Gtk\\Entry
         */
        Class *entry_class = new Class("Gtk_Entry");
        entry_class->extends(widget_class);
        entry_class->registerFunctions(class_Gtk_Entry_methods);
        entry_class->alias("Gtk\\Entry");
        ext->registerClass(entry_class);
        /**
         * Gtk\\Label
         */
        Class *label_class = new Class("Gtk_Label");
        label_class->extends(widget_class);
        label_class->registerFunctions(class_Gtk_Label_methods);
        label_class->alias("Gtk\\Label");
        ext->registerClass(label_class);

        ext->registerResource("GtkApplication", GtkApplication_dtor);
        ext->registerResource("GObject", GObject_dtor);
    };

    ext->info({"gtk support", "enabled"},
              {
                  {"author", "Rango"},
                  {"version", ext->version},
              });

    return ext;
}

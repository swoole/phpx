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

#include <gtk/gtk.h>

#include <iostream>

using namespace php;
using namespace std;

struct PHP_Gtk_Application
{
    GtkBuilder *builder;
    GtkWidget *main_window;
};

static vector<Variant *> callbacks;

void PHP_Gtk_callback(GtkApplication* app, gpointer user_data)
{
    Variant v = *(Variant *) user_data;
    call(v);
}

void on_main_window_destroy(GtkApplication* app, gpointer user_data)
{
    Variant v = *(Variant *) user_data;
    Object o(v);
    o.exec("quit");
}

PHPX_METHOD(GtkApplication, construct)
{
    if (args.count() < 2)
    {
        error(E_ERROR, "invalid parameters.");
        return;
    }
    int argc = 0;
    char *argv[] =
    { "phpx-gtk" };
    gtk_init(&argc, ( char ***)&argv);

    GtkBuilder *builder = gtk_builder_new();

    if (gtk_builder_add_from_file(builder, args[0].toCString(), NULL) < 0)
    {
        error(E_ERROR, "invalid parameters.");
        return;
    }

    GtkWidget *window = GTK_WIDGET(gtk_builder_get_object(builder, args[1].toCString()));
    if (window == nullptr)
    {
        error(E_ERROR, "main window[id=%s] is not eixsts.", args[1].toCString());
        return;
    }
    g_signal_connect (window, "destroy", G_CALLBACK(on_main_window_destroy), _this.dup());

    PHP_Gtk_Application *app = new PHP_Gtk_Application;
    app->builder = builder;
    app->main_window = window;
    auto res = newResource<PHP_Gtk_Application>("GtkApplication", app);
    _this.set("app", res);
}

PHPX_METHOD(GtkApplication, run)
{
    //g_object_unref(builder);
    PHP_Gtk_Application *app = _this.get("app").toResource<PHP_Gtk_Application>("GtkApplication");
    gtk_widget_show(app->main_window);
    gtk_main();
}

PHPX_METHOD(GtkApplication, find)
{
    PHP_Gtk_Application *app = _this.get("app").toResource<PHP_Gtk_Application>("GtkApplication");
    GtkWidget *window = GTK_WIDGET(gtk_builder_get_object(app->builder, args[0].toCString()));
    if (window != nullptr)
    {
        Object widget = newObject("Gtk\\Widget");
        auto res = newResource<GtkWidget>("GtkWidget", window);
        widget.set("resource", res);
        retval = widget;
    }
}

PHPX_METHOD(GtkApplication, quit)
{
    gtk_main_quit();
    for (int i = 0; i < callbacks.size(); i++)
    {
        auto callback = callbacks[i];
        delete callbacks[i];
    }
}

PHPX_METHOD(GtkWidget, on)
{
    GtkWidget *widget = _this.get("resource").toResource<GtkWidget>("GtkWidget");
    auto callback = args[1].dup();
    g_signal_connect(widget, args[0].toCString(), G_CALLBACK (PHP_Gtk_callback), callback);
    callbacks.push_back(callback);
}

PHPX_METHOD(GtkWidget, getText)
{
    GtkWidget *widget = _this.get("resource").toResource<GtkWidget>("GtkWidget");
    auto text = gtk_entry_get_text((GtkEntry *) widget);
    auto length = gtk_entry_get_text_length((GtkEntry *) widget);
    retval = Variant(text, length);
}

PHPX_METHOD(GtkWidget, setText)
{
    GtkWidget *widget = _this.get("resource").toResource<GtkWidget>("GtkWidget");
    gtk_entry_set_text((GtkEntry *) widget, args[0].toCString());
}

void GtkApplication_dtor(zend_resource *res)
{
    PHP_Gtk_Application *app = static_cast<PHP_Gtk_Application*>(res->ptr);
    delete app;
}

void GtkWidget_dtor(zend_resource *res)
{
    GtkWidget *w = static_cast<GtkWidget*>(res->ptr);
}

PHPX_EXTENSION()
{
    Extension *ext = new Extension("gtk", "0.0.1");

    ext->onStart = [ext]()
    {
        Class *c = new Class("Gtk\\Application");

        c->addMethod("__construct", GtkApplication_construct, CONSTRUCT);
        c->addMethod("find", GtkApplication_find);
        c->addMethod("run", GtkApplication_run);
        c->addMethod("quit", GtkApplication_quit);
        ext->registerClass(c);

        Class *widget = new Class("Gtk\\Widget");
        widget->addMethod("on", GtkWidget_on);
        widget->addMethod("getText", GtkWidget_getText);

        auto argInfo = new ArgInfo(1);
        argInfo->add("text", nullptr, IS_STRING);
        widget->addMethod("setText", GtkWidget_setText, PUBLIC, argInfo);

        ext->registerClass(widget);

        ext->registerResource("GtkApplication", GtkApplication_dtor);
        ext->registerResource("GtkWidget", GtkWidget_dtor);
    };

    ext->info(
    {
        "gtk support", "enabled"
    },
    {
        { "author", "Rango" },
        { "version", ext->version },
    });

    return ext;
}

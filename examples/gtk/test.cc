#include <gtk/gtk.h>

void on_window1_destroy(GtkApplication* app,  gpointer user_data)
{
    gtk_main_quit();
}

void on_button1_clicked(GtkApplication* app,  gpointer user_data)
{
    gtk_main_quit();
}
 
 
int main(int argc, char *argv[])
{
    GtkBuilder      *builder; 
    GtkWidget       *window;
 
    gtk_init(&argc, &argv);
 
    builder = gtk_builder_new();
    gtk_builder_add_from_file (builder, "test.glade", NULL);
 
    window = GTK_WIDGET(gtk_builder_get_object(builder, "window1"));
    //gtk_builder_connect_signals(builder, NULL);

    g_signal_connect (window, "destroy", G_CALLBACK (on_window1_destroy), NULL);

    GtkWidget *button1 = GTK_WIDGET(gtk_builder_get_object(builder, "button1"));
    g_signal_connect (button1, "clicked", G_CALLBACK (on_button1_clicked), NULL);
 
    g_object_unref(builder);
 
    gtk_widget_show(window);                
    gtk_main();
 
    return 0;
}
 


#include <gtk/gtk.h>

static void aktivieren(GtkApplication *app, gpointer data)
{
	GtkWidget *window;
	window = gtk_application_window_new(app);
	gtk_window_set_title(GTK_WINDOW(window), "my app");
	gtk_window_set_default_size(GTK_WINDOW(window), 200, 200);
	gtk_widget_show_all(window);
}
int main(int argc, char **argv)
{
	GtkApplication *app;
	app = gtk_application_new("com.abed.www", G_APPLICATION_FLAGS_NONE);
	g_signal_connect(app, "activate", G_CALLBACK(aktivieren), NULL);
	g_application_run(G_APPLICATION(app), argc, argv);


	

	g_object_unref(app);
}

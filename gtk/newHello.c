#include <gtk/gtk.h>

static void callback(GtkWidget *widget, gpointer data)
{
	g_print("Hello again\n");
}

static gboolean delete_event(GtkWidget *widget, GdkEvent *event, gpointer data)
{
	//gtk_main_quit();
	return FALSE;
}

int main(int argc, char *argv[])
{
	GtkWidget *window;
	GtkWidget *button;
	GtkWidget *button1;
	GtkWidget *buttonbox;


	gtk_init(&argc, &argv);

	window = gtk_window_new (GTK_WINDOW_TOPLEVEL);

	gtk_window_set_title(GTK_WINDOW(window), "Hello Buttons");

	g_signal_connect(window, "delete-event", G_CALLBACK(delete_event), NULL);
	g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);

	gtk_container_set_border_width(GTK_CONTAINER(window), 10);

	buttonbox = gtk_hbox_new(FALSE, 0);
	gtk_container_add(GTK_CONTAINER(window), buttonbox);

	button1 = gtk_button_new_with_label("Button 1");
	g_signal_connect(button1, "clicked", G_CALLBACK(callback), NULL);
	gtk_box_pack_start(GTK_BOX(buttonbox), button1, TRUE, TRUE, 0);

	button = gtk_button_new_with_label("Button 2");
	g_signal_connect(button, "clicked", G_CALLBACK(callback), NULL);
	gtk_box_pack_start(GTK_BOX(buttonbox), button, TRUE, TRUE, 0);

	button = gtk_button_new_with_label("Quit");
	g_signal_connect_swapped(button, "clicked", G_CALLBACK(gtk_widget_destroy), window);
	gtk_box_pack_start(GTK_BOX(buttonbox), button, TRUE, TRUE, 0);

	gtk_widget_show_all(window);

	gtk_main();
}

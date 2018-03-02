#include <gtk/gtk.h>
#include <string.h>

int status = 0;

static void destroy(GtkWidget* window, gpointer data)
{
	gtk_main_quit();
}


static gboolean delete_event(GtkWidget *window, GdkEvent *event, gpointer data);

static void changeIt(GtkWidget *widget, gpointer data)
{
	gtk_label_set_markup(GTK_LABEL(widget), "<span style='italic' foreground='red'>I have changed</span>");
}

int main(int argc, char **argv)
{

	if (argc > 1)
	{
	if (!strcmp((argv[1]) ,  "true"))
		status = 1;
	}
		

	GtkWidget *window, *label, *button, *button1,  *butbox ;
	gtk_init(&argc, &argv);

	window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
	gtk_window_set_title(GTK_WINDOW(window), "Hello World!");
	butbox = gtk_vbox_new(TRUE, 3);

	gtk_container_add(GTK_CONTAINER(window), butbox);
	gtk_container_set_border_width(GTK_CONTAINER(window), 10);

	gtk_widget_set_size_request(window, 200, 100);

	g_signal_connect(G_OBJECT(window), "destroy", G_CALLBACK(destroy), NULL);
	g_signal_connect(G_OBJECT(window), "delete_event", G_CALLBACK(delete_event), NULL);


	label = gtk_label_new("Hello World");
	gtk_box_pack_start(GTK_BOX(butbox), label, TRUE, TRUE, 1);

	button = gtk_button_new_with_label("click me");
	g_signal_connect_swapped(G_OBJECT(button), "clicked", G_CALLBACK(changeIt), label);


	gtk_box_pack_start(GTK_BOX(butbox), button, TRUE, TRUE, 1);

	button1 = gtk_button_new_with_label("Exit");
	g_signal_connect_swapped(G_OBJECT(button1), "clicked", G_CALLBACK(gtk_widget_destroy), button);
	g_signal_connect(G_OBJECT(button), "delete_event", G_CALLBACK(delete_event), NULL);

	gtk_box_pack_start(GTK_BOX(butbox), button1, TRUE, TRUE, 1);


	gtk_widget_show_all(window);


	gtk_main();
	return 0;
}

static gboolean delete_event(GtkWidget *window, GdkEvent *event, gpointer data)
{
/*	if (status == 1)
	{
		return TRUE;
	}else
		return FALSE;
		*/
	return TRUE;
}

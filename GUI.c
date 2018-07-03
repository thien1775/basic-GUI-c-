#include <gtk/gtk.h>
#include <glib.h>
#include <stdio.h>


GtkWidget *button1;
GtkWidget *button2;
GtkWidget *window;
temp = 0;
void
print_hello(GtkWidget * widget, gpointer   data)
{
	g_print("Hello World %d\n", temp);
	temp++;
}

int
main(int argc, char *argv[])
{
	GtkWidget *box;


	gtk_init(&argc, &argv);

	window = gtk_window_new(GTK_WINDOW_TOPLEVEL);

	button1 = gtk_button_new_with_label("approach 1");
	button2 = gtk_button_new_with_label("approach 2");

	box = gtk_box_new(GTK_ORIENTATION_VERTICAL, 10);
	gtk_box_pack_start(GTK_BOX(box), button1, TRUE, TRUE,
		10);
	gtk_box_pack_start(GTK_BOX(box), button2, TRUE, TRUE,
		10);

	gtk_container_add(GTK_CONTAINER(window), box);
	gtk_widget_show_all(window);

	g_signal_connect(window, "destroy",
		G_CALLBACK(gtk_main_quit), NULL);
	g_signal_connect(button1, "clicked",
		G_CALLBACK(print_hello),
		window);
	g_signal_connect(button2, "clicked",
		G_CALLBACK(print_hello),
		window);
	const gchar *str1;
	const gchar *str2;
	for (int i = 0; i < 10; i++) {
		asprintf(&str1, "hello %d", temp);
		asprintf(&str2, "hello %d", temp + 1);
		gtk_button_set_label(button1, str1);
		gtk_button_set_label(button2, str2);
	}
	gtk_main();

	return 0;
}

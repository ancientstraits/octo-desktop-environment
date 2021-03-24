#include <gio/gio.h>
#include <gtk/gtk.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <function.h>

#include <gtk_function.h>

int main(int argc, char *argv[]) {
	GtkWidget *window, *button, *fixed, *fixed2, *scroll, *view, *img;
	GtkBuilder *builder;
	GError *error = NULL;
	gtk_init(&argc, &argv);

	builder = gtk_builder_new();
	if (gtk_builder_add_from_file(builder, "ui/octo.xml", &error) == 0) {
		if (gtk_builder_add_from_file(builder, "/usr/share/octo/octo.xml", error))
		{
		g_printerr("Error loading file: %s\n", error->message);
		g_clear_error(&error);
		return 1;
		
			
	}}

	window = gtk_builder_get_object(builder, "window");
	gtk_window_set_title(GTK_WINDOW(window), "Octo");
	fixed = gtk_builder_get_object(builder, "fixed");
	img = gtk_builder_get_object(builder, "background");
	scroll = gtk_builder_get_object(builder, "scroll");
	view = gtk_builder_get_object(builder, "view");
	fixed2 = gtk_builder_get_object(builder, "fixed2");
	GList *l;
	int x = 30;
	int y = 30;
	gtk_window_fullscreen(GTK_WINDOW(window));
	for (l = g_app_info_get_all(); l != NULL; l = l->next) {
		char *name_data = g_app_info_get_display_name(l->data);
		char buffer[11];
		substr(buffer, sizeof(buffer), name_data, 10);

		button = gtk_button_new_with_label(buffer);
		gtk_widget_set_size_request(button, 150, 150);
		gtk_widget_set_opacity(button, .625);
		GAppInfo *cool = l->data;
		g_signal_connect(button, "clicked", G_CALLBACK(execute), cool);
		gtk_fixed_put(GTK_FIXED(fixed2), button, x, y);
		if (y == 510) {
			y = 30;
			x = x + 160;
		} else {
			y = y + 160;
		}
	}
	gtk_widget_show_all(window);
	g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);
	gtk_main();

	return 0;
}

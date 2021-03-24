#include <gtk/gtk.h>

#include <gtk_function.h>

void execute(GtkApplication *app, gpointer data){
	g_app_info_launch(data, NULL, NULL, NULL);
	abort();
}

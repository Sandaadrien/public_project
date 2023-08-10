#include <stdio.h>
#include <gtk/gtk.h>

int main(int argc , char ** argv) {
	
	gtk_init(&argc , &argv);
	
	GtkWidget * window;
	GtkWidget * img;
	
//	GtkWidget * bouton;
	
//	button = gtk_button_new_with_label("boutton");
	
	window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
	
	g_signal_connect(G_OBJECT(window),"destroy",G_CALLBACK(gtk_main_quit),NULL);
	
	gtk_container_set_border_width(GTK_CONTAINER(window),20);
	
	gtk_window_set_title(GTK_WINDOW(window),"boutons et images");
	gtk_window_set_default_size(GTK_WINDOW(window),400,300);
	
	gtk_window_set_position(GTK_WINDOW(window),GTK_WIN_POS_CENTER);
	
	img = gtk_image_new_from_file("img.png");
	gtk_container_add(GTK_CONTAINER(window),img);
	
	
	
	
	gtk_widget_show_all(window);
	
	gtk_main();
	
	return EXIT_SUCCESS;
}

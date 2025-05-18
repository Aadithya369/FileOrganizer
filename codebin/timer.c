#include <gtk/gtk.h>
#include <time.h>
int main(int agrc, char **argv){
	GtkApplication *app = gtk_application_new("FOCUS TIMER",G_APPLICATION_DEFAULT_FLAGS);
	GtkWidget *clock;
	GtkWidget *start_button;
	GtkWidget *stop_button;
	GtkWidget *cancel_button;		

	clock = gtk_button_new_with_label("CLOCK");
	start_button = gtk_button_new_with_label("START");
	stop_button = gtk_button_new_with_label("STOP");
	cancel_buttom = gtk_button_new_with_label("CANCEL");

	g_signal_connect(app,"activate",,NULL);

}

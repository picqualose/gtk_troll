#include <gtk/gtk.h>

///// FONCTION /////

//Fonction permettant de quitter l'application (trivial)
void destroy (GtkWidget *widget, gpointer data)
{
    gtk_main_quit ();
}


///// MAIN /////

int main (int argc, char *argv[])
{
    //Declaration
    
    GtkWidget *window;
    GtkWidget *box1;
    GtkWidget *box2;
    GtkWidget *button_o;    
    GtkWidget *button_n;

    gtk_init (&argc, &argv);
//*CRER*//
    window = gtk_window_new (GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title (GTK_WINDOW (window), "ATTENTION ALERTE CRITIQUE !");

        //Box du Message 
    box1 = gtk_vbox_new(FALSE, 0);
        //Box boutons "Oui - Non "
    box2 = gtk_hbox_new(FALSE, 0);  

    gtk_container_add (GTK_CONTAINER (window), box1);


//*RELIER*//


//*AFFICHER*//

    gtk_widget_show (window);
    gtk_main ();
    return 0;
}


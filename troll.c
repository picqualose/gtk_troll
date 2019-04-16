#include <gtk/gtk.h>

///// FONCTION /////

//Fonction permettant de quitter l'application (trivial)
void destroy (GtkWidget *widget, gpointer data)
{
    gtk_main_quit ();
}

void oui  (GtkWidget *widget, gpointer data)
{
    g_print ("oui\n");
   
    GtkWidget *button_o;    
    
    //Definitions des boutons  
    button_o = gtk_button_new_with_label ("Non");

}

void non  (GtkWidget *widget, gpointer data)
{
    g_print ("non\n");
   
    GtkWidget *button_n;    
    
    //Definitions des boutons  
    button_n = gtk_button_new_with_label ("oui");

}



///// MAIN /////

int main (int argc, char *argv[])
{
    //Declaration
    
    GtkWidget *window;
    GtkWidget *box_principal;
    GtkWidget *box1;
    GtkWidget *box2;
    GtkWidget *button_o;    
    GtkWidget *button_n;
    GtkWidget *label;
    GtkWidget *image;

    gtk_init (&argc, &argv);

/// DEFINITION DES OBJETS 

    //creation de la fenetre 
    window = gtk_window_new (GTK_WINDOW_TOPLEVEL);
    //changement titre fenetre 
    gtk_window_set_title (GTK_WINDOW (window), "ATTENTION ALERTE CRITIQUE !");

    //Affichage de la fenetre 
    gtk_widget_show (window);


    //Definition des boxs
        //Box Principale qui contient tout
    box_principal = gtk_vbox_new(FALSE, 0);
        //Box du Message 
    box1 = gtk_vbox_new(FALSE, 0);
        //Box boutons "Oui - Non "
    box2 = gtk_hbox_new(FALSE, 0);  

    

    //Definitions des boutons  
    button_o = gtk_button_new_with_label ("Oui");
    button_n = gtk_button_new_with_label ("Non");
    label = gtk_label_new("FAIS LE BASIOU");
    
    //Image 
    image = gtk_image_new_from_file ("images/blob.png");


///MISE EN PLACE 

    //Ajout de la box principale dans la fenetre
    gtk_container_add (GTK_CONTAINER (window), box_principal);

    // Mise en place des box 1 et 2 dans la box principales
    gtk_box_pack_start(GTK_BOX(box_principal), box1, TRUE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(box_principal), box2, TRUE, FALSE, 0);
    // Mise en place du texte dans la box 1 
    gtk_box_pack_start(GTK_BOX(box1), image, TRUE, TRUE, 0);
    gtk_box_pack_start(GTK_BOX(box1), label, TRUE, TRUE, 0);

    // Mise en place des boutons oui et non dans la box2
    gtk_box_pack_start(GTK_BOX(box2), button_o, TRUE, TRUE, 0);
    gtk_box_pack_start(GTK_BOX(box2), button_n, TRUE, TRUE, 0);
   
//FONCTIONS DES ELEMENTS 
    // Appelle d'une fonction si on clique dessus
    gtk_signal_connect (GTK_OBJECT (button_o), "clicked", GTK_SIGNAL_FUNC(oui), NULL);
    gtk_signal_connect (GTK_OBJECT (button_n), "clicked", GTK_SIGNAL_FUNC(non), NULL);


    //Afficheage des elements 
   gtk_widget_show (image); 
   gtk_widget_show (label); 
   gtk_widget_show (button_o); 
   gtk_widget_show (button_n); 
   gtk_widget_show (box_principal); 
   gtk_widget_show (box1); 
   gtk_widget_show (box2); 
   gtk_widget_show (window); 
    
    gtk_main ();
    return 0;
}


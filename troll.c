#include <gtk/gtk.h>

///// FONCTION /////

//Fonction permettant de quitter l'application (trivial)
void destroy (GtkWidget *widget, gpointer data)
{
    gtk_main_quit ();
}

void oui  (GtkWidget *widget, gpointer data)
{
   gchar* bouton;
   gchar* bouton2;
   bouton = gtk_button_get_label ((GtkButton*) widget);
   bouton2 = gtk_button_get_label ((GtkButton*) data);
   

  // g_print ("%s\n",bouton2);
  // g_print ("%s\n",bouton);

/*PROBLEME :  Caractere non UTF8 qui s'incrementent au bout de deux changements. 
  On pense que c'est du au fait qu'on change le label du bouton alors que c'est une 
  variable constante a la base. 
  A CHERCHER MAIS PAS TRES IMPORTANT ! */
 // gtk_button_set_label( (GtkButton*) widget, bouton2 ) ;  
 // gtk_button_set_label( (GtkButton*) data, bouton ) ;  

    
   //En attendant, on remplace par ca, qui fonctionne tout aussi bien : 

     gtk_button_set_label( (GtkButton*) widget, "Oui" ) ; 
     gtk_button_set_label( (GtkButton*) data, "Non" ) ;  

}

static gboolean mouse(GtkWidget *widget,gpointer user_data) {
    g_print("bouge\n") ;
}




///// MAIN /////

int main (int argc, char *argv[])
{
    //Declaration
    
    GtkWidget *window;
    GtkWidget *box_principal;
    GtkWidget *box1;
    GtkWidget *box2;
    GtkWidget *box_up;
    GtkWidget *button_o;    
    GtkWidget *button_n;
    GtkWidget *label;
    GtkWidget *image;
    GtkWidget *barre;
    GtkWidget *button_quit;


    gtk_init (&argc, &argv);

/// DEFINITION DES OBJETS 

    //creation de la fenetre 
    window = gtk_window_new (GTK_WINDOW_TOPLEVEL);
    //changement titre fenetre 
    gtk_window_set_title (GTK_WINDOW (window), "BlobFish");

    //Affichage de la fenetre 
    gtk_widget_show (window);


    //Definition des boxs
        //Box Principale qui contient tout
    box_principal = gtk_box_new( GTK_ORIENTATION_VERTICAL, 0);
        //Box du Message 
    box1 = gtk_box_new( GTK_ORIENTATION_VERTICAL, 0);
        //Box boutons "Oui - Non "
    box2 = gtk_box_new( GTK_ORIENTATION_HORIZONTAL, 0);
        //Box Up
    box_up = gtk_box_new( GTK_ORIENTATION_HORIZONTAL, 0);
 
    

    //Definitions des boutons 

    button_o = gtk_button_new ();
    gtk_button_set_label ((GtkButton*)button_o,"Oui");
    button_n = gtk_button_new ();
    gtk_button_set_label ((GtkButton*)button_n,"Non");

  //  button_o = gtk_button_new_with_label ("Oui");
  //  button_n = gtk_button_new_with_label ("Non");
    button_quit = gtk_button_new ();
    //gtk_button_set_image (button_quit, "/image/blob.png");
    label = gtk_label_new("FAIS LE BASIOU");
    
    //Image 
    image = gtk_image_new_from_file ("images/blob.png");

    //Barre 
      barre = gtk_level_bar_new();

    ///MISE EN PLACE 

    //Ajout de la box principale dans la fenetre
    gtk_container_add (GTK_CONTAINER (window), box_principal);

    // Mise en place des box 1 et 2 dans la box principales
    gtk_box_pack_start(GTK_BOX(box_principal), box_up, TRUE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(box_principal), box1, TRUE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(box_principal), box2, TRUE, FALSE, 0);
    // Mise en place du texte dans la box 1 
    gtk_box_pack_start(GTK_BOX(box1), image, TRUE, TRUE, 0);
    gtk_box_pack_start(GTK_BOX(box1), label, TRUE, TRUE, 0); 
    gtk_box_pack_start(GTK_BOX(box1), barre, TRUE, TRUE, 0);
    
    // Mise en place des boutons oui et non dans la box2
    gtk_box_pack_start(GTK_BOX(box2), button_o, TRUE, TRUE, 0);
    gtk_box_pack_start(GTK_BOX(box2), button_n, TRUE, TRUE, 0);
   
//FONCTIONS DES ELEMENTS 
    // Appelle d'une fonction si on clique dessus
     g_signal_connect (button_o, "enter", G_CALLBACK(oui), button_n);
     g_signal_connect (button_n, "enter", G_CALLBACK(oui), button_o);
//     g_signal_connect (button_n, "enter",  G_CALLBACK(mouse), NULL);
//     g_signal_connect (GTK_OBJECT (button_n), "enter", GTK_SIGNAL_FUNC(mouse), NULL);


    //Afficheage des elements 
   gtk_widget_show (image); 
   gtk_widget_show (label); 
   gtk_widget_show (button_o); 
   gtk_widget_show (button_n); 
   gtk_widget_show (box_principal); 
   gtk_widget_show (box1); 
   gtk_widget_show (box2); 
   gtk_widget_show (window); 
   gtk_widget_show (barre);
   gtk_widget_show (box_up);

    
    gtk_main ();
    return 0;
}


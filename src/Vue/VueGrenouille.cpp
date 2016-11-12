/***************************************
*Definition de la classe VueGrenouille *
***************************************/

#include "../Presentateur/Presentateur.hpp"



/**
* Initialiser
*/

void 
VueGrenouille::initialiser(){
// Créations des pixbufs.
images_["grenouilloland"] =
Gdk::Pixbuf::create_from_file(cheminImages_ + "coeur.png");
images_["morte"] =
Gdk::Pixbuf::create_from_file(cheminImages_ + "grand-nenuphare-rouge-96x96.png");
images_["vivante"] =
Gdk::Pixbuf::create_from_file(cheminImages_ + "grand-nenuphare-jaune-96x96.png");
}

/**
* LiretitreVue
*/

const Glib::ustring 
VueGrenouille::lireTitreVue(){
return titreVue;
}

/**
*LireTitreGrenouille
*/

const Glib::ustring 
VueGrenouille::lireTitreGrenouille{
return titreGrenouille;
}

/**
*LireTitreDimension
*/

const Glib::ustring 
VueGrenouille::lireTitreDimension(){
return titreDimension;
}

/**
*lireImage
*/

const Glib::RefPtr< Gdk::Pixbuf>& 
VueGrenouille::lireImage(const Glib::ustring& nom) {
return images[nom];
}


/**
* VueGrenouille Constructeur
*/
VueGrenouille::Vue(Presentateur& presentateur):
presentateur(presentateur),
ptrgrenouilleGraph(new grenouilleGraphique(titregrenouille,*this)),
dimension(titreDimension,*this) {

// Titre de la vue.
set_title(titreVue);

// Gestionnaire de mise en forme associé à la fenêtre principale.
Gtk::VBox* gestionnaire = Gtk::manage(new Gtk::VBox());
add(*gestionnaire);

// Construction de la barre de menus et d'outils.
construireBarreMenusEtOutils(*gestionnaire);

// Construction de la partie centrale de la fenêtre principale.
construirePartieCentrale(*gestionnaire);

// Construction de la partie inférieure de la fenêtre principale.
construirePartieInferieure(*gestionnaire);

// La fenêtre principale est rendue non redimensionnable. Cela permettra de
// forcer le recalcul des dimensions lorsque la dimension du jeu de la vie
// sera modifiée.
set_resizable(false);

// Affichage de tous les composants graphiques.
show_all_children();

}



/**
* lirePresentateur
*/  
const Presentateur& 
VueGrenouille::lirePresentateur() const{
return presentateur;
}


/*
* construireBarreMenusEtOutils. *
*/

void
VueGrenouille::construireBarreMenusEtOutils(Gtk::VBox& gestionnaire) {

// Groupe d'actions.
Glib::RefPtr< Gtk::ActionGroup > groupe = Gtk::ActionGroup::create();
groupe->add(Gtk::Action::create("CommandesMenu",
			  "Commandes"));

// Action "Nouveau".
{
Glib::RefPtr< Gtk::Action > action =
Gtk::Action::create("CommandesNouveau",
			  Gtk::Stock::NEW,
			  "Nouvelle partie",
			  "Préparer une nouvelle simulation.");
auto crochet = sigc::mem_fun(*this, &VueGrenouille::cbNouveau);
groupe->add(action, crochet);
}

// Action "A propos ...".
{
Glib::RefPtr< Gtk::Action > action =
Gtk::Action::create("CommandesAPropos",
			  Gtk::Stock::ABOUT,
			  "À propos ...",
			  "Présenter l'application.");
auto crochet = sigc::mem_fun(*this, &VueGrenouille::cbAPropos);
groupe->add(action, crochet);
}

// Action "Quitter".
{
Glib::RefPtr< Gtk::Action > action =
Gtk::Action::create("CommandesQuitter",
			  Gtk::Stock::QUIT,
			  "Quitter",
			  "Quitter l'application.");
auto crochet = sigc::mem_fun(*this, &VueGrenouille::cbQuitter);
groupe->add(action, crochet);
}

// Manager des groupes d'actions.
Glib::RefPtr< Gtk::UIManager > manager = Gtk::UIManager::create();
manager->insert_action_group(groupe);
add_accel_group(manager->get_accel_group());

// Structures XML des barres de menus et d'outils.
const Glib::ustring structures =
"<ui>"
"  <menubar name='BarreMenus'>"
"    <menu action='CommandesMenu'>"
"      <menuitem action='CommandesNouveau'/>"
"      <menuitem action='CommandesAPropos'/>"
"      <separator/>"
"      <menuitem action='CommandesQuitter'/>"
"    </menu>"
"  </menubar>"
"  <toolbar  name='BarreOutils'>"
"    <toolitem action='CommandesNouveau'/>"
"    <toolitem action='CommandesAPropos'/>"
"    <toolitem action='CommandesQuitter'/>"
"  </toolbar>"
"</ui>";
manager->add_ui_from_string(structures);

// Ajout des barres de menus et d'outils dans le gestionnaire. Chacun
// occupe une ligne complète de la grille.
Gtk::Widget* ptrBarreMenus = manager->get_widget("/BarreMenus");
if (ptrBarreMenus != nullptr) {
gestionnaire.pack_start(*ptrBarreMenus, Gtk::PACK_SHRINK);
}
Gtk::Widget* ptrBarreOutils = manager->get_widget("/BarreOutils");
if(ptrBarreOutils != nullptr) {
gestionnaire.pack_start(*ptrBarreOutils, Gtk::PACK_SHRINK);
}

}

/*
*construirePartieCentrale
*/

void
VueGrenouille::construirePartieCentrale(Gtk::VBox& gestionnaire) {

// Ajout du gestionnaire de mise en forme pour la partie centrale.
gestionnaire.add(gestionnaireCentre_);

// Ajout du jeu de la vie graphique dans le gestionnaire de la partie
// centrale.
gestionnaireCentre_.pack_start(*ptrgrenouilleGraph);

}

/*
*construirePartieInferieure
*/

void
VueGrenouille::construirePartieInferieure(Gtk::VBox& gestionnaire) {
gestionnaire.add(dimension);
}

/*
*cbNouveau
*/

void
VueGrenouille::cbNouveau() {

// Réinitialisation du modèle via le présentateur associé à cette vue.
presentateur.reinitialiser();

// Demander au jeu de la vie graphique de bien vouloir se mettre à jour.
ptrgrenouilleGraphique->mettreAJour(presentateur);

}

/*
*cbChangerModele
*/

void
VueGrenouille::cbChangerModele() {


// Création, via le présentateur, d'un nouveau modèle avec la dimension
// souhaitée.
presentateur.nouveauModele(dimension.valeur());

// Suppression de l'ancien jeu de la vie graphique et remplacement par le
// nouveau.
gestionnaireCentre_.remove(*ptrgrenouilleGraphique);
ptrgrenouilleGraphique.reset(new grenouilleGraphique(titregrenouille,
						*this));
gestionnaireCentre_.pack_start(*ptrgrenouilleGraphique);

// Réaffichage de tous les composants de la fenêtre principale. Le fait que
// cette dernière soit non redimensionnable entraîne le recalcul des
// dimensions de tous ses composants.
show_all_children();

}

/*
*cbAPropos()
*/

void
Vue::cbAPropos() {

// Construction du dialogue.
Gtk::AboutDialog apropos;
apropos.set_transient_for(*this);
apropos.set_program_name("Grenouille");
apropos.set_version("0.1");
apropos.set_comments("TP C++/Gtkmm du M1 Info.");
apropos.set_authors({ "M-F-S-Y" });
apropos.set_logo(images_["grenouille"]);

// Affichage du dialogue.
apropos.run();

// Effacement du dialogue.
apropos.hide();

}

/*
*cbQuitter
*/

void
Vue::cbQuitter() {
hide();
}

/*
*titreVue
*/

const Glib::ustring Vue::titreVue("Jeu Grenouille");

/*
*titreGeneration
*/

const Glib::ustring Vue::titregrenouille("Génération");

/*
*titreDimension
*/

const Glib::ustring Vue::titreDimension("Dimension");

/**
*cheminImages
*/

const Glib::ustring Vue::cheminImages("Icones/");

/*
*images
*/

std::map< Glib::ustring, Glib::RefPtr< Gdk::Pixbuf> > Vue::images_;



/********************************
* Definition de la classe VueGrenouille. *
********************************/

#include "Presentateur.hpp"

using namespace Grenouille;

/****************
* initialiser. *
****************/

void 
VueGrenouille::initialiser() {

	// Creations des pixbufs.
	images["Grenouille"] = 
	Gdk::Pixbuf::create_from_file(cheminImages + "grenouille.gif");

	images["eau"] = 
	Gdk::Pixbuf::create_from_file(cheminImages + "eau-96x96.png");

	images["nen"] = 
	Gdk::Pixbuf::create_from_file(cheminImages + "nen-96x96.png");
	images["nen_moyen"] = 
	Gdk::Pixbuf::create_from_file(cheminImages + "nen_moyen-96x96.png");
	images["nen_petit"] = 
	Gdk::Pixbuf::create_from_file(cheminImages + "nen_petit-96x96.png");

	images["nen_dopant"] = 
	Gdk::Pixbuf::create_from_file(cheminImages + "nen_dopant-96x96.png");
	images["nen_dopant_moyen"] = 
	Gdk::Pixbuf::create_from_file(cheminImages + "nen_dopant_moyen-96x96.png");
	images["nen_dopant_petit"] = 
	Gdk::Pixbuf::create_from_file(cheminImages + "nen_dopant_petit-96x96.png");

	images["nen_nutritif"] = 
	Gdk::Pixbuf::create_from_file(cheminImages + "nen_nutritif-96x96.png");
	images["nen_nutritif_moyen"] = 
	Gdk::Pixbuf::create_from_file(cheminImages + "nen_nutritif_moyen-96x96.png");
	images["nen_nutritif_petit"] = 
	Gdk::Pixbuf::create_from_file(cheminImages + "nen_nutritif_petit-96x96.png");

	images["nen_veneneux"] = 
	Gdk::Pixbuf::create_from_file(cheminImages + "nen_veneneux-96x96.png");
	images["nen_veneneux_moyen"] = 
	Gdk::Pixbuf::create_from_file(cheminImages + "nen_veneneux_moyen-96x96.png");
	images["nen_veneneux_petit"] = 
	Gdk::Pixbuf::create_from_file(cheminImages + "nen_veneneux_petit-96x96.png");

	images["gren_eau"] = 
	Gdk::Pixbuf::create_from_file(cheminImages + "gren_eau.png");

	images["gren_nen"] = 
	Gdk::Pixbuf::create_from_file(cheminImages + "gren_nen-96x96.png");
	images["gren_nen_moyen"] = 
	Gdk::Pixbuf::create_from_file(cheminImages + "gren_nen_moyen-96x96.png");
	images["gren_nen_petit"] = 
	Gdk::Pixbuf::create_from_file(cheminImages + "gren_nen_petit-96x96.png");

	images["gren_nen_dopant"] = 
	Gdk::Pixbuf::create_from_file(cheminImages + "gren_nen_dopant-96x96.png");
	images["gren_nen_dopant_moyen"] = 
	Gdk::Pixbuf::create_from_file(cheminImages + "gren_nen_dopant_moyen-96x96.png");
	images["gren_nen_dopant_petit"] = 
	Gdk::Pixbuf::create_from_file(cheminImages + "gren_nen_dopant_petit-96x96.png");

	images["gren_nen_nutritif"] = 
	Gdk::Pixbuf::create_from_file(cheminImages + "gren_nen_nutritif-96x96.png");
	images["gren_nen_nutritif_moyen"] = 
	Gdk::Pixbuf::create_from_file(cheminImages + "gren_nen_nutritif_moyen-96x96.png");
	images["gren_nen_nutritif_petit"] = 
	Gdk::Pixbuf::create_from_file(cheminImages + "gren_nen_nutritif_petit-96x96.png");

	images["gren_nen_veneneux"] = 
	Gdk::Pixbuf::create_from_file(cheminImages + "gren_nen_veneneux-96x96.png");
	images["gren_nen_veneneux_moyen"] = 
	Gdk::Pixbuf::create_from_file(cheminImages + "gren_nen_veneneux_moyen-96x96.png");
	images["gren_nen_veneneux_petit"] = 
	Gdk::Pixbuf::create_from_file(cheminImages + "gren_nen_veneneux_petit-96x96.png");
}

/*****************
* lireTitreVue. *
*****************/

const Glib::ustring 
VueGrenouille::lireTitreVue() {
	return titreVue;
}

/************************
* lireTitreGrenouille. *
************************/

const Glib::ustring 
VueGrenouille::lireTitreGrenouille() {
	return titreGrenouille;
}

/***********************
* lireTitreChronometre. *
***********************/

const Glib::ustring 
VueGrenouille::lireTitreChronometre() {
	return titreChronometre;
}

/***********************
* lireTitreDimension. *
***********************/

const Glib::ustring 
VueGrenouille::lireTitreDimension() {
	return titreDimension;
}

/**************
* lireImage. *
**************/

const Glib::RefPtr< Gdk::Pixbuf>& 
VueGrenouille::lireImage(const Glib::ustring& nom) {
	return images[nom];
}

/*****************
* VueGrenouille. *  
*****************/

VueGrenouille::VueGrenouille(Presentateur& presentateur):
_ptrPresentateur(&presentateur),
_ptrGrenouilleGraphique(new GrenouilleGraphique(titreGrenouille, *this)),
pointsDeVie(titrePointsDeVie),
_dimension(titreDimension, *this),
_chrnometre(titreChronometre) {

	// Titre de la vue.
	set_title(titreVue);

	// Icone
	set_icon(images["Grenouille"]);

	// Gestionnaire de mise en forme associe à la fenetre principal.
	Gtk::VBox* gestionnaire = Gtk::manage(new Gtk::VBox());
	add(*gestionnaire);

	// Construction de la barre de menus et d'outils.
	construireBarreMenusEtOutils(*gestionnaire);

	// Construction de la partie centrale de la fenetre principal.
	construirePartieCentrale(*gestionnaire);

	// Construction de la partie inferieure de la fenetre principal.
	construirePartieInferieure(*gestionnaire);

	set_resizable(false);

	// Affichage de tous les composants graphiques.
	show_all_children();

}

/*********************
* lirePresentateur. *
*********************/

const Presentateur& 
VueGrenouille::lirePresentateur() const {
	return *_ptrPresentateur;
}

/*******************************
* lirePresentateurModifiable. *
*******************************/

Presentateur& 
VueGrenouille::lirePresentateurModifiable() {
	return *_ptrPresentateur;
}

/****************
*  miseAJour.  *
****************/

void
VueGrenouille::mettreAJour() {

	// Mise à jour de l'affichage des points de vie de la grenouille.
	_pointDeVie.mettreAJour(*_ptrPresentateur);

	// Mise à jour des cases du Grenouille graphique.
	_ptrGrenouilleGraphique->mettreAJour(*_ptrPresentateur);

	// Mise à jour de l'affichage du chronomètre de jeu.
	_chrnometre.mettreAJour(*_ptrPresentateur);
}

/****************
* verrouiller. *
****************/

void
VueGrenouille::verrouiller() {
	_verrou.lock();
}

/*****************
* deverrouiller. *
*****************/

void
VueGrenouille::deverrouiller() {
	_verrou.unlock();
}

/*********************************
* construireBarreMenusEtOutils. *
*********************************/

void
VueGrenouille::construireBarreMenusEtOutils(Gtk::VBox& gestionnaire) {

	// Groupe d'actions.
	Glib::RefPtr< Gtk::ActionGroup > groupe = Gtk::ActionGroup::create();
	groupe->add(Gtk::Action::create("CommandesMenu", 
				  "Commandes"));

	// Action "Suivante".
	{
	Glib::RefPtr< Gtk::Action > action = 
	Gtk::Action::create("CommandesPreparer", 
			  Gtk::Stock::EXECUTE,
			  "Préparer",
			  "Préparer une nouvelle partie.");
	auto crochet = sigc::mem_fun(*this, &VueGrenouille::cbChangerModele);
	groupe->add(action, crochet); 
	}

	// Action "Nouveau".
	{
	Glib::RefPtr< Gtk::Action > action = 
	Gtk::Action::create("CommandesNouveau", 
			  Gtk::Stock::NEW,
			  "Nouvelle partie",
			  "Lancer une nouvelle partie.");
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
	"      <menuitem action='CommandesPreparer'/>"
	"      <menuitem action='CommandesNouveau'/>"
	"      <menuitem action='CommandesAPropos'/>"
	"      <separator/>"
	"      <menuitem action='CommandesQuitter'/>"
	"    </menu>"
	"  </menubar>"
	"  <toolbar  name='BarreOutils'>"
	"    <toolitem action='CommandesPreparer'/>"
	"    <toolitem action='CommandesNouveau'/>"
	"    <toolitem action='CommandesAPropos'/>"
	"    <toolitem action='CommandesQuitter'/>"
	"  </toolbar>"
	"</ui>";
	manager->add_ui_from_string(structures);

	// Ajout des barres de menus et d'outils dans le gestionnaire. Chacun
	// occupe une ligne complete de la grille.

	Gtk::Widget* ptrBarreMenus = manager->get_widget("/BarreMenus");
	if (ptrBarreMenus != nullptr) {
	gestionnaire.pack_start(*ptrBarreMenus, Gtk::PACK_SHRINK);
	}
	Gtk::Widget* ptrBarreOutils = manager->get_widget("/BarreOutils");
	if(ptrBarreOutils != nullptr) {
	gestionnaire.pack_start(*ptrBarreOutils, Gtk::PACK_SHRINK);
	}
}

/*****************************
* construirePartieCentrale. *
*****************************/

void
VueGrenouille::construirePartieCentrale(Gtk::VBox& gestionnaire) {

	_gestionnaireCentre.pack_start(_pointDeVie, Gtk::PACK_SHRINK);
	_gestionnaireCentre.pack_start(*_ptrGrenouilleGraphique);
	gestionnaire.add(_gestionnaireCentre);

}


/*******************************
* construirePartieInferieure. *
*******************************/

void 
VueGrenouille::construirePartieInferieure(Gtk::VBox& gestionnaire) {

	_gestionnaireBas.pack_start(_dimension, Gtk::PACK_SHRINK);
	_gestionnaireBas.pack_start(_chrnometre);
	gestionnaire.add(_gestionnaireBas);

}

/**************
* cbNouveau. *
**************/

void 
VueGrenouille::cbNouveau() {

	// Verrouillage.
	verrouiller();

	Presentateur::DelegationVue::lancerPartie(*_ptrPresentateur);

	// Deverrouillage.
	deverrouiller();

}

/********************
* cbChangerModele. *
********************/

void
VueGrenouille::cbChangerModele() {

	// Verrouillage.
	verrouiller();

	// Creation, via le presentateur associe a cette vue, d'un nouveau modele avec
	// la dimension souhaitee.
	const int dimension = _dimension.valeur();
	Presentateur::DelegationVue::nouveauModele(*_ptrPresentateur, dimension);

	// Suppression de l'ancienne representation graphique du jeu et remplacement
	// par une nouvelle adaptee a la nouvelle dimension.
	_gestionnaireCentre.remove(*_ptrGrenouilleGraphique);
	_ptrGrenouilleGraphique.reset(new GrenouilleGraphique(titreGrenouille, 
							*this));
	_gestionnaireCentre.pack_start(*_ptrGrenouilleGraphique);

	// Re-affichage de tous les composants de la fenetre. Le fait que cette
	// derniere soit non redimensionnable entraine le recalcul des dimensions
	// de tous ses composants.
	show_all_children();

	// Deverrouillage.
	deverrouiller();

}

/****************
* cbAPropos(). *
****************/

void 
VueGrenouille::cbAPropos() {

	// Construction du dialogue.
	Gtk::AboutDialog apropos;
	apropos.set_transient_for(*this);
	apropos.set_program_name("Grenouille");
	apropos.set_version("1.0");
	apropos.set_copyright("Marechal Charlie, Fontaine Luc, Souleiman Choukri, ");
	apropos.set_comments("Devoir C++/Gtkmm du M1 Info.");
	apropos.set_authors({ "Marechal Charlie, Fontaine Luc, Souleiman Choukri et" });
	apropos.set_logo(images["Grenouille"]);

	// Affichage du dialogue.
	apropos.run();

	// Effacement du dialogue.
	apropos.hide();

}

/**************
* cbQuitter. *
**************/

void 
VueGrenouille::cbQuitter() {

	// Verrouillage.
	verrouiller();

	// Effacement de la fenetre principale.
	hide();

	// Deverrouillage.
	deverrouiller();

}

/**************
* _titreVue. *
**************/

const Glib::ustring VueGrenouille::titreVue("Grenouille");

/*********************
* _titreGrenouille. *
*********************/

const Glib::ustring VueGrenouille::titreGrenouille("Plateau");

/********************
* _titrepointDeVie. *
********************/

const Glib::ustring VueGrenouille::titrepointDeVie("Points de vie");

/********************
* _titreDimension. *
********************/

const Glib::ustring VueGrenouille::titreDimension("Résolution");

/********************
* _titreChronometre. *
********************/

const Glib::ustring VueGrenouille::titreChronometre("Chronomètre");

/******************
* cheminImages. *
******************/

const Glib::ustring VueGrenouille::cheminImages("src/Icones/");

/************
* images. *
************/

std::map< Glib::ustring, Glib::RefPtr< Gdk::Pixbuf> > VueGrenouille::images;

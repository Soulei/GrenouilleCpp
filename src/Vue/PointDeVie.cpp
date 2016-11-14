/***************************************
* Definition de la classe Point de vie *
***************************************/

#include "Presentateur.hpp"
#include "PointDeVie.hpp"

using namespace grenouille;

/*
* Constructeur du point de vie
*/

PointDeVie::PointDeVie(const Glib::ustring& titre):
	Gtk::Frame(titre),
	_imageCoeur(VueGrenouille::cheminImages + "coeur-96*96.png")
{

	// Affichage des points de vie en "large"
	_labelPv.set_markup("<span font-size=\"large\"> 1 </span>");

	Gtk::HBox* gestionnaire = Gtk::manage(new Gtk::HBox());
	gestionnaire->pack_start(_imageCoeur);
	gestionnaire->pack_start(_labelPv);
	add(*gestionnaire);
}

/*
* mettreAJour. 
*/

void
PointDeVie::mettreAJour(const Presentateur& presentateur) {

	//On recupère les points de vie de la grenouille
	const unsigned int pv = presentateur.lireModele().lirePvGrenouille();

	// Conversion en string
	std::ostringstream conversion;
	conversion << pv;

	// Mise à jour du label
	_labelPv.set_markup("<span font-size=\"large\">" + conversion.str() + "</span>");

	// Mise à jour de l'image du coeur.
	if(presentateur.lireModele().grenouilleMalade())
<<<<<<< HEAD
		imageCoeur.set(Vue::cheminImages + "coeurEmpoisonne-96x96.png");
=======
		_imageCoeur.set(Vue::cheminImages + "coeur_malade-96x96.png");
>>>>>>> 74c69b74dbe8db3c69174fdb0ec4461261771d8e
	else
		_imageCoeur.set(Vue::cheminImages + "coeur-96x96.png");
}

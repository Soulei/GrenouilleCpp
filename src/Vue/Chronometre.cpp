/****************************
* Definition de la classe Chronometre. *
****************************/

#include "Presentateur.hpp"
#include "Chronometre.hpp"

using namespace grenouille;

/****************
* Chronometre. *
***************/

Chronometre::Chronometre(const Glib::ustring& titre):
	Gtk::Frame(titre) {
	add(_barreDeProgression);
}

/****************
* mettreAJour. *
***************/
void
Chronometre::mettreAJour(const Presentateur& presentateur) {

	// Récupération du temps de Jeu actuel.
	int temps = 60 - presentateur.lireModele().lireCompteur();

	// Fraction pour la barre de progression
	double fraction = temps / 60.0;
	_barreDeProgression.set_fraction(fraction);

	// Conversion en string pour afficher le temps.
	std::ostringstream conversion;
	conversion << temps;

	// Affichage du temps dans la barre de progression.
	_barreDeProgression.set_text(conversion.str() + " Sec.");
	_barreDeProgression.set_show_text(true);
}

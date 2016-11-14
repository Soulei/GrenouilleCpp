/*****************************************
 * Definition de la classe Presentateur. *
 *****************************************/

#include "Presentateur.hpp"
#include "Cellule.hpp"

using namespace grenouilloland;

/*****************
 * Presentateur. *
 *****************/

Presentateur::Presentateur(const int& dimMin,
	const int& dimMax,
	const int& dimension):
	_dimMin(dimMin),
	_dimMax(dimMax),
	_ptrModele(new Jeu(dimension)),
	_ptrVue(new VueGrenouille(*this)),
	_vieillissement(sigc::mem_fun(*this, &Presentateur::vieillissement))
{
}

/**************
 * dimension. *
 **************/

const int&
Presentateur::dimension() const {
  return _ptrModele->lireDimension();
}

/*************************
 * lireDimMin. *
 *************************/

const int&
Presentateur::lireDimMin() const {
  return _dimMin;
}

/*************************
 * lireDimMax. *
 *************************/

const int&
Presentateur::lireDimMax() const {
  return _dimMax;
}

/***************
 * lireModele. *
 ***************/

const Jeu&
Presentateur::lireModele() const {
  return *_ptrModele;
}

/************
 * lireVue. *
 ************/

const VueGrenouille&
Presentateur::lireVue() const {
  return *_ptrVue;
}



/*************
 * demarrer. *
 *************/

void
Presentateur::demarrer() {
  Gtk::Main::run(*_ptrVue);
}

/*******************
 * vieillissement. *
 *******************/

bool
Presentateur::vieillissement() {

	// Lance le vieillissement du Jeu.
	bool ret = Jeu::Delegation::vieillissement(*_ptrModele);

	// Met la VueGrenouille à jour.
	VueGrenouille::Delegation::mettreAJour(*_ptrVue);
	return ret;
}

/*******************
 * lancerPartie. *
 *******************/

void
Presentateur::lancerPartie() {

	// Déconnecte le connecteur pour stopper une éventuelle partie.
	_conn.disconnect();

	// Réinitialise le Jeu.
	Jeu::Delegation::reinitialiser(*_ptrModele);

	if (_ptrModele->end()) {

		// Démarre le Jeu.
		Jeu::Delegation::lancerPartie(*_ptrModele);

		// Lance la création du premier chemin de nénuphars.
		Jeu::Delegation::creerChemin(*_ptrModele);

		// MAJ de la VueGrenouille.
		VueGrenouille::Delegation::mettreAJour(*_ptrVue);

		// Connecte le connecteur au slot _vieillissement avec un timer d'une seconde.
		// La méthode vieillissement sera ainsi lancé toutes les secondes.
		_conn = Glib::signal_timeout().connect(_vieillissement, 1000);
	}
}

/***********************
 * deplacerGrenouille. *
 ***********************/

bool
Presentateur::deplacerGrenouille(const int& ligne, const int& colonne) {
	if (Jeu::Delegation::deplacerGrenouille(*_ptrModele, colonne, ligne)) {

		// MAJ de la VueGrenouille.
		VueGrenouille::Delegation::mettreAJour(*_ptrVue);
		return true;
	}
	return false;
}

/******************
 * nouveauModele. *
 ******************/

void
Presentateur::nouveauModele(const int& dimension) {
	_ptrModele.reset(new Jeu(dimension));
}

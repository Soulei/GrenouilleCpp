/************************************************
 * Definition de la classe GrenouilleGraphique. *
 ************************************************/

#include "Presentateur.hpp"

using namespace grenouilloland;

/************************
 * GenerationGraphique. *
 ************************/

GrenouilleGraphique::GrenouilleGraphique(const Glib::ustring& titre, VueGrenouille& vue):
  	Gtk::AspectFrame(titre),
  	_ptrVue(&vue) {

  	// Ajout du gestionnaire dans le contours.
  	add(_gestionnaire);

  	// Recuperation du presentateur associe a la vue proprietaire.
  	const Presentateur& presentateur = vue.lirePresentateur();

  	// Recuperation du modele via le presentateur.
  	const Jeu& modele = presentateur.lireModele();

  	// Recuperation de dimension du modele.
  	const int& dim = modele.lireDimension();

  	// Boucle de creation des cellules graphiques.
  	for (int i = 0; i < dim*dim; i ++) {
      	CelluleGraphique* c = Gtk::manage(new CelluleGraphique(*this, i%dim, i/dim));
      	_gestionnaire.attach(*c, i%dim, i/dim, 1, 1);
      	_cellules.push_back(c);
    }
}

/************
 * lireVue. *
 ************/

const VueGrenouille& 
GrenouilleGraphique::lireVue() const {
  return *_ptrVue;
}

/**********************
 * lireVueModifiable. *
 **********************/

VueGrenouille&
GrenouilleGraphique::lireVueModifiable() {
  return *_ptrVue;
}

/****************
 * mettreAJour. *
 ****************/

void
GrenouilleGraphique::mettreAJour(const Presentateur& presentateur) {
  for (CelluleGraphique* ptrCellule : _cellules) {
    ptrCellule->mettreAJour(presentateur);
  }
}

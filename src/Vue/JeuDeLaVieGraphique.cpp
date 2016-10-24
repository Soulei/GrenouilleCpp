/************************************************
 * Définition de la classe JeuDeLaVieGraphique. *
 ************************************************/

#include "Presentateur.hpp"

/************************
 * GenerationGraphique. *
 ************************/

JeuDeLaVieGraphique::JeuDeLaVieGraphique(const Glib::ustring& titre, Vue& vue):
  Gtk::AspectFrame(titre),
  vue_(vue) {

  // Ajout du gestionnaire dans le contour.
  add(gestionnaire_);

  // Obtention du presentateur associe a la vue proprietaire.
  const Presentateur& presentateur = vue.lirePresentateur();

  // Obtention du modèle via le présentateur.
  const JeuDeLaVie& modele = presentateur.lireModele();

  // Obtention de dimension du modèle.
  const int& dimension = modele.lireDimension();
    
  // Boucle de création des cellules graphiques.
  for (int i = 0; i < dimension; i ++) {
    for (int j = 0; j < dimension; j ++) {
      CelluleGraphique* cellule = 
	Gtk::manage(new CelluleGraphique(*this, i, j));
      gestionnaire_.attach(*cellule, i, j, 1, 1);
      cellules_.push_back(cellule);
    }
  }

}

/************
 * lireVue. *
 ************/

const Vue& 
JeuDeLaVieGraphique::lireVue() const {
  return vue_;
}

/**********************
 * lireVueModifiable. *
 **********************/

Vue& 
JeuDeLaVieGraphique::lireVueModifiable() {
  return vue_;
}

/****************
 * mettreAJour. *
 ****************/

void 
JeuDeLaVieGraphique::mettreAJour(const Presentateur& presentateur) {
  for (CelluleGraphique* ptrCellule : cellules_) {
    ptrCellule->mettreAJour(presentateur);
  }
}

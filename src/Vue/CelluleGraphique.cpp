/*********************************************
 * Définition de la classe CelluleGraphique. *
 *********************************************/

#include "Presentateur.hpp"

/*********************
 * CelluleGraphique. *
 *********************/

CelluleGraphique::CelluleGraphique(JeuDeLaVieGraphique& jeuDeLaVieGraphique,
				   const int& ligne,
				   const int& colonne):
  jeuDeLaVieGraphique_(jeuDeLaVieGraphique),
  ligne_(ligne),
  colonne_(colonne) {

  // Obtention de la vue.
  const Vue& vue = jeuDeLaVieGraphique.lireVue();

  // Obtention du présentateur.
  const Presentateur& presentateur = vue.lirePresentateur();

  // Création des pixmaps représentants les états d'une cellule.
  {
      
    // Renommage de type local.
    typedef std::unique_ptr< Gtk::Image > Pointer;

    // La cellule est morte.
    etats_[false] = Pointer(new Gtk::Image(vue.lireImage("morte")));

    // La cellule est vivante.
    etats_[true] = Pointer(new Gtk::Image(vue.lireImage("vivante")));

  }

  // Connection du callback associé au click de souris.
  {
    auto crochet = sigc::mem_fun(*this, &CelluleGraphique::cbClickSouris);
    signal_button_press_event().connect(crochet);
  }

  // Mise à jour de cette cellule graphique.
  mettreAJour(presentateur);

}

/****************************
 * lireJeuDeLaVieGraphique. *
 ****************************/

const JeuDeLaVieGraphique& 
CelluleGraphique::lireJeuDeLaVieGraphique() const {
  return jeuDeLaVieGraphique_;
}

/**************
 * lireLigne. *
 **************/

const int& 
CelluleGraphique::lireLigne() const {
  return ligne_;
}

/****************
 * lireColonne. *
 ****************/

const int& 
CelluleGraphique::lireColonne() const {
  return colonne_;
}

/****************
 * mettreAJour. *
 ****************/

void 
CelluleGraphique::mettreAJour(const Presentateur& presentateur) {
  
  // Obtention du nouvel état de la cellule du modèle correspondante via le 
  // présentateur.
  const bool etat = presentateur.estVivante(ligne_, colonne_);

  // Obtention du pixmap correspondant.
  Gtk::Image& image = *etats_[etat];
  
  // Si l'état de cette cellule n'a pas changé, il n'y a rien à faire.
  if (&image == get_child()) {
    return;
  }

  // Sinon, suppression de l'ancien pixmap et affichage du nouveau.
  remove();
  add(image);
  image.show();

}

/******************
 * cbClickSouris. *
 ******************/

bool 
CelluleGraphique::cbClickSouris(GdkEventButton* evt) {

  // Obtention de la vue modifiable.
  Vue& vue = jeuDeLaVieGraphique_.lireVueModifiable();

  // Obtention du présentateur modifiable associé à la vue.
  Presentateur& presentateur = vue.lirePresentateurModifiable();

  // Demander au présentateur de bien vouloir faire basculer la cellule du
  // modèle correspondante.
  presentateur.basculer(ligne_, colonne_);

  // Mise à jour de cette cellule graphique.
  mettreAJour(presentateur);

  // Systématiquement retourner la valeur vrai.
  return true;

}

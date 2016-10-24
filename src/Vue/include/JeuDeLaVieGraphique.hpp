#ifndef JeuDeLaVieGraphique_hpp
#define JeuDeLaVieGraphique_hpp

#include "CelluleGraphique.hpp"
#include <gtkmm/aspectframe.h>
#include <gtkmm/grid.h>
#include <vector>

// Déclaration incomplète de la classe Vue.
class Vue;

/**
 * @class JeuDeLaVieGraphique JeuDeLaVieGraphique.hpp
 *
 * Déclaration de la classe JeuDeLaVieGraphique représentant une génération
 * de cellules graphiques.
 *
 * @note Une instance de cette classe ne peut être dupliquée implicitement.
 */
class JeuDeLaVieGraphique: public Gtk::AspectFrame {
public:

  // Déclarations d'amitié envers les classes Vue et CelluleGraphique.
  friend class Vue;
  friend class CelluleGraphique;

public:

  /**
   * Constructeur logique.
   *
   * @param[in] titre - le titre du contour.
   * @param[in,out] vue - la valeur de @ref vue_.
   */
  JeuDeLaVieGraphique(const Glib::ustring& titre, Vue& vue);

public:

  /**
   * Accesseur.
   *
   * @return la valeur de @ref vue_.
   */
  const Vue& lireVue() const;

protected:

  /**
   * Accesseur.
   *
   * @return la valeur de @ref vue_.
   */
  Vue& lireVueModifiable();

protected:

  /**
   * Met à jour l'ensemble des cellules graphiques de ce jeu de la vie 
   * graphique.
   *
   * @param[in] presentateur - le présentateur a invoquer.
   */
  void mettreAJour(const Presentateur& presentateur);

protected:

  /**
   * Vue propriétaire de ce jeu de la vie graphique.
   */
  Vue& vue_;

  /**
   * Gestionnaire de mise en forme de ce jeu graphique.
   */
  Gtk::Grid gestionnaire_;

  /**
   * Cellules graphiques de ce jeu de la vie graphique.
   */
  std::vector< CelluleGraphique* > cellules_;

};

#endif

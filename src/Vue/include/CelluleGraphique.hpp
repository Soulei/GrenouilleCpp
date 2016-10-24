#ifndef CelluleGraphique_hpp
#define CelluleGraphique_hpp

#include <gtkmm/eventbox.h>
#include <gtkmm/image.h>
#include <map>
#include <memory>

// Déclarations incomplètes des classes Presentateur et JeuDeLaVieGraphique.
class Presentateur;
class JeuDeLaVieGraphique;

/**
 * @class CelluleGraphique CelluleGraphique.hpp 
 *
 * Déclaration de la classe CelluleGraphique représentant graphiquement une
 * cellule du modèle.
 *
 * @note Une instance de cette classe ne peut être dupliquée implicitement. 
 * @note Chaque instance de cette classe est son propre listener.
 */
class CelluleGraphique: public Gtk::EventBox {
public:

  // Déclaration d'amitié envers la classe JeuDeLaVieGraphique.
  friend class JeuDeLaVieGraphique;

public:

  /**
   * Constructeur logique.
   *
   * @param[in,out] jeuDeLaVie - la valeur de @ref jeuDeLaVieGraphique_.
   * @param[in] ligne - la valeur de @ref ligne_.
   * @param[in] colonne - la valeur de @ref colonne_.
   */
  CelluleGraphique(JeuDeLaVieGraphique& jeuDeLaVieGraphique,
		   const int& ligne,
		   const int& colonne);

  /**
   * Constructeur par recopie.
   *
   * @param[in] autre - l'instance a recopier.
   */
  CelluleGraphique(const CelluleGraphique& autre) = delete;

public:

  /**
   * Accesseur.
   *
   * @return la valeur de @ref jeuDeLaVieGraphique_.
   */
  const JeuDeLaVieGraphique& lireJeuDeLaVieGraphique() const;

  /**
   * Accesseur.
   *
   * @return la valeur de @ref ligne_.
   */
  const int& lireLigne() const;

  /**
   * Accesseur.
   *
   * @return la valeur de @ref colonne_.
   */
  const int& lireColonne() const;

protected:

  /**
   * Demande à cette cellule graphique de se mettre à jour en fonction de l'état
   * de la cellule correspondante du modèle.
   * 
   * @param[in] presentateur - le présentateur à invoquer.
   */
  void mettreAJour(const Presentateur& presentateur);

  /**
   * Callback invoqué lors d'un click de souris sur cette cellule graphique.
   *
   * @param[in] evt - l'événement associé au click.
   * @return la valeur @c true.
   */
  bool cbClickSouris(GdkEventButton* evt);

protected:

  /**
   * Représentation graphique du jeu de la vie propriétaire de cette cellule 
   * graphique.
   */
  JeuDeLaVieGraphique& jeuDeLaVieGraphique_;
  
  /**
   * Numéro de ligne de cette cellule dans le modèle.
   */
  const int ligne_;

  /**
   * Numéro de colonne de cette cellule dans le modèle.
   */
  const int colonne_;

  /**
   * Pixmaps représentant les deux états possibles d'une cellule.
   *
   * @note En toute rigueur, cette map devrait être définie en tant 
   *   qu'attribut de classe et non d'instance. Cependant, GTK ne supporte pas
   *   qu'un widget puisse appartenir à plusieurs conteneurs. Par conséquent,
   *   nous devons répliquer les images, d'ou un gaspillage de mémoire.
   */
  std::map< bool, std::unique_ptr< Gtk::Image > > etats_;

};

#endif

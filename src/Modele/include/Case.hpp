#ifndef Case_hpp
#define Case_hpp

#include <memory>
#include "Etat.hpp"

namespace grenouilloland {

/**
 * Declarations incompletes necessaires.
 */
class Jeu;
class Element;

/**
 * @class Case Case.hpp
 * @brief Case du Jeu Grenouilloland.
 *
 * Declaration de la classe Case representant une Case du Jeu Grenouilloland.
 */
class Case {

friend class Jeu;

public:

  /**
   * Constructeur logique instanciant une case.
   *
   * @param[in] colonne - la valeur de @ref _colonne.
   * @param[in] ligne - la valeur de @ref _ligne.
   */
  Case(const int& colonne, const int& ligne);

public:

  /**
   * Accesseur du numéro de ligne.
   *
   * @return la valeur de @ref _ligne.
   */
  const int& lireLigne() const;

  /**
   * Accesseur du numéro de colonne.
   *
   * @return la valeur de @ref _colonne.
   */
  const int& lireColonne() const;

  /**
   * Accesseur de l'élément.
   *
   * @return la valeur de l'élément pointé par @ref _element.
   */
  const Element& lireElement() const;
  
protected:

  /**
   * Remplace l'élement présent par celui en paramètre.
   *
   * @param[in,out] element - nouvel élément de la cellule.
   */
  void changerElement(Element* element);
  
  /**
   * Vieillisement de l'élément.
   *
   * @return nouvel état de l'élément pointé par @ref _element.
   */
  Etat vieillirElement();

protected:

  /**
   * Numero de ligne de cette cellule.
   */
  int _ligne;

  /**
   * Numero de colonne de cette cellule.
   */
  int _colonne;

  /**
   * Element contenu dans la cellule.
   */
  std::unique_ptr<Element> _element;

};

}

#endif

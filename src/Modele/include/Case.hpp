#ifndef Case_hpp
#define Case_hpp

#include "Element.hpp"
#include "Coordonnee.hpp"


/*!
 * \file Case.hpp
 * \brief Caractérise le comportement d'une classe
 * \author Choukri SOULEIMAN IMAN
 * \version 0.1
 */

/*! \namespace grenouilloland
 *
 * espace de nommage regroupant les outils composants
 * le jeu Grenouille
 */
namespace grenouilloland
{
  /*! \class Case
   * \brief classe representant une case sur le plateau(la mare)
   */
  class Case
  {
  public:
    /*!
     *  \brief Constructeur
     *  Constructeur de la classe Case
     *  \param elt : element à initialiser avec la case
     */
    Case(const Coordonnee * c);

  public:
    /*!
     *  \brief Remplacer un element dans une case
     *
     *  Methode qui permet de remplacer l'element neneuphar ou eau
     *  dans une case
     *  \param e : element à placer dans la case
     *  \return void
     */
    void remplaceElt(Element const * e);

    /*!
     *  \brief Position de la case
     *  \return les coordonnees de la case
     */
    Coordonnee getPosition();

    /*!
     *  \brief l'element contenu dans la case
     *  \return element
     */
    const Element getElement();
    /*!
     *  \brief Faire vieillir l'element de la case
     *  \return void
     */
    void vieillirElt();
    /*!
     *  \brief Couleur de l'element
     *  \return Couleur
     */
    Couleur const couleurElt() const;
    /*!
     *  \brief l'element contenu dans la case
     *  \return element
     */
    void setElement(Element * e);
    /*!
     *  \brief Setter de l'attribut pos
     *  \param coord : coordonne de la case
     */
    void setPosition(Coordonnee & coord) const;

  private:
    Element * e_;
    Coordonnee * pos_;
  };
};

#endif

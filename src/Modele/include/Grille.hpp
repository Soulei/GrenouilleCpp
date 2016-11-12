#ifndef Grille_hpp
#define Grille_hpp

#include "Matrix.hpp"
/*!
 * \file Grille.h
 * \brief Caractérise la structure de la mare
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
  /*! \class Grille
   * \brief classe representant le lecteur
   */
  class Grille
  {
  public:
    /*!
     *  \brief Constructeur
     *  Constructeur de la classe Grille
     *  \param dimension : dimension du plateau
     */
    Grille(const int & dimension);

    /*!
     *  \brief Destructeur
     *  Destructeur de la classe Case
     */
    virtual ~Grille();

  public:
    /*!
     *  \brief Afficher le plateau (la mare)
     *  \return void
     */
    void afficher();

  public:
    Matrix grille_;
  private:
    int dimension_;

  };
};

#endif

#ifndef Jeu_hpp
#define Jeu_hpp

#include "Grenouille.hpp"
#include "Case.hpp"
#include <vector>

/*!
 * \file Jeu.hpp
 * \brief Caractérise le deroulement du jeu
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
  class Jeu
  {
  public:
    /*!
     *  \brief Constructeur
     *  Constructeur de la classe Case
     *  \param dimension : dimension du jeu
     */
    Jeu(const int & dimension);

  public:
    /*!
     *  \brief Initialiser le jeu avec les nenuphards de
     *  façon aléatoire
     *  \return void
     */
    void initialiser();

    /*!
     *  \brief Construire un nouveau chemin pour la grenouille
     *  lorsque les nenuphards deviennent de l'eau
     *  \return void
     */
    void construireChemin();

    /*!
     *  \brief Lencer le jeu
     *  \return les coordonnees de la case
     */
    void lancerJeu();

    /**
     * Accesseur.
     *
     * @return la valeur de @ref dimension_.
     */
    const int& lireDimension() const;

    /**
     * Accesseur.
     *
     * @return la valeur de @ref grille_.
     */
     const std::vector< Case > & lireGrille();

  protected:
    Grenouille * grenouille_;
    const int dimension_;
    std::vector< Case > grille_;
  };
};

#endif

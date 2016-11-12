#ifndef Grenouille_hpp
#define Grenouille_hpp

#include "Coordonnee.hpp"

/*!
 * \file Grenouille.hpp
 * \brief Caractérise le comportement d'une grenouille
 * \author Choukri SOULEIMAN IMAN
 * \version 0.1
 */

/*! \namespace grenouilloland
 *
 * espace de nommage regroupant les outils composants
 * le jeu grenouille
 */
namespace grenouilloland
{
  /*! \class Grenouille
   * \brief classe representant la grenouille
   */
  class Grenouille
  {
  public:
    Grenouille();
    /*!
     *  \brief Deplacer la grenouille
     *
     *  Methode qui permet de deplacer la grenouille vers la case
     *  nord
     *  \return void
     */
    void deplacerNord();
    /*!
     *  \brief Deplacer la grenouille
     *
     *  Methode qui permet de deplacer la grenouille vers la case
     *  Sud
     *  \return void
     */
    void deplacerSud();
    /*!
     *  \brief Deplacer la grenouille
     *
     *  Methode qui permet de deplacer la grenouille vers la case
     *  Est
     *  \return void
     */
    void deplacerEst();
    /*!
     *  \brief Deplacer la grenouille
     *
     *  Methode qui permet de deplacer la grenouille vers la case
     *  Ouest
     *  \return void
     */
    void deplacerOuest();

    /*!
     *  \brief Reduire les points de vie de la grenouille
     *
     *  Methode qui permet de modifier les points de vie de
     *  la grenouille selon le type d'element rencontre dans la mare
     *  \return void
     */
    void reduirePtvie(const Element & e);
    /*!
     *  \brief Getter vie
     *  \return int points de vie
     */
    int getVie();

    /*!
     *  \brief Rend la grenouille malade et si deja malade
     *  elle meurt
     *  \return void
     */
    void rendreMalade();
    /*!
     *  \brief Guerrir la grenouille et augmente par une unite
     *  ses points de vie
     *  \return void
     */
    void guerir();

  private:
    bool malade_;
    int pointVie_;
    Coordonnee posCour_;
  };
};

#endif

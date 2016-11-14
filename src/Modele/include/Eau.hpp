#ifndef Eau_hpp
#define Eau_hpp

#include "Element.hpp"
/*!
 * \file Element.h
 * \brief Classe abstraite représentant les elements du plateau
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
   /*! \class Element
    * \brief classe representant les elements du plateau de jeu
    */
   class Eau: public Element{
     /*!
      *  \brief Constructeur
      *  Constructeur de la classe Eau
      */
    public:
     Eau();
   };
};
#endif

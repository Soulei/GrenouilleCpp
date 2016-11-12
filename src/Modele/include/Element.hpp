#ifndef Element_hpp
#define Element_hpp

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
   class Element{
   public:
     enum Couleur{Vert, RougeMortel, RougeDopant, Rose, Jaune, None}
     /*!
      *  \brief Reduire les point de vie de l'element
      *  \return void
      */
     virtual void vieillir();
      /*!
       *  \brief Couleur de l'element
       *  \return string etant la couleur
       */
      virtual Couleur getCouleur();
      /*!
       *  \brief point de vie de l'element
       *  \return int
       */
      virtual int getvie();
    public:
      Couleur type_;
      int pntvie_;


   };
};
#endif

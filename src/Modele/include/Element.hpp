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
    enum Couleur{Vert, RougeMortel, RougeDopant, Rose, Jaune, None};
   class Element{
   public:
     /*!
      *  \brief Reduire les point de vie de l'element
      *  \return void
      */
     virtual void vieillir();
      /*!
       *  \brief Couleur de l'element
       *  \return string etant la couleur
       */
      virtual Couleur const getCouleur();
      /*!
       *  \brief point de vie de l'element
       *  \return int
       */
      virtual int getvie();
    public:
      Couleur const type_;
      int pntvie_;


   };
};
#endif

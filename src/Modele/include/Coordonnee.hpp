#ifndef Coordonnee_hpp
#define Coordonnee_hpp

/*!
 * \file Coordonee.h
 * \brief Les coordonne d'une case
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
  /*! \class CPlayer
   * \brief classe representant le lecteur
   */
  class Coordonnee
  {
  public:
    /*!
     *  \brief Constructeur
     *  Constructeur de la classe Coordonnee
     *  \param x : abscisse
     *  \param y : ordonne
     */
    Coordonnee(const int & x, const int & y);
    /*!
     *  \brief Getter de x
     *  \return int qui est x
     */
    int getX() const;
    /*!
     *  \brief Getter de y
     *  \return int qui est y
     */
    int getY() const;
    /*!
     *  \brief Setter de x
     *  \param x : abscisse x
     */
    void setX(int x) const;
    /*!
     *  \brief Setter de y
     *  \param y : ordonnee y
     */
    void setY(int y) const;
  private:
    int x_;
    int y_;
  };
};

#endif

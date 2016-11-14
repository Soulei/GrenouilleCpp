#ifndef Dimension_hpp
#define Dimension_hpp

#include <gtkmm/comboboxtext.h>
#include <gtkmm/liststore.h>

namespace grenouilloland {

  /**
  * Declarations incompletes necessaires.
  */
  class Vue;

  /**
  * @class Dimension Dimension.hpp
  * @brief Controleur de la dimension du Jeu.
  * @author Marechal Charlie
  * @author Fontaine Luc
  * @author Souleiman Choukri
  * @author Yan Xiaoge
  *
  * Declaration de la classe Dimension.
  * Widget de type menu déroulant
  * @note une instance de cette classe ne peut etre dupliquee.
  */

  class Dimension: public Gtk::Frame {
  public:

  /**
  * Constructeur logique.
  *
  * @param[in] titre - le titre du contour.
  * @param[in,out] vue - la valeur de @ref ptrVue.
  */
  Dimension(const Glib::ustring& titre, VueGrenouille& vue);

  public:

  /**
  * Accesseur.
  * @return la valeur de @ref ptrVue.
  */
  const VueGrenouille& lireVue() const;

  public:

  /**
  * Retourne la dimension actuelle.
  * @return la dimension actuelle.
  */
  int valeur() const;

  protected:

  /**
  * Callback associe au changement de valeur.
  */
  void cbChangementDeValeur();

  private:

  /**
  * Constructeur par recopie.
  * @param[in] recopie - l'instance à recopier.
  */
  Dimension(const Dimension& recopie) = delete;

  /**
  * Operateur d'affectation.
  *
  * @param[in] recopie - l'instance à recopier.
  * @return cette instance apres recopie.
  */
  Dimension& operator=(const Dimension& recopie) = delete;

  protected:

  /**
  * Unique vue proprietaire de ce controleur.
  */
  Vue* const ptrVue;

  /**
  * Menu déroulant.
  */
  Gtk::ComboBoxText listeDim;

  };
}

#endif

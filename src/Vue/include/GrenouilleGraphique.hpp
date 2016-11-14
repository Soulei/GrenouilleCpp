#ifndef GrenouilleGraphique_hpp
#define GrenouilleGraphique_hpp

#include "CelluleGraphique.hpp"
#include <gtkmm/aspectframe.h>
#include <gtkmm/grid.h>
#include <vector>

namespace grenouilloland {

/**
* Declarations incompletes necessaires.
*/
class Vue;

/**
* @class GrenouilleGraphique GrenouilleGraphique.hpp
* @brief Representation graphique du Jeu grenouille.

* Declaration de la classe grenouilleGraphique representant le
* plateau du Jeu grenouille.
*
* @note Une instance de cette classe ne peut être dupliquée.
*/
class GrenouilleGraphique: public Gtk::AspectFrame {
public:

/**
* Declaration d'amitié.
*/
friend class Vue;

/**
* Declaration d'amitié.
*/
friend class CelluleGraphique;

public:

/**
* Constructeur logique.
* @param[in] titre - le titre du contour.
* @param[in,out] vue - la valeur de @ref ptrVue.
*/
GrenouilleGraphique(const Glib::ustring& titre, VueGrenouille& vue);

public:

/**
* Accesseur.
* @return la valeur de @ref ptrVue.
*/
const Vue& lireVue() const;

protected:

/**
* Accesseur.
* @return la valeur de @ref ptrVue.
*/
Vue& lireVueModifiable();

protected:

/**
* Met a jour l'ensemble des cellules graphiques
* @param[in] presentateur - le presentateur a appeller.
* @note Pour appeller cette methode, la vue doit etre verouillee.
*/
void mettreAJour(const Presentateur& presentateur);

protected:

/**
* Unique vue proprietaire de cette generation.
*/
Vue* const _ptrVue;

/**
* Gestionnaire de mise en forme de ce plateau.
*/
Gtk::Grid _gestionnaire;

/**
* Cellules graphiques de cette representation graphique du jeu Grenouille.
*/
std::vector< CelluleGraphique* > _cellules;

};
}

#endif

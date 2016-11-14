#ifndef Chronometre_hpp
#define Chronometre_hpp

#include <gtkmm/frame.h>
#include <gtkmm/progressbar.h>

namespace grenouille {

/**
* Declarations incompletes necessaires.
*/
class Vue;

/**
* @class Chronometre Chronometre.hpp
* @brief Afficheur du temps de Jeu.

* Declaration de la classe Chronometre representant le chrono du jeu. 
* Le Widget de type barre de progression.
* @author Marechal Charlie
* @author Fontaine Luc
* @author Souleiman Choukri
* @author Yan Xiaoge
* @note une instance de cette classe ne peut etre dupliquee.
*/
class Chronometre: public Gtk::Frame {

/**
* Declaration d'amitie.
*/
friend class Vue;

public:

/**
* Constructeur logique.
*
* @param[in] titre - le titre du contour.
*/
Chronometre(const Glib::ustring& titre);

protected:

/**
* Met à jour la barre de progression selon le chronomètre du Jeu.
* @param[in] presentateur - le Presentateur à appeller.
*/
void mettreAJour(const Presentateur& presentateur);

private:

/**
* Constructeur par recopie.
* @param[in] recopie - l'instance à recopier.
*/
Chronometre(const Chronometre& recopie) = delete;

/**
* Operateur d'affectation.
* @param[in] recopie - l'instance à recopier.
* @return cette instance apres recopie.
*/
Chronometre& operator=(const Chronometre& recopie) = delete;

protected:

/**
* Barre de progression.
*/
Gtk::ProgressBar _barreDeProgression;

};
}

#endif

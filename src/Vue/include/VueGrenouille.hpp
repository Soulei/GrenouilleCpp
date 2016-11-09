/****************************************
* Declaration de la classe VueGrenouille *
*****************************************/

#ifndef VueGrenouille_hpp
#define VueGrenouille_hpp

#include <gtkmm/main.h>
#include <gtkmm/window.h>
#include <gtkmm/box.h>
#include <gtkmm/action.h>
#include <gtkmm/actiongroup.h>
#include <gtkmm/stock.h>
#include <gtkmm/uimanager.h>
#include <gtkmm/aboutdialog.h>
#include <gtkmm/cellrendererpixbuf.h>
#include <map>

class Vue: public Gtk::Window {
public:

  // Déclarations d'amitié envers les classes CelluleGraphique et Dimension.
  friend class CelluleGraphique;
  friend class Dimension;

public:
  /**
   * Initialise cette classe.
   *
   * @note cette méthode doit être appelée avant toutes les autres.
   */
  static void initialiser();

public:

  /**
   * Accesseur.
   *
   * @return la valeur de @ref titreVue.
   */
  static const Glib::ustring lireTitreVue();

  /**
   * Accesseur.
   *
   * @return la valeur de @ref titreGrenouille.
   */
  static const Glib::ustring lireTitreGrenouille;

  /**
   * Accesseur.
   *
   * @return la valeur de @ref titreDimension.
   */
  static const Glib::ustring lireTitreDimension();

protected:

  /**
   * Retourne l'image dont le nom est fourni en argument.
   *
   * @param[in] nom - le nom de l'image.
   * @return l'image correspondante.
   */
  static const Glib::RefPtr< Gdk::Pixbuf>& lireImage(const Glib::ustring& nom);

public:

  /**
   * Constructeur logique.
   *
   * @param[in] presentateur - la valeur de @ref presentateur_.
   */
  Vue(Presentateur& presentateur);

  /**
   * Constructeur par recopie.
   *
   * @param[in] autre - l'instance à recopier.
   */
  Vue(const Vue& autre) = delete;

public:

  /**
   * Accesseur.
   *
   * @return la valeur de @ref presentateur_.
   */
  const Presentateur& lirePresentateur() const;

public:

  /**
   * Opérateur d'affectation.
   *
   * @param[in] autre - l'instance à recopier.
   * @return cette instance après recopie.
   */
  Vue& operator=(const Vue& autre) = delete;

protected:

  /**
   * Construit les barre de menus et d'outils.
   * 
   * @param[in,out] gestionnaire - le gestionnaire de mise en forme associé à
   *   la fenêtre principale.
   */
  void construireBarreMenusEtOutils(Gtk::VBox& gestionnaire);

  /**
   * Construit la partie centrale de la fenêtre principale qui contient un jeu 
   * de la vie graphique.
   * 
   * @param[in,out] gestionnaire - le gestionnaire de mise en forme associé à
   *   la fenêtre principale.
   */
  void construirePartieCentrale(Gtk::VBox& gestionnaire);

  /**
   * Construit la partie inférieure de la fenêtre principale qui contient le
   * contrôleur de dimension du jeu de la vie.
   * 
   * @param[in,out] gestionnaire - le gestionnaire de mise en forme associé à
   *   la fenêtre principale.
   */
  void construirePartieInferieure(Gtk::VBox& gestionnaire);

protected:

  /**
   * Callback permettant de préparer le jeu pour une nouvelle 
   * partie. 
   *
   * @note Cette méthode est invoquée suite à un click sur l'entrée "Nouveau" du
   * menu "Commandes" ou bien sur le bouton correspondant dans la barre 
   * d'outils.
   */
  void cbNouveau();

  /**
   * Callback permettant de changer la résolution du jeu de la vie.
   * 
   * @note Cette méthode est invoquée par le contrôleur de la résolution du jeu
   *   de la vie.
   */
  void cbChangerModele();

  /**
   * Callback permettant de présenter l'application et ses auteurs. 
   *
   * @note Cette méthode est invoquée suite à un click sur l'entrée 
   *   "A propos ..." du menu "Commandes" ou bien sur le bouton correspondant 
   *   dans la barre d'outils.
   */
  void cbAPropos();

  /**
   * Callback permettant de quitter proprement l'application. 
   *
   * @note Cette méthode est invoquée suite à un click sur l'entrée "Quitter" du
   *   menu "Commandes" ou bien sur le bouton correspondant dans la barre 
   *   d'outils.
   */
  void cbQuitter();

protected:

  /**
   * Titre de cette vue.
   */
  static const Glib::ustring titreVue;

  /**
   * Titre du jeu.
   */
  static const Glib::ustring titreGrenouille;

  /**
   * Titre du contrôleur de la dimension
   */
  static const Glib::ustring titreDimension;

  /**
   * Chemins d'accès au répertoire contenant les images.
   */
  static const Glib::ustring cheminImages;

  /**
   * Map permettant de stocker les images manipulées par cette vue.
   */
  static std::map< Glib::ustring, Glib::RefPtr< Gdk::Pixbuf> > images;

protected:

  /**
   * Présentateur associé à cette vue.
   */
  Presentateur& presentateur;

  /**
   * Jeu de la vie graphique de cette vue.
   */
  std::unique_ptr< GrenouilleGraphique > ptrgrenouilleGraphique;

  /**
   * Contrôleur de la dimension du jeu de la vie de cette vue.
   */
  Dimension dimension;

  /**
   * Gestionnaire de mise en forme associé à la partie centrale de la
   * fenêtre principale. Cette partie contient le jeu de la vie graphique qui
   * change avec le modèle. C'est pour cette raison que nous la définissons en 
   * tant qu'attribut de cette vue.
   */
  Gtk::HBox gestionnaireCentre_;

};

#endif

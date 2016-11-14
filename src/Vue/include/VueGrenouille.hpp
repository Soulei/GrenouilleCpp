#ifndef Vue_hpp
#define Vue_hpp

#include "GrenouilleGraphique.hpp"
#include "Chronometre.hpp"
#include "Dimension.hpp"
#include "PointDeVie.hpp"
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
#include <mutex>

	namespace grenouilloland {

	/**
	* Declarations incompletes necessaires.
	*/
	class Presentateur;

	/**
	* @class VueGrenouille VueGrenouille.hpp
	* @brief VueGrenouille de l'application.
	* @author Marechal Charlie
	* @author Fontaine Luc
	* @author Souleiman Choukri
	* à
	* Declaration de la classe VueGrenouille representant la vue du jeu grenouilloland, son interface graphique
	*
	*/
	class VueGrenouille: public Gtk::Window {
	public:

	/**
	* Declaration d'amitié.
	*/
	friend class CaseGraphique;

	friend class Dimension;

	friend class PointDeVie;

	public:

	/**
	* Initialise cette classe.
	*/
	static void initialiser();

	public:

	/**
	* Accesseur.
	* @return la valeur de @ref titreVue.
	*/
	static const Glib::ustring lireTitreVue();

	/**
	* Accesseur.
	* @return la valeur de @ref titreGrenouille.
	*/
	static const Glib::ustring lireTitreGrenouille();

	/**
	* Accesseur.
	* @return la valeur de @ref titrePointDeVie.
	*/
	static const Glib::ustring lireTitrePointDeVie();

	/**
	* Accesseur.
	* @return la valeur de @ref titreChronometre.
	*/
	static const Glib::ustring lireTitreChronometre();

	/**
	* Accesseur.
	* @return la valeur de @ref titreDimension.
	*/
	static const Glib::ustring lireTitreDimension();

	protected:

	/**
	* Retourne l'image dont le nom est fourni en argument.
	* @param[in] nom - le nom de l'image.
	* @return l'image correspondante.
	*/
	static const Glib::RefPtr< Gdk::Pixbuf>& lireImage(const Glib::ustring& nom);

	public:

	/**
	* Constructeur logique.
	* @param[in] presentateur - la valeur de @ref _ptrPresentateur.
	*/
	VueGrenouille(Presentateur& presentateur);

	protected:

	/**
	* Met à jour l'affichage des PointDeVie, l'ensemble des CelluleGraphique
	* de GrenouilleGraphique ainsi que le Chronometre.
	*/
	void mettreAJour();

	public:

	/**
	* Accesseur.
	* @return la valeur de @ref ptrPresentateur.
	*/
	const Presentateur& lirePresentateur() const;

	protected:

	/**
	* Accesseur.
	* @return la valeur de @ref ptrPresentateur.
	*/
	Presentateur& lirePresentateurModifiable();

	protected:

	/**
	* Verrouille cette vue.
	*/
	void verrouiller();

	/**
	* Deverrouille cette vue.
	*/
	void deverrouiller();

	protected:

	/**
	* Construit les barre de menus et d'outils.
	* @param[in,out] gestionnaire - le gestionnaire de mise en forme associe a
	* la fenetre principale.
	*/
	void construireBarreMenusEtOutils(Gtk::VBox& gestionnaire);

	/**
	* Construit la partie centrale de la fenetre principale contenant le
	* GrenouilleGraphique et les PointDeVie.
	* @param[in,out] gestionnaire - le gestionnaire de mise en forme associe a
	*   la fenetre principale.
	*/
	void construirePartieCentrale(Gtk::VBox& gestionnaire);

	/**
	* Construit la partie inferieure de la fenetre principale contenant le
	* controleur de la dimension du jeu.
	* @param[in,out] gestionnaire - le gestionnaire de mise en forme associe a
	* la fenetre principale.
	*/
	void construirePartieInferieure(Gtk::VBox& gestionnaire);

	protected:

	/**
	* Callback permettant de preparer le jeu pour une nouvelle partie. Cette methode
	* est appellée lors d'une pression sur le bouton nouveau de la barre de commande.
	* @note Lors de cette methode la vue est verrouillee.
	*/
	void cbNouveau();

	/**
	* Callback permettant de preparer une nouvelle partie avec une autre dimension.
	* @note Lors de cette methode la vue est verrouillee.
	*/
	void cbChangerModele();

	/**
	* Callback permettant de presenter l'application et ses auteurs. Cette
	* methode est appellee suite a une pression sur l entre "A propos ..." du menu
	* "Commandes" ou bien sur le bouton correspondant dans la barre d'outils.
	*/
	void cbAPropos();

	/**
	* Callback permettant de quitter l'application. Cette methode
	* est appellee suite a une pression sur le l entree "Quitter" du menu "Commandes"
	* ou bien sur le bouton correspondant dans la barre d'outils.
	*
	* @note Lors de cette methode la vue est verrouillee.
	*/
	void cbQuitter();

	private:

	/**
	* Constructeur par recopie.
	* @param[in] recopie - l'instance a recopier.
	*/
	VueGrenouille(const VueGrenouille& recopie) = delete;

	/**
	* Operateur d'affectation.
	*
	* @param[in] recopie - l'instance a recopier.
	* @return cette instance apres recopie.
	*/
	VueGrenouille& operator=(const VueGrenouille& recopie) = delete;

	protected:

	/**
	* Titre de cette vue.
	*/
	static const Glib::ustring titreVue;

	/**
	* Titre de la representation graphique du jeu grenouille.
	*/
	static const Glib::ustring titreGrenouille;

	/**
	* Titre du panneau de points de vie.
	*/
	static const Glib::ustring titrePointDeVie;

	/**
	* Titre du controleur du chronomètre du jeu.
	*/
	static const Glib::ustring titreChronometre;

	/**
	* Titre du controleur de la dimension du jeu.
	*/
	static const Glib::ustring titreDimension;


	/**
	* Chemin d'acces au répertoire contenant les images.
	*/
	static const Glib::ustring cheminImages;

	/**
	* Stockage des images dans un map.
	*/
	static std::map< Glib::ustring, Glib::RefPtr< Gdk::Pixbuf> > images;

	protected:

	/**
	* Presentateur unique associe a cette vue.
	*/
	Presentateur* const ptrPresentateur;

	/**
	* Representation graphique du modele.
	*/
	std::unique_ptr< GrenouilleGraphique > _ptrGrenouilleGraphique;

	/**
	* Affichage des points de vie de la grenouille.
	*/
	PointDeVie pointDeVie;

	/**
	* Controleur de la dimension du jeu.
	*/
	Dimension dimension;

	/**
	* Affichage du chronomètre du jeu.
	*/
	Chronometre chronometre;

	/**
	* Gestionnaire de la partie centrale de la fenetre principale
	* contenant GrenouilleGraphique et PointDeVie.
	*/
	Gtk::HBox gestionnaireCentre;

	/**
	* Gestionnaire de la partie inférieure de la fenetre principale
	* contenant Dimension et Chronometre.
	*/
	Gtk::HBox gestionnaireBas;

	/**
	* Verrou associe à cette vue.
	*/
	std::mutex verrou;

	/**
	* Sous-classe Delegation amie avec le Presentateur, elle permet de mettre à jour la vue sans pour autant
	* donner accès à des methodes non voulu
	*/
	public :
	class Delegation
	{
		public :
			friend class Presentateur;

		private :

			static void mettreAJour(VueGrenouille& vue)
			{
				vue.mettreAJour();
			}
	};

	};
}

#endif

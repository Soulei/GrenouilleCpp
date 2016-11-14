#ifndef CelluleGraphique_hpp
#define CelluleGraphique_hpp

#include <gtkmm/eventbox.h>
#include <gtkmm/image.h>
#include <map>
#include <memory>

<<<<<<< HEAD
	namespace grenouilloland {

	/**
	* Declarations incompletes necessaires.
	*/
	class Presentateur;
	class GrenouilleGraphique;

	/**
	* @class CelluleGraphique CelluleGraphique.hpp
	* @brief Representation graphique d'une Cellule.
	* @author Marechal Charlie
	* @author Fontaine Luc
	* @author Souleiman Choukri
	*
	* Declaration de la classe CelluleGraphique representant graphiquement une
	* Cellule du modele.
	*/
	class CelluleGraphique: public Gtk::EventBox {
	public:

	/**
	* Declaration d'amitié.
	*/
	friend class GrenouilleGraphique;

	public:

	/**
	* Constructeur logique.
	*
	* @param[in,out] jeu - la valeur de @ref ptrGrenouilleGraphique.
	* @param[in] ligne - la valeur de @ref ligne.
	* @param[in] colonne - la valeur de @ref colonne.
	*/
	CelluleGraphique(GrenouilleGraphique& grenouilleGraphique,
		   const int& colonne,
		   const int& ligne);

	public:

	/**
	* Accesseur.
	*
	* @return la valeur de @ref ptrGrenouilleGraphique.
	*/
	const GrenouilleGraphique& lireGrenouilleGraphique() const;

	/**
	* Accesseur.
	*
	* @return la valeur de @ref colonne.
	*/
	const int& lireColonne() const;

	/**
	* Accesseur.
	*
	* @return la valeur de @ref ligne.
	*/
	const int& lireLigne() const;


	protected:

	/**
	* Demande a cette Cellule graphique de se mettre a jour en fonction de
	* l'etat de la Cellule correspondante du modele.
	*
	* @param[in] presentateur - le presentateur a invoquer.
	*
	* @note La vue doit etre verrouille pour pouvoir invoquer cette methode.
	*/
	void mettreAJour(const Presentateur& presentateur);

	/**
	* Callback invoque lors d'un click de souris sur cette Cellule graphique.
	*
	* @param[in] evt - l'evenement associe au click.
	* @return la valeur @c true.
	*/
	bool cbClickSouris(GdkEventButton* evt);

	private:

	/**
	* Constructeur par recopie.
	*
	* @param[in] recopie - l'instance a recopier.
	*/
	CelluleGraphique(const CelluleGraphique& recopie) = delete;

	/**
	* Operateur d'affectation.
	*
	* @param[in] recopie - l'instance a recopier.
	* @return cette instance apres recopie.
	*/
	CelluleGraphique& operator=(const CelluleGraphique& recopie) = delete;

	protected:

	/**
	* Unique representation graphique du jeu proprietaire de cette
	* Cellule graphique.
	*/
	GrenouilleGraphique* const ptrGrenouilleGraphique;

	/**
	* Numero de ligne de cette Cellule dans le modele.
	*/
	const int ligne;

	/**
	* Numero de colonne de cette Cellule dans le modele.
	*/
	const int colonne;

	/**
	* Pixmaps representant les etats possibles d'une Cellule graphique.
	*
	* @note En toute rigueur, cette map devrait etre definie en tant
	*   qu'attribut de classe et non d'instance. Cependant, GTK ne supporte pas
	*   qu'un widget puisse appartenir a plusieurs container. Par consequent,
	*   nous devons repliquer les images, d'ou un gaspillage de memoire.
	*/
	std::map< int, std::unique_ptr< Gtk::Image > > etats;

	};
=======
namespace grenouille {

/**
* Declarations incompletes necessaires.
*/
class Presentateur;
class GrenouilleGraphique;

/**
* @class CelluleGraphique CelluleGraphique.hh 
* @brief Representation graphique d'une Cellule.
* @author Marechal Charlie
* @author Fontaine Luc
* @author Souleiman Choukri
* @author Yan Xiaoge
* Declaration de la classe CelluleGraphique representant graphiquement une
* Cellule du modele.
*/
class CelluleGraphique: public Gtk::EventBox {
public:

/**
* Declaration d'amitié.
*/
friend class GrenouilleGraphique;

public:

/**
* Constructeur logique.
*
* @param[in,out] jeu - la valeur de @ref ptrGrenouilleGraphique.
* @param[in] ligne - la valeur de @ref ligne.
* @param[in] colonne - la valeur de @ref colonne.
*/
CelluleGraphique(GrenouilleGraphique& grenouilleGraphique,
	   const int& colonne,
	   const int& ligne);

public:

/**
* Accesseur.
*
* @return la valeur de @ref ptrGrenouilleGraphique.
*/
const GrenouilleGraphique& lireGrenouilleGraphique() const;

/**
* Accesseur.
*
* @return la valeur de @ref colonne.
*/
const int& lireColonne() const;

/**
* Accesseur.
*
* @return la valeur de @ref ligne.
*/
const int& lireLigne() const;


protected:

/**
* Demande a cette Cellule graphique de se mettre a jour en fonction de
* l'etat de la Cellule correspondante du modele.
* 
* @param[in] presentateur - le presentateur a invoquer.
*
* @note La vue doit etre verrouille pour pouvoir invoquer cette methode.
*/
void mettreAJour(const Presentateur& presentateur);

/**
* Callback invoque lors d'un click de souris sur cette Cellule graphique.
*
* @param[in] evt - l'evenement associe au click.
* @return la valeur @c true.
*/
bool cbClickSouris(GdkEventButton* evt);

private:

/**
* Constructeur par recopie.
*
* @param[in] recopie - l'instance a recopier.
*/
CelluleGraphique(const CelluleGraphique& recopie) = delete;

/**
* Operateur d'affectation.
*
* @param[in] recopie - l'instance a recopier.
* @return cette instance apres recopie.
*/
CelluleGraphique& operator=(const CelluleGraphique& recopie) = delete;

protected:

/**
* Unique representation graphique du jeu proprietaire de cette 
* Cellule graphique.
*/
GrenouilleGraphique* const ptrGrenouilleGraphique;

/**
* Numero de ligne de cette Cellule dans le modele.
*/
const int ligne;

/**
* Numero de colonne de cette Cellule dans le modele.
*/
const int colonne;

/**
* Pixmaps representant les etats possibles d'une Cellule graphique.
*
* @note En toute rigueur, cette map devrait etre definie en tant 
*   qu'attribut de classe et non d'instance. Cependant, GTK ne supporte pas
*   qu'un widget puisse appartenir a plusieurs container. Par consequent,
*   nous devons repliquer les images, d'ou un gaspillage de memoire.
*/
std::map< int, std::unique_ptr< Gtk::Image > > etats;

};
>>>>>>> 35b937d99e0f330b27700ceef30beb252e6c4473
}

#endif

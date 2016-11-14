#ifndef Element_hpp
#define Element_hpp

#include "Grenouille.hpp"
#include "StrategieAbstraite.hpp"
#include "Etat.hpp"

namespace grenouilloland {

/**
 * @class Element Element.hpp
 * @brief Element du Jeu Grenouilloland.
 *
 * Declaration de la classe abstraite Element réprésentant la structure d'un élément du jeu Grenouilloland.
 */
class Element
{

	public :
		/**
		 * Destructeur de l'élément.
		 */
		virtual ~Element() = 0;

		/**
		 * Accesseur de l'ID identifiant le type de l'élément.
		 *
		 * @return valeur de l'ID.
		 */
		virtual const int& lireId() const = 0;

		/**
		 * Méthode permettant de détecter si l'élément est de l'eau.
		 *
		 * return false.
		 */
		virtual bool isEau() const;

		/**
		 * Accesseur de l'état de l'élément.
		 *
		 * @return valeur de @ref _etat.
		 */
		const Etat& lireEtat() const;

	protected :
		/**
		 * Constructeur logique instanciant un élément.
		 *
		 * @param[in] strategie - stratégie appliqué par l'élément.
		 */
		Element(const StrategieAbstraite& strategie);

	private :
		/**
		 * Vieillissement de l'élément.
		 *
		 * @return valeur de @ref _etat.
		 */
		virtual Etat vieillir();

		/**
		 * Application de la stratégie de l'élément sur la grenouille.
		 *
		 * @param[in,out] g - grenouille subissant la stratégie de l'élément.
		 */
		void appliquerStrategie(Grenouille& g) const;

	protected :
		/**
		 * Etat de l'élément.
		 */
		Etat _etat;

	private :
		/**
		 * Pointeur sur la stratégie appliquée par l'élément.
		 */
		const StrategieAbstraite* _strategie;

	public :
		/**
		 * @class Delegation Element.hpp
		 * @brief Delegation de la classe Element du Jeu Grenouilloland.
		 *
		 * Declaration et définition de la classe Delegation de la classe Element communiquant avec les classes Jeu et Cellule.
		 */
		class Delegation
		{
			public :
				friend class Jeu;
				friend class Cellule;

			private :
				/**
				 * Vieillissement d'un élément.
				 *
				 * @param[in,out] e - élément à faire vieillir.
				 *
				 * @return valeur de l'état de l'élément venant de vieillir.
				 */
				static Etat vieillir(Element& e)
				{
					return e.vieillir();
				}

				/**
				 * Application de la stratégie d'un élément sur une grenouille.
				 *
				 * @param[in] e - élément appliquant sa stratégie.
				 * @param[in,out] g - grenouille subissant la stratégie.
				 */
				static void appliquerStrategie(const Element& e, Grenouille& g)
				{
					e.appliquerStrategie(g);
				}
		};
};

}

#endif

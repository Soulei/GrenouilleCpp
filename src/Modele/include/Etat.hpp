#ifndef Etat_hpp
#define Etat_hpp

namespace grenouilloland {

/**
 * @class Etat Etat.hpp
 * @brief Etat du Jeu Grenouilloland.
 *
 * Declaration de la classe Etat réprésentant les différents états d'un élément du jeu Grenouilloland.
 */
class Etat {
	public :
		/**
		 * @enum Enum
		 *
		 * Enumeration regroupant les différents état possible d'un élément.
		 */
		enum Enum
		{
			Grand, Moyen, Petit, Mort
		};
	private :
		/**
		 * Valeur de l'état.
		 */
		Enum _etat;
	public :
		/**
		 * Constructeur par défaut d'un état.
		 */
		Etat();
		/**
		 * Constructeur logique d'un état.
		 *
		 * @param[in] e - valeur de l'état.
		 */
		Etat(const Enum& e);
		/**
		 * Opérateur d'égalité d'un état.
		 *
		 * @param[in] e - valeur de l'état à comparer.
		 *
		 * @return true en cas d'égalité, false sinon.
		 */
		bool operator==(const Enum& e) const;
};

}

#endif

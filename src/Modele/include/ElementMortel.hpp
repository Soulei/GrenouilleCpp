#ifndef ElementMortel_hpp
#define ElementMortel_hpp

#include "Element.hpp"

namespace grenouilloland {

/**
 * @class ElementMortel ElementMortel.hpp
 * @brief ElementMortel du Jeu Grenouilloland.
 * Declaration de la classe abstraite ElementMortel réprésentant 
 * la structure d'un élément ayant plusieurs états de vieillissement du jeu Grenouilloland.
 */
class ElementMortel : public Element
{
	public :
		/**
		 * Destructeur d'un élément mortel.
		 */
		virtual ~ElementMortel() = 0;

	protected :
		/**
		 * Constructeur logique d'un élément mortel.
		 *
		 * @param[in] strategie - stratégie de l'élément mortel.
		 */
		ElementMortel(const StrategieAbstraite& strategie);

		/**
		 * Vieillissement de l'élément mortel.
		 *
		 * @return l'état de l'élément mortel.
		 */
		Etat vieillir();
}; 

}

#endif

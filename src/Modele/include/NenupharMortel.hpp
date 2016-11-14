#ifndef NenupharMortel_hpp	
#define NenupharMortel_hpp

#include "ElementMortel.hpp"
#include "StrategieMort.hpp"

namespace grenouilloland {

/**
 * @class NenupharMortel NenupharMortel.hpp
 * @brief NenupharMortel du Jeu Grenouilloland.
 *
 * Declaration de la classe NenupharMortel réprésentant un nénuphar mortel du jeu Grenouilloland.
 */
class NenupharMortel : public ElementMortel
{
	public :
		/**
		 * Constructeur par défaut d'un nénuphar mortel.
		 */
		NenupharMortel();
		
		/**
		 * Destructeur d'un nénuphar mortel.
		 */
		~NenupharMortel();
	
	public :
		/**
		 * Accesseur de l'ID identifiant un nénuphar mortel.
		 *
		 * @return la valeur de @ref _ID.
		 *
		 * @note L'_ID est const et public mais cet accesseur est 
		 * nécessaire car il est lu dans la vue sur un objet de type
		 * Element et un Element n'a pas d'attribut _ID.
		 * 
		 */
		const int& lireId() const;

	public :
		/**
		 * ID identifiant un nénuphar mortel.
		 */
		static const int _ID;
}; 

}

#endif

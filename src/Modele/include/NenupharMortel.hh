#ifndef __NENUPHAR_MORTEL_HH_
#define __NENUPHAR_MORTEL_HH_

#include "ElementMortel.hh"
#include "StrategieMort.hh"

namespace grenouilloland {

/**
 * @class NenupharMortel NenupharMortel.hh
 * @brief NenupharMortel du Jeu Grenouilloland.
 * @author Beudin.Alexandre Dauxais.Yann
 * @date 05.01.2012
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

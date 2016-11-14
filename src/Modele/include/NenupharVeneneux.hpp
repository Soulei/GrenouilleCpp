#ifndef NenupharVeneneux_hpp	
#define NenupharVeneneux_hpp

#include "ElementMortel.hpp"
#include "StrategieVeneneuse.hpp"

namespace grenouilloland {

/**
 * @class NenupharVeneneux NenupharVeneneux.hpp
 * @brief NenupharVeneneux du Jeu Grenouilloland.
 *
 * Declaration de la classe NenupharVeneneux réprésentant un nénuphar vénéneux du jeu Grenouilloland.
 */
class NenupharVeneneux : public ElementMortel
{
	public :
		/**
		 * Constructeur par défaut d'un nénuphar vénéneux.
		 */
		NenupharVeneneux();
		
		/**
		 * Destructeur d'un nénuphar vénéneux.
		 */
		~NenupharVeneneux();

	public :
		/**
		 * Accesseur de l'ID identifiant un nénuphar vénéneux.
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
		 * ID identifiant un nénuphar vénéneux.
		 */
		static const int _ID;
};

}

#endif

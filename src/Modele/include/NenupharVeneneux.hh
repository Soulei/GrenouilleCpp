#ifndef __NENUPHAR_VENENEUX_HH_
#define __NENUPAHR_VENENEUX_HH_

#include "ElementMortel.hh"
#include "StrategieVeneneuse.hh"

namespace grenouilloland {

/**
 * @class NenupharVeneneux NenupharVeneneux.hh
 * @brief NenupharVeneneux du Jeu Grenouilloland.
 * @author Beudin.Alexandre Dauxais.Yann
 * @date 05.01.2012
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

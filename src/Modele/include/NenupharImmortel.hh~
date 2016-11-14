#ifndef __NENUPHAR_IMMORTEL_HH_
#define __NENUPHAR_IMMORTEL_HH_

#include "Element.hh"
#include "StrategieNeutre.hh"

namespace grenouilloland {

/**
 * @class NenupharImmortel NenupharImmortel.hh
 * @brief NenupharImmortel du Jeu Grenouilloland.
 * @author Beudin.Alexandre Dauxais.Yann
 * @date 05.01.2012
 *
 * Declaration de la classe NenupharImmortel réprésentant un nénuphar immortel du jeu Grenouilloland.
 */
class NenupharImmortel : public Element
{
	public :
		/**
		 * Constructeur par défaut d'un nénuphar immortel.
		 */
		NenupharImmortel();
		
		/**
		 * Destructeur d'un nénuphar immortel.
		 */
		~NenupharImmortel();

	public :
		/**
		 * Accesseur de l'ID identifiant un nénuphar immortel.
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
		 * ID définissant un nénuphar immortel.
		 */
		static const int _ID;
};

}

#endif

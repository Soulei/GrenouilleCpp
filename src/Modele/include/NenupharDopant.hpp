#ifndef NenupharDopant_hpp
#define NenupharDopant_hpp

#include "StrategieDopante.hpp"
#include "ElementMortel.hpp"

namespace grenouilloland {

/**
 * @class NenupharDopant NenupharDopant.hpp
 * @brief NenupharDopant du Jeu Grenouilloland.
 *
 * Declaration de la classe Nenuphar réprésentant un nénuphar classique du jeu Grenouilloland.
 */
class NenupharDopant : public ElementMortel
{
	public :
		/**
		 * Constructeur par défaut d'un nénuphar dopant.
		 */
		NenupharDopant();
		
		/**
		 * Destructeur d'un nénuphar dopant.
		 */
		~NenupharDopant();

	public :
		/**
		 * Acceseur à l'ID définissant un nénupahr dopant.
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
		 * ID définissant un nénuphar dopant.
		 */
		static const int _ID;
};

}

#endif

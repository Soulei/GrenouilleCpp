#ifndef Nenuphar_hpp
#define Nenuphar_hpp

#include "ElementMortel.hpp"
#include "StrategieNeutre.hpp"

namespace grenouilloland {

/**
 * @class Nenuphar Nenuphar.hpp
 * @brief Nenuphar du Jeu Grenouilloland.
 *
 * Declaration de la classe Nenuphar réprésentant un nénuphar classique du jeu Grenouilloland.
 */
class Nenuphar : public ElementMortel
{
	public :
		/**
		 * Constructeur par défaut du nénuphar.
		 */
		Nenuphar();
		
		/**
		 * Destructeur du nénuphar.
		 */
		~Nenuphar();

	public :
		/**
		 * Accesseur de l'ID identifiant le type nénuphar.
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
		 * ID identifiant le nénuphar.
		 */
		static const int _ID;
};

}

#endif

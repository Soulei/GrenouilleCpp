#ifndef NenupharNutritif_hpp
#define NenupharNutritif_hpp

#include "ElementMortel.hpp"
#include "StrategieNutritive.hpp"

namespace grenouilloland {

/**
 * @class NenupharNutritif NenupharNutritif.hpp
 * @brief NenupharNutritif du Jeu Grenouilloland.
 *
 * Declaration de la classe NenupharNutritif réprésentant un nénuphar nutritif du jeu Grenouilloland.
 */
class NenupharNutritif : public ElementMortel
{
	public :
		/**
		 * Constructeur par défaut d'un nénuphar nutritif.
		 */
		NenupharNutritif();
		
		/**
		 * Destructeur d'un nénuphar nutritif.
		 */
		~NenupharNutritif();

	public :
		/**
		 * Accesseur de l'ID identifiant un nénuphar nutritif.
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
		 * ID identifiant un nénuphar nutritif.
		 */
		static const int _ID;
};

}

#endif

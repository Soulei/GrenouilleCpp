#ifndef Eau_hpp
#define Eau_hpp

#include "StrategieMort.hpp"
#include "Element.hpp"

namespace grenouilloland {

/**
 * @class Eau Eau.hpp
 * @brief Case du Jeu Grenouilloland.
 *
 * Declaration de la classe Eau réprésentant l'élément d'eau dans le jeu Grenouilloland.
 */
class Eau : public Element
{
	public :
	
		/**
		 * Constructeur par défaut instanciant de l'eau.
		 */
		Eau();
		
		/**
		 * Destructeur d'un élément d'eau.
		 */
		~Eau();
		
	public :
		/**
		 * Accesseur de l'_ID identifiant l'eau.
		 *
		 * @return la valeur de @ref _ID.
		 *
		 * @note L'_ID est const et public mais cet accesseur est 
		 * nécessaire car il est lu dans la vue sur un objet de type
		 * Element et un Element n'a pas d'attribut _ID.
		 * 
		 */
		const int& lireId() const;

		/**
		 * Méthode permettant de détecter si l'élément est de l'eau.
		 *
		 * @return true.
		 */
		bool isEau() const;

	public:
		/**
		 * ID identifiant l'eau pour associer une image.
		 */
		static const int _ID; //TODO utiliser plutôt un enum class
}; 

}

#endif

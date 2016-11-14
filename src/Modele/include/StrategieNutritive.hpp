#ifndef StrategieNutritive_hpp
#define StrategieNutritive_hpp

#include "StrategieAbstraite.hpp"

namespace grenouilloland {

/**
 * @class StrategieNutritive StrategieNutritive.hpp
 * @brief StrategieNutritive du Jeu Grenouilloland.
 *
 * Declaration de la classe StrategieNutritive réprésentant la stratégie nutritive d'un nénuphar du jeu Grenouilloland.
 */
class StrategieNutritive : public StrategieAbstraite
{
	public :
		/**
		 * Application des effets de la stratégie.
		 *
		 * @param[in,out] pv - pv à modifier.
		 * @param[in,out] malade - état de santé à modifier.
		 */
		void appliquerEffet(unsigned int& pv, bool& malade) const;
		
	private :
		/**
		 * Constructeur par défaut d'une stratégie nutritive.
		 */
		StrategieNutritive();
		
		/**
		 * Constructeur par recopie d'une stratégie nutritive.
		 *
		 * @note Celui-ci a été rendu inaccessible et n'est pas utilisé mais sa suppression entraînait une erreur.
		 */
		StrategieNutritive(const StrategieNutritive&);
		
	public :
		/**
		 * @class Deleguation
		 * @brief Deleguation de StrategieNutritive du Jeu Grenouilloland.
		 *
		 * Declaration de la classe Deleguation de la classe StrategieNutritive communiquant avec la classe GestStrat<StrategieNutritive>.
		 */		
		class Deleguation {
			public :
				friend class GestStrat<StrategieNutritive>;
			
			private :
				/**
				 * Retourne une instance de StrategieNutritive.
				 *
				 * @return instance de StrategieNutritive.
				 */	
				static StrategieNutritive Strategie()
				{
					return StrategieNutritive();
				}
		};
};

}

#endif

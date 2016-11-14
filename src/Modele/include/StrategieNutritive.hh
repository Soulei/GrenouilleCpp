#ifndef __STRATEGIE_NUTRITIVE_HH_
#define __STRATEGIE_NUTRITIVE_HH_

#include "StrategieAbstraite.hh"

namespace grenouilloland {

/**
 * @class StrategieNutritive StrategieNutritive.hh
 * @brief StrategieNutritive du Jeu Grenouilloland.
 * @author Beudin.Alexandre Dauxais.Yann
 * @date 05.01.2012
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
		 * @class Mandataire
		 * @brief Mandataire de StrategieNutritive du Jeu Grenouilloland.
		 *
		 * Declaration de la classe Mandataire de la classe StrategieNutritive communiquant avec la classe GestStrat<StrategieNutritive>.
		 */		
		class Mandataire {
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

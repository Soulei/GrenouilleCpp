#ifndef __STRATEGIE_NEUTRE_HH_
#define __STRATEGIE_NEUTRE_HH_

#include "StrategieAbstraite.hh"

namespace grenouilloland {

/**
 * @class StrategieNeutre StrategieNeutre.hh
 * @brief StrategieNeutre du Jeu Grenouilloland.
 * @author Beudin.Alexandre Dauxais.Yann
 * @date 05.01.2012
 *
 * Declaration de la classe StrategieNeutre réprésentant la stratégie neutre d'un nénuphar du jeu Grenouilloland.
 */
class StrategieNeutre : public StrategieAbstraite
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
		 * Constructeur par défaut d'une stratégie neutre.
		 */
		StrategieNeutre();

		/**
		 * Constructeur par recopie d'une stratégie neutre.
		 *
		 * @note Celui-ci a été rendu inaccessible et n'est pas utilisé mais sa suppression entraînait une erreur.
		 */
		StrategieNeutre(const StrategieNeutre&);
		
	public :
		/**
		 * @class Mandataire
		 * @brief Mandataire de StrategieNeutre du Jeu Grenouilloland.
		 *
		 * Declaration de la classe Mandataire de la classe StrategieNeutre communiquant avec la classe GestStrat<StrategieNeutre>.
		 */		
		class Mandataire {
			public :
				friend class GestStrat<StrategieNeutre>;

			/**
			 * Retourne une instance de StrategieNeutre.
			 *
			 * @return instance de StrategieNeutre.
			 */				
			private :	
				static StrategieNeutre Strategie()
				{
					return StrategieNeutre();
				}
		};
};

}

#endif

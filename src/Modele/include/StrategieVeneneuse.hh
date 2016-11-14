#ifndef __STRATEGIE_VENENEUSE_HH_
#define __STRATEGIE_VENENEUSE_HH_

#include "StrategieAbstraite.hh"

namespace grenouilloland {

/**
 * @class StrategieVeneneuse StrategieVeneneuse.hh
 * @brief StrategieVeneneuse du Jeu Grenouilloland.
 * @author Beudin.Alexandre Dauxais.Yann
 * @date 05.01.2012
 *
 * Declaration de la classe StrategieVeneneuse réprésentant la stratégie vénéneuse d'un nénuphar du jeu Grenouilloland.
 */
class StrategieVeneneuse : public StrategieAbstraite
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
		 * Constructeur par défaut d'une stratégie vénéneuse.
		 */
		StrategieVeneneuse();
		
		/**
		 * Constructeur par recopie d'une stratégie vénéneuse.
		 *
		 * @note Celui-ci a été rendu inaccessible et n'est pas utilisé mais sa suppression entraînait une erreur.
		 */
		StrategieVeneneuse(const StrategieVeneneuse&);
		
	public :
		/**
		 * @class Mandataire
		 * @brief Mandataire de StrategieVeneneuse du Jeu Grenouilloland.
		 *
		 * Declaration de la classe Mandataire de la classe StrategieVeneneuse communiquant avec la classe GestStrat<StrategieVeneneuse>.
		 */	
		class Mandataire {
			public :
				friend class GestStrat<StrategieVeneneuse>;
			
			private :
				/**
				 * Retourne une instance de StrategieVeneneuse.
				 *
				 * @return instance de StrategieVeneneuse.
				 */	
				static StrategieVeneneuse Strategie()
				{
					return StrategieVeneneuse();
				}
		};
};

}

#endif

#ifndef StrategieVeneneuse_hpp
#define StrategieVeneneuse_hpp

#include "StrategieAbstraite.hpp"

namespace grenouilloland {

/**
 * @class StrategieVeneneuse StrategieVeneneuse.hpp
 * @brief StrategieVeneneuse du Jeu Grenouilloland.
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
		 * @class Deleguation
		 * @brief Deleguation de StrategieVeneneuse du Jeu Grenouilloland.
		 *
		 * Declaration de la classe Deleguation de la classe StrategieVeneneuse communiquant avec la classe GestStrat<StrategieVeneneuse>.
		 */	
		class Deleguation {
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

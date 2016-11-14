#ifndef StrategieAbstraite_hpp
#define StrategieAbstraite_hpp

#include "Grenouille.hpp"
#include "TGestStrat.hpp"

namespace grenouilloland {

/**
 * @class StrategieAbstraite StrategieAbstraite.hpp
 * @brief StrategieAbstraite du Jeu Grenouilloland.
 *
 * Declaration de la classe abstraite StrategieAbstraite réprésentant la structure d'une stratégie du jeu Grenouilloland.
 */
class StrategieAbstraite
{
	public :
		/**
		 * Application de la stratégie sur une grenouille.
		 *
		 * @param[in,out] g - grenouille subissant la stratégie.
		 */
		void appliquerStrategie(Grenouille& g) const;
		
		/**
		 * Application des effets de la stratégie.
		 *
		 * @param[in,out] pv - pv à modifier.
		 * @param[in,out] malade - état de santé à modifier.
		 */
		virtual void appliquerEffet(unsigned int& pv, bool& malade) const = 0;
		
	private :
	
		/**
		 * Opérateur de recopie d'une stratégie abstraite.
		 *
		 * @note Supprimé.
		 */
		StrategieAbstraite* operator= (const StrategieAbstraite&) = delete;
};

}

#endif

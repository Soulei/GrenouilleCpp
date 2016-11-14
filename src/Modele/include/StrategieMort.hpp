#ifndef StrategieMort_hpp
#define StrategieMort_hpp

#include "StrategieAbstraite.hpp"

namespace grenouilloland {

/**
 * @class StrategieMort StrategieMort.hpp
 * @brief StrategieMort du Jeu Grenouilloland.
 *
 * Declaration de la classe StrategieMort réprésentant la stratégie de mort d'un nénuphar du jeu Grenouilloland.
 */
class StrategieMort : public StrategieAbstraite
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
		 * Constructeur par défaut d'une stratégie de mort.
		 */
		StrategieMort();
		
		/**
		 * Constructeur par recopie d'une stratégie de mort.
		 *
		 * @note Celui-ci a été rendu inaccessible et n'est pas utilisé mais sa suppression entraînait une erreur.
		 */
		StrategieMort(const StrategieMort&);
		
	public :
		/**
		 * @class Deleguation
		 * @brief Deleguation de StrategieMort du Jeu Grenouilloland.
		 *
		 * Declaration de la classe Deleguation de la classe StrategieMort communiquant avec la classe GestStrat<StrategieMort>.
		 */		
		class Deleguation {
			public :
				friend class GestStrat<StrategieMort>;
			
			private :
				/**
				 * Retourne une instance de StrategieMort.
				 *
				 * @return instance de StrategieMort.
				 */		
				static StrategieMort Strategie()
				{
					return StrategieMort();
				}
		};
};

}

#endif

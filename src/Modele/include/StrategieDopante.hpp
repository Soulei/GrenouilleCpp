#ifndef StrategieDopante_hpp
#define StrategieDopante_hpp

#include "StrategieAbstraite.hpp"

namespace grenouilloland {

/**
 * @class StrategieDopante StrategieDopante.hpp
 * @brief StrategieDopante du Jeu Grenouilloland.
 *
 * Declaration de la classe StrategieDopante réprésentant la stratégie dopante d'un nénuphar du jeu Grenouilloland.
 */
class StrategieDopante : public StrategieAbstraite
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
		 * Constructeur par défaut d'une stratégie dopante.
		 */
		StrategieDopante();
		
		/**
		 * Constructeur par recopie d'une stratégie dopante.
		 *
		 * @note Celui-ci a été rendu inaccessible et n'est pas utilisé mais sa suppression entraînait une erreur.
		 */
		StrategieDopante(const StrategieDopante&);
		
	public :
		/**
		 * @class Deleguation
		 * @brief Deleguation de StrategieDopante du Jeu Grenouilloland.
		 *
		 * Declaration de la classe Deleguation de la classe StrategieDopante communiquant avec la classe GestStrat<StrategieDopante>.
		 */		
		class Deleguation {
			public :
				friend class GestStrat<StrategieDopante>;
			
			
			private :
				/**
				 * Retourne une instance de StrategieDopante.
				 *
				 * @return instance de StrategieDopante.
				 */	
				static StrategieDopante Strategie()
				{
					return StrategieDopante();
				}
		};
};

}

#endif

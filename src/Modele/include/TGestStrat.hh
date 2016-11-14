#ifndef __T_GEST_STRAT_HH_
#define __T_GEST_STRAT_HH_

namespace grenouilloland {

/**
 * @class GestStrat TGestStrat.hh
 * @brief GestStrat<T> du Jeu Grenouilloland.
 * @author Beudin.Alexandre Dauxais.Yann
 * @date 05.01.2012
 *
 * Declaration de la classe template GestStrat réprésentant un nénuphar vénéneux du jeu Grenouilloland.
 */
template <class T> class GestStrat
{
	public :
		/**
		 * Stratégie gérée par la classe.
		 */
		static const T& strategie;
};

/**
 * La stratégie est fournie par la méthode Strategie() du Mandataire de celle-ci.
 */
template <class T> const T& GestStrat<T>::strategie = T::Mandataire::Strategie();

}

#endif

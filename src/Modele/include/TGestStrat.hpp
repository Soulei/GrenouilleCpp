#ifndef TGestStrat_hpp
#define TGestStrat_hpp

namespace grenouilloland {

/**
 * @class GestStrat TGestStrat.hpp
 * @brief GestStrat<T> du Jeu Grenouilloland.
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
 * La stratégie est fournie par la méthode Strategie() du Deleguation de celle-ci.
 */
template <class T> const T& GestStrat<T>::strategie = T::Deleguation::Strategie();

}

#endif

#ifndef PointDeVie_hpp
#define PointDeVie_hpp

#include <gtkmm/frame.h>

	namespace grenouilloland {


	class VueGrenouille;

	/**
	 * @class PointDeVie PointDeVie.hpp
	 * @brief Declaration de la classe PointDeVie repésentant la santé de la grenouille

	*/
	class PointDeVie: public Gtk::Frame {

	/**
	*(Attention)
	*Declaration d'amitié.
	*/
	friend class Vue;

	public:

		/**
		* Constructeur logique.
		*/
		PointDeVie(const Glib::ustring& titre);

	protected:
		/**
		* Methode qui met à jour la santé de la grenouille
		*/
		void mettreAJour(const Presentateur& presentateur);

	private:

		/**
		* Constructeur par recopie.
		*/
		PointDeVie(const PointDeVie& autre) = delete;

		/**
		* Operateur d'affectation.
		*
		* @param[in] autre - l'instance à recopier.
		* @return cette instance après recopie.
		*/
		PointDeVie& operator=(const PointDeVie& autre) = delete;

	protected:

		/**
		* Image.
		*/
		Gtk::Image imageCoeur;

		/**
		* Label.
		*/
		Gtk::Label labelPv;

	};
}

#endif

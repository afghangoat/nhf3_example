/**
 * @file Film.hpp
 * @brief Ez az osztály felelős az alap film osztály.
 *
 * @author Funk Gábor
 * @date 2025-04-27
 */
#ifndef FILM_HPP
#define FILM_HPP

#include <string>
#include <iostream>

/**
 * @class Film
 * @brief Az alap film base osztály. Tartalmazza a film címét, meddig tart és kiadási évét. (Megjelenése)
 */
class Film {
	protected:
	
		std::string cim; ///< A film címe.
		int lejatszasiIdo; ///< Meddig tart a film percben.
		int kiadasiEv; ///< A film megjelenési ideje évben.

	public:
		Film(const std::string& cim, int lejatszasiIdo, int kiadasiEv); ///< A film konstruktora ami címet, megjelenést és időtartamot kér.

		virtual void kiir() const; ///< Kiírja a családfilm nevét, lejátszási idejét (meddíg tart percben) és címét. 
		
		void setEv(int ujEv); ///< Setter a megjelenési évre.
		int getEv() const; ///< Visszaadja a megjelenési évet.
		void setCim(const std::string& ujCim); ///< Setter a címre.
		std::string getCim() const; ///< Visszaadja a címet.
		virtual void kiir_stream(std::ostream& os) const;

		virtual ~Film() = default; ///< Virtuális destruktor mert fognak öröklődni osztályok a Film osztályból.
		
		friend std::ostream& operator<<(std::ostream& os, const Film& film);
};
#endif
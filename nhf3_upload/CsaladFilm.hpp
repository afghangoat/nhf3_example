/**
 * @file CsaladFilm.hpp
 * @brief Ez az osztály felelős a családi filmek megvalósításáért.
 *
 * @author Funk Gábor
 * @date 2025-04-27
 */
#ifndef CSALADFILM_HPP
#define CSALADFILM_HPP

#include "Film.hpp"

/**
 * @class CsaladFilm
 * @brief Speciális korhatáros film.
 */
class CsaladFilm : public Film {
	private:
		int korhatar; ///< A minimum korhatár.

	public:
		CsaladFilm(const std::string& cim, int lejatszasiIdo, int kiadasiEv, int korhatar); ///< Alap konstruktor ami a filmhez hasonló csak a korhatárt is meg kell adni.

		void kiir() const override; ///< Kiírja a családfilm nevét, lejátszási idejét (meddíg tart percben), korhatárát és címét. 
		void kiir_stream(std::ostream& os) const override;
};

#endif
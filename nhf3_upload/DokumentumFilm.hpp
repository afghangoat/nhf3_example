/**
 * @file DokumentumFilm.hpp
 * @brief Ez az osztály felelős a dokumentum filmek megvalósításáért.
 *
 * @author Funk Gábor
 * @date 2025-04-27
 */
#ifndef DOKFILM_HPP
#define DOKFILM_HPP

#include "Film.hpp"

/**
 * @class DokumentumFilm
 * @brief Speciális film leírással.
 */
class DokumentumFilm : public Film {
	private:
		std::string leiras; ///< Leírja, hogy miről szól a dokumentumfilm.

	public:
		DokumentumFilm(const std::string& cim, int lejatszasiIdo, int kiadasiEv, const std::string& leiras); ///< Alap konstruktor ami a filmhez hasonló csak a leírást is meg kell adni.

		void kiir() const override; ///< Kiírja a családfilm nevét, lejátszási idejét (meddíg tart percben), leírását és címét. 
		void kiir_stream(std::ostream& os) const override;
};

#endif
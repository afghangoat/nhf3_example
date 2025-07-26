/**
 * @file Filmtar.hpp
 * @brief Ez az osztály felelős a filmek tárolásáért, a keresésért, olvasásért.
 *
 * @author Funk Gábor
 * @date 2025-04-27
 */
#ifndef FILMTAR_HPP
#define FILMTAR_HPP

#include "Film.hpp"
#include "CsaladFilm.hpp"
#include "DokumentumFilm.hpp"

#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>
#include <fstream>
#include <sstream>
#include "Filehiba.hpp"

#include "DinTomb.hpp"

/**
 * @class FilmTar
 * @brief A filmek tárolásáért és elérését biztosító osztály.
 */
class FilmTar {
	private:
		Tarolo<Film*> filmek; ///< A filmek pointerként tárolva

	public:
		void hozzaad(Film* film); ///< Hozzáad egy filmet a tárolóba.

		void kiir() const; ///<Kiírja a filmtárolóba lévő összes filmet.
		
		Tarolo<Film*> keres(const std::string& keresett) const; ///< Megkeresi a paraméterként kapott rész stringből a cím alapján a filmeket és egy dinamikus tömböt ad vissza amely azokat tartalmazza.

		void modositas(size_t index, const std::string& uj_cim, int uj_ev); ///< Modosítja az index-edik filmet új címmel és új évszámmal.
		
		void torles(int index); ///< Törli az index-edik elemet a tárolóból.
		
		size_t mennyi_elem() const; ///< Megadja hogy hány film van a tárolóba.

		~FilmTar(); ///< Destruktor, felszabadítja a tárolt elemeket.
		
		void file_ment(const std::string& fajlnev) const;
		void file_beolvas(const std::string& fajlnev);
};

#endif
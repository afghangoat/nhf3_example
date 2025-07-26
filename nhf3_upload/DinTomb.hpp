#ifndef DINTOMB_HPP
#define DINTOMB_HPP

#include <iostream>
#include <stdexcept>
#include <algorithm>
#include <cctype>
#include <string>

/**
 * @file DinTomb.hpp
 * @brief Ebbe a fájlba van a dinamikus tömb osztály
 *
 * @author Funk Gábor
 * @date 2025-04-27
 */

/**
 * @class Tarolo
 * @brief Egy alap generikus dinamikus tároló.
 * @tparam T mit tároljon a tömb?
 */
template <typename T>
class Tarolo {
	private:
		T* tomb; ///< Tömb base pointer.
		size_t kapacitas; ///< A tömb kapacitása.
		size_t aktualisMeret; ///< A tömbbe mennyi elem van jelenleg.
		bool birtokolt;

	public:
		Tarolo(bool birtokolt_=true);

		~Tarolo();
		void hozzaad(const T& elem); ///< Hozzáad egy új elemet a tömbhöz, ha nincs elég hely, foglal még és nagyobbodik a tömb.

		size_t meret() const; ///< Visszaadja, hogy mennyi elem van a tömbben.
		
		void torol(size_t index); ///< Töröl egy indexedik elemet a tömbből.
		
		void torol_egesz(); ///< Törli az összes elemet a tömbből.

		T& operator[](size_t index); ///< Visszaadja a tömb [i]-edik elemét.

		const T& operator[](size_t index) const; ///< Visszaadja a tömb [i]-edik elemét. Ez konstans hívásra kell.
		
};

#include "Tarolo_impl.hpp"

#endif
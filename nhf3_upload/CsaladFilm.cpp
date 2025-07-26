#include "CsaladFilm.hpp"

CsaladFilm::CsaladFilm(const std::string& cim, int lejatszasiIdo, int kiadasiEv, int korhatar): Film(cim, lejatszasiIdo, kiadasiEv), korhatar(korhatar) {}

void CsaladFilm::kiir() const {
	Film::kiir();
	std::cout << "Korhatár: " << korhatar << "+" << std::endl;
}

void CsaladFilm::kiir_stream(std::ostream& os) const {
    os << "1 " << getCim() << "|" << lejatszasiIdo << " " << getEv() << " " << korhatar;
}
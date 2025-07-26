#include "DokumentumFilm.hpp"

DokumentumFilm::DokumentumFilm(const std::string& cim, int lejatszasiIdo, int kiadasiEv, const std::string& leiras): Film(cim, lejatszasiIdo, kiadasiEv), leiras(leiras) {}

void DokumentumFilm::kiir_stream(std::ostream& os) const {
    os << "2 " << getCim() << "|" << lejatszasiIdo << " " << getEv() << " " << leiras;
}

void DokumentumFilm::kiir() const {
	Film::kiir();
	std::cout << "Leírás: " << leiras << std::endl;
}
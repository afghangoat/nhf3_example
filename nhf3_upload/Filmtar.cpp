#include "Filmtar.hpp"

void FilmTar::hozzaad(Film* film) {
	filmek.hozzaad(film);
}

void FilmTar::kiir() const {
	for(size_t i=0;i<filmek.meret();i++){
		filmek[i]->kiir();
		std::cout << "--------------------------" << std::endl;
	}
}

Tarolo<Film*> FilmTar::keres(const std::string& keresett) const {
	Tarolo<Film*> talalatok(false);  

	std::string keresett_lower = keresett;
	std::transform(keresett_lower.begin(), keresett_lower.end(), keresett_lower.begin(), ::tolower);

	for (size_t i = 0; i < filmek.meret(); ++i) {
		Film* film = filmek[i];
		if (film == nullptr) continue;

		std::string cim = film->getCim();
		std::string cim_lower = cim;
		std::transform(cim_lower.begin(), cim_lower.end(), cim_lower.begin(), ::tolower);

		if (cim_lower.find(keresett_lower) != std::string::npos) {
			talalatok.hozzaad(film);
		}
	}

	return talalatok;
}

void FilmTar::modositas(size_t index, const std::string& uj_cim, int uj_ev) {

    filmek[index ]->setCim(uj_cim);
    filmek[index ]->setEv(uj_ev);
    std::cout << "A film sikeresen módosítva.\n";
}

void FilmTar::torles(int index) {
    if (index < 0) {
        throw std::out_of_range("Hibás index a törléshez!");
        return;
    }

    filmek.torol(index);

    std::cout << "A film sikeresen törölve.\n";
}

FilmTar::~FilmTar() {
	//filmek.torol_egesz();
}

size_t FilmTar::mennyi_elem() const{
	return filmek.meret();
}

void FilmTar::file_beolvas(const std::string& fajlnev) {
	std::ifstream fin(fajlnev);
	if (!fin.is_open()) {
		throw FileMegnyitasHiba(fajlnev);
		return;
	}

	std::string sor;
	while (std::getline(fin, sor)) {
		std::istringstream iss(sor);
		int tipus;
		std::string cim;
		int hossz, ev;

		iss >> tipus;
		iss.ignore();

		std::getline(iss, cim, '|');
		iss >> hossz >> ev;

		if (tipus == 0) {
			hozzaad(new Film(cim, hossz, ev));
		}
		else if (tipus == 1) {
			int korhatar;
			iss >> korhatar;
			hozzaad(new CsaladFilm(cim, hossz, ev, korhatar));
		}
		else if (tipus == 2) {
			std::string leiras;
			iss.ignore();
			std::getline(iss, leiras);
			hozzaad(new DokumentumFilm(cim, hossz, ev, leiras));
		}
	}

	fin.close();
}

void FilmTar::file_ment(const std::string& fajlnev) const {
	std::ofstream fout(fajlnev);
	if (!fout.is_open()) {
		throw FileMegnyitasHiba(fajlnev);
		return;
	}

	for (size_t i = 0; i < filmek.meret(); ++i) {
		fout << *filmek[i] << "\n";
	}

	fout.close();
}
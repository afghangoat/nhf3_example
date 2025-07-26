#include "Film.hpp"

Film::Film(const std::string& cim, int lejatszasiIdo, int kiadasiEv): cim(cim), lejatszasiIdo(lejatszasiIdo), kiadasiEv(kiadasiEv) {}

void Film::kiir() const {
	std::cout << "Cím: " << cim << ", Lejátszási idő: " << lejatszasiIdo << " perc, Kiadási év: " << kiadasiEv << std::endl;
}
void Film::kiir_stream(std::ostream& os) const{
	os << "0 " << getCim() << "|" << lejatszasiIdo << " " << getEv();
}

std::ostream& operator<<(std::ostream& os, const Film& film) {
	film.kiir_stream(os);
	return os;
}

void Film::setEv(int ujEv){
	kiadasiEv=ujEv;
}
int Film::getEv() const{
	return kiadasiEv;
}
void Film::setCim(const std::string& ujCim){
	cim=ujCim;
}
std::string Film::getCim() const{
	return cim;
}
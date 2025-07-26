#ifndef TI_HPP
#define TI_HPP

template <typename T>
Tarolo<T>::Tarolo(bool birtokolt_): tomb(nullptr), kapacitas(0), aktualisMeret(0), birtokolt(birtokolt_) {}

template <typename T>
Tarolo<T>::~Tarolo() {
	torol_egesz();
}

template <typename T>
void Tarolo<T>::hozzaad(const T& elem) {
	if (aktualisMeret == kapacitas) {
		size_t ujKapacitas = (kapacitas == 0) ? 1 : kapacitas * 2;
		T* ujTomb = new T[ujKapacitas];

		for (size_t i = 0; i < aktualisMeret; i++) {
			ujTomb[i] = tomb[i];
		}

		delete[] tomb;
		tomb = ujTomb;
		kapacitas = ujKapacitas;
	}

	tomb[aktualisMeret] = elem;
	aktualisMeret++;
}

template <typename T>
size_t Tarolo<T>::meret() const {
	return aktualisMeret;
}

template <typename T>
T& Tarolo<T>::operator[](size_t index) {
	if (index > aktualisMeret+1) {
		std::cout << "|" << index;
		throw std::out_of_range("Index nincs benne tömb határain!");
	}
	return tomb[index];
}
template <typename T>
const T& Tarolo<T>::operator[](size_t index) const {
	if (index > aktualisMeret+1) {
		std::cout << "|" << index;
		throw std::out_of_range("Index nincs benne tömb határain!");
	}
	return tomb[index];
}

template <typename T>
void Tarolo<T>::torol(size_t index) {
	if (index >= aktualisMeret) {
		throw std::out_of_range("Hibás index a törléshez!");
	}
	
	if (birtokolt && tomb[index] != nullptr) {
		delete tomb[index];
	}

	for (size_t i = index; i < aktualisMeret - 1; ++i) {
		tomb[i] = tomb[i + 1];
	}

	--aktualisMeret;
}

template <typename T>
void Tarolo<T>::torol_egesz() {
	if (birtokolt) {
		for (size_t i = 0; i < meret(); i++) {
			if (tomb[i] != nullptr) {
				delete tomb[i];
				tomb[i] = nullptr;
			}
		}
	}
	if (tomb != nullptr) {
		delete[] tomb;
		tomb = nullptr;
	}
}
#endif
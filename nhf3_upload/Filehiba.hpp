#ifndef FILEHIBA_HPP
#define FILEHIBA_HPP

#include <stdexcept>
#include <string>

class FileMegnyitasHiba : public std::runtime_error {
public:
	explicit FileMegnyitasHiba(const std::string& uzenet): std::runtime_error("Fájlmegnyitási hiba: " + uzenet) {}
};

#endif
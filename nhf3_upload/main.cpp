
#include "Filmtar.hpp"

#include "gtest_lite.h"
#include "memtrace.h"

int main(){
	
	int tesztelunk=0;
	std::cout << "Tesztelünk? (1/0)\n";
	std::cin >> tesztelunk;
	
	if(tesztelunk==1){
		//A tesztek
		GTINIT(std::cin);
		
		//CsaladFilm hozzáadható-e?
		TEST(Filmtar, csaladfilm) {
			FilmTar filmtar;
			filmtar.hozzaad(new DokumentumFilm("A Föld Története",192, 1995, "NATGEO"));
			filmtar.hozzaad(new DokumentumFilm("Magyarország Története",197, 1999, "Valaki KFT"));

			filmtar.keres("Gyűrű");
			filmtar.modositas(1, "A Gyűrűk Ura: Különkiadás", 2002);

			EXPECT_EQ(2u,filmtar.mennyi_elem());
			
		} ENDM
		
		//DokumentumFilm hozzáadható-e?
		TEST(Filmtar, doku_film) {
			FilmTar filmtar;
			filmtar.hozzaad(new CsaladFilm("A Gyűrűk Ura", 2001, 178, 18));
			filmtar.hozzaad(new CsaladFilm("A Gyűrűk Ura 2", 2005, 155, 19));
			filmtar.hozzaad(new CsaladFilm("A Gyűrűk Ura 2 és fél", 2009, 155, 20));


			EXPECT_EQ(3u,filmtar.mennyi_elem());
			
		} ENDM
		
		//A keresés tesztelése
		TEST(Filmtar, kereses) {
			FilmTar filmtar;
			filmtar.hozzaad(new CsaladFilm("A Gyűrűk Ura", 2001, 178, 18));
			Tarolo<Film*> van_e_talalat=filmtar.keres("Gyűrű");

			EXPECT_EQ(1u,van_e_talalat.meret());
			
		} ENDM
		
		//A keresés módosítással
		TEST(Filmtar, modositas) {
			FilmTar filmtar;
			filmtar.hozzaad(new CsaladFilm("Valami", 2001, 178, 18));
			filmtar.hozzaad(new CsaladFilm("Ez nem sikerült cím", 2001, 178, 18));
			Tarolo<Film*> van_e_talalat=filmtar.keres("Gyűrű");
			

			EXPECT_EQ(0u,van_e_talalat.meret());
			
			filmtar.modositas(0, "A Gyűrűk Ura: Különkiadás", 2002);
			
			filmtar.kiir();
			Tarolo<Film*> van_e_talalat2=filmtar.keres("Gyűrű");
			EXPECT_EQ(1u,van_e_talalat2.meret());
			
		} ENDM
		
		
		
		TEST(Filmtar, torles) {
			FilmTar filmtar;
			filmtar.hozzaad(new DokumentumFilm("A Föld Története",192, 1995, "NATGEO"));
			filmtar.hozzaad(new DokumentumFilm("Magyarország Története",197, 1999, "Invincible KFT"));

			EXPECT_NO_THROW(filmtar.torles(1));
			
			EXPECT_EQ(1u,filmtar.mennyi_elem());
			
		} ENDM
		
		//Tulindexeles
		TEST(Filmtar, tulindexeles) {
			FilmTar filmtar;
			filmtar.hozzaad(new DokumentumFilm("A Föld Története",192, 1995, "NATGEO"));
			filmtar.hozzaad(new DokumentumFilm("Magyarország Története",197, 1999, "Invincible KFT"));

			EXPECT_THROW(filmtar.torles(-2),std::out_of_range) << "Nincs -2-es index."; //-2. elem törlése
			
		} ENDM
		
		TEST(FilmTarTeszt, File kezeles) {
			FilmTar eredeti;
			eredeti.hozzaad(new Film("Tesztfilm", 120, 2000));
			eredeti.hozzaad(new CsaladFilm("Csaladi film", 90, 2010, 6));
			eredeti.hozzaad(new DokumentumFilm("Dokufilm", 60, 2015, "Leiras teszt"));

			std::string fajlnev = "teszt_filmek.txt";

			EXPECT_NO_THROW(eredeti.file_ment(fajlnev));
			
			//EXPECT_THROW(eredeti.file_ment(fajlnev+"nem ertelmes file."),FileMegnyitasHiba);

			FilmTar beolvasott;
			EXPECT_NO_THROW(beolvasott.file_beolvas(fajlnev));

			ASSERT_EQ(eredeti.mennyi_elem(), beolvasott.mennyi_elem());
		} ENDM
		
		TEST(Film, getterek) {
			Film* f =new DokumentumFilm("A Föld Története",192, 1995, "NATGEO");
			f->setEv(1999);
			EXPECT_EQ(f->getEv(),1999);
			
			f->setCim("Uj");
			EXPECT_STREQ(f->getCim().c_str(),"Uj");
			
			delete f;
			
		} ENDM
		
		GTEND(std::cerr);
	
	} else {
		//Példa használatra (Így fog majd a program véglegesen futni.
		FilmTar filmtar;
		std::cout << "Honnan olvasson be a filmtár?:";
		std::string inputfajl;
		std::cin >> inputfajl;
		filmtar.file_beolvas(inputfajl);
		std::string cim;
		std::string leiras;
		int lejatszasiIdo, kiadasiEv, korhatar;
			
		while (true) {
			
			std::cout << "\n=== Menü ===\n";
			std::cout << "1. Film hozzáadása\n";
			std::cout << "2. Filmek listázása\n";
			std::cout << "3. Keresés cím alapján\n";
			std::cout << "4. Film törlése index alapján\n";
			std::cout << "0. Kilépés\n";
			std::cout << "Választás: ";

			
			
			int valasztas;
			std::cin >> valasztas;
			std::cin.ignore();

			if (valasztas == 0) break;
			else if (valasztas == 1) {
				std::cout << "Adja meg a film címét: ";
				getline(std::cin, cim);

				std::cout << "Adja meg a lejátszási időt (perc): ";
				std::cin >> lejatszasiIdo;

				std::cout << "Adja meg a kiadási évet: ";
				std::cin >> kiadasiEv;

				std::cin.ignore();

				std::cout << "Típus (0: Sima, 1: Családi, 2: Dokumentum): ";
				int tipus;
				std::cin >> tipus;
				std::cin.ignore();

				if (tipus == 0) {
					filmtar.hozzaad(new Film(cim, lejatszasiIdo, kiadasiEv));
				} else if (tipus == 1) {
					std::cout << "Adja meg a korhatárt: ";
					std::cin >> korhatar;
					std::cin.ignore();
					filmtar.hozzaad(new CsaladFilm(cim, lejatszasiIdo, kiadasiEv, korhatar));
				} else if (tipus == 2) {
					std::cout << "Adja meg a leírást: ";
					getline(std::cin, leiras);
					filmtar.hozzaad(new DokumentumFilm(cim, lejatszasiIdo, kiadasiEv, leiras));
				}
			}
			else if (valasztas == 2) {
				filmtar.kiir();
			}
			else if (valasztas == 3) {
				std::cout << "Keresett szöveg a címben: ";
				std::string keres;
				getline(std::cin, keres);

				Tarolo<Film*> talalatok = filmtar.keres(keres);
				std::cout << "\nKeresési találatok:\n";
				for (size_t i = 0; i < talalatok.meret(); ++i) {
					std::cout << "[" << i << "] ";
					talalatok[i]->kiir();
					std::cout << "--------------------------\n";
				}
			}
			else if (valasztas == 4) {
				std::cout << "Adja meg a törlendő film indexét: ";
				int index;
				std::cin >> index;
				std::cin.ignore();
				try {
					filmtar.torles(index);
				} catch (const std::exception& e) {
					std::cerr << "Hiba: " << e.what() << "\n";
				}
			}
			else {
				std::cout << "Érvénytelen választás.\n";
			}
		}

		filmtar.file_ment(inputfajl);
		std::cout << "\nKilépés...\n";
	}

    return 0;
}
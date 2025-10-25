#include <iostream>
#include <string>
#include <cstddef>

struct Student {
	std::string ime;
	std::string JMBAG;
	int godina_studija;
	int ECTS_bodovi;
	double prosjek_ocjena;
};

void filter_students(Student studenti[], std::size_t n,
					void (*akcija)(Student&),
					bool (*filter)(Student&)) {
	for (std::size_t i = 0; i < n; ++i) {
		if (filter(studenti[i])) {
			akcija(studenti[i]);
		}
	}
}

void ispis(Student& s) {
	std::cout << "Ime: " << s.ime << ", JMBAG: " << s.JMBAG << ", Godina: " << s.godina_studija << ", ECTS: " << s.ECTS_bodovi << ", Prosjek: " << s.prosjek_ocjena << std::endl;
}

void povecaj_godinu(Student& s) {
	s.godina_studija++;
}

int main() {
	Student studenti[] = {
		{"Marin", "1234567890", 1, 10, 3.5},
		{"Iva", "1111111111", 2, 60, 4.2},
		{"Karlo", "0987654321", 3, 20, 2.5},
		{"Toma", "1231231230", 1, 0, 3.2},
		{"Klara", "2223334440", 2, 55, 2.4}
	};
	std::size_t n = sizeof(studenti) / sizeof(studenti[0]);

	auto uvjet_prva_godina = [](Student& s) {
		return s.godina_studija == 1 && s.ECTS_bodovi > 0;
	};

	auto uvjet_vece_3_5 = [](Student& s) {
		return s.prosjek_ocjena > 3.5;
	};

	auto uvjet_45_ECTS = [](Student& s) {
		return s.ECTS_bodovi >= 45;
	};

	std::cout << "Studenti prve godine koji su polozili barem jedan ispit su: " << std::endl;
	filter_students(studenti, n, ispis, uvjet_prva_godina);

	std::cout << "\nStudenti s prosjekom vecim od 3.5 su: " << std::endl;
	filter_students(studenti, n, ispis, uvjet_vece_3_5);

	std::cout << "\nStudenti s vise od 45 ECTS bodova su: " << std::endl;
	filter_students(studenti, n, ispis, uvjet_45_ECTS);

	std::cout << "\nSvi studenti nakon promjene: " << std::endl;
	for (std::size_t i = 0; i < n; ++i) {
		ispis(studenti[i]);
	}

	return 0;
}
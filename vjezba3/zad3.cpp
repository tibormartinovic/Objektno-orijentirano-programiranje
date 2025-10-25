#include <iostream>
#include <vector>

int main() {
	auto paran = [](int x) { return x % 2 == 0; };
	auto neparan = [](int x) { return x % 2 != 0; };
	auto udvostruci = [](int x) { return x * 2; };
	auto podijeli = [](int x) { return x / 2; };

	auto funkcija1 = [&](std::vector<int>&niz) {
		for (auto& element : niz) {
			if (paran(element)) {
				element = podijeli(element);
			} else {
				element = udvostruci(element);
			}
		}
	};

	auto izracunaj_sumu_produkt = [&](const std::vector<int>&niz, int& suma, int& produkt) {
		suma = 0;
		produkt = 1;
		auto dodavanje_u_sumu = [&](int x) { suma += x; };
		auto dodavanje_u_produkt = [&](int x) { produkt *= x; };

		for (int element : niz) {
			dodavanje_u_sumu(element);
			dodavanje_u_produkt(element);
		}
	};

	auto izracunaj_sumu_vecu_od_praga = [&](const std::vector<int>&niz, int prag, int& suma) {
		suma = 0;
		auto dodavanje_ako_je_veci = [prag, &suma](int x) { if (x > prag) suma += x; };

		for (int element : niz) {
			dodavanje_ako_je_veci(element);
		}
	};


	std::vector<int> niz = {1, 2, 3, 4, 5};

	std::cout << "Originalni niz je: ";
	for (int element : niz) {
		std::cout << element << " ";
	}
	std::cout << std::endl;


	funkcija1(niz);
	std::cout << "Niz nakon modifikacije: ";
	for (int element : niz) {
		std::cout << element << " ";
	}
	std::cout << std::endl;

	int suma;
	int produkt;
	izracunaj_sumu_produkt(niz, suma, produkt);
	std::cout << "Suma je: " << suma << ", a produkt je: " << produkt << std::endl;


	int prag = 3;
	int suma_prag;
	izracunaj_sumu_vecu_od_praga(niz, prag, suma_prag);
	std::cout << "Suma brojeva vecih od " << prag << "je: " << suma_prag << std::endl;

	return 0;
}
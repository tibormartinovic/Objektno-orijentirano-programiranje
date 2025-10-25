#include <iostream>
#include <cstddef>

inline bool ascending(int a, int b) {
	return a < b;
}

inline bool descending(int a, int b) {
	return a > b;
}

void sortt(int niz[], std::size_t n, bool (*cmp)(int, int)) {
	for (std::size_t i = 0; i < n - 1; ++i) {
		for (std::size_t j = 0; j < (n - i - 1); ++j) {
			if (!cmp(niz[j], niz[j + 1])) {
				int temp = niz[j];
				niz[j] = niz[j + 1];
				niz[j + 1] = temp;
			}
		}
	}
}

int main() {
	int niz[] = {6, 4, 9, 2, 3};
	std::size_t n = sizeof(niz) / sizeof(niz[0]);
	
	std::cout << "Originalni niz je: ";
	for (std::size_t i = 0; i < n; ++i) {
		std::cout << niz[i] << " ";
	}
	std::cout << std::endl;


	sortt(niz, n, ascending);
	std::cout << "Niz nakon ascending: ";
	for (std::size_t i = 0; i < n; ++i) {
		std::cout << niz[i] << " ";
	}
	std::cout << std::endl;


	sortt(niz, n, descending);
	std::cout << "Niz nakon descending: ";
	for (std::size_t i = 0; i < n; ++i) {
		std::cout << niz[i] << " ";
	}
	std::cout << std::endl;


	return 0;
}
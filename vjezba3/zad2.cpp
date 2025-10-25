#include <iostream>
#include <cstddef>

template <typename T>
inline bool ascending(T a, T b) {
	return a < b;
}

template <typename T>
inline bool descending(T a, T b) {
	return a > b;
}

template <typename T>
void sortt(T niz[], std::size_t n, bool (*cmp)(T, T)) {
	for (std::size_t i = 0; i < n - 1; ++i) {
		for (std::size_t j = 0; j < (n - i - 1); ++j) {
			if (!cmp(niz[j], niz[j + 1])) {
				T temp = niz[j];
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


	double double_niz[] = {6.6, 4.4, 9.9, 2.2, 3.3};
	std::size_t dbl_N = sizeof(double_niz) / sizeof(double_niz[0]);

	std::cout << "Originalni double niz je: ";
	for (std::size_t i = 0; i < dbl_N; ++i) {
		std::cout << double_niz[i] << " ";
	}
	std::cout << std::endl;

	sortt(double_niz, dbl_N, ascending);
	std::cout << "Ascending double niz je: ";
	for (std::size_t i = 0; i < dbl_N; ++i) {
		std::cout << double_niz[i] << " ";
	}
	std::cout << std::endl;

	sortt(double_niz, dbl_N, descending);
	std::cout << "Descending double niz je: ";
	for (std::size_t i = 0; i < dbl_N; ++i) {
		std::cout << double_niz[i] << " ";
	}
	std::cout << std::endl;



	return 0;
}
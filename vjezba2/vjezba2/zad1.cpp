#include <iostream>

int* fibonacci_niz(int n) {
	if (n <= 0) {
		return nullptr;
	}

	int* niz = new int[n] {1, 1}; 

	for (int i = 2; i < n; ++i) {
		niz[i] = niz[i - 1] + niz[i - 2];
	}
	return niz;
}

int main() {
	int n;
	std::cout << "Broj clanova niza je: ";
	std::cin >> n;

	int* fibonacci = fibonacci_niz(n);
	
	if (fibonacci != nullptr) {
		std::cout << "Fibonaccijev niz: ";
		for (int i = 0; i < n; ++i) {
			std::cout << fibonacci[i] << " ";
		}
		std::cout << std::endl;
	}
	delete[] fibonacci;
	return 0;

}
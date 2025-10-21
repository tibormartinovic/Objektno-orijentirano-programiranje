#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>

double** napravi_matricu(int m, int n) {
	double** matrica = new double*[m];
	for (int i = 0; i < m; i++) {
		matrica[i] = new double[n];
	}
	return matrica;
}

void izbrisi_matricu(double** matrica, int m) {
	for (int i = 0; i < m; i++) {
		delete[] matrica[i];
	}
	delete[] matrica;
}

void unesi_matricu(double** matrica, int m, int n) {
	std::cout << "Unesi elemente matrice " << m << "x" << n << ":" << std::endl;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			std::cin >> matrica[i][j];
		}
	}
}

void generiraj_matricu(double** matrica, int m, int n, double a, double b) {
	srand(time(0));
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			matrica[i][j] = a + (b - a) * (rand() / (double)RAND_MAX);
		}
	}
}

double** zbroj_matrica(double** A, double** B, int m, int n) {
	double** C = napravi_matricu(m, n);
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			C[i][j] = A[i][j] + B[i][j];
		}
	}
	return C;
}

double** oduzimanje_matrica(double** A, double** B, int m, int n) {
	double** C = napravi_matricu(m, n);
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			C[i][j] = A[i][j] - B[i][j];
		}
	}
	return C;
}

double** mnozenje_matrica(double** A, double** B, int m, int n, int p) {
	double** C = napravi_matricu(m, p);
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			C[i][j] = 0;
			for (int k = 0; k < n; k++) {
				C[i][j] += A[i][k] * B[k][j];
			}
		}
	}
	return C;
}

double** transponiranje_matrice(double** A, int m, int n) {
	double** T = napravi_matricu(n, m);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			T[i][j] = A[j][i];
		}
	}
	return T;
}

void ispis_matrice(double** matrica, int m, int n) {
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			std::cout << fixed << setprecision(4) << right << setw(10) << matrica[i][j];
		}
		std::cout << std::endl;
	}
}


int main() {
	int m, n, p;
	std::cout << "Unesi dimenzije matrica: ";
	std::cin >> m >> n >> p;

	double** A = napravi_matricu(m, n);
	double** B = napravi_matricu(n, p);
	double** C = napravi_matricu(m, n);


	unesi_matricu(A, m, n);

	double a, b;
	std::cout << "Unesi raspon za matricu B: ";
	std::cin >> a >> b;
	generiraj_matricu(B, n, p, a, b);


	unesi_matricu(C, m, n);

	std::cout << "Matrica A: " << std::endl;
	ispis_matrice(A, m, n);
	std::cout << "Matrica B: " << std::endl;
	ispis_matrice(B, n, p);
	std::cout << "Matrica C: " << std::endl;
	ispis_matrice(C, m, n);


	double** suma = zbroj_matrica(A, C, m, n);
	std::cout << "Zbroj matrica A i C je: " << std::endl;
	ispis_matrice(suma, m, n);
	izbrisi_matricu(suma, m);

	double** razlika = oduzimanje_matrica(A, C, m, n);
	std::cout << "Razlika matrica A i C je: " << std::endl;
	ispis_matrice(razlika, m, n);
	izbrisi_matricu(razlika, m);

	double** produkt = mnozenje_matrica(A, B, m, n, p);
	std::cout << "Umnozak matrica A i B je: " << std::endl;
	ispis_matrice(produkt, m, p);
	izbrisi_matricu(produkt, m);

	double** transponiranje = transponiranje_matrice(A, m, n);
	std::cout << "Transponirana matrica A: " << std::endl;
	ispis_matrice(transponiranje, n, m);
	izbrisi_matricu(transponiranje, n);


	izbrisi_matricu(A, m);
	izbrisi_matricu(B, n);
	izbrisi_matricu(C, m);

	return 0;
}

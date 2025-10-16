#include <iostream>

int ogranicenje(int a, int low = 0, int high = 100) {
	if (a < low) {
		return low;
	} else if (a > high) {
		return high;
	} else {
		return a;
	}
}

double ogranicenje(double a, double low = 0.0, double high = 100.0) {
	if (a < low) {
		return low;
	} else if (a > high) {
		return high;
	} else {
		return a;
	}
}

int main() {
	int a{ 2 };
	double b{ 5.3 };

	std::cout << ogranicenje(b) << '\n';
	std::cout << ogranicenje(a) << '\n';

	return 0;
}
#include <iostream>
#include "zad2.h"

int main() {
	Vector* my_vector = vector_new(2);

	vector_push_back(my_vector, 10);
	vector_push_back(my_vector, 20);
	vector_push_back(my_vector, 30);

	std::cout << "Velicina vektora je: " << vector_size(my_vector) << std::endl;

	std::cout << "Prvi element je: " << vector_front(my_vector) << std::endl;
	std::cout << "Zadnji element je: " << vector_back(my_vector) << std::endl;

	vector_pop_back(my_vector);
	std::cout << "Nova velicina vektora je: " << vector_size(my_vector) << std::endl;

	vector_delete(my_vector);

	return 0;
}
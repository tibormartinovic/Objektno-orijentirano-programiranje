#ifndef VECTOR
#define VECTOR

#include <cstddef>
#include <iostream>

struct Vector {
	int* element;
	int fiz_vel;
	int log_vel;
};

Vector* vector_new(int cap);
void vector_delete(Vector* v);
void vector_push_back(Vector* v, int vrijednost);
void vector_pop_back(Vector* v);
int vector_front(Vector* v);
int vector_back(Vector* v);
int vector_size(Vector *v);

#endif

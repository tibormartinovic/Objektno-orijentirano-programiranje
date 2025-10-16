#include <iostream>
#include "zad2.h"

Vector* vector_new(int cap) {
	Vector* v = new Vector;
	v->element = new int[cap];
	v->log_vel = 0;
	v->fiz_vel = cap;
	return v;
}

void vector_delete(Vector* v) {
	if (v != nullptr) {
		delete[] v->element;
		delete v;
	}
}


void vector_push_back(Vector* v, int vrijednost) {
	if (v->log_vel == v->fiz_vel) {
		int nova_vel = v->fiz_vel * 2;

		int* novi_niz = new int[nova_vel];
		for (int i = 0; i < v->log_vel; ++i) {
			novi_niz[i] = v->element[i];
		}
		delete[] v->element;
		v->element = novi_niz;
		v->fiz_vel = nova_vel;
	}
	v->element[v->log_vel] = vrijednost;
	v->log_vel++;
}

void vector_pop_back(Vector* v) {
	if (v->log_vel > 0) {
		v->log_vel--;
	}
}

int vector_front(Vector* v) {
	if (v->log_vel > 0) {
		return v->element[0];
	}
	return 0;
}

int vector_back(Vector* v) {
	if (v->log_vel > 0) {
		return v->element[v->log_vel - 1];
	}
	return 0;
}

int vector_size(Vector *v) {
	return v->log_vel;
}




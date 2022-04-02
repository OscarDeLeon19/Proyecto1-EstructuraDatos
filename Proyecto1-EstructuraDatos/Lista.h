#pragma once
#include "Nodo.h"

class Lista {
public:
	Lista();
	~Lista();
	void llenarLista(int, int);
	void verLista();
	void verValores();
	Nodo* obtenerNodo(int);
	Nodo* getPrimero();
private:
	struct Nodo* primero;
};
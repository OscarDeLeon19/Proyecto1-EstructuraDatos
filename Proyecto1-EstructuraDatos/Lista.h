#pragma once

class Lista {
public:
	Lista();
	struct Nodo *primero;
	void llenarLista(int, int);
	void verLista();
	void verListaAlRevez();
	Nodo* obtenerNodo(int);
};
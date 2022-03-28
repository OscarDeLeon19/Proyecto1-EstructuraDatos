#include "Lista.h";
#include "Nodo.h";
#include <cstddef>
#include <iostream>
using namespace std;

Lista::Lista() {

}

void Lista::llenarLista(int pos, int fin) {
	primero = new (Nodo);
	primero->posicion = pos;
	primero->anterior = NULL;
	primero->arriba = NULL;
	primero->abajo = NULL;
	Nodo* auxiliar = primero;

	for (size_t i = pos + 1; i <= fin; i++)
	{
		Nodo* nuevo = new (Nodo);
		Nodo* anterior = new (Nodo);
		nuevo->posicion = i;
		nuevo->abajo = NULL;
		nuevo->arriba = NULL;
		auxiliar->siguiente = nuevo;
		anterior = auxiliar;
		auxiliar = auxiliar->siguiente;
		auxiliar->anterior = anterior;
		auxiliar->siguiente = NULL;
	}
}

void Lista::verLista() {
	Nodo* auxiliar = primero;
	cout << " | ";
	while (auxiliar != NULL) {
		int pos = auxiliar->posicion;
		if (pos > 9) {
			cout << auxiliar->posicion << " | ";
		}
		else {
			cout << auxiliar->posicion << "  | ";
		}
		auxiliar = auxiliar->siguiente;
	}
	cout << endl;
}

void Lista::verListaAlRevez() {
	Nodo* auxiliar = primero;	
	while (auxiliar != NULL) {
		auxiliar = auxiliar->siguiente;
		if (auxiliar->siguiente == NULL) {
			Nodo* otro = new (Nodo);
			otro = auxiliar;
			while (otro != NULL) {
				cout << "Nodo No." << otro->posicion << endl;
				otro = otro->anterior;
			}
			break;
		}		
	}
	cout << endl;
}

Nodo* Lista::obtenerNodo(int pos) {
	Nodo* aux = primero;
	for (size_t i = 0; i < pos; i++)
	{
		aux = aux->siguiente;
	}
	return aux;
}

void Lista::verValores() {
	Nodo* auxiliar = primero;
	cout << " | ";
	while (auxiliar != NULL) {
		int pos = auxiliar->valor;
		if (pos > 9) {
			cout << pos << " | ";
		}
		else {
			cout << pos << "  | ";
		}
		auxiliar = auxiliar->siguiente;
	}
	cout << endl;
}
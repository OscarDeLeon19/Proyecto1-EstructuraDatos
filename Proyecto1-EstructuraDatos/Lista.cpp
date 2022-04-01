#include "Lista.h";
#include "Nodo.h";
#include <cstddef>
#include <iostream>
using namespace std;

/*
	Constructor de la clase lista	
*/
Lista::Lista() {

}
/*
	Destructor de la clase Lista
*/
Lista::~Lista()
{

}

/*
	Crea una fila de la matriz enlazando nodos.
*/
void Lista::llenarLista(int pos, int fin) {
	primero = new (Nodo);
	primero->posicion = pos;
	primero->anterior = NULL;
	primero->arriba = NULL;
	primero->abajo = NULL;
	primero->adelante = NULL;
	primero->atras = NULL;
	Nodo* auxiliar = primero;

	for (size_t i = pos + 1; i <= fin; i++)
	{
		Nodo* nuevo = new (Nodo);
		Nodo* anterior = new (Nodo);
		nuevo->posicion = i;
		nuevo->abajo = NULL;
		nuevo->arriba = NULL;
		nuevo->adelante = NULL;
		nuevo->atras = NULL;
		auxiliar->siguiente = nuevo;
		anterior = auxiliar;
		auxiliar = auxiliar->siguiente;
		auxiliar->anterior = anterior;
		auxiliar->siguiente = NULL;
	}
}

/*
	Imprime la fila de una matriz
*/
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

/*
	Obtiene un nodo de la lista segun su posicion.
*/
Nodo* Lista::obtenerNodo(int pos) {
	Nodo* aux = primero;
	for (size_t i = 0; i < pos; i++)
	{
		aux = aux->siguiente;
	}
	return aux;
}

/*
	Devuelve el nodo primero de la lista
*/
Nodo* Lista::getPrimero()
{
	return primero;
}
/*
	Muestra la lista de valores de la lista.
*/
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
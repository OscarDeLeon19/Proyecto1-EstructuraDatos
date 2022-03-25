#include "Matriz.h"
#include "Nodo.h"
#include "Lista.h"
#include <iostream>
using namespace std;

Matriz::Matriz(int filas, int columnas, int niveles) {
	this->filas = filas;
	this->columnas = columnas;
	this->niveles = niveles;
}

void Matriz::verDatosMatriz() {
	cout << "Filas: " << filas <<endl;
	cout << "Columnas: " << columnas << endl;
	cout << "Niveles: " << niveles << endl;
}

void Matriz::listarMatriz() {
	for (size_t i = 0; i < columnas; i++)
	{
		lista[i].verLista();
	}
}

void Matriz::generarMatriz() {
	lista = new Lista[columnas];
	for (size_t i = 0; i < columnas; i++)
	{
		lista[i] = Lista();
		int inicio = 1 + (i *filas);
		int final = filas * (i + 1);
		lista[i].llenarLista(inicio,final);
	}
	listarMatriz();
	primero = new (Nodo);
	primero = lista[0].primero;
	// Iniciamos el proceso de agregar la matriz;
	for (size_t i = 0; i < columnas -1; i++)
	{
		for (size_t j = 0; j < filas; j++)
		{
			Nodo* nodo1 = new (Nodo);
			Nodo* nodo2 = new (Nodo);
			nodo1 = lista[i].obtenerNodo(j);
			nodo2 = lista[i + 1].obtenerNodo(j);
			nodo1->abajo = nodo2;
			nodo2->arriba = nodo1;
		}
	}
}


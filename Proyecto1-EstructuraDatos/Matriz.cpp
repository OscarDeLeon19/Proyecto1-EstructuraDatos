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

bool Matriz::comprobarVictoria(){
	bool comprobacion = true;
	for (int i = 0; i < columnas; i++)
	{
		for (int j = 0; j < filas; j++)
		{
			Nodo* nodo = new (Nodo);
			nodo = lista[i].obtenerNodo(j);
			if (i == (columnas - 1) && j == (filas -1)) {
				if (nodo->valor != 0) {
					comprobacion = false;
				}
			}
			else {
				if (nodo->posicion != nodo->valor) {
					comprobacion = false;
				}
			}
		}
	}
	return comprobacion;
}

int Matriz::contarPunteo() {
	int punteo = 0;
	for (int i = 0; i < columnas; i++)
	{
		for (int j = 0; j < filas; j++)
		{
			Nodo* nodo = new (Nodo);
			nodo = lista[i].obtenerNodo(j);
			if (nodo->posicion == nodo->valor) {
				punteo = punteo + 2;
			}
		}
	}
	return punteo;
}

Lista* Matriz::obtenerLista() {
	return lista;
}
Nodo* Matriz::devolverJugador()
{
	Nodo* nodoJugador = new (Nodo);
	for (int i = 0; i < columnas; i++)
	{
		for (int j = 0; j < filas; j++)
		{
			Nodo* nodo = new (Nodo);
			nodo = lista[i].obtenerNodo(j);
			if (nodo->valor == 0) {
				nodoJugador = nodo;
			}
		}
	}
	return nodoJugador;
}
void Matriz::verDatosMatriz() {
	cout << "Filas: " << filas <<endl;
	cout << "Columnas: " << columnas << endl;
	cout << "Niveles: " << niveles << endl;
}

void Matriz::listarMatrizPosicion() {
	for (size_t i = 0; i < columnas; i++)
	{
		lista[i].verLista();
	}
	cout << endl;
}

void Matriz::listarMatrizValor() {

	for (int i = 0; i < columnas; i++)
	{
		lista[i].verValores();
	}
	cout << endl;
}
void Matriz::generarMatriz() {
	// Se inicia con la creacion de las listas enlazadas
	lista = new Lista[columnas];
	for (size_t i = 0; i < columnas; i++)
	{
		lista[i] = Lista();
		int inicio = 1 + (i *filas);
		int final = filas * (i + 1);
		lista[i].llenarLista(inicio,final);
	}
	listarMatrizPosicion();
	primero = new (Nodo);
	primero = lista[0].primero;
	// Iniciamos el proceso de agregar los nodos de arriba y abajo;
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

void Matriz::ingresarDatos(int* datosMatriz) {
	int dato = 0;
	for (int i = 0; i < columnas; i++)
	{
		for (int j = 0; j < filas; j++)
		{
			Nodo* nodo = new (Nodo);
			nodo = lista[i].obtenerNodo(j);
			nodo->valor = datosMatriz[dato];
			dato++;
		}
	}
	listarMatrizValor();
}


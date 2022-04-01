#include "Matriz.h"
#include "Nodo.h"
#include "Lista.h"
#include <iostream>
using namespace std;
/*
	Constructor de la clase matriz
*/
Matriz::Matriz(int filas, int columnas) {
	this->filas = filas;
	this->columnas = columnas;
}
/*
	Destructor de la clase matriz
*/
Matriz::Matriz()
{
}
/*
	Destructor de la clase matriz
*/
Matriz::~Matriz()
{
	lista->~Lista();
}
/*
	Comprueba si los nodos estan ordenados de la manera correcta.
	Devuelve el resultado.
*/
bool Matriz::comprobarVictoria(bool ultimo){
	bool comprobacion = true;
	for (int i = 0; i < columnas; i++)
	{
		for (int j = 0; j < filas; j++)
		{
			Nodo* nodo = new (Nodo);
			nodo = lista[i].obtenerNodo(j);
			if (ultimo == true) {
				if (i == (columnas - 1) && j == (filas - 1)) {
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
			else {
				if (nodo->posicion != nodo->valor) {
					comprobacion = false;
				}
			}
		}
	}
	return comprobacion;
}
/*
	Cuenta el punteo obtenido en la matriz
*/
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
/*
	Obtiene el array de listas de la matriz
*/
Lista* Matriz::obtenerLista() {
	return lista;
}

/*
	Devuelve el nodo con el valor 0
*/
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

/*
	Mueestra la lista de matrices con sus posiciones
*/
void Matriz::listarMatrizPosicion() {
	for (size_t i = 0; i < columnas; i++)
	{
		lista[i].verLista();
	}
	cout << endl;
}
/*
	Muestra la matriz con sus valores
*/
void Matriz::listarMatrizValor() {
	cout << endl;
	for (int i = 0; i < columnas; i++)
	{
		lista[i].verValores();
	}
	cout << endl;
}

/*
	Crea la matriz ortogonal utilizando varias listas enlazadas.
*/
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
	primero = new (Nodo);
	primero = lista[0].getPrimero();;
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
/*
	Ingresa los datos de la matriz a cada nodo
*/
int Matriz::ingresarDatos(int dato, int* datosMatriz) {
	
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
	return dato;
}
/*
	Ingresa las posiciones a los nodos de la matriz
*/
int Matriz::ingresarPosiciones(int lugar) {
	for (int i = 0; i < columnas; i++)
	{
		for (int j = 0; j < filas; j++)
		{
			Nodo* nodo = new (Nodo);
			nodo = lista[i].obtenerNodo(j);
			nodo->posicion = lugar;
			lugar++;
		}
	}
	return lugar;
}

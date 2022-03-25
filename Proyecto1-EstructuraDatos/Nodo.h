#pragma once

struct Nodo
{
	int valor;
	int posicion;
	struct Nodo* siguiente;
	struct Nodo* anterior;
	struct Nodo* arriba;
	struct Nodo* abajo;
	struct Nodo* atras;
	struct Nodo* adelante;
};
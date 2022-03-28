#pragma once
#include <cstddef>
#include "Lista.h"
#include "Nodo.h"

class Matriz {
public:
	Matriz(int,int,int);
	void verDatosMatriz();
	void generarMatriz();
	void listarMatrizPosicion();
	void listarMatrizValor();
	void ingresarDatos(int*);
	int contarPunteo();
	bool comprobarVictoria();
	Lista* obtenerLista();
	Nodo* devolverJugador();
private:
	int filas;
	int columnas;
	int niveles;
	class Lista* lista;
	struct Nodo* primero;
};
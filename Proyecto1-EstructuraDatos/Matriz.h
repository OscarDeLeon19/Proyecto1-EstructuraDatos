#pragma once
#include <cstddef>
#include "Lista.h"
#include "Nodo.h"

class Matriz {
public:
	Matriz(int,int);
	Matriz();
	~Matriz();
	void generarMatriz();
	void listarMatrizPosicion();
	void listarMatrizValor();
	int ingresarDatos(int, int*);
	int ingresarPosiciones(int);
	int contarPunteo();
	bool comprobarVictoria(bool);
	Lista* obtenerLista();
	Nodo* devolverJugador();
private:
	int filas;
	int columnas;
	class Lista* lista;
	struct Nodo* primero;
};
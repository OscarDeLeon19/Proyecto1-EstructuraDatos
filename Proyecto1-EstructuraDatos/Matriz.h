#pragma once
#include <cstddef>
#include "Lista.h"

class Matriz {
public:
	Matriz(int,int,int);
	void verDatosMatriz();
	void generarMatriz();
	void listarMatrizPosicion();
	void listarMatrizValor();
	void ingresarDatos(int*);
	Lista* obtenerLista();
private:
	int filas;
	int columnas;
	int niveles;
	class Lista* lista;
	struct Nodo* primero;
};
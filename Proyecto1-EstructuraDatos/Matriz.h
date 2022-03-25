#pragma once
#include <cstddef>

class Matriz {
public:
	Matriz(int,int,int);
	void verDatosMatriz();
	void generarMatriz();
	void listarMatriz();
private:
	int filas;
	int columnas;
	int niveles;
	class Lista* lista;
	struct Nodo* primero;
	struct Nodo* jugador;
};
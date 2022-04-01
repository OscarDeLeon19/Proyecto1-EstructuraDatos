#pragma once

#include "Matriz.h"


class Juego {
public:
	Juego(Matriz*, int*, int, int, int);
	~Juego();
	void iniciarJuego();
	void moverArriba();
	void moverAbajo();
	void moverIzquierda();
	void moverDerecha();
	void moverAdelante();
	void moverAtras();
	void iniciarMatriz();
	void agregarNodosMatriz();
	void listarMatriz();
	void obtenerJugador();	
	int obtenerPunteo();
	bool comprobarVictoria();
private:
	int niveles;
	int columnas;
	int filas;
	class Matriz* matriz;
	struct Nodo* jugador;
	int* datosMatriz;
	class Tabla* tabla;
};
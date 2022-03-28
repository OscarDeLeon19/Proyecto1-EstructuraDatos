#pragma once

#include "Matriz.h"

class Juego {
public:
	Juego(Matriz*, int*);
	void iniciarJuego();
	void obtenerJugador();
	void moverArriba();
	void moverAbajo();
	void moverIzquierda();
	void moverDerecha();
	void iniciarMatriz();
private:
	class Matriz* matriz;
	struct Nodo* jugador;
	int* datosMatriz;
};
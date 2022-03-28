#include "Juego.h"
#include <iostream>
using namespace std;

Juego::Juego(Matriz *matriz, int* datosMatriz)
{
	this->matriz = matriz;
	this->datosMatriz = datosMatriz;
}

void Juego::iniciarJuego() {
	string nombre;
	cout << "Ingresa tu nombre: " << endl;
	cin >> nombre;
	cout << "Inicia el juego" << endl;
	iniciarMatriz();
	jugador = new (Nodo);
	jugador = matriz->devolverJugador();
	bool accion = true;
	int pasos = 0;
	unsigned tiempoInicial, tiempoFinal;
	
	tiempoInicial = clock();
	while (accion == true) {
		if (accion == true) {
			pasos++;
			cout << "Acciones:" << endl;
			cout << "Mover arriba: W" << endl;
			cout << "Mover izquierda: A" << endl;
			cout << "Mover abajo: S" << endl;
			cout << "Mover derecha: D" << endl;
			cout << "Reiniciar: R" << endl;
			cout << "Terminar: T" << endl;
			char movimiento;
			cin >> movimiento;
			switch (movimiento) {
			case 'w':
				moverArriba();
				break;
			case 'a':
				moverIzquierda();
				break;
			case 's':
				moverAbajo();
				break;
			case 'd':
				moverDerecha();
				break;
			case 't':
				accion = false;
				break;
			case 'r':
				iniciarMatriz();
				jugador = matriz->devolverJugador();
				break;
			default:
				cout << "Accion invalida" << endl;
			}
			bool victoria = matriz->comprobarVictoria();
			if (victoria == true) {
				cout << "Haz ganado" << endl;
				accion = false;				
			}
		}		
	}
		tiempoFinal = clock();
		double tiempoPartida = (double(tiempoFinal - tiempoInicial) / CLOCKS_PER_SEC);
		int punteo = matriz->contarPunteo();
		cout << "Reporte" << endl;
		cout << "Pasos: " << pasos << endl;
		cout << "Tiempo: " << tiempoPartida << endl;
		cout << "Punteo: " << punteo << endl;
	
}

void Juego::moverArriba() {
	if (jugador->abajo != NULL) {
		Nodo* nuevo = new (Nodo);
		Nodo* aux = new (Nodo);
		nuevo = jugador->abajo;
		int posJugador = jugador->valor;
		int posNuevo= nuevo->valor;
		aux = jugador;
		jugador = nuevo;
		nuevo = aux;
		nuevo->valor = posNuevo;
		jugador->valor = posJugador;
	}
	matriz->listarMatrizValor();
}

void Juego::moverAbajo() {
	if (jugador->arriba != NULL) {
		Nodo* nuevo = new (Nodo);
		Nodo* aux = new (Nodo);
		nuevo = jugador->arriba;
		int posJugador = jugador->valor;
		int posNuevo = nuevo->valor;
		aux = jugador;
		jugador = nuevo;
		nuevo = aux;
		nuevo->valor = posNuevo;
		jugador->valor = posJugador;
	}
	matriz->listarMatrizValor();
}

void Juego::moverIzquierda() {
	if (jugador->siguiente != NULL) {
		Nodo* nuevo = new (Nodo);
		Nodo* aux = new (Nodo);
		nuevo = jugador->siguiente;
		int posJugador = jugador->valor;
		int posNuevo = nuevo->valor;
		aux = jugador;
		jugador = nuevo;
		nuevo = aux;
		nuevo->valor = posNuevo;
		jugador->valor = posJugador;
	}
	matriz->listarMatrizValor();
}

void Juego::moverDerecha() {
	if (jugador->anterior != NULL) {
		Nodo* nuevo = new (Nodo);
		Nodo* aux = new (Nodo);
		nuevo = jugador->anterior;
		int posJugador = jugador->valor;
		int posNuevo = nuevo->valor;
		aux = jugador;
		jugador = nuevo;
		nuevo = aux;
		nuevo->valor = posNuevo;
		jugador->valor = posJugador;
	}
	matriz->listarMatrizValor();
}

void Juego::iniciarMatriz() {
	matriz->ingresarDatos(datosMatriz);
}

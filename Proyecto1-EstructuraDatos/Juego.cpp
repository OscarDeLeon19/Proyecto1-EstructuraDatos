#include "Juego.h"
#include <iostream>
#include "Reporte.h"
#include "Tabla.h"
using namespace std;

Juego::Juego(Matriz *matriz, int* datosMatriz, int niveles, int columnas, int filas)
{
	this->matriz = matriz;
	this->datosMatriz = datosMatriz;
	this->niveles = niveles;
	this->columnas = columnas;
	this->filas = filas;
	tabla = new Tabla();
}


void Juego::iniciarJuego() {
	string nombre;
	cout << "Ingresa tu nombre: " << endl;
	cin >> nombre;
	cout << "Inicia el juego" << endl;
	iniciarMatriz();	
	agregarNodosMatriz();
	obtenerJugador();
	
	
	bool accion = true;
	int pasos = 0;
	unsigned tiempoInicial, tiempoFinal;
	
	tiempoInicial = clock();
	cout << endl;
	cout << "Acciones:" << endl;
	cout << "Mover arriba: W" << endl;
	cout << "Mover izquierda: A" << endl;
	cout << "Mover abajo: S" << endl;
	cout << "Mover derecha: D" << endl;
	cout << "Mover adelante: E" << endl;
	cout << "Mover atras: Q" << endl;
	cout << "Reiniciar: R" << endl;
	cout << "Terminar: T" << endl;
	cout << "Puntajes: P" << endl;
	cout << "Informacion: i" << endl;
	cout << endl;
	while (accion == true) {
		if (accion == true) {
			pasos++;			
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
			case 'q':
				moverAtras();
				break;
			case 'e':
				moverAdelante();
				break;
			case 't':
				accion = false;
				break;
			case 'r':
				iniciarMatriz();
				obtenerJugador();
				break;
			case 'p':
				tabla->verReportes();
				break;
			case 'i':
				cout << endl;
				cout << "Acciones:" << endl;
				cout << "Mover arriba: W" << endl;
				cout << "Mover izquierda: A" << endl;
				cout << "Mover abajo: S" << endl;
				cout << "Mover derecha: D" << endl;
				cout << "Mover adelante: E" << endl;
				cout << "Mover atras: Q" << endl;
				cout << "Reiniciar: R" << endl;
				cout << "Terminar: T" << endl;
				cout << "Puntajes: P" << endl;
				cout << "Informacion: i" << endl;
				cout << endl;
				break;
			default:
				cout << "Accion invalida" << endl;
			}
			bool victoria = comprobarVictoria();
			if (victoria == true) {
				cout << "Haz ganado" << endl;
				accion = false;				
			}
		}		
	}
		tiempoFinal = clock();
		double tiempoPartida = (double(tiempoFinal - tiempoInicial) / CLOCKS_PER_SEC);
		int punteo = obtenerPunteo();;
		cout << endl;
		cout << "Reporte" << endl;
		cout << "Pasos: " << pasos << endl;
		cout << "Tiempo: " << tiempoPartida << endl;
		cout << "Punteo: " << punteo << endl;	
		Reporte* reporte = new Reporte(nombre, punteo, tiempoPartida);
		tabla->agregarReporte(reporte);

		cout << endl;
		cout << "�Deseas iniciar otro juego?" << endl;
		cout << "1. Si" << endl;
		int des;
		cin >> des;
		if (des == 1) {
			iniciarJuego();
		}
		
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
	listarMatriz();
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
	listarMatriz();
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
	listarMatriz();
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
	listarMatriz();
}

void Juego::moverAdelante() {
	if (jugador->atras != NULL) {
		Nodo* nuevo = new (Nodo);
		Nodo* aux = new (Nodo);
		nuevo = jugador->atras;
		int posJugador = jugador->valor;
		int posNuevo = nuevo->valor;
		aux = jugador;
		jugador = nuevo;
		nuevo = aux;
		nuevo->valor = posNuevo;
		jugador->valor = posJugador;
	}
	listarMatriz();
}

void Juego::moverAtras() {
	if (jugador->adelante != NULL) {
		Nodo* nuevo = new (Nodo);
		Nodo* aux = new (Nodo);
		nuevo = jugador->adelante;
		int posJugador = jugador->valor;
		int posNuevo = nuevo->valor;
		aux = jugador;
		jugador = nuevo;
		nuevo = aux;
		nuevo->valor = posNuevo;
		jugador->valor = posJugador;
	}
	listarMatriz();
}

void Juego::iniciarMatriz() {
	int dato = 0;
	int posicion = 1;
	for (int i = 0; i < niveles; i++)
	{
		int nuevo = matriz[i].ingresarPosiciones(posicion);
		posicion = nuevo;
	}
	for (int i = 0; i < niveles; i++)
	{
		int nuevo = matriz[i].ingresarDatos(dato, datosMatriz);
		dato = nuevo;
	}
	listarMatriz();
}

void Juego::agregarNodosMatriz()
{
	for (int i = 0; i < (niveles - 1); i++)
	{
		Lista* lista1 = matriz[i].obtenerLista();
		Lista* lista2 = matriz[i+1].obtenerLista();
		for (int i = 0; i < columnas; i++)
		{
			for (int j = 0; j < filas; j++)
			{
				Nodo* nodo1 = new (Nodo);
				Nodo* nodo2 = new (Nodo);
				nodo1 = lista1[i].obtenerNodo(j);
				nodo2 = lista2[i].obtenerNodo(j);
				nodo1->adelante = nodo2;
				nodo2->atras = nodo1;
			}
		}
	}
}

void Juego::listarMatriz()
{
	for (int i = 0; i < niveles; i++)
	{
		cout << "Nivel " << (i + 1) << endl;
		matriz[i].listarMatrizValor();
	}
}

void Juego::obtenerJugador()
{
	jugador = new (Nodo);	
	for (int i = 0; i < niveles; i++)
	{
		jugador = matriz[i].devolverJugador();
		if (jugador->valor == 0) {
			break;
		}
	}
}

int Juego::obtenerPunteo()
{
	int total = 0;
	for (int i = 0; i < niveles; i++)
	{
		int punteo = matriz[i].contarPunteo();
		total = total + punteo;
	}
	return total;
}

bool Juego::comprobarVictoria()
{
	bool victoria = true;
	for (int i = 0; i < niveles; i++)
	{
		if (i == (niveles - 1)) {
			victoria = matriz[i].comprobarVictoria(true);
		}
		else {
			victoria = matriz[i].comprobarVictoria(true);
		}		
	}
	return victoria;
}




#include "Juego.h"
#include <iostream>
#include "Reporte.h"
#include "Tabla.h"
using namespace std;
/*
	Constructor de la clase juego
*/
Juego::Juego(Matriz *matriz, int* datosMatriz, int niveles, int columnas, int filas)
{
	this->matriz = matriz;
	this->datosMatriz = datosMatriz;
	this->niveles = niveles;
	this->columnas = columnas;
	this->filas = filas;
	tabla = new Tabla();
}
/*
	Destructor de la clase juego
*/
Juego::~Juego()
{
	for (int i = 0; i < niveles; i++)
	{
		matriz[i].~Matriz();
	}
	delete matriz;
	delete jugador;
	delete datosMatriz;
	delete tabla;
}

/*
	Inicia el juego. Despliega las opciones y genera el ciclo que se repite mientras el juego no termine.
*/
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
		int tiempoPartida = (int(tiempoFinal - tiempoInicial) / CLOCKS_PER_SEC);
		int punteo = obtenerPunteo();;
		cout << endl;
		cout << "Reporte" << endl;
		cout << "Pasos: " << pasos << endl;
		cout << "Tiempo: " << tiempoPartida << " seg" << endl;
		cout << "Punteo: " << punteo << endl;	
		Reporte* reporte = new Reporte(nombre, punteo, tiempoPartida);
		tabla->agregarReporte(reporte);

		cout << endl;
		cout << "¿Deseas iniciar otro juego?" << endl;
		cout << "1. Si" << endl;
		int des;
		cin >> des;
		if (des == 1) {
			iniciarJuego();
		}
		else {
			cout << "Fin del programa. Resultados" << endl;
			tabla->verReportes();
		}
		
}
/*
	Cambia de lugar la casilla del jugador con la casilla de abajo.
*/
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
/*
	Cambia de lugar la casilla del jugador con la casilla de arriba.
*/
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

/*
	Cambia de lugar la casilla del jugador con la casilla de la derecha.
*/
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
/*
	Cambia de lugar la casilla del jugador con la casilla de la izquierda.
*/
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
/*
	Cambia de lugar la casilla del jugador con la casilla de atras.
*/
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

/*
	Cambia de lugar la casilla del jugador con la casilla de adelante.
*/
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

/*
	Inicializa las matrices
*/
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

/*
	Agrega los nodos de adelante y atras entre matrices
*/
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

/*
	Imprime las matrices en pantalla
*/
void Juego::listarMatriz()
{
	for (int i = 0; i < niveles; i++)
	{
		cout << "Nivel " << (i + 1) << endl;
		matriz[i].listarMatrizValor();
	}
}

/*
	Iguala el nodo jugador al obtenido de las matrices
*/
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
/*
	Obtiene el punteo total obtenido de las matrices
*/
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

/*
	Comprueba si todos los nodos estan en la posicion correcta
*/
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




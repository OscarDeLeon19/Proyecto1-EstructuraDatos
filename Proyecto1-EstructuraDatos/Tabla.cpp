#include "Tabla.h"
#include <iostream>
/*
	Constructor de la clase tabla
*/
Tabla::Tabla()
{
}
/*
	Destructor de la clase tabla
*/
Tabla::~Tabla()
{
	primero->~Reporte();
	delete primero;
}
/*
	Agrega un reporte nuevo a la lista de reportes.
*/
void Tabla::agregarReporte(Reporte* reporte)
{
	if (primero == NULL) {
		primero = reporte;
		primero->setSiguiente(NULL);
	}
	else {
		Reporte* aux = primero;
		while (aux->getSiguiente() != NULL) {			
				aux = aux->getSiguiente();
		}
		aux->setSiguiente(reporte);
		reporte->setSiguiente(NULL);
	}
}
/*
	Muestra todos los reportes que estan en la lista
*/
void Tabla::verReportes()
{
	cout << endl;
	if (primero == NULL) {
		cout << "No hay reportes agregados" << endl;
	}
	else {
		cout << "Jugadores" << endl;
		cout << endl;
		Reporte* aux = primero;
		int i = 1;
		while (aux->getSiguiente() != NULL) {
			cout << "Jugador No." << i << endl;
			cout << "Nombre: " << aux->getNombre() << endl;
			cout << "Punteo: " << aux->getPunteo() << endl;
			cout << "Tiempo: " << aux->getTiempo() << " segundos" << endl;
			cout << endl;
			aux = aux->getSiguiente();
			i++;
		}
		cout << "Jugador No." << i << endl;
		cout << "Nombre: " << aux->getNombre() << endl;
		cout << "Punteo: " << aux->getPunteo() << endl;
		cout << "Tiempo: " << aux->getTiempo() << " segundos" << endl;
		cout << endl;

	}
}

#include "Tabla.h"
#include <iostream>

Tabla::Tabla()
{
}

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

void Tabla::verReportes()
{
	cout << endl;
	if (primero == NULL) {
		cout << "No hay reportes agregados" << endl;
	}
	else {
		Reporte* aux = primero;
		int i = 1;
		while (aux->getSiguiente() != NULL) {
			cout << "Reporte No." << i << endl;
			cout << "Nombre: " << aux->getNombre() << endl;
			cout << "Punteo: " << aux->getPunteo() << endl;
			cout << "Tiempo: " << aux->getTiempo() << endl;
			cout << endl;
			aux = aux->getSiguiente();
			i++;
		}
		cout << "Reporte No." << i << endl;
		cout << "Nombre: " << aux->getNombre() << endl;
		cout << "Punteo: " << aux->getPunteo() << endl;
		cout << "Tiempo: " << aux->getTiempo() << endl;
		cout << endl;
	}
}

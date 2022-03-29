#include "Reporte.h"

Reporte::Reporte(string nombre, int punteo, double tiempo)
{
	this->nombre = nombre;
	this->punteo = punteo;
	this->tiempo = tiempo;
}

void Reporte::setNombre(string nombre)
{
	this->nombre = nombre;
}

string Reporte::getNombre()
{
	return nombre;
}

void Reporte::setPunteo(int punteo)
{
	this->punteo = punteo;
}

int Reporte::getPunteo()
{
	return punteo;
}

void Reporte::setTiempo(double tiempo)
{
	this->tiempo = tiempo;
}

double Reporte::getTiempo()
{
	return tiempo;
}

void Reporte::setSiguiente(Reporte* siguiente)
{
	this->siguiente = siguiente;
}

Reporte* Reporte::getSiguiente()
{
	return siguiente;
}

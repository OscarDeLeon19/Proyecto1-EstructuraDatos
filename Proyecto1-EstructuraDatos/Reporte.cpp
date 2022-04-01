#include "Reporte.h"
#include <iostream>
/*
	Constructor de la clase reporte
*/
Reporte::Reporte(string nombre, int punteo, int tiempo)
{
	this->nombre = nombre;
	this->punteo = punteo;
	this->tiempo = tiempo;
}
/*
	Destructor de la clase reporte;
*/
Reporte::~Reporte()
{
	delete siguiente;
}

/*
	Asigna un nombre
*/
void Reporte::setNombre(string nombre)
{
	this->nombre = nombre;
}
/*
	Devuelve un nombre
*/
string Reporte::getNombre()
{
	return nombre;
}
/*
	Asigna un punteo
*/
void Reporte::setPunteo(int punteo)
{
	this->punteo = punteo;
}
/*
	Devuelve el punteo del reporte
*/
int Reporte::getPunteo()
{
	return punteo;
}
/*
	Asigna el tiempo que se tardo el reporte en mostrarse.
*/
void Reporte::setTiempo(double tiempo)
{
	this->tiempo = tiempo;
}
/*
	Devuelve el tiempo que duro la partida.
*/
double Reporte::getTiempo()
{
	return tiempo;
}
/*
	Asigna el reporte siguiente del reporte actual
*/
void Reporte::setSiguiente(Reporte* siguiente)
{
	this->siguiente = siguiente;
}
/*
	Devuelve el reporte siguiente del reporte actual
*/
Reporte* Reporte::getSiguiente()
{
	return siguiente;
}

#pragma once
#include <string>
using namespace std;

class Reporte
{
public:
	Reporte(string,int,double);
	void setNombre(string);
	string getNombre();
	void setPunteo(int);
	int getPunteo();
	void setTiempo(double);
	double getTiempo();
	void setSiguiente(Reporte*);
	Reporte* getSiguiente();
private:
	string nombre;
	int punteo;
	double tiempo;
	class Reporte* siguiente;
};
#pragma once
#include <string>
using namespace std;

class Reporte
{
public:
	Reporte(string,int,int);
	~Reporte();
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
	int tiempo;
	class Reporte* siguiente;
};
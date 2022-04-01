#pragma once
#include "Reporte.h"

class Tabla {
public:
	Tabla();
	~Tabla();
	void agregarReporte(Reporte* reporte);
	void verReportes();
private:
	Reporte* primero = NULL;
};
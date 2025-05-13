#pragma once
#include <string>


class Bar
{
	std::string nombre;
	int valoracion; //[1-10] 
	
	// entre 15 y 30 minutos
	int tiempo_consumicion;
	int tiempo_desplazamiento;

	// tiempo total de la ruta
	int tiempo_total;
	// valoracion/tiempo_total 
	double ratio_puntuacion_tiempo;

public:
	Bar(std::string nombre, int valoracion, int tiempo_consumicion, int tiempo_desplazamiento);


	// eficiencia 
	const std::string *getNombre() const { return &nombre; }
	const int *getValoracion() const { return &valoracion; }
	const int *getTiempo_consumicion() const { return &tiempo_consumicion; }
	const int *getTiempo_desplazamiento() const { return &tiempo_desplazamiento; }
	const int *getTiempo_total() const { return &tiempo_total; }
	const double *getRatio_puntuacion_tiempo() const { return &ratio_puntuacion_tiempo; }

	

};


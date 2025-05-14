#include "Bar.h"
#include <iostream>
using namespace std;
Bar::Bar()
{
    nombre = "";
    valoracion = 0;
    tiempo_consumicion = 0;
    tiempo_desplazamiento = 0;
    tiempo_total = 0;
    ratio_puntuacion_tiempo = 0.0;
}

Bar::Bar(std::string nombre, int valoración, int tiempo_consumicion, int tiempo_desplazamiento)
    : nombre(nombre), valoracion(valoración), tiempo_consumicion(tiempo_consumicion), tiempo_desplazamiento(tiempo_desplazamiento)
{

    // Asegurarse de que la valoración esté en el rango [1-10]1
    if (valoracion < 1)
    {
        valoracion = 1;
    }
    else if (valoracion > 10)
    {
        valoracion = 10;
    }

    // Calcular el tiempo total de la ruta
    tiempo_total = tiempo_consumicion + (2 * tiempo_desplazamiento); // ida y vuelta
    // Calcular la relación valoración/tiempo
    if (tiempo_total > 0)
    {
        ratio_puntuacion_tiempo = (double)(valoracion) / tiempo_total;
    }
    else
    {
        ratio_puntuacion_tiempo = 0.0; // Evitar división por cero
    }
}

ostream &operator<<(ostream &s, const Bar &b)
{
    // El Mirador (Valoración: 10, Tiempo total: 54 min)
    s << b.nombre << " (Valoración: " << b.valoracion << ", Tiempo total: " 
    << b.tiempo_total << " min, Ratio: " << b.ratio_puntuacion_tiempo << ")";
    return s;
}
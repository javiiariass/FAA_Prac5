#include "Serie.h"
#include <iostream>
using namespace std;

Serie::Serie()
{
    nombre = "";
    numero_episodios_pendientes = 0;
    duracion_episodio = 0;
    genero = "";
    ratio_puntuacion_duracion = 0.0;
    valoracion = 0; // Inicializar puntuación a 0
}


Serie::Serie(std::string nombre, int valoracion, int episodiosPendientes, int duracion_episodio, std::string genero)
{
    this->nombre = nombre;
    this->numero_episodios_pendientes = episodiosPendientes;
    this->duracion_episodio = duracion_episodio;
    this->genero = genero;
    this->valoracion = valoracion; // Inicializar puntuación a 0
    
    //controlar division por 0
    if (duracion_episodio > 0)
        this->ratio_puntuacion_duracion = (double)valoracion / duracion_episodio; // Evitar división por cero
    else
        this->ratio_puntuacion_duracion = 0.0; // Evitar división por cero

     
    
}

ostream &operator<<(ostream &s, const Serie &o)
{
    s<< o.nombre << " (Valoración: " << o.valoracion << ", Genero: "<< o.genero <<", Episodios: "
    << o.numero_episodios_pendientes << ", Duración episodio: " << o.duracion_episodio 
    << " min, Ratio: " << o.ratio_puntuacion_duracion << ")";
    
    return s;
}
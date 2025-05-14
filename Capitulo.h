#pragma once
#include <string>
class Capitulo
{
public:
    std::string Serie;
    int Numero_episodio;
    int duracion_episodio; // en minutos
    double ratio_puntuacion_duracion;
    int valoracion; // [1-10]
    Capitulo(std::string serie, int numero_episodio, int duracion_episodio, double ratio_puntuacion_duracion, int valoracion)
        : Serie(serie), Numero_episodio(numero_episodio), duracion_episodio(duracion_episodio), ratio_puntuacion_duracion(ratio_puntuacion_duracion), valoracion(valoracion) {}
    
    Capitulo() : Serie(""), Numero_episodio(0), duracion_episodio(0), ratio_puntuacion_duracion(0.0), valoracion(0) {}
};


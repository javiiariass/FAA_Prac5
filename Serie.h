#pragma once
#include <string>

class Serie
{
    std::string nombre;
    int numero_episodios_pendientes;
    int duracion_episodio; // en minutos
    std::string genero;
    double ratio_puntuacion_duracion;
    int valoracion; // [1-10]
public:
    Serie(std::string nombre, int valoracion, int episodiosPendientes, int duracion_episodio, std::string genero);
    Serie();
    
    const std::string *getNombre() const { return &nombre; }
    const int *getEpisodios_pendientes() const { return &numero_episodios_pendientes; }
    void setEpisodios_pendientes(int episodiosPendientes) { numero_episodios_pendientes = episodiosPendientes; }
    const int *getDuracion_episodio() const { return &duracion_episodio; }
    const std::string *getGenero() const { return &genero; }
    const double *getRatio_puntuacion_duracion() const { return &ratio_puntuacion_duracion; }
    const int *getValoracion() const { return &valoracion; }

    friend std::ostream &operator<<(std::ostream &s, const Serie &o); // Sobrecarga del operador de salida
};


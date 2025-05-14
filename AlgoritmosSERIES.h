#pragma once
#include "Serie.h"
#include <tuple>
#include <vector>
#include "Capitulo.h"
using namespace std;

class AlgoritmosSERIES
{
    // Estrategia 1: Mayor valoración (descendente)
    static bool compararPorValoracionS(const Serie &a, const Serie &b);

    // Estrategia 2: Menor Duracion (ascendente)
    static bool compararPorDuracionS(const Serie &a, const Serie &b);

    // Estrategia 3: Mejor relación valoración/duración (descendente)
    static bool compararPorRatioS(const Serie &a, const Serie &b);

    // Devuelve un vector de strings con el nombre de cada genero y el numero de capitulos de ese genero
    static vector <string> numeroCategorias(const vector<Serie> &capitulosAgrupados);
    
    // Reagrupa los capitulos en una lista de series
    static vector<Serie> agruparPorSerie(vector<Capitulo> capitulos, vector<Serie> series);
public:
    
    static tuple<vector<Serie>, int, int, vector<string>> maratonseries_capitulos(vector<Serie> &series, int tiempoDisponible, int criterio);
};


#pragma once
#include <vector>
#include "bar.h"

using namespace std;

class Algoritmos
{
	// Estrategia 1: Mayor valoración (descendente)
	static bool compararPorValoracion(const Bar &a, const Bar &b);

	// Estrategia 2: Menor tiempo total (ascendente)
	static bool compararPorTiempoTotal(const Bar &a, const Bar &b);

	// Estrategia 3: Mejor relación valoración/tiempo (descendente)
	static bool compararPorRatio(const Bar &a, const Bar &b);

public:
	static vector<Bar> RUTATAPAS(vector<Bar> bares, int tiempoDisponible, int criterio);
};

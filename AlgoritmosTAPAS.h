#pragma once
#include <vector>
#include <tuple>
#include "bar.h"
#include "AlgoritmosOrdenacion.h"



class AlgoritmosTAPAS
{
	
	// Estrategia 1: Mayor valoración (descendente)
	static bool compararPorValoracionT(const Bar &a, const Bar &b);
	
	// Estrategia 2: Menor tiempo total (ascendente)
	static bool compararPorTiempoTotalT(const Bar &a, const Bar &b);
	
	// Estrategia 3: Mejor relación valoración/tiempo (descendente)
	static bool compararPorRatioT(const Bar &a, const Bar &b);

	
public:
	
	
	static void PruebaOrdenar(vector<Bar> &Bares, int criterio);
	static tuple< vector<Bar>, int, int> RUTATAPAS(vector<Bar> bares, int tiempoDisponible, int criterio);
	
	
	
};

#include <algorithm>
#include <iostream>
#include "AlgoritmosTAPAS.h"
#include "Bar.h"
using namespace std;

// ********************************* Estrategias *********************************
// --- Comparadores para las diferentes estrategias ---

// Estrategia 1: Mayor valoración (descendente)
bool AlgoritmosTAPAS::compararPorValoracionT(const Bar &a, const Bar &b)
{

	return *a.getValoracion() > *b.getValoracion();
}

// Estrategia 2: Menor tiempo total (ascendente)
bool AlgoritmosTAPAS::compararPorTiempoTotalT(const Bar &a, const Bar &b)
{
	return *a.getTiempo_total() < *b.getTiempo_total();
}

// Estrategia 3: Mejor relación valoración/tiempo (descendente)
bool AlgoritmosTAPAS::compararPorRatioT(const Bar &a, const Bar &b)
{
	return *a.getRatio_puntuacion_tiempo() > *b.getRatio_puntuacion_tiempo();
}


/**
 * Función de prueba para ordenar un vector de objetos Bar.
 * Llama a la función de ordenación con el criterio correspondiente.
 * @param Bares Vector de objetos Bar a ordenar
 * @param criterio Criterio de ordenación (1: valoración, 2: tiempo total, 3: ratio)
 */
void AlgoritmosTAPAS::PruebaOrdenar(vector<Bar> &Bares, int criterio){
	// Llamar a la función de ordenación con el criterio correspondiente
	switch (criterio)
	{
	case 1:
		AlgoritmosOrdenacion::ordenar(Bares, compararPorValoracionT);
		break;
	case 2:
		AlgoritmosOrdenacion::ordenar(Bares, compararPorTiempoTotalT);
		break;
	case 3:
		AlgoritmosOrdenacion::ordenar(Bares, compararPorRatioT);
		break;
	default:
		cout << "Criterio no válido. Se usará el criterio por defecto (mayor valoración)." << endl;
		AlgoritmosOrdenacion::ordenar(Bares, compararPorValoracionT);
		break;
	}
}




// ********************************* Algoritmo exhaustivo *********************************

/**
 * Algoritmo voraz para seleccionar los bares a visitar.
 *
 * @param bares Vector de objetos Bar con la información de cada bar
 * @param tiempoDisponible Tiempo máximo disponible en minutos
 * @param criterio Criterio de selección (1: valoración, 2: tiempo total, 3: ratio)
 * @return Vector de bares seleccionados, tiempo total consumido y puntuación total
 */
tuple<vector<Bar>,int, int> AlgoritmosTAPAS::RUTATAPAS(vector<Bar> bares, int tiempoDisponible, int criterio)
{

	// Ordenar bares según cierto criterio
	switch (criterio)
	{
	case 1:
		// Estrategia 1: Mayor valoración (descendente)
		AlgoritmosOrdenacion::ordenar(bares, compararPorValoracionT);
		break;
	case 2:
		// Estrategia 2: Menor tiempo total (ascendente)
		AlgoritmosOrdenacion::ordenar(bares, compararPorTiempoTotalT);
		break;
	case 3:
		// Estrategia 3: Mejor relación valoración/tiempo (descendente)
		AlgoritmosOrdenacion::ordenar(bares, compararPorRatioT);
		break;
	default:
		cout << "Criterio no válido. Se usará el criterio por defecto (mayor valoración)." << endl;
		AlgoritmosOrdenacion::ordenar(bares, compararPorValoracionT);
		break;
	}

	int tiempoRestante = tiempoDisponible;
	int puntuacionTotal = 0;
	vector<Bar> baresSeleccionados;

	for ( Bar bar : bares)
	{
		// Tiempo total = ida + vuelta + consumición
		int tiempoNecesario = *bar.getTiempo_total();	

		if (tiempoRestante >= tiempoNecesario)
		{
			puntuacionTotal += *bar.getValoracion();
			baresSeleccionados.push_back(bar);
			tiempoRestante -= tiempoNecesario;
		}
	}

	return {baresSeleccionados, tiempoDisponible - tiempoRestante, puntuacionTotal}; 
}
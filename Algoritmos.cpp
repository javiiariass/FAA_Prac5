#include <algorithm>
#include <iostream>
#include "Algoritmos.h"
#include "Bar.h"
using namespace std;

// ********************************* Estrategias *********************************
// --- Comparadores para las diferentes estrategias ---

// Estrategia 1: Mayor valoración (descendente)
static bool compararPorValoracion(const Bar &a, const Bar &b)
{

	return *a.getValoracion() > *b.getValoracion();
}

// Estrategia 2: Menor tiempo total (ascendente)
static bool compararPorTiempoTotal(const Bar &a, const Bar &b)
{
	return *a.getTiempo_total() < *b.getTiempo_total();
}

// Estrategia 3: Mejor relación valoración/tiempo (descendente)
static bool compararPorRatio(const Bar &a, const Bar &b)
{
	return *a.getRatio_puntuacion_tiempo() > *b.getRatio_puntuacion_tiempo();
}

// ********************************* Algoritmos ordenacion *********************************

static void ordenar(vector<Bar> Bares, bool (*criterio)(const Bar &, const Bar &))
{
	// Podemos reemplazar el algoritmo de ordenación sin modificar el resto del código
	sort(Bares.begin(), Bares.end(), criterio);
	// Mergesort(inicio, fin, criterio);
}

static void Mergesort(vector<Bar> Bares, bool(*criterio)(const Bar &, const Bar &))
{
	Mergesort(Bares.begin(), Bares.end(), criterio);
}

// implementar el algoritmo de ordenación mergesort
static void merge(vector<Bar>::iterator inicio, vector<Bar>::iterator medio, vector<Bar>::iterator fin, bool (*criterio)(const Bar &, const Bar &))
{
	vector<Bar> aux(fin - inicio);
	auto it = aux.begin();
	auto it1 = inicio;
	auto it2 = medio;

	while (it1 < medio && it2 < fin)
	{
		if (criterio(*it1, *it2))
		{
			*it++ = *it1++;
		}
		else
		{
			*it++ = *it2++;
		}
	}

	while (it1 < medio)
	{
		*it++ = *it1++;
	}

	while (it2 < fin)
	{
		*it++ = *it2++;
	}

	copy(aux.begin(), aux.end(), inicio);
}




static void Mergesort(vector<Bar>::iterator inicio, vector<Bar>::iterator fin, bool (*criterio)(const Bar &, const Bar &))
{
	if (fin - inicio > 1)
	{
		auto medio = inicio + (fin - inicio) / 2;
		Mergesort(inicio, medio, criterio);
		Mergesort(medio, fin, criterio);
		merge(inicio, medio, fin, criterio);
	}
}

// ********************************* Algoritmo exhaustivo *********************************

/**
 * Algoritmo voraz para seleccionar los bares a visitar.
 *
 * @param bares Vector de objetos Bar con la información de cada bar
 * @param tiempoDisponible Tiempo máximo disponible en minutos
 * @return Vector de bares seleccionados
 */
vector<Bar> Algoritmos::RUTATAPAS(vector<Bar> bares, int tiempoDisponible, int criterio)
{

	// Ordenar bares según cierto criterio
	switch (criterio)
	{
	case 1:
		// Estrategia 1: Mayor valoración (descendente)
		ordenar(bares, compararPorValoracion);
		break;
	case 2:
		// Estrategia 2: Menor tiempo total (ascendente)
		ordenar(bares, compararPorTiempoTotal);
		break;
	case 3:
		// Estrategia 3: Mejor relación valoración/tiempo (descendente)
		ordenar(bares, compararPorRatio);
		break;
	default:
		cout << "Criterio no válido. Se usará el criterio por defecto (mayor valoración)." << endl;
		ordenar(bares, compararPorValoracion);
		break;
	}

	int tiempoRestante = tiempoDisponible;
	vector<Bar> baresSeleccionados;

	for (const Bar &bar : bares)
	{
		// Tiempo total = ida + vuelta + consumición
		int tiempoNecesario = (2 * bar.getTiempo_desplazamiento) + bar.getTiempo_consumicion;

		if (tiempoRestante >= tiempoNecesario)
		{
			baresSeleccionados.push_back(bar);
			tiempoRestante -= tiempoNecesario;
		}
	}

	return baresSeleccionados;
}
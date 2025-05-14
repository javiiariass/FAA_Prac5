#include "AlgoritmosOrdenacion.h"
#include <algorithm>


/**
 * Función de ordenación.
 * Ordena un vector de objetos Bar utilizando un algoritmo de ordenacion.
 */
void AlgoritmosOrdenacion::ordenar(vector<Bar> &Bares, bool (*criterio)(const Bar &, const Bar &))
{
	// Podemos reemplazar el algoritmo de ordenación sin modificar el resto del código

	// Trabaja internamente con quicksort
	//sort(Bares.begin(), Bares.end(), criterio);


	 Mergesort(Bares, criterio);
}

/**
 * Algoritmo de ordenación Mergesort.
 * Implementa el algoritmo de ordenación Mergesort para ordenar un vector de objetos Bar.
 * Llamar a esta función con el vector completo
 */
 void AlgoritmosOrdenacion::Mergesort(vector<Bar> &Bares, bool(*criterio)(const Bar &, const Bar &))
{
	// Llama a la función Mergesort con los límites del vector
	// Bares.begin() es el primer elemento del vector
	// Bares.end() es el último elemento del vector
	Mergesort(Bares.begin(), Bares.end(), criterio);
}

/**
 * Algoritmo de ordenación Mergesort.
 * Implementa el algoritmo de ordenación Mergesort para ordenar un vector de objetos Bar.
 * @param inicio Iterador al inicio del vector. Funcionan como punteros
 * @param fin Iterador al final del vector. Funcionan como punteros
 * @param criterio Criterio de ordenación (función que compara dos objetos Bar)
 */
void AlgoritmosOrdenacion::Mergesort(vector<Bar>::iterator inicio, vector<Bar>::iterator fin, bool (*criterio)(const Bar &, const Bar &))
{
	if (fin - inicio > 1)
	{
		// El compilador deduce el tipo de la variable
		auto medio = inicio + (fin - inicio) / 2;

		Mergesort(inicio, medio, criterio);
		Mergesort(medio, fin, criterio);
		merge(inicio, medio, fin, criterio);
	}
}


/**
 * Función de mezcla para el algoritmo Mergesort.
 * Combina dos subvectores ordenados en un solo vector ordenado.
 * @param inicio Iterador al inicio del vector
 * @param medio Iterador al medio del vector
 * @param fin Iterador al final del vector
 * @param criterio Criterio de ordenación (función que compara dos objetos Bar)
 * @note Esta función es parte del algoritmo Mergesort y no debe ser llamada directamente.
 */
 void AlgoritmosOrdenacion::merge(vector<Bar>::iterator inicio, vector<Bar>::iterator medio, vector<Bar>::iterator fin, bool (*criterio)(const Bar &, const Bar &))
{
	vector<Bar> aux(fin - inicio); // Crear un vector auxiliar del tamaño adecuado
	

	//vector<Bar>::iterator no es más que un iterador, báicamente un puntero
	
	// el tipo auto hace que el compilador deduzca el tipo de la variable
	// Es lo mismo que poner vector<Bar>::iterator
	auto it = aux.begin(); // Primer elemento del vector auxiliar 
	auto it1 = inicio;
	auto it2 = medio;

	// Al hacer ++ sobre un iterador, se avanza al siguiente elemento

	// hasta que el elemento izdo llegue al medio o el elemento dcho llegue al final
	while (it1 < medio && it2 < fin)
	{
		
		if (criterio(*it1, *it2))
		{
			// Si el elemento de la izquierda es menor que el de la derecha
			// se copia el elemento de la izquierda al vector auxiliar y se avanza el iterador
			// al siguiente elemento
			*it++ = *it1++;
		}
		else
		{
			// Si el elemento de la derecha es menor o igual que el de la izquierda
			// se copia el elemento de la derecha al vector auxiliar y se avanza el iterador
			// al siguiente elemento
			*it++ = *it2++;
		}
	}

	// Copiar el resto de los elementos que quedan en la parte izquierda
	// y en la parte derecha al vector auxiliar
	while (it1 < medio)
	{
		*it++ = *it1++;
	}

	while (it2 < fin)
	{
		*it++ = *it2++;
	}

	// Copiamos el resultado del vector auxiliar al vector original
	// en las posiciones correspondientes desde la posición incicada por inicio
	copy(aux.begin(), aux.end(), inicio); 
}


// ------------------------- Algoritmos para Series -----------------------

/**
 * Función de ordenación.
 * Ordena un vector de objetos Serie utilizando un algoritmo de ordenacion.
 */
void AlgoritmosOrdenacion::ordenar(vector<Serie> &series, bool (*criterio)(const Serie &, const Serie &))
{
	// Podemos reemplazar el algoritmo de ordenación sin modificar el resto del código

	// Trabaja internamente con quicksort
	//sort(series.begin(), series.end(), criterio);


	Mergesort(series, criterio);
}

/**
 * Algoritmo de ordenación Mergesort.
 * Implementa el algoritmo de ordenación Mergesort para ordenar un vector de objetos Serie.
 * Llamar a esta función con el vector completo
 */
void AlgoritmosOrdenacion::Mergesort(vector<Serie> &series, bool(*criterio)(const Serie &, const Serie &))
{
	// Llama a la función Mergesort con los límites del vector
	// series.begin() es el primer elemento del vector
	// series.end() es el último elemento del vector
	Mergesort(series.begin(), series.end(), criterio);
}

/**
 * Algoritmo de ordenación Mergesort.
 * Implementa el algoritmo de ordenación Mergesort para ordenar un vector de objetos Serie.
 * @param inicio Iterador al inicio del vector. Funcionan como punteros
 * @param fin Iterador al final del vector. Funcionan como punteros
 * @param criterio Criterio de ordenación (función que compara dos objetos Serie)
 */
void AlgoritmosOrdenacion::Mergesort(vector<Serie>::iterator inicio, vector<Serie>::iterator fin, bool (*criterio)(const Serie &, const Serie &))
{
	if (fin - inicio > 1)
	{
		// El compilador deduce el tipo de la variable
		auto medio = inicio + (fin - inicio) / 2;

		Mergesort(inicio, medio, criterio);
		Mergesort(medio, fin, criterio);
		merge(inicio, medio, fin, criterio);
	}
}


/**
 * Función de mezcla para el algoritmo Mergesort.
 * Combina dos subvectores ordenados en un solo vector ordenado.
 * @param inicio Iterador al inicio del vector
 * @param medio Iterador al medio del vector
 * @param fin Iterador al final del vector
 * @param criterio Criterio de ordenación (función que compara dos objetos Serie)
 * @note Esta función es parte del algoritmo Mergesort y no debe ser llamada directamente.
 */
 void AlgoritmosOrdenacion::merge(vector<Serie>::iterator inicio, vector<Serie>::iterator medio, vector<Serie>::iterator fin, bool (*criterio)(const Serie &, const Serie &))
{
	vector<Serie> aux(fin - inicio); // Crear un vector auxiliar del tamaño adecuado
	

	//vector<Serie>::iterator no es más que un iterador, básicamente un puntero
	
	// el tipo auto hace que el compilador deduzca el tipo de la variable
	// Es lo mismo que poner vector<Serie>::iterator
	auto it = aux.begin(); // Primer elemento del vector auxiliar 
	auto it1 = inicio;
	auto it2 = medio;

	// Al hacer ++ sobre un iterador, se avanza al siguiente elemento

	// hasta que el elemento izdo llegue al medio o el elemento dcho llegue al final
	while (it1 < medio && it2 < fin)
	{
		
		if (criterio(*it1, *it2))
		{
			// Si el elemento de la izquierda es menor que el de la derecha
			// se copia el elemento de la izquierda al vector auxiliar y se avanza el iterador
			// al siguiente elemento
			*it++ = *it1++;
		}
		else
		{
			// Si el elemento de la derecha es menor o igual que el de la izquierda
			// se copia el elemento de la derecha al vector auxiliar y se avanza el iterador
			// al siguiente elemento
			*it++ = *it2++;
		}
	}

	// Copiar el resto de los elementos que quedan en la parte izquierda
	// y en la parte derecha al vector auxiliar
	while (it1 < medio)
	{
		*it++ = *it1++;
	}

	while (it2 < fin)
	{
		*it++ = *it2++;
	}

	// Copiamos el resultado del vector auxiliar al vector original
	// en las posiciones correspondientes desde la posición incicada por inicio
	copy(aux.begin(), aux.end(), inicio); 
}

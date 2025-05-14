#include "AlgoritmosSERIES.h"
#include "AlgoritmosOrdenacion.h"
#include "Capitulo.h"
#include <string>

#include <iostream>
#include <map>
using namespace std;

// ********************************* Estrategias *********************************
// --- Comparadores para las diferentes estrategias ---

// Estrategia 1: Mayor valoración (descendente)
bool AlgoritmosSERIES::compararPorValoracionS(const Serie &a, const Serie &b)
{
    return *a.getValoracion() > *b.getValoracion();
}

// Estrategia 2: Menor duracion  (ascendente)
bool AlgoritmosSERIES::compararPorDuracionS(const Serie &a, const Serie &b)
{
    return *a.getDuracion_episodio() < *b.getDuracion_episodio();
}

// Estrategia 3: Mejor relación valoración/duración (descendente)
bool AlgoritmosSERIES::compararPorRatioS(const Serie &a, const Serie &b)
{
    return *a.getRatio_puntuacion_duracion() > *b.getRatio_puntuacion_duracion();
}

// ********************************** Algoritmo exhaustivo *********************************
/**
 * Función de prueba para ordenar un vector de objetos Serie.
 * Llama a la función de ordenación con el criterio correspondiente.
 * @param series Vector de objetos Serie a ordenar
 * @param criterio Criterio de ordenación (1: valoración, 2: duración, 3: ratio)
 * @return Tupla con el vector de objetos Serie ordenados, el tiempo consumido, 
 * la puntuación total y un vector de String con cada genero y el numero de capitulos de ese genero
 */
tuple<vector<Serie>, int, int, vector<string>> AlgoritmosSERIES::maratonseries_capitulos(vector<Serie> &series, int tiempoDisponible, int criterio)
{

    
    // cout << "Vector de series antes de ordenar:" << endl;
    // for (const auto &serie : series)
    // {
    //     cout << serie << endl;
    // }
    
    // Todos los episodios siguen el mismo criterio de ordenación
    // Se separa despues de ordenar en capitulos
    // Llamar a la función de ordenación con el criterio correspondiente
    switch (criterio)
    {
    case 1:
        AlgoritmosOrdenacion::ordenar(series, compararPorValoracionS);
        break;
    case 2:
        AlgoritmosOrdenacion::ordenar(series, compararPorDuracionS);
        break;
    case 3:
        AlgoritmosOrdenacion::ordenar(series, compararPorRatioS);
        break;
    default:
        cout << "Criterio no válido. Se usará el criterio por defecto (mayor valoración)." << endl;
        AlgoritmosOrdenacion::ordenar(series, compararPorValoracionS);
        break;
    }
    
    // cout << "Vector de series después de ordenar:" << endl;
    // for (const auto &serie : series)
    // {
    //     cout << serie << endl;
    // }


    // Crear lista de todos los capítulos individuales
    vector<Capitulo> capitulos;
    for (const auto &serie : series)
    {
        for (int e = 1; e <= *serie.getEpisodios_pendientes(); ++e)
        {

            capitulos.emplace_back(
                *serie.getNombre(), e, *serie.getDuracion_episodio(), *serie.getRatio_puntuacion_duracion(), *serie.getValoracion());
        }
    }


    int tiempoRestante = tiempoDisponible;
    int puntuacionTotal = 0;
    vector<Capitulo> capitulosSeleccionados;

    for (const auto &capitulo : capitulos)
    {
        if (tiempoRestante >= capitulo.duracion_episodio)
        {
            capitulosSeleccionados.push_back(capitulo);
            tiempoRestante -= capitulo.duracion_episodio;
            puntuacionTotal += capitulo.valoracion;
        }
    }

    vector<Serie> capitulosAgrupados = agruparPorSerie(capitulosSeleccionados, series);

    vector <string> capitulosGenero = numeroCategorias(capitulosAgrupados);
    
    return {capitulosAgrupados, tiempoDisponible - tiempoRestante, puntuacionTotal, capitulosGenero};
}

// ***************************** funciones auxiliares ****************************

// Reagrupa los capitulos en una lista de series
vector<Serie> AlgoritmosSERIES::agruparPorSerie(vector<Capitulo> capitulos, vector<Serie> series)
{
    vector<Serie> seriesResultado;

    for (unsigned int i = 0; i < series.size(); i++)
    {
        int contador = 0;
        string cap = *series.at(i).getNombre();
        for (unsigned int j = 0; j < capitulos.size(); j++)
        {
            // Si el nombre de la serie coincide con el nombre del capitulo
            if (cap == capitulos.at(j).Serie)
            {
                // incrementamos el contador de episodios
                // eliminamos el capitulo de la lista para iterar menos veces
                capitulos.erase(capitulos.begin() + j);
                j--;
                contador++;
            }
        }
        // Si el contador es mayor que 0, significa que hemos encontrado capitulos de esa serie
        if (contador > 0)
        {
            // Creamos una nueva serie con el nombre y el contador de episodios
            Serie nuevaSerie(*series.at(i).getNombre(), *series.at(i).getValoracion(), contador, *series.at(i).getDuracion_episodio(), *series.at(i).getGenero());
            seriesResultado.push_back(nuevaSerie);
        }
    }

    return seriesResultado;
}

/**
 * Devuelve un vector de strings con el nombre de cada genero y el numero de capitulos de ese genero
 * @param capitulosAgrupados Vector de objetos Serie con los capítulos agrupados
 */
vector <string> AlgoritmosSERIES::numeroCategorias(const vector<Serie> &capitulosAgrupados){
    map<string, int> contadorGeneros;
    for (const auto &serie : capitulosAgrupados) {
        string genero = *serie.getGenero();
        contadorGeneros[genero] += *serie.getEpisodios_pendientes();
    }

    vector<string> resultado;
    for (const auto &par : contadorGeneros) {
        resultado.push_back(par.first + ": " + to_string(par.second));
    }
    
    return resultado;
}


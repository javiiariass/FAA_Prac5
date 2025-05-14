// main.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
using namespace std;
#include "Bar.h"
#include "AlgoritmosTAPAS.h"
#include "AlgoritmosSERIES.h"
#include "Serie.h"
int menuTapas();
int menuPrincipal();
int menuMaraton();
int seleccionCorrecta(int inicio, int final);
bool problemaTapas();
void mostrarBares(const vector<Bar> &bares);
void mostrarSeries(const vector<Serie> &series);
int pedirTiempoDisponible();
bool problemaMaraton();

int main()
{

    bool salir = false;
    do
    {
        system("cls");
        switch (menuPrincipal())
        {
        case 1:
        {
            salir = problemaTapas();
            break;
        }
        case 2:
        {
            salir = problemaMaraton();
            break;
        }
        case 0:
            salir = true;
            break;

        default:
            cout << "Opción no válida." << endl;
            break;
        }
        system("pause");
    } while (!salir);

    return 0;
}

// ********************************* Problema Tapas *********************************

/**
 * Función para mostrar el menú de tapas.
 * Muestra las opciones de ordenación y ejecución del algoritmo voraz.
 */
int menuTapas()
{
    cout << "Problema de la ruta de tapas" << endl;
    cout << "---------------------------------------" << endl;
    cout << "Elija una opción:" << endl;
    cout << "1. Estrategia 1: por valoración" << endl;
    cout << "2. Estrategia 2: tiempo total" << endl;
    cout << "3. Estrategia 3: por ratio" << endl;
    cout << "4. Comparar las 3 estrategias" << endl;
    cout << "5. Probar ordenar por valoración" << endl;
    cout << "6. Probar ordenar por tiempo total" << endl;
    cout << "7. Probar ordenar por ratio" << endl;
    cout << "8. Volver al menú principal" << endl;

    cout << "0. Salir" << endl;

    return seleccionCorrecta(0, 8);
}

/**
 * Función para ejecutar el problema de la ruta de tapas.
 * Muestra el menú de tapas y ejecuta las opciones seleccionadas.
 * @return indica si sale del programa o vuelve al menú principal
 * @return 1 si sale del programa, 0 si vuelve al menú principal
 */
bool problemaTapas()
{

    int opcion;
    vector<Bar> bares_ruta_tapa = {
        // Nombre, Valoracion, Tiempo Consumo (min), Tiempo Desplazamiento (min)
        Bar("El Rincon del choco", 9, 30, 10),
        Bar("Bar la esquina", 6, 15, 5),
        Bar("Tapas y cañas", 4, 15, 5),
        Bar("Casa Manolo", 8, 25, 5),
        Bar("La Bodeguita", 7, 20, 7),
        Bar("El Mirador", 10, 30, 12),
        Bar("Mesón del Puerto", 5, 15, 5),
        Bar("La Taberna Asturiana", 8, 20, 10),
        Bar("El Rincón del Abuelo", 3, 25, 12),
        Bar("Tapería Central", 6, 20, 7)};

    bool salir = false;
    do
    {
        system("cls");
        switch (menuTapas())
        {
        case 1:
        {
            system("cls");
            cout << "Probando RUTATAPAS por valoración..." << endl;
            int tiempo = pedirTiempoDisponible();

            cout << "\n\n-----------------\n";
            cout << "Bares originales:" << endl;
            mostrarBares(bares_ruta_tapa);

            cout << "\n\n-----------------\n";
            cout << "Con " << tiempo << " minutos disponibles:" << endl;
            auto resultado = AlgoritmosTAPAS::RUTATAPAS(bares_ruta_tapa, tiempo, 1);
            cout << "Tiempo total consumido: " << get<1>(resultado) << " minutos" << endl;
            cout << "Puntuación total: " << get<2>(resultado) << endl;
            mostrarBares(get<0>(resultado));
            break;
        }
        case 2:
        {
            system("cls");
            cout << "Probando RUTATAPAS por tiempo total..." << endl;
            int tiempo = pedirTiempoDisponible();

            cout << "\n\n-----------------\n";
            cout << "Bares originales:" << endl;
            mostrarBares(bares_ruta_tapa);

            cout << "\n\n-----------------\n";
            cout << "Con " << tiempo << " minutos disponibles:" << endl;
            auto resultado = AlgoritmosTAPAS::RUTATAPAS(bares_ruta_tapa, tiempo, 2);
            cout << "Tiempo total consumido: " << get<1>(resultado) << " minutos" << endl;
            cout << "Puntuación total: " << get<2>(resultado) << endl;
            mostrarBares(get<0>(resultado));
            break;
        }
        case 3:
        {
            system("cls");
            cout << "Probando RUTATAPAS por valoración..." << endl;
            int tiempo = pedirTiempoDisponible();

            cout << "\n\n-----------------\n";
            cout << "Bares originales:" << endl;
            mostrarBares(bares_ruta_tapa);

            cout << "\n\n-----------------\n";
            cout << "Con " << tiempo << " minutos disponibles:" << endl;
            auto resultado = AlgoritmosTAPAS::RUTATAPAS(bares_ruta_tapa, tiempo, 3);
            cout << "Tiempo total consumido: " << get<1>(resultado) << " minutos" << endl;
            cout << "Puntuación total: " << get<2>(resultado) << endl;
            mostrarBares(get<0>(resultado));
            break;
        }
        case 4:
        {
            system("cls");
            cout << "Probando RUTATAPAS con todas las estrategias..." << endl;
            int tiempo = pedirTiempoDisponible();

            cout << "\n-----------------\n";
            cout << "Bares originales:" << endl;
            mostrarBares(bares_ruta_tapa);

            cout << "\n-----------------\n";
            cout << "Con " << tiempo << " minutos disponibles:" << endl;
            cout << "\n-----------------\n"
                 << "Por Valoración:\n";
            auto resultado = AlgoritmosTAPAS::RUTATAPAS(bares_ruta_tapa, tiempo, 1);
            cout << "Tiempo total consumido: " << get<1>(resultado) << " minutos" << endl;
            cout << "Puntuación total: " << get<2>(resultado) << "\n\n";
            cout << "Bares seleccionados:\n";
            mostrarBares(get<0>(resultado));

            cout << "\n-----------------\n"
                 << "Por Tiempo total:\n";
            resultado = AlgoritmosTAPAS::RUTATAPAS(bares_ruta_tapa, tiempo, 2);
            cout << "Tiempo total consumido: " << get<1>(resultado) << " minutos" << endl;
            cout << "Puntuación total: " << get<2>(resultado) << "\n\n";
            cout << "Bares seleccionados:\n";
            mostrarBares(get<0>(resultado));

            cout << "\n-----------------\n"
                 << "Por Ratio:\n";
            resultado = AlgoritmosTAPAS::RUTATAPAS(bares_ruta_tapa, tiempo, 3);
            cout << "Tiempo total consumido: " << get<1>(resultado) << " minutos" << endl;
            cout << "Puntuación total: " << get<2>(resultado) << "\n\n";
            cout << "Bares seleccionados:\n";
            mostrarBares(get<0>(resultado));

            break;
        }
        case 5:
        {
            cout << "\n\nProbando ordenar por valoración..." << endl;
            cout << "\n-----------------\n";
            cout << "Orden Bares originales:" << endl;
            mostrarBares(bares_ruta_tapa);

            // Cramos copia del vector original
            vector<Bar> bares_ruta_tapa_COPIA = bares_ruta_tapa;
            AlgoritmosTAPAS::PruebaOrdenar(bares_ruta_tapa_COPIA, 1);

            cout << "\nBares ordenados por valoración (descendente):" << endl;
            mostrarBares(bares_ruta_tapa_COPIA);

            break;
        }
        case 6:
        {
            cout << "\n\nProbando ordenar por tiempo total..." << endl;
            cout << "\n-----------------\n";
            cout << "Orden Bares originales:" << endl;
            mostrarBares(bares_ruta_tapa);

            // Cramos copia del vector original
            vector<Bar> bares_ruta_tapa_COPIA = bares_ruta_tapa;
            AlgoritmosTAPAS::PruebaOrdenar(bares_ruta_tapa_COPIA, 2);

            cout << "\nBares ordenados por tiempo total (ascendente):" << endl;
            mostrarBares(bares_ruta_tapa_COPIA);

            break;
        }
        case 7:
        {
            cout << "\n\nProbando ordenar por Ratio..." << endl;
            cout << "\n-----------------\n";
            cout << "Orden Bares originales:" << endl;
            mostrarBares(bares_ruta_tapa);

            // Cramos copia del vector original
            vector<Bar> bares_ruta_tapa_COPIA = bares_ruta_tapa;
            AlgoritmosTAPAS::PruebaOrdenar(bares_ruta_tapa_COPIA, 3);

            cout << "\nBares ordenados por ratio (descendente):" << endl;
            mostrarBares(bares_ruta_tapa_COPIA);

            break;
        }
        case 8:
        {
            cout << "Volviendo al menú principal..." << endl;
            salir = true;
            opcion = 0;
            break;
        }
        case 0:
            salir = true;
            cout << "Saliendo del programa..." << endl;
            salir = true;
            opcion = 1;
            break;
        }
        system("pause");
    } while (!salir);

    return opcion;
}

void mostrarBares(const vector<Bar> &bares)
{
    int i = 1;
    for (const auto &bar : bares)
    {
        cout << i++ << ". " << bar << endl;
    }
}

int pedirTiempoDisponible()
{
    cout << "Introduzca el tiempo disponible (en minutos): ";
    return seleccionCorrecta(0, INT_MAX); // Cualquier valor positivo es válido
}


// ********************************* Problema maraton *********************************

int menuMaraton(){
    cout << "Problema Maratón de Series" << endl;
    cout << "---------------------------------------" << endl;
    cout << "Elija una opción:" << endl;
    cout << "1. Estrategia 1: por valoración" << endl;
    cout << "2. Estrategia 2: por duración" << endl;
    cout << "3. Estrategia 3: por ratio" << endl;
    cout << "4. Comparar las 3 estrategias" << endl;
    cout << "5. Volver al menú principal" << endl;
    cout << "0. Salir" << endl;

    return seleccionCorrecta(0, 4);
}

bool problemaMaraton()
{
    int opcion = false;
    vector<Serie> series_maraton = {
        // Nombre, Valoracion, Tiempo Consumo (min), Tiempo Desplazamiento (min)
        Serie("Stranger Things", 3, 50, 8, "ciencia-ficcion"),
        Serie("Breaking Bad", 2, 45, 9, "drama"),
        Serie("The Office", 5, 22, 7, "comedia"),
        Serie("Game of Thrones", 2, 60, 9, "fantasía"),    
        Serie("Brooklyn Nine-Nine", 4, 22, 6, "comedia"),
        Serie("The Mandalorian", 2, 40, 8, "ciencia-ficcion"),
        Serie("Peaky Blinders", 3, 55, 7, "drama"),
        Serie("The Witcher", 2, 60, 7, "fantasía"),
        Serie("Money Heist", 3, 45, 8, "acción"),
        Serie("The Boys", 2, 55, 8, "acción")
    };
    

    bool salir = false;
    do
    {
        system("cls");
        switch (menuMaraton())
        {
            case 1:
            {
                vector<Serie> series_maraton_COPIA = series_maraton;
                system("cls");
                cout << "Probando Maratón de Serries por valoración..." << endl;
                int tiempo = pedirTiempoDisponible();

                cout << "\n\n-----------------\n";
                cout << "(vector) Series originales:" << endl;
                mostrarSeries(series_maraton);

                cout << "\n\n-----------------\n";
                cout << "Con " << tiempo << " minutos disponibles:" << endl;

                auto resultado = AlgoritmosSERIES::maratonseries_capitulos(series_maraton_COPIA, tiempo, 1);
                
                cout << "Tiempo total consumido: " << get<1>(resultado) << " minutos" << endl;
                cout << "Puntuación total: " << get<2>(resultado) << endl;
                cout << "Capítulos seleccionados: " << endl;
                
                mostrarSeries(get<0>(resultado));
                
                cout << "\nCategorías\n****\n";
                for (const string &categoria : get<3>(resultado)) {
                    cout << categoria << endl;
                }
                break;
                
            }
            case 2:
            {
                vector<Serie> series_maraton_COPIA = series_maraton;
                system("cls");
                cout << "Probando Maratón de Serries por duracion..." << endl;
                int tiempo = pedirTiempoDisponible();

                cout << "\n\n-----------------\n";
                cout << "(vector) Series originales:" << endl;
                mostrarSeries(series_maraton);

                cout << "\n\n-----------------\n";
                cout << "Con " << tiempo << " minutos disponibles:" << endl;

                auto resultado = AlgoritmosSERIES::maratonseries_capitulos(series_maraton_COPIA, tiempo, 2);
                
                cout << "Tiempo total consumido: " << get<1>(resultado) << " minutos" << endl;
                cout << "Puntuación total: " << get<2>(resultado) << endl;
                cout << "Capítulos seleccionados: " << endl;
                
                mostrarSeries(get<0>(resultado));
                
                cout << "\nCategorías\n****\n";
                for (const string &categoria : get<3>(resultado)) {
                    cout << categoria << endl;
                }
                break;
            }
            case 3:
            {
                vector<Serie> series_maraton_COPIA = series_maraton;
                system("cls");
                cout << "Probando Maratón de Serries por Ratio(valoracion/duracion)..." << endl;
                int tiempo = pedirTiempoDisponible();

                cout << "\n\n-----------------\n";
                cout << "(vector) Series originales:" << endl;
                mostrarSeries(series_maraton);

                cout << "\n\n-----------------\n";
                cout << "Con " << tiempo << " minutos disponibles:" << endl;

                auto resultado = AlgoritmosSERIES::maratonseries_capitulos(series_maraton_COPIA, tiempo, 1);
                
                cout << "Tiempo total consumido: " << get<1>(resultado) << " minutos" << endl;
                cout << "Puntuación total: " << get<2>(resultado) << endl;
                cout << "Capítulos seleccionados: " << endl;
                
                mostrarSeries(get<0>(resultado));
                
                cout << "\nCategorías\n****\n";
                for (const string &categoria : get<3>(resultado)) {
                    cout << categoria << endl;
                }
                break;
            }
            case 4:
            {
                system("cls");
                cout << "Probando Maratón de Series con todas las estrategias..." << endl;
                int tiempo = pedirTiempoDisponible();
               
                cout << "\n-----------------\n";
                cout << "Con " << tiempo << " minutos disponibles:" << endl;
                
                cout << "\n-----------------\n"
                     << "Por Valoración:\n";
                auto resultado = AlgoritmosSERIES::maratonseries_capitulos(series_maraton, tiempo, 1);
                cout << "Tiempo total consumido: " << get<1>(resultado) << " minutos" << endl;
                cout << "Puntuación total: " << get<2>(resultado) << "\n\n";
                cout << "Capítulos seleccionados: " << endl;
                for (const auto &capitulo : get<0>(resultado)) {
                    cout << capitulo << endl;
                }
                cout << "\nCategorías\n****\n";
                for (const string &categoria : get<3>(resultado)) {
                    cout << categoria << endl;
                }
                
                cout << "\n-----------------\n"
                     << "Por tiempo total:\n";
                resultado = AlgoritmosSERIES::maratonseries_capitulos(series_maraton, tiempo, 2);
                cout << "Tiempo total consumido: " << get<1>(resultado) << " minutos" << endl;
                cout << "Puntuación total: " << get<2>(resultado) << "\n\n";
                cout << "Capítulos seleccionados: " << endl;
                for (const auto &capitulo : get<0>(resultado)) {
                    cout << capitulo << endl;
                }
                cout << "\nCategorías\n****\n";
                for (const string &categoria : get<3>(resultado)) {
                    cout << categoria << endl;
                }
                
                cout << "\n-----------------\n"
                     << "Por Ratio:\n";
                resultado = AlgoritmosSERIES::maratonseries_capitulos(series_maraton, tiempo, 3);
                cout << "Tiempo total consumido: " << get<1>(resultado) << " minutos" << endl;
                cout << "Puntuación total: " << get<2>(resultado) << "\n\n";
                cout << "Capítulos seleccionados: " << endl;
                for (const auto &capitulo : get<0>(resultado)) {
                    cout << capitulo << endl;
                }
                cout << "\nCategorías\n****\n";
                for (const string &categoria : get<3>(resultado)) {
                    cout << categoria << endl;
                }
                
                break;
            }
            case 5:
            {
                cout << "Volviendo al menú principal..." << endl;
                salir = true;
                opcion = false;
                break;
            }
            case 0:
                salir = true;
                cout << "Saliendo del programa..." << endl;
                opcion = true;
                break;
        }
        system("pause");
    } while (!salir);
    return true;
}

void mostrarSeries(const vector<Serie> &series)
{
    int i = 1;
    for (const auto &serie : series)
    {
        cout << i++ << ". " << serie << endl;
    }
}


/**
 * Función para mostrar el menú principal.
 * Muestra los dos problemas de la práctica
 * @return Opción seleccionada
 */
int menuPrincipal()
{
    cout << "Practica 5: Algoritmos de ordenacion y seleccion" << endl;
    cout << "1. Ruta de tapas" << endl;
    cout << "2. Maratón de Series" << endl;
    cout << "0. Salir" << endl;

    return seleccionCorrecta(0, 2);
}

/**
 * Función para seleccionar una opción válida del menú.
 * @param inicio Valor mínimo de la opción
 * @param final Valor máximo de la opción
 * @return Opción seleccionada
 */
int seleccionCorrecta(int inicio, int final)
{
    int a;

    do
    {
        cout << "Elección: ";
        cin >> a;

        if (cin.fail())
        {
            // Si introduce un carácter en vez de un número
            a = final + 1; // o cualquier num no valido en menu
            cin.clear();   // Reset a la flag fail
            fflush(stdin); // Descartamos de buffer los caracteres leidos
        }
    } while (a < inicio || a > final);

    return a;
}

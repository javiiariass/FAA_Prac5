#pragma once

#include "Bar.h"
#include "Capitulo.h"
#include "Serie.h"
#include <vector>
using namespace std;
class AlgoritmosOrdenacion
{

    static void merge(vector<Bar>::iterator inicio, vector<Bar>::iterator medio, vector<Bar>::iterator fin, bool (*criterio)(const Bar &, const Bar &));
    static void merge(vector<Serie>::iterator inicio, vector<Serie>::iterator medio, vector<Serie>::iterator fin, bool (*criterio)(const Serie &, const Serie &));
	
    static void Mergesort(vector<Bar>::iterator inicio, vector<Bar>::iterator fin, bool(*criterio)(const Bar &, const Bar &));
	static void Mergesort(vector<Serie>::iterator inicio, vector<Serie>::iterator fin, bool(*criterio)(const Serie &, const Serie &));
    
    static void Mergesort(vector<Bar> &Bares, bool(*criterio)(const Bar &, const Bar &));
    static void Mergesort(vector<Serie> &Series, bool(*criterio)(const Serie &, const Serie &));
public:
    static void ordenar(vector<Bar> &Bares, bool (*criterio)(const Bar &, const Bar &));
    static void ordenar(vector<Serie> &Series, bool (*criterio)(const Serie &, const Serie &));
};



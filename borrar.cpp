#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric> // Para std::accumulate

// Estructura para representar un bar
struct Bar {
    int id;
    int puntuacion;
    int tiempo_desplazamiento; // Tiempo de ida y vuelta
    int tiempo_consumo;
    double tiempo_total;
    double ratio_puntuacion_tiempo;

    Bar(int i, int p, int d, int c) : id(i), puntuacion(p), tiempo_desplazamiento(d), tiempo_consumo(c) {
        tiempo_total = static_cast<double>(tiempo_desplazamiento + tiempo_consumo);
        if (tiempo_total > 0) {
            ratio_puntuacion_tiempo = static_cast<double>(puntuacion) / tiempo_total;
        } else {
            ratio_puntuacion_tiempo = 0.0; // Evitar división por cero
        }
    }
};

// --- Comparadores para las diferentes estrategias ---

// Estrategia 1: Mayor puntuación (descendente)
bool compararPorPuntuacion(const Bar& a, const Bar& b) {
    return a.puntuacion > b.puntuacion;
}

// Estrategia 2: Menor tiempo total (ascendente)
bool compararPorTiempoTotal(const Bar& a, const Bar& b) {
    return a.tiempo_total < b.tiempo_total;
}

// Estrategia 3: Mejor relación puntuación/tiempo (descendente)
bool compararPorRatio(const Bar& a, const Bar& b) {
    return a.ratio_puntuacion_tiempo > b.ratio_puntuacion_tiempo;
}

// Función genérica para ejecutar la estrategia voraz
std::pair<int, std::vector<Bar>> resolverRutaTapa(std::vector<Bar> bares, int tiempo_limite, 
                                                 bool (*comparador)(const Bar&, const Bar&)) {
    // 1. Ordenar los bares según el comparador de la estrategia
    std::sort(bares.begin(), bares.end(), comparador);

    std::vector<Bar> bares_seleccionados;
    int puntuacion_total = 0;
    int tiempo_actual = 0;

    // 2. Iterar y seleccionar bares
    for (const auto& bar : bares) {
        if (tiempo_actual + bar.tiempo_total <= tiempo_limite) {
            bares_seleccionados.push_back(bar);
            puntuacion_total += bar.puntuacion;
            tiempo_actual += bar.tiempo_total;
        }
    }
    return {puntuacion_total, bares_seleccionados};
}

void imprimirResultado(const std::string& estrategia, int puntuacion_total, const std::vector<Bar>& bares_seleccionados) {
    std::cout << "--- Estrategia: " << estrategia << " ---\n";
    std::cout << "Puntuacion Total: " << puntuacion_total << "\n";
    std::cout << "Bares seleccionados:\n";
    if (bares_seleccionados.empty()) {
        std::cout << "  Ninguno.\n";
    } else {
        for (const auto& bar : bares_seleccionados) {
            std::cout << "  Bar ID: " << bar.id 
                      << ", Puntuacion: " << bar.puntuacion 
                      << ", Tiempo Total: " << bar.tiempo_total 
                      << ", Ratio P/T: " << bar.ratio_puntuacion_tiempo << "\n";
        }
    }
    std::cout << "\n";
}

int main() {
    // Ejemplo de datos de bares
    std::vector<Bar> bares_ejemplo = {
        Bar(1, 10, 20, 10),  // Puntuacion:10, D:20, C:10 -> T:30, Ratio: 0.33
        Bar(2, 8,  10, 5),   // Puntuacion:8,  D:10, C:5  -> T:15, Ratio: 0.53
        Bar(3, 12, 30, 10),  // Puntuacion:12, D:30, C:10 -> T:40, Ratio: 0.30
        Bar(4, 6,  5,  5),   // Puntuacion:6,  D:5,  C:5  -> T:10, Ratio: 0.60
        Bar(5, 15, 40, 15)   // Puntuacion:15, D:40, C:15 -> T:55, Ratio: 0.27
    };
    int tiempo_limite = 60;

    // Ejecutar Estrategia 1: Mejor Puntuación
    auto resultado1 = resolverRutaTapa(bares_ejemplo, tiempo_limite, compararPorPuntuacion);
    imprimirResultado("Mejor Puntuacion", resultado1.first, resultado1.second);

    // Ejecutar Estrategia 2: Menor Tiempo Total
    auto resultado2 = resolverRutaTapa(bares_ejemplo, tiempo_limite, compararPorTiempoTotal);
    imprimirResultado("Menor Tiempo Total", resultado2.first, resultado2.second);

    // Ejecutar Estrategia 3: Mejor Relación Puntuación/Tiempo
    auto resultado3 = resolverRutaTapa(bares_ejemplo, tiempo_limite, compararPorRatio);
    imprimirResultado("Mejor Relacion Puntuacion/Tiempo", resultado3.first, resultado3.second);

    return 0;
}
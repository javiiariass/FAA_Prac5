---
cssclasses:
  - center-images
---
<h1 class="center">MEMORIA PRACTICA 5</h1>

![[Fondo.png|500]]


# Tabla de contenido <!-- omit -->
```insta-toc
---
title:
  name: ""
  level: 1
  center: false
exclude: ""
style:
  listType: number
omit: []
levels:
  min: 1
  max: 6
---

# 

1. Problema 1: La ruta de la Tapa
    1. Estrategia 1: Mejores valoraciones
        1. Estrategia 1: Resultado Quicksort
        2. Estrategia 1: Resultado Mergesort
    2. Estrategia 2: Menor tiempo total de visita
    3. Estrategia 3: Ratio (Valoración/tiempo total)
    4. Comparación 3 Estrategias
        1. 300 minutos
        2. 237 minutos
    5. Conclusión
2. Problema 2: Maratón de series
    1. Estrategia 1: Mejor Valoración
    2. Estrategia 2: Menor duración
    3. Estrategia 3: Ratio (valoración/duración)
    4. Comparación 3 Estrategias Series
        1. 721 minutos
        2. 936 minutos
    5. Conclusión
    6. A diferencia de la mochila fraccionaria clásica, ¿crees que la Estrategia 3 es óptima en este caso?
```
# Problema 1: La ruta de la Tapa

> [!important] Dato importante
	> El enunciado comenta que el tiempo de desplazamiento es en una dirección, es decir, si queremos ir a un bar y volver al punto central, el tiempo de desplazamiento se cuenta dos veces. Por  tanto: $$T_{Total} = T_{Consumición} + (2 \cdot T_{Desplazamiento})$$

## Estrategia 1: Mejores valoraciones
> [!info] Algoritmo de ordenación
> Como podemos ver, el resultado varía con distintos algoritmos de ordenación aún que el tiempo disponible sea el mismo. Esto se debe a cómo funciona internamente cada algoritmo, haciendo que se comporten de una manera u otra en caso de que el atributo que se está usando para ordenar sea el igual en los elementos comparados actuales.
> A partir de ahora, voy a usar por defecto el algoritmo ==MergeSort==

### Estrategia 1: Resultado Quicksort
![[Estrategia1_180min_QUICKSORT.png|400]]
### Estrategia 1: Resultado Mergesort
![[Estrategia1_180min_MERGESORT.png|400]]

## Estrategia 2: Menor tiempo total de visita
![[TAPA_Estrategia2_180min_MERGESORT.png|400]]

Como podemos ver, ha mejorado un poco con respecto a la estrategia anterior
## Estrategia 3: Ratio (Valoración/tiempo total)
![[TAPAS_Estrategia3_180min_MERGESORT.png|400]]
Podríamos suponer que esta opción iba a ser mejor (en general puede serlo) pero por la propia naturaleza de los algoritmos voraces, puede haber casos en los que la solución global no es la óptima.

## Comparación 3 Estrategias 
### 300 minutos
![[TAPA_3Estrategias_300min.png|400]]
En este caso podemos ver cómo la primera y segunda estrategia han obtenido el mismo resultado. Ambas han seleccionado los mismos bares, aún que sus criterios de selección han hecho que las seleccionen en distinto orden. 
### 237 minutos
![[TAPA_3Estrategias_237min.png|400]]
En este caso podemos ver cómo la tercera estrategia ha obtenido el mismo tiempo pero mejor puntuación total.

## Conclusión
Como podemos ver, el mejor resultado no lo da siempre la misma estrategia. Esto se debe a la naturaleza de los voraces ya que se centran en obtener la mejor solución local, es decir, en el paso que estén en ese momento. Se podría decir que no tienen una visión "global" para intentar obtener la mejor solución total aún que el coste local en algún punto no sea el óptimo.

# Problema 2: Maratón de series
Este problema es bastante similar al anterior, solo que cada elemento tiene cantidades.
## Estrategia 1: Mejor Valoración
![[SERIE_Estrategia1_600min.png|400]]

## Estrategia 2: Menor duración
![[SERIE_Estrategia2_600min.png|400]]
Como podemos ver, en esta estrategia obtenemos una menor puntuación total pero, a cambio, podemos ver un mayor número de capítulos.

## Estrategia 3: Ratio (valoración/duración)
![[SERIE_Estrategia3_600min.png|400]]
Con esta duración, esta estrategia obtiene el mismo resultado que la primera estrategia.

## Comparación 3 Estrategias Series
### 721 minutos
![[SERIE_3Estrategias_721min.png|400]]

### 936 minutos
![[SERIE_3Estrategias_936min.png|400]]
## Conclusión
Como podemos ver, al igual que el primer problema, los resultados varían en función a los datos de entrada. No creo que haya una estrategia mejor que otra ya que dependerá de qué estemos buscando.  ¿Buscamos ver el mayor número de episodios posibles?, ¿o acaso buscamos ver menos episodios pero que estén muy bien valorados?
Aún que en las pruebas que se han realizado la estrategia 3 parece ser la más consistente en cuanto a mejor "resultado", no creo que haya que considerarla la mejor por lo ya comentado. 

En conclusión, dependiendo de la entrada (las series que se introducen, con sus  respectivas valoraciones, duraciones y numero de episodios) puede ser mejor o peor cualquier estrategia.

## A diferencia de la mochila fraccionaria clásica, ¿crees que la Estrategia 3 es óptima en este caso?
Creo que en este caso, la estrategia 3 no es lo más óptimo. La mochila fraccionaria clásica podría ser más óptima en el caso de que los episodios fueran divisibles, es decir, si se pudieran ver por trozos, la estrategia 3 sería más óptima por permitirnos seleccionar siempre los minutos de contenido que ofrecen la mayor valoración por unidad de tiempo, aprovechando así al máximo cada instante disponible hasta llenar exactamente el tiempo límite.


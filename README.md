# eda-lvl5-dnatool README

* Fecha de entrega: 10/05/2022
* Grupo: 7
  * DALZOTTO, Rafael
  * HEIR, Alejandro Nahuel

22.08 - Algoritmos y Estructuras de Datos - Ingeniería Electrónica - ITBA


# Respuestas

## Mejores alineamientos para los mystery genomes:

* Mystery genome 1 - OV806939
  * Delta B.1.617.2 - OM202516
  * Puntaje óptimo: 29826
* Mystery genome 2 - MT345875
  * Wuhan reference genome - NC_045512.2
  * Puntaje óptimo: 29885
* Mystery genome 3 - OU772970
  * Delta B.1.617.2 - OM202516
  * Puntaje óptimo: 29840

Los alineamientos óptimos correspondientes se encuentra en `/resources/test/results/`


# Bonus points
* La complejidad computacional del algoritmo Needleman-Wunsch es O(mn) debido a que el calculo
  de las direcciones (o scores) de la matriz de alineacion depende de los largos de ambas
  secuencias. 
  
  Sin embargo logramos reducir sustancialmente el uso de memoria, gracias a aprovechar
  cada bit en los elementos de la matriz de direcciones (DirectionMat) y debido a que no usamos
  una matriz de scores, resultando en un uso de memoria de no mas de 250 MB para comparar dos
  secuencias de unos 30000 pares de base (resultados experimentales). En cambio al usar una
  matriz de scores de `int32_t`, el uso de memoria se eleva a mas de 3 GB.
* Al cambiar los valores en el sistema de puntaje, cambia el puntaje final de alineamiento
  óptimo y tambien puede cambiar el alinieamiento optimo en si
* Comparamos los genomas de SARS-CoV-2003 y MERS-CoV con Wuhan reference genome
  * Puntaje de MERS-CoV vs Wuhan reference genome:       7240
  * Puntaje de SARS-CoV-2003 vs Wuhan reference genome:  18645
  * Los alineamientos óptimos correspondientes se encuentran en `/resources/test/results/`
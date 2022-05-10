# eda-lvl5-dnatool

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
  * Beta B.1.351 - MZ314996
  * Puntaje óptimo: 29865
* Mystery genome 3 - OU772970
  * Delta B.1.617.2 - OM202516
  * Puntaje óptimo: 29840

Los alineamientos óptimos correspondientes se encuentra en `/resources/test/results/`


# Bonus points
* La complejidad computacional del algoritmo Needleman-Wunsch es O(mn) debido a que el calculo
  de las direcciones (o scores) de la matriz de alineacion depende de los largos de ambas
  secuencias
* Al cambiar los valores en el sistema de puntaje, cambia el puntaje final de alineamiento
  óptimo y tambien puede cambiar el alinieamiento optimo en si
* Comparamos los genomas de SARS-CoV-2003 y MERS-CoV con Wuhan reference genome
  * Puntaje de MERS-CoV vs Wuhan reference genome:       7240
  * Puntaje de SARS-CoV-2003 vs Wuhan reference genome:  18645

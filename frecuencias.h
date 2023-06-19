#ifndef ALGORITMODEHUFFMAN_FRECUENCIAS_H
#define ALGORITMODEHUFFMAN_FRECUENCIAS_H

#include "estructuras.h"
#include "arbolDeHuffman.h"

#define MAX_SYMBOLS 255

void calcularFrecuencias(const char *texto, int *arregloDeFrecuencias);
Fila *enfilarFrecuencias(Fila *fila, const int *arregloDeFrecuencias);

#endif //ALGORITMODEHUFFMAN_FRECUENCIAS_H

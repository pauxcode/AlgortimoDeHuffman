#ifndef ALGORITMODEHUFFMAN_FRECUENCIAS_H
#define ALGORITMODEHUFFMAN_FRECUENCIAS_H
#include "arbolDeHuffman.h"
#define MAX_SYMBOLS 255

Fila *enfilarFrecuencias(Fila *fila, const int *arregloDeFrecuencias);
void calcularFrecuencias(const char *texto, int *arregloDeFrecuencias);
#endif //ALGORITMODEHUFFMAN_FRECUENCIAS_H

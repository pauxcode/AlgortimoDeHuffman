#include "frecuencias.h"

void calcularFrecuencias(const char *texto, int *arregloDeFrecuencias) {
    for (int i = 0; i < MAX_SYMBOLS; i++)
        arregloDeFrecuencias[i] = 0;

    while (*texto != '\0') {
        arregloDeFrecuencias[(int)(*texto)]++;
        texto++;
    }
}

Fila *enfilarFrecuencias(Fila *fila, const int *arregloDeFrecuencias) {
    for (int i = 0; i < MAX_SYMBOLS; i++)
        if (arregloDeFrecuencias[i] > 0) {
            NodoArbol *nuevoNodo = crearNodoArbol((char)i, arregloDeFrecuencias[i]);
            fila = enfilar(fila, nuevoNodo);
        }

    return fila;
}
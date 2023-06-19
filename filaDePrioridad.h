#ifndef ALGORITMODEHUFFMAN_FILADEPRIORIDAD_H
#define ALGORITMODEHUFFMAN_FILADEPRIORIDAD_H
#include "estructuras.h"
#include <stdio.h>
#include <stdlib.h>
#define vacia NULL
Fila *enfilar(Fila *fila, NodoArbol *nodoArbol);
Fila *quitarDeFila(Fila *fila);
void mostrarFila(Fila *fila);
#endif //ALGORITMODEHUFFMAN_FILADEPRIORIDAD_H

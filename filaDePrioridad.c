#include "filaDePrioridad.h"
#include <stdio.h>
Fila *enfilar(Fila *fila, NodoArbol *nodoArbol) {
    Fila *nuevoEnFila, *aux;

    nuevoEnFila = (Fila *) malloc(sizeof(Fila));
    nuevoEnFila->nodo = nodoArbol;

    // Si la fila esta vacia pone el nodo al inicio, pero si entra otro con menor frecuencia,
    // lo sustituira mandando al sustituido atras
    if (fila == vacia || nuevoEnFila->nodo->frecuencia < fila->nodo->frecuencia) {
        nuevoEnFila->siguiente = fila;
        fila = nuevoEnFila;
    } else {
        aux = fila;
        while (aux->siguiente != NULL && aux->siguiente->nodo->frecuencia <= nodoArbol->frecuencia)
            aux = aux->siguiente;
        nuevoEnFila->siguiente = aux->siguiente;
        aux->siguiente = nuevoEnFila;
    }

    return fila;
}

Fila *quitarDeFila(Fila *fila) {
    Fila *aux;

    if(fila == vacia) return NULL;

    aux = fila;
    fila = fila->siguiente;
    free(aux);

    return fila;
}

void mostrarFila(Fila *fila) {
    while (fila != vacia) {
        printf("[%c:%d] ", fila->nodo->caracter, fila->nodo->frecuencia);
        fila = fila->siguiente;
    }
    printf("\n");
}
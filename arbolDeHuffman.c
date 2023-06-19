#include "arbolDeHuffman.h"
NodoArbol *crearNodoArbol(char caracter, int frecuencia) {
    NodoArbol *nodo = (NodoArbol *) malloc(sizeof(NodoArbol));
    nodo->caracter = caracter;
    nodo->frecuencia = frecuencia;
    nodo->izquierdo = NULL;
    nodo->derecho = NULL;

    return nodo;
}

NodoArbol *crearArbol(Fila *fila) {
    while (fila->siguiente != NULL) {
        NodoArbol *izquierda, *derecha;

        izquierda = fila->nodo;
        fila = quitarDeFila(fila);

        derecha = fila->nodo;
        fila = quitarDeFila(fila);

        int frecuenciaPadre = izquierda->frecuencia + derecha->frecuencia;

        NodoArbol *padre = crearNodoArbol('$', frecuenciaPadre);
        padre->izquierdo = izquierda;
        padre->derecho = derecha;

        fila = enfilar(fila, padre);
    }

    return fila->nodo;
}
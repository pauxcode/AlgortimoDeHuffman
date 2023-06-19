#ifndef ALGORITMODEHUFFMAN_ESTRUCTURAS_H
#define ALGORITMODEHUFFMAN_ESTRUCTURAS_H

typedef struct Fila {
    struct NodoArbol *nodo;
    struct Fila *siguiente;
} Fila;

typedef struct NodoArbol {
    char caracter;
    int frecuencia;
    struct NodoArbol *izquierdo, *derecho;
} NodoArbol;

typedef struct Lista {
    char caracter;
    int indice;
    int *codigo;
    struct Lista *siguiente;
} Lista;

#endif //ALGORITMODEHUFFMAN_ESTRUCTURAS_H

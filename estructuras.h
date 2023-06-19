typedef struct NodoLista {
    int array[10];
    char caracter;
    struct NodoLista *siguiente;
} NodoLista;

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
    int codigo[10];
    int *codigo2;
    struct Lista *siguiente;
} Lista;
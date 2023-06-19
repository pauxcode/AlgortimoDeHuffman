#define MAX_SYMBOLS 255
#define NODO_HOJA nodo->izquierdo == NULL && nodo->derecho == NULL
#include "filaDePrioridad.h"
#include "arbolDeHuffman.h"
#include <stdio.h>

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
            NodoArbol *temp = crearNodoArbol((char)i, arregloDeFrecuencias[i]);
            fila = enfilar(fila, temp);
        }

    return fila;
}

Lista *agregarLista(Lista *nodo, char caracter, const int *arr, int indice) {
    Lista *ptr, *p;
    ptr = (Lista *) malloc(sizeof(Lista));

    ptr->caracter = caracter;
    ptr->indice = indice;
    ptr->codigo2 = (int *) malloc(indice * sizeof(int));

    for (int i = 0; i < indice; ++i) {
        ptr->codigo[i] = arr[i];
        ptr->codigo2[i] = arr[i];
    }
    if (nodo == NULL) {
        nodo = ptr;
    } else {
        p = nodo;
        while (p->siguiente != NULL)
            p = p->siguiente;
        ptr->siguiente = p->siguiente;
        p->siguiente = ptr;
    }
    return nodo;
}

#pragma clang diagnostic push
#pragma ide diagnostic ignored "misc-no-recursion"
Lista *obtenerCodigosHuffman(NodoArbol *nodo, Lista *lista, int *codigo, int indice) {
    if (NODO_HOJA) {
        printf("[%c: ", nodo->caracter);
        for (int i = 0; i < indice; i++){
            printf("%d", codigo[i]);
        }
        printf("]");
        lista = agregarLista(lista, nodo->caracter, codigo, indice);
    }

    if (nodo->izquierdo != NULL) {
        codigo[indice] = 0;
        lista = obtenerCodigosHuffman(nodo->izquierdo, lista, codigo, indice + 1);
    }

    if (nodo->derecho != NULL) {
        codigo[indice] = 1;
        lista = obtenerCodigosHuffman(nodo->derecho, lista,codigo, indice + 1);
    }

    return lista;
}
#pragma clang diagnostic pop

void codificarMensaje(Lista *lista, const char *texto, int *porfi, int *auxI) {
    Lista *listaOriginal = lista;
    printf("\n");
    while (*texto != '\0') {
        while (lista != NULL) {
            if (*texto == lista->caracter) {
                int *temp = (int*)realloc(porfi, (lista->indice + *auxI) * sizeof(int));
                porfi = temp;
                for (int i = 0; i < lista->indice; ++i) {
                    printf("%d", lista->codigo2[i]);
                    porfi[*auxI] = lista->codigo2[i];
                    *auxI = *auxI + 1;
                }
            }
            lista = lista->siguiente;
        }
        texto++;
        lista = listaOriginal;
    }
}

void decodificarMensaje(Lista *lista, const int *porfi, const int *auxI) {
    Lista *listaOriginal = lista;
    int ret = 0;
    while (ret < *auxI) {
        while (lista != NULL) {
            int cont = 0;
            for (int i = 0; i < lista->indice; ++i) {
                if (porfi[ret + i] != lista->codigo2[i]) {
                    break;
                } else {
                    cont++;
                }
            }
            if (cont == lista->indice) {
                printf("%c", lista->caracter);
                ret += cont;
                lista = listaOriginal;
                break;
            }
            lista = lista->siguiente;
        }
    }
}

int main() {
    Fila *fila = NULL;
    NodoArbol *raiz = NULL;
    int frecuencias[MAX_SYMBOLS];
    const char *texto = "Pinocho se comio un bizcocho.";

    int codigo[5];
    int indice = 0;
    Lista *lista = NULL;

    calcularFrecuencias(texto, frecuencias);
    fila = enfilarFrecuencias(fila, frecuencias);
    mostrarFila(fila);
    raiz = crearArbol(fila);

    lista = obtenerCodigosHuffman(raiz, lista, codigo, indice);

    int *porfi = (int *) malloc(sizeof(int));
    int auxI = 0;

    codificarMensaje(lista, texto, porfi, &auxI);

    printf("\n");
    for (int i = 0; i < auxI; ++i) {
        printf("%d", porfi[i]);
    }
    printf("\n");

    decodificarMensaje(lista, porfi, &auxI);

    return 0;
}

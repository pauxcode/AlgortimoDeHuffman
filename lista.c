#include "lista.h"

Lista *agregarLista(Lista *nodo, char caracter, const int *arr, int indice) {
    Lista *ptr, *p;
    ptr = (Lista *) malloc(sizeof(Lista));

    ptr->caracter = caracter;
    ptr->indice = indice;
    ptr->codigo = (int *) malloc(indice * sizeof(int));

    for (int i = 0; i < indice; ++i)
        ptr->codigo[i] = arr[i];

    if (nodo == NULL)
        nodo = ptr;
    else {
        p = nodo;
        while (p->siguiente != NULL)
            p = p->siguiente;
        ptr->siguiente = p->siguiente;
        p->siguiente = ptr;
    }

    return nodo;
}
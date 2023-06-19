#include "codigosHuffman.h"

#pragma clang diagnostic push
#pragma ide diagnostic ignored "misc-no-recursion"
Lista *obtenerCodigosHuffman(NodoArbol *nodo, Lista *lista, int *codigo, int indice) {
    if (NODO_HOJA) {
        printf("[%c: ", nodo->caracter);
        for (int i = 0; i < indice; i++){
            printf("%d", codigo[i]);
        }
        printf("]\n");
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

int *codificarMensaje(Lista *lista, const char *texto, int *codigo, int *indice) {
    Lista *listaOriginal = lista;
    codigo = (int *) malloc(sizeof(int));
    while (*texto != '\0') {
        while (lista != NULL) {
            if (*texto == lista->caracter) {
                int *temp = (int *) realloc(codigo, (lista->indice + *indice) * sizeof(int));
                codigo = temp;
                for (int i = 0; i < lista->indice; ++i) {
                    printf("%d", lista->codigo[i]);
                    codigo[*indice] = lista->codigo[i];
                    (*indice)++;
                }
            }
            lista = lista->siguiente;
        }
        texto++;
        lista = listaOriginal;
    }

    return codigo;
}

void decodificarMensaje(Lista *lista, const int *codigo, const int *indice) {
    Lista *listaOriginal = lista;
    int ret = 0;
    while (ret < *indice)
        while (lista != NULL) {
            int cont = 0;
            for (int i = 0; i < lista->indice; ++i) {
                if (codigo[ret + i] != lista->codigo[i])
                    break;
                cont++;
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
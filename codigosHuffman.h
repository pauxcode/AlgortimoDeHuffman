#ifndef ALGORITMODEHUFFMAN_CODIGOSHUFFMAN_H
#define ALGORITMODEHUFFMAN_CODIGOSHUFFMAN_H

#include <stdio.h>
#include <stdlib.h>
#include "estructuras.h"
#include "lista.h"

#define NODO_HOJA nodo->izquierdo == NULL && nodo->derecho == NULL

Lista *obtenerCodigosHuffman(NodoArbol *nodo, Lista *lista, int *codigo, int indice);
int *codificarMensaje(Lista *lista, const char *texto, int *codigo, int *indice);
void decodificarMensaje(Lista *lista, const int *codigo, const int *indice);

#endif //ALGORITMODEHUFFMAN_CODIGOSHUFFMAN_H

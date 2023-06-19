#include <stdio.h>
#include <string.h>
#include "frecuencias.h"
#include "arbolDeHuffman.h"
#include "codigosHuffman.h"

int main() {
    Fila *fila = NULL;
    Lista *lista = NULL;
    NodoArbol *raiz = NULL;
    int *mensajeCodificado = NULL;
    int indice = 0;
    int frecuencias[MAX_SYMBOLS];
    int codigo[10];
    char texto[100];
    //Texto de ejemplo: Pinocho se comio un bizcocho.

    printf("Ingresa un texto: ");
    fgets(texto, sizeof(texto), stdin);
    texto[strcspn(texto, "\n")] = '\0';

    calcularFrecuencias(texto, frecuencias);
    fila = enfilarFrecuencias(fila, frecuencias);
    raiz = crearArbol(fila);
    printf("\nCodigos:\n");
    lista = obtenerCodigosHuffman(raiz, lista, codigo, indice);

    printf("\nMensaje original:\n");
    printf("%s", texto);
    printf("\n");

    printf("\nMensaje codificado:\n");
    mensajeCodificado = codificarMensaje(lista, texto, mensajeCodificado, &indice);
    printf("\n");

    printf("\nMensaje decodificado:\n");
    decodificarMensaje(lista, mensajeCodificado, &indice);
    printf("\n");

    return 0;
}
#ifndef ALGORITMODEHUFFMAN_ARBOLDEHUFFMAN_H
#define ALGORITMODEHUFFMAN_ARBOLDEHUFFMAN_H

#include <stdlib.h>
#include "estructuras.h"
#include "filaDePrioridad.h"

NodoArbol *crearNodoArbol(char caracter, int frecuencia);
NodoArbol *crearArbol(Fila *fila);

#endif //ALGORITMODEHUFFMAN_ARBOLDEHUFFMAN_H

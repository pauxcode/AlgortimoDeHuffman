cmake_minimum_required(VERSION 3.25)
project(AlgoritmoDeHuffman C)

set(CMAKE_C_STANDARD 23)

add_executable(AlgoritmoDeHuffman main.c arbolDeHuffman.c filaDePrioridad.c filaDePrioridad.h arbolDeHuffman.h codigosHuffman.c codigosHuffman.h lista.c lista.h frecuencias.c frecuencias.h estructuras.h)

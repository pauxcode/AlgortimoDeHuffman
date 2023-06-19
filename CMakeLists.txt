cmake_minimum_required(VERSION 3.25)
project(AlgoritmoDeHuffman C)

set(CMAKE_C_STANDARD 23)

add_executable(AlgoritmoDeHuffman main.c arbolDeHuffman.c filaDePrioridad.c estructuras.h filaDePrioridad.h arbolDeHuffman.h)

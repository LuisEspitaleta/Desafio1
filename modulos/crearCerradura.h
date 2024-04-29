#ifndef CREARCERRADURA_H
#define CREARCERRADURA_H

int** crearMatrizCuadrada(int &tamano);
int* llenaCerradura(int* tamanioLlave, int* llaveK);
int compararPosicionMatrices(int** matrizA, int** matrizB, int tamanoA, int tamanoB, int* llave);
int** rotarMatrizCuadrada(int** matriz, int &tamano);

#endif

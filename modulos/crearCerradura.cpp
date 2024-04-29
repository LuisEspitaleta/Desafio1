#include <iostream>
#include <string>
#include "crearCerradura.h"

using namespace std;

int** crearMatrizCuadrada(int &tamano) {
    int** matriz = new int*[tamano]; // Reserva de memoria para las filas

    int indice = 1;
    for (int i = 0; i < tamano; ++i) {
        matriz[i] = new int[tamano]; // Reserva de memoria para las columnas
        for (int j = 0; j < tamano; ++j) {
            if ((j == tamano / 2) && (i == tamano / 2) ) {
                matriz[i][j] = 0;
            } else {
                matriz[i][j] = indice ++;
            }
        }
    }
    return matriz;
}

// Función para rotar la matriz en sentido horario (90 grados) Punto 2
int** rotarMatrizCuadrada(int** matriz, int &tamano) {
    int** matrizRotada = new int*[tamano];
    for (int i = 0; i < tamano; ++i) {
        matrizRotada[i] = new int[tamano];
        for (int j = 0; j < tamano; ++j) {
            matrizRotada[i][j] = matriz[tamano - j - 1][i];
        }
    }
    return matrizRotada;
}


int compararPosicionMatrices(int** matrizA, int** matrizB, int* llave) {
    // Verificar si la posición (i, j) de la matriz A es mayor que la de la matriz B
    cout << "comparando " << matrizA[llave[0]][llave[1]] << " con " << matrizB[llave[0]][llave[1]] << endl;
    if (matrizA[llave[0]][llave[1]] > matrizB[llave[0]][llave[1]]) {
        return 1; // Devolver 1 si matriz A es mayor
    }
    // Verificar si la posición (i, j) de la matriz A es menor que la de la matriz B
    else if (matrizA[llave[0]][llave[1]] < matrizB[llave[0]][llave[1]]) {
        return -1; // Devolver -1 si matriz A es menor
    }
    // Si ninguna de las condiciones anteriores se cumple, significa que las posiciones son iguales
    return 0;
}

int* llenaCerradura(int* tamanioLlave,int* llaveK){

    int valorCerraduraM, valorInicioMatriz = 3;
    int *ptrValorInicioMatriz = &valorInicioMatriz;
    int *ptrValorCerradura = &valorCerraduraM;
    int *cerraduraX = new int[*tamanioLlave-1];
    int*** arregloDeMatrices = new int**[*tamanioLlave-1];
    bool finalizar = false;

    // Llenar el array preguntando al usuario por los valores la cerradura X
    for (int i = 0; i < *tamanioLlave-1; ++i) {
        if (i == 0) {
            do {
                cout << "Ingrese el valor Con que inice la cerradura:";
                cin >> *ptrValorCerradura;
                cerraduraX[i] = *ptrValorCerradura;
                int** miMatriz = crearMatrizCuadrada(cerraduraX[i]);
                arregloDeMatrices[i] = miMatriz;
            } while(*ptrValorCerradura % 2 == 0 || (*ptrValorCerradura < 3));
        }else{
            do{

                cerraduraX[i] = *ptrValorInicioMatriz;
                cout  <<  cerraduraX[i];
                int** miMatriz = crearMatrizCuadrada(cerraduraX[i]);
                    for (int i = 0; i < cerraduraX[i]; ++i) {
                        for (int j = 0; j < cerraduraX[i]; ++j) {
                            cout << miMatriz[i][j] << " "; // Usamos cout en lugar de std::cout
                        }
                        cout << "\n"; // Salto de linea
                    }

                for (int i = 0; i < 4; ++i) {
                    int resultado = compararPosicionMatrices(arregloDeMatrices[i-1], miMatriz, llaveK);
                    if (resultado != llaveK[i+2]) {
                        miMatriz = rotarMatrizCuadrada(miMatriz, cerraduraX[i]);
                    }else {
                        finalizar = false;
                        break;
                    }
                    if (i == 3) {
                        finalizar = true;
                        *ptrValorInicioMatriz + 2;
                    }
                }
            } while(finalizar);
        }
    }

    return cerraduraX;

}

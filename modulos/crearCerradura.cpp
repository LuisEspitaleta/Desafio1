#include <iostream>
#include "crearCerradura.h"

using namespace std;

// Función para imprimir la matriz
void imprimirMatriz(int** matriz, int &tamano) {
    for (int i = 0; i < tamano; ++i) {
        for (int j = 0; j < tamano; ++j) {
            cout << matriz[i][j] << " "; // Usamos cout en lugar de std::cout
        }
        cout << "\n"; // Salto de linea
    }
}


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

int compararPosicionMatrices(int** matrizA, int** matrizB, int tamanoA, int tamanoB, int* llave) {

    int fila = llave[0];
    int columna = llave[1];

    // Verificar si el campo a comparar está dentro de los límites de la matriz B (la más pequeña)
    if (fila >= tamanoB || columna >= tamanoB) {
        //cout << "Error: El campo " << fila << ", " << columna << " a comparar esta fuera de los limites de la matriz B.\n";
        return 2; // O retorna algún código de error o valor indicativo de la situación
    }

    // Verificar si el campo a comparar está dentro de los límites de la matriz A
    if (fila >= tamanoA || columna >= tamanoA) {
        //cout << "Advertencia: El campo " << fila << ", " << columna << " a comparar esta fuera de los limites de la matriz A.\n";
        return 2;
    }
    // Verificar si la posición (i, j) de la matriz A es mayor que la de la matriz B
    //cout << "comparando " << matrizA[fila-1][columna-1] << " con " << matrizB[fila-1][columna-1] << endl;
    if (matrizA[fila-1][columna-1] > matrizB[fila-1][columna-1]) {
        return 1; // Devolver 1 si matriz A es mayor
    }
    // Verificar si la posición (i, j) de la matriz A es menor que la de la matriz B
    else if (matrizA[fila-1][columna-1] < matrizB[fila-1][columna-1]) {
        return -1; // Devolver -1 si matriz A es menor
    }
    // Si ninguna de las condiciones anteriores se cumple, significa que las posiciones son iguales
    return 0;
}

int* llenaCerradura(int* tamanioLlave, int* llaveK){

    int valorCerraduraM, valorInicioMatriz;
    int *ptrValorCerradura = &valorCerraduraM;
    int *cerraduraX = new int[*tamanioLlave-1];
    int*** arregloDeMatrices = new int**[*tamanioLlave-1];
    bool finalizar = false;
    int detener = 1;


    // Llenar el array preguntando al usuario por los valores la cerradura X
    for (int i = 0; i < *tamanioLlave-1; ++i) {
        //cout << "\n \nllenando campo: " << i+1;
        //cout << "\n \n";
        valorInicioMatriz = 3 ;
        if (i == 0) {
            do {
                cout << llaveK[0];
                cout << llaveK[1];
                if (valorInicioMatriz < llaveK[0] || valorInicioMatriz < llaveK[1]) {
                    valorInicioMatriz += 2;
                }
                cout << "\n";
                cout << valorInicioMatriz;
                cout << "\n";
                cerraduraX[i] = valorInicioMatriz;
                int** miMatriz = crearMatrizCuadrada(cerraduraX[i]);
                arregloDeMatrices[i] = miMatriz;              
            } while((valorInicioMatriz % 2 == 0) || (valorInicioMatriz < 3) || (valorInicioMatriz < llaveK[0]));
            imprimirMatriz(arregloDeMatrices[i], valorInicioMatriz);
            cout << "\n";
        }else{
            do{
                int** miMatriz = crearMatrizCuadrada(valorInicioMatriz);
                for (int j = 0; j < 4; ++j) {
                    int resultado = compararPosicionMatrices(arregloDeMatrices[i-1], miMatriz, cerraduraX[i-1], valorInicioMatriz, llaveK);
                    int siguienteValor = llaveK[i+1];
                    imprimirMatriz(miMatriz, valorInicioMatriz);
                    cout << "\n\n";
                    if (resultado != siguienteValor && resultado != 2){
                        miMatriz = rotarMatrizCuadrada(miMatriz, valorInicioMatriz);
                    }else if(resultado == 2){
                        finalizar = false;
                        break;
                    }else{
                        finalizar = true;
                        break;
                    }
                    if (j == 3) {
                        finalizar = true;
                    }
                }

                cerraduraX[i] = valorInicioMatriz;
                if (valorInicioMatriz == (cerraduraX[i-1])-2) {
                    valorInicioMatriz += 4;
                }else{
                    valorInicioMatriz += 2;
                }
                if ((i > 2) && (valorInicioMatriz == (cerraduraX[i-2]))) {
                    valorInicioMatriz += 2;
                }
                arregloDeMatrices[i] = miMatriz;
            } while(!finalizar);
        }
    }
    return cerraduraX;
}

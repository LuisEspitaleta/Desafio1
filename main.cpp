#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

#include "modulos/crearCerradura.h"
#include "modulos/crearReglaK.h"

using namespace std;

// Función para crear una matriz cuadrada dinámica  Punto 1


// Función para imprimir la matriz
void imprimirMatriz(int** matriz, int &tamano) {
    for (int i = 0; i < tamano; ++i) {
        for (int j = 0; j < tamano; ++j) {
            cout << matriz[i][j] << " "; // Usamos cout en lugar de std::cout
        }
        cout << "\n"; // Salto de linea
    }
}



void liberarMemoria(int*** matriz, int &size, int* tamanos) {
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < tamanos[i]; ++j) {
            delete[] matriz[i][j];
        }
        delete[] matriz[i];
    }
    delete[] matriz;
}



int main() {

    int tamanioLlave, tamanioCerradura, opcion;
    int cantidadMatrices;
    int *ptrTamanioLlave = &tamanioLlave;
    int *ptrCantidadMatrices = &cantidadMatrices;
    int *ptrOpcion = &opcion;
    int** arrayOpen = new int*[2];
    // Preguntar tamaño de la llave (debe ser de 3 o más)

    do {
        cout << "Ingrese el tamaio de la llave (debe ser 3 o mas): ";
        cin >> *ptrTamanioLlave;
        if (*ptrTamanioLlave < 3){
            cout << "Por favor, ingrese un valor valido (3 o mas)." << endl;
        }
    } while (*ptrTamanioLlave < 3);

    int *llaveK = new int[*ptrTamanioLlave];
    int *cerraduraK = new int[*ptrTamanioLlave-1];

    llaveK = llenaLLave(ptrTamanioLlave);
    cerraduraK = llenaCerradura(ptrTamanioLlave, llaveK);
    for (int i = 0; i < tamanioLlave; ++i) {
        cout << llaveK[i] << " "; // Usamos cout en lugar de std::cout
    }
    for (int i = 0; i < tamanioLlave; ++i) {
        cout << cerraduraK[i] << " "; // Usamos cout en lugar de std::cout
    }
    // Preguntar tamaño de la cerradura (debe ser de 3 o más)
    do {
        cout << "Ingrese el tamaio de la cerradura (debe ser 3 o mas): ";
        cin >> *ptrCantidadMatrices;
    } while (*ptrCantidadMatrices < 3);
    int *cerradura = new int[*ptrCantidadMatrices];
    int *llave = new int[*ptrCantidadMatrices+1];
    do {
        cout << "Desea generar los datos aleatoriamente? Si(1) No(2): ";
        cin >> *ptrOpcion;
    } while (*ptrOpcion != 1 && *ptrOpcion != 2);

    //arrayOpen = llenaLLaveCerradura(ptrCantidadMatrices, ptrOpcion);
    //cerradura = arrayOpen[0];
    //llave = arrayOpen[1];

    cout << "\n";

    int*** arregloDeMatrices = new int**[*ptrCantidadMatrices];

    for (int i = 0; i < *ptrCantidadMatrices; ++i) {
        cout << "Matriz " << i + 1 << ":\n";
        // Crear la matriz llamando la funcion crearMatrizCuadrada()
        int** miMatriz = crearMatrizCuadrada(cerradura[i]);
        arregloDeMatrices[i] = miMatriz;
        //up

        cout << "Matriz original:\n";
        // Imprimir la matriz llamando la funcion imprimirMatriz()
        imprimirMatriz(miMatriz, cerradura[i]);

        // Rotar la matriz y obtener la matriz rotada
        //int** matrizRotada = rotarMatrizCuadrada(miMatriz, *ptrTamano);
    }

    int x = llave[0];
    int y = llave[1];

    int resultado;
    bool finalizar = false;
    for (int j = 0; j < *ptrCantidadMatrices - 1; ++j) {
        int** matrizB = arregloDeMatrices[j+1];
        cout << "\n\nComparando matriz" << j+1 << " con matriz" << j+2 << endl;
        cout << "tamanio del arreglo B" << (j+1)  << " es " << cerradura[j+1] << endl;
        cout <<"la llavce es " << llave[j+2] << endl;
        for (int i = 0; i < 4; ++i) {
            int resultado = compararPosicionMatrices(arregloDeMatrices[j], matrizB, llave);
            cout << "\nComparación 1 en la posición (" << x << ", " << y << "): " << resultado << endl;
            cout << "el tamanio B" << (j+1)  << " es " << cerradura[j+1] << endl;
            imprimirMatriz(matrizB, cerradura[j+1]);
            if (resultado != llave[j+2]) {
                matrizB = rotarMatrizCuadrada(matrizB, cerradura[j+1]);
            }else {
                break;
            }
            if (i == 3) {
                finalizar = true;
            }
        }
        if (finalizar) {
            cout << "\nLa llave x(";
            for (int i = 0; i < *ptrCantidadMatrices+1; ++i) {
                cout << llave[i] << ",";
            }
            cout << ") no abre la cerradura K(";
            for (int i = 0; i < *ptrCantidadMatrices; ++i) {
                cout << cerradura[i] << ",";
            }
            cout << ")\n";
            break;
        }
    }

    if (!finalizar) {
        cout << "\nLa llave x(";
        for (int i = 0; i < *ptrCantidadMatrices+1; ++i) {
            cout << llave[i] << ",";
        }
        cout << ") Abrio con exito la cerradura K(";
        for (int i = 0; i < *ptrCantidadMatrices; ++i) {
            cout << cerradura[i] << ",";
        }
        cout << ")\n";
    }

    // Liberar la memoria de matrices
    liberarMemoria(arregloDeMatrices, *ptrCantidadMatrices, cerradura);
    delete[] cerradura;
    delete[] llave;
    return 0;
}

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

#include "modulos/crearCerradura.h"
#include "modulos/crearReglaK.h"

using namespace std;

// Función para crear una matriz cuadrada dinámica  Punto 1





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
    int *ptrTamanioLlave = &tamanioLlave;
    int *ptrOpcion = &opcion;

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
    cout << "\nLa llave x(";
    for (int i = 0; i < tamanioLlave; ++i) {
        cout << llaveK[i] << " "; // Usamos cout en lugar de std::cout
    }
    cout << ") Abrio con exito la cerradura K(";
    for (int i = 0; i < tamanioLlave-1; ++i) {
        cout << cerraduraK[i] << " "; // Usamos cout en lugar de std::cout
    } bool finalizar = false;
    cout << ")" << endl;


    // Liberar la memoria de matrices
    //liberarMemoria(arregloDeMatrices, *ptrCantidadMatrices, cerradura);
    //delete[] cerradura;
    //delete[] llave;
    return 0;
}

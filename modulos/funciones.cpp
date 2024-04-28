#include <iostream>
#include <string>
#include "funciones.h"

using namespace std;

int** llenaLLaveCerradura(int* ptrCantidadMatrices, int* ptrOpcion){

    int tamanioLlave, tamanioCerradura, valorCerradura, valorLlave;
    int *ptrValorCerradura = &valorCerradura;
    int *ptrValorLlave = &valorLlave;
    int *cerraduraX = new int[*ptrCantidadMatrices];
    int *llaveK = new int[*ptrCantidadMatrices+1];
    int** llaveYCerrradura = new int*[2];

    // Inicializar la semilla para la generación de números aleatorios
    srand(static_cast<unsigned int>(time(nullptr)));

    if (*ptrOpcion == 1) {//Llenar de manera aletoria
        for (int i = 0; i < *ptrCantidadMatrices; ++i) {
            int valor;
            do {
                valor = rand() % 100;
            } while (valor % 2 == 0 || valor < 3); // Repetir si el número es par o menor que 3
            cerraduraX[i] = valor;
            cout << "Valor para la Cerradura[" << i << "]: " << cerraduraX[i];
        }
        for (int i = 0; i < *ptrCantidadMatrices+1; ++i) {
            if (i > 1) {
                do {
                    llaveK[i] = (rand() % 3) - 1;
                } while (*ptrValorLlave > 1 || *ptrValorLlave < -1);
                cout << "Valor para la llave[" << i << "]: " << llaveK[i];
            }else {
                cout << "Ingrese el valor para la llave[" << i << "]: ";
                cin >> *ptrValorLlave;
                llaveK[i] = *ptrValorLlave;
            }
        }
    }else{//Llenar de manera Manual
        // Llenar el array preguntando al usuario por los valores la cerradura X
        for (int i = 0; i < *ptrCantidadMatrices; ++i) {
            do {
                cout << "Ingrese el valor para cerradura[" << i+1 << "]: ";
                cin >> *ptrValorCerradura;
                cerraduraX[i] = *ptrValorCerradura;
            } while(*ptrValorCerradura % 2 == 0 || (*ptrValorCerradura < 3));
        }
        cout << "\n";
        // Llenar el array preguntando al usuario por los valores de la clave K
        for (int i = 0; i < *ptrCantidadMatrices+1; ++i) {
            if (i > 1) {
                do {
                    cout << "Ingrese el valor para la llave[" << i+1 << "]: ";
                    cin >> *ptrValorLlave;
                    llaveK[i] = *ptrValorLlave;
                } while (*ptrValorLlave > 1 || *ptrValorLlave < -1);
            }else {
                cout << "Ingrese el valor para la llave[" << i << "]: ";
                cin >> *ptrValorLlave;
                llaveK[i] = *ptrValorLlave;
            }

        }
    }

    llaveYCerrradura[0] = cerraduraX;
    llaveYCerrradura[1] = llaveK;
    return llaveYCerrradura;

}

#include <iostream>
#include "crearReglaK.h"

using namespace std;

int* llenaLLave(int* tamanioLlave){

    int valorLlave;
    int *llaveK = new int[*tamanioLlave];
    int *ptrValorLlave = &valorLlave;

        // Llenar el array preguntando al usuario por los valores de la clave K
        for (int i = 0; i < *tamanioLlave; ++i) {
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


    return llaveK;

}

#include <iostream>
#include "crearReglaK.h"

using namespace std;

int* llenaLLave(int* tamanioLlave){

    int valorLlave;
    int *llaveK = new int[*tamanioLlave];
    int *ptrValorLlave = &valorLlave;

    // Llenar el arreglo llave preguntandole al usuario por los valores de la clave K
    for (int i = 0; i < *tamanioLlave; ++i) {
        if (i > 1) {
            do {
                //Los siguientes puestos definirar la configuración de la llave donde solo de puede colocar 0, 1 ó -1
                cout << "Ingrese el valor para la llave[" << i+1 << "]: ";
                cin >> *ptrValorLlave;
                llaveK[i] = *ptrValorLlave;
            } while (*ptrValorLlave > 1 || *ptrValorLlave < -1);
        }else {
            // los dos primeros puesto, seran la fila y la comuna el cual mas adelante se va a comparar
            cout << "Ingrese el valor para la llave[" << i << "]: ";
            cin >> *ptrValorLlave;
            llaveK[i] = *ptrValorLlave;
        }

    }


    return llaveK;

}

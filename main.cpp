#include <iostream>
#include <string>

#include "modulos/crearCerradura.h"
#include "modulos/crearReglaK.h"

using namespace std;

// Función para crear una matriz cuadrada dinámica  Punto 1


int main() {

    int tamanioLlave;
    int *ptrTamanioLlave = &tamanioLlave;

    // Preguntar tamaño de la llave (debe ser de 3 o más)
    do {
        cout << "Ingrese el tamaio de la llave (debe ser 3 o mas): ";
        cin >> *ptrTamanioLlave;
        if (*ptrTamanioLlave < 3){
            cout << "Por favor, ingrese un valor valido (3 o mas)." << endl;
        }
    } while (*ptrTamanioLlave < 3);
    int tamanioCerradura = tamanioLlave-1;
    int *ptrTamanioCerradura = &tamanioCerradura;

    int *llaveK = new int[*ptrTamanioLlave];
    int *cerraduraK = new int[*ptrTamanioCerradura];


    llaveK = llenaLLave(ptrTamanioLlave);
    cerraduraK = llenaCerradura(ptrTamanioCerradura, llaveK);
    cout << "\nLa llave x(";
    for (int i = 0; i < *ptrTamanioLlave; ++i) {
        cout << llaveK[i] << " "; // Usamos cout en lugar de std::cout
    }
    cout << ") Abrio con exito la cerradura K(";
    for (int i = 0; i < *ptrTamanioCerradura; ++i) {
        cout << cerraduraK[i] << " "; // Usamos cout en lugar de std::cout
    } bool finalizar = false;
    cout << ")" << endl;


    // Liberar la memoria de matrices
    delete[] cerraduraK;
    delete[] llaveK;
    return 0;
}

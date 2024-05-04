#include <iostream>
#include <string>

#include "modulos/crearCerradura.h"
#include "modulos/crearReglaK.h"

using namespace std;


int main() {

    int tamanioLlave;
    int *ptrTamanioLlave = &tamanioLlave;

    // Preguntar tamaño de la llave (debe ser de 3 o más)
    do {
        cout << "Ingrese el tamaio de la llave (debe ser 3 o mas): ";
        cin >> tamanioLlave;
        if (isdigit(tamanioLlave)) {
            cout << "Por favor, ingrese un numero (3 o mas):" << endl;
            *ptrTamanioLlave = 0;
        }else{
            if (*ptrTamanioLlave < 3){
                cout << "Por favor, ingrese un valor valido (3 o mas):" << endl;
            }
        }

    } while (*ptrTamanioLlave < 3);

    // Calcular el tamaño de la cerradura (llave - 1)
    int tamanioCerradura = tamanioLlave-1;
    int *ptrTamanioCerradura = &tamanioCerradura;

    // Crear arreglos dinámicos para la llave y la cerradura
    int *llaveK = new int[*ptrTamanioLlave];
    int *cerraduraK = new int[*ptrTamanioCerradura];

    // Llenar la llave con valores aleatorios (crearCerradura.h)
    llaveK = llenaLLave(ptrTamanioLlave);

    // Generar la cerradura usando la llave (crearReglaK.h)
    cerraduraK = llenaCerradura(ptrTamanioCerradura, llaveK);

    //Imprimir resultados
    cout << "\nLa llave x(";
    for (int i = 0; i < *ptrTamanioLlave; ++i) {
        cout << llaveK[i] << " "; // Imprimir llave
    }
    cout << ") Abrio con exito la cerradura K(";
    for (int i = 0; i < *ptrTamanioCerradura; ++i) {
        cout << cerraduraK[i] << " "; // Imprimir cerradura
    } bool finalizar = false;
    cout << ")" << endl;

    // Liberar la memoria de matrices
    delete[] cerraduraK;
    delete[] llaveK;
    return 0;
}

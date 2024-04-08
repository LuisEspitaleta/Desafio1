#include <iostream>

using namespace std;

// Función para crear una matriz cuadrada dinámica
int** crearMatrizCuadrada(int &tamano) {
    int** matriz = new int*[tamano]; // Reserva de memoria para las filas
    for (int i = 0; i < tamano; ++i) {
        matriz[i] = new int[tamano]; // Reserva de memoria para las columnas
        for (int j = 0; j < tamano; ++j) {
            matriz[i][j] = i * tamano + j + 1; // Llenado automática
        }
    }
    return matriz;
}

// Función para imprimir la matriz
void imprimirMatriz(int** matriz, int &tamano) {
    cout << "Matriz resultante:\n"; // Usamos cout en lugar de std::cout
    for (int i = 0; i < tamano; ++i) {
        for (int j = 0; j < tamano; ++j) {
            cout << matriz[i][j] << " "; // Usamos cout en lugar de std::cout
        }
        cout << "\n"; // Salto de linea
    }
}

int main() {
    int tamano;
    int *ptrTamano = &tamano;
    cout << "Ingrese el tamaio de la matriz cuadrada: ";
    cin >> *ptrTamano;

    // Crear la matriz llamando la funcion crearMatrizCuadrada()
    int** miMatriz = crearMatrizCuadrada(*ptrTamano);

    // Imprimir la matriz llamando la funcion imprimirMatriz()
    imprimirMatriz(miMatriz, *ptrTamano);

    // Liberar la memoria por fila
    for (int i = 0; i < *ptrTamano; ++i) {
        delete[] miMatriz[i];
    }
    delete[] miMatriz;

    return 0;
}

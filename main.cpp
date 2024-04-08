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
    for (int i = 0; i < tamano; ++i) {
        for (int j = 0; j < tamano; ++j) {
            cout << matriz[i][j] << " "; // Usamos cout en lugar de std::cout
        }
        cout << "\n"; // Salto de linea
    }
}

// Función para rotar la matriz en sentido horario (90 grados)
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

void liberarMemoria(int*** matriz, int &size, int* tamanos) {
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < tamanos[i]; ++j) {
            delete[] matriz[i][j];
        }
        delete[] matriz[i];
    }
    delete[] matriz;
}

int compararPosicionMatrices(int** matrizA, int** matrizB, int tamano, int i, int j) {
    // Verificar si la posición (i, j) de la matriz A es mayor que la de la matriz B
    if (matrizA[i][j] > matrizB[i][j]) {
        return 1; // Devolver 1 si matriz A es mayor
    }
    // Verificar si la posición (i, j) de la matriz A es menor que la de la matriz B
    else if (matrizA[i][j] < matrizB[i][j]) {
        return -1; // Devolver -1 si matriz A es menor
    }
    // Si ninguna de las condiciones anteriores se cumple, significa que las posiciones son iguales
    return 0;
}

int main() {

    int cantidadMatrices;
    int *ptrCantidadMatrices = &cantidadMatrices;
    cout << "Ingrese la cantidad de matrices que desea crear: ";
    cin >> *ptrCantidadMatrices;


    int*** arregloDeMatrices = new int**[*ptrCantidadMatrices];
    int* tamanos = new int[cantidadMatrices];

    int tamano;
    int *ptrTamano = &tamano;
    for (int i = 0; i < *ptrCantidadMatrices; ++i) {
        cout << "Ingrese el tamaio de la matriz cuadrada: ";
        cin >> *ptrTamano;
        tamanos[i] = *ptrTamano;

        cout << "Matriz " << i + 1 << ":\n";
        // Crear la matriz llamando la funcion crearMatrizCuadrada()
        int** miMatriz = crearMatrizCuadrada(*ptrTamano);
        arregloDeMatrices[i] = miMatriz;

        cout << "Matriz original:\n";
        // Imprimir la matriz llamando la funcion imprimirMatriz()
        imprimirMatriz(miMatriz, *ptrTamano);

        // Rotar la matriz y obtener la matriz rotada
        //int** matrizRotada = rotarMatrizCuadrada(miMatriz, *ptrTamano);
    }

    int x = 1;
    int y = 1;
    int resultado = compararPosicionMatrices(arregloDeMatrices[0], arregloDeMatrices[1], tamano, x, y);
    cout << "\nComparación en la posición (" << x << ", " << y << "): " << resultado << endl;


    // Liberar la memoria de matrices
    liberarMemoria(arregloDeMatrices, *ptrCantidadMatrices, tamanos);
    delete[] tamanos;
    return 0;
}

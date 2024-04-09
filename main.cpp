#include <iostream>

using namespace std;

// Función para crear una matriz cuadrada dinámica
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

int compararPosicionMatrices(int** matrizA, int** matrizB, int i, int j) {
    // Verificar si la posición (i, j) de la matriz A es mayor que la de la matriz B
    cout << "comparando " << matrizA[i][j] << " con " << matrizB[i][j] << endl;
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

    int tamanioLlave, tamanioCerradura;
    cout << "Ingrese El tamaño de la cerradura";
    cin >> tamanioCerradura;
    int *cerradura = new int[tamanioCerradura];

    // Llenar el array preguntando al usuario por los valores
    for (int i = 0; i < tamanioCerradura; ++i) {
        cout << "Ingrese el valor para cerradura[" << i << "]: ";
        cin >> cerradura[i];
    }
    int *llave[tamanioLlave];

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

    int x = 4;
    int y = 3;
    int condicion = -1;
    //int resultado = compararPosicionMatrices(arregloDeMatrices[0], arregloDeMatrices[1], x, y);

    int resultado;
    //int cerradura[4] = {5, 7, 5, 9};
    //int llave[5] = {4, 3, 1, 1, -1};
    bool finalizar = false;
    for (int j = 0; j < *ptrCantidadMatrices - 1; ++j) {
        int** matrizB = arregloDeMatrices[j+1];
        cout << "\n\nComparando matriz" << j+1 << " con matriz" << j+2 << endl;
        cout << "tamanio del arreglo B" << (j+1)  << " es " << tamanos[j+1] << endl;
        cout <<"la llavce es " << llave[j+2] << endl;
        for (int i = 0; i < 4; ++i) {
            int resultado = compararPosicionMatrices(arregloDeMatrices[j], matrizB, x, y);
            cout << "\nComparación 1 en la posición (" << x << ", " << y << "): " << resultado << endl;
            cout << "el tamanio B" << (j+1)  << " es " << tamanos[j+1] << endl;
            imprimirMatriz(matrizB, tamanos[j+1]);
            if (resultado != llave[j+2]) {
                matrizB = rotarMatrizCuadrada(matrizB, tamanos[j+1]);
            }else {
                break;
            }
            if (i == 3) {
                finalizar = true;
            }
        }
        if (finalizar) {
            break;
        }
    }

    // Liberar la memoria de matrices
    liberarMemoria(arregloDeMatrices, *ptrCantidadMatrices, tamanos);
    delete[] tamanos;
    return 0;
}

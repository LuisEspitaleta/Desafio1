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

int compararPosicionMatrices(int** matrizA, int** matrizB, int *llave) {
    // Verificar si la posición (i, j) de la matriz A es mayor que la de la matriz B
    cout << "comparando " << matrizA[llave[0]][llave[1]] << " con " << matrizB[llave[0]][llave[1]] << endl;
    if (matrizA[llave[0]][llave[1]] > matrizB[llave[0]][llave[1]]) {
        return 1; // Devolver 1 si matriz A es mayor
    }
    // Verificar si la posición (i, j) de la matriz A es menor que la de la matriz B
    else if (matrizA[llave[0]][llave[1]] < matrizB[llave[0]][llave[1]]) {
        return -1; // Devolver -1 si matriz A es menor
    }
    // Si ninguna de las condiciones anteriores se cumple, significa que las posiciones son iguales
    return 0;
}

int main() {

    int tamanioLlave, tamanioCerradura, valorCerradura, valorLlave;
    int *ptrValorCerradura = &valorCerradura;
    int *ptrValorLlave = &valorLlave;
    int cantidadMatrices;
    int *ptrCantidadMatrices = &cantidadMatrices;
    cout << "Ingrese El tamaio de la cerradura:";
    cin >> *ptrCantidadMatrices;
    int *cerradura = new int[*ptrCantidadMatrices];

    // Llenar el array preguntando al usuario por los valores la cerradura X
    for (int i = 0; i < *ptrCantidadMatrices; ++i) {
        do {
            cout << "Ingrese el valor para cerradura[" << i+1 << "]: ";
            cin >> *ptrValorCerradura;
            cerradura[i] = *ptrValorCerradura;
        } while(*ptrValorCerradura % 2 == 0 || (*ptrValorCerradura < 3));
    }
    cout << "\n";
    int *llave = new int[*ptrCantidadMatrices+1];
    // Llenar el array preguntando al usuario por los valores de la clave K
    for (int i = 0; i < *ptrCantidadMatrices+1; ++i) {
        if (i > 1) {
            do {
                cout << "Ingrese el valor para la llave[" << i+1 << "]: ";
                cin >> *ptrValorLlave;
                llave[i] = *ptrValorLlave;
            } while (*ptrValorLlave > 1 || *ptrValorLlave < -1);
        }else {
            cout << "Ingrese el valor para la llave[" << i << "]: ";
            cin >> *ptrValorLlave;
            llave[i] = *ptrValorLlave;
        }

    }
    cout << "\n";

    int*** arregloDeMatrices = new int**[*ptrCantidadMatrices];

    for (int i = 0; i < *ptrCantidadMatrices; ++i) {
        cout << "Matriz " << i + 1 << ":\n";
        // Crear la matriz llamando la funcion crearMatrizCuadrada()
        int** miMatriz = crearMatrizCuadrada(cerradura[i]);
        arregloDeMatrices[i] = miMatriz;

        cout << "Matriz original:\n";
        // Imprimir la matriz llamando la funcion imprimirMatriz()
        imprimirMatriz(miMatriz, cerradura[i]);

        // Rotar la matriz y obtener la matriz rotada
        //int** matrizRotada = rotarMatrizCuadrada(miMatriz, *ptrTamano);
    }

    int x = 4;
    int y = 3;
    int condicion = -1;

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
            break;
        }
    }

    // Liberar la memoria de matrices
    liberarMemoria(arregloDeMatrices, *ptrCantidadMatrices, cerradura);
    delete[] cerradura;
    delete[] llave;
    return 0;
}

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

// Función para crear una matriz cuadrada dinámica  Punto 1
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

// Función para rotar la matriz en sentido horario (90 grados) Punto 2
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

int compararPosicionMatrices(int** matrizA, int** matrizB, int* llave) {
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

int main() {

    int tamanioLlave, tamanioCerradura, opcion;
    int cantidadMatrices;
    int *ptrCantidadMatrices = &cantidadMatrices;
    int *ptrOpcion = &opcion;
    int** arrayOpen = new int*[2];

    // Preguntar tamaño de la cerradura (debe ser de 3 o más)
    do {
        cout << "Ingrese el tamaio de la cerradura (debe ser 3 o mas): ";
        cin >> *ptrCantidadMatrices;
    } while (*ptrCantidadMatrices < 3);
    int *cerradura = new int[*ptrCantidadMatrices];
    int *llave = new int[*ptrCantidadMatrices+1];
    do {
        cout << "Desea generar los datos aleatoriamente? Si(1) No(2): ";
        cin >> *ptrOpcion;
    } while (*ptrOpcion != 1 && *ptrOpcion != 2);

    arrayOpen = llenaLLaveCerradura(ptrCantidadMatrices, ptrOpcion);
    cerradura = arrayOpen[0];
    llave = arrayOpen[1];

    cout << "\n";

    int*** arregloDeMatrices = new int**[*ptrCantidadMatrices];

    for (int i = 0; i < *ptrCantidadMatrices; ++i) {
        cout << "Matriz " << i + 1 << ":\n";
        // Crear la matriz llamando la funcion crearMatrizCuadrada()
        int** miMatriz = crearMatrizCuadrada(cerradura[i]);
        arregloDeMatrices[i] = miMatriz;
        //up

        cout << "Matriz original:\n";
        // Imprimir la matriz llamando la funcion imprimirMatriz()
        imprimirMatriz(miMatriz, cerradura[i]);

        // Rotar la matriz y obtener la matriz rotada
        //int** matrizRotada = rotarMatrizCuadrada(miMatriz, *ptrTamano);
    }

    int x = llave[0];
    int y = llave[1];

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
            cout << "\nLa llave x(";
            for (int i = 0; i < *ptrCantidadMatrices+1; ++i) {
                cout << llave[i] << ",";
            }
            cout << ") no abre la cerradura K(";
            for (int i = 0; i < *ptrCantidadMatrices; ++i) {
                cout << cerradura[i] << ",";
            }
            cout << ")\n";
            break;
        }
    }

    if (!finalizar) {
        cout << "\nLa llave x(";
        for (int i = 0; i < *ptrCantidadMatrices+1; ++i) {
            cout << llave[i] << ",";
        }
        cout << ") Abrio con exito la cerradura K(";
        for (int i = 0; i < *ptrCantidadMatrices; ++i) {
            cout << cerradura[i] << ",";
        }
        cout << ")\n";
    }

    // Liberar la memoria de matrices
    liberarMemoria(arregloDeMatrices, *ptrCantidadMatrices, cerradura);
    delete[] cerradura;
    delete[] llave;
    return 0;
}

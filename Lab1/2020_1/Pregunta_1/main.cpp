#include <iostream>
#include <iomanip>

using namespace std;

// Variable global con un caso de prueba predefinido
int matriz[5][4]{
    {1, 2, 3, 4},
    {5, 6, 7, 8},
    {9, 10, 11, 12},
    {13, 14, 15, 16},
    {17, 18, 19, 20}
};
int numFil = 5, numCol = 4;

int matrizSobre[5][4]{
    {0, 0, 0, 0},
    {0, 0, 0, 0},
    {0, 0, 0, 0},
    {0, 0, 0, 0},
    {0, 0, 0, 0}
};

void recorrerBorde(int inicioFila, int finFila, int inicioColumna, int finColumna) {
    // Caso base: si el borde es inexistente
    if (inicioFila > finFila or inicioColumna > finColumna) {
        return;
    }

    // Recorrer la fila superior (de izquierda a derecha)
    for (int j = inicioColumna; j <= finColumna; j++) {
        cout << matriz[inicioFila][j] << " ";
    }
    cout << endl;

    // Recorrer la columna derecha (de arriba hacia abajo)
    for (int i = inicioFila + 1; i <= finFila; i++) {
        cout << matriz[i][finColumna] << " ";
    }

    cout << endl;
    // Recorrer la fila inferior (de derecha a izquierda), si hay más de una fila
    if (inicioFila < finFila) {
        for (int j = finColumna - 1; j >= inicioColumna; j--) {
            cout << matriz[finFila][j] << " ";
        }
    }
    cout << endl;

    // Recorrer la columna izquierda (de abajo hacia arriba), si hay más de una columna
    if (inicioColumna < finColumna) {
        for (int i = finFila - 1; i > inicioFila; i--) {
            cout << matriz[i][inicioColumna] << " ";
        }
    }
    cout << endl;
    // Llamada recursiva para el siguiente borde interno
    recorrerBorde(inicioFila + 1, finFila - 1, inicioColumna + 1, finColumna - 1);
}

int main() {
    cout << "Recorrido de la máquina cargadora: (Cada salto de linea es un cambio de dirección) " << endl;
    recorrerBorde(0, numFil - 1, 0, numCol - 1);
    return 0;
}




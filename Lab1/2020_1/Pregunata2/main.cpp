#include <iostream>
#include <iomanip>

using namespace std;

bool distribuirUbicaciones(int matriz[][5], int &productos, int filaFinal, int columna, int filaInici, int maxUbi, int minUbi, int &ubicaciones) {

    if (maxUbi < minUbi) {
        return false; // la condicion no hace posible la 
    }
    
    if (productos <= 0) {
        return true; // si llega aqui y ya no hay productos entonces devuelve (true)
    }
    int cant = 0;
    while (cant < maxUbi and productos > 0) {
        if (matriz[filaInici][cant] == 0 and productos > 0) {
            matriz[filaInici][cant] = 5;
            productos--;
            ubicaciones++;
            if (productos <= 0) break;
        }
        if (filaInici != filaFinal)
            if (matriz[filaFinal][cant] == 0) {
                matriz[filaFinal][cant] = 5;
                productos--;
                ubicaciones++;
                if (productos <= 0) break;
            }
        cant++;
    }
    return distribuirUbicaciones(matriz, productos, filaFinal - 1, columna, filaInici + 1, maxUbi - 1, minUbi, ubicaciones);
}

int main(int argc, char** argv) {
    int n = 5; //columnas
    int m = 6; //Filas
    int max = 4, min = 1, productos = 24;
    int matriz[6][5] = {
        {0, 0, 0, 1, 0},
        {0, 0, 0, 0, 0},
        {1, 0, 0, 0, 0},
        {0, 1, 0, 0, 0},
        {0, 0, 0, 0, 0},
        {0, 1, 0, 0, 0}
    };
    int ubicaciones = 0;
    cout << "Se pueden ubicar los productos: ";
    if (distribuirUbicaciones(matriz, productos, m - 1, n, 0, max, min, ubicaciones)) {
        cout << "SII mi rey" << endl;
    }else cout<< "No mi king"<<endl;
    cout <<"Ubicaciones: "<<ubicaciones<<endl;
    // Imprimir la matriz resultante
    cout << "Distribución de ubicaciones:" << endl;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cout << matriz[i][j] << " ";
        }
        cout << endl;
    }
}
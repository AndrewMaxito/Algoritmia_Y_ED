
/* 
 * File:   main.cpp
 * Author: andre
 *
 * Created on 5 de septiembre de 2024, 05:57 PM
 */

#include <iostream>
#include <iomanip>

using namespace std;
int movimientos[4][2]{
    {-1, 0}, //arriba
    {1, 0}, //abajo
    {0, -1}, //izquierda
    {0, 1} //derecha
};

void SondaRobot(int mov, int posX, int posY, int filas, int columnas,
        int &unidadesEcncontradas, int tablero[][6]) {
    if (posX >= filas or posX < 0){
        for (int i = 0; i < filas; i++) {
            unidadesEcncontradas += tablero[i][posY];
        }
        return;
    }
    if (posY >= columnas or posY < 0){
        for (int i = 0; i < columnas; i++) {
            unidadesEcncontradas += tablero[posX][i];
        }
        return;
    }

    int nX, nY;
    if (mov == 3 or mov == 2) { //izquierda o drecha
        for (int i = 0; i < filas; i++) {
            unidadesEcncontradas += tablero[i][posY];
        }

        unidadesEcncontradas -= tablero[posX][posY];
        nX = posX;
        nY = posY + movimientos[mov][1];
    } 
    
    if (mov == 0 or mov == 1) {
        for (int i = 0; i < columnas; i++) {
            unidadesEcncontradas += tablero[posX][i];
        }
        unidadesEcncontradas -= tablero[posX][posY];
        nX = posX + movimientos[mov][0];
        nY = posY;
    }
    return SondaRobot(mov, nX, nY, filas, columnas, unidadesEcncontradas, tablero);
}

int main(int argc, char** argv) {
    int tablero[6][6]{
        {0, 0, 0, 1, 0, 1},
        {0, 0, 1, 0, 0, 0},
        {0, 1, 0, 0, 0, 1},
        {1, 0, 0, 0, 0, 0},
        {0, 1, 0, 0, 0, 0},
        {0, 0, 0, 0, 1, 0}
    };
    int unidadesEcncontradas = 0;
    int posX = 5, posY = 5;
    int filas = 6, columnas = 6;
    int mov = 1; //derecha
    SondaRobot(mov, posX, posY, filas, columnas, unidadesEcncontradas, tablero);
    cout << unidadesEcncontradas;
    return 0;
}


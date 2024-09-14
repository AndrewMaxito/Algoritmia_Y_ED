

/* 
 * File:   main.cpp
 * Author: andre
 *
 * Created on 5 de septiembre de 2024, 03:57 PM
 */

#include <iomanip>
#include <iostream>
#include <cmath>

using namespace std;
#define MAX 10

int Robot(int x, int y, int n, int m, int tablero[][MAX]) {
    if (x == n-1 and y == m-1 ) {
        return tablero[x][y];
    }
    int sumaDerecha=-999,sumaAbajo=-999,total;
    //Derecha
    if (y+1 <= m-1) {
        sumaDerecha = Robot(x, y+1, n, m, tablero); 
    }
    //abajo
    if (x+1 <= n-1) {
        sumaAbajo = Robot(x+1, y, n, m, tablero); 
    }
    if (sumaAbajo > sumaDerecha){
        total = tablero[x][y] + sumaAbajo;
    }else total = tablero[x][y] + sumaDerecha;
    return total;
}

int main(int argc, char** argv) {
    int n = 3, m = 4;
    int tablero[MAX][MAX]{
        {1, 2, 3, 9},
        {5, -1, -1, -1},
        {-4, 2, 1, 1}
    };
    cout << Robot(0, 0, n, m, tablero) << endl;

    return 0;
}


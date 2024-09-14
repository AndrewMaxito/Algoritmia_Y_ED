/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: andre
 *
 * Created on 12 de septiembre de 2024, 04:14 PM
 */

#include <iostream>
#include <iomanip>

using namespace std;

int matrizProd[10][9]{
    {1, 2, 3, 4, 5, 6, 7, 8, 0},
    {1, 2, 3, 4, 5, 6, 7, 8, 1},
    {1, 2, 3, 4, 5, 6, 7, 8, 2},
    {1, 2, 3, 4, 5, 6, 7, 8, 3},
    {1, 2, 3, 4, 5, 6, 7, 8, 4},
    {1, 2, 3, 4, 5, 6, 7, 8, 5},
    {1, 2, 3, 4, 5, 6, 7, 8, 6},
    {1, 2, 3, 4, 5, 6, 7, 8, 7},
    {1, 2, 3, 4, 5, 6, 7, 8, 8},
    {1, 2, 3, 4, 5, 6, 7, 8, 9},
};

void buscaPintaMayor(int Fx, int y, int P) {

    for (int i = y + 1; i < P; i++) {
        if (matrizProd[Fx][y] < matrizProd[Fx][i]) {
            int auxCod = matrizProd[Fx][y];
            matrizProd[Fx][y] = matrizProd[Fx][i];
            matrizProd[Fx][i] = auxCod;
        }
    }
    cout << matrizProd[Fx][y] << " ";
}

void robotPinta(int M, int I, int N, int D, int P, int Fx, int &diasX, int capPint, bool bandera) { //Fx = fila actual
    if (capPint < N) return;
    if (diasX > D) return;

    if (bandera == false) {
        for (int y = 0; y < P and y < capPint; y++) {
            buscaPintaMayor(Fx, y, P);
        }
        diasX++;
        cout << endl;
        if (capPint == M) {
            Fx++;
            bandera = true;
        } else robotPinta(M, I, N, D, P, Fx + 1, diasX, capPint + 1, bandera);

    }
    if (bandera == true) {
        for (int y = 0; y < P and y < capPint; y++) {
            buscaPintaMayor(Fx, y, P);
        }
        cout << endl;
        capPint--;
        diasX++;
        robotPinta(M, I, N, D, P, Fx + 1, diasX, capPint, bandera);
    }
}

int main(int argc, char** argv) {
    int D = 10, P = 9; //filas = D -> columnas = P
    int M = 8, I = 6, N = 4;
    int diasX = 0;
    bool bandera = false;
    robotPinta(M, I, N, D, P, 0, diasX, I, bandera);
    cout << "El rodillo dura  " << diasX << endl;
    return 0;
}



/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: andre
 *
 * Created on 13 de septiembre de 2024, 12:49 PM
 */

#include <iostream>
#include <iomanip>

using namespace std;

int CampoMinado[9][5]{
    {0, 0, 0, 0, 1},
    {0, 0, 0, 0, 0},
    {0, 0, 1, 0, 0},
    {0, 0, 0, 0, 0},
    {0, 1, 1, 0, 1},
    {0, 1, 1, 0, 1},
    {1, 1, 0, 1, 0},
    {0, 0, 0, 1, 0},
    {1, 0, 0, 0, 0},
};
//Derecha 0,1
//abajo 1,0
//daigonal 1,1


//MOVIMIENTOS DE BUSQUEDA
int movRas[8][2]{
    {-1, -1},
    {-1, 0},
    {-1, 1},
    {0, 1},
    {1, 1},
    {1, 0},
    {1, -1},
    {0, -1}
};
//Derecha 0,1
//Izquierda 0-1
//arriba -1,0
//abajo 1,0
//daigonal 1,1

void detectaMinas(int fil, int col, int xn, int yn) {
    for (int i = 0; i < 8; i++) {
        int X = xn + movRas[i][0];
        int Y = yn + movRas[i][1];

        if (X <= fil - 1 and Y <= col - 1 and X >= 0 and Y >= 0) {
            if (CampoMinado[X][Y] == 1) {
                cout << "Encontre  mina en: " << '(' << X << ',' << Y << ')' << "  corre" << endl;
            }
        }
    }
}

int robotDetector(int fil, int col, int xn, int yn, int pasos) {
    /*Caso base*/
    //acaba si llega al final

    if (xn == fil - 1 and yn == col - 1) return pasos;
    if (CampoMinado[xn][yn] == 1) return -1; //si choca con una mina devuelve -1
    int cantDerecha = -1, cantAbajo = -1, cantDiagonal = -1, valorMin;
    detectaMinas(fil, col, xn, yn);
    //Derecha
    if (yn + 1 <= col - 1) {
        cantDerecha = robotDetector(fil, col, xn, yn + 1, pasos + 1);
    }
    //Abajo
    if (xn + 1 <= fil - 1) {
        cantAbajo = robotDetector(fil, col, xn + 1, yn, pasos + 1);
    }
    //diagonla
    if (xn + 1 <= fil - 1 and yn + 1 <= col - 1) {
        cantDiagonal = robotDetector(fil, col, xn + 1, yn + 1, pasos + 1);
    }


    valorMin = -1;

    if (cantDerecha != -1 and (valorMin == -1 or cantDerecha < valorMin)) {
        valorMin = cantDerecha;
    }
    if (cantAbajo != -1 and (valorMin == -1 or cantAbajo < valorMin)) {
        valorMin = cantAbajo;
    }
    if (cantDiagonal != -1 and (valorMin == -1 or cantDiagonal < valorMin)) {
        valorMin = cantDiagonal;
    }
    return valorMin;
}

int main(int argc, char** argv) {
    int fil = 9, col = 5;
    int xn = 0, yn = 0; //pos actual
    //asumiendo que siempre quiero llegar a fil-1,col-1
    int cantPasos = robotDetector(fil, col, xn, yn, 0);
    if (cantPasos != -1) {
        cout<<"La cantidad de pasos "<<cantPasos<<endl;
    }else{
        cout<<"No existe solucion posible"<<endl;
    }


    return 0;
}
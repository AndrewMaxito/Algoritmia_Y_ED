/* 
 * File:   main.cpp
 * Author: andre
 *
 * Created on 11 de octubre de 2024, 16:36
 */

#include <iostream>
#include <iomanip>

using namespace std;
#include "Pila.h"
#include "funcionesPila.h"
#include "funcionesLista.h"
#define N 7

int red[N][N] = {
    {0  , 0, 0 , 0 , 0, 0  , 0},
    {10 , 0, 20, 30, 0, 20 , 40},
    {0  , 0, 0 , 0 , 0, 100, 0},
    {0  , 0, 0 , 0 , 0, 80 , 0},
    {50 ,10, 5 , 10, 0, 100, 4},
    {100, 0, 0 , 0 , 0, 0  , 0},
    {0  , 0, 0 , 0 , 0, 0  , 0}
};


int buscarSkynerd(int &posSkay){
    struct Pila pilaRecMatr;
    construir(pilaRecMatr);
    for (int i = 0; i < N; i++) apilar(pilaRecMatr, i);
    
    //valor inicial (asumiendo que la matriz sea de alemos 1 elemneto 1x1-> (exista)
    int posX = desapilar(pilaRecMatr);
    while (!esPilaVacia(pilaRecMatr)) { 
        int posY = desapilar(pilaRecMatr);
        if (red[posX][posY] == 0){
            posX = posY;
        }
    }  
    
    //evaluacion en cruz (+)
    int cantPaquetesEnvi=0;
    for (int i = 0; i < N; i++) {
        if (i!=posX and (red[i][posX] != 0 or red[posX][i] == 0)){
            return -1;
        }
        if (cantPaquetesEnvi < red[posX][i] ) cantPaquetesEnvi = red[posX][i] ;
    }
    posSkay = posX+1;
    return cantPaquetesEnvi;
}


int main(int argc, char** argv) {
    int posSkay;
    int cantPaquetesEnvi = buscarSkynerd(posSkay);
    
    if (cantPaquetesEnvi != -1){
        cout<<"Skynerd ha sido detectado en el servidor "<<posSkay<<endl;
        cout<<"Maximo de paquetes enviados por Skynerd "<<cantPaquetesEnvi<<endl;
    }else{
        cout<< "Skynerd no esta en la red"<<endl;
    }
    return 0;
}


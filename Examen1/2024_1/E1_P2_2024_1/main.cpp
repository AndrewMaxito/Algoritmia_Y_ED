/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: david
 *
 * Created on 7 de octubre de 2024, 12:20
 */

#include <cstdlib>
#include <iostream>
#include "Pila.h"
#include "funcionesPila.h"
#define N 10
using namespace std;

/*
 * 
 */

void muestraMovimientos(char comandos[N],int size){
    Pila pila;
    construir(pila);
    for (int i=0; i<=size; i++){
        apilar(pila,i+1);
        if (i==size || comandos[i]=='S'){
            while (!esPilaVacia(pila)){
                cout << desapilar(pila) << " ";
            }
        }
    }
    cout << endl;
}

int main(int argc, char** argv) {
    char comandos[N] = {'S','B','S','B','B','S','S'};
    int size = 7;
    muestraMovimientos(comandos,size);
    char comandos2[N] = {'B','B','B','S','B'};
    size = 5;
    muestraMovimientos(comandos2,size);
    char comandos3[N] = {'B','B','B','B','B'};
    size = 5;
    muestraMovimientos(comandos3,size);
    return 0;
}


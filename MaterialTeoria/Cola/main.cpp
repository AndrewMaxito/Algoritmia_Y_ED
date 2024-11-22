/* 
 * File:   main.cpp
 * Author: Ana Roncal
 *
 * Created on 1 de setiembre de 2024, 22:58
 */

#include <iostream>
#include "Cola.h"
#include "funcionesCola.h"
using namespace std;

/*
 * IMPLEMENTACIÓN DE UNA COLA
 * USANDO PUNTEROS CABEZA Y COLA
 * ALGORITMIA Y ESTRUCTURA DE DATOS 2024-2
 */
int main(int argc, char** argv) {

    struct Cola cola;
   
    construir(cola);

    /*Encolamos elementos en la Cola*/
    encolar(cola, 4);
    encolar(cola, 3);
    encolar(cola, 12);
    encolar(cola, 2);
    imprime(cola);
    /*Desencolamos elementos de la cola*/
    while(not esColaVacia(cola))
        cout<<"Desencolando: "<<desencolar(cola)<<endl;
    imprime(cola);
    destruirCola(cola);
    
    return 0;
}


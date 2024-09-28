/* 
 * File:   main.cpp
 * Author: ANA RONCAL
 * Created on 21 de agosto de 2023, 11:57 AM
 */

#include <iostream>
#include "Pila.h"

using namespace std;
#include "funcionesPila.h"

/*
 * IMPLEMENTACIÓN DE UNA PILA
 * ALGORITMIA Y ESTRUCTURA DE DATOS 2024-1
 */
int main(int argc, char** argv) {

    struct Pila pila;
    construir(pila);
    /*Apilamos elementos en la pila*/
    apilar(pila, 1);
    apilar(pila, 3);
    apilar(pila, 2);
    apilar(pila, 4);
    imprimir(pila);
    
    /*Desapilamos elementos en la pila*/
    while(not esPilaVacia(pila)){
        cout<<"Desapilando: "<<desapilar(pila)<<endl;
    }
    imprimir(pila);
    return 0;
}


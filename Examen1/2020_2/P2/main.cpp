/* 
 * File:   main.cpp
 * Author: andre
 *
 * Created on 11 de octubre de 2024, 13:12
 */

#include <iostream>
#include <iomanip>

using namespace std;
#include "Nodo.h"
#include "Lista.h"
#include "Pila.h"
#include "funcionesLista.h"
#include "funcionesPila.h"

int main(int argc, char** argv) {
    int arrPerCont[8]{10, 20, 15, 10, 12, 10, 13, 18};
    int cantDias = 8;


    int arregloGurdado[cantDias]{};
    struct Pila pilaAux;
    construir(pilaAux);


    for (int i = 0; i < cantDias; i++) {
        int valorActual = arrPerCont[i];
        int cantAcumulada =0;
        while (esPilaVacia(pilaAux) == false and cima(pilaAux) <= valorActual) {
            cantAcumulada += ( 1 + pilaAux.lista.cabeza->cant);
            int basura = desapilar(pilaAux); //quitarlo
        }
        apilar(pilaAux,valorActual,cantAcumulada);
        arregloGurdado[i]=cantAcumulada;
    }
    
    
    for (int i = 0; i < cantDias; i++) {
        if (i!=0 ) cout<<',';
        cout <<arregloGurdado[i];
    }
    return 0;
}




/* 
 * File:   main.cpp
 * Author: Andrew Max
 *
 * Created on 30 de setiembre de 2024, 19:31
 */

#include <iostream>
#include <iomanip>

using namespace std;
#include "Pila.h"
#include "funcionesPila.h"

/*
 * 
 */

void ordenarPila(struct Pila &pilaPrin) {
    //Pila auxliar
    struct Pila aux;
    construir(aux);

    //asumiendo que tu pila siempre tiene almneos un elemnto XD si es una pila vacia pon el if y return
    int cantidad = longitud(pilaPrin);
    for (cantidad; cantidad != 0; cantidad--) {
        int max = desapilar(pilaPrin); //mano (asume que el primero que agarras es el mayor por el momento)
        
        
        for (int i = 0; i < cantidad-1; i++) {
            int valor = desapilar(pilaPrin);
            if (valor > max) {
                apilar(aux, max);
                max = valor;
            } else {
                apilar(aux, valor);
            }
        }
        apilar(pilaPrin, max); //aseguras el poner el valor mas alto al principio

        //devolver todo de la pila aux
        while (!esPilaVacia(aux)) {
            apilar(pilaPrin, desapilar(aux));
        }
    }
}

int main(int argc, char** argv) {
    struct Pila pilaPrin;
    construir(pilaPrin);
    apilar(pilaPrin, 1);
    apilar(pilaPrin, 4);
//    apilar(pilaPrin, 3);
//    apilar(pilaPrin, 7);
//    apilar(pilaPrin, 2);
    cout << "Pila inicial: " << endl;
    imprimir(pilaPrin);
    ordenarPila(pilaPrin);
    cout << "Pila Final: " << endl;
    imprimir(pilaPrin);

    return 0;
}


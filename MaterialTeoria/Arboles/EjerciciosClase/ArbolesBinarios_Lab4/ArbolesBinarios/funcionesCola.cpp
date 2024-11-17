/* 
 * File:   funcionesCola.cpp
 * Author: ANA RONCAL
 * Created on 18 de abril de 2024, 10:28 AM
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>

#include "Cola.h"
#include "funcionesCola.h"
#include "funcionesLista.h"
using namespace std;

/*constructor de Cola*/
void construir(struct Cola & cola){
    construir(cola.lista);
}

bool esColaVacia(const struct Cola & cola){
    return esListaVacia(cola.lista);
}

void encolar(struct Cola & cola, struct NodoArbol *  elemento){
    insertarAlFinal(cola.lista, elemento);
}

struct NodoArbol *  desencolar(struct Cola & cola){
    if(esColaVacia(cola)){
        cout<<"La cola está vacía no se puede desencolar"<<endl;
        exit(1);
    }
    struct NodoArbol *  elemento = retornaCabeza(cola.lista);
    eliminaCabeza(cola.lista);
    return elemento;
}

void imprimir(const struct Cola & cola){
    imprimir(cola.lista);
}

void destruirCola(struct Cola & cola){
    destruir(cola.lista);
}
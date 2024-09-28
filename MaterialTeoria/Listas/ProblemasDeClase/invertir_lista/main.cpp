/* 
 * File:   main.cpp
 * Author: Ana Roncal
 *
 * Created on 1 de setiembre de 2024, 20:42
 */

#include <iostream>
using namespace std;
#include "Lista.h"
#include "funciones.h"

void invierte(struct Lista &ptrlista) {
    struct Nodo *prec, *pant, *paux;//paux sera el puntero siguiente
    int n = ptrlista.longitud;

    prec = ptrlista.cabeza;
    paux = prec->siguiente;//asumiendo que no es una lista vacia (sino se deberia cambiar)
    for (int i = 1; i < n; i++) {
        pant = prec;
        prec = paux;
        paux = prec->siguiente;
        prec->siguiente = pant;
        if (i == 1) pant->siguiente = nullptr;
    }
    ptrlista.cabeza = prec;
}


//Inversion iterativa
struct Nodo * recorre(Nodo *ptrActual) {
    if (ptrActual == nullptr) return nullptr;//En caso sea lista vacia
    if (ptrActual->siguiente == nullptr) return ptrActual;//hará que llegue al ultimo puntero
    Nodo*nodoFinal = recorre(ptrActual->siguiente);
    Nodo *ptrSig = ptrActual->siguiente;  
    ptrSig->siguiente = ptrActual; //el siguiente se le asigna al actual 
    ptrActual->siguiente = nullptr; // el actual ahora se le pone en nullptr
    return nodoFinal; //devuelve el ultimo nodo siempre (una vez que se haya encontrado)
}

void invierterec(struct Lista &ptrlista) {
    Nodo *ptr = recorre(ptrlista.cabeza);
    ptrlista.cabeza = ptr;//asigna la direccion de la cabeza al ultimo nodo de la lista
}

int main(int argc, char** argv) {

    struct Lista lista;
    /*Construimos la lista, al inicio la lista esta vacía*/
    construir(lista);
    insertarAlInicio(lista, 20);
    insertarAlInicio(lista, 16);
    insertarAlInicio(lista, 12);
    insertarAlInicio(lista, 15);
    insertarAlInicio(lista, 10);
    imprime(lista);
    invierterec(lista);
    imprime(lista);

    return 0;
}


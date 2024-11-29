

/* 
 * File:   main.cpp
 * Author: andre
 *
 * Created on 28 de noviembre de 2024, 16:02
 */

#include <iostream>
#include <iomanip>

#include "ArbolB.h"
#include "funcionesAB.h"
using namespace std;

void inserta_izq(NodoArbol *tad, NodoGen dato) {
    NodoArbol* nuevo = crearNuevoNodo(nullptr, dato, nullptr);
    tad->izquierda = nuevo;
}

void inserta_der(NodoArbol *tad, NodoGen dato) {
    NodoArbol* nuevo = crearNuevoNodo(nullptr, dato, nullptr);
    tad->derecha = nuevo;
}

void insertanivel(NodoArbol* narbol, int *paq,
        int ini, int n) {
    NodoGen temp;

    if (ini == n) return;
    //izquierda
    temp.cromo = 0;
    temp.cantidad = paq[ini];
    inserta_izq(narbol, temp);
    insertanivel(narbol->izquierda, paq, ini + 1, n);

    //derecha
    temp.cromo = 1;
    temp.cantidad = paq[ini];
    inserta_der(narbol, temp);
    insertanivel(narbol->derecha, paq, ini + 1, n);

}

void creaArbolCromo(ArbolBinario &arbol, int *paq, int n) {

    NodoGen temp;
    //Primer Nodo
    temp.cromo = 0;
    temp.cantidad = 0;
    plantarArbolBinario(arbol, nullptr, temp, nullptr);
    //El resto de valores
    insertanivel(arbol.raiz, paq, 0, n);
}

void calculaCantidadPosibilidades(const NodoArbol *tad, int pesoBuscado,
        int pesoParcial, int &cantidadSolu) {
//    if (tad == nullptr)return ;
    
    int nuevoPesoParcial = pesoParcial + tad->elemento.cantidad*tad->elemento.cromo;
    if (tad->izquierda == nullptr and tad->derecha == nullptr) { //es una hoja
        if (nuevoPesoParcial == pesoBuscado) cantidadSolu++;
    } else {
        //Izquierda
        calculaCantidadPosibilidades(tad->izquierda, pesoBuscado, nuevoPesoParcial, cantidadSolu);
        //Derecha
        calculaCantidadPosibilidades(tad->derecha, pesoBuscado, nuevoPesoParcial, cantidadSolu);
    }
}

int main(int argc, char** argv) {
    //A)Implemenatacion Arbol Cromosoma
    ArbolBinario arbol;
    int paq[] = {10, 50, 20, 30, 40};
    //    int paq[] ={10,50};
    int n = sizeof (paq) / sizeof (paq[0]);
    construir(arbol);
    creaArbolCromo(arbol, paq, n);
    //B)
    int pesoBuscado = 70;
    int pesoParcial = 0;
    int cantidadSolu = 0;
    calculaCantidadPosibilidades(arbol.raiz, pesoBuscado, pesoParcial, cantidadSolu);
    cout << cantidadSolu << endl;



    return 0;
}


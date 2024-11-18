
/* 
 * File:   main.cpp
 * Author: andre
 *
 * Created on 18 de noviembre de 2024, 14:42
 */

#include <iostream>
#include <iomanip>

using namespace std;
#include "ArbolB.h"
#include "funcionesAB.h"
#include "Servidor.h"
#include "Pila.h"
#include "funcionesPila.h"

bool evaluaSopsechoso(NodoArbol *izquierda, NodoArbol *derecha) {
    if (derecha != nullptr) {
        if (derecha->elemento.letra == 'S' and derecha->elemento.velocidad == 200) {
            cout << "En el hijo derecho de ";
            return true;
        }
    }
    if (izquierda != nullptr) {
        if (izquierda->elemento.letra == 'S' and izquierda->elemento.velocidad == 200) {
            cout << "En el hijo izquierdo de ";
            return true;
        }
    }
    return false;
}

void pasarNivel(Pila &pilaAux, bool &flag) {
    if (esPilaVacia(pilaAux))return;
    NodoArbol *nodoAux = desapilar(pilaAux);
//    cout << nodoAux->elemento.letra << "-" << nodoAux->elemento.velocidad << endl;/*Para pruebas*/
    //evalua si es skynerd esta en sus hijos
    if (nodoAux->elemento.velocidad == 200) {
        flag = evaluaSopsechoso(nodoAux->izquierda, nodoAux->derecha);
        if (flag) {
            cout << nodoAux->elemento.letra << "-" << nodoAux->elemento.velocidad <<" Se encontro Skynerd";
            destruirPila(pilaAux); //desapila todo por si queda algo en la pila
            return;
        }
    }
    pasarNivel(pilaAux,flag);
    if (flag == true) return; //antes de apilar cualquier valor del siguiente nivel se verifica
    if (nodoAux->derecha != nullptr) {
        apilar(pilaAux, nodoAux->derecha);
    }
    if (nodoAux->izquierda != nullptr) {
        apilar(pilaAux, nodoAux->izquierda);
    }
}

bool buscaSkynerd(ArbolBinario &arbol) {

    if (esArbolVacio(arbol))return false;
    bool flag = false;
    Pila pilaAux;
    construir(pilaAux);
    apilar(pilaAux, arbol.raiz);
    //Se buscara por nivel
    int i = 1;
    while (not esPilaVacia(pilaAux)) {
        pasarNivel(pilaAux,flag);
        i++; // Para la pregunta c)
    }
    if (flag == true) cout << "( nivel:"<<i<<")"<<endl;
    else cout << "No se encontro Skynerd en la red"<<endl;
}

int main(int argc, char** argv) {
    //Pregunta a)

    Servidor serv1{'E', 50}, serv2{'E', 100}, serv3{'S', 100}, serv4{'E', 200};
    Servidor serv5{'S', 50}, serv6{'Z', 200}, serv7{'S', 200}, serv8{'S', 150};
    Servidor serv9{'Z', 50}, serv10{'Z', 100};
    ArbolBinario arbol, arbol1, arbol2, arbol3, arbol4, arbol5, arbol6, arbol7;
    //hojas
    plantarArbolBinario(arbol1, nullptr, serv1, nullptr);
    plantarArbolBinario(arbol2, nullptr, serv2, nullptr);
    plantarArbolBinario(arbol3, nullptr, serv5, nullptr);
    plantarArbolBinario(arbol4, nullptr, serv3, nullptr);
    plantarArbolBinario(arbol5, nullptr, serv4, nullptr);
    plantarArbolBinario(arbol6, nullptr, serv8, nullptr);
    //Izquierda
    plantarArbolBinario(arbol7, arbol1.raiz, serv5, nullptr);
    plantarArbolBinario(arbol1, arbol2.raiz, serv6, nullptr);
    plantarArbolBinario(arbol2, arbol7, serv2, arbol1);
    plantarArbolBinario(arbol1, arbol2, serv9, arbol3);
    //derecha
    plantarArbolBinario(arbol3, arbol4, serv7, arbol5);
    plantarArbolBinario(arbol2, arbol3, serv4, arbol6);
    //arbol final
    plantarArbolBinario(arbol, arbol1, serv10, arbol2);

    //Pregunta b) y c)
    bool seEncuentra = buscaSkynerd(arbol);

    return 0;
}


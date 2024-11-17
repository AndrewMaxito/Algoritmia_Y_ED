

/* 
 * File:   funcionesArbolesBinarios.cpp
 * Author: andre
 * 
 * Created on 16 de noviembre de 2024, 02:22 PM
 */
#include <iostream>
#include <iomanip>
#include <cstring>
using namespace std;
#include "ArbolBinario.h"
#include "funcionesArbolesBinarios.h"

void cosntruir(ArbolBinario &arbol) {
    arbol.raiz = nullptr;
    arbol.size = 0;
}

bool esNodoVacio(const NodoArbol *nodo) {
    return nodo == nullptr;

}

bool esArbolVacio(const ArbolBinario &arbol) {
    return esNodoVacio(arbol.raiz);
}

struct NodoArbol* crearNuevoNodoArbol(NodoArbol *izquierdo,
        const Elemento elemento, NodoArbol *derecho) {
    NodoArbol *nuevoNodo = new NodoArbol;

    //valores
    nuevoNodo->izquierda = izquierdo;
    nuevoNodo->elemento = elemento;
    nuevoNodo->derecha = derecho;
    return nuevoNodo;
}

void plantarArbolBinario(ArbolBinario &arbol, NodoArbol *izquiero,
        const Elemento elemento, NodoArbol *derecho) {
    NodoArbol *nuevoNodo = crearNuevoNodoArbol(izquiero, elemento, derecho);
    arbol.raiz = nuevoNodo;
}
//segunda forma

void plantarArbolBinario(ArbolBinario &arbol, ArbolBinario &arbolIzq,
        const Elemento elemento, ArbolBinario &arbolDer) {
    NodoArbol *nuevoNodo = crearNuevoNodoArbol(arbolIzq.raiz, elemento, arbolDer.raiz);
    arbol.raiz = nuevoNodo;
}


//contar Nodos

int numeroNodosRecursivo(NodoArbol *nodo) {
    if (esNodoVacio(nodo))return 0;
    else return 1 + numeroNodosRecursivo(nodo->izquierda) + numeroNodosRecursivo(nodo->derecha);
}

int numeroNodos(const ArbolBinario &arbol) {
    return numeroNodosRecursivo(arbol.raiz);
}

//actulizar cantidad nodos

void actualizarCantidadNodos(ArbolBinario &arbol) {
    arbol.size = numeroNodos(arbol);
}
//eliminar

void destruirArbolBinario(ArbolBinario &arbol) {
    destruirRecursivo(arbol.raiz);
    arbol.raiz = nullptr;
}

void destruirRecursivo(NodoArbol *nodo){
    
    if (not esNodoVacio(nodo)) {
        destruirRecursivo(nodo->izquierda);
        destruirRecursivo(nodo->derecha);
        delete nodo;
    }
}


//Imprimir

void imprimeNodo(struct NodoArbol * nodo) {
    cout << left << setw(14) << nodo->elemento.capitulo << right << setw(2) << nodo->elemento.relevancia << ", ";
}

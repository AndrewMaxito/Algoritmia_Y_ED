

/* 
 * File:   main.cpp
 * Author: AndrewMax
 *
 * Created on 29 de noviembre de 2024, 05:33 PM
 */

#include <iostream>

#include "ArbolBB.h"
#include "funcionesABB.h"
#include "funcionesAB.h"
#include "Pila.h"
#include "funcionesPila.h"


using namespace std;


//Supopniendo que siempre se encontrara el elemento

NodoArbol * buscaNodoElemento_Iterativo(NodoArbol *raiz, int elemento) {
    NodoArbol *recorrido;
    recorrido = raiz;
    while (recorrido) {
        if (recorrido->elemento == elemento)return recorrido;
        else if (recorrido->elemento > elemento) recorrido = recorrido->izquierda;
        else recorrido = recorrido->derecha;
    }
    //Solo por si acaso
    cout << "No se encontro el nodo " << endl;
    exit(1);
}
void Insertar_Recursivo(ArbolBinarioBusqueda& arbol, int dato){
    NodoArbol *recorrido = arbol.arbolBinario.raiz;
    while (true) {
        if(recorrido->elemento== dato) break;//ya existe
        
        if (recorrido->elemento > dato){
            if (esNodoVacio(recorrido->izquierda)){
                plantarArbolBinario(recorrido->izquierda,nullptr,dato,nullptr);
                return ;
            }else recorrido = recorrido->izquierda;
        }else{
            if (esNodoVacio(recorrido->derecha)){
                plantarArbolBinario(recorrido->derecha,nullptr,dato,nullptr);
                return ;
            }else recorrido = recorrido->derecha;        
        }
    }
}


void recorrerEnOrden_Iterativo(ArbolBinarioBusqueda arbol) {
    if (esNodoVacio(arbol.arbolBinario.raiz)) return;
    Pila pilaAux;
    construir(pilaAux);

    NodoArbol *recorrido;

    recorrido = arbol.arbolBinario.raiz;

    //
    while (true) {
        //Llega hasta un nodo que no tiene hijos_izqierda
        while (recorrido) {
            apilar(pilaAux, recorrido->elemento);
            recorrido = recorrido->izquierda;
        }
        if (esPilaVacia(pilaAux)) break; //termina recorrido si ya no tiene elementos la pila

        //Si aun hay elemento en la pila (aun no termina)
        cout << cima(pilaAux) << "  ";
        recorrido = buscaNodoElemento_Iterativo(arbol.arbolBinario.raiz, desapilar(pilaAux));

        //Va a la derecha
        if (not esNodoVacio(recorrido->derecha)) recorrido = recorrido->derecha;
        else recorrido = nullptr; //esta en una hoja
    }
}

void recorrerPreOrden_Iterativo(ArbolBinarioBusqueda arbol) {
    if (esNodoVacio(arbol.arbolBinario.raiz))return;

    Pila pilaAux;
    construir(pilaAux);
    NodoArbol *recorrido = arbol.arbolBinario.raiz;


    apilar(pilaAux, recorrido->elemento);
    //
    while (not esPilaVacia(pilaAux)) {
        //muestra actual
        cout << cima(pilaAux) << "  ";
        recorrido = buscaNodoElemento_Iterativo(arbol.arbolBinario.raiz, desapilar(pilaAux));

        //apila elemento derecha si no es vacio
        if (not esNodoVacio(recorrido->derecha)) {
            apilar(pilaAux, recorrido->derecha->elemento); //preferible trabajarlo en otra funcion para no romper el encapsulamiento
        }
        //apila elemento izquierda si no es vacio
        if (not esNodoVacio(recorrido->izquierda)) {
            apilar(pilaAux, recorrido->izquierda->elemento); //preferible trabajarlo en otra funcion para no romper el encapsulamiento
        }
    }
}

void recorrerPosOrden_Iterativo(ArbolBinarioBusqueda arbol){
    if (esArbolVacio(arbol.arbolBinario))return ;
    Pila pilaAux;
    construir(pilaAux);
    NodoArbol *recorrido = arbol.arbolBinario.raiz;
    
    
    
    //
    int ultimo=-9999;//tendra un valor cuando haya entrado ya a la derecha
    while (true) {
        while (recorrido) {
            apilar(pilaAux, recorrido->elemento);
            recorrido = recorrido->izquierda;
        }
        
        if (esPilaVacia(pilaAux))break;
        
        recorrido = buscaNodoElemento_Iterativo(arbol.arbolBinario.raiz,cima(pilaAux));
        
        if (recorrido->derecha and recorrido->derecha->elemento != ultimo) {//si no es una hoja y es su primera evaluacion
            recorrido = recorrido->derecha;
        } else {
            ultimo = desapilar(pilaAux);
            recorrido = nullptr;
            cout << ultimo << "  ";
        }
    }
}


int main(int argc, char** argv) {
    ArbolBinarioBusqueda arbol1;

    construir(arbol1);
    insertar(arbol1, 50);
    insertar(arbol1, 30);
    insertar(arbol1, 70);
    insertar(arbol1, 10);
    insertar(arbol1, 40);
    insertar(arbol1, 60);
    insertar(arbol1, 80);
    insertar(arbol1, 5);
    insertar(arbol1, 20);
    insertar(arbol1, 35);
    insertar(arbol1, 45);
    insertar(arbol1, 7);
    insertar(arbol1, 6);
    insertar(arbol1, 8);
    cout << "Recorrido InOrder: "<<endl;
    recorrerEnOrden_Iterativo(arbol1);
    cout << endl;
    cout << "Recorrido PreOrder: "<<endl;
    recorrerPreOrden_Iterativo(arbol1);
    cout <<endl;
    cout << "Recorrido PosOrder: "<<endl;
    recorrerPosOrden_Iterativo(arbol1);
    return 0;
}



/* 
 * File:   main.cpp
 * Author: andre
 *
 * Created on 28 de noviembre de 2024, 21:48
 */

#include <iostream>
#include <iomanip>

#include "ArbolBB.h"
#include "funcionesABB.h"
#include "funcionesAB.h"

using namespace std;


//void despacha(NodoArbol *&ptrArbol,int cant){
//    NodoArbol *aux;
//    
//    if(cant==0) return;
//    aux = minimoArbol(ptrArbol);
//    cout << aux->elemento.lote<<"gaaa"<<endl;
//    if(aux->elemento.cantidad<=cant){
//        int falta=cant-aux->elemento.cantidad;
//        ptrArbol=eliminarRecursivo(ptrArbol,aux->elemento.lote);
//        despacha(ptrArbol,falta);
//    }
//    else
//        aux->elemento.cantidad-=cant;
//}
void fusionarRec(struct NodoArbol *& destino, struct NodoArbol *& emisor){
    //caso base
    if(esNodoVacio(emisor)) return;
    //caso recursivo
    //llamadas recursivas
    fusionarRec(destino, emisor->izquierda);
    fusionarRec(destino, emisor->derecha);
    //procesar nodo
    NodoArbol* nodoActual = emisor;
    emisor = nullptr;//Desconectar del arbol
    insertarRecursivo(destino, nodoActual->elemento);
}

int main(int argc, char** argv) {
    ArbolBinarioBusqueda arbol1,arbol2;
    construir(arbol1);
    construir(arbol2);
    //Arbol Destino
    insertar(arbol1,{20180211,20});
    insertar(arbol1,{20170810,20});
    insertar(arbol1,{20170620,20});
    insertar(arbol1,{20180409,10}); 
    //Arbol Emisor
    insertar(arbol2,{20180211,10});
    insertar(arbol2,{20170811,5});
    insertar(arbol2,{20180410,15});
    
    recorrerEnOrden(arbol1.arbolBinario);
    //despacha(arbol.arbolBinario.raiz,60);
    //cout <<endl;
    cout <<endl;
    recorrerEnOrden(arbol2.arbolBinario);
    cout << endl;
    cout<<"Fusionar arboles: "<<endl;;
    fusionarRec(arbol1.arbolBinario.raiz, arbol2.arbolBinario.raiz);
    recorrerEnOrden(arbol1.arbolBinario);
    cout <<endl;
    return 0;
}


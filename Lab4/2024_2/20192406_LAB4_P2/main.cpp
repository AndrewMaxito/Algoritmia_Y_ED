
/* 
 * File:   main.cpp
 * Author: alulab14
 *
 * Created on 30 de noviembre de 2024, 09:19 AM
 */

#include <iostream>
#include <iomanip>

#include "ArbolBB.h"
#include "funcionesABB.h"
#include "funcionesAB.h"
#include "Pila.h"
#include "funcionesPila.h"

using namespace std;
void ingresa_Lote(ArbolBinarioBusqueda &arbol,int aa,int cantidad){
    insertar(arbol,aa,cantidad);//se modifico la funcion de la profesora(aqui no hay restriccion de recursivo)
}
NodoArbol *bucarNodoIterativo(ArbolBinarioBusqueda arbol,int dato){
    NodoArbol *recorrido = arbol.arbolBinario.raiz;
    while (recorrido) {
        if (recorrido->elemento == dato)return recorrido;  
        if (recorrido->elemento > dato) {
            recorrido =recorrido->izquierda;
        } else {
            recorrido =recorrido->derecha;
        }
    }
    //solo por si acaso (siempre deberia ya que se trabajara con datos ingresados)
    cout << "No se encontro el dato "<<endl;
    exit(1);
}

void recorrerInOrderInversa_recursiva(ArbolBinarioBusqueda arbol){
    if (esNodoVacio(arbol.arbolBinario.raiz))return ; // no hay elementos
    Pila pilaAux;
    construir(pilaAux);
    NodoArbol *recorrido = arbol.arbolBinario.raiz;
    //
    while (true) {
        while (recorrido) {
            apilar(pilaAux,recorrido->elemento);
            recorrido = recorrido->derecha;
        }
        if (esPilaVacia(pilaAux))break;
        cout << cima(pilaAux)/1000 << "-"<<cima(pilaAux)%1000<< "   ";
        recorrido = bucarNodoIterativo(arbol,desapilar(pilaAux));
        
        if (recorrido->izquierda != nullptr) {
            recorrido = recorrido->izquierda;

        } else recorrido = nullptr;
    } 
}


int main(int argc, char** argv) {
    ArbolBinarioBusqueda arbol;
    construir(arbol);
    //a)
    ingresa_Lote(arbol,2018,100);
    ingresa_Lote(arbol,2011,150);
    ingresa_Lote(arbol,2022,50);
    ingresa_Lote(arbol,2010,175);
    ingresa_Lote(arbol,2017,25);
    ingresa_Lote(arbol,2019,125);
    ingresa_Lote(arbol,2023,200); // para porbar 
    ingresa_Lote(arbol,2020,75);
    
     //Solo para comprobar ingreso correcto 
    //recorrerPostOrden(arbol.arbolBinario);
    
    
    ingresa_Lote(arbol,2011,150); //Ingreso de dato existente (para sumar su cantidad)
    //b)
    recorrerInOrderInversa_recursiva(arbol);
    return 0;
}


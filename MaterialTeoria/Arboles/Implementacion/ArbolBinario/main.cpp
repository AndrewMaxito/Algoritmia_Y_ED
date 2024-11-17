/* 
 * File:   main.cpp
 * Author: Ana Roncal
 *
 * Created on 27 de octubre de 2024, 16:56
 */

#include <iostream>
using namespace std;
#include "ArbolB.h"
#include "funcionesAB.h"
/*
 *  ARBOLES BINARIOS 2024-2
 *  Clase ABB
 */
int main(int argc, char** argv) {

    struct ArbolBinario arbol;
    construir(arbol);

    cout<<"Es árbol vacío: "<<esArbolVacio(arbol)<<endl;
    
    /*tipos de inserción*/
    plantarArbolBinario(arbol, nullptr, 100, nullptr);
    
    
    
    struct ArbolBinario arbol1, arbol2, arbol3, arbol4;
    //convencional
    plantarArbolBinario(arbol1, nullptr, 25, nullptr);
    plantarArbolBinario(arbol2, nullptr, 75, nullptr);
    
    //añadir arboles existentes a uno nuevo (nueva raiz)
    plantarArbolBinario(arbol3, arbol1, 50, arbol2);
    plantarArbolBinario(arbol4, nullptr, 150, nullptr);
    plantarArbolBinario(arbol, arbol3, 100, arbol4);

    
    //Recorrios
    cout <<"Recorrer en pre orden: "<< endl;
    recorrerPreOrden(arbol); cout<<endl;
    
    cout <<"Recorrer en En orden: "<< endl;
    recorrerEnOrden(arbol); cout<<endl;
    
    cout <<"Recorrer en Post orden: "<< endl;
    recorrerPostOrden(arbol); cout<<endl;
    
    cout<<"Altura árbol: " << altura(arbol) <<endl;
    cout<<"Número de hojas: "<<numeroHojas(arbol) <<endl;
    cout<<"Número de nodos: "<<numeroNodos(arbol) <<endl;
    cout<<"Es equilibrado: "<<esEquilibrado(arbol)<<endl;
    
    return 0;
}

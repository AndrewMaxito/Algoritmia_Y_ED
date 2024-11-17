/* 
 * File:   main.cpp
 * Author: ANA RONCAL
 * Created on 30 de mayo de 2025, 05:05 PM
 */

#include <iostream>
#include <cstring>
#include "ArbolBinario.h"
using namespace std;
#include "funcionesArbolesBinarios.h"
#include "Elemento.h"

/*
 * ESTRUCTURA ÁRBOL BINARIO 2024-1
 */
int main(int argc, char** argv) {

    struct ArbolBinario arbol, arbol1, arbol2, arbol3, arbol4, arbol5, arbol6;
    struct ArbolBinario arbol7, arbol8;
    struct Elemento elemento1 {"Sección1.1.1", 4},
                    elemento2 {"Sección1.1.2", 2},
                    elemento3 {"Sección2.1", 3},
                    elemento4 {"Sección2.2", 4},
                    elemento5 {"Principal", 10},
                    elemento6 {"Sección1.1", 6},
                    elemento7 {"Capítulo1", 8},
                    elemento8 {"Capítulo2", 5},
                    elemento9 {"Título", 7};
       
    /*Título 7
    Capítulo1 8
    Capítulo2 5
    Sección1.1 6
    Principal 10
    Sección2.1 3
    Sección2.2 4
    Sección1.1.1 4
    Sección1.1.2 2*/
    
    plantarArbolBinario(arbol1, nullptr, elemento1, nullptr);
    plantarArbolBinario(arbol2, nullptr, elemento2, nullptr);
    plantarArbolBinario(arbol3, nullptr, elemento3, nullptr);
    plantarArbolBinario(arbol4, nullptr, elemento4, nullptr);
    plantarArbolBinario(arbol5, nullptr, elemento5, nullptr);
    plantarArbolBinario(arbol6, arbol1, elemento6, arbol2);
    plantarArbolBinario(arbol7, arbol6, elemento7, arbol5);
    plantarArbolBinario(arbol8, arbol3, elemento8, arbol4);
    plantarArbolBinario(arbol, arbol7, elemento9, arbol8);
    
    actualizarCantidadNodos(arbol);
//    recorridoPorNivel(arbol);
//    cout<<endl<<endl;
//    
    char nodoEliminar = 'D'; 
    eliminaSubArbol(arbol, nodoEliminar);
    
    recorridoPorNivel(arbol);
    
    return 0;
}


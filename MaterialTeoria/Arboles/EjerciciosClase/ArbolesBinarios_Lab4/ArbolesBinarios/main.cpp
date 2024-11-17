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
    struct Elemento elemento;
    construir(arbol);
    /*Título 7
    Capítulo1 8
    Capítulo2 5
    Sección1.1 6
    Principal 10
    Sección2.1 3
    Sección2.2 4
    Sección1.1.1 4
    Sección1.1.2 2*/
    
    strcpy(elemento.capitulo,"Sección1.1.1");
    elemento.relevancia = 4;
    plantarArbolBinario(arbol1, nullptr, elemento, nullptr);
        
    strcpy(elemento.capitulo,"Sección1.1.2");
    elemento.relevancia = 2;
    plantarArbolBinario(arbol2, nullptr, elemento, nullptr);
       
    strcpy(elemento.capitulo,"Sección2.1");
    elemento.relevancia = 3;
    plantarArbolBinario(arbol3, nullptr, elemento, nullptr);
           
    strcpy(elemento.capitulo,"Sección2.2");
    elemento.relevancia = 4;
    plantarArbolBinario(arbol4, nullptr, elemento, nullptr);
       
    strcpy(elemento.capitulo,"Principal");
    elemento.relevancia = 10;
    plantarArbolBinario(arbol5, nullptr, elemento, nullptr);
    
    strcpy(elemento.capitulo,"Sección1.1");
    elemento.relevancia = 6;
    plantarArbolBinario(arbol6, arbol1, elemento, arbol2);
    
    strcpy(elemento.capitulo,"Capítulo1");
    elemento.relevancia = 8;
    plantarArbolBinario(arbol7, arbol6, elemento, arbol5);
    
    strcpy(elemento.capitulo,"Capítulo2");
    elemento.relevancia = 5;
    plantarArbolBinario(arbol8, arbol3, elemento, arbol4);
    
    strcpy(elemento.capitulo,"Título");
    elemento.relevancia = 7;
    plantarArbolBinario(arbol, arbol7, elemento, arbol8);
    
    recorridoPorNivel(arbol);
    cout<<endl;
    
    eliminaSubArbol(arbol);
    
    recorridoPorNivel(arbol);
    
    return 0;
}


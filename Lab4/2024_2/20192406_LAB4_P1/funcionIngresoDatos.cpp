

/* 
 * File:   funcionIngresoDatos.cpp
 * Author: alulab14
 * 
 * Created on 30 de noviembre de 2024, 08:10 AM
 */
#include <iostream>
#include <iomanip>
#include "funcionIngresoDatos.h"
#include "funcionesAB.h"
using namespace std;


void ingresarDatosPregunta(ArbolBinario &arbol){
    
    ArbolBinario arbol1,arbol2,arbol3,arbol4,arbol5,arbol6,arbol7;
    //hojas
    plantarArbolBinario(arbol1,nullptr,'N',nullptr);
    plantarArbolBinario(arbol2,nullptr,'O',nullptr);
    plantarArbolBinario(arbol3,nullptr,'A',nullptr);
    plantarArbolBinario(arbol4,nullptr,'S',nullptr);
    plantarArbolBinario(arbol5,nullptr,'A',nullptr);
    plantarArbolBinario(arbol6,nullptr,'S',nullptr);
    //tallos
    plantarArbolBinario(arbol7,arbol1.raiz,'E',nullptr);
    plantarArbolBinario(arbol1,arbol2.raiz,'A',nullptr);
    
    plantarArbolBinario(arbol2,arbol1.raiz,'B',nullptr);
    plantarArbolBinario(arbol1,arbol2.raiz,'L',nullptr);
    
    //Izquierda
    plantarArbolBinario(arbol2,arbol7,'I',arbol1);
    
    
    //Derecha
    plantarArbolBinario(arbol7,nullptr,'O',arbol4.raiz);
    plantarArbolBinario(arbol4,arbol3,'N',arbol7);
    plantarArbolBinario(arbol3,arbol4.raiz,'E',nullptr);
    
    plantarArbolBinario(arbol4,nullptr,'O',arbol6.raiz);
    plantarArbolBinario(arbol6,arbol5,'R',arbol4);
    plantarArbolBinario(arbol5,nullptr,'R',arbol6.raiz);
    
    plantarArbolBinario(arbol6,arbol3,'U',arbol5);
    //final
    plantarArbolBinario(arbol,arbol2,'B',arbol6);
    
   
    
    
    
    
}
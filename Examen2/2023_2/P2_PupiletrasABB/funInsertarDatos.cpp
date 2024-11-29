

/* 
 * File:   funInsertarDatos.cpp
 * Author: andre
 * 
 * Created on 28 de noviembre de 2024, 07:03 PM
 */

#include "funInsertarDatos.h"
#include "funcionesAB.h"

void insertarDatosProblemaAB(ArbolBinario& arbol){
    
    ArbolBinario arbol1,arbol2,arbol3,arbol4,arbol5,arbol6,arbol7;
    //crear Hojas
    plantarArbolBinario(arbol1,nullptr,'E',nullptr);
    plantarArbolBinario(arbol2,nullptr,'R',nullptr);
    plantarArbolBinario(arbol3,nullptr,'T',nullptr);
    plantarArbolBinario(arbol4,nullptr,'O',nullptr);
    plantarArbolBinario(arbol5,nullptr,'F',nullptr);
    plantarArbolBinario(arbol6,nullptr,'T',nullptr);
    //TALLOS
    //IZQUIERDA
    plantarArbolBinario(arbol7,arbol3.raiz,'G',nullptr);
    plantarArbolBinario(arbol3,arbol2,'E',arbol7);
    plantarArbolBinario(arbol7,arbol1,'D',arbol3);
    
    //DERECHA
    plantarArbolBinario(arbol1,arbol4.raiz,'C',nullptr);
    plantarArbolBinario(arbol4,arbol1.raiz,'C',nullptr);
    plantarArbolBinario(arbol2,arbol5,'A',arbol6);
    plantarArbolBinario(arbol5,arbol2.raiz,'N',nullptr);
    plantarArbolBinario(arbol1,arbol4,'I',arbol5);
    
    //TODO
    plantarArbolBinario(arbol,arbol7,'L',arbol1);
}
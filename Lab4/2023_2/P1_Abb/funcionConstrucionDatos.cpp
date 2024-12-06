/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   funcionConstrucionDatos.cpp
 * Author: andre
 * 
 * Created on 6 de diciembre de 2024, 04:07 PM
 */

#include "funcionConstrucionDatos.h"
#include "funcionesAB.h"
#include "ArbolB.h"
using namespace std;
void generarArbolSistema( ArbolBinario & arbolSistema){  
    
    
    
    //Colaboracion de Gonzalo XD (me lo robe)
    
    plantarArbolBinario(arbolSistema.raiz, nullptr, 3, nullptr);
    plantarArbolBinario(arbolSistema.raiz->izquierda, nullptr, 1, nullptr);
    plantarArbolBinario(arbolSistema.raiz->derecha, nullptr, 5, nullptr);
    plantarArbolBinario(arbolSistema.raiz->izquierda->derecha, nullptr, 2, nullptr);
    plantarArbolBinario(arbolSistema.raiz->derecha->izquierda, nullptr, 4, nullptr);
    plantarArbolBinario(arbolSistema.raiz->derecha->derecha, nullptr, 6, nullptr);
    plantarArbolBinario(arbolSistema.raiz->derecha->derecha->derecha, nullptr, 7, nullptr);   
      
//    plantarArbolBinario(arbolSistema.raiz, nullptr, 4, nullptr);
//    plantarArbolBinario(arbolSistema.raiz->izquierda, nullptr, -2, nullptr);
//    plantarArbolBinario(arbolSistema.raiz->derecha, nullptr, 6, nullptr);
//    plantarArbolBinario(arbolSistema.raiz->izquierda->izquierda, nullptr, -3, nullptr);
//    plantarArbolBinario(arbolSistema.raiz->izquierda->derecha, nullptr, -1, nullptr);
//    plantarArbolBinario(arbolSistema.raiz->derecha->izquierda, nullptr, 5, nullptr);
//    plantarArbolBinario(arbolSistema.raiz->derecha->derecha, nullptr, 7, nullptr);
//    plantarArbolBinario(arbolSistema.raiz->izquierda->derecha->derecha, nullptr, 0, nullptr);
}
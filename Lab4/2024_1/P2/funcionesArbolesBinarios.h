/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   funcionesArbolesBinarios.h
 * Author: andre
 *
 * Created on 16 de noviembre de 2024, 02:22 PM
 */

#ifndef FUNCIONESARBOLESBINARIOS_H
#define FUNCIONESARBOLESBINARIOS_H

void cosntruir(ArbolBinario &arbol);


bool esNodoVacio(const NodoArbol *nodo);
bool esArbolVacio(const ArbolBinario &arbol);
struct NodoArbol* crearNuevoNodoArbol(NodoArbol *izquierdo,
        const Elemento elemento, NodoArbol *derecho);
void plantarArbolBinario(ArbolBinario &arbol,  NodoArbol *izquiero,
        const Elemento elemento,NodoArbol *derecho);

void plantarArbolBinario(ArbolBinario &arbol,ArbolBinario &arbolIzq,
        const Elemento elemento,ArbolBinario &arbolDer);

int numeroNodosRecursivo(NodoArbol *nodo);
int numeroNodos(const ArbolBinario &arbol);

void destruirArbolBinario(ArbolBinario &arbol);
void destruirRecursivo(NodoArbol *nodo);


void actualizarCantidadNodos(ArbolBinario &arbol);
void imprimeNodo(struct NodoArbol * nodo);

#endif /* FUNCIONESARBOLESBINARIOS_H */

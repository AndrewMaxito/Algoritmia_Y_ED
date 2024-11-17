
/* 
 * File:   NodoArbol.h
 * Author: andre
 *
 * Created on 16 de noviembre de 2024, 02:17 PM
 */

#ifndef NODOARBOL_H
#define NODOARBOL_H

#include "Elemento.h"

struct NodoArbol{
    Elemento elemento;
    NodoArbol *izquierda;
    NodoArbol *derecha;
};
#endif /* NODOARBOL_H */


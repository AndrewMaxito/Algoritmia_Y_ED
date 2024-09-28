/* 
 * File:   Lista.h
 * Author: ANA RONCAL
 *
 * Created on 1 de setiembre de 2024, 20:43
 */

#ifndef LISTA_H
#define LISTA_H

#include "Nodo.h"
struct Lista {
    struct Nodo * cabeza; /*apunta al inicio de la lista*/
    int longitud; /*guarda la longitud de la lista*/
};

#endif /* LISTA_H */
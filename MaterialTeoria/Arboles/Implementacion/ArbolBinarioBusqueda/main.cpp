/* 
 * File:   main.cpp
 * Author: Ana Roncal
 *
 * Created on 27 de octubre de 2024, 16:56
 */

#include <iostream>
using namespace std;
#include "ArbolBB.h"
#include "funcionesABB.h"
/*
 *  ARBOLES BINARIOS 2024-2
 *  Clase ABB
 */
int main(int argc, char** argv) {

    struct ArbolBinarioBusqueda arbol;
    
    construir(arbol);
    
    insertar(arbol, 100);
    insertar(arbol, 50);
    insertar(arbol, 150);
    insertar(arbol, 125);
    insertar(arbol, 175);
    insertar(arbol, 200);
    insertar(arbol, 25);
    insertar(arbol, 75);
    
    enOrden(arbol);
    
    /*Función de búsqueda*/
    cout << endl <<"Se encuentra el nodo 125 en el arból: " << buscar(arbol, 125)<< endl;
    
    eliminar(arbol, 25);
    eliminar(arbol, 150);
    eliminar(arbol, 100);
    enOrden(arbol);
    
    return 0;
}

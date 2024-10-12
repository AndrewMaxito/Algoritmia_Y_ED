/* 
 * Archivo:   main.cpp
 * Autor: Gonzalo Quinteros Mostacero
 *
 * Creado el 25 de septiembre de 2024, 09:44 PM
 */

#include <iostream>
#include <iomanip>
#include "Pila.h"
#include "FuncionesAuxiliares.h"
#include "funcionesPila.h"
#define MAX 5

using namespace std;

int main(int argc, char** argv) {
    struct Pila contenedor;
    struct Pila cajas[MAX];
    int cantCajas, capacidadCaja;
    ingresarContenedor(contenedor, cantCajas, capacidadCaja);
    cout<<"Contenedor: ";
    imprimir(contenedor);
    distribuirProductos(contenedor, cajas, cantCajas, capacidadCaja);
    mostrarPilas(cajas, cantCajas);
    return 0;
}


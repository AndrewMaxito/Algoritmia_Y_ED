/* 
 * Archivo:   main.cpp
 * Autor: Gonzalo Quinteros Mostacero
 *
 * Creado el 11 de octubre de 2024, 05:47 PM
 */

#include <iostream>
#include <iomanip>
#include "Pila.h"
#include "funcionesPila.h"
#include "FuncionesAuxiliares.h"
#define MAX_DIAS 8

using namespace std;

int main(int argc, char** argv) {
    int contagios[MAX_DIAS] = {10, 20, 15, 10, 12, 10, 13, 18};
    int intervalo[MAX_DIAS] = {};
    struct Pila pila;
    construir(pila);
    calcularIntervalosIncremento(contagios, intervalo, MAX_DIAS, pila);
    imprimirIntervalosIncremento(intervalo, MAX_DIAS);
    return 0;
}


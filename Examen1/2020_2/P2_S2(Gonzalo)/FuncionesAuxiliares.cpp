/* 
 * Archivo:   FuncionesAuxiliares.cpp
 * Autor: Gonzalo Quinteros Mostacero
 *
 * Creado el 11 de octubre de 2024, 05:51 PM
 */

#include <iostream>
#include <iomanip>
#include "Pila.h"
#include "funcionesPila.h"
#include "FuncionesAuxiliares.h"

using namespace std;

void calcularIntervalosIncremento(int *contagios, int *intervalo, int cantDias, 
                                  struct Pila &pila){
    int indiceDia, cantContagiados, cantDiasTendencia;
    bool nuevoDia;
    struct DiaContagio dia;
    indiceDia = 0;
    nuevoDia = true;
    while (indiceDia<cantDias){
        if (nuevoDia){
            cantContagiados = contagios[indiceDia];
            cantDiasTendencia = 0;
            dia.cantContagiados = cantContagiados;
            nuevoDia = false;
        }
        if (not esPilaVacia(pila) and cima(pila).cantContagiados<=cantContagiados){
            cantDiasTendencia += (cima(pila).cantDiasTendencia + 1);
            desapilar(pila);
        } else {
            dia.cantDiasTendencia = cantDiasTendencia;
            apilar(pila, dia);
            intervalo[indiceDia] = cantDiasTendencia;
            indiceDia++;
            nuevoDia = true;
        }
    }
}

void imprimirIntervalosIncremento(int *intervalo, int cantDias){
    cout << "El conjunto de intervalos de incremento de todos los dias es {";
    for(int i=0; i<cantDias; i++){
        cout << intervalo[i];
        if (i<cantDias-1) cout << ", ";
    }
    cout << "}" << endl;
}
/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: david
 *
 * Created on 23 de setiembre de 2024, 11:21
 */

#include <cstdlib>
#include "Cola.h"
#include "funcionesCola.h"

using namespace std;

/*
 * 
 */

int main(int argc, char** argv) {
    Cola colaPrioridad;
    construirPrioridad(colaPrioridad);
    /*Esta funcion se encuentra implementada en FuncionesCola.cpp*/
    encolarPrioridad(colaPrioridad,3,'V');
    encolarPrioridad(colaPrioridad,5,'V');
    imprimePrioridad(colaPrioridad);
    encolarPrioridad(colaPrioridad,1,'N');
    imprimePrioridad(colaPrioridad);
    encolarPrioridad(colaPrioridad,10,'N');
    imprimePrioridad(colaPrioridad);
    return 0;
}


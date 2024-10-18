/* 
 * File:   main.cpp
 * Author: andre
 *
 * Created on 18 de octubre de 2024, 10:30
 */

#include <iostream>
#include <iomanip>

using namespace std;
#include "Pila.h"
#include "funcionesPila.h"
#include "StrEfectivo.h"

int formaGrupoTerna(struct StrEfectivo *policia, int cantEfectivos, struct Pila &pilaAux) {

    int cantGrupos = 0;
    for (int i = 0; i < cantEfectivos; i++) {
        apilar(pilaAux, policia[i]);
    }
    while (!esPilaVacia(pilaAux)) {
        struct StrEfectivo polRegistrado = desapilar(pilaAux);
        int n = polRegistrado.idEfec;
        for (int i = n; i < cantEfectivos; i++) {
            if (polRegistrado.gradoEfec < policia[i].gradoEfec) break;
            if (polRegistrado.gradoEfec == policia[i].gradoEfec){
                if (polRegistrado.tiempoEfec <= policia[i].tiempoEfec) break;
            }
            cantGrupos++;
        }
        cantGrupos++;
    }
    return cantGrupos;
}

int main(int argc, char** argv) {
    //Ingreso de datos
    struct StrEfectivo policia[4]{
        {1, 3, 1},
        {2, 2, 1},
        {3, 2, 4},
        {3, 2, 4}
    };
    int cantEfectivos = 3;

    //Crear Pila
    struct Pila pilaAux;
    construir(pilaAux);

    int cant = formaGrupoTerna(policia, cantEfectivos, pilaAux);
    cout << "Se pueden formar " << cant << endl;

    return 0;
}



/* 
 * File:   main.cpp
 * Author: andre
 *
 * Created on 30 de setiembre de 2024, 17:00
 */

#include <iostream>
#include <iomanip>

using namespace std;
#include "Lista.h"
#include "Nodo.h"
#include "funcionesLista.h"

void fucionarLista(struct Lista &listaFinal, struct Lista &listaDia) {

    if (esListaVacia(listaDia)) {
        cout << "La lista del dia X esta vacia" << endl;
        return;
    }
    if (esListaVacia(listaFinal)) {
        listaFinal.cabeza = listaDia.cabeza;
        listaFinal.longitud = listaDia.longitud;
        return;
    }
    struct Nodo *ultimoPrincipal = obtenerUltimoNodo(listaFinal);
    struct Nodo *primeroPrincipal = listaFinal.cabeza;
    struct Nodo *primeroDia = listaDia.cabeza;
    struct Nodo *ultimoDia = obtenerUltimoNodo(listaDia);
    
    if (primeroDia->elemento >= ultimoPrincipal->elemento ){//si el elmento del dia es mayor o igual se pone al ultimo de la lista
        ultimoPrincipal->siguiente = primeroDia;
        listaFinal.longitud += listaDia.longitud;
        return;
    }
    if (ultimoDia->elemento < primeroPrincipal->elemento){
        ultimoDia->siguiente = primeroPrincipal;
        listaFinal.cabeza = ultimoDia;
        listaFinal.longitud += listaDia.longitud;
        return;
    }
}

int main(int argc, char** argv) {
    struct Lista listaLunes, listaMartes, listaMiercoles, listaJueves, listaViernes;
    struct Lista listaFinal;
    //Para la resolucion no se considerara la modificacion de los nodos (el numero de la sucursal no se usara)
    /*Carga de la lista de pedidos del Lunes*/
    construir(listaLunes);
    insertarAlInicio(listaLunes, 12);
    insertarAlInicio(listaLunes, 10);
    insertarAlInicio(listaLunes, 8);
    /*Carga de la lista de pedidos del Martes*/
    construir(listaMartes);
    insertarAlInicio(listaMartes, 9);
    insertarAlInicio(listaMartes, 11);
    /*Carga de la lista de pedidos del Miercoles*/
    construir(listaMiercoles);
    insertarAlInicio(listaMiercoles, 10);
    insertarAlInicio(listaMiercoles, 9);
    insertarAlInicio(listaMiercoles, 8);
    /*Carga de la lista de pedidos del Jueves*/
    construir(listaJueves);
    insertarAlInicio(listaJueves, 16);
    insertarAlInicio(listaJueves, 15);
    insertarAlInicio(listaJueves, 14);
    /*Carga de la lista de pedidos del Viernes*/
    construir(listaViernes);
    insertarAlInicio(listaViernes, 19);
    insertarAlInicio(listaViernes, 18);
    insertarAlInicio(listaViernes, 17);


    //
    construir(listaFinal);
    //Pregunta 2
    //Se asumira que la lista del lunes simpre estará cargada
//    for (int i = 2; i <= 5; i++) {
//        switch (i) {
//            case 1:
//                fucionarLista(listaFinal, listaLunes);
//                break;
//            case 2:
//                fucionarLista(listaFinal, listaMartes);
//                break;
//            case 3:
//                fucionarLista(listaFinal, listaMiercoles);
//                break;
//            case 4:
//                fucionarLista(listaFinal, listaJueves);
//                break;
//            case 5:
//                fucionarLista(listaFinal, listaViernes);
//                break;
//        }
//    }





    return 0;
}


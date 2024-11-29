

/* 
 * File:   main.cpp
 * Author: andre
 *
 * Created on 28 de noviembre de 2024, 06:44 PM
 */

#include <iostream>
#include <iomanip>
#include <string.h>

#include "ArbolB.h"
#include "funcionesAB.h"
#include "funInsertarDatos.h"
#include "Lista.h"
#include "funciones.h"
#include "Palabras.h"
using namespace std;

bool buscaLaLetra(char letra, char *palabra) {
    for (int i = 0; palabra[i]; i++) {
        if (palabra[i] == letra) return true;
    }
    return false;
}

bool estaCadaPabra(const Lista &aux, char *palabra) {

    for (int i = 0; palabra[i]; i++) {
        Nodo *recorrido = aux.cabeza;
        bool flag = false;
        while (recorrido) {
            if (palabra[i] == recorrido->elemento) {
                flag = true;
                break;
            }
            recorrido = recorrido->siguiente;
        }
        if (flag == false)return false;
    }
    return true;
}

void buscarPalabraEnLasHojas(const NodoArbol *raiz, char *palabra, Lista &aux, bool &encontrado) {
    if (raiz == nullptr or encontrado == true)return;

    bool perteneceLetra = buscaLaLetra(raiz->elemento, palabra);
    if (perteneceLetra == true and longitud(aux) + 1 <= strlen(palabra)) {
        insertarAlFinal(aux, raiz->elemento);
    } else {
        return; //No es el camino
    }
    if (raiz->derecha == nullptr and raiz->izquierda == nullptr) {//Estoy en una hoja
        if (longitud(aux) == strlen(palabra) and estaCadaPabra(aux, palabra) == true) {
            encontrado = true;
        } else eliminaCola(aux);
    } else {
        //Izquierda
        buscarPalabraEnLasHojas(raiz->izquierda, palabra, aux, encontrado);
        //Derecha
        buscarPalabraEnLasHojas(raiz->derecha, palabra, aux, encontrado);
        eliminaCola(aux);
    }
}

void buscarPalabra(char *palabra, const NodoArbol *raiz) {
    Lista aux;
    construir(aux);
    bool encontrado = false;
    buscarPalabraEnLasHojas(raiz, palabra, aux, encontrado);
    if (encontrado == true) {
        cout  << " "<< palabra << "  ";
    }
}
void buscaConjuntoDePalabras(const ArbolBinario &arbol,Palabras *conjuntoDePalabras,int cantidadPalabras){
    for (int i = 0; i < cantidadPalabras; i++) {
        buscarPalabra(conjuntoDePalabras[i].palabra,arbol.raiz);
    }
}

int main(int argc, char** argv) {
    ArbolBinario arbol;
    construir(arbol);
    insertarDatosProblemaAB(arbol);
    //a)
    char palabra[10] = "MUNDO";//Esto no deberia mostrarlo 
    buscarPalabra(palabra, arbol.raiz);
    //b)
    struct Palabras palabrasDonatello[6] = {
        {"HIJO"},
        {"FINAL"},
        {"MUNDO"},
        {"DEL"},
        {"DIA"},
        {"CICLO"}};
    int cantidad = sizeof(palabrasDonatello)/sizeof(palabrasDonatello[0]);
    buscaConjuntoDePalabras(arbol,palabrasDonatello,cantidad);

    return 0;
}


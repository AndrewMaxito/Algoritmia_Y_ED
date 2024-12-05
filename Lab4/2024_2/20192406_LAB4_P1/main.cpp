

/* 
 * File:   main.cpp
 * Author: alulab14
 *
 * Created on 30 de noviembre de 2024, 08:06 AM
 */

#include <iostream>
#include <iostream>
#include <cstring>

#include "ArbolB.h"
#include "funcionesAB.h"
using namespace std;
#include "funcionIngresoDatos.h"

void imprimirPalabras(NodoArbol *nodo, char *palabra) {
    if (esNodoVacio(nodo))return;
    int cantidadLetras = strlen(palabra);
    palabra[cantidadLetras] = nodo->elemento; //delimitador
    if (nodo->izquierda == nullptr and nodo->derecha == nullptr) {//hoja
        cout << palabra << endl;
        int cantD = strlen(palabra);
        palabra[cantD - 1] = '\0';
        return;
    } else {
        imprimirPalabras(nodo->izquierda, palabra);
        if (nodo->derecha == nullptr) {
            int cantD = strlen(palabra);
            palabra[cantD - 1] = '\0';
        } else {
            imprimirPalabras(nodo->derecha, palabra);
            int cantD = strlen(palabra);
            palabra[cantD - 1] = '\0';
        }
    }
}

int main(int argc, char** argv) {
    ArbolBinario arbol;
    construir(arbol);
    //a)Ingreso de datos:
    ingresarDatosPregunta(arbol); //se creo una biblioteca para esto
    //recorrerPreOrden(arbol);//verifica ingreso correcto
    //b)Impresion Palabras
    char palabra[100]{};
    imprimirPalabras(arbol.raiz, palabra);

    return 0;
}


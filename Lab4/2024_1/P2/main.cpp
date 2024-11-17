
/* 
 * File:   main.cpp
 * Author: AndreMax
 *
 * Created on 16 de noviembre de 2024, 02:12 PM
 */

#include <iostream>
#include <iomanip>
#include <cstring>
using namespace std;

#include "ArbolBinario.h"
#include "funcionesArbolesBinarios.h"
#include "funcionesCola.h"
#include "Cola.h"
void recorridoPorNivel(const ArbolBinario &arbol) {
    if (esArbolVacio(arbol)) return;
    Cola cola;
    construir(cola);
    int nivelPrin = -1, nivelAct = 0;
    //inicial
    encolar(cola, arbol.raiz);
    encolar(cola, nullptr); //delimitador de nivel

    /*Recorrido Por nivel o amplitud*/
    while (not esColaVacia(cola)) {
        NodoArbol *nodoEvaluar = desencolar(cola);
        if (nodoEvaluar != nullptr) {
            if (strcmp(nodoEvaluar->elemento.capitulo, "Principal") == 0) nivelPrin = nivelAct;
            imprimeNodo(nodoEvaluar);
            if (not esNodoVacio(nodoEvaluar->izquierda))
                encolar(cola, nodoEvaluar->izquierda);
            if (not esNodoVacio(nodoEvaluar->derecha))
                encolar(cola, nodoEvaluar->derecha);
        } else {
            cout << endl;
            nivelAct++;
            if (not esColaVacia(cola))encolar(cola, nullptr);
        }
    }
    destruirCola(cola);
    if (nivelPrin != -1)
        cout << "El nivel del capítulo 'Principal' es: " << nivelPrin;
}

void eliminaSubArbol(ArbolBinario &arbol,char nodoEliminar){
    cout <<"Nodos del árbol antes de eliminar: " << arbol.size << endl;
    int nodosEliminados;
    NodoArbol *auxEliminar;
    if (nodoEliminar == 'D') {
        nodosEliminados = numeroNodosRecursivo(arbol.raiz->derecha);
        auxEliminar = arbol.raiz->derecha;
        arbol.raiz->derecha = nullptr;
    } else if (nodoEliminar == 'I'){
        nodosEliminados = numeroNodosRecursivo(arbol.raiz->izquierda);
        auxEliminar = arbol.raiz->izquierda;
        arbol.raiz->izquierda = nullptr;
    }
    destruirRecursivo(auxEliminar);
    arbol.size -= nodosEliminados;
    cout <<"Nodos del árbol después de eliminar: " << arbol.size << endl;   
}

int main(int argc, char** argv) {

    //    ArbolBinario arbol;
    //    cosntruir(arbol);

    struct ArbolBinario arbol, arbol1, arbol2, arbol3, arbol4, arbol5, arbol6;
    struct ArbolBinario arbol7, arbol8;

    struct Elemento elemento1 {
        "Sección1.1.1", 4
    }, elemento2{"Sección1.1.2", 2},
    elemento3{"Sección2.1", 3}, elemento4{"Sección2.2", 4},
    elemento5{"Principal", 10}, elemento6{"Sección1.1", 6},
    elemento7{"Capítulo1", 8}, elemento8{"Capítulo2", 5},
    elemento9{"Título", 7};
    
    
    //Para las hojas
    plantarArbolBinario(arbol1, nullptr, elemento1, nullptr);
    plantarArbolBinario(arbol2, nullptr, elemento2, nullptr);
    plantarArbolBinario(arbol3, nullptr, elemento3, nullptr);
    plantarArbolBinario(arbol4, nullptr, elemento4, nullptr);
    plantarArbolBinario(arbol5, nullptr, elemento5, nullptr);
    
    
    //tallos
    plantarArbolBinario(arbol6, arbol1, elemento6, arbol2);
    plantarArbolBinario(arbol7, arbol6, elemento7, arbol5);
    plantarArbolBinario(arbol8, arbol3, elemento8, arbol4);
    plantarArbolBinario(arbol, arbol7, elemento9, arbol8);
    
    //actulizarCantidadNodos
    
    actualizarCantidadNodos(arbol);
    
    //Pregunta b) 
    cout << "Pregunta B) :"<<endl;
    recorridoPorNivel(arbol);
    cout <<endl<<endl;
    cout << "Pregunta C: "<<endl;
    //Pregunta c)
    char nodoEliminar = 'D'; 
    eliminaSubArbol(arbol,nodoEliminar);
    recorridoPorNivel(arbol);
    
    return 0;
}


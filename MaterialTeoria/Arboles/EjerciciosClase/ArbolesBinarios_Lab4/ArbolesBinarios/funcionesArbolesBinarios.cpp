/* 
 * File:   funcionesArbolesBB.cpp
 * Author: ANA RONCAL
 * Created on 19 de septiembre de 2023, 10:46 AM
 */

#include <iostream>
#include <iomanip>
#include <cstring>
#include "ArbolBinario.h"
#include "Cola.h"
#include "Elemento.h"
using namespace std;
#include "funcionesCola.h"
#include "funcionesArbolesBinarios.h"

void construir(struct ArbolBinario & arbol){
    arbol.raiz = nullptr;
}

bool esNodoVacio(struct NodoArbol * nodo){
    return nodo == nullptr;
}

bool esArbolVacio(const struct ArbolBinario & arbol){
    return esNodoVacio(arbol.raiz);
}

struct NodoArbol * crearNuevoNodoArbol(struct NodoArbol * izquierdo, 
                         struct Elemento elemento, struct NodoArbol * derecho){
    struct NodoArbol * nuevoNodo = new struct NodoArbol;
    nuevoNodo->elemento = elemento;
    nuevoNodo->izquierda = izquierdo;
    nuevoNodo->derecha = derecho;
    return nuevoNodo;
}

void plantarArbolBinario(struct ArbolBinario & arbol, struct NodoArbol * izquierdo,
                       struct Elemento elemento, struct NodoArbol * derecho){
    
    struct NodoArbol * nuevoNodo = crearNuevoNodoArbol(izquierdo, elemento, derecho);
    arbol.raiz = nuevoNodo;
    arbol.size++;
}

void plantarArbolBinario(struct ArbolBinario & arbol, struct ArbolBinario & arbolIzquierdo,
                         struct Elemento elemento, struct ArbolBinario & arbolDerecho){
    
    struct NodoArbol * nuevoNodo = crearNuevoNodoArbol(arbolIzquierdo.raiz, elemento, arbolDerecho.raiz);
    arbol.raiz = nuevoNodo;
    arbol.size++;
}

struct Elemento raiz(struct NodoArbol * nodo){
    if (esNodoVacio(nodo)){
        cout<<"No se puede obtener ra�z de un �rbol vacio"<<endl;
        exit(1);
    }
    return nodo->elemento;
}

struct NodoArbol * hijoDerecho(const struct ArbolBinario & arbol){
    if (esArbolVacio(arbol)){
        cout<<"No se puede obtener ra�z de un �rbol vacio"<<endl;
        exit(1);
    }
    return arbol.raiz->derecha;
}

struct  NodoArbol * hijoIzquierdo(const struct ArbolBinario & arbol){
    if (esArbolVacio(arbol)){
        cout<<"No se puede obtener ra�z de un �rbol vacio"<<endl;
        exit(1);
    }
    
    return arbol.raiz->izquierda;
 }

void imprimeRaiz(const struct ArbolBinario & arbol){
    imprimeNodo(arbol.raiz);
}

void imprimeNodo(struct NodoArbol * nodo){
    cout<<left<<setw(14)<<nodo->elemento.capitulo<<right<<setw(2)<<nodo->elemento.relevancia<<", ";
}

void recorrerEnOrdenRecursivo(struct NodoArbol * nodo){
    if(not esNodoVacio(nodo)){
        recorrerEnOrdenRecursivo(nodo->izquierda);
        imprimeNodo(nodo);
        recorrerEnOrdenRecursivo(nodo->derecha);
    }
}

/*En árbol, se lleva a cabo visitando el hijo izquierdo del nodo, luego el nodo
 luego todos los restantes, comenzando por la raíz*/
void recorrerEnOrden(const struct ArbolBinario & arbol){
    /*Imprime en orden*/
    recorrerEnOrdenRecursivo(arbol.raiz);
    
}

void recorrerEnPreOrdenRecursivo(struct NodoArbol * nodo){
    if(not esNodoVacio(nodo)){
        imprimeNodo(nodo);
        recorrerEnPreOrdenRecursivo(nodo->izquierda);
        recorrerEnPreOrdenRecursivo(nodo->derecha);
    }
}

/*recorrido descendente, se lleva a cabo visitando cada nodo, seguido de sus hijos,
 luego todos los restantes, comenzando por la raíz*/
void recorrerPreOrden(const struct ArbolBinario & arbol){
    recorrerEnPreOrdenRecursivo(arbol.raiz);
   
}

void recorrerEnPostOrdenRecursivo(struct NodoArbol * nodo){
    if(not esNodoVacio(nodo)){
        recorrerEnPostOrdenRecursivo(nodo->izquierda);
        recorrerEnPostOrdenRecursivo(nodo->derecha);
        imprimeNodo(nodo);
    }
}

/*recorrido ascendente, se lleva a cabo visitando los hijos, y luego el nodo
 luego todos los restantes, comenzando por la raíz*/
void recorrerPostOrden(const struct ArbolBinario & arbol){
  
    recorrerEnPostOrdenRecursivo(arbol.raiz);
    
}

/*recorre el árbol por niveles usando una cola*/
void recorridoPorNivel(struct ArbolBinario & arbol){
    struct Cola cola; /*Se usa una cola para acceder a los nodos*/
    construir(cola);
    int ultimoNivel, nivel = 0;
    struct Elemento elemento;
    
    if(not esArbolVacio(arbol)){
        encolar(cola, arbol.raiz);
        encolar(cola, nullptr); //encolo una marca
        while(not esColaVacia(cola)){
            struct NodoArbol * nodo = desencolar(cola);
            
            if(nodo != nullptr)
                if(strcmp(nodo->elemento.capitulo,"Principal") == 0)
                    ultimoNivel = nivel;
            
            if(nodo == nullptr){
                cout<<endl;
                nivel++;
                if(not esColaVacia(cola)){
                    encolar(cola, nullptr);
                }
            }
            else{
                imprimeNodo(nodo);
                if (not esNodoVacio(nodo->izquierda)){
                    encolar(cola, nodo->izquierda);
                }
                if (not esNodoVacio(nodo->derecha)){
                    encolar(cola, nodo->derecha);  
                }
            }
        }
    }
    destruirCola(cola);   
    cout <<"El nivel es:" <<ultimoNivel;
}

int maximo(int a, int b){
    return a>=b ? a: b;
}

int alturaRecursivo(struct NodoArbol * nodo){
    if(esNodoVacio(nodo))
        return 0;
    else if(esNodoVacio(nodo->izquierda) and esNodoVacio(nodo->derecha))
        return 0; 
    else
        return 1 + maximo( alturaRecursivo(nodo->izquierda), alturaRecursivo(nodo->derecha));
}

int altura(const struct ArbolBinario & arbol){
    return alturaRecursivo(arbol.raiz); //como el arbol ha sido construido no va apuntar a nullptr
}

int numeroNodosRecursivo(struct NodoArbol * nodo){
    if(esNodoVacio(nodo))
        return 0;
    else
        return 1 + numeroNodosRecursivo(nodo->izquierda) + numeroNodosRecursivo(nodo->derecha);   
}

/*Determina el número de elementos del árbol*/
int numeroNodos(const struct ArbolBinario & arbol){
    return numeroNodosRecursivo(arbol.raiz);
}

int numeroHojasRecursivo(struct NodoArbol * nodo){
    if(esNodoVacio(nodo))
        return 0;
    else if ( esNodoVacio(nodo->izquierda) and esNodoVacio(nodo->derecha) )
        return 1;
    else
        return numeroHojasRecursivo(nodo->izquierda) + numeroHojasRecursivo(nodo->derecha);
}

int numeroHojas(const struct ArbolBinario & arbol){
    return numeroHojasRecursivo(arbol.raiz);
}

int esEquilibradoRecursivo(struct NodoArbol * nodo){
    if(esNodoVacio(nodo))
        return 1;
    else{
        int alturaHijoIzquierdo = alturaRecursivo(nodo->izquierda);
        int alturaHijoDerecho = alturaRecursivo(nodo->derecha);
        int diferencia = abs(alturaHijoIzquierdo - alturaHijoDerecho);
        return diferencia<=1 and 
               esEquilibradoRecursivo(nodo->izquierda) and 
               esEquilibradoRecursivo(nodo->derecha);
    }        
}

int esEquilibrado(const struct ArbolBinario & arbol ){
    return esEquilibradoRecursivo(arbol.raiz);
}

int esHoja(const struct ArbolBinario & arbol){
    if(esArbolVacio(arbol))
        return 0;
    else
        return esNodoVacio(arbol.raiz->izquierda) and esNodoVacio(arbol.raiz->derecha);
}

void destruirArbolBinario(struct ArbolBinario & arbol){
    destruirRecursivo(arbol.raiz);
    arbol.raiz = nullptr;
}

void destruirRecursivo(struct NodoArbol * nodo){
    if(not (esNodoVacio(nodo))){
        destruirRecursivo(nodo->izquierda);
        destruirRecursivo(nodo->derecha);
        delete nodo;
    }
}

void eliminaSubArbol(struct ArbolBinario & arbol){
    int nodosEliminados;
    struct NodoArbol * aux ;
    char nodoEliminar = 'D'; 
    if(nodoEliminar == 'D'){ //eliminar derecha
        nodosEliminados = numeroNodosRecursivo(arbol.raiz->derecha);
        aux = arbol.raiz->derecha;
        arbol.raiz->derecha = nullptr;
    }
    else if(nodoEliminar == 'I'){
        nodosEliminados = numeroNodosRecursivo(arbol.raiz->izquierda);
        aux = arbol.raiz->izquierda;
        arbol.raiz->izquierda = nullptr;
    }
    destruirRecursivo(aux);
    arbol.size -= nodosEliminados;
}

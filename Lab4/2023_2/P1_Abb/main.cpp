

/* 
 * File:   main.cpp
 * Author: andre
 *
 * Created on 6 de diciembre de 2024, 01:38 PM
 */

#include <iostream>
#include <iomanip>

#include "ArbolBB.h"
#include "funcionesABB.h"
#include "funcionConstrucionDatos.h"
#include "funcionesAB.h"
#include <climits>
using namespace std;

NodoArbol * busqueda_primer_ancestro_comun_recursivo(NodoArbol *raiz, int valorMenor, int valorMayor) {
    //verifica si estamos en un punto medio
    if (raiz->elemento > valorMenor and raiz->elemento < valorMayor) return raiz;

    //verifica que mayor no sea ancetro de menor
    if (raiz->elemento > valorMayor) {
        if (raiz->izquierda->elemento == valorMayor or raiz->izquierda->elemento == valorMenor)return raiz; //uno es acentro del otro
        return busqueda_primer_ancestro_comun_recursivo(raiz->izquierda, valorMenor, valorMayor);
    } else {
        if (raiz->derecha->elemento == valorMayor or raiz->derecha->elemento == valorMenor)return raiz; //uno es acentro del otro
        return busqueda_primer_ancestro_comun_recursivo(raiz->derecha, valorMenor, valorMayor);
    }
}

NodoArbol* busca_primer_ancestro_comun(const ArbolBinarioBusqueda &arbolPrincipal, int valorA, int valorB) {
    //Primero se evalua si existen almenos esos valores en el nodo
    if (not (buscar(arbolPrincipal, 1) and buscar(arbolPrincipal, 1)) or valorA == valorB) return nullptr;
    int valorMayor, valorMenor;
    //nos aseguramos que entre bien para facilitar la busqueda
    if (valorA > valorB) {
        valorMayor = valorA;
        valorMenor = valorB;
    } else {
        valorMayor = valorB;
        valorMenor = valorA;
    }
    //si lllega aqui es que si exiten ambos valores en el arbol
    return busqueda_primer_ancestro_comun_recursivo(arbolPrincipal.arbolBinario.raiz, valorMenor, valorMayor);
}

void suma_posOrden(NodoArbol *recorridoPricipal,NodoArbol *recorridoSistema){
    
    if (esNodoVacio(recorridoPricipal) or esNodoVacio(recorridoSistema)) return;
    
    recorridoPricipal->elemento += recorridoSistema->elemento;
    suma_posOrden(recorridoPricipal->izquierda,recorridoSistema->izquierda);//todo a la izquierda;
    suma_posOrden(recorridoPricipal->derecha,recorridoSistema->derecha);//todo a la derecha;
}
bool esABBRecursivo(NodoArbol* nodo, int min, int max) {
    if (esNodoVacio(nodo)) return true; // Un árbol vacío es un ABB

    // Verificar si el valor del nodo actual está dentro del rango permitido
    if (nodo->elemento <= min || nodo->elemento >= max) return false;

    // Verificar recursivamente en los subárboles izquierdo y derecho
    return esABBRecursivo(nodo->izquierda, min, nodo->elemento) and
           esABBRecursivo(nodo->derecha, nodo->elemento, max);
}

bool suma_parcial_arboles(NodoArbol *raizPrin,NodoArbol *raizSis,int comun){
    
    //primero se dirigen por los mismos lugares
    NodoArbol *recorridoPricipal = raizPrin;  
    NodoArbol *recorridoSistema = raizSis;  
    while (true) {
        if (recorridoPricipal->elemento == comun)break;
        if (recorridoPricipal->elemento > comun){
            if (recorridoSistema->izquierda == nullptr)return true; //lo termina ya que no se modifica nadano se modifico nada
            recorridoPricipal = recorridoPricipal->izquierda;
            recorridoSistema = recorridoSistema->izquierda;
        }else{
            if (recorridoSistema->derecha == nullptr)return true; //lo termina ya que no se modifica nadano se modifico nada
            recorridoPricipal = recorridoPricipal->derecha;
            recorridoSistema = recorridoSistema->derecha;
        }
    }
    
    //Si llega aqui es por que almenos existe niveles para sumar
    
    //ahora se suman los vlaores
    suma_posOrden(recorridoPricipal,recorridoSistema); 
    return esABBRecursivo(raizPrin, INT_MIN, INT_MAX);
}

void funcionPrincipal(ArbolBinarioBusqueda &arbolPrincipal, int *arrDatosIngresados) {
    //Datos ingresados (lo hago despues)
    //ingresarDatos(arbolPrincipal, arrDatosIngresados);

    // /* comentar el resultado del token
    insertar(arbolPrincipal, 5);
    insertar(arbolPrincipal, 2);
    insertar(arbolPrincipal, 12);
    insertar(arbolPrincipal, 1);
    insertar(arbolPrincipal, 3);
    insertar(arbolPrincipal, 8);
    insertar(arbolPrincipal, 18);
    // */
    ArbolBinario arbolSistema;
    construir(arbolSistema);
    generarArbolSistema(arbolSistema);
    
    //como pide devolver un nul en caso no ea se trabajara con un nodo (pero en este caso es mejor trabajar con el valor )
    NodoArbol *nodoAncestroComun = busca_primer_ancestro_comun(arbolPrincipal, 1, 4);
    //Lo que me interesa es el elemento no el nodo
    if (esNodoVacio(nodoAncestroComun)){
        cout << "No existe comun (uno de los valores no se encuntra en el nodo)" <<endl;
        return;
    }
    bool fueExitosa = suma_parcial_arboles(arbolPrincipal.arbolBinario.raiz,arbolSistema.raiz,nodoAncestroComun->elemento);
    if (fueExitosa == true) cout << "Acceso otorgado"<<endl;
    else cout << "Acceso denegado"<<endl;
}

int main(int argc, char** argv) {
    //a)Crear arbol Token

    ArbolBinarioBusqueda arbolPrincipal;
    construir(arbolPrincipal);
    int arrDatosIngresados[8] = {3, 5, 3, 1, 5, 4, 5, 2};
    //a)Crear arbol Token
    funcionPrincipal(arbolPrincipal, arrDatosIngresados);
    return 0;
}


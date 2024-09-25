/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: david
 *
 * Created on 9 de setiembre de 2024, 10:35
 */

#include <cstdlib>
#include <iostream>
#include "Lista.h"
#include "funcionesLista.h"
using namespace std;

/*
 * 
 */

bool esPrimo(int n){
    int cantDivisores=0;
    for (int i=1; i<=n; i++){
        if (n%i==0){
            cantDivisores++;
        }
    }
    return cantDivisores==2;
}

void eliminarMultiplos(struct Lista & lista,int dato){
    int valor;
    Nodo *recorrido = lista.cabeza;
    while (recorrido->elemento!=dato){
        recorrido = recorrido->siguiente;
    }
    recorrido = recorrido->siguiente;
    while (recorrido!=nullptr){
        valor = recorrido->elemento;
        recorrido = recorrido->siguiente;
        if (valor % dato==0){
            eliminaNodo(lista,valor);
        }
    }
}

int main(int argc, char** argv) {
    int n, dato;
    struct Lista lista;
    construir(lista); /*Paso 1*/
    cout << "Ingrese el valor de n: ";
    cin >> n;
    for (int i=2; i<=n; i++){
        insertarAlFinal(lista,i);
    }
    imprime(lista);
    dato = lista.cabeza->elemento;
    Nodo *recorrido = lista.cabeza;
    while (dato*dato<=n){
        if (esPrimo(dato)){ //paso 4
            eliminarMultiplos(lista,dato); //Paso 5
        }
        recorrido = recorrido->siguiente; //Paso 6
        dato = recorrido->elemento;
    }
    imprime(lista);
    return 0;
}
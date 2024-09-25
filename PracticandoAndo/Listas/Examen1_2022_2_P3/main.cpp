

/* 
 * File:   main.cpp
 * Author: Andrew Max
 *
 * Created on 24 de setiembre de 2024, 18:27
 */

#include <iomanip>
#include <iostream>

using namespace std;
#include "Lista.h"
#include "Nodo.h"
#include "funciones.h"

/*
 * 
 */

bool esPrimo(const int elementoEva, const int dato) {
    int residuo = elementoEva % dato;
//    cout<< dato << " "<<elementoEva <<" "<<residuo<<endl;
    if (residuo == 0)
        return false;
    return true;
}

void funcionEratoste(struct Nodo *nodAct, int dato) {
    struct Lista listaTachados; //Preguntar si mueren los espacios gurdados en esta lista cuando acabe la funcion
    construir(listaTachados);
    struct Nodo *recorrido = nodAct->siguiente;
    struct Nodo *anterior = nodAct;

    while (recorrido != nullptr) {
        if (not esPrimo(recorrido->elemento, dato)) {
            insertarAlFinal(listaTachados, recorrido->elemento);
            anterior->siguiente = recorrido->siguiente;
            delete recorrido;
        } else anterior = recorrido;
        recorrido = anterior->siguiente;
    }

    if (not esListaVacia(listaTachados)) {
        cout << "Numero de Procesado " << dato << endl;
        cout << "Numeros tacahadaos para el " << dato << ": ";
        imprime(listaTachados);
    } else {
        cout << "Numero de Procesado " << dato << ", no tiene numeros tacahados" << endl;
    }
}

int main(int argc, char** argv) {
    //pedir el numero N
    int n = 15;
    //    cout << "Ingrese el valor de N"<<endl;
    //crear la lista de numero hata el n
    struct Lista lista;
    construir(lista);
    for (int i = 2; i <= n; i++) {
        insertarAlFinal(lista, i);
    }
    cout<<"Rango de numeros: ";
    imprime(lista);
    cout<<endl;

    //
    struct Nodo *recorrido = lista.cabeza;
    for (int i = 0; recorrido != nullptr; i++) {
        int dato = recorrido->elemento;
        funcionEratoste(recorrido, dato);
        recorrido = recorrido->siguiente;
        cout<<endl;
    }
    
    cout<<"Los numeros primos en el rango seleccionado son: ";
    imprime(lista);

    return 0;
}


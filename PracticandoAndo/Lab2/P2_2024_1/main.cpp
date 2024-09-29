
/* 
 * File:   main.cpp
 * Author: andre
 *
 * Created on 28 de setiembre de 2024, 22:11
 */

#include <iomanip>
#include <iostream>


using namespace std;
#include "Pila.h"
#include "Lista.h"
#include "Nodo.h"
#include "funcionesPila.h"
#include "funcionesLista.h"

void honi(int n, struct Pila &a, struct Pila &b, struct Pila &c) {
    if (n == 0)return;
    honi(n - 1, a, c, b);
    apilar(c, desapilar(a));
    honi(n - 1, b, a, c);
}

int main(int argc, char** argv) {
    //Primero asumire que la calidad es la misma (luego se implmentara para el caso de claidad)
    struct Lista faja;
    //introducir los valores de la faja
    construir(faja);
    insertarAlInicio(faja, 200);
    insertarAlInicio(faja, 50);
    insertarAlInicio(faja, 150);
    insertarAlInicio(faja, 250);
    insertarAlInicio(faja, 30);
    cout << "La faja esta conformada por los siguintes valores: " << endl;
    imprime(faja);

    //crear pila principal mas pilas auxiliares
    struct Pila prin, aux1, aux2, aux3;
    struct Nodo *mano1;
    construir(prin);
    construir(aux1);
    construir(aux2);
    construir(aux3);

    while (!esListaVacia(faja)) { //si la faja aun tiene elementos se genera la colocacion
        mano1 = obtenerUltimoNodo(faja); //agarra el ultimo elemento de la faja
        apilar(aux3, mano1->elemento); //suelta el nodo una pila aux
        eliminaCola(faja); //quita completamnete el ultimo nodo de la faja
        cout << "nuevo valor:  " << cima(aux3) << endl;
        cout << "Los valores de la pila antes del nuevo ingreso  es: " << endl;
        imprimir(prin);
        if (!esPilaVacia(prin)) {
            int cantiad = longitud(prin);
            for (int i = 0; i <= cantiad; i++) {
                honi(i, prin, aux1, aux2);
                if (esPilaVacia(prin) or cima(prin) > cima(aux3)) {
                    apilar(prin, desapilar(aux3));
                    honi(i, aux2, aux1, prin);
                    break;
                }
                honi(i, aux2, aux1, prin);
            }
        } else {
            apilar(prin, desapilar(aux3));
        }
        cout << "luego que el robot acomode los bloques: " << endl;
        imprimir(prin);
    }
    return 0;
}


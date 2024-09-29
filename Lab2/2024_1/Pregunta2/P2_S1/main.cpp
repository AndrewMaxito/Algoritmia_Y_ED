
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

void mueveCajas(int valorMano1,struct Pila &prin,struct Pila &aux1,struct Pila &aux2,struct Pila &aux3){
    if (esPilaVacia(prin) or valorMano1 < cima(prin)){
        apilar(prin,valorMano1);
        int cantidad = longitud(aux3);
        honi(cantidad,aux3,aux2,prin);
        return ;
    }
    apilar(aux1,desapilar(prin));
    int cant = longitud(aux3);
    honi(cant,aux3,aux2,aux1);
    mueveCajas(valorMano1,prin,aux2,aux3,aux1);
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
    cout << "La faja esta conformada por los siguintes valores: ";
    imprime(faja);
    cout<<endl;

    //crear pila principal mas pilas auxiliares
    struct Pila prin, aux1, aux2, aux3;
    struct Nodo *mano1;
    construir(prin);
    construir(aux1);
    construir(aux2);
    construir(aux3);

    while (!esListaVacia(faja)) { //si la faja aun tiene elementos se genera la colocacion
        mano1 = obtenerUltimoNodo(faja); //agarra el ultimo elemento de la faja
        int valMano1 = mano1->elemento;
        eliminaCola(faja); //quita completamnete el ultimo nodo de la faja
        cout << "ingresa el nuevo valor:  " << valMano1 << endl;
        cout << "Los valores de la pila antes del nuevo ingreso  es: ";
        imprimir(prin);
        cout<<endl;
        mueveCajas(valMano1,prin,aux1,aux2,aux3);     
        cout << "luego que el robot acomode los bloques: ";
        imprimir(prin);
        cout<<endl;
    }
    return 0;
}


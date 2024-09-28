/* 
 * File:   funcionesLista.cpp
 * Author: Ana Roncal
 * 
 * Created on 1 de setiembre de 2024, 22:28
 */
#include <iostream>
#include <iomanip>
#include "Lista.h"
#include "funcionesLista.h"
using namespace std;

/*Valores iniciales de la lista*/
void construir(struct Lista & lista) {
    lista.cabeza = nullptr;
    lista.longitud = 0;
}

/*devuelve si la lista esta vacia 1, caso contrario 0 */
const bool esListaVacia(const struct Lista & lista) {
    return lista.cabeza == nullptr;
}

/*devuelve la longitud de la lista*/
int longitud(const struct Lista  & lista) {
    return lista.longitud;
}

/*inserta un nodo siempre al inicio de la lista*/
void insertarAlInicio(struct Lista & lista, int elemento) {

    /*Se va cambiar por la función crear nodo*/
    struct Nodo * nuevoNodo = new struct Nodo;
    nuevoNodo->elemento = elemento;
    nuevoNodo->siguiente = lista.cabeza;

    lista.cabeza = nuevoNodo;
    lista.longitud++;
}

/*inserta un nodo siempre al final de la lista*/
void insertarAlFinal(struct Lista & lista, int elemento) {

    struct Nodo * ultimoNodo = obtenerUltimoNodo(lista);
    struct Nodo * nuevoNodo = crearNodo(elemento, nullptr);

    if (ultimoNodo == nullptr) /*Si la lista está vacia*/
        lista.cabeza = nuevoNodo; /*se inserta en la cabeza de la lista*/
    else //La lista ya tiene nodos
        ultimoNodo->siguiente = nuevoNodo;
    lista.longitud++;
}

/*Crea un nuevo nodo con los datos dados como parámetros*/
struct Nodo * crearNodo(int elemento, struct Nodo * siguiente) {
    struct Nodo * nuevoNodo = new struct Nodo;
    nuevoNodo->elemento = elemento;
    nuevoNodo->siguiente = siguiente;
    return nuevoNodo;
}

//Notar que esta función retorna nulo cuando la lista es vacía

/*Obtiene el último nodo de la lista*/
struct Nodo * obtenerUltimoNodo(const struct Lista & lista) {
    struct Nodo * ultimo = nullptr;
    struct Nodo* recorrido = lista.cabeza;

    while (recorrido != nullptr) {
        ultimo = recorrido;
        recorrido = recorrido->siguiente;
    }
    return ultimo;
}

/*inserta un nodo en orden*/
void insertarEnOrden(struct Lista & lista, int elemento) {

    struct Nodo * nodoAnterior = obtenerNodoAnterior(lista, elemento);
    struct Nodo * nuevoNodo = crearNodo(elemento, nullptr);
    /*Si nodoAnterior es igual a nulo, la lista está vacia, se debe
     insertar al inicio, no hay nodos menores que elemento*/
    if (nodoAnterior == nullptr) { /*la lista está vacia*/
        nuevoNodo->siguiente = lista.cabeza;
        lista.cabeza = nuevoNodo;
    } else {
        nuevoNodo->siguiente = nodoAnterior->siguiente;
        nodoAnterior->siguiente = nuevoNodo;
    }
    lista.longitud++;
}

/*retorna el anterior al que tiene el elemento*/
struct Nodo * obtenerNodoAnterior(const struct Lista & lista, int elemento) {
    struct Nodo * anterior = nullptr;
    struct Nodo * recorrido = lista.cabeza;
    while ((recorrido != nullptr) and (recorrido->elemento < elemento)) {
        anterior = recorrido;
        recorrido = recorrido->siguiente;
    }
    return anterior;
}

struct Nodo * seEncuentra(const struct Lista & lista, int elemento) {
    struct Nodo * recorrido = lista.cabeza;

    /*retorna el nodo correspondiente al elemento buscado*/
    while ((recorrido != nullptr) and (recorrido->elemento != elemento)) {
        recorrido = recorrido->siguiente;
    }
    return recorrido;
}

int retornaCabeza(const struct Lista & lista){
    return lista.cabeza->elemento;
}

void eliminaNodo(struct Lista & lista, int elemento) {
    struct Nodo * ultimo = nullptr;
    struct Nodo * recorrido = lista.cabeza;
    /*Avanzo hasta encontrar el elemento*/
    /*Si no lo encuentra no elimina nada*/
    while ((recorrido != nullptr) and (recorrido->elemento != elemento)) {
        ultimo = recorrido;
        recorrido = recorrido->siguiente;
    }

    if (recorrido != nullptr) {
        if (ultimo == nullptr) /*Estoy al inicio de la lista*/
            lista.cabeza = recorrido->siguiente;
        else
            ultimo->siguiente = recorrido->siguiente;
        delete recorrido; /*libera la memoria*/
        lista.longitud--;
    }
}

void eliminaCabeza(struct Lista & lista) {
    struct Nodo * nodoAEliminar = lista.cabeza;
    if (nodoAEliminar != nullptr) {
        lista.cabeza = lista.cabeza->siguiente;
        delete nodoAEliminar;
        lista.longitud--;
    }
}

/*Elimina el último elemento de la lista, es llamado cola*/
void eliminaCola(struct Lista lista) {
    struct Nodo * ultimo = nullptr;
    struct Nodo * penultimo = nullptr;
    struct Nodo * recorrido = lista.cabeza;

    while (recorrido != nullptr) {
        if (ultimo != nullptr)
            penultimo = ultimo;
        ultimo = recorrido;
        recorrido = recorrido->siguiente;
    }

    if (ultimo != nullptr) {
        //Si no hay penultimo, se está¡ eliminando el Único nodo de la lista
        if (penultimo == nullptr)
            lista.cabeza = nullptr;
        else
            penultimo->siguiente = nullptr;
        delete ultimo;
        lista.longitud--;
    }
}

void destruir(struct Lista & lista) {
    /*recorrido apunta al inicio del lista*/
    struct Nodo * recorrido = lista.cabeza;

    while (recorrido != nullptr) {
        /*Nodo auxiliar que va servir para eliminar los nodos*/
        struct Nodo * nodoAEliminar = recorrido;
        recorrido = recorrido->siguiente;
        delete nodoAEliminar;
    }
    /*la lista queda vacia*/
    lista.cabeza = nullptr;
    lista.longitud = 0;
}

/*con const aquello que pasas no va cambiar, el compilador se da cuenta que es constante*/
/*Se recorre la lista en forma secuencial*/
/*se utiliza para no modificar la estructura, la proteje de ti mismo*/
/*Si se quiere acceder a los datos, por ejemplo lista.longitud = 20, no te deja
 dado que la estructura es de lectura solamente*/
void imprime(const struct Lista & lista) {
    cout << fixed;
    cout << setprecision(2);
    if (esListaVacia(lista)) {
        cout << "La lista está vacía no se puede mostrar" << endl;
        return;
    } else {
        struct Nodo * recorrido = lista.cabeza;
        int estaImprimiendoLaCabeza = 1;
        cout << "[";

        while (recorrido != nullptr) {
            /*Este artificio coloca la primera coma después de la cabeza*/
            if (not estaImprimiendoLaCabeza)
                cout << ", ";
            estaImprimiendoLaCabeza = 0;
            cout << recorrido->elemento;
            recorrido = recorrido->siguiente;
        }
        cout << "]" << endl;
    }
}
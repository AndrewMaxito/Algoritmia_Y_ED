

/* 
 * File:   main.cpp
 * Author: andre
 *
 * Created on 18 de octubre de 2024, 12:30
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
#include <cmath>

using namespace std;
#include "Pedido.h"
#include "Lista.h"
#include "funcionesLista.h"

/*
 * 
 */
void cargarDatos(struct Lista &listaPedido, const char* nomArch) {
    ifstream arch(nomArch, ios::in);
    if (!arch.is_open()) {
        cout << "No se pudo abrir el archivo " << nomArch << endl;
        exit(1);
    }

    int cantPedidos = 0;
    char buffId[5], complejidad, c;
    int personal, horaPico;


    double preparacion;
    double tiempoViaje;
    double distancia;
    while (true) {
        struct StrPedido pedidos;
        arch.getline(buffId, 5, ',');
        if (arch.eof()) break;
        arch >> complejidad >> c >> personal >> c >> distancia >> c >> horaPico;
        arch.get(); // salto de linea

        //LLenar datos estructura
        strcpy(pedidos.id, buffId);

        //Tiempo de preparacion
        switch (complejidad) {
            case 'b':
                preparacion = 10;
                break;
            case 'm':
                preparacion = 20;
                break;
            case 'a':
                preparacion = 30;
                break;
        }
        if (personal == 0)
            preparacion += 5;

        pedidos.tiempoPreparacion = preparacion;
        //tiempo de llegada 
        tiempoViaje = (distancia * 1.0 / 45)*60;
        if (horaPico == 1)
            tiempoViaje += 10;
        pedidos.tiempoEstimadoViaje = tiempoViaje;
        insertarAlInicio(listaPedido, pedidos);
    }
}

void radix(struct Lista &listaPedido, struct Lista *listasDigitos, int divi) {

    struct Nodo *recorrido = listaPedido.cabeza;
    //sacar por digito
    while (recorrido != nullptr) {
        int tiempoActual = recorrido->elemento.tiempoEstimadoViaje + recorrido->elemento.tiempoPreparacion;
        int digito = ((int) (tiempoActual / divi)) % 10;
        struct StrPedido elemento = recorrido->elemento;
        eliminaCabeza(listaPedido);
        insertarAlFinal(listasDigitos[digito], elemento);
        recorrido = listaPedido.cabeza;
    }
    //devolver a la listaPedidos
    for (int i = 0; i < 10; i++) {
        if (listasDigitos[i].cabeza != nullptr) {
            if (listaPedido.cabeza == nullptr)
                listaPedido.cabeza = listasDigitos[i].cabeza;
            else listaPedido.cola->siguiente = listasDigitos[i].cabeza;

            listaPedido.cola = listasDigitos[i].cola;
            //quita valores
            listasDigitos[i].cabeza = nullptr;
            listasDigitos[i].cola = nullptr;
            listasDigitos[i].longitud = 0;
        }
    }
}

void ordenarLista(struct Lista &listaPedido) {
    int pasada = 2;
    struct Lista listasDigitos[10];
    for (int i = 0; i < 10; i++) {
        construir(listasDigitos[i]);
    }
    for (int i = 0; i < pasada; i++) {
        int divi = pow(10, i);
        radix(listaPedido, listasDigitos, divi);
    }
}

int main(int argc, char** argv) {

    struct Lista listaPedido;
    construir(listaPedido);

    int cantPedidos;
    cargarDatos(listaPedido, "regPedidos.txt");
    ordenarLista(listaPedido);
    imprime(listaPedido);

    return 0;
}


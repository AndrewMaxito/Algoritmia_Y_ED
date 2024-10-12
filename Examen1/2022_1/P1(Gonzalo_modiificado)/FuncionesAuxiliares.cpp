/* 
 * Archivo:   FuncionesAuxiliares.cpp
 * Autor: Gonzalo Quinteros Mostacero
 *
 * Creado el 25 de septiembre de 2024, 09:51 PM
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cmath>
#include "Pila.h"
#include "funcionesPila.h"
#include "FuncionesAuxiliares.h"

using namespace std;

void ingresarContenedor(struct Pila &contenedor, int &cantCajas, int &capacidadCaja) {
    construir(contenedor);
    int cantProductos, fechaCaducidad;
    struct Producto producto;
    ifstream archDatos("Datos.txt", ios::in);
    if (!archDatos) {
        cout << "ERROR: No se pudo abrir el archivo Datos.txt" << endl;
        exit(1);
    }
    archDatos >> cantProductos>>capacidadCaja;
    for (int i = cantProductos; i > 0; i--) {
        archDatos>>fechaCaducidad;
        producto.id = i;
        producto.fechaCaducidad = fechaCaducidad;
        apilar(contenedor, producto);
    }
    // Calcular el numero de cajas necesarias para guardar los productos
    cantCajas = ceil((double) cantProductos / capacidadCaja);
    archDatos.close();
}

void distribuirProductos(struct Pila &contenedor, struct Pila *cajas, int cantCajas, int capacidadCaja) {

    struct Producto paquete;
    for (int i = 0; i < cantCajas; i++) construir(cajas[i]);

    while (not esPilaVacia(contenedor)) {
        paquete = desapilar(contenedor);
        int cajaCorre;
        //buscarCaja donde va el paquete 
        for (int i = 0; i < cantCajas; i++) {
            if (esPilaVacia(cajas[i]) or longitud(cajas[i]) < capacidadCaja or cima(cajas[i]) < paquete.fechaCaducidad) {
                cajaCorre = i;
                break;
            }
        }

        // desapilo uno a uno lo de la caja (apilandolo de nuevo al contenedor)  comparando con la fecha del paquete en mano
        while (esPilaVacia(cajas[cajaCorre]) == false and
                cima(cajas[cajaCorre]) < paquete.fechaCaducidad) {
            apilar(contenedor, desapilar(cajas[cajaCorre])); //si cumple se desapila y se pone de nuevo en el contenedor
        }
        apilar(cajas[cajaCorre], paquete);
    }
}

void mostrarPilas(struct Pila *cajas, int cantCajas) {
    for (int i = 0; i < cantCajas; i++) {
        cout << "Caja " << i + 1 << ": ";
        imprimir(cajas[i]);
    }
}
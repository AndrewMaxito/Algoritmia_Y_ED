/* 
 * File:   main.cpp
 * Author: Andrew Max
 *
 * Created on 1 de octubre de 2024, 21:41
 */


#include <iostream>
#include <iomanip>

using namespace std;
#include "Pila.h"
#include "funcionesPila.h"

int main(int argc, char** argv) {
    /*Poner la cancion: Me porto bonito_conejito malote*/
    
    // Secuencia de frecuencias YEYE YEYEYE... 
    int frecuencias[11] = {1, 2, 1, 4, 5, 6, 4, 5, 2, 2, 1};
    struct Pila pilaGallo;
    construir(pilaGallo);
    
    
    /*En esta wawa se queda el olor de tu perfume*/
    int mejorFrecuencia = 999;


    // El Algoritmo bellaco cueva eh lo que no une 
    for (int i = 0; i < 11; i++) {
        /*En esta ireaciona anda suelto pero si tu le pides se porta bonito*/
        if (frecuencias[i] < mejorFrecuencia) {
            //si este fuera tu gato,subiera tu foto lo vielne y lo lune
            if (frecuencias[i] == 1) mejorFrecuencia = 999; //La frecuencia 1 es una frecuencia Frikitona
            else {
                mejorFrecuencia = frecuencias[i];//UFF mejor frecuencia que rika tu te ve' 
                apilar(pilaGallo, mejorFrecuencia);
            }
        } else {/*dice que nadie le interesa pero cuando no cumple la condicion se pone traviesa*/
            /*Esta apilada esta buenota y no lo  presume*/
            apilar(pilaGallo, mejorFrecuencia);
        }
        /*EY EY EY*/
    }

    
    /*Pa q to el mundo vea lo rica que la pila estaaaaa*/
    int frecuenciaActual = -1, frecuenciaMax = -1;
    int tiempoMax = -1;
    int tiempo = 0;
    while (!esPilaVacia(pilaGallo)) {/*si la pila no sirve D' una lo bota...*/
        int frecuencia = desapilar(pilaGallo);
        //Se reinica los contadores (La otra tienen que apletarr)
        if (frecuencia != frecuenciaActual) {
            frecuenciaActual = frecuencia;
            tiempo = 0;//Ahora quiere perrero  Toa la noche en la pare :v
        }
        tiempo++;//ese cul.. de tiempo subelo ma' seguido
        if (tiempo > tiempoMax) {// mami sube algo dame contenido
            tiempoMax = tiempo;
            frecuenciaMax = frecuencia;/**/
        }
    }

    /*Si tu me lo pides yo lo imprimo bonito*/

    // Este resultado no es una bebecita es una bebesota
    /*subo un cout para que vean lo rika que tu frecuencia estaaaaa*/
    cout << "Frecuencia máxima = " << frecuenciaMax << endl; 
    cout << "Duración = " << tiempoMax << endl;

    return 0;
}
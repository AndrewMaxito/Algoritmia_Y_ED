
/* 
 * File:   main.cpp
 * Author: andre
 *
 * Created on 1 de noviembre de 2024, 15:06
 */

#include <iomanip>
#include <iostream>

using namespace std;

int buscaInicioRadicacion(int *arrRad, int inicio, int fin) {
    if (inicio == fin) return inicio;
    int medio = (inicio + fin) / 2;
    if (arrRad[medio] <= 0) { //descarta derecha
        return buscaInicioRadicacion(arrRad, medio + 1, fin);
    } else {
        return buscaInicioRadicacion(arrRad, inicio, medio);
    }
}

int buscarSinPar(int *arrRad, int inicio, int fin) {
    if (inicio == fin)return arrRad[inicio];
    int medio = (inicio + fin) / 2;
    int cantidadEspacios = fin - inicio + 1;
    int tipo = cantidadEspacios / 2;

    if (tipo % 2 == 0) {
        if (arrRad[medio] == arrRad[medio + 1]) {//descarta izquierda
            return buscarSinPar(arrRad, medio + 2, fin);
        } else return buscarSinPar(arrRad, inicio, medio);
    } else {
        if (arrRad[medio] == arrRad[medio - 1]) {//descarta Izquierda
            return buscarSinPar(arrRad, medio + 1, fin);
        } else return buscarSinPar(arrRad, inicio, medio - 1);
    }
}

int main(int argc, char** argv) {
    int arrRad[] = {-1, 0, -1, 0, 1, 1, 2, 2, 3, 3, 4, 3, 3, 2, 2};
    int n = sizeof (arrRad) / sizeof (arrRad[0]);

    int inicioRad = buscaInicioRadicacion(arrRad, 0, n - 1);
    int potenciaDetonacion = buscarSinPar(arrRad, inicioRad, n - 1);

//    int mejorRad = arrRad[(inicioRad + n - 1) / 2]; //valido solo si tiene los mismos pares antes y despues de la detonacion
    cout << "La radiacion empieza a: " << inicioRad << "Km. Potencia máxima " <<
            potenciaDetonacion << " Megatones" << endl;

    return 0;
}


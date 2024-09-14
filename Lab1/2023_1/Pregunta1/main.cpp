/* 
 * File:   main.cpp
 * Author: andre
 *
 * Created on 2 de septiembre de 2024, 10:41 AM
 */

#include <iomanip>
#include <iostream>
#include <cmath>
using namespace std;

int arrCamiones[4]{25, 50, 100, 100};
int arrPaquetes[5]{50, 20, 30, 50, 20};

void cargarBits(int *arr, int num, int base, int bits) {
    for (int i = 0; i < bits; i++) {
        arr[i] = 0;
    }
    int resto, cant = 0;
    while (num > 0) {
        resto = num % base;
        num /= base;
        arr[cant++] = resto;
    }
}

int main(int argc, char** argv) {
    int cantCamiones = 4; //base= cantCamiones=3 ya que no puede existir un camion vacio
    int cantPaquetes = 5; // cant bits
    int opciones = pow(cantCamiones, cantPaquetes);
    int mejorComb[cantPaquetes]{}, combActual[cantPaquetes];
    int mejorDIF = 999;

    //camion 1 = 0,camion 2 = 1;camion 3 = 2
    for (int i = 0; i < opciones; i++) {
        cargarBits(combActual, i, cantCamiones, cantPaquetes);
        //restircciones
        //1.peso
        bool flag = true;
        int arrPesoActCam[cantCamiones]{};
        for (int j = 0; j < cantPaquetes; j++) {
            int numCam = combActual[j];
            arrPesoActCam[numCam] += (arrPaquetes[j]);
            if (arrPesoActCam[numCam] >= arrCamiones[numCam]) {
                flag = false;
                break;
            }
        }
        if (flag == true) {
            int maxDif = -1, minDif = 999, optimo;
            for (int j = 0; j < cantCamiones; j++) {
                if (minDif > arrCamiones[j] - arrPesoActCam[j]) {
                    minDif = arrCamiones[j] - arrPesoActCam[j];
                }
                if (maxDif < arrCamiones[j] - arrPesoActCam[j]) {
                    maxDif = arrCamiones[j] - arrPesoActCam[j];
                }
            }
            optimo = maxDif - minDif;
            if (optimo < mejorDIF) {
                mejorDIF = optimo;
                for (int j = 0; j < cantPaquetes; j++) {
                    mejorComb[j] = combActual[j];
                }
            }
        }
    }
    cout << "MEJOR SOLUCION" << endl;
    for (int j = 0; j < cantPaquetes; j++) {
        cout << "Paquete: " << j + 1 << "  Camion: " << mejorComb[j] + 1 << endl;
        ;
    }
    cout << "mejor diferencia " << mejorDIF << endl;
    return 0;
}


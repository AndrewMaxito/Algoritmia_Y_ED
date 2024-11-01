

/* 
 * File:   main.cpp
 * Author: andre
 *
 * Created on 31 de octubre de 2024, 16:48
 */

#include <iomanip>
#include <iostream>
using namespace std;

int busBinaria(int *arr, int inicio, int fin, int valorBuscado) {
    if (inicio > fin)return -1;
    
    int medio = (inicio + fin) / 2;
    if (arr[medio] == valorBuscado) {
        return medio;
    } else {
        if (arr[medio] > valorBuscado) {//si el medio es mayor se descarta los valores de la derecha
            busBinaria(arr, inicio, medio-1, valorBuscado);
        } else {//si el medio no es se descarta los valores de la izquierda
            busBinaria(arr, medio+1, fin, valorBuscado);
        }
    }
}

int main(int argc, char** argv) {
    int arr[] = {2, 3, 4, 5, 6, 7, 10, 11};
    int n = sizeof (arr) / sizeof (arr[0]);
    cout << busBinaria(arr, 0, n - 1, 7); //Se solicita  buscar un valor en este jemplo es 7

    return 0;
}


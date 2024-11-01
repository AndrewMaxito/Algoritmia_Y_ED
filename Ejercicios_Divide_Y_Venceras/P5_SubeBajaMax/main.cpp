
/* 
 * File:   main.cpp
 * Author: andre
 *
 * Created on 1 de noviembre de 2024, 12:23
 */

#include <iomanip>
#include <iostream>
using namespace std;

/*
 * 
 */

int subeBajaMax(int *arr, int inicio, int fin) {
    if (inicio == fin) return arr[inicio];
    int medio = (inicio + fin) / 2;
    if (arr[medio] < arr[medio + 1]) {//si el de mi derecha es mayor es que sigue subiendo (descarto la izquierda)
        return subeBajaMax(arr, medio + 1, fin);
    } else {
        return subeBajaMax(arr, inicio, medio);
    }
}

int main(int argc, char** argv) {
    int arrNumeros[] = {8, 10, 20, 80, 100, 200, 400, 500, 3, 2, 1};
    int n = sizeof (arrNumeros) / sizeof (arrNumeros[0]);
    cout << subeBajaMax(arrNumeros, 0, n - 1);
    return 0;
}



/* 
 * File:   main.cpp
 * Author: andre
 *
 * Created on 31 de octubre de 2024, 16:44
 */

#include <iostream>
#include <iomanip>

using namespace std;

int buscaSinPareja(int *arr, int inicio, int fin) {
    if (inicio == fin)return arr[inicio];
    int medio = (inicio + fin) / 2;
    if (medio % 2 == 0) { //si medio es multiplo entre 2
        if (arr[medio] == arr[medio + 1]) {//si es par y el de su  derecha es igual a él se descarta los valores de la izquierda
            return buscaSinPareja(arr, medio+2, fin);
        } else {
            return buscaSinPareja(arr, inicio, medio);
        }
    } else {
        if (arr[medio] == arr[medio - 1]) { //si no es par se descarta lo de la izquierda
            return buscaSinPareja(arr, medio + 1, fin);
        } else {
            return buscaSinPareja(arr, inicio, medio - 1);
        }
    }
}

int main(int argc, char** argv) {
    int arrNumeros[] = {1, 1, 2, 3, 3};
    int n = sizeof (arrNumeros) / sizeof (arrNumeros[0]);
    cout << buscaSinPareja(arrNumeros, 0, n-1);
    return 0;
}


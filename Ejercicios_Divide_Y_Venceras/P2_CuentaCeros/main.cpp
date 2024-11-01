

/* 
 * File:   main.cpp
 * Author: andre
 *
 * Created on 31 de octubre de 2024, 18:25
 */

#include <iostream>
#include <iomanip>

using namespace std;

int cuentaCeros(int *arr, int inicio, int fin, int valorBuscado) {
    if (inicio == fin){
        if (arr[inicio]==valorBuscado) return 1;
        else return 0;
    }
    
    int medio = (inicio + fin) / 2;
    if (arr[medio] == valorBuscado) {//sumo y descarto derecha
        int acumulado = (fin - medio);
        return acumulado + cuentaCeros(arr, inicio, medio, valorBuscado);
    }else{ // descarta todo lo de la izquierda
        return cuentaCeros(arr,medio+1,fin,valorBuscado);
    }
}

int main(int argc, char** argv) {
    int arrNumeros[] = {1, 1, 1 ,1 ,1, 0, 0, 0 ,0 ,0 };
    int n = sizeof (arrNumeros) / sizeof (arrNumeros[0]);
    int valorBuscado = 0; //para ser mas general 
    cout << cuentaCeros(arrNumeros, 0, n - 1, valorBuscado);
    return 0;
}


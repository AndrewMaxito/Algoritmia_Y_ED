/* 
 * File:   main.cpp
 * Author: andreMax
 *
 * Created on 1 de noviembre de 2024, 12:43
 */

#include <iostream>
#include <iomanip>
using namespace std;


int mergeSort(int *arr, int inico, int medio, int fin) {
    int tamArr = fin - inico + 1;
    int arrAux[tamArr];
    int p = inico, q = medio + 1; //p es el contador de la izquida y q de la derecha
    int m = 0; //pos inicial del arreglo auxiliar

    int inversiones = 0;
    while (p <= medio and q <= fin) {
        if (arr[p] <= arr[q])
            arrAux[m++] = arr[p++];
        else {
            arrAux[m++] = arr[q++];
            inversiones += (medio - p + 1); //comoe no solo cumplira para el valor evaluado sino para sus anteriores tambien 
        }
    }
    //copia elementos restantes de la midad izquirda (si hubiera)
    while (p <= medio) {
        arrAux[m++] = arr[p++];
    }
    //copia elementos restnates de la mitad derecha (si hubuiera)
    while (q <= fin) {
        arrAux[m++] = arr[q++];
    }
    
    //copia los elementos ordenados en el arreglo original 
    for (int i = 0; i < tamArr; i++) {
        arr[i+inico] = arrAux[i];
    }
    return inversiones;
}

int mergeSortYCuenta(int *arr, int inico, int fin) {
    if (inico == fin) return 0;
    int inversiones = 0;
    int medio = (inico + fin) / 2;
    inversiones += mergeSortYCuenta(arr, inico, medio); //izquierda
    inversiones += mergeSortYCuenta(arr, medio + 1, fin); //derecha
    inversiones += mergeSort(arr, inico, medio, fin); // cuenta las inversiones 
    return inversiones;
}

int main(int argc, char** argv) {
    int arrNumeros[] = {10, 5, 8, 2, 5, 3};
    int n = sizeof (arrNumeros) / sizeof (arrNumeros[0]);
    cout << "Número de inversiones: " << mergeSortYCuenta(arrNumeros, 0, n - 1) << endl;
    return 0;
}


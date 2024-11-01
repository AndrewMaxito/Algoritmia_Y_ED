

/* 
 * File:   main.cpp
 * Author: andre
 *
 * Created on 31 de octubre de 2024, 20:34
 */

#include <iomanip>
#include <iostream>
#include <limits.h>
using namespace std;

int max_compara(int valorA,int valorB){
    if (valorA > valorB) return valorA;
    return valorB;
}

int sumaMaximaCruzada(int arr[], int inicio, int medio, int fin) {
    int suma_izq = INT_MIN;
    int suma = 0;

    // Buscar lo mejor consecutivo desde el medio hacia la izquierda ( <-medio )
    for (int i = medio; i >= inicio; i--) {
        suma += arr[i];
        suma_izq = max_compara(suma_izq, suma);
    }

    int suma_der = INT_MIN;
    suma = 0;

    // Buscar lo mejor consecutivo desde el medio hacia la Derecha (medio ->)
    for (int i = medio + 1; i <= fin; i++) {
        suma += arr[i];
        suma_der = max_compara(suma_der, suma);
    }

    // devuleve el mejor valor si se fuera a combinar
    return suma_izq + suma_der;
}

int sumaMaxima(int *arr,int  inicio,int fin){
    if (inicio == fin) return arr[inicio];
    int medio = (inicio+fin)/2;
    
    //calcular la suma de la izquierda mas la derecha
    int sumaIzq = sumaMaxima(arr,inicio,medio);//mejor combinacion de la izquierda
    int sumaDer = sumaMaxima(arr,medio+1,fin); // mejor combinacion de la derecha
    int sumaCombinacion = sumaMaximaCruzada(arr, inicio, medio, fin); // mejor combinacion de la combinacion
    
    return max_compara(sumaIzq, max_compara(sumaDer, sumaCombinacion));
}

int main(int argc, char** argv) {
    int arr[] = {-2, -5, 6, -2, -3, 1, 5, -6};
    int n = sizeof (arr) / sizeof (arr[0]);
   
    cout << "La suma máxima  es: " << sumaMaxima(arr, 0, n - 1) << endl;
    return 0;
}


/* 
 * File:   main.cpp
 * Author: andre
 *
 * Created on 1 de noviembre de 2024, 14:33
 */

#include <iostream>
#include <iomanip>
using namespace std;

int menorValor(int valorA, int ValorB){
    if (valorA < ValorB)return valorA;
    else return ValorB;
}

int sumaCombinado(int *arr,int inicio,int medio,int fin){
    int suma = 0;
    //Evalua mitad izquierda
    int suma_izquierda = 999;
    for (int i = medio; i >= inicio; i--) {
        suma += arr[i];
        suma_izquierda = menorValor(suma_izquierda,suma); 
    }
    
    //Evalua la mitdad hacia la derecha 
    suma = 0;
    int suma_Derecha= 999;
    for (int i = medio+1; i <= fin; i++) {
        suma += arr[i];
        suma_Derecha = menorValor(suma_Derecha,suma); 
    }
    return suma_izquierda + suma_Derecha;
}


int sumaContiguos(int *arrMarcas,int inicio,int fin){
    if (inicio == fin) return 0;
    int medio = (inicio+fin)/2;
    int sumaIzqui = sumaContiguos(arrMarcas,inicio,medio);//izquierda
    int sumaDer = sumaContiguos(arrMarcas,medio+1,fin);//Derecha
    int sumaCombi = sumaCombinado(arrMarcas,inicio,medio,fin);//combina izquierda-Derecha
    
    //devolvera lo mejor (el menor valor encontrado)
    return menorValor(sumaIzqui,menorValor(sumaDer,sumaCombi));
}
int main(int argc, char** argv) {

    int arrMarcas1[] = {2, 5, -6, 2, 3, -1, -5, 6};
    int n = sizeof (arrMarcas1) / sizeof (arrMarcas1[0]);
    cout << "La acumulacion negtiva mas alta es: " << sumaContiguos(arrMarcas1, 0, n - 1) << endl;
    
    
    int arrMarcas2[] = {2, -3, 4, -5, -7};
    n = sizeof (arrMarcas2) / sizeof (arrMarcas2[0]);
    cout << "La acumulacion negtiva mas alta es: " << sumaContiguos(arrMarcas2, 0, n - 1) << endl;
    
    int arrMarcas3[] = {-4, 5, 6, -4, 3, -1, -5, 6};
    n = sizeof (arrMarcas3) / sizeof (arrMarcas3[0]);
    cout << "La acumulacion negtiva mas alta es: " << sumaContiguos(arrMarcas3, 0, n - 1) << endl;
    return 0;
}


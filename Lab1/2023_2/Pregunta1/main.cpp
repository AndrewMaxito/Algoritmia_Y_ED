
/* 
 * File:   main.cpp
 * Author: andre
 *
 * Created on 1 de septiembre de 2024, 05:48 PM
 */

#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;
int pesos[4][4]{
    {20, 20, 20, 20},
    {10, 30, 10, 30},
    {10, 10, 10, 10},
    {15, 15, 15, 15}
};
int precios[4][4]{
    {10, 10, 10, 50},
    {80, 10, 10, 20},
    {20, 20, 20, 20},
    {50, 50, 50, 50}
};
int n = 4, pesMaxBarco = 100;

void cargaBits(int *comb, int num, int base, int bits) {
    for (int i = 0; i < bits; i++) {
        comb[i] = 0;
    }
    int resto, j = 0;
    while (num > 0) {
        resto = num % base;
        num = num / base;
        comb[j++] = resto;
    }
}

bool evaluarOpc(int *comb, int &precioActual) {
    int pesoActual = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int posArr = n * i + j;
            pesoActual += (comb[posArr]) * pesos[i][j];
            precioActual += (comb[posArr]) * precios[i][j];
            if (pesoActual > pesMaxBarco) {
                precioActual = 0;
                return false;
            }
        }
    }
    return true;
}

void guardarComb(int *comb, int *mejorComb, int cantConte) {
    for (int i = 0; i < cantConte; i++) {
        mejorComb[i] = comb[i];
    }
}

void imprimirContenedor(int *mejorComb){
    //Imprime Pesos
    cout<<"Pesos (Toneladas)"<<endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int posArr = n * i + j;
            cout << setw(5)<<mejorComb[posArr]*(pesos[i][j])<<"   ";
        }
        cout<<endl;
    }
    //Imprime Valores
    cout<<"Valores (Miles de $)"<<endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int posArr = n * i + j;
            cout << setw(5)<<mejorComb[posArr]*(precios[i][j])<<"   ";
        }
        cout<<endl;
    }
}

int main(int argc, char** argv) {

    int barco = 1; //un solo barco
    int cantConte = 16; //numero de bits
    int base = barco + 1; //se pasa a base 2-> 1 para los que iran en le barco y 0 para los que se quedan
    int opciones = pow(base, cantConte);
    int comb[cantConte], mejorComb[cantConte], mejorPrecio = 0;


    for (int i = 0; i < opciones; i++) {
        cargaBits(comb, i, base, cantConte);
        //restricciones 
        //1. Peso y precio 
        int precioActual = 0;
        bool evaluar = evaluarOpc(comb,precioActual);
        if (evaluar == true and mejorPrecio < precioActual) {
            guardarComb(comb, mejorComb, cantConte);
            mejorPrecio = precioActual;
        }
    }
    cout<<"Valor Maximo "<<mejorPrecio<<" (en miles de $)"<<endl;
    
    imprimirContenedor(mejorComb);
    
    return 0;
}


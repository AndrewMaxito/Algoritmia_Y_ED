/* 
 * File:   main.cpp
 * Author: Ana Roncal
 *
 * Created on 1 de setiembre de 2024, 22:23
 */

#include <iostream>
#include "Pila.h"
#include "funcionesPila.h"
using namespace std;

void pasapila(Pila &pila1,Pila &pila2){
    int valor,aux,n;
    
    while(!esPilaVacia(pila1)){
        n=0;
        valor=desapilar(pila1);
        while(!esPilaVacia(pila1)){
            apilar(pila2,valor);
            valor=desapilar(pila1);
            n++;
        }
        while(!esPilaVacia(pila2) and n>0){
            aux=desapilar(pila2);
            apilar(pila1,aux);
            n--;
        }
        apilar(pila2,valor);
    }
}
void ordenarec(Pila &pila1,int n){
    int valor,max,aux,i=n-1;
    Pila pila2;
    
    construir(pila2);
    if(n==0) return;
    max=desapilar(pila1);
    while(i>0){
        valor=desapilar(pila1);
        if(valor>max){
            apilar(pila2,max);
            max = valor;
        }
        else
            apilar(pila2,valor);
        i--;
    }
    apilar(pila1,max);
    while(!esPilaVacia(pila2)){
        aux=desapilar(pila2);
        apilar(pila1,aux);
    }
    ordenarec(pila1,n-1);
}

void hanoi(int n,Pila &a,Pila &b,Pila &c){
    
    if(n==0) return;
    hanoi(n-1,a,c,b);
    apilar(c,desapilar(a));
    hanoi(n-1,b,a,c);
    
}


int main(int argc, char** argv) {
    /**/
    struct Pila pila,pfin;
    construir(pila);
    /*Apilamos elementos en la pila*/
    apilar(pila, 10);
    apilar(pila, 2);
    apilar(pila, 30);
    apilar(pila, 4);
    imprimir(pila);
    
    construir(pfin);
    pasapila(pila,pfin);
    imprimir(pfin);
    ordenarec(pfin,longitud(pfin));
    imprimir(pfin);
 
    return 0;
}


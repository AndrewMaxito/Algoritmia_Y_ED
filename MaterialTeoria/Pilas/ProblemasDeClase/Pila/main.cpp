/* 
 * File:   main.cpp
 * Author: Ana Roncal
 *
 * Created on 1 de setiembre de 2024, 22:23
 */

#include <iostream>
#include "Pila.h"
#include "funcionesPila.h"
#include "funcionesLista.h"
using namespace std;

void pasapila(Pila &pila1,Pila &pila2){
    int valor,aux,n;
    
    while(!esPilaVacia(pila1)){
        n=0;
        valor=desapilar(pila1);
        //Desapila la pila1 y lo pone en la pila 2 a excepcion del ultimo elemento
        //si hay n elementos en lapila lo siguiente mandara que hay n-1 elemetos (el otro esta en la mano) 
        while(!esPilaVacia(pila1)){
            apilar(pila2,valor);
            valor=desapilar(pila1);
            n++;
        }
        //ddevolvera los elemntos ingresados en esa iteracion menos el que esta en la mano
        while(!esPilaVacia(pila2) and n>0){
            aux=desapilar(pila2);
            apilar(pila1,aux);
            n--;
        }
        apilar(pila2,valor);// ahora ingresa el valor de la mano a la pila 2 
    }
}


void pasapilaRec(struct Pila &pila1,struct Pila &pila2){
    if (esPilaVacia(pila1)) return ;
    int valor = desapilar(pila1);//si la pila no esta vacia se desapila y guarda el valor 
    pasapilaRec(pila1,pila2);//evalua el siguiente elemento 
    apilar(pila2,valor);//Inserta el valor del elemento en la nueva pila
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

void hanoi(int n,Pila &a,Pila &b,Pila &c){ //a= pila_origen, b=pila_auxiliar, c=pila_destino, n cantidad de discos
    
    if(n==0) return;
    hanoi(n-1,a,c,b);
     
    apilar(c,desapilar(a));
    
    
    
    hanoi(n-1,b,a,c);
    cout<<"hani------"<<endl;
    imprimir(a);
    cout<<endl;
   
    
}


int main(int argc, char** argv) {
    /**/
    struct Pila pila,pfin,b;
    construir(pila);
    /*Apilamos elementos en la pila*/
    apilar(pila, 10);
    apilar(pila, 2);
    apilar(pila, 30);
    apilar(pila, 4);
//    cout<<"Pila incial: "<<endl;
//    imprimir(pila);
//    
    construir(pfin);
    construir(b);
//    pasapilaRec(pila,pfin);
//    //pasapila(pila,pfin);
//    cout<<"Mostrar pila copiada: "<<endl;
//    imprimir(pfin);
//    
//    ordenarec(pfin,longitud(pfin));
//    cout<<"Motsrar la nueva pila ordenada: "<<endl;
//    imprimir(pfin);
    hanoi(4,pila,b,pfin);
    cout<<"luego de Hanoi"<<endl;
    imprimir(pfin);
    return 0;
}


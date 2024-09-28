/* 
 * File:   main.cpp
 * Author: Ana Roncal
 *
 * Created on 1 de setiembre de 2024, 22:23
 */

#include <iostream>
#include "Pila.h"
#include "funcionesPila.h"
#define N 7
using namespace std;

//int red[N][N]={ {0,0,0,0,0,0,0},
//                {10,0,20,30,0,20,40},
//                {0,0,0,0,0,100,0},
//                {0,0,0,0,0,80,0},
//                {50,10,5,10,0,100,4},
//                {100,0,0,0,0,0,0},
//                {0,0,0,0,0,0,0}};

int red[N][N]={ {0,0,0,0,0,0,0},
                {10,0,20,30,0,20,40},
                {0,0,0,0,0,100,0},
                {0,0,0,0,0,80,0},
                {50,0,5,10,0,100,4},
                {100,0,0,0,0,0,0},
                {0,0,0,0,0,0,0}};

int buscasky(int n){
    Pila stack;
    int a,b,cand,flag=1;
    
    construir(stack);
    for(int i=0;i<n;i++)apilar(stack,i);
    while(longitud(stack)>1){
        a=desapilar(stack);
        b=desapilar(stack);
        if(red[a][b]==0)apilar(stack,b);
        else apilar(stack,a);
    }
    cand = desapilar(stack);
    for(int i=0;i<n;i++)
        if(not red[cand][i] and i!=cand)
            flag=0;
    if(flag==1)
        for(int i=0;i<n;i++)
            if(red[i][cand]!=0)
                flag=0;
    if(flag==1)
        return cand+1;
    return -1;    
}




int main(int argc, char** argv) {
    int n=N;
    
    cout <<"El servidor es:"<< buscasky(n);
    
    return 0;
}


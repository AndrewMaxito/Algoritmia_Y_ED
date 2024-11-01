
/* 
 * File:   main.cpp
 * Author: andre
 *
 * Created on 31 de octubre de 2024, 19:21
 */

#include <iostream>
#include <iomanip>

using namespace std;

int subeBajaBuscaMenor(int *arr,int inicio,int fin){
    if (inicio == fin){
        return arr[inicio];
    }
    int medio = (inicio+fin)/2;
    if (arr[medio] > arr[fin]) {//descarto la midad izquierda
        return subeBajaBuscaMenor(arr,medio+1,fin);
    } else {
        return subeBajaBuscaMenor(arr,inicio,medio);
    }
}


int main(int argc, char** argv) {
    int arrNumeros[] = {10, 5, 6, 7, 8, 9};
    int n = sizeof(arrNumeros) / sizeof(arrNumeros[0]);
    cout << subeBajaBuscaMenor(arrNumeros,0,n-1);
    return 0;
}

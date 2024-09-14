
/* 
 * File:   main.cpp
 * Author: andre
 *
 * Created on 4 de septiembre de 2024, 05:58 PM
 */

#include <iomanip>  
#include <iostream>
#include <cmath>

using namespace std;

/*
 * 
 */
void imprimirAsteriscos(int n) {
    for (int i = 0; i < n; i++) {
        cout << "* ";
    }
    cout << endl; //salto
}

void patron(int n, int i) {
    if (n == 0) return;
    patron(n / 2, i); //como si empezara de menor a mayor

    for (int j = 0; j < i; j++) {
        cout << "  ";
    }
    imprimirAsteriscos(n);
    patron(n / 2,i+ n / 2); //como si empezara de mayor a menor
}

int main(int argc, char** argv) {
    int n = 4, i = 0;
    patron(n, i);
    return 0;
}
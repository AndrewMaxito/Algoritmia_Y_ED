

/* 
 * File:   main.cpp
 * Author: andre
 *
 * Created on 5 de septiembre de 2024, 03:29 PM
 */

#include <iomanip>
#include <iostream>

using namespace std;

void imprimirAsteriscos(int a){
    for (int i = 0; i < a; i++) {
        cout << "* ";
    }
    cout<<endl;
}

void triangulo(int a, int b) {
    if (a > b) return;
    imprimirAsteriscos(a);
    triangulo(a+1,b);
    imprimirAsteriscos(a);
}

int main(int argc, char** argv) {
    int a = 3, b = 5;
    triangulo(a, b);
    return 0;
}


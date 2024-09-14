/* 
 * File:   main.cpp
 * Author: andre
 *
 * Created on 1 de septiembre de 2024, 06:57 PM
 */

#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;


char barco[4][10]{
    {'H', 'C', 'H', 'B', 'Y', 'S', 'O', 'S', 'O', 'H'},
    {'S', 'C', 'S', 'S', 'Y', 'Q', 'O', 'S', 'Z', 'K'},
    {'O', 'P', 'N', 'Y', 'O', 'K', 'F', 'H', 'C', 'K'},
    {'O', 'B', 'N', 'I', 'Y', 'S', 'P', 'O', 'O', 'K'}
};

char palabra[3]{'H', 'S', 'O'}; //0,1,2

int movimientos[4][2]{
    {-1, 0}, //arriba
    {1, 0}, //abajo
    {0, -1}, //izquirda
    {0, 1}//derecha
};
int filas = 4, columnas = 10;

void cargarBit(int *comb, int num, int base, int bits) {
    for (int i = 0; i < bits; i++) {
        comb[i] = 0;
    }
    int rest, cant = 0;
    while (num > 0) {
        rest = num % base;
        num = num / base;
        comb[cant++] = rest;
    }
}

bool busca(int x, int y, int *comb) {
    
    int posCom = comb[0];
    if (barco[x][y] != palabra[posCom]) return false;
    int nX, nY; //nuevo X nuevo Y  
    
    //Usa los posibles movimientos
    for (int i = 0; i < 4; i++) {
        nX = x + movimientos[i][0];
        nY = y + movimientos[i][1];
        int j;
        for (j = 1; j < 3; j++) { //3 = cantidad de palabras, empieza en q ya qye ya se evaluo
            posCom = comb[j];
            if (nX >= filas or nX < 0 or nY >= columnas or nY < 0) break;
            if (barco[nX][nY] != palabra[posCom]) break;
            //Si llega hasta aqui actuliza el movimiento 
            nX = nX + movimientos[i][0];
            nY = nY + movimientos[i][1];
        }
        if (j == 3) return true;
    }
    return false;
}

void buscarPalabras(int *comb) {
    for (int x = 0; x < filas; x++) {
        for (int y = 0; y < columnas; y++) {
            if (busca(x, y, comb)) {
                cout << "Combinación encontrada en (" << x << ", " << y << ") " << endl;
            }
        }
    }
}



bool esCombinacionValida(int *comb, int bits) {
    // Verificar si todos los bits son iguales, en ese caso la combinación no es válida
    for (int i = 0; i < bits - 1; i++) {
        for (int j = i + 1; j < bits; j++) {
            if (comb[i] == comb[j]) {
                return false; //si encuentra una similitud, descarta  
            }
        }
    }
    return true; // Todos los bits son diferente, la combinancion es válida
}

int main(int argc, char** argv) {
    int base = 3, bits = 3;// bits = cantidad de opciones ; base = cantidad de elemntos
    int opciones = pow(base, bits);
    int comb[bits];
    
    for (int i = 0; i < opciones; i++) {
        cargarBit(comb, i, base, bits); //carga la opcion
        if (esCombinacionValida(comb, bits)) {//si es verdad busca esa combinacion en barco (pupiletras)
            buscarPalabras(comb);
        }
    }
    return 0;
}

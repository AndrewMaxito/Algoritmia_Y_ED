/* 
 * File:   main.cpp
 * Author: Andew Max B.
 *
 * Created on 13 de septiembre de 2024, 06:19 PM
 */

#include <iostream>
#include <iomanip>

using namespace std;

int matrizTabla[6][6]{
    {0, 0, 0, 1, 0, 1},
    {0, 0, 1, 0, 0, 0},
    {0, 1, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0},
    {0, 1, 0, 0, 1, 0},
    {0, 0, 0, 0, 1, 0},
};

int cuentaUnidadesEncontradas(int posX, int posY, int sonda) {
    int uniEncon = 0;
    if (sonda == 0) return matrizTabla[posX][posY];
    for (int i = -sonda; i <= sonda; i++) {
        uniEncon += matrizTabla[posX - i][posY - sonda] + matrizTabla[posX - i][posY + sonda];
        if (i != sonda and i != -sonda) {
            uniEncon += matrizTabla[posX - sonda][posY - i] + matrizTabla[posX + sonda][posY + i];
        }
    }
    return uniEncon;
}

int buscarUnidadPorSonda(int posX, int posY, int fila, int columa, int sonda) {
    if (posX + sonda > fila - 1 or posX - sonda < 0 or posY + sonda > columa - 1 or posY - sonda < 0)return 0; //evaluo que sea posible
    //cuenta unidades
    int unidadesEncontradas = cuentaUnidadesEncontradas(posX, posY, sonda);
    return unidadesEncontradas + buscarUnidadPorSonda(posX, posY, fila, columa, sonda + 1);
}

int main(int argc, char** argv) {
    int N = 6, M = 6;
    int posX = 4, posY = 4;
    int cantUni = buscarUnidadPorSonda(posX, posY, N, M, 0);
    cout <<"Unidades encontradas: "<< cantUni << endl;
    return 0;
}


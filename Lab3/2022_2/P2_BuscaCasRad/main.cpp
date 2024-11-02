/* 
 * File:   main.cpp
 * Author: andre
 *
 * Created on 1 de noviembre de 2024, 20:15
 */



#include <iostream>
#include <iomanip>
using namespace std;

/*solucon Mejorada (El primer inento esta mas abajo)*/
void buscaMaximoEnFila(int filaEvaluada, int tablero[][7], int inicio, int fin, int &columnaMax, int &valorMax) {
    if (inicio == fin) {
        columnaMax = inicio;
        valorMax = tablero[filaEvaluada][inicio];
        return;
    }

    int med = (inicio + fin) / 2;
    if (tablero[filaEvaluada][med] < tablero[filaEvaluada][med + 1]) { //es un subeBaja Busca Max 
        buscaMaximoEnFila(filaEvaluada, tablero, med + 1, fin, columnaMax, valorMax);
    } else {//en caso sea = igual se descarta la derecha ya que no subira mas ejm (1221),(123321)
        buscaMaximoEnFila(filaEvaluada, tablero, inicio, med, columnaMax, valorMax);
    }
}

void potenciaMaxima(int filas, int columnas, int tablero[][7], int &columnaEncontrada, int &potencia) {
    int medioColumna = (columnas - 1) / 2;

    for (int i = 0; i < filas; i++) {
        int columnaLocal, valorMaximoFila;

        // Aplicamos divide y vencerás en el rango completo de columnas, desde la primera hasta la última columna (como un arreglo unidimensional)
        buscaMaximoEnFila(i, tablero, 0, columnas - 1, columnaLocal, valorMaximoFila);

        // Actualiza la potencia máxima y la columna si encontramos un nuevo máximo
        if (valorMaximoFila > potencia) {
            potencia = valorMaximoFila;
            columnaEncontrada = columnaLocal;
            //si se quiere la final solo poner aqui (para la b)
        }
    }
}

int main(int argc, char **argv) {

    int filas = 8, columnas = 7;
    int columnaEncontrada, potencia = 0;
    int tablero[8][7] = {
        {0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0},
        {1, 1, 1, 0, 0, 0, 0},
        {1, 2, 1, 0, 0, 0, 0},
        {1, 1, 1, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0}
    };

    potenciaMaxima(filas, columnas, tablero, columnaEncontrada, potencia);
    cout << "Columna: " << columnaEncontrada << " con potencia máxima de: " << potencia << endl;
    return 0;
}

/*Casos de Prueba*/
/*
 * 
 * 
 * int filas = 8, columnas = 7;
    int columnaEncontrada, potencia = 0;
    int tablero[8][7] = {
        {0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0},
        {1, 1, 1, 0, 0, 0, 0},
        {1, 2, 1, 0, 0, 0, 0},
        {1, 1, 1, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0}
    };
 * 
 * 
 int filas = 8, columnas = 7;
    int columnaEncontrada, potencia = 0;
    int tablero[8][7] = {
        {0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0},
        {0, 0, 1, 1, 1, 0, 0},
        {0, 0, 1, 2, 1, 0, 0},
        {0, 0, 1, 1, 1, 0, 0},
        {0, 0, 0, 0, 0, 0, 0}
    };
 * 
 int filas = 8, columnas = 7;
    int columnaEncontrada, potencia = 0;
    int tablero[8][7] = {
        {0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0},
        {0, 1, 1, 1, 0, 0, 0},
        {0, 1, 2, 1, 0, 0, 0},
        {0, 1, 1, 1, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0}
    };
 * 
 * int filas = 8, columnas = 7;
    int columnaEncontrada, potencia = 0;
    int tablero[8][7] = {
        {0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0},
        {1, 1, 1, 1, 1, 0, 0},
        {1, 2, 2, 2, 1, 0, 0},
        {1, 2, 3, 2, 1, 0, 0},
        {1, 2, 2, 2, 1, 0, 0},
        {1, 1, 1, 1, 1, 0, 0}
    };
 * 
 * 
 int filas = 10, columnas = 7;
    int columnaEncontrada, potencia = 0;
    int tablero[10][7] = {
        {0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 1, 1, 1},
        {0, 0, 0, 0, 1, 2, 2},
        {0, 0, 0, 0, 1, 2, 3},
        {0, 0, 0, 0, 1, 2, 2},
        {0, 0, 0, 0, 1, 1, 1},
        {0, 0, 0, 0, 0, 0, 0}
    };
 * 
 * 
 * int filas = 8, columnas = 7;
    int columnaEncontrada, potencia = 0;
    int tablero[8][7] = {
        {0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0},
        {1, 1, 1, 1, 0, 0, 0},
        {2, 2, 2, 1, 0, 0, 0},
        {2, 3, 2, 1, 0, 0, 0},
        {2, 2, 2, 1, 0, 0, 0},
        {1, 1, 1, 1, 0, 0, 0}
    };
 
 */

/*SOlucion Inicial*/

//
//#include <iostream>
//#include <iomanip>
//using namespace std;
//
//int maxValor(int valorA,int valorB){
//    if (valorA > valorB)return valorA;
//    return valorB;
//}
//
//int buscaMaximoEnFila(int filaEvaluada, int tablero[][7],int  inicio, int fin){
//    if (inicio == fin){
//        return inicio;
//    }
//    int med = (inicio+fin)/2;
//    if (tablero[filaEvaluada][med] < tablero[filaEvaluada][med+1] ){
//        return buscaMaximoEnFila( filaEvaluada,  tablero,  med+1,  fin);
//    }else{
//        return buscaMaximoEnFila( filaEvaluada,  tablero,  inicio,  med);
//    }
//}
//
//
//void potenciaMaxima(int filas,int columnas,int tablero[][7],int &columnaEcontrada,int &potencia){
//    int medioColumna = (columnas-1)/2; //cantidad de datos (trabajandolo como un arreglo unidimensional)
//    int posMaxEncontrado,maxPotenciaFila;
//    for (int i = 0; i < filas; i++) {
//        if (tablero[i][medioColumna-1] != tablero[i][medioColumna+1] ){ //si iguales no se puede determinar que lado evaluar
//            if (tablero[i][medioColumna-1] > tablero[i][medioColumna+1]){//esta a la derecha
//                posMaxEncontrado = buscaMaximoEnFila(i, tablero, 0, medioColumna - 1);
//            }else{
//                posMaxEncontrado = buscaMaximoEnFila(i, tablero, medioColumna +1, columnas-1);
//            }
//        }else{
//            //si ambos valores son iguales se valida el medio
//            posMaxEncontrado = medioColumna;
//        }
//        maxPotenciaFila = tablero[i][posMaxEncontrado];
//        if (maxPotenciaFila > potencia){
//            columnaEcontrada = posMaxEncontrado;
//            potencia = maxPotenciaFila;
//        }
//    }    
//}
//
//int main(int argc, char** argv) {
//    int filas = 10 ,columnas=7;
//    int columnaEcontrada,potencia=0;
//    int tablero[10][7]{
//        {0 ,0 ,0 ,0 ,0 ,0 ,0},
//        {0 ,0 ,0 ,0 ,0 ,0 ,0},
//        {0 ,0 ,0 ,0 ,0 ,0 ,0},
//        {0 ,0 ,0 ,0 ,0 ,0 ,0},
//        {0 ,0 ,0 ,0 ,1 ,1 ,1},
//        {0 ,0 ,0 ,0 ,1 ,2 ,2},
//        {0 ,0 ,0 ,0 ,1 ,2 ,3},
//        {0 ,0 ,0 ,0 ,1 ,2 ,2},
//        {0 ,0 ,0 ,0 ,1 ,1 ,1},
//        {0 ,0 ,0 ,0 ,0 ,0 ,0}
//    };
//    
//    potenciaMaxima(filas,columnas,tablero,columnaEcontrada,potencia);
//    cout << "columna "<<columnaEcontrada<<" maximo "<<potencia<<endl;
//    return 0;
//}
//
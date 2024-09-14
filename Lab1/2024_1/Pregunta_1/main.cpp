/* 
 * File:   main.cpp
 * Author: andre
 *
 * Created on 26 de agosto de 2024, 15:07
 */

#include <iostream>
#include <iomanip>
#include <cmath>
#include <fstream>

using namespace std;
#include "armas.h"
#include "Guerrero.h"

void cargaBits(int num, int bas, int bits, int *combGen) {
    int res;
    for (int i = 0; i < bits; i++)
        combGen[i] = 0;
    int i = 0;
    while (num > 0) {
        res = num % bas;
        num = num / bas;
        combGen[i++] = res;
    }
}

int main(int argc, char** argv) {
    struct Armas arrArm[12];
    struct Guerrero arrGuerr[3];

    //Cargar Esteucturas 
    //1.estructura arma
    ifstream archArm("armas.txt", ios::in);
    ifstream archGuerreros("Guerreros.txt", ios::in);
    if (!archArm.is_open()) {
        cout << "No se pudo abrir el arch armas.txt" << endl;
        exit(1);
    }
    if (!archGuerreros.is_open()) {
        cout << "No se pudo abrir el arch Guerreros.txt" << endl;
        exit(1);
    }
    //1.estructura arma
    char letra;
    int contArm = 0;


    while (true) {
        //D 25 2 R
        archArm >> letra;
        if (archArm.eof()) break;
        arrArm[contArm].letra = letra;
        archArm >> arrArm[contArm].poder >> arrArm[contArm].tipo;
        arrArm[contArm].cantReq = 0;
        while (archArm.get() != '\n') {
            int cantReq = arrArm[contArm].cantReq;
            archArm >> arrArm[contArm].req[cantReq];
            arrArm[contArm].cantReq++;
        }
        contArm++;
    }

    //2. estructura de guerreros
    int num, contGue=0;
    while (true) {
        archGuerreros >> num;
        if (archGuerreros.eof()) break;
        arrGuerr[contGue].numero = num;
        archGuerreros >> arrGuerr[contGue].poder;
        arrGuerr[contGue].cant = 0;
        while (archGuerreros.get() != '\n') {
            int cant = arrGuerr[contGue].cant;
            archGuerreros >> arrGuerr[contGue].tipoArma[cant];
            arrGuerr[contGue].cant++;
        }
        contGue++;
    }
    ///////////////////////////////////////////////////////////////////////////////////////////////
    
 
    
    
    //Pregunta2  creacion del algortimo
    int cantGue = 3, cantArmas = 12;// cantArmas= cantidad de "bits" ->(para las combinaciones) 
    int base = cantGue+1;// base = mochila +1 ->(tomando una mochila "nula")
    int cantOpc = pow(base, cantArmas); //numero de posibilidades
    int combGen[cantArmas]; //opcion expresada en la base requerida
    int mejorCombi[12]{};// Guarda la mejor alternativa para su impresion
    
    
    
    int mejorPoder = 999;
    for (int i = 0; i < cantOpc; i++) {
        cargaBits(i, base, cantArmas, combGen);

        /*Restricciones*/
        //Recorrer arreglo opcion para ver si es valida

        int arrPoderMochilaActual[cantGue]{};
        
        int flag = false; //si deja de cumplir alguna de las restricciones se cambaiara el valor ys e desacartara
        
        for (int indPosArma = 0; indPosArma < cantArmas; indPosArma++) { //indicador del arma 
            flag = false;
            //1 restriccion de tipo de arma 
            if (combGen[indPosArma] != 0) { //se desacarta la opcion 0  (machila vacia)
                int guerrMochi = combGen[indPosArma] - 1; //posicion del guerrero en el arreglo creado
                int canTipArm = arrGuerr[guerrMochi].cant;
                //Evaluo si el arma cumple con el tipo de arma si no cumple se descarta (debe descartarse despues de leer todas ya que el guerrero puede ser derrotado con mas de un tipo de arma)
                for (int k = 0; k < canTipArm; k++) {
                    if (arrArm[indPosArma].tipo == arrGuerr[guerrMochi].tipoArma[k]) {
                        flag = true;
                        break;
                    }
                }
                if (flag == false) break;
                //2.Verificar condicion de prerequisito
                //si llega a esta parte la bandera esta en true***********************
                int canRequiArm = arrArm[indPosArma].cantReq;
                for (int k = 0; k < canRequiArm; k++) {//k es la cantidad de requisitos
                    //Busca las pos del arma
                    int posArmReq;
                    for (int p = 0; p < cantArmas; p++) {
                        if (arrArm[p].letra == arrArm[indPosArma].req[k]) {
                            posArmReq = p;
                            break;
                        }
                    }
                    if (combGen[posArmReq] != combGen[indPosArma]) {
                        flag = false;
                        break;
                    }
                }
                if (flag == false) break;
                // si llego hasta aqui es por que cumple los requisitos de tipo y pre-requisito solo falta el de poder
                arrPoderMochilaActual[guerrMochi] += arrArm[indPosArma].poder;
            }
        }
        // 3. requisito de poder y eficiencia en armas 
        int poderTotalActual = 0;
        for (int j = 0; j < cantGue; j++) {
            if (arrPoderMochilaActual[j] < arrGuerr[j].poder) {
                flag = false;
                break;
            }
            poderTotalActual += arrPoderMochilaActual[j];
        }
        //eficiencia en el resultado: (Para que matar una mosca con una basuca si tengo matamosca ;V)
        if (flag != false and poderTotalActual < mejorPoder) { //guardar la mejor combinacion 
            for (int j = 0; j < cantArmas; j++) {
                mejorPoder = poderTotalActual;
                mejorCombi[j] = combGen[j];
            }
        }
    }

    //Impresion
    for (int i = 0; i < cantGue; i++) {
        cout << "Guerrero " << i + 1 << endl;
        cout << "Poder: " << arrGuerr[i].poder << endl;
        cout << "Armas en mochila para vencerlo: ";
        for (int j = 0; j < cantArmas; j++) {
            if (mejorCombi[j] == (i + 1)) cout << arrArm[j].letra << " ";
        }
        cout << endl;
    }
    return 0;
}


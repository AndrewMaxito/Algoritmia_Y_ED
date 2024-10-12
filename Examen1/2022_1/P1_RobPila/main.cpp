
/* 
 * File:   main.cpp
 * Author: andre
 *
 * Created on 11 de octubre de 2024, 18:55
 */

#include <iostream>
#include <iomanip>
using namespace std;
#include "Pila.h"
#include "funcionesPila.h"
/*
 * 
 */
int main(int argc, char** argv) {
    int cantPro = 10, capCaja = 3;
    int  cantCajas= (cantPro/capCaja)+1;
    int arrNumeros[cantPro] = {20221224, 20221130, 20221212, 20220814, 20221106, 
    20221003, 20220918, 20220630, 20221006, 20110603};
    
    struct Pila caja1,caja2,caja3,caja4,contenedor;
    construir(caja1);
    construir(caja2);
    construir(caja3);
    construir(caja4);
    construir(contenedor);
    
    for (int i = 0; i < cantPro; i++) {
        apilar(contenedor,arrNumeros[i]);
    }
    
    
    while (!esPilaVacia(contenedor)) {
        int valor = desapilar(contenedor);
        
        //buscar la caja a la que pertenece
        for (int i = 0; i < cantCajas; i++) {
            switch (i){
                case 1:
                    
                    
                    break;
                case 2:
                    
                    break;
                case 3:
                    
                    break;
                case 4:
                    
                    
                    break;
            }
        }

        
        
        
        

    }

    

    
    
    
    
    
    
    
    
    
    
    
    
   
    

    
    
    
    
    return 0;
}


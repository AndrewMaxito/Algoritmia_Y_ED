

/* 
 * File:   main.cpp
 * Author: andre
 *
 * Created on 5 de diciembre de 2024, 19:18
 */

#include <iostream>
#include <iomanip>

using namespace std;

void merge(int *arr, int ini, int medio, int fin) {
    int tamAux = (fin - ini + 1);
    int arrAux[tamAux];

    int p = ini, q = medio + 1, m = 0;
    
    //Inserta datos de cada uno
    while (p <= medio and q <= fin) {
        if (arr[p] < arr[q]) {
            arrAux[m++] = arr[p++];
        } else {
            arrAux[m++] = arr[q++];
        }
    }
    //inserta datos si es que sobraron
    
    //Datos de la izquierda
    while (p <= medio) {
        arrAux[m++] = arr[p++];
    }
    //Datos de la derecha
    while (q <= fin) {
        arrAux[m++] = arr[q++];
    }
    
    //Inserta datos ordenados del aux en el arreglo original
    for (int i = 0; i < m; i++) {
        arr[ini + i] = arrAux[i];
    }
}

void merge_sort(int *arr, int ini, int fin) {
    if (ini == fin)return;
    int medio = (ini + fin) / 2;

    merge_sort(arr, ini, medio); //izquierda
    merge_sort(arr, medio + 1, fin); //Derecha
    
    //Ordenamento:
    merge(arr, ini, medio, fin);
}

int buscaTriple(int *arr,int ini,int fin){
    //caso base
    if (ini == fin)return arr[ini];
    //medio 
    int medio = (ini + fin)/2;
    
    //condicion para reducir la cantidad de veces (es opcional)
    if (arr[medio] == arr[medio +1] and arr[medio] == arr[medio-1])return arr[medio];
    
    //Realiza el descarta y la nueva busqueda
    if (medio % 2 == 0) { //es par 
        if (arr[medio] == arr[medio+1]) {//descarta izquierda
            return buscaTriple(arr,medio,fin);
        } else {
            return buscaTriple(arr,ini,medio);
        }
    } else {
        if (arr[medio] == arr[medio-1]) {//descarto izquierda
            return buscaTriple(arr,medio+1,fin);
        } else {
            return buscaTriple(arr,ini,medio-1);
        }
    }
}
int main(int argc, char** argv) {
    //Registro de ingreso de datos
    int arrResgistro[] = {1, 6, 3, 4, 5, 6, 3, 7, 5, 4, 3, 1, 7};
    int n = sizeof (arrResgistro) / sizeof (arrResgistro[0]);
    //Primero ordenamos el registro para buscar el que no salio
    merge_sort(arrResgistro, 0, n - 1);
    
    //Se busca el que se repite 3 veces (similar a buscaSolitario)
    cout << "EL que ingreso y no volvio a salir es el empleado numero: " << buscaTriple(arrResgistro,0,n-1)<<endl;
    return 0;
}


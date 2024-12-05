
/* 
 * File:   main.cpp
 * Author: andre
 *
 * Created on 3 de diciembre de 2024, 05:08 PM
 */

#include <iostream>
#include <climits>
#define  n 6
using namespace std;



int encontrarMinimo(int dist[], bool visitado[]) {
    
    //Valores mas prqueños para la busquea
    int minDist = INT_MAX;
    int minIndice = -1;
    
    //Proceso de busqueda
    for (int i = 0; i < n; ++i) {
        if (visitado[i] == false and dist[i] < minDist) {
            minDist = dist[i];
            minIndice = i;
        }
    }
    return minIndice;
}


void dijkstra(int grafo[][n],int origen){
    int dist[n];       //Distancias minimas desde el nodo al origen
    bool visitado[n]; //Nodos Procesados
    
    //Inicializacion
    for (int i = 0; i < n; i++) {
        dist[i] = INT_MAX;    //Todos empiezan en un numero muy grande
        visitado[i] = false; //todos empiezan sin visitar (false)
    }
    
    dist[origen] = 0; //La distancia al nodo origen es 0 (distancia a si mismo)
    
    
    //Procesar todos los nodos
    for (int i = 0; i < n; i++) {
        // Encuentra el nodo no visitado con la menor distancia
        int u = encontrarMinimo(dist, visitado);
        
        //Marca ese nodo como visitado
        if (u == -1)break; //si no hubiera nodos alcanzables
        visitado[u] = true;


        // Actualiza las distancias de los nodos vecinos
        for (int v = 0; v < n; ++v) {
            if (visitado[v] == false and grafo[u][v] > 0) { // Si hay conexión
                int nuevaDist = dist[u] + grafo[u][v];
                //Si la nueva distancia mejora el costo actual, actualizar
                if (nuevaDist < dist[v]) {
                    dist[v] = nuevaDist;
                }
            }
        }
    }
   cout << "Nodo Origen: " << origen + 1 << endl;
    for (int i = 0; i < n; ++i) {
        if (dist[i] == INT_MAX)
            cout << "Nodo " << i + 1 << ": Inalcanzable" << endl;
        else
            cout << "Nodo " << i + 1 << ": " << dist[i] << endl;
    }
}
int main(int argc, char** argv) {
    int grafo[][n] = {
    //  [a] [b] [c] [d] [e] [f]
        { 0,  4,  2,  0,  0,  0},
        { 4,  0,  1,  5,  0,  0},
        { 2,  1,  0,  8, 10,  0},
        { 0,  5,  8,  0,  2,  6},
        { 0,  0, 10,  2,  0,  2},
        { 0,  0,  6,  0,  2,  0}
    };


    int origen = 0; //de donde se empezara
    
    dijkstra(grafo, origen);
    return 0;
}


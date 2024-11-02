

/* 
 * File:   main.cpp
 * Author: GABRIEL  MEDRANO AMARO
 *
 * Created on 1 de noviembre de 2024, 01:52 PM
 */

#include <iostream>
#include <iomanip>
#include <fstream>        

using namespace std;

int buscarTriple(int *arr,int ini,int fin){
    if(ini>fin)return -1;
    
    int med=(ini+fin)/2;
    
    if(arr[med]==arr[med-1] and arr[med]==arr[med+1])return med;
    
    if(med%2!=0){
        if(arr[med]==arr[med+1]){
            buscarTriple(arr,ini,med-1);
        }
        else{
            buscarTriple(arr,med+1,fin);
        }
    }
    else{
        if(arr[med]==arr[med+1]){
            
            buscarTriple(arr,med,fin);
        }
        else{
            buscarTriple(arr,ini,med);
        }
        
    }
}

int main(int argc, char** argv) {
    int arr[]={1,1,2,2,4,4,5,5,5,6,6};
    int n=sizeof(arr)/sizeof(arr[0]);
    int arrStock[]={20,20,30,10,10,10,20,20,20,10,10};
    int m=sizeof(arrStock)/sizeof(arrStock[0]);
    int pos;

    
    
    pos=buscarTriple(arr,0,n-1);
    
    cout<<"Las cajas se encuentran en las posiciones "<<pos-1<<", "<<pos<<" y "<<pos+1<<endl;
    cout<<"Son de producto "<<arr[pos]<<"."<<endl;
    cout<<"Su stock suma: "<<arrStock[pos-1]+arrStock[pos]+arrStock[pos+1]<<endl;

    return 0;
}


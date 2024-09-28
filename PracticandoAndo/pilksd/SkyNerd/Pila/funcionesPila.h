// -*- C++ -*-

/* 
 * File:   funcionesPila.h
 * Author: ANA RONCAL
 *
 * Created on 1 de setiembre de 2024, 22:29
 */

#ifndef FUNCIONESPILA_H
#define FUNCIONESPILA_H

void construir(struct Pila & );
int longitud(const struct Pila & );
bool esPilaVacia(const struct Pila &);
void apilar(struct Pila &, int ); 
int desapilar(struct Pila &);
int cima(const struct Pila &);
void destruirPila(struct Pila &);
void imprimir(const struct Pila &);

#endif /* FUNCIONESPILA_H */
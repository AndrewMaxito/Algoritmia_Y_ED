/* 
 * File:   funcionesPila.h
 * Author: ANA RONCAL
 * Created on 7 de abril de 2024, 03:41 PM
 */

#ifndef FUNCIONESPILA_H
#define FUNCIONESPILA_H

void construir(struct Pila & ); //no cambios
int longitud(const struct Pila & );//no cambios
bool esPilaVacia(const struct Pila &);//No cambios

void apilar(struct Pila &, struct StrEfectivo); //SI cambios
struct StrEfectivo desapilar(struct Pila &);//Si cambios
struct StrEfectivo cima(const struct Pila &);//si cambios

void destruirPila(struct Pila &);//No cambios
void imprimir(const struct Pila &);

#endif /* FUNCIONESPILA_H */


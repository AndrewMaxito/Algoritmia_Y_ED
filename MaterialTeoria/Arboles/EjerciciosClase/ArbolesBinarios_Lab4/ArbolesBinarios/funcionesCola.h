/* 
 * File:   funcionesCola.h
 * Author: ANA RONCAL
 * Created on 18 de abril de 2024, 10:28 AM
 */

#ifndef FUNCIONESCOLA_H
#define FUNCIONESCOLA_H

void construir(struct Cola & );       
bool esColaVacia(const struct Cola & cola);
void encolar(struct Cola & cola, struct NodoArbol *  elemento);
void imprimir(const struct Cola & cola);
struct NodoArbol *  desencolar(struct Cola & cola);
void destruirCola(struct Cola & cola);
#endif /* FUNCIONESCOLA_H */


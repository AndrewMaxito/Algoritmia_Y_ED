// -*- C++ -*-

/* 
 * File:   funcionesCola.h
 * Author: ANA RONCAL
 *
 * Created on 1 de setiembre de 2024, 23:02
 */

#ifndef FUNCIONESCOLA_H
#define FUNCIONESCOLA_H

void construir(struct Cola & );       
bool esColaVacia(const struct Cola & cola);
void encolar(struct Cola & cola, int elemento);
void imprime(const struct Cola & cola);
int desencolar(struct Cola & cola);

int longitud(const struct Cola & cola);
void destruirCola(struct Cola & cola);

#endif /* FUNCIONESCOLA_H */